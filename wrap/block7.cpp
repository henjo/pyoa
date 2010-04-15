
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCellViewDMData
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCellViewDMData_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCellViewDMData_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCellViewDMDataObject* self = (PyoaCellViewDMDataObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCellViewDMData)
    {
        PyParamoaCellViewDMData p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaCellViewDMData_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaCellViewDMData, Choices are:\n"
        "    (oaCellViewDMData)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCellViewDMData_tp_dealloc(PyoaCellViewDMDataObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCellViewDMData_tp_repr(PyObject *ob)
{
    PyParamoaCellViewDMData value;
    int convert_status=PyoaCellViewDMData_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaCellViewDMData::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCellViewDMData_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCellViewDMData v1;
    PyParamoaCellViewDMData v2;
    int convert_status1=PyoaCellViewDMData_Convert(ob1,&v1);
    int convert_status2=PyoaCellViewDMData_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCellViewDMData_Convert(PyObject* ob,PyParamoaCellViewDMData* result)
{
    if (ob == NULL) return 1;
    if (PyoaCellViewDMData_Check(ob)) {
        result->SetData( (oaCellViewDMData**) ((PyoaCellViewDMDataObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCellViewDMData Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCellViewDMData_FromoaCellViewDMData(oaCellViewDMData** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaCellViewDMData* data=*value;
        PyObject* bself = PyoaCellViewDMData_Type.tp_alloc(&PyoaCellViewDMData_Type,0);
        if (bself == NULL) return bself;
        PyoaCellViewDMDataObject* self = (PyoaCellViewDMDataObject*)bself;
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
PyObject* PyoaCellViewDMData_FromoaCellViewDMData(oaCellViewDMData* data)
{
    if (data) {
       PyObject* bself = PyoaCellViewDMData_Type.tp_alloc(&PyoaCellViewDMData_Type,0);
       if (bself == NULL) return bself;
       PyoaCellViewDMDataObject* self = (PyoaCellViewDMDataObject*)bself;
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
static char oaCellViewDMData_getCellName_doc[] = 
"Class: oaCellViewDMData, Function: getCellName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getCellName(oaScalarName& cellName) const\n"
"    Signature: getCellName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the cell name for this CellDMData object.\n"
"    cellName\n"
"    the returned oaScalarName cell name\n"
"    oacInvalidCellView\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getCellName(const oaNameSpace& ns,oaString& cellName) const\n"
"    Signature: getCellName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns name for this oaCellViewDMData object as an oaString in the specified namespace.\n"
"    ns\n"
"    input parameter - the nameSpace in which to return the cell name\n"
"    cellName\n"
"    the returned oaString cell name\n"
"    oacInvalidCellView\n"
;

static PyObject*
oaCellViewDMData_getCellName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCellViewDMData data;
    int convert_status=PyoaCellViewDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCellViewDMDataObject* self=(PyoaCellViewDMDataObject*)ob;
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
        "No Arg-Matching Function found for class: oaCellViewDMData, function: getCellName, Choices are:\n"
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
static char oaCellViewDMData_getViewName_doc[] = 
"Class: oaCellViewDMData, Function: getViewName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getViewName(oaScalarName& viewName) const\n"
"    Signature: getViewName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the view name for this oaCellViewDMData object.\n"
"    viewName\n"
"    the returned oaScalarName view name\n"
"    oacInvalidCellView\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getViewName(const oaNameSpace& ns,oaString& viewName) const\n"
"    Signature: getViewName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the view name for this oaCellViewDMData object in the specified nameSpace.\n"
"    ns\n"
"    input parameter - the namespace in which to return the view name\n"
"    viewName\n"
"    the returned oaString view name\n"
"    oacInvalidCellView\n"
;

static PyObject*
oaCellViewDMData_getViewName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCellViewDMData data;
    int convert_status=PyoaCellViewDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCellViewDMDataObject* self=(PyoaCellViewDMDataObject*)ob;
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
        "No Arg-Matching Function found for class: oaCellViewDMData, function: getViewName, Choices are:\n"
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
static char oaCellViewDMData_getViewType_doc[] = 
"Class: oaCellViewDMData, Function: getViewType\n"
"  Paramegers: ()\n"
"    Calls: oaViewType* getViewType() const\n"
"    Signature: getViewType|ptr-oaViewType|\n"
"    BrowseData: 1\n"
"    This function returns the view type for this oaCellViewDMData object.\n"
"    oacInvalidCellView\n"
;

static PyObject*
oaCellViewDMData_getViewType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCellViewDMData data;
    int convert_status=PyoaCellViewDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCellViewDMDataObject* self=(PyoaCellViewDMDataObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaViewTypep result= (data.DataCall()->getViewType());
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
static char oaCellViewDMData_isNull_doc[] =
"Class: oaCellViewDMData, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaCellViewDMData_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaCellViewDMData data;
    int convert_status=PyoaCellViewDMData_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaCellViewDMData_assign_doc[] = 
"Class: oaCellViewDMData, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCellViewDMData_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCellViewDMData data;
  int convert_status=PyoaCellViewDMData_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCellViewDMData p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCellViewDMData_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCellViewDMData_methodlist[] = {
    {"getCellName",(PyCFunction)oaCellViewDMData_getCellName,METH_VARARGS,oaCellViewDMData_getCellName_doc},
    {"getViewName",(PyCFunction)oaCellViewDMData_getViewName,METH_VARARGS,oaCellViewDMData_getViewName_doc},
    {"getViewType",(PyCFunction)oaCellViewDMData_getViewType,METH_VARARGS,oaCellViewDMData_getViewType_doc},
    {"isNull",(PyCFunction)oaCellViewDMData_tp_isNull,METH_VARARGS,oaCellViewDMData_isNull_doc},
    {"assign",(PyCFunction)oaCellViewDMData_tp_assign,METH_VARARGS,oaCellViewDMData_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCellViewDMData_doc[] = 
"Class: oaCellViewDMData\n"
"  oaCellViewDMData objects represent database objects that can be associated with a DM cellView and can be used to persistently store properties ( oaProp objects), groups ( oaGroup objects), group members ( oaGroupMember objects) and application objects (see oaAppObject ).\n"
"Constructors:\n"
"  Paramegers: (oaCellViewDMData)\n"
"    Calls: (const oaCellViewDMData&)\n"
"    Signature: oaCellViewDMData||cref-oaCellViewDMData,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCellViewDMData_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCellViewDMData",
    sizeof(PyoaCellViewDMDataObject),
    0,
    (destructor)oaCellViewDMData_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCellViewDMData_tp_compare,	/* tp_compare */
    (reprfunc)oaCellViewDMData_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCellViewDMData_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCellViewDMData_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDMData_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCellViewDMData_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCellViewDMData_static_destroy_doc[] = 
"Class: oaCellViewDMData, Function: destroy\n"
"  Paramegers: (oaScalarName,oaScalarName,oaScalarName)\n"
"    Calls: void destroy(const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName)\n"
"    Signature: destroy|void-void|cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,\n"
"    This function attempts to remove the CellViewDMData object associated with the given library, cellName and viewName from disk. It throws an exception if the CellViewDMData is currently open or if the CellViewDMData cannot be found on disk.\n"
"    libName\n"
"    the name of the library associated with the DM Data\n"
"    cellName\n"
"    the name of the cell\n"
"    viewName\n"
"    the name of the view\n"
"    oacDestroyDMDataOpen\n"
"    oacDestroyDMDataDoesNotExist\n"
"    oacDMDataCannotGetWriteAccess\n"
;

static PyObject*
oaCellViewDMData_static_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarName p1;
    PyParamoaScalarName p2;
    PyParamoaScalarName p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaScalarName_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaScalarName_Convert,&p3)) {
        oaCellViewDMData::destroy(p1.Data(),p2.Data(),p3.Data());
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
static char oaCellViewDMData_static_exists_doc[] = 
"Class: oaCellViewDMData, Function: exists\n"
"  Paramegers: (oaScalarName,oaScalarName,oaScalarName)\n"
"    Calls: oaBoolean exists(const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName)\n"
"    Signature: exists|simple-oaBoolean|cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,\n"
"    This function returns a boolean that indicates if there is a CellViewDMData object open for the given library, cellName and viewName, or if a CellViewDMData file exists on disk with a non-zero size.\n"
"    libName\n"
"    the name of the library associated with the DM Data\n"
"    cellName\n"
"    the name of the cell\n"
"    viewName\n"
"    the name of the view\n"
;

static PyObject*
oaCellViewDMData_static_exists(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarName p1;
    PyParamoaScalarName p2;
    PyParamoaScalarName p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaScalarName_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaScalarName_Convert,&p3)) {
        oaBoolean result= (oaCellViewDMData::exists(p1.Data(),p2.Data(),p3.Data()));
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
static char oaCellViewDMData_static_find_doc[] = 
"Class: oaCellViewDMData, Function: find\n"
"  Paramegers: (oaScalarName,oaScalarName,oaScalarName)\n"
"    Calls: oaCellViewDMData* find(const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName)\n"
"    Signature: find|ptr-oaCellViewDMData|cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,\n"
"    This function attempts to find an open CellViewDMData for the given library, cellName and viewName. If successful, a pointer to the DMData object is returned; otherwise, NULL is returned.\n"
"    libName\n"
"    the name of the library associated with the DM Data\n"
"    cellName\n"
"    the name of the cell\n"
"    viewName\n"
"    the name of the view\n"
;

static PyObject*
oaCellViewDMData_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarName p1;
    PyParamoaScalarName p2;
    PyParamoaScalarName p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaScalarName_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaScalarName_Convert,&p3)) {
        oaCellViewDMDatap result= (oaCellViewDMData::find(p1.Data(),p2.Data(),p3.Data()));
        return PyoaCellViewDMData_FromoaCellViewDMData(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCellViewDMData_static_open_doc[] = 
"Class: oaCellViewDMData, Function: open\n"
"  Paramegers: (oaScalarName,oaScalarName,oaScalarName,oaViewType,oaChar)\n"
"    Calls: oaCellViewDMData* open(const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName,const oaViewType* viewType,oaChar mode)\n"
"    Signature: open|ptr-oaCellViewDMData|cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cptr-oaViewType,simple-oaChar,\n"
"    This function attempts to open the DM data for the cellView specified with libName , cellName , viewName and viewType in the specified mode. If the mode is not 'r'ead-only mode, the cell and view will be created if they did not exist prior to this open() call. In the 'r'ead-only mode, the specified cellView and its owners must exist, otherwise an oacCellViewOwnerDoesNotExist exception is thrown. Also, for existing cellViews, the viewType specified must match the existing view's viewType for the open to be successful. An exception is thrown otherwise. If successful, a pointer to the CellViewDMData object is returned.\n"
"    libName\n"
"    the name of the library associated with the DM Data\n"
"    cellName\n"
"    the name of the cell associated with the DM Data\n"
"    viewName\n"
"    the name of the view associated with the DM Data\n"
"    viewType\n"
"    the viewType of the cellView associated with the DM Data\n"
"    mode\n"
"    'read-only,' 'a'ppend, or 'w'rite mode in which to access the DMData; 'a'ppend and 'w'rite mode attempt to obtain write access to data; 'a'ppend retains any existing LibDMData; while'w'rite deletes (truncates) any existing DMData\n"
"    oacOpenUndefinedModeDMData\n"
"    undefined mode (must be 'r'ead-only, 'w'rite or 'a'ppend)\n"
"    oacCellViewOwnerDoesNotExist\n"
"    read mode specified, but either or both the cell and view owners do not exist\n"
"    oacLibNotFound\n"
"    the library with the specified name could not be found\n"
"    oacDMDataCannotGetReadAccess\n"
"    requested read access to the DMData could not be obtained\n"
"    oacDMDataHasReadNeedWriteAccess\n"
"    write access was requested but read access exists on DMData\n"
"    oacDMDataCannotGetWriteAccess\n"
"    requested write access to the DMData could not be obtained\n"
"    oacOpenOnDMDataBeingPurged\n"
"    attempt to open DMData while DMData is being purged\n"
"    oacDMDataDoesNotExist\n"
"    read access requested, but DMData does not exist\n"
"    oacCannotLockDMData\n"
"    write access specified, but cannot get a write lock on the file\n"
"  Paramegers: (oaScalarName,oaScalarName,oaScalarName,oaChar)\n"
"    Calls: oaCellViewDMData* open(const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName,oaChar mode)\n"
"    Signature: open|ptr-oaCellViewDMData|cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,simple-oaChar,\n"
"    This function attempts to open the oaCellViewDMData object for the cellView identified by the specified library, cell and view names with the specified mode. If the specified mode is a write-access mode ('a'ppend or 'w'rite mode) and the oaCellViewDMData does not exist, it will be created. If the specified mode is a read-access mode ('r'ead-only mode) and the oaCellViewDMData does not exist, an oacDMDataDoesNotExist exception will be thrown.\n"
"    If successful, a pointer to the CellViewDMData object is returned.\n"
"    libName\n"
"    the name of the library associated with the DM Data\n"
"    cellName\n"
"    the name of the cell associated with the DM Data\n"
"    viewName\n"
"    the name of the view associated with the DM Data\n"
"    mode\n"
"    'read-only,' 'a'ppend, or 'w'rite mode in which to access the DMData; 'a'ppend and 'w'rite mode attempt to obtain write access to data; 'a'ppend retains any existing LibDMData; while'w'rite deletes (truncates) any existing DMData\n"
"    oacOpenUndefinedModeDMData\n"
"    oacLibNotFound\n"
"    oacDMDataCannotGetReadAccess\n"
"    oacDMDataHasReadNeedWriteAccess\n"
"    oacDMDataCannotGetWriteAccess\n"
"    oacCellViewOwnerDoesNotExist\n"
;

static PyObject*
oaCellViewDMData_static_open(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaScalarName,oaScalarName,oaScalarName,oaViewType,oaChar)
    {
        PyParamoaScalarName p1;
        PyParamoaScalarName p2;
        PyParamoaScalarName p3;
        PyParamoaViewType p4;
        PyParamoaChar p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaScalarName_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaScalarName_Convert,&p3,
              &PyoaViewType_Convert,&p4,
              &PyoaChar_Convert,&p5)) {
            if (!PyValidateDbObject(p4.Data(),4)) return NULL;
            oaCellViewDMDatap result= (oaCellViewDMData::open(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaCellViewDMData_FromoaCellViewDMData(result);
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
            oaCellViewDMDatap result= (oaCellViewDMData::open(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaCellViewDMData_FromoaCellViewDMData(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaCellViewDMData, function: open, Choices are:\n"
        "    (oaScalarName,oaScalarName,oaScalarName,oaViewType,oaChar)\n"
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
static PyMethodDef oaCellViewDMData_staticmethodlist[] = {
    {"static_destroy",(PyCFunction)oaCellViewDMData_static_destroy,METH_VARARGS,oaCellViewDMData_static_destroy_doc},
    {"static_exists",(PyCFunction)oaCellViewDMData_static_exists,METH_VARARGS,oaCellViewDMData_static_exists_doc},
    {"static_find",(PyCFunction)oaCellViewDMData_static_find,METH_VARARGS,oaCellViewDMData_static_find_doc},
    {"static_open",(PyCFunction)oaCellViewDMData_static_open,METH_VARARGS,oaCellViewDMData_static_open_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCellViewDMData_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCellViewDMData_Type)<0) {
      printf("** PyType_Ready failed for: oaCellViewDMData\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCellViewDMData",
           (PyObject*)(&PyoaCellViewDMData_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCellViewDMData\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaCellViewDMData_Type.tp_dict;
    for(method=oaCellViewDMData_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaCellViewModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaCellViewModTypeEnum_Convert(PyObject* ob,PyParamoaCellViewModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetViewCellViewModType")==0) { result->SetData(oacSetViewCellViewModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaCellViewModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCellViewModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaCellViewModTypeEnum_FromoaCellViewModTypeEnum(oaCellViewModTypeEnum ob)
{
    if (ob==oacSetViewCellViewModType) return PyString_FromString("oacSetViewCellViewModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaCellViewModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaCellViewModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaCellViewModTypeEnum_FromoaCellViewModTypeEnum(oaCellViewModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaCellViewModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaCellViewModTypeEnum_doc[] =
"Type convert function for enum: oaCellViewModTypeEnum";
                               
static PyMethodDef PyoaCellViewModTypeEnum_method =
  {"oaCellViewModTypeEnum",(PyCFunction)PyoaCellViewModTypeEnum_TypeFunction,METH_VARARGS,oaCellViewModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaCellViewModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetViewCellViewModType");
    PyDict_SetItemString(mod_dict,"oacSetViewCellViewModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaCellViewModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaCellViewModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaCellViewModTypeEnum\n");
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
// Wrapper Implementation for Class: oaClearanceMeasure
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaClearanceMeasure_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaClearanceMeasure_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaClearanceMeasureObject* self = (PyoaClearanceMeasureObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaClearanceMeasureEnum)
    {
        PyParamoaClearanceMeasureEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaClearanceMeasureEnum_Convert,&p1)) {
            self->value =  new oaClearanceMeasure(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaClearanceMeasure(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaClearanceMeasure)
    {
        PyParamoaClearanceMeasure p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaClearanceMeasure_Convert,&p1)) {
            self->value= new oaClearanceMeasure(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaClearanceMeasure, Choices are:\n"
        "    (oaClearanceMeasureEnum)\n"
        "    (oaString)\n"
        "    (oaClearanceMeasure)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaClearanceMeasure_tp_dealloc(PyoaClearanceMeasureObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaClearanceMeasure_tp_repr(PyObject *ob)
{
    PyParamoaClearanceMeasure value;
    int convert_status=PyoaClearanceMeasure_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[40];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaClearanceMeasure::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaClearanceMeasure_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaClearanceMeasure v1;
    PyParamoaClearanceMeasure v2;
    int convert_status1=PyoaClearanceMeasure_Convert(ob1,&v1);
    int convert_status2=PyoaClearanceMeasure_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaClearanceMeasure_Convert(PyObject* ob,PyParamoaClearanceMeasure* result)
{
    if (ob == NULL) return 1;
    if (PyoaClearanceMeasure_Check(ob)) {
        result->SetData(  ((PyoaClearanceMeasureObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaClearanceMeasure Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaClearanceMeasure_FromoaClearanceMeasure(oaClearanceMeasure* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaClearanceMeasure_Type.tp_alloc(&PyoaClearanceMeasure_Type,0);
        if (bself == NULL) return bself;
        PyoaClearanceMeasureObject* self = (PyoaClearanceMeasureObject*)bself;
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
static char oaClearanceMeasure_getName_doc[] = 
"Class: oaClearanceMeasure, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaClearanceMeasureEnum object.\n"
;

static PyObject*
oaClearanceMeasure_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaClearanceMeasure data;
    int convert_status=PyoaClearanceMeasure_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClearanceMeasureObject* self=(PyoaClearanceMeasureObject*)ob;

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
static char oaClearanceMeasure_oaClearanceMeasureEnum_doc[] = 
"Class: oaClearanceMeasure, Function: oaClearanceMeasureEnum\n"
"  Paramegers: ()\n"
"    Calls: oaClearanceMeasureEnum oaClearanceMeasureEnum() const\n"
"    Signature: operator oaClearanceMeasureEnum|simple-oaClearanceMeasureEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaClearanceMeasure object into the corresponding #oaClearanceMeasureEnum value.\n"
;

static PyObject*
oaClearanceMeasure_oaClearanceMeasureEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaClearanceMeasure data;
    int convert_status=PyoaClearanceMeasure_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClearanceMeasureObject* self=(PyoaClearanceMeasureObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaClearanceMeasureEnum result= (data.DataCall()->operator oaClearanceMeasureEnum());
        return PyoaClearanceMeasureEnum_FromoaClearanceMeasureEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaClearanceMeasure_assign_doc[] = 
"Class: oaClearanceMeasure, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaClearanceMeasure_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaClearanceMeasure data;
  int convert_status=PyoaClearanceMeasure_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaClearanceMeasure p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaClearanceMeasure_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaClearanceMeasure_methodlist[] = {
    {"getName",(PyCFunction)oaClearanceMeasure_getName,METH_VARARGS,oaClearanceMeasure_getName_doc},
    {"oaClearanceMeasureEnum",(PyCFunction)oaClearanceMeasure_oaClearanceMeasureEnum,METH_VARARGS,oaClearanceMeasure_oaClearanceMeasureEnum_doc},
    {"assign",(PyCFunction)oaClearanceMeasure_tp_assign,METH_VARARGS,oaClearanceMeasure_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaClearanceMeasure_doc[] = 
"Class: oaClearanceMeasure\n"
"  The oaClearanceMeasure class encapsulates the enumerated values that describe the different types of clearance measurements.\n"
"  oaClearanceMeasureEnum\n"
"Constructors:\n"
"  Paramegers: (oaClearanceMeasureEnum)\n"
"    Calls: oaClearanceMeasure(oaClearanceMeasureEnum valueIn)\n"
"    Signature: oaClearanceMeasure||simple-oaClearanceMeasureEnum,\n"
"    This function constructs an instance of an oaClearanceMeasure class using the specified #oaClearanceMeasureEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaClearanceMeasure(const oaString& name)\n"
"    Signature: oaClearanceMeasure||cref-oaString,\n"
"    This function constructs an instance of an oaClearanceMeasure class using the #oaClearanceMeasureEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaClearanceMeasureEnum.\n"
"    oacInvalidClearanceMeasureTypeName\n"
"  Paramegers: (oaClearanceMeasure)\n"
"    Calls: (const oaClearanceMeasure&)\n"
"    Signature: oaClearanceMeasure||cref-oaClearanceMeasure,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaClearanceMeasure_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaClearanceMeasure",
    sizeof(PyoaClearanceMeasureObject),
    0,
    (destructor)oaClearanceMeasure_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaClearanceMeasure_tp_compare,	/* tp_compare */
    (reprfunc)oaClearanceMeasure_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaClearanceMeasure_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaClearanceMeasure_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaClearanceMeasure_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaClearanceMeasure_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaClearanceMeasure_Type)<0) {
      printf("** PyType_Ready failed for: oaClearanceMeasure\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaClearanceMeasure",
           (PyObject*)(&PyoaClearanceMeasure_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaClearanceMeasure\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaClearanceMeasureEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaClearanceMeasureEnum_Convert(PyObject* ob,PyParamoaClearanceMeasureEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacEuclidianClearanceMeasure")==0) { result->SetData(oacEuclidianClearanceMeasure); return 1;}
        if (strcasecmp(str,"oacMaxXYClearanceMeasure")==0) { result->SetData(oacMaxXYClearanceMeasure); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaClearanceMeasureEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaClearanceMeasureEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaClearanceMeasureEnum_FromoaClearanceMeasureEnum(oaClearanceMeasureEnum ob)
{
    if (ob==oacEuclidianClearanceMeasure) return PyString_FromString("oacEuclidianClearanceMeasure");
    if (ob==oacMaxXYClearanceMeasure) return PyString_FromString("oacMaxXYClearanceMeasure");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaClearanceMeasureEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaClearanceMeasureEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaClearanceMeasureEnum_FromoaClearanceMeasureEnum(oaClearanceMeasureEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaClearanceMeasureEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaClearanceMeasureEnum_doc[] =
"Type convert function for enum: oaClearanceMeasureEnum";
                               
static PyMethodDef PyoaClearanceMeasureEnum_method =
  {"oaClearanceMeasureEnum",(PyCFunction)PyoaClearanceMeasureEnum_TypeFunction,METH_VARARGS,oaClearanceMeasureEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaClearanceMeasureEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacEuclidianClearanceMeasure");
    PyDict_SetItemString(mod_dict,"oacEuclidianClearanceMeasure",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMaxXYClearanceMeasure");
    PyDict_SetItemString(mod_dict,"oacMaxXYClearanceMeasure",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaClearanceMeasureEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaClearanceMeasureEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaClearanceMeasureEnum\n");
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
// Wrapper Implementation for Class: oaCluster
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCluster_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCluster_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaClusterObject* self = (PyoaClusterObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCluster)
    {
        PyParamoaCluster p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaCluster_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaCluster, Choices are:\n"
        "    (oaCluster)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCluster_tp_dealloc(PyoaClusterObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCluster_tp_repr(PyObject *ob)
{
    PyParamoaCluster value;
    int convert_status=PyoaCluster_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaCluster::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[31];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaCluster::");
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
oaCluster_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCluster v1;
    PyParamoaCluster v2;
    int convert_status1=PyoaCluster_Convert(ob1,&v1);
    int convert_status2=PyoaCluster_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCluster_Convert(PyObject* ob,PyParamoaCluster* result)
{
    if (ob == NULL) return 1;
    if (PyoaCluster_Check(ob)) {
        result->SetData( (oaCluster**) ((PyoaClusterObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCluster Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCluster_FromoaCluster(oaCluster** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaCluster* data=*value;
        PyObject* bself = PyoaCluster_Type.tp_alloc(&PyoaCluster_Type,0);
        if (bself == NULL) return bself;
        PyoaClusterObject* self = (PyoaClusterObject*)bself;
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
PyObject* PyoaCluster_FromoaCluster(oaCluster* data)
{
    if (data) {
       PyObject* bself = PyoaCluster_Type.tp_alloc(&PyoaCluster_Type,0);
       if (bself == NULL) return bself;
       PyoaClusterObject* self = (PyoaClusterObject*)bself;
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
static char oaCluster_addToCluster_doc[] = 
"Class: oaCluster, Function: addToCluster\n"
"  Paramegers: (oaCluster)\n"
"    Calls: void addToCluster(oaCluster* cluster)\n"
"    Signature: addToCluster|void-void|ptr-oaCluster,\n"
"    This function adds this cluster as a child cluster to the specified cluster.\n"
"    oacClusterAlreadyHasParent\n"
"    oacInvalidCluster\n"
"    oacInvalidChildCluster\n"
"    oacSameCluster\n"
;

static PyObject*
oaCluster_addToCluster(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterObject* self=(PyoaClusterObject*)ob;
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
static char oaCluster_destroy_doc[] = 
"Class: oaCluster, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this cluster, removing it from the database. All instances in this cluster remain intact. If there are boundaries associated with this cluster, the boundaries are destroyed.\n"
;

static PyObject*
oaCluster_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterObject* self=(PyoaClusterObject*)ob;
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
static char oaCluster_getBlockagesOwnedBy_doc[] = 
"Class: oaCluster, Function: getBlockagesOwnedBy\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaBlockage_oaCluster getBlockagesOwnedBy() const\n"
"    Signature: getBlockagesOwnedBy|simple-oaCollection_oaBlockage_oaCluster|\n"
"    BrowseData: 1\n"
"    This function returns a collection containing all of the oaBlockage objects that have this cluster as owner.\n"
;

static PyObject*
oaCluster_getBlockagesOwnedBy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterObject* self=(PyoaClusterObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaBlockage_oaCluster* result= new oaCollection_oaBlockage_oaCluster(data.DataCall()->getBlockagesOwnedBy());
        return PyoaCollection_oaBlockage_oaCluster_FromoaCollection_oaBlockage_oaCluster(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCluster_getBlockagesOwnedByIter_doc[] = 
"Class: oaCluster, Function: getBlockagesOwnedByIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaBlockage getBlockagesOwnedByIter() const\n"
"    Signature: getBlockagesOwnedByIter|simple-oaIter_oaBlockage|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection containing all of the oaBlockage objects that have this cluster as owner.\n"
;

static PyObject*
oaCluster_getBlockagesOwnedByIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterObject* self=(PyoaClusterObject*)ob;
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
static char oaCluster_getBoundaries_doc[] = 
"Class: oaCluster, Function: getBoundaries\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaClusterBoundary_oaCluster getBoundaries() const\n"
"    Signature: getBoundaries|simple-oaCollection_oaClusterBoundary_oaCluster|\n"
"    BrowseData: 1\n"
"    This function returns a collection containing all of the oaClusterBoundary objects associated with this cluster.\n"
;

static PyObject*
oaCluster_getBoundaries(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterObject* self=(PyoaClusterObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaClusterBoundary_oaCluster* result= new oaCollection_oaClusterBoundary_oaCluster(data.DataCall()->getBoundaries());
        return PyoaCollection_oaClusterBoundary_oaCluster_FromoaCollection_oaClusterBoundary_oaCluster(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCluster_getBoundariesIter_doc[] = 
"Class: oaCluster, Function: getBoundariesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaClusterBoundary getBoundariesIter() const\n"
"    Signature: getBoundariesIter|simple-oaIter_oaClusterBoundary|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection containing all of the oaClusterBoundary objects associated with this cluster.\n"
;

static PyObject*
oaCluster_getBoundariesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterObject* self=(PyoaClusterObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaClusterBoundary* result= new oaIter_oaClusterBoundary(data.DataCall()->getBoundaries());
        return PyoaIter_oaClusterBoundary_FromoaIter_oaClusterBoundary(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCluster_getClusterType_doc[] = 
"Class: oaCluster, Function: getClusterType\n"
"  Paramegers: ()\n"
"    Calls: oaClusterType getClusterType() const\n"
"    Signature: getClusterType|simple-oaClusterType|\n"
"    BrowseData: 1\n"
"    This function returns the clusterType of this cluster.\n"
;

static PyObject*
oaCluster_getClusterType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterObject* self=(PyoaClusterObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaClusterType* result= new oaClusterType(data.DataCall()->getClusterType());
        return PyoaClusterType_FromoaClusterType(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCluster_getClusters_doc[] = 
"Class: oaCluster, Function: getClusters\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaCluster_oaCluster getClusters() const\n"
"    Signature: getClusters|simple-oaCollection_oaCluster_oaCluster|\n"
"    BrowseData: 1\n"
"    This function returns a collection of clusters in this cluster.\n"
;

static PyObject*
oaCluster_getClusters(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterObject* self=(PyoaClusterObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaCluster_oaCluster* result= new oaCollection_oaCluster_oaCluster(data.DataCall()->getClusters());
        return PyoaCollection_oaCluster_oaCluster_FromoaCollection_oaCluster_oaCluster(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCluster_getClustersIter_doc[] = 
"Class: oaCluster, Function: getClustersIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaCluster getClustersIter() const\n"
"    Signature: getClustersIter|simple-oaIter_oaCluster|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of clusters in this cluster.\n"
;

static PyObject*
oaCluster_getClustersIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterObject* self=(PyoaClusterObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaCluster* result= new oaIter_oaCluster(data.DataCall()->getClusters());
        return PyoaIter_oaCluster_FromoaIter_oaCluster(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCluster_getInsts_doc[] = 
"Class: oaCluster, Function: getInsts\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaInst_oaCluster getInsts() const\n"
"    Signature: getInsts|simple-oaCollection_oaInst_oaCluster|\n"
"    BrowseData: 1\n"
"    This function returns a collection of instances in this cluster.\n"
;

static PyObject*
oaCluster_getInsts(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterObject* self=(PyoaClusterObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaInst_oaCluster* result= new oaCollection_oaInst_oaCluster(data.DataCall()->getInsts());
        return PyoaCollection_oaInst_oaCluster_FromoaCollection_oaInst_oaCluster(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCluster_getInstsIter_doc[] = 
"Class: oaCluster, Function: getInstsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaInst getInstsIter() const\n"
"    Signature: getInstsIter|simple-oaIter_oaInst|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of instances in this cluster.\n"
;

static PyObject*
oaCluster_getInstsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterObject* self=(PyoaClusterObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaInst* result= new oaIter_oaInst(data.DataCall()->getInsts());
        return PyoaIter_oaInst_FromoaIter_oaInst(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaCluster_getName_doc[] = 
"Class: oaCluster, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function fills out name with the name of this cluster.\n"
"    name\n"
"    The string in which the cluster name is returned\n"
;

static PyObject*
oaCluster_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterObject* self=(PyoaClusterObject*)ob;
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
static char oaCluster_getParent_doc[] = 
"Class: oaCluster, Function: getParent\n"
"  Paramegers: ()\n"
"    Calls: oaCluster* getParent() const\n"
"    Signature: getParent|ptr-oaCluster|\n"
"    BrowseData: 1\n"
"    This function returns the parent cluster of this cluster if this cluster is a child cluster. Otherwise, NULL is returned.\n"
;

static PyObject*
oaCluster_getParent(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterObject* self=(PyoaClusterObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaClusterp result= (data.DataCall()->getParent());
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
static char oaCluster_isParent_doc[] = 
"Class: oaCluster, Function: isParent\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isParent() const\n"
"    Signature: isParent|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this cluster is a parent cluster.\n"
;

static PyObject*
oaCluster_isParent(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterObject* self=(PyoaClusterObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isParent());
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
static char oaCluster_removeFromCluster_doc[] = 
"Class: oaCluster, Function: removeFromCluster\n"
"  Paramegers: ()\n"
"    Calls: void removeFromCluster()\n"
"    Signature: removeFromCluster|void-void|\n"
"    BrowseData: 0\n"
"    This function removes this cluster from the parent cluster. If this cluster is not a child of another cluster, this function does nothing.\n"
;

static PyObject*
oaCluster_removeFromCluster(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterObject* self=(PyoaClusterObject*)ob;
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
static char oaCluster_setClusterType_doc[] = 
"Class: oaCluster, Function: setClusterType\n"
"  Paramegers: (oaClusterType)\n"
"    Calls: void setClusterType(oaClusterType type)\n"
"    Signature: setClusterType|void-void|simple-oaClusterType,\n"
"    This function sets the cluster type to the specified value.\n"
;

static PyObject*
oaCluster_setClusterType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterObject* self=(PyoaClusterObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaClusterType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaClusterType_Convert,&p1)) {
        data.DataCall()->setClusterType(p1.Data());
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
static char oaCluster_setName_doc[] = 
"Class: oaCluster, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function sets the name of this cluster to the specified value.\n"
"    name\n"
"    The new name for this cluster\n"
"    oacClusterNameExists\n"
;

static PyObject*
oaCluster_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterObject* self=(PyoaClusterObject*)ob;
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
static char oaCluster_isNull_doc[] =
"Class: oaCluster, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaCluster_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaCluster data;
    int convert_status=PyoaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaCluster_assign_doc[] = 
"Class: oaCluster, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCluster_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCluster data;
  int convert_status=PyoaCluster_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCluster p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCluster_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCluster_methodlist[] = {
    {"addToCluster",(PyCFunction)oaCluster_addToCluster,METH_VARARGS,oaCluster_addToCluster_doc},
    {"destroy",(PyCFunction)oaCluster_destroy,METH_VARARGS,oaCluster_destroy_doc},
    {"getBlockagesOwnedBy",(PyCFunction)oaCluster_getBlockagesOwnedBy,METH_VARARGS,oaCluster_getBlockagesOwnedBy_doc},
    {"getBlockagesOwnedByIter",(PyCFunction)oaCluster_getBlockagesOwnedByIter,METH_VARARGS,oaCluster_getBlockagesOwnedByIter_doc},
    {"getBoundaries",(PyCFunction)oaCluster_getBoundaries,METH_VARARGS,oaCluster_getBoundaries_doc},
    {"getBoundariesIter",(PyCFunction)oaCluster_getBoundariesIter,METH_VARARGS,oaCluster_getBoundariesIter_doc},
    {"getClusterType",(PyCFunction)oaCluster_getClusterType,METH_VARARGS,oaCluster_getClusterType_doc},
    {"getClusters",(PyCFunction)oaCluster_getClusters,METH_VARARGS,oaCluster_getClusters_doc},
    {"getClustersIter",(PyCFunction)oaCluster_getClustersIter,METH_VARARGS,oaCluster_getClustersIter_doc},
    {"getInsts",(PyCFunction)oaCluster_getInsts,METH_VARARGS,oaCluster_getInsts_doc},
    {"getInstsIter",(PyCFunction)oaCluster_getInstsIter,METH_VARARGS,oaCluster_getInstsIter_doc},
    {"getName",(PyCFunction)oaCluster_getName,METH_VARARGS,oaCluster_getName_doc},
    {"getParent",(PyCFunction)oaCluster_getParent,METH_VARARGS,oaCluster_getParent_doc},
    {"isParent",(PyCFunction)oaCluster_isParent,METH_VARARGS,oaCluster_isParent_doc},
    {"removeFromCluster",(PyCFunction)oaCluster_removeFromCluster,METH_VARARGS,oaCluster_removeFromCluster_doc},
    {"setClusterType",(PyCFunction)oaCluster_setClusterType,METH_VARARGS,oaCluster_setClusterType_doc},
    {"setName",(PyCFunction)oaCluster_setName,METH_VARARGS,oaCluster_setName_doc},
    {"isNull",(PyCFunction)oaCluster_tp_isNull,METH_VARARGS,oaCluster_isNull_doc},
    {"assign",(PyCFunction)oaCluster_tp_assign,METH_VARARGS,oaCluster_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCluster_doc[] = 
"Class: oaCluster\n"
"  The oaCluster class implements a cluster object that is used to associate a group of instances and boundaries within a block. Clusters can be hierarchical.\n"
"  The oaCluster class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaCluster)\n"
"    Calls: (const oaCluster&)\n"
"    Signature: oaCluster||cref-oaCluster,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCluster_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCluster",
    sizeof(PyoaClusterObject),
    0,
    (destructor)oaCluster_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCluster_tp_compare,	/* tp_compare */
    (reprfunc)oaCluster_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCluster_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCluster_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBlockObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCluster_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCluster_static_create_doc[] = 
"Class: oaCluster, Function: create\n"
"  Paramegers: (oaBlock,oaString,oaClusterType)\n"
"    Calls: oaCluster* create(oaBlock* block,const oaString& name,oaClusterType type)\n"
"    Signature: create|ptr-oaCluster|ptr-oaBlock,cref-oaString,simple-oaClusterType,\n"
"    This function creates a new cluster object in the specified block with the specified attributes.\n"
"    block\n"
"    The block that creates the cluster\n"
"    name\n"
"    The name of the cluster\n"
"    isExclusive\n"
"    The type of cluster\n"
"    A pointer to the new oaCluster\n"
"    oacClusterNameExists\n"
;

static PyObject*
oaCluster_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBlock p1;
    PyParamoaString p2;
    PyParamoaClusterType p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaBlock_Convert,&p1,
          &PyoaString_Convert,&p2,
          &PyoaClusterType_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaClusterp result= (oaCluster::create(p1.Data(),p2.Data(),p3.Data()));
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
static char oaCluster_static_find_doc[] = 
"Class: oaCluster, Function: find\n"
"  Paramegers: (oaBlock,oaString)\n"
"    Calls: oaCluster* find(const oaBlock* block,const oaString& name)\n"
"    Signature: find|ptr-oaCluster|cptr-oaBlock,cref-oaString,\n"
"    This function searches the specified block for a cluster with the specified name . The cluster is returned if found. Otherwise, NULL is returned.\n"
"    block\n"
"    The block to search\n"
"    name\n"
"    The name of the cluster to find\n"
;

static PyObject*
oaCluster_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBlock p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaBlock_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaClusterp result= (oaCluster::find(p1.Data(),p2.Data()));
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
static PyMethodDef oaCluster_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaCluster_static_create,METH_VARARGS,oaCluster_static_create_doc},
    {"static_find",(PyCFunction)oaCluster_static_find,METH_VARARGS,oaCluster_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCluster_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCluster_Type)<0) {
      printf("** PyType_Ready failed for: oaCluster\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCluster",
           (PyObject*)(&PyoaCluster_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCluster\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaCluster_Type.tp_dict;
    for(method=oaCluster_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaClusterBoundary
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaClusterBoundary_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaClusterBoundary_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaClusterBoundaryObject* self = (PyoaClusterBoundaryObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaClusterBoundary)
    {
        PyParamoaClusterBoundary p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaClusterBoundary_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaClusterBoundary, Choices are:\n"
        "    (oaClusterBoundary)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaClusterBoundary_tp_dealloc(PyoaClusterBoundaryObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaClusterBoundary_tp_repr(PyObject *ob)
{
    PyParamoaClusterBoundary value;
    int convert_status=PyoaClusterBoundary_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaClusterBoundary::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[39];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaClusterBoundary::");
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
oaClusterBoundary_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaClusterBoundary v1;
    PyParamoaClusterBoundary v2;
    int convert_status1=PyoaClusterBoundary_Convert(ob1,&v1);
    int convert_status2=PyoaClusterBoundary_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaClusterBoundary_Convert(PyObject* ob,PyParamoaClusterBoundary* result)
{
    if (ob == NULL) return 1;
    if (PyoaClusterBoundary_Check(ob)) {
        result->SetData( (oaClusterBoundary**) ((PyoaClusterBoundaryObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaClusterBoundary Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaClusterBoundary_FromoaClusterBoundary(oaClusterBoundary** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaClusterBoundary* data=*value;
        PyObject* bself = PyoaClusterBoundary_Type.tp_alloc(&PyoaClusterBoundary_Type,0);
        if (bself == NULL) return bself;
        PyoaClusterBoundaryObject* self = (PyoaClusterBoundaryObject*)bself;
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
PyObject* PyoaClusterBoundary_FromoaClusterBoundary(oaClusterBoundary* data)
{
    if (data) {
       PyObject* bself = PyoaClusterBoundary_Type.tp_alloc(&PyoaClusterBoundary_Type,0);
       if (bself == NULL) return bself;
       PyoaClusterBoundaryObject* self = (PyoaClusterBoundaryObject*)bself;
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
static char oaClusterBoundary_getCluster_doc[] = 
"Class: oaClusterBoundary, Function: getCluster\n"
"  Paramegers: ()\n"
"    Calls: oaCluster* getCluster() const\n"
"    Signature: getCluster|ptr-oaCluster|\n"
"    BrowseData: 1\n"
"    This function returns the cluster of this boundary.\n"
;

static PyObject*
oaClusterBoundary_getCluster(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaClusterBoundary data;
    int convert_status=PyoaClusterBoundary_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterBoundaryObject* self=(PyoaClusterBoundaryObject*)ob;
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
static char oaClusterBoundary_getName_doc[] = 
"Class: oaClusterBoundary, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function fills out name with the name of this boundary.\n"
;

static PyObject*
oaClusterBoundary_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaClusterBoundary data;
    int convert_status=PyoaClusterBoundary_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterBoundaryObject* self=(PyoaClusterBoundaryObject*)ob;
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
static char oaClusterBoundary_setName_doc[] = 
"Class: oaClusterBoundary, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function sets the name of this cluster boundary to the specified name .\n"
"    oacBoundaryNameExists\n"
;

static PyObject*
oaClusterBoundary_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaClusterBoundary data;
    int convert_status=PyoaClusterBoundary_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterBoundaryObject* self=(PyoaClusterBoundaryObject*)ob;
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
static char oaClusterBoundary_isNull_doc[] =
"Class: oaClusterBoundary, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaClusterBoundary_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaClusterBoundary data;
    int convert_status=PyoaClusterBoundary_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaClusterBoundary_assign_doc[] = 
"Class: oaClusterBoundary, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaClusterBoundary_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaClusterBoundary data;
  int convert_status=PyoaClusterBoundary_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaClusterBoundary p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaClusterBoundary_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaClusterBoundary_methodlist[] = {
    {"getCluster",(PyCFunction)oaClusterBoundary_getCluster,METH_VARARGS,oaClusterBoundary_getCluster_doc},
    {"getName",(PyCFunction)oaClusterBoundary_getName,METH_VARARGS,oaClusterBoundary_getName_doc},
    {"setName",(PyCFunction)oaClusterBoundary_setName,METH_VARARGS,oaClusterBoundary_setName_doc},
    {"isNull",(PyCFunction)oaClusterBoundary_tp_isNull,METH_VARARGS,oaClusterBoundary_isNull_doc},
    {"assign",(PyCFunction)oaClusterBoundary_tp_assign,METH_VARARGS,oaClusterBoundary_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaClusterBoundary_doc[] = 
"Class: oaClusterBoundary\n"
"  The oaClusterBoundary class indicates an area in which the contents of a specific cluster should be placed. Each oaClusterBoundary is attached to a specific oaCluster object. An oaCluster may have multiple oaClusterBoundary objects attached to it, in which case the contents of the cluster may be placed in any of its boundaries. An oaClusterBoundary must have a unique name with respect to all Boundaries in a given design.\n"
"Constructors:\n"
"  Paramegers: (oaClusterBoundary)\n"
"    Calls: (const oaClusterBoundary&)\n"
"    Signature: oaClusterBoundary||cref-oaClusterBoundary,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaClusterBoundary_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaClusterBoundary",
    sizeof(PyoaClusterBoundaryObject),
    0,
    (destructor)oaClusterBoundary_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaClusterBoundary_tp_compare,	/* tp_compare */
    (reprfunc)oaClusterBoundary_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaClusterBoundary_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaClusterBoundary_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBoundary_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaClusterBoundary_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaClusterBoundary_static_create_doc[] = 
"Class: oaClusterBoundary, Function: create\n"
"  Paramegers: (oaCluster,oaString,oaPointArray)\n"
"    Calls: oaClusterBoundary* create(oaCluster* cluster,const oaString& name,const oaPointArray& points)\n"
"    Signature: create|ptr-oaClusterBoundary|ptr-oaCluster,cref-oaString,cref-oaPointArray,cptr-oaString,\n"
"    This function creates a new cluster boundary object in the specified cluster with the specified attributes.\n"
"    If boundary edgeNames are not supplied, the edges are automatically named, using the form EDGE_ n , where n starts at zero and increments by one.\n"
"    Note: The order of the points actually set on the oaClusterBoundary is not guaranteed to be the same as the order of points passed to the create() function. Consequently, the order of points returned by a subsequent oaClusterBoundary::getPoints() may be different from the order of points specified in points .\n"
"    oacBoundaryNameExists\n"
"    oacBoundaryHasExtraPoints\n"
"    oacBoundaryTooFewPoints\n"
"  Paramegers: (oaCluster,oaString,oaPointArray,[oaString])\n"
"    Calls: oaClusterBoundary* create(oaCluster* cluster,const oaString& name,const oaPointArray& points,const oaString* edgeNames)\n"
"    Signature: create|ptr-oaClusterBoundary|ptr-oaCluster,cref-oaString,cref-oaPointArray,cptr-oaString,\n"
"    This function creates a new cluster boundary object in the specified cluster with the specified attributes.\n"
"    If boundary edgeNames are not supplied, the edges are automatically named, using the form EDGE_ n , where n starts at zero and increments by one.\n"
"    Note: The order of the points actually set on the oaClusterBoundary is not guaranteed to be the same as the order of points passed to the create() function. Consequently, the order of points returned by a subsequent oaClusterBoundary::getPoints() may be different from the order of points specified in points .\n"
"    oacBoundaryNameExists\n"
"    oacBoundaryHasExtraPoints\n"
"    oacBoundaryTooFewPoints\n"
"  Paramegers: (oaCluster,oaPointArray)\n"
"    Calls: oaClusterBoundary* create(oaCluster* cluster,const oaPointArray& points)\n"
"    Signature: create|ptr-oaClusterBoundary|ptr-oaCluster,cref-oaPointArray,cptr-oaString,\n"
"    This function creates a new cluster boundary object in the specified cluster with the specified attributes. A name for the new cluster boundary is automatically generated, with the default name prefix B__%d, d referring to a unique integer.\n"
"    If boundary edgeNames are not supplied, the edges are automatically named, using the form EDGE_ n , where n starts at zero and increments by one.\n"
"    Note: The order of the points actually set on the oaClusterBoundary is not guaranteed to be the same as the order of points passed to the create() function. Consequently, the order of points returned by a subsequent oaClusterBoundary::getPoints() may be different from the order of points specified in points .\n"
"    oacBoundaryHasExtraPoints\n"
"    oacBoundaryTooFewPoints\n"
"  Paramegers: (oaCluster,oaPointArray,[oaString])\n"
"    Calls: oaClusterBoundary* create(oaCluster* cluster,const oaPointArray& points,const oaString* edgeNames)\n"
"    Signature: create|ptr-oaClusterBoundary|ptr-oaCluster,cref-oaPointArray,cptr-oaString,\n"
"    This function creates a new cluster boundary object in the specified cluster with the specified attributes. A name for the new cluster boundary is automatically generated, with the default name prefix B__%d, d referring to a unique integer.\n"
"    If boundary edgeNames are not supplied, the edges are automatically named, using the form EDGE_ n , where n starts at zero and increments by one.\n"
"    Note: The order of the points actually set on the oaClusterBoundary is not guaranteed to be the same as the order of points passed to the create() function. Consequently, the order of points returned by a subsequent oaClusterBoundary::getPoints() may be different from the order of points specified in points .\n"
"    oacBoundaryHasExtraPoints\n"
"    oacBoundaryTooFewPoints\n"
;

static PyObject*
oaClusterBoundary_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaCluster,oaString,oaPointArray)
    {
        PyParamoaCluster p1;
        PyParamoaString p2;
        PyParamoaPointArray p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaCluster_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaPointArray_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaClusterBoundaryp result= (oaClusterBoundary::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaClusterBoundary_FromoaClusterBoundary(result);
        }
    }
    PyErr_Clear();
    // Case: (oaCluster,oaString,oaPointArray,[oaString])
    {
        PyParamoaCluster p1;
        PyParamoaString p2;
        PyParamoaPointArray p3;
        PyParamoaString_Array p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaCluster_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaPointArray_Convert,&p3,
              &PyoaString_Array_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!(p3.Data().getNumElements()==p4.Len())) {
                PyErr_SetString(PyExc_TypeError,
                    "number of edges does not match number of points");
                return NULL;
            }
            oaClusterBoundaryp result= (oaClusterBoundary::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaClusterBoundary_FromoaClusterBoundary(result);
        }
    }
    PyErr_Clear();
    // Case: (oaCluster,oaPointArray)
    {
        PyParamoaCluster p1;
        PyParamoaPointArray p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaCluster_Convert,&p1,
              &PyoaPointArray_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaClusterBoundaryp result= (oaClusterBoundary::create(p1.Data(),p2.Data()));
            return PyoaClusterBoundary_FromoaClusterBoundary(result);
        }
    }
    PyErr_Clear();
    // Case: (oaCluster,oaPointArray,[oaString])
    {
        PyParamoaCluster p1;
        PyParamoaPointArray p2;
        PyParamoaString_Array p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaCluster_Convert,&p1,
              &PyoaPointArray_Convert,&p2,
              &PyoaString_Array_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!(p2.Data().getNumElements()==p3.Len())) {
                PyErr_SetString(PyExc_TypeError,
                    "number of edges does not match number of points");
                return NULL;
            }
            oaClusterBoundaryp result= (oaClusterBoundary::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaClusterBoundary_FromoaClusterBoundary(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaClusterBoundary, function: create, Choices are:\n"
        "    (oaCluster,oaString,oaPointArray)\n"
        "    (oaCluster,oaString,oaPointArray,[oaString])\n"
        "    (oaCluster,oaPointArray)\n"
        "    (oaCluster,oaPointArray,[oaString])\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaClusterBoundary_static_find_doc[] = 
"Class: oaClusterBoundary, Function: find\n"
"  Paramegers: (oaCluster,oaString)\n"
"    Calls: oaClusterBoundary* find(const oaCluster* cluster,const oaString& name)\n"
"    Signature: find|ptr-oaClusterBoundary|cptr-oaCluster,cref-oaString,\n"
"    This function searches the design of the specified cluster for a cluster boundary with the specified name. The boundary is returned if found. Otherwise, NULL is returned.\n"
;

static PyObject*
oaClusterBoundary_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCluster p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaCluster_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaClusterBoundaryp result= (oaClusterBoundary::find(p1.Data(),p2.Data()));
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
static PyMethodDef oaClusterBoundary_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaClusterBoundary_static_create,METH_VARARGS,oaClusterBoundary_static_create_doc},
    {"static_find",(PyCFunction)oaClusterBoundary_static_find,METH_VARARGS,oaClusterBoundary_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaClusterBoundary_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaClusterBoundary_Type)<0) {
      printf("** PyType_Ready failed for: oaClusterBoundary\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaClusterBoundary",
           (PyObject*)(&PyoaClusterBoundary_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaClusterBoundary\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaClusterBoundary_Type.tp_dict;
    for(method=oaClusterBoundary_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaClusterModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaClusterModTypeEnum_Convert(PyObject* ob,PyParamoaClusterModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetNameClusterModType")==0) { result->SetData(oacSetNameClusterModType); return 1;}
        if (strcasecmp(str,"oacSetClusterTypeClusterModType")==0) { result->SetData(oacSetClusterTypeClusterModType); return 1;}
        if (strcasecmp(str,"oacAddInstClusterModType")==0) { result->SetData(oacAddInstClusterModType); return 1;}
        if (strcasecmp(str,"oacRemoveInstClusterModType")==0) { result->SetData(oacRemoveInstClusterModType); return 1;}
        if (strcasecmp(str,"oacAddClusterClusterModType")==0) { result->SetData(oacAddClusterClusterModType); return 1;}
        if (strcasecmp(str,"oacRemoveClusterClusterModType")==0) { result->SetData(oacRemoveClusterClusterModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaClusterModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaClusterModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaClusterModTypeEnum_FromoaClusterModTypeEnum(oaClusterModTypeEnum ob)
{
    if (ob==oacSetNameClusterModType) return PyString_FromString("oacSetNameClusterModType");
    if (ob==oacSetClusterTypeClusterModType) return PyString_FromString("oacSetClusterTypeClusterModType");
    if (ob==oacAddInstClusterModType) return PyString_FromString("oacAddInstClusterModType");
    if (ob==oacRemoveInstClusterModType) return PyString_FromString("oacRemoveInstClusterModType");
    if (ob==oacAddClusterClusterModType) return PyString_FromString("oacAddClusterClusterModType");
    if (ob==oacRemoveClusterClusterModType) return PyString_FromString("oacRemoveClusterClusterModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaClusterModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaClusterModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaClusterModTypeEnum_FromoaClusterModTypeEnum(oaClusterModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaClusterModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaClusterModTypeEnum_doc[] =
"Type convert function for enum: oaClusterModTypeEnum";
                               
static PyMethodDef PyoaClusterModTypeEnum_method =
  {"oaClusterModTypeEnum",(PyCFunction)PyoaClusterModTypeEnum_TypeFunction,METH_VARARGS,oaClusterModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaClusterModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetNameClusterModType");
    PyDict_SetItemString(mod_dict,"oacSetNameClusterModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetClusterTypeClusterModType");
    PyDict_SetItemString(mod_dict,"oacSetClusterTypeClusterModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAddInstClusterModType");
    PyDict_SetItemString(mod_dict,"oacAddInstClusterModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRemoveInstClusterModType");
    PyDict_SetItemString(mod_dict,"oacRemoveInstClusterModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAddClusterClusterModType");
    PyDict_SetItemString(mod_dict,"oacAddClusterClusterModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRemoveClusterClusterModType");
    PyDict_SetItemString(mod_dict,"oacRemoveClusterClusterModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaClusterModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaClusterModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaClusterModTypeEnum\n");
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
// Wrapper Implementation for Class: oaClusterType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaClusterType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaClusterType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaClusterTypeObject* self = (PyoaClusterTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaClusterTypeEnum)
    {
        PyParamoaClusterTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaClusterTypeEnum_Convert,&p1)) {
            self->value =  new oaClusterType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaClusterType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaClusterType)
    {
        PyParamoaClusterType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaClusterType_Convert,&p1)) {
            self->value= new oaClusterType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaClusterType, Choices are:\n"
        "    (oaClusterTypeEnum)\n"
        "    (oaString)\n"
        "    (oaClusterType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaClusterType_tp_dealloc(PyoaClusterTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaClusterType_tp_repr(PyObject *ob)
{
    PyParamoaClusterType value;
    int convert_status=PyoaClusterType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[35];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaClusterType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaClusterType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaClusterType v1;
    PyParamoaClusterType v2;
    int convert_status1=PyoaClusterType_Convert(ob1,&v1);
    int convert_status2=PyoaClusterType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaClusterType_Convert(PyObject* ob,PyParamoaClusterType* result)
{
    if (ob == NULL) return 1;
    if (PyoaClusterType_Check(ob)) {
        result->SetData(  ((PyoaClusterTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaClusterType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaClusterType_FromoaClusterType(oaClusterType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaClusterType_Type.tp_alloc(&PyoaClusterType_Type,0);
        if (bself == NULL) return bself;
        PyoaClusterTypeObject* self = (PyoaClusterTypeObject*)bself;
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
static char oaClusterType_getName_doc[] = 
"Class: oaClusterType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaClusterTypeEnum object.\n"
;

static PyObject*
oaClusterType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaClusterType data;
    int convert_status=PyoaClusterType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterTypeObject* self=(PyoaClusterTypeObject*)ob;

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
static char oaClusterType_oaClusterTypeEnum_doc[] = 
"Class: oaClusterType, Function: oaClusterTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaClusterTypeEnum oaClusterTypeEnum() const\n"
"    Signature: operator oaClusterTypeEnum|simple-oaClusterTypeEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaClusterType object into the corresponding #oaClusterTypeEnum value.\n"
;

static PyObject*
oaClusterType_oaClusterTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaClusterType data;
    int convert_status=PyoaClusterType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaClusterTypeObject* self=(PyoaClusterTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaClusterTypeEnum result= (data.DataCall()->operator oaClusterTypeEnum());
        return PyoaClusterTypeEnum_FromoaClusterTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaClusterType_assign_doc[] = 
"Class: oaClusterType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaClusterType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaClusterType data;
  int convert_status=PyoaClusterType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaClusterType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaClusterType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaClusterType_methodlist[] = {
    {"getName",(PyCFunction)oaClusterType_getName,METH_VARARGS,oaClusterType_getName_doc},
    {"oaClusterTypeEnum",(PyCFunction)oaClusterType_oaClusterTypeEnum,METH_VARARGS,oaClusterType_oaClusterTypeEnum_doc},
    {"assign",(PyCFunction)oaClusterType_tp_assign,METH_VARARGS,oaClusterType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaClusterType_doc[] = 
"Class: oaClusterType\n"
"  The oaClusterType class is an enum wrapper class that indicates the inclusiveness of an oaCluster's region.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaClusterTypeEnum\n"
"Constructors:\n"
"  Paramegers: (oaClusterTypeEnum)\n"
"    Calls: oaClusterType(oaClusterTypeEnum valueIn)\n"
"    Signature: oaClusterType||simple-oaClusterTypeEnum,\n"
"    This function constructs an instance of an oaClusterType class using the specified #oaClusterTypeEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaClusterType(const oaString& name)\n"
"    Signature: oaClusterType||cref-oaString,\n"
"    This function constructs an instance of an oaClusterType class using the oaClusterTypeEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaClusterTypeEnum.\n"
"    oacInvalidClusterTypeName\n"
"  Paramegers: (oaClusterType)\n"
"    Calls: (const oaClusterType&)\n"
"    Signature: oaClusterType||cref-oaClusterType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaClusterType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaClusterType",
    sizeof(PyoaClusterTypeObject),
    0,
    (destructor)oaClusterType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaClusterType_tp_compare,	/* tp_compare */
    (reprfunc)oaClusterType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaClusterType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaClusterType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaClusterType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaClusterType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaClusterType_Type)<0) {
      printf("** PyType_Ready failed for: oaClusterType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaClusterType",
           (PyObject*)(&PyoaClusterType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaClusterType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaClusterTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaClusterTypeEnum_Convert(PyObject* ob,PyParamoaClusterTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacClusterTypeInclusive")==0) { result->SetData(oacClusterTypeInclusive); return 1;}
        if (strcasecmp(str,"oacClusterTypeExclusive")==0) { result->SetData(oacClusterTypeExclusive); return 1;}
        if (strcasecmp(str,"oacClusterTypeSuggested")==0) { result->SetData(oacClusterTypeSuggested); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaClusterTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaClusterTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaClusterTypeEnum_FromoaClusterTypeEnum(oaClusterTypeEnum ob)
{
    if (ob==oacClusterTypeInclusive) return PyString_FromString("oacClusterTypeInclusive");
    if (ob==oacClusterTypeExclusive) return PyString_FromString("oacClusterTypeExclusive");
    if (ob==oacClusterTypeSuggested) return PyString_FromString("oacClusterTypeSuggested");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaClusterTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaClusterTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaClusterTypeEnum_FromoaClusterTypeEnum(oaClusterTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaClusterTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaClusterTypeEnum_doc[] =
"Type convert function for enum: oaClusterTypeEnum";
                               
static PyMethodDef PyoaClusterTypeEnum_method =
  {"oaClusterTypeEnum",(PyCFunction)PyoaClusterTypeEnum_TypeFunction,METH_VARARGS,oaClusterTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaClusterTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacClusterTypeInclusive");
    PyDict_SetItemString(mod_dict,"oacClusterTypeInclusive",value);
    Py_DECREF(value);
    value=PyString_FromString("oacClusterTypeExclusive");
    PyDict_SetItemString(mod_dict,"oacClusterTypeExclusive",value);
    Py_DECREF(value);
    value=PyString_FromString("oacClusterTypeSuggested");
    PyDict_SetItemString(mod_dict,"oacClusterTypeSuggested",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaClusterTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaClusterTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaClusterTypeEnum\n");
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
// Wrapper Implementation for Class: oaCollTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaCollTypeEnum_Convert(PyObject* ob,PyParamoaCollTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacBaseCollType")==0) { result->SetData(oacBaseCollType); return 1;}
        if (strcasecmp(str,"oacDomainBaseCollType")==0) { result->SetData(oacDomainBaseCollType); return 1;}
        if (strcasecmp(str,"oacAllCollType")==0) { result->SetData(oacAllCollType); return 1;}
        if (strcasecmp(str,"oacGenericCollType")==0) { result->SetData(oacGenericCollType); return 1;}
        if (strcasecmp(str,"oacEmptyCollType")==0) { result->SetData(oacEmptyCollType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaCollTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaCollTypeEnum_FromoaCollTypeEnum(oaCollTypeEnum ob)
{
    if (ob==oacBaseCollType) return PyString_FromString("oacBaseCollType");
    if (ob==oacDomainBaseCollType) return PyString_FromString("oacDomainBaseCollType");
    if (ob==oacAllCollType) return PyString_FromString("oacAllCollType");
    if (ob==oacGenericCollType) return PyString_FromString("oacGenericCollType");
    if (ob==oacEmptyCollType) return PyString_FromString("oacEmptyCollType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaCollTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaCollTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaCollTypeEnum_FromoaCollTypeEnum(oaCollTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaCollTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaCollTypeEnum_doc[] =
"Type convert function for enum: oaCollTypeEnum";
                               
static PyMethodDef PyoaCollTypeEnum_method =
  {"oaCollTypeEnum",(PyCFunction)PyoaCollTypeEnum_TypeFunction,METH_VARARGS,oaCollTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaCollTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacBaseCollType");
    PyDict_SetItemString(mod_dict,"oacBaseCollType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDomainBaseCollType");
    PyDict_SetItemString(mod_dict,"oacDomainBaseCollType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAllCollType");
    PyDict_SetItemString(mod_dict,"oacAllCollType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacGenericCollType");
    PyDict_SetItemString(mod_dict,"oacGenericCollType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacEmptyCollType");
    PyDict_SetItemString(mod_dict,"oacEmptyCollType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaCollTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaCollTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaCollTypeEnum\n");
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
// Wrapper Implementation for Class: oaCollection_oaAnalysisLib_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAnalysisLib_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAnalysisLib_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAnalysisLib_oaTechObject* self = (PyoaCollection_oaAnalysisLib_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAnalysisLib_oaTech)
    {
        PyParamoaCollection_oaAnalysisLib_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAnalysisLib_oaTech_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaAnalysisLib_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAnalysisLib_oaTech, Choices are:\n"
        "    (oaCollection_oaAnalysisLib_oaTech)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAnalysisLib_oaTech_tp_dealloc(PyoaCollection_oaAnalysisLib_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaAnalysisLib_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAnalysisLib_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAnalysisLib_oaTech value;
    int convert_status=PyoaCollection_oaAnalysisLib_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaCollection_oaAnalysisLib_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAnalysisLib_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAnalysisLib_oaTech v1;
    PyParamoaCollection_oaAnalysisLib_oaTech v2;
    int convert_status1=PyoaCollection_oaAnalysisLib_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAnalysisLib_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAnalysisLib_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaAnalysisLib_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAnalysisLib_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaAnalysisLib_oaTech*) ((PyoaCollection_oaAnalysisLib_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAnalysisLib_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAnalysisLib_oaTech_FromoaCollection_oaAnalysisLib_oaTech(oaCollection_oaAnalysisLib_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAnalysisLib_oaTech_Type.tp_alloc(&PyoaCollection_oaAnalysisLib_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAnalysisLib_oaTechObject* self = (PyoaCollection_oaAnalysisLib_oaTechObject*)bself;
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
static char oaCollection_oaAnalysisLib_oaTech_includes_doc[] = 
"Class: oaCollection_oaAnalysisLib_oaTech, Function: includes\n"
"  Paramegers: (oaAnalysisLib)\n"
"    Calls: oaBoolean includes(const oaAnalysisLib* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaAnalysisLib,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaAnalysisLib_oaTech_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaAnalysisLib_oaTech data;
    int convert_status=PyoaCollection_oaAnalysisLib_oaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaAnalysisLib_oaTechObject* self=(PyoaCollection_oaAnalysisLib_oaTechObject*)ob;

    PyParamoaAnalysisLib p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaAnalysisLib_Convert,&p1)) {
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

static char oaCollection_oaAnalysisLib_oaTech_assign_doc[] = 
"Class: oaCollection_oaAnalysisLib_oaTech, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaAnalysisLib_oaTech_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaAnalysisLib_oaTech data;
  int convert_status=PyoaCollection_oaAnalysisLib_oaTech_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaAnalysisLib_oaTech p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaAnalysisLib_oaTech_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaAnalysisLib_oaTech_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaAnalysisLib_oaTech_includes,METH_VARARGS,oaCollection_oaAnalysisLib_oaTech_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaAnalysisLib_oaTech_tp_assign,METH_VARARGS,oaCollection_oaAnalysisLib_oaTech_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaAnalysisLib_oaTech_doc[] = 
"Class: oaCollection_oaAnalysisLib_oaTech\n"
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
"  Paramegers: (oaCollection_oaAnalysisLib_oaTech)\n"
"    Calls: oaCollection_oaAnalysisLib_oaTech(const oaCollection_oaAnalysisLib_oaTech& coll)\n"
"    Signature: oaCollection_oaAnalysisLib_oaTech||cref-oaCollection_oaAnalysisLib_oaTech,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaAnalysisLib_oaTech)\n"
"    Calls: (const oaCollection_oaAnalysisLib_oaTech&)\n"
"    Signature: oaCollection_oaAnalysisLib_oaTech||cref-oaCollection_oaAnalysisLib_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAnalysisLib_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAnalysisLib_oaTech",
    sizeof(PyoaCollection_oaAnalysisLib_oaTechObject),
    0,
    (destructor)oaCollection_oaAnalysisLib_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAnalysisLib_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAnalysisLib_oaTech_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAnalysisLib_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaAnalysisLib_oaTech_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAnalysisLib_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAnalysisLib_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAnalysisLib_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAnalysisLib_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAnalysisLib_oaTech",
           (PyObject*)(&PyoaCollection_oaAnalysisLib_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAnalysisLib_oaTech\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAnalysisOpPoint_oaAnalysisPoint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAnalysisOpPoint_oaAnalysisPoint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAnalysisOpPoint_oaAnalysisPointObject* self = (PyoaCollection_oaAnalysisOpPoint_oaAnalysisPointObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAnalysisOpPoint_oaAnalysisPoint)
    {
        PyParamoaCollection_oaAnalysisOpPoint_oaAnalysisPoint p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAnalysisOpPoint_oaAnalysisPoint_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaAnalysisOpPoint_oaAnalysisPoint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAnalysisOpPoint_oaAnalysisPoint, Choices are:\n"
        "    (oaCollection_oaAnalysisOpPoint_oaAnalysisPoint)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_tp_dealloc(PyoaCollection_oaAnalysisOpPoint_oaAnalysisPointObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaAnalysisOpPoint_oaAnalysisPoint*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAnalysisOpPoint_oaAnalysisPoint value;
    int convert_status=PyoaCollection_oaAnalysisOpPoint_oaAnalysisPoint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[68];
    sprintf(buffer,"<oaCollection_oaAnalysisOpPoint_oaAnalysisPoint::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAnalysisOpPoint_oaAnalysisPoint v1;
    PyParamoaCollection_oaAnalysisOpPoint_oaAnalysisPoint v2;
    int convert_status1=PyoaCollection_oaAnalysisOpPoint_oaAnalysisPoint_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAnalysisOpPoint_oaAnalysisPoint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAnalysisOpPoint_oaAnalysisPoint_Convert(PyObject* ob,PyParamoaCollection_oaAnalysisOpPoint_oaAnalysisPoint* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAnalysisOpPoint_oaAnalysisPoint_Check(ob)) {
        result->SetData( (oaCollection_oaAnalysisOpPoint_oaAnalysisPoint*) ((PyoaCollection_oaAnalysisOpPoint_oaAnalysisPointObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAnalysisOpPoint_oaAnalysisPoint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAnalysisOpPoint_oaAnalysisPoint_FromoaCollection_oaAnalysisOpPoint_oaAnalysisPoint(oaCollection_oaAnalysisOpPoint_oaAnalysisPoint* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAnalysisOpPoint_oaAnalysisPoint_Type.tp_alloc(&PyoaCollection_oaAnalysisOpPoint_oaAnalysisPoint_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAnalysisOpPoint_oaAnalysisPointObject* self = (PyoaCollection_oaAnalysisOpPoint_oaAnalysisPointObject*)bself;
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
static char oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_includes_doc[] = 
"Class: oaCollection_oaAnalysisOpPoint_oaAnalysisPoint, Function: includes\n"
"  Paramegers: (oaAnalysisOpPoint)\n"
"    Calls: oaBoolean includes(const oaAnalysisOpPoint* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaAnalysisOpPoint,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaAnalysisOpPoint_oaAnalysisPoint data;
    int convert_status=PyoaCollection_oaAnalysisOpPoint_oaAnalysisPoint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaAnalysisOpPoint_oaAnalysisPointObject* self=(PyoaCollection_oaAnalysisOpPoint_oaAnalysisPointObject*)ob;

    PyParamoaAnalysisOpPoint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaAnalysisOpPoint_Convert,&p1)) {
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

static char oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_assign_doc[] = 
"Class: oaCollection_oaAnalysisOpPoint_oaAnalysisPoint, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaAnalysisOpPoint_oaAnalysisPoint data;
  int convert_status=PyoaCollection_oaAnalysisOpPoint_oaAnalysisPoint_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaAnalysisOpPoint_oaAnalysisPoint p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaAnalysisOpPoint_oaAnalysisPoint_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_includes,METH_VARARGS,oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_tp_assign,METH_VARARGS,oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_doc[] = 
"Class: oaCollection_oaAnalysisOpPoint_oaAnalysisPoint\n"
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
"  Paramegers: (oaCollection_oaAnalysisOpPoint_oaAnalysisPoint)\n"
"    Calls: oaCollection_oaAnalysisOpPoint_oaAnalysisPoint(const oaCollection_oaAnalysisOpPoint_oaAnalysisPoint& coll)\n"
"    Signature: oaCollection_oaAnalysisOpPoint_oaAnalysisPoint||cref-oaCollection_oaAnalysisOpPoint_oaAnalysisPoint,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaAnalysisOpPoint_oaAnalysisPoint)\n"
"    Calls: (const oaCollection_oaAnalysisOpPoint_oaAnalysisPoint&)\n"
"    Signature: oaCollection_oaAnalysisOpPoint_oaAnalysisPoint||cref-oaCollection_oaAnalysisOpPoint_oaAnalysisPoint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAnalysisOpPoint_oaAnalysisPoint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAnalysisOpPoint_oaAnalysisPoint",
    sizeof(PyoaCollection_oaAnalysisOpPoint_oaAnalysisPointObject),
    0,
    (destructor)oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAnalysisOpPoint_oaAnalysisPoint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAnalysisOpPoint_oaAnalysisPoint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAnalysisOpPoint_oaAnalysisPoint_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAnalysisOpPoint_oaAnalysisPoint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAnalysisOpPoint_oaAnalysisPoint",
           (PyObject*)(&PyoaCollection_oaAnalysisOpPoint_oaAnalysisPoint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAnalysisOpPoint_oaAnalysisPoint\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAnalysisOpPoint_oaOpPointHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAnalysisOpPoint_oaOpPointHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAnalysisOpPoint_oaOpPointHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAnalysisOpPoint_oaOpPointHeaderObject* self = (PyoaCollection_oaAnalysisOpPoint_oaOpPointHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAnalysisOpPoint_oaOpPointHeader)
    {
        PyParamoaCollection_oaAnalysisOpPoint_oaOpPointHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAnalysisOpPoint_oaOpPointHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaAnalysisOpPoint_oaOpPointHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAnalysisOpPoint_oaOpPointHeader, Choices are:\n"
        "    (oaCollection_oaAnalysisOpPoint_oaOpPointHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAnalysisOpPoint_oaOpPointHeader_tp_dealloc(PyoaCollection_oaAnalysisOpPoint_oaOpPointHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaAnalysisOpPoint_oaOpPointHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAnalysisOpPoint_oaOpPointHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAnalysisOpPoint_oaOpPointHeader value;
    int convert_status=PyoaCollection_oaAnalysisOpPoint_oaOpPointHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[68];
    sprintf(buffer,"<oaCollection_oaAnalysisOpPoint_oaOpPointHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAnalysisOpPoint_oaOpPointHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAnalysisOpPoint_oaOpPointHeader v1;
    PyParamoaCollection_oaAnalysisOpPoint_oaOpPointHeader v2;
    int convert_status1=PyoaCollection_oaAnalysisOpPoint_oaOpPointHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAnalysisOpPoint_oaOpPointHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAnalysisOpPoint_oaOpPointHeader_Convert(PyObject* ob,PyParamoaCollection_oaAnalysisOpPoint_oaOpPointHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAnalysisOpPoint_oaOpPointHeader_Check(ob)) {
        result->SetData( (oaCollection_oaAnalysisOpPoint_oaOpPointHeader*) ((PyoaCollection_oaAnalysisOpPoint_oaOpPointHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAnalysisOpPoint_oaOpPointHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAnalysisOpPoint_oaOpPointHeader_FromoaCollection_oaAnalysisOpPoint_oaOpPointHeader(oaCollection_oaAnalysisOpPoint_oaOpPointHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAnalysisOpPoint_oaOpPointHeader_Type.tp_alloc(&PyoaCollection_oaAnalysisOpPoint_oaOpPointHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAnalysisOpPoint_oaOpPointHeaderObject* self = (PyoaCollection_oaAnalysisOpPoint_oaOpPointHeaderObject*)bself;
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
static char oaCollection_oaAnalysisOpPoint_oaOpPointHeader_includes_doc[] = 
"Class: oaCollection_oaAnalysisOpPoint_oaOpPointHeader, Function: includes\n"
"  Paramegers: (oaAnalysisOpPoint)\n"
"    Calls: oaBoolean includes(const oaAnalysisOpPoint* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaAnalysisOpPoint,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaAnalysisOpPoint_oaOpPointHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaAnalysisOpPoint_oaOpPointHeader data;
    int convert_status=PyoaCollection_oaAnalysisOpPoint_oaOpPointHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaAnalysisOpPoint_oaOpPointHeaderObject* self=(PyoaCollection_oaAnalysisOpPoint_oaOpPointHeaderObject*)ob;

    PyParamoaAnalysisOpPoint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaAnalysisOpPoint_Convert,&p1)) {
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

static char oaCollection_oaAnalysisOpPoint_oaOpPointHeader_assign_doc[] = 
"Class: oaCollection_oaAnalysisOpPoint_oaOpPointHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaAnalysisOpPoint_oaOpPointHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaAnalysisOpPoint_oaOpPointHeader data;
  int convert_status=PyoaCollection_oaAnalysisOpPoint_oaOpPointHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaAnalysisOpPoint_oaOpPointHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaAnalysisOpPoint_oaOpPointHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaAnalysisOpPoint_oaOpPointHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaAnalysisOpPoint_oaOpPointHeader_includes,METH_VARARGS,oaCollection_oaAnalysisOpPoint_oaOpPointHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaAnalysisOpPoint_oaOpPointHeader_tp_assign,METH_VARARGS,oaCollection_oaAnalysisOpPoint_oaOpPointHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaAnalysisOpPoint_oaOpPointHeader_doc[] = 
"Class: oaCollection_oaAnalysisOpPoint_oaOpPointHeader\n"
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
"  Paramegers: (oaCollection_oaAnalysisOpPoint_oaOpPointHeader)\n"
"    Calls: oaCollection_oaAnalysisOpPoint_oaOpPointHeader(const oaCollection_oaAnalysisOpPoint_oaOpPointHeader& coll)\n"
"    Signature: oaCollection_oaAnalysisOpPoint_oaOpPointHeader||cref-oaCollection_oaAnalysisOpPoint_oaOpPointHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaAnalysisOpPoint_oaOpPointHeader)\n"
"    Calls: (const oaCollection_oaAnalysisOpPoint_oaOpPointHeader&)\n"
"    Signature: oaCollection_oaAnalysisOpPoint_oaOpPointHeader||cref-oaCollection_oaAnalysisOpPoint_oaOpPointHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAnalysisOpPoint_oaOpPointHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAnalysisOpPoint_oaOpPointHeader",
    sizeof(PyoaCollection_oaAnalysisOpPoint_oaOpPointHeaderObject),
    0,
    (destructor)oaCollection_oaAnalysisOpPoint_oaOpPointHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAnalysisOpPoint_oaOpPointHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAnalysisOpPoint_oaOpPointHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAnalysisOpPoint_oaOpPointHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaAnalysisOpPoint_oaOpPointHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAnalysisOpPoint_oaOpPointHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAnalysisOpPoint_oaOpPointHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAnalysisOpPoint_oaOpPointHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAnalysisOpPoint_oaOpPointHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAnalysisOpPoint_oaOpPointHeader",
           (PyObject*)(&PyoaCollection_oaAnalysisOpPoint_oaOpPointHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAnalysisOpPoint_oaOpPointHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAnalysisPoint_oaDesign
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAnalysisPoint_oaDesign_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAnalysisPoint_oaDesign_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAnalysisPoint_oaDesignObject* self = (PyoaCollection_oaAnalysisPoint_oaDesignObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAnalysisPoint_oaDesign)
    {
        PyParamoaCollection_oaAnalysisPoint_oaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAnalysisPoint_oaDesign_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaAnalysisPoint_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAnalysisPoint_oaDesign, Choices are:\n"
        "    (oaCollection_oaAnalysisPoint_oaDesign)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAnalysisPoint_oaDesign_tp_dealloc(PyoaCollection_oaAnalysisPoint_oaDesignObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaAnalysisPoint_oaDesign*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAnalysisPoint_oaDesign_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAnalysisPoint_oaDesign value;
    int convert_status=PyoaCollection_oaAnalysisPoint_oaDesign_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[59];
    sprintf(buffer,"<oaCollection_oaAnalysisPoint_oaDesign::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAnalysisPoint_oaDesign_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAnalysisPoint_oaDesign v1;
    PyParamoaCollection_oaAnalysisPoint_oaDesign v2;
    int convert_status1=PyoaCollection_oaAnalysisPoint_oaDesign_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAnalysisPoint_oaDesign_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAnalysisPoint_oaDesign_Convert(PyObject* ob,PyParamoaCollection_oaAnalysisPoint_oaDesign* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAnalysisPoint_oaDesign_Check(ob)) {
        result->SetData( (oaCollection_oaAnalysisPoint_oaDesign*) ((PyoaCollection_oaAnalysisPoint_oaDesignObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAnalysisPoint_oaDesign Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAnalysisPoint_oaDesign_FromoaCollection_oaAnalysisPoint_oaDesign(oaCollection_oaAnalysisPoint_oaDesign* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAnalysisPoint_oaDesign_Type.tp_alloc(&PyoaCollection_oaAnalysisPoint_oaDesign_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAnalysisPoint_oaDesignObject* self = (PyoaCollection_oaAnalysisPoint_oaDesignObject*)bself;
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
static char oaCollection_oaAnalysisPoint_oaDesign_includes_doc[] = 
"Class: oaCollection_oaAnalysisPoint_oaDesign, Function: includes\n"
"  Paramegers: (oaAnalysisPoint)\n"
"    Calls: oaBoolean includes(const oaAnalysisPoint* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaAnalysisPoint,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaAnalysisPoint_oaDesign_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaAnalysisPoint_oaDesign data;
    int convert_status=PyoaCollection_oaAnalysisPoint_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaAnalysisPoint_oaDesignObject* self=(PyoaCollection_oaAnalysisPoint_oaDesignObject*)ob;

    PyParamoaAnalysisPoint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaAnalysisPoint_Convert,&p1)) {
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

static char oaCollection_oaAnalysisPoint_oaDesign_assign_doc[] = 
"Class: oaCollection_oaAnalysisPoint_oaDesign, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaAnalysisPoint_oaDesign_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaAnalysisPoint_oaDesign data;
  int convert_status=PyoaCollection_oaAnalysisPoint_oaDesign_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaAnalysisPoint_oaDesign p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaAnalysisPoint_oaDesign_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaAnalysisPoint_oaDesign_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaAnalysisPoint_oaDesign_includes,METH_VARARGS,oaCollection_oaAnalysisPoint_oaDesign_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaAnalysisPoint_oaDesign_tp_assign,METH_VARARGS,oaCollection_oaAnalysisPoint_oaDesign_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaAnalysisPoint_oaDesign_doc[] = 
"Class: oaCollection_oaAnalysisPoint_oaDesign\n"
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
"  Paramegers: (oaCollection_oaAnalysisPoint_oaDesign)\n"
"    Calls: oaCollection_oaAnalysisPoint_oaDesign(const oaCollection_oaAnalysisPoint_oaDesign& coll)\n"
"    Signature: oaCollection_oaAnalysisPoint_oaDesign||cref-oaCollection_oaAnalysisPoint_oaDesign,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaAnalysisPoint_oaDesign)\n"
"    Calls: (const oaCollection_oaAnalysisPoint_oaDesign&)\n"
"    Signature: oaCollection_oaAnalysisPoint_oaDesign||cref-oaCollection_oaAnalysisPoint_oaDesign,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAnalysisPoint_oaDesign_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAnalysisPoint_oaDesign",
    sizeof(PyoaCollection_oaAnalysisPoint_oaDesignObject),
    0,
    (destructor)oaCollection_oaAnalysisPoint_oaDesign_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAnalysisPoint_oaDesign_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAnalysisPoint_oaDesign_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAnalysisPoint_oaDesign_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaAnalysisPoint_oaDesign_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAnalysisPoint_oaDesign_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAnalysisPoint_oaDesign_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAnalysisPoint_oaDesign_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAnalysisPoint_oaDesign\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAnalysisPoint_oaDesign",
           (PyObject*)(&PyoaCollection_oaAnalysisPoint_oaDesign_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAnalysisPoint_oaDesign\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAnalysisPoint_oaParasiticNetwork
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAnalysisPoint_oaParasiticNetwork_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAnalysisPoint_oaParasiticNetwork_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAnalysisPoint_oaParasiticNetworkObject* self = (PyoaCollection_oaAnalysisPoint_oaParasiticNetworkObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAnalysisPoint_oaParasiticNetwork)
    {
        PyParamoaCollection_oaAnalysisPoint_oaParasiticNetwork p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAnalysisPoint_oaParasiticNetwork_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaAnalysisPoint_oaParasiticNetwork(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAnalysisPoint_oaParasiticNetwork, Choices are:\n"
        "    (oaCollection_oaAnalysisPoint_oaParasiticNetwork)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAnalysisPoint_oaParasiticNetwork_tp_dealloc(PyoaCollection_oaAnalysisPoint_oaParasiticNetworkObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaAnalysisPoint_oaParasiticNetwork*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAnalysisPoint_oaParasiticNetwork_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAnalysisPoint_oaParasiticNetwork value;
    int convert_status=PyoaCollection_oaAnalysisPoint_oaParasiticNetwork_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[69];
    sprintf(buffer,"<oaCollection_oaAnalysisPoint_oaParasiticNetwork::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAnalysisPoint_oaParasiticNetwork_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAnalysisPoint_oaParasiticNetwork v1;
    PyParamoaCollection_oaAnalysisPoint_oaParasiticNetwork v2;
    int convert_status1=PyoaCollection_oaAnalysisPoint_oaParasiticNetwork_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAnalysisPoint_oaParasiticNetwork_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAnalysisPoint_oaParasiticNetwork_Convert(PyObject* ob,PyParamoaCollection_oaAnalysisPoint_oaParasiticNetwork* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAnalysisPoint_oaParasiticNetwork_Check(ob)) {
        result->SetData( (oaCollection_oaAnalysisPoint_oaParasiticNetwork*) ((PyoaCollection_oaAnalysisPoint_oaParasiticNetworkObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAnalysisPoint_oaParasiticNetwork Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAnalysisPoint_oaParasiticNetwork_FromoaCollection_oaAnalysisPoint_oaParasiticNetwork(oaCollection_oaAnalysisPoint_oaParasiticNetwork* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAnalysisPoint_oaParasiticNetwork_Type.tp_alloc(&PyoaCollection_oaAnalysisPoint_oaParasiticNetwork_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAnalysisPoint_oaParasiticNetworkObject* self = (PyoaCollection_oaAnalysisPoint_oaParasiticNetworkObject*)bself;
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
static char oaCollection_oaAnalysisPoint_oaParasiticNetwork_includes_doc[] = 
"Class: oaCollection_oaAnalysisPoint_oaParasiticNetwork, Function: includes\n"
"  Paramegers: (oaAnalysisPoint)\n"
"    Calls: oaBoolean includes(const oaAnalysisPoint* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaAnalysisPoint,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaAnalysisPoint_oaParasiticNetwork_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaAnalysisPoint_oaParasiticNetwork data;
    int convert_status=PyoaCollection_oaAnalysisPoint_oaParasiticNetwork_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaAnalysisPoint_oaParasiticNetworkObject* self=(PyoaCollection_oaAnalysisPoint_oaParasiticNetworkObject*)ob;

    PyParamoaAnalysisPoint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaAnalysisPoint_Convert,&p1)) {
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

static char oaCollection_oaAnalysisPoint_oaParasiticNetwork_assign_doc[] = 
"Class: oaCollection_oaAnalysisPoint_oaParasiticNetwork, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaAnalysisPoint_oaParasiticNetwork_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaAnalysisPoint_oaParasiticNetwork data;
  int convert_status=PyoaCollection_oaAnalysisPoint_oaParasiticNetwork_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaAnalysisPoint_oaParasiticNetwork p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaAnalysisPoint_oaParasiticNetwork_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaAnalysisPoint_oaParasiticNetwork_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaAnalysisPoint_oaParasiticNetwork_includes,METH_VARARGS,oaCollection_oaAnalysisPoint_oaParasiticNetwork_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaAnalysisPoint_oaParasiticNetwork_tp_assign,METH_VARARGS,oaCollection_oaAnalysisPoint_oaParasiticNetwork_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaAnalysisPoint_oaParasiticNetwork_doc[] = 
"Class: oaCollection_oaAnalysisPoint_oaParasiticNetwork\n"
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
"  Paramegers: (oaCollection_oaAnalysisPoint_oaParasiticNetwork)\n"
"    Calls: oaCollection_oaAnalysisPoint_oaParasiticNetwork(const oaCollection_oaAnalysisPoint_oaParasiticNetwork& coll)\n"
"    Signature: oaCollection_oaAnalysisPoint_oaParasiticNetwork||cref-oaCollection_oaAnalysisPoint_oaParasiticNetwork,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaAnalysisPoint_oaParasiticNetwork)\n"
"    Calls: (const oaCollection_oaAnalysisPoint_oaParasiticNetwork&)\n"
"    Signature: oaCollection_oaAnalysisPoint_oaParasiticNetwork||cref-oaCollection_oaAnalysisPoint_oaParasiticNetwork,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAnalysisPoint_oaParasiticNetwork_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAnalysisPoint_oaParasiticNetwork",
    sizeof(PyoaCollection_oaAnalysisPoint_oaParasiticNetworkObject),
    0,
    (destructor)oaCollection_oaAnalysisPoint_oaParasiticNetwork_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAnalysisPoint_oaParasiticNetwork_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAnalysisPoint_oaParasiticNetwork_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAnalysisPoint_oaParasiticNetwork_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaAnalysisPoint_oaParasiticNetwork_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAnalysisPoint_oaParasiticNetwork_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAnalysisPoint_oaParasiticNetwork_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAnalysisPoint_oaParasiticNetwork_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAnalysisPoint_oaParasiticNetwork\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAnalysisPoint_oaParasiticNetwork",
           (PyObject*)(&PyoaCollection_oaAnalysisPoint_oaParasiticNetwork_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAnalysisPoint_oaParasiticNetwork\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAppDef_oaDMData
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppDef_oaDMData_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAppDef_oaDMData_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAppDef_oaDMDataObject* self = (PyoaCollection_oaAppDef_oaDMDataObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAppDef_oaDMData)
    {
        PyParamoaCollection_oaAppDef_oaDMData p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAppDef_oaDMData_Convert,&p1)) {
            self->value = (oaCollection_oaAppDef_oaObject*)  new oaCollection_oaAppDef_oaDMData(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAppDef_oaDMData, Choices are:\n"
        "    (oaCollection_oaAppDef_oaDMData)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAppDef_oaDMData_tp_dealloc(PyoaCollection_oaAppDef_oaDMDataObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaAppDef_oaDMData*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppDef_oaDMData_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAppDef_oaDMData value;
    int convert_status=PyoaCollection_oaAppDef_oaDMData_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaAppDef_oaDMData::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAppDef_oaDMData_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAppDef_oaDMData v1;
    PyParamoaCollection_oaAppDef_oaDMData v2;
    int convert_status1=PyoaCollection_oaAppDef_oaDMData_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAppDef_oaDMData_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAppDef_oaDMData_Convert(PyObject* ob,PyParamoaCollection_oaAppDef_oaDMData* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAppDef_oaDMData_Check(ob)) {
        result->SetData( (oaCollection_oaAppDef_oaDMData*) ((PyoaCollection_oaAppDef_oaDMDataObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAppDef_oaDMData Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAppDef_oaDMData_FromoaCollection_oaAppDef_oaDMData(oaCollection_oaAppDef_oaDMData* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAppDef_oaDMData_Type.tp_alloc(&PyoaCollection_oaAppDef_oaDMData_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAppDef_oaDMDataObject* self = (PyoaCollection_oaAppDef_oaDMDataObject*)bself;
        self->value = (oaCollection_oaAppDef_oaObject*)  data;
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
static char oaCollection_oaAppDef_oaDMData_doc[] = 
"Class: oaCollection_oaAppDef_oaDMData\n"
"  Class type oaCollection_oaAppDef_oaDMData\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaAppDef_oaDMData)\n"
"    Calls: oaCollection_oaAppDef_oaDMData(const oaCollection_oaAppDef_oaDMData& c)\n"
"    Signature: oaCollection_oaAppDef_oaDMData||cref-oaCollection_oaAppDef_oaDMData,\n"
"    Constructor oaCollection_oaAppDef_oaDMData\n"
"  Paramegers: (oaCollection_oaAppDef_oaDMData)\n"
"    Calls: (const oaCollection_oaAppDef_oaDMData&)\n"
"    Signature: oaCollection_oaAppDef_oaDMData||cref-oaCollection_oaAppDef_oaDMData,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAppDef_oaDMData_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAppDef_oaDMData",
    sizeof(PyoaCollection_oaAppDef_oaDMDataObject),
    0,
    (destructor)oaCollection_oaAppDef_oaDMData_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAppDef_oaDMData_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAppDef_oaDMData_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAppDef_oaDMData_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaCollection_oaAppDef_oaObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAppDef_oaDMData_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAppDef_oaDMData_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAppDef_oaDMData_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAppDef_oaDMData\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAppDef_oaDMData",
           (PyObject*)(&PyoaCollection_oaAppDef_oaDMData_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAppDef_oaDMData\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAppDef_oaDesign
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppDef_oaDesign_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAppDef_oaDesign_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAppDef_oaDesignObject* self = (PyoaCollection_oaAppDef_oaDesignObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAppDef_oaDesign)
    {
        PyParamoaCollection_oaAppDef_oaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAppDef_oaDesign_Convert,&p1)) {
            self->value = (oaCollection_oaAppDef_oaObject*)  new oaCollection_oaAppDef_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAppDef_oaDesign, Choices are:\n"
        "    (oaCollection_oaAppDef_oaDesign)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAppDef_oaDesign_tp_dealloc(PyoaCollection_oaAppDef_oaDesignObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaAppDef_oaDesign*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppDef_oaDesign_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAppDef_oaDesign value;
    int convert_status=PyoaCollection_oaAppDef_oaDesign_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaAppDef_oaDesign::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAppDef_oaDesign_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAppDef_oaDesign v1;
    PyParamoaCollection_oaAppDef_oaDesign v2;
    int convert_status1=PyoaCollection_oaAppDef_oaDesign_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAppDef_oaDesign_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAppDef_oaDesign_Convert(PyObject* ob,PyParamoaCollection_oaAppDef_oaDesign* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAppDef_oaDesign_Check(ob)) {
        result->SetData( (oaCollection_oaAppDef_oaDesign*) ((PyoaCollection_oaAppDef_oaDesignObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAppDef_oaDesign Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAppDef_oaDesign_FromoaCollection_oaAppDef_oaDesign(oaCollection_oaAppDef_oaDesign* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAppDef_oaDesign_Type.tp_alloc(&PyoaCollection_oaAppDef_oaDesign_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAppDef_oaDesignObject* self = (PyoaCollection_oaAppDef_oaDesignObject*)bself;
        self->value = (oaCollection_oaAppDef_oaObject*)  data;
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
static char oaCollection_oaAppDef_oaDesign_doc[] = 
"Class: oaCollection_oaAppDef_oaDesign\n"
"  Class type oaCollection_oaAppDef_oaDesign\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaAppDef_oaDesign)\n"
"    Calls: oaCollection_oaAppDef_oaDesign(const oaCollection_oaAppDef_oaDesign& c)\n"
"    Signature: oaCollection_oaAppDef_oaDesign||cref-oaCollection_oaAppDef_oaDesign,\n"
"    Constructor oaCollection_oaAppDef_oaDesign\n"
"  Paramegers: (oaCollection_oaAppDef_oaDesign)\n"
"    Calls: (const oaCollection_oaAppDef_oaDesign&)\n"
"    Signature: oaCollection_oaAppDef_oaDesign||cref-oaCollection_oaAppDef_oaDesign,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAppDef_oaDesign_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAppDef_oaDesign",
    sizeof(PyoaCollection_oaAppDef_oaDesignObject),
    0,
    (destructor)oaCollection_oaAppDef_oaDesign_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAppDef_oaDesign_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAppDef_oaDesign_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAppDef_oaDesign_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaCollection_oaAppDef_oaObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAppDef_oaDesign_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAppDef_oaDesign_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAppDef_oaDesign_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAppDef_oaDesign\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAppDef_oaDesign",
           (PyObject*)(&PyoaCollection_oaAppDef_oaDesign_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAppDef_oaDesign\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAppDef_oaObject
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppDef_oaObject_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAppDef_oaObject_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAppDef_oaObjectObject* self = (PyoaCollection_oaAppDef_oaObjectObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAppDef_oaObject)
    {
        PyParamoaCollection_oaAppDef_oaObject p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAppDef_oaObject_Convert,&p1)) {
            self->value =  new oaCollection_oaAppDef_oaObject(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAppDef_oaObject, Choices are:\n"
        "    (oaCollection_oaAppDef_oaObject)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAppDef_oaObject_tp_dealloc(PyoaCollection_oaAppDef_oaObjectObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppDef_oaObject_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAppDef_oaObject value;
    int convert_status=PyoaCollection_oaAppDef_oaObject_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaAppDef_oaObject::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAppDef_oaObject_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAppDef_oaObject v1;
    PyParamoaCollection_oaAppDef_oaObject v2;
    int convert_status1=PyoaCollection_oaAppDef_oaObject_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAppDef_oaObject_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAppDef_oaObject_Convert(PyObject* ob,PyParamoaCollection_oaAppDef_oaObject* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAppDef_oaObject_Check(ob)) {
        result->SetData(  ((PyoaCollection_oaAppDef_oaObjectObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAppDef_oaObject Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAppDef_oaObject_FromoaCollection_oaAppDef_oaObject(oaCollection_oaAppDef_oaObject* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAppDef_oaObject_Type.tp_alloc(&PyoaCollection_oaAppDef_oaObject_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAppDef_oaObjectObject* self = (PyoaCollection_oaAppDef_oaObjectObject*)bself;
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
static char oaCollection_oaAppDef_oaObject_getCount_doc[] = 
"Class: oaCollection_oaAppDef_oaObject, Function: getCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCount() const\n"
"    Signature: getCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    Function getCount\n"
;

static PyObject*
oaCollection_oaAppDef_oaObject_getCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaAppDef_oaObject data;
    int convert_status=PyoaCollection_oaAppDef_oaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaAppDef_oaObjectObject* self=(PyoaCollection_oaAppDef_oaObjectObject*)ob;

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
static char oaCollection_oaAppDef_oaObject_includes_doc[] = 
"Class: oaCollection_oaAppDef_oaObject, Function: includes\n"
"  Paramegers: (oaAppDef)\n"
"    Calls: oaBoolean includes(const oaAppDef* object) const\n"
"    Signature: includes|simple-oaBoolean|cptr-oaAppDef,\n"
"    Function includes\n"
;

static PyObject*
oaCollection_oaAppDef_oaObject_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaAppDef_oaObject data;
    int convert_status=PyoaCollection_oaAppDef_oaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaAppDef_oaObjectObject* self=(PyoaCollection_oaAppDef_oaObjectObject*)ob;

    PyParamoaAppDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaAppDef_Convert,&p1)) {
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
static char oaCollection_oaAppDef_oaObject_isEmpty_doc[] = 
"Class: oaCollection_oaAppDef_oaObject, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty() const\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    Function isEmpty\n"
;

static PyObject*
oaCollection_oaAppDef_oaObject_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaAppDef_oaObject data;
    int convert_status=PyoaCollection_oaAppDef_oaObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaAppDef_oaObjectObject* self=(PyoaCollection_oaAppDef_oaObjectObject*)ob;

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

static char oaCollection_oaAppDef_oaObject_assign_doc[] = 
"Class: oaCollection_oaAppDef_oaObject, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaAppDef_oaObject_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaAppDef_oaObject data;
  int convert_status=PyoaCollection_oaAppDef_oaObject_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaAppDef_oaObject p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaAppDef_oaObject_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaAppDef_oaObject_methodlist[] = {
    {"getCount",(PyCFunction)oaCollection_oaAppDef_oaObject_getCount,METH_VARARGS,oaCollection_oaAppDef_oaObject_getCount_doc},
    {"includes",(PyCFunction)oaCollection_oaAppDef_oaObject_includes,METH_VARARGS,oaCollection_oaAppDef_oaObject_includes_doc},
    {"isEmpty",(PyCFunction)oaCollection_oaAppDef_oaObject_isEmpty,METH_VARARGS,oaCollection_oaAppDef_oaObject_isEmpty_doc},
    {"assign",(PyCFunction)oaCollection_oaAppDef_oaObject_tp_assign,METH_VARARGS,oaCollection_oaAppDef_oaObject_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaAppDef_oaObject_doc[] = 
"Class: oaCollection_oaAppDef_oaObject\n"
"  Class type oaCollection_oaAppDef_oaObject\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaAppDef_oaObject)\n"
"    Calls: oaCollection_oaAppDef_oaObject(const oaCollection_oaAppDef_oaObject& c)\n"
"    Signature: oaCollection_oaAppDef_oaObject||cref-oaCollection_oaAppDef_oaObject,\n"
"    Constructor oaCollection_oaAppDef_oaObject\n"
"  Paramegers: (oaCollection_oaAppDef_oaObject)\n"
"    Calls: (const oaCollection_oaAppDef_oaObject&)\n"
"    Signature: oaCollection_oaAppDef_oaObject||cref-oaCollection_oaAppDef_oaObject,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAppDef_oaObject_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAppDef_oaObject",
    sizeof(PyoaCollection_oaAppDef_oaObjectObject),
    0,
    (destructor)oaCollection_oaAppDef_oaObject_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAppDef_oaObject_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAppDef_oaObject_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAppDef_oaObject_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaAppDef_oaObject_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAppDef_oaObject_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAppDef_oaObject_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAppDef_oaObject_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAppDef_oaObject\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAppDef_oaObject",
           (PyObject*)(&PyoaCollection_oaAppDef_oaObject_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAppDef_oaObject\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAppDef_oaSession
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppDef_oaSession_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAppDef_oaSession_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAppDef_oaSessionObject* self = (PyoaCollection_oaAppDef_oaSessionObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAppDef_oaSession, Choices are:\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAppDef_oaSession_tp_dealloc(PyoaCollection_oaAppDef_oaSessionObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppDef_oaSession_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAppDef_oaSession value;
    int convert_status=PyoaCollection_oaAppDef_oaSession_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[53];
    sprintf(buffer,"<oaCollection_oaAppDef_oaSession::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAppDef_oaSession_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAppDef_oaSession v1;
    PyParamoaCollection_oaAppDef_oaSession v2;
    int convert_status1=PyoaCollection_oaAppDef_oaSession_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAppDef_oaSession_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAppDef_oaSession_Convert(PyObject* ob,PyParamoaCollection_oaAppDef_oaSession* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAppDef_oaSession_Check(ob)) {
        result->SetData(  ((PyoaCollection_oaAppDef_oaSessionObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAppDef_oaSession Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAppDef_oaSession_FromoaCollection_oaAppDef_oaSession(oaCollection_oaAppDef_oaSession* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAppDef_oaSession_Type.tp_alloc(&PyoaCollection_oaAppDef_oaSession_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAppDef_oaSessionObject* self = (PyoaCollection_oaAppDef_oaSessionObject*)bself;
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
static char oaCollection_oaAppDef_oaSession_getCount_doc[] = 
"Class: oaCollection_oaAppDef_oaSession, Function: getCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCount() const\n"
"    Signature: getCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    Function getCount\n"
;

static PyObject*
oaCollection_oaAppDef_oaSession_getCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaAppDef_oaSession data;
    int convert_status=PyoaCollection_oaAppDef_oaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaAppDef_oaSessionObject* self=(PyoaCollection_oaAppDef_oaSessionObject*)ob;

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
static char oaCollection_oaAppDef_oaSession_isEmpty_doc[] = 
"Class: oaCollection_oaAppDef_oaSession, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty() const\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    Function isEmpty\n"
;

static PyObject*
oaCollection_oaAppDef_oaSession_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaAppDef_oaSession data;
    int convert_status=PyoaCollection_oaAppDef_oaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaAppDef_oaSessionObject* self=(PyoaCollection_oaAppDef_oaSessionObject*)ob;

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

static char oaCollection_oaAppDef_oaSession_assign_doc[] = 
"Class: oaCollection_oaAppDef_oaSession, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaAppDef_oaSession_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaAppDef_oaSession data;
  int convert_status=PyoaCollection_oaAppDef_oaSession_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaAppDef_oaSession p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaAppDef_oaSession_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaAppDef_oaSession_methodlist[] = {
    {"getCount",(PyCFunction)oaCollection_oaAppDef_oaSession_getCount,METH_VARARGS,oaCollection_oaAppDef_oaSession_getCount_doc},
    {"isEmpty",(PyCFunction)oaCollection_oaAppDef_oaSession_isEmpty,METH_VARARGS,oaCollection_oaAppDef_oaSession_isEmpty_doc},
    {"assign",(PyCFunction)oaCollection_oaAppDef_oaSession_tp_assign,METH_VARARGS,oaCollection_oaAppDef_oaSession_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaAppDef_oaSession_doc[] = 
"Class: oaCollection_oaAppDef_oaSession\n"
"  Class type oaCollection_oaAppDef_oaSession\n"
"Constructors:\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAppDef_oaSession_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAppDef_oaSession",
    sizeof(PyoaCollection_oaAppDef_oaSessionObject),
    0,
    (destructor)oaCollection_oaAppDef_oaSession_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAppDef_oaSession_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAppDef_oaSession_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAppDef_oaSession_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaAppDef_oaSession_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAppDef_oaSession_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAppDef_oaSession_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAppDef_oaSession_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAppDef_oaSession\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAppDef_oaSession",
           (PyObject*)(&PyoaCollection_oaAppDef_oaSession_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAppDef_oaSession\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAppDef_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppDef_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAppDef_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAppDef_oaTechObject* self = (PyoaCollection_oaAppDef_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAppDef_oaTech)
    {
        PyParamoaCollection_oaAppDef_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAppDef_oaTech_Convert,&p1)) {
            self->value = (oaCollection_oaAppDef_oaObject*)  new oaCollection_oaAppDef_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAppDef_oaTech, Choices are:\n"
        "    (oaCollection_oaAppDef_oaTech)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAppDef_oaTech_tp_dealloc(PyoaCollection_oaAppDef_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaAppDef_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppDef_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAppDef_oaTech value;
    int convert_status=PyoaCollection_oaAppDef_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaCollection_oaAppDef_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAppDef_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAppDef_oaTech v1;
    PyParamoaCollection_oaAppDef_oaTech v2;
    int convert_status1=PyoaCollection_oaAppDef_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAppDef_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAppDef_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaAppDef_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAppDef_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaAppDef_oaTech*) ((PyoaCollection_oaAppDef_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAppDef_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAppDef_oaTech_FromoaCollection_oaAppDef_oaTech(oaCollection_oaAppDef_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAppDef_oaTech_Type.tp_alloc(&PyoaCollection_oaAppDef_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAppDef_oaTechObject* self = (PyoaCollection_oaAppDef_oaTechObject*)bself;
        self->value = (oaCollection_oaAppDef_oaObject*)  data;
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
static char oaCollection_oaAppDef_oaTech_doc[] = 
"Class: oaCollection_oaAppDef_oaTech\n"
"  Class type oaCollection_oaAppDef_oaTech\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaAppDef_oaTech)\n"
"    Calls: oaCollection_oaAppDef_oaTech(const oaCollection_oaAppDef_oaTech& c)\n"
"    Signature: oaCollection_oaAppDef_oaTech||cref-oaCollection_oaAppDef_oaTech,\n"
"    Constructor oaCollection_oaAppDef_oaTech\n"
"  Paramegers: (oaCollection_oaAppDef_oaTech)\n"
"    Calls: (const oaCollection_oaAppDef_oaTech&)\n"
"    Signature: oaCollection_oaAppDef_oaTech||cref-oaCollection_oaAppDef_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAppDef_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAppDef_oaTech",
    sizeof(PyoaCollection_oaAppDef_oaTechObject),
    0,
    (destructor)oaCollection_oaAppDef_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAppDef_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAppDef_oaTech_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAppDef_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaCollection_oaAppDef_oaObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAppDef_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAppDef_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAppDef_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAppDef_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAppDef_oaTech",
           (PyObject*)(&PyoaCollection_oaAppDef_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAppDef_oaTech\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAppObjectDef_oaDMData
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppObjectDef_oaDMData_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAppObjectDef_oaDMData_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAppObjectDef_oaDMDataObject* self = (PyoaCollection_oaAppObjectDef_oaDMDataObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAppObjectDef_oaDMData)
    {
        PyParamoaCollection_oaAppObjectDef_oaDMData p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAppObjectDef_oaDMData_Convert,&p1)) {
            self->value = (oaAppObjectDefCollection*)  new oaCollection_oaAppObjectDef_oaDMData(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAppObjectDef_oaDMData, Choices are:\n"
        "    (oaCollection_oaAppObjectDef_oaDMData)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAppObjectDef_oaDMData_tp_dealloc(PyoaCollection_oaAppObjectDef_oaDMDataObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaAppObjectDef_oaDMData*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppObjectDef_oaDMData_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAppObjectDef_oaDMData value;
    int convert_status=PyoaCollection_oaAppObjectDef_oaDMData_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[58];
    sprintf(buffer,"<oaCollection_oaAppObjectDef_oaDMData::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAppObjectDef_oaDMData_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAppObjectDef_oaDMData v1;
    PyParamoaCollection_oaAppObjectDef_oaDMData v2;
    int convert_status1=PyoaCollection_oaAppObjectDef_oaDMData_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAppObjectDef_oaDMData_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAppObjectDef_oaDMData_Convert(PyObject* ob,PyParamoaCollection_oaAppObjectDef_oaDMData* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAppObjectDef_oaDMData_Check(ob)) {
        result->SetData( (oaCollection_oaAppObjectDef_oaDMData*) ((PyoaCollection_oaAppObjectDef_oaDMDataObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAppObjectDef_oaDMData Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAppObjectDef_oaDMData_FromoaCollection_oaAppObjectDef_oaDMData(oaCollection_oaAppObjectDef_oaDMData* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAppObjectDef_oaDMData_Type.tp_alloc(&PyoaCollection_oaAppObjectDef_oaDMData_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAppObjectDef_oaDMDataObject* self = (PyoaCollection_oaAppObjectDef_oaDMDataObject*)bself;
        self->value = (oaAppObjectDefCollection*)  data;
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
static char oaCollection_oaAppObjectDef_oaDMData_doc[] = 
"Class: oaCollection_oaAppObjectDef_oaDMData\n"
"  Class type oaCollection_oaAppObjectDef_oaDMData\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaAppObjectDef_oaDMData)\n"
"    Calls: oaCollection_oaAppObjectDef_oaDMData(const oaCollection_oaAppObjectDef_oaDMData& c)\n"
"    Signature: oaCollection_oaAppObjectDef_oaDMData||cref-oaCollection_oaAppObjectDef_oaDMData,\n"
"    Constructor oaCollection_oaAppObjectDef_oaDMData\n"
"  Paramegers: (oaCollection_oaAppObjectDef_oaDMData)\n"
"    Calls: (const oaCollection_oaAppObjectDef_oaDMData&)\n"
"    Signature: oaCollection_oaAppObjectDef_oaDMData||cref-oaCollection_oaAppObjectDef_oaDMData,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAppObjectDef_oaDMData_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAppObjectDef_oaDMData",
    sizeof(PyoaCollection_oaAppObjectDef_oaDMDataObject),
    0,
    (destructor)oaCollection_oaAppObjectDef_oaDMData_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAppObjectDef_oaDMData_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAppObjectDef_oaDMData_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAppObjectDef_oaDMData_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaAppObjectDefCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAppObjectDef_oaDMData_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAppObjectDef_oaDMData_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAppObjectDef_oaDMData_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAppObjectDef_oaDMData\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAppObjectDef_oaDMData",
           (PyObject*)(&PyoaCollection_oaAppObjectDef_oaDMData_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAppObjectDef_oaDMData\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAppObjectDef_oaDesign
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppObjectDef_oaDesign_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAppObjectDef_oaDesign_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAppObjectDef_oaDesignObject* self = (PyoaCollection_oaAppObjectDef_oaDesignObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAppObjectDef_oaDesign)
    {
        PyParamoaCollection_oaAppObjectDef_oaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAppObjectDef_oaDesign_Convert,&p1)) {
            self->value = (oaAppObjectDefCollection*)  new oaCollection_oaAppObjectDef_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAppObjectDef_oaDesign, Choices are:\n"
        "    (oaCollection_oaAppObjectDef_oaDesign)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAppObjectDef_oaDesign_tp_dealloc(PyoaCollection_oaAppObjectDef_oaDesignObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaAppObjectDef_oaDesign*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppObjectDef_oaDesign_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAppObjectDef_oaDesign value;
    int convert_status=PyoaCollection_oaAppObjectDef_oaDesign_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[58];
    sprintf(buffer,"<oaCollection_oaAppObjectDef_oaDesign::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAppObjectDef_oaDesign_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAppObjectDef_oaDesign v1;
    PyParamoaCollection_oaAppObjectDef_oaDesign v2;
    int convert_status1=PyoaCollection_oaAppObjectDef_oaDesign_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAppObjectDef_oaDesign_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAppObjectDef_oaDesign_Convert(PyObject* ob,PyParamoaCollection_oaAppObjectDef_oaDesign* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAppObjectDef_oaDesign_Check(ob)) {
        result->SetData( (oaCollection_oaAppObjectDef_oaDesign*) ((PyoaCollection_oaAppObjectDef_oaDesignObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAppObjectDef_oaDesign Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAppObjectDef_oaDesign_FromoaCollection_oaAppObjectDef_oaDesign(oaCollection_oaAppObjectDef_oaDesign* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAppObjectDef_oaDesign_Type.tp_alloc(&PyoaCollection_oaAppObjectDef_oaDesign_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAppObjectDef_oaDesignObject* self = (PyoaCollection_oaAppObjectDef_oaDesignObject*)bself;
        self->value = (oaAppObjectDefCollection*)  data;
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
static char oaCollection_oaAppObjectDef_oaDesign_doc[] = 
"Class: oaCollection_oaAppObjectDef_oaDesign\n"
"  Class type oaCollection_oaAppObjectDef_oaDesign\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaAppObjectDef_oaDesign)\n"
"    Calls: oaCollection_oaAppObjectDef_oaDesign(const oaCollection_oaAppObjectDef_oaDesign& c)\n"
"    Signature: oaCollection_oaAppObjectDef_oaDesign||cref-oaCollection_oaAppObjectDef_oaDesign,\n"
"    Constructor oaCollection_oaAppObjectDef_oaDesign\n"
"  Paramegers: (oaCollection_oaAppObjectDef_oaDesign)\n"
"    Calls: (const oaCollection_oaAppObjectDef_oaDesign&)\n"
"    Signature: oaCollection_oaAppObjectDef_oaDesign||cref-oaCollection_oaAppObjectDef_oaDesign,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAppObjectDef_oaDesign_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAppObjectDef_oaDesign",
    sizeof(PyoaCollection_oaAppObjectDef_oaDesignObject),
    0,
    (destructor)oaCollection_oaAppObjectDef_oaDesign_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAppObjectDef_oaDesign_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAppObjectDef_oaDesign_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAppObjectDef_oaDesign_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaAppObjectDefCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAppObjectDef_oaDesign_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAppObjectDef_oaDesign_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAppObjectDef_oaDesign_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAppObjectDef_oaDesign\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAppObjectDef_oaDesign",
           (PyObject*)(&PyoaCollection_oaAppObjectDef_oaDesign_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAppObjectDef_oaDesign\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAppObjectDef_oaSession
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppObjectDef_oaSession_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAppObjectDef_oaSession_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAppObjectDef_oaSessionObject* self = (PyoaCollection_oaAppObjectDef_oaSessionObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAppObjectDef_oaSession, Choices are:\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAppObjectDef_oaSession_tp_dealloc(PyoaCollection_oaAppObjectDef_oaSessionObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppObjectDef_oaSession_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAppObjectDef_oaSession value;
    int convert_status=PyoaCollection_oaAppObjectDef_oaSession_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[59];
    sprintf(buffer,"<oaCollection_oaAppObjectDef_oaSession::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAppObjectDef_oaSession_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAppObjectDef_oaSession v1;
    PyParamoaCollection_oaAppObjectDef_oaSession v2;
    int convert_status1=PyoaCollection_oaAppObjectDef_oaSession_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAppObjectDef_oaSession_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAppObjectDef_oaSession_Convert(PyObject* ob,PyParamoaCollection_oaAppObjectDef_oaSession* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAppObjectDef_oaSession_Check(ob)) {
        result->SetData(  ((PyoaCollection_oaAppObjectDef_oaSessionObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAppObjectDef_oaSession Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAppObjectDef_oaSession_FromoaCollection_oaAppObjectDef_oaSession(oaCollection_oaAppObjectDef_oaSession* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAppObjectDef_oaSession_Type.tp_alloc(&PyoaCollection_oaAppObjectDef_oaSession_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAppObjectDef_oaSessionObject* self = (PyoaCollection_oaAppObjectDef_oaSessionObject*)bself;
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
static char oaCollection_oaAppObjectDef_oaSession_getCount_doc[] = 
"Class: oaCollection_oaAppObjectDef_oaSession, Function: getCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCount() const\n"
"    Signature: getCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    Function getCount\n"
;

static PyObject*
oaCollection_oaAppObjectDef_oaSession_getCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaAppObjectDef_oaSession data;
    int convert_status=PyoaCollection_oaAppObjectDef_oaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaAppObjectDef_oaSessionObject* self=(PyoaCollection_oaAppObjectDef_oaSessionObject*)ob;

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
static char oaCollection_oaAppObjectDef_oaSession_isEmpty_doc[] = 
"Class: oaCollection_oaAppObjectDef_oaSession, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty() const\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    Function isEmpty\n"
;

static PyObject*
oaCollection_oaAppObjectDef_oaSession_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaAppObjectDef_oaSession data;
    int convert_status=PyoaCollection_oaAppObjectDef_oaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaAppObjectDef_oaSessionObject* self=(PyoaCollection_oaAppObjectDef_oaSessionObject*)ob;

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

static char oaCollection_oaAppObjectDef_oaSession_assign_doc[] = 
"Class: oaCollection_oaAppObjectDef_oaSession, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaAppObjectDef_oaSession_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaAppObjectDef_oaSession data;
  int convert_status=PyoaCollection_oaAppObjectDef_oaSession_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaAppObjectDef_oaSession p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaAppObjectDef_oaSession_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaAppObjectDef_oaSession_methodlist[] = {
    {"getCount",(PyCFunction)oaCollection_oaAppObjectDef_oaSession_getCount,METH_VARARGS,oaCollection_oaAppObjectDef_oaSession_getCount_doc},
    {"isEmpty",(PyCFunction)oaCollection_oaAppObjectDef_oaSession_isEmpty,METH_VARARGS,oaCollection_oaAppObjectDef_oaSession_isEmpty_doc},
    {"assign",(PyCFunction)oaCollection_oaAppObjectDef_oaSession_tp_assign,METH_VARARGS,oaCollection_oaAppObjectDef_oaSession_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaAppObjectDef_oaSession_doc[] = 
"Class: oaCollection_oaAppObjectDef_oaSession\n"
"  Class type oaCollection_oaAppObjectDef_oaSession\n"
"Constructors:\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAppObjectDef_oaSession_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAppObjectDef_oaSession",
    sizeof(PyoaCollection_oaAppObjectDef_oaSessionObject),
    0,
    (destructor)oaCollection_oaAppObjectDef_oaSession_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAppObjectDef_oaSession_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAppObjectDef_oaSession_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAppObjectDef_oaSession_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaAppObjectDef_oaSession_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAppObjectDef_oaSession_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAppObjectDef_oaSession_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAppObjectDef_oaSession_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAppObjectDef_oaSession\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAppObjectDef_oaSession",
           (PyObject*)(&PyoaCollection_oaAppObjectDef_oaSession_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAppObjectDef_oaSession\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAppObjectDef_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppObjectDef_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAppObjectDef_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAppObjectDef_oaTechObject* self = (PyoaCollection_oaAppObjectDef_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAppObjectDef_oaTech)
    {
        PyParamoaCollection_oaAppObjectDef_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAppObjectDef_oaTech_Convert,&p1)) {
            self->value = (oaAppObjectDefCollection*)  new oaCollection_oaAppObjectDef_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAppObjectDef_oaTech, Choices are:\n"
        "    (oaCollection_oaAppObjectDef_oaTech)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAppObjectDef_oaTech_tp_dealloc(PyoaCollection_oaAppObjectDef_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaAppObjectDef_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppObjectDef_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAppObjectDef_oaTech value;
    int convert_status=PyoaCollection_oaAppObjectDef_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[56];
    sprintf(buffer,"<oaCollection_oaAppObjectDef_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAppObjectDef_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAppObjectDef_oaTech v1;
    PyParamoaCollection_oaAppObjectDef_oaTech v2;
    int convert_status1=PyoaCollection_oaAppObjectDef_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAppObjectDef_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAppObjectDef_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaAppObjectDef_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAppObjectDef_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaAppObjectDef_oaTech*) ((PyoaCollection_oaAppObjectDef_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAppObjectDef_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAppObjectDef_oaTech_FromoaCollection_oaAppObjectDef_oaTech(oaCollection_oaAppObjectDef_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAppObjectDef_oaTech_Type.tp_alloc(&PyoaCollection_oaAppObjectDef_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAppObjectDef_oaTechObject* self = (PyoaCollection_oaAppObjectDef_oaTechObject*)bself;
        self->value = (oaAppObjectDefCollection*)  data;
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
static char oaCollection_oaAppObjectDef_oaTech_doc[] = 
"Class: oaCollection_oaAppObjectDef_oaTech\n"
"  Class type oaCollection_oaAppObjectDef_oaTech\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaAppObjectDef_oaTech)\n"
"    Calls: oaCollection_oaAppObjectDef_oaTech(const oaCollection_oaAppObjectDef_oaTech& c)\n"
"    Signature: oaCollection_oaAppObjectDef_oaTech||cref-oaCollection_oaAppObjectDef_oaTech,\n"
"    Constructor oaCollection_oaAppObjectDef_oaTech\n"
"  Paramegers: (oaCollection_oaAppObjectDef_oaTech)\n"
"    Calls: (const oaCollection_oaAppObjectDef_oaTech&)\n"
"    Signature: oaCollection_oaAppObjectDef_oaTech||cref-oaCollection_oaAppObjectDef_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAppObjectDef_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAppObjectDef_oaTech",
    sizeof(PyoaCollection_oaAppObjectDef_oaTechObject),
    0,
    (destructor)oaCollection_oaAppObjectDef_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAppObjectDef_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAppObjectDef_oaTech_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAppObjectDef_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaAppObjectDefCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAppObjectDef_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAppObjectDef_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAppObjectDef_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAppObjectDef_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAppObjectDef_oaTech",
           (PyObject*)(&PyoaCollection_oaAppObjectDef_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAppObjectDef_oaTech\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAppObject_oaDMData
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppObject_oaDMData_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAppObject_oaDMData_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAppObject_oaDMDataObject* self = (PyoaCollection_oaAppObject_oaDMDataObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAppObject_oaDMData)
    {
        PyParamoaCollection_oaAppObject_oaDMData p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAppObject_oaDMData_Convert,&p1)) {
            self->value = (oaAppObjectCollection*)  new oaCollection_oaAppObject_oaDMData(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAppObject_oaDMData, Choices are:\n"
        "    (oaCollection_oaAppObject_oaDMData)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAppObject_oaDMData_tp_dealloc(PyoaCollection_oaAppObject_oaDMDataObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaAppObject_oaDMData*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppObject_oaDMData_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAppObject_oaDMData value;
    int convert_status=PyoaCollection_oaAppObject_oaDMData_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaCollection_oaAppObject_oaDMData::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAppObject_oaDMData_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAppObject_oaDMData v1;
    PyParamoaCollection_oaAppObject_oaDMData v2;
    int convert_status1=PyoaCollection_oaAppObject_oaDMData_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAppObject_oaDMData_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAppObject_oaDMData_Convert(PyObject* ob,PyParamoaCollection_oaAppObject_oaDMData* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAppObject_oaDMData_Check(ob)) {
        result->SetData( (oaCollection_oaAppObject_oaDMData*) ((PyoaCollection_oaAppObject_oaDMDataObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAppObject_oaDMData Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAppObject_oaDMData_FromoaCollection_oaAppObject_oaDMData(oaCollection_oaAppObject_oaDMData* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAppObject_oaDMData_Type.tp_alloc(&PyoaCollection_oaAppObject_oaDMData_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAppObject_oaDMDataObject* self = (PyoaCollection_oaAppObject_oaDMDataObject*)bself;
        self->value = (oaAppObjectCollection*)  data;
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
static char oaCollection_oaAppObject_oaDMData_doc[] = 
"Class: oaCollection_oaAppObject_oaDMData\n"
"  Class type oaCollection_oaAppObject_oaDMData\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaAppObject_oaDMData)\n"
"    Calls: oaCollection_oaAppObject_oaDMData(const oaCollection_oaAppObject_oaDMData& c)\n"
"    Signature: oaCollection_oaAppObject_oaDMData||cref-oaCollection_oaAppObject_oaDMData,\n"
"    Constructor oaCollection_oaAppObject_oaDMData\n"
"  Paramegers: (oaCollection_oaAppObject_oaDMData)\n"
"    Calls: (const oaCollection_oaAppObject_oaDMData&)\n"
"    Signature: oaCollection_oaAppObject_oaDMData||cref-oaCollection_oaAppObject_oaDMData,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAppObject_oaDMData_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAppObject_oaDMData",
    sizeof(PyoaCollection_oaAppObject_oaDMDataObject),
    0,
    (destructor)oaCollection_oaAppObject_oaDMData_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAppObject_oaDMData_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAppObject_oaDMData_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAppObject_oaDMData_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaAppObjectCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAppObject_oaDMData_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAppObject_oaDMData_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAppObject_oaDMData_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAppObject_oaDMData\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAppObject_oaDMData",
           (PyObject*)(&PyoaCollection_oaAppObject_oaDMData_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAppObject_oaDMData\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAppObject_oaDesign
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppObject_oaDesign_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAppObject_oaDesign_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAppObject_oaDesignObject* self = (PyoaCollection_oaAppObject_oaDesignObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAppObject_oaDesign)
    {
        PyParamoaCollection_oaAppObject_oaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAppObject_oaDesign_Convert,&p1)) {
            self->value = (oaAppObjectCollection*)  new oaCollection_oaAppObject_oaDesign(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAppObject_oaDesign, Choices are:\n"
        "    (oaCollection_oaAppObject_oaDesign)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAppObject_oaDesign_tp_dealloc(PyoaCollection_oaAppObject_oaDesignObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaAppObject_oaDesign*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppObject_oaDesign_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAppObject_oaDesign value;
    int convert_status=PyoaCollection_oaAppObject_oaDesign_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaCollection_oaAppObject_oaDesign::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAppObject_oaDesign_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAppObject_oaDesign v1;
    PyParamoaCollection_oaAppObject_oaDesign v2;
    int convert_status1=PyoaCollection_oaAppObject_oaDesign_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAppObject_oaDesign_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAppObject_oaDesign_Convert(PyObject* ob,PyParamoaCollection_oaAppObject_oaDesign* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAppObject_oaDesign_Check(ob)) {
        result->SetData( (oaCollection_oaAppObject_oaDesign*) ((PyoaCollection_oaAppObject_oaDesignObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAppObject_oaDesign Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAppObject_oaDesign_FromoaCollection_oaAppObject_oaDesign(oaCollection_oaAppObject_oaDesign* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAppObject_oaDesign_Type.tp_alloc(&PyoaCollection_oaAppObject_oaDesign_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAppObject_oaDesignObject* self = (PyoaCollection_oaAppObject_oaDesignObject*)bself;
        self->value = (oaAppObjectCollection*)  data;
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
static char oaCollection_oaAppObject_oaDesign_doc[] = 
"Class: oaCollection_oaAppObject_oaDesign\n"
"  Class type oaCollection_oaAppObject_oaDesign\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaAppObject_oaDesign)\n"
"    Calls: oaCollection_oaAppObject_oaDesign(const oaCollection_oaAppObject_oaDesign& c)\n"
"    Signature: oaCollection_oaAppObject_oaDesign||cref-oaCollection_oaAppObject_oaDesign,\n"
"    Constructor oaCollection_oaAppObject_oaDesign\n"
"  Paramegers: (oaCollection_oaAppObject_oaDesign)\n"
"    Calls: (const oaCollection_oaAppObject_oaDesign&)\n"
"    Signature: oaCollection_oaAppObject_oaDesign||cref-oaCollection_oaAppObject_oaDesign,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAppObject_oaDesign_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAppObject_oaDesign",
    sizeof(PyoaCollection_oaAppObject_oaDesignObject),
    0,
    (destructor)oaCollection_oaAppObject_oaDesign_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAppObject_oaDesign_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAppObject_oaDesign_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAppObject_oaDesign_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaAppObjectCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAppObject_oaDesign_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAppObject_oaDesign_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAppObject_oaDesign_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAppObject_oaDesign\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAppObject_oaDesign",
           (PyObject*)(&PyoaCollection_oaAppObject_oaDesign_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAppObject_oaDesign\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAppObject_oaTech
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppObject_oaTech_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAppObject_oaTech_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAppObject_oaTechObject* self = (PyoaCollection_oaAppObject_oaTechObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAppObject_oaTech)
    {
        PyParamoaCollection_oaAppObject_oaTech p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAppObject_oaTech_Convert,&p1)) {
            self->value = (oaAppObjectCollection*)  new oaCollection_oaAppObject_oaTech(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAppObject_oaTech, Choices are:\n"
        "    (oaCollection_oaAppObject_oaTech)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAppObject_oaTech_tp_dealloc(PyoaCollection_oaAppObject_oaTechObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaAppObject_oaTech*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAppObject_oaTech_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAppObject_oaTech value;
    int convert_status=PyoaCollection_oaAppObject_oaTech_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[53];
    sprintf(buffer,"<oaCollection_oaAppObject_oaTech::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAppObject_oaTech_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAppObject_oaTech v1;
    PyParamoaCollection_oaAppObject_oaTech v2;
    int convert_status1=PyoaCollection_oaAppObject_oaTech_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAppObject_oaTech_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAppObject_oaTech_Convert(PyObject* ob,PyParamoaCollection_oaAppObject_oaTech* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAppObject_oaTech_Check(ob)) {
        result->SetData( (oaCollection_oaAppObject_oaTech*) ((PyoaCollection_oaAppObject_oaTechObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAppObject_oaTech Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAppObject_oaTech_FromoaCollection_oaAppObject_oaTech(oaCollection_oaAppObject_oaTech* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAppObject_oaTech_Type.tp_alloc(&PyoaCollection_oaAppObject_oaTech_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAppObject_oaTechObject* self = (PyoaCollection_oaAppObject_oaTechObject*)bself;
        self->value = (oaAppObjectCollection*)  data;
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
static char oaCollection_oaAppObject_oaTech_doc[] = 
"Class: oaCollection_oaAppObject_oaTech\n"
"  Class type oaCollection_oaAppObject_oaTech\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaAppObject_oaTech)\n"
"    Calls: oaCollection_oaAppObject_oaTech(const oaCollection_oaAppObject_oaTech& c)\n"
"    Signature: oaCollection_oaAppObject_oaTech||cref-oaCollection_oaAppObject_oaTech,\n"
"    Constructor oaCollection_oaAppObject_oaTech\n"
"  Paramegers: (oaCollection_oaAppObject_oaTech)\n"
"    Calls: (const oaCollection_oaAppObject_oaTech&)\n"
"    Signature: oaCollection_oaAppObject_oaTech||cref-oaCollection_oaAppObject_oaTech,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAppObject_oaTech_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAppObject_oaTech",
    sizeof(PyoaCollection_oaAppObject_oaTechObject),
    0,
    (destructor)oaCollection_oaAppObject_oaTech_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAppObject_oaTech_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAppObject_oaTech_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAppObject_oaTech_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaAppObjectCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAppObject_oaTech_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAppObject_oaTech_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAppObject_oaTech_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAppObject_oaTech\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAppObject_oaTech",
           (PyObject*)(&PyoaCollection_oaAppObject_oaTech_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAppObject_oaTech\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAreaBoundary_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAreaBoundary_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAreaBoundary_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAreaBoundary_oaBlockObject* self = (PyoaCollection_oaAreaBoundary_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAreaBoundary_oaBlock)
    {
        PyParamoaCollection_oaAreaBoundary_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAreaBoundary_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaAreaBoundary_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAreaBoundary_oaBlock, Choices are:\n"
        "    (oaCollection_oaAreaBoundary_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAreaBoundary_oaBlock_tp_dealloc(PyoaCollection_oaAreaBoundary_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaAreaBoundary_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAreaBoundary_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAreaBoundary_oaBlock value;
    int convert_status=PyoaCollection_oaAreaBoundary_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[57];
    sprintf(buffer,"<oaCollection_oaAreaBoundary_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAreaBoundary_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAreaBoundary_oaBlock v1;
    PyParamoaCollection_oaAreaBoundary_oaBlock v2;
    int convert_status1=PyoaCollection_oaAreaBoundary_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAreaBoundary_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAreaBoundary_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaAreaBoundary_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAreaBoundary_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaAreaBoundary_oaBlock*) ((PyoaCollection_oaAreaBoundary_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAreaBoundary_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAreaBoundary_oaBlock_FromoaCollection_oaAreaBoundary_oaBlock(oaCollection_oaAreaBoundary_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAreaBoundary_oaBlock_Type.tp_alloc(&PyoaCollection_oaAreaBoundary_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAreaBoundary_oaBlockObject* self = (PyoaCollection_oaAreaBoundary_oaBlockObject*)bself;
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
static char oaCollection_oaAreaBoundary_oaBlock_includes_doc[] = 
"Class: oaCollection_oaAreaBoundary_oaBlock, Function: includes\n"
"  Paramegers: (oaAreaBoundary)\n"
"    Calls: oaBoolean includes(const oaAreaBoundary* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaAreaBoundary,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaAreaBoundary_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaAreaBoundary_oaBlock data;
    int convert_status=PyoaCollection_oaAreaBoundary_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaAreaBoundary_oaBlockObject* self=(PyoaCollection_oaAreaBoundary_oaBlockObject*)ob;

    PyParamoaAreaBoundary p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaAreaBoundary_Convert,&p1)) {
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

static char oaCollection_oaAreaBoundary_oaBlock_assign_doc[] = 
"Class: oaCollection_oaAreaBoundary_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaAreaBoundary_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaAreaBoundary_oaBlock data;
  int convert_status=PyoaCollection_oaAreaBoundary_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaAreaBoundary_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaAreaBoundary_oaBlock_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaAreaBoundary_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaAreaBoundary_oaBlock_includes,METH_VARARGS,oaCollection_oaAreaBoundary_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaAreaBoundary_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaAreaBoundary_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaAreaBoundary_oaBlock_doc[] = 
"Class: oaCollection_oaAreaBoundary_oaBlock\n"
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
"  Paramegers: (oaCollection_oaAreaBoundary_oaBlock)\n"
"    Calls: oaCollection_oaAreaBoundary_oaBlock(const oaCollection_oaAreaBoundary_oaBlock& coll)\n"
"    Signature: oaCollection_oaAreaBoundary_oaBlock||cref-oaCollection_oaAreaBoundary_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaAreaBoundary_oaBlock)\n"
"    Calls: (const oaCollection_oaAreaBoundary_oaBlock&)\n"
"    Signature: oaCollection_oaAreaBoundary_oaBlock||cref-oaCollection_oaAreaBoundary_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAreaBoundary_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAreaBoundary_oaBlock",
    sizeof(PyoaCollection_oaAreaBoundary_oaBlockObject),
    0,
    (destructor)oaCollection_oaAreaBoundary_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAreaBoundary_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAreaBoundary_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAreaBoundary_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaAreaBoundary_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAreaBoundary_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAreaBoundary_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAreaBoundary_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAreaBoundary_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAreaBoundary_oaBlock",
           (PyObject*)(&PyoaCollection_oaAreaBoundary_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAreaBoundary_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAssignment_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAssignment_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAssignment_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAssignment_oaBlockObject* self = (PyoaCollection_oaAssignment_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAssignment_oaBlock)
    {
        PyParamoaCollection_oaAssignment_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAssignment_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaAssignment_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAssignment_oaBlock, Choices are:\n"
        "    (oaCollection_oaAssignment_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAssignment_oaBlock_tp_dealloc(PyoaCollection_oaAssignment_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaAssignment_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAssignment_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAssignment_oaBlock value;
    int convert_status=PyoaCollection_oaAssignment_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaCollection_oaAssignment_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAssignment_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAssignment_oaBlock v1;
    PyParamoaCollection_oaAssignment_oaBlock v2;
    int convert_status1=PyoaCollection_oaAssignment_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAssignment_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAssignment_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaAssignment_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAssignment_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaAssignment_oaBlock*) ((PyoaCollection_oaAssignment_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAssignment_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAssignment_oaBlock_FromoaCollection_oaAssignment_oaBlock(oaCollection_oaAssignment_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAssignment_oaBlock_Type.tp_alloc(&PyoaCollection_oaAssignment_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAssignment_oaBlockObject* self = (PyoaCollection_oaAssignment_oaBlockObject*)bself;
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
static char oaCollection_oaAssignment_oaBlock_includes_doc[] = 
"Class: oaCollection_oaAssignment_oaBlock, Function: includes\n"
"  Paramegers: (oaAssignment)\n"
"    Calls: oaBoolean includes(const oaAssignment* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaAssignment,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaAssignment_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaAssignment_oaBlock data;
    int convert_status=PyoaCollection_oaAssignment_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaAssignment_oaBlockObject* self=(PyoaCollection_oaAssignment_oaBlockObject*)ob;

    PyParamoaAssignment p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaAssignment_Convert,&p1)) {
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

static char oaCollection_oaAssignment_oaBlock_assign_doc[] = 
"Class: oaCollection_oaAssignment_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaAssignment_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaAssignment_oaBlock data;
  int convert_status=PyoaCollection_oaAssignment_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaAssignment_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaAssignment_oaBlock_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaAssignment_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaAssignment_oaBlock_includes,METH_VARARGS,oaCollection_oaAssignment_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaAssignment_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaAssignment_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaAssignment_oaBlock_doc[] = 
"Class: oaCollection_oaAssignment_oaBlock\n"
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
"  Paramegers: (oaCollection_oaAssignment_oaBlock)\n"
"    Calls: oaCollection_oaAssignment_oaBlock(const oaCollection_oaAssignment_oaBlock& coll)\n"
"    Signature: oaCollection_oaAssignment_oaBlock||cref-oaCollection_oaAssignment_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaAssignment_oaBlock)\n"
"    Calls: (const oaCollection_oaAssignment_oaBlock&)\n"
"    Signature: oaCollection_oaAssignment_oaBlock||cref-oaCollection_oaAssignment_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAssignment_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAssignment_oaBlock",
    sizeof(PyoaCollection_oaAssignment_oaBlockObject),
    0,
    (destructor)oaCollection_oaAssignment_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAssignment_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAssignment_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAssignment_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaAssignment_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAssignment_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAssignment_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAssignment_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAssignment_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAssignment_oaBlock",
           (PyObject*)(&PyoaCollection_oaAssignment_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAssignment_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaAssignment_oaInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAssignment_oaInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaAssignment_oaInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaAssignment_oaInstObject* self = (PyoaCollection_oaAssignment_oaInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaAssignment_oaInst)
    {
        PyParamoaCollection_oaAssignment_oaInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaAssignment_oaInst_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaAssignment_oaInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaAssignment_oaInst, Choices are:\n"
        "    (oaCollection_oaAssignment_oaInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaAssignment_oaInst_tp_dealloc(PyoaCollection_oaAssignment_oaInstObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaAssignment_oaInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaAssignment_oaInst_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaAssignment_oaInst value;
    int convert_status=PyoaCollection_oaAssignment_oaInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaAssignment_oaInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaAssignment_oaInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaAssignment_oaInst v1;
    PyParamoaCollection_oaAssignment_oaInst v2;
    int convert_status1=PyoaCollection_oaAssignment_oaInst_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaAssignment_oaInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaAssignment_oaInst_Convert(PyObject* ob,PyParamoaCollection_oaAssignment_oaInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaAssignment_oaInst_Check(ob)) {
        result->SetData( (oaCollection_oaAssignment_oaInst*) ((PyoaCollection_oaAssignment_oaInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaAssignment_oaInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaAssignment_oaInst_FromoaCollection_oaAssignment_oaInst(oaCollection_oaAssignment_oaInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaAssignment_oaInst_Type.tp_alloc(&PyoaCollection_oaAssignment_oaInst_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaAssignment_oaInstObject* self = (PyoaCollection_oaAssignment_oaInstObject*)bself;
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
static char oaCollection_oaAssignment_oaInst_includes_doc[] = 
"Class: oaCollection_oaAssignment_oaInst, Function: includes\n"
"  Paramegers: (oaAssignment)\n"
"    Calls: oaBoolean includes(const oaAssignment* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaAssignment,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaAssignment_oaInst_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaAssignment_oaInst data;
    int convert_status=PyoaCollection_oaAssignment_oaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaAssignment_oaInstObject* self=(PyoaCollection_oaAssignment_oaInstObject*)ob;

    PyParamoaAssignment p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaAssignment_Convert,&p1)) {
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

static char oaCollection_oaAssignment_oaInst_assign_doc[] = 
"Class: oaCollection_oaAssignment_oaInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaAssignment_oaInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaAssignment_oaInst data;
  int convert_status=PyoaCollection_oaAssignment_oaInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaAssignment_oaInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaAssignment_oaInst_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaAssignment_oaInst_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaAssignment_oaInst_includes,METH_VARARGS,oaCollection_oaAssignment_oaInst_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaAssignment_oaInst_tp_assign,METH_VARARGS,oaCollection_oaAssignment_oaInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaAssignment_oaInst_doc[] = 
"Class: oaCollection_oaAssignment_oaInst\n"
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
"  Paramegers: (oaCollection_oaAssignment_oaInst)\n"
"    Calls: oaCollection_oaAssignment_oaInst(const oaCollection_oaAssignment_oaInst& coll)\n"
"    Signature: oaCollection_oaAssignment_oaInst||cref-oaCollection_oaAssignment_oaInst,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaAssignment_oaInst)\n"
"    Calls: (const oaCollection_oaAssignment_oaInst&)\n"
"    Signature: oaCollection_oaAssignment_oaInst||cref-oaCollection_oaAssignment_oaInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaAssignment_oaInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaAssignment_oaInst",
    sizeof(PyoaCollection_oaAssignment_oaInstObject),
    0,
    (destructor)oaCollection_oaAssignment_oaInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaAssignment_oaInst_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaAssignment_oaInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaAssignment_oaInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaAssignment_oaInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaAssignment_oaInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaAssignment_oaInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaAssignment_oaInst_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaAssignment_oaInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaAssignment_oaInst",
           (PyObject*)(&PyoaCollection_oaAssignment_oaInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaAssignment_oaInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaBitNet_oaBitNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBitNet_oaBitNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaBitNet_oaBitNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaBitNet_oaBitNetObject* self = (PyoaCollection_oaBitNet_oaBitNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaBitNet_oaBitNet)
    {
        PyParamoaCollection_oaBitNet_oaBitNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaBitNet_oaBitNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaBitNet_oaBitNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaBitNet_oaBitNet, Choices are:\n"
        "    (oaCollection_oaBitNet_oaBitNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaBitNet_oaBitNet_tp_dealloc(PyoaCollection_oaBitNet_oaBitNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaBitNet_oaBitNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBitNet_oaBitNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaBitNet_oaBitNet value;
    int convert_status=PyoaCollection_oaBitNet_oaBitNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaBitNet_oaBitNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaBitNet_oaBitNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaBitNet_oaBitNet v1;
    PyParamoaCollection_oaBitNet_oaBitNet v2;
    int convert_status1=PyoaCollection_oaBitNet_oaBitNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaBitNet_oaBitNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaBitNet_oaBitNet_Convert(PyObject* ob,PyParamoaCollection_oaBitNet_oaBitNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaBitNet_oaBitNet_Check(ob)) {
        result->SetData( (oaCollection_oaBitNet_oaBitNet*) ((PyoaCollection_oaBitNet_oaBitNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaBitNet_oaBitNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaBitNet_oaBitNet_FromoaCollection_oaBitNet_oaBitNet(oaCollection_oaBitNet_oaBitNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaBitNet_oaBitNet_Type.tp_alloc(&PyoaCollection_oaBitNet_oaBitNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaBitNet_oaBitNetObject* self = (PyoaCollection_oaBitNet_oaBitNetObject*)bself;
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
static char oaCollection_oaBitNet_oaBitNet_includes_doc[] = 
"Class: oaCollection_oaBitNet_oaBitNet, Function: includes\n"
"  Paramegers: (oaBitNet)\n"
"    Calls: oaBoolean includes(const oaBitNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaBitNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaBitNet_oaBitNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaBitNet_oaBitNet data;
    int convert_status=PyoaCollection_oaBitNet_oaBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaBitNet_oaBitNetObject* self=(PyoaCollection_oaBitNet_oaBitNetObject*)ob;

    PyParamoaBitNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBitNet_Convert,&p1)) {
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

static char oaCollection_oaBitNet_oaBitNet_assign_doc[] = 
"Class: oaCollection_oaBitNet_oaBitNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaBitNet_oaBitNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaBitNet_oaBitNet data;
  int convert_status=PyoaCollection_oaBitNet_oaBitNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaBitNet_oaBitNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaBitNet_oaBitNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaBitNet_oaBitNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaBitNet_oaBitNet_includes,METH_VARARGS,oaCollection_oaBitNet_oaBitNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaBitNet_oaBitNet_tp_assign,METH_VARARGS,oaCollection_oaBitNet_oaBitNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaBitNet_oaBitNet_doc[] = 
"Class: oaCollection_oaBitNet_oaBitNet\n"
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
"  Paramegers: (oaCollection_oaBitNet_oaBitNet)\n"
"    Calls: oaCollection_oaBitNet_oaBitNet(const oaCollection_oaBitNet_oaBitNet& coll)\n"
"    Signature: oaCollection_oaBitNet_oaBitNet||cref-oaCollection_oaBitNet_oaBitNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaBitNet_oaBitNet)\n"
"    Calls: (const oaCollection_oaBitNet_oaBitNet&)\n"
"    Signature: oaCollection_oaBitNet_oaBitNet||cref-oaCollection_oaBitNet_oaBitNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaBitNet_oaBitNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaBitNet_oaBitNet",
    sizeof(PyoaCollection_oaBitNet_oaBitNetObject),
    0,
    (destructor)oaCollection_oaBitNet_oaBitNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaBitNet_oaBitNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaBitNet_oaBitNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaBitNet_oaBitNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaBitNet_oaBitNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaBitNet_oaBitNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaBitNet_oaBitNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaBitNet_oaBitNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaBitNet_oaBitNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaBitNet_oaBitNet",
           (PyObject*)(&PyoaCollection_oaBitNet_oaBitNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaBitNet_oaBitNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaBitNet_oaNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBitNet_oaNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaBitNet_oaNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaBitNet_oaNetObject* self = (PyoaCollection_oaBitNet_oaNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaBitNet_oaNet)
    {
        PyParamoaCollection_oaBitNet_oaNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaBitNet_oaNet_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaBitNet_oaNet(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaBitNet_oaNet, Choices are:\n"
        "    (oaCollection_oaBitNet_oaNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaBitNet_oaNet_tp_dealloc(PyoaCollection_oaBitNet_oaNetObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaBitNet_oaNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBitNet_oaNet_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaBitNet_oaNet value;
    int convert_status=PyoaCollection_oaBitNet_oaNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaCollection_oaBitNet_oaNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaBitNet_oaNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaBitNet_oaNet v1;
    PyParamoaCollection_oaBitNet_oaNet v2;
    int convert_status1=PyoaCollection_oaBitNet_oaNet_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaBitNet_oaNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaBitNet_oaNet_Convert(PyObject* ob,PyParamoaCollection_oaBitNet_oaNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaBitNet_oaNet_Check(ob)) {
        result->SetData( (oaCollection_oaBitNet_oaNet*) ((PyoaCollection_oaBitNet_oaNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaBitNet_oaNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaBitNet_oaNet_FromoaCollection_oaBitNet_oaNet(oaCollection_oaBitNet_oaNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaBitNet_oaNet_Type.tp_alloc(&PyoaCollection_oaBitNet_oaNet_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaBitNet_oaNetObject* self = (PyoaCollection_oaBitNet_oaNetObject*)bself;
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
static char oaCollection_oaBitNet_oaNet_includes_doc[] = 
"Class: oaCollection_oaBitNet_oaNet, Function: includes\n"
"  Paramegers: (oaBitNet)\n"
"    Calls: oaBoolean includes(const oaBitNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaBitNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaBitNet_oaNet_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaBitNet_oaNet data;
    int convert_status=PyoaCollection_oaBitNet_oaNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaBitNet_oaNetObject* self=(PyoaCollection_oaBitNet_oaNetObject*)ob;

    PyParamoaBitNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBitNet_Convert,&p1)) {
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

static char oaCollection_oaBitNet_oaNet_assign_doc[] = 
"Class: oaCollection_oaBitNet_oaNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaBitNet_oaNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaBitNet_oaNet data;
  int convert_status=PyoaCollection_oaBitNet_oaNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaBitNet_oaNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaBitNet_oaNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaBitNet_oaNet_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaBitNet_oaNet_includes,METH_VARARGS,oaCollection_oaBitNet_oaNet_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaBitNet_oaNet_tp_assign,METH_VARARGS,oaCollection_oaBitNet_oaNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaBitNet_oaNet_doc[] = 
"Class: oaCollection_oaBitNet_oaNet\n"
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
"  Paramegers: (oaCollection_oaBitNet_oaNet)\n"
"    Calls: oaCollection_oaBitNet_oaNet(const oaCollection_oaBitNet_oaNet& coll)\n"
"    Signature: oaCollection_oaBitNet_oaNet||cref-oaCollection_oaBitNet_oaNet,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaBitNet_oaNet)\n"
"    Calls: (const oaCollection_oaBitNet_oaNet&)\n"
"    Signature: oaCollection_oaBitNet_oaNet||cref-oaCollection_oaBitNet_oaNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaBitNet_oaNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaBitNet_oaNet",
    sizeof(PyoaCollection_oaBitNet_oaNetObject),
    0,
    (destructor)oaCollection_oaBitNet_oaNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaBitNet_oaNet_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaBitNet_oaNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaBitNet_oaNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaBitNet_oaNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaBitNet_oaNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaBitNet_oaNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaBitNet_oaNet_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaBitNet_oaNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaBitNet_oaNet",
           (PyObject*)(&PyoaCollection_oaBitNet_oaNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaBitNet_oaNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaBitTerm_oaBitTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBitTerm_oaBitTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaBitTerm_oaBitTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaBitTerm_oaBitTermObject* self = (PyoaCollection_oaBitTerm_oaBitTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaBitTerm_oaBitTerm)
    {
        PyParamoaCollection_oaBitTerm_oaBitTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaBitTerm_oaBitTerm_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaBitTerm_oaBitTerm(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaBitTerm_oaBitTerm, Choices are:\n"
        "    (oaCollection_oaBitTerm_oaBitTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaBitTerm_oaBitTerm_tp_dealloc(PyoaCollection_oaBitTerm_oaBitTermObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaBitTerm_oaBitTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBitTerm_oaBitTerm_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaBitTerm_oaBitTerm value;
    int convert_status=PyoaCollection_oaBitTerm_oaBitTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaBitTerm_oaBitTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaBitTerm_oaBitTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaBitTerm_oaBitTerm v1;
    PyParamoaCollection_oaBitTerm_oaBitTerm v2;
    int convert_status1=PyoaCollection_oaBitTerm_oaBitTerm_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaBitTerm_oaBitTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaBitTerm_oaBitTerm_Convert(PyObject* ob,PyParamoaCollection_oaBitTerm_oaBitTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaBitTerm_oaBitTerm_Check(ob)) {
        result->SetData( (oaCollection_oaBitTerm_oaBitTerm*) ((PyoaCollection_oaBitTerm_oaBitTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaBitTerm_oaBitTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaBitTerm_oaBitTerm_FromoaCollection_oaBitTerm_oaBitTerm(oaCollection_oaBitTerm_oaBitTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaBitTerm_oaBitTerm_Type.tp_alloc(&PyoaCollection_oaBitTerm_oaBitTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaBitTerm_oaBitTermObject* self = (PyoaCollection_oaBitTerm_oaBitTermObject*)bself;
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
static char oaCollection_oaBitTerm_oaBitTerm_includes_doc[] = 
"Class: oaCollection_oaBitTerm_oaBitTerm, Function: includes\n"
"  Paramegers: (oaBitTerm)\n"
"    Calls: oaBoolean includes(const oaBitTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaBitTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaBitTerm_oaBitTerm_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaBitTerm_oaBitTerm data;
    int convert_status=PyoaCollection_oaBitTerm_oaBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaBitTerm_oaBitTermObject* self=(PyoaCollection_oaBitTerm_oaBitTermObject*)ob;

    PyParamoaBitTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBitTerm_Convert,&p1)) {
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

static char oaCollection_oaBitTerm_oaBitTerm_assign_doc[] = 
"Class: oaCollection_oaBitTerm_oaBitTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaBitTerm_oaBitTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaBitTerm_oaBitTerm data;
  int convert_status=PyoaCollection_oaBitTerm_oaBitTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaBitTerm_oaBitTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaBitTerm_oaBitTerm_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaBitTerm_oaBitTerm_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaBitTerm_oaBitTerm_includes,METH_VARARGS,oaCollection_oaBitTerm_oaBitTerm_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaBitTerm_oaBitTerm_tp_assign,METH_VARARGS,oaCollection_oaBitTerm_oaBitTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaBitTerm_oaBitTerm_doc[] = 
"Class: oaCollection_oaBitTerm_oaBitTerm\n"
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
"  Paramegers: (oaCollection_oaBitTerm_oaBitTerm)\n"
"    Calls: oaCollection_oaBitTerm_oaBitTerm(const oaCollection_oaBitTerm_oaBitTerm& coll)\n"
"    Signature: oaCollection_oaBitTerm_oaBitTerm||cref-oaCollection_oaBitTerm_oaBitTerm,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaBitTerm_oaBitTerm)\n"
"    Calls: (const oaCollection_oaBitTerm_oaBitTerm&)\n"
"    Signature: oaCollection_oaBitTerm_oaBitTerm||cref-oaCollection_oaBitTerm_oaBitTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaBitTerm_oaBitTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaBitTerm_oaBitTerm",
    sizeof(PyoaCollection_oaBitTerm_oaBitTermObject),
    0,
    (destructor)oaCollection_oaBitTerm_oaBitTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaBitTerm_oaBitTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaBitTerm_oaBitTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaBitTerm_oaBitTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaBitTerm_oaBitTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaBitTerm_oaBitTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaBitTerm_oaBitTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaBitTerm_oaBitTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaBitTerm_oaBitTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaBitTerm_oaBitTerm",
           (PyObject*)(&PyoaCollection_oaBitTerm_oaBitTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaBitTerm_oaBitTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaBlockObject_oaMarker
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBlockObject_oaMarker_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaBlockObject_oaMarker_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaBlockObject_oaMarkerObject* self = (PyoaCollection_oaBlockObject_oaMarkerObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaBlockObject_oaMarker)
    {
        PyParamoaCollection_oaBlockObject_oaMarker p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaBlockObject_oaMarker_Convert,&p1)) {
            self->value =  new oaCollection_oaBlockObject_oaMarker(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaBlockObject_oaMarker, Choices are:\n"
        "    (oaCollection_oaBlockObject_oaMarker)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaBlockObject_oaMarker_tp_dealloc(PyoaCollection_oaBlockObject_oaMarkerObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBlockObject_oaMarker_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaBlockObject_oaMarker value;
    int convert_status=PyoaCollection_oaBlockObject_oaMarker_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[57];
    sprintf(buffer,"<oaCollection_oaBlockObject_oaMarker::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaBlockObject_oaMarker_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaBlockObject_oaMarker v1;
    PyParamoaCollection_oaBlockObject_oaMarker v2;
    int convert_status1=PyoaCollection_oaBlockObject_oaMarker_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaBlockObject_oaMarker_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaBlockObject_oaMarker_Convert(PyObject* ob,PyParamoaCollection_oaBlockObject_oaMarker* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaBlockObject_oaMarker_Check(ob)) {
        result->SetData(  ((PyoaCollection_oaBlockObject_oaMarkerObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaBlockObject_oaMarker Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaBlockObject_oaMarker_FromoaCollection_oaBlockObject_oaMarker(oaCollection_oaBlockObject_oaMarker* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaBlockObject_oaMarker_Type.tp_alloc(&PyoaCollection_oaBlockObject_oaMarker_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaBlockObject_oaMarkerObject* self = (PyoaCollection_oaBlockObject_oaMarkerObject*)bself;
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
static char oaCollection_oaBlockObject_oaMarker_getCount_doc[] = 
"Class: oaCollection_oaBlockObject_oaMarker, Function: getCount\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCount() const\n"
"    Signature: getCount|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    Function getCount\n"
;

static PyObject*
oaCollection_oaBlockObject_oaMarker_getCount(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaBlockObject_oaMarker data;
    int convert_status=PyoaCollection_oaBlockObject_oaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaBlockObject_oaMarkerObject* self=(PyoaCollection_oaBlockObject_oaMarkerObject*)ob;

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
static char oaCollection_oaBlockObject_oaMarker_includes_doc[] = 
"Class: oaCollection_oaBlockObject_oaMarker, Function: includes\n"
"  Paramegers: (oaBlockObject)\n"
"    Calls: oaBoolean includes(const oaBlockObject* object) const\n"
"    Signature: includes|simple-oaBoolean|cptr-oaBlockObject,\n"
"    Function includes\n"
;

static PyObject*
oaCollection_oaBlockObject_oaMarker_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaBlockObject_oaMarker data;
    int convert_status=PyoaCollection_oaBlockObject_oaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaBlockObject_oaMarkerObject* self=(PyoaCollection_oaBlockObject_oaMarkerObject*)ob;

    PyParamoaBlockObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBlockObject_Convert,&p1)) {
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
static char oaCollection_oaBlockObject_oaMarker_isEmpty_doc[] = 
"Class: oaCollection_oaBlockObject_oaMarker, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty() const\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    Function isEmpty\n"
;

static PyObject*
oaCollection_oaBlockObject_oaMarker_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaBlockObject_oaMarker data;
    int convert_status=PyoaCollection_oaBlockObject_oaMarker_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaBlockObject_oaMarkerObject* self=(PyoaCollection_oaBlockObject_oaMarkerObject*)ob;

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

static char oaCollection_oaBlockObject_oaMarker_assign_doc[] = 
"Class: oaCollection_oaBlockObject_oaMarker, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaBlockObject_oaMarker_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaBlockObject_oaMarker data;
  int convert_status=PyoaCollection_oaBlockObject_oaMarker_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaBlockObject_oaMarker p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaBlockObject_oaMarker_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaBlockObject_oaMarker_methodlist[] = {
    {"getCount",(PyCFunction)oaCollection_oaBlockObject_oaMarker_getCount,METH_VARARGS,oaCollection_oaBlockObject_oaMarker_getCount_doc},
    {"includes",(PyCFunction)oaCollection_oaBlockObject_oaMarker_includes,METH_VARARGS,oaCollection_oaBlockObject_oaMarker_includes_doc},
    {"isEmpty",(PyCFunction)oaCollection_oaBlockObject_oaMarker_isEmpty,METH_VARARGS,oaCollection_oaBlockObject_oaMarker_isEmpty_doc},
    {"assign",(PyCFunction)oaCollection_oaBlockObject_oaMarker_tp_assign,METH_VARARGS,oaCollection_oaBlockObject_oaMarker_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaBlockObject_oaMarker_doc[] = 
"Class: oaCollection_oaBlockObject_oaMarker\n"
"  Class type oaCollection_oaBlockObject_oaMarker\n"
"Constructors:\n"
"  Paramegers: (oaCollection_oaBlockObject_oaMarker)\n"
"    Calls: oaCollection_oaBlockObject_oaMarker(const oaCollection_oaBlockObject_oaMarker& c)\n"
"    Signature: oaCollection_oaBlockObject_oaMarker||cref-oaCollection_oaBlockObject_oaMarker,\n"
"    Constructor oaCollection_oaBlockObject_oaMarker\n"
"  Paramegers: (oaCollection_oaBlockObject_oaMarker)\n"
"    Calls: (const oaCollection_oaBlockObject_oaMarker&)\n"
"    Signature: oaCollection_oaBlockObject_oaMarker||cref-oaCollection_oaBlockObject_oaMarker,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaBlockObject_oaMarker_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaBlockObject_oaMarker",
    sizeof(PyoaCollection_oaBlockObject_oaMarkerObject),
    0,
    (destructor)oaCollection_oaBlockObject_oaMarker_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaBlockObject_oaMarker_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaBlockObject_oaMarker_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaBlockObject_oaMarker_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaBlockObject_oaMarker_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaBlockObject_oaMarker_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaBlockObject_oaMarker_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaBlockObject_oaMarker_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaBlockObject_oaMarker\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaBlockObject_oaMarker",
           (PyObject*)(&PyoaCollection_oaBlockObject_oaMarker_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaBlockObject_oaMarker\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaBlockage_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBlockage_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaBlockage_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaBlockage_oaBlockObject* self = (PyoaCollection_oaBlockage_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaBlockage_oaBlock)
    {
        PyParamoaCollection_oaBlockage_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaBlockage_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaBlockage_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaBlockage_oaBlock, Choices are:\n"
        "    (oaCollection_oaBlockage_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaBlockage_oaBlock_tp_dealloc(PyoaCollection_oaBlockage_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaBlockage_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBlockage_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaBlockage_oaBlock value;
    int convert_status=PyoaCollection_oaBlockage_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[53];
    sprintf(buffer,"<oaCollection_oaBlockage_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaBlockage_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaBlockage_oaBlock v1;
    PyParamoaCollection_oaBlockage_oaBlock v2;
    int convert_status1=PyoaCollection_oaBlockage_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaBlockage_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaBlockage_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaBlockage_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaBlockage_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaBlockage_oaBlock*) ((PyoaCollection_oaBlockage_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaBlockage_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaBlockage_oaBlock_FromoaCollection_oaBlockage_oaBlock(oaCollection_oaBlockage_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaBlockage_oaBlock_Type.tp_alloc(&PyoaCollection_oaBlockage_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaBlockage_oaBlockObject* self = (PyoaCollection_oaBlockage_oaBlockObject*)bself;
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
static char oaCollection_oaBlockage_oaBlock_includes_doc[] = 
"Class: oaCollection_oaBlockage_oaBlock, Function: includes\n"
"  Paramegers: (oaBlockage)\n"
"    Calls: oaBoolean includes(const oaBlockage* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaBlockage,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaBlockage_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaBlockage_oaBlock data;
    int convert_status=PyoaCollection_oaBlockage_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaBlockage_oaBlockObject* self=(PyoaCollection_oaBlockage_oaBlockObject*)ob;

    PyParamoaBlockage p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBlockage_Convert,&p1)) {
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

static char oaCollection_oaBlockage_oaBlock_assign_doc[] = 
"Class: oaCollection_oaBlockage_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaBlockage_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaBlockage_oaBlock data;
  int convert_status=PyoaCollection_oaBlockage_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaBlockage_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaBlockage_oaBlock_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaBlockage_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaBlockage_oaBlock_includes,METH_VARARGS,oaCollection_oaBlockage_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaBlockage_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaBlockage_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaBlockage_oaBlock_doc[] = 
"Class: oaCollection_oaBlockage_oaBlock\n"
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
"  Paramegers: (oaCollection_oaBlockage_oaBlock)\n"
"    Calls: oaCollection_oaBlockage_oaBlock(const oaCollection_oaBlockage_oaBlock& coll)\n"
"    Signature: oaCollection_oaBlockage_oaBlock||cref-oaCollection_oaBlockage_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaBlockage_oaBlock)\n"
"    Calls: (const oaCollection_oaBlockage_oaBlock&)\n"
"    Signature: oaCollection_oaBlockage_oaBlock||cref-oaCollection_oaBlockage_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaBlockage_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaBlockage_oaBlock",
    sizeof(PyoaCollection_oaBlockage_oaBlockObject),
    0,
    (destructor)oaCollection_oaBlockage_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaBlockage_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaBlockage_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaBlockage_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaBlockage_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaBlockage_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaBlockage_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaBlockage_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaBlockage_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaBlockage_oaBlock",
           (PyObject*)(&PyoaCollection_oaBlockage_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaBlockage_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaBlockage_oaCluster
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBlockage_oaCluster_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaBlockage_oaCluster_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaBlockage_oaClusterObject* self = (PyoaCollection_oaBlockage_oaClusterObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaBlockage_oaCluster)
    {
        PyParamoaCollection_oaBlockage_oaCluster p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaBlockage_oaCluster_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaBlockage_oaCluster(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaBlockage_oaCluster, Choices are:\n"
        "    (oaCollection_oaBlockage_oaCluster)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaBlockage_oaCluster_tp_dealloc(PyoaCollection_oaBlockage_oaClusterObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaBlockage_oaCluster*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBlockage_oaCluster_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaBlockage_oaCluster value;
    int convert_status=PyoaCollection_oaBlockage_oaCluster_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaCollection_oaBlockage_oaCluster::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaBlockage_oaCluster_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaBlockage_oaCluster v1;
    PyParamoaCollection_oaBlockage_oaCluster v2;
    int convert_status1=PyoaCollection_oaBlockage_oaCluster_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaBlockage_oaCluster_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaBlockage_oaCluster_Convert(PyObject* ob,PyParamoaCollection_oaBlockage_oaCluster* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaBlockage_oaCluster_Check(ob)) {
        result->SetData( (oaCollection_oaBlockage_oaCluster*) ((PyoaCollection_oaBlockage_oaClusterObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaBlockage_oaCluster Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaBlockage_oaCluster_FromoaCollection_oaBlockage_oaCluster(oaCollection_oaBlockage_oaCluster* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaBlockage_oaCluster_Type.tp_alloc(&PyoaCollection_oaBlockage_oaCluster_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaBlockage_oaClusterObject* self = (PyoaCollection_oaBlockage_oaClusterObject*)bself;
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
static char oaCollection_oaBlockage_oaCluster_includes_doc[] = 
"Class: oaCollection_oaBlockage_oaCluster, Function: includes\n"
"  Paramegers: (oaBlockage)\n"
"    Calls: oaBoolean includes(const oaBlockage* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaBlockage,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaBlockage_oaCluster_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaBlockage_oaCluster data;
    int convert_status=PyoaCollection_oaBlockage_oaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaBlockage_oaClusterObject* self=(PyoaCollection_oaBlockage_oaClusterObject*)ob;

    PyParamoaBlockage p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBlockage_Convert,&p1)) {
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

static char oaCollection_oaBlockage_oaCluster_assign_doc[] = 
"Class: oaCollection_oaBlockage_oaCluster, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaBlockage_oaCluster_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaBlockage_oaCluster data;
  int convert_status=PyoaCollection_oaBlockage_oaCluster_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaBlockage_oaCluster p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaBlockage_oaCluster_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaBlockage_oaCluster_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaBlockage_oaCluster_includes,METH_VARARGS,oaCollection_oaBlockage_oaCluster_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaBlockage_oaCluster_tp_assign,METH_VARARGS,oaCollection_oaBlockage_oaCluster_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaBlockage_oaCluster_doc[] = 
"Class: oaCollection_oaBlockage_oaCluster\n"
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
"  Paramegers: (oaCollection_oaBlockage_oaCluster)\n"
"    Calls: oaCollection_oaBlockage_oaCluster(const oaCollection_oaBlockage_oaCluster& coll)\n"
"    Signature: oaCollection_oaBlockage_oaCluster||cref-oaCollection_oaBlockage_oaCluster,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaBlockage_oaCluster)\n"
"    Calls: (const oaCollection_oaBlockage_oaCluster&)\n"
"    Signature: oaCollection_oaBlockage_oaCluster||cref-oaCollection_oaBlockage_oaCluster,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaBlockage_oaCluster_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaBlockage_oaCluster",
    sizeof(PyoaCollection_oaBlockage_oaClusterObject),
    0,
    (destructor)oaCollection_oaBlockage_oaCluster_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaBlockage_oaCluster_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaBlockage_oaCluster_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaBlockage_oaCluster_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaBlockage_oaCluster_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaBlockage_oaCluster_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaBlockage_oaCluster_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaBlockage_oaCluster_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaBlockage_oaCluster\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaBlockage_oaCluster",
           (PyObject*)(&PyoaCollection_oaBlockage_oaCluster_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaBlockage_oaCluster\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaBlockage_oaInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBlockage_oaInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaBlockage_oaInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaBlockage_oaInstObject* self = (PyoaCollection_oaBlockage_oaInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaBlockage_oaInst)
    {
        PyParamoaCollection_oaBlockage_oaInst p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaBlockage_oaInst_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaBlockage_oaInst(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaBlockage_oaInst, Choices are:\n"
        "    (oaCollection_oaBlockage_oaInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaBlockage_oaInst_tp_dealloc(PyoaCollection_oaBlockage_oaInstObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaBlockage_oaInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBlockage_oaInst_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaBlockage_oaInst value;
    int convert_status=PyoaCollection_oaBlockage_oaInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaBlockage_oaInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaBlockage_oaInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaBlockage_oaInst v1;
    PyParamoaCollection_oaBlockage_oaInst v2;
    int convert_status1=PyoaCollection_oaBlockage_oaInst_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaBlockage_oaInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaBlockage_oaInst_Convert(PyObject* ob,PyParamoaCollection_oaBlockage_oaInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaBlockage_oaInst_Check(ob)) {
        result->SetData( (oaCollection_oaBlockage_oaInst*) ((PyoaCollection_oaBlockage_oaInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaBlockage_oaInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaBlockage_oaInst_FromoaCollection_oaBlockage_oaInst(oaCollection_oaBlockage_oaInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaBlockage_oaInst_Type.tp_alloc(&PyoaCollection_oaBlockage_oaInst_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaBlockage_oaInstObject* self = (PyoaCollection_oaBlockage_oaInstObject*)bself;
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
static char oaCollection_oaBlockage_oaInst_includes_doc[] = 
"Class: oaCollection_oaBlockage_oaInst, Function: includes\n"
"  Paramegers: (oaBlockage)\n"
"    Calls: oaBoolean includes(const oaBlockage* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaBlockage,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaBlockage_oaInst_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaBlockage_oaInst data;
    int convert_status=PyoaCollection_oaBlockage_oaInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaBlockage_oaInstObject* self=(PyoaCollection_oaBlockage_oaInstObject*)ob;

    PyParamoaBlockage p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBlockage_Convert,&p1)) {
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

static char oaCollection_oaBlockage_oaInst_assign_doc[] = 
"Class: oaCollection_oaBlockage_oaInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaBlockage_oaInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaBlockage_oaInst data;
  int convert_status=PyoaCollection_oaBlockage_oaInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaBlockage_oaInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaBlockage_oaInst_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaBlockage_oaInst_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaBlockage_oaInst_includes,METH_VARARGS,oaCollection_oaBlockage_oaInst_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaBlockage_oaInst_tp_assign,METH_VARARGS,oaCollection_oaBlockage_oaInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaBlockage_oaInst_doc[] = 
"Class: oaCollection_oaBlockage_oaInst\n"
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
"  Paramegers: (oaCollection_oaBlockage_oaInst)\n"
"    Calls: oaCollection_oaBlockage_oaInst(const oaCollection_oaBlockage_oaInst& coll)\n"
"    Signature: oaCollection_oaBlockage_oaInst||cref-oaCollection_oaBlockage_oaInst,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaBlockage_oaInst)\n"
"    Calls: (const oaCollection_oaBlockage_oaInst&)\n"
"    Signature: oaCollection_oaBlockage_oaInst||cref-oaCollection_oaBlockage_oaInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaBlockage_oaInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaBlockage_oaInst",
    sizeof(PyoaCollection_oaBlockage_oaInstObject),
    0,
    (destructor)oaCollection_oaBlockage_oaInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaBlockage_oaInst_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaBlockage_oaInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaBlockage_oaInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaBlockage_oaInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaBlockage_oaInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaBlockage_oaInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaBlockage_oaInst_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaBlockage_oaInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaBlockage_oaInst",
           (PyObject*)(&PyoaCollection_oaBlockage_oaInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaBlockage_oaInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaBlockage_oaLayerHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBlockage_oaLayerHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaBlockage_oaLayerHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaBlockage_oaLayerHeaderObject* self = (PyoaCollection_oaBlockage_oaLayerHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaBlockage_oaLayerHeader)
    {
        PyParamoaCollection_oaBlockage_oaLayerHeader p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaBlockage_oaLayerHeader_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaBlockage_oaLayerHeader(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaBlockage_oaLayerHeader, Choices are:\n"
        "    (oaCollection_oaBlockage_oaLayerHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaBlockage_oaLayerHeader_tp_dealloc(PyoaCollection_oaBlockage_oaLayerHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaBlockage_oaLayerHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBlockage_oaLayerHeader_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaBlockage_oaLayerHeader value;
    int convert_status=PyoaCollection_oaBlockage_oaLayerHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[59];
    sprintf(buffer,"<oaCollection_oaBlockage_oaLayerHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaBlockage_oaLayerHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaBlockage_oaLayerHeader v1;
    PyParamoaCollection_oaBlockage_oaLayerHeader v2;
    int convert_status1=PyoaCollection_oaBlockage_oaLayerHeader_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaBlockage_oaLayerHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaBlockage_oaLayerHeader_Convert(PyObject* ob,PyParamoaCollection_oaBlockage_oaLayerHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaBlockage_oaLayerHeader_Check(ob)) {
        result->SetData( (oaCollection_oaBlockage_oaLayerHeader*) ((PyoaCollection_oaBlockage_oaLayerHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaBlockage_oaLayerHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaBlockage_oaLayerHeader_FromoaCollection_oaBlockage_oaLayerHeader(oaCollection_oaBlockage_oaLayerHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaBlockage_oaLayerHeader_Type.tp_alloc(&PyoaCollection_oaBlockage_oaLayerHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaBlockage_oaLayerHeaderObject* self = (PyoaCollection_oaBlockage_oaLayerHeaderObject*)bself;
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
static char oaCollection_oaBlockage_oaLayerHeader_includes_doc[] = 
"Class: oaCollection_oaBlockage_oaLayerHeader, Function: includes\n"
"  Paramegers: (oaBlockage)\n"
"    Calls: oaBoolean includes(const oaBlockage* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaBlockage,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaBlockage_oaLayerHeader_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaBlockage_oaLayerHeader data;
    int convert_status=PyoaCollection_oaBlockage_oaLayerHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaBlockage_oaLayerHeaderObject* self=(PyoaCollection_oaBlockage_oaLayerHeaderObject*)ob;

    PyParamoaBlockage p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBlockage_Convert,&p1)) {
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

static char oaCollection_oaBlockage_oaLayerHeader_assign_doc[] = 
"Class: oaCollection_oaBlockage_oaLayerHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaBlockage_oaLayerHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaBlockage_oaLayerHeader data;
  int convert_status=PyoaCollection_oaBlockage_oaLayerHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaBlockage_oaLayerHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaBlockage_oaLayerHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaBlockage_oaLayerHeader_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaBlockage_oaLayerHeader_includes,METH_VARARGS,oaCollection_oaBlockage_oaLayerHeader_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaBlockage_oaLayerHeader_tp_assign,METH_VARARGS,oaCollection_oaBlockage_oaLayerHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaBlockage_oaLayerHeader_doc[] = 
"Class: oaCollection_oaBlockage_oaLayerHeader\n"
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
"  Paramegers: (oaCollection_oaBlockage_oaLayerHeader)\n"
"    Calls: oaCollection_oaBlockage_oaLayerHeader(const oaCollection_oaBlockage_oaLayerHeader& coll)\n"
"    Signature: oaCollection_oaBlockage_oaLayerHeader||cref-oaCollection_oaBlockage_oaLayerHeader,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaBlockage_oaLayerHeader)\n"
"    Calls: (const oaCollection_oaBlockage_oaLayerHeader&)\n"
"    Signature: oaCollection_oaBlockage_oaLayerHeader||cref-oaCollection_oaBlockage_oaLayerHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaBlockage_oaLayerHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaBlockage_oaLayerHeader",
    sizeof(PyoaCollection_oaBlockage_oaLayerHeaderObject),
    0,
    (destructor)oaCollection_oaBlockage_oaLayerHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaBlockage_oaLayerHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaBlockage_oaLayerHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaBlockage_oaLayerHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaBlockage_oaLayerHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaBlockage_oaLayerHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaBlockage_oaLayerHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaBlockage_oaLayerHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaBlockage_oaLayerHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaBlockage_oaLayerHeader",
           (PyObject*)(&PyoaCollection_oaBlockage_oaLayerHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaBlockage_oaLayerHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaBlockage_oaPRBoundary
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBlockage_oaPRBoundary_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaBlockage_oaPRBoundary_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaBlockage_oaPRBoundaryObject* self = (PyoaCollection_oaBlockage_oaPRBoundaryObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaBlockage_oaPRBoundary)
    {
        PyParamoaCollection_oaBlockage_oaPRBoundary p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaBlockage_oaPRBoundary_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaBlockage_oaPRBoundary(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaBlockage_oaPRBoundary, Choices are:\n"
        "    (oaCollection_oaBlockage_oaPRBoundary)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaBlockage_oaPRBoundary_tp_dealloc(PyoaCollection_oaBlockage_oaPRBoundaryObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaBlockage_oaPRBoundary*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBlockage_oaPRBoundary_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaBlockage_oaPRBoundary value;
    int convert_status=PyoaCollection_oaBlockage_oaPRBoundary_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[58];
    sprintf(buffer,"<oaCollection_oaBlockage_oaPRBoundary::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaBlockage_oaPRBoundary_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaBlockage_oaPRBoundary v1;
    PyParamoaCollection_oaBlockage_oaPRBoundary v2;
    int convert_status1=PyoaCollection_oaBlockage_oaPRBoundary_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaBlockage_oaPRBoundary_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaBlockage_oaPRBoundary_Convert(PyObject* ob,PyParamoaCollection_oaBlockage_oaPRBoundary* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaBlockage_oaPRBoundary_Check(ob)) {
        result->SetData( (oaCollection_oaBlockage_oaPRBoundary*) ((PyoaCollection_oaBlockage_oaPRBoundaryObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaBlockage_oaPRBoundary Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaBlockage_oaPRBoundary_FromoaCollection_oaBlockage_oaPRBoundary(oaCollection_oaBlockage_oaPRBoundary* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaBlockage_oaPRBoundary_Type.tp_alloc(&PyoaCollection_oaBlockage_oaPRBoundary_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaBlockage_oaPRBoundaryObject* self = (PyoaCollection_oaBlockage_oaPRBoundaryObject*)bself;
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
static char oaCollection_oaBlockage_oaPRBoundary_includes_doc[] = 
"Class: oaCollection_oaBlockage_oaPRBoundary, Function: includes\n"
"  Paramegers: (oaBlockage)\n"
"    Calls: oaBoolean includes(const oaBlockage* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaBlockage,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaBlockage_oaPRBoundary_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaBlockage_oaPRBoundary data;
    int convert_status=PyoaCollection_oaBlockage_oaPRBoundary_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaBlockage_oaPRBoundaryObject* self=(PyoaCollection_oaBlockage_oaPRBoundaryObject*)ob;

    PyParamoaBlockage p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBlockage_Convert,&p1)) {
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

static char oaCollection_oaBlockage_oaPRBoundary_assign_doc[] = 
"Class: oaCollection_oaBlockage_oaPRBoundary, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaBlockage_oaPRBoundary_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaBlockage_oaPRBoundary data;
  int convert_status=PyoaCollection_oaBlockage_oaPRBoundary_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaBlockage_oaPRBoundary p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaBlockage_oaPRBoundary_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaBlockage_oaPRBoundary_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaBlockage_oaPRBoundary_includes,METH_VARARGS,oaCollection_oaBlockage_oaPRBoundary_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaBlockage_oaPRBoundary_tp_assign,METH_VARARGS,oaCollection_oaBlockage_oaPRBoundary_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaBlockage_oaPRBoundary_doc[] = 
"Class: oaCollection_oaBlockage_oaPRBoundary\n"
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
"  Paramegers: (oaCollection_oaBlockage_oaPRBoundary)\n"
"    Calls: oaCollection_oaBlockage_oaPRBoundary(const oaCollection_oaBlockage_oaPRBoundary& coll)\n"
"    Signature: oaCollection_oaBlockage_oaPRBoundary||cref-oaCollection_oaBlockage_oaPRBoundary,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaBlockage_oaPRBoundary)\n"
"    Calls: (const oaCollection_oaBlockage_oaPRBoundary&)\n"
"    Signature: oaCollection_oaBlockage_oaPRBoundary||cref-oaCollection_oaBlockage_oaPRBoundary,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaBlockage_oaPRBoundary_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaBlockage_oaPRBoundary",
    sizeof(PyoaCollection_oaBlockage_oaPRBoundaryObject),
    0,
    (destructor)oaCollection_oaBlockage_oaPRBoundary_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaBlockage_oaPRBoundary_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaBlockage_oaPRBoundary_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaBlockage_oaPRBoundary_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaBlockage_oaPRBoundary_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaBlockage_oaPRBoundary_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaBlockage_oaPRBoundary_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaBlockage_oaPRBoundary_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaBlockage_oaPRBoundary\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaBlockage_oaPRBoundary",
           (PyObject*)(&PyoaCollection_oaBlockage_oaPRBoundary_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaBlockage_oaPRBoundary\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaBusNetBit_oaBusNetDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBusNetBit_oaBusNetDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaBusNetBit_oaBusNetDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaBusNetBit_oaBusNetDefObject* self = (PyoaCollection_oaBusNetBit_oaBusNetDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaBusNetBit_oaBusNetDef)
    {
        PyParamoaCollection_oaBusNetBit_oaBusNetDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaBusNetBit_oaBusNetDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaBusNetBit_oaBusNetDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaBusNetBit_oaBusNetDef, Choices are:\n"
        "    (oaCollection_oaBusNetBit_oaBusNetDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaBusNetBit_oaBusNetDef_tp_dealloc(PyoaCollection_oaBusNetBit_oaBusNetDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaBusNetBit_oaBusNetDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBusNetBit_oaBusNetDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaBusNetBit_oaBusNetDef value;
    int convert_status=PyoaCollection_oaBusNetBit_oaBusNetDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[58];
    sprintf(buffer,"<oaCollection_oaBusNetBit_oaBusNetDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaBusNetBit_oaBusNetDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaBusNetBit_oaBusNetDef v1;
    PyParamoaCollection_oaBusNetBit_oaBusNetDef v2;
    int convert_status1=PyoaCollection_oaBusNetBit_oaBusNetDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaBusNetBit_oaBusNetDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaBusNetBit_oaBusNetDef_Convert(PyObject* ob,PyParamoaCollection_oaBusNetBit_oaBusNetDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaBusNetBit_oaBusNetDef_Check(ob)) {
        result->SetData( (oaCollection_oaBusNetBit_oaBusNetDef*) ((PyoaCollection_oaBusNetBit_oaBusNetDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaBusNetBit_oaBusNetDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaBusNetBit_oaBusNetDef_FromoaCollection_oaBusNetBit_oaBusNetDef(oaCollection_oaBusNetBit_oaBusNetDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaBusNetBit_oaBusNetDef_Type.tp_alloc(&PyoaCollection_oaBusNetBit_oaBusNetDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaBusNetBit_oaBusNetDefObject* self = (PyoaCollection_oaBusNetBit_oaBusNetDefObject*)bself;
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
static char oaCollection_oaBusNetBit_oaBusNetDef_includes_doc[] = 
"Class: oaCollection_oaBusNetBit_oaBusNetDef, Function: includes\n"
"  Paramegers: (oaBusNetBit)\n"
"    Calls: oaBoolean includes(const oaBusNetBit* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaBusNetBit,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaBusNetBit_oaBusNetDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaBusNetBit_oaBusNetDef data;
    int convert_status=PyoaCollection_oaBusNetBit_oaBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaBusNetBit_oaBusNetDefObject* self=(PyoaCollection_oaBusNetBit_oaBusNetDefObject*)ob;

    PyParamoaBusNetBit p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBusNetBit_Convert,&p1)) {
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

static char oaCollection_oaBusNetBit_oaBusNetDef_assign_doc[] = 
"Class: oaCollection_oaBusNetBit_oaBusNetDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaBusNetBit_oaBusNetDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaBusNetBit_oaBusNetDef data;
  int convert_status=PyoaCollection_oaBusNetBit_oaBusNetDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaBusNetBit_oaBusNetDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaBusNetBit_oaBusNetDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaBusNetBit_oaBusNetDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaBusNetBit_oaBusNetDef_includes,METH_VARARGS,oaCollection_oaBusNetBit_oaBusNetDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaBusNetBit_oaBusNetDef_tp_assign,METH_VARARGS,oaCollection_oaBusNetBit_oaBusNetDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaBusNetBit_oaBusNetDef_doc[] = 
"Class: oaCollection_oaBusNetBit_oaBusNetDef\n"
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
"  Paramegers: (oaCollection_oaBusNetBit_oaBusNetDef)\n"
"    Calls: oaCollection_oaBusNetBit_oaBusNetDef(const oaCollection_oaBusNetBit_oaBusNetDef& coll)\n"
"    Signature: oaCollection_oaBusNetBit_oaBusNetDef||cref-oaCollection_oaBusNetBit_oaBusNetDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaBusNetBit_oaBusNetDef)\n"
"    Calls: (const oaCollection_oaBusNetBit_oaBusNetDef&)\n"
"    Signature: oaCollection_oaBusNetBit_oaBusNetDef||cref-oaCollection_oaBusNetBit_oaBusNetDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaBusNetBit_oaBusNetDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaBusNetBit_oaBusNetDef",
    sizeof(PyoaCollection_oaBusNetBit_oaBusNetDefObject),
    0,
    (destructor)oaCollection_oaBusNetBit_oaBusNetDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaBusNetBit_oaBusNetDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaBusNetBit_oaBusNetDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaBusNetBit_oaBusNetDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaBusNetBit_oaBusNetDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaBusNetBit_oaBusNetDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaBusNetBit_oaBusNetDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaBusNetBit_oaBusNetDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaBusNetBit_oaBusNetDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaBusNetBit_oaBusNetDef",
           (PyObject*)(&PyoaCollection_oaBusNetBit_oaBusNetDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaBusNetBit_oaBusNetDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaBusNetDef_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBusNetDef_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaBusNetDef_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaBusNetDef_oaBlockObject* self = (PyoaCollection_oaBusNetDef_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaBusNetDef_oaBlock)
    {
        PyParamoaCollection_oaBusNetDef_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaBusNetDef_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaBusNetDef_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaBusNetDef_oaBlock, Choices are:\n"
        "    (oaCollection_oaBusNetDef_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaBusNetDef_oaBlock_tp_dealloc(PyoaCollection_oaBusNetDef_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaBusNetDef_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBusNetDef_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaBusNetDef_oaBlock value;
    int convert_status=PyoaCollection_oaBusNetDef_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaCollection_oaBusNetDef_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaBusNetDef_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaBusNetDef_oaBlock v1;
    PyParamoaCollection_oaBusNetDef_oaBlock v2;
    int convert_status1=PyoaCollection_oaBusNetDef_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaBusNetDef_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaBusNetDef_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaBusNetDef_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaBusNetDef_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaBusNetDef_oaBlock*) ((PyoaCollection_oaBusNetDef_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaBusNetDef_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaBusNetDef_oaBlock_FromoaCollection_oaBusNetDef_oaBlock(oaCollection_oaBusNetDef_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaBusNetDef_oaBlock_Type.tp_alloc(&PyoaCollection_oaBusNetDef_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaBusNetDef_oaBlockObject* self = (PyoaCollection_oaBusNetDef_oaBlockObject*)bself;
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
static char oaCollection_oaBusNetDef_oaBlock_includes_doc[] = 
"Class: oaCollection_oaBusNetDef_oaBlock, Function: includes\n"
"  Paramegers: (oaBusNetDef)\n"
"    Calls: oaBoolean includes(const oaBusNetDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaBusNetDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaBusNetDef_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaBusNetDef_oaBlock data;
    int convert_status=PyoaCollection_oaBusNetDef_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaBusNetDef_oaBlockObject* self=(PyoaCollection_oaBusNetDef_oaBlockObject*)ob;

    PyParamoaBusNetDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBusNetDef_Convert,&p1)) {
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

static char oaCollection_oaBusNetDef_oaBlock_assign_doc[] = 
"Class: oaCollection_oaBusNetDef_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaBusNetDef_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaBusNetDef_oaBlock data;
  int convert_status=PyoaCollection_oaBusNetDef_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaBusNetDef_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaBusNetDef_oaBlock_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaBusNetDef_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaBusNetDef_oaBlock_includes,METH_VARARGS,oaCollection_oaBusNetDef_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaBusNetDef_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaBusNetDef_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaBusNetDef_oaBlock_doc[] = 
"Class: oaCollection_oaBusNetDef_oaBlock\n"
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
"  Paramegers: (oaCollection_oaBusNetDef_oaBlock)\n"
"    Calls: oaCollection_oaBusNetDef_oaBlock(const oaCollection_oaBusNetDef_oaBlock& coll)\n"
"    Signature: oaCollection_oaBusNetDef_oaBlock||cref-oaCollection_oaBusNetDef_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaBusNetDef_oaBlock)\n"
"    Calls: (const oaCollection_oaBusNetDef_oaBlock&)\n"
"    Signature: oaCollection_oaBusNetDef_oaBlock||cref-oaCollection_oaBusNetDef_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaBusNetDef_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaBusNetDef_oaBlock",
    sizeof(PyoaCollection_oaBusNetDef_oaBlockObject),
    0,
    (destructor)oaCollection_oaBusNetDef_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaBusNetDef_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaBusNetDef_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaBusNetDef_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaBusNetDef_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaBusNetDef_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaBusNetDef_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaBusNetDef_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaBusNetDef_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaBusNetDef_oaBlock",
           (PyObject*)(&PyoaCollection_oaBusNetDef_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaBusNetDef_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaBusNet_oaBusNetDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBusNet_oaBusNetDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaBusNet_oaBusNetDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaBusNet_oaBusNetDefObject* self = (PyoaCollection_oaBusNet_oaBusNetDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaBusNet_oaBusNetDef)
    {
        PyParamoaCollection_oaBusNet_oaBusNetDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaBusNet_oaBusNetDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaBusNet_oaBusNetDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaBusNet_oaBusNetDef, Choices are:\n"
        "    (oaCollection_oaBusNet_oaBusNetDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaBusNet_oaBusNetDef_tp_dealloc(PyoaCollection_oaBusNet_oaBusNetDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaBusNet_oaBusNetDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBusNet_oaBusNetDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaBusNet_oaBusNetDef value;
    int convert_status=PyoaCollection_oaBusNet_oaBusNetDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaCollection_oaBusNet_oaBusNetDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaBusNet_oaBusNetDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaBusNet_oaBusNetDef v1;
    PyParamoaCollection_oaBusNet_oaBusNetDef v2;
    int convert_status1=PyoaCollection_oaBusNet_oaBusNetDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaBusNet_oaBusNetDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaBusNet_oaBusNetDef_Convert(PyObject* ob,PyParamoaCollection_oaBusNet_oaBusNetDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaBusNet_oaBusNetDef_Check(ob)) {
        result->SetData( (oaCollection_oaBusNet_oaBusNetDef*) ((PyoaCollection_oaBusNet_oaBusNetDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaBusNet_oaBusNetDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaBusNet_oaBusNetDef_FromoaCollection_oaBusNet_oaBusNetDef(oaCollection_oaBusNet_oaBusNetDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaBusNet_oaBusNetDef_Type.tp_alloc(&PyoaCollection_oaBusNet_oaBusNetDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaBusNet_oaBusNetDefObject* self = (PyoaCollection_oaBusNet_oaBusNetDefObject*)bself;
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
static char oaCollection_oaBusNet_oaBusNetDef_includes_doc[] = 
"Class: oaCollection_oaBusNet_oaBusNetDef, Function: includes\n"
"  Paramegers: (oaBusNet)\n"
"    Calls: oaBoolean includes(const oaBusNet* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaBusNet,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaBusNet_oaBusNetDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaBusNet_oaBusNetDef data;
    int convert_status=PyoaCollection_oaBusNet_oaBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaBusNet_oaBusNetDefObject* self=(PyoaCollection_oaBusNet_oaBusNetDefObject*)ob;

    PyParamoaBusNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBusNet_Convert,&p1)) {
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

static char oaCollection_oaBusNet_oaBusNetDef_assign_doc[] = 
"Class: oaCollection_oaBusNet_oaBusNetDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaBusNet_oaBusNetDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaBusNet_oaBusNetDef data;
  int convert_status=PyoaCollection_oaBusNet_oaBusNetDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaBusNet_oaBusNetDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaBusNet_oaBusNetDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaBusNet_oaBusNetDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaBusNet_oaBusNetDef_includes,METH_VARARGS,oaCollection_oaBusNet_oaBusNetDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaBusNet_oaBusNetDef_tp_assign,METH_VARARGS,oaCollection_oaBusNet_oaBusNetDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaBusNet_oaBusNetDef_doc[] = 
"Class: oaCollection_oaBusNet_oaBusNetDef\n"
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
"  Paramegers: (oaCollection_oaBusNet_oaBusNetDef)\n"
"    Calls: oaCollection_oaBusNet_oaBusNetDef(const oaCollection_oaBusNet_oaBusNetDef& coll)\n"
"    Signature: oaCollection_oaBusNet_oaBusNetDef||cref-oaCollection_oaBusNet_oaBusNetDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaBusNet_oaBusNetDef)\n"
"    Calls: (const oaCollection_oaBusNet_oaBusNetDef&)\n"
"    Signature: oaCollection_oaBusNet_oaBusNetDef||cref-oaCollection_oaBusNet_oaBusNetDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaBusNet_oaBusNetDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaBusNet_oaBusNetDef",
    sizeof(PyoaCollection_oaBusNet_oaBusNetDefObject),
    0,
    (destructor)oaCollection_oaBusNet_oaBusNetDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaBusNet_oaBusNetDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaBusNet_oaBusNetDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaBusNet_oaBusNetDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaBusNet_oaBusNetDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaBusNet_oaBusNetDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaBusNet_oaBusNetDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaBusNet_oaBusNetDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaBusNet_oaBusNetDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaBusNet_oaBusNetDef",
           (PyObject*)(&PyoaCollection_oaBusNet_oaBusNetDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaBusNet_oaBusNetDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaBusTermBit_oaBusTermDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBusTermBit_oaBusTermDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaBusTermBit_oaBusTermDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaBusTermBit_oaBusTermDefObject* self = (PyoaCollection_oaBusTermBit_oaBusTermDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaBusTermBit_oaBusTermDef)
    {
        PyParamoaCollection_oaBusTermBit_oaBusTermDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaBusTermBit_oaBusTermDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaBusTermBit_oaBusTermDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaBusTermBit_oaBusTermDef, Choices are:\n"
        "    (oaCollection_oaBusTermBit_oaBusTermDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaBusTermBit_oaBusTermDef_tp_dealloc(PyoaCollection_oaBusTermBit_oaBusTermDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaBusTermBit_oaBusTermDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBusTermBit_oaBusTermDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaBusTermBit_oaBusTermDef value;
    int convert_status=PyoaCollection_oaBusTermBit_oaBusTermDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[60];
    sprintf(buffer,"<oaCollection_oaBusTermBit_oaBusTermDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaBusTermBit_oaBusTermDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaBusTermBit_oaBusTermDef v1;
    PyParamoaCollection_oaBusTermBit_oaBusTermDef v2;
    int convert_status1=PyoaCollection_oaBusTermBit_oaBusTermDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaBusTermBit_oaBusTermDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaBusTermBit_oaBusTermDef_Convert(PyObject* ob,PyParamoaCollection_oaBusTermBit_oaBusTermDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaBusTermBit_oaBusTermDef_Check(ob)) {
        result->SetData( (oaCollection_oaBusTermBit_oaBusTermDef*) ((PyoaCollection_oaBusTermBit_oaBusTermDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaBusTermBit_oaBusTermDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaBusTermBit_oaBusTermDef_FromoaCollection_oaBusTermBit_oaBusTermDef(oaCollection_oaBusTermBit_oaBusTermDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaBusTermBit_oaBusTermDef_Type.tp_alloc(&PyoaCollection_oaBusTermBit_oaBusTermDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaBusTermBit_oaBusTermDefObject* self = (PyoaCollection_oaBusTermBit_oaBusTermDefObject*)bself;
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
static char oaCollection_oaBusTermBit_oaBusTermDef_includes_doc[] = 
"Class: oaCollection_oaBusTermBit_oaBusTermDef, Function: includes\n"
"  Paramegers: (oaBusTermBit)\n"
"    Calls: oaBoolean includes(const oaBusTermBit* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaBusTermBit,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaBusTermBit_oaBusTermDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaBusTermBit_oaBusTermDef data;
    int convert_status=PyoaCollection_oaBusTermBit_oaBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaBusTermBit_oaBusTermDefObject* self=(PyoaCollection_oaBusTermBit_oaBusTermDefObject*)ob;

    PyParamoaBusTermBit p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBusTermBit_Convert,&p1)) {
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

static char oaCollection_oaBusTermBit_oaBusTermDef_assign_doc[] = 
"Class: oaCollection_oaBusTermBit_oaBusTermDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaBusTermBit_oaBusTermDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaBusTermBit_oaBusTermDef data;
  int convert_status=PyoaCollection_oaBusTermBit_oaBusTermDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaBusTermBit_oaBusTermDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaBusTermBit_oaBusTermDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaBusTermBit_oaBusTermDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaBusTermBit_oaBusTermDef_includes,METH_VARARGS,oaCollection_oaBusTermBit_oaBusTermDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaBusTermBit_oaBusTermDef_tp_assign,METH_VARARGS,oaCollection_oaBusTermBit_oaBusTermDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaBusTermBit_oaBusTermDef_doc[] = 
"Class: oaCollection_oaBusTermBit_oaBusTermDef\n"
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
"  Paramegers: (oaCollection_oaBusTermBit_oaBusTermDef)\n"
"    Calls: oaCollection_oaBusTermBit_oaBusTermDef(const oaCollection_oaBusTermBit_oaBusTermDef& coll)\n"
"    Signature: oaCollection_oaBusTermBit_oaBusTermDef||cref-oaCollection_oaBusTermBit_oaBusTermDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaBusTermBit_oaBusTermDef)\n"
"    Calls: (const oaCollection_oaBusTermBit_oaBusTermDef&)\n"
"    Signature: oaCollection_oaBusTermBit_oaBusTermDef||cref-oaCollection_oaBusTermBit_oaBusTermDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaBusTermBit_oaBusTermDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaBusTermBit_oaBusTermDef",
    sizeof(PyoaCollection_oaBusTermBit_oaBusTermDefObject),
    0,
    (destructor)oaCollection_oaBusTermBit_oaBusTermDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaBusTermBit_oaBusTermDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaBusTermBit_oaBusTermDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaBusTermBit_oaBusTermDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaBusTermBit_oaBusTermDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaBusTermBit_oaBusTermDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaBusTermBit_oaBusTermDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaBusTermBit_oaBusTermDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaBusTermBit_oaBusTermDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaBusTermBit_oaBusTermDef",
           (PyObject*)(&PyoaCollection_oaBusTermBit_oaBusTermDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaBusTermBit_oaBusTermDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaBusTermDef_oaBlock
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBusTermDef_oaBlock_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaBusTermDef_oaBlock_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaBusTermDef_oaBlockObject* self = (PyoaCollection_oaBusTermDef_oaBlockObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaBusTermDef_oaBlock)
    {
        PyParamoaCollection_oaBusTermDef_oaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaBusTermDef_oaBlock_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaBusTermDef_oaBlock(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaBusTermDef_oaBlock, Choices are:\n"
        "    (oaCollection_oaBusTermDef_oaBlock)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaBusTermDef_oaBlock_tp_dealloc(PyoaCollection_oaBusTermDef_oaBlockObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaBusTermDef_oaBlock*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBusTermDef_oaBlock_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaBusTermDef_oaBlock value;
    int convert_status=PyoaCollection_oaBusTermDef_oaBlock_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaCollection_oaBusTermDef_oaBlock::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaBusTermDef_oaBlock_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaBusTermDef_oaBlock v1;
    PyParamoaCollection_oaBusTermDef_oaBlock v2;
    int convert_status1=PyoaCollection_oaBusTermDef_oaBlock_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaBusTermDef_oaBlock_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaBusTermDef_oaBlock_Convert(PyObject* ob,PyParamoaCollection_oaBusTermDef_oaBlock* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaBusTermDef_oaBlock_Check(ob)) {
        result->SetData( (oaCollection_oaBusTermDef_oaBlock*) ((PyoaCollection_oaBusTermDef_oaBlockObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaBusTermDef_oaBlock Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaBusTermDef_oaBlock_FromoaCollection_oaBusTermDef_oaBlock(oaCollection_oaBusTermDef_oaBlock* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaBusTermDef_oaBlock_Type.tp_alloc(&PyoaCollection_oaBusTermDef_oaBlock_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaBusTermDef_oaBlockObject* self = (PyoaCollection_oaBusTermDef_oaBlockObject*)bself;
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
static char oaCollection_oaBusTermDef_oaBlock_includes_doc[] = 
"Class: oaCollection_oaBusTermDef_oaBlock, Function: includes\n"
"  Paramegers: (oaBusTermDef)\n"
"    Calls: oaBoolean includes(const oaBusTermDef* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaBusTermDef,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaBusTermDef_oaBlock_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaBusTermDef_oaBlock data;
    int convert_status=PyoaCollection_oaBusTermDef_oaBlock_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaBusTermDef_oaBlockObject* self=(PyoaCollection_oaBusTermDef_oaBlockObject*)ob;

    PyParamoaBusTermDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBusTermDef_Convert,&p1)) {
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

static char oaCollection_oaBusTermDef_oaBlock_assign_doc[] = 
"Class: oaCollection_oaBusTermDef_oaBlock, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaBusTermDef_oaBlock_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaBusTermDef_oaBlock data;
  int convert_status=PyoaCollection_oaBusTermDef_oaBlock_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaBusTermDef_oaBlock p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaBusTermDef_oaBlock_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaBusTermDef_oaBlock_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaBusTermDef_oaBlock_includes,METH_VARARGS,oaCollection_oaBusTermDef_oaBlock_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaBusTermDef_oaBlock_tp_assign,METH_VARARGS,oaCollection_oaBusTermDef_oaBlock_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaBusTermDef_oaBlock_doc[] = 
"Class: oaCollection_oaBusTermDef_oaBlock\n"
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
"  Paramegers: (oaCollection_oaBusTermDef_oaBlock)\n"
"    Calls: oaCollection_oaBusTermDef_oaBlock(const oaCollection_oaBusTermDef_oaBlock& coll)\n"
"    Signature: oaCollection_oaBusTermDef_oaBlock||cref-oaCollection_oaBusTermDef_oaBlock,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaBusTermDef_oaBlock)\n"
"    Calls: (const oaCollection_oaBusTermDef_oaBlock&)\n"
"    Signature: oaCollection_oaBusTermDef_oaBlock||cref-oaCollection_oaBusTermDef_oaBlock,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaBusTermDef_oaBlock_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaBusTermDef_oaBlock",
    sizeof(PyoaCollection_oaBusTermDef_oaBlockObject),
    0,
    (destructor)oaCollection_oaBusTermDef_oaBlock_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaBusTermDef_oaBlock_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaBusTermDef_oaBlock_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaBusTermDef_oaBlock_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaBusTermDef_oaBlock_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaBusTermDef_oaBlock_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaBusTermDef_oaBlock_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaBusTermDef_oaBlock_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaBusTermDef_oaBlock\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaBusTermDef_oaBlock",
           (PyObject*)(&PyoaCollection_oaBusTermDef_oaBlock_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaBusTermDef_oaBlock\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaBusTerm_oaBusTermDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBusTerm_oaBusTermDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaBusTerm_oaBusTermDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaBusTerm_oaBusTermDefObject* self = (PyoaCollection_oaBusTerm_oaBusTermDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaBusTerm_oaBusTermDef)
    {
        PyParamoaCollection_oaBusTerm_oaBusTermDef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaBusTerm_oaBusTermDef_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaBusTerm_oaBusTermDef(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaBusTerm_oaBusTermDef, Choices are:\n"
        "    (oaCollection_oaBusTerm_oaBusTermDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaBusTerm_oaBusTermDef_tp_dealloc(PyoaCollection_oaBusTerm_oaBusTermDefObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaBusTerm_oaBusTermDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaBusTerm_oaBusTermDef_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaBusTerm_oaBusTermDef value;
    int convert_status=PyoaCollection_oaBusTerm_oaBusTermDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[57];
    sprintf(buffer,"<oaCollection_oaBusTerm_oaBusTermDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaBusTerm_oaBusTermDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaBusTerm_oaBusTermDef v1;
    PyParamoaCollection_oaBusTerm_oaBusTermDef v2;
    int convert_status1=PyoaCollection_oaBusTerm_oaBusTermDef_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaBusTerm_oaBusTermDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaBusTerm_oaBusTermDef_Convert(PyObject* ob,PyParamoaCollection_oaBusTerm_oaBusTermDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaBusTerm_oaBusTermDef_Check(ob)) {
        result->SetData( (oaCollection_oaBusTerm_oaBusTermDef*) ((PyoaCollection_oaBusTerm_oaBusTermDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaBusTerm_oaBusTermDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaBusTerm_oaBusTermDef_FromoaCollection_oaBusTerm_oaBusTermDef(oaCollection_oaBusTerm_oaBusTermDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaBusTerm_oaBusTermDef_Type.tp_alloc(&PyoaCollection_oaBusTerm_oaBusTermDef_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaBusTerm_oaBusTermDefObject* self = (PyoaCollection_oaBusTerm_oaBusTermDefObject*)bself;
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
static char oaCollection_oaBusTerm_oaBusTermDef_includes_doc[] = 
"Class: oaCollection_oaBusTerm_oaBusTermDef, Function: includes\n"
"  Paramegers: (oaBusTerm)\n"
"    Calls: oaBoolean includes(const oaBusTerm* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaBusTerm,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaBusTerm_oaBusTermDef_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaBusTerm_oaBusTermDef data;
    int convert_status=PyoaCollection_oaBusTerm_oaBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaBusTerm_oaBusTermDefObject* self=(PyoaCollection_oaBusTerm_oaBusTermDefObject*)ob;

    PyParamoaBusTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBusTerm_Convert,&p1)) {
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

static char oaCollection_oaBusTerm_oaBusTermDef_assign_doc[] = 
"Class: oaCollection_oaBusTerm_oaBusTermDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaBusTerm_oaBusTermDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaBusTerm_oaBusTermDef data;
  int convert_status=PyoaCollection_oaBusTerm_oaBusTermDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaBusTerm_oaBusTermDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaBusTerm_oaBusTermDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaBusTerm_oaBusTermDef_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaBusTerm_oaBusTermDef_includes,METH_VARARGS,oaCollection_oaBusTerm_oaBusTermDef_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaBusTerm_oaBusTermDef_tp_assign,METH_VARARGS,oaCollection_oaBusTerm_oaBusTermDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaBusTerm_oaBusTermDef_doc[] = 
"Class: oaCollection_oaBusTerm_oaBusTermDef\n"
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
"  Paramegers: (oaCollection_oaBusTerm_oaBusTermDef)\n"
"    Calls: oaCollection_oaBusTerm_oaBusTermDef(const oaCollection_oaBusTerm_oaBusTermDef& coll)\n"
"    Signature: oaCollection_oaBusTerm_oaBusTermDef||cref-oaCollection_oaBusTerm_oaBusTermDef,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaBusTerm_oaBusTermDef)\n"
"    Calls: (const oaCollection_oaBusTerm_oaBusTermDef&)\n"
"    Signature: oaCollection_oaBusTerm_oaBusTermDef||cref-oaCollection_oaBusTerm_oaBusTermDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaBusTerm_oaBusTermDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaBusTerm_oaBusTermDef",
    sizeof(PyoaCollection_oaBusTerm_oaBusTermDefObject),
    0,
    (destructor)oaCollection_oaBusTerm_oaBusTermDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaBusTerm_oaBusTermDef_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaBusTerm_oaBusTermDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaBusTerm_oaBusTermDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaBusTerm_oaBusTermDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaBusTerm_oaBusTermDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaBusTerm_oaBusTermDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaBusTerm_oaBusTermDef_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaBusTerm_oaBusTermDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaBusTerm_oaBusTermDef",
           (PyObject*)(&PyoaCollection_oaBusTerm_oaBusTermDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaBusTerm_oaBusTermDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaCellView_oaCell
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaCellView_oaCell_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaCellView_oaCell_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaCellView_oaCellObject* self = (PyoaCollection_oaCellView_oaCellObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaCellView_oaCell)
    {
        PyParamoaCollection_oaCellView_oaCell p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaCellView_oaCell_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaCellView_oaCell(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaCellView_oaCell, Choices are:\n"
        "    (oaCollection_oaCellView_oaCell)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaCellView_oaCell_tp_dealloc(PyoaCollection_oaCellView_oaCellObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaCellView_oaCell*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaCellView_oaCell_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaCellView_oaCell value;
    int convert_status=PyoaCollection_oaCellView_oaCell_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaCellView_oaCell::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaCellView_oaCell_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaCellView_oaCell v1;
    PyParamoaCollection_oaCellView_oaCell v2;
    int convert_status1=PyoaCollection_oaCellView_oaCell_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaCellView_oaCell_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaCellView_oaCell_Convert(PyObject* ob,PyParamoaCollection_oaCellView_oaCell* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaCellView_oaCell_Check(ob)) {
        result->SetData( (oaCollection_oaCellView_oaCell*) ((PyoaCollection_oaCellView_oaCellObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaCellView_oaCell Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaCellView_oaCell_FromoaCollection_oaCellView_oaCell(oaCollection_oaCellView_oaCell* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaCellView_oaCell_Type.tp_alloc(&PyoaCollection_oaCellView_oaCell_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaCellView_oaCellObject* self = (PyoaCollection_oaCellView_oaCellObject*)bself;
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
static char oaCollection_oaCellView_oaCell_includes_doc[] = 
"Class: oaCollection_oaCellView_oaCell, Function: includes\n"
"  Paramegers: (oaCellView)\n"
"    Calls: oaBoolean includes(const oaCellView* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaCellView,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaCellView_oaCell_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaCellView_oaCell data;
    int convert_status=PyoaCollection_oaCellView_oaCell_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaCellView_oaCellObject* self=(PyoaCollection_oaCellView_oaCellObject*)ob;

    PyParamoaCellView p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaCellView_Convert,&p1)) {
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

static char oaCollection_oaCellView_oaCell_assign_doc[] = 
"Class: oaCollection_oaCellView_oaCell, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaCellView_oaCell_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaCellView_oaCell data;
  int convert_status=PyoaCollection_oaCellView_oaCell_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaCellView_oaCell p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaCellView_oaCell_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaCellView_oaCell_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaCellView_oaCell_includes,METH_VARARGS,oaCollection_oaCellView_oaCell_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaCellView_oaCell_tp_assign,METH_VARARGS,oaCollection_oaCellView_oaCell_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaCellView_oaCell_doc[] = 
"Class: oaCollection_oaCellView_oaCell\n"
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
"  Paramegers: (oaCollection_oaCellView_oaCell)\n"
"    Calls: oaCollection_oaCellView_oaCell(const oaCollection_oaCellView_oaCell& coll)\n"
"    Signature: oaCollection_oaCellView_oaCell||cref-oaCollection_oaCellView_oaCell,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaCellView_oaCell)\n"
"    Calls: (const oaCollection_oaCellView_oaCell&)\n"
"    Signature: oaCollection_oaCellView_oaCell||cref-oaCollection_oaCellView_oaCell,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaCellView_oaCell_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaCellView_oaCell",
    sizeof(PyoaCollection_oaCellView_oaCellObject),
    0,
    (destructor)oaCollection_oaCellView_oaCell_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaCellView_oaCell_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaCellView_oaCell_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaCellView_oaCell_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaCellView_oaCell_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaCellView_oaCell_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaCellView_oaCell_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaCellView_oaCell_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaCellView_oaCell\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaCellView_oaCell",
           (PyObject*)(&PyoaCollection_oaCellView_oaCell_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaCellView_oaCell\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaCellView_oaLib
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaCellView_oaLib_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaCellView_oaLib_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaCellView_oaLibObject* self = (PyoaCollection_oaCellView_oaLibObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaCellView_oaLib)
    {
        PyParamoaCollection_oaCellView_oaLib p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaCellView_oaLib_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaCellView_oaLib(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaCellView_oaLib, Choices are:\n"
        "    (oaCollection_oaCellView_oaLib)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaCellView_oaLib_tp_dealloc(PyoaCollection_oaCellView_oaLibObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaCellView_oaLib*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaCellView_oaLib_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaCellView_oaLib value;
    int convert_status=PyoaCollection_oaCellView_oaLib_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaCollection_oaCellView_oaLib::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaCellView_oaLib_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaCellView_oaLib v1;
    PyParamoaCollection_oaCellView_oaLib v2;
    int convert_status1=PyoaCollection_oaCellView_oaLib_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaCellView_oaLib_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaCellView_oaLib_Convert(PyObject* ob,PyParamoaCollection_oaCellView_oaLib* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaCellView_oaLib_Check(ob)) {
        result->SetData( (oaCollection_oaCellView_oaLib*) ((PyoaCollection_oaCellView_oaLibObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaCellView_oaLib Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaCellView_oaLib_FromoaCollection_oaCellView_oaLib(oaCollection_oaCellView_oaLib* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaCellView_oaLib_Type.tp_alloc(&PyoaCollection_oaCellView_oaLib_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaCellView_oaLibObject* self = (PyoaCollection_oaCellView_oaLibObject*)bself;
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
static char oaCollection_oaCellView_oaLib_includes_doc[] = 
"Class: oaCollection_oaCellView_oaLib, Function: includes\n"
"  Paramegers: (oaCellView)\n"
"    Calls: oaBoolean includes(const oaCellView* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaCellView,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaCellView_oaLib_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaCellView_oaLib data;
    int convert_status=PyoaCollection_oaCellView_oaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaCellView_oaLibObject* self=(PyoaCollection_oaCellView_oaLibObject*)ob;

    PyParamoaCellView p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaCellView_Convert,&p1)) {
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

static char oaCollection_oaCellView_oaLib_assign_doc[] = 
"Class: oaCollection_oaCellView_oaLib, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaCellView_oaLib_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaCellView_oaLib data;
  int convert_status=PyoaCollection_oaCellView_oaLib_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaCellView_oaLib p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaCellView_oaLib_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaCellView_oaLib_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaCellView_oaLib_includes,METH_VARARGS,oaCollection_oaCellView_oaLib_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaCellView_oaLib_tp_assign,METH_VARARGS,oaCollection_oaCellView_oaLib_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaCellView_oaLib_doc[] = 
"Class: oaCollection_oaCellView_oaLib\n"
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
"  Paramegers: (oaCollection_oaCellView_oaLib)\n"
"    Calls: oaCollection_oaCellView_oaLib(const oaCollection_oaCellView_oaLib& coll)\n"
"    Signature: oaCollection_oaCellView_oaLib||cref-oaCollection_oaCellView_oaLib,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaCellView_oaLib)\n"
"    Calls: (const oaCollection_oaCellView_oaLib&)\n"
"    Signature: oaCollection_oaCellView_oaLib||cref-oaCollection_oaCellView_oaLib,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaCellView_oaLib_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaCellView_oaLib",
    sizeof(PyoaCollection_oaCellView_oaLibObject),
    0,
    (destructor)oaCollection_oaCellView_oaLib_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaCellView_oaLib_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaCellView_oaLib_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaCellView_oaLib_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaCellView_oaLib_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaCellView_oaLib_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaCellView_oaLib_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaCellView_oaLib_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaCellView_oaLib\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaCellView_oaLib",
           (PyObject*)(&PyoaCollection_oaCellView_oaLib_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaCellView_oaLib\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaCellView_oaView
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaCellView_oaView_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaCellView_oaView_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaCellView_oaViewObject* self = (PyoaCollection_oaCellView_oaViewObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaCellView_oaView)
    {
        PyParamoaCollection_oaCellView_oaView p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaCellView_oaView_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaCellView_oaView(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaCellView_oaView, Choices are:\n"
        "    (oaCollection_oaCellView_oaView)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaCellView_oaView_tp_dealloc(PyoaCollection_oaCellView_oaViewObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaCellView_oaView*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaCellView_oaView_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaCellView_oaView value;
    int convert_status=PyoaCollection_oaCellView_oaView_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaCollection_oaCellView_oaView::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaCellView_oaView_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaCellView_oaView v1;
    PyParamoaCollection_oaCellView_oaView v2;
    int convert_status1=PyoaCollection_oaCellView_oaView_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaCellView_oaView_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaCellView_oaView_Convert(PyObject* ob,PyParamoaCollection_oaCellView_oaView* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaCellView_oaView_Check(ob)) {
        result->SetData( (oaCollection_oaCellView_oaView*) ((PyoaCollection_oaCellView_oaViewObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaCellView_oaView Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaCellView_oaView_FromoaCollection_oaCellView_oaView(oaCollection_oaCellView_oaView* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaCellView_oaView_Type.tp_alloc(&PyoaCollection_oaCellView_oaView_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaCellView_oaViewObject* self = (PyoaCollection_oaCellView_oaViewObject*)bself;
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
static char oaCollection_oaCellView_oaView_includes_doc[] = 
"Class: oaCollection_oaCellView_oaView, Function: includes\n"
"  Paramegers: (oaCellView)\n"
"    Calls: oaBoolean includes(const oaCellView* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaCellView,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaCellView_oaView_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaCellView_oaView data;
    int convert_status=PyoaCollection_oaCellView_oaView_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaCellView_oaViewObject* self=(PyoaCollection_oaCellView_oaViewObject*)ob;

    PyParamoaCellView p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaCellView_Convert,&p1)) {
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

static char oaCollection_oaCellView_oaView_assign_doc[] = 
"Class: oaCollection_oaCellView_oaView, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaCellView_oaView_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaCellView_oaView data;
  int convert_status=PyoaCollection_oaCellView_oaView_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaCellView_oaView p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaCellView_oaView_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaCellView_oaView_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaCellView_oaView_includes,METH_VARARGS,oaCollection_oaCellView_oaView_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaCellView_oaView_tp_assign,METH_VARARGS,oaCollection_oaCellView_oaView_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaCellView_oaView_doc[] = 
"Class: oaCollection_oaCellView_oaView\n"
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
"  Paramegers: (oaCollection_oaCellView_oaView)\n"
"    Calls: oaCollection_oaCellView_oaView(const oaCollection_oaCellView_oaView& coll)\n"
"    Signature: oaCollection_oaCellView_oaView||cref-oaCollection_oaCellView_oaView,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaCellView_oaView)\n"
"    Calls: (const oaCollection_oaCellView_oaView&)\n"
"    Signature: oaCollection_oaCellView_oaView||cref-oaCollection_oaCellView_oaView,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaCellView_oaView_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaCellView_oaView",
    sizeof(PyoaCollection_oaCellView_oaViewObject),
    0,
    (destructor)oaCollection_oaCellView_oaView_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaCellView_oaView_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaCellView_oaView_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaCellView_oaView_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaCellView_oaView_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaCellView_oaView_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaCellView_oaView_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaCellView_oaView_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaCellView_oaView\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaCellView_oaView",
           (PyObject*)(&PyoaCollection_oaCellView_oaView_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaCellView_oaView\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaCell_oaLib
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaCell_oaLib_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaCell_oaLib_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaCell_oaLibObject* self = (PyoaCollection_oaCell_oaLibObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaCell_oaLib)
    {
        PyParamoaCollection_oaCell_oaLib p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaCell_oaLib_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaCell_oaLib(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaCell_oaLib, Choices are:\n"
        "    (oaCollection_oaCell_oaLib)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaCell_oaLib_tp_dealloc(PyoaCollection_oaCell_oaLibObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaCell_oaLib*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaCell_oaLib_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaCell_oaLib value;
    int convert_status=PyoaCollection_oaCell_oaLib_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaCollection_oaCell_oaLib::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaCell_oaLib_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaCell_oaLib v1;
    PyParamoaCollection_oaCell_oaLib v2;
    int convert_status1=PyoaCollection_oaCell_oaLib_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaCell_oaLib_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaCell_oaLib_Convert(PyObject* ob,PyParamoaCollection_oaCell_oaLib* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaCell_oaLib_Check(ob)) {
        result->SetData( (oaCollection_oaCell_oaLib*) ((PyoaCollection_oaCell_oaLibObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaCell_oaLib Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaCell_oaLib_FromoaCollection_oaCell_oaLib(oaCollection_oaCell_oaLib* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaCell_oaLib_Type.tp_alloc(&PyoaCollection_oaCell_oaLib_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaCell_oaLibObject* self = (PyoaCollection_oaCell_oaLibObject*)bself;
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
static char oaCollection_oaCell_oaLib_includes_doc[] = 
"Class: oaCollection_oaCell_oaLib, Function: includes\n"
"  Paramegers: (oaCell)\n"
"    Calls: oaBoolean includes(const oaCell* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaCell,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaCell_oaLib_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaCell_oaLib data;
    int convert_status=PyoaCollection_oaCell_oaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaCell_oaLibObject* self=(PyoaCollection_oaCell_oaLibObject*)ob;

    PyParamoaCell p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaCell_Convert,&p1)) {
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

static char oaCollection_oaCell_oaLib_assign_doc[] = 
"Class: oaCollection_oaCell_oaLib, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaCell_oaLib_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaCell_oaLib data;
  int convert_status=PyoaCollection_oaCell_oaLib_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaCell_oaLib p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaCell_oaLib_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaCell_oaLib_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaCell_oaLib_includes,METH_VARARGS,oaCollection_oaCell_oaLib_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaCell_oaLib_tp_assign,METH_VARARGS,oaCollection_oaCell_oaLib_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaCell_oaLib_doc[] = 
"Class: oaCollection_oaCell_oaLib\n"
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
"  Paramegers: (oaCollection_oaCell_oaLib)\n"
"    Calls: oaCollection_oaCell_oaLib(const oaCollection_oaCell_oaLib& coll)\n"
"    Signature: oaCollection_oaCell_oaLib||cref-oaCollection_oaCell_oaLib,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaCell_oaLib)\n"
"    Calls: (const oaCollection_oaCell_oaLib&)\n"
"    Signature: oaCollection_oaCell_oaLib||cref-oaCollection_oaCell_oaLib,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaCell_oaLib_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaCell_oaLib",
    sizeof(PyoaCollection_oaCell_oaLibObject),
    0,
    (destructor)oaCollection_oaCell_oaLib_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaCell_oaLib_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaCell_oaLib_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaCell_oaLib_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaCell_oaLib_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaCell_oaLib_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaCell_oaLib_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaCell_oaLib_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaCell_oaLib\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaCell_oaLib",
           (PyObject*)(&PyoaCollection_oaCell_oaLib_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaCell_oaLib\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaCollection_oaClusterBoundary_oaCluster
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaClusterBoundary_oaCluster_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaCollection_oaClusterBoundary_oaCluster_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaCollection_oaClusterBoundary_oaClusterObject* self = (PyoaCollection_oaClusterBoundary_oaClusterObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaCollection_oaClusterBoundary_oaCluster)
    {
        PyParamoaCollection_oaClusterBoundary_oaCluster p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaCollection_oaClusterBoundary_oaCluster_Convert,&p1)) {
            self->value = (oaBaseCollection*)  new oaCollection_oaClusterBoundary_oaCluster(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaCollection_oaClusterBoundary_oaCluster, Choices are:\n"
        "    (oaCollection_oaClusterBoundary_oaCluster)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaCollection_oaClusterBoundary_oaCluster_tp_dealloc(PyoaCollection_oaClusterBoundary_oaClusterObject* self)
{
    if (!self->borrow) {
        delete (oaCollection_oaClusterBoundary_oaCluster*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaCollection_oaClusterBoundary_oaCluster_tp_repr(PyObject *ob)
{
    PyParamoaCollection_oaClusterBoundary_oaCluster value;
    int convert_status=PyoaCollection_oaClusterBoundary_oaCluster_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[62];
    sprintf(buffer,"<oaCollection_oaClusterBoundary_oaCluster::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaCollection_oaClusterBoundary_oaCluster_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaCollection_oaClusterBoundary_oaCluster v1;
    PyParamoaCollection_oaClusterBoundary_oaCluster v2;
    int convert_status1=PyoaCollection_oaClusterBoundary_oaCluster_Convert(ob1,&v1);
    int convert_status2=PyoaCollection_oaClusterBoundary_oaCluster_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaCollection_oaClusterBoundary_oaCluster_Convert(PyObject* ob,PyParamoaCollection_oaClusterBoundary_oaCluster* result)
{
    if (ob == NULL) return 1;
    if (PyoaCollection_oaClusterBoundary_oaCluster_Check(ob)) {
        result->SetData( (oaCollection_oaClusterBoundary_oaCluster*) ((PyoaCollection_oaClusterBoundary_oaClusterObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaCollection_oaClusterBoundary_oaCluster Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaCollection_oaClusterBoundary_oaCluster_FromoaCollection_oaClusterBoundary_oaCluster(oaCollection_oaClusterBoundary_oaCluster* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaCollection_oaClusterBoundary_oaCluster_Type.tp_alloc(&PyoaCollection_oaClusterBoundary_oaCluster_Type,0);
        if (bself == NULL) return bself;
        PyoaCollection_oaClusterBoundary_oaClusterObject* self = (PyoaCollection_oaClusterBoundary_oaClusterObject*)bself;
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
static char oaCollection_oaClusterBoundary_oaCluster_includes_doc[] = 
"Class: oaCollection_oaClusterBoundary_oaCluster, Function: includes\n"
"  Paramegers: (oaClusterBoundary)\n"
"    Calls: oaBoolean includes(const oaClusterBoundary* o)\n"
"    Signature: includes|simple-oaBoolean|cptr-oaClusterBoundary,\n"
"    This function determines if the given object is a member of this collection.\n"
"    Note: This function is not guaranteed to be fast. For some collections, the database walks over all the members of the collection until this function either finds the object or tries all members of the collection.\n"
;

static PyObject*
oaCollection_oaClusterBoundary_oaCluster_includes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaCollection_oaClusterBoundary_oaCluster data;
    int convert_status=PyoaCollection_oaClusterBoundary_oaCluster_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaCollection_oaClusterBoundary_oaClusterObject* self=(PyoaCollection_oaClusterBoundary_oaClusterObject*)ob;

    PyParamoaClusterBoundary p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaClusterBoundary_Convert,&p1)) {
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

static char oaCollection_oaClusterBoundary_oaCluster_assign_doc[] = 
"Class: oaCollection_oaClusterBoundary_oaCluster, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaCollection_oaClusterBoundary_oaCluster_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaCollection_oaClusterBoundary_oaCluster data;
  int convert_status=PyoaCollection_oaClusterBoundary_oaCluster_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaCollection_oaClusterBoundary_oaCluster p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaCollection_oaClusterBoundary_oaCluster_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaCollection_oaClusterBoundary_oaCluster_methodlist[] = {
    {"includes",(PyCFunction)oaCollection_oaClusterBoundary_oaCluster_includes,METH_VARARGS,oaCollection_oaClusterBoundary_oaCluster_includes_doc},
    {"assign",(PyCFunction)oaCollection_oaClusterBoundary_oaCluster_tp_assign,METH_VARARGS,oaCollection_oaClusterBoundary_oaCluster_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaCollection_oaClusterBoundary_oaCluster_doc[] = 
"Class: oaCollection_oaClusterBoundary_oaCluster\n"
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
"  Paramegers: (oaCollection_oaClusterBoundary_oaCluster)\n"
"    Calls: oaCollection_oaClusterBoundary_oaCluster(const oaCollection_oaClusterBoundary_oaCluster& coll)\n"
"    Signature: oaCollection_oaClusterBoundary_oaCluster||cref-oaCollection_oaClusterBoundary_oaCluster,\n"
"    This is the oaCollection copy constructor. It constructs a copy of the collection specified by coll .\n"
"  Paramegers: (oaCollection_oaClusterBoundary_oaCluster)\n"
"    Calls: (const oaCollection_oaClusterBoundary_oaCluster&)\n"
"    Signature: oaCollection_oaClusterBoundary_oaCluster||cref-oaCollection_oaClusterBoundary_oaCluster,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaCollection_oaClusterBoundary_oaCluster_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaCollection_oaClusterBoundary_oaCluster",
    sizeof(PyoaCollection_oaClusterBoundary_oaClusterObject),
    0,
    (destructor)oaCollection_oaClusterBoundary_oaCluster_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaCollection_oaClusterBoundary_oaCluster_tp_compare,	/* tp_compare */
    (reprfunc)oaCollection_oaClusterBoundary_oaCluster_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaCollection_oaClusterBoundary_oaCluster_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaCollection_oaClusterBoundary_oaCluster_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseCollection_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaCollection_oaClusterBoundary_oaCluster_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaCollection_oaClusterBoundary_oaCluster_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaCollection_oaClusterBoundary_oaCluster_Type)<0) {
      printf("** PyType_Ready failed for: oaCollection_oaClusterBoundary_oaCluster\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaCollection_oaClusterBoundary_oaCluster",
           (PyObject*)(&PyoaCollection_oaClusterBoundary_oaCluster_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaCollection_oaClusterBoundary_oaCluster\n");
       return -1;
    }
    return 0;
}

