
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaLayerPairConstraintDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerPairConstraintDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerPairConstraintDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerPairConstraintDefObject* self = (PyoaLayerPairConstraintDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLayerPairConstraintDef)
    {
        PyParamoaLayerPairConstraintDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayerPairConstraintDef_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLayerPairConstraintDef, Choices are:\n"
        "    (oaLayerPairConstraintDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaLayerPairConstraintDef_tp_dealloc(PyoaLayerPairConstraintDefObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerPairConstraintDef_tp_repr(PyObject *ob)
{
    PyParamoaLayerPairConstraintDef value;
    int convert_status=PyoaLayerPairConstraintDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaLayerPairConstraintDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerPairConstraintDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerPairConstraintDef v1;
    PyParamoaLayerPairConstraintDef v2;
    int convert_status1=PyoaLayerPairConstraintDef_Convert(ob1,&v1);
    int convert_status2=PyoaLayerPairConstraintDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerPairConstraintDef_Convert(PyObject* ob,PyParamoaLayerPairConstraintDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerPairConstraintDef_Check(ob)) {
        result->SetData( (oaLayerPairConstraintDef**) ((PyoaLayerPairConstraintDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerPairConstraintDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerPairConstraintDef_FromoaLayerPairConstraintDef(oaLayerPairConstraintDef** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLayerPairConstraintDef* data=*value;
        PyObject* bself = PyoaLayerPairConstraintDef_Type.tp_alloc(&PyoaLayerPairConstraintDef_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerPairConstraintDefObject* self = (PyoaLayerPairConstraintDefObject*)bself;
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
PyObject* PyoaLayerPairConstraintDef_FromoaLayerPairConstraintDef(oaLayerPairConstraintDef* data)
{
    if (data) {
       PyObject* bself = PyoaLayerPairConstraintDef_Type.tp_alloc(&PyoaLayerPairConstraintDef_Type,0);
       if (bself == NULL) return bself;
       PyoaLayerPairConstraintDefObject* self = (PyoaLayerPairConstraintDefObject*)bself;
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
static char oaLayerPairConstraintDef_isSymmetric_doc[] = 
"Class: oaLayerPairConstraintDef, Function: isSymmetric\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isSymmetric() const\n"
"    Signature: isSymmetric|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether this definition is symmetric with respect to layer order.\n"
;

static PyObject*
oaLayerPairConstraintDef_isSymmetric(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerPairConstraintDef data;
    int convert_status=PyoaLayerPairConstraintDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerPairConstraintDefObject* self=(PyoaLayerPairConstraintDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isSymmetric());
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
static char oaLayerPairConstraintDef_isNull_doc[] =
"Class: oaLayerPairConstraintDef, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLayerPairConstraintDef_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLayerPairConstraintDef data;
    int convert_status=PyoaLayerPairConstraintDef_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLayerPairConstraintDef_assign_doc[] = 
"Class: oaLayerPairConstraintDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLayerPairConstraintDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLayerPairConstraintDef data;
  int convert_status=PyoaLayerPairConstraintDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLayerPairConstraintDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLayerPairConstraintDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaLayerPairConstraintDef_methodlist[] = {
    {"isSymmetric",(PyCFunction)oaLayerPairConstraintDef_isSymmetric,METH_VARARGS,oaLayerPairConstraintDef_isSymmetric_doc},
    {"isNull",(PyCFunction)oaLayerPairConstraintDef_tp_isNull,METH_VARARGS,oaLayerPairConstraintDef_isNull_doc},
    {"assign",(PyCFunction)oaLayerPairConstraintDef_tp_assign,METH_VARARGS,oaLayerPairConstraintDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerPairConstraintDef_doc[] = 
"Class: oaLayerPairConstraintDef\n"
"  An oaLayerPairConstraintDef object specifies a definition for a layer pair constraint. The definition contains a name, a list of databases that the constraint can be created in, a list of types of oaValues that are allowed for the constraint, and a boolean indicating whether or not the constraint is symmetric with respect to layer order. The names for constraint definitions must be unique.\n"
"Constructors:\n"
"  Paramegers: (oaLayerPairConstraintDef)\n"
"    Calls: (const oaLayerPairConstraintDef&)\n"
"    Signature: oaLayerPairConstraintDef||cref-oaLayerPairConstraintDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerPairConstraintDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerPairConstraintDef",
    sizeof(PyoaLayerPairConstraintDefObject),
    0,
    (destructor)oaLayerPairConstraintDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerPairConstraintDef_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerPairConstraintDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLayerPairConstraintDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLayerPairConstraintDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConstraintDef_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerPairConstraintDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerPairConstraintDef_static_create_doc[] = 
"Class: oaLayerPairConstraintDef, Function: create\n"
"  Paramegers: (oaString,oaSubset_oaType,oaSubset_oaType,oaSubset_oaDBType)\n"
"    Calls: oaLayerPairConstraintDef* create(const oaString& name,const oaSubset_oaType& allowedValues,const oaSubset_oaType& allowedObjects,const oaSubset_oaDBType& allowedDB)\n"
"    Signature: create|ptr-oaLayerPairConstraintDef|cref-oaString,cref-oaSubset_oaType,cref-oaSubset_oaType,cref-oaSubset_oaDBType,simple-oaBoolean,\n"
"    This function creates a new layer pair constraint definition with the specified attributes.\n"
"    name\n"
"    The name of the new definition.\n"
"    allowedValues\n"
"    The value types that constraints with this definition can have.\n"
"    allowedObjects\n"
"    The objects that constraints with this definition can be attached to.\n"
"    allowedDB\n"
"    The databases that constraints with this definition can be created in.\n"
"    symmetric\n"
"    A boolean indicating whether or not this definition is symmetric with respect to layer order.\n"
"    oacConstraintDefExists\n"
"    oacInvalidValueType\n"
"  Paramegers: (oaString,oaSubset_oaType,oaSubset_oaType,oaSubset_oaDBType,oaBoolean)\n"
"    Calls: oaLayerPairConstraintDef* create(const oaString& name,const oaSubset_oaType& allowedValues,const oaSubset_oaType& allowedObjects,const oaSubset_oaDBType& allowedDB,oaBoolean symmetric)\n"
"    Signature: create|ptr-oaLayerPairConstraintDef|cref-oaString,cref-oaSubset_oaType,cref-oaSubset_oaType,cref-oaSubset_oaDBType,simple-oaBoolean,\n"
"    This function creates a new layer pair constraint definition with the specified attributes.\n"
"    name\n"
"    The name of the new definition.\n"
"    allowedValues\n"
"    The value types that constraints with this definition can have.\n"
"    allowedObjects\n"
"    The objects that constraints with this definition can be attached to.\n"
"    allowedDB\n"
"    The databases that constraints with this definition can be created in.\n"
"    symmetric\n"
"    A boolean indicating whether or not this definition is symmetric with respect to layer order.\n"
"    oacConstraintDefExists\n"
"    oacInvalidValueType\n"
;

static PyObject*
oaLayerPairConstraintDef_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaString,oaSubset_oaType,oaSubset_oaType,oaSubset_oaDBType)
    {
        PyParamoaString p1;
        PyParamoaSubset_oaType p2;
        PyParamoaSubset_oaType p3;
        PyParamoaSubset_oaDBType p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaSubset_oaType_Convert,&p2,
              &PyoaSubset_oaType_Convert,&p3,
              &PyoaSubset_oaDBType_Convert,&p4)) {
            oaLayerPairConstraintDefp result= (oaLayerPairConstraintDef::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaLayerPairConstraintDef_FromoaLayerPairConstraintDef(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaSubset_oaType,oaSubset_oaType,oaSubset_oaDBType,oaBoolean)
    {
        PyParamoaString p1;
        PyParamoaSubset_oaType p2;
        PyParamoaSubset_oaType p3;
        PyParamoaSubset_oaDBType p4;
        PyParamoaBoolean p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaString_Convert,&p1,
              &PyoaSubset_oaType_Convert,&p2,
              &PyoaSubset_oaType_Convert,&p3,
              &PyoaSubset_oaDBType_Convert,&p4,
              &PyoaBoolean_Convert,&p5)) {
            oaLayerPairConstraintDefp result= (oaLayerPairConstraintDef::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaLayerPairConstraintDef_FromoaLayerPairConstraintDef(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLayerPairConstraintDef, function: create, Choices are:\n"
        "    (oaString,oaSubset_oaType,oaSubset_oaType,oaSubset_oaDBType)\n"
        "    (oaString,oaSubset_oaType,oaSubset_oaType,oaSubset_oaDBType,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLayerPairConstraintDef_static_get_doc[] = 
"Class: oaLayerPairConstraintDef, Function: get\n"
"  Paramegers: (oaLayerPairConstraintType)\n"
"    Calls: oaLayerPairConstraintDef* get(oaLayerPairConstraintType type)\n"
"    Signature: get|ptr-oaLayerPairConstraintDef|simple-oaLayerPairConstraintType,\n"
"    This function returns the built-in layer pair constraint definition of the type specified.\n"
"    type\n"
"    The built in layer pair constraint type to get.\n"
;

static PyObject*
oaLayerPairConstraintDef_static_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerPairConstraintType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayerPairConstraintType_Convert,&p1)) {
        oaLayerPairConstraintDefp result= (oaLayerPairConstraintDef::get(p1.Data()));
        return PyoaLayerPairConstraintDef_FromoaLayerPairConstraintDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLayerPairConstraintDef_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaLayerPairConstraintDef_static_create,METH_VARARGS,oaLayerPairConstraintDef_static_create_doc},
    {"static_get",(PyCFunction)oaLayerPairConstraintDef_static_get,METH_VARARGS,oaLayerPairConstraintDef_static_get_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerPairConstraintDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerPairConstraintDef_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerPairConstraintDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerPairConstraintDef",
           (PyObject*)(&PyoaLayerPairConstraintDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerPairConstraintDef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLayerPairConstraintDef_Type.tp_dict;
    for(method=oaLayerPairConstraintDef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaLayerPairConstraintType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerPairConstraintType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerPairConstraintType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerPairConstraintTypeObject* self = (PyoaLayerPairConstraintTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLayerPairConstraintTypeEnum)
    {
        PyParamoaLayerPairConstraintTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaLayerPairConstraintTypeEnum_Convert,&p1)) {
            self->value =  new oaLayerPairConstraintType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaLayerPairConstraintType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaLayerPairConstraintType)
    {
        PyParamoaLayerPairConstraintType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayerPairConstraintType_Convert,&p1)) {
            self->value= new oaLayerPairConstraintType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaLayerPairConstraintType, Choices are:\n"
        "    (oaLayerPairConstraintTypeEnum)\n"
        "    (oaString)\n"
        "    (oaLayerPairConstraintType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaLayerPairConstraintType_tp_dealloc(PyoaLayerPairConstraintTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerPairConstraintType_tp_repr(PyObject *ob)
{
    PyParamoaLayerPairConstraintType value;
    int convert_status=PyoaLayerPairConstraintType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[47];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaLayerPairConstraintType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerPairConstraintType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerPairConstraintType v1;
    PyParamoaLayerPairConstraintType v2;
    int convert_status1=PyoaLayerPairConstraintType_Convert(ob1,&v1);
    int convert_status2=PyoaLayerPairConstraintType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerPairConstraintType_Convert(PyObject* ob,PyParamoaLayerPairConstraintType* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerPairConstraintType_Check(ob)) {
        result->SetData(  ((PyoaLayerPairConstraintTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerPairConstraintType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerPairConstraintType_FromoaLayerPairConstraintType(oaLayerPairConstraintType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaLayerPairConstraintType_Type.tp_alloc(&PyoaLayerPairConstraintType_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerPairConstraintTypeObject* self = (PyoaLayerPairConstraintTypeObject*)bself;
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
static char oaLayerPairConstraintType_getName_doc[] = 
"Class: oaLayerPairConstraintType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name associated with the encapsulated oaLayerPairConstraintTypeEnum object.\n"
;

static PyObject*
oaLayerPairConstraintType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerPairConstraintType data;
    int convert_status=PyoaLayerPairConstraintType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerPairConstraintTypeObject* self=(PyoaLayerPairConstraintTypeObject*)ob;

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
static char oaLayerPairConstraintType_oaLayerPairConstraintTypeEnum_doc[] = 
"Class: oaLayerPairConstraintType, Function: oaLayerPairConstraintTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaLayerPairConstraintTypeEnum oaLayerPairConstraintTypeEnum() const\n"
"    Signature: operator oaLayerPairConstraintTypeEnum|simple-oaLayerPairConstraintTypeEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaLayerPairConstraintType object into the corresponding oaLayerPairConstraintTypeEnum.\n"
;

static PyObject*
oaLayerPairConstraintType_oaLayerPairConstraintTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerPairConstraintType data;
    int convert_status=PyoaLayerPairConstraintType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerPairConstraintTypeObject* self=(PyoaLayerPairConstraintTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerPairConstraintTypeEnum result= (data.DataCall()->operator oaLayerPairConstraintTypeEnum());
        return PyoaLayerPairConstraintTypeEnum_FromoaLayerPairConstraintTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaLayerPairConstraintType_assign_doc[] = 
"Class: oaLayerPairConstraintType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLayerPairConstraintType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLayerPairConstraintType data;
  int convert_status=PyoaLayerPairConstraintType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLayerPairConstraintType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLayerPairConstraintType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaLayerPairConstraintType_methodlist[] = {
    {"getName",(PyCFunction)oaLayerPairConstraintType_getName,METH_VARARGS,oaLayerPairConstraintType_getName_doc},
    {"oaLayerPairConstraintTypeEnum",(PyCFunction)oaLayerPairConstraintType_oaLayerPairConstraintTypeEnum,METH_VARARGS,oaLayerPairConstraintType_oaLayerPairConstraintTypeEnum_doc},
    {"assign",(PyCFunction)oaLayerPairConstraintType_tp_assign,METH_VARARGS,oaLayerPairConstraintType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerPairConstraintType_doc[] = 
"Class: oaLayerPairConstraintType\n"
"  The oaLayerPairConstraintType class is an enum wrapper class for oaLayerPairConstraintTypeEnum values.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaLayerPairConstraintTypeEnum\n"
"Constructors:\n"
"  Paramegers: (oaLayerPairConstraintTypeEnum)\n"
"    Calls: oaLayerPairConstraintType(oaLayerPairConstraintTypeEnum typeIn)\n"
"    Signature: oaLayerPairConstraintType||simple-oaLayerPairConstraintTypeEnum,\n"
"    This constructor for the oaLayerPairConstraintType class enum wrapper takes an oaLayerPairConstraintTypeEnum value.\n"
"    typeIn\n"
"    An oaLayerPairConstraintTypeEnum type value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaLayerPairConstraintType(const oaString& name)\n"
"    Signature: oaLayerPairConstraintType||cref-oaString,\n"
"    This function creates an instance of an oaLayerPairConstraintType class using the oaLayerPairConstraintTypeEnum associated with the specified string name. This name must be defined in the legal set of names associated with oaLayerPairConstraintTypeEnum.\n"
"    name\n"
"    The name of the layer pair constraint type.\n"
"    oacInvalidLayerPairConstraintTypeName\n"
"  Paramegers: (oaLayerPairConstraintType)\n"
"    Calls: (const oaLayerPairConstraintType&)\n"
"    Signature: oaLayerPairConstraintType||cref-oaLayerPairConstraintType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerPairConstraintType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerPairConstraintType",
    sizeof(PyoaLayerPairConstraintTypeObject),
    0,
    (destructor)oaLayerPairConstraintType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerPairConstraintType_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerPairConstraintType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLayerPairConstraintType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLayerPairConstraintType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerPairConstraintType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerPairConstraintType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerPairConstraintType_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerPairConstraintType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerPairConstraintType",
           (PyObject*)(&PyoaLayerPairConstraintType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerPairConstraintType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaLayerPairConstraintTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaLayerPairConstraintTypeEnum_Convert(PyObject* ob,PyParamoaLayerPairConstraintTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacMinClearance")==0) { result->SetData(oacMinClearance); return 1;}
        if (strcasecmp(str,"oacMaxClearance")==0) { result->SetData(oacMaxClearance); return 1;}
        if (strcasecmp(str,"oacMinSameNetClearance")==0) { result->SetData(oacMinSameNetClearance); return 1;}
        if (strcasecmp(str,"oacMinExtension")==0) { result->SetData(oacMinExtension); return 1;}
        if (strcasecmp(str,"oacMaxExtension")==0) { result->SetData(oacMaxExtension); return 1;}
        if (strcasecmp(str,"oacMinDualExtension")==0) { result->SetData(oacMinDualExtension); return 1;}
        if (strcasecmp(str,"oacMinOverlap")==0) { result->SetData(oacMinOverlap); return 1;}
        if (strcasecmp(str,"oacViaStackingAllowed")==0) { result->SetData(oacViaStackingAllowed); return 1;}
        if (strcasecmp(str,"oacMinRedundantViaSetback")==0) { result->SetData(oacMinRedundantViaSetback); return 1;}
        if (strcasecmp(str,"oacMinConcaveCornerOverlap")==0) { result->SetData(oacMinConcaveCornerOverlap); return 1;}
        if (strcasecmp(str,"oacMinConcaveCornerExtension")==0) { result->SetData(oacMinConcaveCornerExtension); return 1;}
        if (strcasecmp(str,"oacKeepAlignedShapes")==0) { result->SetData(oacKeepAlignedShapes); return 1;}
        if (strcasecmp(str,"oacMinEndOfLineExtension")==0) { result->SetData(oacMinEndOfLineExtension); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaLayerPairConstraintTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerPairConstraintTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaLayerPairConstraintTypeEnum_FromoaLayerPairConstraintTypeEnum(oaLayerPairConstraintTypeEnum ob)
{
    if (ob==oacMinClearance) return PyString_FromString("oacMinClearance");
    if (ob==oacMaxClearance) return PyString_FromString("oacMaxClearance");
    if (ob==oacMinSameNetClearance) return PyString_FromString("oacMinSameNetClearance");
    if (ob==oacMinExtension) return PyString_FromString("oacMinExtension");
    if (ob==oacMaxExtension) return PyString_FromString("oacMaxExtension");
    if (ob==oacMinDualExtension) return PyString_FromString("oacMinDualExtension");
    if (ob==oacMinOverlap) return PyString_FromString("oacMinOverlap");
    if (ob==oacViaStackingAllowed) return PyString_FromString("oacViaStackingAllowed");
    if (ob==oacMinRedundantViaSetback) return PyString_FromString("oacMinRedundantViaSetback");
    if (ob==oacMinConcaveCornerOverlap) return PyString_FromString("oacMinConcaveCornerOverlap");
    if (ob==oacMinConcaveCornerExtension) return PyString_FromString("oacMinConcaveCornerExtension");
    if (ob==oacKeepAlignedShapes) return PyString_FromString("oacKeepAlignedShapes");
    if (ob==oacMinEndOfLineExtension) return PyString_FromString("oacMinEndOfLineExtension");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaLayerPairConstraintTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaLayerPairConstraintTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaLayerPairConstraintTypeEnum_FromoaLayerPairConstraintTypeEnum(oaLayerPairConstraintTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaLayerPairConstraintTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaLayerPairConstraintTypeEnum_doc[] =
"Type convert function for enum: oaLayerPairConstraintTypeEnum";
                               
static PyMethodDef PyoaLayerPairConstraintTypeEnum_method =
  {"oaLayerPairConstraintTypeEnum",(PyCFunction)PyoaLayerPairConstraintTypeEnum_TypeFunction,METH_VARARGS,oaLayerPairConstraintTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaLayerPairConstraintTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacMinClearance");
    PyDict_SetItemString(mod_dict,"oacMinClearance",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMaxClearance");
    PyDict_SetItemString(mod_dict,"oacMaxClearance",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinSameNetClearance");
    PyDict_SetItemString(mod_dict,"oacMinSameNetClearance",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinExtension");
    PyDict_SetItemString(mod_dict,"oacMinExtension",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMaxExtension");
    PyDict_SetItemString(mod_dict,"oacMaxExtension",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinDualExtension");
    PyDict_SetItemString(mod_dict,"oacMinDualExtension",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinOverlap");
    PyDict_SetItemString(mod_dict,"oacMinOverlap",value);
    Py_DECREF(value);
    value=PyString_FromString("oacViaStackingAllowed");
    PyDict_SetItemString(mod_dict,"oacViaStackingAllowed",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinRedundantViaSetback");
    PyDict_SetItemString(mod_dict,"oacMinRedundantViaSetback",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinConcaveCornerOverlap");
    PyDict_SetItemString(mod_dict,"oacMinConcaveCornerOverlap",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinConcaveCornerExtension");
    PyDict_SetItemString(mod_dict,"oacMinConcaveCornerExtension",value);
    Py_DECREF(value);
    value=PyString_FromString("oacKeepAlignedShapes");
    PyDict_SetItemString(mod_dict,"oacKeepAlignedShapes",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMinEndOfLineExtension");
    PyDict_SetItemString(mod_dict,"oacMinEndOfLineExtension",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaLayerPairConstraintTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaLayerPairConstraintTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaLayerPairConstraintTypeEnum\n");
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
// Wrapper Implementation for Class: oaLayerValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLayerValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLayerValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLayerValueObject* self = (PyoaLayerValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLayerValue)
    {
        PyParamoaLayerValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLayerValue_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLayerValue, Choices are:\n"
        "    (oaLayerValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaLayerValue_tp_dealloc(PyoaLayerValueObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLayerValue_tp_repr(PyObject *ob)
{
    PyParamoaLayerValue value;
    int convert_status=PyoaLayerValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[34];
    sprintf(buffer,"<oaLayerValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLayerValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLayerValue v1;
    PyParamoaLayerValue v2;
    int convert_status1=PyoaLayerValue_Convert(ob1,&v1);
    int convert_status2=PyoaLayerValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLayerValue_Convert(PyObject* ob,PyParamoaLayerValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaLayerValue_Check(ob)) {
        result->SetData( (oaLayerValue**) ((PyoaLayerValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLayerValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLayerValue_FromoaLayerValue(oaLayerValue** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLayerValue* data=*value;
        PyObject* bself = PyoaLayerValue_Type.tp_alloc(&PyoaLayerValue_Type,0);
        if (bself == NULL) return bself;
        PyoaLayerValueObject* self = (PyoaLayerValueObject*)bself;
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
PyObject* PyoaLayerValue_FromoaLayerValue(oaLayerValue* data)
{
    if (data) {
       PyObject* bself = PyoaLayerValue_Type.tp_alloc(&PyoaLayerValue_Type,0);
       if (bself == NULL) return bself;
       PyoaLayerValueObject* self = (PyoaLayerValueObject*)bself;
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
static char oaLayerValue_get_doc[] = 
"Class: oaLayerValue, Function: get\n"
"  Paramegers: ()\n"
"    Calls: oaLayerNum get() const\n"
"    Signature: get|simple-oaLayerNum|\n"
"    BrowseData: 1\n"
"    This function returns the layer number for this value.\n"
;

static PyObject*
oaLayerValue_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerValue data;
    int convert_status=PyoaLayerValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerValueObject* self=(PyoaLayerValueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerNum result= (data.DataCall()->get());
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
static char oaLayerValue_set_doc[] = 
"Class: oaLayerValue, Function: set\n"
"  Paramegers: (oaLayerNum)\n"
"    Calls: void set(oaLayerNum value)\n"
"    Signature: set|void-void|simple-oaLayerNum,\n"
"    This function sets the layer number for this value\n"
"    value\n"
"    The layer number to set\n"
;

static PyObject*
oaLayerValue_set(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLayerValue data;
    int convert_status=PyoaLayerValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLayerValueObject* self=(PyoaLayerValueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaLayerNum p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayerNum_Convert,&p1)) {
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
static char oaLayerValue_isNull_doc[] =
"Class: oaLayerValue, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLayerValue_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLayerValue data;
    int convert_status=PyoaLayerValue_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLayerValue_assign_doc[] = 
"Class: oaLayerValue, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLayerValue_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLayerValue data;
  int convert_status=PyoaLayerValue_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLayerValue p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLayerValue_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaLayerValue_methodlist[] = {
    {"get",(PyCFunction)oaLayerValue_get,METH_VARARGS,oaLayerValue_get_doc},
    {"set",(PyCFunction)oaLayerValue_set,METH_VARARGS,oaLayerValue_set_doc},
    {"isNull",(PyCFunction)oaLayerValue_tp_isNull,METH_VARARGS,oaLayerValue_isNull_doc},
    {"assign",(PyCFunction)oaLayerValue_tp_assign,METH_VARARGS,oaLayerValue_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerValue_doc[] = 
"Class: oaLayerValue\n"
"  The oaLayerValue represents a value containing an oaLayerNumber.\n"
"  See oaValue for a discussion of the usage of all of the oaValue subclasses.\n"
"Constructors:\n"
"  Paramegers: (oaLayerValue)\n"
"    Calls: (const oaLayerValue&)\n"
"    Signature: oaLayerValue||cref-oaLayerValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLayerValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLayerValue",
    sizeof(PyoaLayerValueObject),
    0,
    (destructor)oaLayerValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLayerValue_tp_compare,	/* tp_compare */
    (reprfunc)oaLayerValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLayerValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLayerValue_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaValue_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLayerValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLayerValue_static_create_doc[] = 
"Class: oaLayerValue, Function: create\n"
"  Paramegers: (oaObject,oaLayerNum)\n"
"    Calls: oaLayerValue* create(oaObject* database,oaLayerNum value)\n"
"    Signature: create|ptr-oaLayerValue|ptr-oaObject,simple-oaLayerNum,\n"
"    This function creates a layer value in the database specified.\n"
"    database\n"
"    The database in which to create the value\n"
"    value\n"
"    The layer number value\n"
"    oacInvalidDatabase\n"
;

static PyObject*
oaLayerValue_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObject p1;
    PyParamoaLayerNum p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaObject_Convert,&p1,
          &PyoaLayerNum_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaLayerValuep result= (oaLayerValue::create(p1.Data(),p2.Data()));
        return PyoaLayerValue_FromoaLayerValue(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLayerValue_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaLayerValue_static_create,METH_VARARGS,oaLayerValue_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLayerValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLayerValue_Type)<0) {
      printf("** PyType_Ready failed for: oaLayerValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLayerValue",
           (PyObject*)(&PyoaLayerValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLayerValue\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLayerValue_Type.tp_dict;
    for(method=oaLayerValue_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaLefNS
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLefNS_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLefNS_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLefNSObject* self = (PyoaLefNSObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaNameSpace*)  new oaLefNS();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaLefNS)
    {
        PyParamoaLefNS p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLefNS_Convert,&p1)) {
            self->value=(oaNameSpace*)  new oaLefNS(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaLefNS, Choices are:\n"
        "    ()\n"
        "    (oaLefNS)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaLefNS_tp_dealloc(PyoaLefNSObject* self)
{
    if (!self->borrow) {
        delete (oaLefNS*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLefNS_tp_repr(PyObject *ob)
{
    PyParamoaLefNS value;
    int convert_status=PyoaLefNS_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[29];
    sprintf(buffer,"<oaLefNS::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLefNS_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLefNS v1;
    PyParamoaLefNS v2;
    int convert_status1=PyoaLefNS_Convert(ob1,&v1);
    int convert_status2=PyoaLefNS_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLefNS_Convert(PyObject* ob,PyParamoaLefNS* result)
{
    if (ob == NULL) return 1;
    if (PyoaLefNS_Check(ob)) {
        result->SetData( (oaLefNS*) ((PyoaLefNSObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLefNS Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLefNS_FromoaLefNS(oaLefNS* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaLefNS_Type.tp_alloc(&PyoaLefNS_Type,0);
        if (bself == NULL) return bself;
        PyoaLefNSObject* self = (PyoaLefNSObject*)bself;
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
static char oaLefNS_getCloseBusChar_doc[] = 
"Class: oaLefNS, Function: getCloseBusChar\n"
"  Paramegers: ()\n"
"    Calls: oaChar getCloseBusChar() const\n"
"    Signature: getCloseBusChar|simple-oaChar|\n"
"    BrowseData: 1\n"
"    This function returns the close bus character for this nameSpace.\n"
;

static PyObject*
oaLefNS_getCloseBusChar(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLefNS data;
    int convert_status=PyoaLefNS_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLefNSObject* self=(PyoaLefNSObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaChar result= (data.DataCall()->getCloseBusChar());
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
static char oaLefNS_getHierDelimiter_doc[] = 
"Class: oaLefNS, Function: getHierDelimiter\n"
"  Paramegers: ()\n"
"    Calls: oaChar getHierDelimiter() const\n"
"    Signature: getHierDelimiter|simple-oaChar|\n"
"    BrowseData: 1\n"
"    This function returns the hierarchy character for this nameSpace.\n"
;

static PyObject*
oaLefNS_getHierDelimiter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLefNS data;
    int convert_status=PyoaLefNS_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLefNSObject* self=(PyoaLefNSObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaChar result= (data.DataCall()->getHierDelimiter());
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
static char oaLefNS_getOpenBusChar_doc[] = 
"Class: oaLefNS, Function: getOpenBusChar\n"
"  Paramegers: ()\n"
"    Calls: oaChar getOpenBusChar() const\n"
"    Signature: getOpenBusChar|simple-oaChar|\n"
"    BrowseData: 1\n"
"    This function returns the open bus character for this nameSpace.\n"
;

static PyObject*
oaLefNS_getOpenBusChar(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLefNS data;
    int convert_status=PyoaLefNS_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLefNSObject* self=(PyoaLefNSObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaChar result= (data.DataCall()->getOpenBusChar());
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
static char oaLefNS_getType_doc[] = 
"Class: oaLefNS, Function: getType\n"
"  Paramegers: ([oaChar])\n"
"    Calls: oaNameType getType(const oaChar* in) const\n"
"    Signature: getType|simple-oaNameType|cptr-oaChar,\n"
"    Function getType\n"
;

static PyObject*
oaLefNS_getType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLefNS data;
    int convert_status=PyoaLefNS_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLefNSObject* self=(PyoaLefNSObject*)ob;

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
static char oaLefNS_isEqual_doc[] = 
"Class: oaLefNS, Function: isEqual\n"
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
oaLefNS_isEqual(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLefNS data;
    int convert_status=PyoaLefNS_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLefNSObject* self=(PyoaLefNSObject*)ob;

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
        "No Arg-Matching Function found for class: oaLefNS, function: isEqual, Choices are:\n"
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

// ------------------------------------------------------------------
static char oaLefNS_setCloseBusChar_doc[] = 
"Class: oaLefNS, Function: setCloseBusChar\n"
"  Paramegers: (oaChar)\n"
"    Calls: void setCloseBusChar(oaChar c)\n"
"    Signature: setCloseBusChar|void-void|simple-oaChar,\n"
"    This function sets the value of the close bus character for this nameSpace.\n"
"    c\n"
"    The value of the close bus character\n"
"    oacProgrammableCharTaken\n"
;

static PyObject*
oaLefNS_setCloseBusChar(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLefNS data;
    int convert_status=PyoaLefNS_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLefNSObject* self=(PyoaLefNSObject*)ob;

    PyParamoaChar p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaChar_Convert,&p1)) {
        data.DataCall()->setCloseBusChar(p1.Data());
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
static char oaLefNS_setHierDelimiter_doc[] = 
"Class: oaLefNS, Function: setHierDelimiter\n"
"  Paramegers: (oaChar)\n"
"    Calls: void setHierDelimiter(oaChar c)\n"
"    Signature: setHierDelimiter|void-void|simple-oaChar,\n"
"    This function sets the value of the hierarchy delimiter for this nameSpace.\n"
"    c\n"
"    The value of the hierarchy delimiter\n"
"    oacProgrammableCharTaken\n"
;

static PyObject*
oaLefNS_setHierDelimiter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLefNS data;
    int convert_status=PyoaLefNS_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLefNSObject* self=(PyoaLefNSObject*)ob;

    PyParamoaChar p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaChar_Convert,&p1)) {
        data.DataCall()->setHierDelimiter(p1.Data());
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
static char oaLefNS_setOpenBusChar_doc[] = 
"Class: oaLefNS, Function: setOpenBusChar\n"
"  Paramegers: (oaChar)\n"
"    Calls: void setOpenBusChar(oaChar c)\n"
"    Signature: setOpenBusChar|void-void|simple-oaChar,\n"
"    This function sets the value of the open bus character for this nameSpace.\n"
"    c\n"
"    The value of the open bus character\n"
"    oacProgrammableCharTaken\n"
;

static PyObject*
oaLefNS_setOpenBusChar(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLefNS data;
    int convert_status=PyoaLefNS_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLefNSObject* self=(PyoaLefNSObject*)ob;

    PyParamoaChar p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaChar_Convert,&p1)) {
        data.DataCall()->setOpenBusChar(p1.Data());
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

static char oaLefNS_assign_doc[] = 
"Class: oaLefNS, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLefNS_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLefNS data;
  int convert_status=PyoaLefNS_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLefNS p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLefNS_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaLefNS_methodlist[] = {
    {"getCloseBusChar",(PyCFunction)oaLefNS_getCloseBusChar,METH_VARARGS,oaLefNS_getCloseBusChar_doc},
    {"getHierDelimiter",(PyCFunction)oaLefNS_getHierDelimiter,METH_VARARGS,oaLefNS_getHierDelimiter_doc},
    {"getOpenBusChar",(PyCFunction)oaLefNS_getOpenBusChar,METH_VARARGS,oaLefNS_getOpenBusChar_doc},
    {"getType",(PyCFunction)oaLefNS_getType,METH_VARARGS,oaLefNS_getType_doc},
    {"isEqual",(PyCFunction)oaLefNS_isEqual,METH_VARARGS,oaLefNS_isEqual_doc},
    {"setCloseBusChar",(PyCFunction)oaLefNS_setCloseBusChar,METH_VARARGS,oaLefNS_setCloseBusChar_doc},
    {"setHierDelimiter",(PyCFunction)oaLefNS_setHierDelimiter,METH_VARARGS,oaLefNS_setHierDelimiter_doc},
    {"setOpenBusChar",(PyCFunction)oaLefNS_setOpenBusChar,METH_VARARGS,oaLefNS_setOpenBusChar_doc},
    {"assign",(PyCFunction)oaLefNS_tp_assign,METH_VARARGS,oaLefNS_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLefNS_doc[] = 
"Class: oaLefNS\n"
"  The oaLefNS class implements the LEF nameSpace used in name mapping. The LEF name space reflects the rules for specifying names of objects in LEF files. In conjunction with the oaName object, the oaLefNS class facilitates mapping names to and from LEF. See the Name Mapping Section of the Programmers Guide for more information.\n"
"  The LEF NameSpace is case sensitive, with programmable bus charactesr. It does not support vectored, stepped names, or bundle names, though it needs to know what characters are being used as bus delimiters in order to provide the proper mapping. See the LEF/DEF Name Space Section of the Programmers Guide for a more detailed description of the characteristics of the LEF name space.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaLefNS()\n"
"    Signature: oaLefNS||\n"
"    This function constructs the LefNS instance.\n"
"  Paramegers: (oaLefNS)\n"
"    Calls: (const oaLefNS&)\n"
"    Signature: oaLefNS||cref-oaLefNS,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLefNS_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLefNS",
    sizeof(PyoaLefNSObject),
    0,
    (destructor)oaLefNS_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLefNS_tp_compare,	/* tp_compare */
    (reprfunc)oaLefNS_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLefNS_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLefNS_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaNameSpace_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLefNS_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLefNS_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLefNS_Type)<0) {
      printf("** PyType_Ready failed for: oaLefNS\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLefNS",
           (PyObject*)(&PyoaLefNS_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLefNS\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaLib
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLib_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLib_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLibObject* self = (PyoaLibObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLib)
    {
        PyParamoaLib p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLib_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLib, Choices are:\n"
        "    (oaLib)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaLib_tp_dealloc(PyoaLibObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLib_tp_repr(PyObject *ob)
{
    PyParamoaLib value;
    int convert_status=PyoaLib_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaLib::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaScalarName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[27];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaLib::");
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
oaLib_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLib v1;
    PyParamoaLib v2;
    int convert_status1=PyoaLib_Convert(ob1,&v1);
    int convert_status2=PyoaLib_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLib_Convert(PyObject* ob,PyParamoaLib* result)
{
    if (ob == NULL) return 1;
    if (PyoaLib_Check(ob)) {
        result->SetData( (oaLib**) ((PyoaLibObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLib Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLib_FromoaLib(oaLib** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLib* data=*value;
        PyObject* bself = PyoaLib_Type.tp_alloc(&PyoaLib_Type,0);
        if (bself == NULL) return bself;
        PyoaLibObject* self = (PyoaLibObject*)bself;
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
PyObject* PyoaLib_FromoaLib(oaLib* data)
{
    if (data) {
       PyObject* bself = PyoaLib_Type.tp_alloc(&PyoaLib_Type,0);
       if (bself == NULL) return bself;
       PyoaLibObject* self = (PyoaLibObject*)bself;
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
static char oaLib_calcVMSize_doc[] = 
"Class: oaLib, Function: calcVMSize\n"
"  Paramegers: ()\n"
"    Calls: oaUInt8 calcVMSize() const\n"
"    Signature: calcVMSize|simple-oaUInt8|\n"
"    BrowseData: 1\n"
"    This function calculates and returns the amount of virtual memory this library database is currently using.\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
;

static PyObject*
oaLib_calcVMSize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
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
static char oaLib_close_doc[] = 
"Class: oaLib, Function: close\n"
"  Paramegers: ()\n"
"    Calls: void close()\n"
"    Signature: close|void-void|\n"
"    BrowseData: 0\n"
"    This function closes the library. All of its contents become inaccessible, all its library access calls are released, and its non-committed changes are lost.\n"
"    Note: This function does not require library access. For more information on library access, see classoaLib.html Library Access in the detailed description for oaLib. classoaLib.html classoaLib.html\n"
;

static PyObject*
oaLib_close(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
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
static char oaLib_getAccess_doc[] = 
"Class: oaLib, Function: getAccess\n"
"  Paramegers: (oaLibAccess)\n"
"    Calls: oaBoolean getAccess(oaLibAccess accessType)\n"
"    Signature: getAccess|simple-oaBoolean|simple-oaLibAccess,simple-oaUInt4,\n"
"    oaLib::getAccess\n"
"    This function tries to get the requested access for the library. A boolean is returned which indicates success or failure. Library access cannot be upgraded (changed from read to write), so an exception is thrown if this is attempted.\n"
"    accessType\n"
"    the type of access requested on this library\n"
"    timeout\n"
"    an optional timeout in seconds for the function to wait to obtain the requested access\n"
"    oacLibAccessCannotUpgrade\n"
"  Paramegers: (oaLibAccess,oaUInt4)\n"
"    Calls: oaBoolean getAccess(oaLibAccess accessType,oaUInt4 timeout)\n"
"    Signature: getAccess|simple-oaBoolean|simple-oaLibAccess,simple-oaUInt4,\n"
"    oaLib::getAccess\n"
"    This function tries to get the requested access for the library. A boolean is returned which indicates success or failure. Library access cannot be upgraded (changed from read to write), so an exception is thrown if this is attempted.\n"
"    accessType\n"
"    the type of access requested on this library\n"
"    timeout\n"
"    an optional timeout in seconds for the function to wait to obtain the requested access\n"
"    oacLibAccessCannotUpgrade\n"
;

static PyObject*
oaLib_getAccess(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaLibAccess)
    {
        PyParamoaLibAccess p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaLibAccess_Convert,&p1)) {
            oaBoolean result= (data.DataCall()->getAccess(p1.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLibAccess,oaUInt4)
    {
        PyParamoaLibAccess p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaLibAccess_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            oaBoolean result= (data.DataCall()->getAccess(p1.Data(),p2.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLib, function: getAccess, Choices are:\n"
        "    (oaLibAccess)\n"
        "    (oaLibAccess,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_getAccessLevel_doc[] = 
"Class: oaLib, Function: getAccessLevel\n"
"  Paramegers: ()\n"
"    Calls: oaLibAccessLevel getAccessLevel() const\n"
"    Signature: getAccessLevel|simple-oaLibAccessLevel|\n"
"    BrowseData: 1\n"
"    This function returns the level of access that the user has on the library. There are three levels of access: no access, read access, and write access.\n"
;

static PyObject*
oaLib_getAccessLevel(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLibAccessLevel* result= new oaLibAccessLevel(data.DataCall()->getAccessLevel());
        return PyoaLibAccessLevel_FromoaLibAccessLevel(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_getAttributes_doc[] = 
"Class: oaLib, Function: getAttributes\n"
"  Paramegers: (oaDMAttrArray)\n"
"    Calls: void getAttributes(oaDMAttrArray& attrs) const\n"
"    Signature: getAttributes|void-void|ref-oaDMAttrArray,\n"
"    BrowseData: 0,oaDMAttrArray\n"
"    This function returns the attributes defined for this library and its Design Management (DM) and Version Control (VC) systems when the library was created.\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to the library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    attrs\n"
"    Contains the list of attributes associated with the library and its DM and VC systems.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaLib_getAttributes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDMAttrArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMAttrArray_Convert,&p1)) {
        data.DataCall()->getAttributes(p1.Data());
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
static char oaLib_getCellViews_doc[] = 
"Class: oaLib, Function: getCellViews\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaCellView_oaLib getCellViews() const\n"
"    Signature: getCellViews|simple-oaCollection_oaCellView_oaLib|\n"
"    BrowseData: 1\n"
"    This function returns a collection of cellViews in this library.\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to this library does not exist. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaLib_getCellViews(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaCellView_oaLib* result= new oaCollection_oaCellView_oaLib(data.DataCall()->getCellViews());
        return PyoaCollection_oaCellView_oaLib_FromoaCollection_oaCellView_oaLib(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_getCellViewsIter_doc[] = 
"Class: oaLib, Function: getCellViewsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaCellView getCellViewsIter() const\n"
"    Signature: getCellViewsIter|simple-oaIter_oaCellView|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of cellViews in this library.\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to this library does not exist. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaLib_getCellViewsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaCellView* result= new oaIter_oaCellView(data.DataCall()->getCellViews());
        return PyoaIter_oaCellView_FromoaIter_oaCellView(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_getCells_doc[] = 
"Class: oaLib, Function: getCells\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaCell_oaLib getCells() const\n"
"    Signature: getCells|simple-oaCollection_oaCell_oaLib|\n"
"    BrowseData: 1\n"
"    This function returns a collection of cells in this library.\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to this library does not exist. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaLib_getCells(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaCell_oaLib* result= new oaCollection_oaCell_oaLib(data.DataCall()->getCells());
        return PyoaCollection_oaCell_oaLib_FromoaCollection_oaCell_oaLib(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_getCellsIter_doc[] = 
"Class: oaLib, Function: getCellsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaCell getCellsIter() const\n"
"    Signature: getCellsIter|simple-oaIter_oaCell|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of cells in this library.\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to this library does not exist. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaLib_getCellsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaCell* result= new oaIter_oaCell(data.DataCall()->getCells());
        return PyoaIter_oaCell_FromoaIter_oaCell(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_getControlledObjects_doc[] = 
"Class: oaLib, Function: getControlledObjects\n"
"  Paramegers: ()\n"
"    Calls: oaDMObjectIter getControlledObjects()\n"
"    Signature: getControlledObjects|simple-oaDMObjectIter|simple-oaVCQueryDepth,ptr-oaDMObject,simple-oaBoolean,\n"
"    BrowseData: 1\n"
"    oaLib::getControlledObjects\n"
"    This function returns an array of the objects that the version control system reports as being controlled in this library.\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to this library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    depth\n"
"    this parameter is used to control the depth that this function will go in the hierarchy when applying this operation. The enum values have the following meanings:\n"
"    oacFileVCQueryDepth: query only the immediate children files of this container\n"
"    oacCellVCQueryDepth: stop the query at the Cell level, not including \"cell files\"\n"
"    oacViewVCQueryDepth: stop the query at the View level, not including \"view files\"\n"
"    oacCellViewVCQueryDepth: stop the query at the CellView level, not including \"cellView\" files\n"
"    oacCellViewFileVCQueryDepth: stop the query at the CellView file level. This is currently the lowest level\n"
"    oacMaxQueryDepth: query to the bottom of the hierarchy\n"
"    top\n"
"    the object that represents the top of the query hierarchy. NULL indicates to start from the top of the library.\n"
"    localOnly\n"
"    only return objects that also exist in the local directory\n"
"    oacLibAccessDenied\n"
"  Paramegers: (oaVCQueryDepth)\n"
"    Calls: oaDMObjectIter getControlledObjects(oaVCQueryDepth depth)\n"
"    Signature: getControlledObjects|simple-oaDMObjectIter|simple-oaVCQueryDepth,ptr-oaDMObject,simple-oaBoolean,\n"
"    oaLib::getControlledObjects\n"
"    This function returns an array of the objects that the version control system reports as being controlled in this library.\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to this library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    depth\n"
"    this parameter is used to control the depth that this function will go in the hierarchy when applying this operation. The enum values have the following meanings:\n"
"    oacFileVCQueryDepth: query only the immediate children files of this container\n"
"    oacCellVCQueryDepth: stop the query at the Cell level, not including \"cell files\"\n"
"    oacViewVCQueryDepth: stop the query at the View level, not including \"view files\"\n"
"    oacCellViewVCQueryDepth: stop the query at the CellView level, not including \"cellView\" files\n"
"    oacCellViewFileVCQueryDepth: stop the query at the CellView file level. This is currently the lowest level\n"
"    oacMaxQueryDepth: query to the bottom of the hierarchy\n"
"    top\n"
"    the object that represents the top of the query hierarchy. NULL indicates to start from the top of the library.\n"
"    localOnly\n"
"    only return objects that also exist in the local directory\n"
"    oacLibAccessDenied\n"
"  Paramegers: (oaVCQueryDepth,oaDMObject)\n"
"    Calls: oaDMObjectIter getControlledObjects(oaVCQueryDepth depth,oaDMObject* top)\n"
"    Signature: getControlledObjects|simple-oaDMObjectIter|simple-oaVCQueryDepth,ptr-oaDMObject,simple-oaBoolean,\n"
"    oaLib::getControlledObjects\n"
"    This function returns an array of the objects that the version control system reports as being controlled in this library.\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to this library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    depth\n"
"    this parameter is used to control the depth that this function will go in the hierarchy when applying this operation. The enum values have the following meanings:\n"
"    oacFileVCQueryDepth: query only the immediate children files of this container\n"
"    oacCellVCQueryDepth: stop the query at the Cell level, not including \"cell files\"\n"
"    oacViewVCQueryDepth: stop the query at the View level, not including \"view files\"\n"
"    oacCellViewVCQueryDepth: stop the query at the CellView level, not including \"cellView\" files\n"
"    oacCellViewFileVCQueryDepth: stop the query at the CellView file level. This is currently the lowest level\n"
"    oacMaxQueryDepth: query to the bottom of the hierarchy\n"
"    top\n"
"    the object that represents the top of the query hierarchy. NULL indicates to start from the top of the library.\n"
"    localOnly\n"
"    only return objects that also exist in the local directory\n"
"    oacLibAccessDenied\n"
"  Paramegers: (oaVCQueryDepth,oaDMObject,oaBoolean)\n"
"    Calls: oaDMObjectIter getControlledObjects(oaVCQueryDepth depth,oaDMObject* top,oaBoolean localOnly)\n"
"    Signature: getControlledObjects|simple-oaDMObjectIter|simple-oaVCQueryDepth,ptr-oaDMObject,simple-oaBoolean,\n"
"    oaLib::getControlledObjects\n"
"    This function returns an array of the objects that the version control system reports as being controlled in this library.\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to this library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    depth\n"
"    this parameter is used to control the depth that this function will go in the hierarchy when applying this operation. The enum values have the following meanings:\n"
"    oacFileVCQueryDepth: query only the immediate children files of this container\n"
"    oacCellVCQueryDepth: stop the query at the Cell level, not including \"cell files\"\n"
"    oacViewVCQueryDepth: stop the query at the View level, not including \"view files\"\n"
"    oacCellViewVCQueryDepth: stop the query at the CellView level, not including \"cellView\" files\n"
"    oacCellViewFileVCQueryDepth: stop the query at the CellView file level. This is currently the lowest level\n"
"    oacMaxQueryDepth: query to the bottom of the hierarchy\n"
"    top\n"
"    the object that represents the top of the query hierarchy. NULL indicates to start from the top of the library.\n"
"    localOnly\n"
"    only return objects that also exist in the local directory\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaLib_getControlledObjects(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaDMObjectIter* result= new oaDMObjectIter(data.DataCall()->getControlledObjects());
            return PyoaDMObjectIter_FromoaDMObjectIter(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaVCQueryDepth)
    {
        PyParamoaVCQueryDepth p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaVCQueryDepth_Convert,&p1)) {
            oaDMObjectIter* result= new oaDMObjectIter(data.DataCall()->getControlledObjects(p1.Data()));
            return PyoaDMObjectIter_FromoaDMObjectIter(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaVCQueryDepth,oaDMObject)
    {
        PyParamoaVCQueryDepth p1;
        PyParamoaDMObject p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaVCQueryDepth_Convert,&p1,
              &PyoaDMObject_Convert,&p2)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaDMObjectIter* result= new oaDMObjectIter(data.DataCall()->getControlledObjects(p1.Data(),p2.Data()));
            return PyoaDMObjectIter_FromoaDMObjectIter(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaVCQueryDepth,oaDMObject,oaBoolean)
    {
        PyParamoaVCQueryDepth p1;
        PyParamoaDMObject p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaVCQueryDepth_Convert,&p1,
              &PyoaDMObject_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaDMObjectIter* result= new oaDMObjectIter(data.DataCall()->getControlledObjects(p1.Data(),p2.Data(),p3.Data()));
            return PyoaDMObjectIter_FromoaDMObjectIter(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLib, function: getControlledObjects, Choices are:\n"
        "    ()\n"
        "    (oaVCQueryDepth)\n"
        "    (oaVCQueryDepth,oaDMObject)\n"
        "    (oaVCQueryDepth,oaDMObject,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_getDMSystemName_doc[] = 
"Class: oaLib, Function: getDMSystemName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getDMSystemName(oaString& dmSystem) const\n"
"    Signature: getDMSystemName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of the DMSystem associated with this library.\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    dmSystem\n"
"    output parameter - the returned name of the DMSystem associated with this file\n"
;

static PyObject*
oaLib_getDMSystemName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getDMSystemName(p1.Data());
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
static char oaLib_getFullPath_doc[] = 
"Class: oaLib, Function: getFullPath\n"
"  Paramegers: (oaString)\n"
"    Calls: void getFullPath(oaString& fullPath) const\n"
"    Signature: getFullPath|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the full (absolute) path to this library.\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    fullPath\n"
"    output parameter - the returned full (absolute) path to this library\n"
;

static PyObject*
oaLib_getFullPath(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getFullPath(p1.Data());
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
static char oaLib_getGroups_doc[] = 
"Class: oaLib, Function: getGroups\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaGroup_oaLib getGroups() const\n"
"    Signature: getGroups|simple-oaCollection_oaGroup_oaLib|\n"
"    BrowseData: 1\n"
"    This function returns a collection of groups in this lib database.\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to this library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaLib_getGroups(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaGroup_oaLib* result= new oaCollection_oaGroup_oaLib(data.DataCall()->getGroups());
        return PyoaCollection_oaGroup_oaLib_FromoaCollection_oaGroup_oaLib(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_getGroupsByName_doc[] = 
"Class: oaLib, Function: getGroupsByName\n"
"  Paramegers: (oaString)\n"
"    Calls: oaCollection_oaGroup_oaLib getGroupsByName(const oaString& name) const\n"
"    Signature: getGroupsByName|simple-oaCollection_oaGroup_oaLib|cref-oaString,\n"
"    This function returns a collection of groups in this library database with the specified name .\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to the library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaLib_getGroupsByName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        oaCollection_oaGroup_oaLib* result= new oaCollection_oaGroup_oaLib(data.DataCall()->getGroupsByName(p1.Data()));
        return PyoaCollection_oaGroup_oaLib_FromoaCollection_oaGroup_oaLib(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_getGroupsByNameIter_doc[] = 
"Class: oaLib, Function: getGroupsByNameIter\n"
"  Paramegers: (oaString)\n"
"    Calls: oaIter_oaGroup getGroupsByNameIter(const oaString& name) const\n"
"    Signature: getGroupsByNameIter|simple-oaIter_oaGroup|cref-oaString,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of groups in this library database with the specified name .\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to the library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaLib_getGroupsByNameIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
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
static char oaLib_getGroupsIter_doc[] = 
"Class: oaLib, Function: getGroupsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaGroup getGroupsIter() const\n"
"    Signature: getGroupsIter|simple-oaIter_oaGroup|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of groups in this lib database.\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to this library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaLib_getGroupsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
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
static char oaLib_getMode_doc[] = 
"Class: oaLib, Function: getMode\n"
"  Paramegers: ()\n"
"    Calls: oaLibMode getMode() const\n"
"    Signature: getMode|simple-oaLibMode|\n"
"    BrowseData: 1\n"
"    oaLib::getMode\n"
"    This function returns the access mode of this library. This is the mode that was passed in when the library was opened or created.\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
;

static PyObject*
oaLib_getMode(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLibMode* result= new oaLibMode(data.DataCall()->getMode());
        return PyoaLibMode_FromoaLibMode(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_getName_doc[] = 
"Class: oaLib, Function: getName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getName(oaScalarName& name) const\n"
"    Signature: getName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the name of this library. The name is returned as an oaScalarName .\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getName(const oaNameSpace& ns,oaString& out) const\n"
"    Signature: getName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the name of this library. The name is returned as an oaString mapped to the specified namespace.\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
;

static PyObject*
oaLib_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
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
        "No Arg-Matching Function found for class: oaLib, function: getName, Choices are:\n"
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
static char oaLib_getPath_doc[] = 
"Class: oaLib, Function: getPath\n"
"  Paramegers: (oaString)\n"
"    Calls: void getPath(oaString& path) const\n"
"    Signature: getPath|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the path to this library.\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    path\n"
"    the path to the library directory is returned in this oaString .\n"
;

static PyObject*
oaLib_getPath(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
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
static char oaLib_getViews_doc[] = 
"Class: oaLib, Function: getViews\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaView_oaLib getViews() const\n"
"    Signature: getViews|simple-oaCollection_oaView_oaLib|\n"
"    BrowseData: 1\n"
"    This function returns a collection of views in this library.\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to this library does not exist. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaLib_getViews(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaView_oaLib* result= new oaCollection_oaView_oaLib(data.DataCall()->getViews());
        return PyoaCollection_oaView_oaLib_FromoaCollection_oaView_oaLib(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_getViewsByName_doc[] = 
"Class: oaLib, Function: getViewsByName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: oaCollection_oaView_oaLib getViewsByName(const oaScalarName& name) const\n"
"    Signature: getViewsByName|simple-oaCollection_oaView_oaLib|cref-oaScalarName,\n"
"    This function returns a collection of views in this library database with the specified name .\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to this library does not exist. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaLib_getViewsByName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaScalarName p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaScalarName_Convert,&p1)) {
        oaCollection_oaView_oaLib* result= new oaCollection_oaView_oaLib(data.DataCall()->getViewsByName(p1.Data()));
        return PyoaCollection_oaView_oaLib_FromoaCollection_oaView_oaLib(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_getViewsByNameIter_doc[] = 
"Class: oaLib, Function: getViewsByNameIter\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: oaIter_oaView getViewsByNameIter(const oaScalarName& name) const\n"
"    Signature: getViewsByNameIter|simple-oaIter_oaView|cref-oaScalarName,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of views in this library database with the specified name .\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to this library does not exist. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaLib_getViewsByNameIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaScalarName p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaScalarName_Convert,&p1)) {
        oaIter_oaView* result= new oaIter_oaView(data.DataCall()->getViewsByName(p1.Data()));
        return PyoaIter_oaView_FromoaIter_oaView(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_getViewsIter_doc[] = 
"Class: oaLib, Function: getViewsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaView getViewsIter() const\n"
"    Signature: getViewsIter|simple-oaIter_oaView|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of views in this library.\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to this library does not exist. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaLib_getViewsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaView* result= new oaIter_oaView(data.DataCall()->getViews());
        return PyoaIter_oaView_FromoaIter_oaView(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_getWorkingVersions_doc[] = 
"Class: oaLib, Function: getWorkingVersions\n"
"  Paramegers: ()\n"
"    Calls: oaDMObjectVersionRefIter getWorkingVersions() const\n"
"    Signature: getWorkingVersions|simple-oaDMObjectVersionRefIter|simple-oaVCQueryDepth,\n"
"    BrowseData: 1\n"
"    oaLib::getWorkingVersions\n"
"    This function retrieves the version information of this library. The version information reported back is the version of the file that is currently visible in the user's workspace. The objects in the array must all be versionable and belong to this library.\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to this library does not exist. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    depth\n"
"    this parameter is used to control the depth that this function will go in the hierarchy when applying this operation. The enum values have the following meanings:\n"
"    oacFileVCQueryDepth: query only the immediate children files of this container\n"
"    oacCellVCQueryDepth: stop the query at the Cell level, not including \"cell files\"\n"
"    oacViewVCQueryDepth: stop the query at the View level, not including \"view files\"\n"
"    oacCellViewVCQueryDepth: stop the query at the CellView level, not including \"cellView\" files\n"
"    oacCellViewFileVCQueryDepth: stop the query at the CellView file level. This is currently the lowest level\n"
"    oacMaxQueryDepth: query to the bottom of the hierarchy\n"
"    oacLibAccessDenied\n"
"  Paramegers: (oaVCQueryDepth)\n"
"    Calls: oaDMObjectVersionRefIter getWorkingVersions(oaVCQueryDepth depth) const\n"
"    Signature: getWorkingVersions|simple-oaDMObjectVersionRefIter|simple-oaVCQueryDepth,\n"
"    oaLib::getWorkingVersions\n"
"    This function retrieves the version information of this library. The version information reported back is the version of the file that is currently visible in the user's workspace. The objects in the array must all be versionable and belong to this library.\n"
"    Note: This function requires access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if access to this library does not exist. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    depth\n"
"    this parameter is used to control the depth that this function will go in the hierarchy when applying this operation. The enum values have the following meanings:\n"
"    oacFileVCQueryDepth: query only the immediate children files of this container\n"
"    oacCellVCQueryDepth: stop the query at the Cell level, not including \"cell files\"\n"
"    oacViewVCQueryDepth: stop the query at the View level, not including \"view files\"\n"
"    oacCellViewVCQueryDepth: stop the query at the CellView level, not including \"cellView\" files\n"
"    oacCellViewFileVCQueryDepth: stop the query at the CellView file level. This is currently the lowest level\n"
"    oacMaxQueryDepth: query to the bottom of the hierarchy\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaLib_getWorkingVersions(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaDMObjectVersionRefIter* result= new oaDMObjectVersionRefIter(data.DataCall()->getWorkingVersions());
            return PyoaDMObjectVersionRefIter_FromoaDMObjectVersionRefIter(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaVCQueryDepth)
    {
        PyParamoaVCQueryDepth p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaVCQueryDepth_Convert,&p1)) {
            oaDMObjectVersionRefIter* result= new oaDMObjectVersionRefIter(data.DataCall()->getWorkingVersions(p1.Data()));
            return PyoaDMObjectVersionRefIter_FromoaDMObjectVersionRefIter(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLib, function: getWorkingVersions, Choices are:\n"
        "    ()\n"
        "    (oaVCQueryDepth)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_getWritePath_doc[] = 
"Class: oaLib, Function: getWritePath\n"
"  Paramegers: (oaString)\n"
"    Calls: void getWritePath(oaString& writePath) const\n"
"    Signature: getWritePath|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    oaLib::getWritePath\n"
"    This function returns the write path to this library. This is the path to the directory that may be used as a place to create temporary files (using oaDMObject::getTempFile ). The writePath is a non-persistent attribute of the library.\n"
"    If the library is opened using oaLib::create , the writePath is the same as the library path. If the library is opened using oaLib::open , the writePath can be specified through the oaLib::open API.\n"
"    When a library is specified in the library definition file (see oaLibDefList Detailed Description), the writePath may be specified as an attribute using the ASSIGN syntax, with the library attribute name of \"writePath\". If the writePath is not specified, it will default to the library path.\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    writePath\n"
"    the returned write path for this library\n"
;

static PyObject*
oaLib_getWritePath(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getWritePath(p1.Data());
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
static char oaLib_hasVC_doc[] = 
"Class: oaLib, Function: hasVC\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasVC() const\n"
"    Signature: hasVC|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean that indicates whether or not the library has a version control system associated with it.\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
;

static PyObject*
oaLib_hasVC(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasVC());
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
static char oaLib_isMarkedToBeClosed_doc[] = 
"Class: oaLib, Function: isMarkedToBeClosed\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isMarkedToBeClosed() const\n"
"    Signature: isMarkedToBeClosed|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this library is marked to be closed. Libraries can be marked \"to be closed\" when the current session's library definitions are being reloaded from the library definitions file.\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
;

static PyObject*
oaLib_isMarkedToBeClosed(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isMarkedToBeClosed());
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
static char oaLib_isReadable_doc[] = 
"Class: oaLib, Function: isReadable\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isReadable() const\n"
"    Signature: isReadable|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if the library is readable; false if not.\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
;

static PyObject*
oaLib_isReadable(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isReadable());
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
static char oaLib_isWritable_doc[] = 
"Class: oaLib, Function: isWritable\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isWritable() const\n"
"    Signature: isWritable|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if the library is writable; false if not.\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
;

static PyObject*
oaLib_isWritable(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isWritable());
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
static char oaLib_releaseAccess_doc[] = 
"Class: oaLib, Function: releaseAccess\n"
"  Paramegers: ()\n"
"    Calls: void releaseAccess()\n"
"    Signature: releaseAccess|void-void|\n"
"    BrowseData: 0\n"
"    oaLib::releaseAccess\n"
"    This function requests that the current access on this library be released. An exception is thrown if the library is not currently being accessed.\n"
"    oacLibReleaseNoAccess\n"
;

static PyObject*
oaLib_releaseAccess(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->releaseAccess();
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
static char oaLib_setAttributes_doc[] = 
"Class: oaLib, Function: setAttributes\n"
"  Paramegers: (oaDMAttrArray)\n"
"    Calls: void setAttributes(const oaDMAttrArray& attrs)\n"
"    Signature: setAttributes|void-void|cref-oaDMAttrArray,\n"
"    This function sets the attributes specified in the given attrList array for this library and its associated Design Management (DM) and Version Control (VC) systems. The attributes are specific to the DM and VC systems, which may impose restrictions on what attributes may be changed.\n"
"    Note: This function requires write access to this library (through oaLib::getAccess ). An oacLibAccessDenied exception is thrown if write access to this library does not exist.\n"
"    For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    attrs\n"
"    Contains the attributes to set for the library and its associated DM and VC systems.\n"
"    oacLibAccessDenied\n"
;

static PyObject*
oaLib_setAttributes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibObject* self=(PyoaLibObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDMAttrArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMAttrArray_Convert,&p1)) {
        data.DataCall()->setAttributes(p1.Data());
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
static char oaLib_isNull_doc[] =
"Class: oaLib, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLib_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLib data;
    int convert_status=PyoaLib_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLib_assign_doc[] = 
"Class: oaLib, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLib_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLib data;
  int convert_status=PyoaLib_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLib p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLib_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaLib_methodlist[] = {
    {"calcVMSize",(PyCFunction)oaLib_calcVMSize,METH_VARARGS,oaLib_calcVMSize_doc},
    {"close",(PyCFunction)oaLib_close,METH_VARARGS,oaLib_close_doc},
    {"getAccess",(PyCFunction)oaLib_getAccess,METH_VARARGS,oaLib_getAccess_doc},
    {"getAccessLevel",(PyCFunction)oaLib_getAccessLevel,METH_VARARGS,oaLib_getAccessLevel_doc},
    {"getAttributes",(PyCFunction)oaLib_getAttributes,METH_VARARGS,oaLib_getAttributes_doc},
    {"getCellViews",(PyCFunction)oaLib_getCellViews,METH_VARARGS,oaLib_getCellViews_doc},
    {"getCellViewsIter",(PyCFunction)oaLib_getCellViewsIter,METH_VARARGS,oaLib_getCellViewsIter_doc},
    {"getCells",(PyCFunction)oaLib_getCells,METH_VARARGS,oaLib_getCells_doc},
    {"getCellsIter",(PyCFunction)oaLib_getCellsIter,METH_VARARGS,oaLib_getCellsIter_doc},
    {"getControlledObjects",(PyCFunction)oaLib_getControlledObjects,METH_VARARGS,oaLib_getControlledObjects_doc},
    {"getDMSystemName",(PyCFunction)oaLib_getDMSystemName,METH_VARARGS,oaLib_getDMSystemName_doc},
    {"getFullPath",(PyCFunction)oaLib_getFullPath,METH_VARARGS,oaLib_getFullPath_doc},
    {"getGroups",(PyCFunction)oaLib_getGroups,METH_VARARGS,oaLib_getGroups_doc},
    {"getGroupsByName",(PyCFunction)oaLib_getGroupsByName,METH_VARARGS,oaLib_getGroupsByName_doc},
    {"getGroupsByNameIter",(PyCFunction)oaLib_getGroupsByNameIter,METH_VARARGS,oaLib_getGroupsByNameIter_doc},
    {"getGroupsIter",(PyCFunction)oaLib_getGroupsIter,METH_VARARGS,oaLib_getGroupsIter_doc},
    {"getMode",(PyCFunction)oaLib_getMode,METH_VARARGS,oaLib_getMode_doc},
    {"getName",(PyCFunction)oaLib_getName,METH_VARARGS,oaLib_getName_doc},
    {"getPath",(PyCFunction)oaLib_getPath,METH_VARARGS,oaLib_getPath_doc},
    {"getViews",(PyCFunction)oaLib_getViews,METH_VARARGS,oaLib_getViews_doc},
    {"getViewsByName",(PyCFunction)oaLib_getViewsByName,METH_VARARGS,oaLib_getViewsByName_doc},
    {"getViewsByNameIter",(PyCFunction)oaLib_getViewsByNameIter,METH_VARARGS,oaLib_getViewsByNameIter_doc},
    {"getViewsIter",(PyCFunction)oaLib_getViewsIter,METH_VARARGS,oaLib_getViewsIter_doc},
    {"getWorkingVersions",(PyCFunction)oaLib_getWorkingVersions,METH_VARARGS,oaLib_getWorkingVersions_doc},
    {"getWritePath",(PyCFunction)oaLib_getWritePath,METH_VARARGS,oaLib_getWritePath_doc},
    {"hasVC",(PyCFunction)oaLib_hasVC,METH_VARARGS,oaLib_hasVC_doc},
    {"isMarkedToBeClosed",(PyCFunction)oaLib_isMarkedToBeClosed,METH_VARARGS,oaLib_isMarkedToBeClosed_doc},
    {"isReadable",(PyCFunction)oaLib_isReadable,METH_VARARGS,oaLib_isReadable_doc},
    {"isWritable",(PyCFunction)oaLib_isWritable,METH_VARARGS,oaLib_isWritable_doc},
    {"releaseAccess",(PyCFunction)oaLib_releaseAccess,METH_VARARGS,oaLib_releaseAccess_doc},
    {"setAttributes",(PyCFunction)oaLib_setAttributes,METH_VARARGS,oaLib_setAttributes_doc},
    {"isNull",(PyCFunction)oaLib_tp_isNull,METH_VARARGS,oaLib_isNull_doc},
    {"assign",(PyCFunction)oaLib_tp_assign,METH_VARARGS,oaLib_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLib_doc[] = 
"Class: oaLib\n"
"  An oaLib is a collection of design data represented as a library database and library data.\n"
"  The library database contains all information about the on-disk library including the cells, views, cellViews, associated data files on disk, and associated information about this data.\n"
"  Libraries have several different roles and purposes:\n"
"  Design libraries contain the user-created parts of a design hierarchy, including all the data and design components that make up a design.\n"
"  Reference libraries contain the master copies of the cells you can reference in a design.\n"
"  Technology libraries contain the technology parameters that correspond to a particular design methodology and fabrication technology. These parameters typically are contained in a technology database ( oaTech ).\n"
"  It is possible to store all these types of data in a single library. Usually, however, the reference data and technology parameters are stored in a single library.\n"
"  A library is also a logical container object that contains cells, views, cellViews, and files, as follows:\n"
"  A cell ( oaCell ) is a container object that contains cellViews and files. A single cell contains the data that describe an individual building block of a chip or system. A cell can contain multiple cellViews, each of which represent a different view of this cell.\n"
"  A view ( oaView ) is a container object that contains cellViews and files. A view is a specific representation of a cell. Different views can represent levels of abstraction for a design (behavior or gate), or different stages in the design process (RTL, post-synthesis, placed, routed).\n"
"  Each view has a designated viewType, which is persistent. The oaViewType utility class is used to represent a viewType. There are several reserved viewTypes used by OpenAccess, which are represented in the oaReservedViewType enum wrapper class. You can specify the view type with the viewType argument to oaDesign::open .\n"
"  A cellView ( oaCellView ) is a container object that contains files. CellViews also can contain OpenAccess databases such as an oaDesign or oaWafer .\n"
"  A cellView will always have a single oaDMFile that holds the primary data for the cellView and is known as the primary file. This correlates to the master file definition in previous versions of OpenAccess. The view's viewType attribute indicates the type of this file. The primary oaDMFile can be empty (or not exist on disk).\n"
"  A file ( oaDMFile ) contains data. Files can be created or modified using the oaDMFile API.\n"
"  The oaLib class can be observed by deriving from\n"
"  Library Access\n"
"  Before any library structure data -- such as oaCells, oaViews, oaCellViews, oaDMFiles, and their attributes -- is accessed, the application must obtain read library access. Before changing anything in the library structure, the application must obtain write library access. Read and write library access is obtained through the appropriate oaLib::getAccess call.\n"
"  For example, read-only oaLib functions, such as oaLib::getCells , oaLib::getViews , and oaLib::getCellViews , require read access to the library, and set() functions, such as oaLib::setAttributes , require write access to the library. However, oaLib static functions and oaLib functions that access static data on an oaLib, such as oaLib::create , oaLib::open , or oaLib::find , do not require library access.\n"
"  Note: If an oaLib function requires library access, this requirement is noted in the function description. If the library access must be write access, this requirement also is noted.\n"
"  You can use oaLib::hasAccess(), oaLib::hasWriteAccess and oaLib::getAccessType() to obtain information about library access status. Library access persists until ended through an oaLib::releaseAccess call.\n"
"  The OpenAccess design, wafer, tech, and parasitic database functions have library access built in -- users do not have to obtain library access to open or modify the oaDesign , oaWafer , oaTech , and parasitics databases. Before opening any of these database objects, OpenAccess first looks to see if the user has obtained library access; if not, OpenAccess will attempt to get access. If Open Access cannot get library access, an exception is thrown. When OA obtains library access, it is held for as short a time as possible within the span of the API call.\n"
"  For more Information on accessing and working with OpenAccess libraries, see OpenAccess 2.2 Libraries and Design Management in the Programmers Guide.\n"
"Constructors:\n"
"  Paramegers: (oaLib)\n"
"    Calls: (const oaLib&)\n"
"    Signature: oaLib||cref-oaLib,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLib_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLib",
    sizeof(PyoaLibObject),
    0,
    (destructor)oaLib_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLib_tp_compare,	/* tp_compare */
    (reprfunc)oaLib_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLib_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLib_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDMContainer_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLib_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLib_static_create_doc[] = 
"Class: oaLib, Function: create\n"
"  Paramegers: (oaScalarName,oaString)\n"
"    Calls: oaLib* create(const oaScalarName& name,const oaString& libPath)\n"
"    Signature: create|ptr-oaLib|cref-oaScalarName,cref-oaString,simple-oaLibMode,cref-oaString,cptr-oaDMAttrArray,\n"
"    This function creates the library using the specified name and attributes. The directory specified by libPath will be created to hold the library files.\n"
"    Example: If libPath is specified as usr1/mylibs/project1/cells , the /usr1/mylibs/project1/ parent directory must exist and /usr1/mylibs/project1/cells must not exist.\n"
"    Note that the creator of a library is responsible for adding the library definition (library name and path) of the newly-created library in the library definition file used by OpenAccess applications (see oaLibDefFile::addLib for more information).\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    name\n"
"    the name of the library to create\n"
"    libPath\n"
"    an absolute or relative path to the library directory. The specified directory will be created to hold the library files.\n"
"    mode\n"
"    the access mode of the library to create\n"
"    dmSystem\n"
"    the dmSystem name of the library to create\n"
"    dmAttrList\n"
"    A list of persistent attributes to be given to the new library. The set of valid attribute names and values are defined by a specific DM system and the Version Control system that it uses.\n"
"    oacLibNameExists\n"
"    - a library with the specified name already exists\n"
"    oacLibCouldNotCreate\n"
"    - libPath is an empty string; it specifies the name of an existing file or a non-empty directory; or the directory specified by libPath is not writeable\n"
"    Note: This function also throws an oaOSError if the libPath is not a syntactically valid directory name or the parent directory specified in libPath -- up to but not including the library name -- does not exist.\n"
"  Paramegers: (oaScalarName,oaString,oaLibMode)\n"
"    Calls: oaLib* create(const oaScalarName& name,const oaString& libPath,oaLibMode mode)\n"
"    Signature: create|ptr-oaLib|cref-oaScalarName,cref-oaString,simple-oaLibMode,cref-oaString,cptr-oaDMAttrArray,\n"
"    This function creates the library using the specified name and attributes. The directory specified by libPath will be created to hold the library files.\n"
"    Example: If libPath is specified as usr1/mylibs/project1/cells , the /usr1/mylibs/project1/ parent directory must exist and /usr1/mylibs/project1/cells must not exist.\n"
"    Note that the creator of a library is responsible for adding the library definition (library name and path) of the newly-created library in the library definition file used by OpenAccess applications (see oaLibDefFile::addLib for more information).\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    name\n"
"    the name of the library to create\n"
"    libPath\n"
"    an absolute or relative path to the library directory. The specified directory will be created to hold the library files.\n"
"    mode\n"
"    the access mode of the library to create\n"
"    dmSystem\n"
"    the dmSystem name of the library to create\n"
"    dmAttrList\n"
"    A list of persistent attributes to be given to the new library. The set of valid attribute names and values are defined by a specific DM system and the Version Control system that it uses.\n"
"    oacLibNameExists\n"
"    - a library with the specified name already exists\n"
"    oacLibCouldNotCreate\n"
"    - libPath is an empty string; it specifies the name of an existing file or a non-empty directory; or the directory specified by libPath is not writeable\n"
"    Note: This function also throws an oaOSError if the libPath is not a syntactically valid directory name or the parent directory specified in libPath -- up to but not including the library name -- does not exist.\n"
"  Paramegers: (oaScalarName,oaString,oaLibMode,oaString)\n"
"    Calls: oaLib* create(const oaScalarName& name,const oaString& libPath,oaLibMode mode,const oaString& dmSystem)\n"
"    Signature: create|ptr-oaLib|cref-oaScalarName,cref-oaString,simple-oaLibMode,cref-oaString,cptr-oaDMAttrArray,\n"
"    This function creates the library using the specified name and attributes. The directory specified by libPath will be created to hold the library files.\n"
"    Example: If libPath is specified as usr1/mylibs/project1/cells , the /usr1/mylibs/project1/ parent directory must exist and /usr1/mylibs/project1/cells must not exist.\n"
"    Note that the creator of a library is responsible for adding the library definition (library name and path) of the newly-created library in the library definition file used by OpenAccess applications (see oaLibDefFile::addLib for more information).\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    name\n"
"    the name of the library to create\n"
"    libPath\n"
"    an absolute or relative path to the library directory. The specified directory will be created to hold the library files.\n"
"    mode\n"
"    the access mode of the library to create\n"
"    dmSystem\n"
"    the dmSystem name of the library to create\n"
"    dmAttrList\n"
"    A list of persistent attributes to be given to the new library. The set of valid attribute names and values are defined by a specific DM system and the Version Control system that it uses.\n"
"    oacLibNameExists\n"
"    - a library with the specified name already exists\n"
"    oacLibCouldNotCreate\n"
"    - libPath is an empty string; it specifies the name of an existing file or a non-empty directory; or the directory specified by libPath is not writeable\n"
"    Note: This function also throws an oaOSError if the libPath is not a syntactically valid directory name or the parent directory specified in libPath -- up to but not including the library name -- does not exist.\n"
"  Paramegers: (oaScalarName,oaString,oaLibMode,oaString,oaDMAttrArray)\n"
"    Calls: oaLib* create(const oaScalarName& name,const oaString& libPath,oaLibMode mode,const oaString& dmSystem,const oaDMAttrArray* dmAttrList)\n"
"    Signature: create|ptr-oaLib|cref-oaScalarName,cref-oaString,simple-oaLibMode,cref-oaString,cptr-oaDMAttrArray,\n"
"    This function creates the library using the specified name and attributes. The directory specified by libPath will be created to hold the library files.\n"
"    Example: If libPath is specified as usr1/mylibs/project1/cells , the /usr1/mylibs/project1/ parent directory must exist and /usr1/mylibs/project1/cells must not exist.\n"
"    Note that the creator of a library is responsible for adding the library definition (library name and path) of the newly-created library in the library definition file used by OpenAccess applications (see oaLibDefFile::addLib for more information).\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    name\n"
"    the name of the library to create\n"
"    libPath\n"
"    an absolute or relative path to the library directory. The specified directory will be created to hold the library files.\n"
"    mode\n"
"    the access mode of the library to create\n"
"    dmSystem\n"
"    the dmSystem name of the library to create\n"
"    dmAttrList\n"
"    A list of persistent attributes to be given to the new library. The set of valid attribute names and values are defined by a specific DM system and the Version Control system that it uses.\n"
"    oacLibNameExists\n"
"    - a library with the specified name already exists\n"
"    oacLibCouldNotCreate\n"
"    - libPath is an empty string; it specifies the name of an existing file or a non-empty directory; or the directory specified by libPath is not writeable\n"
"    Note: This function also throws an oaOSError if the libPath is not a syntactically valid directory name or the parent directory specified in libPath -- up to but not including the library name -- does not exist.\n"
;

static PyObject*
oaLib_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaScalarName,oaString)
    {
        PyParamoaScalarName p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaScalarName_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            oaLibp result= (oaLib::create(p1.Data(),p2.Data()));
            return PyoaLib_FromoaLib(result);
        }
    }
    PyErr_Clear();
    // Case: (oaScalarName,oaString,oaLibMode)
    {
        PyParamoaScalarName p1;
        PyParamoaString p2;
        PyParamoaLibMode p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaScalarName_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaLibMode_Convert,&p3)) {
            oaLibp result= (oaLib::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaLib_FromoaLib(result);
        }
    }
    PyErr_Clear();
    // Case: (oaScalarName,oaString,oaLibMode,oaString)
    {
        PyParamoaScalarName p1;
        PyParamoaString p2;
        PyParamoaLibMode p3;
        PyParamoaString p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaScalarName_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaLibMode_Convert,&p3,
              &PyoaString_Convert,&p4)) {
            oaLibp result= (oaLib::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaLib_FromoaLib(result);
        }
    }
    PyErr_Clear();
    // Case: (oaScalarName,oaString,oaLibMode,oaString,oaDMAttrArray)
    {
        PyParamoaScalarName p1;
        PyParamoaString p2;
        PyParamoaLibMode p3;
        PyParamoaString p4;
        PyParamoaDMAttrArray p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaScalarName_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaLibMode_Convert,&p3,
              &PyoaString_Convert,&p4,
              &PyoaDMAttrArray_ConvertAof,&p5)) {
            oaLibp result= (oaLib::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.DataAof()));
            return PyoaLib_FromoaLib(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLib, function: create, Choices are:\n"
        "    (oaScalarName,oaString)\n"
        "    (oaScalarName,oaString,oaLibMode)\n"
        "    (oaScalarName,oaString,oaLibMode,oaString)\n"
        "    (oaScalarName,oaString,oaLibMode,oaString,oaDMAttrArray)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_static_exists_doc[] = 
"Class: oaLib, Function: exists\n"
"  Paramegers: (oaString)\n"
"    Calls: oaBoolean exists(const oaString& libPath)\n"
"    Signature: exists|simple-oaBoolean|cref-oaString,\n"
"    This function returns true if a library directory exists at the given libPath .\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    libPath\n"
"    an absolute or relative path to the library directory.\n"
;

static PyObject*
oaLib_static_exists(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        oaBoolean result= (oaLib::exists(p1.Data()));
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
static char oaLib_static_find_doc[] = 
"Class: oaLib, Function: find\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: oaLib* find(const oaScalarName& name)\n"
"    Signature: find|ptr-oaLib|cref-oaScalarName,\n"
"    This function attempts to find an open library with the specified name . If found, a pointer to the library is returned. If the library cannot be found, NULL is returned.\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    name\n"
"    the name of the library to be found.\n"
;

static PyObject*
oaLib_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarName p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaScalarName_Convert,&p1)) {
        oaLibp result= (oaLib::find(p1.Data()));
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
static char oaLib_static_getOpenLibs_doc[] = 
"Class: oaLib, Function: getOpenLibs\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaLib_oaLib getOpenLibs()\n"
"    Signature: getOpenLibs|simple-oaCollection_oaLib_oaLib|\n"
"    BrowseData: 1\n"
"    This function returns a collection of open library databases.\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
;

static PyObject*
oaLib_static_getOpenLibs(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaLib_oaLib* result= new oaCollection_oaLib_oaLib(oaLib::getOpenLibs());
        return PyoaCollection_oaLib_oaLib_FromoaCollection_oaLib_oaLib(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_static_getOpenLibsIter_doc[] = 
"Class: oaLib, Function: getOpenLibsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaLib getOpenLibsIter()\n"
"    Signature: getOpenLibsIter|simple-oaIter_oaLib|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of open library databases.\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
;

static PyObject*
oaLib_static_getOpenLibsIter(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaLib* result= new oaIter_oaLib(oaLib::getOpenLibs());
        return PyoaIter_oaLib_FromoaIter_oaLib(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLib_static_open_doc[] = 
"Class: oaLib, Function: open\n"
"  Paramegers: (oaScalarName,oaString)\n"
"    Calls: oaLib* open(const oaScalarName& name,const oaString& libPath)\n"
"    Signature: open|ptr-oaLib|cref-oaScalarName,cref-oaString,cref-oaString,simple-oaLibMode,\n"
"    This function opens an existing library at the given path, using the specified name and attributes. An oacCannotOpenOpenedLib exception is thrown if the library is open; an oacLibNameDoesNotMatchPath exception is thrown if the specified name does not match the actual name of the library found at the specified libPath .\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    name\n"
"    the name of the library to open\n"
"    libPath\n"
"    an absolute or relative path to the library directory\n"
"    writePath\n"
"    the path that is writable for the opened library\n"
"    mode\n"
"    the mode of the library to open\n"
"    oacCannotOpenOpenedLib\n"
"    oacLibNameDoesNotMatchPath\n"
"  Paramegers: (oaScalarName,oaString,oaString)\n"
"    Calls: oaLib* open(const oaScalarName& name,const oaString& libPath,const oaString& writePath)\n"
"    Signature: open|ptr-oaLib|cref-oaScalarName,cref-oaString,cref-oaString,simple-oaLibMode,\n"
"    This function opens an existing library at the given path, using the specified name and attributes. An oacCannotOpenOpenedLib exception is thrown if the library is open; an oacLibNameDoesNotMatchPath exception is thrown if the specified name does not match the actual name of the library found at the specified libPath .\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    name\n"
"    the name of the library to open\n"
"    libPath\n"
"    an absolute or relative path to the library directory\n"
"    writePath\n"
"    the path that is writable for the opened library\n"
"    mode\n"
"    the mode of the library to open\n"
"    oacCannotOpenOpenedLib\n"
"    oacLibNameDoesNotMatchPath\n"
"  Paramegers: (oaScalarName,oaString,oaString,oaLibMode)\n"
"    Calls: oaLib* open(const oaScalarName& name,const oaString& libPath,const oaString& writePath,oaLibMode mode)\n"
"    Signature: open|ptr-oaLib|cref-oaScalarName,cref-oaString,cref-oaString,simple-oaLibMode,\n"
"    This function opens an existing library at the given path, using the specified name and attributes. An oacCannotOpenOpenedLib exception is thrown if the library is open; an oacLibNameDoesNotMatchPath exception is thrown if the specified name does not match the actual name of the library found at the specified libPath .\n"
"    Note: This function does not require library access. For more information on library access, see Library Access in the detailed description for oaLib.\n"
"    name\n"
"    the name of the library to open\n"
"    libPath\n"
"    an absolute or relative path to the library directory\n"
"    writePath\n"
"    the path that is writable for the opened library\n"
"    mode\n"
"    the mode of the library to open\n"
"    oacCannotOpenOpenedLib\n"
"    oacLibNameDoesNotMatchPath\n"
;

static PyObject*
oaLib_static_open(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaScalarName,oaString)
    {
        PyParamoaScalarName p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaScalarName_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            oaLibp result= (oaLib::open(p1.Data(),p2.Data()));
            return PyoaLib_FromoaLib(result);
        }
    }
    PyErr_Clear();
    // Case: (oaScalarName,oaString,oaString)
    {
        PyParamoaScalarName p1;
        PyParamoaString p2;
        PyParamoaString p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaScalarName_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaString_Convert,&p3)) {
            oaLibp result= (oaLib::open(p1.Data(),p2.Data(),p3.Data()));
            return PyoaLib_FromoaLib(result);
        }
    }
    PyErr_Clear();
    // Case: (oaScalarName,oaString,oaString,oaLibMode)
    {
        PyParamoaScalarName p1;
        PyParamoaString p2;
        PyParamoaString p3;
        PyParamoaLibMode p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaScalarName_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaString_Convert,&p3,
              &PyoaLibMode_Convert,&p4)) {
            oaLibp result= (oaLib::open(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaLib_FromoaLib(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLib, function: open, Choices are:\n"
        "    (oaScalarName,oaString)\n"
        "    (oaScalarName,oaString,oaString)\n"
        "    (oaScalarName,oaString,oaString,oaLibMode)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLib_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaLib_static_create,METH_VARARGS,oaLib_static_create_doc},
    {"static_exists",(PyCFunction)oaLib_static_exists,METH_VARARGS,oaLib_static_exists_doc},
    {"static_find",(PyCFunction)oaLib_static_find,METH_VARARGS,oaLib_static_find_doc},
    {"static_getOpenLibs",(PyCFunction)oaLib_static_getOpenLibs,METH_VARARGS,oaLib_static_getOpenLibs_doc},
    {"static_getOpenLibsIter",(PyCFunction)oaLib_static_getOpenLibsIter,METH_VARARGS,oaLib_static_getOpenLibsIter_doc},
    {"static_open",(PyCFunction)oaLib_static_open,METH_VARARGS,oaLib_static_open_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLib_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLib_Type)<0) {
      printf("** PyType_Ready failed for: oaLib\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLib",
           (PyObject*)(&PyoaLib_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLib\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLib_Type.tp_dict;
    for(method=oaLib_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Array for class: oaLib
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLib_Array_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLib_Array_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaLib_ArrayObject* self = (PyoaLib_ArrayObject*)gself;
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
    /* Case: (oaLib_Array) */
    {
        PyParamoaLib_Array p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLib_Array_Convert,&p1)) {
            self->data.TakeAway(p1);
            return gself;
        }
    }
    /* Error */
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaLib_Array, Choices are:\n"
        "    ()\n"
        "    (int)\n"
        "    (oaLib_Array)\n"
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
oaLib_Array_dealloc(PyObject* gself)
{
    PyoaLib_ArrayObject* self = (PyoaLib_ArrayObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaLib_Array_str(PyObject *ob)
{
    PyParamoaLib_Array value;
    int convert_status=PyoaLib_Array_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* lst=PyoaLib_Array_CreateList(value);
    PyObject* result=PyObject_Str(lst);
    Py_DECREF(lst);
    return result;
}

// ------------------------------------------------------------------
static PyObject*
oaLib_Array_repr(PyObject *ob)
{
    PyParamoaLib_Array value;
    int convert_status=PyoaLib_Array_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* lst=PyoaLib_Array_CreateList(value);
    PyObject* result=PyObject_Repr(lst);
    Py_DECREF(lst);
    return result;
}

// ------------------------------------------------------------------
static int
oaLib_Array_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLib_Array p1;
    PyParamoaLib_Array p2;
    int s1=PyoaLib_Array_Convert(ob1,&p1);
    int s2=PyoaLib_Array_Convert(ob2,&p2);
    assert(s1!=0);
    assert(s2!=0);
    PyObject* l1=PyoaLib_Array_CreateList(p1);
    PyObject* l2=PyoaLib_Array_CreateList(p2);
    int result=PyObject_Compare(l1,l2);
    Py_DECREF(l1);
    Py_DECREF(l2);
    return result;
}

// ------------------------------------------------------------------
int
PyoaLib_Array_Convert(PyObject* ob,PyParamoaLib_Array* result)
{
  Pyoa_ssize_t len,i;
  if (PyoaLib_Array_Check(ob)) {
    PyoaLib_ArrayObject* self = (PyoaLib_ArrayObject*)ob;
    result->Borrow(self->data);
  }
  else if (PyList_Check(ob)) {
    len=PyList_Size(ob);
    result->SetLen(len);
    PyParamoaLib data;
    for(i=0;i<len;i++) {
      PyObject* a=PyList_GetItem(ob,i);
      if (!PyoaLib_Convert(a,&data)) return 0;
      result->SetItem(i,data.Data());
    }
  }
  else if (PyTuple_Check(ob)) {
    len=PyTuple_Size(ob);
    result->SetLen(len);
    PyParamoaLib data;
    for(i=0;i<len;i++) {
      PyObject* a=PyTuple_GetItem(ob,i);
      if (!PyoaLib_Convert(a,&data)) return 0;
      result->SetItem(i,data.Data());
    }
  }
  else {
    PyErr_SetString(PyExc_TypeError,
      "Convertion of parameter to class: oaLib_Array Failed");
    return 0;
  }
  return 1;
}

// ------------------------------------------------------------------
PyObject* PyoaLib_Array_FromoaLib_Array(const oaLib_Array& value)
{
  PyObject* gself = PyoaLib_Array_Type.tp_alloc(&PyoaLib_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaLib_ArrayObject* self = (PyoaLib_ArrayObject*)gself;
  self->data = value;
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaLib_Array_FromoaLib_Array(PyTypeoaLib* data,Pyoa_ssize_t len,PyObject* lock)
{
  PyObject* gself = PyoaLib_Array_Type.tp_alloc(&PyoaLib_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaLib_ArrayObject* self = (PyoaLib_ArrayObject*)gself;
  self->data.Borrow(data,len);
  self->borrow = 1;
  self->locks=NULL;
  if (lock) PyoaLockObject(self->locks,lock);
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaLib_Array_CreateList(PyParamoaLib_Array& value)
{
  Pyoa_ssize_t i;
  PyObject* lst=PyList_New(value.Len());
  for(i=0;i<value.Len();i++) {
    PyObject* ob=PyoaLib_FromoaLib(value.Data()[i]);
    PyList_SetItem(lst,i,ob);
  }
  return lst;
}

// ------------------------------------------------------------------
// Methods
// ------------------------------------------------------------------
static char oaLib_Array_assign_doc[] = 
"Class: oaLib_Array, Function: assign\n"
"  Paramegers: (oaLib_Array)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaLib_Array_assign(PyObject* ob, PyObject *args)
{
  PyoaLib_ArrayObject* self=(PyoaLib_ArrayObject*)ob;
  try {
    PyParamoaLib_Array p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLib_Array_Convert,&p1)) {
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
static char oaLib_Array_list_doc[] = 
"Class: oaLib_Array, Function: list\n"
"  Paramegers: ()\n"
"    This function returns the current value as a list.\n"
;

static PyObject*
oaLib_Array_list(PyObject* ob, PyObject *args)
{
  PyoaLib_ArrayObject* self=(PyoaLib_ArrayObject*)ob;
  try {
    if (PyArg_ParseTuple(args,(char*)"")) {
      return PyoaLib_Array_CreateList(self->data);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------
static PyMethodDef oaLib_Array_methodlist[] = {
    {"assign",(PyCFunction)oaLib_Array_assign,METH_VARARGS,oaLib_Array_assign_doc},
    {"list",(PyCFunction)oaLib_Array_list,METH_VARARGS,oaLib_Array_list_doc},
   {NULL,NULL,0,NULL}
};

// ------------------------------------------------------------------
static PyObject*
oaLib_Array_index_get(PyObject* ob,Pyoa_ssize_t index)
{
  PyoaLib_ArrayObject* self=(PyoaLib_ArrayObject*)ob;
  try {
    PyParamoaLib_Array data;
    int convert_status=PyoaLib_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return NULL;
    }
    return PyoaLib_FromoaLib(data.GetItemPtr(index),1,self->locks);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static Pyoa_ssize_t
oaLib_Array_index_get_length(PyObject* ob)
{
    PyParamoaLib_Array data;
    int convert_status=PyoaLib_Array_Convert(ob,&data);
    assert(convert_status!=0);
    return data.Len();
}

// ------------------------------------------------------------------
static int
oaLib_Array_index_set(PyObject *ob, Pyoa_ssize_t index, PyObject* value)
{
  try {
    PyParamoaLib_Array data;
    PyParamoaLib dataitem;
    int convert_status=PyoaLib_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return -1;
    }
    if (PyoaLib_Convert(value,&dataitem)==0) return -1;
    data.SetItem(index,dataitem.Data());
    return 0;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return 0;
  }
}

// ------------------------------------------------------------------
static char oaLib_Array_doc[] =
"Class: oaLib_Array\n"
"  The oaLib_Array utility class provides an array of oaLib.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaLib_Array()\n"
"    Signature: oaLib_Array||\n"
"    This is the default constructor for the oaLib_Array class. This constructor creates an empty oaLib_Array.\n"
"  Paramegers: (oaLib_Array)\n"
"    Calls: (const oaLib_Array&)\n"
"    Signature: oaLib_Array||cref-oaLib_Array,\n"
;

// ------------------------------------------------------------------
static PySequenceMethods oaLib_Array_as_sequence = {
    (Pyoa_inquiry)oaLib_Array_index_get_length, /* sq_length */
    (Pyoa_binaryfunc)0,              /* sq_concat */
    (Pyoa_intargfunc)0,              /* sq_repeat */
    (Pyoa_intargfunc)oaLib_Array_index_get, /* sq_item */
    (Pyoa_intintargfunc)0,           /* sq_slice */
    (Pyoa_intobjargproc)oaLib_Array_index_set,      /* sq_ass_item */
};

// ------------------------------------------------------------------
PyTypeObject PyoaLib_Array_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLib_Array",
    sizeof(PyoaLib_ArrayObject),
    0,
    oaLib_Array_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaLib_Array_compare,    /* tp_compare */
    oaLib_Array_repr,      /* tp_repr */
    0,                                  /* tp_as_number */
    &oaLib_Array_as_sequence,  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaLib_Array_str,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLib_Array_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaLib_Array_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaLib_Array_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
int
PyoaLib_Array_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLib_Array_Type)<0) {
      printf("** PyType_Ready failed for: oaLib_Array\n");
      return -1;
    }
    if (PyDict_SetItemString(mod_dict,"oaLib_Array",
           (PyObject*)(&PyoaLib_Array_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLib_Array\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaLibAccess
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLibAccess_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLibAccess_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLibAccessObject* self = (PyoaLibAccessObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLibAccessEnum)
    {
        PyParamoaLibAccessEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaLibAccessEnum_Convert,&p1)) {
            self->value =  new oaLibAccess(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaLibAccess(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaLibAccess)
    {
        PyParamoaLibAccess p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLibAccess_Convert,&p1)) {
            self->value= new oaLibAccess(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaLibAccess, Choices are:\n"
        "    (oaLibAccessEnum)\n"
        "    (oaString)\n"
        "    (oaLibAccess)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaLibAccess_tp_dealloc(PyoaLibAccessObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLibAccess_tp_repr(PyObject *ob)
{
    PyParamoaLibAccess value;
    int convert_status=PyoaLibAccess_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[33];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaLibAccess::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLibAccess_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLibAccess v1;
    PyParamoaLibAccess v2;
    int convert_status1=PyoaLibAccess_Convert(ob1,&v1);
    int convert_status2=PyoaLibAccess_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLibAccess_Convert(PyObject* ob,PyParamoaLibAccess* result)
{
    if (ob == NULL) return 1;
    if (PyoaLibAccess_Check(ob)) {
        result->SetData(  ((PyoaLibAccessObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLibAccess Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLibAccess_FromoaLibAccess(oaLibAccess* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaLibAccess_Type.tp_alloc(&PyoaLibAccess_Type,0);
        if (bself == NULL) return bself;
        PyoaLibAccessObject* self = (PyoaLibAccessObject*)bself;
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
static char oaLibAccess_getName_doc[] = 
"Class: oaLibAccess, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the string name of the oaLibAccessEnum value set on this oaLibAccess wrapper object.\n"
;

static PyObject*
oaLibAccess_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibAccess data;
    int convert_status=PyoaLibAccess_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibAccessObject* self=(PyoaLibAccessObject*)ob;

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
static char oaLibAccess_oaLibAccessEnum_doc[] = 
"Class: oaLibAccess, Function: oaLibAccessEnum\n"
"  Paramegers: ()\n"
"    Calls: oaLibAccessEnum oaLibAccessEnum() const\n"
"    Signature: operator oaLibAccessEnum|simple-oaLibAccessEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaLibAccess object into its corresponding oaLibAccessEnum value.\n"
;

static PyObject*
oaLibAccess_oaLibAccessEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibAccess data;
    int convert_status=PyoaLibAccess_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibAccessObject* self=(PyoaLibAccessObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLibAccessEnum result= (data.DataCall()->operator oaLibAccessEnum());
        return PyoaLibAccessEnum_FromoaLibAccessEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaLibAccess_assign_doc[] = 
"Class: oaLibAccess, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLibAccess_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLibAccess data;
  int convert_status=PyoaLibAccess_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLibAccess p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLibAccess_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaLibAccess_methodlist[] = {
    {"getName",(PyCFunction)oaLibAccess_getName,METH_VARARGS,oaLibAccess_getName_doc},
    {"oaLibAccessEnum",(PyCFunction)oaLibAccess_oaLibAccessEnum,METH_VARARGS,oaLibAccess_oaLibAccessEnum_doc},
    {"assign",(PyCFunction)oaLibAccess_tp_assign,METH_VARARGS,oaLibAccess_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLibAccess_doc[] = 
"Class: oaLibAccess\n"
"  oaLibAccessEnum\n"
"  oaLibAccess is a utility wrapper class that encapsulates oaLibAccessEnum values, which represent different types of library access.\n"
"Constructors:\n"
"  Paramegers: (oaLibAccessEnum)\n"
"    Calls: oaLibAccess(oaLibAccessEnum valueIn)\n"
"    Signature: oaLibAccess||simple-oaLibAccessEnum,\n"
"    This oaLibAccess constructor takes an oaLibAccessEnum value as input.\n"
"    valueIn\n"
"    an oaLibAccessEnum value\n"
"  Paramegers: (oaString)\n"
"    Calls: oaLibAccess(const oaString& name)\n"
"    Signature: oaLibAccess||cref-oaString,\n"
"    This oaLibAccess constructor takes the oaString name of an oaLibAccessEnum value as input.\n"
"    name\n"
"    the oaString name of an oaLibAccessEnum value\n"
"    oacInvalidLibAccessName\n"
"  Paramegers: (oaLibAccess)\n"
"    Calls: (const oaLibAccess&)\n"
"    Signature: oaLibAccess||cref-oaLibAccess,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLibAccess_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLibAccess",
    sizeof(PyoaLibAccessObject),
    0,
    (destructor)oaLibAccess_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLibAccess_tp_compare,	/* tp_compare */
    (reprfunc)oaLibAccess_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLibAccess_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLibAccess_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLibAccess_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLibAccess_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLibAccess_Type)<0) {
      printf("** PyType_Ready failed for: oaLibAccess\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLibAccess",
           (PyObject*)(&PyoaLibAccess_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLibAccess\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaLibAccessEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaLibAccessEnum_Convert(PyObject* ob,PyParamoaLibAccessEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacReadLibAccess")==0) { result->SetData(oacReadLibAccess); return 1;}
        if (strcasecmp(str,"oacWriteLibAccess")==0) { result->SetData(oacWriteLibAccess); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaLibAccessEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLibAccessEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaLibAccessEnum_FromoaLibAccessEnum(oaLibAccessEnum ob)
{
    if (ob==oacReadLibAccess) return PyString_FromString("oacReadLibAccess");
    if (ob==oacWriteLibAccess) return PyString_FromString("oacWriteLibAccess");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaLibAccessEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaLibAccessEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaLibAccessEnum_FromoaLibAccessEnum(oaLibAccessEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaLibAccessEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaLibAccessEnum_doc[] =
"Type convert function for enum: oaLibAccessEnum";
                               
static PyMethodDef PyoaLibAccessEnum_method =
  {"oaLibAccessEnum",(PyCFunction)PyoaLibAccessEnum_TypeFunction,METH_VARARGS,oaLibAccessEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaLibAccessEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacReadLibAccess");
    PyDict_SetItemString(mod_dict,"oacReadLibAccess",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWriteLibAccess");
    PyDict_SetItemString(mod_dict,"oacWriteLibAccess",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaLibAccessEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaLibAccessEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaLibAccessEnum\n");
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
// Wrapper Implementation for Class: oaLibAccessLevel
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLibAccessLevel_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLibAccessLevel_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLibAccessLevelObject* self = (PyoaLibAccessLevelObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLibAccessLevelEnum)
    {
        PyParamoaLibAccessLevelEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaLibAccessLevelEnum_Convert,&p1)) {
            self->value =  new oaLibAccessLevel(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaLibAccessLevel(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaLibAccessLevel)
    {
        PyParamoaLibAccessLevel p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLibAccessLevel_Convert,&p1)) {
            self->value= new oaLibAccessLevel(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaLibAccessLevel, Choices are:\n"
        "    (oaLibAccessLevelEnum)\n"
        "    (oaString)\n"
        "    (oaLibAccessLevel)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaLibAccessLevel_tp_dealloc(PyoaLibAccessLevelObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLibAccessLevel_tp_repr(PyObject *ob)
{
    PyParamoaLibAccessLevel value;
    int convert_status=PyoaLibAccessLevel_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[38];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaLibAccessLevel::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLibAccessLevel_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLibAccessLevel v1;
    PyParamoaLibAccessLevel v2;
    int convert_status1=PyoaLibAccessLevel_Convert(ob1,&v1);
    int convert_status2=PyoaLibAccessLevel_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLibAccessLevel_Convert(PyObject* ob,PyParamoaLibAccessLevel* result)
{
    if (ob == NULL) return 1;
    if (PyoaLibAccessLevel_Check(ob)) {
        result->SetData(  ((PyoaLibAccessLevelObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLibAccessLevel Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLibAccessLevel_FromoaLibAccessLevel(oaLibAccessLevel* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaLibAccessLevel_Type.tp_alloc(&PyoaLibAccessLevel_Type,0);
        if (bself == NULL) return bself;
        PyoaLibAccessLevelObject* self = (PyoaLibAccessLevelObject*)bself;
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
static char oaLibAccessLevel_getName_doc[] = 
"Class: oaLibAccessLevel, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name associated with the oaLibAccessLevelEnum value set on this oaLibAccessLevel object.\n"
;

static PyObject*
oaLibAccessLevel_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibAccessLevel data;
    int convert_status=PyoaLibAccessLevel_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibAccessLevelObject* self=(PyoaLibAccessLevelObject*)ob;

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
static char oaLibAccessLevel_oaLibAccessLevelEnum_doc[] = 
"Class: oaLibAccessLevel, Function: oaLibAccessLevelEnum\n"
"  Paramegers: ()\n"
"    Calls: oaLibAccessLevelEnum oaLibAccessLevelEnum() const\n"
"    Signature: operator oaLibAccessLevelEnum|simple-oaLibAccessLevelEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaLibAccessLevel object into its corresponding oaLibAccessLevelEnum value.\n"
;

static PyObject*
oaLibAccessLevel_oaLibAccessLevelEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibAccessLevel data;
    int convert_status=PyoaLibAccessLevel_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibAccessLevelObject* self=(PyoaLibAccessLevelObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLibAccessLevelEnum result= (data.DataCall()->operator oaLibAccessLevelEnum());
        return PyoaLibAccessLevelEnum_FromoaLibAccessLevelEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaLibAccessLevel_assign_doc[] = 
"Class: oaLibAccessLevel, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLibAccessLevel_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLibAccessLevel data;
  int convert_status=PyoaLibAccessLevel_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLibAccessLevel p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLibAccessLevel_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaLibAccessLevel_methodlist[] = {
    {"getName",(PyCFunction)oaLibAccessLevel_getName,METH_VARARGS,oaLibAccessLevel_getName_doc},
    {"oaLibAccessLevelEnum",(PyCFunction)oaLibAccessLevel_oaLibAccessLevelEnum,METH_VARARGS,oaLibAccessLevel_oaLibAccessLevelEnum_doc},
    {"assign",(PyCFunction)oaLibAccessLevel_tp_assign,METH_VARARGS,oaLibAccessLevel_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLibAccessLevel_doc[] = 
"Class: oaLibAccessLevel\n"
"  oaLibAccessLevelEnum\n"
"  oaLibAccessLevel a utility enum wrapper class that encapsulates oaLibAccessLevelEnum values, which indicate the current library access level. There are three levels: read, write, and none.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"Constructors:\n"
"  Paramegers: (oaLibAccessLevelEnum)\n"
"    Calls: oaLibAccessLevel(oaLibAccessLevelEnum valueIn)\n"
"    Signature: oaLibAccessLevel||simple-oaLibAccessLevelEnum,\n"
"    This oaLibAccessLevel constructor takes an oaLibAccessLevelEnum value as input.\n"
"    valueIn\n"
"    an oaLibAccessLevelEnum value\n"
"  Paramegers: (oaString)\n"
"    Calls: oaLibAccessLevel(const oaString& name)\n"
"    Signature: oaLibAccessLevel||cref-oaString,\n"
"    This oaLibAccessLevel constructor takes an oaLibAccessLevelEnum name as input.\n"
"    name\n"
"    the name associated with a valid oaLibAccessLevelEnum value\n"
"    oacInvalidLibAccessLevelName\n"
"  Paramegers: (oaLibAccessLevel)\n"
"    Calls: (const oaLibAccessLevel&)\n"
"    Signature: oaLibAccessLevel||cref-oaLibAccessLevel,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLibAccessLevel_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLibAccessLevel",
    sizeof(PyoaLibAccessLevelObject),
    0,
    (destructor)oaLibAccessLevel_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLibAccessLevel_tp_compare,	/* tp_compare */
    (reprfunc)oaLibAccessLevel_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLibAccessLevel_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLibAccessLevel_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLibAccessLevel_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLibAccessLevel_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLibAccessLevel_Type)<0) {
      printf("** PyType_Ready failed for: oaLibAccessLevel\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLibAccessLevel",
           (PyObject*)(&PyoaLibAccessLevel_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLibAccessLevel\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaLibAccessLevelEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaLibAccessLevelEnum_Convert(PyObject* ob,PyParamoaLibAccessLevelEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacNoLibAccessLevel")==0) { result->SetData(oacNoLibAccessLevel); return 1;}
        if (strcasecmp(str,"oacReadLibAccessLevel")==0) { result->SetData(oacReadLibAccessLevel); return 1;}
        if (strcasecmp(str,"oacWriteLibAccessLevel")==0) { result->SetData(oacWriteLibAccessLevel); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaLibAccessLevelEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLibAccessLevelEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaLibAccessLevelEnum_FromoaLibAccessLevelEnum(oaLibAccessLevelEnum ob)
{
    if (ob==oacNoLibAccessLevel) return PyString_FromString("oacNoLibAccessLevel");
    if (ob==oacReadLibAccessLevel) return PyString_FromString("oacReadLibAccessLevel");
    if (ob==oacWriteLibAccessLevel) return PyString_FromString("oacWriteLibAccessLevel");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaLibAccessLevelEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaLibAccessLevelEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaLibAccessLevelEnum_FromoaLibAccessLevelEnum(oaLibAccessLevelEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaLibAccessLevelEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaLibAccessLevelEnum_doc[] =
"Type convert function for enum: oaLibAccessLevelEnum";
                               
static PyMethodDef PyoaLibAccessLevelEnum_method =
  {"oaLibAccessLevelEnum",(PyCFunction)PyoaLibAccessLevelEnum_TypeFunction,METH_VARARGS,oaLibAccessLevelEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaLibAccessLevelEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacNoLibAccessLevel");
    PyDict_SetItemString(mod_dict,"oacNoLibAccessLevel",value);
    Py_DECREF(value);
    value=PyString_FromString("oacReadLibAccessLevel");
    PyDict_SetItemString(mod_dict,"oacReadLibAccessLevel",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWriteLibAccessLevel");
    PyDict_SetItemString(mod_dict,"oacWriteLibAccessLevel",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaLibAccessLevelEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaLibAccessLevelEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaLibAccessLevelEnum\n");
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
// Wrapper Implementation for Class: oaLibDMData
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLibDMData_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLibDMData_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLibDMDataObject* self = (PyoaLibDMDataObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLibDMData)
    {
        PyParamoaLibDMData p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLibDMData_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLibDMData, Choices are:\n"
        "    (oaLibDMData)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaLibDMData_tp_dealloc(PyoaLibDMDataObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLibDMData_tp_repr(PyObject *ob)
{
    PyParamoaLibDMData value;
    int convert_status=PyoaLibDMData_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[33];
    sprintf(buffer,"<oaLibDMData::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLibDMData_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLibDMData v1;
    PyParamoaLibDMData v2;
    int convert_status1=PyoaLibDMData_Convert(ob1,&v1);
    int convert_status2=PyoaLibDMData_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLibDMData_Convert(PyObject* ob,PyParamoaLibDMData* result)
{
    if (ob == NULL) return 1;
    if (PyoaLibDMData_Check(ob)) {
        result->SetData( (oaLibDMData**) ((PyoaLibDMDataObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLibDMData Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLibDMData_FromoaLibDMData(oaLibDMData** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLibDMData* data=*value;
        PyObject* bself = PyoaLibDMData_Type.tp_alloc(&PyoaLibDMData_Type,0);
        if (bself == NULL) return bself;
        PyoaLibDMDataObject* self = (PyoaLibDMDataObject*)bself;
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
PyObject* PyoaLibDMData_FromoaLibDMData(oaLibDMData* data)
{
    if (data) {
       PyObject* bself = PyoaLibDMData_Type.tp_alloc(&PyoaLibDMData_Type,0);
       if (bself == NULL) return bself;
       PyoaLibDMDataObject* self = (PyoaLibDMDataObject*)bself;
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
static char oaLibDMData_doc[] = 
"Class: oaLibDMData\n"
"  oaLibDMData objects represent database objects that can be associated with a DM library and can be used to persistently store properties ( oaProp objects), groups ( oaGroup objects), group members ( oaGroupMember objects) and application objects (see oaAppObject ).\n"
"  The oaDMData class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaLibDMData)\n"
"    Calls: (const oaLibDMData&)\n"
"    Signature: oaLibDMData||cref-oaLibDMData,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLibDMData_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLibDMData",
    sizeof(PyoaLibDMDataObject),
    0,
    (destructor)oaLibDMData_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLibDMData_tp_compare,	/* tp_compare */
    (reprfunc)oaLibDMData_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLibDMData_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDMData_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLibDMData_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLibDMData_static_destroy_doc[] = 
"Class: oaLibDMData, Function: destroy\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void destroy(const oaScalarName& libName)\n"
"    Signature: destroy|void-void|cref-oaScalarName,\n"
"    This function attempts to remove this oaLibDMData from disk. It throws an exception if the oaLibDMData is currently open or if the oaLibDMData cannot be found on disk.\n"
"    libName\n"
"    name of the library associated with the DMData\n"
"    oacLibNotFound\n"
"    the library with the specified name cannot be found\n"
"    oacDestroyDMDataOpen\n"
"    the DMData is open\n"
"    oacDMDataCannotGetWriteAccess\n"
"    cannot get write access to the DMData\n"
"    oacDestroyDMDataDoesNotExist\n"
"    the DM Data does not exist on disk\n"
;

static PyObject*
oaLibDMData_static_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarName p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaScalarName_Convert,&p1)) {
        oaLibDMData::destroy(p1.Data());
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
static char oaLibDMData_static_exists_doc[] = 
"Class: oaLibDMData, Function: exists\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: oaBoolean exists(const oaScalarName& libName)\n"
"    Signature: exists|simple-oaBoolean|cref-oaScalarName,\n"
"    This function returns true if there is an oaLibDMData object open for the given library or if an oaLibDMData file exists on disk with a non-zero size.\n"
"    libName\n"
"    name of the library associated with the DMData\n"
;

static PyObject*
oaLibDMData_static_exists(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarName p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaScalarName_Convert,&p1)) {
        oaBoolean result= (oaLibDMData::exists(p1.Data()));
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
static char oaLibDMData_static_find_doc[] = 
"Class: oaLibDMData, Function: find\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: oaLibDMData* find(const oaScalarName& libName)\n"
"    Signature: find|ptr-oaLibDMData|cref-oaScalarName,\n"
"    This function attempts to find and open the oaLibDMData for the named library. If successful, a pointer to the oaLibDMData object is returned; otherwise, NULL is returned.\n"
"    libName\n"
"    name of the library associated with the DMData\n"
;

static PyObject*
oaLibDMData_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarName p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaScalarName_Convert,&p1)) {
        oaLibDMDatap result= (oaLibDMData::find(p1.Data()));
        return PyoaLibDMData_FromoaLibDMData(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLibDMData_static_open_doc[] = 
"Class: oaLibDMData, Function: open\n"
"  Paramegers: (oaScalarName,oaChar)\n"
"    Calls: oaLibDMData* open(const oaScalarName& libName,oaChar mode)\n"
"    Signature: open|ptr-oaLibDMData|cref-oaScalarName,simple-oaChar,\n"
"    This function attempts to open the oaLibDMData object for the library with the specified name in the specified mode. If the specified mode is a write-access mode ('a'ppend or 'w'rite mode) and the oaLibDMData does not exist, it will be created. If the specified mode is a read-access mode ('r'ead-only mode) and the oaLibDMData does not exist, an oacDMDataDoesNotExist exception will be thrown.\n"
"    If successful, a pointer to the LibDMData object is returned.\n"
"    libName\n"
"    name of the library associated with the DMData\n"
"    mode\n"
"    'read-only,' 'a'ppend, or 'w'rite mode in which to access the DMData; 'a'ppend and 'w'rite mode attempt to obtain write access to data; 'a'ppend retains any existing LibDMData; while'w'rite deletes (truncates) any existing DMData\n"
"    oacOpenUndefinedModeDMData\n"
"    The specified mode is invalid\n"
"    oacLibNotFound\n"
"    the library with the specified name could not be found\n"
"    oacOpenOnDMDataBeingPurged\n"
"    attempt to open DMData while DMData is being purged\n"
"    oacDMDataCannotGetReadAccess\n"
"    requested read access to the DMData could not be obtained\n"
"    oacDMDataHasReadNeedWriteAccess\n"
"    write access was requested but read access exists on DMData\n"
"    oacDMDataCannotGetWriteAccess\n"
"    requested write access to the DMData could not be obtained\n"
"    oacDMDataDoesNotExist\n"
"    read access requested, but DMData does not exist\n"
"    oacCannotLockDMData\n"
"    write access specified, but cannot get a write lock on the file.\n"
;

static PyObject*
oaLibDMData_static_open(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarName p1;
    PyParamoaChar p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaScalarName_Convert,&p1,
          &PyoaChar_Convert,&p2)) {
        oaLibDMDatap result= (oaLibDMData::open(p1.Data(),p2.Data()));
        return PyoaLibDMData_FromoaLibDMData(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLibDMData_staticmethodlist[] = {
    {"static_destroy",(PyCFunction)oaLibDMData_static_destroy,METH_VARARGS,oaLibDMData_static_destroy_doc},
    {"static_exists",(PyCFunction)oaLibDMData_static_exists,METH_VARARGS,oaLibDMData_static_exists_doc},
    {"static_find",(PyCFunction)oaLibDMData_static_find,METH_VARARGS,oaLibDMData_static_find_doc},
    {"static_open",(PyCFunction)oaLibDMData_static_open,METH_VARARGS,oaLibDMData_static_open_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLibDMData_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLibDMData_Type)<0) {
      printf("** PyType_Ready failed for: oaLibDMData\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLibDMData",
           (PyObject*)(&PyoaLibDMData_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLibDMData\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLibDMData_Type.tp_dict;
    for(method=oaLibDMData_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaLibDataType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLibDataType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLibDataType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLibDataTypeObject* self = (PyoaLibDataTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLibDataTypeEnum)
    {
        PyParamoaLibDataTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaLibDataTypeEnum_Convert,&p1)) {
            self->value =  new oaLibDataType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaLibDataType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaLibDataType)
    {
        PyParamoaLibDataType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLibDataType_Convert,&p1)) {
            self->value= new oaLibDataType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaLibDataType, Choices are:\n"
        "    (oaLibDataTypeEnum)\n"
        "    (oaString)\n"
        "    (oaLibDataType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaLibDataType_tp_dealloc(PyoaLibDataTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLibDataType_tp_repr(PyObject *ob)
{
    PyParamoaLibDataType value;
    int convert_status=PyoaLibDataType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[35];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaLibDataType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLibDataType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLibDataType v1;
    PyParamoaLibDataType v2;
    int convert_status1=PyoaLibDataType_Convert(ob1,&v1);
    int convert_status2=PyoaLibDataType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLibDataType_Convert(PyObject* ob,PyParamoaLibDataType* result)
{
    if (ob == NULL) return 1;
    if (PyoaLibDataType_Check(ob)) {
        result->SetData(  ((PyoaLibDataTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLibDataType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLibDataType_FromoaLibDataType(oaLibDataType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaLibDataType_Type.tp_alloc(&PyoaLibDataType_Type,0);
        if (bself == NULL) return bself;
        PyoaLibDataTypeObject* self = (PyoaLibDataTypeObject*)bself;
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
static char oaLibDataType_getName_doc[] = 
"Class: oaLibDataType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the string name of the oaLibDataTypeEnum value for this oaLibDataType wrapper object.\n"
;

static PyObject*
oaLibDataType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDataType data;
    int convert_status=PyoaLibDataType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDataTypeObject* self=(PyoaLibDataTypeObject*)ob;

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
static char oaLibDataType_oaLibDataTypeEnum_doc[] = 
"Class: oaLibDataType, Function: oaLibDataTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaLibDataTypeEnum oaLibDataTypeEnum() const\n"
"    Signature: operator oaLibDataTypeEnum|simple-oaLibDataTypeEnum|\n"
"    BrowseData: 1\n"
"    This function casts this oaLibDataType into its corresponding oaLibDataTypeEnum value.\n"
;

static PyObject*
oaLibDataType_oaLibDataTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDataType data;
    int convert_status=PyoaLibDataType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDataTypeObject* self=(PyoaLibDataTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLibDataTypeEnum result= (data.DataCall()->operator oaLibDataTypeEnum());
        return PyoaLibDataTypeEnum_FromoaLibDataTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaLibDataType_assign_doc[] = 
"Class: oaLibDataType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLibDataType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLibDataType data;
  int convert_status=PyoaLibDataType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLibDataType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLibDataType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaLibDataType_methodlist[] = {
    {"getName",(PyCFunction)oaLibDataType_getName,METH_VARARGS,oaLibDataType_getName_doc},
    {"oaLibDataTypeEnum",(PyCFunction)oaLibDataType_oaLibDataTypeEnum,METH_VARARGS,oaLibDataType_oaLibDataTypeEnum_doc},
    {"assign",(PyCFunction)oaLibDataType_tp_assign,METH_VARARGS,oaLibDataType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLibDataType_doc[] = 
"Class: oaLibDataType\n"
"  The oaLibDataType class is an enum wrapper class for oaLibDataTypeEnum values.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaLibDataTypeEnum\n"
"Constructors:\n"
"  Paramegers: (oaLibDataTypeEnum)\n"
"    Calls: oaLibDataType(oaLibDataTypeEnum valueIn)\n"
"    Signature: oaLibDataType||simple-oaLibDataTypeEnum,\n"
"    This oaLibDataType constructor takes an oaLibDataTypeEnum value as input.\n"
"    valueIn\n"
"    an oaLibDataTypeEnum value\n"
"  Paramegers: (oaString)\n"
"    Calls: oaLibDataType(const oaString& name)\n"
"    Signature: oaLibDataType||cref-oaString,\n"
"    This oaLibDataType constructor takes an oaLibDataTypeEnum string name as input.\n"
"    name\n"
"    an oaLibDataTypeEnum string name\n"
"    oacInvalidLibDataTypeName\n"
"    the specified oaLibDataTypeEnum string name is invalid\n"
"  Paramegers: (oaLibDataType)\n"
"    Calls: (const oaLibDataType&)\n"
"    Signature: oaLibDataType||cref-oaLibDataType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLibDataType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLibDataType",
    sizeof(PyoaLibDataTypeObject),
    0,
    (destructor)oaLibDataType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLibDataType_tp_compare,	/* tp_compare */
    (reprfunc)oaLibDataType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLibDataType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLibDataType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLibDataType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLibDataType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLibDataType_Type)<0) {
      printf("** PyType_Ready failed for: oaLibDataType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLibDataType",
           (PyObject*)(&PyoaLibDataType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLibDataType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaLibDataTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaLibDataTypeEnum_Convert(PyObject* ob,PyParamoaLibDataTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacLibDataType")==0) { result->SetData(oacLibDataType); return 1;}
        if (strcasecmp(str,"oacLibAppObjectDataType")==0) { result->SetData(oacLibAppObjectDataType); return 1;}
        if (strcasecmp(str,"oacLibPropDataType")==0) { result->SetData(oacLibPropDataType); return 1;}
        if (strcasecmp(str,"oacLibGroupDataType")==0) { result->SetData(oacLibGroupDataType); return 1;}
        if (strcasecmp(str,"oacLibGroupMemDataType")==0) { result->SetData(oacLibGroupMemDataType); return 1;}
        if (strcasecmp(str,"oacLibAvatarDataType")==0) { result->SetData(oacLibAvatarDataType); return 1;}
        if (strcasecmp(str,"oacLibValueDataType")==0) { result->SetData(oacLibValueDataType); return 1;}
        if (strcasecmp(str,"oacLibConstraintParamDefDataType")==0) { result->SetData(oacLibConstraintParamDefDataType); return 1;}
        if (strcasecmp(str,"oacLibConstraintParamDataType")==0) { result->SetData(oacLibConstraintParamDataType); return 1;}
        if (strcasecmp(str,"oacLibConstraintDefDataType")==0) { result->SetData(oacLibConstraintDefDataType); return 1;}
        if (strcasecmp(str,"oacLibConstraintDataType")==0) { result->SetData(oacLibConstraintDataType); return 1;}
        if (strcasecmp(str,"oacLibConstraintGroupDataType")==0) { result->SetData(oacLibConstraintGroupDataType); return 1;}
        if (strcasecmp(str,"oacLibConstraintGroupMemDataType")==0) { result->SetData(oacLibConstraintGroupMemDataType); return 1;}
        if (strcasecmp(str,"oacLibConstraintGroupHeaderDataType")==0) { result->SetData(oacLibConstraintGroupHeaderDataType); return 1;}
        if (strcasecmp(str,"oacCellDataType")==0) { result->SetData(oacCellDataType); return 1;}
        if (strcasecmp(str,"oacViewDataType")==0) { result->SetData(oacViewDataType); return 1;}
        if (strcasecmp(str,"oacCellViewDataType")==0) { result->SetData(oacCellViewDataType); return 1;}
        if (strcasecmp(str,"oacDMFileDataType")==0) { result->SetData(oacDMFileDataType); return 1;}
        if (strcasecmp(str,"oacLibFeatureDataType")==0) { result->SetData(oacLibFeatureDataType); return 1;}
        if (strcasecmp(str,"oacLibFeaturePolicyDataType")==0) { result->SetData(oacLibFeaturePolicyDataType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaLibDataTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLibDataTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaLibDataTypeEnum_FromoaLibDataTypeEnum(oaLibDataTypeEnum ob)
{
    if (ob==oacLibDataType) return PyString_FromString("oacLibDataType");
    if (ob==oacLibAppObjectDataType) return PyString_FromString("oacLibAppObjectDataType");
    if (ob==oacLibPropDataType) return PyString_FromString("oacLibPropDataType");
    if (ob==oacLibGroupDataType) return PyString_FromString("oacLibGroupDataType");
    if (ob==oacLibGroupMemDataType) return PyString_FromString("oacLibGroupMemDataType");
    if (ob==oacLibAvatarDataType) return PyString_FromString("oacLibAvatarDataType");
    if (ob==oacLibValueDataType) return PyString_FromString("oacLibValueDataType");
    if (ob==oacLibConstraintParamDefDataType) return PyString_FromString("oacLibConstraintParamDefDataType");
    if (ob==oacLibConstraintParamDataType) return PyString_FromString("oacLibConstraintParamDataType");
    if (ob==oacLibConstraintDefDataType) return PyString_FromString("oacLibConstraintDefDataType");
    if (ob==oacLibConstraintDataType) return PyString_FromString("oacLibConstraintDataType");
    if (ob==oacLibConstraintGroupDataType) return PyString_FromString("oacLibConstraintGroupDataType");
    if (ob==oacLibConstraintGroupMemDataType) return PyString_FromString("oacLibConstraintGroupMemDataType");
    if (ob==oacLibConstraintGroupHeaderDataType) return PyString_FromString("oacLibConstraintGroupHeaderDataType");
    if (ob==oacCellDataType) return PyString_FromString("oacCellDataType");
    if (ob==oacViewDataType) return PyString_FromString("oacViewDataType");
    if (ob==oacCellViewDataType) return PyString_FromString("oacCellViewDataType");
    if (ob==oacDMFileDataType) return PyString_FromString("oacDMFileDataType");
    if (ob==oacLibFeatureDataType) return PyString_FromString("oacLibFeatureDataType");
    if (ob==oacLibFeaturePolicyDataType) return PyString_FromString("oacLibFeaturePolicyDataType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaLibDataTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaLibDataTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaLibDataTypeEnum_FromoaLibDataTypeEnum(oaLibDataTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaLibDataTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaLibDataTypeEnum_doc[] =
"Type convert function for enum: oaLibDataTypeEnum";
                               
static PyMethodDef PyoaLibDataTypeEnum_method =
  {"oaLibDataTypeEnum",(PyCFunction)PyoaLibDataTypeEnum_TypeFunction,METH_VARARGS,oaLibDataTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaLibDataTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacLibDataType");
    PyDict_SetItemString(mod_dict,"oacLibDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibAppObjectDataType");
    PyDict_SetItemString(mod_dict,"oacLibAppObjectDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibPropDataType");
    PyDict_SetItemString(mod_dict,"oacLibPropDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibGroupDataType");
    PyDict_SetItemString(mod_dict,"oacLibGroupDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibGroupMemDataType");
    PyDict_SetItemString(mod_dict,"oacLibGroupMemDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibAvatarDataType");
    PyDict_SetItemString(mod_dict,"oacLibAvatarDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibValueDataType");
    PyDict_SetItemString(mod_dict,"oacLibValueDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibConstraintParamDefDataType");
    PyDict_SetItemString(mod_dict,"oacLibConstraintParamDefDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibConstraintParamDataType");
    PyDict_SetItemString(mod_dict,"oacLibConstraintParamDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibConstraintDefDataType");
    PyDict_SetItemString(mod_dict,"oacLibConstraintDefDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibConstraintDataType");
    PyDict_SetItemString(mod_dict,"oacLibConstraintDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibConstraintGroupDataType");
    PyDict_SetItemString(mod_dict,"oacLibConstraintGroupDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibConstraintGroupMemDataType");
    PyDict_SetItemString(mod_dict,"oacLibConstraintGroupMemDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibConstraintGroupHeaderDataType");
    PyDict_SetItemString(mod_dict,"oacLibConstraintGroupHeaderDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCellDataType");
    PyDict_SetItemString(mod_dict,"oacCellDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacViewDataType");
    PyDict_SetItemString(mod_dict,"oacViewDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCellViewDataType");
    PyDict_SetItemString(mod_dict,"oacCellViewDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDMFileDataType");
    PyDict_SetItemString(mod_dict,"oacDMFileDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibFeatureDataType");
    PyDict_SetItemString(mod_dict,"oacLibFeatureDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibFeaturePolicyDataType");
    PyDict_SetItemString(mod_dict,"oacLibFeaturePolicyDataType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaLibDataTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaLibDataTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaLibDataTypeEnum\n");
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
// Wrapper Implementation for Class: oaLibDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLibDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLibDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLibDefObject* self = (PyoaLibDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLibDef)
    {
        PyParamoaLibDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLibDef_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLibDef, Choices are:\n"
        "    (oaLibDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaLibDef_tp_dealloc(PyoaLibDefObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLibDef_tp_repr(PyObject *ob)
{
    PyParamoaLibDef value;
    int convert_status=PyoaLibDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[30];
    sprintf(buffer,"<oaLibDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLibDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLibDef v1;
    PyParamoaLibDef v2;
    int convert_status1=PyoaLibDef_Convert(ob1,&v1);
    int convert_status2=PyoaLibDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLibDef_Convert(PyObject* ob,PyParamoaLibDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaLibDef_Check(ob)) {
        result->SetData( (oaLibDef**) ((PyoaLibDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLibDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLibDef_FromoaLibDef(oaLibDef** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLibDef* data=*value;
        PyObject* bself = PyoaLibDef_Type.tp_alloc(&PyoaLibDef_Type,0);
        if (bself == NULL) return bself;
        PyoaLibDefObject* self = (PyoaLibDefObject*)bself;
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
PyObject* PyoaLibDef_FromoaLibDef(oaLibDef* data)
{
    if (data) {
       PyObject* bself = PyoaLibDef_Type.tp_alloc(&PyoaLibDef_Type,0);
       if (bself == NULL) return bself;
       PyoaLibDefObject* self = (PyoaLibDefObject*)bself;
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
static char oaLibDef_getLibAttributes_doc[] = 
"Class: oaLibDef, Function: getLibAttributes\n"
"  Paramegers: (oaDMAttrArray)\n"
"    Calls: void getLibAttributes(oaDMAttrArray& attrs) const\n"
"    Signature: getLibAttributes|void-void|ref-oaDMAttrArray,\n"
"    BrowseData: 0,oaDMAttrArray\n"
"    This function fills in the library attributes array of this libDef object. If there are no attributes in this definition, an empty array is returned.\n"
"    attrs\n"
"    output parameter - the attributes array of the library that this libDef object defines.\n"
;

static PyObject*
oaLibDef_getLibAttributes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDef data;
    int convert_status=PyoaLibDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefObject* self=(PyoaLibDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDMAttrArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMAttrArray_Convert,&p1)) {
        data.DataCall()->getLibAttributes(p1.Data());
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
static char oaLibDef_getLibMode_doc[] = 
"Class: oaLibDef, Function: getLibMode\n"
"  Paramegers: ()\n"
"    Calls: oaLibMode getLibMode() const\n"
"    Signature: getLibMode|simple-oaLibMode|\n"
"    BrowseData: 1\n"
"    This function returns the access mode of the library that this libDef object defines (see oaLibMode for further information).\n"
;

static PyObject*
oaLibDef_getLibMode(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDef data;
    int convert_status=PyoaLibDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefObject* self=(PyoaLibDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLibMode* result= new oaLibMode(data.DataCall()->getLibMode());
        return PyoaLibMode_FromoaLibMode(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLibDef_getLibName_doc[] = 
"Class: oaLibDef, Function: getLibName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getLibName(oaScalarName& libName) const\n"
"    Signature: getLibName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function fills in the library name of the library that this libDef object defines.\n"
"    libName\n"
"    output parameter - the logical name of the library.\n"
;

static PyObject*
oaLibDef_getLibName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDef data;
    int convert_status=PyoaLibDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefObject* self=(PyoaLibDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaScalarName p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaScalarName_Convert,&p1)) {
        data.DataCall()->getLibName(p1.Data());
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
static char oaLibDef_getLibPath_doc[] = 
"Class: oaLibDef, Function: getLibPath\n"
"  Paramegers: (oaString)\n"
"    Calls: void getLibPath(oaString& path) const\n"
"    Signature: getLibPath|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function fills in the library path of the library that this libDef object defines.\n"
"    path\n"
"    output parameter - the physical path to the library.\n"
;

static PyObject*
oaLibDef_getLibPath(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDef data;
    int convert_status=PyoaLibDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefObject* self=(PyoaLibDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getLibPath(p1.Data());
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
static char oaLibDef_getLibWritePath_doc[] = 
"Class: oaLibDef, Function: getLibWritePath\n"
"  Paramegers: (oaString)\n"
"    Calls: void getLibWritePath(oaString& writePath) const\n"
"    Signature: getLibWritePath|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function gets the write path of the library associated with this libDef object.\n"
"    writePath\n"
"    output parameter - the write path of the library associated with this libDef.\n"
;

static PyObject*
oaLibDef_getLibWritePath(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDef data;
    int convert_status=PyoaLibDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefObject* self=(PyoaLibDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getLibWritePath(p1.Data());
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
static char oaLibDef_isNull_doc[] =
"Class: oaLibDef, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLibDef_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLibDef data;
    int convert_status=PyoaLibDef_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLibDef_assign_doc[] = 
"Class: oaLibDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLibDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLibDef data;
  int convert_status=PyoaLibDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLibDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLibDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaLibDef_methodlist[] = {
    {"getLibAttributes",(PyCFunction)oaLibDef_getLibAttributes,METH_VARARGS,oaLibDef_getLibAttributes_doc},
    {"getLibMode",(PyCFunction)oaLibDef_getLibMode,METH_VARARGS,oaLibDef_getLibMode_doc},
    {"getLibName",(PyCFunction)oaLibDef_getLibName,METH_VARARGS,oaLibDef_getLibName_doc},
    {"getLibPath",(PyCFunction)oaLibDef_getLibPath,METH_VARARGS,oaLibDef_getLibPath_doc},
    {"getLibWritePath",(PyCFunction)oaLibDef_getLibWritePath,METH_VARARGS,oaLibDef_getLibWritePath_doc},
    {"isNull",(PyCFunction)oaLibDef_tp_isNull,METH_VARARGS,oaLibDef_isNull_doc},
    {"assign",(PyCFunction)oaLibDef_tp_assign,METH_VARARGS,oaLibDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLibDef_doc[] = 
"Class: oaLibDef\n"
"  oaLibDef is a derived class of oaLibDefListMem . It represents a library definition included in the owning library definition list ( oaLibDefList ).\n"
"Constructors:\n"
"  Paramegers: (oaLibDef)\n"
"    Calls: (const oaLibDef&)\n"
"    Signature: oaLibDef||cref-oaLibDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLibDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLibDef",
    sizeof(PyoaLibDefObject),
    0,
    (destructor)oaLibDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLibDef_tp_compare,	/* tp_compare */
    (reprfunc)oaLibDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLibDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLibDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaLibDefListMem_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLibDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLibDef_static_create_doc[] = 
"Class: oaLibDef, Function: create\n"
"  Paramegers: (oaLibDefList,oaScalarName,oaString)\n"
"    Calls: oaLibDef* create(oaLibDefList* defList,const oaScalarName& libName,const oaString& libPath)\n"
"    Signature: create|ptr-oaLibDef|ptr-oaLibDefList,cref-oaScalarName,cref-oaString,cref-oaString,simple-oaLibMode,cptr-oaDMAttrArray,ptr-oaLibDefListMem,\n"
"    oaLibDef::create\n"
"    This function creates an oaLibDef object and places it in the specified defList with the specified parameters. The libDef will be positioned in the owning defList before the followingMem if it is specified; otherwise it will positioned at the end of defList .\n"
"    Note that the writePath and libMode parameters as well as any attributes contained in the optional libAttrs oaDMAttrArray will be written out to the top file associated with the owning defList when a save operation is performed on the oaLibDefList . Each attribute will be written in the file in a separate ASSIGN statement (see oaLibDefList for more information on the format of the ASSIGN statement used in library definition files).\n"
"    defList\n"
"    - required input parameter. The owning oaLibDefList object in which this object will be placed.\n"
"    libName\n"
"    - required input parameter. The logical name of the library\n"
"    libPath\n"
"    - required input parameter. The physical path to the library. A Relative path is supported, which should be specified relative to the path of the file associated with the owning defList .\n"
"    writePath\n"
"    - optional input parameter. The write path of the library. A relative path is supported, which should relative to the path of the associated with the owning defList . When a subsequent save is performed on the owning defList , this attribute value will be saved with the \"writePath\" attribute name in a library definition file ASSIGN statement.\n"
"    libMode\n"
"    - optional input parameter. The mode of the library. The default value is oacSharedLibMode. When a subsequent save is performed on the owning defList , this attribute value will be saved with the \"libMode\" attribute name in a library definition file ASSIGN statement.\n"
"    libAttrs\n"
"    - optional input parameter array. An oaDMAttrArray of library attributes. When a subsequent save is performed on the owning defList , each attribute name and value will be saved in the library definition file in a separate ASSIGN statement.\n"
"    followingMem\n"
"    - optional input parameter. The member in the ordered defList that this libDef will be positioned before. If NULL is specified, this libDef will be positioned at the end of the owning defList .\n"
"    oacLibDefExists\n"
"    oacInvalidLibDefListMemCreate\n"
"  Paramegers: (oaLibDefList,oaScalarName,oaString,oaString)\n"
"    Calls: oaLibDef* create(oaLibDefList* defList,const oaScalarName& libName,const oaString& libPath,const oaString& writePath)\n"
"    Signature: create|ptr-oaLibDef|ptr-oaLibDefList,cref-oaScalarName,cref-oaString,cref-oaString,simple-oaLibMode,cptr-oaDMAttrArray,ptr-oaLibDefListMem,\n"
"    oaLibDef::create\n"
"    This function creates an oaLibDef object and places it in the specified defList with the specified parameters. The libDef will be positioned in the owning defList before the followingMem if it is specified; otherwise it will positioned at the end of defList .\n"
"    Note that the writePath and libMode parameters as well as any attributes contained in the optional libAttrs oaDMAttrArray will be written out to the top file associated with the owning defList when a save operation is performed on the oaLibDefList . Each attribute will be written in the file in a separate ASSIGN statement (see oaLibDefList for more information on the format of the ASSIGN statement used in library definition files).\n"
"    defList\n"
"    - required input parameter. The owning oaLibDefList object in which this object will be placed.\n"
"    libName\n"
"    - required input parameter. The logical name of the library\n"
"    libPath\n"
"    - required input parameter. The physical path to the library. A Relative path is supported, which should be specified relative to the path of the file associated with the owning defList .\n"
"    writePath\n"
"    - optional input parameter. The write path of the library. A relative path is supported, which should relative to the path of the associated with the owning defList . When a subsequent save is performed on the owning defList , this attribute value will be saved with the \"writePath\" attribute name in a library definition file ASSIGN statement.\n"
"    libMode\n"
"    - optional input parameter. The mode of the library. The default value is oacSharedLibMode. When a subsequent save is performed on the owning defList , this attribute value will be saved with the \"libMode\" attribute name in a library definition file ASSIGN statement.\n"
"    libAttrs\n"
"    - optional input parameter array. An oaDMAttrArray of library attributes. When a subsequent save is performed on the owning defList , each attribute name and value will be saved in the library definition file in a separate ASSIGN statement.\n"
"    followingMem\n"
"    - optional input parameter. The member in the ordered defList that this libDef will be positioned before. If NULL is specified, this libDef will be positioned at the end of the owning defList .\n"
"    oacLibDefExists\n"
"    oacInvalidLibDefListMemCreate\n"
"  Paramegers: (oaLibDefList,oaScalarName,oaString,oaString,oaLibMode)\n"
"    Calls: oaLibDef* create(oaLibDefList* defList,const oaScalarName& libName,const oaString& libPath,const oaString& writePath,oaLibMode libMode)\n"
"    Signature: create|ptr-oaLibDef|ptr-oaLibDefList,cref-oaScalarName,cref-oaString,cref-oaString,simple-oaLibMode,cptr-oaDMAttrArray,ptr-oaLibDefListMem,\n"
"    oaLibDef::create\n"
"    This function creates an oaLibDef object and places it in the specified defList with the specified parameters. The libDef will be positioned in the owning defList before the followingMem if it is specified; otherwise it will positioned at the end of defList .\n"
"    Note that the writePath and libMode parameters as well as any attributes contained in the optional libAttrs oaDMAttrArray will be written out to the top file associated with the owning defList when a save operation is performed on the oaLibDefList . Each attribute will be written in the file in a separate ASSIGN statement (see oaLibDefList for more information on the format of the ASSIGN statement used in library definition files).\n"
"    defList\n"
"    - required input parameter. The owning oaLibDefList object in which this object will be placed.\n"
"    libName\n"
"    - required input parameter. The logical name of the library\n"
"    libPath\n"
"    - required input parameter. The physical path to the library. A Relative path is supported, which should be specified relative to the path of the file associated with the owning defList .\n"
"    writePath\n"
"    - optional input parameter. The write path of the library. A relative path is supported, which should relative to the path of the associated with the owning defList . When a subsequent save is performed on the owning defList , this attribute value will be saved with the \"writePath\" attribute name in a library definition file ASSIGN statement.\n"
"    libMode\n"
"    - optional input parameter. The mode of the library. The default value is oacSharedLibMode. When a subsequent save is performed on the owning defList , this attribute value will be saved with the \"libMode\" attribute name in a library definition file ASSIGN statement.\n"
"    libAttrs\n"
"    - optional input parameter array. An oaDMAttrArray of library attributes. When a subsequent save is performed on the owning defList , each attribute name and value will be saved in the library definition file in a separate ASSIGN statement.\n"
"    followingMem\n"
"    - optional input parameter. The member in the ordered defList that this libDef will be positioned before. If NULL is specified, this libDef will be positioned at the end of the owning defList .\n"
"    oacLibDefExists\n"
"    oacInvalidLibDefListMemCreate\n"
"  Paramegers: (oaLibDefList,oaScalarName,oaString,oaString,oaLibMode,oaDMAttrArray)\n"
"    Calls: oaLibDef* create(oaLibDefList* defList,const oaScalarName& libName,const oaString& libPath,const oaString& writePath,oaLibMode libMode,const oaDMAttrArray* libAttrs)\n"
"    Signature: create|ptr-oaLibDef|ptr-oaLibDefList,cref-oaScalarName,cref-oaString,cref-oaString,simple-oaLibMode,cptr-oaDMAttrArray,ptr-oaLibDefListMem,\n"
"    oaLibDef::create\n"
"    This function creates an oaLibDef object and places it in the specified defList with the specified parameters. The libDef will be positioned in the owning defList before the followingMem if it is specified; otherwise it will positioned at the end of defList .\n"
"    Note that the writePath and libMode parameters as well as any attributes contained in the optional libAttrs oaDMAttrArray will be written out to the top file associated with the owning defList when a save operation is performed on the oaLibDefList . Each attribute will be written in the file in a separate ASSIGN statement (see oaLibDefList for more information on the format of the ASSIGN statement used in library definition files).\n"
"    defList\n"
"    - required input parameter. The owning oaLibDefList object in which this object will be placed.\n"
"    libName\n"
"    - required input parameter. The logical name of the library\n"
"    libPath\n"
"    - required input parameter. The physical path to the library. A Relative path is supported, which should be specified relative to the path of the file associated with the owning defList .\n"
"    writePath\n"
"    - optional input parameter. The write path of the library. A relative path is supported, which should relative to the path of the associated with the owning defList . When a subsequent save is performed on the owning defList , this attribute value will be saved with the \"writePath\" attribute name in a library definition file ASSIGN statement.\n"
"    libMode\n"
"    - optional input parameter. The mode of the library. The default value is oacSharedLibMode. When a subsequent save is performed on the owning defList , this attribute value will be saved with the \"libMode\" attribute name in a library definition file ASSIGN statement.\n"
"    libAttrs\n"
"    - optional input parameter array. An oaDMAttrArray of library attributes. When a subsequent save is performed on the owning defList , each attribute name and value will be saved in the library definition file in a separate ASSIGN statement.\n"
"    followingMem\n"
"    - optional input parameter. The member in the ordered defList that this libDef will be positioned before. If NULL is specified, this libDef will be positioned at the end of the owning defList .\n"
"    oacLibDefExists\n"
"    oacInvalidLibDefListMemCreate\n"
"  Paramegers: (oaLibDefList,oaScalarName,oaString,oaString,oaLibMode,oaDMAttrArray,oaLibDefListMem)\n"
"    Calls: oaLibDef* create(oaLibDefList* defList,const oaScalarName& libName,const oaString& libPath,const oaString& writePath,oaLibMode libMode,const oaDMAttrArray* libAttrs,oaLibDefListMem* followingMem)\n"
"    Signature: create|ptr-oaLibDef|ptr-oaLibDefList,cref-oaScalarName,cref-oaString,cref-oaString,simple-oaLibMode,cptr-oaDMAttrArray,ptr-oaLibDefListMem,\n"
"    oaLibDef::create\n"
"    This function creates an oaLibDef object and places it in the specified defList with the specified parameters. The libDef will be positioned in the owning defList before the followingMem if it is specified; otherwise it will positioned at the end of defList .\n"
"    Note that the writePath and libMode parameters as well as any attributes contained in the optional libAttrs oaDMAttrArray will be written out to the top file associated with the owning defList when a save operation is performed on the oaLibDefList . Each attribute will be written in the file in a separate ASSIGN statement (see oaLibDefList for more information on the format of the ASSIGN statement used in library definition files).\n"
"    defList\n"
"    - required input parameter. The owning oaLibDefList object in which this object will be placed.\n"
"    libName\n"
"    - required input parameter. The logical name of the library\n"
"    libPath\n"
"    - required input parameter. The physical path to the library. A Relative path is supported, which should be specified relative to the path of the file associated with the owning defList .\n"
"    writePath\n"
"    - optional input parameter. The write path of the library. A relative path is supported, which should relative to the path of the associated with the owning defList . When a subsequent save is performed on the owning defList , this attribute value will be saved with the \"writePath\" attribute name in a library definition file ASSIGN statement.\n"
"    libMode\n"
"    - optional input parameter. The mode of the library. The default value is oacSharedLibMode. When a subsequent save is performed on the owning defList , this attribute value will be saved with the \"libMode\" attribute name in a library definition file ASSIGN statement.\n"
"    libAttrs\n"
"    - optional input parameter array. An oaDMAttrArray of library attributes. When a subsequent save is performed on the owning defList , each attribute name and value will be saved in the library definition file in a separate ASSIGN statement.\n"
"    followingMem\n"
"    - optional input parameter. The member in the ordered defList that this libDef will be positioned before. If NULL is specified, this libDef will be positioned at the end of the owning defList .\n"
"    oacLibDefExists\n"
"    oacInvalidLibDefListMemCreate\n"
;

static PyObject*
oaLibDef_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaLibDefList,oaScalarName,oaString)
    {
        PyParamoaLibDefList p1;
        PyParamoaScalarName p2;
        PyParamoaString p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaLibDefList_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaString_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaLibDefp result= (oaLibDef::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaLibDef_FromoaLibDef(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLibDefList,oaScalarName,oaString,oaString)
    {
        PyParamoaLibDefList p1;
        PyParamoaScalarName p2;
        PyParamoaString p3;
        PyParamoaString p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaLibDefList_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaString_Convert,&p3,
              &PyoaString_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaLibDefp result= (oaLibDef::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaLibDef_FromoaLibDef(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLibDefList,oaScalarName,oaString,oaString,oaLibMode)
    {
        PyParamoaLibDefList p1;
        PyParamoaScalarName p2;
        PyParamoaString p3;
        PyParamoaString p4;
        PyParamoaLibMode p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaLibDefList_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaString_Convert,&p3,
              &PyoaString_Convert,&p4,
              &PyoaLibMode_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaLibDefp result= (oaLibDef::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaLibDef_FromoaLibDef(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLibDefList,oaScalarName,oaString,oaString,oaLibMode,oaDMAttrArray)
    {
        PyParamoaLibDefList p1;
        PyParamoaScalarName p2;
        PyParamoaString p3;
        PyParamoaString p4;
        PyParamoaLibMode p5;
        PyParamoaDMAttrArray p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaLibDefList_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaString_Convert,&p3,
              &PyoaString_Convert,&p4,
              &PyoaLibMode_Convert,&p5,
              &PyoaDMAttrArray_ConvertAof,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaLibDefp result= (oaLibDef::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.DataAof()));
            return PyoaLibDef_FromoaLibDef(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLibDefList,oaScalarName,oaString,oaString,oaLibMode,oaDMAttrArray,oaLibDefListMem)
    {
        PyParamoaLibDefList p1;
        PyParamoaScalarName p2;
        PyParamoaString p3;
        PyParamoaString p4;
        PyParamoaLibMode p5;
        PyParamoaDMAttrArray p6;
        PyParamoaLibDefListMem p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaLibDefList_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaString_Convert,&p3,
              &PyoaString_Convert,&p4,
              &PyoaLibMode_Convert,&p5,
              &PyoaDMAttrArray_ConvertAof,&p6,
              &PyoaLibDefListMem_Convert,&p7)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p7.Data(),7)) return NULL;
            oaLibDefp result= (oaLibDef::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.DataAof(),p7.Data()));
            return PyoaLibDef_FromoaLibDef(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLibDef, function: create, Choices are:\n"
        "    (oaLibDefList,oaScalarName,oaString)\n"
        "    (oaLibDefList,oaScalarName,oaString,oaString)\n"
        "    (oaLibDefList,oaScalarName,oaString,oaString,oaLibMode)\n"
        "    (oaLibDefList,oaScalarName,oaString,oaString,oaLibMode,oaDMAttrArray)\n"
        "    (oaLibDefList,oaScalarName,oaString,oaString,oaLibMode,oaDMAttrArray,oaLibDefListMem)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLibDef_static_find_doc[] = 
"Class: oaLibDef, Function: find\n"
"  Paramegers: (oaLibDefList,oaScalarName)\n"
"    Calls: oaLibDef* find(const oaLibDefList* defList,const oaScalarName& libName)\n"
"    Signature: find|ptr-oaLibDef|cptr-oaLibDefList,cref-oaScalarName,\n"
"    This function finds the libDef object in the specified defList list with the given libName . Users can create only one library definition in a libDefList with a library name (see oaLibDef::create ).\n"
"    Note also, if oaLibDefList::openLibs() finds library definitions library definition file hierarchy with the same logical library name, it will open the last of the multiply-defined libraries.\n"
"    defList\n"
"    The oaLibDefList object which this object is in.\n"
"    libName\n"
"    The logical name of the library.\n"
;

static PyObject*
oaLibDef_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefList p1;
    PyParamoaScalarName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaLibDefList_Convert,&p1,
          &PyoaScalarName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaLibDefp result= (oaLibDef::find(p1.Data(),p2.Data()));
        return PyoaLibDef_FromoaLibDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLibDef_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaLibDef_static_create,METH_VARARGS,oaLibDef_static_create_doc},
    {"static_find",(PyCFunction)oaLibDef_static_find,METH_VARARGS,oaLibDef_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLibDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLibDef_Type)<0) {
      printf("** PyType_Ready failed for: oaLibDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLibDef",
           (PyObject*)(&PyoaLibDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLibDef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLibDef_Type.tp_dict;
    for(method=oaLibDef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaLibDefList
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLibDefList_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLibDefList_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLibDefListObject* self = (PyoaLibDefListObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLibDefList)
    {
        PyParamoaLibDefList p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLibDefList_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLibDefList, Choices are:\n"
        "    (oaLibDefList)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaLibDefList_tp_dealloc(PyoaLibDefListObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLibDefList_tp_repr(PyObject *ob)
{
    PyParamoaLibDefList value;
    int convert_status=PyoaLibDefList_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[34];
    sprintf(buffer,"<oaLibDefList::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLibDefList_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLibDefList v1;
    PyParamoaLibDefList v2;
    int convert_status1=PyoaLibDefList_Convert(ob1,&v1);
    int convert_status2=PyoaLibDefList_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLibDefList_Convert(PyObject* ob,PyParamoaLibDefList* result)
{
    if (ob == NULL) return 1;
    if (PyoaLibDefList_Check(ob)) {
        result->SetData( (oaLibDefList**) ((PyoaLibDefListObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLibDefList Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLibDefList_FromoaLibDefList(oaLibDefList** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLibDefList* data=*value;
        PyObject* bself = PyoaLibDefList_Type.tp_alloc(&PyoaLibDefList_Type,0);
        if (bself == NULL) return bself;
        PyoaLibDefListObject* self = (PyoaLibDefListObject*)bself;
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
PyObject* PyoaLibDefList_FromoaLibDefList(oaLibDefList* data)
{
    if (data) {
       PyObject* bself = PyoaLibDefList_Type.tp_alloc(&PyoaLibDefList_Type,0);
       if (bself == NULL) return bself;
       PyoaLibDefListObject* self = (PyoaLibDefListObject*)bself;
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
static char oaLibDefList_destroy_doc[] = 
"Class: oaLibDefList, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this libDefList object.\n"
;

static PyObject*
oaLibDefList_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefList data;
    int convert_status=PyoaLibDefList_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefListObject* self=(PyoaLibDefListObject*)ob;
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
static char oaLibDefList_getFullPath_doc[] = 
"Class: oaLibDefList, Function: getFullPath\n"
"  Paramegers: (oaString)\n"
"    Calls: void getFullPath(oaString& path) const\n"
"    Signature: getFullPath|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the full path to the file associated with this libDefList object.\n"
"    fullPath\n"
"    output parameter - full absolute path, including filename, of the lib def file associated with this libDefList object.\n"
;

static PyObject*
oaLibDefList_getFullPath(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefList data;
    int convert_status=PyoaLibDefList_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefListObject* self=(PyoaLibDefListObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getFullPath(p1.Data());
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
static char oaLibDefList_getMembers_doc[] = 
"Class: oaLibDefList, Function: getMembers\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaLibDefListMem_oaLibDefList getMembers() const\n"
"    Signature: getMembers|simple-oaCollection_oaLibDefListMem_oaLibDefList|\n"
"    BrowseData: 1\n"
"    oaLibDefList::getMembers\n"
"    This function returns a collection of the libDefList members in this lib def list. Note that the libDefList is ordered, which means the order of the oaLibDefListMem objects returned from the iterator is meaningful and persistent.\n"
"    Below is a sample recursive routine that gets and iterates through all the oaLibDefListMems in an oaLibDefList passed to the routine. The purpose of the routine is to process all the library definitions found in the user's library definition file hierarchy at and below the level of the oaLibDefList passed to the routine.\n"
"    walkLibDefList( oaLibDefList *list) { oaType memType; oaScalarName libName; oaString tempString; oaIter<oaLibDefListMem> listIter(list-> getMembers ()); while ( oaLibDefListMem *listMem = listIter.getNext()) { switch (memType = listMem-> getType ()) { case oacLibDefType : (( oaLibDef *)(listMem))->getLibName(libName); libName. get (tempString); cout << \"Got Lib Def: Logical Library Name = \" << tempString << endl; //process lib def ... break ; case oacLibDefListRefType : (( oaLibDefListRef *)(listMem))->getRefListPath(tempString); oaLibDefList *nextList = oaLibDefList::get (tempString, 'r' ); walkLibDefList(nextList); break ; } } }\n"
;

static PyObject*
oaLibDefList_getMembers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefList data;
    int convert_status=PyoaLibDefList_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefListObject* self=(PyoaLibDefListObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaLibDefListMem_oaLibDefList* result= new oaCollection_oaLibDefListMem_oaLibDefList(data.DataCall()->getMembers());
        return PyoaCollection_oaLibDefListMem_oaLibDefList_FromoaCollection_oaLibDefListMem_oaLibDefList(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLibDefList_getMembersIter_doc[] = 
"Class: oaLibDefList, Function: getMembersIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaLibDefListMem getMembersIter() const\n"
"    Signature: getMembersIter|simple-oaIter_oaLibDefListMem|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: oaLibDefList::getMembers\n"
"    This function returns a collection of the libDefList members in this lib def list. Note that the libDefList is ordered, which means the order of the oaLibDefListMem objects returned from the iterator is meaningful and persistent.\n"
"    Below is a sample recursive routine that gets and iterates through all the oaLibDefListMems in an oaLibDefList passed to the routine. The purpose of the routine is to process all the library definitions found in the user's library definition file hierarchy at and below the level of the oaLibDefList passed to the routine.\n"
"    walkLibDefList( oaLibDefList *list) { oaType memType; oaScalarName libName; oaString tempString; oaIter<oaLibDefListMem> listIter(list-> getMembers ()); while ( oaLibDefListMem *listMem = listIter.getNext()) { switch (memType = listMem-> getType ()) { case oacLibDefType : (( oaLibDef *)(listMem))->getLibName(libName); libName. get (tempString); cout << \"Got Lib Def: Logical Library Name = \" << tempString << endl; //process lib def ... break ; case oacLibDefListRefType : (( oaLibDefListRef *)(listMem))->getRefListPath(tempString); oaLibDefList *nextList = oaLibDefList::get (tempString, 'r' ); walkLibDefList(nextList); break ; } } }\n"
;

static PyObject*
oaLibDefList_getMembersIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefList data;
    int convert_status=PyoaLibDefList_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefListObject* self=(PyoaLibDefListObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaLibDefListMem* result= new oaIter_oaLibDefListMem(data.DataCall()->getMembers());
        return PyoaIter_oaLibDefListMem_FromoaIter_oaLibDefListMem(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLibDefList_getMode_doc[] = 
"Class: oaLibDefList, Function: getMode\n"
"  Paramegers: ()\n"
"    Calls: oaChar getMode() const\n"
"    Signature: getMode|simple-oaChar|\n"
"    BrowseData: 1\n"
"    This function returns the mode of this libDefList object. There are three modes supported - 'r'ead, 'a'ppend, and 'w'rite (see oaLibDefList::get() for a description of each mode).\n"
;

static PyObject*
oaLibDefList_getMode(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefList data;
    int convert_status=PyoaLibDefList_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefListObject* self=(PyoaLibDefListObject*)ob;
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
static char oaLibDefList_getPath_doc[] = 
"Class: oaLibDefList, Function: getPath\n"
"  Paramegers: (oaString)\n"
"    Calls: void getPath(oaString& path) const\n"
"    Signature: getPath|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the path to the file associated with this libDefList object.\n"
"    filePath\n"
"    output parameter - complete path, including filename, of the lib def file associated with this libDefList object. The complete path can either be an absolute path or a relative path\n"
;

static PyObject*
oaLibDefList_getPath(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefList data;
    int convert_status=PyoaLibDefList_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefListObject* self=(PyoaLibDefListObject*)ob;
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
static char oaLibDefList_save_doc[] = 
"Class: oaLibDefList, Function: save\n"
"  Paramegers: ()\n"
"    Calls: void save()\n"
"    Signature: save|void-void|\n"
"    BrowseData: 0\n"
"    oaLibDefList::save\n"
"    This function saves this libDefList object to the file associated with it. Note that this oaLibDefList object must have been returned through a previous oaLibDefList::get call with the 'a'ppend or 'w'rite option.\n"
"    oacSaveReadOnlyLibDefList\n"
;

static PyObject*
oaLibDefList_save(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefList data;
    int convert_status=PyoaLibDefList_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefListObject* self=(PyoaLibDefListObject*)ob;
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
static char oaLibDefList_saveAs_doc[] = 
"Class: oaLibDefList, Function: saveAs\n"
"  Paramegers: (oaString)\n"
"    Calls: void saveAs(const oaString& path)\n"
"    Signature: saveAs|void-void|cref-oaString,\n"
"    This function saves this libDefList object to the file specified by the path . Note that this oaLibDefList object must have been returned through a previous oaLibDefList::get call with the 'a'ppend or 'w'rite option.\n"
"    filePath\n"
"    input parameter - absolute or relative path, including filename. A relative path should be specified relative to the current working directory.\n"
;

static PyObject*
oaLibDefList_saveAs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefList data;
    int convert_status=PyoaLibDefList_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefListObject* self=(PyoaLibDefListObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->saveAs(p1.Data());
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
static char oaLibDefList_isNull_doc[] =
"Class: oaLibDefList, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLibDefList_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLibDefList data;
    int convert_status=PyoaLibDefList_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLibDefList_assign_doc[] = 
"Class: oaLibDefList, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLibDefList_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLibDefList data;
  int convert_status=PyoaLibDefList_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLibDefList p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLibDefList_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaLibDefList_methodlist[] = {
    {"destroy",(PyCFunction)oaLibDefList_destroy,METH_VARARGS,oaLibDefList_destroy_doc},
    {"getFullPath",(PyCFunction)oaLibDefList_getFullPath,METH_VARARGS,oaLibDefList_getFullPath_doc},
    {"getMembers",(PyCFunction)oaLibDefList_getMembers,METH_VARARGS,oaLibDefList_getMembers_doc},
    {"getMembersIter",(PyCFunction)oaLibDefList_getMembersIter,METH_VARARGS,oaLibDefList_getMembersIter_doc},
    {"getMode",(PyCFunction)oaLibDefList_getMode,METH_VARARGS,oaLibDefList_getMode_doc},
    {"getPath",(PyCFunction)oaLibDefList_getPath,METH_VARARGS,oaLibDefList_getPath_doc},
    {"save",(PyCFunction)oaLibDefList_save,METH_VARARGS,oaLibDefList_save_doc},
    {"saveAs",(PyCFunction)oaLibDefList_saveAs,METH_VARARGS,oaLibDefList_saveAs_doc},
    {"isNull",(PyCFunction)oaLibDefList_tp_isNull,METH_VARARGS,oaLibDefList_isNull_doc},
    {"assign",(PyCFunction)oaLibDefList_tp_assign,METH_VARARGS,oaLibDefList_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLibDefList_doc[] = 
"Class: oaLibDefList\n"
"  The oaLibDefList class contains functions that users can call to use and manage their library definition file(s) and their library definition file hierarchy.\n"
"  An oaLibDefList object is associated with one or more library definition files. For each session, there is a top-level library definition file, and possibly one or more lower-level library definition files that are referenced in the top-level and/or lower-level files.\n"
"  The top-level library definition file may be the default session library definition file, named lib.defs , or a user-specified file. The statements in a library definition that the oaLibDefList class supports are the following (required keywords, which may be in upper or lower case, are in shown bold ; required arguments are shown in italics separated by one or more spaces):\n"
"  DEFINE libraryName absolute_or_relative_path_from_this_file_to_library\n"
"  INCLUDE absolute_or_relative_path_from_this_file_to_the_included_file\n"
"  ASSIGN libraryName attribute_name attribute_value\n"
"  The oaLibDefList class provides functions that support using and managing library definition files, such as:\n"
"  opening the libraries listed in and referenced by a top-level session default or user-specified library definition file (see oaLibDefList::openLibs )\n"
"  creating an oaLibDefList object for a specified file or changing the mode of accessing the file that is associated with an existing oaLibdefList (see oaLibDefList::get )\n"
"  saving definitions and references contained in an oaLibDefList object to its associated file on disk (see oaLibDefList::save and oaLibDefList::saveAs )\n"
"  Getting a collection of the members contained in an oaLibDefList (see oaLibDefList::getMembers )\n"
"  Data Model\n"
"  An oaLibDefList object contains an ordered collection of oaLibDefListMem objects, which may include one of two types of objects instantiated from classes derived from oaLibDefListMem : library definitions ( oaLibDef objects) and references to other oaLibDefLists ( oaLibDefListRef objects). In effect, lib def lists can be nested by including a reference to another list as a list member. Multiple levels of references, therefore, result in a hierarchy of libDefLists.\n"
"  The order of the oaLibDefListMem objects in an oaLibDefList is meaningful, and it is used by oaLibDefList::openLibs to resolve conflicts among library definitions included in an oaLibDefList hierarchy.\n"
"  Sample Usage\n"
"  For an sample user routine that gets and iterates through all the oaLibDefListMems in an oaLibDefList, see oaLibDefList::getMembers .\n"
"  For a sample routine that appends a new lib def to the lib def file associated with the session's oaLibDefList, see oaLibDefList::getTopList .\n"
"Constructors:\n"
"  Paramegers: (oaLibDefList)\n"
"    Calls: (const oaLibDefList&)\n"
"    Signature: oaLibDefList||cref-oaLibDefList,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLibDefList_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLibDefList",
    sizeof(PyoaLibDefListObject),
    0,
    (destructor)oaLibDefList_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLibDefList_tp_compare,	/* tp_compare */
    (reprfunc)oaLibDefList_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLibDefList_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLibDefList_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaSessionObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLibDefList_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLibDefList_static_find_doc[] = 
"Class: oaLibDefList, Function: find\n"
"  Paramegers: (oaString)\n"
"    Calls: oaLibDefList* find(const oaString& filePath)\n"
"    Signature: find|ptr-oaLibDefList|cref-oaString,\n"
"    This function finds the libDefList object associated with the specified filePath . A NULL pointer is returned if the list is not found.\n"
"    filePath\n"
"    input parameter - the complete relative or absolute path to the file associated with this libDefList. If a relative path is specified, it should be relative to the current working directory.\n"
;

static PyObject*
oaLibDefList_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        oaLibDefListp result= (oaLibDefList::find(p1.Data()));
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
static char oaLibDefList_static_get_doc[] = 
"Class: oaLibDefList, Function: get\n"
"  Paramegers: (oaString,oaChar)\n"
"    Calls: oaLibDefList* get(const oaString& filePath,oaChar mode)\n"
"    Signature: get|ptr-oaLibDefList|cref-oaString,simple-oaChar,\n"
"    oaLibDefList::get\n"
"    This function finds, creates or truncates the library definition list associated with an oaLibDefList object according to the specified filePath and mode . It returns a pointer to the LibDefList named, which might be new or might have existed previously.\n"
"    Note that this function constructs a list of the library definitions (oaLibDefs) and library definition file references (oaLibDefListRefs) found in the specified filePath file only. It does not walk through the library definition list hierarchy and add to the list library definitions contained in other files that are referenced in filepath . For a sample user routine that gets and iterates through all the oaLibDefListMems listed in and referenced by an oaLibDefList object, see oaLibDefList::getMembers .\n"
"    The filePath specifies a library definition file to be associated with the list object. The library definition list will be read in from the file in 'r'ead-only or 'a'ppend mode, or an empty list will be created in 'w'rite mode. The list can later be saved to the file (with an oaLibDefList::save ) only if the preceding get() specified the 'a'ppend' or 'w'rite mode.\n"
"    Note: to change the mode of an existing oaLibDefList object, call get() on the same path that was used to create the existing object, specifying the existing filepath associated with the object and the new mode.\n"
"    filePath\n"
"    input parameter - the complete absolute or relative path to the file associated with this libDefList. A relative path should be specified relative to the current working directory.\n"
"    mode\n"
"    input parameter - There are three modes supported - 'r'ead, 'a'ppend, and 'w'rite.\n"
"    'r': read-only mode - the list is constructed by reading in the contents of the specified file. An exception will be thrown if that file cannot be found or read.\n"
"    'a': append mode - the list is constructed by reading in the contents of the specified file, and it can be saved later. An exception will be thrown if that file exists and is not writable, or if the file exists and is a symbolic link.\n"
"    'w': write mode - an empty list will be constructed and returned. If the file at the specified path exists, it will be truncated during the save() call later, and an exception will be thrown if that file exists and can not be written; if the file does not exist, it will be created if later this list is saved.\n"
"    Example: Suppose the library definition listed in the file specified by filePath has already been constructed through a previous oaLibDefList::openLibs(filePath) call. Then, calling oaLibDefList::get (filePath, 'r') or oaLibDefList::get (filePath, 'a') will only affect the mode of the existing list, while oaLibDefList::get (filePath, 'w') also will truncate the list by emptying it when a later oaLibDefList:: save(filePath) call is made.\n"
"    oacLibDefListFileNotReadable\n"
"    oacLibDefListFileNotWritable\n"
"    oacUndefinedLibDefListMode\n"
"    oacLibDefFileCannotAppendSymbolicLink\n"
;

static PyObject*
oaLibDefList_static_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    PyParamoaChar p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaString_Convert,&p1,
          &PyoaChar_Convert,&p2)) {
        oaLibDefListp result= (oaLibDefList::get(p1.Data(),p2.Data()));
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
static char oaLibDefList_static_getDefaultPath_doc[] = 
"Class: oaLibDefList, Function: getDefaultPath\n"
"  Paramegers: (oaString)\n"
"    Calls: void getDefaultPath(oaString& path)\n"
"    Signature: getDefaultPath|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the default path for the library definition file, named lib.defs , in the user's environment. If the file is not found, an empty string will be returned.\n"
"    The default library definition file, lib.defs , is searched for in the following locations, in the following order: 1) current working directory, 2) in $HOME, then 3) in the data/libraries sub-directory in the OA installation directory. The path to the first-located lib.defs file is returned in filePath .\n"
"    filePath\n"
"    output parameter - output parameter - complete path, including filename, to the found default lib.defs library definition file. The complete path can either be an absolute path or a relative path.\n"
;

static PyObject*
oaLibDefList_static_getDefaultPath(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        oaLibDefList::getDefaultPath(p1.Data());
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
static char oaLibDefList_static_getLibDefLists_doc[] = 
"Class: oaLibDefList, Function: getLibDefLists\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaLibDefList_oaLibDefList getLibDefLists()\n"
"    Signature: getLibDefLists|simple-oaCollection_oaLibDefList_oaLibDefList|\n"
"    BrowseData: 1\n"
"    This function returns a collection of libDefList objects in this session.\n"
;

static PyObject*
oaLibDefList_static_getLibDefLists(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaLibDefList_oaLibDefList* result= new oaCollection_oaLibDefList_oaLibDefList(oaLibDefList::getLibDefLists());
        return PyoaCollection_oaLibDefList_oaLibDefList_FromoaCollection_oaLibDefList_oaLibDefList(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLibDefList_static_getLibDefListsIter_doc[] = 
"Class: oaLibDefList, Function: getLibDefListsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaLibDefList getLibDefListsIter()\n"
"    Signature: getLibDefListsIter|simple-oaIter_oaLibDefList|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of libDefList objects in this session.\n"
;

static PyObject*
oaLibDefList_static_getLibDefListsIter(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaLibDefList* result= new oaIter_oaLibDefList(oaLibDefList::getLibDefLists());
        return PyoaIter_oaLibDefList_FromoaIter_oaLibDefList(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLibDefList_static_getTopList_doc[] = 
"Class: oaLibDefList, Function: getTopList\n"
"  Paramegers: ()\n"
"    Calls: oaLibDefList* getTopList()\n"
"    Signature: getTopList|ptr-oaLibDefList|\n"
"    BrowseData: 1\n"
"    This function gets the current top libDefList for this session. The current top libDefList for this session is established by the top-level oaLibDefList used in the most recent successful oaLibDefList::openLibs() call. If openLibs() has not been called or it failed so that there is no top-level libDefList established for this session, this function will return NULL.\n"
"    Note: getTopList() gets the libDefList in 'r'ead-only mode. This means that the returned oaLibDefList object cannot be saved with a subsequent oaLibDefList::save or oaLibDefList::saveAs() call. To get a list that can be saved, use the oaLibDefList::get function with the 'a'ppend option.\n"
"    Below is a sample routine that gets the top list for an oaLibDefList, changes its mode to append, creates a new libDef, which adds the new lib def to the end of the libDefList object, then saves the updated list to the disk file associated with the list.\n"
"    oaString libraryPath( \"./DesignLib\" ); oaString library( \"DesignLib\" ); oaScalarName libraryName(oaNs,library); oaLibDefList *list = oaLibDefList::getTopList (); if (list) { oaString topListPath; list-> getPath (topListPath); list-> get (topListPath, 'a' ); oaLibDef *newLibDef = oaLibDef::create (list,libraryName,libraryPath); list-> save (); }\n"
;

static PyObject*
oaLibDefList_static_getTopList(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaLibDefListp result= (oaLibDefList::getTopList());
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
static char oaLibDefList_static_openLibs_doc[] = 
"Class: oaLibDefList, Function: openLibs\n"
"  Paramegers: ()\n"
"    Calls: void openLibs()\n"
"    Signature: openLibs|void-void|\n"
"    BrowseData: 0\n"
"    oaLibDefList::openLibs1\n"
"    This function searches for a default library definition file, named lib.defs . If found, this function reads the library definitions listed in the file and any definitions listed in other library definition files included in the file, and opens all the libraries based on the listed definitions. If there is a library open with the same name but with a definition different from the listed definition, the existing library will be closed, and the new definition will be used to open a new library with that name.\n"
"    The default library definition file, lib.defs , is searched for in the following locations, in the following order: 1) current working directory, 2) in $HOME, then 3) in the data/libraries sub-directory in the OA installation directory. The first-located lib.defs file is opened.\n"
"    If the file is not found or cannot be opened, this function returns and provides notification to observers through oaObserver<oaLibDefList>::onLoadWarnings() .\n"
"    The operation is aborted (no libraries will be opened) if there are any syntax errors in the library definition file. oaObserver<oaLibDefList>::onLoadWarnings() will be triggered to pass out all syntax errors found in the file.\n"
"    Warnings other than syntax errors do not result in a termination of the function. Instead, openLibs() will issue a load warning, then attempt to continue opening the libraries. For example, if there are two library definitions with the same logical library name in the oaLibDefList hierarchy, openLibs() will issue a warning, then load the last of the duplicately-defined libraries (it will use the path to the last-listed conflicting library name to open the library).\n"
"  Paramegers: (oaString)\n"
"    Calls: void openLibs(const oaString& path)\n"
"    Signature: openLibs|void-void|cref-oaString,\n"
"    oaLibDefList::openLibs2\n"
"    This function loads the library definition file specified by filePath . Note that if a relative path is specified, it should be relative to the current working directory. This function reads the library definitions listed in the file and any definitions listed in other library definition files included in the file, and opens all the libraries according to their definitions. If there is a library open with the same name but with a definition different from the listed definition, that existing library will be closed and the new definition will be used to open a new library with that name.\n"
"    An oacLibDefFileCannotOpenFile exception is thrown if the path specified does not point to a readable file.\n"
"    The operation is aborted (no libraries will be opened) if there are any syntax errors in the library definition file. oaObserver<oaLibDefList>::onLoadWarnings() will be triggered to pass out all syntax errors found in the file.\n"
"    Warnings other than syntax errors do not result in a termination of the operation. Instead, openLibs() will issue a load warning, then attempt to continue opening the libraries. For example, if there are two library definitions with the same logical library name in the oaLibDefList hierarchy, openLibs() will issue a warning, then load the last of the duplicately-defined libraries (it will use the path to the last-listed conflicting library name to open the library).\n"
"    filePath\n"
"    input parameter - absolute or relative path, including filename. A relative path should be specified relative to the current working directory.\n"
"    oacLibDefFileCannotOpenFile\n"
;

static PyObject*
oaLibDefList_static_openLibs(PyObject* ob, PyObject *args)
{
  try {
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaLibDefList::openLibs();
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
            oaLibDefList::openLibs(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLibDefList, function: openLibs, Choices are:\n"
        "    ()\n"
        "    (oaString)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLibDefList_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaLibDefList_static_find,METH_VARARGS,oaLibDefList_static_find_doc},
    {"static_get",(PyCFunction)oaLibDefList_static_get,METH_VARARGS,oaLibDefList_static_get_doc},
    {"static_getDefaultPath",(PyCFunction)oaLibDefList_static_getDefaultPath,METH_VARARGS,oaLibDefList_static_getDefaultPath_doc},
    {"static_getLibDefLists",(PyCFunction)oaLibDefList_static_getLibDefLists,METH_VARARGS,oaLibDefList_static_getLibDefLists_doc},
    {"static_getLibDefListsIter",(PyCFunction)oaLibDefList_static_getLibDefListsIter,METH_VARARGS,oaLibDefList_static_getLibDefListsIter_doc},
    {"static_getTopList",(PyCFunction)oaLibDefList_static_getTopList,METH_VARARGS,oaLibDefList_static_getTopList_doc},
    {"static_openLibs",(PyCFunction)oaLibDefList_static_openLibs,METH_VARARGS,oaLibDefList_static_openLibs_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLibDefList_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLibDefList_Type)<0) {
      printf("** PyType_Ready failed for: oaLibDefList\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLibDefList",
           (PyObject*)(&PyoaLibDefList_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLibDefList\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLibDefList_Type.tp_dict;
    for(method=oaLibDefList_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaLibDefListMem
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLibDefListMem_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLibDefListMem_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLibDefListMemObject* self = (PyoaLibDefListMemObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLibDefListMem)
    {
        PyParamoaLibDefListMem p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLibDefListMem_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLibDefListMem, Choices are:\n"
        "    (oaLibDefListMem)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaLibDefListMem_tp_dealloc(PyoaLibDefListMemObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLibDefListMem_tp_repr(PyObject *ob)
{
    PyParamoaLibDefListMem value;
    int convert_status=PyoaLibDefListMem_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaLibDefListMem::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLibDefListMem_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLibDefListMem v1;
    PyParamoaLibDefListMem v2;
    int convert_status1=PyoaLibDefListMem_Convert(ob1,&v1);
    int convert_status2=PyoaLibDefListMem_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLibDefListMem_Convert(PyObject* ob,PyParamoaLibDefListMem* result)
{
    if (ob == NULL) return 1;
    if (PyoaLibDefListMem_Check(ob)) {
        result->SetData( (oaLibDefListMem**) ((PyoaLibDefListMemObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLibDefListMem Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLibDefListMem_FromoaLibDefListMem(oaLibDefListMem** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLibDefListMem* data=*value;
        if (data->getType()==oacLibDefListRefType) return PyoaLibDefListRef_FromoaLibDefListRef((oaLibDefListRef**)value,borrow,lock);
        if (data->getType()==oacLibDefType) return PyoaLibDef_FromoaLibDef((oaLibDef**)value,borrow,lock);
        PyObject* bself = PyoaLibDefListMem_Type.tp_alloc(&PyoaLibDefListMem_Type,0);
        if (bself == NULL) return bself;
        PyoaLibDefListMemObject* self = (PyoaLibDefListMemObject*)bself;
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
PyObject* PyoaLibDefListMem_FromoaLibDefListMem(oaLibDefListMem* data)
{
    if (data) {
        if (data->getType()==oacLibDefListRefType) return PyoaLibDefListRef_FromoaLibDefListRef((oaLibDefListRef*)data);
        if (data->getType()==oacLibDefType) return PyoaLibDef_FromoaLibDef((oaLibDef*)data);
       PyObject* bself = PyoaLibDefListMem_Type.tp_alloc(&PyoaLibDefListMem_Type,0);
       if (bself == NULL) return bself;
       PyoaLibDefListMemObject* self = (PyoaLibDefListMemObject*)bself;
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
static char oaLibDefListMem_destroy_doc[] = 
"Class: oaLibDefListMem, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    oaLibDefListMem::destroy\n"
"    This function destroys this oaLibDefListMem object.\n"
;

static PyObject*
oaLibDefListMem_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefListMem data;
    int convert_status=PyoaLibDefListMem_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefListMemObject* self=(PyoaLibDefListMemObject*)ob;
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
static char oaLibDefListMem_getList_doc[] = 
"Class: oaLibDefListMem, Function: getList\n"
"  Paramegers: ()\n"
"    Calls: oaLibDefList* getList() const\n"
"    Signature: getList|ptr-oaLibDefList|\n"
"    BrowseData: 1\n"
"    This function returns the oaLibDefList which contains this member object.\n"
;

static PyObject*
oaLibDefListMem_getList(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefListMem data;
    int convert_status=PyoaLibDefListMem_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefListMemObject* self=(PyoaLibDefListMemObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLibDefListp result= (data.DataCall()->getList());
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
static char oaLibDefListMem_moveAfter_doc[] = 
"Class: oaLibDefListMem, Function: moveAfter\n"
"  Paramegers: (oaLibDefListMem)\n"
"    Calls: void moveAfter(oaLibDefListMem* member)\n"
"    Signature: moveAfter|void-void|ptr-oaLibDefListMem,\n"
"    This function moves this oaLibDefListMem object after the specified member in the owning oaLibDefList .\n"
"    member\n"
"    input parameter - The list member that this object will be moved after.\n"
"    oacInvalidLibDefListMemMove\n"
;

static PyObject*
oaLibDefListMem_moveAfter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefListMem data;
    int convert_status=PyoaLibDefListMem_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefListMemObject* self=(PyoaLibDefListMemObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaLibDefListMem p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLibDefListMem_Convert,&p1)) {
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
static char oaLibDefListMem_moveToFirst_doc[] = 
"Class: oaLibDefListMem, Function: moveToFirst\n"
"  Paramegers: ()\n"
"    Calls: void moveToFirst()\n"
"    Signature: moveToFirst|void-void|\n"
"    BrowseData: 0\n"
"    This function moves this oaLibDefListMem object to the first position in the owning oaLibDefList .\n"
;

static PyObject*
oaLibDefListMem_moveToFirst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefListMem data;
    int convert_status=PyoaLibDefListMem_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefListMemObject* self=(PyoaLibDefListMemObject*)ob;
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
static char oaLibDefListMem_moveToLast_doc[] = 
"Class: oaLibDefListMem, Function: moveToLast\n"
"  Paramegers: ()\n"
"    Calls: void moveToLast()\n"
"    Signature: moveToLast|void-void|\n"
"    BrowseData: 0\n"
"    This function moves this oaLibDefListMem object to the last position in the owning oaLibDefList .\n"
;

static PyObject*
oaLibDefListMem_moveToLast(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefListMem data;
    int convert_status=PyoaLibDefListMem_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefListMemObject* self=(PyoaLibDefListMemObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->moveToLast();
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
static char oaLibDefListMem_isNull_doc[] =
"Class: oaLibDefListMem, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLibDefListMem_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLibDefListMem data;
    int convert_status=PyoaLibDefListMem_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLibDefListMem_assign_doc[] = 
"Class: oaLibDefListMem, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLibDefListMem_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLibDefListMem data;
  int convert_status=PyoaLibDefListMem_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLibDefListMem p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLibDefListMem_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaLibDefListMem_methodlist[] = {
    {"destroy",(PyCFunction)oaLibDefListMem_destroy,METH_VARARGS,oaLibDefListMem_destroy_doc},
    {"getList",(PyCFunction)oaLibDefListMem_getList,METH_VARARGS,oaLibDefListMem_getList_doc},
    {"moveAfter",(PyCFunction)oaLibDefListMem_moveAfter,METH_VARARGS,oaLibDefListMem_moveAfter_doc},
    {"moveToFirst",(PyCFunction)oaLibDefListMem_moveToFirst,METH_VARARGS,oaLibDefListMem_moveToFirst_doc},
    {"moveToLast",(PyCFunction)oaLibDefListMem_moveToLast,METH_VARARGS,oaLibDefListMem_moveToLast_doc},
    {"isNull",(PyCFunction)oaLibDefListMem_tp_isNull,METH_VARARGS,oaLibDefListMem_isNull_doc},
    {"assign",(PyCFunction)oaLibDefListMem_tp_assign,METH_VARARGS,oaLibDefListMem_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLibDefListMem_doc[] = 
"Class: oaLibDefListMem\n"
"  oaLibDefListMem is a base class that represents a member in a oaLibDefList . It has two derived classes: oaLibDef , which represents a library definition, and oaLibDefListRef , which represents a reference to another lib def list.\n"
"  For a sample user routine that gets and iterates through all the oaLibDefListMems in an oaLibDefList passed to the routine in order to process all the library definitions found in the user's library definition file hierarchy, see oaLibDefList::getMembers .\n"
"Constructors:\n"
"  Paramegers: (oaLibDefListMem)\n"
"    Calls: (const oaLibDefListMem&)\n"
"    Signature: oaLibDefListMem||cref-oaLibDefListMem,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLibDefListMem_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLibDefListMem",
    sizeof(PyoaLibDefListMemObject),
    0,
    (destructor)oaLibDefListMem_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLibDefListMem_tp_compare,	/* tp_compare */
    (reprfunc)oaLibDefListMem_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLibDefListMem_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLibDefListMem_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaSessionObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLibDefListMem_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLibDefListMem_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLibDefListMem_Type)<0) {
      printf("** PyType_Ready failed for: oaLibDefListMem\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLibDefListMem",
           (PyObject*)(&PyoaLibDefListMem_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLibDefListMem\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaLibDefListRef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLibDefListRef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLibDefListRef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLibDefListRefObject* self = (PyoaLibDefListRefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLibDefListRef)
    {
        PyParamoaLibDefListRef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLibDefListRef_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLibDefListRef, Choices are:\n"
        "    (oaLibDefListRef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaLibDefListRef_tp_dealloc(PyoaLibDefListRefObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLibDefListRef_tp_repr(PyObject *ob)
{
    PyParamoaLibDefListRef value;
    int convert_status=PyoaLibDefListRef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaLibDefListRef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLibDefListRef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLibDefListRef v1;
    PyParamoaLibDefListRef v2;
    int convert_status1=PyoaLibDefListRef_Convert(ob1,&v1);
    int convert_status2=PyoaLibDefListRef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLibDefListRef_Convert(PyObject* ob,PyParamoaLibDefListRef* result)
{
    if (ob == NULL) return 1;
    if (PyoaLibDefListRef_Check(ob)) {
        result->SetData( (oaLibDefListRef**) ((PyoaLibDefListRefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLibDefListRef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLibDefListRef_FromoaLibDefListRef(oaLibDefListRef** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLibDefListRef* data=*value;
        PyObject* bself = PyoaLibDefListRef_Type.tp_alloc(&PyoaLibDefListRef_Type,0);
        if (bself == NULL) return bself;
        PyoaLibDefListRefObject* self = (PyoaLibDefListRefObject*)bself;
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
PyObject* PyoaLibDefListRef_FromoaLibDefListRef(oaLibDefListRef* data)
{
    if (data) {
       PyObject* bself = PyoaLibDefListRef_Type.tp_alloc(&PyoaLibDefListRef_Type,0);
       if (bself == NULL) return bself;
       PyoaLibDefListRefObject* self = (PyoaLibDefListRefObject*)bself;
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
static char oaLibDefListRef_getRefListPath_doc[] = 
"Class: oaLibDefListRef, Function: getRefListPath\n"
"  Paramegers: (oaString)\n"
"    Calls: void getRefListPath(oaString& path) const\n"
"    Signature: getRefListPath|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function fills in the path to the referred list of this libDefListRef object.\n"
"    path\n"
"    output parameter - the path to the referred libDefList.\n"
;

static PyObject*
oaLibDefListRef_getRefListPath(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefListRef data;
    int convert_status=PyoaLibDefListRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibDefListRefObject* self=(PyoaLibDefListRefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getRefListPath(p1.Data());
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
static char oaLibDefListRef_isNull_doc[] =
"Class: oaLibDefListRef, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLibDefListRef_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLibDefListRef data;
    int convert_status=PyoaLibDefListRef_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLibDefListRef_assign_doc[] = 
"Class: oaLibDefListRef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLibDefListRef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLibDefListRef data;
  int convert_status=PyoaLibDefListRef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLibDefListRef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLibDefListRef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaLibDefListRef_methodlist[] = {
    {"getRefListPath",(PyCFunction)oaLibDefListRef_getRefListPath,METH_VARARGS,oaLibDefListRef_getRefListPath_doc},
    {"isNull",(PyCFunction)oaLibDefListRef_tp_isNull,METH_VARARGS,oaLibDefListRef_isNull_doc},
    {"assign",(PyCFunction)oaLibDefListRef_tp_assign,METH_VARARGS,oaLibDefListRef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLibDefListRef_doc[] = 
"Class: oaLibDefListRef\n"
"  oaLibDefListRef is a derived class of oaLibDefListMem . It represents a reference to a another library definition list in the owning oaLibDefList .\n"
"Constructors:\n"
"  Paramegers: (oaLibDefListRef)\n"
"    Calls: (const oaLibDefListRef&)\n"
"    Signature: oaLibDefListRef||cref-oaLibDefListRef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLibDefListRef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLibDefListRef",
    sizeof(PyoaLibDefListRefObject),
    0,
    (destructor)oaLibDefListRef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLibDefListRef_tp_compare,	/* tp_compare */
    (reprfunc)oaLibDefListRef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLibDefListRef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLibDefListRef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaLibDefListMem_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLibDefListRef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLibDefListRef_static_create_doc[] = 
"Class: oaLibDefListRef, Function: create\n"
"  Paramegers: (oaLibDefList,oaString)\n"
"    Calls: oaLibDefListRef* create(oaLibDefList* libList,const oaString& refListPath)\n"
"    Signature: create|ptr-oaLibDefListRef|ptr-oaLibDefList,cref-oaString,ptr-oaLibDefListMem,\n"
"    This function creates the libDefListRef object in the owning libList with the the given parameters. Exceptions will be thrown if a reference object already exists with the same path as refListPath .\n"
"    This object will be created in the owning libList before the specified followingMem , which must be in the same owning list. If followinMem is not specified (or if NULL is specified), this object will be positioned at the end of the owning libList .\n"
"    libList\n"
"    input parameter - The oaLibDefList in which this oaLibDefListRef will be created.\n"
"    refListPath\n"
"    input parameter - The path to the file of the referred libDefList. A relative path can be specified, which must be relative to the path of the file of the owning libList .\n"
"    followingMem\n"
"    optional input parameter - The member in the owning libList list that this libDef will be positioned in front of. If this parameter is not specified (or if NULL is specified), this oaLibDefListRef will be positioned at the end of the owning libList .\n"
"    oacLibDefListRefExists\n"
"    oacInvalidLibDefListMemCreate\n"
"  Paramegers: (oaLibDefList,oaString,oaLibDefListMem)\n"
"    Calls: oaLibDefListRef* create(oaLibDefList* libList,const oaString& refListPath,oaLibDefListMem* followingMem)\n"
"    Signature: create|ptr-oaLibDefListRef|ptr-oaLibDefList,cref-oaString,ptr-oaLibDefListMem,\n"
"    This function creates the libDefListRef object in the owning libList with the the given parameters. Exceptions will be thrown if a reference object already exists with the same path as refListPath .\n"
"    This object will be created in the owning libList before the specified followingMem , which must be in the same owning list. If followinMem is not specified (or if NULL is specified), this object will be positioned at the end of the owning libList .\n"
"    libList\n"
"    input parameter - The oaLibDefList in which this oaLibDefListRef will be created.\n"
"    refListPath\n"
"    input parameter - The path to the file of the referred libDefList. A relative path can be specified, which must be relative to the path of the file of the owning libList .\n"
"    followingMem\n"
"    optional input parameter - The member in the owning libList list that this libDef will be positioned in front of. If this parameter is not specified (or if NULL is specified), this oaLibDefListRef will be positioned at the end of the owning libList .\n"
"    oacLibDefListRefExists\n"
"    oacInvalidLibDefListMemCreate\n"
;

static PyObject*
oaLibDefListRef_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaLibDefList,oaString)
    {
        PyParamoaLibDefList p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaLibDefList_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaLibDefListRefp result= (oaLibDefListRef::create(p1.Data(),p2.Data()));
            return PyoaLibDefListRef_FromoaLibDefListRef(result);
        }
    }
    PyErr_Clear();
    // Case: (oaLibDefList,oaString,oaLibDefListMem)
    {
        PyParamoaLibDefList p1;
        PyParamoaString p2;
        PyParamoaLibDefListMem p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaLibDefList_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaLibDefListMem_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaLibDefListRefp result= (oaLibDefListRef::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaLibDefListRef_FromoaLibDefListRef(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaLibDefListRef, function: create, Choices are:\n"
        "    (oaLibDefList,oaString)\n"
        "    (oaLibDefList,oaString,oaLibDefListMem)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLibDefListRef_static_find_doc[] = 
"Class: oaLibDefListRef, Function: find\n"
"  Paramegers: (oaLibDefList,oaString)\n"
"    Calls: oaLibDefListRef* find(const oaLibDefList* defList,const oaString& refListPath)\n"
"    Signature: find|ptr-oaLibDefListRef|cptr-oaLibDefList,cref-oaString,\n"
"    This function attempts to find and return the libDefListRef object in the owning defList that refers to a libDefList at the specified refListPath .\n"
"    defList\n"
"    input parameter - The owning oaLibDefList to search.\n"
"    refListPath\n"
"    input parameter- The path to the file of the referred libDefList. A Relative path may be specified, which must be relative to the path of the file of the owning defList .\n"
;

static PyObject*
oaLibDefListRef_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefList p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaLibDefList_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaLibDefListRefp result= (oaLibDefListRef::find(p1.Data(),p2.Data()));
        return PyoaLibDefListRef_FromoaLibDefListRef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLibDefListRef_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaLibDefListRef_static_create,METH_VARARGS,oaLibDefListRef_static_create_doc},
    {"static_find",(PyCFunction)oaLibDefListRef_static_find,METH_VARARGS,oaLibDefListRef_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLibDefListRef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLibDefListRef_Type)<0) {
      printf("** PyType_Ready failed for: oaLibDefListRef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLibDefListRef",
           (PyObject*)(&PyoaLibDefListRef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLibDefListRef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLibDefListRef_Type.tp_dict;
    for(method=oaLibDefListRef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaLibDefListWarningTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaLibDefListWarningTypeEnum_Convert(PyObject* ob,PyParamoaLibDefListWarningTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacNoDefaultLibDefListWarning")==0) { result->SetData(oacNoDefaultLibDefListWarning); return 1;}
        if (strcasecmp(str,"oacCannotOpenDefaultLibDefListWarning")==0) { result->SetData(oacCannotOpenDefaultLibDefListWarning); return 1;}
        if (strcasecmp(str,"oacSyntaxErrorLibDefListWarning")==0) { result->SetData(oacSyntaxErrorLibDefListWarning); return 1;}
        if (strcasecmp(str,"oacCannotOpenIncludeLibDefListWarning")==0) { result->SetData(oacCannotOpenIncludeLibDefListWarning); return 1;}
        if (strcasecmp(str,"oacRecursiveIncludeLibDefListWarning")==0) { result->SetData(oacRecursiveIncludeLibDefListWarning); return 1;}
        if (strcasecmp(str,"oacMultiDefinitionsLibDefListWarning")==0) { result->SetData(oacMultiDefinitionsLibDefListWarning); return 1;}
        if (strcasecmp(str,"oacCannotOpenLibLibDefListWarning")==0) { result->SetData(oacCannotOpenLibLibDefListWarning); return 1;}
        if (strcasecmp(str,"oacUndefinedVarLibDefListWarning")==0) { result->SetData(oacUndefinedVarLibDefListWarning); return 1;}
        if (strcasecmp(str,"oacLibNameUndefinedLibDefListWarning")==0) { result->SetData(oacLibNameUndefinedLibDefListWarning); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaLibDefListWarningTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLibDefListWarningTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaLibDefListWarningTypeEnum_FromoaLibDefListWarningTypeEnum(oaLibDefListWarningTypeEnum ob)
{
    if (ob==oacNoDefaultLibDefListWarning) return PyString_FromString("oacNoDefaultLibDefListWarning");
    if (ob==oacCannotOpenDefaultLibDefListWarning) return PyString_FromString("oacCannotOpenDefaultLibDefListWarning");
    if (ob==oacSyntaxErrorLibDefListWarning) return PyString_FromString("oacSyntaxErrorLibDefListWarning");
    if (ob==oacCannotOpenIncludeLibDefListWarning) return PyString_FromString("oacCannotOpenIncludeLibDefListWarning");
    if (ob==oacRecursiveIncludeLibDefListWarning) return PyString_FromString("oacRecursiveIncludeLibDefListWarning");
    if (ob==oacMultiDefinitionsLibDefListWarning) return PyString_FromString("oacMultiDefinitionsLibDefListWarning");
    if (ob==oacCannotOpenLibLibDefListWarning) return PyString_FromString("oacCannotOpenLibLibDefListWarning");
    if (ob==oacUndefinedVarLibDefListWarning) return PyString_FromString("oacUndefinedVarLibDefListWarning");
    if (ob==oacLibNameUndefinedLibDefListWarning) return PyString_FromString("oacLibNameUndefinedLibDefListWarning");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaLibDefListWarningTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaLibDefListWarningTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaLibDefListWarningTypeEnum_FromoaLibDefListWarningTypeEnum(oaLibDefListWarningTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaLibDefListWarningTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaLibDefListWarningTypeEnum_doc[] =
"Type convert function for enum: oaLibDefListWarningTypeEnum";
                               
static PyMethodDef PyoaLibDefListWarningTypeEnum_method =
  {"oaLibDefListWarningTypeEnum",(PyCFunction)PyoaLibDefListWarningTypeEnum_TypeFunction,METH_VARARGS,oaLibDefListWarningTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaLibDefListWarningTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacNoDefaultLibDefListWarning");
    PyDict_SetItemString(mod_dict,"oacNoDefaultLibDefListWarning",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotOpenDefaultLibDefListWarning");
    PyDict_SetItemString(mod_dict,"oacCannotOpenDefaultLibDefListWarning",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSyntaxErrorLibDefListWarning");
    PyDict_SetItemString(mod_dict,"oacSyntaxErrorLibDefListWarning",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotOpenIncludeLibDefListWarning");
    PyDict_SetItemString(mod_dict,"oacCannotOpenIncludeLibDefListWarning",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRecursiveIncludeLibDefListWarning");
    PyDict_SetItemString(mod_dict,"oacRecursiveIncludeLibDefListWarning",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMultiDefinitionsLibDefListWarning");
    PyDict_SetItemString(mod_dict,"oacMultiDefinitionsLibDefListWarning",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCannotOpenLibLibDefListWarning");
    PyDict_SetItemString(mod_dict,"oacCannotOpenLibLibDefListWarning",value);
    Py_DECREF(value);
    value=PyString_FromString("oacUndefinedVarLibDefListWarning");
    PyDict_SetItemString(mod_dict,"oacUndefinedVarLibDefListWarning",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibNameUndefinedLibDefListWarning");
    PyDict_SetItemString(mod_dict,"oacLibNameUndefinedLibDefListWarning",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaLibDefListWarningTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaLibDefListWarningTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaLibDefListWarningTypeEnum\n");
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
// Wrapper Implementation for Class: oaLibMode
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLibMode_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLibMode_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLibModeObject* self = (PyoaLibModeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLibModeEnum)
    {
        PyParamoaLibModeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaLibModeEnum_Convert,&p1)) {
            self->value =  new oaLibMode(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaLibMode(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaLibMode)
    {
        PyParamoaLibMode p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLibMode_Convert,&p1)) {
            self->value= new oaLibMode(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaLibMode, Choices are:\n"
        "    (oaLibModeEnum)\n"
        "    (oaString)\n"
        "    (oaLibMode)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaLibMode_tp_dealloc(PyoaLibModeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLibMode_tp_repr(PyObject *ob)
{
    PyParamoaLibMode value;
    int convert_status=PyoaLibMode_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[31];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaLibMode::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLibMode_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLibMode v1;
    PyParamoaLibMode v2;
    int convert_status1=PyoaLibMode_Convert(ob1,&v1);
    int convert_status2=PyoaLibMode_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLibMode_Convert(PyObject* ob,PyParamoaLibMode* result)
{
    if (ob == NULL) return 1;
    if (PyoaLibMode_Check(ob)) {
        result->SetData(  ((PyoaLibModeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLibMode Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLibMode_FromoaLibMode(oaLibMode* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaLibMode_Type.tp_alloc(&PyoaLibMode_Type,0);
        if (bself == NULL) return bself;
        PyoaLibModeObject* self = (PyoaLibModeObject*)bself;
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
static char oaLibMode_getName_doc[] = 
"Class: oaLibMode, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the string name of the oaLibModeEnum value for this oaLibMode wrapper object.\n"
;

static PyObject*
oaLibMode_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibMode data;
    int convert_status=PyoaLibMode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibModeObject* self=(PyoaLibModeObject*)ob;

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
static char oaLibMode_oaLibModeEnum_doc[] = 
"Class: oaLibMode, Function: oaLibModeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaLibModeEnum oaLibModeEnum() const\n"
"    Signature: operator oaLibModeEnum|simple-oaLibModeEnum|\n"
"    BrowseData: 1\n"
"    This function returns the oaLibModeEnum value for this oaLibMode wrapper object.\n"
;

static PyObject*
oaLibMode_oaLibModeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibMode data;
    int convert_status=PyoaLibMode_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLibModeObject* self=(PyoaLibModeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLibModeEnum result= (data.DataCall()->operator oaLibModeEnum());
        return PyoaLibModeEnum_FromoaLibModeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaLibMode_assign_doc[] = 
"Class: oaLibMode, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLibMode_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLibMode data;
  int convert_status=PyoaLibMode_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLibMode p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLibMode_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaLibMode_methodlist[] = {
    {"getName",(PyCFunction)oaLibMode_getName,METH_VARARGS,oaLibMode_getName_doc},
    {"oaLibModeEnum",(PyCFunction)oaLibMode_oaLibModeEnum,METH_VARARGS,oaLibMode_oaLibModeEnum_doc},
    {"assign",(PyCFunction)oaLibMode_tp_assign,METH_VARARGS,oaLibMode_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLibMode_doc[] = 
"Class: oaLibMode\n"
"  oaLibModeEnum\n"
"  oaLibMode is an wrapper class that encapsulates oaLibModeEnum values, which represent the modes available for accessing a library.\n"
"Constructors:\n"
"  Paramegers: (oaLibModeEnum)\n"
"    Calls: oaLibMode(oaLibModeEnum valueIn)\n"
"    Signature: oaLibMode||simple-oaLibModeEnum,\n"
"    This constructor for the oaLibMode class enum wrapper takes an oaLibMode type as input.\n"
"    valueIn\n"
"    an oaLibModeEnum value\n"
"  Paramegers: (oaString)\n"
"    Calls: oaLibMode(const oaString& name)\n"
"    Signature: oaLibMode||cref-oaString,\n"
"    This constructor for the oaLibMode class enum wrapper takes an oaLibModeEnum string name as input.\n"
"    name\n"
"    an oaLibModeEnum string name\n"
"    oacInvalidLibModeName\n"
"    the specified oaLibModeEnum string name is invalid\n"
"  Paramegers: (oaLibMode)\n"
"    Calls: (const oaLibMode&)\n"
"    Signature: oaLibMode||cref-oaLibMode,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLibMode_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLibMode",
    sizeof(PyoaLibModeObject),
    0,
    (destructor)oaLibMode_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLibMode_tp_compare,	/* tp_compare */
    (reprfunc)oaLibMode_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLibMode_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLibMode_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLibMode_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLibMode_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLibMode_Type)<0) {
      printf("** PyType_Ready failed for: oaLibMode\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLibMode",
           (PyObject*)(&PyoaLibMode_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLibMode\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaLibModeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaLibModeEnum_Convert(PyObject* ob,PyParamoaLibModeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSharedLibMode")==0) { result->SetData(oacSharedLibMode); return 1;}
        if (strcasecmp(str,"oacNonSharedLibMode")==0) { result->SetData(oacNonSharedLibMode); return 1;}
        if (strcasecmp(str,"oacReadOnlyLibMode")==0) { result->SetData(oacReadOnlyLibMode); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaLibModeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLibModeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaLibModeEnum_FromoaLibModeEnum(oaLibModeEnum ob)
{
    if (ob==oacSharedLibMode) return PyString_FromString("oacSharedLibMode");
    if (ob==oacNonSharedLibMode) return PyString_FromString("oacNonSharedLibMode");
    if (ob==oacReadOnlyLibMode) return PyString_FromString("oacReadOnlyLibMode");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaLibModeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaLibModeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaLibModeEnum_FromoaLibModeEnum(oaLibModeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaLibModeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaLibModeEnum_doc[] =
"Type convert function for enum: oaLibModeEnum";
                               
static PyMethodDef PyoaLibModeEnum_method =
  {"oaLibModeEnum",(PyCFunction)PyoaLibModeEnum_TypeFunction,METH_VARARGS,oaLibModeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaLibModeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSharedLibMode");
    PyDict_SetItemString(mod_dict,"oacSharedLibMode",value);
    Py_DECREF(value);
    value=PyString_FromString("oacNonSharedLibMode");
    PyDict_SetItemString(mod_dict,"oacNonSharedLibMode",value);
    Py_DECREF(value);
    value=PyString_FromString("oacReadOnlyLibMode");
    PyDict_SetItemString(mod_dict,"oacReadOnlyLibMode",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaLibModeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaLibModeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaLibModeEnum\n");
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
// Wrapper Implementation for Class: oaLine
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLine_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLine_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLineObject* self = (PyoaLineObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLine)
    {
        PyParamoaLine p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLine_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLine, Choices are:\n"
        "    (oaLine)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaLine_tp_dealloc(PyoaLineObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLine_tp_repr(PyObject *ob)
{
    PyParamoaLine value;
    int convert_status=PyoaLine_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[28];
    sprintf(buffer,"<oaLine::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLine_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLine v1;
    PyParamoaLine v2;
    int convert_status1=PyoaLine_Convert(ob1,&v1);
    int convert_status2=PyoaLine_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLine_Convert(PyObject* ob,PyParamoaLine* result)
{
    if (ob == NULL) return 1;
    if (PyoaLine_Check(ob)) {
        result->SetData( (oaLine**) ((PyoaLineObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLine Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLine_FromoaLine(oaLine** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLine* data=*value;
        PyObject* bself = PyoaLine_Type.tp_alloc(&PyoaLine_Type,0);
        if (bself == NULL) return bself;
        PyoaLineObject* self = (PyoaLineObject*)bself;
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
PyObject* PyoaLine_FromoaLine(oaLine* data)
{
    if (data) {
       PyObject* bself = PyoaLine_Type.tp_alloc(&PyoaLine_Type,0);
       if (bself == NULL) return bself;
       PyoaLineObject* self = (PyoaLineObject*)bself;
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
static char oaLine_getNumPoints_doc[] = 
"Class: oaLine, Function: getNumPoints\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumPoints() const\n"
"    Signature: getNumPoints|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of nonidentical points in this line.\n"
;

static PyObject*
oaLine_getNumPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLine data;
    int convert_status=PyoaLine_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLineObject* self=(PyoaLineObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumPoints());
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
static char oaLine_getPoints_doc[] = 
"Class: oaLine, Function: getPoints\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void getPoints(oaPointArray& points) const\n"
"    Signature: getPoints|void-void|ref-oaPointArray,\n"
"    BrowseData: 0,oaPointArray\n"
"    This function fills out points with the points of this line.\n"
;

static PyObject*
oaLine_getPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLine data;
    int convert_status=PyoaLine_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLineObject* self=(PyoaLineObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPointArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPointArray_Convert,&p1)) {
        data.DataCall()->getPoints(p1.Data());
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
static char oaLine_setPoints_doc[] = 
"Class: oaLine, Function: setPoints\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void setPoints(const oaPointArray& points)\n"
"    Signature: setPoints|void-void|cref-oaPointArray,\n"
"    This function sets the points of this line to the specified pointArray. The new pointArray is first compressed to remove any collinear or coincident points. It is then checked to verify there are at least three remaining points.\n"
"    oacLineTooFewPoints\n"
;

static PyObject*
oaLine_setPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLine data;
    int convert_status=PyoaLine_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLineObject* self=(PyoaLineObject*)ob;
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
static char oaLine_isNull_doc[] =
"Class: oaLine, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLine_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLine data;
    int convert_status=PyoaLine_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLine_assign_doc[] = 
"Class: oaLine, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLine_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLine data;
  int convert_status=PyoaLine_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLine p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLine_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaLine_methodlist[] = {
    {"getNumPoints",(PyCFunction)oaLine_getNumPoints,METH_VARARGS,oaLine_getNumPoints_doc},
    {"getPoints",(PyCFunction)oaLine_getPoints,METH_VARARGS,oaLine_getPoints_doc},
    {"setPoints",(PyCFunction)oaLine_setPoints,METH_VARARGS,oaLine_setPoints_doc},
    {"isNull",(PyCFunction)oaLine_tp_isNull,METH_VARARGS,oaLine_isNull_doc},
    {"assign",(PyCFunction)oaLine_tp_assign,METH_VARARGS,oaLine_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLine_doc[] = 
"Class: oaLine\n"
"  The oaLine class is a subclass of oaShape that implements a line shape. The oaLine class contains a compressed pointArray that represents a line in the design.\n"
"Constructors:\n"
"  Paramegers: (oaLine)\n"
"    Calls: (const oaLine&)\n"
"    Signature: oaLine||cref-oaLine,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLine_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLine",
    sizeof(PyoaLineObject),
    0,
    (destructor)oaLine_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLine_tp_compare,	/* tp_compare */
    (reprfunc)oaLine_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLine_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLine_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaShape_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLine_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLine_static_create_doc[] = 
"Class: oaLine, Function: create\n"
"  Paramegers: (oaBlock,oaLayerNum,oaPurposeNum,oaPointArray)\n"
"    Calls: oaLine* create(oaBlock* block,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPointArray& points)\n"
"    Signature: create|ptr-oaLine|ptr-oaBlock,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPointArray,\n"
"    This function creates a line with the specified attributes. The specified pointArray is first compressed to remove any collinear or coincident points. It is then checked to verify that there are at least two remaining points.\n"
"    block\n"
"    The block in which this line is located\n"
"    layerNum\n"
"    The number of the layer on which this line is located\n"
"    purposeNum\n"
"    The number of the purpose on which this line is located\n"
"    points\n"
"    The pointArray used to construct this line\n"
"    oacLineTooFewPoints\n"
;

static PyObject*
oaLine_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBlock p1;
    PyParamoaLayerNum p2;
    PyParamoaPurposeNum p3;
    PyParamoaPointArray p4;
    if (PyArg_ParseTuple(args,"O&O&O&O&",
          &PyoaBlock_Convert,&p1,
          &PyoaLayerNum_Convert,&p2,
          &PyoaPurposeNum_Convert,&p3,
          &PyoaPointArray_Convert,&p4)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaLinep result= (oaLine::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
        return PyoaLine_FromoaLine(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLine_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaLine_static_create,METH_VARARGS,oaLine_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLine_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLine_Type)<0) {
      printf("** PyType_Ready failed for: oaLine\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLine",
           (PyObject*)(&PyoaLine_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLine\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLine_Type.tp_dict;
    for(method=oaLine_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaLumpedElmore
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaLumpedElmore_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaLumpedElmore_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaLumpedElmoreObject* self = (PyoaLumpedElmoreObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaLumpedElmore)
    {
        PyParamoaLumpedElmore p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaLumpedElmore_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaLumpedElmore, Choices are:\n"
        "    (oaLumpedElmore)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaLumpedElmore_tp_dealloc(PyoaLumpedElmoreObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaLumpedElmore_tp_repr(PyObject *ob)
{
    PyParamoaLumpedElmore value;
    int convert_status=PyoaLumpedElmore_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaLumpedElmore::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaLumpedElmore_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaLumpedElmore v1;
    PyParamoaLumpedElmore v2;
    int convert_status1=PyoaLumpedElmore_Convert(ob1,&v1);
    int convert_status2=PyoaLumpedElmore_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaLumpedElmore_Convert(PyObject* ob,PyParamoaLumpedElmore* result)
{
    if (ob == NULL) return 1;
    if (PyoaLumpedElmore_Check(ob)) {
        result->SetData( (oaLumpedElmore**) ((PyoaLumpedElmoreObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaLumpedElmore Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaLumpedElmore_FromoaLumpedElmore(oaLumpedElmore** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaLumpedElmore* data=*value;
        PyObject* bself = PyoaLumpedElmore_Type.tp_alloc(&PyoaLumpedElmore_Type,0);
        if (bself == NULL) return bself;
        PyoaLumpedElmoreObject* self = (PyoaLumpedElmoreObject*)bself;
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
PyObject* PyoaLumpedElmore_FromoaLumpedElmore(oaLumpedElmore* data)
{
    if (data) {
       PyObject* bself = PyoaLumpedElmore_Type.tp_alloc(&PyoaLumpedElmore_Type,0);
       if (bself == NULL) return bself;
       PyoaLumpedElmoreObject* self = (PyoaLumpedElmoreObject*)bself;
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
static char oaLumpedElmore_getElmores_doc[] = 
"Class: oaLumpedElmore, Function: getElmores\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaElmore_oaLumpedElmore getElmores() const\n"
"    Signature: getElmores|simple-oaCollection_oaElmore_oaLumpedElmore|\n"
"    BrowseData: 1\n"
"    This function returns a collection of elmores for the receivers in this reduced model.\n"
;

static PyObject*
oaLumpedElmore_getElmores(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLumpedElmore data;
    int convert_status=PyoaLumpedElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLumpedElmoreObject* self=(PyoaLumpedElmoreObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaElmore_oaLumpedElmore* result= new oaCollection_oaElmore_oaLumpedElmore(data.DataCall()->getElmores());
        return PyoaCollection_oaElmore_oaLumpedElmore_FromoaCollection_oaElmore_oaLumpedElmore(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLumpedElmore_getElmoresIter_doc[] = 
"Class: oaLumpedElmore, Function: getElmoresIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaElmore getElmoresIter() const\n"
"    Signature: getElmoresIter|simple-oaIter_oaElmore|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of elmores for the receivers in this reduced model.\n"
;

static PyObject*
oaLumpedElmore_getElmoresIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLumpedElmore data;
    int convert_status=PyoaLumpedElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLumpedElmoreObject* self=(PyoaLumpedElmoreObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaElmore* result= new oaIter_oaElmore(data.DataCall()->getElmores());
        return PyoaIter_oaElmore_FromoaIter_oaElmore(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLumpedElmore_getTotalCap_doc[] = 
"Class: oaLumpedElmore, Function: getTotalCap\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getTotalCap() const\n"
"    Signature: getTotalCap|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the total capacitance value for this oaLumpedElmore model.\n"
"    OpenAccess assumes capacitance data is specified in Farads\n"
;

static PyObject*
oaLumpedElmore_getTotalCap(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLumpedElmore data;
    int convert_status=PyoaLumpedElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLumpedElmoreObject* self=(PyoaLumpedElmoreObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getTotalCap());
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
static char oaLumpedElmore_setTotalCap_doc[] = 
"Class: oaLumpedElmore, Function: setTotalCap\n"
"  Paramegers: (oaFloat)\n"
"    Calls: void setTotalCap(oaFloat value)\n"
"    Signature: setTotalCap|void-void|simple-oaFloat,\n"
"    This function sets the total capacitance value for this oaLumpedElmore model.\n"
"    OpenAccess assumes capacitance data is specified in Farads\n"
;

static PyObject*
oaLumpedElmore_setTotalCap(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLumpedElmore data;
    int convert_status=PyoaLumpedElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaLumpedElmoreObject* self=(PyoaLumpedElmoreObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFloat_Convert,&p1)) {
        data.DataCall()->setTotalCap(p1.Data());
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
static char oaLumpedElmore_isNull_doc[] =
"Class: oaLumpedElmore, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaLumpedElmore_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaLumpedElmore data;
    int convert_status=PyoaLumpedElmore_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaLumpedElmore_assign_doc[] = 
"Class: oaLumpedElmore, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaLumpedElmore_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaLumpedElmore data;
  int convert_status=PyoaLumpedElmore_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaLumpedElmore p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaLumpedElmore_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaLumpedElmore_methodlist[] = {
    {"getElmores",(PyCFunction)oaLumpedElmore_getElmores,METH_VARARGS,oaLumpedElmore_getElmores_doc},
    {"getElmoresIter",(PyCFunction)oaLumpedElmore_getElmoresIter,METH_VARARGS,oaLumpedElmore_getElmoresIter_doc},
    {"getTotalCap",(PyCFunction)oaLumpedElmore_getTotalCap,METH_VARARGS,oaLumpedElmore_getTotalCap_doc},
    {"setTotalCap",(PyCFunction)oaLumpedElmore_setTotalCap,METH_VARARGS,oaLumpedElmore_setTotalCap_doc},
    {"isNull",(PyCFunction)oaLumpedElmore_tp_isNull,METH_VARARGS,oaLumpedElmore_isNull_doc},
    {"assign",(PyCFunction)oaLumpedElmore_tp_assign,METH_VARARGS,oaLumpedElmore_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLumpedElmore_doc[] = 
"Class: oaLumpedElmore\n"
"  The oaLumpedElmore class represents a reduced model for the parasitics seen by a driver of a net, using a total lumped capacitance and a set of Elmore delays to each receiver. The oaElmore class represents the Elmore delays, which are the first moment of the impulse response of the interconnect parasitics from the driver to each receiver.\n"
"  Undo is not supported for oaLumpedElmore objects.\n"
"Constructors:\n"
"  Paramegers: (oaLumpedElmore)\n"
"    Calls: (const oaLumpedElmore&)\n"
"    Signature: oaLumpedElmore||cref-oaLumpedElmore,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaLumpedElmore_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaLumpedElmore",
    sizeof(PyoaLumpedElmoreObject),
    0,
    (destructor)oaLumpedElmore_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaLumpedElmore_tp_compare,	/* tp_compare */
    (reprfunc)oaLumpedElmore_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaLumpedElmore_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaLumpedElmore_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaReducedModel_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaLumpedElmore_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaLumpedElmore_static_create_doc[] = 
"Class: oaLumpedElmore, Function: create\n"
"  Paramegers: (oaDesignObject,oaAnalysisPoint,oaFloat)\n"
"    Calls: oaLumpedElmore* create(oaDesignObject* driver,const oaAnalysisPoint* ap,oaFloat totalCap)\n"
"    Signature: create|ptr-oaLumpedElmore|ptr-oaDesignObject,cptr-oaAnalysisPoint,simple-oaFloat,\n"
"    This function creates an oaLumpedElmore model for the specified driver object and analysis point. The driver can be terminal or instTerm in block or occurrence domain.\n"
"    oacInvalidReducedModelDomain\n"
"    oacInvalidReducedModelObjectType\n"
"    oacInvalidDriverTermType\n"
"    oacParasiticTermMustBeScalar\n"
"    oacParasiticInstTermMustBeScalar\n"
;

static PyObject*
oaLumpedElmore_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDesignObject p1;
    PyParamoaAnalysisPoint p2;
    PyParamoaFloat p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaDesignObject_Convert,&p1,
          &PyoaAnalysisPoint_Convert,&p2,
          &PyoaFloat_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        oaLumpedElmorep result= (oaLumpedElmore::create(p1.Data(),p2.Data(),p3.Data()));
        return PyoaLumpedElmore_FromoaLumpedElmore(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaLumpedElmore_static_find_doc[] = 
"Class: oaLumpedElmore, Function: find\n"
"  Paramegers: (oaDesignObject,oaAnalysisPoint)\n"
"    Calls: oaLumpedElmore* find(const oaDesignObject* driver,const oaAnalysisPoint* ap)\n"
"    Signature: find|ptr-oaLumpedElmore|cptr-oaDesignObject,cptr-oaAnalysisPoint,\n"
"    This function finds the lumpedElmore on the specified driver and analysisPoint. If found it returns the object, otherwise it returns null pointer to the caller.\n"
;

static PyObject*
oaLumpedElmore_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDesignObject p1;
    PyParamoaAnalysisPoint p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDesignObject_Convert,&p1,
          &PyoaAnalysisPoint_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        oaLumpedElmorep result= (oaLumpedElmore::find(p1.Data(),p2.Data()));
        return PyoaLumpedElmore_FromoaLumpedElmore(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaLumpedElmore_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaLumpedElmore_static_create,METH_VARARGS,oaLumpedElmore_static_create_doc},
    {"static_find",(PyCFunction)oaLumpedElmore_static_find,METH_VARARGS,oaLumpedElmore_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaLumpedElmore_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaLumpedElmore_Type)<0) {
      printf("** PyType_Ready failed for: oaLumpedElmore\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaLumpedElmore",
           (PyObject*)(&PyoaLumpedElmore_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaLumpedElmore\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaLumpedElmore_Type.tp_dict;
    for(method=oaLumpedElmore_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaMapFile
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaMapFile_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaMapFile_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaMapFileObject* self = (PyoaMapFileObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value = (oaFSComponent*)  new oaMapFile(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaMapFile, Choices are:\n"
        "    (oaString)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaMapFile_tp_dealloc(PyoaMapFileObject* self)
{
    if (!self->borrow) {
        delete (oaMapFile*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaMapFile_tp_repr(PyObject *ob)
{
    PyParamoaMapFile value;
    int convert_status=PyoaMapFile_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[31];
    sprintf(buffer,"<oaMapFile::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaMapFile_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaMapFile v1;
    PyParamoaMapFile v2;
    int convert_status1=PyoaMapFile_Convert(ob1,&v1);
    int convert_status2=PyoaMapFile_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaMapFile_Convert(PyObject* ob,PyParamoaMapFile* result)
{
    if (ob == NULL) return 1;
    if (PyoaMapFile_Check(ob)) {
        result->SetData( (oaMapFile*) ((PyoaMapFileObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaMapFile Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaMapFile_FromoaMapFile(oaMapFile* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaMapFile_Type.tp_alloc(&PyoaMapFile_Type,0);
        if (bself == NULL) return bself;
        PyoaMapFileObject* self = (PyoaMapFileObject*)bself;
        self->value = (oaFSComponent*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaMapFile_getMappableSize_doc[] = 
"Class: oaMapFile, Function: getMappableSize\n"
"  Paramegers: ()\n"
"    Calls: oaUInt8 getMappableSize() const\n"
"    Signature: getMappableSize|simple-oaUInt8|\n"
"    BrowseData: 1\n"
"    This function returns the size of the portion of the file that is currently mappable. The mappable size is established when the first window is opened. If no windows are currently open, this function returns the current file size.\n"
;

static PyObject*
oaMapFile_getMappableSize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapFile data;
    int convert_status=PyoaMapFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapFileObject* self=(PyoaMapFileObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt8 result= (data.DataCall()->getMappableSize());
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
static char oaMapFile_getSwap_doc[] = 
"Class: oaMapFile, Function: getSwap\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean getSwap() const\n"
"    Signature: getSwap|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether this file requires byte-swapping.\n"
"    true or false\n"
;

static PyObject*
oaMapFile_getSwap(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapFile data;
    int convert_status=PyoaMapFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapFileObject* self=(PyoaMapFileObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->getSwap());
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
static char oaMapFile_isMapped_doc[] = 
"Class: oaMapFile, Function: isMapped\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isMapped() const\n"
"    Signature: isMapped|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if this file is mapped.\n"
"    true or false\n"
;

static PyObject*
oaMapFile_isMapped(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapFile data;
    int convert_status=PyoaMapFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapFileObject* self=(PyoaMapFileObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isMapped());
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
static char oaMapFile_setSize_doc[] = 
"Class: oaMapFile, Function: setSize\n"
"  Paramegers: (oaUInt8)\n"
"    Calls: void setSize(oaUInt8 size)\n"
"    Signature: setSize|void-void|simple-oaUInt8,\n"
"    This function sets the size of this file to the specified value. The file must be open for this function to succeed.\n"
"    size\n"
"    The new size of the file\n"
"    oacFileTruncateFailed\n"
;

static PyObject*
oaMapFile_setSize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapFile data;
    int convert_status=PyoaMapFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapFileObject* self=(PyoaMapFileObject*)ob;

    PyParamoaUInt8 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt8_Convert,&p1)) {
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

// ------------------------------------------------------------------
static char oaMapFile_setSwap_doc[] = 
"Class: oaMapFile, Function: setSwap\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: void setSwap(oaBoolean swapIn)\n"
"    Signature: setSwap|void-void|simple-oaBoolean,\n"
"    This function sets the byte-swapping flag for this map file to indicate it requires byte-swapping.\n"
;

static PyObject*
oaMapFile_setSwap(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapFile data;
    int convert_status=PyoaMapFile_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapFileObject* self=(PyoaMapFileObject*)ob;

    PyParamoaBoolean p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBoolean_Convert,&p1)) {
        data.DataCall()->setSwap(p1.Data());
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

static char oaMapFile_assign_doc[] = 
"Class: oaMapFile, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaMapFile_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaMapFile data;
  int convert_status=PyoaMapFile_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaMapFile p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaMapFile_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaMapFile_methodlist[] = {
    {"getMappableSize",(PyCFunction)oaMapFile_getMappableSize,METH_VARARGS,oaMapFile_getMappableSize_doc},
    {"getSwap",(PyCFunction)oaMapFile_getSwap,METH_VARARGS,oaMapFile_getSwap_doc},
    {"isMapped",(PyCFunction)oaMapFile_isMapped,METH_VARARGS,oaMapFile_isMapped_doc},
    {"setSize",(PyCFunction)oaMapFile_setSize,METH_VARARGS,oaMapFile_setSize_doc},
    {"setSwap",(PyCFunction)oaMapFile_setSwap,METH_VARARGS,oaMapFile_setSwap_doc},
    {"assign",(PyCFunction)oaMapFile_tp_assign,METH_VARARGS,oaMapFile_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaMapFile_doc[] = 
"Class: oaMapFile\n"
"  The oaMapFile class implements the basic file-mapping capability for memory-mapped disk files, including functions for reading and writing the file data. This class has byte-swapping supports for files across machines. This class supports files larger than 32 bits. The API allows you to map any 32-bit window of the file at a time.\n"
"  You cannot map zero-size files. When you create files, the tool checks the mapping size. If the file size is zero, the map is not created.\n"
"  It is the user's responsibility to ensure all writes are aligned on a boundary of the object size to be written. For example, you must write out shorts on two-byte boundaries, ints on four-byte boundaries, and so on. Violating this requirement results in a bus-error.\n"
"  The Win32 and UNIX versions of this class differ due to the differences in file mapping support. Because of how Win32 supports memory mapping, it is not effective to derive this class from the oaFile class.\n"
"Constructors:\n"
"  Paramegers: (oaString)\n"
"    Calls: oaMapFile(const oaString& nameIn)\n"
"    Signature: oaMapFile||cref-oaString,\n"
"    This function is the constructor for the oaMapFile class. This function initializes the members, but does not access the specified file in any way.\n"
"    nameIn\n"
"    The name of the file to initialize\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaMapFile_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaMapFile",
    sizeof(PyoaMapFileObject),
    0,
    (destructor)oaMapFile_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaMapFile_tp_compare,	/* tp_compare */
    (reprfunc)oaMapFile_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaMapFile_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaMapFile_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaFile_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaMapFile_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaMapFile_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaMapFile_Type)<0) {
      printf("** PyType_Ready failed for: oaMapFile\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaMapFile",
           (PyObject*)(&PyoaMapFile_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaMapFile\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaMapFileWindow
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaMapFileWindow_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaMapFileWindow_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaMapFileWindowObject* self = (PyoaMapFileWindowObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaMapFile)
    {
        PyParamoaMapFile p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaMapFile_Convert,&p1)) {
            self->value = (oaMapWindow*)  new oaMapFileWindow(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaMapFileWindow, Choices are:\n"
        "    (oaMapFile)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaMapFileWindow_tp_dealloc(PyoaMapFileWindowObject* self)
{
    if (!self->borrow) {
        delete (oaMapFileWindow*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaMapFileWindow_tp_repr(PyObject *ob)
{
    PyParamoaMapFileWindow value;
    int convert_status=PyoaMapFileWindow_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaMapFileWindow::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaMapFileWindow_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaMapFileWindow v1;
    PyParamoaMapFileWindow v2;
    int convert_status1=PyoaMapFileWindow_Convert(ob1,&v1);
    int convert_status2=PyoaMapFileWindow_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaMapFileWindow_Convert(PyObject* ob,PyParamoaMapFileWindow* result)
{
    if (ob == NULL) return 1;
    if (PyoaMapFileWindow_Check(ob)) {
        result->SetData( (oaMapFileWindow*) ((PyoaMapFileWindowObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaMapFileWindow Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaMapFileWindow_FromoaMapFileWindow(oaMapFileWindow* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaMapFileWindow_Type.tp_alloc(&PyoaMapFileWindow_Type,0);
        if (bself == NULL) return bself;
        PyoaMapFileWindowObject* self = (PyoaMapFileWindowObject*)bself;
        self->value = (oaMapWindow*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaMapFileWindow_extend_doc[] = 
"Class: oaMapFileWindow, Function: extend\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaUInt4 extend(oaUInt4 sizeIn)\n"
"    Signature: extend|simple-oaUInt4|simple-oaUInt4,\n"
"    This function ensures that the size of the memory-mapped window is at least sizeIn , extending the memory-mapped window if necessary without changing the window offset. The new window size that is returned may be somewhat larger than sizeIn due to memory-mapping granularity. In write mode, the file is also extended, if necessary.\n"
"    sizeIn\n"
"    The minimum size of the memory-mapped window\n"
;

static PyObject*
oaMapFileWindow_extend(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapFileWindow data;
    int convert_status=PyoaMapFileWindow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapFileWindowObject* self=(PyoaMapFileWindowObject*)ob;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        oaUInt4 result= (data.DataCall()->extend(p1.Data()));
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
static char oaMapFileWindow_getMapFile_doc[] = 
"Class: oaMapFileWindow, Function: getMapFile\n"
"  Paramegers: ()\n"
"    Calls: oaMapFile& getMapFile()\n"
"    Signature: getMapFile|ref-oaMapFile|\n"
"    BrowseData: 1\n"
"    This function returns the mapFile associated with this mapFileWindow.\n"
;

static PyObject*
oaMapFileWindow_getMapFile(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapFileWindow data;
    int convert_status=PyoaMapFileWindow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapFileWindowObject* self=(PyoaMapFileWindowObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaMapFile* result=&(data.DataCall()->getMapFile());
        return PyoaMapFile_FromoaMapFile(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaMapFileWindow_getSwap_doc[] = 
"Class: oaMapFileWindow, Function: getSwap\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean getSwap() const\n"
"    Signature: getSwap|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating if this file requires byte-swapping.\n"
"    true or false\n"
;

static PyObject*
oaMapFileWindow_getSwap(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapFileWindow data;
    int convert_status=PyoaMapFileWindow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapFileWindowObject* self=(PyoaMapFileWindowObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->getSwap());
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
static char oaMapFileWindow_move_doc[] = 
"Class: oaMapFileWindow, Function: move\n"
"  Paramegers: (oaUInt4,oaUInt8)\n"
"    Calls: oaUInt4 move(oaUInt4 sizeIn,oaUInt8 offsetIn)\n"
"    Signature: move|simple-oaUInt4|simple-oaUInt4,simple-oaUInt8,simple-oaBoolean,\n"
"    This function moves the memory-mapped window from the current offset in the file to offsetIn , changing the size of the window to sizeIn .\n"
"    sizeIn\n"
"    The new size of the memory-mapped window\n"
"    offsetIn\n"
"    The new starting location in the file for this memory-mapped window\n"
"    resize\n"
"  Paramegers: (oaUInt4,oaUInt8,oaBoolean)\n"
"    Calls: oaUInt4 move(oaUInt4 sizeIn,oaUInt8 offsetIn,oaBoolean resize)\n"
"    Signature: move|simple-oaUInt4|simple-oaUInt4,simple-oaUInt8,simple-oaBoolean,\n"
"    This function moves the memory-mapped window from the current offset in the file to offsetIn , changing the size of the window to sizeIn .\n"
"    sizeIn\n"
"    The new size of the memory-mapped window\n"
"    offsetIn\n"
"    The new starting location in the file for this memory-mapped window\n"
"    resize\n"
;

static PyObject*
oaMapFileWindow_move(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapFileWindow data;
    int convert_status=PyoaMapFileWindow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapFileWindowObject* self=(PyoaMapFileWindowObject*)ob;

    // Case: (oaUInt4,oaUInt8)
    {
        PyParamoaUInt4 p1;
        PyParamoaUInt8 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaUInt8_Convert,&p2)) {
            oaUInt4 result= (data.DataCall()->move(p1.Data(),p2.Data()));
            return PyoaUInt4_FromoaUInt4(result);
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaUInt8,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaUInt8 p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaUInt8_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            oaUInt4 result= (data.DataCall()->move(p1.Data(),p2.Data(),p3.Data()));
            return PyoaUInt4_FromoaUInt4(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaMapFileWindow, function: move, Choices are:\n"
        "    (oaUInt4,oaUInt8)\n"
        "    (oaUInt4,oaUInt8,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaMapFileWindow_readSwapCheck_doc[] = 
"Class: oaMapFileWindow, Function: readSwapCheck\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void readSwapCheck(oaUInt4& loc)\n"
"    Signature: readSwapCheck|void-void|ref-oaUInt4,\n"
"    BrowseData: 0,oaUInt4\n"
"    This function reads an integer from this file. This test integer determines if subsequent reads from this file must be done using byte-swapping.\n"
"    loc\n"
"    The location in the file from which to read the integer\n"
;

static PyObject*
oaMapFileWindow_readSwapCheck(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapFileWindow data;
    int convert_status=PyoaMapFileWindow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapFileWindowObject* self=(PyoaMapFileWindowObject*)ob;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->readSwapCheck(p1.Data());
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
static char oaMapFileWindow_reset_doc[] = 
"Class: oaMapFileWindow, Function: reset\n"
"  Paramegers: ()\n"
"    Calls: void reset()\n"
"    Signature: reset|void-void|\n"
"    BrowseData: 0\n"
"    Function reset\n"
;

static PyObject*
oaMapFileWindow_reset(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapFileWindow data;
    int convert_status=PyoaMapFileWindow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapFileWindowObject* self=(PyoaMapFileWindowObject*)ob;

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
static char oaMapFileWindow_setMapFile_doc[] = 
"Class: oaMapFileWindow, Function: setMapFile\n"
"  Paramegers: (oaMapFile)\n"
"    Calls: void setMapFile(oaMapFile& mapFileIn)\n"
"    Signature: setMapFile|void-void|ref-oaMapFile,\n"
"    BrowseData: 0,oaMapFile\n"
"    This function changes the underlying file to use for subsequent mapping.\n"
"    mapFileIn\n"
"    The map file to use\n"
"    oacInvalidSetMapWindowFile\n"
;

static PyObject*
oaMapFileWindow_setMapFile(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapFileWindow data;
    int convert_status=PyoaMapFileWindow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapFileWindowObject* self=(PyoaMapFileWindowObject*)ob;

    PyParamoaMapFile p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaMapFile_Convert,&p1)) {
        data.DataCall()->setMapFile(p1.Data());
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
static char oaMapFileWindow_writeSwapCheck_doc[] = 
"Class: oaMapFileWindow, Function: writeSwapCheck\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void writeSwapCheck(oaUInt4& loc)\n"
"    Signature: writeSwapCheck|void-void|ref-oaUInt4,\n"
"    BrowseData: 0,oaUInt4\n"
"    This function writes an integer to this file. This test integer determines if subsequent reads from this file must be done using byte-swapping.\n"
"    loc\n"
"    The location in the file where to write the integer\n"
;

static PyObject*
oaMapFileWindow_writeSwapCheck(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapFileWindow data;
    int convert_status=PyoaMapFileWindow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapFileWindowObject* self=(PyoaMapFileWindowObject*)ob;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->writeSwapCheck(p1.Data());
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

static char oaMapFileWindow_assign_doc[] = 
"Class: oaMapFileWindow, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaMapFileWindow_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaMapFileWindow data;
  int convert_status=PyoaMapFileWindow_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaMapFileWindow p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaMapFileWindow_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaMapFileWindow_methodlist[] = {
    {"extend",(PyCFunction)oaMapFileWindow_extend,METH_VARARGS,oaMapFileWindow_extend_doc},
    {"getMapFile",(PyCFunction)oaMapFileWindow_getMapFile,METH_VARARGS,oaMapFileWindow_getMapFile_doc},
    {"getSwap",(PyCFunction)oaMapFileWindow_getSwap,METH_VARARGS,oaMapFileWindow_getSwap_doc},
    {"move",(PyCFunction)oaMapFileWindow_move,METH_VARARGS,oaMapFileWindow_move_doc},
    {"readSwapCheck",(PyCFunction)oaMapFileWindow_readSwapCheck,METH_VARARGS,oaMapFileWindow_readSwapCheck_doc},
    {"reset",(PyCFunction)oaMapFileWindow_reset,METH_VARARGS,oaMapFileWindow_reset_doc},
    {"setMapFile",(PyCFunction)oaMapFileWindow_setMapFile,METH_VARARGS,oaMapFileWindow_setMapFile_doc},
    {"writeSwapCheck",(PyCFunction)oaMapFileWindow_writeSwapCheck,METH_VARARGS,oaMapFileWindow_writeSwapCheck_doc},
    {"assign",(PyCFunction)oaMapFileWindow_tp_assign,METH_VARARGS,oaMapFileWindow_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaMapFileWindow_doc[] = 
"Class: oaMapFileWindow\n"
"  The oaMapFileWindow utility class reads data from and writes data to a memory-mapped disk file. The oaMapFileWindow class derives from oaMapWindow , associating the window with an oaMapFile as the backing storage.\n"
"  This class includes byte-swapping support for files moved between big-endian and little-endian computers. This class supports files with sizes larger than 32 bits. As part of this support, the API allows any 32-bit window of the file to map at a time.\n"
"  The usage of oaMapFileWindow is primarily internal to OpenAccess. It is public because pcell evaluators may use it to store private data in a pcell supermaster. See oaPackedData for a discussion. Such callers will get an oaMapFileWindow from oaPcellDataCallback::onPcellRead or oaPcellDataCallback::onPcellWrite. They do not need to call any functions on oaMapFileWindow except the inherited call oaMapWindow::data() .\n"
"Constructors:\n"
"  Paramegers: (oaMapFile)\n"
"    Calls: oaMapFileWindow(oaMapFile& mapFileIn)\n"
"    Signature: oaMapFileWindow||ref-oaMapFile,\n"
"    Constructor oaMapFileWindow\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaMapFileWindow_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaMapFileWindow",
    sizeof(PyoaMapFileWindowObject),
    0,
    (destructor)oaMapFileWindow_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaMapFileWindow_tp_compare,	/* tp_compare */
    (reprfunc)oaMapFileWindow_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaMapFileWindow_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaMapFileWindow_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaMapWindow_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaMapFileWindow_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaMapFileWindow_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaMapFileWindow_Type)<0) {
      printf("** PyType_Ready failed for: oaMapFileWindow\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaMapFileWindow",
           (PyObject*)(&PyoaMapFileWindow_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaMapFileWindow\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaMapWindow
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaMapWindow_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaMapWindow_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaMapWindowObject* self = (PyoaMapWindowObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaMapWindow, Choices are:\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaMapWindow_tp_dealloc(PyoaMapWindowObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaMapWindow_tp_repr(PyObject *ob)
{
    PyParamoaMapWindow value;
    int convert_status=PyoaMapWindow_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[33];
    sprintf(buffer,"<oaMapWindow::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaMapWindow_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaMapWindow v1;
    PyParamoaMapWindow v2;
    int convert_status1=PyoaMapWindow_Convert(ob1,&v1);
    int convert_status2=PyoaMapWindow_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaMapWindow_Convert(PyObject* ob,PyParamoaMapWindow* result)
{
    if (ob == NULL) return 1;
    if (PyoaMapWindow_Check(ob)) {
        result->SetData(  ((PyoaMapWindowObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaMapWindow Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaMapWindow_FromoaMapWindow(oaMapWindow* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaMapWindow_Type.tp_alloc(&PyoaMapWindow_Type,0);
        if (bself == NULL) return bself;
        PyoaMapWindowObject* self = (PyoaMapWindowObject*)bself;
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
// IndexGetMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaMapWindow_index_get_doc[] = 
"Class: oaMapWindow, Function: index_get\n"
;

static PyObject*
oaMapWindow_index_get(PyObject* ob,Pyoa_ssize_t index)
{
  PyoaMapWindowObject* self=(PyoaMapWindowObject*)ob;
  try {
    PyParamoaMapWindow data;
    int convert_status=PyoaMapWindow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapWindowObject* self=(PyoaMapWindowObject*)ob;

    PyParamoaUInt4 p1;
    if (index<0 || index>=data.Data().getSize()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return NULL;
    }
    oaByte* result=&(data.Data()[index]);
    return PyoaByte_FromoaByte(result,1,ob);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static Pyoa_ssize_t
oaMapWindow_index_get_length(PyObject* ob)
{
    PyParamoaMapWindow data;
    int convert_status=PyoaMapWindow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapWindowObject* self=(PyoaMapWindowObject*)ob;

    return data.Data().getSize();
}


// ------------------------------------------------------------------
// IndexSetMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaMapWindow_index_set_doc[] = 
"Class: oaMapWindow, Function: index_set\n"
;

static int
oaMapWindow_index_set(PyObject *ob, Pyoa_ssize_t index, PyObject* value)
{
  try {
    PyParamoaMapWindow data;
    int convert_status=PyoaMapWindow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapWindowObject* self=(PyoaMapWindowObject*)ob;

    PyParamoaUInt4 p1;
    if (index<0 || index>=data.Data().getSize()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return -1;
    }
    PyParamoaByte result;
    if (PyoaByte_Convert(value,&result)==0) return -1;
    data.Data()[index]=result.Data();
    return 0;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return -1;
  }
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaMapWindow_data_doc[] = 
"Class: oaMapWindow, Function: data\n"
"  Paramegers: ()\n"
"    Calls: const oaPackedData& data() const\n"
"    Signature: data|cref-oaPackedData|\n"
"    BrowseData: 1\n"
"    This function returns a reference to the oaPackedData interface that is associated with this mapWindow. Use this function to access the functions on oaPackedData to read and write data from and to this mapWindow.\n"
;

static PyObject*
oaMapWindow_data(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapWindow data;
    int convert_status=PyoaMapWindow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapWindowObject* self=(PyoaMapWindowObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        const oaPackedData& result= (data.DataCall()->data());
        return PyoaPackedData_FromoaPackedData((oaPackedData*)(&result),1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaMapWindow_getLoc_doc[] = 
"Class: oaMapWindow, Function: getLoc\n"
"  Paramegers: (oaUInt8)\n"
"    Calls: oaUInt4 getLoc(oaUInt8 offsetIn) const\n"
"    Signature: getLoc|simple-oaUInt4|simple-oaUInt8,\n"
"    This function returns the location within the window of offsetIn , which must be currently mapped.\n"
;

static PyObject*
oaMapWindow_getLoc(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapWindow data;
    int convert_status=PyoaMapWindow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapWindowObject* self=(PyoaMapWindowObject*)ob;

    PyParamoaUInt8 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt8_Convert,&p1)) {
        oaUInt4 result= (data.DataCall()->getLoc(p1.Data()));
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
static char oaMapWindow_getOffset_doc[] = 
"Class: oaMapWindow, Function: getOffset\n"
"  Paramegers: ()\n"
"    Calls: oaUInt8 getOffset() const\n"
"    Signature: getOffset|simple-oaUInt8|\n"
"    BrowseData: 1\n"
"    This function returns the offset of this mapWindow.\n"
;

static PyObject*
oaMapWindow_getOffset(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapWindow data;
    int convert_status=PyoaMapWindow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapWindowObject* self=(PyoaMapWindowObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt8 result= (data.DataCall()->getOffset());
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
static char oaMapWindow_getSize_doc[] = 
"Class: oaMapWindow, Function: getSize\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getSize() const\n"
"    Signature: getSize|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the size of this mapWindow.\n"
;

static PyObject*
oaMapWindow_getSize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapWindow data;
    int convert_status=PyoaMapWindow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapWindowObject* self=(PyoaMapWindowObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getSize());
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
static char oaMapWindow_isMapped_doc[] = 
"Class: oaMapWindow, Function: isMapped\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isMapped() const\n"
"    Signature: isMapped|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if this mapWindow is mapped.\n"
"  Paramegers: (oaUInt4,oaUInt8,oaUInt4)\n"
"    Calls: oaBoolean isMapped(oaUInt4 sizeIn,oaUInt8 offsetIn,oaUInt4& loc) const\n"
"    Signature: isMapped|simple-oaBoolean|simple-oaUInt4,simple-oaUInt8,ref-oaUInt4,\n"
"    This function returns true if the window is mapped and covers sizeIn bytes starting at offsetIn . The location within the window of offsetIn is returned in loc .\n"
;

static PyObject*
oaMapWindow_isMapped(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMapWindow data;
    int convert_status=PyoaMapWindow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMapWindowObject* self=(PyoaMapWindowObject*)ob;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaBoolean result= (data.DataCall()->isMapped());
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaUInt8,oaUInt4)
    {
        PyParamoaUInt4 p1;
        PyParamoaUInt8 p2;
        PyParamoaUInt4 p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaUInt8_Convert,&p2,
              &PyoaUInt4_Convert,&p3)) {
            oaBoolean result= (data.DataCall()->isMapped(p1.Data(),p2.Data(),p3.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaMapWindow, function: isMapped, Choices are:\n"
        "    ()\n"
        "    (oaUInt4,oaUInt8,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaMapWindow_assign_doc[] = 
"Class: oaMapWindow, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaMapWindow_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaMapWindow data;
  int convert_status=PyoaMapWindow_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaMapWindow p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaMapWindow_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaMapWindow_methodlist[] = {
    {"data",(PyCFunction)oaMapWindow_data,METH_VARARGS,oaMapWindow_data_doc},
    {"getLoc",(PyCFunction)oaMapWindow_getLoc,METH_VARARGS,oaMapWindow_getLoc_doc},
    {"getOffset",(PyCFunction)oaMapWindow_getOffset,METH_VARARGS,oaMapWindow_getOffset_doc},
    {"getSize",(PyCFunction)oaMapWindow_getSize,METH_VARARGS,oaMapWindow_getSize_doc},
    {"isMapped",(PyCFunction)oaMapWindow_isMapped,METH_VARARGS,oaMapWindow_isMapped_doc},
    {"assign",(PyCFunction)oaMapWindow_tp_assign,METH_VARARGS,oaMapWindow_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------

static PySequenceMethods oaMapWindow_as_sequence = {
    (Pyoa_inquiry)oaMapWindow_index_get_length, /* sq_length */
    (Pyoa_binaryfunc)0,		/* sq_concat */
    (Pyoa_intargfunc)0,		/* sq_repeat */
    (Pyoa_intargfunc)oaMapWindow_index_get,	/* sq_item */
    (Pyoa_intintargfunc)0,		/* sq_slice */
    (Pyoa_intobjargproc)oaMapWindow_index_set,	/* sq_ass_item */
};
// ------------------------------------------------------------------
static char oaMapWindow_doc[] = 
"Class: oaMapWindow\n"
"  This utility class is used to read data from and write data to a memory-mapped disk file.\n"
"  The primary usage of oaMapWindow is internal to OpenAccess. It is public because applications that do pcell evaluation can use them to store private data in a pcell supermaster. See oaPackedData for a discussion of this usage. The only function that pcell evaluators need to call on an oaMapWindow is data() . They do not ever construct a class instance.\n"
"Constructors:\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaMapWindow_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaMapWindow",
    sizeof(PyoaMapWindowObject),
    0,
    (destructor)oaMapWindow_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaMapWindow_tp_compare,	/* tp_compare */
    (reprfunc)oaMapWindow_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    &oaMapWindow_as_sequence,	/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaMapWindow_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaMapWindow_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaMapWindow_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaMapWindow_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaMapWindow_Type)<0) {
      printf("** PyType_Ready failed for: oaMapWindow\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaMapWindow",
           (PyObject*)(&PyoaMapWindow_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaMapWindow\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaMarker
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaMarker_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaMarker_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaMarkerObject* self = (PyoaMarkerObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaMarker)
    {
        PyParamoaMarker p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaMarker_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaMarker, Choices are:\n"
        "    (oaMarker)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaMarker_tp_dealloc(PyoaMarkerObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaMarker_tp_repr(PyObject *ob)
{
    PyParamoaMarker value;
    int convert_status=PyoaMarker_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[30];
    sprintf(buffer,"<oaMarker::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaMarker_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaMarker v1;
    PyParamoaMarker v2;
    int convert_status1=PyoaMarker_Convert(ob1,&v1);
    int convert_status2=PyoaMarker_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaMarker_Convert(PyObject* ob,PyParamoaMarker* result)
{
    if (ob == NULL) return 1;
    if (PyoaMarker_Check(ob)) {
        result->SetData( (oaMarker**) ((PyoaMarkerObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaMarker Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaMarker_FromoaMarker(oaMarker** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaMarker* data=*value;
        PyObject* bself = PyoaMarker_Type.tp_alloc(&PyoaMarker_Type,0);
        if (bself == NULL) return bself;
        PyoaMarkerObject* self = (PyoaMarkerObject*)bself;
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
PyObject* PyoaMarker_FromoaMarker(oaMarker* data)
{
    if (data) {
       PyObject* bself = PyoaMarker_Type.tp_alloc(&PyoaMarker_Type,0);
       if (bself == NULL) return bself;
       PyoaMarkerObject* self = (PyoaMarkerObject*)bself;
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
static char oaMarker_addObject_doc[] = 
"Class: oaMarker, Function: addObject\n"
"  Paramegers: (oaBlockObject)\n"
"    Calls: void addObject(oaBlockObject* obj)\n"
"    Signature: addObject|void-void|ptr-oaBlockObject,\n"
"    This function adds the specified object to the list of objects associated with the marker. An oacObjectAlreadyOnMarker exception is thrown if the object already exists on the marker.\n"
"    oacInvalidMarkerMemType\n"
"    oacObjMarkerNotInSameBlock\n"
"    oacObjectAlreadyOnMarker\n"
;

static PyObject*
oaMarker_addObject(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBlockObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBlockObject_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->addObject(p1.Data());
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
static char oaMarker_getDeleteWhen_doc[] = 
"Class: oaMarker, Function: getDeleteWhen\n"
"  Paramegers: ()\n"
"    Calls: oaMarkerDeleteWhen getDeleteWhen() const\n"
"    Signature: getDeleteWhen|simple-oaMarkerDeleteWhen|\n"
"    BrowseData: 1\n"
"    This function returns the deleteWhen attribute of this marker.\n"
;

static PyObject*
oaMarker_getDeleteWhen(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaMarkerDeleteWhen* result= new oaMarkerDeleteWhen(data.DataCall()->getDeleteWhen());
        return PyoaMarkerDeleteWhen_FromoaMarkerDeleteWhen(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaMarker_getMsg_doc[] = 
"Class: oaMarker, Function: getMsg\n"
"  Paramegers: (oaString)\n"
"    Calls: void getMsg(oaString& msg) const\n"
"    Signature: getMsg|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function gets the message string associated with this marker.\n"
;

static PyObject*
oaMarker_getMsg(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getMsg(p1.Data());
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
static char oaMarker_getObjects_doc[] = 
"Class: oaMarker, Function: getObjects\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaBlockObject_oaMarker getObjects() const\n"
"    Signature: getObjects|simple-oaCollection_oaBlockObject_oaMarker|\n"
"    BrowseData: 1\n"
"    This function returns the collection of objects associated with this marker.\n"
;

static PyObject*
oaMarker_getObjects(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaBlockObject_oaMarker* result= new oaCollection_oaBlockObject_oaMarker(data.DataCall()->getObjects());
        return PyoaCollection_oaBlockObject_oaMarker_FromoaCollection_oaBlockObject_oaMarker(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaMarker_getObjectsIter_doc[] = 
"Class: oaMarker, Function: getObjectsIter\n"
"  Paramegers: ()\n"
"    Calls: oaBlockObjectIter getObjectsIter() const\n"
"    Signature: getObjectsIter|simple-oaBlockObjectIter|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of objects associated with this marker.\n"
;

static PyObject*
oaMarker_getObjectsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBlockObjectIter* result= new oaBlockObjectIter(data.DataCall()->getObjects());
        return PyoaBlockObjectIter_FromoaBlockObjectIter(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaMarker_getPoints_doc[] = 
"Class: oaMarker, Function: getPoints\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void getPoints(oaPointArray& points) const\n"
"    Signature: getPoints|void-void|ref-oaPointArray,\n"
"    BrowseData: 0,oaPointArray\n"
"    This function fills out points with the pointArray of this marker.\n"
;

static PyObject*
oaMarker_getPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPointArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPointArray_Convert,&p1)) {
        data.DataCall()->getPoints(p1.Data());
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
static char oaMarker_getSeverity_doc[] = 
"Class: oaMarker, Function: getSeverity\n"
"  Paramegers: ()\n"
"    Calls: oaMarkerSeverity getSeverity() const\n"
"    Signature: getSeverity|simple-oaMarkerSeverity|\n"
"    BrowseData: 1\n"
"    This function returns the severity attribute associated with this marker.\n"
;

static PyObject*
oaMarker_getSeverity(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaMarkerSeverity* result= new oaMarkerSeverity(data.DataCall()->getSeverity());
        return PyoaMarkerSeverity_FromoaMarkerSeverity(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaMarker_getShortMsg_doc[] = 
"Class: oaMarker, Function: getShortMsg\n"
"  Paramegers: (oaString)\n"
"    Calls: void getShortMsg(oaString& shortMsg) const\n"
"    Signature: getShortMsg|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function gets the short message string associated with this marker.\n"
;

static PyObject*
oaMarker_getShortMsg(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getShortMsg(p1.Data());
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
static char oaMarker_getTool_doc[] = 
"Class: oaMarker, Function: getTool\n"
"  Paramegers: (oaString)\n"
"    Calls: void getTool(oaString& tool) const\n"
"    Signature: getTool|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function gets the tool string associated with this marker.\n"
;

static PyObject*
oaMarker_getTool(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getTool(p1.Data());
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
static char oaMarker_isClosed_doc[] = 
"Class: oaMarker, Function: isClosed\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isClosed() const\n"
"    Signature: isClosed|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean that indicates whether the pointArray associated with this marker is closed.\n"
;

static PyObject*
oaMarker_isClosed(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isClosed());
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
static char oaMarker_isVisible_doc[] = 
"Class: oaMarker, Function: isVisible\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isVisible() const\n"
"    Signature: isVisible|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean that indicates if this marker is visible.\n"
;

static PyObject*
oaMarker_isVisible(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isVisible());
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
static char oaMarker_removeObject_doc[] = 
"Class: oaMarker, Function: removeObject\n"
"  Paramegers: (oaBlockObject)\n"
"    Calls: void removeObject(oaBlockObject* obj)\n"
"    Signature: removeObject|void-void|ptr-oaBlockObject,\n"
"    This function removes the specified object from the list of objects associated with this marker. This function does nothing if the object is not associated with this marker.\n"
;

static PyObject*
oaMarker_removeObject(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBlockObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBlockObject_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->removeObject(p1.Data());
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
static char oaMarker_setDeleteWhen_doc[] = 
"Class: oaMarker, Function: setDeleteWhen\n"
"  Paramegers: (oaMarkerDeleteWhen)\n"
"    Calls: void setDeleteWhen(oaMarkerDeleteWhen deleteWhen)\n"
"    Signature: setDeleteWhen|void-void|simple-oaMarkerDeleteWhen,\n"
"    This function changes the deleteWhen attribute of this marker to the specified deleteWhen value.\n"
;

static PyObject*
oaMarker_setDeleteWhen(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaMarkerDeleteWhen p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaMarkerDeleteWhen_Convert,&p1)) {
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
static char oaMarker_setIsClosed_doc[] = 
"Class: oaMarker, Function: setIsClosed\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: void setIsClosed(oaBoolean val)\n"
"    Signature: setIsClosed|void-void|simple-oaBoolean,\n"
"    This function is used to indicate whether the pointArray associated with this marker is closed or not.\n"
;

static PyObject*
oaMarker_setIsClosed(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBoolean p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBoolean_Convert,&p1)) {
        data.DataCall()->setIsClosed(p1.Data());
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
static char oaMarker_setIsVisible_doc[] = 
"Class: oaMarker, Function: setIsVisible\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: void setIsVisible(oaBoolean val)\n"
"    Signature: setIsVisible|void-void|simple-oaBoolean,\n"
"    This function is used to indicate whether or not this marker is visible.\n"
;

static PyObject*
oaMarker_setIsVisible(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBoolean p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBoolean_Convert,&p1)) {
        data.DataCall()->setIsVisible(p1.Data());
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
static char oaMarker_setMsg_doc[] = 
"Class: oaMarker, Function: setMsg\n"
"  Paramegers: (oaString)\n"
"    Calls: void setMsg(const oaString& msg)\n"
"    Signature: setMsg|void-void|cref-oaString,\n"
"    This function sets the message string associated with this marker.\n"
;

static PyObject*
oaMarker_setMsg(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->setMsg(p1.Data());
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
static char oaMarker_setPoints_doc[] = 
"Class: oaMarker, Function: setPoints\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void setPoints(const oaPointArray& points)\n"
"    Signature: setPoints|void-void|cref-oaPointArray,\n"
"    This function sets the pointArray of this marker to the value specified.\n"
;

static PyObject*
oaMarker_setPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
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
static char oaMarker_setSeverity_doc[] = 
"Class: oaMarker, Function: setSeverity\n"
"  Paramegers: (oaMarkerSeverity)\n"
"    Calls: void setSeverity(oaMarkerSeverity severity)\n"
"    Signature: setSeverity|void-void|simple-oaMarkerSeverity,\n"
"    This function sets the severity attribute of this marker.\n"
;

static PyObject*
oaMarker_setSeverity(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaMarkerSeverity p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaMarkerSeverity_Convert,&p1)) {
        data.DataCall()->setSeverity(p1.Data());
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
static char oaMarker_setShortMsg_doc[] = 
"Class: oaMarker, Function: setShortMsg\n"
"  Paramegers: (oaString)\n"
"    Calls: void setShortMsg(const oaString& shortMsg)\n"
"    Signature: setShortMsg|void-void|cref-oaString,\n"
"    This function sets the short message string associated with this marker.\n"
;

static PyObject*
oaMarker_setShortMsg(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->setShortMsg(p1.Data());
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
static char oaMarker_setTool_doc[] = 
"Class: oaMarker, Function: setTool\n"
"  Paramegers: (oaString)\n"
"    Calls: void setTool(const oaString& tool)\n"
"    Signature: setTool|void-void|cref-oaString,\n"
"    This function sets the tool string associated with this marker.\n"
;

static PyObject*
oaMarker_setTool(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->setTool(p1.Data());
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
static char oaMarker_transform_doc[] = 
"Class: oaMarker, Function: transform\n"
"  Paramegers: (oaDouble,oaDouble)\n"
"    Calls: void transform(oaDouble scale,oaDouble angle)\n"
"    Signature: transform|void-void|simple-oaDouble,simple-oaDouble,\n"
"    This function transforms this marker by the specified scale factor and rotation angle .\n"
;

static PyObject*
oaMarker_transform(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerObject* self=(PyoaMarkerObject*)ob;
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
static char oaMarker_isNull_doc[] =
"Class: oaMarker, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaMarker_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaMarker data;
    int convert_status=PyoaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaMarker_assign_doc[] = 
"Class: oaMarker, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaMarker_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaMarker data;
  int convert_status=PyoaMarker_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaMarker p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaMarker_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaMarker_methodlist[] = {
    {"addObject",(PyCFunction)oaMarker_addObject,METH_VARARGS,oaMarker_addObject_doc},
    {"getDeleteWhen",(PyCFunction)oaMarker_getDeleteWhen,METH_VARARGS,oaMarker_getDeleteWhen_doc},
    {"getMsg",(PyCFunction)oaMarker_getMsg,METH_VARARGS,oaMarker_getMsg_doc},
    {"getObjects",(PyCFunction)oaMarker_getObjects,METH_VARARGS,oaMarker_getObjects_doc},
    {"getObjectsIter",(PyCFunction)oaMarker_getObjectsIter,METH_VARARGS,oaMarker_getObjectsIter_doc},
    {"getPoints",(PyCFunction)oaMarker_getPoints,METH_VARARGS,oaMarker_getPoints_doc},
    {"getSeverity",(PyCFunction)oaMarker_getSeverity,METH_VARARGS,oaMarker_getSeverity_doc},
    {"getShortMsg",(PyCFunction)oaMarker_getShortMsg,METH_VARARGS,oaMarker_getShortMsg_doc},
    {"getTool",(PyCFunction)oaMarker_getTool,METH_VARARGS,oaMarker_getTool_doc},
    {"isClosed",(PyCFunction)oaMarker_isClosed,METH_VARARGS,oaMarker_isClosed_doc},
    {"isVisible",(PyCFunction)oaMarker_isVisible,METH_VARARGS,oaMarker_isVisible_doc},
    {"removeObject",(PyCFunction)oaMarker_removeObject,METH_VARARGS,oaMarker_removeObject_doc},
    {"setDeleteWhen",(PyCFunction)oaMarker_setDeleteWhen,METH_VARARGS,oaMarker_setDeleteWhen_doc},
    {"setIsClosed",(PyCFunction)oaMarker_setIsClosed,METH_VARARGS,oaMarker_setIsClosed_doc},
    {"setIsVisible",(PyCFunction)oaMarker_setIsVisible,METH_VARARGS,oaMarker_setIsVisible_doc},
    {"setMsg",(PyCFunction)oaMarker_setMsg,METH_VARARGS,oaMarker_setMsg_doc},
    {"setPoints",(PyCFunction)oaMarker_setPoints,METH_VARARGS,oaMarker_setPoints_doc},
    {"setSeverity",(PyCFunction)oaMarker_setSeverity,METH_VARARGS,oaMarker_setSeverity_doc},
    {"setShortMsg",(PyCFunction)oaMarker_setShortMsg,METH_VARARGS,oaMarker_setShortMsg_doc},
    {"setTool",(PyCFunction)oaMarker_setTool,METH_VARARGS,oaMarker_setTool_doc},
    {"transform",(PyCFunction)oaMarker_transform,METH_VARARGS,oaMarker_transform_doc},
    {"isNull",(PyCFunction)oaMarker_tp_isNull,METH_VARARGS,oaMarker_isNull_doc},
    {"assign",(PyCFunction)oaMarker_tp_assign,METH_VARARGS,oaMarker_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaMarker_doc[] = 
"Class: oaMarker\n"
"  The oaMarker class implements a marker object. The intent of marker objects is to support the ability to indicate design violations and the objects that are causing the violation. A marker allows you to\n"
"  Define an array of points to indicate the area or location of the violation\n"
"  Assign a message string that describes the violation\n"
"  Assign a second string that can be used as a tag for the violation\n"
"  Assign the name of the tool reporting the violation\n"
"  Assign a severity value for the violation\n"
"  Define whether the marker is visible or not for rendering purposes\n"
"  Associate zero or more objects that caused the violation with the marker\n"
"  Define the circumstances under which the marker is automatically deleted; this is designated by the oaMarkerDeleteWhen enumerated type\n"
"  The oaMarker class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaMarker)\n"
"    Calls: (const oaMarker&)\n"
"    Signature: oaMarker||cref-oaMarker,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaMarker_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaMarker",
    sizeof(PyoaMarkerObject),
    0,
    (destructor)oaMarker_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaMarker_tp_compare,	/* tp_compare */
    (reprfunc)oaMarker_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaMarker_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaMarker_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaFig_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaMarker_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaMarker_static_create_doc[] = 
"Class: oaMarker, Function: create\n"
"  Paramegers: (oaBlock,oaPointArray,oaString,oaString,oaString,oaBoolean,oaBoolean,oaMarkerSeverity)\n"
"    Calls: oaMarker* create(oaBlock* block,const oaPointArray& points,const oaString& msg,const oaString& shortMsg,const oaString& tool,oaBoolean isVisible,oaBoolean isClosed,oaMarkerSeverity severity)\n"
"    Signature: create|ptr-oaMarker|ptr-oaBlock,cref-oaPointArray,cref-oaString,cref-oaString,cref-oaString,simple-oaBoolean,simple-oaBoolean,simple-oaMarkerSeverity,simple-oaMarkerDeleteWhen,\n"
"    This function creates a new marker in the specified block with the given attributes. There is no check if a marker already exists with the specified attributes.\n"
"  Paramegers: (oaBlock,oaPointArray,oaString,oaString,oaString,oaBoolean,oaBoolean,oaMarkerSeverity,oaMarkerDeleteWhen)\n"
"    Calls: oaMarker* create(oaBlock* block,const oaPointArray& points,const oaString& msg,const oaString& shortMsg,const oaString& tool,oaBoolean isVisible,oaBoolean isClosed,oaMarkerSeverity severity,oaMarkerDeleteWhen deleteWhen)\n"
"    Signature: create|ptr-oaMarker|ptr-oaBlock,cref-oaPointArray,cref-oaString,cref-oaString,cref-oaString,simple-oaBoolean,simple-oaBoolean,simple-oaMarkerSeverity,simple-oaMarkerDeleteWhen,\n"
"    This function creates a new marker in the specified block with the given attributes. There is no check if a marker already exists with the specified attributes.\n"
;

static PyObject*
oaMarker_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaBlock,oaPointArray,oaString,oaString,oaString,oaBoolean,oaBoolean,oaMarkerSeverity)
    {
        PyParamoaBlock p1;
        PyParamoaPointArray p2;
        PyParamoaString p3;
        PyParamoaString p4;
        PyParamoaString p5;
        PyParamoaBoolean p6;
        PyParamoaBoolean p7;
        PyParamoaMarkerSeverity p8;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaPointArray_Convert,&p2,
              &PyoaString_Convert,&p3,
              &PyoaString_Convert,&p4,
              &PyoaString_Convert,&p5,
              &PyoaBoolean_Convert,&p6,
              &PyoaBoolean_Convert,&p7,
              &PyoaMarkerSeverity_Convert,&p8)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaMarkerp result= (oaMarker::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data()));
            return PyoaMarker_FromoaMarker(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaPointArray,oaString,oaString,oaString,oaBoolean,oaBoolean,oaMarkerSeverity,oaMarkerDeleteWhen)
    {
        PyParamoaBlock p1;
        PyParamoaPointArray p2;
        PyParamoaString p3;
        PyParamoaString p4;
        PyParamoaString p5;
        PyParamoaBoolean p6;
        PyParamoaBoolean p7;
        PyParamoaMarkerSeverity p8;
        PyParamoaMarkerDeleteWhen p9;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaPointArray_Convert,&p2,
              &PyoaString_Convert,&p3,
              &PyoaString_Convert,&p4,
              &PyoaString_Convert,&p5,
              &PyoaBoolean_Convert,&p6,
              &PyoaBoolean_Convert,&p7,
              &PyoaMarkerSeverity_Convert,&p8,
              &PyoaMarkerDeleteWhen_Convert,&p9)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaMarkerp result= (oaMarker::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data()));
            return PyoaMarker_FromoaMarker(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaMarker, function: create, Choices are:\n"
        "    (oaBlock,oaPointArray,oaString,oaString,oaString,oaBoolean,oaBoolean,oaMarkerSeverity)\n"
        "    (oaBlock,oaPointArray,oaString,oaString,oaString,oaBoolean,oaBoolean,oaMarkerSeverity,oaMarkerDeleteWhen)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaMarker_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaMarker_static_create,METH_VARARGS,oaMarker_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaMarker_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaMarker_Type)<0) {
      printf("** PyType_Ready failed for: oaMarker\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaMarker",
           (PyObject*)(&PyoaMarker_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaMarker\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaMarker_Type.tp_dict;
    for(method=oaMarker_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaMarkerDeleteWhen
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaMarkerDeleteWhen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaMarkerDeleteWhen_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaMarkerDeleteWhenObject* self = (PyoaMarkerDeleteWhenObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaMarkerDeleteWhenEnum)
    {
        PyParamoaMarkerDeleteWhenEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaMarkerDeleteWhenEnum_Convert,&p1)) {
            self->value =  new oaMarkerDeleteWhen(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaMarkerDeleteWhen(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaMarkerDeleteWhen)
    {
        PyParamoaMarkerDeleteWhen p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaMarkerDeleteWhen_Convert,&p1)) {
            self->value= new oaMarkerDeleteWhen(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaMarkerDeleteWhen, Choices are:\n"
        "    (oaMarkerDeleteWhenEnum)\n"
        "    (oaString)\n"
        "    (oaMarkerDeleteWhen)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaMarkerDeleteWhen_tp_dealloc(PyoaMarkerDeleteWhenObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaMarkerDeleteWhen_tp_repr(PyObject *ob)
{
    PyParamoaMarkerDeleteWhen value;
    int convert_status=PyoaMarkerDeleteWhen_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[40];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaMarkerDeleteWhen::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaMarkerDeleteWhen_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaMarkerDeleteWhen v1;
    PyParamoaMarkerDeleteWhen v2;
    int convert_status1=PyoaMarkerDeleteWhen_Convert(ob1,&v1);
    int convert_status2=PyoaMarkerDeleteWhen_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaMarkerDeleteWhen_Convert(PyObject* ob,PyParamoaMarkerDeleteWhen* result)
{
    if (ob == NULL) return 1;
    if (PyoaMarkerDeleteWhen_Check(ob)) {
        result->SetData(  ((PyoaMarkerDeleteWhenObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaMarkerDeleteWhen Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaMarkerDeleteWhen_FromoaMarkerDeleteWhen(oaMarkerDeleteWhen* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaMarkerDeleteWhen_Type.tp_alloc(&PyoaMarkerDeleteWhen_Type,0);
        if (bself == NULL) return bself;
        PyoaMarkerDeleteWhenObject* self = (PyoaMarkerDeleteWhenObject*)bself;
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
static char oaMarkerDeleteWhen_getName_doc[] = 
"Class: oaMarkerDeleteWhen, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaMarkerDeleteWhenEnum object.\n"
;

static PyObject*
oaMarkerDeleteWhen_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarkerDeleteWhen data;
    int convert_status=PyoaMarkerDeleteWhen_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerDeleteWhenObject* self=(PyoaMarkerDeleteWhenObject*)ob;

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
static char oaMarkerDeleteWhen_oaMarkerDeleteWhenEnum_doc[] = 
"Class: oaMarkerDeleteWhen, Function: oaMarkerDeleteWhenEnum\n"
"  Paramegers: ()\n"
"    Calls: oaMarkerDeleteWhenEnum oaMarkerDeleteWhenEnum() const\n"
"    Signature: operator oaMarkerDeleteWhenEnum|simple-oaMarkerDeleteWhenEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaMarkerDeleteWhen object into the corresponding #oaMarkerDeleteWhenEnum value.\n"
;

static PyObject*
oaMarkerDeleteWhen_oaMarkerDeleteWhenEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarkerDeleteWhen data;
    int convert_status=PyoaMarkerDeleteWhen_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerDeleteWhenObject* self=(PyoaMarkerDeleteWhenObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaMarkerDeleteWhenEnum result= (data.DataCall()->operator oaMarkerDeleteWhenEnum());
        return PyoaMarkerDeleteWhenEnum_FromoaMarkerDeleteWhenEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaMarkerDeleteWhen_assign_doc[] = 
"Class: oaMarkerDeleteWhen, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaMarkerDeleteWhen_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaMarkerDeleteWhen data;
  int convert_status=PyoaMarkerDeleteWhen_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaMarkerDeleteWhen p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaMarkerDeleteWhen_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaMarkerDeleteWhen_methodlist[] = {
    {"getName",(PyCFunction)oaMarkerDeleteWhen_getName,METH_VARARGS,oaMarkerDeleteWhen_getName_doc},
    {"oaMarkerDeleteWhenEnum",(PyCFunction)oaMarkerDeleteWhen_oaMarkerDeleteWhenEnum,METH_VARARGS,oaMarkerDeleteWhen_oaMarkerDeleteWhenEnum_doc},
    {"assign",(PyCFunction)oaMarkerDeleteWhen_tp_assign,METH_VARARGS,oaMarkerDeleteWhen_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaMarkerDeleteWhen_doc[] = 
"Class: oaMarkerDeleteWhen\n"
"  The oaMarkerDeleteWhen class is an enum wrapper class that defines if and when OpenAccess automatically deletes oaMarker objects. Applications choose one of the values below for each marker they create. When a marker is deleted, all objects associated with the marker are updated accordingly. When an object is deleted, the markers associated with it are checked to see if they should be destroyed, based on the value of its deleteWhen attribute.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaMarkerDeleteWhenEnum\n"
"Constructors:\n"
"  Paramegers: (oaMarkerDeleteWhenEnum)\n"
"    Calls: oaMarkerDeleteWhen(oaMarkerDeleteWhenEnum valueIn)\n"
"    Signature: oaMarkerDeleteWhen||simple-oaMarkerDeleteWhenEnum,\n"
"    This function constructs an instance of an oaMarkerDeleteWhen class using the specified #oaMarkerDeleteWhenEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaMarkerDeleteWhen(const oaString& name)\n"
"    Signature: oaMarkerDeleteWhen||cref-oaString,\n"
"    This function constructs an instance of an oaMarkerDeleteWhen class using the #oaMarkerDeleteWhenEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaMarkerDeleteWhenEnum.\n"
"    oacInvalidMarkerDeleteWhenTypeName\n"
"  Paramegers: (oaMarkerDeleteWhen)\n"
"    Calls: (const oaMarkerDeleteWhen&)\n"
"    Signature: oaMarkerDeleteWhen||cref-oaMarkerDeleteWhen,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaMarkerDeleteWhen_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaMarkerDeleteWhen",
    sizeof(PyoaMarkerDeleteWhenObject),
    0,
    (destructor)oaMarkerDeleteWhen_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaMarkerDeleteWhen_tp_compare,	/* tp_compare */
    (reprfunc)oaMarkerDeleteWhen_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaMarkerDeleteWhen_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaMarkerDeleteWhen_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaMarkerDeleteWhen_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaMarkerDeleteWhen_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaMarkerDeleteWhen_Type)<0) {
      printf("** PyType_Ready failed for: oaMarkerDeleteWhen\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaMarkerDeleteWhen",
           (PyObject*)(&PyoaMarkerDeleteWhen_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaMarkerDeleteWhen\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaMarkerDeleteWhenEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaMarkerDeleteWhenEnum_Convert(PyObject* ob,PyParamoaMarkerDeleteWhenEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacDeleteOnUnknown")==0) { result->SetData(oacDeleteOnUnknown); return 1;}
        if (strcasecmp(str,"oacDeleteOnNever")==0) { result->SetData(oacDeleteOnNever); return 1;}
        if (strcasecmp(str,"oacDeleteOnFirst")==0) { result->SetData(oacDeleteOnFirst); return 1;}
        if (strcasecmp(str,"oacDeleteOnLast")==0) { result->SetData(oacDeleteOnLast); return 1;}
        if (strcasecmp(str,"oacDeleteOnModify")==0) { result->SetData(oacDeleteOnModify); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaMarkerDeleteWhenEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaMarkerDeleteWhenEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaMarkerDeleteWhenEnum_FromoaMarkerDeleteWhenEnum(oaMarkerDeleteWhenEnum ob)
{
    if (ob==oacDeleteOnUnknown) return PyString_FromString("oacDeleteOnUnknown");
    if (ob==oacDeleteOnNever) return PyString_FromString("oacDeleteOnNever");
    if (ob==oacDeleteOnFirst) return PyString_FromString("oacDeleteOnFirst");
    if (ob==oacDeleteOnLast) return PyString_FromString("oacDeleteOnLast");
    if (ob==oacDeleteOnModify) return PyString_FromString("oacDeleteOnModify");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaMarkerDeleteWhenEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaMarkerDeleteWhenEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaMarkerDeleteWhenEnum_FromoaMarkerDeleteWhenEnum(oaMarkerDeleteWhenEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaMarkerDeleteWhenEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaMarkerDeleteWhenEnum_doc[] =
"Type convert function for enum: oaMarkerDeleteWhenEnum";
                               
static PyMethodDef PyoaMarkerDeleteWhenEnum_method =
  {"oaMarkerDeleteWhenEnum",(PyCFunction)PyoaMarkerDeleteWhenEnum_TypeFunction,METH_VARARGS,oaMarkerDeleteWhenEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaMarkerDeleteWhenEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacDeleteOnUnknown");
    PyDict_SetItemString(mod_dict,"oacDeleteOnUnknown",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDeleteOnNever");
    PyDict_SetItemString(mod_dict,"oacDeleteOnNever",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDeleteOnFirst");
    PyDict_SetItemString(mod_dict,"oacDeleteOnFirst",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDeleteOnLast");
    PyDict_SetItemString(mod_dict,"oacDeleteOnLast",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDeleteOnModify");
    PyDict_SetItemString(mod_dict,"oacDeleteOnModify",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaMarkerDeleteWhenEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaMarkerDeleteWhenEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaMarkerDeleteWhenEnum\n");
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
// Wrapper Implementation for Class: oaMarkerModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaMarkerModTypeEnum_Convert(PyObject* ob,PyParamoaMarkerModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetPointsMarkerModType")==0) { result->SetData(oacSetPointsMarkerModType); return 1;}
        if (strcasecmp(str,"oacSetVisibleMarkerModType")==0) { result->SetData(oacSetVisibleMarkerModType); return 1;}
        if (strcasecmp(str,"oacAddObjectMarkerModType")==0) { result->SetData(oacAddObjectMarkerModType); return 1;}
        if (strcasecmp(str,"oacSetSeverityMarkerModType")==0) { result->SetData(oacSetSeverityMarkerModType); return 1;}
        if (strcasecmp(str,"oacSetMsgMarkerModType")==0) { result->SetData(oacSetMsgMarkerModType); return 1;}
        if (strcasecmp(str,"oacSetShortMsgMarkerModType")==0) { result->SetData(oacSetShortMsgMarkerModType); return 1;}
        if (strcasecmp(str,"oacSetToolMarkerModType")==0) { result->SetData(oacSetToolMarkerModType); return 1;}
        if (strcasecmp(str,"oacSetDeleteWhenMarkerModType")==0) { result->SetData(oacSetDeleteWhenMarkerModType); return 1;}
        if (strcasecmp(str,"oacSetClosedMarkerModType")==0) { result->SetData(oacSetClosedMarkerModType); return 1;}
        if (strcasecmp(str,"oacRemoveObjectMarkerModType")==0) { result->SetData(oacRemoveObjectMarkerModType); return 1;}
        if (strcasecmp(str,"oacAddToFigGroupMarkerModType")==0) { result->SetData(oacAddToFigGroupMarkerModType); return 1;}
        if (strcasecmp(str,"oacRemoveFromFigGroupMarkerModType")==0) { result->SetData(oacRemoveFromFigGroupMarkerModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaMarkerModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaMarkerModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaMarkerModTypeEnum_FromoaMarkerModTypeEnum(oaMarkerModTypeEnum ob)
{
    if (ob==oacSetPointsMarkerModType) return PyString_FromString("oacSetPointsMarkerModType");
    if (ob==oacSetVisibleMarkerModType) return PyString_FromString("oacSetVisibleMarkerModType");
    if (ob==oacAddObjectMarkerModType) return PyString_FromString("oacAddObjectMarkerModType");
    if (ob==oacSetSeverityMarkerModType) return PyString_FromString("oacSetSeverityMarkerModType");
    if (ob==oacSetMsgMarkerModType) return PyString_FromString("oacSetMsgMarkerModType");
    if (ob==oacSetShortMsgMarkerModType) return PyString_FromString("oacSetShortMsgMarkerModType");
    if (ob==oacSetToolMarkerModType) return PyString_FromString("oacSetToolMarkerModType");
    if (ob==oacSetDeleteWhenMarkerModType) return PyString_FromString("oacSetDeleteWhenMarkerModType");
    if (ob==oacSetClosedMarkerModType) return PyString_FromString("oacSetClosedMarkerModType");
    if (ob==oacRemoveObjectMarkerModType) return PyString_FromString("oacRemoveObjectMarkerModType");
    if (ob==oacAddToFigGroupMarkerModType) return PyString_FromString("oacAddToFigGroupMarkerModType");
    if (ob==oacRemoveFromFigGroupMarkerModType) return PyString_FromString("oacRemoveFromFigGroupMarkerModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaMarkerModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaMarkerModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaMarkerModTypeEnum_FromoaMarkerModTypeEnum(oaMarkerModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaMarkerModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaMarkerModTypeEnum_doc[] =
"Type convert function for enum: oaMarkerModTypeEnum";
                               
static PyMethodDef PyoaMarkerModTypeEnum_method =
  {"oaMarkerModTypeEnum",(PyCFunction)PyoaMarkerModTypeEnum_TypeFunction,METH_VARARGS,oaMarkerModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaMarkerModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetPointsMarkerModType");
    PyDict_SetItemString(mod_dict,"oacSetPointsMarkerModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetVisibleMarkerModType");
    PyDict_SetItemString(mod_dict,"oacSetVisibleMarkerModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAddObjectMarkerModType");
    PyDict_SetItemString(mod_dict,"oacAddObjectMarkerModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetSeverityMarkerModType");
    PyDict_SetItemString(mod_dict,"oacSetSeverityMarkerModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetMsgMarkerModType");
    PyDict_SetItemString(mod_dict,"oacSetMsgMarkerModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetShortMsgMarkerModType");
    PyDict_SetItemString(mod_dict,"oacSetShortMsgMarkerModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetToolMarkerModType");
    PyDict_SetItemString(mod_dict,"oacSetToolMarkerModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetDeleteWhenMarkerModType");
    PyDict_SetItemString(mod_dict,"oacSetDeleteWhenMarkerModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetClosedMarkerModType");
    PyDict_SetItemString(mod_dict,"oacSetClosedMarkerModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRemoveObjectMarkerModType");
    PyDict_SetItemString(mod_dict,"oacRemoveObjectMarkerModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAddToFigGroupMarkerModType");
    PyDict_SetItemString(mod_dict,"oacAddToFigGroupMarkerModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRemoveFromFigGroupMarkerModType");
    PyDict_SetItemString(mod_dict,"oacRemoveFromFigGroupMarkerModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaMarkerModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaMarkerModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaMarkerModTypeEnum\n");
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
// Wrapper Implementation for Class: oaMarkerQuery
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaMarkerQuery_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaMarkerQuery_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaMarkerQueryObject* self = (PyoaMarkerQueryObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    if (is_raw) {
        PyErr_SetString(PyExc_TypeError,
            "No Constructor for pure-virtual class: oaMarkerQuery");
    }
    else {
        pyv_oaMarkerQuery* p = new pyv_oaMarkerQuery();
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
oaMarkerQuery_tp_dealloc(PyoaMarkerQueryObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaMarkerQuery_tp_repr(PyObject *ob)
{
    PyParamoaMarkerQuery value;
    int convert_status=PyoaMarkerQuery_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaMarkerQuery::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaMarkerQuery_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaMarkerQuery v1;
    PyParamoaMarkerQuery v2;
    int convert_status1=PyoaMarkerQuery_Convert(ob1,&v1);
    int convert_status2=PyoaMarkerQuery_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaMarkerQuery_Convert(PyObject* ob,PyParamoaMarkerQuery* result)
{
    if (ob == NULL) return 1;
    if (PyoaMarkerQuery_Check(ob)) {
        result->SetData( (oaMarkerQuery*) ((PyoaMarkerQueryObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaMarkerQuery Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaMarkerQuery_FromoaMarkerQuery(oaMarkerQuery* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaMarkerQuery_Type.tp_alloc(&PyoaMarkerQuery_Type,0);
        if (bself == NULL) return bself;
        PyoaMarkerQueryObject* self = (PyoaMarkerQueryObject*)bself;
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
pyv_oaMarkerQuery::pyv_oaMarkerQuery()
 : pyob(NULL),
   oaMarkerQuery()
{
}

// ------------------------------------------------------------------
pyv_oaMarkerQuery::pyv_oaMarkerQuery(const oaMarkerQuery& p)
 : pyob(NULL),
   oaMarkerQuery(p)
{
}

// ------------------------------------------------------------------
void pyv_oaMarkerQuery::queryMarker(oaMarker* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"queryMarker");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaMarkerQuery::queryMarker was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaMarker_FromoaMarker(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaMarkerQuery::queryMarker had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaMarkerQuery::endRef(oaRef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaMarkerQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaMarkerQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaMarkerQuery::endRef(oaRef* p1,oaUInt4 p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaMarkerQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaMarkerQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaMarkerQuery::endRef(oaRef* p1,oaUInt4 p2,oaUInt4 p3)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaMarkerQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(3);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyTuple_SetItem(args,2,PyoaUInt4_FromoaUInt4(p3));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaMarkerQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
oaBoolean pyv_oaMarkerQuery::startRef(oaRef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaMarkerQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaMarkerQuery::startRef had an error.");
    }
    PyParamoaBoolean rv;
    if (PyoaBoolean_Convert(result,&rv)==0) {
        throw oaPythonException("Python Virtual Function oaBoolean::startRef has incorrect return type.");
    }
    Py_DECREF(result);
    return rv.Data();
}

// ------------------------------------------------------------------
oaBoolean pyv_oaMarkerQuery::startRef(oaRef* p1,oaUInt4 p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaMarkerQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaMarkerQuery::startRef had an error.");
    }
    PyParamoaBoolean rv;
    if (PyoaBoolean_Convert(result,&rv)==0) {
        throw oaPythonException("Python Virtual Function oaBoolean::startRef has incorrect return type.");
    }
    Py_DECREF(result);
    return rv.Data();
}

// ------------------------------------------------------------------
oaBoolean pyv_oaMarkerQuery::startRef(oaRef* p1,oaUInt4 p2,oaUInt4 p3)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaMarkerQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(3);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyTuple_SetItem(args,2,PyoaUInt4_FromoaUInt4(p3));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaMarkerQuery::startRef had an error.");
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
static char oaMarkerQuery_query_doc[] = 
"Class: oaMarkerQuery, Function: query\n"
"  Paramegers: (oaDesign,oaBox)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating markers in the specified region of the specified design hierarchy.\n"
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
"    This function begins the query process to start generating markers in the specified region of the specified design hierarchy.\n"
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
"    This function begins the query process to start generating markers in the specified region of the specified design hierarchy.\n"
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
"    This function begins the query process to start generating markers in the specified region of the specified design hierarchy.\n"
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
"    This function begins the query process to start generating markers in the specified region of the specified design hierarchy.\n"
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
"    This function begins the query process to start generating markers in the specified region of the specified design hierarchy.\n"
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
"    This function begins the query process to start generating markers in the specified region of the specified design hierarchy.\n"
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
"    This function begins the query process to start generating markers in the specified region of the specified design hierarchy.\n"
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
oaMarkerQuery_query(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarkerQuery data;
    int convert_status=PyoaMarkerQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerQueryObject* self=(PyoaMarkerQueryObject*)ob;

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
        "No Arg-Matching Function found for class: oaMarkerQuery, function: query, Choices are:\n"
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
static char oaMarkerQuery_queryMarker_doc[] = 
"Class: oaMarkerQuery, Function: queryMarker\n"
"  Paramegers: (oaMarker)\n"
"    Calls: virtual void queryMarker(oaMarker* marker)\n"
"    Signature: queryMarker|void-void|ptr-oaMarker,\n"
"    This function processes each result of the marker query.\n"
"    marker\n"
"    Pointer to an oaMarker found during querying\n"
;

static PyObject*
oaMarkerQuery_queryMarker(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarkerQuery data;
    int convert_status=PyoaMarkerQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerQueryObject* self=(PyoaMarkerQueryObject*)ob;

    PyParamoaMarker p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaMarker_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        PyErr_SetString(PyExc_TypeError,
            "Call to Pure-Virtual Function class: oaMarkerQuery, function: queryMarker");
            return NULL;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaMarkerQuery_assign_doc[] = 
"Class: oaMarkerQuery, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaMarkerQuery_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaMarkerQuery data;
  int convert_status=PyoaMarkerQuery_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaMarkerQuery p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaMarkerQuery_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaMarkerQuery_methodlist[] = {
    {"query",(PyCFunction)oaMarkerQuery_query,METH_VARARGS,oaMarkerQuery_query_doc},
    {"queryMarker",(PyCFunction)oaMarkerQuery_queryMarker,METH_VARARGS,oaMarkerQuery_queryMarker_doc},
    {"assign",(PyCFunction)oaMarkerQuery_tp_assign,METH_VARARGS,oaMarkerQuery_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaMarkerQuery_doc[] = 
"Class: oaMarkerQuery\n"
"  The oaMarkerQuery class implements functionality to query a specified region in a design hierarchy and quickly return all oaMarker that overlap the region.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaMarkerQuery()\n"
"    Signature: oaMarkerQuery||\n"
"    This is the constructor for the oaMarkerQuery class.\n"
"  Paramegers: (oaMarkerQuery)\n"
"    Calls: (const oaMarkerQuery&)\n"
"    Signature: oaMarkerQuery||cref-oaMarkerQuery,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaMarkerQuery_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaMarkerQuery",
    sizeof(PyoaMarkerQueryObject),
    0,
    (destructor)oaMarkerQuery_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaMarkerQuery_tp_compare,	/* tp_compare */
    (reprfunc)oaMarkerQuery_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaMarkerQuery_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaMarkerQuery_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaRegionQuery_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaMarkerQuery_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaMarkerQuery_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaMarkerQuery_Type)<0) {
      printf("** PyType_Ready failed for: oaMarkerQuery\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaMarkerQuery",
           (PyObject*)(&PyoaMarkerQuery_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaMarkerQuery\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaMarkerSeverity
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaMarkerSeverity_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaMarkerSeverity_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaMarkerSeverityObject* self = (PyoaMarkerSeverityObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaMarkerSeverityEnum)
    {
        PyParamoaMarkerSeverityEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaMarkerSeverityEnum_Convert,&p1)) {
            self->value =  new oaMarkerSeverity(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaMarkerSeverity(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaMarkerSeverity)
    {
        PyParamoaMarkerSeverity p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaMarkerSeverity_Convert,&p1)) {
            self->value= new oaMarkerSeverity(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaMarkerSeverity, Choices are:\n"
        "    (oaMarkerSeverityEnum)\n"
        "    (oaString)\n"
        "    (oaMarkerSeverity)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaMarkerSeverity_tp_dealloc(PyoaMarkerSeverityObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaMarkerSeverity_tp_repr(PyObject *ob)
{
    PyParamoaMarkerSeverity value;
    int convert_status=PyoaMarkerSeverity_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[38];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaMarkerSeverity::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaMarkerSeverity_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaMarkerSeverity v1;
    PyParamoaMarkerSeverity v2;
    int convert_status1=PyoaMarkerSeverity_Convert(ob1,&v1);
    int convert_status2=PyoaMarkerSeverity_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaMarkerSeverity_Convert(PyObject* ob,PyParamoaMarkerSeverity* result)
{
    if (ob == NULL) return 1;
    if (PyoaMarkerSeverity_Check(ob)) {
        result->SetData(  ((PyoaMarkerSeverityObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaMarkerSeverity Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaMarkerSeverity_FromoaMarkerSeverity(oaMarkerSeverity* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaMarkerSeverity_Type.tp_alloc(&PyoaMarkerSeverity_Type,0);
        if (bself == NULL) return bself;
        PyoaMarkerSeverityObject* self = (PyoaMarkerSeverityObject*)bself;
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
static char oaMarkerSeverity_getName_doc[] = 
"Class: oaMarkerSeverity, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaMarkerSeverityEnum object.\n"
;

static PyObject*
oaMarkerSeverity_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarkerSeverity data;
    int convert_status=PyoaMarkerSeverity_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerSeverityObject* self=(PyoaMarkerSeverityObject*)ob;

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
static char oaMarkerSeverity_oaMarkerSeverityEnum_doc[] = 
"Class: oaMarkerSeverity, Function: oaMarkerSeverityEnum\n"
"  Paramegers: ()\n"
"    Calls: oaMarkerSeverityEnum oaMarkerSeverityEnum() const\n"
"    Signature: operator oaMarkerSeverityEnum|simple-oaMarkerSeverityEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaMarkerSeverity object into the corresponding #oaMarkerSeverityEnum value.\n"
;

static PyObject*
oaMarkerSeverity_oaMarkerSeverityEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMarkerSeverity data;
    int convert_status=PyoaMarkerSeverity_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMarkerSeverityObject* self=(PyoaMarkerSeverityObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaMarkerSeverityEnum result= (data.DataCall()->operator oaMarkerSeverityEnum());
        return PyoaMarkerSeverityEnum_FromoaMarkerSeverityEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaMarkerSeverity_assign_doc[] = 
"Class: oaMarkerSeverity, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaMarkerSeverity_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaMarkerSeverity data;
  int convert_status=PyoaMarkerSeverity_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaMarkerSeverity p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaMarkerSeverity_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaMarkerSeverity_methodlist[] = {
    {"getName",(PyCFunction)oaMarkerSeverity_getName,METH_VARARGS,oaMarkerSeverity_getName_doc},
    {"oaMarkerSeverityEnum",(PyCFunction)oaMarkerSeverity_oaMarkerSeverityEnum,METH_VARARGS,oaMarkerSeverity_oaMarkerSeverityEnum_doc},
    {"assign",(PyCFunction)oaMarkerSeverity_tp_assign,METH_VARARGS,oaMarkerSeverity_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaMarkerSeverity_doc[] = 
"Class: oaMarkerSeverity\n"
"  The oaMarkerSeverity class is an enum wrapper class that defines the severity type on oaMarker objects. Applications choose one of the values below for each marker they create.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaMarkerSeverityEnum\n"
"Constructors:\n"
"  Paramegers: (oaMarkerSeverityEnum)\n"
"    Calls: oaMarkerSeverity(oaMarkerSeverityEnum valueIn)\n"
"    Signature: oaMarkerSeverity||simple-oaMarkerSeverityEnum,\n"
"    This function constructs an instance of an oaMarkerSeverity class using the specified #oaMarkerSeverityEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaMarkerSeverity(const oaString& name)\n"
"    Signature: oaMarkerSeverity||cref-oaString,\n"
"    This function constructs an instance of an oaMarkerSeverity class using the #oaMarkerSeverityEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaMarkerSeverityEnum.\n"
"    oacInvalidMarkerSeverityTypeName\n"
"  Paramegers: (oaMarkerSeverity)\n"
"    Calls: (const oaMarkerSeverity&)\n"
"    Signature: oaMarkerSeverity||cref-oaMarkerSeverity,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaMarkerSeverity_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaMarkerSeverity",
    sizeof(PyoaMarkerSeverityObject),
    0,
    (destructor)oaMarkerSeverity_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaMarkerSeverity_tp_compare,	/* tp_compare */
    (reprfunc)oaMarkerSeverity_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaMarkerSeverity_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaMarkerSeverity_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaMarkerSeverity_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaMarkerSeverity_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaMarkerSeverity_Type)<0) {
      printf("** PyType_Ready failed for: oaMarkerSeverity\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaMarkerSeverity",
           (PyObject*)(&PyoaMarkerSeverity_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaMarkerSeverity\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaMarkerSeverityEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaMarkerSeverityEnum_Convert(PyObject* ob,PyParamoaMarkerSeverityEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacAnnotationMarkerSeverity")==0) { result->SetData(oacAnnotationMarkerSeverity); return 1;}
        if (strcasecmp(str,"oacInfoMarkerSeverity")==0) { result->SetData(oacInfoMarkerSeverity); return 1;}
        if (strcasecmp(str,"oacAcknowledgedWarningMarkerSeverity")==0) { result->SetData(oacAcknowledgedWarningMarkerSeverity); return 1;}
        if (strcasecmp(str,"oacWarningMarkerSeverity")==0) { result->SetData(oacWarningMarkerSeverity); return 1;}
        if (strcasecmp(str,"oacSignedOffErrorMarkerSeverity")==0) { result->SetData(oacSignedOffErrorMarkerSeverity); return 1;}
        if (strcasecmp(str,"oacErrorMarkerSeverity")==0) { result->SetData(oacErrorMarkerSeverity); return 1;}
        if (strcasecmp(str,"oacSignedOffCriticalErrorMarkerSeverity")==0) { result->SetData(oacSignedOffCriticalErrorMarkerSeverity); return 1;}
        if (strcasecmp(str,"oacCriticalErrorMarkerSeverity")==0) { result->SetData(oacCriticalErrorMarkerSeverity); return 1;}
        if (strcasecmp(str,"oacFatalErrorMarkerSeverity")==0) { result->SetData(oacFatalErrorMarkerSeverity); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaMarkerSeverityEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaMarkerSeverityEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaMarkerSeverityEnum_FromoaMarkerSeverityEnum(oaMarkerSeverityEnum ob)
{
    if (ob==oacAnnotationMarkerSeverity) return PyString_FromString("oacAnnotationMarkerSeverity");
    if (ob==oacInfoMarkerSeverity) return PyString_FromString("oacInfoMarkerSeverity");
    if (ob==oacAcknowledgedWarningMarkerSeverity) return PyString_FromString("oacAcknowledgedWarningMarkerSeverity");
    if (ob==oacWarningMarkerSeverity) return PyString_FromString("oacWarningMarkerSeverity");
    if (ob==oacSignedOffErrorMarkerSeverity) return PyString_FromString("oacSignedOffErrorMarkerSeverity");
    if (ob==oacErrorMarkerSeverity) return PyString_FromString("oacErrorMarkerSeverity");
    if (ob==oacSignedOffCriticalErrorMarkerSeverity) return PyString_FromString("oacSignedOffCriticalErrorMarkerSeverity");
    if (ob==oacCriticalErrorMarkerSeverity) return PyString_FromString("oacCriticalErrorMarkerSeverity");
    if (ob==oacFatalErrorMarkerSeverity) return PyString_FromString("oacFatalErrorMarkerSeverity");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaMarkerSeverityEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaMarkerSeverityEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaMarkerSeverityEnum_FromoaMarkerSeverityEnum(oaMarkerSeverityEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaMarkerSeverityEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaMarkerSeverityEnum_doc[] =
"Type convert function for enum: oaMarkerSeverityEnum";
                               
static PyMethodDef PyoaMarkerSeverityEnum_method =
  {"oaMarkerSeverityEnum",(PyCFunction)PyoaMarkerSeverityEnum_TypeFunction,METH_VARARGS,oaMarkerSeverityEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaMarkerSeverityEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacAnnotationMarkerSeverity");
    PyDict_SetItemString(mod_dict,"oacAnnotationMarkerSeverity",value);
    Py_DECREF(value);
    value=PyString_FromString("oacInfoMarkerSeverity");
    PyDict_SetItemString(mod_dict,"oacInfoMarkerSeverity",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAcknowledgedWarningMarkerSeverity");
    PyDict_SetItemString(mod_dict,"oacAcknowledgedWarningMarkerSeverity",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWarningMarkerSeverity");
    PyDict_SetItemString(mod_dict,"oacWarningMarkerSeverity",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSignedOffErrorMarkerSeverity");
    PyDict_SetItemString(mod_dict,"oacSignedOffErrorMarkerSeverity",value);
    Py_DECREF(value);
    value=PyString_FromString("oacErrorMarkerSeverity");
    PyDict_SetItemString(mod_dict,"oacErrorMarkerSeverity",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSignedOffCriticalErrorMarkerSeverity");
    PyDict_SetItemString(mod_dict,"oacSignedOffCriticalErrorMarkerSeverity",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCriticalErrorMarkerSeverity");
    PyDict_SetItemString(mod_dict,"oacCriticalErrorMarkerSeverity",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFatalErrorMarkerSeverity");
    PyDict_SetItemString(mod_dict,"oacFatalErrorMarkerSeverity",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaMarkerSeverityEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaMarkerSeverityEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaMarkerSeverityEnum\n");
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
// Wrapper Implementation for Class: oaMaterial
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaMaterial_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaMaterial_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaMaterialObject* self = (PyoaMaterialObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaMaterialEnum)
    {
        PyParamoaMaterialEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaMaterialEnum_Convert,&p1)) {
            self->value =  new oaMaterial(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaMaterial(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaMaterial)
    {
        PyParamoaMaterial p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaMaterial_Convert,&p1)) {
            self->value= new oaMaterial(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaMaterial, Choices are:\n"
        "    (oaMaterialEnum)\n"
        "    (oaString)\n"
        "    (oaMaterial)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaMaterial_tp_dealloc(PyoaMaterialObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaMaterial_tp_repr(PyObject *ob)
{
    PyParamoaMaterial value;
    int convert_status=PyoaMaterial_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[32];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaMaterial::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaMaterial_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaMaterial v1;
    PyParamoaMaterial v2;
    int convert_status1=PyoaMaterial_Convert(ob1,&v1);
    int convert_status2=PyoaMaterial_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaMaterial_Convert(PyObject* ob,PyParamoaMaterial* result)
{
    if (ob == NULL) return 1;
    if (PyoaMaterial_Check(ob)) {
        result->SetData(  ((PyoaMaterialObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaMaterial Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaMaterial_FromoaMaterial(oaMaterial* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaMaterial_Type.tp_alloc(&PyoaMaterial_Type,0);
        if (bself == NULL) return bself;
        PyoaMaterialObject* self = (PyoaMaterialObject*)bself;
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
static char oaMaterial_getName_doc[] = 
"Class: oaMaterial, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaMaterialEnum object.\n"
;

static PyObject*
oaMaterial_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMaterial data;
    int convert_status=PyoaMaterial_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMaterialObject* self=(PyoaMaterialObject*)ob;

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
static char oaMaterial_oaMaterialEnum_doc[] = 
"Class: oaMaterial, Function: oaMaterialEnum\n"
"  Paramegers: ()\n"
"    Calls: oaMaterialEnum oaMaterialEnum() const\n"
"    Signature: operator oaMaterialEnum|simple-oaMaterialEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaMaterial object into the corresponding #oaMaterialEnum value.\n"
;

static PyObject*
oaMaterial_oaMaterialEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMaterial data;
    int convert_status=PyoaMaterial_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMaterialObject* self=(PyoaMaterialObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaMaterialEnum result= (data.DataCall()->operator oaMaterialEnum());
        return PyoaMaterialEnum_FromoaMaterialEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaMaterial_assign_doc[] = 
"Class: oaMaterial, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaMaterial_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaMaterial data;
  int convert_status=PyoaMaterial_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaMaterial p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaMaterial_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaMaterial_methodlist[] = {
    {"getName",(PyCFunction)oaMaterial_getName,METH_VARARGS,oaMaterial_getName_doc},
    {"oaMaterialEnum",(PyCFunction)oaMaterial_oaMaterialEnum,METH_VARARGS,oaMaterial_oaMaterialEnum_doc},
    {"assign",(PyCFunction)oaMaterial_tp_assign,METH_VARARGS,oaMaterial_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaMaterial_doc[] = 
"Class: oaMaterial\n"
"  The oaMaterial class is an enum wrapper class that classifies the types of physical layers on a chip by what fundamental electrical purpose they serve. See oaPhysicalLayer::create for its usage.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaMaterialEnum\n"
"Constructors:\n"
"  Paramegers: (oaMaterialEnum)\n"
"    Calls: oaMaterial(oaMaterialEnum valueIn)\n"
"    Signature: oaMaterial||simple-oaMaterialEnum,\n"
"    This function constructs an instance of an oaMaterial class using the specified #oaMaterialEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaMaterial(const oaString& name)\n"
"    Signature: oaMaterial||cref-oaString,\n"
"    This function constructs an instance of an oaMaterial class using the #oaMaterialEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaMaterialEnum.\n"
"    oacInvalidMaterialName\n"
"  Paramegers: (oaMaterial)\n"
"    Calls: (const oaMaterial&)\n"
"    Signature: oaMaterial||cref-oaMaterial,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaMaterial_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaMaterial",
    sizeof(PyoaMaterialObject),
    0,
    (destructor)oaMaterial_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaMaterial_tp_compare,	/* tp_compare */
    (reprfunc)oaMaterial_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaMaterial_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaMaterial_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaMaterial_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaMaterial_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaMaterial_Type)<0) {
      printf("** PyType_Ready failed for: oaMaterial\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaMaterial",
           (PyObject*)(&PyoaMaterial_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaMaterial\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaMaterialEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaMaterialEnum_Convert(PyObject* ob,PyParamoaMaterialEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacOtherMaterial")==0) { result->SetData(oacOtherMaterial); return 1;}
        if (strcasecmp(str,"oacNWellMaterial")==0) { result->SetData(oacNWellMaterial); return 1;}
        if (strcasecmp(str,"oacPWellMaterial")==0) { result->SetData(oacPWellMaterial); return 1;}
        if (strcasecmp(str,"oacNDiffMaterial")==0) { result->SetData(oacNDiffMaterial); return 1;}
        if (strcasecmp(str,"oacPDiffMaterial")==0) { result->SetData(oacPDiffMaterial); return 1;}
        if (strcasecmp(str,"oacNImplantMaterial")==0) { result->SetData(oacNImplantMaterial); return 1;}
        if (strcasecmp(str,"oacPImplantMaterial")==0) { result->SetData(oacPImplantMaterial); return 1;}
        if (strcasecmp(str,"oacPolyMaterial")==0) { result->SetData(oacPolyMaterial); return 1;}
        if (strcasecmp(str,"oacCutMaterial")==0) { result->SetData(oacCutMaterial); return 1;}
        if (strcasecmp(str,"oacMetalMaterial")==0) { result->SetData(oacMetalMaterial); return 1;}
        if (strcasecmp(str,"oacContactlessMetalMaterial")==0) { result->SetData(oacContactlessMetalMaterial); return 1;}
        if (strcasecmp(str,"oacDiffMaterial")==0) { result->SetData(oacDiffMaterial); return 1;}
        if (strcasecmp(str,"oacRecognitionMaterial")==0) { result->SetData(oacRecognitionMaterial); return 1;}
        if (strcasecmp(str,"oacPassivationCutMaterial")==0) { result->SetData(oacPassivationCutMaterial); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaMaterialEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaMaterialEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaMaterialEnum_FromoaMaterialEnum(oaMaterialEnum ob)
{
    if (ob==oacOtherMaterial) return PyString_FromString("oacOtherMaterial");
    if (ob==oacNWellMaterial) return PyString_FromString("oacNWellMaterial");
    if (ob==oacPWellMaterial) return PyString_FromString("oacPWellMaterial");
    if (ob==oacNDiffMaterial) return PyString_FromString("oacNDiffMaterial");
    if (ob==oacPDiffMaterial) return PyString_FromString("oacPDiffMaterial");
    if (ob==oacNImplantMaterial) return PyString_FromString("oacNImplantMaterial");
    if (ob==oacPImplantMaterial) return PyString_FromString("oacPImplantMaterial");
    if (ob==oacPolyMaterial) return PyString_FromString("oacPolyMaterial");
    if (ob==oacCutMaterial) return PyString_FromString("oacCutMaterial");
    if (ob==oacMetalMaterial) return PyString_FromString("oacMetalMaterial");
    if (ob==oacContactlessMetalMaterial) return PyString_FromString("oacContactlessMetalMaterial");
    if (ob==oacDiffMaterial) return PyString_FromString("oacDiffMaterial");
    if (ob==oacRecognitionMaterial) return PyString_FromString("oacRecognitionMaterial");
    if (ob==oacPassivationCutMaterial) return PyString_FromString("oacPassivationCutMaterial");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaMaterialEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaMaterialEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaMaterialEnum_FromoaMaterialEnum(oaMaterialEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaMaterialEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaMaterialEnum_doc[] =
"Type convert function for enum: oaMaterialEnum";
                               
static PyMethodDef PyoaMaterialEnum_method =
  {"oaMaterialEnum",(PyCFunction)PyoaMaterialEnum_TypeFunction,METH_VARARGS,oaMaterialEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaMaterialEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacOtherMaterial");
    PyDict_SetItemString(mod_dict,"oacOtherMaterial",value);
    Py_DECREF(value);
    value=PyString_FromString("oacNWellMaterial");
    PyDict_SetItemString(mod_dict,"oacNWellMaterial",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPWellMaterial");
    PyDict_SetItemString(mod_dict,"oacPWellMaterial",value);
    Py_DECREF(value);
    value=PyString_FromString("oacNDiffMaterial");
    PyDict_SetItemString(mod_dict,"oacNDiffMaterial",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPDiffMaterial");
    PyDict_SetItemString(mod_dict,"oacPDiffMaterial",value);
    Py_DECREF(value);
    value=PyString_FromString("oacNImplantMaterial");
    PyDict_SetItemString(mod_dict,"oacNImplantMaterial",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPImplantMaterial");
    PyDict_SetItemString(mod_dict,"oacPImplantMaterial",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPolyMaterial");
    PyDict_SetItemString(mod_dict,"oacPolyMaterial",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCutMaterial");
    PyDict_SetItemString(mod_dict,"oacCutMaterial",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMetalMaterial");
    PyDict_SetItemString(mod_dict,"oacMetalMaterial",value);
    Py_DECREF(value);
    value=PyString_FromString("oacContactlessMetalMaterial");
    PyDict_SetItemString(mod_dict,"oacContactlessMetalMaterial",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDiffMaterial");
    PyDict_SetItemString(mod_dict,"oacDiffMaterial",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRecognitionMaterial");
    PyDict_SetItemString(mod_dict,"oacRecognitionMaterial",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPassivationCutMaterial");
    PyDict_SetItemString(mod_dict,"oacPassivationCutMaterial",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaMaterialEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaMaterialEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaMaterialEnum\n");
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
// Wrapper Implementation for Class: oaMemNetCollection
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaMemNetCollection_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaMemNetCollection_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaMemNetCollectionObject* self = (PyoaMemNetCollectionObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaMemNetCollection, Choices are:\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaMemNetCollection_tp_dealloc(PyoaMemNetCollectionObject* self)
{
    if (!self->borrow) {
        delete (oaMemNetCollection*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaMemNetCollection_tp_repr(PyObject *ob)
{
    PyParamoaMemNetCollection value;
    int convert_status=PyoaMemNetCollection_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaMemNetCollection::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaMemNetCollection_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaMemNetCollection v1;
    PyParamoaMemNetCollection v2;
    int convert_status1=PyoaMemNetCollection_Convert(ob1,&v1);
    int convert_status2=PyoaMemNetCollection_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaMemNetCollection_Convert(PyObject* ob,PyParamoaMemNetCollection* result)
{
    if (ob == NULL) return 1;
    if (PyoaMemNetCollection_Check(ob)) {
        result->SetData( (oaMemNetCollection*) ((PyoaMemNetCollectionObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaMemNetCollection Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaMemNetCollection_FromoaMemNetCollection(oaMemNetCollection* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaMemNetCollection_Type.tp_alloc(&PyoaMemNetCollection_Type,0);
        if (bself == NULL) return bself;
        PyoaMemNetCollectionObject* self = (PyoaMemNetCollectionObject*)bself;
        self->value = (oaBaseMemNetCollection*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaMemNetCollection_includes_doc[] = 
"Class: oaMemNetCollection, Function: includes\n"
"  Paramegers: (oaNet)\n"
"    Calls: oaBoolean includes(const oaNet* objectIn)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaNet,\n"
"    This functions determines if the specified block net is a member of the collection.\n"
;

static PyObject*
oaMemNetCollection_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaMemNetCollection data;
    int convert_status=PyoaMemNetCollection_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaMemNetCollectionObject* self=(PyoaMemNetCollectionObject*)ob;

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

static char oaMemNetCollection_assign_doc[] = 
"Class: oaMemNetCollection, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaMemNetCollection_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaMemNetCollection data;
  int convert_status=PyoaMemNetCollection_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaMemNetCollection p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaMemNetCollection_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaMemNetCollection_methodlist[] = {
    {"includes",(PyCFunction)oaMemNetCollection_includes,METH_VARARGS,oaMemNetCollection_includes_doc},
    {"assign",(PyCFunction)oaMemNetCollection_tp_assign,METH_VARARGS,oaMemNetCollection_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaMemNetCollection_doc[] = 
"Class: oaMemNetCollection\n"
"  The member net collection class represents a collection of nets that the starting net is a member of. The oaMemNetCollection is such a collection of nets in the block domain. Examples are that a[1] is a member of a[4:0] . All explicit nets are members of themselves and so have a non-empty member net collection. See oaNet::getMemberNets() for a complete description of which nets are members of which other nets.\n"
"  The oaMemNetCollection class is a specialized collection class because the oaMemNetIter used to iterate over it does not have the standard getNext signature use by the template collection classes.\n"
"  The most common way to use an oaMemNetCollection is to use it inline in the construction of an oaMemNetIter , so the oaMemNetCollection is never explicitly declared. In the following example, net->getMemberNets() returns an oaMemNetCollection.\n"
"  oaMemNetIter nIter(net->getMemberNets()); while ( oaNet *net = nIter.getNext()) { ... }\n"
"Constructors:\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaMemNetCollection_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaMemNetCollection",
    sizeof(PyoaMemNetCollectionObject),
    0,
    (destructor)oaMemNetCollection_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaMemNetCollection_tp_compare,	/* tp_compare */
    (reprfunc)oaMemNetCollection_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaMemNetCollection_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaMemNetCollection_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseMemNetCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaMemNetCollection_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaMemNetCollection_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaMemNetCollection_Type)<0) {
      printf("** PyType_Ready failed for: oaMemNetCollection\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaMemNetCollection",
           (PyObject*)(&PyoaMemNetCollection_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaMemNetCollection\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaMemNetIter
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaMemNetIter_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaMemNetIter_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaMemNetIterObject* self = (PyoaMemNetIterObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaMemNetCollection)
    {
        PyParamoaMemNetCollection p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaMemNetCollection_Convert,&p1)) {
            self->value = (oaBaseMemNetIter*)  new oaMemNetIter(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaMemNetIter)
    {
        PyParamoaMemNetIter p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaMemNetIter_Convert,&p1)) {
            self->value = (oaBaseMemNetIter*)  new oaMemNetIter(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaMemNetIter, Choices are:\n"
        "    (oaMemNetCollection)\n"
        "    (oaMemNetIter)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaMemNetIter_tp_dealloc(PyoaMemNetIterObject* self)
{
    if (!self->borrow) {
        delete (oaMemNetIter*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaMemNetIter_tp_repr(PyObject *ob)
{
    PyParamoaMemNetIter value;
    int convert_status=PyoaMemNetIter_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[34];
    sprintf(buffer,"<oaMemNetIter::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaMemNetIter_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaMemNetIter v1;
    PyParamoaMemNetIter v2;
    int convert_status1=PyoaMemNetIter_Convert(ob1,&v1);
    int convert_status2=PyoaMemNetIter_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
static PyObject*
oaMemNetIter_getiter(PyObject *self)
{
    Py_INCREF(self);
    return self;
}

// ------------------------------------------------------------------
PyObject* oaMemNetIter_iternext(PyObject *self);

// ------------------------------------------------------------------
int
PyoaMemNetIter_Convert(PyObject* ob,PyParamoaMemNetIter* result)
{
    if (ob == NULL) return 1;
    if (PyoaMemNetIter_Check(ob)) {
        result->SetData( (oaMemNetIter*) ((PyoaMemNetIterObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaMemNetIter Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaMemNetIter_FromoaMemNetIter(oaMemNetIter* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaMemNetIter_Type.tp_alloc(&PyoaMemNetIter_Type,0);
        if (bself == NULL) return bself;
        PyoaMemNetIterObject* self = (PyoaMemNetIterObject*)bself;
        self->value = (oaBaseMemNetIter*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaMemNetIter_getNext_doc[] = 
"Class: oaMemNetIter, Function: getNext\n"
"  Paramegers: ()\n"
"    Calls: oaNet* getNext()\n"
"    Signature: getNext|ptr-oaNet|ref-oaUInt4,\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the next object in the collection that is being iterated. NULL is returned when there are no more objects to return.\n"
"    arg\n"
"    The member index of the current net in the returned net\n"
;

extern PyObject* oaMemNetIter_getNext(PyObject *self, PyObject *args);

// ------------------------------------------------------------------
static char oaMemNetIter_next_doc[] = 
"Class: oaMemNetIter, Function: next\n"
"  Paramegers: ()\n"
"    Calls: oaNet* next()\n"
"    Signature: next|ptr-oaNet|,\n"
"    BrowseData: 1\n"
"    get next value or raise StopIteration\n"
;

extern PyObject* oaMemNetIter_next(PyObject *self, PyObject *args);

static char oaMemNetIter_assign_doc[] = 
"Class: oaMemNetIter, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaMemNetIter_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaMemNetIter data;
  int convert_status=PyoaMemNetIter_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaMemNetIter p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaMemNetIter_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaMemNetIter_methodlist[] = {
    {"getNext",(PyCFunction)oaMemNetIter_getNext,METH_VARARGS,oaMemNetIter_getNext_doc},
    {"next",(PyCFunction)oaMemNetIter_next,METH_VARARGS,oaMemNetIter_next_doc},
    {"assign",(PyCFunction)oaMemNetIter_tp_assign,METH_VARARGS,oaMemNetIter_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaMemNetIter_doc[] = 
"Class: oaMemNetIter\n"
"  The oaMemNetIter class implements a special case iterator. This class returns member oaNets of an oaMemNetCollection . A collection of member nets is all those nets of whom the current net is a member. Because all nets are members of themselves, this iterator will always return at least one net.\n"
"  For example, a collection of member nets for net a would contain all of the following nets:\n"
"  a\n"
"  x,y,a\n"
"  a*4\n"
"  The member net index is returned in the getNext() function. This index indicates the member position of the specified net in the collection. For the example above, the iterator would return the following values:\n"
"  a 0\n"
"  x,y,a 2\n"
"  a*4 0\n"
"  a*4 1\n"
"  a*4 2\n"
"  a*4 3\n"
"  This particular collection and iterator are primarily for those applications that want to traverse single-bit connectivity.\n"
"Constructors:\n"
"  Paramegers: (oaMemNetCollection)\n"
"    Calls: oaMemNetIter(const oaMemNetCollection& cl)\n"
"    Signature: oaMemNetIter||cref-oaMemNetCollection,\n"
"    This function constructs a new oaMemNetIter object according to the specified memNet collection cl .\n"
"    cl\n"
"    The specified oaMemNetCollection object\n"
"  Paramegers: (oaMemNetIter)\n"
"    Calls: oaMemNetIter(const oaMemNetIter& iterIn)\n"
"    Signature: oaMemNetIter||cref-oaMemNetIter,\n"
"    This function constructs a new oaMemNetIter class and iterates over the same set of objects as the specified oaMemNetIter iterator. The new iterator starts at the beginning of the collection.\n"
"    iterIn\n"
"    The iterator value to use\n"
"  Paramegers: (oaMemNetIter)\n"
"    Calls: (const oaMemNetIter&)\n"
"    Signature: oaMemNetIter||cref-oaMemNetIter,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaMemNetIter_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaMemNetIter",
    sizeof(PyoaMemNetIterObject),
    0,
    (destructor)oaMemNetIter_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaMemNetIter_tp_compare,	/* tp_compare */
    (reprfunc)oaMemNetIter_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaMemNetIter_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    (getiterfunc)oaMemNetIter_getiter,	/* tp_iter */
    (iternextfunc)oaMemNetIter_iternext,	/* tp_iternext */
    oaMemNetIter_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseMemNetIter_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaMemNetIter_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaMemNetIter_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaMemNetIter_Type)<0) {
      printf("** PyType_Ready failed for: oaMemNetIter\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaMemNetIter",
           (PyObject*)(&PyoaMemNetIter_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaMemNetIter\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaMfgLayerArray
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaMfgLayerArray_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaMfgLayerArray_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaMfgLayerArrayObject* self = (PyoaMfgLayerArrayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaLayerNum*)  new oaMfgLayerArray();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaLayerNum*)  new oaMfgLayerArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaMfgLayerArray)
    {
        PyParamoaMfgLayerArray p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaMfgLayerArray_Convert,&p1)) {
            self->value=(oaArrayBase_oaLayerNum*)  new oaMfgLayerArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaMfgLayerArray, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaMfgLayerArray)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaMfgLayerArray_tp_dealloc(PyoaMfgLayerArrayObject* self)
{
    if (!self->borrow) {
        delete (oaMfgLayerArray*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaMfgLayerArray_tp_repr(PyObject *ob)
{
    PyParamoaMfgLayerArray value;
    int convert_status=PyoaMfgLayerArray_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaMfgLayerArray::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaMfgLayerArray_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaMfgLayerArray v1;
    PyParamoaMfgLayerArray v2;
    int convert_status1=PyoaMfgLayerArray_Convert(ob1,&v1);
    int convert_status2=PyoaMfgLayerArray_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaMfgLayerArray_Convert(PyObject* ob,PyParamoaMfgLayerArray* result)
{
    if (ob == NULL) return 1;
    if (PyoaMfgLayerArray_Check(ob)) {
        result->SetData( (oaMfgLayerArray*) ((PyoaMfgLayerArrayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaMfgLayerArray Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaMfgLayerArray_FromoaMfgLayerArray(oaMfgLayerArray* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaMfgLayerArray_Type.tp_alloc(&PyoaMfgLayerArray_Type,0);
        if (bself == NULL) return bself;
        PyoaMfgLayerArrayObject* self = (PyoaMfgLayerArrayObject*)bself;
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
static char oaMfgLayerArray_doc[] = 
"Class: oaMfgLayerArray\n"
"  This class represents a set of manufacturing layers that can be used in an oaImage .\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaMfgLayerArray()\n"
"    Signature: oaMfgLayerArray||simple-oaUInt4,\n"
"    This is one of the constructors for the oaMfgLayerArray class. This version sets the size of the array and allocates storage for it. The number of values is set to zero.\n"
"    sizeIn\n"
"    The initial size of the array\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaMfgLayerArray(oaUInt4 sizeIn)\n"
"    Signature: oaMfgLayerArray||simple-oaUInt4,\n"
"    This is one of the constructors for the oaMfgLayerArray class. This version sets the size of the array and allocates storage for it. The number of values is set to zero.\n"
"    sizeIn\n"
"    The initial size of the array\n"
"  Paramegers: (oaMfgLayerArray)\n"
"    Calls: (const oaMfgLayerArray&)\n"
"    Signature: oaMfgLayerArray||cref-oaMfgLayerArray,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaMfgLayerArray_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaMfgLayerArray",
    sizeof(PyoaMfgLayerArrayObject),
    0,
    (destructor)oaMfgLayerArray_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaMfgLayerArray_tp_compare,	/* tp_compare */
    (reprfunc)oaMfgLayerArray_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaMfgLayerArray_doc,	/* tp_doc */
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
    oaMfgLayerArray_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaMfgLayerArray_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaMfgLayerArray_Type)<0) {
      printf("** PyType_Ready failed for: oaMfgLayerArray\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaMfgLayerArray",
           (PyObject*)(&PyoaMfgLayerArray_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaMfgLayerArray\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaModAssignAssignment
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaModAssignAssignment_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaModAssignAssignment_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaModAssignAssignmentObject* self = (PyoaModAssignAssignmentObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaModAssignAssignment)
    {
        PyParamoaModAssignAssignment p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaModAssignAssignment_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaModAssignAssignment, Choices are:\n"
        "    (oaModAssignAssignment)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaModAssignAssignment_tp_dealloc(PyoaModAssignAssignmentObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaModAssignAssignment_tp_repr(PyObject *ob)
{
    PyParamoaModAssignAssignment value;
    int convert_status=PyoaModAssignAssignment_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaModAssignAssignment::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[43];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaModAssignAssignment::");
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
oaModAssignAssignment_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaModAssignAssignment v1;
    PyParamoaModAssignAssignment v2;
    int convert_status1=PyoaModAssignAssignment_Convert(ob1,&v1);
    int convert_status2=PyoaModAssignAssignment_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaModAssignAssignment_Convert(PyObject* ob,PyParamoaModAssignAssignment* result)
{
    if (ob == NULL) return 1;
    if (PyoaModAssignAssignment_Check(ob)) {
        result->SetData( (oaModAssignAssignment**) ((PyoaModAssignAssignmentObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaModAssignAssignment Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaModAssignAssignment_FromoaModAssignAssignment(oaModAssignAssignment** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaModAssignAssignment* data=*value;
        PyObject* bself = PyoaModAssignAssignment_Type.tp_alloc(&PyoaModAssignAssignment_Type,0);
        if (bself == NULL) return bself;
        PyoaModAssignAssignmentObject* self = (PyoaModAssignAssignmentObject*)bself;
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
PyObject* PyoaModAssignAssignment_FromoaModAssignAssignment(oaModAssignAssignment* data)
{
    if (data) {
       PyObject* bself = PyoaModAssignAssignment_Type.tp_alloc(&PyoaModAssignAssignment_Type,0);
       if (bself == NULL) return bself;
       PyoaModAssignAssignmentObject* self = (PyoaModAssignAssignmentObject*)bself;
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
static char oaModAssignAssignment_getAssignmentDef_doc[] = 
"Class: oaModAssignAssignment, Function: getAssignmentDef\n"
"  Paramegers: (oaAssignmentDef)\n"
"    Calls: void getAssignmentDef(oaAssignmentDef& aDef) const\n"
"    Signature: getAssignmentDef|void-void|ref-oaAssignmentDef,\n"
"    BrowseData: 0,oaAssignmentDef\n"
"    This function retrieves the data associated with this assignment and returns it in the assignmentDef argument.\n"
;

static PyObject*
oaModAssignAssignment_getAssignmentDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModAssignAssignment data;
    int convert_status=PyoaModAssignAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModAssignAssignmentObject* self=(PyoaModAssignAssignmentObject*)ob;
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
static char oaModAssignAssignment_setAssignmentDef_doc[] = 
"Class: oaModAssignAssignment, Function: setAssignmentDef\n"
"  Paramegers: (oaAssignmentDef)\n"
"    Calls: void setAssignmentDef(const oaAssignmentDef& aDef)\n"
"    Signature: setAssignmentDef|void-void|cref-oaAssignmentDef,\n"
"    This function sets the data for this assignment from the specified assignmentDef .\n"
"    oacInvalidAssignmentDef\n"
;

static PyObject*
oaModAssignAssignment_setAssignmentDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModAssignAssignment data;
    int convert_status=PyoaModAssignAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModAssignAssignmentObject* self=(PyoaModAssignAssignmentObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaAssignmentDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaAssignmentDef_Convert,&p1)) {
        data.DataCall()->setAssignmentDef(p1.Data());
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
static char oaModAssignAssignment_isNull_doc[] =
"Class: oaModAssignAssignment, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaModAssignAssignment_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaModAssignAssignment data;
    int convert_status=PyoaModAssignAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaModAssignAssignment_assign_doc[] = 
"Class: oaModAssignAssignment, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaModAssignAssignment_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaModAssignAssignment data;
  int convert_status=PyoaModAssignAssignment_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaModAssignAssignment p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaModAssignAssignment_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaModAssignAssignment_methodlist[] = {
    {"getAssignmentDef",(PyCFunction)oaModAssignAssignment_getAssignmentDef,METH_VARARGS,oaModAssignAssignment_getAssignmentDef_doc},
    {"setAssignmentDef",(PyCFunction)oaModAssignAssignment_setAssignmentDef,METH_VARARGS,oaModAssignAssignment_setAssignmentDef_doc},
    {"isNull",(PyCFunction)oaModAssignAssignment_tp_isNull,METH_VARARGS,oaModAssignAssignment_isNull_doc},
    {"assign",(PyCFunction)oaModAssignAssignment_tp_assign,METH_VARARGS,oaModAssignAssignment_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModAssignAssignment_doc[] = 
"Class: oaModAssignAssignment\n"
"  The oaModAssignAssignment class implements a connection assignment that specifies assignment definition values to replace those specified in a corresponding oaModConnectDef or a previously encountered oaModAssignAssignment. Applications interpreting the connectivity continue searching up the design hierarchy for a connection assignment with the name specified in the oaModAssignAssignment. If none is found, the assignment value is the default net name.\n"
"  This type of connection assignment is useful for integrating a block of intellectual property that contain connection definition. An oaModAssignAssignment can be used to insure that connectivity traversal applications search for connection assignments consistently in the entire design hierarchy.\n"
"Constructors:\n"
"  Paramegers: (oaModAssignAssignment)\n"
"    Calls: (const oaModAssignAssignment&)\n"
"    Signature: oaModAssignAssignment||cref-oaModAssignAssignment,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaModAssignAssignment_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaModAssignAssignment",
    sizeof(PyoaModAssignAssignmentObject),
    0,
    (destructor)oaModAssignAssignment_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaModAssignAssignment_tp_compare,	/* tp_compare */
    (reprfunc)oaModAssignAssignment_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaModAssignAssignment_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaModAssignAssignment_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaModAssignment_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaModAssignAssignment_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModAssignAssignment_static_create_doc[] = 
"Class: oaModAssignAssignment, Function: create\n"
"  Paramegers: (oaModInst,oaString,oaAssignmentDef)\n"
"    Calls: oaModAssignAssignment* create(const oaModInst* inst,const oaString& name,const oaAssignmentDef& aDef)\n"
"    Signature: create|ptr-oaModAssignAssignment|cptr-oaModInst,cref-oaString,cref-oaAssignmentDef,\n"
"    This function creates an oaModAssignAssignment with the specified attributes on the given instance.\n"
"    inst\n"
"    The instance on which to create the connection assignment\n"
"    name\n"
"    The name to give to this assignment. This name should correspond to the lookup name specified in the assignment definition of an oaModNetConnectDef or oaModTermConnectDef object.\n"
"    assignmentDef\n"
"    Specifies the assignment definition values to replace those of a corresponding oaModNetConnectDef or oaModTermConnectDef object.\n"
"    oacInstHasAssignment\n"
"    oacInvalidAssignmentDef\n"
;

static PyObject*
oaModAssignAssignment_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModInst p1;
    PyParamoaString p2;
    PyParamoaAssignmentDef p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaModInst_Convert,&p1,
          &PyoaString_Convert,&p2,
          &PyoaAssignmentDef_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaModAssignAssignmentp result= (oaModAssignAssignment::create(p1.Data(),p2.Data(),p3.Data()));
        return PyoaModAssignAssignment_FromoaModAssignAssignment(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaModAssignAssignment_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaModAssignAssignment_static_create,METH_VARARGS,oaModAssignAssignment_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaModAssignAssignment_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaModAssignAssignment_Type)<0) {
      printf("** PyType_Ready failed for: oaModAssignAssignment\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaModAssignAssignment",
           (PyObject*)(&PyoaModAssignAssignment_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaModAssignAssignment\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaModAssignAssignment_Type.tp_dict;
    for(method=oaModAssignAssignment_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaModAssignValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaModAssignValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaModAssignValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaModAssignValueObject* self = (PyoaModAssignValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaModAssignValue)
    {
        PyParamoaModAssignValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaModAssignValue_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaModAssignValue, Choices are:\n"
        "    (oaModAssignValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaModAssignValue_tp_dealloc(PyoaModAssignValueObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaModAssignValue_tp_repr(PyObject *ob)
{
    PyParamoaModAssignValue value;
    int convert_status=PyoaModAssignValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaModAssignValue::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[38];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaModAssignValue::");
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
oaModAssignValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaModAssignValue v1;
    PyParamoaModAssignValue v2;
    int convert_status1=PyoaModAssignValue_Convert(ob1,&v1);
    int convert_status2=PyoaModAssignValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaModAssignValue_Convert(PyObject* ob,PyParamoaModAssignValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaModAssignValue_Check(ob)) {
        result->SetData( (oaModAssignValue**) ((PyoaModAssignValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaModAssignValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaModAssignValue_FromoaModAssignValue(oaModAssignValue** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaModAssignValue* data=*value;
        PyObject* bself = PyoaModAssignValue_Type.tp_alloc(&PyoaModAssignValue_Type,0);
        if (bself == NULL) return bself;
        PyoaModAssignValueObject* self = (PyoaModAssignValueObject*)bself;
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
PyObject* PyoaModAssignValue_FromoaModAssignValue(oaModAssignValue* data)
{
    if (data) {
       PyObject* bself = PyoaModAssignValue_Type.tp_alloc(&PyoaModAssignValue_Type,0);
       if (bself == NULL) return bself;
       PyoaModAssignValueObject* self = (PyoaModAssignValueObject*)bself;
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
static char oaModAssignValue_getValue_doc[] = 
"Class: oaModAssignValue, Function: getValue\n"
"  Paramegers: (oaSimpleName)\n"
"    Calls: void getValue(oaSimpleName& netName) const\n"
"    Signature: getValue|void-void|ref-oaSimpleName,\n"
"    BrowseData: 0,oaSimpleName\n"
"    This function returns the netName of this oaModAssignValue object. This netName specifies the name of a single-bit net to use to in resolving the connections associated with a corresponding oaModConnectDef object in the design hierarchy.\n"
;

static PyObject*
oaModAssignValue_getValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModAssignValue data;
    int convert_status=PyoaModAssignValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModAssignValueObject* self=(PyoaModAssignValueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaSimpleName p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSimpleName_Convert,&p1)) {
        data.DataCall()->getValue(p1.Data());
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
static char oaModAssignValue_setValue_doc[] = 
"Class: oaModAssignValue, Function: setValue\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void setValue(const oaScalarName& netName)\n"
"    Signature: setValue|void-void|cref-oaScalarName,\n"
"    This function sets the netName value of this oaModAssignValue object.\n"
"  Paramegers: (oaVectorBitName)\n"
"    Calls: void setValue(const oaVectorBitName& netName)\n"
"    Signature: setValue|void-void|cref-oaVectorBitName,\n"
"    This function sets the netName value of this oaModAssignValue object.\n"
;

static PyObject*
oaModAssignValue_setValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModAssignValue data;
    int convert_status=PyoaModAssignValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModAssignValueObject* self=(PyoaModAssignValueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
            data.DataCall()->setValue(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaVectorBitName)
    {
        PyParamoaVectorBitName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaVectorBitName_Convert,&p1)) {
            data.DataCall()->setValue(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaModAssignValue, function: setValue, Choices are:\n"
        "    (oaScalarName)\n"
        "    (oaVectorBitName)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModAssignValue_isNull_doc[] =
"Class: oaModAssignValue, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaModAssignValue_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaModAssignValue data;
    int convert_status=PyoaModAssignValue_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaModAssignValue_assign_doc[] = 
"Class: oaModAssignValue, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaModAssignValue_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaModAssignValue data;
  int convert_status=PyoaModAssignValue_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaModAssignValue p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaModAssignValue_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaModAssignValue_methodlist[] = {
    {"getValue",(PyCFunction)oaModAssignValue_getValue,METH_VARARGS,oaModAssignValue_getValue_doc},
    {"setValue",(PyCFunction)oaModAssignValue_setValue,METH_VARARGS,oaModAssignValue_setValue_doc},
    {"isNull",(PyCFunction)oaModAssignValue_tp_isNull,METH_VARARGS,oaModAssignValue_isNull_doc},
    {"assign",(PyCFunction)oaModAssignValue_tp_assign,METH_VARARGS,oaModAssignValue_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModAssignValue_doc[] = 
"Class: oaModAssignValue\n"
"  The oaModAssignValue class implements a connection assignment that specifies\n"
"  the name of the net to use in place of the name of the net associated with the corresponding oaModNetConnectDef object\n"
"  the name of the net to use to externally connect to the terminal associated with the corresponding oaModTermConnectDef object\n"
"Constructors:\n"
"  Paramegers: (oaModAssignValue)\n"
"    Calls: (const oaModAssignValue&)\n"
"    Signature: oaModAssignValue||cref-oaModAssignValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaModAssignValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaModAssignValue",
    sizeof(PyoaModAssignValueObject),
    0,
    (destructor)oaModAssignValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaModAssignValue_tp_compare,	/* tp_compare */
    (reprfunc)oaModAssignValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaModAssignValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaModAssignValue_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaModAssignment_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaModAssignValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModAssignValue_static_create_doc[] = 
"Class: oaModAssignValue, Function: create\n"
"  Paramegers: (oaModInst,oaString,oaScalarName)\n"
"    Calls: oaModAssignValue* create(const oaModInst* inst,const oaString& name,const oaScalarName& netName)\n"
"    Signature: create|ptr-oaModAssignValue|cptr-oaModInst,cref-oaString,cref-oaScalarName,\n"
"    This function creates an oaModAssignValue object with the specified attributes on the given instance.\n"
"    inst\n"
"    The instance this assign will be attached to. It will apply to ConnectDefs in the hierarchy underneath this instance.\n"
"    name\n"
"    The name to give to the assignment. This name should correspond to the assignment name specified in the assignment definition in an oaModNetConnectDef or oaModTermConnectDef .\n"
"    netName\n"
"    The name of a scalar net to be used when resolving the connectivity associated with oaModNetConnectDef and oaModTermConnectDef objects in a design hierarchy.\n"
"    oacInstHasAssignment\n"
"  Paramegers: (oaModInst,oaString,oaVectorBitName)\n"
"    Calls: oaModAssignValue* create(const oaModInst* inst,const oaString& name,const oaVectorBitName& netName)\n"
"    Signature: create|ptr-oaModAssignValue|cptr-oaModInst,cref-oaString,cref-oaVectorBitName,\n"
"    This function creates an oaModAssignValue object with the specified attributes on the given instance.\n"
"    inst\n"
"    The instance this assign will be attached to. It will apply to ConnectDefs in the hierarchy underneath this instance.\n"
"    name\n"
"    The name to give to the assignment. This name should correspond to the assignment name specified in the assignment definition in an oaModNetConnectDef or oaModTermConnectDef object.\n"
"    netName\n"
"    The name of a single-bit bus net to be used when resolving the connectivity associated with oaModNetConnectDef and oaModTermConnectDef objects in a design hierarchy.\n"
"    oacInstHasAssignment\n"
;

static PyObject*
oaModAssignValue_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaModInst,oaString,oaScalarName)
    {
        PyParamoaModInst p1;
        PyParamoaString p2;
        PyParamoaScalarName p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaModInst_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaScalarName_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModAssignValuep result= (oaModAssignValue::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaModAssignValue_FromoaModAssignValue(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModInst,oaString,oaVectorBitName)
    {
        PyParamoaModInst p1;
        PyParamoaString p2;
        PyParamoaVectorBitName p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaModInst_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaVectorBitName_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModAssignValuep result= (oaModAssignValue::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaModAssignValue_FromoaModAssignValue(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaModAssignValue, function: create, Choices are:\n"
        "    (oaModInst,oaString,oaScalarName)\n"
        "    (oaModInst,oaString,oaVectorBitName)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaModAssignValue_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaModAssignValue_static_create,METH_VARARGS,oaModAssignValue_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaModAssignValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaModAssignValue_Type)<0) {
      printf("** PyType_Ready failed for: oaModAssignValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaModAssignValue",
           (PyObject*)(&PyoaModAssignValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaModAssignValue\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaModAssignValue_Type.tp_dict;
    for(method=oaModAssignValue_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaModAssignment
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaModAssignment_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaModAssignment_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaModAssignmentObject* self = (PyoaModAssignmentObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaModAssignment)
    {
        PyParamoaModAssignment p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaModAssignment_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaModAssignment, Choices are:\n"
        "    (oaModAssignment)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaModAssignment_tp_dealloc(PyoaModAssignmentObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaModAssignment_tp_repr(PyObject *ob)
{
    PyParamoaModAssignment value;
    int convert_status=PyoaModAssignment_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaModAssignment::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[37];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaModAssignment::");
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
oaModAssignment_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaModAssignment v1;
    PyParamoaModAssignment v2;
    int convert_status1=PyoaModAssignment_Convert(ob1,&v1);
    int convert_status2=PyoaModAssignment_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaModAssignment_Convert(PyObject* ob,PyParamoaModAssignment* result)
{
    if (ob == NULL) return 1;
    if (PyoaModAssignment_Check(ob)) {
        result->SetData( (oaModAssignment**) ((PyoaModAssignmentObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaModAssignment Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaModAssignment_FromoaModAssignment(oaModAssignment** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaModAssignment* data=*value;
        if (data->getType()==oacModAssignAssignmentType) return PyoaModAssignAssignment_FromoaModAssignAssignment((oaModAssignAssignment**)value,borrow,lock);
        if (data->getType()==oacModAssignValueType) return PyoaModAssignValue_FromoaModAssignValue((oaModAssignValue**)value,borrow,lock);
        PyObject* bself = PyoaModAssignment_Type.tp_alloc(&PyoaModAssignment_Type,0);
        if (bself == NULL) return bself;
        PyoaModAssignmentObject* self = (PyoaModAssignmentObject*)bself;
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
PyObject* PyoaModAssignment_FromoaModAssignment(oaModAssignment* data)
{
    if (data) {
        if (data->getType()==oacModAssignAssignmentType) return PyoaModAssignAssignment_FromoaModAssignAssignment((oaModAssignAssignment*)data);
        if (data->getType()==oacModAssignValueType) return PyoaModAssignValue_FromoaModAssignValue((oaModAssignValue*)data);
       PyObject* bself = PyoaModAssignment_Type.tp_alloc(&PyoaModAssignment_Type,0);
       if (bself == NULL) return bself;
       PyoaModAssignmentObject* self = (PyoaModAssignmentObject*)bself;
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
static char oaModAssignment_destroy_doc[] = 
"Class: oaModAssignment, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this assignment, removing it from the database.\n"
;

static PyObject*
oaModAssignment_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModAssignment data;
    int convert_status=PyoaModAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModAssignmentObject* self=(PyoaModAssignmentObject*)ob;
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
static char oaModAssignment_getInst_doc[] = 
"Class: oaModAssignment, Function: getInst\n"
"  Paramegers: ()\n"
"    Calls: oaModInst* getInst() const\n"
"    Signature: getInst|ptr-oaModInst|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the instance with which this assignment is associated.\n"
;

static PyObject*
oaModAssignment_getInst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModAssignment data;
    int convert_status=PyoaModAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModAssignmentObject* self=(PyoaModAssignmentObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaModInstp result= (data.DataCall()->getInst());
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
static char oaModAssignment_getName_doc[] = 
"Class: oaModAssignment, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of this assignment in the given name string. This is the name that is searched for when resolving the connections for the oaModNetConnectDef and oaModTermConnectDef objects.\n"
;

static PyObject*
oaModAssignment_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModAssignment data;
    int convert_status=PyoaModAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModAssignmentObject* self=(PyoaModAssignmentObject*)ob;
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
static char oaModAssignment_setInst_doc[] = 
"Class: oaModAssignment, Function: setInst\n"
"  Paramegers: (oaModInst)\n"
"    Calls: void setInst(oaModInst* inst)\n"
"    Signature: setInst|void-void|ptr-oaModInst,\n"
"    This function changes the instance with which this assignment is associated.\n"
"    oacInstAndAssignmentNotInSameBlock\n"
;

static PyObject*
oaModAssignment_setInst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModAssignment data;
    int convert_status=PyoaModAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModAssignmentObject* self=(PyoaModAssignmentObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaModInst p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModInst_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setInst(p1.Data());
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
static char oaModAssignment_setName_doc[] = 
"Class: oaModAssignment, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function changes the assignment name for this assignment object. The name is also updated for each of the occurrences that the assignment appears in.\n"
;

static PyObject*
oaModAssignment_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModAssignment data;
    int convert_status=PyoaModAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModAssignmentObject* self=(PyoaModAssignmentObject*)ob;
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
static char oaModAssignment_isNull_doc[] =
"Class: oaModAssignment, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaModAssignment_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaModAssignment data;
    int convert_status=PyoaModAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaModAssignment_assign_doc[] = 
"Class: oaModAssignment, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaModAssignment_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaModAssignment data;
  int convert_status=PyoaModAssignment_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaModAssignment p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaModAssignment_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaModAssignment_methodlist[] = {
    {"destroy",(PyCFunction)oaModAssignment_destroy,METH_VARARGS,oaModAssignment_destroy_doc},
    {"getInst",(PyCFunction)oaModAssignment_getInst,METH_VARARGS,oaModAssignment_getInst_doc},
    {"getName",(PyCFunction)oaModAssignment_getName,METH_VARARGS,oaModAssignment_getName_doc},
    {"setInst",(PyCFunction)oaModAssignment_setInst,METH_VARARGS,oaModAssignment_setInst_doc},
    {"setName",(PyCFunction)oaModAssignment_setName,METH_VARARGS,oaModAssignment_setName_doc},
    {"isNull",(PyCFunction)oaModAssignment_tp_isNull,METH_VARARGS,oaModAssignment_isNull_doc},
    {"assign",(PyCFunction)oaModAssignment_tp_assign,METH_VARARGS,oaModAssignment_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModAssignment_doc[] = 
"Class: oaModAssignment\n"
"  The oaModAssignment class is the base class for all types of connection assignments. The oaModAssignment objects specify the overriding assignments for the connection definitions specified in corresponding oaModConnectDef objects. Together, these objects allow you to specify how nets are to be connected to by name in a design hierarchy.\n"
"  See oaModNetConnectDef and oaModTermConnectDef for information on the specific type of connection definition. See oaModAssignValue and oaModAssignAssignment for information on the specific type of connection assignment.\n"
"  The oaModAssignment class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaModAssignment)\n"
"    Calls: (const oaModAssignment&)\n"
"    Signature: oaModAssignment||cref-oaModAssignment,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaModAssignment_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaModAssignment",
    sizeof(PyoaModAssignmentObject),
    0,
    (destructor)oaModAssignment_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaModAssignment_tp_compare,	/* tp_compare */
    (reprfunc)oaModAssignment_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaModAssignment_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaModAssignment_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaModObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaModAssignment_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModAssignment_static_find_doc[] = 
"Class: oaModAssignment, Function: find\n"
"  Paramegers: (oaModInst,oaString)\n"
"    Calls: oaModAssignment* find(const oaModInst* inst,const oaString& name)\n"
"    Signature: find|ptr-oaModAssignment|cptr-oaModInst,cref-oaString,\n"
"    This function searches the specified instance for an assignment with the specified lookup name .\n"
"    A pointer to the assignment, if found\n"
;

static PyObject*
oaModAssignment_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModInst p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaModInst_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaModAssignmentp result= (oaModAssignment::find(p1.Data(),p2.Data()));
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
static PyMethodDef oaModAssignment_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaModAssignment_static_find,METH_VARARGS,oaModAssignment_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaModAssignment_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaModAssignment_Type)<0) {
      printf("** PyType_Ready failed for: oaModAssignment\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaModAssignment",
           (PyObject*)(&PyoaModAssignment_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaModAssignment\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaModAssignment_Type.tp_dict;
    for(method=oaModAssignment_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaModBitInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaModBitInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaModBitInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaModBitInstObject* self = (PyoaModBitInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaModBitInst)
    {
        PyParamoaModBitInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaModBitInst_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaModBitInst, Choices are:\n"
        "    (oaModBitInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaModBitInst_tp_dealloc(PyoaModBitInstObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaModBitInst_tp_repr(PyObject *ob)
{
    PyParamoaModBitInst value;
    int convert_status=PyoaModBitInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaModBitInst::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaSimpleName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[34];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaModBitInst::");
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
oaModBitInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaModBitInst v1;
    PyParamoaModBitInst v2;
    int convert_status1=PyoaModBitInst_Convert(ob1,&v1);
    int convert_status2=PyoaModBitInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaModBitInst_Convert(PyObject* ob,PyParamoaModBitInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaModBitInst_Check(ob)) {
        result->SetData( (oaModBitInst**) ((PyoaModBitInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaModBitInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaModBitInst_FromoaModBitInst(oaModBitInst** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaModBitInst* data=*value;
        if (data->getType()==oacModVectorInstBitType) return PyoaModVectorInstBit_FromoaModVectorInstBit((oaModVectorInstBit**)value,borrow,lock);
        if (data->getType()==oacModScalarInstType) return PyoaModScalarInst_FromoaModScalarInst((oaModScalarInst**)value,borrow,lock);
        PyObject* bself = PyoaModBitInst_Type.tp_alloc(&PyoaModBitInst_Type,0);
        if (bself == NULL) return bself;
        PyoaModBitInstObject* self = (PyoaModBitInstObject*)bself;
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
PyObject* PyoaModBitInst_FromoaModBitInst(oaModBitInst* data)
{
    if (data) {
        if (data->getType()==oacModVectorInstBitType) return PyoaModVectorInstBit_FromoaModVectorInstBit((oaModVectorInstBit*)data);
        if (data->getType()==oacModScalarInstType) return PyoaModScalarInst_FromoaModScalarInst((oaModScalarInst*)data);
       PyObject* bself = PyoaModBitInst_Type.tp_alloc(&PyoaModBitInst_Type,0);
       if (bself == NULL) return bself;
       PyoaModBitInstObject* self = (PyoaModBitInstObject*)bself;
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
static char oaModBitInst_doc[] = 
"Class: oaModBitInst\n"
"  The oaModBitInst class is the base class for scalar, module instances of a design master.\n"
"  oaModDesignBitInst objects are always in the module domain.\n"
"Constructors:\n"
"  Paramegers: (oaModBitInst)\n"
"    Calls: (const oaModBitInst&)\n"
"    Signature: oaModBitInst||cref-oaModBitInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaModBitInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaModBitInst",
    sizeof(PyoaModBitInstObject),
    0,
    (destructor)oaModBitInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaModBitInst_tp_compare,	/* tp_compare */
    (reprfunc)oaModBitInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaModBitInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaModDesignInst_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaModBitInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaModBitInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaModBitInst_Type)<0) {
      printf("** PyType_Ready failed for: oaModBitInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaModBitInst",
           (PyObject*)(&PyoaModBitInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaModBitInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaModBitNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaModBitNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaModBitNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaModBitNetObject* self = (PyoaModBitNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaModBitNet)
    {
        PyParamoaModBitNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaModBitNet_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaModBitNet, Choices are:\n"
        "    (oaModBitNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaModBitNet_tp_dealloc(PyoaModBitNetObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaModBitNet_tp_repr(PyObject *ob)
{
    PyParamoaModBitNet value;
    int convert_status=PyoaModBitNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaModBitNet::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[33];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaModBitNet::");
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
oaModBitNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaModBitNet v1;
    PyParamoaModBitNet v2;
    int convert_status1=PyoaModBitNet_Convert(ob1,&v1);
    int convert_status2=PyoaModBitNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaModBitNet_Convert(PyObject* ob,PyParamoaModBitNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaModBitNet_Check(ob)) {
        result->SetData( (oaModBitNet**) ((PyoaModBitNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaModBitNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaModBitNet_FromoaModBitNet(oaModBitNet** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaModBitNet* data=*value;
        if (data->getType()==oacModBusNetBitType) return PyoaModBusNetBit_FromoaModBusNetBit((oaModBusNetBit**)value,borrow,lock);
        if (data->getType()==oacModScalarNetType) return PyoaModScalarNet_FromoaModScalarNet((oaModScalarNet**)value,borrow,lock);
        PyObject* bself = PyoaModBitNet_Type.tp_alloc(&PyoaModBitNet_Type,0);
        if (bself == NULL) return bself;
        PyoaModBitNetObject* self = (PyoaModBitNetObject*)bself;
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
PyObject* PyoaModBitNet_FromoaModBitNet(oaModBitNet* data)
{
    if (data) {
        if (data->getType()==oacModBusNetBitType) return PyoaModBusNetBit_FromoaModBusNetBit((oaModBusNetBit*)data);
        if (data->getType()==oacModScalarNetType) return PyoaModScalarNet_FromoaModScalarNet((oaModScalarNet*)data);
       PyObject* bself = PyoaModBitNet_Type.tp_alloc(&PyoaModBitNet_Type,0);
       if (bself == NULL) return bself;
       PyoaModBitNetObject* self = (PyoaModBitNetObject*)bself;
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
static char oaModBitNet_breakEquivalence_doc[] = 
"Class: oaModBitNet, Function: breakEquivalence\n"
"  Paramegers: ()\n"
"    Calls: void breakEquivalence()\n"
"    Signature: breakEquivalence|void-void|\n"
"    BrowseData: 0\n"
"    This function breaks the equivalence between this net with all other nets it was equivalent to.\n"
"    oacNetHasNoEquivNet\n"
;

static PyObject*
oaModBitNet_breakEquivalence(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBitNet data;
    int convert_status=PyoaModBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBitNetObject* self=(PyoaModBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->breakEquivalence();
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
static char oaModBitNet_getConnectDef_doc[] = 
"Class: oaModBitNet, Function: getConnectDef\n"
"  Paramegers: ()\n"
"    Calls: oaModNetConnectDef* getConnectDef() const\n"
"    Signature: getConnectDef|ptr-oaModNetConnectDef|\n"
"    BrowseData: 1\n"
"    This function returns the connection definition associated with this net if there is one. Otherwise, NULL is returned.\n"
;

static PyObject*
oaModBitNet_getConnectDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBitNet data;
    int convert_status=PyoaModBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBitNetObject* self=(PyoaModBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaModNetConnectDefp result= (data.DataCall()->getConnectDef());
        return PyoaModNetConnectDef_FromoaModNetConnectDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBitNet_getEquivalentNets_doc[] = 
"Class: oaModBitNet, Function: getEquivalentNets\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaModBitNet_oaModBitNet getEquivalentNets() const\n"
"    Signature: getEquivalentNets|simple-oaCollection_oaModBitNet_oaModBitNet|\n"
"    BrowseData: 1\n"
"    This function returns a collection of nets equivalent to this net.\n"
"    This function gets the collection of all equivalent nets not including the net used to get the collection. The returned collection will be empty if there are no equivalent nets assigned to this net.\n"
;

static PyObject*
oaModBitNet_getEquivalentNets(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBitNet data;
    int convert_status=PyoaModBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBitNetObject* self=(PyoaModBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaModBitNet_oaModBitNet* result= new oaCollection_oaModBitNet_oaModBitNet(data.DataCall()->getEquivalentNets());
        return PyoaCollection_oaModBitNet_oaModBitNet_FromoaCollection_oaModBitNet_oaModBitNet(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBitNet_getEquivalentNetsIter_doc[] = 
"Class: oaModBitNet, Function: getEquivalentNetsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaModBitNet getEquivalentNetsIter() const\n"
"    Signature: getEquivalentNetsIter|simple-oaIter_oaModBitNet|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of nets equivalent to this net.\n"
"    This function gets the collection of all equivalent nets not including the net used to get the collection. The returned collection will be empty if there are no equivalent nets assigned to this net.\n"
;

static PyObject*
oaModBitNet_getEquivalentNetsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBitNet data;
    int convert_status=PyoaModBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBitNetObject* self=(PyoaModBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaModBitNet* result= new oaIter_oaModBitNet(data.DataCall()->getEquivalentNets());
        return PyoaIter_oaModBitNet_FromoaIter_oaModBitNet(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBitNet_getPreferredEquivalent_doc[] = 
"Class: oaModBitNet, Function: getPreferredEquivalent\n"
"  Paramegers: ()\n"
"    Calls: oaModBitNet* getPreferredEquivalent() const\n"
"    Signature: getPreferredEquivalent|ptr-oaModBitNet|\n"
"    BrowseData: 1\n"
"    This function returns the preferred equivalent net associated with this net. If this net does not have any equivalents, the net itself is returned since it is considered the preferred equivalent of itself.\n"
;

static PyObject*
oaModBitNet_getPreferredEquivalent(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBitNet data;
    int convert_status=PyoaModBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBitNetObject* self=(PyoaModBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaModBitNetp result= (data.DataCall()->getPreferredEquivalent());
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
static char oaModBitNet_isPreferredEquivalent_doc[] = 
"Class: oaModBitNet, Function: isPreferredEquivalent\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isPreferredEquivalent() const\n"
"    Signature: isPreferredEquivalent|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this net is the preferred equivalent net in a set of equivalent nets. true is also returned if the net does not have any equivalents.\n"
;

static PyObject*
oaModBitNet_isPreferredEquivalent(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBitNet data;
    int convert_status=PyoaModBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBitNetObject* self=(PyoaModBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isPreferredEquivalent());
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
static char oaModBitNet_makeEquivalent_doc[] = 
"Class: oaModBitNet, Function: makeEquivalent\n"
"  Paramegers: (oaModBitNet)\n"
"    Calls: void makeEquivalent(oaModBitNet* equivNet)\n"
"    Signature: makeEquivalent|void-void|ptr-oaModBitNet,\n"
"    This function will set this net and the specified net equivalent. Exceptions are thrown if the given net is NULL, if this and the given net are in different designs, or if either net is multi-bit.\n"
"    equivNet\n"
"    The net to be set as equivalent to this net.\n"
"    oacInvalidNet\n"
"    oacNetEquivNetNotInSameDesign\n"
;

static PyObject*
oaModBitNet_makeEquivalent(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBitNet data;
    int convert_status=PyoaModBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBitNetObject* self=(PyoaModBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaModBitNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaModBitNet_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->makeEquivalent(p1.Data());
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
static char oaModBitNet_setPreferredEquivalent_doc[] = 
"Class: oaModBitNet, Function: setPreferredEquivalent\n"
"  Paramegers: ()\n"
"    Calls: void setPreferredEquivalent()\n"
"    Signature: setPreferredEquivalent|void-void|\n"
"    BrowseData: 0\n"
"    This function sets this net to the preferred net of a set of equivalent nets. If this net does not have any equivalents, this function does nothing.\n"
;

static PyObject*
oaModBitNet_setPreferredEquivalent(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBitNet data;
    int convert_status=PyoaModBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBitNetObject* self=(PyoaModBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->setPreferredEquivalent();
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
static char oaModBitNet_isNull_doc[] =
"Class: oaModBitNet, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaModBitNet_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaModBitNet data;
    int convert_status=PyoaModBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaModBitNet_assign_doc[] = 
"Class: oaModBitNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaModBitNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaModBitNet data;
  int convert_status=PyoaModBitNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaModBitNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaModBitNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaModBitNet_methodlist[] = {
    {"breakEquivalence",(PyCFunction)oaModBitNet_breakEquivalence,METH_VARARGS,oaModBitNet_breakEquivalence_doc},
    {"getConnectDef",(PyCFunction)oaModBitNet_getConnectDef,METH_VARARGS,oaModBitNet_getConnectDef_doc},
    {"getEquivalentNets",(PyCFunction)oaModBitNet_getEquivalentNets,METH_VARARGS,oaModBitNet_getEquivalentNets_doc},
    {"getEquivalentNetsIter",(PyCFunction)oaModBitNet_getEquivalentNetsIter,METH_VARARGS,oaModBitNet_getEquivalentNetsIter_doc},
    {"getPreferredEquivalent",(PyCFunction)oaModBitNet_getPreferredEquivalent,METH_VARARGS,oaModBitNet_getPreferredEquivalent_doc},
    {"isPreferredEquivalent",(PyCFunction)oaModBitNet_isPreferredEquivalent,METH_VARARGS,oaModBitNet_isPreferredEquivalent_doc},
    {"makeEquivalent",(PyCFunction)oaModBitNet_makeEquivalent,METH_VARARGS,oaModBitNet_makeEquivalent_doc},
    {"setPreferredEquivalent",(PyCFunction)oaModBitNet_setPreferredEquivalent,METH_VARARGS,oaModBitNet_setPreferredEquivalent_doc},
    {"isNull",(PyCFunction)oaModBitNet_tp_isNull,METH_VARARGS,oaModBitNet_isNull_doc},
    {"assign",(PyCFunction)oaModBitNet_tp_assign,METH_VARARGS,oaModBitNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModBitNet_doc[] = 
"Class: oaModBitNet\n"
"  The oaModBitNet class is the base class for single-bit nets that are part of the design's logical description.\n"
"  You can have two or more bitNets that are equivalent. Equivalent bitNets are traversed separately or logically as the same net.\n"
"  You can create associate a connection definition, oaModNetConnectDef , with a bitNet.\n"
"Constructors:\n"
"  Paramegers: (oaModBitNet)\n"
"    Calls: (const oaModBitNet&)\n"
"    Signature: oaModBitNet||cref-oaModBitNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaModBitNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaModBitNet",
    sizeof(PyoaModBitNetObject),
    0,
    (destructor)oaModBitNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaModBitNet_tp_compare,	/* tp_compare */
    (reprfunc)oaModBitNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaModBitNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaModBitNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaModNet_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaModBitNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaModBitNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaModBitNet_Type)<0) {
      printf("** PyType_Ready failed for: oaModBitNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaModBitNet",
           (PyObject*)(&PyoaModBitNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaModBitNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaModBitTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaModBitTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaModBitTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaModBitTermObject* self = (PyoaModBitTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaModBitTerm)
    {
        PyParamoaModBitTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaModBitTerm_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaModBitTerm, Choices are:\n"
        "    (oaModBitTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaModBitTerm_tp_dealloc(PyoaModBitTermObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaModBitTerm_tp_repr(PyObject *ob)
{
    PyParamoaModBitTerm value;
    int convert_status=PyoaModBitTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaModBitTerm::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[34];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaModBitTerm::");
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
oaModBitTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaModBitTerm v1;
    PyParamoaModBitTerm v2;
    int convert_status1=PyoaModBitTerm_Convert(ob1,&v1);
    int convert_status2=PyoaModBitTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaModBitTerm_Convert(PyObject* ob,PyParamoaModBitTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaModBitTerm_Check(ob)) {
        result->SetData( (oaModBitTerm**) ((PyoaModBitTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaModBitTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaModBitTerm_FromoaModBitTerm(oaModBitTerm** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaModBitTerm* data=*value;
        if (data->getType()==oacModBusTermBitType) return PyoaModBusTermBit_FromoaModBusTermBit((oaModBusTermBit**)value,borrow,lock);
        if (data->getType()==oacModScalarTermType) return PyoaModScalarTerm_FromoaModScalarTerm((oaModScalarTerm**)value,borrow,lock);
        PyObject* bself = PyoaModBitTerm_Type.tp_alloc(&PyoaModBitTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaModBitTermObject* self = (PyoaModBitTermObject*)bself;
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
PyObject* PyoaModBitTerm_FromoaModBitTerm(oaModBitTerm* data)
{
    if (data) {
        if (data->getType()==oacModBusTermBitType) return PyoaModBusTermBit_FromoaModBusTermBit((oaModBusTermBit*)data);
        if (data->getType()==oacModScalarTermType) return PyoaModScalarTerm_FromoaModScalarTerm((oaModScalarTerm*)data);
       PyObject* bself = PyoaModBitTerm_Type.tp_alloc(&PyoaModBitTerm_Type,0);
       if (bself == NULL) return bself;
       PyoaModBitTermObject* self = (PyoaModBitTermObject*)bself;
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
static char oaModBitTerm_getConnectDef_doc[] = 
"Class: oaModBitTerm, Function: getConnectDef\n"
"  Paramegers: ()\n"
"    Calls: oaModTermConnectDef* getConnectDef() const\n"
"    Signature: getConnectDef|ptr-oaModTermConnectDef|\n"
"    BrowseData: 1\n"
"    This function gets the connection definition that is associated with this module bitTerm. It returns NULL if no ConnectDef has been set on the terminal.\n"
;

static PyObject*
oaModBitTerm_getConnectDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBitTerm data;
    int convert_status=PyoaModBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBitTermObject* self=(PyoaModBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaModTermConnectDefp result= (data.DataCall()->getConnectDef());
        return PyoaModTermConnectDef_FromoaModTermConnectDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBitTerm_isNull_doc[] =
"Class: oaModBitTerm, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaModBitTerm_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaModBitTerm data;
    int convert_status=PyoaModBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaModBitTerm_assign_doc[] = 
"Class: oaModBitTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaModBitTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaModBitTerm data;
  int convert_status=PyoaModBitTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaModBitTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaModBitTerm_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaModBitTerm_methodlist[] = {
    {"getConnectDef",(PyCFunction)oaModBitTerm_getConnectDef,METH_VARARGS,oaModBitTerm_getConnectDef_doc},
    {"isNull",(PyCFunction)oaModBitTerm_tp_isNull,METH_VARARGS,oaModBitTerm_isNull_doc},
    {"assign",(PyCFunction)oaModBitTerm_tp_assign,METH_VARARGS,oaModBitTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModBitTerm_doc[] = 
"Class: oaModBitTerm\n"
"  The oaModBitTerm class is the base class for single-bit terminals that are part of the design's logical description.\n"
"  You can create associate a connection definition, oaModTermConnectDef , with a bitTerm.\n"
"Constructors:\n"
"  Paramegers: (oaModBitTerm)\n"
"    Calls: (const oaModBitTerm&)\n"
"    Signature: oaModBitTerm||cref-oaModBitTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaModBitTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaModBitTerm",
    sizeof(PyoaModBitTermObject),
    0,
    (destructor)oaModBitTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaModBitTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaModBitTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaModBitTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaModBitTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaModTerm_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaModBitTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaModBitTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaModBitTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaModBitTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaModBitTerm",
           (PyObject*)(&PyoaModBitTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaModBitTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaModBundleNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaModBundleNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaModBundleNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaModBundleNetObject* self = (PyoaModBundleNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaModBundleNet)
    {
        PyParamoaModBundleNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaModBundleNet_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaModBundleNet, Choices are:\n"
        "    (oaModBundleNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaModBundleNet_tp_dealloc(PyoaModBundleNetObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaModBundleNet_tp_repr(PyObject *ob)
{
    PyParamoaModBundleNet value;
    int convert_status=PyoaModBundleNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaModBundleNet::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[36];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaModBundleNet::");
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
oaModBundleNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaModBundleNet v1;
    PyParamoaModBundleNet v2;
    int convert_status1=PyoaModBundleNet_Convert(ob1,&v1);
    int convert_status2=PyoaModBundleNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaModBundleNet_Convert(PyObject* ob,PyParamoaModBundleNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaModBundleNet_Check(ob)) {
        result->SetData( (oaModBundleNet**) ((PyoaModBundleNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaModBundleNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaModBundleNet_FromoaModBundleNet(oaModBundleNet** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaModBundleNet* data=*value;
        PyObject* bself = PyoaModBundleNet_Type.tp_alloc(&PyoaModBundleNet_Type,0);
        if (bself == NULL) return bself;
        PyoaModBundleNetObject* self = (PyoaModBundleNetObject*)bself;
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
PyObject* PyoaModBundleNet_FromoaModBundleNet(oaModBundleNet* data)
{
    if (data) {
       PyObject* bself = PyoaModBundleNet_Type.tp_alloc(&PyoaModBundleNet_Type,0);
       if (bself == NULL) return bself;
       PyoaModBundleNetObject* self = (PyoaModBundleNetObject*)bself;
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
static char oaModBundleNet_getMember_doc[] = 
"Class: oaModBundleNet, Function: getMember\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaModNet* getMember(oaUInt4 index) const\n"
"    Signature: getMember|ptr-oaModNet|simple-oaUInt4,\n"
"    This function returns the specified member of this net at the specified bundle member index.\n"
"    memIndex\n"
"    The bundle member index of the net to be returned.\n"
"    A pointer to an oaModNet\n"
"    oacInvalidBundleNetMemberIndex\n"
;

static PyObject*
oaModBundleNet_getMember(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBundleNet data;
    int convert_status=PyoaModBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBundleNetObject* self=(PyoaModBundleNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        oaModNetp result= (data.DataCall()->getMember(p1.Data()));
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
static char oaModBundleNet_getMembers_doc[] = 
"Class: oaModBundleNet, Function: getMembers\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaModNet_oaModBundleNet getMembers() const\n"
"    Signature: getMembers|simple-oaCollection_oaModNet_oaModBundleNet|\n"
"    BrowseData: 1\n"
"    This function returns a collection of the member nets in this oaModBundleNet.\n"
;

static PyObject*
oaModBundleNet_getMembers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBundleNet data;
    int convert_status=PyoaModBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBundleNetObject* self=(PyoaModBundleNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaModNet_oaModBundleNet* result= new oaCollection_oaModNet_oaModBundleNet(data.DataCall()->getMembers());
        return PyoaCollection_oaModNet_oaModBundleNet_FromoaCollection_oaModNet_oaModBundleNet(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBundleNet_getMembersIter_doc[] = 
"Class: oaModBundleNet, Function: getMembersIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaModNet getMembersIter() const\n"
"    Signature: getMembersIter|simple-oaIter_oaModNet|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of the member nets in this oaModBundleNet.\n"
;

static PyObject*
oaModBundleNet_getMembersIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBundleNet data;
    int convert_status=PyoaModBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBundleNetObject* self=(PyoaModBundleNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaModNet* result= new oaIter_oaModNet(data.DataCall()->getMembers());
        return PyoaIter_oaModNet_FromoaIter_oaModNet(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBundleNet_getName_doc[] = 
"Class: oaModBundleNet, Function: getName\n"
"  Paramegers: (oaBundleName)\n"
"    Calls: void getName(oaBundleName& name) const\n"
"    Signature: getName|void-void|ref-oaBundleName,\n"
"    BrowseData: 0,oaBundleName\n"
"    This function returns the name of this modBundleNet.\n"
"    name\n"
"    The name of the modBundleNet to return\n"
"  Paramegers: (oaName)\n"
"    Calls: void getName(oaName& name) const\n"
"    Signature: getName|void-void|ref-oaName,\n"
"    BrowseData: 0,oaName\n"
"    This function returns the name of this net in the name argument.\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getName(const oaNameSpace& ns,oaString& name) const\n"
"    Signature: getName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the name of this net in the specified nameSpace in the specified name string.\n"
;

static PyObject*
oaModBundleNet_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBundleNet data;
    int convert_status=PyoaModBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBundleNetObject* self=(PyoaModBundleNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaBundleName)
    {
        PyParamoaBundleName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBundleName_Convert,&p1)) {
            data.DataCall()->getName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaName)
    {
        PyParamoaName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaName_Convert,&p1)) {
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
        "No Arg-Matching Function found for class: oaModBundleNet, function: getName, Choices are:\n"
        "    (oaBundleName)\n"
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
static char oaModBundleNet_getNumMembers_doc[] = 
"Class: oaModBundleNet, Function: getNumMembers\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumMembers() const\n"
"    Signature: getNumMembers|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of members in this oaModBundleNet. Each member net in an oaModBundleNet can repeat.\n"
;

static PyObject*
oaModBundleNet_getNumMembers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBundleNet data;
    int convert_status=PyoaModBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBundleNetObject* self=(PyoaModBundleNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumMembers());
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
static char oaModBundleNet_getRepeat_doc[] = 
"Class: oaModBundleNet, Function: getRepeat\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaUInt4 getRepeat(oaUInt4 index) const\n"
"    Signature: getRepeat|simple-oaUInt4|simple-oaUInt4,\n"
"    This function returns the repeat count for the specified member of this oaModBundleNet.\n"
"    For example, for oaModBundleNet a,b,c , the repeat count for each member is one. An oaModBundleNet x,100*y[0:1] contains two members, and the repeat count for the second member is 100. The number of bits for the net is 201.\n"
"    memIndex\n"
"    The member number for which to return the repeat count\n"
"    An unsigned value indicating the repeat count for the specified member of the oaModBundleNet\n"
"    oacInvalidBundleNetMemberIndex\n"
;

static PyObject*
oaModBundleNet_getRepeat(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBundleNet data;
    int convert_status=PyoaModBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBundleNetObject* self=(PyoaModBundleNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        oaUInt4 result= (data.DataCall()->getRepeat(p1.Data()));
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
static char oaModBundleNet_isNull_doc[] =
"Class: oaModBundleNet, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaModBundleNet_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaModBundleNet data;
    int convert_status=PyoaModBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaModBundleNet_assign_doc[] = 
"Class: oaModBundleNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaModBundleNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaModBundleNet data;
  int convert_status=PyoaModBundleNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaModBundleNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaModBundleNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaModBundleNet_methodlist[] = {
    {"getMember",(PyCFunction)oaModBundleNet_getMember,METH_VARARGS,oaModBundleNet_getMember_doc},
    {"getMembers",(PyCFunction)oaModBundleNet_getMembers,METH_VARARGS,oaModBundleNet_getMembers_doc},
    {"getMembersIter",(PyCFunction)oaModBundleNet_getMembersIter,METH_VARARGS,oaModBundleNet_getMembersIter_doc},
    {"getName",(PyCFunction)oaModBundleNet_getName,METH_VARARGS,oaModBundleNet_getName_doc},
    {"getNumMembers",(PyCFunction)oaModBundleNet_getNumMembers,METH_VARARGS,oaModBundleNet_getNumMembers_doc},
    {"getRepeat",(PyCFunction)oaModBundleNet_getRepeat,METH_VARARGS,oaModBundleNet_getRepeat_doc},
    {"isNull",(PyCFunction)oaModBundleNet_tp_isNull,METH_VARARGS,oaModBundleNet_isNull_doc},
    {"assign",(PyCFunction)oaModBundleNet_tp_assign,METH_VARARGS,oaModBundleNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModBundleNet_doc[] = 
"Class: oaModBundleNet\n"
"  This class implements a multi-bit net composed of one or more scalar nets, bus nets, or a combination of both. When an oaModBundleNet is created, all member nets specified as part of the bundle name expression are added to it. The constituent scalar nets and bus nets are automatically created as implicit nets if they do not already exist.\n"
"Constructors:\n"
"  Paramegers: (oaModBundleNet)\n"
"    Calls: (const oaModBundleNet&)\n"
"    Signature: oaModBundleNet||cref-oaModBundleNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaModBundleNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaModBundleNet",
    sizeof(PyoaModBundleNetObject),
    0,
    (destructor)oaModBundleNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaModBundleNet_tp_compare,	/* tp_compare */
    (reprfunc)oaModBundleNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaModBundleNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaModBundleNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaModNet_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaModBundleNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModBundleNet_static_create_doc[] = 
"Class: oaModBundleNet, Function: create\n"
"  Paramegers: (oaModule,oaBundleName)\n"
"    Calls: oaModBundleNet* create(oaModule* module,const oaBundleName& name)\n"
"    Signature: create|ptr-oaModBundleNet|ptr-oaModule,cref-oaBundleName,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates an oaModBundleNet object in the specified module with the specified attributes. The name specifies the members of the oaBundleNet object and these member nets are automatically created if they do not already exist in the specified block. An exception is thrown if an oaModBundleNet object with the given name already exists.\n"
"    module\n"
"    The module in which to create the oaModBundleNet\n"
"    name\n"
"    The name of this oaModBundleNet. The members of the bundleNet are derived from the name.\n"
"    sigType\n"
"    The signal type to associate with this net\n"
"    isGlobal\n"
"    Specifies if this is a global net\n"
"    A pointer to an oaModBundleNet\n"
"    oacNetExists\n"
"  Paramegers: (oaModule,oaBundleName,oaSigType)\n"
"    Calls: oaModBundleNet* create(oaModule* module,const oaBundleName& name,oaSigType type)\n"
"    Signature: create|ptr-oaModBundleNet|ptr-oaModule,cref-oaBundleName,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates an oaModBundleNet object in the specified module with the specified attributes. The name specifies the members of the oaBundleNet object and these member nets are automatically created if they do not already exist in the specified block. An exception is thrown if an oaModBundleNet object with the given name already exists.\n"
"    module\n"
"    The module in which to create the oaModBundleNet\n"
"    name\n"
"    The name of this oaModBundleNet. The members of the bundleNet are derived from the name.\n"
"    sigType\n"
"    The signal type to associate with this net\n"
"    isGlobal\n"
"    Specifies if this is a global net\n"
"    A pointer to an oaModBundleNet\n"
"    oacNetExists\n"
"  Paramegers: (oaModule,oaBundleName,oaSigType,oaBoolean)\n"
"    Calls: oaModBundleNet* create(oaModule* module,const oaBundleName& name,oaSigType type,oaBoolean isGlobal)\n"
"    Signature: create|ptr-oaModBundleNet|ptr-oaModule,cref-oaBundleName,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates an oaModBundleNet object in the specified module with the specified attributes. The name specifies the members of the oaBundleNet object and these member nets are automatically created if they do not already exist in the specified block. An exception is thrown if an oaModBundleNet object with the given name already exists.\n"
"    module\n"
"    The module in which to create the oaModBundleNet\n"
"    name\n"
"    The name of this oaModBundleNet. The members of the bundleNet are derived from the name.\n"
"    sigType\n"
"    The signal type to associate with this net\n"
"    isGlobal\n"
"    Specifies if this is a global net\n"
"    A pointer to an oaModBundleNet\n"
"    oacNetExists\n"
;

static PyObject*
oaModBundleNet_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaModule,oaBundleName)
    {
        PyParamoaModule p1;
        PyParamoaBundleName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaBundleName_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBundleNetp result= (oaModBundleNet::create(p1.Data(),p2.Data()));
            return PyoaModBundleNet_FromoaModBundleNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModule,oaBundleName,oaSigType)
    {
        PyParamoaModule p1;
        PyParamoaBundleName p2;
        PyParamoaSigType p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaBundleName_Convert,&p2,
              &PyoaSigType_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBundleNetp result= (oaModBundleNet::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaModBundleNet_FromoaModBundleNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModule,oaBundleName,oaSigType,oaBoolean)
    {
        PyParamoaModule p1;
        PyParamoaBundleName p2;
        PyParamoaSigType p3;
        PyParamoaBoolean p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaBundleName_Convert,&p2,
              &PyoaSigType_Convert,&p3,
              &PyoaBoolean_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBundleNetp result= (oaModBundleNet::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaModBundleNet_FromoaModBundleNet(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaModBundleNet, function: create, Choices are:\n"
        "    (oaModule,oaBundleName)\n"
        "    (oaModule,oaBundleName,oaSigType)\n"
        "    (oaModule,oaBundleName,oaSigType,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBundleNet_static_find_doc[] = 
"Class: oaModBundleNet, Function: find\n"
"  Paramegers: (oaModule,oaBundleName)\n"
"    Calls: oaModBundleNet* find(const oaModule* module,const oaBundleName& name)\n"
"    Signature: find|ptr-oaModBundleNet|cptr-oaModule,cref-oaBundleName,\n"
"    This function searches the specified module for an oaModBundleNet with the specified name .\n"
"    module\n"
"    The module to search\n"
"    name\n"
"    The name of the oaModBundleNet to find\n"
"    A pointer to an oaModBundleNet; NULL is returned if found\n"
;

static PyObject*
oaModBundleNet_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModule p1;
    PyParamoaBundleName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaModule_Convert,&p1,
          &PyoaBundleName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaModBundleNetp result= (oaModBundleNet::find(p1.Data(),p2.Data()));
        return PyoaModBundleNet_FromoaModBundleNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBundleNet_static_isValidName_doc[] = 
"Class: oaModBundleNet, Function: isValidName\n"
"  Paramegers: (oaModule,oaBundleName)\n"
"    Calls: oaBoolean isValidName(const oaModule* module,const oaBundleName& name)\n"
"    Signature: isValidName|simple-oaBoolean|cptr-oaModule,cref-oaBundleName,\n"
"    This function returns a boolean value indicating whether the specified name is valid for a new oaModBundleNet in the specified module.\n"
"    module\n"
"    The module in which to check the oaModBundleNet name\n"
"    name\n"
"    The name of the new oaModBundleNet that might be created\n"
;

static PyObject*
oaModBundleNet_static_isValidName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModule p1;
    PyParamoaBundleName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaModule_Convert,&p1,
          &PyoaBundleName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaBoolean result= (oaModBundleNet::isValidName(p1.Data(),p2.Data()));
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
static PyMethodDef oaModBundleNet_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaModBundleNet_static_create,METH_VARARGS,oaModBundleNet_static_create_doc},
    {"static_find",(PyCFunction)oaModBundleNet_static_find,METH_VARARGS,oaModBundleNet_static_find_doc},
    {"static_isValidName",(PyCFunction)oaModBundleNet_static_isValidName,METH_VARARGS,oaModBundleNet_static_isValidName_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaModBundleNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaModBundleNet_Type)<0) {
      printf("** PyType_Ready failed for: oaModBundleNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaModBundleNet",
           (PyObject*)(&PyoaModBundleNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaModBundleNet\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaModBundleNet_Type.tp_dict;
    for(method=oaModBundleNet_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaModBundleTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaModBundleTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaModBundleTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaModBundleTermObject* self = (PyoaModBundleTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaModBundleTerm)
    {
        PyParamoaModBundleTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaModBundleTerm_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaModBundleTerm, Choices are:\n"
        "    (oaModBundleTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaModBundleTerm_tp_dealloc(PyoaModBundleTermObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaModBundleTerm_tp_repr(PyObject *ob)
{
    PyParamoaModBundleTerm value;
    int convert_status=PyoaModBundleTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaModBundleTerm::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[37];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaModBundleTerm::");
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
oaModBundleTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaModBundleTerm v1;
    PyParamoaModBundleTerm v2;
    int convert_status1=PyoaModBundleTerm_Convert(ob1,&v1);
    int convert_status2=PyoaModBundleTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaModBundleTerm_Convert(PyObject* ob,PyParamoaModBundleTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaModBundleTerm_Check(ob)) {
        result->SetData( (oaModBundleTerm**) ((PyoaModBundleTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaModBundleTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaModBundleTerm_FromoaModBundleTerm(oaModBundleTerm** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaModBundleTerm* data=*value;
        PyObject* bself = PyoaModBundleTerm_Type.tp_alloc(&PyoaModBundleTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaModBundleTermObject* self = (PyoaModBundleTermObject*)bself;
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
PyObject* PyoaModBundleTerm_FromoaModBundleTerm(oaModBundleTerm* data)
{
    if (data) {
       PyObject* bself = PyoaModBundleTerm_Type.tp_alloc(&PyoaModBundleTerm_Type,0);
       if (bself == NULL) return bself;
       PyoaModBundleTermObject* self = (PyoaModBundleTermObject*)bself;
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
static char oaModBundleTerm_getMember_doc[] = 
"Class: oaModBundleTerm, Function: getMember\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaModTerm* getMember(oaUInt4 index) const\n"
"    Signature: getMember|ptr-oaModTerm|simple-oaUInt4,\n"
"    This function returns the memIndex member of this bundleTerm.\n"
"    memIndex\n"
"    The bundle member index of the member term to get\n"
"    A pointer to an oaModTerm\n"
"    oacInvalidBundleTermMemberIndex\n"
;

static PyObject*
oaModBundleTerm_getMember(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBundleTerm data;
    int convert_status=PyoaModBundleTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBundleTermObject* self=(PyoaModBundleTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        oaModTermp result= (data.DataCall()->getMember(p1.Data()));
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
static char oaModBundleTerm_getMembers_doc[] = 
"Class: oaModBundleTerm, Function: getMembers\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaModTerm_oaModBundleTerm getMembers() const\n"
"    Signature: getMembers|simple-oaCollection_oaModTerm_oaModBundleTerm|\n"
"    BrowseData: 1\n"
"    This function returns a collection of member terms in this bundleTerm.\n"
;

static PyObject*
oaModBundleTerm_getMembers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBundleTerm data;
    int convert_status=PyoaModBundleTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBundleTermObject* self=(PyoaModBundleTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaModTerm_oaModBundleTerm* result= new oaCollection_oaModTerm_oaModBundleTerm(data.DataCall()->getMembers());
        return PyoaCollection_oaModTerm_oaModBundleTerm_FromoaCollection_oaModTerm_oaModBundleTerm(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBundleTerm_getMembersIter_doc[] = 
"Class: oaModBundleTerm, Function: getMembersIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaModTerm getMembersIter() const\n"
"    Signature: getMembersIter|simple-oaIter_oaModTerm|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of member terms in this bundleTerm.\n"
;

static PyObject*
oaModBundleTerm_getMembersIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBundleTerm data;
    int convert_status=PyoaModBundleTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBundleTermObject* self=(PyoaModBundleTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaModTerm* result= new oaIter_oaModTerm(data.DataCall()->getMembers());
        return PyoaIter_oaModTerm_FromoaIter_oaModTerm(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBundleTerm_getName_doc[] = 
"Class: oaModBundleTerm, Function: getName\n"
"  Paramegers: (oaBundleName)\n"
"    Calls: void getName(oaBundleName& name) const\n"
"    Signature: getName|void-void|ref-oaBundleName,\n"
"    BrowseData: 0,oaBundleName\n"
"    This function returns the name of this modBundleTerm.\n"
"    name\n"
"    The name of the modBundleTerm to return\n"
"  Paramegers: (oaName)\n"
"    Calls: void getName(oaName& name) const\n"
"    Signature: getName|void-void|ref-oaName,\n"
"    BrowseData: 0,oaName\n"
"    This function fills out name with the name of this terminal.\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getName(const oaNameSpace& ns,oaString& name) const\n"
"    Signature: getName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function fills in name with the name of this terminal mapped to the specified nameSpace.\n"
;

static PyObject*
oaModBundleTerm_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBundleTerm data;
    int convert_status=PyoaModBundleTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBundleTermObject* self=(PyoaModBundleTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaBundleName)
    {
        PyParamoaBundleName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBundleName_Convert,&p1)) {
            data.DataCall()->getName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaName)
    {
        PyParamoaName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaName_Convert,&p1)) {
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
        "No Arg-Matching Function found for class: oaModBundleTerm, function: getName, Choices are:\n"
        "    (oaBundleName)\n"
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
static char oaModBundleTerm_getNumMembers_doc[] = 
"Class: oaModBundleTerm, Function: getNumMembers\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumMembers() const\n"
"    Signature: getNumMembers|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of members in this bundleTerm.\n"
"    The number of member terminals in this bundleTerm\n"
;

static PyObject*
oaModBundleTerm_getNumMembers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBundleTerm data;
    int convert_status=PyoaModBundleTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBundleTermObject* self=(PyoaModBundleTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumMembers());
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
static char oaModBundleTerm_isNull_doc[] =
"Class: oaModBundleTerm, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaModBundleTerm_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaModBundleTerm data;
    int convert_status=PyoaModBundleTerm_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaModBundleTerm_assign_doc[] = 
"Class: oaModBundleTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaModBundleTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaModBundleTerm data;
  int convert_status=PyoaModBundleTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaModBundleTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaModBundleTerm_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaModBundleTerm_methodlist[] = {
    {"getMember",(PyCFunction)oaModBundleTerm_getMember,METH_VARARGS,oaModBundleTerm_getMember_doc},
    {"getMembers",(PyCFunction)oaModBundleTerm_getMembers,METH_VARARGS,oaModBundleTerm_getMembers_doc},
    {"getMembersIter",(PyCFunction)oaModBundleTerm_getMembersIter,METH_VARARGS,oaModBundleTerm_getMembersIter_doc},
    {"getName",(PyCFunction)oaModBundleTerm_getName,METH_VARARGS,oaModBundleTerm_getName_doc},
    {"getNumMembers",(PyCFunction)oaModBundleTerm_getNumMembers,METH_VARARGS,oaModBundleTerm_getNumMembers_doc},
    {"isNull",(PyCFunction)oaModBundleTerm_tp_isNull,METH_VARARGS,oaModBundleTerm_isNull_doc},
    {"assign",(PyCFunction)oaModBundleTerm_tp_assign,METH_VARARGS,oaModBundleTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModBundleTerm_doc[] = 
"Class: oaModBundleTerm\n"
"  The oaModBundleTerm class implements a multi-bit terminal for an oaModule . It is composed of a list of scalarTerms and busTerms and repeated copies of those elements. When a bundleTerm is created, the constituent scalarTerms and busNetBits are automatically created if they do not already exist. oaModBundleTerm objects are associated with oaModNets that may be oaModBundleNets but aren't required to be. The number of bits implied by the names of the oaModBundleTerm and its oaModNet must match to be valid.\n"
"  oaModBundleTerm, oaOccBundleTerm , and oaBundleTerm each represent bundle terminals in a different hierarchy domain, where in each case the master represents a level of hierarchy in the design.\n"
"  For oaModBundleTerm, the master is an oaModule , and each module in a cellview will have a set of zero or more modBundleTerms. For oaOccBundleTerm , the master is an oaOccurrence .\n"
"  For oaBundleTerm , the master is an oaBlock , and the top block for the cellView will have a set of zero or more bundleTerms. In the typical case where all block objects are visible to the module domain, the oaModBundleTerms on the top oaModule will have corresponding oaBundleTerms on the top oaBlock . All of the oaModBundleTerms on the top module have a corresponding oaOccBundleTerm on the top oaOccurrence .\n"
"Constructors:\n"
"  Paramegers: (oaModBundleTerm)\n"
"    Calls: (const oaModBundleTerm&)\n"
"    Signature: oaModBundleTerm||cref-oaModBundleTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaModBundleTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaModBundleTerm",
    sizeof(PyoaModBundleTermObject),
    0,
    (destructor)oaModBundleTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaModBundleTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaModBundleTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaModBundleTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaModBundleTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaModTerm_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaModBundleTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModBundleTerm_static_create_doc[] = 
"Class: oaModBundleTerm, Function: create\n"
"  Paramegers: (oaModNet,oaBundleName)\n"
"    Calls: oaModBundleTerm* create(oaModNet* modNet,const oaBundleName& name)\n"
"    Signature: create|ptr-oaModBundleTerm|ptr-oaModNet,cref-oaBundleName,simple-oaTermType,\n"
"    This function adds a new oaModBundleTerm to the specified modNet. The bundle name must imply the same number of bits as the width of the modNet.\n"
"    modNet\n"
"    A pointer to the modNet to associate with the terminal; the bits of the modNet are associated with the constituent bits of the automatically created member terminals\n"
"    name\n"
"    The name of the terminal\n"
"    termType\n"
"    The type of the terminal to create\n"
"    oacCannotCreateTermWithImplicitNet\n"
"  Paramegers: (oaModNet,oaBundleName,oaTermType)\n"
"    Calls: oaModBundleTerm* create(oaModNet* modNet,const oaBundleName& name,oaTermType termType)\n"
"    Signature: create|ptr-oaModBundleTerm|ptr-oaModNet,cref-oaBundleName,simple-oaTermType,\n"
"    This function adds a new oaModBundleTerm to the specified modNet. The bundle name must imply the same number of bits as the width of the modNet.\n"
"    modNet\n"
"    A pointer to the modNet to associate with the terminal; the bits of the modNet are associated with the constituent bits of the automatically created member terminals\n"
"    name\n"
"    The name of the terminal\n"
"    termType\n"
"    The type of the terminal to create\n"
"    oacCannotCreateTermWithImplicitNet\n"
;

static PyObject*
oaModBundleTerm_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaModNet,oaBundleName)
    {
        PyParamoaModNet p1;
        PyParamoaBundleName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaModNet_Convert,&p1,
              &PyoaBundleName_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBundleTermp result= (oaModBundleTerm::create(p1.Data(),p2.Data()));
            return PyoaModBundleTerm_FromoaModBundleTerm(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModNet,oaBundleName,oaTermType)
    {
        PyParamoaModNet p1;
        PyParamoaBundleName p2;
        PyParamoaTermType p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaModNet_Convert,&p1,
              &PyoaBundleName_Convert,&p2,
              &PyoaTermType_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBundleTermp result= (oaModBundleTerm::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaModBundleTerm_FromoaModBundleTerm(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaModBundleTerm, function: create, Choices are:\n"
        "    (oaModNet,oaBundleName)\n"
        "    (oaModNet,oaBundleName,oaTermType)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBundleTerm_static_find_doc[] = 
"Class: oaModBundleTerm, Function: find\n"
"  Paramegers: (oaModule,oaBundleName)\n"
"    Calls: oaModBundleTerm* find(const oaModule* module,const oaBundleName& name)\n"
"    Signature: find|ptr-oaModBundleTerm|cptr-oaModule,cref-oaBundleName,\n"
"    This function searches the specified module for a bundleTerm with the given name . The bundleTerm is returned if it exists. Otherwise, NULL is returned.\n"
"    module\n"
"    The module to search\n"
"    name\n"
"    The name of the terminal\n"
"    A pointer to an oaModBundleTerm if found; otherwise, NULL is returned\n"
;

static PyObject*
oaModBundleTerm_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModule p1;
    PyParamoaBundleName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaModule_Convert,&p1,
          &PyoaBundleName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaModBundleTermp result= (oaModBundleTerm::find(p1.Data(),p2.Data()));
        return PyoaModBundleTerm_FromoaModBundleTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBundleTerm_static_isValidName_doc[] = 
"Class: oaModBundleTerm, Function: isValidName\n"
"  Paramegers: (oaModule,oaModNet,oaBundleName)\n"
"    Calls: oaBoolean isValidName(const oaModule* module,const oaModNet* net,const oaBundleName& name)\n"
"    Signature: isValidName|simple-oaBoolean|cptr-oaModule,cptr-oaModNet,cref-oaBundleName,\n"
"    This function returns a boolean value that indicates if the specified name is valid for a new oaModBundleTerm object associated with the specified net.\n"
"    module\n"
"    The module in which to create the new bundle terminal\n"
"    net\n"
"    The net with which to associate the new bundle terminal\n"
"    name\n"
"    The name of the new bundle terminal\n"
;

static PyObject*
oaModBundleTerm_static_isValidName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModule p1;
    PyParamoaModNet p2;
    PyParamoaBundleName p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaModule_Convert,&p1,
          &PyoaModNet_Convert,&p2,
          &PyoaBundleName_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        oaBoolean result= (oaModBundleTerm::isValidName(p1.Data(),p2.Data(),p3.Data()));
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
static PyMethodDef oaModBundleTerm_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaModBundleTerm_static_create,METH_VARARGS,oaModBundleTerm_static_create_doc},
    {"static_find",(PyCFunction)oaModBundleTerm_static_find,METH_VARARGS,oaModBundleTerm_static_find_doc},
    {"static_isValidName",(PyCFunction)oaModBundleTerm_static_isValidName,METH_VARARGS,oaModBundleTerm_static_isValidName_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaModBundleTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaModBundleTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaModBundleTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaModBundleTerm",
           (PyObject*)(&PyoaModBundleTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaModBundleTerm\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaModBundleTerm_Type.tp_dict;
    for(method=oaModBundleTerm_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaModBusNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaModBusNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaModBusNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaModBusNetObject* self = (PyoaModBusNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaModBusNet)
    {
        PyParamoaModBusNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaModBusNet_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaModBusNet, Choices are:\n"
        "    (oaModBusNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaModBusNet_tp_dealloc(PyoaModBusNetObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaModBusNet_tp_repr(PyObject *ob)
{
    PyParamoaModBusNet value;
    int convert_status=PyoaModBusNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaModBusNet::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[33];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaModBusNet::");
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
oaModBusNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaModBusNet v1;
    PyParamoaModBusNet v2;
    int convert_status1=PyoaModBusNet_Convert(ob1,&v1);
    int convert_status2=PyoaModBusNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaModBusNet_Convert(PyObject* ob,PyParamoaModBusNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaModBusNet_Check(ob)) {
        result->SetData( (oaModBusNet**) ((PyoaModBusNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaModBusNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaModBusNet_FromoaModBusNet(oaModBusNet** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaModBusNet* data=*value;
        PyObject* bself = PyoaModBusNet_Type.tp_alloc(&PyoaModBusNet_Type,0);
        if (bself == NULL) return bself;
        PyoaModBusNetObject* self = (PyoaModBusNetObject*)bself;
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
PyObject* PyoaModBusNet_FromoaModBusNet(oaModBusNet* data)
{
    if (data) {
       PyObject* bself = PyoaModBusNet_Type.tp_alloc(&PyoaModBusNet_Type,0);
       if (bself == NULL) return bself;
       PyoaModBusNetObject* self = (PyoaModBusNetObject*)bself;
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
static char oaModBusNet_getDef_doc[] = 
"Class: oaModBusNet, Function: getDef\n"
"  Paramegers: ()\n"
"    Calls: oaModBusNetDef* getDef() const\n"
"    Signature: getDef|ptr-oaModBusNetDef|\n"
"    BrowseData: 1\n"
"    This function returns the busNetDef for this busNet.\n"
"    A pointer to an oaModBusNetDef\n"
;

static PyObject*
oaModBusNet_getDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNet data;
    int convert_status=PyoaModBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetObject* self=(PyoaModBusNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusNetDefp result= (data.DataCall()->getDef());
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
static char oaModBusNet_getName_doc[] = 
"Class: oaModBusNet, Function: getName\n"
"  Paramegers: (oaVectorName)\n"
"    Calls: void getName(oaVectorName& name) const\n"
"    Signature: getName|void-void|ref-oaVectorName,\n"
"    BrowseData: 0,oaVectorName\n"
"    This function returns the name of this modBusNet.\n"
"    name\n"
"    The name of the modBusNet to return\n"
"  Paramegers: (oaName)\n"
"    Calls: void getName(oaName& name) const\n"
"    Signature: getName|void-void|ref-oaName,\n"
"    BrowseData: 0,oaName\n"
"    This function returns the name of this net in the name argument.\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getName(const oaNameSpace& ns,oaString& name) const\n"
"    Signature: getName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the name of this net in the specified nameSpace in the specified name string.\n"
;

static PyObject*
oaModBusNet_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNet data;
    int convert_status=PyoaModBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetObject* self=(PyoaModBusNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaVectorName)
    {
        PyParamoaVectorName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaVectorName_Convert,&p1)) {
            data.DataCall()->getName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaName)
    {
        PyParamoaName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaName_Convert,&p1)) {
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
        "No Arg-Matching Function found for class: oaModBusNet, function: getName, Choices are:\n"
        "    (oaVectorName)\n"
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
static char oaModBusNet_getStart_doc[] = 
"Class: oaModBusNet, Function: getStart\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getStart() const\n"
"    Signature: getStart|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the starting index for this busNet.\n"
"    The starting index of this busNet\n"
;

static PyObject*
oaModBusNet_getStart(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNet data;
    int convert_status=PyoaModBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetObject* self=(PyoaModBusNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getStart());
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
static char oaModBusNet_getStep_doc[] = 
"Class: oaModBusNet, Function: getStep\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getStep() const\n"
"    Signature: getStep|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the step value for this busNet.\n"
"    The step value for this busNet\n"
;

static PyObject*
oaModBusNet_getStep(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNet data;
    int convert_status=PyoaModBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetObject* self=(PyoaModBusNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getStep());
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
static char oaModBusNet_getStop_doc[] = 
"Class: oaModBusNet, Function: getStop\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getStop() const\n"
"    Signature: getStop|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the ending index for this busNet.\n"
"    The ending index for this busNet\n"
;

static PyObject*
oaModBusNet_getStop(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNet data;
    int convert_status=PyoaModBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetObject* self=(PyoaModBusNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getStop());
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
static char oaModBusNet_setBaseName_doc[] = 
"Class: oaModBusNet, Function: setBaseName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void setBaseName(const oaScalarName& name)\n"
"    Signature: setBaseName|void-void|cref-oaScalarName,\n"
"    This function sets the base name of this oaModBusNet object. The name is also updated for each occurrence the net appears in.\n"
"    baseName\n"
"    The new base name to be set for this net.\n"
"    oacBusNetBaseNameMatchesScalarName\n"
"    oacBusNetNameMatchesAutoName\n"
"    oacCannotRenameToImplicitBusNet\n"
"    oacCannotSetNameOfImplicitNet\n"
"    oacCannotSetNameOfNetInBundleNet\n"
"    oacImplicitModuleNetExists\n"
"    oacImplicitBlockNetExists\n"
"    oacInvalidHierNetName\n"
"    oacNetExists\n"
"    oacNetSetBaseNameConflictsInTerms\n"
"    oacNetSetBaseNameConflictsInInstTerms\n"
;

static PyObject*
oaModBusNet_setBaseName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNet data;
    int convert_status=PyoaModBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetObject* self=(PyoaModBusNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaScalarName p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaScalarName_Convert,&p1)) {
        data.DataCall()->setBaseName(p1.Data());
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
static char oaModBusNet_setRange_doc[] = 
"Class: oaModBusNet, Function: setRange\n"
"  Paramegers: (oaUInt4,oaUInt4)\n"
"    Calls: void setRange(oaUInt4 start,oaUInt4 stop)\n"
"    Signature: setRange|void-void|simple-oaUInt4,simple-oaUInt4,\n"
"    This function changes the vector range for this modBusNet. The new number of bits implied by the specified start and stop bits must match the current number of bits. This restriction is necessary so that any terminals or instance terminals that are associated with this busNet are not affected.\n"
"    start\n"
"    The starting index of the net\n"
"    stop\n"
"    The stopping index of the net\n"
"    oacCannotRenameToImplicitBusNet\n"
"    oacCannotSetRangeOfImplicitBus\n"
"    oacCannotSetRangeOfBusInBundleNet\n"
"    oacInvalidBusStartStopRange\n"
"    oacNetExists\n"
"    oacNetSetRangeConflictsWithOtherNets\n"
;

static PyObject*
oaModBusNet_setRange(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNet data;
    int convert_status=PyoaModBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetObject* self=(PyoaModBusNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    PyParamoaUInt4 p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaUInt4_Convert,&p1,
          &PyoaUInt4_Convert,&p2)) {
        data.DataCall()->setRange(p1.Data(),p2.Data());
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
static char oaModBusNet_isNull_doc[] =
"Class: oaModBusNet, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaModBusNet_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaModBusNet data;
    int convert_status=PyoaModBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaModBusNet_assign_doc[] = 
"Class: oaModBusNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaModBusNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaModBusNet data;
  int convert_status=PyoaModBusNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaModBusNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaModBusNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaModBusNet_methodlist[] = {
    {"getDef",(PyCFunction)oaModBusNet_getDef,METH_VARARGS,oaModBusNet_getDef_doc},
    {"getName",(PyCFunction)oaModBusNet_getName,METH_VARARGS,oaModBusNet_getName_doc},
    {"getStart",(PyCFunction)oaModBusNet_getStart,METH_VARARGS,oaModBusNet_getStart_doc},
    {"getStep",(PyCFunction)oaModBusNet_getStep,METH_VARARGS,oaModBusNet_getStep_doc},
    {"getStop",(PyCFunction)oaModBusNet_getStop,METH_VARARGS,oaModBusNet_getStop_doc},
    {"setBaseName",(PyCFunction)oaModBusNet_setBaseName,METH_VARARGS,oaModBusNet_setBaseName_doc},
    {"setRange",(PyCFunction)oaModBusNet_setRange,METH_VARARGS,oaModBusNet_setRange_doc},
    {"isNull",(PyCFunction)oaModBusNet_tp_isNull,METH_VARARGS,oaModBusNet_isNull_doc},
    {"assign",(PyCFunction)oaModBusNet_tp_assign,METH_VARARGS,oaModBusNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModBusNet_doc[] = 
"Class: oaModBusNet\n"
"  The oaModBusNet class implements a net in the module domain that represents one or more bits that are associated by a common base name and vector-range specification. An oaModBusNet object has a corresponding oaModBusNetDef object that manages all oaModBusNet objects that share the same base name.\n"
"  oaModBusNet, oaOccBusNet , and oaBusNet each represent bus nets on a different kind of master, where in each case the master represents a level of hierarchy in the design.\n"
"  For oaModBusNet, the master is an oaModule , and each module in a design will have a set of zero or more modBusNets. For oaOccBusNet , the master is an oaOccurrence .\n"
"  For oaBusNet , the master is an oaBlock , and the top block for the design will have a set of zero or more busNets. Typically, many of the oaBusNets on the top oaBlock have a corresponding oaModBusNet on the top oaModule . All of the oaBusNets on the top oaBlock have a corresponding oaOccBusNet on the top oaOccurrence .\n"
"  When oaBusNet objects are created in the block domain, the corresponding oaModBusNet objects are automatically created on the top oaModule .\n"
"Constructors:\n"
"  Paramegers: (oaModBusNet)\n"
"    Calls: (const oaModBusNet&)\n"
"    Signature: oaModBusNet||cref-oaModBusNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaModBusNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaModBusNet",
    sizeof(PyoaModBusNetObject),
    0,
    (destructor)oaModBusNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaModBusNet_tp_compare,	/* tp_compare */
    (reprfunc)oaModBusNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaModBusNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaModBusNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaModNet_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaModBusNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModBusNet_static_create_doc[] = 
"Class: oaModBusNet, Function: create\n"
"  Paramegers: (oaModule,oaScalarName,oaUInt4,oaUInt4,oaUInt4)\n"
"    Calls: oaModBusNet* create(oaModule* module,const oaScalarName& baseName,oaUInt4 start,oaUInt4 stop,oaUInt4 step)\n"
"    Signature: create|ptr-oaModBusNet|ptr-oaModule,cref-oaScalarName,simple-oaUInt4,simple-oaUInt4,simple-oaUInt4,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates a single-bit or multi-bit busNet with the specified attributes. The specified baseName and start , stop , and step indices are first checked to verify they are legal and do not specify an existing busNet.\n"
"    module\n"
"    The module in which to create the busNet\n"
"    baseName\n"
"    The base name for the busNet\n"
"    start\n"
"    The starting index of the busNet\n"
"    stop\n"
"    The stopping index of the busNet\n"
"    step\n"
"    The index increment value from start to step; step should be greater than zero\n"
"    sigType\n"
"    The signal type of the busNet\n"
"    isGlobal\n"
"    Specifies if this is a global busNet\n"
"    A pointer to the oaModBusNet created\n"
"    oacBusNetNameMatchesAutoName\n"
"    oacInvalidVectorValue\n"
"    oacBusNetBaseNameMatchesScalarName\n"
"    oacNetExists\n"
"    oacImplicitModuleNetExists\n"
"    oacImplicitBlockNetExists\n"
"    oacInvalidHierNetName\n"
"  Paramegers: (oaModule,oaScalarName,oaUInt4,oaUInt4,oaUInt4,oaSigType)\n"
"    Calls: oaModBusNet* create(oaModule* module,const oaScalarName& baseName,oaUInt4 start,oaUInt4 stop,oaUInt4 step,oaSigType type)\n"
"    Signature: create|ptr-oaModBusNet|ptr-oaModule,cref-oaScalarName,simple-oaUInt4,simple-oaUInt4,simple-oaUInt4,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates a single-bit or multi-bit busNet with the specified attributes. The specified baseName and start , stop , and step indices are first checked to verify they are legal and do not specify an existing busNet.\n"
"    module\n"
"    The module in which to create the busNet\n"
"    baseName\n"
"    The base name for the busNet\n"
"    start\n"
"    The starting index of the busNet\n"
"    stop\n"
"    The stopping index of the busNet\n"
"    step\n"
"    The index increment value from start to step; step should be greater than zero\n"
"    sigType\n"
"    The signal type of the busNet\n"
"    isGlobal\n"
"    Specifies if this is a global busNet\n"
"    A pointer to the oaModBusNet created\n"
"    oacBusNetNameMatchesAutoName\n"
"    oacInvalidVectorValue\n"
"    oacBusNetBaseNameMatchesScalarName\n"
"    oacNetExists\n"
"    oacImplicitModuleNetExists\n"
"    oacImplicitBlockNetExists\n"
"    oacInvalidHierNetName\n"
"  Paramegers: (oaModule,oaScalarName,oaUInt4,oaUInt4,oaUInt4,oaSigType,oaBoolean)\n"
"    Calls: oaModBusNet* create(oaModule* module,const oaScalarName& baseName,oaUInt4 start,oaUInt4 stop,oaUInt4 step,oaSigType type,oaBoolean isGlobal)\n"
"    Signature: create|ptr-oaModBusNet|ptr-oaModule,cref-oaScalarName,simple-oaUInt4,simple-oaUInt4,simple-oaUInt4,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates a single-bit or multi-bit busNet with the specified attributes. The specified baseName and start , stop , and step indices are first checked to verify they are legal and do not specify an existing busNet.\n"
"    module\n"
"    The module in which to create the busNet\n"
"    baseName\n"
"    The base name for the busNet\n"
"    start\n"
"    The starting index of the busNet\n"
"    stop\n"
"    The stopping index of the busNet\n"
"    step\n"
"    The index increment value from start to step; step should be greater than zero\n"
"    sigType\n"
"    The signal type of the busNet\n"
"    isGlobal\n"
"    Specifies if this is a global busNet\n"
"    A pointer to the oaModBusNet created\n"
"    oacBusNetNameMatchesAutoName\n"
"    oacInvalidVectorValue\n"
"    oacBusNetBaseNameMatchesScalarName\n"
"    oacNetExists\n"
"    oacImplicitModuleNetExists\n"
"    oacImplicitBlockNetExists\n"
"    oacInvalidHierNetName\n"
"  Paramegers: (oaModule,oaVectorName)\n"
"    Calls: oaModBusNet* create(oaModule* module,const oaVectorName& name)\n"
"    Signature: create|ptr-oaModBusNet|ptr-oaModule,cref-oaVectorName,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates a busNet with the specified attributes using an oaVectorName as input and creating a multi-bit busNet. (Use one of the other create() API functions to create single-bit nets.)\n"
"    module\n"
"    The module in which to create the busNet\n"
"    name\n"
"    The base name, start, stop, and step values to use to create the busNet\n"
"    sigType\n"
"    The signal type of the busNet\n"
"    isGlobal\n"
"    Specifies if this is a global busNet\n"
"    A pointer to an oaModBusNet\n"
"    oacBusNetNameMatchesAutoName\n"
"    oacInvalidVectorValue\n"
"    oacBusNetBaseNameMatchesScalarName\n"
"    oacNetExists\n"
"    oacImplicitModuleNetExists\n"
"    oacImplicitBlockNetExists\n"
"    oacInvalidHierNetName\n"
"  Paramegers: (oaModule,oaVectorName,oaSigType)\n"
"    Calls: oaModBusNet* create(oaModule* module,const oaVectorName& name,oaSigType type)\n"
"    Signature: create|ptr-oaModBusNet|ptr-oaModule,cref-oaVectorName,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates a busNet with the specified attributes using an oaVectorName as input and creating a multi-bit busNet. (Use one of the other create() API functions to create single-bit nets.)\n"
"    module\n"
"    The module in which to create the busNet\n"
"    name\n"
"    The base name, start, stop, and step values to use to create the busNet\n"
"    sigType\n"
"    The signal type of the busNet\n"
"    isGlobal\n"
"    Specifies if this is a global busNet\n"
"    A pointer to an oaModBusNet\n"
"    oacBusNetNameMatchesAutoName\n"
"    oacInvalidVectorValue\n"
"    oacBusNetBaseNameMatchesScalarName\n"
"    oacNetExists\n"
"    oacImplicitModuleNetExists\n"
"    oacImplicitBlockNetExists\n"
"    oacInvalidHierNetName\n"
"  Paramegers: (oaModule,oaVectorName,oaSigType,oaBoolean)\n"
"    Calls: oaModBusNet* create(oaModule* module,const oaVectorName& name,oaSigType type,oaBoolean isGlobal)\n"
"    Signature: create|ptr-oaModBusNet|ptr-oaModule,cref-oaVectorName,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates a busNet with the specified attributes using an oaVectorName as input and creating a multi-bit busNet. (Use one of the other create() API functions to create single-bit nets.)\n"
"    module\n"
"    The module in which to create the busNet\n"
"    name\n"
"    The base name, start, stop, and step values to use to create the busNet\n"
"    sigType\n"
"    The signal type of the busNet\n"
"    isGlobal\n"
"    Specifies if this is a global busNet\n"
"    A pointer to an oaModBusNet\n"
"    oacBusNetNameMatchesAutoName\n"
"    oacInvalidVectorValue\n"
"    oacBusNetBaseNameMatchesScalarName\n"
"    oacNetExists\n"
"    oacImplicitModuleNetExists\n"
"    oacImplicitBlockNetExists\n"
"    oacInvalidHierNetName\n"
"  Paramegers: (oaModule,oaVectorBitName)\n"
"    Calls: oaModBusNet* create(oaModule* module,const oaVectorBitName& name)\n"
"    Signature: create|ptr-oaModBusNet|ptr-oaModule,cref-oaVectorBitName,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates a busNet with the specified attributes, using an oaVectorBitName as input and creating a single-bit busNet.\n"
"    module\n"
"    The module in which to create the busNet\n"
"    name\n"
"    The base name and bit index to use to create the busNet\n"
"    sigType\n"
"    The signal type of the busNet\n"
"    isGlobal\n"
"    Specifies if this is a global net\n"
"    A pointer to an oaModBusNet\n"
"    oacBusNetNameMatchesAutoName\n"
"    oacInvalidVectorValue\n"
"    oacBusNetBaseNameMatchesScalarName\n"
"    oacNetExists\n"
"    oacImplicitModuleNetExists\n"
"    oacImplicitBlockNetExists\n"
"    oacInvalidHierNetName\n"
"  Paramegers: (oaModule,oaVectorBitName,oaSigType)\n"
"    Calls: oaModBusNet* create(oaModule* module,const oaVectorBitName& name,oaSigType type)\n"
"    Signature: create|ptr-oaModBusNet|ptr-oaModule,cref-oaVectorBitName,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates a busNet with the specified attributes, using an oaVectorBitName as input and creating a single-bit busNet.\n"
"    module\n"
"    The module in which to create the busNet\n"
"    name\n"
"    The base name and bit index to use to create the busNet\n"
"    sigType\n"
"    The signal type of the busNet\n"
"    isGlobal\n"
"    Specifies if this is a global net\n"
"    A pointer to an oaModBusNet\n"
"    oacBusNetNameMatchesAutoName\n"
"    oacInvalidVectorValue\n"
"    oacBusNetBaseNameMatchesScalarName\n"
"    oacNetExists\n"
"    oacImplicitModuleNetExists\n"
"    oacImplicitBlockNetExists\n"
"    oacInvalidHierNetName\n"
"  Paramegers: (oaModule,oaVectorBitName,oaSigType,oaBoolean)\n"
"    Calls: oaModBusNet* create(oaModule* module,const oaVectorBitName& name,oaSigType type,oaBoolean isGlobal)\n"
"    Signature: create|ptr-oaModBusNet|ptr-oaModule,cref-oaVectorBitName,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates a busNet with the specified attributes, using an oaVectorBitName as input and creating a single-bit busNet.\n"
"    module\n"
"    The module in which to create the busNet\n"
"    name\n"
"    The base name and bit index to use to create the busNet\n"
"    sigType\n"
"    The signal type of the busNet\n"
"    isGlobal\n"
"    Specifies if this is a global net\n"
"    A pointer to an oaModBusNet\n"
"    oacBusNetNameMatchesAutoName\n"
"    oacInvalidVectorValue\n"
"    oacBusNetBaseNameMatchesScalarName\n"
"    oacNetExists\n"
"    oacImplicitModuleNetExists\n"
"    oacImplicitBlockNetExists\n"
"    oacInvalidHierNetName\n"
;

static PyObject*
oaModBusNet_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaModule,oaScalarName,oaUInt4,oaUInt4,oaUInt4)
    {
        PyParamoaModule p1;
        PyParamoaScalarName p2;
        PyParamoaUInt4 p3;
        PyParamoaUInt4 p4;
        PyParamoaUInt4 p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaUInt4_Convert,&p3,
              &PyoaUInt4_Convert,&p4,
              &PyoaUInt4_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusNetp result= (oaModBusNet::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaModBusNet_FromoaModBusNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModule,oaScalarName,oaUInt4,oaUInt4,oaUInt4,oaSigType)
    {
        PyParamoaModule p1;
        PyParamoaScalarName p2;
        PyParamoaUInt4 p3;
        PyParamoaUInt4 p4;
        PyParamoaUInt4 p5;
        PyParamoaSigType p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaUInt4_Convert,&p3,
              &PyoaUInt4_Convert,&p4,
              &PyoaUInt4_Convert,&p5,
              &PyoaSigType_Convert,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusNetp result= (oaModBusNet::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data()));
            return PyoaModBusNet_FromoaModBusNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModule,oaScalarName,oaUInt4,oaUInt4,oaUInt4,oaSigType,oaBoolean)
    {
        PyParamoaModule p1;
        PyParamoaScalarName p2;
        PyParamoaUInt4 p3;
        PyParamoaUInt4 p4;
        PyParamoaUInt4 p5;
        PyParamoaSigType p6;
        PyParamoaBoolean p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaUInt4_Convert,&p3,
              &PyoaUInt4_Convert,&p4,
              &PyoaUInt4_Convert,&p5,
              &PyoaSigType_Convert,&p6,
              &PyoaBoolean_Convert,&p7)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusNetp result= (oaModBusNet::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data()));
            return PyoaModBusNet_FromoaModBusNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModule,oaVectorName)
    {
        PyParamoaModule p1;
        PyParamoaVectorName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaVectorName_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusNetp result= (oaModBusNet::create(p1.Data(),p2.Data()));
            return PyoaModBusNet_FromoaModBusNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModule,oaVectorName,oaSigType)
    {
        PyParamoaModule p1;
        PyParamoaVectorName p2;
        PyParamoaSigType p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaVectorName_Convert,&p2,
              &PyoaSigType_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusNetp result= (oaModBusNet::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaModBusNet_FromoaModBusNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModule,oaVectorName,oaSigType,oaBoolean)
    {
        PyParamoaModule p1;
        PyParamoaVectorName p2;
        PyParamoaSigType p3;
        PyParamoaBoolean p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaVectorName_Convert,&p2,
              &PyoaSigType_Convert,&p3,
              &PyoaBoolean_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusNetp result= (oaModBusNet::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaModBusNet_FromoaModBusNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModule,oaVectorBitName)
    {
        PyParamoaModule p1;
        PyParamoaVectorBitName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaVectorBitName_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusNetp result= (oaModBusNet::create(p1.Data(),p2.Data()));
            return PyoaModBusNet_FromoaModBusNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModule,oaVectorBitName,oaSigType)
    {
        PyParamoaModule p1;
        PyParamoaVectorBitName p2;
        PyParamoaSigType p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaVectorBitName_Convert,&p2,
              &PyoaSigType_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusNetp result= (oaModBusNet::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaModBusNet_FromoaModBusNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModule,oaVectorBitName,oaSigType,oaBoolean)
    {
        PyParamoaModule p1;
        PyParamoaVectorBitName p2;
        PyParamoaSigType p3;
        PyParamoaBoolean p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaVectorBitName_Convert,&p2,
              &PyoaSigType_Convert,&p3,
              &PyoaBoolean_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusNetp result= (oaModBusNet::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaModBusNet_FromoaModBusNet(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaModBusNet, function: create, Choices are:\n"
        "    (oaModule,oaScalarName,oaUInt4,oaUInt4,oaUInt4)\n"
        "    (oaModule,oaScalarName,oaUInt4,oaUInt4,oaUInt4,oaSigType)\n"
        "    (oaModule,oaScalarName,oaUInt4,oaUInt4,oaUInt4,oaSigType,oaBoolean)\n"
        "    (oaModule,oaVectorName)\n"
        "    (oaModule,oaVectorName,oaSigType)\n"
        "    (oaModule,oaVectorName,oaSigType,oaBoolean)\n"
        "    (oaModule,oaVectorBitName)\n"
        "    (oaModule,oaVectorBitName,oaSigType)\n"
        "    (oaModule,oaVectorBitName,oaSigType,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBusNet_static_find_doc[] = 
"Class: oaModBusNet, Function: find\n"
"  Paramegers: (oaModule,oaScalarName,oaUInt4,oaUInt4,oaUInt4)\n"
"    Calls: oaModBusNet* find(const oaModule* module,const oaScalarName& baseName,oaUInt4 start,oaUInt4 stop,oaUInt4 step)\n"
"    Signature: find|ptr-oaModBusNet|cptr-oaModule,cref-oaScalarName,simple-oaUInt4,simple-oaUInt4,simple-oaUInt4,\n"
"    This function searches the specified module for a busNet with the specified baseName and start, stop, step indices. The busNet is returned if found. Otherwise, NULL is returned.\n"
"    module\n"
"    The module in which to find the busNet\n"
"    baseName\n"
"    The base name for the net\n"
"    start\n"
"    The starting index of the net\n"
"    stop\n"
"    The stopping index of the net\n"
"    step\n"
"    The index increment value from start to step; step should be greater than zero\n"
"    A pointer to the oaModBusNet\n"
;

static PyObject*
oaModBusNet_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModule p1;
    PyParamoaScalarName p2;
    PyParamoaUInt4 p3;
    PyParamoaUInt4 p4;
    PyParamoaUInt4 p5;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&",
          &PyoaModule_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaUInt4_Convert,&p3,
          &PyoaUInt4_Convert,&p4,
          &PyoaUInt4_Convert,&p5)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaModBusNetp result= (oaModBusNet::find(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
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
static char oaModBusNet_static_isValidName_doc[] = 
"Class: oaModBusNet, Function: isValidName\n"
"  Paramegers: (oaModule,oaScalarName,oaUInt4,oaUInt4,oaUInt4)\n"
"    Calls: oaBoolean isValidName(const oaModule* module,const oaScalarName& baseName,oaUInt4 start,oaUInt4 stop,oaUInt4 step)\n"
"    Signature: isValidName|simple-oaBoolean|cptr-oaModule,cref-oaScalarName,simple-oaUInt4,simple-oaUInt4,simple-oaUInt4,\n"
"    This function returns a boolean value indicating whether the specified name is valid for a new oaModBusNet in the specified module.\n"
"    module\n"
"    The module to search\n"
"    baseName\n"
"    The base bus net name\n"
"    start\n"
"    The starting index of the net\n"
"    stop\n"
"    The stopping index of the net\n"
"    step\n"
"    The index increment value from start to step; step should be greater than zero\n"
;

static PyObject*
oaModBusNet_static_isValidName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModule p1;
    PyParamoaScalarName p2;
    PyParamoaUInt4 p3;
    PyParamoaUInt4 p4;
    PyParamoaUInt4 p5;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&",
          &PyoaModule_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaUInt4_Convert,&p3,
          &PyoaUInt4_Convert,&p4,
          &PyoaUInt4_Convert,&p5)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaBoolean result= (oaModBusNet::isValidName(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
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
static PyMethodDef oaModBusNet_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaModBusNet_static_create,METH_VARARGS,oaModBusNet_static_create_doc},
    {"static_find",(PyCFunction)oaModBusNet_static_find,METH_VARARGS,oaModBusNet_static_find_doc},
    {"static_isValidName",(PyCFunction)oaModBusNet_static_isValidName,METH_VARARGS,oaModBusNet_static_isValidName_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaModBusNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaModBusNet_Type)<0) {
      printf("** PyType_Ready failed for: oaModBusNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaModBusNet",
           (PyObject*)(&PyoaModBusNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaModBusNet\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaModBusNet_Type.tp_dict;
    for(method=oaModBusNet_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaModBusNetBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaModBusNetBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaModBusNetBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaModBusNetBitObject* self = (PyoaModBusNetBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaModBusNetBit)
    {
        PyParamoaModBusNetBit p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaModBusNetBit_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaModBusNetBit, Choices are:\n"
        "    (oaModBusNetBit)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaModBusNetBit_tp_dealloc(PyoaModBusNetBitObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaModBusNetBit_tp_repr(PyObject *ob)
{
    PyParamoaModBusNetBit value;
    int convert_status=PyoaModBusNetBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaModBusNetBit::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[36];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaModBusNetBit::");
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
oaModBusNetBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaModBusNetBit v1;
    PyParamoaModBusNetBit v2;
    int convert_status1=PyoaModBusNetBit_Convert(ob1,&v1);
    int convert_status2=PyoaModBusNetBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaModBusNetBit_Convert(PyObject* ob,PyParamoaModBusNetBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaModBusNetBit_Check(ob)) {
        result->SetData( (oaModBusNetBit**) ((PyoaModBusNetBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaModBusNetBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaModBusNetBit_FromoaModBusNetBit(oaModBusNetBit** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaModBusNetBit* data=*value;
        PyObject* bself = PyoaModBusNetBit_Type.tp_alloc(&PyoaModBusNetBit_Type,0);
        if (bself == NULL) return bself;
        PyoaModBusNetBitObject* self = (PyoaModBusNetBitObject*)bself;
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
PyObject* PyoaModBusNetBit_FromoaModBusNetBit(oaModBusNetBit* data)
{
    if (data) {
       PyObject* bself = PyoaModBusNetBit_Type.tp_alloc(&PyoaModBusNetBit_Type,0);
       if (bself == NULL) return bself;
       PyoaModBusNetBitObject* self = (PyoaModBusNetBitObject*)bself;
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
static char oaModBusNetBit_getBitIndex_doc[] = 
"Class: oaModBusNetBit, Function: getBitIndex\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getBitIndex() const\n"
"    Signature: getBitIndex|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the index for this busNetBit. Returns can include non-consecutive numbers.\n"
;

static PyObject*
oaModBusNetBit_getBitIndex(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNetBit data;
    int convert_status=PyoaModBusNetBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetBitObject* self=(PyoaModBusNetBitObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getBitIndex());
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
static char oaModBusNetBit_getDef_doc[] = 
"Class: oaModBusNetBit, Function: getDef\n"
"  Paramegers: ()\n"
"    Calls: oaModBusNetDef* getDef() const\n"
"    Signature: getDef|ptr-oaModBusNetDef|\n"
"    BrowseData: 1\n"
"    This function returns the busNetDef associated with this busNetBit.\n"
;

static PyObject*
oaModBusNetBit_getDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNetBit data;
    int convert_status=PyoaModBusNetBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetBitObject* self=(PyoaModBusNetBitObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusNetDefp result= (data.DataCall()->getDef());
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
static char oaModBusNetBit_getName_doc[] = 
"Class: oaModBusNetBit, Function: getName\n"
"  Paramegers: (oaVectorBitName)\n"
"    Calls: void getName(oaVectorBitName& name) const\n"
"    Signature: getName|void-void|ref-oaVectorBitName,\n"
"    BrowseData: 0,oaVectorBitName\n"
"    This function returns the name of this modBusNetBit.\n"
"    name\n"
"    The name of the modBusNetBit to return\n"
"  Paramegers: (oaName)\n"
"    Calls: void getName(oaName& name) const\n"
"    Signature: getName|void-void|ref-oaName,\n"
"    BrowseData: 0,oaName\n"
"    This function returns the name of this net in the name argument.\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getName(const oaNameSpace& ns,oaString& name) const\n"
"    Signature: getName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the name of this net in the specified nameSpace in the specified name string.\n"
;

static PyObject*
oaModBusNetBit_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNetBit data;
    int convert_status=PyoaModBusNetBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetBitObject* self=(PyoaModBusNetBitObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaVectorBitName)
    {
        PyParamoaVectorBitName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaVectorBitName_Convert,&p1)) {
            data.DataCall()->getName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaName)
    {
        PyParamoaName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaName_Convert,&p1)) {
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
        "No Arg-Matching Function found for class: oaModBusNetBit, function: getName, Choices are:\n"
        "    (oaVectorBitName)\n"
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
static char oaModBusNetBit_setName_doc[] = 
"Class: oaModBusNetBit, Function: setName\n"
"  Paramegers: (oaScalarName,oaUInt4)\n"
"    Calls: void setName(const oaScalarName& baseName,oaUInt4 bitIndex)\n"
"    Signature: setName|void-void|cref-oaScalarName,simple-oaUInt4,\n"
"    This function changes the name of this busNetBit to that implied by the given baseName and bitIndex .\n"
"    baseName\n"
"    The new base name for this net\n"
"    bitIndex\n"
"    The new bit index for this net\n"
"    oacCannotSetNameOfImplicitNet\n"
"    oacCannotSetNameOfNetInBundleNet\n"
"    oacBusNetBaseNameMatchesScalarName\n"
"    oacNetExists\n"
;

static PyObject*
oaModBusNetBit_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNetBit data;
    int convert_status=PyoaModBusNetBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetBitObject* self=(PyoaModBusNetBitObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaScalarName p1;
    PyParamoaUInt4 p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaScalarName_Convert,&p1,
          &PyoaUInt4_Convert,&p2)) {
        data.DataCall()->setName(p1.Data(),p2.Data());
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
static char oaModBusNetBit_isNull_doc[] =
"Class: oaModBusNetBit, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaModBusNetBit_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaModBusNetBit data;
    int convert_status=PyoaModBusNetBit_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaModBusNetBit_assign_doc[] = 
"Class: oaModBusNetBit, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaModBusNetBit_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaModBusNetBit data;
  int convert_status=PyoaModBusNetBit_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaModBusNetBit p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaModBusNetBit_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaModBusNetBit_methodlist[] = {
    {"getBitIndex",(PyCFunction)oaModBusNetBit_getBitIndex,METH_VARARGS,oaModBusNetBit_getBitIndex_doc},
    {"getDef",(PyCFunction)oaModBusNetBit_getDef,METH_VARARGS,oaModBusNetBit_getDef_doc},
    {"getName",(PyCFunction)oaModBusNetBit_getName,METH_VARARGS,oaModBusNetBit_getName_doc},
    {"setName",(PyCFunction)oaModBusNetBit_setName,METH_VARARGS,oaModBusNetBit_setName_doc},
    {"isNull",(PyCFunction)oaModBusNetBit_tp_isNull,METH_VARARGS,oaModBusNetBit_isNull_doc},
    {"assign",(PyCFunction)oaModBusNetBit_tp_assign,METH_VARARGS,oaModBusNetBit_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModBusNetBit_doc[] = 
"Class: oaModBusNetBit\n"
"  The oaModBusNetBit class implements an oaModBitNet that represents a single bit of an oaModBusNet which is a busNet in the module domain. When a busNet is created, a corresponding set of busNetBits is automatically created. When the busNet is destroyed, the automatically created busNetBits are also destroyed. An implicitly created busNetBit cannot be used to connect to terminals or instTerms.\n"
"  An oaModBusNetBit can be explicitly created and used in other operations like creating terminals or instTerms. An explicitly created busNetBit must be explicitly destroyed.\n"
"  oaModBusNetBit, oaOccBusNetmBit, and oaBusNetBit each represent a bit of a busNet on a different kind of master, where in each case the master represents a level of hierarchy in the design.\n"
"  For oaModBusNetBit, the master is a module, and each module in a design will have a set of zero or more oaModBusNetBits. For oaOccBusNetBit , the master is an oaOccurrence .\n"
"  For oaBusNet , the master is an oaBlock , and the top block for the design will have a set of zero or more modBusNetBits. Typically, many of the oaBusNetBits on the top oaBlock have a corresponding oaModBusNetBit on the top oaModule . All of the oaBusNetBits on the top oaBlock have a corresponding oaOccBusNetBit on the top oaOccurrence .\n"
"  When oaBusNetBit objects are created in the block domain, the corresponding oaModBusNetBit objects are automatically created on the top oaModule .\n"
"Constructors:\n"
"  Paramegers: (oaModBusNetBit)\n"
"    Calls: (const oaModBusNetBit&)\n"
"    Signature: oaModBusNetBit||cref-oaModBusNetBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaModBusNetBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaModBusNetBit",
    sizeof(PyoaModBusNetBitObject),
    0,
    (destructor)oaModBusNetBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaModBusNetBit_tp_compare,	/* tp_compare */
    (reprfunc)oaModBusNetBit_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaModBusNetBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaModBusNetBit_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaModBitNet_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaModBusNetBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModBusNetBit_static_create_doc[] = 
"Class: oaModBusNetBit, Function: create\n"
"  Paramegers: (oaModule,oaScalarName,oaUInt4)\n"
"    Calls: oaModBusNetBit* create(oaModule* module,const oaScalarName& baseName,oaUInt4 bitIndex)\n"
"    Signature: create|ptr-oaModBusNetBit|ptr-oaModule,cref-oaScalarName,simple-oaUInt4,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates a busNetBit with the specified baseName and bitIndex in the given module .\n"
"    module\n"
"    The module to create the net in\n"
"    baseName\n"
"    The base name to give the net\n"
"    bitIndex\n"
"    The bit index to give the net\n"
"    sigType\n"
"    The signal type of the busNetBit\n"
"    isGlobal\n"
"    Specifies if this is a global net\n"
"    oacBusNetNameMatchesAutoName\n"
"    oacBusNetBaseNameMatchesScalarName\n"
"    oacNetExists\n"
"    oacImplicitModuleNetExists\n"
"    oacImplicitBlockNetExists\n"
"    oacInvalidHierNetName\n"
"  Paramegers: (oaModule,oaScalarName,oaUInt4,oaSigType)\n"
"    Calls: oaModBusNetBit* create(oaModule* module,const oaScalarName& baseName,oaUInt4 bitIndex,oaSigType type)\n"
"    Signature: create|ptr-oaModBusNetBit|ptr-oaModule,cref-oaScalarName,simple-oaUInt4,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates a busNetBit with the specified baseName and bitIndex in the given module .\n"
"    module\n"
"    The module to create the net in\n"
"    baseName\n"
"    The base name to give the net\n"
"    bitIndex\n"
"    The bit index to give the net\n"
"    sigType\n"
"    The signal type of the busNetBit\n"
"    isGlobal\n"
"    Specifies if this is a global net\n"
"    oacBusNetNameMatchesAutoName\n"
"    oacBusNetBaseNameMatchesScalarName\n"
"    oacNetExists\n"
"    oacImplicitModuleNetExists\n"
"    oacImplicitBlockNetExists\n"
"    oacInvalidHierNetName\n"
"  Paramegers: (oaModule,oaScalarName,oaUInt4,oaSigType,oaBoolean)\n"
"    Calls: oaModBusNetBit* create(oaModule* module,const oaScalarName& baseName,oaUInt4 bitIndex,oaSigType type,oaBoolean isGlobal)\n"
"    Signature: create|ptr-oaModBusNetBit|ptr-oaModule,cref-oaScalarName,simple-oaUInt4,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates a busNetBit with the specified baseName and bitIndex in the given module .\n"
"    module\n"
"    The module to create the net in\n"
"    baseName\n"
"    The base name to give the net\n"
"    bitIndex\n"
"    The bit index to give the net\n"
"    sigType\n"
"    The signal type of the busNetBit\n"
"    isGlobal\n"
"    Specifies if this is a global net\n"
"    oacBusNetNameMatchesAutoName\n"
"    oacBusNetBaseNameMatchesScalarName\n"
"    oacNetExists\n"
"    oacImplicitModuleNetExists\n"
"    oacImplicitBlockNetExists\n"
"    oacInvalidHierNetName\n"
"  Paramegers: (oaModule,oaVectorBitName)\n"
"    Calls: oaModBusNetBit* create(oaModule* module,const oaVectorBitName& bitName)\n"
"    Signature: create|ptr-oaModBusNetBit|ptr-oaModule,cref-oaVectorBitName,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates a busNetBit with the baseName and bitIndex as specified in the given bitName in the given module .\n"
"    module\n"
"    The module to create the net in\n"
"    bitName\n"
"    The name specifying the baseName and bit index to give the net\n"
"    sigType\n"
"    The signal type of the busNetBit\n"
"    isGlobal\n"
"    Specifies if this is a global net\n"
"    oacBusNetNameMatchesAutoName\n"
"    oacBusNetBaseNameMatchesScalarName\n"
"    oacNetExists\n"
"    oacImplicitModuleNetExists\n"
"    oacImplicitBlockNetExists\n"
"    oacInvalidHierNetName\n"
"  Paramegers: (oaModule,oaVectorBitName,oaSigType)\n"
"    Calls: oaModBusNetBit* create(oaModule* module,const oaVectorBitName& bitName,oaSigType type)\n"
"    Signature: create|ptr-oaModBusNetBit|ptr-oaModule,cref-oaVectorBitName,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates a busNetBit with the baseName and bitIndex as specified in the given bitName in the given module .\n"
"    module\n"
"    The module to create the net in\n"
"    bitName\n"
"    The name specifying the baseName and bit index to give the net\n"
"    sigType\n"
"    The signal type of the busNetBit\n"
"    isGlobal\n"
"    Specifies if this is a global net\n"
"    oacBusNetNameMatchesAutoName\n"
"    oacBusNetBaseNameMatchesScalarName\n"
"    oacNetExists\n"
"    oacImplicitModuleNetExists\n"
"    oacImplicitBlockNetExists\n"
"    oacInvalidHierNetName\n"
"  Paramegers: (oaModule,oaVectorBitName,oaSigType,oaBoolean)\n"
"    Calls: oaModBusNetBit* create(oaModule* module,const oaVectorBitName& bitName,oaSigType type,oaBoolean isGlobal)\n"
"    Signature: create|ptr-oaModBusNetBit|ptr-oaModule,cref-oaVectorBitName,simple-oaSigType,simple-oaBoolean,\n"
"    This function creates a busNetBit with the baseName and bitIndex as specified in the given bitName in the given module .\n"
"    module\n"
"    The module to create the net in\n"
"    bitName\n"
"    The name specifying the baseName and bit index to give the net\n"
"    sigType\n"
"    The signal type of the busNetBit\n"
"    isGlobal\n"
"    Specifies if this is a global net\n"
"    oacBusNetNameMatchesAutoName\n"
"    oacBusNetBaseNameMatchesScalarName\n"
"    oacNetExists\n"
"    oacImplicitModuleNetExists\n"
"    oacImplicitBlockNetExists\n"
"    oacInvalidHierNetName\n"
;

static PyObject*
oaModBusNetBit_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaModule,oaScalarName,oaUInt4)
    {
        PyParamoaModule p1;
        PyParamoaScalarName p2;
        PyParamoaUInt4 p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaUInt4_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusNetBitp result= (oaModBusNetBit::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaModBusNetBit_FromoaModBusNetBit(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModule,oaScalarName,oaUInt4,oaSigType)
    {
        PyParamoaModule p1;
        PyParamoaScalarName p2;
        PyParamoaUInt4 p3;
        PyParamoaSigType p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaUInt4_Convert,&p3,
              &PyoaSigType_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusNetBitp result= (oaModBusNetBit::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaModBusNetBit_FromoaModBusNetBit(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModule,oaScalarName,oaUInt4,oaSigType,oaBoolean)
    {
        PyParamoaModule p1;
        PyParamoaScalarName p2;
        PyParamoaUInt4 p3;
        PyParamoaSigType p4;
        PyParamoaBoolean p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaUInt4_Convert,&p3,
              &PyoaSigType_Convert,&p4,
              &PyoaBoolean_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusNetBitp result= (oaModBusNetBit::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaModBusNetBit_FromoaModBusNetBit(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModule,oaVectorBitName)
    {
        PyParamoaModule p1;
        PyParamoaVectorBitName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaVectorBitName_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusNetBitp result= (oaModBusNetBit::create(p1.Data(),p2.Data()));
            return PyoaModBusNetBit_FromoaModBusNetBit(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModule,oaVectorBitName,oaSigType)
    {
        PyParamoaModule p1;
        PyParamoaVectorBitName p2;
        PyParamoaSigType p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaVectorBitName_Convert,&p2,
              &PyoaSigType_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusNetBitp result= (oaModBusNetBit::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaModBusNetBit_FromoaModBusNetBit(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModule,oaVectorBitName,oaSigType,oaBoolean)
    {
        PyParamoaModule p1;
        PyParamoaVectorBitName p2;
        PyParamoaSigType p3;
        PyParamoaBoolean p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaModule_Convert,&p1,
              &PyoaVectorBitName_Convert,&p2,
              &PyoaSigType_Convert,&p3,
              &PyoaBoolean_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusNetBitp result= (oaModBusNetBit::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaModBusNetBit_FromoaModBusNetBit(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaModBusNetBit, function: create, Choices are:\n"
        "    (oaModule,oaScalarName,oaUInt4)\n"
        "    (oaModule,oaScalarName,oaUInt4,oaSigType)\n"
        "    (oaModule,oaScalarName,oaUInt4,oaSigType,oaBoolean)\n"
        "    (oaModule,oaVectorBitName)\n"
        "    (oaModule,oaVectorBitName,oaSigType)\n"
        "    (oaModule,oaVectorBitName,oaSigType,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBusNetBit_static_find_doc[] = 
"Class: oaModBusNetBit, Function: find\n"
"  Paramegers: (oaModule,oaScalarName,oaUInt4)\n"
"    Calls: oaModBusNetBit* find(const oaModule* module,const oaScalarName& baseName,oaUInt4 bitIndex)\n"
"    Signature: find|ptr-oaModBusNetBit|cptr-oaModule,cref-oaScalarName,simple-oaUInt4,\n"
"    This function searches the specified module for a busNetBit with the specified baseName and bitIndex . The busNetBit is returned if found. Otherwise, NULL is returned.\n"
"    module\n"
"    The module to search\n"
"    baseName\n"
"    The base name to find\n"
"    bitIndex\n"
"    The bit index to find\n"
;

static PyObject*
oaModBusNetBit_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModule p1;
    PyParamoaScalarName p2;
    PyParamoaUInt4 p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaModule_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaUInt4_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaModBusNetBitp result= (oaModBusNetBit::find(p1.Data(),p2.Data(),p3.Data()));
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
static char oaModBusNetBit_static_isValidName_doc[] = 
"Class: oaModBusNetBit, Function: isValidName\n"
"  Paramegers: (oaModule,oaScalarName,oaUInt4)\n"
"    Calls: oaBoolean isValidName(const oaModule* module,const oaScalarName& baseName,oaUInt4 bitIndex)\n"
"    Signature: isValidName|simple-oaBoolean|cptr-oaModule,cref-oaScalarName,simple-oaUInt4,\n"
"    This function returns a boolean value indicating whether the specified name is valid for a new oaModBusNetBit in the specified module.\n"
"    module\n"
"    The module to search\n"
"    baseName\n"
"    The base name of the bus bit\n"
"    bitIndex\n"
"    The bit index of the bus bit\n"
;

static PyObject*
oaModBusNetBit_static_isValidName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModule p1;
    PyParamoaScalarName p2;
    PyParamoaUInt4 p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaModule_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaUInt4_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaBoolean result= (oaModBusNetBit::isValidName(p1.Data(),p2.Data(),p3.Data()));
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
static PyMethodDef oaModBusNetBit_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaModBusNetBit_static_create,METH_VARARGS,oaModBusNetBit_static_create_doc},
    {"static_find",(PyCFunction)oaModBusNetBit_static_find,METH_VARARGS,oaModBusNetBit_static_find_doc},
    {"static_isValidName",(PyCFunction)oaModBusNetBit_static_isValidName,METH_VARARGS,oaModBusNetBit_static_isValidName_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaModBusNetBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaModBusNetBit_Type)<0) {
      printf("** PyType_Ready failed for: oaModBusNetBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaModBusNetBit",
           (PyObject*)(&PyoaModBusNetBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaModBusNetBit\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaModBusNetBit_Type.tp_dict;
    for(method=oaModBusNetBit_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaModBusNetDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaModBusNetDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaModBusNetDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaModBusNetDefObject* self = (PyoaModBusNetDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaModBusNetDef)
    {
        PyParamoaModBusNetDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaModBusNetDef_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaModBusNetDef, Choices are:\n"
        "    (oaModBusNetDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaModBusNetDef_tp_dealloc(PyoaModBusNetDefObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaModBusNetDef_tp_repr(PyObject *ob)
{
    PyParamoaModBusNetDef value;
    int convert_status=PyoaModBusNetDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaModBusNetDef::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaScalarName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[36];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaModBusNetDef::");
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
oaModBusNetDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaModBusNetDef v1;
    PyParamoaModBusNetDef v2;
    int convert_status1=PyoaModBusNetDef_Convert(ob1,&v1);
    int convert_status2=PyoaModBusNetDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaModBusNetDef_Convert(PyObject* ob,PyParamoaModBusNetDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaModBusNetDef_Check(ob)) {
        result->SetData( (oaModBusNetDef**) ((PyoaModBusNetDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaModBusNetDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaModBusNetDef_FromoaModBusNetDef(oaModBusNetDef** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaModBusNetDef* data=*value;
        PyObject* bself = PyoaModBusNetDef_Type.tp_alloc(&PyoaModBusNetDef_Type,0);
        if (bself == NULL) return bself;
        PyoaModBusNetDefObject* self = (PyoaModBusNetDefObject*)bself;
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
PyObject* PyoaModBusNetDef_FromoaModBusNetDef(oaModBusNetDef* data)
{
    if (data) {
       PyObject* bself = PyoaModBusNetDef_Type.tp_alloc(&PyoaModBusNetDef_Type,0);
       if (bself == NULL) return bself;
       PyoaModBusNetDefObject* self = (PyoaModBusNetDefObject*)bself;
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
static char oaModBusNetDef_destroy_doc[] = 
"Class: oaModBusNetDef, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this oaModBusNetDef, removing it from the database. An exception is thrown if the oaModBusNetDef is implicit or if there are still oaModBusNets associated with it.\n"
"    oacCannotDestroyImplicitBusNetDef\n"
"    oacCannotDestroyBusNetDefWithNets\n"
;

static PyObject*
oaModBusNetDef_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNetDef data;
    int convert_status=PyoaModBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetDefObject* self=(PyoaModBusNetDefObject*)ob;
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
static char oaModBusNetDef_getBitOrder_doc[] = 
"Class: oaModBusNetDef, Function: getBitOrder\n"
"  Paramegers: ()\n"
"    Calls: oaBitOrder getBitOrder() const\n"
"    Signature: getBitOrder|simple-oaBitOrder|\n"
"    BrowseData: 1\n"
"    This function returns the bitOrder associated with this oaModBusNetDef.\n"
;

static PyObject*
oaModBusNetDef_getBitOrder(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNetDef data;
    int convert_status=PyoaModBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetDefObject* self=(PyoaModBusNetDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBitOrder* result= new oaBitOrder(data.DataCall()->getBitOrder());
        return PyoaBitOrder_FromoaBitOrder(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBusNetDef_getBusNetBits_doc[] = 
"Class: oaModBusNetDef, Function: getBusNetBits\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaModBusNetBit_oaModBusNetDef getBusNetBits() const\n"
"    Signature: getBusNetBits|simple-oaCollection_oaModBusNetBit_oaModBusNetDef|\n"
"    BrowseData: 1\n"
"    This function returns a collection of oaModBusNetBit objects in this oaModBusNetDef object.\n"
;

static PyObject*
oaModBusNetDef_getBusNetBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNetDef data;
    int convert_status=PyoaModBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetDefObject* self=(PyoaModBusNetDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaModBusNetBit_oaModBusNetDef* result= new oaCollection_oaModBusNetBit_oaModBusNetDef(data.DataCall()->getBusNetBits());
        return PyoaCollection_oaModBusNetBit_oaModBusNetDef_FromoaCollection_oaModBusNetBit_oaModBusNetDef(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBusNetDef_getBusNetBitsIter_doc[] = 
"Class: oaModBusNetDef, Function: getBusNetBitsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaModBusNetBit getBusNetBitsIter() const\n"
"    Signature: getBusNetBitsIter|simple-oaIter_oaModBusNetBit|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of oaModBusNetBit objects in this oaModBusNetDef object.\n"
;

static PyObject*
oaModBusNetDef_getBusNetBitsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNetDef data;
    int convert_status=PyoaModBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetDefObject* self=(PyoaModBusNetDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaModBusNetBit* result= new oaIter_oaModBusNetBit(data.DataCall()->getBusNetBits());
        return PyoaIter_oaModBusNetBit_FromoaIter_oaModBusNetBit(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBusNetDef_getBusNets_doc[] = 
"Class: oaModBusNetDef, Function: getBusNets\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaModBusNet_oaModBusNetDef getBusNets() const\n"
"    Signature: getBusNets|simple-oaCollection_oaModBusNet_oaModBusNetDef|\n"
"    BrowseData: 1\n"
"    This function returns a collection of oaModBusNet objects in this oaModBusNetDef object.\n"
;

static PyObject*
oaModBusNetDef_getBusNets(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNetDef data;
    int convert_status=PyoaModBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetDefObject* self=(PyoaModBusNetDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaModBusNet_oaModBusNetDef* result= new oaCollection_oaModBusNet_oaModBusNetDef(data.DataCall()->getBusNets());
        return PyoaCollection_oaModBusNet_oaModBusNetDef_FromoaCollection_oaModBusNet_oaModBusNetDef(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBusNetDef_getBusNetsIter_doc[] = 
"Class: oaModBusNetDef, Function: getBusNetsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaModBusNet getBusNetsIter() const\n"
"    Signature: getBusNetsIter|simple-oaIter_oaModBusNet|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of oaModBusNet objects in this oaModBusNetDef object.\n"
;

static PyObject*
oaModBusNetDef_getBusNetsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNetDef data;
    int convert_status=PyoaModBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetDefObject* self=(PyoaModBusNetDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaModBusNet* result= new oaIter_oaModBusNet(data.DataCall()->getBusNets());
        return PyoaIter_oaModBusNet_FromoaIter_oaModBusNet(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBusNetDef_getMaxIndex_doc[] = 
"Class: oaModBusNetDef, Function: getMaxIndex\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getMaxIndex() const\n"
"    Signature: getMaxIndex|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the largest bit number in use for this oaModBusNetDef object. This is the largest index used across all busNets associated with this oaModBusNetDef object.\n"
;

static PyObject*
oaModBusNetDef_getMaxIndex(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNetDef data;
    int convert_status=PyoaModBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetDefObject* self=(PyoaModBusNetDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getMaxIndex());
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
static char oaModBusNetDef_getMinIndex_doc[] = 
"Class: oaModBusNetDef, Function: getMinIndex\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getMinIndex() const\n"
"    Signature: getMinIndex|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the smallest bit number in use for this oaModBusNetDef object. This is the smallest index used across all busNets associated with this oaModBusNetDef object.\n"
;

static PyObject*
oaModBusNetDef_getMinIndex(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNetDef data;
    int convert_status=PyoaModBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetDefObject* self=(PyoaModBusNetDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getMinIndex());
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
static char oaModBusNetDef_getName_doc[] = 
"Class: oaModBusNetDef, Function: getName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getName(oaScalarName& name) const\n"
"    Signature: getName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the name of this oaModBusNetDef object.\n"
"    name\n"
"    The scalar name in which to return the oaModBusNetDef object name\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getName(const oaNameSpace& ns,oaString& name) const\n"
"    Signature: getName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the name string of this oaModBusNetDef object in the specified nameSpace.\n"
"    ns\n"
"    The nameSpace to search\n"
"    name\n"
"    The oaModBusNetDef object to return\n"
;

static PyObject*
oaModBusNetDef_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNetDef data;
    int convert_status=PyoaModBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetDefObject* self=(PyoaModBusNetDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
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
        "No Arg-Matching Function found for class: oaModBusNetDef, function: getName, Choices are:\n"
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
static char oaModBusNetDef_getNumBits_doc[] = 
"Class: oaModBusNetDef, Function: getNumBits\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumBits() const\n"
"    Signature: getNumBits|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of bits covered by the busses in this oaModBusNetDef. The number of bits is equal to abs(maxIndex - minIndex) + 1; it is not necessarily the number of busNetBits present in this busNetDef. To get the number of busNetBits in this busNetDef, use oaModBusNetDef::getBusNetBits() .getCount()\n"
;

static PyObject*
oaModBusNetDef_getNumBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNetDef data;
    int convert_status=PyoaModBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetDefObject* self=(PyoaModBusNetDefObject*)ob;
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
static char oaModBusNetDef_isImplicit_doc[] = 
"Class: oaModBusNetDef, Function: isImplicit\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isImplicit() const\n"
"    Signature: isImplicit|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether this oaModBusNetDef was implicitly created or not.\n"
;

static PyObject*
oaModBusNetDef_isImplicit(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNetDef data;
    int convert_status=PyoaModBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetDefObject* self=(PyoaModBusNetDefObject*)ob;
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
static char oaModBusNetDef_setBitOrder_doc[] = 
"Class: oaModBusNetDef, Function: setBitOrder\n"
"  Paramegers: (oaBitOrder)\n"
"    Calls: void setBitOrder(oaBitOrder order)\n"
"    Signature: setBitOrder|void-void|simple-oaBitOrder,\n"
"    This function changes the bitOrder value associated with the oaModBusNetDef. An exception is thrown if this busNetDef was implicitly created.\n"
"    order\n"
"    The new bitOrder value for this busNetDef\n"
"    oacBitOrderBusNetDefImplicit\n"
;

static PyObject*
oaModBusNetDef_setBitOrder(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusNetDef data;
    int convert_status=PyoaModBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusNetDefObject* self=(PyoaModBusNetDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBitOrder p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBitOrder_Convert,&p1)) {
        data.DataCall()->setBitOrder(p1.Data());
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
static char oaModBusNetDef_isNull_doc[] =
"Class: oaModBusNetDef, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaModBusNetDef_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaModBusNetDef data;
    int convert_status=PyoaModBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaModBusNetDef_assign_doc[] = 
"Class: oaModBusNetDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaModBusNetDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaModBusNetDef data;
  int convert_status=PyoaModBusNetDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaModBusNetDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaModBusNetDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaModBusNetDef_methodlist[] = {
    {"destroy",(PyCFunction)oaModBusNetDef_destroy,METH_VARARGS,oaModBusNetDef_destroy_doc},
    {"getBitOrder",(PyCFunction)oaModBusNetDef_getBitOrder,METH_VARARGS,oaModBusNetDef_getBitOrder_doc},
    {"getBusNetBits",(PyCFunction)oaModBusNetDef_getBusNetBits,METH_VARARGS,oaModBusNetDef_getBusNetBits_doc},
    {"getBusNetBitsIter",(PyCFunction)oaModBusNetDef_getBusNetBitsIter,METH_VARARGS,oaModBusNetDef_getBusNetBitsIter_doc},
    {"getBusNets",(PyCFunction)oaModBusNetDef_getBusNets,METH_VARARGS,oaModBusNetDef_getBusNets_doc},
    {"getBusNetsIter",(PyCFunction)oaModBusNetDef_getBusNetsIter,METH_VARARGS,oaModBusNetDef_getBusNetsIter_doc},
    {"getMaxIndex",(PyCFunction)oaModBusNetDef_getMaxIndex,METH_VARARGS,oaModBusNetDef_getMaxIndex_doc},
    {"getMinIndex",(PyCFunction)oaModBusNetDef_getMinIndex,METH_VARARGS,oaModBusNetDef_getMinIndex_doc},
    {"getName",(PyCFunction)oaModBusNetDef_getName,METH_VARARGS,oaModBusNetDef_getName_doc},
    {"getNumBits",(PyCFunction)oaModBusNetDef_getNumBits,METH_VARARGS,oaModBusNetDef_getNumBits_doc},
    {"isImplicit",(PyCFunction)oaModBusNetDef_isImplicit,METH_VARARGS,oaModBusNetDef_isImplicit_doc},
    {"setBitOrder",(PyCFunction)oaModBusNetDef_setBitOrder,METH_VARARGS,oaModBusNetDef_setBitOrder_doc},
    {"isNull",(PyCFunction)oaModBusNetDef_tp_isNull,METH_VARARGS,oaModBusNetDef_isNull_doc},
    {"assign",(PyCFunction)oaModBusNetDef_tp_assign,METH_VARARGS,oaModBusNetDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModBusNetDef_doc[] = 
"Class: oaModBusNetDef\n"
"  The oaModBusNetDef class implements the definition of a module busNet, including its base name and bit-range. All busNets in a module with the same base name are managed by the same busNet definition. The oaModBusNetDef class tracks the minimum and maximum indices referred to by all of its corresponding busNet and busNetBit objects.\n"
"  A busNetDef can be 'sparse' (have missing bits). Busses do not have to start or end at zero. For example, a<22:25> is a legal bus name. Bus indexes must be non-negative.\n"
"  An busNetDef is automatically created if necessary whenever applications create busNets. Implicitly created busNet definitions have no bitOrder. Applications may explicitly create a busNet definition in order to specify that it has a specific bitOrder.\n"
"  Implicitly created busNet definitions are automatically destroyed when the last busNet with the same base name is destroyed. Explicitly created busNet definitions must be explicitly destroyed.\n"
"  The oaModBusNetDef class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaModBusNetDef)\n"
"    Calls: (const oaModBusNetDef&)\n"
"    Signature: oaModBusNetDef||cref-oaModBusNetDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaModBusNetDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaModBusNetDef",
    sizeof(PyoaModBusNetDefObject),
    0,
    (destructor)oaModBusNetDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaModBusNetDef_tp_compare,	/* tp_compare */
    (reprfunc)oaModBusNetDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaModBusNetDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaModBusNetDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaModObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaModBusNetDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModBusNetDef_static_create_doc[] = 
"Class: oaModBusNetDef, Function: create\n"
"  Paramegers: (oaModule,oaScalarName,oaBitOrder)\n"
"    Calls: oaModBusNetDef* create(const oaModule* module,const oaScalarName& name,oaBitOrder order)\n"
"    Signature: create|ptr-oaModBusNetDef|cptr-oaModule,cref-oaScalarName,simple-oaBitOrder,\n"
"    This function creates an oaModBusNetDef in the specified module with the given base name and bit order. An exception is thrown if an oaModBusNetDef already exists with the specified name . Explicitly creating an oaModBusNetDef also means that the busNet definition must be explicitly destroyed.\n"
"    module\n"
"    The module to create the oaModBusNetDef object in\n"
"    name\n"
"    The base name for the oaModBusNetDef\n"
"    order\n"
"    The bit order for the oaModBusNetDef\n"
"    oacBusNetDefAlreadyExists\n"
;

static PyObject*
oaModBusNetDef_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModule p1;
    PyParamoaScalarName p2;
    PyParamoaBitOrder p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaModule_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaBitOrder_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaModBusNetDefp result= (oaModBusNetDef::create(p1.Data(),p2.Data(),p3.Data()));
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
static char oaModBusNetDef_static_find_doc[] = 
"Class: oaModBusNetDef, Function: find\n"
"  Paramegers: (oaModule,oaScalarName)\n"
"    Calls: oaModBusNetDef* find(const oaModule* module,const oaScalarName& name)\n"
"    Signature: find|ptr-oaModBusNetDef|cptr-oaModule,cref-oaScalarName,\n"
"    This function searches the specified module for an oaModBusNetDef with the specified name. The oaModBusNetDef is returned if found. Otherwise, NULL is returned.\n"
"    module\n"
"    The module to search for the oaModBusNetDef object\n"
"    name\n"
"    The name of the oaModBusNetDef to find\n"
;

static PyObject*
oaModBusNetDef_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModule p1;
    PyParamoaScalarName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaModule_Convert,&p1,
          &PyoaScalarName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaModBusNetDefp result= (oaModBusNetDef::find(p1.Data(),p2.Data()));
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
static PyMethodDef oaModBusNetDef_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaModBusNetDef_static_create,METH_VARARGS,oaModBusNetDef_static_create_doc},
    {"static_find",(PyCFunction)oaModBusNetDef_static_find,METH_VARARGS,oaModBusNetDef_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaModBusNetDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaModBusNetDef_Type)<0) {
      printf("** PyType_Ready failed for: oaModBusNetDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaModBusNetDef",
           (PyObject*)(&PyoaModBusNetDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaModBusNetDef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaModBusNetDef_Type.tp_dict;
    for(method=oaModBusNetDef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaModBusTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaModBusTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaModBusTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaModBusTermObject* self = (PyoaModBusTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaModBusTerm)
    {
        PyParamoaModBusTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaModBusTerm_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaModBusTerm, Choices are:\n"
        "    (oaModBusTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaModBusTerm_tp_dealloc(PyoaModBusTermObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaModBusTerm_tp_repr(PyObject *ob)
{
    PyParamoaModBusTerm value;
    int convert_status=PyoaModBusTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaModBusTerm::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[34];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaModBusTerm::");
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
oaModBusTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaModBusTerm v1;
    PyParamoaModBusTerm v2;
    int convert_status1=PyoaModBusTerm_Convert(ob1,&v1);
    int convert_status2=PyoaModBusTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaModBusTerm_Convert(PyObject* ob,PyParamoaModBusTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaModBusTerm_Check(ob)) {
        result->SetData( (oaModBusTerm**) ((PyoaModBusTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaModBusTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaModBusTerm_FromoaModBusTerm(oaModBusTerm** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaModBusTerm* data=*value;
        PyObject* bself = PyoaModBusTerm_Type.tp_alloc(&PyoaModBusTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaModBusTermObject* self = (PyoaModBusTermObject*)bself;
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
PyObject* PyoaModBusTerm_FromoaModBusTerm(oaModBusTerm* data)
{
    if (data) {
       PyObject* bself = PyoaModBusTerm_Type.tp_alloc(&PyoaModBusTerm_Type,0);
       if (bself == NULL) return bself;
       PyoaModBusTermObject* self = (PyoaModBusTermObject*)bself;
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
static char oaModBusTerm_getDef_doc[] = 
"Class: oaModBusTerm, Function: getDef\n"
"  Paramegers: ()\n"
"    Calls: oaModBusTermDef* getDef() const\n"
"    Signature: getDef|ptr-oaModBusTermDef|\n"
"    BrowseData: 1\n"
"    This function returns the oaModBusTermDef for this oaModBusTerm object.\n"
"    A pointer to an oaModBusTermDef\n"
;

static PyObject*
oaModBusTerm_getDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusTerm data;
    int convert_status=PyoaModBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusTermObject* self=(PyoaModBusTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusTermDefp result= (data.DataCall()->getDef());
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
static char oaModBusTerm_getName_doc[] = 
"Class: oaModBusTerm, Function: getName\n"
"  Paramegers: (oaVectorName)\n"
"    Calls: void getName(oaVectorName& name) const\n"
"    Signature: getName|void-void|ref-oaVectorName,\n"
"    BrowseData: 0,oaVectorName\n"
"    This function returns the name of this modBusTerm.\n"
"    name\n"
"    The name of the modBusTerm to return\n"
"  Paramegers: (oaName)\n"
"    Calls: void getName(oaName& name) const\n"
"    Signature: getName|void-void|ref-oaName,\n"
"    BrowseData: 0,oaName\n"
"    This function fills out name with the name of this terminal.\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getName(const oaNameSpace& ns,oaString& name) const\n"
"    Signature: getName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function fills in name with the name of this terminal mapped to the specified nameSpace.\n"
;

static PyObject*
oaModBusTerm_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusTerm data;
    int convert_status=PyoaModBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusTermObject* self=(PyoaModBusTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaVectorName)
    {
        PyParamoaVectorName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaVectorName_Convert,&p1)) {
            data.DataCall()->getName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaName)
    {
        PyParamoaName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaName_Convert,&p1)) {
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
        "No Arg-Matching Function found for class: oaModBusTerm, function: getName, Choices are:\n"
        "    (oaVectorName)\n"
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
static char oaModBusTerm_getStart_doc[] = 
"Class: oaModBusTerm, Function: getStart\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getStart() const\n"
"    Signature: getStart|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the starting index for this oaModBusTerm object.\n"
"    The starting index for this oaModBusTerm\n"
;

static PyObject*
oaModBusTerm_getStart(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusTerm data;
    int convert_status=PyoaModBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusTermObject* self=(PyoaModBusTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getStart());
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
static char oaModBusTerm_getStep_doc[] = 
"Class: oaModBusTerm, Function: getStep\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getStep() const\n"
"    Signature: getStep|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the stepping index for this oaModBusTerm object.\n"
"    The step value for this oaModBusTerm\n"
;

static PyObject*
oaModBusTerm_getStep(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusTerm data;
    int convert_status=PyoaModBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusTermObject* self=(PyoaModBusTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getStep());
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
static char oaModBusTerm_getStop_doc[] = 
"Class: oaModBusTerm, Function: getStop\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getStop() const\n"
"    Signature: getStop|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the ending index for this oaModBusTerm object.\n"
"    The ending index for this oaModBusTerm\n"
;

static PyObject*
oaModBusTerm_getStop(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusTerm data;
    int convert_status=PyoaModBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusTermObject* self=(PyoaModBusTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getStop());
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
static char oaModBusTerm_setBaseName_doc[] = 
"Class: oaModBusTerm, Function: setBaseName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void setBaseName(const oaScalarName& name)\n"
"    Signature: setBaseName|void-void|cref-oaScalarName,\n"
"    This function sets the name of this oaModBusTerm object. The name is also updated for each occurrence that the term appears in.\n"
"    name\n"
"    The new name to be set for the term.\n"
"    oacCannotSetNameOfImplicitTerm\n"
"    oacCannotSetNameOfTermInBundleTerm\n"
"    oacBusTermBaseNameMatchesScalarName\n"
"    oacNetTermWidthMismatch\n"
"    oacInvalidVectorValue\n"
"    oacTermExists\n"
"    oacTermMemberExists\n"
"    oacInvalidHierTermName\n"
;

static PyObject*
oaModBusTerm_setBaseName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusTerm data;
    int convert_status=PyoaModBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusTermObject* self=(PyoaModBusTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaScalarName p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaScalarName_Convert,&p1)) {
        data.DataCall()->setBaseName(p1.Data());
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
static char oaModBusTerm_setRange_doc[] = 
"Class: oaModBusTerm, Function: setRange\n"
"  Paramegers: (oaUInt4,oaUInt4)\n"
"    Calls: void setRange(oaUInt4 start,oaUInt4 stop)\n"
"    Signature: setRange|void-void|simple-oaUInt4,simple-oaUInt4,\n"
"    This function changes the vector range for this modBusTerm. The new number of bits implied by the specified start and stop bits must match the current number of bits. This restriction is necessary so that any terminals or instance terminals that are associated with this busTerm are not affected.\n"
"    start\n"
"    The starting index of the net\n"
"    stop\n"
"    The stopping index of the net\n"
"    oacCannotSetNameOfImplicitTerm\n"
"    oacCannotSetNameOfTermInBundleTerm\n"
"    oacInvalidBusStartStopRange\n"
"    oacTermExists\n"
;

static PyObject*
oaModBusTerm_setRange(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusTerm data;
    int convert_status=PyoaModBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusTermObject* self=(PyoaModBusTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    PyParamoaUInt4 p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaUInt4_Convert,&p1,
          &PyoaUInt4_Convert,&p2)) {
        data.DataCall()->setRange(p1.Data(),p2.Data());
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
static char oaModBusTerm_isNull_doc[] =
"Class: oaModBusTerm, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaModBusTerm_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaModBusTerm data;
    int convert_status=PyoaModBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaModBusTerm_assign_doc[] = 
"Class: oaModBusTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaModBusTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaModBusTerm data;
  int convert_status=PyoaModBusTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaModBusTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaModBusTerm_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaModBusTerm_methodlist[] = {
    {"getDef",(PyCFunction)oaModBusTerm_getDef,METH_VARARGS,oaModBusTerm_getDef_doc},
    {"getName",(PyCFunction)oaModBusTerm_getName,METH_VARARGS,oaModBusTerm_getName_doc},
    {"getStart",(PyCFunction)oaModBusTerm_getStart,METH_VARARGS,oaModBusTerm_getStart_doc},
    {"getStep",(PyCFunction)oaModBusTerm_getStep,METH_VARARGS,oaModBusTerm_getStep_doc},
    {"getStop",(PyCFunction)oaModBusTerm_getStop,METH_VARARGS,oaModBusTerm_getStop_doc},
    {"setBaseName",(PyCFunction)oaModBusTerm_setBaseName,METH_VARARGS,oaModBusTerm_setBaseName_doc},
    {"setRange",(PyCFunction)oaModBusTerm_setRange,METH_VARARGS,oaModBusTerm_setRange_doc},
    {"isNull",(PyCFunction)oaModBusTerm_tp_isNull,METH_VARARGS,oaModBusTerm_isNull_doc},
    {"assign",(PyCFunction)oaModBusTerm_tp_assign,METH_VARARGS,oaModBusTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModBusTerm_doc[] = 
"Class: oaModBusTerm\n"
"  The oaModBusTerm class implements a terminal in the module domain that represents one or more bits that are associated by a common baseName and vector-range specification. An oaModBusTerm object has a corresponding oaModBusTermDef object that manages all oaModBusTerm objects that share the same baseName.\n"
"  oaModBusTerm, oaOccBusTerm , and oaBusTerm each represent bus terminals in a different hierarchy domain, where in each case the terminal's master represents a level of hierarchy in the design.\n"
"  For oaModBusTerm, the master is an oaModule , and each module in a design will have a set of zero or more modBusTerms. For oaOccBusTerm , the master is an oaOccurrence .\n"
"  For oaBusTerm , the master is an oaBlock , and the top block for the design will have a set of zero or more busTerms. Typically, all of the oaModBusTerms on the top oaModule have a corresponding oaBusTerm on the top oaBlock . All of the oaModBusTerms have a corresponding oaOccBusTerm in the occurrence domain.\n"
"  When oaBusTerm objects are created in the block domain, the corresponding oaModBusTerm objects are automatically created on the top oaModule unless this visibility is suppressed by the create call.\n"
"Constructors:\n"
"  Paramegers: (oaModBusTerm)\n"
"    Calls: (const oaModBusTerm&)\n"
"    Signature: oaModBusTerm||cref-oaModBusTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaModBusTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaModBusTerm",
    sizeof(PyoaModBusTermObject),
    0,
    (destructor)oaModBusTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaModBusTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaModBusTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaModBusTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaModBusTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaModTerm_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaModBusTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModBusTerm_static_create_doc[] = 
"Class: oaModBusTerm, Function: create\n"
"  Paramegers: (oaModNet,oaScalarName,oaUInt4,oaUInt4,oaUInt4)\n"
"    Calls: oaModBusTerm* create(oaModNet* modNet,const oaScalarName& name,oaUInt4 start,oaUInt4 stop,oaUInt4 step)\n"
"    Signature: create|ptr-oaModBusTerm|ptr-oaModNet,cref-oaScalarName,simple-oaUInt4,simple-oaUInt4,simple-oaUInt4,simple-oaTermType,\n"
"    This function creates a bus terminal on the specified module net by separately specifying the base name and the index values. If the module is visible in the block domain this will create an oaBusTerm in the block domain as well.\n"
"    Exceptions are thrown if the number of bits in the net doesn't match the number of bits implied by the terminal name, if the baseName matches the name of an existing scalarTerm (in any domain), or if the member busTermBits already exist. In this form of the create function, an exception is thrown if the start value is equal to the stop value but the step is greater than 0.\n"
"    modNet\n"
"    The net to use to create the oaModBusTerm\n"
"    name\n"
"    The baseName for the oaModBusTerm\n"
"    start\n"
"    The starting index of the oaModBusTerm\n"
"    stop\n"
"    The stopping index of the oaModBusTerm\n"
"    step\n"
"    The step value of the oaModBusTerm\n"
"    termType\n"
"    The type of terminal to create\n"
"    oacTermExists\n"
"    oacInvalidHierTermName\n"
"    oacTermMemberExists\n"
"    oacInvalidVectorValue\n"
"    oacNetTermWidthMismatch\n"
"    oacBusTermBaseNameMatchesScalarName\n"
"    oacBusDefIsBlockDomainSpecific\n"
"    oacCannotCreateTermWithImplicitNet\n"
"  Paramegers: (oaModNet,oaScalarName,oaUInt4,oaUInt4,oaUInt4,oaTermType)\n"
"    Calls: oaModBusTerm* create(oaModNet* modNet,const oaScalarName& name,oaUInt4 start,oaUInt4 stop,oaUInt4 step,oaTermType termType)\n"
"    Signature: create|ptr-oaModBusTerm|ptr-oaModNet,cref-oaScalarName,simple-oaUInt4,simple-oaUInt4,simple-oaUInt4,simple-oaTermType,\n"
"    This function creates a bus terminal on the specified module net by separately specifying the base name and the index values. If the module is visible in the block domain this will create an oaBusTerm in the block domain as well.\n"
"    Exceptions are thrown if the number of bits in the net doesn't match the number of bits implied by the terminal name, if the baseName matches the name of an existing scalarTerm (in any domain), or if the member busTermBits already exist. In this form of the create function, an exception is thrown if the start value is equal to the stop value but the step is greater than 0.\n"
"    modNet\n"
"    The net to use to create the oaModBusTerm\n"
"    name\n"
"    The baseName for the oaModBusTerm\n"
"    start\n"
"    The starting index of the oaModBusTerm\n"
"    stop\n"
"    The stopping index of the oaModBusTerm\n"
"    step\n"
"    The step value of the oaModBusTerm\n"
"    termType\n"
"    The type of terminal to create\n"
"    oacTermExists\n"
"    oacInvalidHierTermName\n"
"    oacTermMemberExists\n"
"    oacInvalidVectorValue\n"
"    oacNetTermWidthMismatch\n"
"    oacBusTermBaseNameMatchesScalarName\n"
"    oacBusDefIsBlockDomainSpecific\n"
"    oacCannotCreateTermWithImplicitNet\n"
"  Paramegers: (oaModNet,oaVectorName)\n"
"    Calls: oaModBusTerm* create(oaModNet* modNet,const oaVectorName& name)\n"
"    Signature: create|ptr-oaModBusTerm|ptr-oaModNet,cref-oaVectorName,simple-oaTermType,\n"
"    This function creates a bus terminal on the specified module net using the specified oaVectorName that incorporates the base name and indexes. If the module is visible in the block domain this will create an oaBusTerm in the block domain as well.\n"
"    Exceptions are thrown if the number of bits in the net doesn't match the number of bits implied by the terminal name, if the baseName matches the name of an existing scalarTerm (in any domain), or if the member busTermBits already exist.\n"
"    modNet\n"
"    The net to use to create the oaModBusTerm\n"
"    name\n"
"    The name to use to create the oaModBusTerm\n"
"    termType\n"
"    The type of terminal to create\n"
"    oacTermExists\n"
"    oacInvalidHierTermName\n"
"    oacTermMemberExists\n"
"    oacInvalidVectorValue\n"
"    oacNetTermWidthMismatch\n"
"    oacBusTermBaseNameMatchesScalarName\n"
"    oacBusDefIsBlockDomainSpecific\n"
"    oacCannotCreateTermWithImplicitNet\n"
"  Paramegers: (oaModNet,oaVectorName,oaTermType)\n"
"    Calls: oaModBusTerm* create(oaModNet* modNet,const oaVectorName& name,oaTermType termType)\n"
"    Signature: create|ptr-oaModBusTerm|ptr-oaModNet,cref-oaVectorName,simple-oaTermType,\n"
"    This function creates a bus terminal on the specified module net using the specified oaVectorName that incorporates the base name and indexes. If the module is visible in the block domain this will create an oaBusTerm in the block domain as well.\n"
"    Exceptions are thrown if the number of bits in the net doesn't match the number of bits implied by the terminal name, if the baseName matches the name of an existing scalarTerm (in any domain), or if the member busTermBits already exist.\n"
"    modNet\n"
"    The net to use to create the oaModBusTerm\n"
"    name\n"
"    The name to use to create the oaModBusTerm\n"
"    termType\n"
"    The type of terminal to create\n"
"    oacTermExists\n"
"    oacInvalidHierTermName\n"
"    oacTermMemberExists\n"
"    oacInvalidVectorValue\n"
"    oacNetTermWidthMismatch\n"
"    oacBusTermBaseNameMatchesScalarName\n"
"    oacBusDefIsBlockDomainSpecific\n"
"    oacCannotCreateTermWithImplicitNet\n"
"  Paramegers: (oaModNet,oaVectorBitName)\n"
"    Calls: oaModBusTerm* create(oaModNet* modNet,const oaVectorBitName& name)\n"
"    Signature: create|ptr-oaModBusTerm|ptr-oaModNet,cref-oaVectorBitName,simple-oaTermType,\n"
"    This function creates a one-bit wide oaModBusTerm with a vectorBitName. If the module is visible in the block domain this will create an oaBusTerm in the block domain as well.\n"
"    Exceptions are thrown if the number of bits in the net doesn't match the number of bits implied by the terminal name, if the baseName matches the name of an existing scalarTerm (in any domain), or if the member busTermBits already exist.\n"
"    modNet\n"
"    The net to use to create the oaModBusTerm\n"
"    name\n"
"    The name to use to create the oaModBusTerm\n"
"    termType\n"
"    The type of terminal to create\n"
"    oacTermExists\n"
"    oacInvalidHierTermName\n"
"    oacTermMemberExists\n"
"    oacInvalidVectorValue\n"
"    oacNetTermWidthMismatch\n"
"    oacBusTermBaseNameMatchesScalarName\n"
"    oacBusDefIsBlockDomainSpecific\n"
"    oacCannotCreateTermWithImplicitNet\n"
"  Paramegers: (oaModNet,oaVectorBitName,oaTermType)\n"
"    Calls: oaModBusTerm* create(oaModNet* modNet,const oaVectorBitName& name,oaTermType termType)\n"
"    Signature: create|ptr-oaModBusTerm|ptr-oaModNet,cref-oaVectorBitName,simple-oaTermType,\n"
"    This function creates a one-bit wide oaModBusTerm with a vectorBitName. If the module is visible in the block domain this will create an oaBusTerm in the block domain as well.\n"
"    Exceptions are thrown if the number of bits in the net doesn't match the number of bits implied by the terminal name, if the baseName matches the name of an existing scalarTerm (in any domain), or if the member busTermBits already exist.\n"
"    modNet\n"
"    The net to use to create the oaModBusTerm\n"
"    name\n"
"    The name to use to create the oaModBusTerm\n"
"    termType\n"
"    The type of terminal to create\n"
"    oacTermExists\n"
"    oacInvalidHierTermName\n"
"    oacTermMemberExists\n"
"    oacInvalidVectorValue\n"
"    oacNetTermWidthMismatch\n"
"    oacBusTermBaseNameMatchesScalarName\n"
"    oacBusDefIsBlockDomainSpecific\n"
"    oacCannotCreateTermWithImplicitNet\n"
;

static PyObject*
oaModBusTerm_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaModNet,oaScalarName,oaUInt4,oaUInt4,oaUInt4)
    {
        PyParamoaModNet p1;
        PyParamoaScalarName p2;
        PyParamoaUInt4 p3;
        PyParamoaUInt4 p4;
        PyParamoaUInt4 p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaModNet_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaUInt4_Convert,&p3,
              &PyoaUInt4_Convert,&p4,
              &PyoaUInt4_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusTermp result= (oaModBusTerm::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaModBusTerm_FromoaModBusTerm(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModNet,oaScalarName,oaUInt4,oaUInt4,oaUInt4,oaTermType)
    {
        PyParamoaModNet p1;
        PyParamoaScalarName p2;
        PyParamoaUInt4 p3;
        PyParamoaUInt4 p4;
        PyParamoaUInt4 p5;
        PyParamoaTermType p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaModNet_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaUInt4_Convert,&p3,
              &PyoaUInt4_Convert,&p4,
              &PyoaUInt4_Convert,&p5,
              &PyoaTermType_Convert,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusTermp result= (oaModBusTerm::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data()));
            return PyoaModBusTerm_FromoaModBusTerm(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModNet,oaVectorName)
    {
        PyParamoaModNet p1;
        PyParamoaVectorName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaModNet_Convert,&p1,
              &PyoaVectorName_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusTermp result= (oaModBusTerm::create(p1.Data(),p2.Data()));
            return PyoaModBusTerm_FromoaModBusTerm(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModNet,oaVectorName,oaTermType)
    {
        PyParamoaModNet p1;
        PyParamoaVectorName p2;
        PyParamoaTermType p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaModNet_Convert,&p1,
              &PyoaVectorName_Convert,&p2,
              &PyoaTermType_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusTermp result= (oaModBusTerm::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaModBusTerm_FromoaModBusTerm(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModNet,oaVectorBitName)
    {
        PyParamoaModNet p1;
        PyParamoaVectorBitName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaModNet_Convert,&p1,
              &PyoaVectorBitName_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusTermp result= (oaModBusTerm::create(p1.Data(),p2.Data()));
            return PyoaModBusTerm_FromoaModBusTerm(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModNet,oaVectorBitName,oaTermType)
    {
        PyParamoaModNet p1;
        PyParamoaVectorBitName p2;
        PyParamoaTermType p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaModNet_Convert,&p1,
              &PyoaVectorBitName_Convert,&p2,
              &PyoaTermType_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusTermp result= (oaModBusTerm::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaModBusTerm_FromoaModBusTerm(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaModBusTerm, function: create, Choices are:\n"
        "    (oaModNet,oaScalarName,oaUInt4,oaUInt4,oaUInt4)\n"
        "    (oaModNet,oaScalarName,oaUInt4,oaUInt4,oaUInt4,oaTermType)\n"
        "    (oaModNet,oaVectorName)\n"
        "    (oaModNet,oaVectorName,oaTermType)\n"
        "    (oaModNet,oaVectorBitName)\n"
        "    (oaModNet,oaVectorBitName,oaTermType)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBusTerm_static_find_doc[] = 
"Class: oaModBusTerm, Function: find\n"
"  Paramegers: (oaModule,oaScalarName,oaUInt4,oaUInt4,oaUInt4)\n"
"    Calls: oaModBusTerm* find(const oaModule* module,const oaScalarName& name,oaUInt4 start,oaUInt4 stop,oaUInt4 step)\n"
"    Signature: find|ptr-oaModBusTerm|cptr-oaModule,cref-oaScalarName,simple-oaUInt4,simple-oaUInt4,simple-oaUInt4,\n"
"    This function searches the specified module for an oaModBusTerm object with the specified baseName and start , stop , and step indices. The oaModBusTerm object is returned if found. Otherwise, NULL is returned.\n"
"    module\n"
"    The module to search for the oaModBusTerm\n"
"    baseName\n"
"    The baseName for the oaModBusTerm\n"
"    start\n"
"    The starting index of the oaModBusTerm\n"
"    stop\n"
"    The stopping index of the oaModBusTerm\n"
"    step\n"
"    The step value of the oaModBusTerm\n"
"    A pointer to an oaModBusTerm\n"
;

static PyObject*
oaModBusTerm_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModule p1;
    PyParamoaScalarName p2;
    PyParamoaUInt4 p3;
    PyParamoaUInt4 p4;
    PyParamoaUInt4 p5;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&",
          &PyoaModule_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaUInt4_Convert,&p3,
          &PyoaUInt4_Convert,&p4,
          &PyoaUInt4_Convert,&p5)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaModBusTermp result= (oaModBusTerm::find(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
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
static char oaModBusTerm_static_isValidName_doc[] = 
"Class: oaModBusTerm, Function: isValidName\n"
"  Paramegers: (oaModule,oaModNet,oaScalarName,oaUInt4,oaUInt4,oaUInt4)\n"
"    Calls: oaBoolean isValidName(const oaModule* module,const oaModNet* net,const oaScalarName& name,oaUInt4 start,oaUInt4 stop,oaUInt4 step)\n"
"    Signature: isValidName|simple-oaBoolean|cptr-oaModule,cptr-oaModNet,cref-oaScalarName,simple-oaUInt4,simple-oaUInt4,simple-oaUInt4,\n"
"    This function returns a boolean value indicating whether the specified name is valid for a new oaModBusTerm object that is associated with the specified net .\n"
"    module\n"
"    The module to search for the oaModBusTerm\n"
"    net\n"
"    The net to use to create the oaModBusTerm\n"
"    name\n"
"    The name for the new oaModBusTerm\n"
"    start\n"
"    The starting index of the oaModBusTerm\n"
"    stop\n"
"    The stopping index of the oaModBusTerm\n"
"    step\n"
"    The step value of the oaModBusTerm\n"
;

static PyObject*
oaModBusTerm_static_isValidName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModule p1;
    PyParamoaModNet p2;
    PyParamoaScalarName p3;
    PyParamoaUInt4 p4;
    PyParamoaUInt4 p5;
    PyParamoaUInt4 p6;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
          &PyoaModule_Convert,&p1,
          &PyoaModNet_Convert,&p2,
          &PyoaScalarName_Convert,&p3,
          &PyoaUInt4_Convert,&p4,
          &PyoaUInt4_Convert,&p5,
          &PyoaUInt4_Convert,&p6)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        oaBoolean result= (oaModBusTerm::isValidName(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data()));
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
static PyMethodDef oaModBusTerm_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaModBusTerm_static_create,METH_VARARGS,oaModBusTerm_static_create_doc},
    {"static_find",(PyCFunction)oaModBusTerm_static_find,METH_VARARGS,oaModBusTerm_static_find_doc},
    {"static_isValidName",(PyCFunction)oaModBusTerm_static_isValidName,METH_VARARGS,oaModBusTerm_static_isValidName_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaModBusTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaModBusTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaModBusTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaModBusTerm",
           (PyObject*)(&PyoaModBusTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaModBusTerm\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaModBusTerm_Type.tp_dict;
    for(method=oaModBusTerm_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaModBusTermBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaModBusTermBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaModBusTermBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaModBusTermBitObject* self = (PyoaModBusTermBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaModBusTermBit)
    {
        PyParamoaModBusTermBit p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaModBusTermBit_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaModBusTermBit, Choices are:\n"
        "    (oaModBusTermBit)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaModBusTermBit_tp_dealloc(PyoaModBusTermBitObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaModBusTermBit_tp_repr(PyObject *ob)
{
    PyParamoaModBusTermBit value;
    int convert_status=PyoaModBusTermBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaModBusTermBit::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[37];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaModBusTermBit::");
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
oaModBusTermBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaModBusTermBit v1;
    PyParamoaModBusTermBit v2;
    int convert_status1=PyoaModBusTermBit_Convert(ob1,&v1);
    int convert_status2=PyoaModBusTermBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaModBusTermBit_Convert(PyObject* ob,PyParamoaModBusTermBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaModBusTermBit_Check(ob)) {
        result->SetData( (oaModBusTermBit**) ((PyoaModBusTermBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaModBusTermBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaModBusTermBit_FromoaModBusTermBit(oaModBusTermBit** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaModBusTermBit* data=*value;
        PyObject* bself = PyoaModBusTermBit_Type.tp_alloc(&PyoaModBusTermBit_Type,0);
        if (bself == NULL) return bself;
        PyoaModBusTermBitObject* self = (PyoaModBusTermBitObject*)bself;
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
PyObject* PyoaModBusTermBit_FromoaModBusTermBit(oaModBusTermBit* data)
{
    if (data) {
       PyObject* bself = PyoaModBusTermBit_Type.tp_alloc(&PyoaModBusTermBit_Type,0);
       if (bself == NULL) return bself;
       PyoaModBusTermBitObject* self = (PyoaModBusTermBitObject*)bself;
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
static char oaModBusTermBit_getBitIndex_doc[] = 
"Class: oaModBusTermBit, Function: getBitIndex\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getBitIndex() const\n"
"    Signature: getBitIndex|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the index for this busTermBit.\n"
;

static PyObject*
oaModBusTermBit_getBitIndex(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusTermBit data;
    int convert_status=PyoaModBusTermBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusTermBitObject* self=(PyoaModBusTermBitObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getBitIndex());
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
static char oaModBusTermBit_getDef_doc[] = 
"Class: oaModBusTermBit, Function: getDef\n"
"  Paramegers: ()\n"
"    Calls: oaModBusTermDef* getDef() const\n"
"    Signature: getDef|ptr-oaModBusTermDef|\n"
"    BrowseData: 1\n"
"    This function returns the modBusTermDef associated with this terminal.\n"
;

static PyObject*
oaModBusTermBit_getDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusTermBit data;
    int convert_status=PyoaModBusTermBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusTermBitObject* self=(PyoaModBusTermBitObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusTermDefp result= (data.DataCall()->getDef());
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
static char oaModBusTermBit_getName_doc[] = 
"Class: oaModBusTermBit, Function: getName\n"
"  Paramegers: (oaVectorBitName)\n"
"    Calls: void getName(oaVectorBitName& name) const\n"
"    Signature: getName|void-void|ref-oaVectorBitName,\n"
"    BrowseData: 0,oaVectorBitName\n"
"    This function returns the name of this modBusTermBit.\n"
"    name\n"
"    The name of the modBusTermBit to return\n"
"  Paramegers: (oaName)\n"
"    Calls: void getName(oaName& name) const\n"
"    Signature: getName|void-void|ref-oaName,\n"
"    BrowseData: 0,oaName\n"
"    This function fills out name with the name of this terminal.\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getName(const oaNameSpace& ns,oaString& name) const\n"
"    Signature: getName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function fills in name with the name of this terminal mapped to the specified nameSpace.\n"
;

static PyObject*
oaModBusTermBit_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusTermBit data;
    int convert_status=PyoaModBusTermBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusTermBitObject* self=(PyoaModBusTermBitObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaVectorBitName)
    {
        PyParamoaVectorBitName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaVectorBitName_Convert,&p1)) {
            data.DataCall()->getName(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaName)
    {
        PyParamoaName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaName_Convert,&p1)) {
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
        "No Arg-Matching Function found for class: oaModBusTermBit, function: getName, Choices are:\n"
        "    (oaVectorBitName)\n"
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
static char oaModBusTermBit_setName_doc[] = 
"Class: oaModBusTermBit, Function: setName\n"
"  Paramegers: (oaScalarName,oaUInt4)\n"
"    Calls: void setName(const oaScalarName& baseName,oaUInt4 bitIndex)\n"
"    Signature: setName|void-void|cref-oaScalarName,simple-oaUInt4,\n"
"    This function changes the name of this busTermBit to that implied by the given baseName and bitIndex .\n"
"    baseName\n"
"    The new base name for this net\n"
"    bitIndex\n"
"    The new bit index for this net\n"
"    oacCannotSetNameOfImplicitTerm\n"
"    oacCannotSetNameOfTermInBundleTerm\n"
"    oacBusTermBaseNameMatchesScalarName\n"
"    oacTermExists\n"
;

static PyObject*
oaModBusTermBit_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBusTermBit data;
    int convert_status=PyoaModBusTermBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaModBusTermBitObject* self=(PyoaModBusTermBitObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaScalarName p1;
    PyParamoaUInt4 p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaScalarName_Convert,&p1,
          &PyoaUInt4_Convert,&p2)) {
        data.DataCall()->setName(p1.Data(),p2.Data());
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
static char oaModBusTermBit_isNull_doc[] =
"Class: oaModBusTermBit, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaModBusTermBit_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaModBusTermBit data;
    int convert_status=PyoaModBusTermBit_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaModBusTermBit_assign_doc[] = 
"Class: oaModBusTermBit, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaModBusTermBit_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaModBusTermBit data;
  int convert_status=PyoaModBusTermBit_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaModBusTermBit p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaModBusTermBit_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaModBusTermBit_methodlist[] = {
    {"getBitIndex",(PyCFunction)oaModBusTermBit_getBitIndex,METH_VARARGS,oaModBusTermBit_getBitIndex_doc},
    {"getDef",(PyCFunction)oaModBusTermBit_getDef,METH_VARARGS,oaModBusTermBit_getDef_doc},
    {"getName",(PyCFunction)oaModBusTermBit_getName,METH_VARARGS,oaModBusTermBit_getName_doc},
    {"setName",(PyCFunction)oaModBusTermBit_setName,METH_VARARGS,oaModBusTermBit_setName_doc},
    {"isNull",(PyCFunction)oaModBusTermBit_tp_isNull,METH_VARARGS,oaModBusTermBit_isNull_doc},
    {"assign",(PyCFunction)oaModBusTermBit_tp_assign,METH_VARARGS,oaModBusTermBit_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModBusTermBit_doc[] = 
"Class: oaModBusTermBit\n"
"  The oaModBusTermBit class implements an oaModBitNet that represents a single bit of an oaModBusTerm , a busTerm in the module domain. When an oaModBusTerm is created, a corresponding set of oaModBusTermBit objects is automatically created. When the busTerm is destroyed, the automatically created busTermBits are also destroyed.\n"
"  An oaModBusTermBit can be explicitly created. An explicitly created busTermBit must be explicitly destroyed.\n"
"  oaModBusTermBit, oaOccBusTermBit , and oaBusTermBit each represent a bit of a busTerminal on a different kind of master, where in each case the master represents a level of hierarchy in the design.\n"
"  For oaModBusTermBit, the master is a module, and each module in a design will have a set of zero or more oaModBusTermBits. For oaOccBusTermBit , the master is an oaOccurrence .\n"
"  For oaBusTerm , the master is an oaBlock , and the top block for the design will have a set of zero or more modBusTermBits. Typically, many of the oaBusTermBits on the top oaBlock have a corresponding oaModBusTermBit on the top oaModule . All of the oaBusTermBits on the top oaBlock have a corresponding oaOccBusTermBit on the top oaOccurrence .\n"
"  When oaBusTermBit objects are created in the block domain, the corresponding oaModBusTermBit objects are automatically created on the top oaModule .\n"
"Constructors:\n"
"  Paramegers: (oaModBusTermBit)\n"
"    Calls: (const oaModBusTermBit&)\n"
"    Signature: oaModBusTermBit||cref-oaModBusTermBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaModBusTermBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaModBusTermBit",
    sizeof(PyoaModBusTermBitObject),
    0,
    (destructor)oaModBusTermBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaModBusTermBit_tp_compare,	/* tp_compare */
    (reprfunc)oaModBusTermBit_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaModBusTermBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaModBusTermBit_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaModBitTerm_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaModBusTermBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaModBusTermBit_static_create_doc[] = 
"Class: oaModBusTermBit, Function: create\n"
"  Paramegers: (oaModBitNet,oaScalarName,oaUInt4)\n"
"    Calls: oaModBusTermBit* create(oaModBitNet* modNet,const oaScalarName& baseName,oaUInt4 bitIndex)\n"
"    Signature: create|ptr-oaModBusTermBit|ptr-oaModBitNet,cref-oaScalarName,simple-oaUInt4,simple-oaTermType,\n"
"    This function creates a busTermBit with the specified baseName and bitIndex in the given module net.\n"
"    modNet\n"
"    The module net to create the terminal on\n"
"    baseName\n"
"    The base name to give the terminal\n"
"    bitIndex\n"
"    The bit index to give the terminal\n"
"    type\n"
"    The terminal type to give the terminal\n"
"    oacBusTermBaseNameMatchesScalarName\n"
"    oacTermExists\n"
"    oacTermMemberExists\n"
"    oacCannotCreateTermWithImplicitNet\n"
"  Paramegers: (oaModBitNet,oaScalarName,oaUInt4,oaTermType)\n"
"    Calls: oaModBusTermBit* create(oaModBitNet* modNet,const oaScalarName& baseName,oaUInt4 bitIndex,oaTermType type)\n"
"    Signature: create|ptr-oaModBusTermBit|ptr-oaModBitNet,cref-oaScalarName,simple-oaUInt4,simple-oaTermType,\n"
"    This function creates a busTermBit with the specified baseName and bitIndex in the given module net.\n"
"    modNet\n"
"    The module net to create the terminal on\n"
"    baseName\n"
"    The base name to give the terminal\n"
"    bitIndex\n"
"    The bit index to give the terminal\n"
"    type\n"
"    The terminal type to give the terminal\n"
"    oacBusTermBaseNameMatchesScalarName\n"
"    oacTermExists\n"
"    oacTermMemberExists\n"
"    oacCannotCreateTermWithImplicitNet\n"
"  Paramegers: (oaModBitNet,oaVectorBitName)\n"
"    Calls: oaModBusTermBit* create(oaModBitNet* modNet,const oaVectorBitName& bitName)\n"
"    Signature: create|ptr-oaModBusTermBit|ptr-oaModBitNet,cref-oaVectorBitName,simple-oaTermType,\n"
"    This function creates a busTermBit with the baseName as specified by bitName on the given modNet .\n"
"    modNet\n"
"    The module net to create the terminal on\n"
"    bitName\n"
"    The name specifying the baseName and bitIndex to give the terminal\n"
"    type\n"
"    The terminal type to give the terminal\n"
"    oacBusTermBaseNameMatchesScalarName\n"
"    oacTermExists\n"
"    oacTermMemberExists\n"
"    oacCannotCreateTermWithImplicitNet\n"
"  Paramegers: (oaModBitNet,oaVectorBitName,oaTermType)\n"
"    Calls: oaModBusTermBit* create(oaModBitNet* modNet,const oaVectorBitName& bitName,oaTermType type)\n"
"    Signature: create|ptr-oaModBusTermBit|ptr-oaModBitNet,cref-oaVectorBitName,simple-oaTermType,\n"
"    This function creates a busTermBit with the baseName as specified by bitName on the given modNet .\n"
"    modNet\n"
"    The module net to create the terminal on\n"
"    bitName\n"
"    The name specifying the baseName and bitIndex to give the terminal\n"
"    type\n"
"    The terminal type to give the terminal\n"
"    oacBusTermBaseNameMatchesScalarName\n"
"    oacTermExists\n"
"    oacTermMemberExists\n"
"    oacCannotCreateTermWithImplicitNet\n"
;

static PyObject*
oaModBusTermBit_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaModBitNet,oaScalarName,oaUInt4)
    {
        PyParamoaModBitNet p1;
        PyParamoaScalarName p2;
        PyParamoaUInt4 p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaModBitNet_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaUInt4_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusTermBitp result= (oaModBusTermBit::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaModBusTermBit_FromoaModBusTermBit(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModBitNet,oaScalarName,oaUInt4,oaTermType)
    {
        PyParamoaModBitNet p1;
        PyParamoaScalarName p2;
        PyParamoaUInt4 p3;
        PyParamoaTermType p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaModBitNet_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaUInt4_Convert,&p3,
              &PyoaTermType_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusTermBitp result= (oaModBusTermBit::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaModBusTermBit_FromoaModBusTermBit(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModBitNet,oaVectorBitName)
    {
        PyParamoaModBitNet p1;
        PyParamoaVectorBitName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaModBitNet_Convert,&p1,
              &PyoaVectorBitName_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusTermBitp result= (oaModBusTermBit::create(p1.Data(),p2.Data()));
            return PyoaModBusTermBit_FromoaModBusTermBit(result);
        }
    }
    PyErr_Clear();
    // Case: (oaModBitNet,oaVectorBitName,oaTermType)
    {
        PyParamoaModBitNet p1;
        PyParamoaVectorBitName p2;
        PyParamoaTermType p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaModBitNet_Convert,&p1,
              &PyoaVectorBitName_Convert,&p2,
              &PyoaTermType_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaModBusTermBitp result= (oaModBusTermBit::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaModBusTermBit_FromoaModBusTermBit(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaModBusTermBit, function: create, Choices are:\n"
        "    (oaModBitNet,oaScalarName,oaUInt4)\n"
        "    (oaModBitNet,oaScalarName,oaUInt4,oaTermType)\n"
        "    (oaModBitNet,oaVectorBitName)\n"
        "    (oaModBitNet,oaVectorBitName,oaTermType)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaModBusTermBit_static_find_doc[] = 
"Class: oaModBusTermBit, Function: find\n"
"  Paramegers: (oaModule,oaScalarName,oaUInt4)\n"
"    Calls: oaModBusTermBit* find(const oaModule* module,const oaScalarName& baseName,oaUInt4 bitIndex)\n"
"    Signature: find|ptr-oaModBusTermBit|cptr-oaModule,cref-oaScalarName,simple-oaUInt4,\n"
"    This function searches the specified module for a busTermBit with the specified baseName and bitIndex . The busTermBit is returned if found. Otherwise, NULL is returned.\n"
"    module\n"
"    The module to search for the busTermBit\n"
"    baseName\n"
"    The base name for the busTermBit\n"
"    bitIndex\n"
"    The bit index for the busTermBit\n"
"    A pointer to an oaModBusTermBit\n"
;

static PyObject*
oaModBusTermBit_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModule p1;
    PyParamoaScalarName p2;
    PyParamoaUInt4 p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaModule_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaUInt4_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaModBusTermBitp result= (oaModBusTermBit::find(p1.Data(),p2.Data(),p3.Data()));
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
static char oaModBusTermBit_static_isValidName_doc[] = 
"Class: oaModBusTermBit, Function: isValidName\n"
"  Paramegers: (oaModBitNet,oaScalarName,oaUInt4)\n"
"    Calls: oaBoolean isValidName(const oaModBitNet* net,const oaScalarName& baseName,oaUInt4 bitIndex)\n"
"    Signature: isValidName|simple-oaBoolean|cptr-oaModBitNet,cref-oaScalarName,simple-oaUInt4,\n"
"    This function returns a boolean value indicating whether the specified name is valid for a new oaBusTermBit in the specified module net.\n"
"    net\n"
"    The module net to search\n"
"    baseName\n"
"    The base name of the bus bit\n"
"    bitIndex\n"
"    The bit index of the bus bit\n"
;

static PyObject*
oaModBusTermBit_static_isValidName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaModBitNet p1;
    PyParamoaScalarName p2;
    PyParamoaUInt4 p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaModBitNet_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaUInt4_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaBoolean result= (oaModBusTermBit::isValidName(p1.Data(),p2.Data(),p3.Data()));
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
static PyMethodDef oaModBusTermBit_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaModBusTermBit_static_create,METH_VARARGS,oaModBusTermBit_static_create_doc},
    {"static_find",(PyCFunction)oaModBusTermBit_static_find,METH_VARARGS,oaModBusTermBit_static_find_doc},
    {"static_isValidName",(PyCFunction)oaModBusTermBit_static_isValidName,METH_VARARGS,oaModBusTermBit_static_isValidName_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaModBusTermBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaModBusTermBit_Type)<0) {
      printf("** PyType_Ready failed for: oaModBusTermBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaModBusTermBit",
           (PyObject*)(&PyoaModBusTermBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaModBusTermBit\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaModBusTermBit_Type.tp_dict;
    for(method=oaModBusTermBit_staticmethodlist;method->ml_name!=NULL;method++) {
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

