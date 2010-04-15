
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaPath
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPath_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPath_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPathObject* self = (PyoaPathObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaPath)
    {
        PyParamoaPath p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPath_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaPath, Choices are:\n"
        "    (oaPath)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPath_tp_dealloc(PyoaPathObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPath_tp_repr(PyObject *ob)
{
    PyParamoaPath value;
    int convert_status=PyoaPath_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[28];
    sprintf(buffer,"<oaPath::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaPath_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPath v1;
    PyParamoaPath v2;
    int convert_status1=PyoaPath_Convert(ob1,&v1);
    int convert_status2=PyoaPath_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPath_Convert(PyObject* ob,PyParamoaPath* result)
{
    if (ob == NULL) return 1;
    if (PyoaPath_Check(ob)) {
        result->SetData( (oaPath**) ((PyoaPathObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPath Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPath_FromoaPath(oaPath** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaPath* data=*value;
        PyObject* bself = PyoaPath_Type.tp_alloc(&PyoaPath_Type,0);
        if (bself == NULL) return bself;
        PyoaPathObject* self = (PyoaPathObject*)bself;
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
PyObject* PyoaPath_FromoaPath(oaPath* data)
{
    if (data) {
       PyObject* bself = PyoaPath_Type.tp_alloc(&PyoaPath_Type,0);
       if (bself == NULL) return bself;
       PyoaPathObject* self = (PyoaPathObject*)bself;
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
static char oaPath_convertToPolygon_doc[] = 
"Class: oaPath, Function: convertToPolygon\n"
"  Paramegers: ()\n"
"    Calls: oaPolygon* convertToPolygon()\n"
"    Signature: convertToPolygon|ptr-oaPolygon|\n"
"    BrowseData: 1\n"
"    This function converts this path object to a polygon object. The resulting polygon is equivalent to the outline of the path. All path attributes are discarded after the object conversion is complete. Pointers to the path are still valid, but point to the new polygon.\n"
;

static PyObject*
oaPath_convertToPolygon(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPath data;
    int convert_status=PyoaPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathObject* self=(PyoaPathObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaPolygonp result= (data.DataCall()->convertToPolygon());
        return PyoaPolygon_FromoaPolygon(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPath_getBeginExt_doc[] = 
"Class: oaPath, Function: getBeginExt\n"
"  Paramegers: ()\n"
"    Calls: oaDist getBeginExt() const\n"
"    Signature: getBeginExt|simple-oaDist|\n"
"    BrowseData: 1\n"
"    This function returns the beginning extension of an oaPath in database units. By definition, the extension is zero if the oaPathStyle is anything other than oacVariablePathStyle.\n"
"    An oaUInt4 that is the beginning extension of the oaPath, in database units\n"
;

static PyObject*
oaPath_getBeginExt(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPath data;
    int convert_status=PyoaPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathObject* self=(PyoaPathObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDist result= (data.DataCall()->getBeginExt());
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
static char oaPath_getBoundary_doc[] = 
"Class: oaPath, Function: getBoundary\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void getBoundary(oaPointArray& boundary) const\n"
"    Signature: getBoundary|void-void|ref-oaPointArray,\n"
"    BrowseData: 0,oaPointArray\n"
"    This function constructs a boundary with the polygonal outline of the path. This function is useful for overlap checks with the path, and to render what the path looks like.\n"
"    boundary\n"
"    The generated boundary point array\n"
"    genBoundary()\n"
;

static PyObject*
oaPath_getBoundary(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPath data;
    int convert_status=PyoaPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathObject* self=(PyoaPathObject*)ob;
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
static char oaPath_getEndExt_doc[] = 
"Class: oaPath, Function: getEndExt\n"
"  Paramegers: ()\n"
"    Calls: oaDist getEndExt() const\n"
"    Signature: getEndExt|simple-oaDist|\n"
"    BrowseData: 1\n"
"    This function returns the ending extension of an oaPath in database units. By definition, the extension is zero if the oaPathStyle is anything other than oacVariablePathStyle.\n"
"    An oaUInt4 that is the ending extension of the oaPath, in database units\n"
;

static PyObject*
oaPath_getEndExt(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPath data;
    int convert_status=PyoaPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathObject* self=(PyoaPathObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDist result= (data.DataCall()->getEndExt());
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
static char oaPath_getNumPoints_doc[] = 
"Class: oaPath, Function: getNumPoints\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumPoints() const\n"
"    Signature: getNumPoints|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of points in the oaPath, which is the number after the oaPath is compressed by oaPath::create() .\n"
;

static PyObject*
oaPath_getNumPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPath data;
    int convert_status=PyoaPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathObject* self=(PyoaPathObject*)ob;
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
static char oaPath_getPoints_doc[] = 
"Class: oaPath, Function: getPoints\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void getPoints(oaPointArray& points) const\n"
"    Signature: getPoints|void-void|ref-oaPointArray,\n"
"    BrowseData: 0,oaPointArray\n"
"    This function gets the point array of an oaPath object. The point array consists of the points along the centerline of the oaPath after the oaPath is compressed by oaPath::create() .\n"
"    points\n"
"    The pointArray of the oaPath after compression\n"
"    Void\n"
;

static PyObject*
oaPath_getPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPath data;
    int convert_status=PyoaPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathObject* self=(PyoaPathObject*)ob;
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
static char oaPath_getStyle_doc[] = 
"Class: oaPath, Function: getStyle\n"
"  Paramegers: ()\n"
"    Calls: oaPathStyle getStyle() const\n"
"    Signature: getStyle|simple-oaPathStyle|\n"
"    BrowseData: 1\n"
"    This function returns the style of the oaPath.\n"
"    oaPathStyle\n"
;

static PyObject*
oaPath_getStyle(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPath data;
    int convert_status=PyoaPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathObject* self=(PyoaPathObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaPathStyle* result= new oaPathStyle(data.DataCall()->getStyle());
        return PyoaPathStyle_FromoaPathStyle(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPath_getWidth_doc[] = 
"Class: oaPath, Function: getWidth\n"
"  Paramegers: ()\n"
"    Calls: oaDist getWidth() const\n"
"    Signature: getWidth|simple-oaDist|\n"
"    BrowseData: 1\n"
"    This function returns the width of this oaPath in database units.\n"
;

static PyObject*
oaPath_getWidth(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPath data;
    int convert_status=PyoaPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathObject* self=(PyoaPathObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDist result= (data.DataCall()->getWidth());
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
static char oaPath_isOrthogonal_doc[] = 
"Class: oaPath, Function: isOrthogonal\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isOrthogonal() const\n"
"    Signature: isOrthogonal|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if the point array for the oaPath is orthogonal.\n"
;

static PyObject*
oaPath_isOrthogonal(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPath data;
    int convert_status=PyoaPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathObject* self=(PyoaPathObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isOrthogonal());
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
static char oaPath_setBeginExt_doc[] = 
"Class: oaPath, Function: setBeginExt\n"
"  Paramegers: (oaDist)\n"
"    Calls: void setBeginExt(oaDist beginExt)\n"
"    Signature: setBeginExt|void-void|simple-oaDist,\n"
"    This function sets the beginning extension for an oaPath that has the oacVariablePathStyle.\n"
"    beginExt\n"
"    The value of the beginning extension for the oaPath, in database units\n"
"    oacInvalidPathExtensionValue\n"
;

static PyObject*
oaPath_setBeginExt(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPath data;
    int convert_status=PyoaPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathObject* self=(PyoaPathObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDist p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDist_Convert,&p1)) {
        data.DataCall()->setBeginExt(p1.Data());
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
static char oaPath_setEndExt_doc[] = 
"Class: oaPath, Function: setEndExt\n"
"  Paramegers: (oaDist)\n"
"    Calls: void setEndExt(oaDist endExt)\n"
"    Signature: setEndExt|void-void|simple-oaDist,\n"
"    This function sets the ending extension for the oaPath to the specified value.\n"
"    endExt\n"
"    The value of the ending extension for the oaPath in database units\n"
"    oacInvalidPathExtensionValue\n"
;

static PyObject*
oaPath_setEndExt(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPath data;
    int convert_status=PyoaPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathObject* self=(PyoaPathObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDist p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDist_Convert,&p1)) {
        data.DataCall()->setEndExt(p1.Data());
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
static char oaPath_setPoints_doc[] = 
"Class: oaPath, Function: setPoints\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void setPoints(const oaPointArray& points)\n"
"    Signature: setPoints|void-void|cref-oaPointArray,\n"
"    This function sets the points of the oaPath with the specified point array. The point array is first compressed to remove collinear and coincident points, then is checked to verify that at least two points remain.\n"
"    points\n"
"    A point array that defines the centerline of the oaPath\n"
"    oacPathHasExtraPoints\n"
"    oacPathTooFewPoints\n"
;

static PyObject*
oaPath_setPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPath data;
    int convert_status=PyoaPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathObject* self=(PyoaPathObject*)ob;
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
static char oaPath_setStyle_doc[] = 
"Class: oaPath, Function: setStyle\n"
"  Paramegers: (oaPathStyle)\n"
"    Calls: void setStyle(oaPathStyle style)\n"
"    Signature: setStyle|void-void|simple-oaPathStyle,\n"
"    This function sets the oaPathStyle value.\n"
;

static PyObject*
oaPath_setStyle(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPath data;
    int convert_status=PyoaPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathObject* self=(PyoaPathObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPathStyle p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPathStyle_Convert,&p1)) {
        data.DataCall()->setStyle(p1.Data());
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
static char oaPath_setWidth_doc[] = 
"Class: oaPath, Function: setWidth\n"
"  Paramegers: (oaDist)\n"
"    Calls: void setWidth(oaDist width)\n"
"    Signature: setWidth|void-void|simple-oaDist,\n"
"    This function sets the width of the oaPath to the specified value.\n"
"    width\n"
"    The width value of the oaPath, in database units\n"
;

static PyObject*
oaPath_setWidth(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPath data;
    int convert_status=PyoaPath_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathObject* self=(PyoaPathObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDist p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDist_Convert,&p1)) {
        data.DataCall()->setWidth(p1.Data());
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
static char oaPath_isNull_doc[] =
"Class: oaPath, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaPath_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaPath data;
    int convert_status=PyoaPath_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaPath_assign_doc[] = 
"Class: oaPath, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPath_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPath data;
  int convert_status=PyoaPath_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPath p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPath_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPath_methodlist[] = {
    {"convertToPolygon",(PyCFunction)oaPath_convertToPolygon,METH_VARARGS,oaPath_convertToPolygon_doc},
    {"getBeginExt",(PyCFunction)oaPath_getBeginExt,METH_VARARGS,oaPath_getBeginExt_doc},
    {"getBoundary",(PyCFunction)oaPath_getBoundary,METH_VARARGS,oaPath_getBoundary_doc},
    {"getEndExt",(PyCFunction)oaPath_getEndExt,METH_VARARGS,oaPath_getEndExt_doc},
    {"getNumPoints",(PyCFunction)oaPath_getNumPoints,METH_VARARGS,oaPath_getNumPoints_doc},
    {"getPoints",(PyCFunction)oaPath_getPoints,METH_VARARGS,oaPath_getPoints_doc},
    {"getStyle",(PyCFunction)oaPath_getStyle,METH_VARARGS,oaPath_getStyle_doc},
    {"getWidth",(PyCFunction)oaPath_getWidth,METH_VARARGS,oaPath_getWidth_doc},
    {"isOrthogonal",(PyCFunction)oaPath_isOrthogonal,METH_VARARGS,oaPath_isOrthogonal_doc},
    {"setBeginExt",(PyCFunction)oaPath_setBeginExt,METH_VARARGS,oaPath_setBeginExt_doc},
    {"setEndExt",(PyCFunction)oaPath_setEndExt,METH_VARARGS,oaPath_setEndExt_doc},
    {"setPoints",(PyCFunction)oaPath_setPoints,METH_VARARGS,oaPath_setPoints_doc},
    {"setStyle",(PyCFunction)oaPath_setStyle,METH_VARARGS,oaPath_setStyle_doc},
    {"setWidth",(PyCFunction)oaPath_setWidth,METH_VARARGS,oaPath_setWidth_doc},
    {"isNull",(PyCFunction)oaPath_tp_isNull,METH_VARARGS,oaPath_isNull_doc},
    {"assign",(PyCFunction)oaPath_tp_assign,METH_VARARGS,oaPath_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPath_doc[] = 
"Class: oaPath\n"
"  The oaPath class implements the oaPath object, which derives from the oaShape class. An oaPath object represents a path that contains a point array and has certain width and style represented by oaPathStyle .\n"
"  Two coincident and three collinear points are illegal, and an exception is thrown if these combinations are detected. You can use oaPointArray::compress() to remove these combinations.\n"
"Constructors:\n"
"  Paramegers: (oaPath)\n"
"    Calls: (const oaPath&)\n"
"    Signature: oaPath||cref-oaPath,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPath_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPath",
    sizeof(PyoaPathObject),
    0,
    (destructor)oaPath_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPath_tp_compare,	/* tp_compare */
    (reprfunc)oaPath_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPath_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPath_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaShape_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPath_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPath_static_create_doc[] = 
"Class: oaPath, Function: create\n"
"  Paramegers: (oaBlock,oaLayerNum,oaPurposeNum,oaDist,oaPointArray)\n"
"    Calls: oaPath* create(oaBlock* block,oaLayerNum layerNum,oaPurposeNum purposeNum,oaDist width,const oaPointArray& points)\n"
"    Signature: create|ptr-oaPath|ptr-oaBlock,simple-oaLayerNum,simple-oaPurposeNum,simple-oaDist,cref-oaPointArray,simple-oaPathStyle,simple-oaDist,simple-oaDist,\n"
"    This function creates an oaPath object with the given attributes. The specified pointArray is checked to verify that there are at least two points and no collinear or coincident points. The begin or end extension arguments must be both zero if the style is not variable.\n"
"    block\n"
"    The block in which the oaPath is created\n"
"    layerNum\n"
"    The number of the layer on which the oaPath is created\n"
"    purposeNum\n"
"    The number of the layer purpose for the oaPath\n"
"    width\n"
"    The oaPath width\n"
"    points\n"
"    The array of points for the oaPath\n"
"    style\n"
"    An enum value that defines the oaPath style\n"
"    beginExt\n"
"    The beginning extension of the oaPath; this value must be 0 (zero) for styles other than oacVariablePathStyle\n"
"    endExt\n"
"    The ending extension of the oaPath; this value must be 0 (zero) for styles other than oacVariablePathStyle\n"
"    oacPathTooFewPoints\n"
"    oacPathHasExtraPoints\n"
"    oacInvalidPathExtensionValue\n"
"  Paramegers: (oaBlock,oaLayerNum,oaPurposeNum,oaDist,oaPointArray,oaPathStyle)\n"
"    Calls: oaPath* create(oaBlock* block,oaLayerNum layerNum,oaPurposeNum purposeNum,oaDist width,const oaPointArray& points,oaPathStyle style)\n"
"    Signature: create|ptr-oaPath|ptr-oaBlock,simple-oaLayerNum,simple-oaPurposeNum,simple-oaDist,cref-oaPointArray,simple-oaPathStyle,simple-oaDist,simple-oaDist,\n"
"    This function creates an oaPath object with the given attributes. The specified pointArray is checked to verify that there are at least two points and no collinear or coincident points. The begin or end extension arguments must be both zero if the style is not variable.\n"
"    block\n"
"    The block in which the oaPath is created\n"
"    layerNum\n"
"    The number of the layer on which the oaPath is created\n"
"    purposeNum\n"
"    The number of the layer purpose for the oaPath\n"
"    width\n"
"    The oaPath width\n"
"    points\n"
"    The array of points for the oaPath\n"
"    style\n"
"    An enum value that defines the oaPath style\n"
"    beginExt\n"
"    The beginning extension of the oaPath; this value must be 0 (zero) for styles other than oacVariablePathStyle\n"
"    endExt\n"
"    The ending extension of the oaPath; this value must be 0 (zero) for styles other than oacVariablePathStyle\n"
"    oacPathTooFewPoints\n"
"    oacPathHasExtraPoints\n"
"    oacInvalidPathExtensionValue\n"
"  Paramegers: (oaBlock,oaLayerNum,oaPurposeNum,oaDist,oaPointArray,oaPathStyle,oaDist)\n"
"    Calls: oaPath* create(oaBlock* block,oaLayerNum layerNum,oaPurposeNum purposeNum,oaDist width,const oaPointArray& points,oaPathStyle style,oaDist beginExt)\n"
"    Signature: create|ptr-oaPath|ptr-oaBlock,simple-oaLayerNum,simple-oaPurposeNum,simple-oaDist,cref-oaPointArray,simple-oaPathStyle,simple-oaDist,simple-oaDist,\n"
"    This function creates an oaPath object with the given attributes. The specified pointArray is checked to verify that there are at least two points and no collinear or coincident points. The begin or end extension arguments must be both zero if the style is not variable.\n"
"    block\n"
"    The block in which the oaPath is created\n"
"    layerNum\n"
"    The number of the layer on which the oaPath is created\n"
"    purposeNum\n"
"    The number of the layer purpose for the oaPath\n"
"    width\n"
"    The oaPath width\n"
"    points\n"
"    The array of points for the oaPath\n"
"    style\n"
"    An enum value that defines the oaPath style\n"
"    beginExt\n"
"    The beginning extension of the oaPath; this value must be 0 (zero) for styles other than oacVariablePathStyle\n"
"    endExt\n"
"    The ending extension of the oaPath; this value must be 0 (zero) for styles other than oacVariablePathStyle\n"
"    oacPathTooFewPoints\n"
"    oacPathHasExtraPoints\n"
"    oacInvalidPathExtensionValue\n"
"  Paramegers: (oaBlock,oaLayerNum,oaPurposeNum,oaDist,oaPointArray,oaPathStyle,oaDist,oaDist)\n"
"    Calls: oaPath* create(oaBlock* block,oaLayerNum layerNum,oaPurposeNum purposeNum,oaDist width,const oaPointArray& points,oaPathStyle style,oaDist beginExt,oaDist endExt)\n"
"    Signature: create|ptr-oaPath|ptr-oaBlock,simple-oaLayerNum,simple-oaPurposeNum,simple-oaDist,cref-oaPointArray,simple-oaPathStyle,simple-oaDist,simple-oaDist,\n"
"    This function creates an oaPath object with the given attributes. The specified pointArray is checked to verify that there are at least two points and no collinear or coincident points. The begin or end extension arguments must be both zero if the style is not variable.\n"
"    block\n"
"    The block in which the oaPath is created\n"
"    layerNum\n"
"    The number of the layer on which the oaPath is created\n"
"    purposeNum\n"
"    The number of the layer purpose for the oaPath\n"
"    width\n"
"    The oaPath width\n"
"    points\n"
"    The array of points for the oaPath\n"
"    style\n"
"    An enum value that defines the oaPath style\n"
"    beginExt\n"
"    The beginning extension of the oaPath; this value must be 0 (zero) for styles other than oacVariablePathStyle\n"
"    endExt\n"
"    The ending extension of the oaPath; this value must be 0 (zero) for styles other than oacVariablePathStyle\n"
"    oacPathTooFewPoints\n"
"    oacPathHasExtraPoints\n"
"    oacInvalidPathExtensionValue\n"
;

static PyObject*
oaPath_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaBlock,oaLayerNum,oaPurposeNum,oaDist,oaPointArray)
    {
        PyParamoaBlock p1;
        PyParamoaLayerNum p2;
        PyParamoaPurposeNum p3;
        PyParamoaDist p4;
        PyParamoaPointArray p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaPurposeNum_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaPointArray_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPathp result= (oaPath::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaPath_FromoaPath(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaLayerNum,oaPurposeNum,oaDist,oaPointArray,oaPathStyle)
    {
        PyParamoaBlock p1;
        PyParamoaLayerNum p2;
        PyParamoaPurposeNum p3;
        PyParamoaDist p4;
        PyParamoaPointArray p5;
        PyParamoaPathStyle p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaPurposeNum_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaPointArray_Convert,&p5,
              &PyoaPathStyle_Convert,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPathp result= (oaPath::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data()));
            return PyoaPath_FromoaPath(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaLayerNum,oaPurposeNum,oaDist,oaPointArray,oaPathStyle,oaDist)
    {
        PyParamoaBlock p1;
        PyParamoaLayerNum p2;
        PyParamoaPurposeNum p3;
        PyParamoaDist p4;
        PyParamoaPointArray p5;
        PyParamoaPathStyle p6;
        PyParamoaDist p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaPurposeNum_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaPointArray_Convert,&p5,
              &PyoaPathStyle_Convert,&p6,
              &PyoaDist_Convert,&p7)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPathp result= (oaPath::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data()));
            return PyoaPath_FromoaPath(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaLayerNum,oaPurposeNum,oaDist,oaPointArray,oaPathStyle,oaDist,oaDist)
    {
        PyParamoaBlock p1;
        PyParamoaLayerNum p2;
        PyParamoaPurposeNum p3;
        PyParamoaDist p4;
        PyParamoaPointArray p5;
        PyParamoaPathStyle p6;
        PyParamoaDist p7;
        PyParamoaDist p8;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaPurposeNum_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaPointArray_Convert,&p5,
              &PyoaPathStyle_Convert,&p6,
              &PyoaDist_Convert,&p7,
              &PyoaDist_Convert,&p8)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPathp result= (oaPath::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data()));
            return PyoaPath_FromoaPath(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaPath, function: create, Choices are:\n"
        "    (oaBlock,oaLayerNum,oaPurposeNum,oaDist,oaPointArray)\n"
        "    (oaBlock,oaLayerNum,oaPurposeNum,oaDist,oaPointArray,oaPathStyle)\n"
        "    (oaBlock,oaLayerNum,oaPurposeNum,oaDist,oaPointArray,oaPathStyle,oaDist)\n"
        "    (oaBlock,oaLayerNum,oaPurposeNum,oaDist,oaPointArray,oaPathStyle,oaDist,oaDist)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPath_static_genBoundary_doc[] = 
"Class: oaPath, Function: genBoundary\n"
"  Paramegers: (oaPointArray,oaDist,oaPathStyle,oaDist,oaDist,oaPointArray)\n"
"    Calls: void genBoundary(const oaPointArray& points,oaDist width,oaPathStyle style,oaDist beginExt,oaDist endExt,oaPointArray& boundary)\n"
"    Signature: genBoundary|void-void|cref-oaPointArray,simple-oaDist,simple-oaPathStyle,simple-oaDist,simple-oaDist,ref-oaPointArray,\n"
"    This function constructs a boundary with the polygonal outline of the path using the specified parameters. This function is useful for determining what a path overlaps before the path is actually created. Another common use is to render the outline of a path before the path is created.\n"
"    points\n"
"    The points that define the centerline of the oaPath\n"
"    width\n"
"    The oaPath width\n"
"    style\n"
"    The oaPath style (an enum value between zero and four)\n"
"    beginExt\n"
"    The beginning extension of the oaPath\n"
"    endExt\n"
"    The ending extension of the oaPath\n"
"    boundary\n"
"    The generated boundary point array\n"
"    oacPathTooFewPoints\n"
"    getBoundary()\n"
;

static PyObject*
oaPath_static_genBoundary(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPointArray p1;
    PyParamoaDist p2;
    PyParamoaPathStyle p3;
    PyParamoaDist p4;
    PyParamoaDist p5;
    PyParamoaPointArray p6;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
          &PyoaPointArray_Convert,&p1,
          &PyoaDist_Convert,&p2,
          &PyoaPathStyle_Convert,&p3,
          &PyoaDist_Convert,&p4,
          &PyoaDist_Convert,&p5,
          &PyoaPointArray_Convert,&p6)) {
        oaPath::genBoundary(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data());
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
static PyMethodDef oaPath_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaPath_static_create,METH_VARARGS,oaPath_static_create_doc},
    {"static_genBoundary",(PyCFunction)oaPath_static_genBoundary,METH_VARARGS,oaPath_static_genBoundary_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPath_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPath_Type)<0) {
      printf("** PyType_Ready failed for: oaPath\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPath",
           (PyObject*)(&PyoaPath_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPath\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaPath_Type.tp_dict;
    for(method=oaPath_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaPathSeg
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPathSeg_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPathSeg_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPathSegObject* self = (PyoaPathSegObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaPathSeg)
    {
        PyParamoaPathSeg p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPathSeg_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaPathSeg, Choices are:\n"
        "    (oaPathSeg)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPathSeg_tp_dealloc(PyoaPathSegObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPathSeg_tp_repr(PyObject *ob)
{
    PyParamoaPathSeg value;
    int convert_status=PyoaPathSeg_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[31];
    sprintf(buffer,"<oaPathSeg::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaPathSeg_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPathSeg v1;
    PyParamoaPathSeg v2;
    int convert_status1=PyoaPathSeg_Convert(ob1,&v1);
    int convert_status2=PyoaPathSeg_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPathSeg_Convert(PyObject* ob,PyParamoaPathSeg* result)
{
    if (ob == NULL) return 1;
    if (PyoaPathSeg_Check(ob)) {
        result->SetData( (oaPathSeg**) ((PyoaPathSegObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPathSeg Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPathSeg_FromoaPathSeg(oaPathSeg** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaPathSeg* data=*value;
        PyObject* bself = PyoaPathSeg_Type.tp_alloc(&PyoaPathSeg_Type,0);
        if (bself == NULL) return bself;
        PyoaPathSegObject* self = (PyoaPathSegObject*)bself;
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
PyObject* PyoaPathSeg_FromoaPathSeg(oaPathSeg* data)
{
    if (data) {
       PyObject* bself = PyoaPathSeg_Type.tp_alloc(&PyoaPathSeg_Type,0);
       if (bself == NULL) return bself;
       PyoaPathSegObject* self = (PyoaPathSegObject*)bself;
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
static char oaPathSeg_getBoundary_doc[] = 
"Class: oaPathSeg, Function: getBoundary\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void getBoundary(oaPointArray& boundary) const\n"
"    Signature: getBoundary|void-void|ref-oaPointArray,\n"
"    BrowseData: 0,oaPointArray\n"
"    This function constructs a boundary with the polygonal outline of the pathSeg. This function is useful for overlap checks with the pathSeg, and to render what the pathSeg looks like.\n"
"    boundary\n"
"    The generated boundary point array\n"
;

static PyObject*
oaPathSeg_getBoundary(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPathSeg data;
    int convert_status=PyoaPathSeg_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathSegObject* self=(PyoaPathSegObject*)ob;
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
static char oaPathSeg_getPoints_doc[] = 
"Class: oaPathSeg, Function: getPoints\n"
"  Paramegers: (oaPoint,oaPoint)\n"
"    Calls: void getPoints(oaPoint& beginPoint,oaPoint& endPoint) const\n"
"    Signature: getPoints|void-void|ref-oaPoint,ref-oaPoint,\n"
"    BrowseData: 0,oaPoint,oaPoint\n"
"    This function gets the begin and end points of an oaPathSeg object. The two points specify the centerline of the oaPathSeg.\n"
"    beginPoint\n"
"    The beginning point of the oaPathSeg\n"
"    endPoint\n"
"    The ending point of the oaPathSeg\n"
;

static PyObject*
oaPathSeg_getPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPathSeg data;
    int convert_status=PyoaPathSeg_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathSegObject* self=(PyoaPathSegObject*)ob;
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
static char oaPathSeg_getRoute_doc[] = 
"Class: oaPathSeg, Function: getRoute\n"
"  Paramegers: ()\n"
"    Calls: oaRoute* getRoute() const\n"
"    Signature: getRoute|ptr-oaRoute|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the route to which this pathSeg may belong. A NULL is returned if this pathSeg is not part of a route.\n"
;

static PyObject*
oaPathSeg_getRoute(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPathSeg data;
    int convert_status=PyoaPathSeg_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathSegObject* self=(PyoaPathSegObject*)ob;
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
static char oaPathSeg_getRouteTopology_doc[] = 
"Class: oaPathSeg, Function: getRouteTopology\n"
"  Paramegers: ()\n"
"    Calls: oaRouteTopology getRouteTopology() const\n"
"    Signature: getRouteTopology|simple-oaRouteTopology|\n"
"    BrowseData: 1\n"
"    This function returns the current routing topology of this pathSeg.\n"
;

static PyObject*
oaPathSeg_getRouteTopology(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPathSeg data;
    int convert_status=PyoaPathSeg_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathSegObject* self=(PyoaPathSegObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaRouteTopology* result= new oaRouteTopology(data.DataCall()->getRouteTopology());
        return PyoaRouteTopology_FromoaRouteTopology(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPathSeg_getStyle_doc[] = 
"Class: oaPathSeg, Function: getStyle\n"
"  Paramegers: (oaSegStyle)\n"
"    Calls: void getStyle(oaSegStyle& style) const\n"
"    Signature: getStyle|void-void|ref-oaSegStyle,\n"
"    BrowseData: 0,oaSegStyle\n"
"    This function populates 'style' with the segStyle of this pathSeg.\n"
"    style\n"
"    A reference to an oaSegStyle object to be populated\n"
;

static PyObject*
oaPathSeg_getStyle(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPathSeg data;
    int convert_status=PyoaPathSeg_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathSegObject* self=(PyoaPathSegObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaSegStyle p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSegStyle_Convert,&p1)) {
        data.DataCall()->getStyle(p1.Data());
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
static char oaPathSeg_hasRoute_doc[] = 
"Class: oaPathSeg, Function: hasRoute\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasRoute() const\n"
"    Signature: hasRoute|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if this pathSeg is part of a route; otherwise it returns false.\n"
;

static PyObject*
oaPathSeg_hasRoute(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPathSeg data;
    int convert_status=PyoaPathSeg_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathSegObject* self=(PyoaPathSegObject*)ob;
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
static char oaPathSeg_isOrthogonal_doc[] = 
"Class: oaPathSeg, Function: isOrthogonal\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isOrthogonal() const\n"
"    Signature: isOrthogonal|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if the points for the oaPathSeg are orthogonal.\n"
;

static PyObject*
oaPathSeg_isOrthogonal(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPathSeg data;
    int convert_status=PyoaPathSeg_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathSegObject* self=(PyoaPathSegObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isOrthogonal());
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
static char oaPathSeg_setPoints_doc[] = 
"Class: oaPathSeg, Function: setPoints\n"
"  Paramegers: (oaPoint,oaPoint)\n"
"    Calls: void setPoints(const oaPoint& beginPoint,const oaPoint& endPoint)\n"
"    Signature: setPoints|void-void|cref-oaPoint,cref-oaPoint,\n"
"    This function sets the beginning and ending points of the oaPathSeg to the specified points. The two points are checked to verify that the length of the segment is greater than zero and that the oaPathSeg remains horizontal, vertical, or diagonal.\n"
"    beginPoint\n"
"    The beginning point for the oaPathSeg\n"
"    endPoint\n"
"    The ending point for the oaPathSeg\n"
"    oacInvalidPathSegPoints\n"
;

static PyObject*
oaPathSeg_setPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPathSeg data;
    int convert_status=PyoaPathSeg_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathSegObject* self=(PyoaPathSegObject*)ob;
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
static char oaPathSeg_setRouteTopology_doc[] = 
"Class: oaPathSeg, Function: setRouteTopology\n"
"  Paramegers: (oaRouteTopology)\n"
"    Calls: void setRouteTopology(const oaRouteTopology& topology)\n"
"    Signature: setRouteTopology|void-void|cref-oaRouteTopology,\n"
"    oaPathSeg::setRouteTopology\n"
"    This function sets the routeTopology of this pathSeg to the specified topology.\n"
"    topology\n"
"    An oaRouteTopology object used to update this pathSeg\n"
;

static PyObject*
oaPathSeg_setRouteTopology(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPathSeg data;
    int convert_status=PyoaPathSeg_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathSegObject* self=(PyoaPathSegObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaRouteTopology p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRouteTopology_Convert,&p1)) {
        data.DataCall()->setRouteTopology(p1.Data());
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
static char oaPathSeg_setStyle_doc[] = 
"Class: oaPathSeg, Function: setStyle\n"
"  Paramegers: (oaSegStyle)\n"
"    Calls: void setStyle(const oaSegStyle& style)\n"
"    Signature: setStyle|void-void|cref-oaSegStyle,\n"
"    This function sets the segStyle of this pathSeg to the specified value. This style will determine the size and shape of the extension at each end of the segment (see oaSegStyle ).\n"
"    style\n"
"    The oaSegStyle object used to update this pathSeg\n"
;

static PyObject*
oaPathSeg_setStyle(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPathSeg data;
    int convert_status=PyoaPathSeg_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathSegObject* self=(PyoaPathSegObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaSegStyle p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSegStyle_Convert,&p1)) {
        data.DataCall()->setStyle(p1.Data());
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
static char oaPathSeg_isNull_doc[] =
"Class: oaPathSeg, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaPathSeg_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaPathSeg data;
    int convert_status=PyoaPathSeg_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaPathSeg_assign_doc[] = 
"Class: oaPathSeg, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPathSeg_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPathSeg data;
  int convert_status=PyoaPathSeg_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPathSeg p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPathSeg_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPathSeg_methodlist[] = {
    {"getBoundary",(PyCFunction)oaPathSeg_getBoundary,METH_VARARGS,oaPathSeg_getBoundary_doc},
    {"getPoints",(PyCFunction)oaPathSeg_getPoints,METH_VARARGS,oaPathSeg_getPoints_doc},
    {"getRoute",(PyCFunction)oaPathSeg_getRoute,METH_VARARGS,oaPathSeg_getRoute_doc},
    {"getRouteTopology",(PyCFunction)oaPathSeg_getRouteTopology,METH_VARARGS,oaPathSeg_getRouteTopology_doc},
    {"getStyle",(PyCFunction)oaPathSeg_getStyle,METH_VARARGS,oaPathSeg_getStyle_doc},
    {"hasRoute",(PyCFunction)oaPathSeg_hasRoute,METH_VARARGS,oaPathSeg_hasRoute_doc},
    {"isOrthogonal",(PyCFunction)oaPathSeg_isOrthogonal,METH_VARARGS,oaPathSeg_isOrthogonal_doc},
    {"setPoints",(PyCFunction)oaPathSeg_setPoints,METH_VARARGS,oaPathSeg_setPoints_doc},
    {"setRouteTopology",(PyCFunction)oaPathSeg_setRouteTopology,METH_VARARGS,oaPathSeg_setRouteTopology_doc},
    {"setStyle",(PyCFunction)oaPathSeg_setStyle,METH_VARARGS,oaPathSeg_setStyle_doc},
    {"isNull",(PyCFunction)oaPathSeg_tp_isNull,METH_VARARGS,oaPathSeg_isNull_doc},
    {"assign",(PyCFunction)oaPathSeg_tp_assign,METH_VARARGS,oaPathSeg_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPathSeg_doc[] = 
"Class: oaPathSeg\n"
"  The oaPathSeg class is a specialization of the oaShape class and is used to realize physical routing segments that can either be orthogonal or diagonal. oaPathSeg objects can be used stand-alone or they can be made a component of an oaRoute object. The former case represents the geometric routing case while the latter represents symbolic routing.\n"
"Constructors:\n"
"  Paramegers: (oaPathSeg)\n"
"    Calls: (const oaPathSeg&)\n"
"    Signature: oaPathSeg||cref-oaPathSeg,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPathSeg_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPathSeg",
    sizeof(PyoaPathSegObject),
    0,
    (destructor)oaPathSeg_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPathSeg_tp_compare,	/* tp_compare */
    (reprfunc)oaPathSeg_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPathSeg_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPathSeg_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaShape_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPathSeg_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPathSeg_static_create_doc[] = 
"Class: oaPathSeg, Function: create\n"
"  Paramegers: (oaBlock,oaLayerNum,oaPurposeNum,oaPoint,oaPoint,oaSegStyle)\n"
"    Calls: oaPathSeg* create(oaBlock* block,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& beginPoint,const oaPoint& endPoint,const oaSegStyle& style)\n"
"    Signature: create|ptr-oaPathSeg|ptr-oaBlock,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,cref-oaPoint,cref-oaSegStyle,\n"
"    This function creates an oaPathSeg object with the given attributes. The specified begin and end points are checked to verify that the segment will be horizontal, vertical, or diagonal and that the length of the segment will be greater than zero.\n"
"    block\n"
"    The block in which the oaPathSeg is created\n"
"    layerNum\n"
"    The number of the layer on which the oaPathSeg is created\n"
"    purposeNum\n"
"    The number of the layer purpose for the oaPathSeg\n"
"    beginPoint\n"
"    The beginning point for the oaPathSeg\n"
"    endPoint\n"
"    The ending point for the oaPathSeg\n"
"    style\n"
"    A reference to an oaSegStyle object that defines the style for the segment\n"
"    oacInvalidPathSegPoints\n"
;

static PyObject*
oaPathSeg_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBlock p1;
    PyParamoaLayerNum p2;
    PyParamoaPurposeNum p3;
    PyParamoaPoint p4;
    PyParamoaPoint p5;
    PyParamoaSegStyle p6;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
          &PyoaBlock_Convert,&p1,
          &PyoaLayerNum_Convert,&p2,
          &PyoaPurposeNum_Convert,&p3,
          &PyoaPoint_Convert,&p4,
          &PyoaPoint_Convert,&p5,
          &PyoaSegStyle_Convert,&p6)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaPathSegp result= (oaPathSeg::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data()));
        return PyoaPathSeg_FromoaPathSeg(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPathSeg_static_genBoundary_doc[] = 
"Class: oaPathSeg, Function: genBoundary\n"
"  Paramegers: (oaPoint,oaPoint,oaSegStyle,oaPointArray)\n"
"    Calls: void genBoundary(const oaPoint& beginPoint,const oaPoint& endPoint,const oaSegStyle& style,oaPointArray& boundary)\n"
"    Signature: genBoundary|void-void|cref-oaPoint,cref-oaPoint,cref-oaSegStyle,ref-oaPointArray,\n"
"    This function fills out boundary with the boundary polygon of a virtual pathSeg that could be realized with the specified attributes without having to create an actual pathSeg object.\n"
"    beginPoint\n"
"    The begin point for the virtual pathSeg\n"
"    endPoint\n"
"    The end point for the virtual pathSeg\n"
"    style\n"
"    The segStyle to use for the virtual pathSeg\n"
"    boundary\n"
"    The point array that will get populated with the boundary points\n"
"    oacInvalidPathSegPoints\n"
;

static PyObject*
oaPathSeg_static_genBoundary(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPoint p1;
    PyParamoaPoint p2;
    PyParamoaSegStyle p3;
    PyParamoaPointArray p4;
    if (PyArg_ParseTuple(args,"O&O&O&O&",
          &PyoaPoint_Convert,&p1,
          &PyoaPoint_Convert,&p2,
          &PyoaSegStyle_Convert,&p3,
          &PyoaPointArray_Convert,&p4)) {
        oaPathSeg::genBoundary(p1.Data(),p2.Data(),p3.Data(),p4.Data());
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
static PyMethodDef oaPathSeg_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaPathSeg_static_create,METH_VARARGS,oaPathSeg_static_create_doc},
    {"static_genBoundary",(PyCFunction)oaPathSeg_static_genBoundary,METH_VARARGS,oaPathSeg_static_genBoundary_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPathSeg_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPathSeg_Type)<0) {
      printf("** PyType_Ready failed for: oaPathSeg\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPathSeg",
           (PyObject*)(&PyoaPathSeg_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPathSeg\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaPathSeg_Type.tp_dict;
    for(method=oaPathSeg_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaPathStyle
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPathStyle_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPathStyle_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPathStyleObject* self = (PyoaPathStyleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaPathStyleEnum)
    {
        PyParamoaPathStyleEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaPathStyleEnum_Convert,&p1)) {
            self->value =  new oaPathStyle(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaPathStyle(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaPathStyle)
    {
        PyParamoaPathStyle p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPathStyle_Convert,&p1)) {
            self->value= new oaPathStyle(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaPathStyle, Choices are:\n"
        "    (oaPathStyleEnum)\n"
        "    (oaString)\n"
        "    (oaPathStyle)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPathStyle_tp_dealloc(PyoaPathStyleObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPathStyle_tp_repr(PyObject *ob)
{
    PyParamoaPathStyle value;
    int convert_status=PyoaPathStyle_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[33];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaPathStyle::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaPathStyle_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPathStyle v1;
    PyParamoaPathStyle v2;
    int convert_status1=PyoaPathStyle_Convert(ob1,&v1);
    int convert_status2=PyoaPathStyle_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPathStyle_Convert(PyObject* ob,PyParamoaPathStyle* result)
{
    if (ob == NULL) return 1;
    if (PyoaPathStyle_Check(ob)) {
        result->SetData(  ((PyoaPathStyleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPathStyle Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPathStyle_FromoaPathStyle(oaPathStyle* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaPathStyle_Type.tp_alloc(&PyoaPathStyle_Type,0);
        if (bself == NULL) return bself;
        PyoaPathStyleObject* self = (PyoaPathStyleObject*)bself;
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
static char oaPathStyle_getName_doc[] = 
"Class: oaPathStyle, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaPathStyleEnum object.\n"
;

static PyObject*
oaPathStyle_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPathStyle data;
    int convert_status=PyoaPathStyle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathStyleObject* self=(PyoaPathStyleObject*)ob;

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
static char oaPathStyle_oaPathStyleEnum_doc[] = 
"Class: oaPathStyle, Function: oaPathStyleEnum\n"
"  Paramegers: ()\n"
"    Calls: oaPathStyleEnum oaPathStyleEnum() const\n"
"    Signature: operator oaPathStyleEnum|simple-oaPathStyleEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaPathStyle object into the corresponding #oaPathStyleEnum value.\n"
;

static PyObject*
oaPathStyle_oaPathStyleEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPathStyle data;
    int convert_status=PyoaPathStyle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPathStyleObject* self=(PyoaPathStyleObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPathStyleEnum result= (data.DataCall()->operator oaPathStyleEnum());
        return PyoaPathStyleEnum_FromoaPathStyleEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaPathStyle_assign_doc[] = 
"Class: oaPathStyle, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPathStyle_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPathStyle data;
  int convert_status=PyoaPathStyle_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPathStyle p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPathStyle_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPathStyle_methodlist[] = {
    {"getName",(PyCFunction)oaPathStyle_getName,METH_VARARGS,oaPathStyle_getName_doc},
    {"oaPathStyleEnum",(PyCFunction)oaPathStyle_oaPathStyleEnum,METH_VARARGS,oaPathStyle_oaPathStyleEnum_doc},
    {"assign",(PyCFunction)oaPathStyle_tp_assign,METH_VARARGS,oaPathStyle_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPathStyle_doc[] = 
"Class: oaPathStyle\n"
"  The oaPathStyle class is an enum wrapper class that describes the various end point styles of oaPath objects.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaPathStyleEnum\n"
"Constructors:\n"
"  Paramegers: (oaPathStyleEnum)\n"
"    Calls: oaPathStyle(oaPathStyleEnum valueIn)\n"
"    Signature: oaPathStyle||simple-oaPathStyleEnum,\n"
"    This function constructs an instance of an oaPathStyle class using the specified #oaPathStyleEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaPathStyle(const oaString& name)\n"
"    Signature: oaPathStyle||cref-oaString,\n"
"    This function constructs an instance of an oaPathStyle class using the #oaPathStyleEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaPathStyleEnum.\n"
"    oacInvalidPathStyleName\n"
"  Paramegers: (oaPathStyle)\n"
"    Calls: (const oaPathStyle&)\n"
"    Signature: oaPathStyle||cref-oaPathStyle,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPathStyle_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPathStyle",
    sizeof(PyoaPathStyleObject),
    0,
    (destructor)oaPathStyle_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPathStyle_tp_compare,	/* tp_compare */
    (reprfunc)oaPathStyle_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPathStyle_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPathStyle_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPathStyle_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPathStyle_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPathStyle_Type)<0) {
      printf("** PyType_Ready failed for: oaPathStyle\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPathStyle",
           (PyObject*)(&PyoaPathStyle_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPathStyle\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaPathStyleEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaPathStyleEnum_Convert(PyObject* ob,PyParamoaPathStyleEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacTruncatePathStyle")==0) { result->SetData(oacTruncatePathStyle); return 1;}
        if (strcasecmp(str,"oacExtendPathStyle")==0) { result->SetData(oacExtendPathStyle); return 1;}
        if (strcasecmp(str,"oacRoundPathStyle")==0) { result->SetData(oacRoundPathStyle); return 1;}
        if (strcasecmp(str,"oacVariablePathStyle")==0) { result->SetData(oacVariablePathStyle); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaPathStyleEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPathStyleEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaPathStyleEnum_FromoaPathStyleEnum(oaPathStyleEnum ob)
{
    if (ob==oacTruncatePathStyle) return PyString_FromString("oacTruncatePathStyle");
    if (ob==oacExtendPathStyle) return PyString_FromString("oacExtendPathStyle");
    if (ob==oacRoundPathStyle) return PyString_FromString("oacRoundPathStyle");
    if (ob==oacVariablePathStyle) return PyString_FromString("oacVariablePathStyle");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaPathStyleEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaPathStyleEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaPathStyleEnum_FromoaPathStyleEnum(oaPathStyleEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaPathStyleEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaPathStyleEnum_doc[] =
"Type convert function for enum: oaPathStyleEnum";
                               
static PyMethodDef PyoaPathStyleEnum_method =
  {"oaPathStyleEnum",(PyCFunction)PyoaPathStyleEnum_TypeFunction,METH_VARARGS,oaPathStyleEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaPathStyleEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacTruncatePathStyle");
    PyDict_SetItemString(mod_dict,"oacTruncatePathStyle",value);
    Py_DECREF(value);
    value=PyString_FromString("oacExtendPathStyle");
    PyDict_SetItemString(mod_dict,"oacExtendPathStyle",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRoundPathStyle");
    PyDict_SetItemString(mod_dict,"oacRoundPathStyle",value);
    Py_DECREF(value);
    value=PyString_FromString("oacVariablePathStyle");
    PyDict_SetItemString(mod_dict,"oacVariablePathStyle",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaPathStyleEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaPathStyleEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaPathStyleEnum\n");
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
// Wrapper Implementation for Class: oaPcellDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPcellDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPcellDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPcellDefObject* self = (PyoaPcellDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaPcellDef, Choices are:\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPcellDef_tp_dealloc(PyoaPcellDefObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPcellDef_tp_repr(PyObject *ob)
{
    PyParamoaPcellDef value;
    int convert_status=PyoaPcellDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[32];
    sprintf(buffer,"<oaPcellDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaPcellDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPcellDef v1;
    PyParamoaPcellDef v2;
    int convert_status1=PyoaPcellDef_Convert(ob1,&v1);
    int convert_status2=PyoaPcellDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPcellDef_Convert(PyObject* ob,PyParamoaPcellDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaPcellDef_Check(ob)) {
        result->SetData(  ((PyoaPcellDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPcellDef Failed");
    return 0;
}
int
PyoaPcellDef_ConvertAof(PyObject* ob,PyParamoaPcellDef* result)
{
    if (ob == NULL) return 1;
    if (ob==Py_None) {
        result->SetData(NULL);
        return 1;
    }
    if (PyoaPcellDef_Check(ob)) {
        result->SetData(  ((PyoaPcellDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPcellDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPcellDef_FromoaPcellDef(oaPcellDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaPcellDef_Type.tp_alloc(&PyoaPcellDef_Type,0);
        if (bself == NULL) return bself;
        PyoaPcellDefObject* self = (PyoaPcellDefObject*)bself;
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
static char oaPcellDef_addData_doc[] = 
"Class: oaPcellDef, Function: addData\n"
"  Paramegers: (oaString,oaString)\n"
"    Calls: oaBoolean addData(const oaString& name,const oaString& value)\n"
"    Signature: addData|simple-oaBoolean|cref-oaString,cref-oaString,\n"
"    This function adds an entry into the name/value pair string table. If an entry with the specified name already in the table, false is returned.\n"
"    name\n"
"    the name of the entry\n"
"    value\n"
"    the value of the entry\n"
;

static PyObject*
oaPcellDef_addData(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPcellDef data;
    int convert_status=PyoaPcellDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPcellDefObject* self=(PyoaPcellDefObject*)ob;

    PyParamoaString p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaString_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        oaBoolean result= (data.DataCall()->addData(p1.Data(),p2.Data()));
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
static char oaPcellDef_getDataValue_doc[] = 
"Class: oaPcellDef, Function: getDataValue\n"
"  Paramegers: (oaString,oaString)\n"
"    Calls: oaBoolean getDataValue(const oaString& name,oaString& value)\n"
"    Signature: getDataValue|simple-oaBoolean|cref-oaString,ref-oaString,\n"
"    This function retrieve the value of an entry in the name/value pair string table. If the entry with the specified name is not found in the table, false is returned.\n"
"    name\n"
"    the name of the entry that its value is being retrieve.\n"
"    value\n"
"    the value of the entry if found.\n"
;

static PyObject*
oaPcellDef_getDataValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPcellDef data;
    int convert_status=PyoaPcellDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPcellDefObject* self=(PyoaPcellDefObject*)ob;

    PyParamoaString p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaString_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        oaBoolean result= (data.DataCall()->getDataValue(p1.Data(),p2.Data()));
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
static char oaPcellDef_removeData_doc[] = 
"Class: oaPcellDef, Function: removeData\n"
"  Paramegers: (oaString)\n"
"    Calls: oaBoolean removeData(const oaString& name)\n"
"    Signature: removeData|simple-oaBoolean|cref-oaString,\n"
"    This function removes an entry from the name/value pair string table. If\n"
"    name\n"
"    the name of the entry\n"
;

static PyObject*
oaPcellDef_removeData(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPcellDef data;
    int convert_status=PyoaPcellDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPcellDefObject* self=(PyoaPcellDefObject*)ob;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        oaBoolean result= (data.DataCall()->removeData(p1.Data()));
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
static char oaPcellDef_setDataValue_doc[] = 
"Class: oaPcellDef, Function: setDataValue\n"
"  Paramegers: (oaString,oaString)\n"
"    Calls: oaBoolean setDataValue(const oaString& name,const oaString& value)\n"
"    Signature: setDataValue|simple-oaBoolean|cref-oaString,cref-oaString,\n"
"    This function sets the entry with specified name with the specificed value in the name/value pair string table. If the entry with the specified name is not found in the string table, false is returned.\n"
"    name\n"
"    the name of the entry that its value is being set.\n"
"    value\n"
"    the new value of the entry\n"
;

static PyObject*
oaPcellDef_setDataValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPcellDef data;
    int convert_status=PyoaPcellDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPcellDefObject* self=(PyoaPcellDefObject*)ob;

    PyParamoaString p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaString_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        oaBoolean result= (data.DataCall()->setDataValue(p1.Data(),p2.Data()));
        return PyoaBoolean_FromoaBoolean(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaPcellDef_assign_doc[] = 
"Class: oaPcellDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPcellDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPcellDef data;
  int convert_status=PyoaPcellDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPcellDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPcellDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPcellDef_methodlist[] = {
    {"addData",(PyCFunction)oaPcellDef_addData,METH_VARARGS,oaPcellDef_addData_doc},
    {"getDataValue",(PyCFunction)oaPcellDef_getDataValue,METH_VARARGS,oaPcellDef_getDataValue_doc},
    {"removeData",(PyCFunction)oaPcellDef_removeData,METH_VARARGS,oaPcellDef_removeData_doc},
    {"setDataValue",(PyCFunction)oaPcellDef_setDataValue,METH_VARARGS,oaPcellDef_setDataValue_doc},
    {"assign",(PyCFunction)oaPcellDef_tp_assign,METH_VARARGS,oaPcellDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPcellDef_doc[] = 
"Class: oaPcellDef\n"
"  An oaPcellDef is a base class used to convey the binding from a pCell to the code that handles its evaluation. It is used by oaDesign::defineSuperMaster() to turn an oaDesign into a SuperMaster and can be returned from that SuperMaster with oaDesign::getPcellDef() . The PcellDef refers to an IPcell that has an oaPcellLink in OpenAccess. This class also provides a name/value pair string table for application to use for storing user data.\n"
"Constructors:\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPcellDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPcellDef",
    sizeof(PyoaPcellDefObject),
    0,
    (destructor)oaPcellDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPcellDef_tp_compare,	/* tp_compare */
    (reprfunc)oaPcellDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPcellDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPcellDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPcellDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPcellDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPcellDef_Type)<0) {
      printf("** PyType_Ready failed for: oaPcellDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPcellDef",
           (PyObject*)(&PyoaPcellDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPcellDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaPcellErrorTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaPcellErrorTypeEnum_Convert(PyObject* ob,PyParamoaPcellErrorTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacPcellBindError")==0) { result->SetData(oacPcellBindError); return 1;}
        if (strcasecmp(str,"oacPcellUnbindError")==0) { result->SetData(oacPcellUnbindError); return 1;}
        if (strcasecmp(str,"oacPcellEvalError")==0) { result->SetData(oacPcellEvalError); return 1;}
        if (strcasecmp(str,"oacPcellReadError")==0) { result->SetData(oacPcellReadError); return 1;}
        if (strcasecmp(str,"oacPcellWriteError")==0) { result->SetData(oacPcellWriteError); return 1;}
        if (strcasecmp(str,"oacPcellCalcDiskSizeError")==0) { result->SetData(oacPcellCalcDiskSizeError); return 1;}
        if (strcasecmp(str,"oacPcellPlugInError")==0) { result->SetData(oacPcellPlugInError); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaPcellErrorTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPcellErrorTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaPcellErrorTypeEnum_FromoaPcellErrorTypeEnum(oaPcellErrorTypeEnum ob)
{
    if (ob==oacPcellBindError) return PyString_FromString("oacPcellBindError");
    if (ob==oacPcellUnbindError) return PyString_FromString("oacPcellUnbindError");
    if (ob==oacPcellEvalError) return PyString_FromString("oacPcellEvalError");
    if (ob==oacPcellReadError) return PyString_FromString("oacPcellReadError");
    if (ob==oacPcellWriteError) return PyString_FromString("oacPcellWriteError");
    if (ob==oacPcellCalcDiskSizeError) return PyString_FromString("oacPcellCalcDiskSizeError");
    if (ob==oacPcellPlugInError) return PyString_FromString("oacPcellPlugInError");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaPcellErrorTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaPcellErrorTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaPcellErrorTypeEnum_FromoaPcellErrorTypeEnum(oaPcellErrorTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaPcellErrorTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaPcellErrorTypeEnum_doc[] =
"Type convert function for enum: oaPcellErrorTypeEnum";
                               
static PyMethodDef PyoaPcellErrorTypeEnum_method =
  {"oaPcellErrorTypeEnum",(PyCFunction)PyoaPcellErrorTypeEnum_TypeFunction,METH_VARARGS,oaPcellErrorTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaPcellErrorTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacPcellBindError");
    PyDict_SetItemString(mod_dict,"oacPcellBindError",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPcellUnbindError");
    PyDict_SetItemString(mod_dict,"oacPcellUnbindError",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPcellEvalError");
    PyDict_SetItemString(mod_dict,"oacPcellEvalError",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPcellReadError");
    PyDict_SetItemString(mod_dict,"oacPcellReadError",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPcellWriteError");
    PyDict_SetItemString(mod_dict,"oacPcellWriteError",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPcellCalcDiskSizeError");
    PyDict_SetItemString(mod_dict,"oacPcellCalcDiskSizeError",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPcellPlugInError");
    PyDict_SetItemString(mod_dict,"oacPcellPlugInError",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaPcellErrorTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaPcellErrorTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaPcellErrorTypeEnum\n");
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
// Wrapper Implementation for Class: oaPcellLink
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPcellLink_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPcellLink_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPcellLinkObject* self = (PyoaPcellLinkObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaPcellLink)
    {
        PyParamoaPcellLink p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPcellLink_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaPcellLink, Choices are:\n"
        "    (oaPcellLink)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPcellLink_tp_dealloc(PyoaPcellLinkObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPcellLink_tp_repr(PyObject *ob)
{
    PyParamoaPcellLink value;
    int convert_status=PyoaPcellLink_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[33];
    sprintf(buffer,"<oaPcellLink::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaPcellLink_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPcellLink v1;
    PyParamoaPcellLink v2;
    int convert_status1=PyoaPcellLink_Convert(ob1,&v1);
    int convert_status2=PyoaPcellLink_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPcellLink_Convert(PyObject* ob,PyParamoaPcellLink* result)
{
    if (ob == NULL) return 1;
    if (PyoaPcellLink_Check(ob)) {
        result->SetData(  ((PyoaPcellLinkObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPcellLink Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPcellLink_FromoaPcellLink(oaPcellLink** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaPcellLink* data=*value;
        PyObject* bself = PyoaPcellLink_Type.tp_alloc(&PyoaPcellLink_Type,0);
        if (bself == NULL) return bself;
        PyoaPcellLinkObject* self = (PyoaPcellLinkObject*)bself;
        self->value = value;
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
PyObject* PyoaPcellLink_FromoaPcellLink(oaPcellLink* data)
{
    if (data) {
       PyObject* bself = PyoaPcellLink_Type.tp_alloc(&PyoaPcellLink_Type,0);
       if (bself == NULL) return bself;
       PyoaPcellLinkObject* self = (PyoaPcellLinkObject*)bself;
       self->data = data;
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
static char oaPcellLink_destroy_doc[] = 
"Class: oaPcellLink, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys the oaPcellLink object and removes the link between OpenAccess and the application pCell.\n"
;

static PyObject*
oaPcellLink_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPcellLink data;
    int convert_status=PyoaPcellLink_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPcellLinkObject* self=(PyoaPcellLinkObject*)ob;
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
static char oaPcellLink_isNull_doc[] =
"Class: oaPcellLink, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaPcellLink_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaPcellLink data;
    int convert_status=PyoaPcellLink_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaPcellLink_assign_doc[] = 
"Class: oaPcellLink, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPcellLink_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPcellLink data;
  int convert_status=PyoaPcellLink_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPcellLink p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPcellLink_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPcellLink_methodlist[] = {
    {"destroy",(PyCFunction)oaPcellLink_destroy,METH_VARARGS,oaPcellLink_destroy_doc},
    {"isNull",(PyCFunction)oaPcellLink_tp_isNull,METH_VARARGS,oaPcellLink_isNull_doc},
    {"assign",(PyCFunction)oaPcellLink_tp_assign,METH_VARARGS,oaPcellLink_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPcellLink_doc[] = 
"Class: oaPcellLink\n"
"  The oaPcellLink class implements the link between OpenAccess and an application-provided pcell evaluator implement though the IPcell interfaces. When the pcell evaluator is provided in memory, the application needs to create the pcell link using oaPcellLink::create() to register with OpenAccess. For IPcell provided through a plug-in module, oaPcellLink::find() and oaPcellLink::getPcellDef() can be used to access the IPcell in the plug-in module.\n"
"Constructors:\n"
"  Paramegers: (oaPcellLink)\n"
"    Calls: (const oaPcellLink&)\n"
"    Signature: oaPcellLink||cref-oaPcellLink,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPcellLink_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPcellLink",
    sizeof(PyoaPcellLinkObject),
    0,
    (destructor)oaPcellLink_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPcellLink_tp_compare,	/* tp_compare */
    (reprfunc)oaPcellLink_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPcellLink_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPcellLink_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPcellLink_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPcellLink_static_find_doc[] = 
"Class: oaPcellLink, Function: find\n"
"  Paramegers: (oaString)\n"
"    Calls: oaPcellLink* find(const oaString& name)\n"
"    Signature: find|ptr-oaPcellLink|cref-oaString,\n"
"    oaPcellLink::find\n"
"    This function trys to find an existing link associated with an IPcell of the same name. If no existing link is found, one will be created by trying to load the plugIn with the same name.\n"
"    name\n"
"    name of the IPcell\n"
;

static PyObject*
oaPcellLink_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        oaPcellLinkp result= (oaPcellLink::find(p1.Data()));
        return PyoaPcellLink_FromoaPcellLink(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPcellLink_static_getPcellDef_doc[] = 
"Class: oaPcellLink, Function: getPcellDef\n"
"  Paramegers: (oaString)\n"
"    Calls: oaPcellDef* getPcellDef(const oaString& name)\n"
"    Signature: getPcellDef|ptr-oaPcellDef|cref-oaString,\n"
"    oaPcellLink::getPcellDef\n"
"    This function returns the an oaPcellDef created through the specified IPcell . It will first call oaPcellLink::find() to locate the IPcell before retrieving the oaPcellDef from the IPcell . An exception will be thrown if it cannot find the IPcell .\n"
"    name\n"
"    name of the IPcell\n"
"    oacPcellEvaluatorNotFound\n"
;

static PyObject*
oaPcellLink_static_getPcellDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        oaPcellDef* result=(oaPcellLink::getPcellDef(p1.Data()));
        if (result==NULL) {
            Py_INCREF(Py_None);
            return Py_None;
        }
        return PyoaPcellDef_FromoaPcellDef(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaPcellLink_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaPcellLink_static_find,METH_VARARGS,oaPcellLink_static_find_doc},
    {"static_getPcellDef",(PyCFunction)oaPcellLink_static_getPcellDef,METH_VARARGS,oaPcellLink_static_getPcellDef_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPcellLink_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPcellLink_Type)<0) {
      printf("** PyType_Ready failed for: oaPcellLink\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPcellLink",
           (PyObject*)(&PyoaPcellLink_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPcellLink\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaPcellLink_Type.tp_dict;
    for(method=oaPcellLink_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaPhysicalLayer
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPhysicalLayer_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPhysicalLayer_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPhysicalLayerObject* self = (PyoaPhysicalLayerObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaPhysicalLayer)
    {
        PyParamoaPhysicalLayer p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPhysicalLayer_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaPhysicalLayer, Choices are:\n"
        "    (oaPhysicalLayer)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPhysicalLayer_tp_dealloc(PyoaPhysicalLayerObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPhysicalLayer_tp_repr(PyObject *ob)
{
    PyParamoaPhysicalLayer value;
    int convert_status=PyoaPhysicalLayer_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaPhysicalLayer::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[37];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaPhysicalLayer::");
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
oaPhysicalLayer_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPhysicalLayer v1;
    PyParamoaPhysicalLayer v2;
    int convert_status1=PyoaPhysicalLayer_Convert(ob1,&v1);
    int convert_status2=PyoaPhysicalLayer_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPhysicalLayer_Convert(PyObject* ob,PyParamoaPhysicalLayer* result)
{
    if (ob == NULL) return 1;
    if (PyoaPhysicalLayer_Check(ob)) {
        result->SetData( (oaPhysicalLayer**) ((PyoaPhysicalLayerObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPhysicalLayer Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPhysicalLayer_FromoaPhysicalLayer(oaPhysicalLayer** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaPhysicalLayer* data=*value;
        PyObject* bself = PyoaPhysicalLayer_Type.tp_alloc(&PyoaPhysicalLayer_Type,0);
        if (bself == NULL) return bself;
        PyoaPhysicalLayerObject* self = (PyoaPhysicalLayerObject*)bself;
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
PyObject* PyoaPhysicalLayer_FromoaPhysicalLayer(oaPhysicalLayer* data)
{
    if (data) {
       PyObject* bself = PyoaPhysicalLayer_Type.tp_alloc(&PyoaPhysicalLayer_Type,0);
       if (bself == NULL) return bself;
       PyoaPhysicalLayerObject* self = (PyoaPhysicalLayerObject*)bself;
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
static char oaPhysicalLayer_getLayerAbove_doc[] = 
"Class: oaPhysicalLayer, Function: getLayerAbove\n"
"  Paramegers: (oaMaterial)\n"
"    Calls: oaPhysicalLayer* getLayerAbove(oaMaterial material) const\n"
"    Signature: getLayerAbove|ptr-oaPhysicalLayer|simple-oaMaterial,\n"
"    This function returns the next layer with a mask number greater than this layer with the specified material type.\n"
"    If there is more than one physical layer for the mask number greater than this layer, an arbitrary one of those layers is returned.\n"
;

static PyObject*
oaPhysicalLayer_getLayerAbove(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPhysicalLayer data;
    int convert_status=PyoaPhysicalLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPhysicalLayerObject* self=(PyoaPhysicalLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaMaterial p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaMaterial_Convert,&p1)) {
        oaPhysicalLayerp result= (data.DataCall()->getLayerAbove(p1.Data()));
        return PyoaPhysicalLayer_FromoaPhysicalLayer(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPhysicalLayer_getLayerBelow_doc[] = 
"Class: oaPhysicalLayer, Function: getLayerBelow\n"
"  Paramegers: (oaMaterial)\n"
"    Calls: oaPhysicalLayer* getLayerBelow(oaMaterial material) const\n"
"    Signature: getLayerBelow|ptr-oaPhysicalLayer|simple-oaMaterial,\n"
"    This function returns the next layer with a mask number less than this layer with the specified material type.\n"
"    If there is more than one physical layer for the mask number less than this layer, an arbitrary one of those layers is returned.\n"
;

static PyObject*
oaPhysicalLayer_getLayerBelow(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPhysicalLayer data;
    int convert_status=PyoaPhysicalLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPhysicalLayerObject* self=(PyoaPhysicalLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaMaterial p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaMaterial_Convert,&p1)) {
        oaPhysicalLayerp result= (data.DataCall()->getLayerBelow(p1.Data()));
        return PyoaPhysicalLayer_FromoaPhysicalLayer(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPhysicalLayer_getManufacturingGrid_doc[] = 
"Class: oaPhysicalLayer, Function: getManufacturingGrid\n"
"  Paramegers: ()\n"
"    Calls: oaDist getManufacturingGrid() const\n"
"    Signature: getManufacturingGrid|simple-oaDist|\n"
"    BrowseData: 1\n"
"    This function gets the manufacturing grid for this layer. The manufacturing grid represents the minimum resolution that can be used to create objects on any purpose using the specified layer. If the manufacturing grid value for this layer has not been set i.e. zero, the default manufacturing grid value for the technology database to which this layer belongs is returned.\n"
;

static PyObject*
oaPhysicalLayer_getManufacturingGrid(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPhysicalLayer data;
    int convert_status=PyoaPhysicalLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPhysicalLayerObject* self=(PyoaPhysicalLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDist result= (data.DataCall()->getManufacturingGrid());
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
static char oaPhysicalLayer_getMaskNumber_doc[] = 
"Class: oaPhysicalLayer, Function: getMaskNumber\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getMaskNumber() const\n"
"    Signature: getMaskNumber|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function gets the maskNumber of this layer. The maskNumber represents the order of layers in the manufacturing process.\n"
;

static PyObject*
oaPhysicalLayer_getMaskNumber(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPhysicalLayer data;
    int convert_status=PyoaPhysicalLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPhysicalLayerObject* self=(PyoaPhysicalLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getMaskNumber());
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
static char oaPhysicalLayer_getMaterial_doc[] = 
"Class: oaPhysicalLayer, Function: getMaterial\n"
"  Paramegers: ()\n"
"    Calls: oaMaterial getMaterial() const\n"
"    Signature: getMaterial|simple-oaMaterial|\n"
"    BrowseData: 1\n"
"    This function gets the material of this layer. The material is an #oaMaterialEnum type that represents the type of material for this layer.\n"
;

static PyObject*
oaPhysicalLayer_getMaterial(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPhysicalLayer data;
    int convert_status=PyoaPhysicalLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPhysicalLayerObject* self=(PyoaPhysicalLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaMaterial* result= new oaMaterial(data.DataCall()->getMaterial());
        return PyoaMaterial_FromoaMaterial(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPhysicalLayer_getPrefRoutingDir_doc[] = 
"Class: oaPhysicalLayer, Function: getPrefRoutingDir\n"
"  Paramegers: ()\n"
"    Calls: oaPrefRoutingDir getPrefRoutingDir() const\n"
"    Signature: getPrefRoutingDir|simple-oaPrefRoutingDir|\n"
"    BrowseData: 1\n"
"    This function gets the preferred routing direction of this layer.\n"
;

static PyObject*
oaPhysicalLayer_getPrefRoutingDir(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPhysicalLayer data;
    int convert_status=PyoaPhysicalLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPhysicalLayerObject* self=(PyoaPhysicalLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaPrefRoutingDir* result= new oaPrefRoutingDir(data.DataCall()->getPrefRoutingDir());
        return PyoaPrefRoutingDir_FromoaPrefRoutingDir(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPhysicalLayer_resetManufacturingGrid_doc[] = 
"Class: oaPhysicalLayer, Function: resetManufacturingGrid\n"
"  Paramegers: ()\n"
"    Calls: void resetManufacturingGrid()\n"
"    Signature: resetManufacturingGrid|void-void|\n"
"    BrowseData: 0\n"
"    This function resets the manufacturingGrid for this layer. The default manufacturing grid value specified for the technology database to which this layer belongs shall apply for this layer after the reset.\n"
;

static PyObject*
oaPhysicalLayer_resetManufacturingGrid(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPhysicalLayer data;
    int convert_status=PyoaPhysicalLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPhysicalLayerObject* self=(PyoaPhysicalLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->resetManufacturingGrid();
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
static char oaPhysicalLayer_setManufacturingGrid_doc[] = 
"Class: oaPhysicalLayer, Function: setManufacturingGrid\n"
"  Paramegers: (oaDist)\n"
"    Calls: void setManufacturingGrid(oaDist grid)\n"
"    Signature: setManufacturingGrid|void-void|simple-oaDist,\n"
"    This function sets the manufacturing grid for this layer. The manufacturing grid represents the minimum resolution that can be used to create objects on any purpose using the specified layer. The new grid value will override any default technology manufacturing grid value that may have been applied for for this physical layer.\n"
"    grid\n"
"    The new value of the manufacturing grid to apply\n"
;

static PyObject*
oaPhysicalLayer_setManufacturingGrid(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPhysicalLayer data;
    int convert_status=PyoaPhysicalLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPhysicalLayerObject* self=(PyoaPhysicalLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDist p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDist_Convert,&p1)) {
        data.DataCall()->setManufacturingGrid(p1.Data());
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
static char oaPhysicalLayer_setMaskNumber_doc[] = 
"Class: oaPhysicalLayer, Function: setMaskNumber\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setMaskNumber(oaUInt4 number)\n"
"    Signature: setMaskNumber|void-void|simple-oaUInt4,\n"
"    This function sets the maskNumber for this layer. The maskNumber represents the order of layers in the manufacturing process.\n"
;

static PyObject*
oaPhysicalLayer_setMaskNumber(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPhysicalLayer data;
    int convert_status=PyoaPhysicalLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPhysicalLayerObject* self=(PyoaPhysicalLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setMaskNumber(p1.Data());
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
static char oaPhysicalLayer_setMaterial_doc[] = 
"Class: oaPhysicalLayer, Function: setMaterial\n"
"  Paramegers: (oaMaterial)\n"
"    Calls: void setMaterial(oaMaterial material)\n"
"    Signature: setMaterial|void-void|simple-oaMaterial,\n"
"    This function sets the material of this layer. The material is an #oaMaterialEnum type that represents the type of material for this layer.\n"
;

static PyObject*
oaPhysicalLayer_setMaterial(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPhysicalLayer data;
    int convert_status=PyoaPhysicalLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPhysicalLayerObject* self=(PyoaPhysicalLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaMaterial p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaMaterial_Convert,&p1)) {
        data.DataCall()->setMaterial(p1.Data());
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
static char oaPhysicalLayer_setPrefRoutingDir_doc[] = 
"Class: oaPhysicalLayer, Function: setPrefRoutingDir\n"
"  Paramegers: (oaPrefRoutingDir)\n"
"    Calls: void setPrefRoutingDir(oaPrefRoutingDir dir)\n"
"    Signature: setPrefRoutingDir|void-void|simple-oaPrefRoutingDir,\n"
"    This function sets the preferred routing direction for this layer.\n"
;

static PyObject*
oaPhysicalLayer_setPrefRoutingDir(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPhysicalLayer data;
    int convert_status=PyoaPhysicalLayer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPhysicalLayerObject* self=(PyoaPhysicalLayerObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPrefRoutingDir p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPrefRoutingDir_Convert,&p1)) {
        data.DataCall()->setPrefRoutingDir(p1.Data());
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
static char oaPhysicalLayer_isNull_doc[] =
"Class: oaPhysicalLayer, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaPhysicalLayer_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaPhysicalLayer data;
    int convert_status=PyoaPhysicalLayer_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaPhysicalLayer_assign_doc[] = 
"Class: oaPhysicalLayer, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPhysicalLayer_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPhysicalLayer data;
  int convert_status=PyoaPhysicalLayer_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPhysicalLayer p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPhysicalLayer_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPhysicalLayer_methodlist[] = {
    {"getLayerAbove",(PyCFunction)oaPhysicalLayer_getLayerAbove,METH_VARARGS,oaPhysicalLayer_getLayerAbove_doc},
    {"getLayerBelow",(PyCFunction)oaPhysicalLayer_getLayerBelow,METH_VARARGS,oaPhysicalLayer_getLayerBelow_doc},
    {"getManufacturingGrid",(PyCFunction)oaPhysicalLayer_getManufacturingGrid,METH_VARARGS,oaPhysicalLayer_getManufacturingGrid_doc},
    {"getMaskNumber",(PyCFunction)oaPhysicalLayer_getMaskNumber,METH_VARARGS,oaPhysicalLayer_getMaskNumber_doc},
    {"getMaterial",(PyCFunction)oaPhysicalLayer_getMaterial,METH_VARARGS,oaPhysicalLayer_getMaterial_doc},
    {"getPrefRoutingDir",(PyCFunction)oaPhysicalLayer_getPrefRoutingDir,METH_VARARGS,oaPhysicalLayer_getPrefRoutingDir_doc},
    {"resetManufacturingGrid",(PyCFunction)oaPhysicalLayer_resetManufacturingGrid,METH_VARARGS,oaPhysicalLayer_resetManufacturingGrid_doc},
    {"setManufacturingGrid",(PyCFunction)oaPhysicalLayer_setManufacturingGrid,METH_VARARGS,oaPhysicalLayer_setManufacturingGrid_doc},
    {"setMaskNumber",(PyCFunction)oaPhysicalLayer_setMaskNumber,METH_VARARGS,oaPhysicalLayer_setMaskNumber_doc},
    {"setMaterial",(PyCFunction)oaPhysicalLayer_setMaterial,METH_VARARGS,oaPhysicalLayer_setMaterial_doc},
    {"setPrefRoutingDir",(PyCFunction)oaPhysicalLayer_setPrefRoutingDir,METH_VARARGS,oaPhysicalLayer_setPrefRoutingDir_doc},
    {"isNull",(PyCFunction)oaPhysicalLayer_tp_isNull,METH_VARARGS,oaPhysicalLayer_isNull_doc},
    {"assign",(PyCFunction)oaPhysicalLayer_tp_assign,METH_VARARGS,oaPhysicalLayer_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPhysicalLayer_doc[] = 
"Class: oaPhysicalLayer\n"
"  The oaPhysicalLayer class defines a physical layer that is referenced when creating physical design data.\n"
"Constructors:\n"
"  Paramegers: (oaPhysicalLayer)\n"
"    Calls: (const oaPhysicalLayer&)\n"
"    Signature: oaPhysicalLayer||cref-oaPhysicalLayer,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPhysicalLayer_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPhysicalLayer",
    sizeof(PyoaPhysicalLayerObject),
    0,
    (destructor)oaPhysicalLayer_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPhysicalLayer_tp_compare,	/* tp_compare */
    (reprfunc)oaPhysicalLayer_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPhysicalLayer_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPhysicalLayer_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaLayer_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPhysicalLayer_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPhysicalLayer_static_create_doc[] = 
"Class: oaPhysicalLayer, Function: create\n"
"  Paramegers: (oaTech,oaString,oaLayerNum)\n"
"    Calls: oaPhysicalLayer* create(oaTech* tech,const oaString& name,oaLayerNum number)\n"
"    Signature: create|ptr-oaPhysicalLayer|ptr-oaTech,cref-oaString,simple-oaLayerNum,simple-oaMaterial,simple-oaUInt4,\n"
"    This function creates a layer with the specified name and number . Any layer number in the set of unsigned four byte integers is a valid layer number.\n"
"    tech\n"
"    The technology database in which to create the layer\n"
"    name\n"
"    The name of the layer to create\n"
"    number\n"
"    The number of the layer to create\n"
"    material\n"
"    The material type of the layer to create\n"
"    maskNumber\n"
"    The mask number of the layer to create\n"
"    oacLayerNameExists\n"
"    oacLayerNumberExists\n"
"  Paramegers: (oaTech,oaString,oaLayerNum,oaMaterial)\n"
"    Calls: oaPhysicalLayer* create(oaTech* tech,const oaString& name,oaLayerNum number,oaMaterial material)\n"
"    Signature: create|ptr-oaPhysicalLayer|ptr-oaTech,cref-oaString,simple-oaLayerNum,simple-oaMaterial,simple-oaUInt4,\n"
"    This function creates a layer with the specified name and number . Any layer number in the set of unsigned four byte integers is a valid layer number.\n"
"    tech\n"
"    The technology database in which to create the layer\n"
"    name\n"
"    The name of the layer to create\n"
"    number\n"
"    The number of the layer to create\n"
"    material\n"
"    The material type of the layer to create\n"
"    maskNumber\n"
"    The mask number of the layer to create\n"
"    oacLayerNameExists\n"
"    oacLayerNumberExists\n"
"  Paramegers: (oaTech,oaString,oaLayerNum,oaMaterial,oaUInt4)\n"
"    Calls: oaPhysicalLayer* create(oaTech* tech,const oaString& name,oaLayerNum number,oaMaterial material,oaUInt4 maskNumber)\n"
"    Signature: create|ptr-oaPhysicalLayer|ptr-oaTech,cref-oaString,simple-oaLayerNum,simple-oaMaterial,simple-oaUInt4,\n"
"    This function creates a layer with the specified name and number . Any layer number in the set of unsigned four byte integers is a valid layer number.\n"
"    tech\n"
"    The technology database in which to create the layer\n"
"    name\n"
"    The name of the layer to create\n"
"    number\n"
"    The number of the layer to create\n"
"    material\n"
"    The material type of the layer to create\n"
"    maskNumber\n"
"    The mask number of the layer to create\n"
"    oacLayerNameExists\n"
"    oacLayerNumberExists\n"
;

static PyObject*
oaPhysicalLayer_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaTech,oaString,oaLayerNum)
    {
        PyParamoaTech p1;
        PyParamoaString p2;
        PyParamoaLayerNum p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaLayerNum_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPhysicalLayerp result= (oaPhysicalLayer::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaPhysicalLayer_FromoaPhysicalLayer(result);
        }
    }
    PyErr_Clear();
    // Case: (oaTech,oaString,oaLayerNum,oaMaterial)
    {
        PyParamoaTech p1;
        PyParamoaString p2;
        PyParamoaLayerNum p3;
        PyParamoaMaterial p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaMaterial_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPhysicalLayerp result= (oaPhysicalLayer::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaPhysicalLayer_FromoaPhysicalLayer(result);
        }
    }
    PyErr_Clear();
    // Case: (oaTech,oaString,oaLayerNum,oaMaterial,oaUInt4)
    {
        PyParamoaTech p1;
        PyParamoaString p2;
        PyParamoaLayerNum p3;
        PyParamoaMaterial p4;
        PyParamoaUInt4 p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaLayerNum_Convert,&p3,
              &PyoaMaterial_Convert,&p4,
              &PyoaUInt4_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPhysicalLayerp result= (oaPhysicalLayer::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaPhysicalLayer_FromoaPhysicalLayer(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaPhysicalLayer, function: create, Choices are:\n"
        "    (oaTech,oaString,oaLayerNum)\n"
        "    (oaTech,oaString,oaLayerNum,oaMaterial)\n"
        "    (oaTech,oaString,oaLayerNum,oaMaterial,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPhysicalLayer_static_find_doc[] = 
"Class: oaPhysicalLayer, Function: find\n"
"  Paramegers: (oaTech,oaString)\n"
"    Calls: oaPhysicalLayer* find(const oaTech* tech,const oaString& name)\n"
"    Signature: find|ptr-oaPhysicalLayer|cptr-oaTech,cref-oaString,\n"
"    This function searches the specified technology database for a physical layer with the specified name . If the specified technology database references other technology databases, those are searched as well and the first matching layer is returned. To find a layer in the current technology database only, refer to the find function that accepts the local argument.\n"
"    If the function finds the specified layer, the function returns a pointer to the oaLayer object. Otherwise, the function returns NULL.\n"
"    Refer to Incremental Technology Databases in the Using Technology Databases section of the Programmers Guide for more information about referenced tech databases.\n"
"    tech\n"
"    The technology database to search\n"
"    name\n"
"    The layer name to find\n"
"  Paramegers: (oaTech,oaLayerNum)\n"
"    Calls: oaPhysicalLayer* find(const oaTech* tech,oaLayerNum number)\n"
"    Signature: find|ptr-oaPhysicalLayer|cptr-oaTech,simple-oaLayerNum,\n"
"    This function searches the specified technology database for a physical layer with the specified number . If the specified technology database references other technology databases, those are searched as well and the first matching layer is returned. To find a layer in the current technology database only, refer to the find function that accepts the local argument.\n"
"    If the function finds the specified layer, the function returns a pointer to the oaLayer object. Otherwise, the function returns NULL.\n"
"    Refer to Incremental Technology Databases in the Using Technology Databases section of the Programmers Guide for more information about referenced tech databases.\n"
"    tech\n"
"    The technology database to search\n"
"    number\n"
"    The layer number to find\n"
"  Paramegers: (oaTech,oaString,oaBoolean)\n"
"    Calls: oaPhysicalLayer* find(const oaTech* tech,const oaString& name,oaBoolean local)\n"
"    Signature: find|ptr-oaPhysicalLayer|cptr-oaTech,cref-oaString,simple-oaBoolean,\n"
"    oaPhysicalLayer::findName2\n"
"    This function searches the specified technology database looking for a physical layer with the specified name . The local argument specifies whether (if true) to look only in the specified technology database or (if false) to look in the specified technology database and all of its referenced databases. If the layer is found, a pointer to the layer object is returned, otherwise NULL is returned.\n"
"    Refer to Incremental Technology Databases in the Using Technology Databases section of the Programmers Guide for more information about referenced tech databases.\n"
"    tech\n"
"    The technology database to search\n"
"    name\n"
"    The layer name to find\n"
"    local\n"
"    Specifies whether (if true) to look only in the specified technology database or (if false) to look in the specified technology database and all of its referenced databases.\n"
"  Paramegers: (oaTech,oaLayerNum,oaBoolean)\n"
"    Calls: oaPhysicalLayer* find(const oaTech* tech,oaLayerNum number,oaBoolean local)\n"
"    Signature: find|ptr-oaPhysicalLayer|cptr-oaTech,simple-oaLayerNum,simple-oaBoolean,\n"
"    oaPhysicalLayer::findNum2\n"
"    This function searches the specified technology database for a physical layer with the specified number . The local argument specifies whether (if true) to look only in the specified technology database or (if false) to search the specified technology database and all of its referenced technology databases. If the layer is found, a pointer to the layer object is returned, otherwise NULL is returned.\n"
"    Refer to Incremental Technology Databases in the Using Technology Databases section of the Programmers Guide for more information about referenced tech databases.\n"
"    tech\n"
"    The technology database to search\n"
"    number\n"
"    The layer number to find\n"
"    local\n"
"    Specifies whether (if true) to look only in the specified technology database or (if false) to look in the specified technology database and all of its referenced databases.\n"
;

static PyObject*
oaPhysicalLayer_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaTech,oaString)
    {
        PyParamoaTech p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPhysicalLayerp result= (oaPhysicalLayer::find(p1.Data(),p2.Data()));
            return PyoaPhysicalLayer_FromoaPhysicalLayer(result);
        }
    }
    PyErr_Clear();
    // Case: (oaTech,oaLayerNum)
    {
        PyParamoaTech p1;
        PyParamoaLayerNum p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaLayerNum_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPhysicalLayerp result= (oaPhysicalLayer::find(p1.Data(),p2.Data()));
            return PyoaPhysicalLayer_FromoaPhysicalLayer(result);
        }
    }
    PyErr_Clear();
    // Case: (oaTech,oaString,oaBoolean)
    {
        PyParamoaTech p1;
        PyParamoaString p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPhysicalLayerp result= (oaPhysicalLayer::find(p1.Data(),p2.Data(),p3.Data()));
            return PyoaPhysicalLayer_FromoaPhysicalLayer(result);
        }
    }
    PyErr_Clear();
    // Case: (oaTech,oaLayerNum,oaBoolean)
    {
        PyParamoaTech p1;
        PyParamoaLayerNum p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPhysicalLayerp result= (oaPhysicalLayer::find(p1.Data(),p2.Data(),p3.Data()));
            return PyoaPhysicalLayer_FromoaPhysicalLayer(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaPhysicalLayer, function: find, Choices are:\n"
        "    (oaTech,oaString)\n"
        "    (oaTech,oaLayerNum)\n"
        "    (oaTech,oaString,oaBoolean)\n"
        "    (oaTech,oaLayerNum,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaPhysicalLayer_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaPhysicalLayer_static_create,METH_VARARGS,oaPhysicalLayer_static_create_doc},
    {"static_find",(PyCFunction)oaPhysicalLayer_static_find,METH_VARARGS,oaPhysicalLayer_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPhysicalLayer_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPhysicalLayer_Type)<0) {
      printf("** PyType_Ready failed for: oaPhysicalLayer\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPhysicalLayer",
           (PyObject*)(&PyoaPhysicalLayer_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPhysicalLayer\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaPhysicalLayer_Type.tp_dict;
    for(method=oaPhysicalLayer_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaPiElmore
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPiElmore_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPiElmore_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPiElmoreObject* self = (PyoaPiElmoreObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaPiElmore)
    {
        PyParamoaPiElmore p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPiElmore_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaPiElmore, Choices are:\n"
        "    (oaPiElmore)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPiElmore_tp_dealloc(PyoaPiElmoreObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPiElmore_tp_repr(PyObject *ob)
{
    PyParamoaPiElmore value;
    int convert_status=PyoaPiElmore_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[32];
    sprintf(buffer,"<oaPiElmore::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaPiElmore_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPiElmore v1;
    PyParamoaPiElmore v2;
    int convert_status1=PyoaPiElmore_Convert(ob1,&v1);
    int convert_status2=PyoaPiElmore_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPiElmore_Convert(PyObject* ob,PyParamoaPiElmore* result)
{
    if (ob == NULL) return 1;
    if (PyoaPiElmore_Check(ob)) {
        result->SetData( (oaPiElmore**) ((PyoaPiElmoreObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPiElmore Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPiElmore_FromoaPiElmore(oaPiElmore** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaPiElmore* data=*value;
        PyObject* bself = PyoaPiElmore_Type.tp_alloc(&PyoaPiElmore_Type,0);
        if (bself == NULL) return bself;
        PyoaPiElmoreObject* self = (PyoaPiElmoreObject*)bself;
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
PyObject* PyoaPiElmore_FromoaPiElmore(oaPiElmore* data)
{
    if (data) {
       PyObject* bself = PyoaPiElmore_Type.tp_alloc(&PyoaPiElmore_Type,0);
       if (bself == NULL) return bself;
       PyoaPiElmoreObject* self = (PyoaPiElmoreObject*)bself;
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
static char oaPiElmore_getElmores_doc[] = 
"Class: oaPiElmore, Function: getElmores\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaElmore_oaPiElmore getElmores() const\n"
"    Signature: getElmores|simple-oaCollection_oaElmore_oaPiElmore|\n"
"    BrowseData: 1\n"
"    This function returns a collection of elmores for the receivers in this reduced model.\n"
;

static PyObject*
oaPiElmore_getElmores(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiElmore data;
    int convert_status=PyoaPiElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiElmoreObject* self=(PyoaPiElmoreObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaElmore_oaPiElmore* result= new oaCollection_oaElmore_oaPiElmore(data.DataCall()->getElmores());
        return PyoaCollection_oaElmore_oaPiElmore_FromoaCollection_oaElmore_oaPiElmore(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPiElmore_getElmoresIter_doc[] = 
"Class: oaPiElmore, Function: getElmoresIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaElmore getElmoresIter() const\n"
"    Signature: getElmoresIter|simple-oaIter_oaElmore|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of elmores for the receivers in this reduced model.\n"
;

static PyObject*
oaPiElmore_getElmoresIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiElmore data;
    int convert_status=PyoaPiElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiElmoreObject* self=(PyoaPiElmoreObject*)ob;
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
static char oaPiElmore_getFarCap_doc[] = 
"Class: oaPiElmore, Function: getFarCap\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getFarCap() const\n"
"    Signature: getFarCap|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the value of the capacitor farthest from the driver in the PI model.\n"
;

static PyObject*
oaPiElmore_getFarCap(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiElmore data;
    int convert_status=PyoaPiElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiElmoreObject* self=(PyoaPiElmoreObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getFarCap());
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
static char oaPiElmore_getNearCap_doc[] = 
"Class: oaPiElmore, Function: getNearCap\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getNearCap() const\n"
"    Signature: getNearCap|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the value of the capacitor closest to the driver in the PI model.\n"
;

static PyObject*
oaPiElmore_getNearCap(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiElmore data;
    int convert_status=PyoaPiElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiElmoreObject* self=(PyoaPiElmoreObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getNearCap());
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
static char oaPiElmore_getPiModel_doc[] = 
"Class: oaPiElmore, Function: getPiModel\n"
"  Paramegers: (oaFloat,oaFloat,oaFloat)\n"
"    Calls: void getPiModel(oaFloat& nearCap,oaFloat& res,oaFloat& farCap) const\n"
"    Signature: getPiModel|void-void|ref-oaFloat,ref-oaFloat,ref-oaFloat,\n"
"    BrowseData: 0,oaFloat,oaFloat,oaFloat\n"
"    This function returns the PI model values of this oaPiElmore.\n"
;

static PyObject*
oaPiElmore_getPiModel(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiElmore data;
    int convert_status=PyoaPiElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiElmoreObject* self=(PyoaPiElmoreObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    PyParamoaFloat p2;
    PyParamoaFloat p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaFloat_Convert,&p1,
          &PyoaFloat_Convert,&p2,
          &PyoaFloat_Convert,&p3)) {
        data.DataCall()->getPiModel(p1.Data(),p2.Data(),p3.Data());
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
static char oaPiElmore_getRes_doc[] = 
"Class: oaPiElmore, Function: getRes\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getRes() const\n"
"    Signature: getRes|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the value of the resistor in the PI model.\n"
;

static PyObject*
oaPiElmore_getRes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiElmore data;
    int convert_status=PyoaPiElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiElmoreObject* self=(PyoaPiElmoreObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getRes());
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
static char oaPiElmore_setFarCap_doc[] = 
"Class: oaPiElmore, Function: setFarCap\n"
"  Paramegers: (oaFloat)\n"
"    Calls: void setFarCap(oaFloat value)\n"
"    Signature: setFarCap|void-void|simple-oaFloat,\n"
"    This function sets the value of the capacitor farthest from the driver in the PI model.\n"
;

static PyObject*
oaPiElmore_setFarCap(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiElmore data;
    int convert_status=PyoaPiElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiElmoreObject* self=(PyoaPiElmoreObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFloat_Convert,&p1)) {
        data.DataCall()->setFarCap(p1.Data());
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
static char oaPiElmore_setNearCap_doc[] = 
"Class: oaPiElmore, Function: setNearCap\n"
"  Paramegers: (oaFloat)\n"
"    Calls: void setNearCap(oaFloat value)\n"
"    Signature: setNearCap|void-void|simple-oaFloat,\n"
"    This function sets the value of the capacitor closest to the driver in the PI model.\n"
;

static PyObject*
oaPiElmore_setNearCap(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiElmore data;
    int convert_status=PyoaPiElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiElmoreObject* self=(PyoaPiElmoreObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFloat_Convert,&p1)) {
        data.DataCall()->setNearCap(p1.Data());
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
static char oaPiElmore_setPiModel_doc[] = 
"Class: oaPiElmore, Function: setPiModel\n"
"  Paramegers: (oaFloat,oaFloat,oaFloat)\n"
"    Calls: void setPiModel(oaFloat nearCap,oaFloat res,oaFloat farCap)\n"
"    Signature: setPiModel|void-void|simple-oaFloat,simple-oaFloat,simple-oaFloat,\n"
"    This function sets the PI model values for this oaPiElmore.\n"
;

static PyObject*
oaPiElmore_setPiModel(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiElmore data;
    int convert_status=PyoaPiElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiElmoreObject* self=(PyoaPiElmoreObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    PyParamoaFloat p2;
    PyParamoaFloat p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaFloat_Convert,&p1,
          &PyoaFloat_Convert,&p2,
          &PyoaFloat_Convert,&p3)) {
        data.DataCall()->setPiModel(p1.Data(),p2.Data(),p3.Data());
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
static char oaPiElmore_setRes_doc[] = 
"Class: oaPiElmore, Function: setRes\n"
"  Paramegers: (oaFloat)\n"
"    Calls: void setRes(oaFloat value)\n"
"    Signature: setRes|void-void|simple-oaFloat,\n"
"    This function sets the value of the resistor in the PI model.\n"
;

static PyObject*
oaPiElmore_setRes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiElmore data;
    int convert_status=PyoaPiElmore_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiElmoreObject* self=(PyoaPiElmoreObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFloat_Convert,&p1)) {
        data.DataCall()->setRes(p1.Data());
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
static char oaPiElmore_isNull_doc[] =
"Class: oaPiElmore, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaPiElmore_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaPiElmore data;
    int convert_status=PyoaPiElmore_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaPiElmore_assign_doc[] = 
"Class: oaPiElmore, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPiElmore_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPiElmore data;
  int convert_status=PyoaPiElmore_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPiElmore p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPiElmore_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPiElmore_methodlist[] = {
    {"getElmores",(PyCFunction)oaPiElmore_getElmores,METH_VARARGS,oaPiElmore_getElmores_doc},
    {"getElmoresIter",(PyCFunction)oaPiElmore_getElmoresIter,METH_VARARGS,oaPiElmore_getElmoresIter_doc},
    {"getFarCap",(PyCFunction)oaPiElmore_getFarCap,METH_VARARGS,oaPiElmore_getFarCap_doc},
    {"getNearCap",(PyCFunction)oaPiElmore_getNearCap,METH_VARARGS,oaPiElmore_getNearCap_doc},
    {"getPiModel",(PyCFunction)oaPiElmore_getPiModel,METH_VARARGS,oaPiElmore_getPiModel_doc},
    {"getRes",(PyCFunction)oaPiElmore_getRes,METH_VARARGS,oaPiElmore_getRes_doc},
    {"setFarCap",(PyCFunction)oaPiElmore_setFarCap,METH_VARARGS,oaPiElmore_setFarCap_doc},
    {"setNearCap",(PyCFunction)oaPiElmore_setNearCap,METH_VARARGS,oaPiElmore_setNearCap_doc},
    {"setPiModel",(PyCFunction)oaPiElmore_setPiModel,METH_VARARGS,oaPiElmore_setPiModel_doc},
    {"setRes",(PyCFunction)oaPiElmore_setRes,METH_VARARGS,oaPiElmore_setRes_doc},
    {"isNull",(PyCFunction)oaPiElmore_tp_isNull,METH_VARARGS,oaPiElmore_isNull_doc},
    {"assign",(PyCFunction)oaPiElmore_tp_assign,METH_VARARGS,oaPiElmore_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPiElmore_doc[] = 
"Class: oaPiElmore\n"
"  The oaPiElmore class represents a reduced model for the parasitics seen by a driver of a net, using a PI model and a set of Elmore delays to each receiver. The PI model consists of two capacitors and a resistor between them, with nearCap being the capacitor closer to the driver. The oaElmore class represents the Elmore delays, which are the first moment of the impulse response of the interconnect parasitics from the driver to each receiver.\n"
"  Undo is not supported for oaPiElmore objects.\n"
"Constructors:\n"
"  Paramegers: (oaPiElmore)\n"
"    Calls: (const oaPiElmore&)\n"
"    Signature: oaPiElmore||cref-oaPiElmore,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPiElmore_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPiElmore",
    sizeof(PyoaPiElmoreObject),
    0,
    (destructor)oaPiElmore_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPiElmore_tp_compare,	/* tp_compare */
    (reprfunc)oaPiElmore_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPiElmore_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPiElmore_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaReducedModel_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPiElmore_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPiElmore_static_create_doc[] = 
"Class: oaPiElmore, Function: create\n"
"  Paramegers: (oaDesignObject,oaAnalysisPoint,oaFloat,oaFloat,oaFloat)\n"
"    Calls: oaPiElmore* create(oaDesignObject* driver,const oaAnalysisPoint* ap,oaFloat nearCap,oaFloat res,oaFloat farCap)\n"
"    Signature: create|ptr-oaPiElmore|ptr-oaDesignObject,cptr-oaAnalysisPoint,simple-oaFloat,simple-oaFloat,simple-oaFloat,\n"
"    This function creates a piElmore model for the specified driver object and analysis point. The driver can be terminal or instTerm in block or occurrence domain.\n"
"    oacInvalidReducedModelDomain\n"
"    oacInvalidReducedModelObjectType\n"
"    oacInvalidDriverTermType\n"
"    oacParasiticTermMustBeScalar\n"
"    oacParasiticInstTermMustBeScalar\n"
;

static PyObject*
oaPiElmore_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDesignObject p1;
    PyParamoaAnalysisPoint p2;
    PyParamoaFloat p3;
    PyParamoaFloat p4;
    PyParamoaFloat p5;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&",
          &PyoaDesignObject_Convert,&p1,
          &PyoaAnalysisPoint_Convert,&p2,
          &PyoaFloat_Convert,&p3,
          &PyoaFloat_Convert,&p4,
          &PyoaFloat_Convert,&p5)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        oaPiElmorep result= (oaPiElmore::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
        return PyoaPiElmore_FromoaPiElmore(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPiElmore_static_find_doc[] = 
"Class: oaPiElmore, Function: find\n"
"  Paramegers: (oaDesignObject,oaAnalysisPoint)\n"
"    Calls: oaPiElmore* find(const oaDesignObject* driver,const oaAnalysisPoint* ap)\n"
"    Signature: find|ptr-oaPiElmore|cptr-oaDesignObject,cptr-oaAnalysisPoint,\n"
"    This function finds the piElmore on the specified driver and analysisPoint. If found it returns the object, otherwise it returns null pointer to the caller.\n"
;

static PyObject*
oaPiElmore_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDesignObject p1;
    PyParamoaAnalysisPoint p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDesignObject_Convert,&p1,
          &PyoaAnalysisPoint_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        oaPiElmorep result= (oaPiElmore::find(p1.Data(),p2.Data()));
        return PyoaPiElmore_FromoaPiElmore(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaPiElmore_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaPiElmore_static_create,METH_VARARGS,oaPiElmore_static_create_doc},
    {"static_find",(PyCFunction)oaPiElmore_static_find,METH_VARARGS,oaPiElmore_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPiElmore_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPiElmore_Type)<0) {
      printf("** PyType_Ready failed for: oaPiElmore\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPiElmore",
           (PyObject*)(&PyoaPiElmore_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPiElmore\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaPiElmore_Type.tp_dict;
    for(method=oaPiElmore_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaPiPoleResidue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPiPoleResidue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPiPoleResidue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPiPoleResidueObject* self = (PyoaPiPoleResidueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaPiPoleResidue)
    {
        PyParamoaPiPoleResidue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPiPoleResidue_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaPiPoleResidue, Choices are:\n"
        "    (oaPiPoleResidue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPiPoleResidue_tp_dealloc(PyoaPiPoleResidueObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPiPoleResidue_tp_repr(PyObject *ob)
{
    PyParamoaPiPoleResidue value;
    int convert_status=PyoaPiPoleResidue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaPiPoleResidue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaPiPoleResidue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPiPoleResidue v1;
    PyParamoaPiPoleResidue v2;
    int convert_status1=PyoaPiPoleResidue_Convert(ob1,&v1);
    int convert_status2=PyoaPiPoleResidue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPiPoleResidue_Convert(PyObject* ob,PyParamoaPiPoleResidue* result)
{
    if (ob == NULL) return 1;
    if (PyoaPiPoleResidue_Check(ob)) {
        result->SetData( (oaPiPoleResidue**) ((PyoaPiPoleResidueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPiPoleResidue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPiPoleResidue_FromoaPiPoleResidue(oaPiPoleResidue** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaPiPoleResidue* data=*value;
        PyObject* bself = PyoaPiPoleResidue_Type.tp_alloc(&PyoaPiPoleResidue_Type,0);
        if (bself == NULL) return bself;
        PyoaPiPoleResidueObject* self = (PyoaPiPoleResidueObject*)bself;
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
PyObject* PyoaPiPoleResidue_FromoaPiPoleResidue(oaPiPoleResidue* data)
{
    if (data) {
       PyObject* bself = PyoaPiPoleResidue_Type.tp_alloc(&PyoaPiPoleResidue_Type,0);
       if (bself == NULL) return bself;
       PyoaPiPoleResidueObject* self = (PyoaPiPoleResidueObject*)bself;
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
static char oaPiPoleResidue_getFarCap_doc[] = 
"Class: oaPiPoleResidue, Function: getFarCap\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getFarCap() const\n"
"    Signature: getFarCap|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the value of the capacitor farthest from the driver in the PI model.\n"
;

static PyObject*
oaPiPoleResidue_getFarCap(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiPoleResidue data;
    int convert_status=PyoaPiPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiPoleResidueObject* self=(PyoaPiPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getFarCap());
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
static char oaPiPoleResidue_getNearCap_doc[] = 
"Class: oaPiPoleResidue, Function: getNearCap\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getNearCap() const\n"
"    Signature: getNearCap|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the value of the capacitor closest to the driver in the PI model.\n"
;

static PyObject*
oaPiPoleResidue_getNearCap(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiPoleResidue data;
    int convert_status=PyoaPiPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiPoleResidueObject* self=(PyoaPiPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getNearCap());
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
static char oaPiPoleResidue_getPiModel_doc[] = 
"Class: oaPiPoleResidue, Function: getPiModel\n"
"  Paramegers: (oaFloat,oaFloat,oaFloat)\n"
"    Calls: void getPiModel(oaFloat& nearCap,oaFloat& res,oaFloat& farCap) const\n"
"    Signature: getPiModel|void-void|ref-oaFloat,ref-oaFloat,ref-oaFloat,\n"
"    BrowseData: 0,oaFloat,oaFloat,oaFloat\n"
"    This function returns the PI model values of this oaPiPoleResidue.\n"
;

static PyObject*
oaPiPoleResidue_getPiModel(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiPoleResidue data;
    int convert_status=PyoaPiPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiPoleResidueObject* self=(PyoaPiPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    PyParamoaFloat p2;
    PyParamoaFloat p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaFloat_Convert,&p1,
          &PyoaFloat_Convert,&p2,
          &PyoaFloat_Convert,&p3)) {
        data.DataCall()->getPiModel(p1.Data(),p2.Data(),p3.Data());
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
static char oaPiPoleResidue_getPoleResidues_doc[] = 
"Class: oaPiPoleResidue, Function: getPoleResidues\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaPoleResidue_oaPiPoleResidue getPoleResidues() const\n"
"    Signature: getPoleResidues|simple-oaCollection_oaPoleResidue_oaPiPoleResidue|\n"
"    BrowseData: 1\n"
"    This function returns a collection of poleResidues for the receivers in this reduced model.\n"
;

static PyObject*
oaPiPoleResidue_getPoleResidues(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiPoleResidue data;
    int convert_status=PyoaPiPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiPoleResidueObject* self=(PyoaPiPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaPoleResidue_oaPiPoleResidue* result= new oaCollection_oaPoleResidue_oaPiPoleResidue(data.DataCall()->getPoleResidues());
        return PyoaCollection_oaPoleResidue_oaPiPoleResidue_FromoaCollection_oaPoleResidue_oaPiPoleResidue(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPiPoleResidue_getPoleResiduesIter_doc[] = 
"Class: oaPiPoleResidue, Function: getPoleResiduesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaPoleResidue getPoleResiduesIter() const\n"
"    Signature: getPoleResiduesIter|simple-oaIter_oaPoleResidue|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of poleResidues for the receivers in this reduced model.\n"
;

static PyObject*
oaPiPoleResidue_getPoleResiduesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiPoleResidue data;
    int convert_status=PyoaPiPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiPoleResidueObject* self=(PyoaPiPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaPoleResidue* result= new oaIter_oaPoleResidue(data.DataCall()->getPoleResidues());
        return PyoaIter_oaPoleResidue_FromoaIter_oaPoleResidue(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPiPoleResidue_getRes_doc[] = 
"Class: oaPiPoleResidue, Function: getRes\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getRes() const\n"
"    Signature: getRes|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the value of the resistor in the PI model.\n"
;

static PyObject*
oaPiPoleResidue_getRes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiPoleResidue data;
    int convert_status=PyoaPiPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiPoleResidueObject* self=(PyoaPiPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getRes());
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
static char oaPiPoleResidue_setFarCap_doc[] = 
"Class: oaPiPoleResidue, Function: setFarCap\n"
"  Paramegers: (oaFloat)\n"
"    Calls: void setFarCap(oaFloat value)\n"
"    Signature: setFarCap|void-void|simple-oaFloat,\n"
"    This function sets the value of the capacitor farthest from the driver in the PI model.\n"
;

static PyObject*
oaPiPoleResidue_setFarCap(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiPoleResidue data;
    int convert_status=PyoaPiPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiPoleResidueObject* self=(PyoaPiPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFloat_Convert,&p1)) {
        data.DataCall()->setFarCap(p1.Data());
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
static char oaPiPoleResidue_setNearCap_doc[] = 
"Class: oaPiPoleResidue, Function: setNearCap\n"
"  Paramegers: (oaFloat)\n"
"    Calls: void setNearCap(oaFloat value)\n"
"    Signature: setNearCap|void-void|simple-oaFloat,\n"
"    This function sets the value of the capacitor closest to the driver in the PI model.\n"
;

static PyObject*
oaPiPoleResidue_setNearCap(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiPoleResidue data;
    int convert_status=PyoaPiPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiPoleResidueObject* self=(PyoaPiPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFloat_Convert,&p1)) {
        data.DataCall()->setNearCap(p1.Data());
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
static char oaPiPoleResidue_setPiModel_doc[] = 
"Class: oaPiPoleResidue, Function: setPiModel\n"
"  Paramegers: (oaFloat,oaFloat,oaFloat)\n"
"    Calls: void setPiModel(oaFloat nearCap,oaFloat res,oaFloat farCap)\n"
"    Signature: setPiModel|void-void|simple-oaFloat,simple-oaFloat,simple-oaFloat,\n"
"    This function sets the PI model values for this oaPiPoleResidue.\n"
;

static PyObject*
oaPiPoleResidue_setPiModel(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiPoleResidue data;
    int convert_status=PyoaPiPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiPoleResidueObject* self=(PyoaPiPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    PyParamoaFloat p2;
    PyParamoaFloat p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaFloat_Convert,&p1,
          &PyoaFloat_Convert,&p2,
          &PyoaFloat_Convert,&p3)) {
        data.DataCall()->setPiModel(p1.Data(),p2.Data(),p3.Data());
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
static char oaPiPoleResidue_setRes_doc[] = 
"Class: oaPiPoleResidue, Function: setRes\n"
"  Paramegers: (oaFloat)\n"
"    Calls: void setRes(oaFloat value)\n"
"    Signature: setRes|void-void|simple-oaFloat,\n"
"    This function sets the value of the resistor in the PI model.\n"
;

static PyObject*
oaPiPoleResidue_setRes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiPoleResidue data;
    int convert_status=PyoaPiPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPiPoleResidueObject* self=(PyoaPiPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFloat_Convert,&p1)) {
        data.DataCall()->setRes(p1.Data());
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
static char oaPiPoleResidue_isNull_doc[] =
"Class: oaPiPoleResidue, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaPiPoleResidue_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaPiPoleResidue data;
    int convert_status=PyoaPiPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaPiPoleResidue_assign_doc[] = 
"Class: oaPiPoleResidue, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPiPoleResidue_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPiPoleResidue data;
  int convert_status=PyoaPiPoleResidue_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPiPoleResidue p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPiPoleResidue_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPiPoleResidue_methodlist[] = {
    {"getFarCap",(PyCFunction)oaPiPoleResidue_getFarCap,METH_VARARGS,oaPiPoleResidue_getFarCap_doc},
    {"getNearCap",(PyCFunction)oaPiPoleResidue_getNearCap,METH_VARARGS,oaPiPoleResidue_getNearCap_doc},
    {"getPiModel",(PyCFunction)oaPiPoleResidue_getPiModel,METH_VARARGS,oaPiPoleResidue_getPiModel_doc},
    {"getPoleResidues",(PyCFunction)oaPiPoleResidue_getPoleResidues,METH_VARARGS,oaPiPoleResidue_getPoleResidues_doc},
    {"getPoleResiduesIter",(PyCFunction)oaPiPoleResidue_getPoleResiduesIter,METH_VARARGS,oaPiPoleResidue_getPoleResiduesIter_doc},
    {"getRes",(PyCFunction)oaPiPoleResidue_getRes,METH_VARARGS,oaPiPoleResidue_getRes_doc},
    {"setFarCap",(PyCFunction)oaPiPoleResidue_setFarCap,METH_VARARGS,oaPiPoleResidue_setFarCap_doc},
    {"setNearCap",(PyCFunction)oaPiPoleResidue_setNearCap,METH_VARARGS,oaPiPoleResidue_setNearCap_doc},
    {"setPiModel",(PyCFunction)oaPiPoleResidue_setPiModel,METH_VARARGS,oaPiPoleResidue_setPiModel_doc},
    {"setRes",(PyCFunction)oaPiPoleResidue_setRes,METH_VARARGS,oaPiPoleResidue_setRes_doc},
    {"isNull",(PyCFunction)oaPiPoleResidue_tp_isNull,METH_VARARGS,oaPiPoleResidue_isNull_doc},
    {"assign",(PyCFunction)oaPiPoleResidue_tp_assign,METH_VARARGS,oaPiPoleResidue_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPiPoleResidue_doc[] = 
"Class: oaPiPoleResidue\n"
"  The oaPiPoleResidue class represents a reduced model for the parasitics seen by a driver of a net using a PI model. The PI model consists of two capacitors and a resistor between them, with nearCap being the capacitor closer to the driver. For each receiver, an oaPoleResidue object represents a set of poles and residues that approximate the transfer function for the interconnect parasitics from the driver to that receiver.\n"
"  Undo is not supported for oaPiPoleResidue objects.\n"
"Constructors:\n"
"  Paramegers: (oaPiPoleResidue)\n"
"    Calls: (const oaPiPoleResidue&)\n"
"    Signature: oaPiPoleResidue||cref-oaPiPoleResidue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPiPoleResidue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPiPoleResidue",
    sizeof(PyoaPiPoleResidueObject),
    0,
    (destructor)oaPiPoleResidue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPiPoleResidue_tp_compare,	/* tp_compare */
    (reprfunc)oaPiPoleResidue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPiPoleResidue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPiPoleResidue_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaReducedModel_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPiPoleResidue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPiPoleResidue_static_create_doc[] = 
"Class: oaPiPoleResidue, Function: create\n"
"  Paramegers: (oaDesignObject,oaAnalysisPoint,oaFloat,oaFloat,oaFloat)\n"
"    Calls: oaPiPoleResidue* create(oaDesignObject* driver,const oaAnalysisPoint* ap,oaFloat nearCap,oaFloat res,oaFloat farCap)\n"
"    Signature: create|ptr-oaPiPoleResidue|ptr-oaDesignObject,cptr-oaAnalysisPoint,simple-oaFloat,simple-oaFloat,simple-oaFloat,\n"
"    This function creates a piPoleResidue model for the specified driver object and analysis point. The driver can be terminal or instTerm in block or occurrence domain.\n"
"    oacInvalidReducedModelDomain\n"
"    oacInvalidReducedModelObjectType\n"
"    oacInvalidDriverTermType\n"
"    oacParasiticTermMustBeScalar\n"
"    oacParasiticInstTermMustBeScalar\n"
;

static PyObject*
oaPiPoleResidue_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDesignObject p1;
    PyParamoaAnalysisPoint p2;
    PyParamoaFloat p3;
    PyParamoaFloat p4;
    PyParamoaFloat p5;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&",
          &PyoaDesignObject_Convert,&p1,
          &PyoaAnalysisPoint_Convert,&p2,
          &PyoaFloat_Convert,&p3,
          &PyoaFloat_Convert,&p4,
          &PyoaFloat_Convert,&p5)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        oaPiPoleResiduep result= (oaPiPoleResidue::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
        return PyoaPiPoleResidue_FromoaPiPoleResidue(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPiPoleResidue_static_find_doc[] = 
"Class: oaPiPoleResidue, Function: find\n"
"  Paramegers: (oaDesignObject,oaAnalysisPoint)\n"
"    Calls: oaPiPoleResidue* find(const oaDesignObject* driver,const oaAnalysisPoint* ap)\n"
"    Signature: find|ptr-oaPiPoleResidue|cptr-oaDesignObject,cptr-oaAnalysisPoint,\n"
"    This function finds the piPoleResidue on the specified driver and analysisPoint. If found it returns the object, otherwise it returns null pointer to the caller.\n"
;

static PyObject*
oaPiPoleResidue_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDesignObject p1;
    PyParamoaAnalysisPoint p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDesignObject_Convert,&p1,
          &PyoaAnalysisPoint_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        oaPiPoleResiduep result= (oaPiPoleResidue::find(p1.Data(),p2.Data()));
        return PyoaPiPoleResidue_FromoaPiPoleResidue(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaPiPoleResidue_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaPiPoleResidue_static_create,METH_VARARGS,oaPiPoleResidue_static_create_doc},
    {"static_find",(PyCFunction)oaPiPoleResidue_static_find,METH_VARARGS,oaPiPoleResidue_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPiPoleResidue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPiPoleResidue_Type)<0) {
      printf("** PyType_Ready failed for: oaPiPoleResidue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPiPoleResidue",
           (PyObject*)(&PyoaPiPoleResidue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPiPoleResidue\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaPiPoleResidue_Type.tp_dict;
    for(method=oaPiPoleResidue_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaPin
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPin_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPin_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPinObject* self = (PyoaPinObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaPin)
    {
        PyParamoaPin p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPin_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaPin, Choices are:\n"
        "    (oaPin)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPin_tp_dealloc(PyoaPinObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPin_tp_repr(PyObject *ob)
{
    PyParamoaPin value;
    int convert_status=PyoaPin_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaPin::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[27];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaPin::");
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
oaPin_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPin v1;
    PyParamoaPin v2;
    int convert_status1=PyoaPin_Convert(ob1,&v1);
    int convert_status2=PyoaPin_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPin_Convert(PyObject* ob,PyParamoaPin* result)
{
    if (ob == NULL) return 1;
    if (PyoaPin_Check(ob)) {
        result->SetData( (oaPin**) ((PyoaPinObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPin Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPin_FromoaPin(oaPin** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaPin* data=*value;
        PyObject* bself = PyoaPin_Type.tp_alloc(&PyoaPin_Type,0);
        if (bself == NULL) return bself;
        PyoaPinObject* self = (PyoaPinObject*)bself;
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
PyObject* PyoaPin_FromoaPin(oaPin* data)
{
    if (data) {
       PyObject* bself = PyoaPin_Type.tp_alloc(&PyoaPin_Type,0);
       if (bself == NULL) return bself;
       PyoaPinObject* self = (PyoaPinObject*)bself;
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
static char oaPin_destroy_doc[] = 
"Class: oaPin, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function removes this pin from the database.\n"
;

static PyObject*
oaPin_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPin data;
    int convert_status=PyoaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinObject* self=(PyoaPinObject*)ob;
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
static char oaPin_getAccessDir_doc[] = 
"Class: oaPin, Function: getAccessDir\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getAccessDir() const\n"
"    Signature: getAccessDir|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the access direction bit-field for this pin.\n"
;

static PyObject*
oaPin_getAccessDir(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPin data;
    int convert_status=PyoaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinObject* self=(PyoaPinObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getAccessDir());
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
static char oaPin_getConnRoutes_doc[] = 
"Class: oaPin, Function: getConnRoutes\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaRoute_oaPin getConnRoutes() const\n"
"    Signature: getConnRoutes|simple-oaCollection_oaRoute_oaPin|\n"
"    BrowseData: 1\n"
"    This function returns a collection of routes connected to this pin. Each route in the collection has this pin as either its startConn, endConn, or both.\n"
;

static PyObject*
oaPin_getConnRoutes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPin data;
    int convert_status=PyoaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinObject* self=(PyoaPinObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaRoute_oaPin* result= new oaCollection_oaRoute_oaPin(data.DataCall()->getConnRoutes());
        return PyoaCollection_oaRoute_oaPin_FromoaCollection_oaRoute_oaPin(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPin_getConnRoutesIter_doc[] = 
"Class: oaPin, Function: getConnRoutesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaRoute getConnRoutesIter() const\n"
"    Signature: getConnRoutesIter|simple-oaIter_oaRoute|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of routes connected to this pin. Each route in the collection has this pin as either its startConn, endConn, or both.\n"
;

static PyObject*
oaPin_getConnRoutesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPin data;
    int convert_status=PyoaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinObject* self=(PyoaPinObject*)ob;
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
static char oaPin_getFigs_doc[] = 
"Class: oaPin, Function: getFigs\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaPinFig_oaPin getFigs() const\n"
"    Signature: getFigs|simple-oaCollection_oaPinFig_oaPin|\n"
"    BrowseData: 1\n"
"    This function returns a collection of figures that are connected with this pin.\n"
;

static PyObject*
oaPin_getFigs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPin data;
    int convert_status=PyoaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinObject* self=(PyoaPinObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaPinFig_oaPin* result= new oaCollection_oaPinFig_oaPin(data.DataCall()->getFigs());
        return PyoaCollection_oaPinFig_oaPin_FromoaCollection_oaPinFig_oaPin(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPin_getFigsIter_doc[] = 
"Class: oaPin, Function: getFigsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaPinFig getFigsIter() const\n"
"    Signature: getFigsIter|simple-oaIter_oaPinFig|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of figures that are connected with this pin.\n"
;

static PyObject*
oaPin_getFigsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPin data;
    int convert_status=PyoaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinObject* self=(PyoaPinObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaPinFig* result= new oaIter_oaPinFig(data.DataCall()->getFigs());
        return PyoaIter_oaPinFig_FromoaIter_oaPinFig(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPin_getName_doc[] = 
"Class: oaPin, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function fills in the name argument with the name of this pin.\n"
;

static PyObject*
oaPin_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPin data;
    int convert_status=PyoaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinObject* self=(PyoaPinObject*)ob;
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
static char oaPin_getPlacementStatus_doc[] = 
"Class: oaPin, Function: getPlacementStatus\n"
"  Paramegers: ()\n"
"    Calls: oaPlacementStatus getPlacementStatus() const\n"
"    Signature: getPlacementStatus|simple-oaPlacementStatus|\n"
"    BrowseData: 1\n"
"    This function returns the placement status of this pin.\n"
;

static PyObject*
oaPin_getPlacementStatus(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPin data;
    int convert_status=PyoaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinObject* self=(PyoaPinObject*)ob;
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
static char oaPin_getTerm_doc[] = 
"Class: oaPin, Function: getTerm\n"
"  Paramegers: ()\n"
"    Calls: oaTerm* getTerm() const\n"
"    Signature: getTerm|ptr-oaTerm|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the terminal to which this pin is attached.\n"
;

static PyObject*
oaPin_getTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPin data;
    int convert_status=PyoaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinObject* self=(PyoaPinObject*)ob;
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
static char oaPin_setAccessDir_doc[] = 
"Class: oaPin, Function: setAccessDir\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setAccessDir(oaUInt4 accessDir)\n"
"    Signature: setAccessDir|void-void|simple-oaUInt4,\n"
"    This function sets the access direction of this pin to the specified value.\n"
"    accessDir\n"
"    The access direction of the pin, specified by OR'ing bits that represent the top, bottom, left, and right directions, referenced as oacTop, oacBottom, oacLeft, and oacRight; a value of oacNone specifies the pin should have no access direction\n"
;

static PyObject*
oaPin_setAccessDir(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPin data;
    int convert_status=PyoaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinObject* self=(PyoaPinObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setAccessDir(p1.Data());
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
static char oaPin_setName_doc[] = 
"Class: oaPin, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function sets the name of this pin to the specified value.\n"
"    name\n"
"    The pin name to set\n"
"    oacPinExists\n"
;

static PyObject*
oaPin_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPin data;
    int convert_status=PyoaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinObject* self=(PyoaPinObject*)ob;
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
static char oaPin_setPlacementStatus_doc[] = 
"Class: oaPin, Function: setPlacementStatus\n"
"  Paramegers: (oaPlacementStatus)\n"
"    Calls: void setPlacementStatus(oaPlacementStatus status)\n"
"    Signature: setPlacementStatus|void-void|simple-oaPlacementStatus,\n"
"    This function sets the placement status of this pin to the specified value.\n"
"    status\n"
"    The status to set\n"
;

static PyObject*
oaPin_setPlacementStatus(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPin data;
    int convert_status=PyoaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinObject* self=(PyoaPinObject*)ob;
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
static char oaPin_setTerm_doc[] = 
"Class: oaPin, Function: setTerm\n"
"  Paramegers: (oaTerm)\n"
"    Calls: void setTerm(oaTerm* term)\n"
"    Signature: setTerm|void-void|ptr-oaTerm,\n"
"    This function sets the terminal for this pin to the specified value. The pin is given a unique name if the pin is explicitly named and if the specified terminal already has a pin with that name.\n"
"    term\n"
"    The terminal to associate with the pin\n"
"    oacTermCannotBeImplicit\n"
;

static PyObject*
oaPin_setTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPin data;
    int convert_status=PyoaPin_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinObject* self=(PyoaPinObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTerm_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setTerm(p1.Data());
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
static char oaPin_isNull_doc[] =
"Class: oaPin, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaPin_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaPin data;
    int convert_status=PyoaPin_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaPin_assign_doc[] = 
"Class: oaPin, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPin_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPin data;
  int convert_status=PyoaPin_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPin p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPin_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPin_methodlist[] = {
    {"destroy",(PyCFunction)oaPin_destroy,METH_VARARGS,oaPin_destroy_doc},
    {"getAccessDir",(PyCFunction)oaPin_getAccessDir,METH_VARARGS,oaPin_getAccessDir_doc},
    {"getConnRoutes",(PyCFunction)oaPin_getConnRoutes,METH_VARARGS,oaPin_getConnRoutes_doc},
    {"getConnRoutesIter",(PyCFunction)oaPin_getConnRoutesIter,METH_VARARGS,oaPin_getConnRoutesIter_doc},
    {"getFigs",(PyCFunction)oaPin_getFigs,METH_VARARGS,oaPin_getFigs_doc},
    {"getFigsIter",(PyCFunction)oaPin_getFigsIter,METH_VARARGS,oaPin_getFigsIter_doc},
    {"getName",(PyCFunction)oaPin_getName,METH_VARARGS,oaPin_getName_doc},
    {"getPlacementStatus",(PyCFunction)oaPin_getPlacementStatus,METH_VARARGS,oaPin_getPlacementStatus_doc},
    {"getTerm",(PyCFunction)oaPin_getTerm,METH_VARARGS,oaPin_getTerm_doc},
    {"setAccessDir",(PyCFunction)oaPin_setAccessDir,METH_VARARGS,oaPin_setAccessDir_doc},
    {"setName",(PyCFunction)oaPin_setName,METH_VARARGS,oaPin_setName_doc},
    {"setPlacementStatus",(PyCFunction)oaPin_setPlacementStatus,METH_VARARGS,oaPin_setPlacementStatus_doc},
    {"setTerm",(PyCFunction)oaPin_setTerm,METH_VARARGS,oaPin_setTerm_doc},
    {"isNull",(PyCFunction)oaPin_tp_isNull,METH_VARARGS,oaPin_isNull_doc},
    {"assign",(PyCFunction)oaPin_tp_assign,METH_VARARGS,oaPin_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPin_doc[] = 
"Class: oaPin\n"
"  The oaPin class implements an object that represents the physical connections of terminals to nets. A terminal can have multiple pins where multiple physical connections can correspond to one logical connection.\n"
"  All pins are associated with a physical figure and are named. These names can be assigned by the creator. For pins associated with scalar terminals, pin names can be automatically assigned by the database.\n"
"  The oaPin class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaPin)\n"
"    Calls: (const oaPin&)\n"
"    Signature: oaPin||cref-oaPin,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPin_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPin",
    sizeof(PyoaPinObject),
    0,
    (destructor)oaPin_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPin_tp_compare,	/* tp_compare */
    (reprfunc)oaPin_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPin_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPin_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBlockObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPin_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPin_static_create_doc[] = 
"Class: oaPin, Function: create\n"
"  Paramegers: (oaTerm)\n"
"    Calls: oaPin* create(oaTerm* term)\n"
"    Signature: create|ptr-oaPin|ptr-oaTerm,simple-oaUInt4,\n"
"    This function creates a pin on the specified terminal. The pin receives the specified access direction. The pin name is automatically generated, with the default prefix P__%d, d referring to a unique integer.\n"
"    term\n"
"    The terminal on which to create the pin\n"
"    accessDir\n"
"    The access direction of the pin, specified by OR'ing bits that represent the top, bottom, left, and right directions, referenced as oacTop, oacBottom, oacLeft, and oacRight; a value of oacNone specifies the pin should have no access direction.\n"
"    A pointer to the oaPin\n"
"    oacTermCannotBeImplicit\n"
"    oacInvalidAccessDirForPin\n"
"  Paramegers: (oaTerm,oaUInt4)\n"
"    Calls: oaPin* create(oaTerm* term,oaUInt4 accessDir)\n"
"    Signature: create|ptr-oaPin|ptr-oaTerm,simple-oaUInt4,\n"
"    This function creates a pin on the specified terminal. The pin receives the specified access direction. The pin name is automatically generated, with the default prefix P__%d, d referring to a unique integer.\n"
"    term\n"
"    The terminal on which to create the pin\n"
"    accessDir\n"
"    The access direction of the pin, specified by OR'ing bits that represent the top, bottom, left, and right directions, referenced as oacTop, oacBottom, oacLeft, and oacRight; a value of oacNone specifies the pin should have no access direction.\n"
"    A pointer to the oaPin\n"
"    oacTermCannotBeImplicit\n"
"    oacInvalidAccessDirForPin\n"
"  Paramegers: (oaTerm,oaString)\n"
"    Calls: oaPin* create(oaTerm* term,const oaString& name)\n"
"    Signature: create|ptr-oaPin|ptr-oaTerm,cref-oaString,simple-oaUInt4,\n"
"    This function creates a pin on the specified terminal. The pin receives the specified access direction and name.\n"
"    term\n"
"    The terminal on which to create the pin\n"
"    name\n"
"    The pin name\n"
"    accessDir\n"
"    The access direction of the pin, specified by OR'ing bits that represent the top, bottom, left, and right directions, referenced as oacTop, oacBottom, oacLeft, and oacRight; a value of oacNone specifies the pin should have no access direction\n"
"    A pointer to the oaPin\n"
"    oacTermCannotBeImplicit\n"
"    oacInvalidAccessDirForPin\n"
"    oacPinExists\n"
"  Paramegers: (oaTerm,oaString,oaUInt4)\n"
"    Calls: oaPin* create(oaTerm* term,const oaString& name,oaUInt4 accessDir)\n"
"    Signature: create|ptr-oaPin|ptr-oaTerm,cref-oaString,simple-oaUInt4,\n"
"    This function creates a pin on the specified terminal. The pin receives the specified access direction and name.\n"
"    term\n"
"    The terminal on which to create the pin\n"
"    name\n"
"    The pin name\n"
"    accessDir\n"
"    The access direction of the pin, specified by OR'ing bits that represent the top, bottom, left, and right directions, referenced as oacTop, oacBottom, oacLeft, and oacRight; a value of oacNone specifies the pin should have no access direction\n"
"    A pointer to the oaPin\n"
"    oacTermCannotBeImplicit\n"
"    oacInvalidAccessDirForPin\n"
"    oacPinExists\n"
;

static PyObject*
oaPin_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaTerm)
    {
        PyParamoaTerm p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaTerm_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPinp result= (oaPin::create(p1.Data()));
            return PyoaPin_FromoaPin(result);
        }
    }
    PyErr_Clear();
    // Case: (oaTerm,oaUInt4)
    {
        PyParamoaTerm p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaTerm_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPinp result= (oaPin::create(p1.Data(),p2.Data()));
            return PyoaPin_FromoaPin(result);
        }
    }
    PyErr_Clear();
    // Case: (oaTerm,oaString)
    {
        PyParamoaTerm p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaTerm_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPinp result= (oaPin::create(p1.Data(),p2.Data()));
            return PyoaPin_FromoaPin(result);
        }
    }
    PyErr_Clear();
    // Case: (oaTerm,oaString,oaUInt4)
    {
        PyParamoaTerm p1;
        PyParamoaString p2;
        PyParamoaUInt4 p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaTerm_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaUInt4_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPinp result= (oaPin::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaPin_FromoaPin(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaPin, function: create, Choices are:\n"
        "    (oaTerm)\n"
        "    (oaTerm,oaUInt4)\n"
        "    (oaTerm,oaString)\n"
        "    (oaTerm,oaString,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPin_static_find_doc[] = 
"Class: oaPin, Function: find\n"
"  Paramegers: (oaTerm,oaString)\n"
"    Calls: oaPin* find(const oaTerm* term,const oaString& name)\n"
"    Signature: find|ptr-oaPin|cptr-oaTerm,cref-oaString,\n"
"    This function searches the specified terminal for a pin with the specified name.\n"
"    term\n"
"    The terminal to search\n"
"    name\n"
"    The pin name to find\n"
"    A pointer to the oaPin, if found; otherwise, NULL is returned\n"
;

static PyObject*
oaPin_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaTerm p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaTerm_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaPinp result= (oaPin::find(p1.Data(),p2.Data()));
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
static PyMethodDef oaPin_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaPin_static_create,METH_VARARGS,oaPin_static_create_doc},
    {"static_find",(PyCFunction)oaPin_static_find,METH_VARARGS,oaPin_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPin_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPin_Type)<0) {
      printf("** PyType_Ready failed for: oaPin\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPin",
           (PyObject*)(&PyoaPin_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPin\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaPin_Type.tp_dict;
    for(method=oaPin_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaPinConnectMethod
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPinConnectMethod_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPinConnectMethod_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPinConnectMethodObject* self = (PyoaPinConnectMethodObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaPinConnectMethodEnum)
    {
        PyParamoaPinConnectMethodEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaPinConnectMethodEnum_Convert,&p1)) {
            self->value =  new oaPinConnectMethod(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaPinConnectMethod(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaPinConnectMethod)
    {
        PyParamoaPinConnectMethod p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPinConnectMethod_Convert,&p1)) {
            self->value= new oaPinConnectMethod(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaPinConnectMethod, Choices are:\n"
        "    (oaPinConnectMethodEnum)\n"
        "    (oaString)\n"
        "    (oaPinConnectMethod)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPinConnectMethod_tp_dealloc(PyoaPinConnectMethodObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPinConnectMethod_tp_repr(PyObject *ob)
{
    PyParamoaPinConnectMethod value;
    int convert_status=PyoaPinConnectMethod_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[40];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaPinConnectMethod::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaPinConnectMethod_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPinConnectMethod v1;
    PyParamoaPinConnectMethod v2;
    int convert_status1=PyoaPinConnectMethod_Convert(ob1,&v1);
    int convert_status2=PyoaPinConnectMethod_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPinConnectMethod_Convert(PyObject* ob,PyParamoaPinConnectMethod* result)
{
    if (ob == NULL) return 1;
    if (PyoaPinConnectMethod_Check(ob)) {
        result->SetData(  ((PyoaPinConnectMethodObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPinConnectMethod Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPinConnectMethod_FromoaPinConnectMethod(oaPinConnectMethod* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaPinConnectMethod_Type.tp_alloc(&PyoaPinConnectMethod_Type,0);
        if (bself == NULL) return bself;
        PyoaPinConnectMethodObject* self = (PyoaPinConnectMethodObject*)bself;
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
static char oaPinConnectMethod_getName_doc[] = 
"Class: oaPinConnectMethod, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName()\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaPinConnectMethodEnum object.\n"
;

static PyObject*
oaPinConnectMethod_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPinConnectMethod data;
    int convert_status=PyoaPinConnectMethod_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinConnectMethodObject* self=(PyoaPinConnectMethodObject*)ob;

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
static char oaPinConnectMethod_oaPinConnectMethodEnum_doc[] = 
"Class: oaPinConnectMethod, Function: oaPinConnectMethodEnum\n"
"  Paramegers: ()\n"
"    Calls: oaPinConnectMethodEnum oaPinConnectMethodEnum() const\n"
"    Signature: operator oaPinConnectMethodEnum|simple-oaPinConnectMethodEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaPinConnectMethod object into the corresponding #oaPinConnectMethodEnum value.\n"
;

static PyObject*
oaPinConnectMethod_oaPinConnectMethodEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPinConnectMethod data;
    int convert_status=PyoaPinConnectMethod_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinConnectMethodObject* self=(PyoaPinConnectMethodObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPinConnectMethodEnum result= (data.DataCall()->operator oaPinConnectMethodEnum());
        return PyoaPinConnectMethodEnum_FromoaPinConnectMethodEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaPinConnectMethod_assign_doc[] = 
"Class: oaPinConnectMethod, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPinConnectMethod_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPinConnectMethod data;
  int convert_status=PyoaPinConnectMethod_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPinConnectMethod p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPinConnectMethod_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPinConnectMethod_methodlist[] = {
    {"getName",(PyCFunction)oaPinConnectMethod_getName,METH_VARARGS,oaPinConnectMethod_getName_doc},
    {"oaPinConnectMethodEnum",(PyCFunction)oaPinConnectMethod_oaPinConnectMethodEnum,METH_VARARGS,oaPinConnectMethod_oaPinConnectMethodEnum_doc},
    {"assign",(PyCFunction)oaPinConnectMethod_tp_assign,METH_VARARGS,oaPinConnectMethod_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPinConnectMethod_doc[] = 
"Class: oaPinConnectMethod\n"
"  The oaPinConnectMethod class is an enum wrapper class that describes the various ways that the pins for a given terminal may connect to their net. See oaTerm::getPinConnectMethod for its usage.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaPinConnectMethodEnum\n"
"Constructors:\n"
"  Paramegers: (oaPinConnectMethodEnum)\n"
"    Calls: oaPinConnectMethod(oaPinConnectMethodEnum valIn)\n"
"    Signature: oaPinConnectMethod||simple-oaPinConnectMethodEnum,\n"
"    This function constructs an instance of an oaPinConnectMethod class using the specified enum value. The enum values are defined in #oaPinConnectMethodEnum.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaPinConnectMethod(const oaString& name)\n"
"    Signature: oaPinConnectMethod||cref-oaString,\n"
"    This function constructs an instance of an oaPinConnectMethod class using the #oaPinConnectMethodEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaPinConnectMethodEnum.\n"
"    oacInvalidPinConnectMethodName\n"
"  Paramegers: (oaPinConnectMethod)\n"
"    Calls: (const oaPinConnectMethod&)\n"
"    Signature: oaPinConnectMethod||cref-oaPinConnectMethod,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPinConnectMethod_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPinConnectMethod",
    sizeof(PyoaPinConnectMethodObject),
    0,
    (destructor)oaPinConnectMethod_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPinConnectMethod_tp_compare,	/* tp_compare */
    (reprfunc)oaPinConnectMethod_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPinConnectMethod_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPinConnectMethod_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPinConnectMethod_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPinConnectMethod_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPinConnectMethod_Type)<0) {
      printf("** PyType_Ready failed for: oaPinConnectMethod\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPinConnectMethod",
           (PyObject*)(&PyoaPinConnectMethod_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPinConnectMethod\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaPinConnectMethodEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaPinConnectMethodEnum_Convert(PyObject* ob,PyParamoaPinConnectMethodEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacDefaultPinConnectMethod")==0) { result->SetData(oacDefaultPinConnectMethod); return 1;}
        if (strcasecmp(str,"oacRingPinConnectMethod")==0) { result->SetData(oacRingPinConnectMethod); return 1;}
        if (strcasecmp(str,"oacAbutPinConnectMethod")==0) { result->SetData(oacAbutPinConnectMethod); return 1;}
        if (strcasecmp(str,"oacFeedthruPinConnectMethod")==0) { result->SetData(oacFeedthruPinConnectMethod); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaPinConnectMethodEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPinConnectMethodEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaPinConnectMethodEnum_FromoaPinConnectMethodEnum(oaPinConnectMethodEnum ob)
{
    if (ob==oacDefaultPinConnectMethod) return PyString_FromString("oacDefaultPinConnectMethod");
    if (ob==oacRingPinConnectMethod) return PyString_FromString("oacRingPinConnectMethod");
    if (ob==oacAbutPinConnectMethod) return PyString_FromString("oacAbutPinConnectMethod");
    if (ob==oacFeedthruPinConnectMethod) return PyString_FromString("oacFeedthruPinConnectMethod");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaPinConnectMethodEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaPinConnectMethodEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaPinConnectMethodEnum_FromoaPinConnectMethodEnum(oaPinConnectMethodEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaPinConnectMethodEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaPinConnectMethodEnum_doc[] =
"Type convert function for enum: oaPinConnectMethodEnum";
                               
static PyMethodDef PyoaPinConnectMethodEnum_method =
  {"oaPinConnectMethodEnum",(PyCFunction)PyoaPinConnectMethodEnum_TypeFunction,METH_VARARGS,oaPinConnectMethodEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaPinConnectMethodEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacDefaultPinConnectMethod");
    PyDict_SetItemString(mod_dict,"oacDefaultPinConnectMethod",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRingPinConnectMethod");
    PyDict_SetItemString(mod_dict,"oacRingPinConnectMethod",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAbutPinConnectMethod");
    PyDict_SetItemString(mod_dict,"oacAbutPinConnectMethod",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFeedthruPinConnectMethod");
    PyDict_SetItemString(mod_dict,"oacFeedthruPinConnectMethod",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaPinConnectMethodEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaPinConnectMethodEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaPinConnectMethodEnum\n");
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
// Wrapper Implementation for Class: oaPinFig
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPinFig_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPinFig_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPinFigObject* self = (PyoaPinFigObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaPinFig)
    {
        PyParamoaPinFig p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPinFig_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaPinFig, Choices are:\n"
        "    (oaPinFig)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPinFig_tp_dealloc(PyoaPinFigObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPinFig_tp_repr(PyObject *ob)
{
    PyParamoaPinFig value;
    int convert_status=PyoaPinFig_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[30];
    sprintf(buffer,"<oaPinFig::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaPinFig_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPinFig v1;
    PyParamoaPinFig v2;
    int convert_status1=PyoaPinFig_Convert(ob1,&v1);
    int convert_status2=PyoaPinFig_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPinFig_Convert(PyObject* ob,PyParamoaPinFig* result)
{
    if (ob == NULL) return 1;
    if (PyoaPinFig_Check(ob)) {
        result->SetData( (oaPinFig**) ((PyoaPinFigObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPinFig Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPinFig_FromoaPinFig(oaPinFig** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaPinFig* data=*value;
        if (data->isShape()) return PyoaShape_FromoaShape((oaShape**)value,borrow,lock);
        if (data->isRef()) return PyoaRef_FromoaRef((oaRef**)value,borrow,lock);
        PyObject* bself = PyoaPinFig_Type.tp_alloc(&PyoaPinFig_Type,0);
        if (bself == NULL) return bself;
        PyoaPinFigObject* self = (PyoaPinFigObject*)bself;
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
PyObject* PyoaPinFig_FromoaPinFig(oaPinFig* data)
{
    if (data) {
        if (data->isShape()) return PyoaShape_FromoaShape((oaShape*)data);
        if (data->isRef()) return PyoaRef_FromoaRef((oaRef*)data);
       PyObject* bself = PyoaPinFig_Type.tp_alloc(&PyoaPinFig_Type,0);
       if (bself == NULL) return bself;
       PyoaPinFigObject* self = (PyoaPinFigObject*)bself;
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
static char oaPinFig_addToPin_doc[] = 
"Class: oaPinFig, Function: addToPin\n"
"  Paramegers: (oaPin)\n"
"    Calls: void addToPin(oaPin* pin)\n"
"    Signature: addToPin|void-void|ptr-oaPin,\n"
"    This function adds this figure to the specified pin. If this figure is already connected to another pin, it is detached from the other pin first.\n"
"    pin\n"
"    The pin to attach the figure to\n"
"    oacCannotAddNetFigToPin\n"
"    oacCannotAddRouteFigToPin\n"
"    oacPinAndFigNotInSameBlock\n"
;

static PyObject*
oaPinFig_addToPin(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPinFig data;
    int convert_status=PyoaPinFig_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinFigObject* self=(PyoaPinFigObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPin p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPin_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->addToPin(p1.Data());
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
static char oaPinFig_getPin_doc[] = 
"Class: oaPinFig, Function: getPin\n"
"  Paramegers: ()\n"
"    Calls: oaPin* getPin() const\n"
"    Signature: getPin|ptr-oaPin|\n"
"    BrowseData: 1\n"
"    This function returns the pin this figure implements. If this figure does not implement a pin, NULL is returned.\n"
;

static PyObject*
oaPinFig_getPin(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPinFig data;
    int convert_status=PyoaPinFig_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinFigObject* self=(PyoaPinFigObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaPinp result= (data.DataCall()->getPin());
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
static char oaPinFig_hasPin_doc[] = 
"Class: oaPinFig, Function: hasPin\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasPin() const\n"
"    Signature: hasPin|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this figure implements a pin.\n"
;

static PyObject*
oaPinFig_hasPin(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPinFig data;
    int convert_status=PyoaPinFig_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinFigObject* self=(PyoaPinFigObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasPin());
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
static char oaPinFig_removeFromPin_doc[] = 
"Class: oaPinFig, Function: removeFromPin\n"
"  Paramegers: ()\n"
"    Calls: void removeFromPin()\n"
"    Signature: removeFromPin|void-void|\n"
"    BrowseData: 0\n"
"    This function removes this figure from the pin to which it is attached. If this figure is not attached to a pin, this function does nothing.\n"
;

static PyObject*
oaPinFig_removeFromPin(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPinFig data;
    int convert_status=PyoaPinFig_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPinFigObject* self=(PyoaPinFigObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->removeFromPin();
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
static char oaPinFig_isNull_doc[] =
"Class: oaPinFig, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaPinFig_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaPinFig data;
    int convert_status=PyoaPinFig_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaPinFig_assign_doc[] = 
"Class: oaPinFig, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPinFig_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPinFig data;
  int convert_status=PyoaPinFig_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPinFig p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPinFig_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPinFig_methodlist[] = {
    {"addToPin",(PyCFunction)oaPinFig_addToPin,METH_VARARGS,oaPinFig_addToPin_doc},
    {"getPin",(PyCFunction)oaPinFig_getPin,METH_VARARGS,oaPinFig_getPin_doc},
    {"hasPin",(PyCFunction)oaPinFig_hasPin,METH_VARARGS,oaPinFig_hasPin_doc},
    {"removeFromPin",(PyCFunction)oaPinFig_removeFromPin,METH_VARARGS,oaPinFig_removeFromPin_doc},
    {"isNull",(PyCFunction)oaPinFig_tp_isNull,METH_VARARGS,oaPinFig_isNull_doc},
    {"assign",(PyCFunction)oaPinFig_tp_assign,METH_VARARGS,oaPinFig_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPinFig_doc[] = 
"Class: oaPinFig\n"
"  The oaPinFig class is an abstract class that is the base for all OpenAccess database figures that can represent pins, including instances, shapes and vias.\n"
"Constructors:\n"
"  Paramegers: (oaPinFig)\n"
"    Calls: (const oaPinFig&)\n"
"    Signature: oaPinFig||cref-oaPinFig,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPinFig_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPinFig",
    sizeof(PyoaPinFigObject),
    0,
    (destructor)oaPinFig_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPinFig_tp_compare,	/* tp_compare */
    (reprfunc)oaPinFig_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPinFig_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPinFig_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConnFig_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPinFig_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPinFig_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPinFig_Type)<0) {
      printf("** PyType_Ready failed for: oaPinFig\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPinFig",
           (PyObject*)(&PyoaPinFig_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPinFig\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaPinModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaPinModTypeEnum_Convert(PyObject* ob,PyParamoaPinModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetTermPinModType")==0) { result->SetData(oacSetTermPinModType); return 1;}
        if (strcasecmp(str,"oacSetNamePinModType")==0) { result->SetData(oacSetNamePinModType); return 1;}
        if (strcasecmp(str,"oacSetAccessDirPinModType")==0) { result->SetData(oacSetAccessDirPinModType); return 1;}
        if (strcasecmp(str,"oacSetPlacementStatusPinModType")==0) { result->SetData(oacSetPlacementStatusPinModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaPinModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPinModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaPinModTypeEnum_FromoaPinModTypeEnum(oaPinModTypeEnum ob)
{
    if (ob==oacSetTermPinModType) return PyString_FromString("oacSetTermPinModType");
    if (ob==oacSetNamePinModType) return PyString_FromString("oacSetNamePinModType");
    if (ob==oacSetAccessDirPinModType) return PyString_FromString("oacSetAccessDirPinModType");
    if (ob==oacSetPlacementStatusPinModType) return PyString_FromString("oacSetPlacementStatusPinModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaPinModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaPinModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaPinModTypeEnum_FromoaPinModTypeEnum(oaPinModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaPinModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaPinModTypeEnum_doc[] =
"Type convert function for enum: oaPinModTypeEnum";
                               
static PyMethodDef PyoaPinModTypeEnum_method =
  {"oaPinModTypeEnum",(PyCFunction)PyoaPinModTypeEnum_TypeFunction,METH_VARARGS,oaPinModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaPinModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetTermPinModType");
    PyDict_SetItemString(mod_dict,"oacSetTermPinModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetNamePinModType");
    PyDict_SetItemString(mod_dict,"oacSetNamePinModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetAccessDirPinModType");
    PyDict_SetItemString(mod_dict,"oacSetAccessDirPinModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetPlacementStatusPinModType");
    PyDict_SetItemString(mod_dict,"oacSetPlacementStatusPinModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaPinModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaPinModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaPinModTypeEnum\n");
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
// Wrapper Implementation for Class: oaPlacementStatus
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPlacementStatus_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPlacementStatus_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPlacementStatusObject* self = (PyoaPlacementStatusObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaPlacementStatusEnum)
    {
        PyParamoaPlacementStatusEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaPlacementStatusEnum_Convert,&p1)) {
            self->value =  new oaPlacementStatus(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaPlacementStatus(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaPlacementStatus)
    {
        PyParamoaPlacementStatus p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPlacementStatus_Convert,&p1)) {
            self->value= new oaPlacementStatus(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaPlacementStatus, Choices are:\n"
        "    (oaPlacementStatusEnum)\n"
        "    (oaString)\n"
        "    (oaPlacementStatus)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPlacementStatus_tp_dealloc(PyoaPlacementStatusObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPlacementStatus_tp_repr(PyObject *ob)
{
    PyParamoaPlacementStatus value;
    int convert_status=PyoaPlacementStatus_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[39];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaPlacementStatus::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaPlacementStatus_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPlacementStatus v1;
    PyParamoaPlacementStatus v2;
    int convert_status1=PyoaPlacementStatus_Convert(ob1,&v1);
    int convert_status2=PyoaPlacementStatus_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPlacementStatus_Convert(PyObject* ob,PyParamoaPlacementStatus* result)
{
    if (ob == NULL) return 1;
    if (PyoaPlacementStatus_Check(ob)) {
        result->SetData(  ((PyoaPlacementStatusObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPlacementStatus Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPlacementStatus_FromoaPlacementStatus(oaPlacementStatus* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaPlacementStatus_Type.tp_alloc(&PyoaPlacementStatus_Type,0);
        if (bself == NULL) return bself;
        PyoaPlacementStatusObject* self = (PyoaPlacementStatusObject*)bself;
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
static char oaPlacementStatus_getName_doc[] = 
"Class: oaPlacementStatus, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated oaPlacementStatusEnum object.\n"
;

static PyObject*
oaPlacementStatus_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPlacementStatus data;
    int convert_status=PyoaPlacementStatus_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPlacementStatusObject* self=(PyoaPlacementStatusObject*)ob;

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
static char oaPlacementStatus_oaPlacementStatusEnum_doc[] = 
"Class: oaPlacementStatus, Function: oaPlacementStatusEnum\n"
"  Paramegers: ()\n"
"    Calls: oaPlacementStatusEnum oaPlacementStatusEnum() const\n"
"    Signature: operator oaPlacementStatusEnum|simple-oaPlacementStatusEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaPlacementStatus object into the corresponding oaPlacementStatusEnum.\n"
;

static PyObject*
oaPlacementStatus_oaPlacementStatusEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPlacementStatus data;
    int convert_status=PyoaPlacementStatus_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPlacementStatusObject* self=(PyoaPlacementStatusObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPlacementStatusEnum result= (data.DataCall()->operator oaPlacementStatusEnum());
        return PyoaPlacementStatusEnum_FromoaPlacementStatusEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaPlacementStatus_assign_doc[] = 
"Class: oaPlacementStatus, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPlacementStatus_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPlacementStatus data;
  int convert_status=PyoaPlacementStatus_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPlacementStatus p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPlacementStatus_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPlacementStatus_methodlist[] = {
    {"getName",(PyCFunction)oaPlacementStatus_getName,METH_VARARGS,oaPlacementStatus_getName_doc},
    {"oaPlacementStatusEnum",(PyCFunction)oaPlacementStatus_oaPlacementStatusEnum,METH_VARARGS,oaPlacementStatus_oaPlacementStatusEnum_doc},
    {"assign",(PyCFunction)oaPlacementStatus_tp_assign,METH_VARARGS,oaPlacementStatus_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPlacementStatus_doc[] = 
"Class: oaPlacementStatus\n"
"  The oaPlacementStatus class encapsulates the enumerated values that describe the different placement status you can assign to an instance or a pin.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaPlacementStatusEnum\n"
"Constructors:\n"
"  Paramegers: (oaPlacementStatusEnum)\n"
"    Calls: oaPlacementStatus(oaPlacementStatusEnum valueIn)\n"
"    Signature: oaPlacementStatus||simple-oaPlacementStatusEnum,\n"
"    This function constructs an instance of an oaPlacementStatus class using the specified oaPlacementStatusEnum value.\n"
"    valueIn\n"
"    an oaPlacementStatusEnum value\n"
"  Paramegers: (oaString)\n"
"    Calls: oaPlacementStatus(const oaString& name)\n"
"    Signature: oaPlacementStatus||cref-oaString,\n"
"    This function constructs an instance of an oaPlacementStatus class using the oaPlacementStatusEnum associated with the specified string name . This name must be defined in the legal set of names associated with oaPlacementStatusEnum.\n"
"    name\n"
"    an oaPlacementStatusEnum string name\n"
"    oacInvalidPlacementStatusTypeName\n"
"  Paramegers: (oaPlacementStatus)\n"
"    Calls: (const oaPlacementStatus&)\n"
"    Signature: oaPlacementStatus||cref-oaPlacementStatus,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPlacementStatus_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPlacementStatus",
    sizeof(PyoaPlacementStatusObject),
    0,
    (destructor)oaPlacementStatus_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPlacementStatus_tp_compare,	/* tp_compare */
    (reprfunc)oaPlacementStatus_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPlacementStatus_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPlacementStatus_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPlacementStatus_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPlacementStatus_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPlacementStatus_Type)<0) {
      printf("** PyType_Ready failed for: oaPlacementStatus\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPlacementStatus",
           (PyObject*)(&PyoaPlacementStatus_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPlacementStatus\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaPlacementStatusEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaPlacementStatusEnum_Convert(PyObject* ob,PyParamoaPlacementStatusEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacNonePlacementStatus")==0) { result->SetData(oacNonePlacementStatus); return 1;}
        if (strcasecmp(str,"oacUnplacedPlacementStatus")==0) { result->SetData(oacUnplacedPlacementStatus); return 1;}
        if (strcasecmp(str,"oacPlacedPlacementStatus")==0) { result->SetData(oacPlacedPlacementStatus); return 1;}
        if (strcasecmp(str,"oacFixedPlacementStatus")==0) { result->SetData(oacFixedPlacementStatus); return 1;}
        if (strcasecmp(str,"oacLockedPlacementStatus")==0) { result->SetData(oacLockedPlacementStatus); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaPlacementStatusEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPlacementStatusEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaPlacementStatusEnum_FromoaPlacementStatusEnum(oaPlacementStatusEnum ob)
{
    if (ob==oacNonePlacementStatus) return PyString_FromString("oacNonePlacementStatus");
    if (ob==oacUnplacedPlacementStatus) return PyString_FromString("oacUnplacedPlacementStatus");
    if (ob==oacPlacedPlacementStatus) return PyString_FromString("oacPlacedPlacementStatus");
    if (ob==oacFixedPlacementStatus) return PyString_FromString("oacFixedPlacementStatus");
    if (ob==oacLockedPlacementStatus) return PyString_FromString("oacLockedPlacementStatus");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaPlacementStatusEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaPlacementStatusEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaPlacementStatusEnum_FromoaPlacementStatusEnum(oaPlacementStatusEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaPlacementStatusEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaPlacementStatusEnum_doc[] =
"Type convert function for enum: oaPlacementStatusEnum";
                               
static PyMethodDef PyoaPlacementStatusEnum_method =
  {"oaPlacementStatusEnum",(PyCFunction)PyoaPlacementStatusEnum_TypeFunction,METH_VARARGS,oaPlacementStatusEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaPlacementStatusEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacNonePlacementStatus");
    PyDict_SetItemString(mod_dict,"oacNonePlacementStatus",value);
    Py_DECREF(value);
    value=PyString_FromString("oacUnplacedPlacementStatus");
    PyDict_SetItemString(mod_dict,"oacUnplacedPlacementStatus",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPlacedPlacementStatus");
    PyDict_SetItemString(mod_dict,"oacPlacedPlacementStatus",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFixedPlacementStatus");
    PyDict_SetItemString(mod_dict,"oacFixedPlacementStatus",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLockedPlacementStatus");
    PyDict_SetItemString(mod_dict,"oacLockedPlacementStatus",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaPlacementStatusEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaPlacementStatusEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaPlacementStatusEnum\n");
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
// Wrapper Implementation for Class: oaPoint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPoint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPoint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPointObject* self = (PyoaPointObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaPoint();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaCoord,oaCoord)
    {
        PyParamoaCoord p1;
        PyParamoaCoord p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaCoord_Convert,&p1,
              &PyoaCoord_Convert,&p2)) {
            self->value =  new oaPoint(p1.Data(),p2.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaPoint,oaTransform)
    {
        PyParamoaPoint p1;
        PyParamoaTransform p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaPoint_Convert,&p1,
              &PyoaTransform_Convert,&p2)) {
            self->value =  new oaPoint(p1.Data(),p2.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaPoint)
    {
        PyParamoaPoint p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPoint_Convert,&p1)) {
            self->value= new oaPoint(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaPoint, Choices are:\n"
        "    ()\n"
        "    (oaCoord,oaCoord)\n"
        "    (oaPoint,oaTransform)\n"
        "    (oaPoint)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPoint_tp_dealloc(PyoaPointObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPoint_tp_repr(PyObject *ob)
{
    PyParamoaPoint value;
    int convert_status=PyoaPoint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaChar sresult[64];
    sprintf(sresult,"[%d,%d]",value.DataCall()->x(),value.DataCall()->y());

    char addr[29];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaPoint::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaPoint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPoint v1;
    PyParamoaPoint v2;
    int convert_status1=PyoaPoint_Convert(ob1,&v1);
    int convert_status2=PyoaPoint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    if (v1.Data()==v2.Data()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPoint_Convert(PyObject* ob,PyParamoaPoint* result)
{
    if (ob == NULL) return 1;
    if (PyoaPoint_Check(ob)) {
        result->SetData(  ((PyoaPointObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPoint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPoint_FromoaPoint(oaPoint* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaPoint_Type.tp_alloc(&PyoaPoint_Type,0);
        if (bself == NULL) return bself;
        PyoaPointObject* self = (PyoaPointObject*)bself;
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
PyObject* PyoaPoint_FromoaPoint(const oaPoint& data)
{
    PyObject* bself = PyoaPoint_Type.tp_alloc(&PyoaPoint_Type,0);
    if (bself == NULL) return bself;
    PyoaPointObject* self = (PyoaPointObject*)bself;
    self->value =  new oaPoint(data);
    self->borrow = 0;
    self->locks = NULL;
    return bself;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPoint_distanceFrom2_doc[] = 
"Class: oaPoint, Function: distanceFrom2\n"
"  Paramegers: (oaPoint)\n"
"    Calls: oaDouble distanceFrom2(const oaPoint& point) const\n"
"    Signature: distanceFrom2|simple-oaDouble|cref-oaPoint,\n"
"    This function returns the square of the distance from this point to the specified point.\n"
"    point\n"
"    The reference point\n"
"    The square of the distance from this point to the specified point\n"
;

static PyObject*
oaPoint_distanceFrom2(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPoint data;
    int convert_status=PyoaPoint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPointObject* self=(PyoaPointObject*)ob;

    PyParamoaPoint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPoint_Convert,&p1)) {
        oaDouble result= (data.DataCall()->distanceFrom2(p1.Data()));
        return PyoaDouble_FromoaDouble(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPoint_set_doc[] = 
"Class: oaPoint, Function: set\n"
"  Paramegers: (oaCoord,oaCoord)\n"
"    Calls: void set(oaCoord x,oaCoord y)\n"
"    Signature: set|void-void|simple-oaCoord,simple-oaCoord,\n"
"    This function sets both coordinates of the point at once.\n"
"    x\n"
"    x-coordinate\n"
"    y\n"
"    y-coordinate\n"
;

static PyObject*
oaPoint_set(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPoint data;
    int convert_status=PyoaPoint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPointObject* self=(PyoaPointObject*)ob;

    PyParamoaCoord p1;
    PyParamoaCoord p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaCoord_Convert,&p1,
          &PyoaCoord_Convert,&p2)) {
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
static char oaPoint_transform_doc[] = 
"Class: oaPoint, Function: transform\n"
"  Paramegers: (oaTransform,oaPoint)\n"
"    Calls: void transform(const oaTransform& xform,oaPoint& result) const\n"
"    Signature: transform|void-void|cref-oaTransform,ref-oaPoint,\n"
"    This function transforms this point with the specified transform. The result is stored in result , which can be the same point.\n"
"    xform\n"
"    The transform value\n"
"    result\n"
"    The resulting transformation value\n"
"    The transformation value\n"
"  Paramegers: (oaTransform)\n"
"    Calls: void transform(const oaTransform& xform)\n"
"    Signature: transform|void-void|cref-oaTransform,\n"
"    This function transforms a point by the specified transform value and replaces the original point with the result.\n"
"    xform\n"
"    The transform value\n"
"  Paramegers: (oaDouble,oaDouble,oaPoint)\n"
"    Calls: void transform(oaDouble scale,oaDouble angle,oaPoint& result) const\n"
"    Signature: transform|void-void|simple-oaDouble,simple-oaDouble,ref-oaPoint,\n"
"    This function transforms this point by the specified scale factor and rotation angle . The point is rotated about the origin. The result is stored in 'result', which can be the same point.\n"
"  Paramegers: (oaDouble,oaDouble)\n"
"    Calls: void transform(oaDouble scale,oaDouble angle)\n"
"    Signature: transform|void-void|simple-oaDouble,simple-oaDouble,\n"
"    This function transforms this point by the specified scale factor and rotation angle . The point is rotated about the origin.\n"
;

static PyObject*
oaPoint_transform(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPoint data;
    int convert_status=PyoaPoint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPointObject* self=(PyoaPointObject*)ob;

    // Case: (oaTransform,oaPoint)
    {
        PyParamoaTransform p1;
        PyParamoaPoint p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaTransform_Convert,&p1,
              &PyoaPoint_Convert,&p2)) {
            data.DataCall()->transform(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaTransform)
    {
        PyParamoaTransform p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaTransform_Convert,&p1)) {
            data.DataCall()->transform(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDouble,oaDouble,oaPoint)
    {
        PyParamoaDouble p1;
        PyParamoaDouble p2;
        PyParamoaPoint p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaDouble_Convert,&p1,
              &PyoaDouble_Convert,&p2,
              &PyoaPoint_Convert,&p3)) {
            data.DataCall()->transform(p1.Data(),p2.Data(),p3.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDouble,oaDouble)
    {
        PyParamoaDouble p1;
        PyParamoaDouble p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaDouble_Convert,&p1,
              &PyoaDouble_Convert,&p2)) {
            data.DataCall()->transform(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaPoint, function: transform, Choices are:\n"
        "    (oaTransform,oaPoint)\n"
        "    (oaTransform)\n"
        "    (oaDouble,oaDouble,oaPoint)\n"
        "    (oaDouble,oaDouble)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPoint_x_doc[] = 
"Class: oaPoint, Function: x\n"
"  Paramegers: ()\n"
"    Calls: oaCoord& x()\n"
"    Signature: x|ref-oaCoord|\n"
"    BrowseData: 1\n"
"    This function returns the reference of the X value of this point.\n"
;

static PyObject*
oaPoint_x(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPoint data;
    int convert_status=PyoaPoint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPointObject* self=(PyoaPointObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaCoord* result=&(data.DataCall()->x());
        return PyoaCoord_FromoaCoord(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPoint_y_doc[] = 
"Class: oaPoint, Function: y\n"
"  Paramegers: ()\n"
"    Calls: oaCoord& y()\n"
"    Signature: y|ref-oaCoord|\n"
"    BrowseData: 1\n"
"    This function returns the reference of the Y value of this point.\n"
;

static PyObject*
oaPoint_y(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPoint data;
    int convert_status=PyoaPoint_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPointObject* self=(PyoaPointObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaCoord* result=&(data.DataCall()->y());
        return PyoaCoord_FromoaCoord(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaPoint_assign_doc[] = 
"Class: oaPoint, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPoint_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPoint data;
  int convert_status=PyoaPoint_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPoint p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPoint_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPoint_methodlist[] = {
    {"distanceFrom2",(PyCFunction)oaPoint_distanceFrom2,METH_VARARGS,oaPoint_distanceFrom2_doc},
    {"set",(PyCFunction)oaPoint_set,METH_VARARGS,oaPoint_set_doc},
    {"transform",(PyCFunction)oaPoint_transform,METH_VARARGS,oaPoint_transform_doc},
    {"x",(PyCFunction)oaPoint_x,METH_VARARGS,oaPoint_x_doc},
    {"y",(PyCFunction)oaPoint_y,METH_VARARGS,oaPoint_y_doc},
    {"assign",(PyCFunction)oaPoint_tp_assign,METH_VARARGS,oaPoint_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPoint_doc[] = 
"Class: oaPoint\n"
"  The oaPoint class specifies a location in a two-dimensional grid with 32-bit integer coordinates. It is used to specify locations and extents for all classes derived from oaFig . An oaPoint is a utility object that is always constructed and destroyed by application code. It can be used for purposes unrelated to OA databases.\n"
"  A sequence of oaPoints is often specified with the oaPointArray class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaPoint()\n"
"    Signature: oaPoint||\n"
"    This function constructs an uninitialized oaPoint object. Accessing the coordinates at this point has indeterminate results.\n"
"  Paramegers: (oaCoord,oaCoord)\n"
"    Calls: oaPoint(oaCoord xValIn,oaCoord yValIn)\n"
"    Signature: oaPoint||simple-oaCoord,simple-oaCoord,\n"
"    This function constructs an oaPoint object containing the specified X,Y coordinates.\n"
"    xValIn\n"
"    The x value of the point coordinate\n"
"    yValIn\n"
"    The y value of the point coordinate\n"
"  Paramegers: (oaPoint,oaTransform)\n"
"    Calls: oaPoint(const oaPoint& point,const oaTransform& xform)\n"
"    Signature: oaPoint||cref-oaPoint,cref-oaTransform,\n"
"    This function constructs an oaPoint object that is a transformed copy of the specified point .\n"
"    point\n"
"    The point to transform\n"
"    xform\n"
"    The transform value\n"
"  Paramegers: (oaPoint)\n"
"    Calls: (const oaPoint&)\n"
"    Signature: oaPoint||cref-oaPoint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPoint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPoint",
    sizeof(PyoaPointObject),
    0,
    (destructor)oaPoint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPoint_tp_compare,	/* tp_compare */
    (reprfunc)oaPoint_tp_repr,	/* tp_repr */
    &oaPointAsNumber,	/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPoint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPoint_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPoint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPoint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPoint_Type)<0) {
      printf("** PyType_Ready failed for: oaPoint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPoint",
           (PyObject*)(&PyoaPoint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPoint\n");
       return -1;
    }
    return 0;
}


// ==================================================================
// Array for class: oaPoint
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPoint_Array_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPoint_Array_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaPoint_ArrayObject* self = (PyoaPoint_ArrayObject*)gself;
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
    /* Case: (oaPoint_Array) */
    {
        PyParamoaPoint_Array p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPoint_Array_Convert,&p1)) {
            self->data.TakeAway(p1);
            return gself;
        }
    }
    /* Error */
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaPoint_Array, Choices are:\n"
        "    ()\n"
        "    (int)\n"
        "    (oaPoint_Array)\n"
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
oaPoint_Array_dealloc(PyObject* gself)
{
    PyoaPoint_ArrayObject* self = (PyoaPoint_ArrayObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaPoint_Array_str(PyObject *ob)
{
    PyParamoaPoint_Array value;
    int convert_status=PyoaPoint_Array_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* lst=PyoaPoint_Array_CreateList(value);
    PyObject* result=PyObject_Str(lst);
    Py_DECREF(lst);
    return result;
}

// ------------------------------------------------------------------
static PyObject*
oaPoint_Array_repr(PyObject *ob)
{
    PyParamoaPoint_Array value;
    int convert_status=PyoaPoint_Array_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* lst=PyoaPoint_Array_CreateList(value);
    PyObject* result=PyObject_Repr(lst);
    Py_DECREF(lst);
    return result;
}

// ------------------------------------------------------------------
static int
oaPoint_Array_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPoint_Array p1;
    PyParamoaPoint_Array p2;
    int s1=PyoaPoint_Array_Convert(ob1,&p1);
    int s2=PyoaPoint_Array_Convert(ob2,&p2);
    assert(s1!=0);
    assert(s2!=0);
    PyObject* l1=PyoaPoint_Array_CreateList(p1);
    PyObject* l2=PyoaPoint_Array_CreateList(p2);
    int result=PyObject_Compare(l1,l2);
    Py_DECREF(l1);
    Py_DECREF(l2);
    return result;
}

// ------------------------------------------------------------------
int
PyoaPoint_Array_Convert(PyObject* ob,PyParamoaPoint_Array* result)
{
  Pyoa_ssize_t len,i;
  if (PyoaPoint_Array_Check(ob)) {
    PyoaPoint_ArrayObject* self = (PyoaPoint_ArrayObject*)ob;
    result->Borrow(self->data);
  }
  else if (PyList_Check(ob)) {
    len=PyList_Size(ob);
    result->SetLen(len);
    PyParamoaPoint data;
    for(i=0;i<len;i++) {
      PyObject* a=PyList_GetItem(ob,i);
      if (!PyoaPoint_Convert(a,&data)) return 0;
      result->SetItem(i,data.Data());
    }
  }
  else if (PyTuple_Check(ob)) {
    len=PyTuple_Size(ob);
    result->SetLen(len);
    PyParamoaPoint data;
    for(i=0;i<len;i++) {
      PyObject* a=PyTuple_GetItem(ob,i);
      if (!PyoaPoint_Convert(a,&data)) return 0;
      result->SetItem(i,data.Data());
    }
  }
  else {
    PyErr_SetString(PyExc_TypeError,
      "Convertion of parameter to class: oaPoint_Array Failed");
    return 0;
  }
  return 1;
}

// ------------------------------------------------------------------
PyObject* PyoaPoint_Array_FromoaPoint_Array(const oaPoint_Array& value)
{
  PyObject* gself = PyoaPoint_Array_Type.tp_alloc(&PyoaPoint_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaPoint_ArrayObject* self = (PyoaPoint_ArrayObject*)gself;
  self->data = value;
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaPoint_Array_FromoaPoint_Array(PyTypeoaPoint* data,Pyoa_ssize_t len,PyObject* lock)
{
  PyObject* gself = PyoaPoint_Array_Type.tp_alloc(&PyoaPoint_Array_Type,0);
  if (gself == NULL) return gself;
  PyoaPoint_ArrayObject* self = (PyoaPoint_ArrayObject*)gself;
  self->data.Borrow(data,len);
  self->borrow = 1;
  self->locks=NULL;
  if (lock) PyoaLockObject(self->locks,lock);
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaPoint_Array_CreateList(PyParamoaPoint_Array& value)
{
  Pyoa_ssize_t i;
  PyObject* lst=PyList_New(value.Len());
  for(i=0;i<value.Len();i++) {
    PyObject* ob=PyoaPoint_FromoaPoint(value.Data()[i]);
    PyList_SetItem(lst,i,ob);
  }
  return lst;
}

// ------------------------------------------------------------------
// Methods
// ------------------------------------------------------------------
static char oaPoint_Array_assign_doc[] = 
"Class: oaPoint_Array, Function: assign\n"
"  Paramegers: (oaPoint_Array)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaPoint_Array_assign(PyObject* ob, PyObject *args)
{
  PyoaPoint_ArrayObject* self=(PyoaPoint_ArrayObject*)ob;
  try {
    PyParamoaPoint_Array p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPoint_Array_Convert,&p1)) {
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
static char oaPoint_Array_list_doc[] = 
"Class: oaPoint_Array, Function: list\n"
"  Paramegers: ()\n"
"    This function returns the current value as a list.\n"
;

static PyObject*
oaPoint_Array_list(PyObject* ob, PyObject *args)
{
  PyoaPoint_ArrayObject* self=(PyoaPoint_ArrayObject*)ob;
  try {
    if (PyArg_ParseTuple(args,(char*)"")) {
      return PyoaPoint_Array_CreateList(self->data);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------
static PyMethodDef oaPoint_Array_methodlist[] = {
    {"assign",(PyCFunction)oaPoint_Array_assign,METH_VARARGS,oaPoint_Array_assign_doc},
    {"list",(PyCFunction)oaPoint_Array_list,METH_VARARGS,oaPoint_Array_list_doc},
   {NULL,NULL,0,NULL}
};

// ------------------------------------------------------------------
static PyObject*
oaPoint_Array_index_get(PyObject* ob,Pyoa_ssize_t index)
{
  PyoaPoint_ArrayObject* self=(PyoaPoint_ArrayObject*)ob;
  try {
    PyParamoaPoint_Array data;
    int convert_status=PyoaPoint_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return NULL;
    }
    return PyoaPoint_FromoaPoint(data.GetItemPtr(index),1,self->locks);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static Pyoa_ssize_t
oaPoint_Array_index_get_length(PyObject* ob)
{
    PyParamoaPoint_Array data;
    int convert_status=PyoaPoint_Array_Convert(ob,&data);
    assert(convert_status!=0);
    return data.Len();
}

// ------------------------------------------------------------------
static int
oaPoint_Array_index_set(PyObject *ob, Pyoa_ssize_t index, PyObject* value)
{
  try {
    PyParamoaPoint_Array data;
    PyParamoaPoint dataitem;
    int convert_status=PyoaPoint_Array_Convert(ob,&data);
    assert(convert_status!=0);
    if (index<0 || index>=data.Len()) {
        PyObject* err=PyString_FromString("index out of range");
        PyErr_SetObject(PyExc_IndexError, err);
        Py_DECREF(err);
        return -1;
    }
    if (PyoaPoint_Convert(value,&dataitem)==0) return -1;
    data.SetItem(index,dataitem.Data());
    return 0;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return 0;
  }
}

// ------------------------------------------------------------------
static char oaPoint_Array_doc[] =
"Class: oaPoint_Array\n"
"  The oaPoint_Array utility class provides an array of oaPoint.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaPoint_Array()\n"
"    Signature: oaPoint_Array||\n"
"    This is the default constructor for the oaPoint_Array class. This constructor creates an empty oaPoint_Array.\n"
"  Paramegers: (oaPoint_Array)\n"
"    Calls: (const oaPoint_Array&)\n"
"    Signature: oaPoint_Array||cref-oaPoint_Array,\n"
;

// ------------------------------------------------------------------
static PySequenceMethods oaPoint_Array_as_sequence = {
    (Pyoa_inquiry)oaPoint_Array_index_get_length, /* sq_length */
    (Pyoa_binaryfunc)0,              /* sq_concat */
    (Pyoa_intargfunc)0,              /* sq_repeat */
    (Pyoa_intargfunc)oaPoint_Array_index_get, /* sq_item */
    (Pyoa_intintargfunc)0,           /* sq_slice */
    (Pyoa_intobjargproc)oaPoint_Array_index_set,      /* sq_ass_item */
};

// ------------------------------------------------------------------
PyTypeObject PyoaPoint_Array_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPoint_Array",
    sizeof(PyoaPoint_ArrayObject),
    0,
    oaPoint_Array_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaPoint_Array_compare,    /* tp_compare */
    oaPoint_Array_repr,      /* tp_repr */
    0,                                  /* tp_as_number */
    &oaPoint_Array_as_sequence,  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaPoint_Array_str,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPoint_Array_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaPoint_Array_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaPoint_Array_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
int
PyoaPoint_Array_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPoint_Array_Type)<0) {
      printf("** PyType_Ready failed for: oaPoint_Array\n");
      return -1;
    }
    if (PyDict_SetItemString(mod_dict,"oaPoint_Array",
           (PyObject*)(&PyoaPoint_Array_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPoint_Array\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaPointArray
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPointArray_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPointArray_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPointArrayObject* self = (PyoaPointArrayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaPoint*)  new oaPointArray();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaPoint*)  new oaPointArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaPointArray)
    {
        PyParamoaPointArray p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaPointArray_Convert,&p1)) {
            self->value = (oaArrayBase_oaPoint*)  new oaPointArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaPointArray,oaTransform)
    {
        PyParamoaPointArray p1;
        PyParamoaTransform p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaPointArray_Convert,&p1,
              &PyoaTransform_Convert,&p2)) {
            self->value = (oaArrayBase_oaPoint*)  new oaPointArray(p1.Data(),p2.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaPointArray,oaPoint)
    {
        PyParamoaPointArray p1;
        PyParamoaPoint p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaPointArray_Convert,&p1,
              &PyoaPoint_Convert,&p2)) {
            self->value = (oaArrayBase_oaPoint*)  new oaPointArray(p1.Data(),p2.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: ([oaPoint])
    {
        PyParamoaPoint_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaPoint_Array_Convert,&p1)) {
            self->value = (oaArrayBase_oaPoint*)  new oaPointArray(p1.Data(),p1.Len());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaBox)
    {
        PyParamoaBox p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBox_Convert,&p1)) {
            self->value = (oaArrayBase_oaPoint*)  new oaPointArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaPointArray, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaPointArray)\n"
        "    (oaPointArray,oaTransform)\n"
        "    (oaPointArray,oaPoint)\n"
        "    ([oaPoint])\n"
        "    (oaBox)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPointArray_tp_dealloc(PyoaPointArrayObject* self)
{
    if (!self->borrow) {
        delete (oaPointArray*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPointArray_tp_repr(PyObject *ob)
{
    PyParamoaPointArray value;
    int convert_status=PyoaPointArray_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[34];
    sprintf(buffer,"<oaPointArray::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaPointArray_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPointArray v1;
    PyParamoaPointArray v2;
    int convert_status1=PyoaPointArray_Convert(ob1,&v1);
    int convert_status2=PyoaPointArray_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    if (v1.Data()==v2.Data()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPointArray_Convert(PyObject* ob,PyParamoaPointArray* result)
{
    if (ob == NULL) return 1;
    if (PyoaPointArray_Check(ob)) {
        result->SetData( (oaPointArray*) ((PyoaPointArrayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPointArray Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPointArray_FromoaPointArray(oaPointArray* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaPointArray_Type.tp_alloc(&PyoaPointArray_Type,0);
        if (bself == NULL) return bself;
        PyoaPointArrayObject* self = (PyoaPointArrayObject*)bself;
        self->value = (oaArrayBase_oaPoint*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPointArray_compress_doc[] = 
"Class: oaPointArray, Function: compress\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void compress(oaPointArray& pointsOut) const\n"
"    Signature: compress|void-void|ref-oaPointArray,simple-oaBoolean,\n"
"    BrowseData: 0,oaPointArray\n"
"    This function returns in pointsOut the point array that is created by removing all collinear and coincident points from this oaPointArray.\n"
"    Note: compress() will produce incorrect results if the edges connected by the points in the point array cross.\n"
"    pointsOut\n"
"    a reference to the compressed oaPointArray produced by this function\n"
"    isClosed\n"
"    specify true if the first and last points in the array should be treated as connected (the figure described by the point array is closed); specify false if the first and last points should be treated as unconnected (the figure described by the point array is open)\n"
"  Paramegers: (oaPointArray,oaBoolean)\n"
"    Calls: void compress(oaPointArray& pointsOut,oaBoolean isClosed) const\n"
"    Signature: compress|void-void|ref-oaPointArray,simple-oaBoolean,\n"
"    This function returns in pointsOut the point array that is created by removing all collinear and coincident points from this oaPointArray.\n"
"    Note: compress() will produce incorrect results if the edges connected by the points in the point array cross.\n"
"    pointsOut\n"
"    a reference to the compressed oaPointArray produced by this function\n"
"    isClosed\n"
"    specify true if the first and last points in the array should be treated as connected (the figure described by the point array is closed); specify false if the first and last points should be treated as unconnected (the figure described by the point array is open)\n"
"  Paramegers: ()\n"
"    Calls: void compress()\n"
"    Signature: compress|void-void|simple-oaBoolean,\n"
"    BrowseData: 0\n"
"    This function removes all collinear and coincident points from this oaPointArray.\n"
"    Note: compress() will produce incorrect results if the edges connected by the points in the array cross.\n"
"    isClosed\n"
"    Specify true if the first and last points in the array should be treated as connected (the figure described by the point array is closed); specify false if the first and last points should be treated as unconnected (the figure described by the point array is open)\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: void compress(oaBoolean isClosed)\n"
"    Signature: compress|void-void|simple-oaBoolean,\n"
"    This function removes all collinear and coincident points from this oaPointArray.\n"
"    Note: compress() will produce incorrect results if the edges connected by the points in the array cross.\n"
"    isClosed\n"
"    Specify true if the first and last points in the array should be treated as connected (the figure described by the point array is closed); specify false if the first and last points should be treated as unconnected (the figure described by the point array is open)\n"
;

static PyObject*
oaPointArray_compress(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPointArray data;
    int convert_status=PyoaPointArray_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPointArrayObject* self=(PyoaPointArrayObject*)ob;

    // Case: (oaPointArray)
    {
        PyParamoaPointArray p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaPointArray_Convert,&p1)) {
            data.DataCall()->compress(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaPointArray,oaBoolean)
    {
        PyParamoaPointArray p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaPointArray_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            data.DataCall()->compress(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            data.DataCall()->compress();
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
            data.DataCall()->compress(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaPointArray, function: compress, Choices are:\n"
        "    (oaPointArray)\n"
        "    (oaPointArray,oaBoolean)\n"
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
static char oaPointArray_contains_doc[] = 
"Class: oaPointArray, Function: contains\n"
"  Paramegers: (oaPoint)\n"
"    Calls: oaBoolean contains(const oaPoint& point) const\n"
"    Signature: contains|simple-oaBoolean|cref-oaPoint,simple-oaBoolean,\n"
"    This function returns a boolean indicating whether or not the specified point is inside or on the edge of this pointArray.\n"
"    Note: the point array is assumed to be closed--that is, the first and last points in the array are treated as connected.\n"
"    point\n"
"    the point to test\n"
"    includeEdges\n"
"    boolean that specifies whether or not points on the edge of the point array are assumed to be contained.\n"
"  Paramegers: (oaPoint,oaBoolean)\n"
"    Calls: oaBoolean contains(const oaPoint& point,oaBoolean includeEdges) const\n"
"    Signature: contains|simple-oaBoolean|cref-oaPoint,simple-oaBoolean,\n"
"    This function returns a boolean indicating whether or not the specified point is inside or on the edge of this pointArray.\n"
"    Note: the point array is assumed to be closed--that is, the first and last points in the array are treated as connected.\n"
"    point\n"
"    the point to test\n"
"    includeEdges\n"
"    boolean that specifies whether or not points on the edge of the point array are assumed to be contained.\n"
"  Paramegers: (oaBox)\n"
"    Calls: oaBoolean contains(const oaBox& box) const\n"
"    Signature: contains|simple-oaBoolean|cref-oaBox,\n"
"    This function returns a boolean indicating whether or not this pointArray, which is assumed to be closed, contains the specified oaBox .\n"
"    box\n"
"    the oaBox to test against\n"
;

static PyObject*
oaPointArray_contains(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPointArray data;
    int convert_status=PyoaPointArray_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPointArrayObject* self=(PyoaPointArrayObject*)ob;

    // Case: (oaPoint)
    {
        PyParamoaPoint p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaPoint_Convert,&p1)) {
            oaBoolean result= (data.DataCall()->contains(p1.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaPoint,oaBoolean)
    {
        PyParamoaPoint p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaPoint_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            oaBoolean result= (data.DataCall()->contains(p1.Data(),p2.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBox)
    {
        PyParamoaBox p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBox_Convert,&p1)) {
            oaBoolean result= (data.DataCall()->contains(p1.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaPointArray, function: contains, Choices are:\n"
        "    (oaPoint)\n"
        "    (oaPoint,oaBoolean)\n"
        "    (oaBox)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPointArray_distanceFrom2_doc[] = 
"Class: oaPointArray, Function: distanceFrom2\n"
"  Paramegers: (oaPoint)\n"
"    Calls: oaDouble distanceFrom2(const oaPoint& point) const\n"
"    Signature: distanceFrom2|simple-oaDouble|cref-oaPoint,\n"
"    This function returns the square of the distance from the specified point to the closest point on this oaPointArray.\n"
"    Note: the point array is assumed to be closed--that is, the first and last points in the array are treated as connected.\n"
;

static PyObject*
oaPointArray_distanceFrom2(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPointArray data;
    int convert_status=PyoaPointArray_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPointArrayObject* self=(PyoaPointArrayObject*)ob;

    PyParamoaPoint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPoint_Convert,&p1)) {
        oaDouble result= (data.DataCall()->distanceFrom2(p1.Data()));
        return PyoaDouble_FromoaDouble(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPointArray_getArea_doc[] = 
"Class: oaPointArray, Function: getArea\n"
"  Paramegers: ()\n"
"    Calls: oaDouble getArea() const\n"
"    Signature: getArea|simple-oaDouble|\n"
"    BrowseData: 1\n"
"    This function returns the area in DBUU contained by the oaPointArray. The PointArray is assumed to be closed.\n"
"    Note: The points in the array can either be a clockwise or a counter-clockwise enclosure. However they must not be self-intersecting.\n"
;

static PyObject*
oaPointArray_getArea(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPointArray data;
    int convert_status=PyoaPointArray_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPointArrayObject* self=(PyoaPointArrayObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDouble result= (data.DataCall()->getArea());
        return PyoaDouble_FromoaDouble(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPointArray_getBBox_doc[] = 
"Class: oaPointArray, Function: getBBox\n"
"  Paramegers: (oaBox)\n"
"    Calls: void getBBox(oaBox& bBox) const\n"
"    Signature: getBBox|void-void|ref-oaBox,\n"
"    BrowseData: 0,oaBox\n"
"    This function calculates the bounding box of the points in this oaPointArray.\n"
;

static PyObject*
oaPointArray_getBBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPointArray data;
    int convert_status=PyoaPointArray_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPointArrayObject* self=(PyoaPointArrayObject*)ob;

    PyParamoaBox p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBox_Convert,&p1)) {
        data.DataCall()->getBBox(p1.Data());
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
static char oaPointArray_hasExtraPoints_doc[] = 
"Class: oaPointArray, Function: hasExtraPoints\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasExtraPoints() const\n"
"    Signature: hasExtraPoints|simple-oaBoolean|simple-oaBoolean,\n"
"    BrowseData: 1\n"
"    This function returns true if this pointArray has any collinear or coincident points. Also returns true if isClosed = true (see below) and the last and first points of the array specify the same point.\n"
"    isClosed\n"
"    specify true if the first and last points in the array should be treated as connected (the figure described by the point array is closed); specify false if the first and last points should be treated as unconnected (the figure described by the point array is open)\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: oaBoolean hasExtraPoints(oaBoolean isClosed) const\n"
"    Signature: hasExtraPoints|simple-oaBoolean|simple-oaBoolean,\n"
"    This function returns true if this pointArray has any collinear or coincident points. Also returns true if isClosed = true (see below) and the last and first points of the array specify the same point.\n"
"    isClosed\n"
"    specify true if the first and last points in the array should be treated as connected (the figure described by the point array is closed); specify false if the first and last points should be treated as unconnected (the figure described by the point array is open)\n"
;

static PyObject*
oaPointArray_hasExtraPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPointArray data;
    int convert_status=PyoaPointArray_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPointArrayObject* self=(PyoaPointArrayObject*)ob;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaBoolean result= (data.DataCall()->hasExtraPoints());
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBoolean)
    {
        PyParamoaBoolean p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBoolean_Convert,&p1)) {
            oaBoolean result= (data.DataCall()->hasExtraPoints(p1.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaPointArray, function: hasExtraPoints, Choices are:\n"
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
static char oaPointArray_isOrthogonal_doc[] = 
"Class: oaPointArray, Function: isOrthogonal\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isOrthogonal() const\n"
"    Signature: isOrthogonal|simple-oaBoolean|simple-oaBoolean,\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if all of the angles in this oaPointArray are multiples of 90 degrees.\n"
"    isClosed\n"
"    specify true if the first and last points in the array should be treated as connected (the figure described by the point array is closed); specify false if the first and last points should be treated as unconnected (the figure described by the point array is open)\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: oaBoolean isOrthogonal(oaBoolean isClosed) const\n"
"    Signature: isOrthogonal|simple-oaBoolean|simple-oaBoolean,\n"
"    This function returns a boolean value that indicates if all of the angles in this oaPointArray are multiples of 90 degrees.\n"
"    isClosed\n"
"    specify true if the first and last points in the array should be treated as connected (the figure described by the point array is closed); specify false if the first and last points should be treated as unconnected (the figure described by the point array is open)\n"
;

static PyObject*
oaPointArray_isOrthogonal(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPointArray data;
    int convert_status=PyoaPointArray_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPointArrayObject* self=(PyoaPointArrayObject*)ob;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaBoolean result= (data.DataCall()->isOrthogonal());
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBoolean)
    {
        PyParamoaBoolean p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBoolean_Convert,&p1)) {
            oaBoolean result= (data.DataCall()->isOrthogonal(p1.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaPointArray, function: isOrthogonal, Choices are:\n"
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
static char oaPointArray_isRectangle_doc[] = 
"Class: oaPointArray, Function: isRectangle\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isRectangle() const\n"
"    Signature: isRectangle|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if this oaPointArray describes a rectangle that could be created as an oaRect . Specifically, to return true the point array must have four points after collinear and coincident points have been removed, and those points must be the corners of a rectangle with horizontal and vertical sides.\n"
;

static PyObject*
oaPointArray_isRectangle(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPointArray data;
    int convert_status=PyoaPointArray_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPointArrayObject* self=(PyoaPointArrayObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isRectangle());
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
static char oaPointArray_isSelfIntersecting_doc[] = 
"Class: oaPointArray, Function: isSelfIntersecting\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isSelfIntersecting() const\n"
"    Signature: isSelfIntersecting|simple-oaBoolean|simple-oaBoolean,\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this oaPointArray intersects itself. This does not include self-touching oaPointArrays.\n"
"    isClosed\n"
"    specify true if the first and last points in the array should be treated as connected (the figure described by the point array is closed); specify false if the first and last points should be treated as unconnected (the figure described by the point array is open)\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: oaBoolean isSelfIntersecting(oaBoolean isClosed) const\n"
"    Signature: isSelfIntersecting|simple-oaBoolean|simple-oaBoolean,\n"
"    This function returns a boolean value that indicates if this oaPointArray intersects itself. This does not include self-touching oaPointArrays.\n"
"    isClosed\n"
"    specify true if the first and last points in the array should be treated as connected (the figure described by the point array is closed); specify false if the first and last points should be treated as unconnected (the figure described by the point array is open)\n"
;

static PyObject*
oaPointArray_isSelfIntersecting(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPointArray data;
    int convert_status=PyoaPointArray_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPointArrayObject* self=(PyoaPointArrayObject*)ob;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaBoolean result= (data.DataCall()->isSelfIntersecting());
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBoolean)
    {
        PyParamoaBoolean p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBoolean_Convert,&p1)) {
            oaBoolean result= (data.DataCall()->isSelfIntersecting(p1.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaPointArray, function: isSelfIntersecting, Choices are:\n"
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
static char oaPointArray_onEdge_doc[] = 
"Class: oaPointArray, Function: onEdge\n"
"  Paramegers: (oaPoint)\n"
"    Calls: oaBoolean onEdge(const oaPoint& point) const\n"
"    Signature: onEdge|simple-oaBoolean|cref-oaPoint,simple-oaBoolean,\n"
"    This function returns a boolean value that indicates if the specified point is on this oaPointArray.\n"
"    point\n"
"    the point to look for on this oaPointArray\n"
"    isClosed\n"
"    specify true if the first and last points in the array should be treated as connected (the figure described by the point array is closed); specify false if the first and last points should be treated as unconnected (the figure described by the point array is open)\n"
"  Paramegers: (oaPoint,oaBoolean)\n"
"    Calls: oaBoolean onEdge(const oaPoint& point,oaBoolean isClosed) const\n"
"    Signature: onEdge|simple-oaBoolean|cref-oaPoint,simple-oaBoolean,\n"
"    This function returns a boolean value that indicates if the specified point is on this oaPointArray.\n"
"    point\n"
"    the point to look for on this oaPointArray\n"
"    isClosed\n"
"    specify true if the first and last points in the array should be treated as connected (the figure described by the point array is closed); specify false if the first and last points should be treated as unconnected (the figure described by the point array is open)\n"
;

static PyObject*
oaPointArray_onEdge(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPointArray data;
    int convert_status=PyoaPointArray_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPointArrayObject* self=(PyoaPointArrayObject*)ob;

    // Case: (oaPoint)
    {
        PyParamoaPoint p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaPoint_Convert,&p1)) {
            oaBoolean result= (data.DataCall()->onEdge(p1.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaPoint,oaBoolean)
    {
        PyParamoaPoint p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaPoint_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            oaBoolean result= (data.DataCall()->onEdge(p1.Data(),p2.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaPointArray, function: onEdge, Choices are:\n"
        "    (oaPoint)\n"
        "    (oaPoint,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPointArray_overlaps_doc[] = 
"Class: oaPointArray, Function: overlaps\n"
"  Paramegers: (oaBox)\n"
"    Calls: oaBoolean overlaps(const oaBox& box) const\n"
"    Signature: overlaps|simple-oaBoolean|cref-oaBox,simple-oaBoolean,\n"
"    This function returns a boolean value that indicates if the specified box overlaps or touches this oaPointArray.\n"
"    Note: overlaps() assumes that the points in the array are specified in clockwise order.\n"
"    box\n"
"    the oaBox to test against\n"
"    closed\n"
"    indicates whether the pointArray is closed.\n"
"  Paramegers: (oaBox,oaBoolean)\n"
"    Calls: oaBoolean overlaps(const oaBox& box,oaBoolean closed) const\n"
"    Signature: overlaps|simple-oaBoolean|cref-oaBox,simple-oaBoolean,\n"
"    This function returns a boolean value that indicates if the specified box overlaps or touches this oaPointArray.\n"
"    Note: overlaps() assumes that the points in the array are specified in clockwise order.\n"
"    box\n"
"    the oaBox to test against\n"
"    closed\n"
"    indicates whether the pointArray is closed.\n"
;

static PyObject*
oaPointArray_overlaps(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPointArray data;
    int convert_status=PyoaPointArray_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPointArrayObject* self=(PyoaPointArrayObject*)ob;

    // Case: (oaBox)
    {
        PyParamoaBox p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBox_Convert,&p1)) {
            oaBoolean result= (data.DataCall()->overlaps(p1.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBox,oaBoolean)
    {
        PyParamoaBox p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaBox_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            oaBoolean result= (data.DataCall()->overlaps(p1.Data(),p2.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaPointArray, function: overlaps, Choices are:\n"
        "    (oaBox)\n"
        "    (oaBox,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPointArray_transform_doc[] = 
"Class: oaPointArray, Function: transform\n"
"  Paramegers: (oaTransform,oaPointArray)\n"
"    Calls: void transform(const oaTransform& xform,oaPointArray& result) const\n"
"    Signature: transform|void-void|cref-oaTransform,ref-oaPointArray,\n"
"    This function transforms this oaPointArray with the specified transform and stores the result in result , which can be the same oaPointArray. The result is assumed the same size as the oaPointArray.\n"
"  Paramegers: (oaTransform)\n"
"    Calls: void transform(const oaTransform& xform)\n"
"    Signature: transform|void-void|cref-oaTransform,\n"
"    This function transforms this oaPointArray with the specified transform.\n"
"  Paramegers: (oaPoint,oaPointArray)\n"
"    Calls: void transform(const oaPoint& offset,oaPointArray& result) const\n"
"    Signature: transform|void-void|cref-oaPoint,ref-oaPointArray,\n"
"    This function transforms this oaPointArray with the specified offset and stores the result in result , which can be the same oaPointArray. The result is assumed the same size as the pointArray.\n"
"  Paramegers: (oaPoint)\n"
"    Calls: void transform(const oaPoint& offset)\n"
"    Signature: transform|void-void|cref-oaPoint,\n"
"    This function transforms this oaPointArray with the specified offset.\n"
"  Paramegers: (oaDouble,oaDouble,oaPointArray)\n"
"    Calls: void transform(oaDouble scale,oaDouble angle,oaPointArray& result) const\n"
"    Signature: transform|void-void|simple-oaDouble,simple-oaDouble,ref-oaPointArray,\n"
"    This function transforms this oaPointArray by the specified scale factor and rotation angle . The points are rotated about the origin. The result is stored in result , which can be the same point.\n"
"  Paramegers: (oaDouble,oaDouble)\n"
"    Calls: void transform(oaDouble scale,oaDouble angle)\n"
"    Signature: transform|void-void|simple-oaDouble,simple-oaDouble,\n"
"    This function transforms this oaPointArray by the specified scale factor and rotation angle . The points are rotated about the origin.\n"
;

static PyObject*
oaPointArray_transform(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPointArray data;
    int convert_status=PyoaPointArray_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPointArrayObject* self=(PyoaPointArrayObject*)ob;

    // Case: (oaTransform,oaPointArray)
    {
        PyParamoaTransform p1;
        PyParamoaPointArray p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaTransform_Convert,&p1,
              &PyoaPointArray_Convert,&p2)) {
            data.DataCall()->transform(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaTransform)
    {
        PyParamoaTransform p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaTransform_Convert,&p1)) {
            data.DataCall()->transform(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaPoint,oaPointArray)
    {
        PyParamoaPoint p1;
        PyParamoaPointArray p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaPoint_Convert,&p1,
              &PyoaPointArray_Convert,&p2)) {
            data.DataCall()->transform(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaPoint)
    {
        PyParamoaPoint p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaPoint_Convert,&p1)) {
            data.DataCall()->transform(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDouble,oaDouble,oaPointArray)
    {
        PyParamoaDouble p1;
        PyParamoaDouble p2;
        PyParamoaPointArray p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaDouble_Convert,&p1,
              &PyoaDouble_Convert,&p2,
              &PyoaPointArray_Convert,&p3)) {
            data.DataCall()->transform(p1.Data(),p2.Data(),p3.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDouble,oaDouble)
    {
        PyParamoaDouble p1;
        PyParamoaDouble p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaDouble_Convert,&p1,
              &PyoaDouble_Convert,&p2)) {
            data.DataCall()->transform(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaPointArray, function: transform, Choices are:\n"
        "    (oaTransform,oaPointArray)\n"
        "    (oaTransform)\n"
        "    (oaPoint,oaPointArray)\n"
        "    (oaPoint)\n"
        "    (oaDouble,oaDouble,oaPointArray)\n"
        "    (oaDouble,oaDouble)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaPointArray_assign_doc[] = 
"Class: oaPointArray, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPointArray_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPointArray data;
  int convert_status=PyoaPointArray_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPointArray p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPointArray_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPointArray_methodlist[] = {
    {"compress",(PyCFunction)oaPointArray_compress,METH_VARARGS,oaPointArray_compress_doc},
    {"contains",(PyCFunction)oaPointArray_contains,METH_VARARGS,oaPointArray_contains_doc},
    {"distanceFrom2",(PyCFunction)oaPointArray_distanceFrom2,METH_VARARGS,oaPointArray_distanceFrom2_doc},
    {"getArea",(PyCFunction)oaPointArray_getArea,METH_VARARGS,oaPointArray_getArea_doc},
    {"getBBox",(PyCFunction)oaPointArray_getBBox,METH_VARARGS,oaPointArray_getBBox_doc},
    {"hasExtraPoints",(PyCFunction)oaPointArray_hasExtraPoints,METH_VARARGS,oaPointArray_hasExtraPoints_doc},
    {"isOrthogonal",(PyCFunction)oaPointArray_isOrthogonal,METH_VARARGS,oaPointArray_isOrthogonal_doc},
    {"isRectangle",(PyCFunction)oaPointArray_isRectangle,METH_VARARGS,oaPointArray_isRectangle_doc},
    {"isSelfIntersecting",(PyCFunction)oaPointArray_isSelfIntersecting,METH_VARARGS,oaPointArray_isSelfIntersecting_doc},
    {"onEdge",(PyCFunction)oaPointArray_onEdge,METH_VARARGS,oaPointArray_onEdge_doc},
    {"overlaps",(PyCFunction)oaPointArray_overlaps,METH_VARARGS,oaPointArray_overlaps_doc},
    {"transform",(PyCFunction)oaPointArray_transform,METH_VARARGS,oaPointArray_transform_doc},
    {"assign",(PyCFunction)oaPointArray_tp_assign,METH_VARARGS,oaPointArray_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPointArray_doc[] = 
"Class: oaPointArray\n"
"  The oaPointArray class represents an array of two-dimensional integer points. These are used in the API to specify a number of figures such as oaPolygons and oaPaths. See oaPolygon::create for an example.\n"
"  PointArrays can be used either to indicate a closed figure, such as a polygon, or an open set of points such as a line. When used to describe a closed figure, the connection between the first and last point is always implicit. In such usage it is an error to have the first and last point be the same. Some member functions of oaPointArray have an isClosed flag to indicate whether the array is intended to describe a closed figure or an open line. Many functions that use PointArrays only apply to closed figures, and a flag is not needed for these functions.\n"
"  PointArrays used as arguments to member functions of oaFig classes should always be well-formed such that they do not contain duplicate or collinear points. oaPointArray::compress() can be used to remove such points from the array.\n"
"  Like all oaArray classes, oaPointArrays have separate counts for their allocated size and for the number of elements currently in use. For good performance be sure to avoid small incremental allocations as elements are added to an array.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaPointArray()\n"
"    Signature: oaPointArray||simple-oaUInt4,\n"
"    This function constructs an oaPointArray object, sets the number of points as specified by numPoints (0 if not specified), and allocates storage for the points.\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaPointArray(oaUInt4 sizeIn)\n"
"    Signature: oaPointArray||simple-oaUInt4,\n"
"    This function constructs an oaPointArray object, sets the number of points as specified by numPoints (0 if not specified), and allocates storage for the points.\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: oaPointArray(const oaPointArray& pointsIn)\n"
"    Signature: oaPointArray||cref-oaPointArray,\n"
"    This function constructs an oaPointArray object, creating a copy of the specified pointArray .\n"
"  Paramegers: (oaPointArray,oaTransform)\n"
"    Calls: oaPointArray(const oaPointArray& pointsIn,const oaTransform& xform)\n"
"    Signature: oaPointArray||cref-oaPointArray,cref-oaTransform,\n"
"    This function constructs an oaPointArray object, creating a copy of the specified pointArray after it is transformed using the specified xform oaTransform .\n"
"  Paramegers: (oaPointArray,oaPoint)\n"
"    Calls: oaPointArray(const oaPointArray& pointsIn,const oaPoint& offset)\n"
"    Signature: oaPointArray||cref-oaPointArray,cref-oaPoint,\n"
"    This function constructs an oaPointArray object, creating a copy of the specified pointArray , and applying an offset contained in the specified oaPoint object.\n"
"  Paramegers: ([oaPoint])\n"
"    Calls: oaPointArray(const oaPoint* pointsIn)\n"
"    Signature: oaPointArray||cptr-oaPoint,simple-oaUInt4,\n"
"    This function constructs an oaPointArray object by copying in an array of oaPoint . The number of elements in the array is indicated by numPointsIn .\n"
"  Paramegers: (oaBox)\n"
"    Calls: oaPointArray(const oaBox& rectIn)\n"
"    Signature: oaPointArray||cref-oaBox,\n"
"    This oaPointArray constructor function creates an array consisting of the four corners of the specified rectIn rectangle, starting at the lower-left and moving clockwise.\n"
"    rectIn\n"
"    oaBox input parameter used for point array construction\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: (const oaPointArray&)\n"
"    Signature: oaPointArray||cref-oaPointArray,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPointArray_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPointArray",
    sizeof(PyoaPointArrayObject),
    0,
    (destructor)oaPointArray_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPointArray_tp_compare,	/* tp_compare */
    (reprfunc)oaPointArray_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPointArray_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPointArray_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArray_oaPoint_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPointArray_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPointArray_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPointArray_Type)<0) {
      printf("** PyType_Ready failed for: oaPointArray\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPointArray",
           (PyObject*)(&PyoaPointArray_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPointArray\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaPoleResidue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPoleResidue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPoleResidue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPoleResidueObject* self = (PyoaPoleResidueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaPoleResidue)
    {
        PyParamoaPoleResidue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPoleResidue_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaPoleResidue, Choices are:\n"
        "    (oaPoleResidue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPoleResidue_tp_dealloc(PyoaPoleResidueObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPoleResidue_tp_repr(PyObject *ob)
{
    PyParamoaPoleResidue value;
    int convert_status=PyoaPoleResidue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaPoleResidue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaPoleResidue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPoleResidue v1;
    PyParamoaPoleResidue v2;
    int convert_status1=PyoaPoleResidue_Convert(ob1,&v1);
    int convert_status2=PyoaPoleResidue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPoleResidue_Convert(PyObject* ob,PyParamoaPoleResidue* result)
{
    if (ob == NULL) return 1;
    if (PyoaPoleResidue_Check(ob)) {
        result->SetData( (oaPoleResidue**) ((PyoaPoleResidueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPoleResidue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPoleResidue_FromoaPoleResidue(oaPoleResidue** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaPoleResidue* data=*value;
        PyObject* bself = PyoaPoleResidue_Type.tp_alloc(&PyoaPoleResidue_Type,0);
        if (bself == NULL) return bself;
        PyoaPoleResidueObject* self = (PyoaPoleResidueObject*)bself;
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
PyObject* PyoaPoleResidue_FromoaPoleResidue(oaPoleResidue* data)
{
    if (data) {
       PyObject* bself = PyoaPoleResidue_Type.tp_alloc(&PyoaPoleResidue_Type,0);
       if (bself == NULL) return bself;
       PyoaPoleResidueObject* self = (PyoaPoleResidueObject*)bself;
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
static char oaPoleResidue_destroy_doc[] = 
"Class: oaPoleResidue, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this oaPoleResidue object, removing it from the database.\n"
;

static PyObject*
oaPoleResidue_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPoleResidue data;
    int convert_status=PyoaPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPoleResidueObject* self=(PyoaPoleResidueObject*)ob;
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
static char oaPoleResidue_getDelay_doc[] = 
"Class: oaPoleResidue, Function: getDelay\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getDelay() const\n"
"    Signature: getDelay|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the Elmore delay for this oaPoleResidue object.\n"
;

static PyObject*
oaPoleResidue_getDelay(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPoleResidue data;
    int convert_status=PyoaPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPoleResidueObject* self=(PyoaPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getDelay());
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
static char oaPoleResidue_getPiPoleResidue_doc[] = 
"Class: oaPoleResidue, Function: getPiPoleResidue\n"
"  Paramegers: ()\n"
"    Calls: oaPiPoleResidue* getPiPoleResidue() const\n"
"    Signature: getPiPoleResidue|ptr-oaPiPoleResidue|\n"
"    BrowseData: 1\n"
"    This function returns the oaPiPoleResidue reduced model for this oaPoleResidue object.\n"
;

static PyObject*
oaPoleResidue_getPiPoleResidue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPoleResidue data;
    int convert_status=PyoaPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPoleResidueObject* self=(PyoaPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaPiPoleResiduep result= (data.DataCall()->getPiPoleResidue());
        return PyoaPiPoleResidue_FromoaPiPoleResidue(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPoleResidue_getPoles_doc[] = 
"Class: oaPoleResidue, Function: getPoles\n"
"  Paramegers: (oaComplexArray_oaFloat)\n"
"    Calls: void getPoles(oaComplexArray_oaFloat& poles) const\n"
"    Signature: getPoles|void-void|ref-oaComplexArray_oaFloat,\n"
"    BrowseData: 0,oaComplexArray_oaFloat\n"
"    This function fills out poles with the complex numbers for each of the poles of the interconnect network.\n"
;

static PyObject*
oaPoleResidue_getPoles(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPoleResidue data;
    int convert_status=PyoaPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPoleResidueObject* self=(PyoaPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaComplexArray_oaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaComplexArray_oaFloat_Convert,&p1)) {
        data.DataCall()->getPoles(p1.Data());
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
static char oaPoleResidue_getReceiver_doc[] = 
"Class: oaPoleResidue, Function: getReceiver\n"
"  Paramegers: ()\n"
"    Calls: oaDesignObject* getReceiver() const\n"
"    Signature: getReceiver|ptr-oaDesignObject|\n"
"    BrowseData: 1\n"
"    This function returns the receiver for this oaPoleResidue object. The receiver is either a terminal or an instTerm.\n"
;

static PyObject*
oaPoleResidue_getReceiver(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPoleResidue data;
    int convert_status=PyoaPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPoleResidueObject* self=(PyoaPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDesignObjectp result= (data.DataCall()->getReceiver());
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
static char oaPoleResidue_getResidues_doc[] = 
"Class: oaPoleResidue, Function: getResidues\n"
"  Paramegers: (oaComplexArray_oaFloat)\n"
"    Calls: void getResidues(oaComplexArray_oaFloat& res) const\n"
"    Signature: getResidues|void-void|ref-oaComplexArray_oaFloat,\n"
"    BrowseData: 0,oaComplexArray_oaFloat\n"
"    This function fills out residues with the complex numbers for each of the residues for the receiver for this oaPoleResidue object.\n"
;

static PyObject*
oaPoleResidue_getResidues(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPoleResidue data;
    int convert_status=PyoaPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPoleResidueObject* self=(PyoaPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaComplexArray_oaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaComplexArray_oaFloat_Convert,&p1)) {
        data.DataCall()->getResidues(p1.Data());
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
static char oaPoleResidue_setDelay_doc[] = 
"Class: oaPoleResidue, Function: setDelay\n"
"  Paramegers: (oaFloat)\n"
"    Calls: void setDelay(oaFloat delay)\n"
"    Signature: setDelay|void-void|simple-oaFloat,\n"
"    This function sets the Elmore delay for this oaPoleResidue object.\n"
;

static PyObject*
oaPoleResidue_setDelay(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPoleResidue data;
    int convert_status=PyoaPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPoleResidueObject* self=(PyoaPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFloat_Convert,&p1)) {
        data.DataCall()->setDelay(p1.Data());
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
static char oaPoleResidue_setPoles_doc[] = 
"Class: oaPoleResidue, Function: setPoles\n"
"  Paramegers: (oaComplexArray_oaFloat)\n"
"    Calls: void setPoles(const oaComplexArray_oaFloat& poles)\n"
"    Signature: setPoles|void-void|cref-oaComplexArray_oaFloat,\n"
"    This function sets the poles of the interconnect network for this oaPoleResidue object to the specified values.\n"
;

static PyObject*
oaPoleResidue_setPoles(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPoleResidue data;
    int convert_status=PyoaPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPoleResidueObject* self=(PyoaPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaComplexArray_oaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaComplexArray_oaFloat_Convert,&p1)) {
        data.DataCall()->setPoles(p1.Data());
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
static char oaPoleResidue_setResidues_doc[] = 
"Class: oaPoleResidue, Function: setResidues\n"
"  Paramegers: (oaComplexArray_oaFloat)\n"
"    Calls: void setResidues(const oaComplexArray_oaFloat& res)\n"
"    Signature: setResidues|void-void|cref-oaComplexArray_oaFloat,\n"
"    This function sets the residues for the receiver for this oaPoleResidue object to the specified values.\n"
;

static PyObject*
oaPoleResidue_setResidues(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPoleResidue data;
    int convert_status=PyoaPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPoleResidueObject* self=(PyoaPoleResidueObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaComplexArray_oaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaComplexArray_oaFloat_Convert,&p1)) {
        data.DataCall()->setResidues(p1.Data());
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
static char oaPoleResidue_isNull_doc[] =
"Class: oaPoleResidue, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaPoleResidue_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaPoleResidue data;
    int convert_status=PyoaPoleResidue_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaPoleResidue_assign_doc[] = 
"Class: oaPoleResidue, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPoleResidue_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPoleResidue data;
  int convert_status=PyoaPoleResidue_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPoleResidue p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPoleResidue_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPoleResidue_methodlist[] = {
    {"destroy",(PyCFunction)oaPoleResidue_destroy,METH_VARARGS,oaPoleResidue_destroy_doc},
    {"getDelay",(PyCFunction)oaPoleResidue_getDelay,METH_VARARGS,oaPoleResidue_getDelay_doc},
    {"getPiPoleResidue",(PyCFunction)oaPoleResidue_getPiPoleResidue,METH_VARARGS,oaPoleResidue_getPiPoleResidue_doc},
    {"getPoles",(PyCFunction)oaPoleResidue_getPoles,METH_VARARGS,oaPoleResidue_getPoles_doc},
    {"getReceiver",(PyCFunction)oaPoleResidue_getReceiver,METH_VARARGS,oaPoleResidue_getReceiver_doc},
    {"getResidues",(PyCFunction)oaPoleResidue_getResidues,METH_VARARGS,oaPoleResidue_getResidues_doc},
    {"setDelay",(PyCFunction)oaPoleResidue_setDelay,METH_VARARGS,oaPoleResidue_setDelay_doc},
    {"setPoles",(PyCFunction)oaPoleResidue_setPoles,METH_VARARGS,oaPoleResidue_setPoles_doc},
    {"setResidues",(PyCFunction)oaPoleResidue_setResidues,METH_VARARGS,oaPoleResidue_setResidues_doc},
    {"isNull",(PyCFunction)oaPoleResidue_tp_isNull,METH_VARARGS,oaPoleResidue_isNull_doc},
    {"assign",(PyCFunction)oaPoleResidue_tp_assign,METH_VARARGS,oaPoleResidue_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPoleResidue_doc[] = 
"Class: oaPoleResidue\n"
"  The oaPoleResidue class represents an Elmore delay and a set of poles and residues that approximate the transfer function of the interconnect parasitics from a particular driver to a receiver on the net. The oaPoleResidue objects are part of a complete oaPiPoleResidue reduced model for a driver.\n"
"  Undo is not supported for oaPoleResidue objects.\n"
"  The oaPoleResidue class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaPoleResidue)\n"
"    Calls: (const oaPoleResidue&)\n"
"    Signature: oaPoleResidue||cref-oaPoleResidue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPoleResidue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPoleResidue",
    sizeof(PyoaPoleResidueObject),
    0,
    (destructor)oaPoleResidue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPoleResidue_tp_compare,	/* tp_compare */
    (reprfunc)oaPoleResidue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPoleResidue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPoleResidue_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDesignObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPoleResidue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPoleResidue_static_create_doc[] = 
"Class: oaPoleResidue, Function: create\n"
"  Paramegers: (oaPiPoleResidue,oaDesignObject,oaFloat,oaComplexArray_oaFloat,oaComplexArray_oaFloat)\n"
"    Calls: oaPoleResidue* create(oaPiPoleResidue* model,oaDesignObject* receiver,oaFloat delay,const oaComplexArray_oaFloat& poles,const oaComplexArray_oaFloat& residues)\n"
"    Signature: create|ptr-oaPoleResidue|ptr-oaPiPoleResidue,ptr-oaDesignObject,simple-oaFloat,cref-oaComplexArray_oaFloat,cref-oaComplexArray_oaFloat,\n"
"    This function creates a new oaPoleResidue object for the specified receiver object, which can be terminal or instTerm in block or occurrence domain, and adds the oaPoleResidue object to the specified oaPiPoleResidue model .\n"
"    model\n"
"    The oaPiPoleResidue model to which to add this oaPoleResidue object\n"
"    receiver\n"
"    The receiver terminal for which to create the oaPoleResidue object\n"
"    delay\n"
"    The Elmore delay to the receiver for this oaPoleResidue object\n"
"    poles\n"
"    The complex numbers for each pole of the interconnect network\n"
"    residues\n"
"    The complex numbers for each residue for the receiver for this oaPoleResidue object\n"
"    oacDriverReceiverNotInSameDomain\n"
"    oacInvalidReducedModelObjectType\n"
"    oacInvalidReceiverTermType\n"
"    oacParasiticTermMustBeScalar\n"
"    oacParasiticInstTermMustBeScalar\n"
"    oacReceiverNetDoesNotMatchDriverNet\n"
;

static PyObject*
oaPoleResidue_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiPoleResidue p1;
    PyParamoaDesignObject p2;
    PyParamoaFloat p3;
    PyParamoaComplexArray_oaFloat p4;
    PyParamoaComplexArray_oaFloat p5;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&",
          &PyoaPiPoleResidue_Convert,&p1,
          &PyoaDesignObject_Convert,&p2,
          &PyoaFloat_Convert,&p3,
          &PyoaComplexArray_oaFloat_Convert,&p4,
          &PyoaComplexArray_oaFloat_Convert,&p5)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        oaPoleResiduep result= (oaPoleResidue::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
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
static char oaPoleResidue_static_find_doc[] = 
"Class: oaPoleResidue, Function: find\n"
"  Paramegers: (oaPiPoleResidue,oaDesignObject)\n"
"    Calls: oaPoleResidue* find(const oaPiPoleResidue* model,const oaDesignObject* receiver)\n"
"    Signature: find|ptr-oaPoleResidue|cptr-oaPiPoleResidue,cptr-oaDesignObject,\n"
"    This function finds and returns the oaPoleResidue value for the specified receiver object in the oaPiPoleResidue reduced model . If no oaPoleResidue object exists for the receiver, the function returns NULL.\n"
;

static PyObject*
oaPoleResidue_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPiPoleResidue p1;
    PyParamoaDesignObject p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaPiPoleResidue_Convert,&p1,
          &PyoaDesignObject_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        oaPoleResiduep result= (oaPoleResidue::find(p1.Data(),p2.Data()));
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
static PyMethodDef oaPoleResidue_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaPoleResidue_static_create,METH_VARARGS,oaPoleResidue_static_create_doc},
    {"static_find",(PyCFunction)oaPoleResidue_static_find,METH_VARARGS,oaPoleResidue_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPoleResidue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPoleResidue_Type)<0) {
      printf("** PyType_Ready failed for: oaPoleResidue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPoleResidue",
           (PyObject*)(&PyoaPoleResidue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPoleResidue\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaPoleResidue_Type.tp_dict;
    for(method=oaPoleResidue_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaPoleResidueModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaPoleResidueModTypeEnum_Convert(PyObject* ob,PyParamoaPoleResidueModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetValuePoleResidueModType")==0) { result->SetData(oacSetValuePoleResidueModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaPoleResidueModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPoleResidueModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaPoleResidueModTypeEnum_FromoaPoleResidueModTypeEnum(oaPoleResidueModTypeEnum ob)
{
    if (ob==oacSetValuePoleResidueModType) return PyString_FromString("oacSetValuePoleResidueModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaPoleResidueModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaPoleResidueModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaPoleResidueModTypeEnum_FromoaPoleResidueModTypeEnum(oaPoleResidueModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaPoleResidueModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaPoleResidueModTypeEnum_doc[] =
"Type convert function for enum: oaPoleResidueModTypeEnum";
                               
static PyMethodDef PyoaPoleResidueModTypeEnum_method =
  {"oaPoleResidueModTypeEnum",(PyCFunction)PyoaPoleResidueModTypeEnum_TypeFunction,METH_VARARGS,oaPoleResidueModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaPoleResidueModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetValuePoleResidueModType");
    PyDict_SetItemString(mod_dict,"oacSetValuePoleResidueModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaPoleResidueModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaPoleResidueModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaPoleResidueModTypeEnum\n");
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
// Wrapper Implementation for Class: oaPolygon
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPolygon_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPolygon_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPolygonObject* self = (PyoaPolygonObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaPolygon)
    {
        PyParamoaPolygon p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPolygon_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaPolygon, Choices are:\n"
        "    (oaPolygon)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPolygon_tp_dealloc(PyoaPolygonObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPolygon_tp_repr(PyObject *ob)
{
    PyParamoaPolygon value;
    int convert_status=PyoaPolygon_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[31];
    sprintf(buffer,"<oaPolygon::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaPolygon_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPolygon v1;
    PyParamoaPolygon v2;
    int convert_status1=PyoaPolygon_Convert(ob1,&v1);
    int convert_status2=PyoaPolygon_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPolygon_Convert(PyObject* ob,PyParamoaPolygon* result)
{
    if (ob == NULL) return 1;
    if (PyoaPolygon_Check(ob)) {
        result->SetData( (oaPolygon**) ((PyoaPolygonObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPolygon Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPolygon_FromoaPolygon(oaPolygon** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaPolygon* data=*value;
        PyObject* bself = PyoaPolygon_Type.tp_alloc(&PyoaPolygon_Type,0);
        if (bself == NULL) return bself;
        PyoaPolygonObject* self = (PyoaPolygonObject*)bself;
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
PyObject* PyoaPolygon_FromoaPolygon(oaPolygon* data)
{
    if (data) {
       PyObject* bself = PyoaPolygon_Type.tp_alloc(&PyoaPolygon_Type,0);
       if (bself == NULL) return bself;
       PyoaPolygonObject* self = (PyoaPolygonObject*)bself;
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
static char oaPolygon_convertToRect_doc[] = 
"Class: oaPolygon, Function: convertToRect\n"
"  Paramegers: ()\n"
"    Calls: oaRect* convertToRect()\n"
"    Signature: convertToRect|ptr-oaRect|\n"
"    BrowseData: 1\n"
"    This function converts this polygon into a rectangle. The rectangle is returned as the same pointer.\n"
"    Note: Only a four-point polygon is converted to a rectangle.\n"
"    oacCannotConvertPolygonToRect\n"
;

static PyObject*
oaPolygon_convertToRect(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPolygon data;
    int convert_status=PyoaPolygon_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPolygonObject* self=(PyoaPolygonObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaRectp result= (data.DataCall()->convertToRect());
        return PyoaRect_FromoaRect(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPolygon_getNumPoints_doc[] = 
"Class: oaPolygon, Function: getNumPoints\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumPoints() const\n"
"    Signature: getNumPoints|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of points in this polygon.\n"
;

static PyObject*
oaPolygon_getNumPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPolygon data;
    int convert_status=PyoaPolygon_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPolygonObject* self=(PyoaPolygonObject*)ob;
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
static char oaPolygon_getPoints_doc[] = 
"Class: oaPolygon, Function: getPoints\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void getPoints(oaPointArray& points) const\n"
"    Signature: getPoints|void-void|ref-oaPointArray,\n"
"    BrowseData: 0,oaPointArray\n"
"    This function returns the point array of this polygon.\n"
"    points\n"
"    The point array containing the points of this polygon\n"
;

static PyObject*
oaPolygon_getPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPolygon data;
    int convert_status=PyoaPolygon_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPolygonObject* self=(PyoaPolygonObject*)ob;
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
static char oaPolygon_isOrthogonal_doc[] = 
"Class: oaPolygon, Function: isOrthogonal\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isOrthogonal() const\n"
"    Signature: isOrthogonal|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates the pointArray of this polygon is orthogonal.\n"
;

static PyObject*
oaPolygon_isOrthogonal(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPolygon data;
    int convert_status=PyoaPolygon_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPolygonObject* self=(PyoaPolygonObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isOrthogonal());
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
static char oaPolygon_setPoints_doc[] = 
"Class: oaPolygon, Function: setPoints\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void setPoints(const oaPointArray& points)\n"
"    Signature: setPoints|void-void|cref-oaPointArray,\n"
"    This function sets the points of this polygon to the specified pointArray. If the array has collinear or coincident points, or the last and first points are the same, an exception is thrown. If the array has less than three points, an exception also is thrown.\n"
"    points\n"
"    The point array containing the points to set the oaPolygon object.\n"
"    oacPolygonHasExtraPoints\n"
"    oacPolygonTooFewPoints\n"
;

static PyObject*
oaPolygon_setPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPolygon data;
    int convert_status=PyoaPolygon_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPolygonObject* self=(PyoaPolygonObject*)ob;
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
static char oaPolygon_isNull_doc[] =
"Class: oaPolygon, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaPolygon_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaPolygon data;
    int convert_status=PyoaPolygon_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaPolygon_assign_doc[] = 
"Class: oaPolygon, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPolygon_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPolygon data;
  int convert_status=PyoaPolygon_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPolygon p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPolygon_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPolygon_methodlist[] = {
    {"convertToRect",(PyCFunction)oaPolygon_convertToRect,METH_VARARGS,oaPolygon_convertToRect_doc},
    {"getNumPoints",(PyCFunction)oaPolygon_getNumPoints,METH_VARARGS,oaPolygon_getNumPoints_doc},
    {"getPoints",(PyCFunction)oaPolygon_getPoints,METH_VARARGS,oaPolygon_getPoints_doc},
    {"isOrthogonal",(PyCFunction)oaPolygon_isOrthogonal,METH_VARARGS,oaPolygon_isOrthogonal_doc},
    {"setPoints",(PyCFunction)oaPolygon_setPoints,METH_VARARGS,oaPolygon_setPoints_doc},
    {"isNull",(PyCFunction)oaPolygon_tp_isNull,METH_VARARGS,oaPolygon_isNull_doc},
    {"assign",(PyCFunction)oaPolygon_tp_assign,METH_VARARGS,oaPolygon_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPolygon_doc[] = 
"Class: oaPolygon\n"
"  The oaPolygon class implements a polygon shape. An oaPointArray describing an oaPolygon must conform to the following requirements and assumptions:\n"
"  1) No duplicate (coincident) points -- duplicate points throw an exception (use oaPointArray::compress to remove coincident points).\n"
"  2) No collinear edges -- that is, three or more collinear points are illegal and cause an exception to be thrown (use oaPointArray::compress to remove collinear points).\n"
"  3) Polygon edges should not cross. An exception is NOT thrown if polygon edges cross, but oaPointArray::compress will produce incorrect results if the edges connected by the points in the array cross.\n"
"  4) oaPolygon functions that throw exceptions for collinear and coincident points, such as oaPolygon::create and oaPolygon::setPoints , assume that the polygon point array is closed--that is, that an edge connects the first and last polygon points specified in the array (since a polygon cannot have coincident points, the first and last polygon points must be different points).\n"
"Constructors:\n"
"  Paramegers: (oaPolygon)\n"
"    Calls: (const oaPolygon&)\n"
"    Signature: oaPolygon||cref-oaPolygon,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPolygon_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPolygon",
    sizeof(PyoaPolygonObject),
    0,
    (destructor)oaPolygon_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPolygon_tp_compare,	/* tp_compare */
    (reprfunc)oaPolygon_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPolygon_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPolygon_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaShape_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPolygon_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPolygon_static_create_doc[] = 
"Class: oaPolygon, Function: create\n"
"  Paramegers: (oaBlock,oaLayerNum,oaPurposeNum,oaPointArray)\n"
"    Calls: oaPolygon* create(oaBlock* block,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPointArray& points)\n"
"    Signature: create|ptr-oaPolygon|ptr-oaBlock,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPointArray,\n"
"    This function creates a polygon with the specified attributes. If the array has collinear or coincident points, or the last and first points of the array are the same, an exception is thrown. If the array has less than three points, an exception also is thrown.\n"
"    block\n"
"    The block in which this oaPolygon object is created\n"
"    layerNum\n"
"    The number of the layer on which this oaPolygon is created\n"
"    purposeNum\n"
"    The number of the layer purpose for this oaPolygon object\n"
"    points\n"
"    The array of points for this oaPolygon object\n"
"    oacPolygonHasExtraPoints\n"
"    oacPolygonTooFewPoints\n"
;

static PyObject*
oaPolygon_static_create(PyObject* ob, PyObject *args)
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
        oaPolygonp result= (oaPolygon::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
        return PyoaPolygon_FromoaPolygon(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaPolygon_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaPolygon_static_create,METH_VARARGS,oaPolygon_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPolygon_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPolygon_Type)<0) {
      printf("** PyType_Ready failed for: oaPolygon\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPolygon",
           (PyObject*)(&PyoaPolygon_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPolygon\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaPolygon_Type.tp_dict;
    for(method=oaPolygon_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaPrefRoutingDir
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPrefRoutingDir_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPrefRoutingDir_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPrefRoutingDirObject* self = (PyoaPrefRoutingDirObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaPrefRoutingDirEnum)
    {
        PyParamoaPrefRoutingDirEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaPrefRoutingDirEnum_Convert,&p1)) {
            self->value =  new oaPrefRoutingDir(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaPrefRoutingDir(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaPrefRoutingDir)
    {
        PyParamoaPrefRoutingDir p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPrefRoutingDir_Convert,&p1)) {
            self->value= new oaPrefRoutingDir(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaPrefRoutingDir, Choices are:\n"
        "    (oaPrefRoutingDirEnum)\n"
        "    (oaString)\n"
        "    (oaPrefRoutingDir)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPrefRoutingDir_tp_dealloc(PyoaPrefRoutingDirObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPrefRoutingDir_tp_repr(PyObject *ob)
{
    PyParamoaPrefRoutingDir value;
    int convert_status=PyoaPrefRoutingDir_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[38];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaPrefRoutingDir::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaPrefRoutingDir_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPrefRoutingDir v1;
    PyParamoaPrefRoutingDir v2;
    int convert_status1=PyoaPrefRoutingDir_Convert(ob1,&v1);
    int convert_status2=PyoaPrefRoutingDir_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPrefRoutingDir_Convert(PyObject* ob,PyParamoaPrefRoutingDir* result)
{
    if (ob == NULL) return 1;
    if (PyoaPrefRoutingDir_Check(ob)) {
        result->SetData(  ((PyoaPrefRoutingDirObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPrefRoutingDir Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPrefRoutingDir_FromoaPrefRoutingDir(oaPrefRoutingDir* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaPrefRoutingDir_Type.tp_alloc(&PyoaPrefRoutingDir_Type,0);
        if (bself == NULL) return bself;
        PyoaPrefRoutingDirObject* self = (PyoaPrefRoutingDirObject*)bself;
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
static char oaPrefRoutingDir_getName_doc[] = 
"Class: oaPrefRoutingDir, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaPrefRoutingDirEnum object.\n"
;

static PyObject*
oaPrefRoutingDir_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPrefRoutingDir data;
    int convert_status=PyoaPrefRoutingDir_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPrefRoutingDirObject* self=(PyoaPrefRoutingDirObject*)ob;

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
static char oaPrefRoutingDir_oaPrefRoutingDirEnum_doc[] = 
"Class: oaPrefRoutingDir, Function: oaPrefRoutingDirEnum\n"
"  Paramegers: ()\n"
"    Calls: oaPrefRoutingDirEnum oaPrefRoutingDirEnum() const\n"
"    Signature: operator oaPrefRoutingDirEnum|simple-oaPrefRoutingDirEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaPrefRoutingDir object into the corresponding #oaPrefRoutingDirEnum value.\n"
;

static PyObject*
oaPrefRoutingDir_oaPrefRoutingDirEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPrefRoutingDir data;
    int convert_status=PyoaPrefRoutingDir_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPrefRoutingDirObject* self=(PyoaPrefRoutingDirObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPrefRoutingDirEnum result= (data.DataCall()->operator oaPrefRoutingDirEnum());
        return PyoaPrefRoutingDirEnum_FromoaPrefRoutingDirEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaPrefRoutingDir_assign_doc[] = 
"Class: oaPrefRoutingDir, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPrefRoutingDir_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPrefRoutingDir data;
  int convert_status=PyoaPrefRoutingDir_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPrefRoutingDir p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPrefRoutingDir_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPrefRoutingDir_methodlist[] = {
    {"getName",(PyCFunction)oaPrefRoutingDir_getName,METH_VARARGS,oaPrefRoutingDir_getName_doc},
    {"oaPrefRoutingDirEnum",(PyCFunction)oaPrefRoutingDir_oaPrefRoutingDirEnum,METH_VARARGS,oaPrefRoutingDir_oaPrefRoutingDirEnum_doc},
    {"assign",(PyCFunction)oaPrefRoutingDir_tp_assign,METH_VARARGS,oaPrefRoutingDir_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPrefRoutingDir_doc[] = 
"Class: oaPrefRoutingDir\n"
"  The oaPrefRoutingDir class encapsulates the enumerated values that describe the different preferred routing directions.\n"
"  oaPrefRoutingDirEnum\n"
"Constructors:\n"
"  Paramegers: (oaPrefRoutingDirEnum)\n"
"    Calls: oaPrefRoutingDir(oaPrefRoutingDirEnum valueIn)\n"
"    Signature: oaPrefRoutingDir||simple-oaPrefRoutingDirEnum,\n"
"    This function constructs an instance of an oaPrefRoutingDir class using the specified enum value. The enum values are defined in #oaPrefRoutingDirEnum.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaPrefRoutingDir(const oaString& name)\n"
"    Signature: oaPrefRoutingDir||cref-oaString,\n"
"    This function constructs an instance of an oaPrefRoutingDir class using the #oaPrefRoutingDirEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaPrefRoutingDirEnum.\n"
"    oacInvalidPrefRoutingDirName\n"
"  Paramegers: (oaPrefRoutingDir)\n"
"    Calls: (const oaPrefRoutingDir&)\n"
"    Signature: oaPrefRoutingDir||cref-oaPrefRoutingDir,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPrefRoutingDir_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPrefRoutingDir",
    sizeof(PyoaPrefRoutingDirObject),
    0,
    (destructor)oaPrefRoutingDir_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPrefRoutingDir_tp_compare,	/* tp_compare */
    (reprfunc)oaPrefRoutingDir_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPrefRoutingDir_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPrefRoutingDir_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPrefRoutingDir_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPrefRoutingDir_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPrefRoutingDir_Type)<0) {
      printf("** PyType_Ready failed for: oaPrefRoutingDir\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPrefRoutingDir",
           (PyObject*)(&PyoaPrefRoutingDir_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPrefRoutingDir\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaPrefRoutingDirEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaPrefRoutingDirEnum_Convert(PyObject* ob,PyParamoaPrefRoutingDirEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacNotApplicablePrefRoutingDir")==0) { result->SetData(oacNotApplicablePrefRoutingDir); return 1;}
        if (strcasecmp(str,"oacNonePrefRoutingDir")==0) { result->SetData(oacNonePrefRoutingDir); return 1;}
        if (strcasecmp(str,"oacHorzPrefRoutingDir")==0) { result->SetData(oacHorzPrefRoutingDir); return 1;}
        if (strcasecmp(str,"oacVertPrefRoutingDir")==0) { result->SetData(oacVertPrefRoutingDir); return 1;}
        if (strcasecmp(str,"oacLeftDiagPrefRoutingDir")==0) { result->SetData(oacLeftDiagPrefRoutingDir); return 1;}
        if (strcasecmp(str,"oacRightDiagPrefRoutingDir")==0) { result->SetData(oacRightDiagPrefRoutingDir); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaPrefRoutingDirEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPrefRoutingDirEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaPrefRoutingDirEnum_FromoaPrefRoutingDirEnum(oaPrefRoutingDirEnum ob)
{
    if (ob==oacNotApplicablePrefRoutingDir) return PyString_FromString("oacNotApplicablePrefRoutingDir");
    if (ob==oacNonePrefRoutingDir) return PyString_FromString("oacNonePrefRoutingDir");
    if (ob==oacHorzPrefRoutingDir) return PyString_FromString("oacHorzPrefRoutingDir");
    if (ob==oacVertPrefRoutingDir) return PyString_FromString("oacVertPrefRoutingDir");
    if (ob==oacLeftDiagPrefRoutingDir) return PyString_FromString("oacLeftDiagPrefRoutingDir");
    if (ob==oacRightDiagPrefRoutingDir) return PyString_FromString("oacRightDiagPrefRoutingDir");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaPrefRoutingDirEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaPrefRoutingDirEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaPrefRoutingDirEnum_FromoaPrefRoutingDirEnum(oaPrefRoutingDirEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaPrefRoutingDirEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaPrefRoutingDirEnum_doc[] =
"Type convert function for enum: oaPrefRoutingDirEnum";
                               
static PyMethodDef PyoaPrefRoutingDirEnum_method =
  {"oaPrefRoutingDirEnum",(PyCFunction)PyoaPrefRoutingDirEnum_TypeFunction,METH_VARARGS,oaPrefRoutingDirEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaPrefRoutingDirEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacNotApplicablePrefRoutingDir");
    PyDict_SetItemString(mod_dict,"oacNotApplicablePrefRoutingDir",value);
    Py_DECREF(value);
    value=PyString_FromString("oacNonePrefRoutingDir");
    PyDict_SetItemString(mod_dict,"oacNonePrefRoutingDir",value);
    Py_DECREF(value);
    value=PyString_FromString("oacHorzPrefRoutingDir");
    PyDict_SetItemString(mod_dict,"oacHorzPrefRoutingDir",value);
    Py_DECREF(value);
    value=PyString_FromString("oacVertPrefRoutingDir");
    PyDict_SetItemString(mod_dict,"oacVertPrefRoutingDir",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLeftDiagPrefRoutingDir");
    PyDict_SetItemString(mod_dict,"oacLeftDiagPrefRoutingDir",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRightDiagPrefRoutingDir");
    PyDict_SetItemString(mod_dict,"oacRightDiagPrefRoutingDir",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaPrefRoutingDirEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaPrefRoutingDirEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaPrefRoutingDirEnum\n");
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
// Wrapper Implementation for Class: oaProp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaProp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaProp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPropObject* self = (PyoaPropObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaProp)
    {
        PyParamoaProp p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaProp_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaProp, Choices are:\n"
        "    (oaProp)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaProp_tp_dealloc(PyoaPropObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaProp_tp_repr(PyObject *ob)
{
    PyParamoaProp value;
    int convert_status=PyoaProp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaProp::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[28];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaProp::");
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
oaProp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaProp v1;
    PyParamoaProp v2;
    int convert_status1=PyoaProp_Convert(ob1,&v1);
    int convert_status2=PyoaProp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaProp_Convert(PyObject* ob,PyParamoaProp* result)
{
    if (ob == NULL) return 1;
    if (PyoaProp_Check(ob)) {
        result->SetData( (oaProp**) ((PyoaPropObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaProp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaProp_FromoaProp(oaProp** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaProp* data=*value;
        if (data->getType()==oacDoublePropType) return PyoaDoubleProp_FromoaDoubleProp((oaDoubleProp**)value,borrow,lock);
        if (data->getType()==oacTimePropType) return PyoaTimeProp_FromoaTimeProp((oaTimeProp**)value,borrow,lock);
        if (data->getType()==oacStringPropType) return PyoaStringProp_FromoaStringProp((oaStringProp**)value,borrow,lock);
        if (data->getType()==oacBooleanPropType) return PyoaBooleanProp_FromoaBooleanProp((oaBooleanProp**)value,borrow,lock);
        if (data->getType()==oacTimeRangePropType) return PyoaTimeRangeProp_FromoaTimeRangeProp((oaTimeRangeProp**)value,borrow,lock);
        if (data->getType()==oacAppPropType) return PyoaAppProp_FromoaAppProp((oaAppProp**)value,borrow,lock);
        if (data->getType()==oacFloatRangePropType) return PyoaFloatRangeProp_FromoaFloatRangeProp((oaFloatRangeProp**)value,borrow,lock);
        if (data->getType()==oacEnumPropType) return PyoaEnumProp_FromoaEnumProp((oaEnumProp**)value,borrow,lock);
        if (data->getType()==oacFloatPropType) return PyoaFloatProp_FromoaFloatProp((oaFloatProp**)value,borrow,lock);
        if (data->getType()==oacIntPropType) return PyoaIntProp_FromoaIntProp((oaIntProp**)value,borrow,lock);
        if (data->getType()==oacDoubleRangePropType) return PyoaDoubleRangeProp_FromoaDoubleRangeProp((oaDoubleRangeProp**)value,borrow,lock);
        if (data->getType()==oacHierPropType) return PyoaHierProp_FromoaHierProp((oaHierProp**)value,borrow,lock);
        if (data->getType()==oacIntRangePropType) return PyoaIntRangeProp_FromoaIntRangeProp((oaIntRangeProp**)value,borrow,lock);
        PyObject* bself = PyoaProp_Type.tp_alloc(&PyoaProp_Type,0);
        if (bself == NULL) return bself;
        PyoaPropObject* self = (PyoaPropObject*)bself;
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
PyObject* PyoaProp_FromoaProp(oaProp* data)
{
    if (data) {
        if (data->getType()==oacDoublePropType) return PyoaDoubleProp_FromoaDoubleProp((oaDoubleProp*)data);
        if (data->getType()==oacTimePropType) return PyoaTimeProp_FromoaTimeProp((oaTimeProp*)data);
        if (data->getType()==oacStringPropType) return PyoaStringProp_FromoaStringProp((oaStringProp*)data);
        if (data->getType()==oacBooleanPropType) return PyoaBooleanProp_FromoaBooleanProp((oaBooleanProp*)data);
        if (data->getType()==oacTimeRangePropType) return PyoaTimeRangeProp_FromoaTimeRangeProp((oaTimeRangeProp*)data);
        if (data->getType()==oacAppPropType) return PyoaAppProp_FromoaAppProp((oaAppProp*)data);
        if (data->getType()==oacFloatRangePropType) return PyoaFloatRangeProp_FromoaFloatRangeProp((oaFloatRangeProp*)data);
        if (data->getType()==oacEnumPropType) return PyoaEnumProp_FromoaEnumProp((oaEnumProp*)data);
        if (data->getType()==oacFloatPropType) return PyoaFloatProp_FromoaFloatProp((oaFloatProp*)data);
        if (data->getType()==oacIntPropType) return PyoaIntProp_FromoaIntProp((oaIntProp*)data);
        if (data->getType()==oacDoubleRangePropType) return PyoaDoubleRangeProp_FromoaDoubleRangeProp((oaDoubleRangeProp*)data);
        if (data->getType()==oacHierPropType) return PyoaHierProp_FromoaHierProp((oaHierProp*)data);
        if (data->getType()==oacIntRangePropType) return PyoaIntRangeProp_FromoaIntRangeProp((oaIntRangeProp*)data);
       PyObject* bself = PyoaProp_Type.tp_alloc(&PyoaProp_Type,0);
       if (bself == NULL) return bself;
       PyoaPropObject* self = (PyoaPropObject*)bself;
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
static char oaProp_copyTo_doc[] = 
"Class: oaProp, Function: copyTo\n"
"  Paramegers: (oaObject)\n"
"    Calls: oaProp* copyTo(oaObject* object) const\n"
"    Signature: copyTo|ptr-oaProp|ptr-oaObject,\n"
"    This function creates a copy of this property on the specified object, and returns the new property. The new object may either be in the same or a different database from the original property.\n"
"    oacPropNameUsed\n"
;

static PyObject*
oaProp_copyTo(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaProp data;
    int convert_status=PyoaProp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPropObject* self=(PyoaPropObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaObject_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaPropp result= (data.DataCall()->copyTo(p1.Data()));
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
static char oaProp_destroy_doc[] = 
"Class: oaProp, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this property, removing it from the database.\n"
;

static PyObject*
oaProp_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaProp data;
    int convert_status=PyoaProp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPropObject* self=(PyoaPropObject*)ob;
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
static char oaProp_getName_doc[] = 
"Class: oaProp, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of the property in name .\n"
;

static PyObject*
oaProp_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaProp data;
    int convert_status=PyoaProp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPropObject* self=(PyoaPropObject*)ob;
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
static char oaProp_getOwner_doc[] = 
"Class: oaProp, Function: getOwner\n"
"  Paramegers: ()\n"
"    Calls: oaObject* getOwner() const\n"
"    Signature: getOwner|ptr-oaObject|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the object that owns this property.\n"
;

static PyObject*
oaProp_getOwner(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaProp data;
    int convert_status=PyoaProp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPropObject* self=(PyoaPropObject*)ob;
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
static char oaProp_getValue_doc[] = 
"Class: oaProp, Function: getValue\n"
"  Paramegers: (oaString)\n"
"    Calls: void getValue(oaString& value) const\n"
"    Signature: getValue|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function converts the value of this property to a string and returns the result in value . The is the string that will be shown if this property is displayed using an oaPropDisplay .\n"
"    Note that many of the oaProp subclasses have a getValue function that returns the property value as its native type. These functions usually have a different argument type.\n"
"    When called with a property of type oaHierProp this call will return the constant string \"oaHierProp\".\n"
;

static PyObject*
oaProp_getValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaProp data;
    int convert_status=PyoaProp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPropObject* self=(PyoaPropObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
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
static char oaProp_moveTo_doc[] = 
"Class: oaProp, Function: moveTo\n"
"  Paramegers: (oaObject)\n"
"    Calls: oaProp* moveTo(oaObject* object)\n"
"    Signature: moveTo|ptr-oaProp|ptr-oaObject,\n"
"    This function moves this property to the specifed object. If the object resides in a different design, the returned property pointer points to a property in that design rather than the property with which this operation was initiated. The property will be removed from the object it was previously associated with.\n"
"    oacPropNameUsed\n"
;

static PyObject*
oaProp_moveTo(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaProp data;
    int convert_status=PyoaProp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPropObject* self=(PyoaPropObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaObject_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaPropp result= (data.DataCall()->moveTo(p1.Data()));
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
static char oaProp_setName_doc[] = 
"Class: oaProp, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function sets the name of this property to the specified name .\n"
"    oacPropNameUsed\n"
;

static PyObject*
oaProp_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaProp data;
    int convert_status=PyoaProp_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPropObject* self=(PyoaPropObject*)ob;
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
static char oaProp_isNull_doc[] =
"Class: oaProp, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaProp_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaProp data;
    int convert_status=PyoaProp_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaProp_assign_doc[] = 
"Class: oaProp, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaProp_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaProp data;
  int convert_status=PyoaProp_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaProp p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaProp_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaProp_methodlist[] = {
    {"copyTo",(PyCFunction)oaProp_copyTo,METH_VARARGS,oaProp_copyTo_doc},
    {"destroy",(PyCFunction)oaProp_destroy,METH_VARARGS,oaProp_destroy_doc},
    {"getName",(PyCFunction)oaProp_getName,METH_VARARGS,oaProp_getName_doc},
    {"getOwner",(PyCFunction)oaProp_getOwner,METH_VARARGS,oaProp_getOwner_doc},
    {"getValue",(PyCFunction)oaProp_getValue,METH_VARARGS,oaProp_getValue_doc},
    {"moveTo",(PyCFunction)oaProp_moveTo,METH_VARARGS,oaProp_moveTo_doc},
    {"setName",(PyCFunction)oaProp_setName,METH_VARARGS,oaProp_setName_doc},
    {"isNull",(PyCFunction)oaProp_tp_isNull,METH_VARARGS,oaProp_isNull_doc},
    {"assign",(PyCFunction)oaProp_tp_assign,METH_VARARGS,oaProp_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaProp_doc[] = 
"Class: oaProp\n"
"  The oaProp class is an abstract base for all types of properties.\n"
"  Properties are application-defined values that can be added to any managed object in any database except for the paged objects: oaDevice , oaNode , oaParasiticNetwork , and oaSubNetwork .\n"
"  Also note that Note: oaProps and oaAppDefs should not be created on oaDMObjects such as oaLibs and oaCellViews. While OpenAccess does not enforce this restriction, there is no way to save such extensions. Instead, use a corresponding oaDMData object to properly represent these Props and AppDefs.\n"
"  Properties are a simple name/value pair. They are optimized for sparse usage on any managed object in an OpenAccess database. They are often used by application programmers for simple customization. Properties are persistently stored in the database. They are visible to anyone who queries for them. Currently there are 13 types of properties that have different types of values. Click on the specific property in the above Inheritance diagram for more details.\n"
"  If applications need to extend the database schema, instead of adding simple name/value pair properties, oaAppDef extensions should be used instead. See Extending the Database in the Programmers Guide for a general discussion of appDefs.\n"
"  The oaProp class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaProp)\n"
"    Calls: (const oaProp&)\n"
"    Signature: oaProp||cref-oaProp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaProp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaProp",
    sizeof(PyoaPropObject),
    0,
    (destructor)oaProp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaProp_tp_compare,	/* tp_compare */
    (reprfunc)oaProp_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaProp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaProp_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaProp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaProp_static_find_doc[] = 
"Class: oaProp, Function: find\n"
"  Paramegers: (oaObject,oaString)\n"
"    Calls: oaProp* find(const oaObject* object,const oaString& name)\n"
"    Signature: find|ptr-oaProp|cptr-oaObject,cref-oaString,simple-oaBoolean,\n"
"    This function searches the specified object for a property with the specified name . If found, the function returns the property. Otherwise, the function returns NULL.\n"
"    If the specified object is a multi-domain object and crossDomain is true, this function searches other domains and inherits properties from the other domains if appropriate. The order of domains from which a multi-domain object can inherit properties is:\n"
"    design-level occurrence\n"
"    design-local occurrence\n"
"    block domain\n"
"    module domain\n"
"    For example, a design-local occurrence object can inherit properties with the same name defined on its equivalant block domain object, and it can inherit properties from the module domain object as well.\n"
"    Note: The owner of the inherited property remains as the equivalent object in the other domain.\n"
"  Paramegers: (oaObject,oaString,oaBoolean)\n"
"    Calls: oaProp* find(const oaObject* object,const oaString& name,oaBoolean crossDomain)\n"
"    Signature: find|ptr-oaProp|cptr-oaObject,cref-oaString,simple-oaBoolean,\n"
"    This function searches the specified object for a property with the specified name . If found, the function returns the property. Otherwise, the function returns NULL.\n"
"    If the specified object is a multi-domain object and crossDomain is true, this function searches other domains and inherits properties from the other domains if appropriate. The order of domains from which a multi-domain object can inherit properties is:\n"
"    design-level occurrence\n"
"    design-local occurrence\n"
"    block domain\n"
"    module domain\n"
"    For example, a design-local occurrence object can inherit properties with the same name defined on its equivalant block domain object, and it can inherit properties from the module domain object as well.\n"
"    Note: The owner of the inherited property remains as the equivalent object in the other domain.\n"
;

static PyObject*
oaProp_static_find(PyObject* ob, PyObject *args)
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
            oaPropp result= (oaProp::find(p1.Data(),p2.Data()));
            return PyoaProp_FromoaProp(result);
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
            oaPropp result= (oaProp::find(p1.Data(),p2.Data(),p3.Data()));
            return PyoaProp_FromoaProp(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaProp, function: find, Choices are:\n"
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
static PyMethodDef oaProp_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaProp_static_find,METH_VARARGS,oaProp_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaProp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaProp_Type)<0) {
      printf("** PyType_Ready failed for: oaProp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaProp",
           (PyObject*)(&PyoaProp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaProp\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaProp_Type.tp_dict;
    for(method=oaProp_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaPropDisplay
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPropDisplay_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPropDisplay_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPropDisplayObject* self = (PyoaPropDisplayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaPropDisplay)
    {
        PyParamoaPropDisplay p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPropDisplay_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaPropDisplay, Choices are:\n"
        "    (oaPropDisplay)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPropDisplay_tp_dealloc(PyoaPropDisplayObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPropDisplay_tp_repr(PyObject *ob)
{
    PyParamoaPropDisplay value;
    int convert_status=PyoaPropDisplay_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaPropDisplay::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaPropDisplay_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPropDisplay v1;
    PyParamoaPropDisplay v2;
    int convert_status1=PyoaPropDisplay_Convert(ob1,&v1);
    int convert_status2=PyoaPropDisplay_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPropDisplay_Convert(PyObject* ob,PyParamoaPropDisplay* result)
{
    if (ob == NULL) return 1;
    if (PyoaPropDisplay_Check(ob)) {
        result->SetData( (oaPropDisplay**) ((PyoaPropDisplayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPropDisplay Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPropDisplay_FromoaPropDisplay(oaPropDisplay** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaPropDisplay* data=*value;
        PyObject* bself = PyoaPropDisplay_Type.tp_alloc(&PyoaPropDisplay_Type,0);
        if (bself == NULL) return bself;
        PyoaPropDisplayObject* self = (PyoaPropDisplayObject*)bself;
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
PyObject* PyoaPropDisplay_FromoaPropDisplay(oaPropDisplay* data)
{
    if (data) {
       PyObject* bself = PyoaPropDisplay_Type.tp_alloc(&PyoaPropDisplay_Type,0);
       if (bself == NULL) return bself;
       PyoaPropDisplayObject* self = (PyoaPropDisplayObject*)bself;
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
static char oaPropDisplay_getProp_doc[] = 
"Class: oaPropDisplay, Function: getProp\n"
"  Paramegers: ()\n"
"    Calls: oaProp* getProp() const\n"
"    Signature: getProp|ptr-oaProp|\n"
"    BrowseData: 1\n"
"    This function returns the owner oaProp object of this oaPropDisplay.\n"
;

static PyObject*
oaPropDisplay_getProp(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPropDisplay data;
    int convert_status=PyoaPropDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPropDisplayObject* self=(PyoaPropDisplayObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaPropp result= (data.DataCall()->getProp());
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
static char oaPropDisplay_isNull_doc[] =
"Class: oaPropDisplay, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaPropDisplay_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaPropDisplay data;
    int convert_status=PyoaPropDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaPropDisplay_assign_doc[] = 
"Class: oaPropDisplay, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPropDisplay_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPropDisplay data;
  int convert_status=PyoaPropDisplay_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPropDisplay p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPropDisplay_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPropDisplay_methodlist[] = {
    {"getProp",(PyCFunction)oaPropDisplay_getProp,METH_VARARGS,oaPropDisplay_getProp_doc},
    {"isNull",(PyCFunction)oaPropDisplay_tp_isNull,METH_VARARGS,oaPropDisplay_isNull_doc},
    {"assign",(PyCFunction)oaPropDisplay_tp_assign,METH_VARARGS,oaPropDisplay_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPropDisplay_doc[] = 
"Class: oaPropDisplay\n"
"  The oaPropDisplay class creates a shape similar to an oaText object, except that it presents a string that is the value of the specified oaProp object. Whenever the value of the oaProp changes, calling the getText function on this display object returns the updated text string that represents the oaProp value.\n"
"  The oaPropDisplay object is contained in the design database that contains the oaProp object.\n"
"Constructors:\n"
"  Paramegers: (oaPropDisplay)\n"
"    Calls: (const oaPropDisplay&)\n"
"    Signature: oaPropDisplay||cref-oaPropDisplay,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPropDisplay_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPropDisplay",
    sizeof(PyoaPropDisplayObject),
    0,
    (destructor)oaPropDisplay_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPropDisplay_tp_compare,	/* tp_compare */
    (reprfunc)oaPropDisplay_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPropDisplay_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPropDisplay_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaTextDisplay_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPropDisplay_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPropDisplay_static_create_doc[] = 
"Class: oaPropDisplay, Function: create\n"
"  Paramegers: (oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist)\n"
"    Calls: oaPropDisplay* create(oaProp* prop,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height)\n"
"    Signature: create|ptr-oaPropDisplay|ptr-oaProp,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates a propDisplay object with the specified attributes.\n"
"    prop\n"
"    The oaProp object with which this textDisplay is associated\n"
"    layerNum\n"
"    The number of the layer for this textDisplay\n"
"    purposeNum\n"
"    The number of the purpose for this textDisplay\n"
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
"    oacNonDesignTextDisplay\n"
"  Paramegers: (oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat)\n"
"    Calls: oaPropDisplay* create(oaProp* prop,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height,oaTextDisplayFormat format)\n"
"    Signature: create|ptr-oaPropDisplay|ptr-oaProp,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates a propDisplay object with the specified attributes.\n"
"    prop\n"
"    The oaProp object with which this textDisplay is associated\n"
"    layerNum\n"
"    The number of the layer for this textDisplay\n"
"    purposeNum\n"
"    The number of the purpose for this textDisplay\n"
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
"    oacNonDesignTextDisplay\n"
"  Paramegers: (oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean)\n"
"    Calls: oaPropDisplay* create(oaProp* prop,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height,oaTextDisplayFormat format,oaBoolean overbar)\n"
"    Signature: create|ptr-oaPropDisplay|ptr-oaProp,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates a propDisplay object with the specified attributes.\n"
"    prop\n"
"    The oaProp object with which this textDisplay is associated\n"
"    layerNum\n"
"    The number of the layer for this textDisplay\n"
"    purposeNum\n"
"    The number of the purpose for this textDisplay\n"
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
"    oacNonDesignTextDisplay\n"
"  Paramegers: (oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean)\n"
"    Calls: oaPropDisplay* create(oaProp* prop,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height,oaTextDisplayFormat format,oaBoolean overbar,oaBoolean visible)\n"
"    Signature: create|ptr-oaPropDisplay|ptr-oaProp,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates a propDisplay object with the specified attributes.\n"
"    prop\n"
"    The oaProp object with which this textDisplay is associated\n"
"    layerNum\n"
"    The number of the layer for this textDisplay\n"
"    purposeNum\n"
"    The number of the purpose for this textDisplay\n"
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
"    oacNonDesignTextDisplay\n"
"  Paramegers: (oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean,oaBoolean)\n"
"    Calls: oaPropDisplay* create(oaProp* prop,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaPoint& origin,oaTextAlign alignment,oaOrient orient,oaFont font,oaDist height,oaTextDisplayFormat format,oaBoolean overbar,oaBoolean visible,oaBoolean drafting)\n"
"    Signature: create|ptr-oaPropDisplay|ptr-oaProp,simple-oaLayerNum,simple-oaPurposeNum,cref-oaPoint,simple-oaTextAlign,simple-oaOrient,simple-oaFont,simple-oaDist,simple-oaTextDisplayFormat,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates a propDisplay object with the specified attributes.\n"
"    prop\n"
"    The oaProp object with which this textDisplay is associated\n"
"    layerNum\n"
"    The number of the layer for this textDisplay\n"
"    purposeNum\n"
"    The number of the purpose for this textDisplay\n"
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
"    oacNonDesignTextDisplay\n"
;

static PyObject*
oaPropDisplay_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist)
    {
        PyParamoaProp p1;
        PyParamoaLayerNum p2;
        PyParamoaPurposeNum p3;
        PyParamoaPoint p4;
        PyParamoaTextAlign p5;
        PyParamoaOrient p6;
        PyParamoaFont p7;
        PyParamoaDist p8;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&",
              &PyoaProp_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaPurposeNum_Convert,&p3,
              &PyoaPoint_Convert,&p4,
              &PyoaTextAlign_Convert,&p5,
              &PyoaOrient_Convert,&p6,
              &PyoaFont_Convert,&p7,
              &PyoaDist_Convert,&p8)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPropDisplayp result= (oaPropDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data()));
            return PyoaPropDisplay_FromoaPropDisplay(result);
        }
    }
    PyErr_Clear();
    // Case: (oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat)
    {
        PyParamoaProp p1;
        PyParamoaLayerNum p2;
        PyParamoaPurposeNum p3;
        PyParamoaPoint p4;
        PyParamoaTextAlign p5;
        PyParamoaOrient p6;
        PyParamoaFont p7;
        PyParamoaDist p8;
        PyParamoaTextDisplayFormat p9;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&",
              &PyoaProp_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaPurposeNum_Convert,&p3,
              &PyoaPoint_Convert,&p4,
              &PyoaTextAlign_Convert,&p5,
              &PyoaOrient_Convert,&p6,
              &PyoaFont_Convert,&p7,
              &PyoaDist_Convert,&p8,
              &PyoaTextDisplayFormat_Convert,&p9)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPropDisplayp result= (oaPropDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data()));
            return PyoaPropDisplay_FromoaPropDisplay(result);
        }
    }
    PyErr_Clear();
    // Case: (oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean)
    {
        PyParamoaProp p1;
        PyParamoaLayerNum p2;
        PyParamoaPurposeNum p3;
        PyParamoaPoint p4;
        PyParamoaTextAlign p5;
        PyParamoaOrient p6;
        PyParamoaFont p7;
        PyParamoaDist p8;
        PyParamoaTextDisplayFormat p9;
        PyParamoaBoolean p10;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&O&",
              &PyoaProp_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaPurposeNum_Convert,&p3,
              &PyoaPoint_Convert,&p4,
              &PyoaTextAlign_Convert,&p5,
              &PyoaOrient_Convert,&p6,
              &PyoaFont_Convert,&p7,
              &PyoaDist_Convert,&p8,
              &PyoaTextDisplayFormat_Convert,&p9,
              &PyoaBoolean_Convert,&p10)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPropDisplayp result= (oaPropDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data(),p10.Data()));
            return PyoaPropDisplay_FromoaPropDisplay(result);
        }
    }
    PyErr_Clear();
    // Case: (oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean)
    {
        PyParamoaProp p1;
        PyParamoaLayerNum p2;
        PyParamoaPurposeNum p3;
        PyParamoaPoint p4;
        PyParamoaTextAlign p5;
        PyParamoaOrient p6;
        PyParamoaFont p7;
        PyParamoaDist p8;
        PyParamoaTextDisplayFormat p9;
        PyParamoaBoolean p10;
        PyParamoaBoolean p11;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&O&O&",
              &PyoaProp_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaPurposeNum_Convert,&p3,
              &PyoaPoint_Convert,&p4,
              &PyoaTextAlign_Convert,&p5,
              &PyoaOrient_Convert,&p6,
              &PyoaFont_Convert,&p7,
              &PyoaDist_Convert,&p8,
              &PyoaTextDisplayFormat_Convert,&p9,
              &PyoaBoolean_Convert,&p10,
              &PyoaBoolean_Convert,&p11)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPropDisplayp result= (oaPropDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data(),p10.Data(),p11.Data()));
            return PyoaPropDisplay_FromoaPropDisplay(result);
        }
    }
    PyErr_Clear();
    // Case: (oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean,oaBoolean)
    {
        PyParamoaProp p1;
        PyParamoaLayerNum p2;
        PyParamoaPurposeNum p3;
        PyParamoaPoint p4;
        PyParamoaTextAlign p5;
        PyParamoaOrient p6;
        PyParamoaFont p7;
        PyParamoaDist p8;
        PyParamoaTextDisplayFormat p9;
        PyParamoaBoolean p10;
        PyParamoaBoolean p11;
        PyParamoaBoolean p12;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&O&O&O&",
              &PyoaProp_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaPurposeNum_Convert,&p3,
              &PyoaPoint_Convert,&p4,
              &PyoaTextAlign_Convert,&p5,
              &PyoaOrient_Convert,&p6,
              &PyoaFont_Convert,&p7,
              &PyoaDist_Convert,&p8,
              &PyoaTextDisplayFormat_Convert,&p9,
              &PyoaBoolean_Convert,&p10,
              &PyoaBoolean_Convert,&p11,
              &PyoaBoolean_Convert,&p12)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPropDisplayp result= (oaPropDisplay::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data(),p10.Data(),p11.Data(),p12.Data()));
            return PyoaPropDisplay_FromoaPropDisplay(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaPropDisplay, function: create, Choices are:\n"
        "    (oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist)\n"
        "    (oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat)\n"
        "    (oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean)\n"
        "    (oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean)\n"
        "    (oaProp,oaLayerNum,oaPurposeNum,oaPoint,oaTextAlign,oaOrient,oaFont,oaDist,oaTextDisplayFormat,oaBoolean,oaBoolean,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaPropDisplay_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaPropDisplay_static_create,METH_VARARGS,oaPropDisplay_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPropDisplay_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPropDisplay_Type)<0) {
      printf("** PyType_Ready failed for: oaPropDisplay\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPropDisplay",
           (PyObject*)(&PyoaPropDisplay_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPropDisplay\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaPropDisplay_Type.tp_dict;
    for(method=oaPropDisplay_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaPropModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaPropModTypeEnum_Convert(PyObject* ob,PyParamoaPropModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetNamePropModType")==0) { result->SetData(oacSetNamePropModType); return 1;}
        if (strcasecmp(str,"oacSetValuePropModType")==0) { result->SetData(oacSetValuePropModType); return 1;}
        if (strcasecmp(str,"oacSetRangePropModType")==0) { result->SetData(oacSetRangePropModType); return 1;}
        if (strcasecmp(str,"oacMovePropModType")==0) { result->SetData(oacMovePropModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaPropModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPropModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaPropModTypeEnum_FromoaPropModTypeEnum(oaPropModTypeEnum ob)
{
    if (ob==oacSetNamePropModType) return PyString_FromString("oacSetNamePropModType");
    if (ob==oacSetValuePropModType) return PyString_FromString("oacSetValuePropModType");
    if (ob==oacSetRangePropModType) return PyString_FromString("oacSetRangePropModType");
    if (ob==oacMovePropModType) return PyString_FromString("oacMovePropModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaPropModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaPropModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaPropModTypeEnum_FromoaPropModTypeEnum(oaPropModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaPropModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaPropModTypeEnum_doc[] =
"Type convert function for enum: oaPropModTypeEnum";
                               
static PyMethodDef PyoaPropModTypeEnum_method =
  {"oaPropModTypeEnum",(PyCFunction)PyoaPropModTypeEnum_TypeFunction,METH_VARARGS,oaPropModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaPropModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetNamePropModType");
    PyDict_SetItemString(mod_dict,"oacSetNamePropModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetValuePropModType");
    PyDict_SetItemString(mod_dict,"oacSetValuePropModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetRangePropModType");
    PyDict_SetItemString(mod_dict,"oacSetRangePropModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMovePropModType");
    PyDict_SetItemString(mod_dict,"oacMovePropModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaPropModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaPropModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaPropModTypeEnum\n");
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
// Wrapper Implementation for Class: oaPurpose
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPurpose_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPurpose_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPurposeObject* self = (PyoaPurposeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaPurpose)
    {
        PyParamoaPurpose p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPurpose_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaPurpose, Choices are:\n"
        "    (oaPurpose)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPurpose_tp_dealloc(PyoaPurposeObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPurpose_tp_repr(PyObject *ob)
{
    PyParamoaPurpose value;
    int convert_status=PyoaPurpose_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaPurpose::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[31];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaPurpose::");
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
oaPurpose_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPurpose v1;
    PyParamoaPurpose v2;
    int convert_status1=PyoaPurpose_Convert(ob1,&v1);
    int convert_status2=PyoaPurpose_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPurpose_Convert(PyObject* ob,PyParamoaPurpose* result)
{
    if (ob == NULL) return 1;
    if (PyoaPurpose_Check(ob)) {
        result->SetData( (oaPurpose**) ((PyoaPurposeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPurpose Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPurpose_FromoaPurpose(oaPurpose** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaPurpose* data=*value;
        PyObject* bself = PyoaPurpose_Type.tp_alloc(&PyoaPurpose_Type,0);
        if (bself == NULL) return bself;
        PyoaPurposeObject* self = (PyoaPurposeObject*)bself;
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
PyObject* PyoaPurpose_FromoaPurpose(oaPurpose* data)
{
    if (data) {
       PyObject* bself = PyoaPurpose_Type.tp_alloc(&PyoaPurpose_Type,0);
       if (bself == NULL) return bself;
       PyoaPurposeObject* self = (PyoaPurposeObject*)bself;
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
static char oaPurpose_destroy_doc[] = 
"Class: oaPurpose, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this purpose, removing it from the technology database.\n"
"    oacCannotDestroyReservedPurpose\n"
;

static PyObject*
oaPurpose_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPurpose data;
    int convert_status=PyoaPurpose_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPurposeObject* self=(PyoaPurposeObject*)ob;
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
static char oaPurpose_getName_doc[] = 
"Class: oaPurpose, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of this purpose.\n"
;

static PyObject*
oaPurpose_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPurpose data;
    int convert_status=PyoaPurpose_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPurposeObject* self=(PyoaPurposeObject*)ob;
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
static char oaPurpose_getNumber_doc[] = 
"Class: oaPurpose, Function: getNumber\n"
"  Paramegers: ()\n"
"    Calls: oaPurposeNum getNumber() const\n"
"    Signature: getNumber|simple-oaPurposeNum|\n"
"    BrowseData: 1\n"
"    This function returns the number of this purpose.\n"
;

static PyObject*
oaPurpose_getNumber(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPurpose data;
    int convert_status=PyoaPurpose_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPurposeObject* self=(PyoaPurposeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaPurposeNum result= (data.DataCall()->getNumber());
        return PyoaPurposeNum_FromoaPurposeNum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPurpose_getPurposeType_doc[] = 
"Class: oaPurpose, Function: getPurposeType\n"
"  Paramegers: ()\n"
"    Calls: oaPurposeType getPurposeType() const\n"
"    Signature: getPurposeType|simple-oaPurposeType|\n"
"    BrowseData: 1\n"
"    This function returns the purpose type of this purpose.\n"
;

static PyObject*
oaPurpose_getPurposeType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPurpose data;
    int convert_status=PyoaPurpose_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPurposeObject* self=(PyoaPurposeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaPurposeType* result= new oaPurposeType(data.DataCall()->getPurposeType());
        return PyoaPurposeType_FromoaPurposeType(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPurpose_isReserved_doc[] = 
"Class: oaPurpose, Function: isReserved\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isReserved() const\n"
"    Signature: isReserved|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if this purpose is reserved.\n"
;

static PyObject*
oaPurpose_isReserved(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPurpose data;
    int convert_status=PyoaPurpose_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPurposeObject* self=(PyoaPurposeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isReserved());
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
static char oaPurpose_setName_doc[] = 
"Class: oaPurpose, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function sets the name of this purpose to the specified value.\n"
"    oacCannotChangeReservedPurpose\n"
"    oacPurposeNameExists\n"
;

static PyObject*
oaPurpose_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPurpose data;
    int convert_status=PyoaPurpose_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPurposeObject* self=(PyoaPurposeObject*)ob;
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
static char oaPurpose_setNumber_doc[] = 
"Class: oaPurpose, Function: setNumber\n"
"  Paramegers: (oaPurposeNum)\n"
"    Calls: void setNumber(oaPurposeNum number)\n"
"    Signature: setNumber|void-void|simple-oaPurposeNum,\n"
"    This function sets the number of this purpose to the specified value.\n"
"    oacCannotChangeReservedPurpose\n"
"    oacPurposeNumberExists\n"
;

static PyObject*
oaPurpose_setNumber(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPurpose data;
    int convert_status=PyoaPurpose_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPurposeObject* self=(PyoaPurposeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPurposeNum p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPurposeNum_Convert,&p1)) {
        data.DataCall()->setNumber(p1.Data());
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
static char oaPurpose_isNull_doc[] =
"Class: oaPurpose, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaPurpose_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaPurpose data;
    int convert_status=PyoaPurpose_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaPurpose_assign_doc[] = 
"Class: oaPurpose, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPurpose_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPurpose data;
  int convert_status=PyoaPurpose_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPurpose p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPurpose_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPurpose_methodlist[] = {
    {"destroy",(PyCFunction)oaPurpose_destroy,METH_VARARGS,oaPurpose_destroy_doc},
    {"getName",(PyCFunction)oaPurpose_getName,METH_VARARGS,oaPurpose_getName_doc},
    {"getNumber",(PyCFunction)oaPurpose_getNumber,METH_VARARGS,oaPurpose_getNumber_doc},
    {"getPurposeType",(PyCFunction)oaPurpose_getPurposeType,METH_VARARGS,oaPurpose_getPurposeType_doc},
    {"isReserved",(PyCFunction)oaPurpose_isReserved,METH_VARARGS,oaPurpose_isReserved_doc},
    {"setName",(PyCFunction)oaPurpose_setName,METH_VARARGS,oaPurpose_setName_doc},
    {"setNumber",(PyCFunction)oaPurpose_setNumber,METH_VARARGS,oaPurpose_setNumber_doc},
    {"isNull",(PyCFunction)oaPurpose_tp_isNull,METH_VARARGS,oaPurpose_isNull_doc},
    {"assign",(PyCFunction)oaPurpose_tp_assign,METH_VARARGS,oaPurpose_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPurpose_doc[] = 
"Class: oaPurpose\n"
"  The oaPurpose class defines a purpose that may be referenced along with a layer when creating physical design data. A purpose consists of a purpose type, a purpose name, and a purpose number.\n"
"  Each technology database will have a set of predefined purposes which correspond to the eight oaPurpose types. These predefined purposes are always available, and may not be changed nor removed. This set of predefined purposes is as follows:\n"
"  Type\n"
"  Name\n"
"  Number\n"
"  oacDrawingPurposeType\n"
"  \"drawing\"\n"
"  oavPurposeNumberDrawing\n"
"  oacFillPurposeType\n"
"  \"fill\"\n"
"  oavPurposeNumberFill\n"
"  oacSlotPurposeType\n"
"  \"slot\"\n"
"  oavPurposeNumberSlot\n"
"  oacOPCSerifPurposeType\n"
"  \"OPCSerif\"\n"
"  oavPurposeNumberOPCSerif\n"
"  oacOPCAntiSerifPurposeType\n"
"  \"OPCAntiSerif\"\n"
"  oavPurposeNumberOPCAntiSerif\n"
"  oacAnnotationPurposeType\n"
"  \"annotation\"\n"
"  oavPurposeNumberAnnotation\n"
"  oacGapFillPurposeType\n"
"  \"gapFill\"\n"
"  oavPurposeNumberGapFill\n"
"  oacRedundantPurposeType\n"
"  \"redundant\"\n"
"  oavPurposeNumberRedundant\n"
"  Additional purposes which are added into the tech database by users will be of type oaPurposeTypeEnum::oacDrawingPurposeType.\n"
"  The oaPurpose class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaPurpose)\n"
"    Calls: (const oaPurpose&)\n"
"    Signature: oaPurpose||cref-oaPurpose,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPurpose_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPurpose",
    sizeof(PyoaPurposeObject),
    0,
    (destructor)oaPurpose_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPurpose_tp_compare,	/* tp_compare */
    (reprfunc)oaPurpose_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPurpose_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPurpose_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaTechObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPurpose_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPurpose_static_create_doc[] = 
"Class: oaPurpose, Function: create\n"
"  Paramegers: (oaTech,oaString,oaPurposeNum)\n"
"    Calls: oaPurpose* create(oaTech* tech,const oaString& name,oaPurposeNum number)\n"
"    Signature: create|ptr-oaPurpose|ptr-oaTech,cref-oaString,simple-oaPurposeNum,\n"
"    This function creates a purpose with the specified name and number . Any purpose number in the set of unsigned four-byte integers is a valid purpose number.\n"
"    oacPurposeNumberExists\n"
"    oacPurposeNameExists\n"
;

static PyObject*
oaPurpose_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaTech p1;
    PyParamoaString p2;
    PyParamoaPurposeNum p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaTech_Convert,&p1,
          &PyoaString_Convert,&p2,
          &PyoaPurposeNum_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaPurposep result= (oaPurpose::create(p1.Data(),p2.Data(),p3.Data()));
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
static char oaPurpose_static_find_doc[] = 
"Class: oaPurpose, Function: find\n"
"  Paramegers: (oaTech,oaString)\n"
"    Calls: oaPurpose* find(const oaTech* tech,const oaString& name)\n"
"    Signature: find|ptr-oaPurpose|cptr-oaTech,cref-oaString,\n"
"    This function searches the specified technology database for a purpose with the specified name . If the specified technology database references other technology databases, those are searched as well and the first matching purpose is returned. To find a purpose in the current technology database only, refer to the find function that accepts the local argument.\n"
"    If the function finds the specified purpose, it returns a pointer to the oaPurpose object. Otherwise, NULL is returned.\n"
"    Refer to Incremental Technology Databases in the Using Technology Databases section of the Programmers Guide for more information about referenced tech databases.\n"
"    tech\n"
"    The technology database to search\n"
"    name\n"
"    The name of the purpose to find\n"
"  Paramegers: (oaTech,oaPurposeNum)\n"
"    Calls: oaPurpose* find(const oaTech* tech,oaPurposeNum number)\n"
"    Signature: find|ptr-oaPurpose|cptr-oaTech,simple-oaPurposeNum,\n"
"    This function searches the specified technology database for a purpose with the specified number . If the specified technology database references other technology databases, those are searched as well and the first matching purpose is returned. To find a purpose in the current technology database only, refer to the find function that accepts the local argument.\n"
"    If the function finds the specified purpose, it returns a pointer to the oaPurpose object. Otherwise, NULL is returned.\n"
"    Refer to Incremental Technology Databases in the Using Technology Databases section of the Programmers Guide for more information about referenced tech databases.\n"
"    tech\n"
"    The technology database to search\n"
"    number\n"
"    The purpose number to find\n"
"  Paramegers: (oaTech,oaString,oaBoolean)\n"
"    Calls: oaPurpose* find(const oaTech* tech,const oaString& name,oaBoolean local)\n"
"    Signature: find|ptr-oaPurpose|cptr-oaTech,cref-oaString,simple-oaBoolean,\n"
"    oaPurpose::findName2\n"
"    This function searches for a purpose with the specified name. The local argument specifies whether (if true) to look only in the specified technology database or (if false) to look in the specified technology database and all of its referenced databases. If the purpose is found, a pointer to the purpose object is returned, otherwise NULL is returned.\n"
"    Refer to Incremental Technology Databases in the Using Technology Databases section of the Programmers Guide for more information about referenced tech databases.\n"
"    tech\n"
"    The technology database to search\n"
"    name\n"
"    The name of the purpose to find\n"
"    local\n"
"    Specifies whether (if true) to look only in the specified technology database or (if false) to look in the specified technology database and all of its referenced databases.\n"
"  Paramegers: (oaTech,oaPurposeNum,oaBoolean)\n"
"    Calls: oaPurpose* find(const oaTech* tech,oaPurposeNum number,oaBoolean local)\n"
"    Signature: find|ptr-oaPurpose|cptr-oaTech,simple-oaPurposeNum,simple-oaBoolean,\n"
"    oaPurpose::findNum2\n"
"    This function searches for a purpose with the specified number. The local argument specifies whether (if true) to look only in the specified technology database or (if false) to look in the specified technology database and all of its referenced databases. If the purpose is found, a pointer to the purpose object is returned, otherwise NULL is returned.\n"
"    Refer to Incremental Technology Databases in the Using Technology Databases section of the Programmers Guide for more information about referenced tech databases.\n"
"    tech\n"
"    The technology database to search\n"
"    number\n"
"    The purpose number to find\n"
"    local\n"
"    Specifies whether (if true) to look only in the specified technology database or (if false) to look in the specified technology database and all of its referenced databases.\n"
;

static PyObject*
oaPurpose_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaTech,oaString)
    {
        PyParamoaTech p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPurposep result= (oaPurpose::find(p1.Data(),p2.Data()));
            return PyoaPurpose_FromoaPurpose(result);
        }
    }
    PyErr_Clear();
    // Case: (oaTech,oaPurposeNum)
    {
        PyParamoaTech p1;
        PyParamoaPurposeNum p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaPurposeNum_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPurposep result= (oaPurpose::find(p1.Data(),p2.Data()));
            return PyoaPurpose_FromoaPurpose(result);
        }
    }
    PyErr_Clear();
    // Case: (oaTech,oaString,oaBoolean)
    {
        PyParamoaTech p1;
        PyParamoaString p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPurposep result= (oaPurpose::find(p1.Data(),p2.Data(),p3.Data()));
            return PyoaPurpose_FromoaPurpose(result);
        }
    }
    PyErr_Clear();
    // Case: (oaTech,oaPurposeNum,oaBoolean)
    {
        PyParamoaTech p1;
        PyParamoaPurposeNum p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaPurposeNum_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaPurposep result= (oaPurpose::find(p1.Data(),p2.Data(),p3.Data()));
            return PyoaPurpose_FromoaPurpose(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaPurpose, function: find, Choices are:\n"
        "    (oaTech,oaString)\n"
        "    (oaTech,oaPurposeNum)\n"
        "    (oaTech,oaString,oaBoolean)\n"
        "    (oaTech,oaPurposeNum,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaPurpose_static_get_doc[] = 
"Class: oaPurpose, Function: get\n"
"  Paramegers: (oaTech,oaPurposeType)\n"
"    Calls: oaPurpose* get(oaTech* tech,oaPurposeType type)\n"
"    Signature: get|ptr-oaPurpose|ptr-oaTech,simple-oaPurposeType,\n"
"    This function returns the reserved purpose of the specified purposeType .\n"
;

static PyObject*
oaPurpose_static_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaTech p1;
    PyParamoaPurposeType p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaTech_Convert,&p1,
          &PyoaPurposeType_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaPurposep result= (oaPurpose::get(p1.Data(),p2.Data()));
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
static PyMethodDef oaPurpose_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaPurpose_static_create,METH_VARARGS,oaPurpose_static_create_doc},
    {"static_find",(PyCFunction)oaPurpose_static_find,METH_VARARGS,oaPurpose_static_find_doc},
    {"static_get",(PyCFunction)oaPurpose_static_get,METH_VARARGS,oaPurpose_static_get_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPurpose_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPurpose_Type)<0) {
      printf("** PyType_Ready failed for: oaPurpose\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPurpose",
           (PyObject*)(&PyoaPurpose_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPurpose\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaPurpose_Type.tp_dict;
    for(method=oaPurpose_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaPurposeModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaPurposeModTypeEnum_Convert(PyObject* ob,PyParamoaPurposeModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetNumberPurposeModType")==0) { result->SetData(oacSetNumberPurposeModType); return 1;}
        if (strcasecmp(str,"oacSetNamePurposeModType")==0) { result->SetData(oacSetNamePurposeModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaPurposeModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPurposeModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaPurposeModTypeEnum_FromoaPurposeModTypeEnum(oaPurposeModTypeEnum ob)
{
    if (ob==oacSetNumberPurposeModType) return PyString_FromString("oacSetNumberPurposeModType");
    if (ob==oacSetNamePurposeModType) return PyString_FromString("oacSetNamePurposeModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaPurposeModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaPurposeModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaPurposeModTypeEnum_FromoaPurposeModTypeEnum(oaPurposeModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaPurposeModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaPurposeModTypeEnum_doc[] =
"Type convert function for enum: oaPurposeModTypeEnum";
                               
static PyMethodDef PyoaPurposeModTypeEnum_method =
  {"oaPurposeModTypeEnum",(PyCFunction)PyoaPurposeModTypeEnum_TypeFunction,METH_VARARGS,oaPurposeModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaPurposeModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetNumberPurposeModType");
    PyDict_SetItemString(mod_dict,"oacSetNumberPurposeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetNamePurposeModType");
    PyDict_SetItemString(mod_dict,"oacSetNamePurposeModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaPurposeModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaPurposeModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaPurposeModTypeEnum\n");
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
// Wrapper Implementation for Class: oaPurposeType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaPurposeType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaPurposeType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaPurposeTypeObject* self = (PyoaPurposeTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaPurposeTypeEnum)
    {
        PyParamoaPurposeTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaPurposeTypeEnum_Convert,&p1)) {
            self->value =  new oaPurposeType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaPurposeType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaPurposeType)
    {
        PyParamoaPurposeType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaPurposeType_Convert,&p1)) {
            self->value= new oaPurposeType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaPurposeType, Choices are:\n"
        "    (oaPurposeTypeEnum)\n"
        "    (oaString)\n"
        "    (oaPurposeType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaPurposeType_tp_dealloc(PyoaPurposeTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaPurposeType_tp_repr(PyObject *ob)
{
    PyParamoaPurposeType value;
    int convert_status=PyoaPurposeType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[35];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaPurposeType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaPurposeType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaPurposeType v1;
    PyParamoaPurposeType v2;
    int convert_status1=PyoaPurposeType_Convert(ob1,&v1);
    int convert_status2=PyoaPurposeType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaPurposeType_Convert(PyObject* ob,PyParamoaPurposeType* result)
{
    if (ob == NULL) return 1;
    if (PyoaPurposeType_Check(ob)) {
        result->SetData(  ((PyoaPurposeTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPurposeType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaPurposeType_FromoaPurposeType(oaPurposeType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaPurposeType_Type.tp_alloc(&PyoaPurposeType_Type,0);
        if (bself == NULL) return bself;
        PyoaPurposeTypeObject* self = (PyoaPurposeTypeObject*)bself;
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
static char oaPurposeType_getName_doc[] = 
"Class: oaPurposeType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaPurposeTypeEnum object.\n"
;

static PyObject*
oaPurposeType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPurposeType data;
    int convert_status=PyoaPurposeType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPurposeTypeObject* self=(PyoaPurposeTypeObject*)ob;

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
static char oaPurposeType_oaPurposeTypeEnum_doc[] = 
"Class: oaPurposeType, Function: oaPurposeTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaPurposeTypeEnum oaPurposeTypeEnum() const\n"
"    Signature: operator oaPurposeTypeEnum|simple-oaPurposeTypeEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaPurposeType object into the corresponding #oaPurposeTypeEnum value.\n"
;

static PyObject*
oaPurposeType_oaPurposeTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPurposeType data;
    int convert_status=PyoaPurposeType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaPurposeTypeObject* self=(PyoaPurposeTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPurposeTypeEnum result= (data.DataCall()->operator oaPurposeTypeEnum());
        return PyoaPurposeTypeEnum_FromoaPurposeTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaPurposeType_assign_doc[] = 
"Class: oaPurposeType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaPurposeType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaPurposeType data;
  int convert_status=PyoaPurposeType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaPurposeType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaPurposeType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaPurposeType_methodlist[] = {
    {"getName",(PyCFunction)oaPurposeType_getName,METH_VARARGS,oaPurposeType_getName_doc},
    {"oaPurposeTypeEnum",(PyCFunction)oaPurposeType_oaPurposeTypeEnum,METH_VARARGS,oaPurposeType_oaPurposeTypeEnum_doc},
    {"assign",(PyCFunction)oaPurposeType_tp_assign,METH_VARARGS,oaPurposeType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPurposeType_doc[] = 
"Class: oaPurposeType\n"
"  The oaPurposeType class encapsulates the enumerated values that describe the different uses of an oaPurpose object.\n"
"  oaPurposeTypeEnum\n"
"Constructors:\n"
"  Paramegers: (oaPurposeTypeEnum)\n"
"    Calls: oaPurposeType(oaPurposeTypeEnum valueIn)\n"
"    Signature: oaPurposeType||simple-oaPurposeTypeEnum,\n"
"    This function constructs an instance of an oaPurposeType class using the specified #oaPurposeTypeEnum value.\n"
"    valueIn\n"
"    A value from the enumerated list representing purpose types that this object will represent\n"
"  Paramegers: (oaString)\n"
"    Calls: oaPurposeType(const oaString& name)\n"
"    Signature: oaPurposeType||cref-oaString,\n"
"    This function constructs an instance of an oaPurposeType class using the #oaPurposeTypeEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaPurposeTypeEnum.\n"
"    name\n"
"    A reference to an oaString object representing a valid purpose type name\n"
"    oacInvalidPurposeTypeName\n"
"  Paramegers: (oaPurposeType)\n"
"    Calls: (const oaPurposeType&)\n"
"    Signature: oaPurposeType||cref-oaPurposeType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaPurposeType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaPurposeType",
    sizeof(PyoaPurposeTypeObject),
    0,
    (destructor)oaPurposeType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaPurposeType_tp_compare,	/* tp_compare */
    (reprfunc)oaPurposeType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaPurposeType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaPurposeType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaPurposeType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaPurposeType_static_get_doc[] = 
"Class: oaPurposeType, Function: get\n"
"  Paramegers: (oaPurposeNum)\n"
"    Calls: oaPurposeTypeEnum get(oaPurposeNum purposeNum)\n"
"    Signature: get|simple-oaPurposeTypeEnum|simple-oaPurposeNum,\n"
"    This utility function converts a purposeNum to a purposeType.\n"
"    purposeNum\n"
"    input purpose number\n"
;

static PyObject*
oaPurposeType_static_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaPurposeNum p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPurposeNum_Convert,&p1)) {
        oaPurposeTypeEnum result= (oaPurposeType::get(p1.Data()));
        return PyoaPurposeTypeEnum_FromoaPurposeTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaPurposeType_staticmethodlist[] = {
    {"static_get",(PyCFunction)oaPurposeType_static_get,METH_VARARGS,oaPurposeType_static_get_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaPurposeType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaPurposeType_Type)<0) {
      printf("** PyType_Ready failed for: oaPurposeType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaPurposeType",
           (PyObject*)(&PyoaPurposeType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaPurposeType\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaPurposeType_Type.tp_dict;
    for(method=oaPurposeType_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaPurposeTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaPurposeTypeEnum_Convert(PyObject* ob,PyParamoaPurposeTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacDrawingPurposeType")==0) { result->SetData(oacDrawingPurposeType); return 1;}
        if (strcasecmp(str,"oacFillPurposeType")==0) { result->SetData(oacFillPurposeType); return 1;}
        if (strcasecmp(str,"oacSlotPurposeType")==0) { result->SetData(oacSlotPurposeType); return 1;}
        if (strcasecmp(str,"oacOPCSerifPurposeType")==0) { result->SetData(oacOPCSerifPurposeType); return 1;}
        if (strcasecmp(str,"oacOPCAntiSerifPurposeType")==0) { result->SetData(oacOPCAntiSerifPurposeType); return 1;}
        if (strcasecmp(str,"oacAnnotationPurposeType")==0) { result->SetData(oacAnnotationPurposeType); return 1;}
        if (strcasecmp(str,"oacGapFillPurposeType")==0) { result->SetData(oacGapFillPurposeType); return 1;}
        if (strcasecmp(str,"oacRedundantPurposeType")==0) { result->SetData(oacRedundantPurposeType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaPurposeTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaPurposeTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaPurposeTypeEnum_FromoaPurposeTypeEnum(oaPurposeTypeEnum ob)
{
    if (ob==oacDrawingPurposeType) return PyString_FromString("oacDrawingPurposeType");
    if (ob==oacFillPurposeType) return PyString_FromString("oacFillPurposeType");
    if (ob==oacSlotPurposeType) return PyString_FromString("oacSlotPurposeType");
    if (ob==oacOPCSerifPurposeType) return PyString_FromString("oacOPCSerifPurposeType");
    if (ob==oacOPCAntiSerifPurposeType) return PyString_FromString("oacOPCAntiSerifPurposeType");
    if (ob==oacAnnotationPurposeType) return PyString_FromString("oacAnnotationPurposeType");
    if (ob==oacGapFillPurposeType) return PyString_FromString("oacGapFillPurposeType");
    if (ob==oacRedundantPurposeType) return PyString_FromString("oacRedundantPurposeType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaPurposeTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaPurposeTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaPurposeTypeEnum_FromoaPurposeTypeEnum(oaPurposeTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaPurposeTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaPurposeTypeEnum_doc[] =
"Type convert function for enum: oaPurposeTypeEnum";
                               
static PyMethodDef PyoaPurposeTypeEnum_method =
  {"oaPurposeTypeEnum",(PyCFunction)PyoaPurposeTypeEnum_TypeFunction,METH_VARARGS,oaPurposeTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaPurposeTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacDrawingPurposeType");
    PyDict_SetItemString(mod_dict,"oacDrawingPurposeType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFillPurposeType");
    PyDict_SetItemString(mod_dict,"oacFillPurposeType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSlotPurposeType");
    PyDict_SetItemString(mod_dict,"oacSlotPurposeType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacOPCSerifPurposeType");
    PyDict_SetItemString(mod_dict,"oacOPCSerifPurposeType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacOPCAntiSerifPurposeType");
    PyDict_SetItemString(mod_dict,"oacOPCAntiSerifPurposeType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAnnotationPurposeType");
    PyDict_SetItemString(mod_dict,"oacAnnotationPurposeType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacGapFillPurposeType");
    PyDict_SetItemString(mod_dict,"oacGapFillPurposeType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRedundantPurposeType");
    PyDict_SetItemString(mod_dict,"oacRedundantPurposeType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaPurposeTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaPurposeTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaPurposeTypeEnum\n");
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
// Wrapper Implementation for Class: oaRangeBase
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRangeBase_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRangeBase_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRangeBaseObject* self = (PyoaRangeBaseObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaRangeBase();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaRangeTypeEnum)
    {
        PyParamoaRangeTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaRangeTypeEnum_Convert,&p1)) {
            self->value =  new oaRangeBase(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaRangeBase)
    {
        PyParamoaRangeBase p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaRangeBase_Convert,&p1)) {
            self->value= new oaRangeBase(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaRangeBase, Choices are:\n"
        "    ()\n"
        "    (oaRangeTypeEnum)\n"
        "    (oaRangeBase)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRangeBase_tp_dealloc(PyoaRangeBaseObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRangeBase_tp_repr(PyObject *ob)
{
    PyParamoaRangeBase value;
    int convert_status=PyoaRangeBase_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[33];
    sprintf(buffer,"<oaRangeBase::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRangeBase_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRangeBase v1;
    PyParamoaRangeBase v2;
    int convert_status1=PyoaRangeBase_Convert(ob1,&v1);
    int convert_status2=PyoaRangeBase_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRangeBase_Convert(PyObject* ob,PyParamoaRangeBase* result)
{
    if (ob == NULL) return 1;
    if (PyoaRangeBase_Check(ob)) {
        result->SetData(  ((PyoaRangeBaseObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRangeBase Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRangeBase_FromoaRangeBase(oaRangeBase* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaRangeBase_Type.tp_alloc(&PyoaRangeBase_Type,0);
        if (bself == NULL) return bself;
        PyoaRangeBaseObject* self = (PyoaRangeBaseObject*)bself;
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
static char oaRangeBase_getRangeType_doc[] = 
"Class: oaRangeBase, Function: getRangeType\n"
"  Paramegers: ()\n"
"    Calls: oaRangeType getRangeType() const\n"
"    Signature: getRangeType|simple-oaRangeType|\n"
"    BrowseData: 1\n"
"    This function returns the rangeType of this oaRangeBase object.\n"
;

static PyObject*
oaRangeBase_getRangeType(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRangeBase data;
    int convert_status=PyoaRangeBase_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRangeBaseObject* self=(PyoaRangeBaseObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaRangeType* result= new oaRangeType(data.DataCall()->getRangeType());
        return PyoaRangeType_FromoaRangeType(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRangeBase_hasLowerBound_doc[] = 
"Class: oaRangeBase, Function: hasLowerBound\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasLowerBound() const\n"
"    Signature: hasLowerBound|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this oaRangeBase object has a lower bound.\n"
;

static PyObject*
oaRangeBase_hasLowerBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRangeBase data;
    int convert_status=PyoaRangeBase_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRangeBaseObject* self=(PyoaRangeBaseObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasLowerBound());
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
static char oaRangeBase_hasUpperBound_doc[] = 
"Class: oaRangeBase, Function: hasUpperBound\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasUpperBound() const\n"
"    Signature: hasUpperBound|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this oaRangeBase object has an upper bound.\n"
;

static PyObject*
oaRangeBase_hasUpperBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRangeBase data;
    int convert_status=PyoaRangeBase_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRangeBaseObject* self=(PyoaRangeBaseObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasUpperBound());
        return PyoaBoolean_FromoaBoolean(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaRangeBase_assign_doc[] = 
"Class: oaRangeBase, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRangeBase_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRangeBase data;
  int convert_status=PyoaRangeBase_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRangeBase p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRangeBase_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRangeBase_methodlist[] = {
    {"getRangeType",(PyCFunction)oaRangeBase_getRangeType,METH_VARARGS,oaRangeBase_getRangeType_doc},
    {"hasLowerBound",(PyCFunction)oaRangeBase_hasLowerBound,METH_VARARGS,oaRangeBase_hasLowerBound_doc},
    {"hasUpperBound",(PyCFunction)oaRangeBase_hasUpperBound,METH_VARARGS,oaRangeBase_hasUpperBound_doc},
    {"assign",(PyCFunction)oaRangeBase_tp_assign,METH_VARARGS,oaRangeBase_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRangeBase_doc[] = 
"Class: oaRangeBase\n"
"  This is a base class for range classes.\n"
"  Todo\n"
"  Check description of class.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaRangeBase()\n"
"    Signature: oaRangeBase||\n"
"    This is the default oaRangeBase constructor.\n"
"  Paramegers: (oaRangeTypeEnum)\n"
"    Calls: oaRangeBase(oaRangeTypeEnum rangeTypeIn)\n"
"    Signature: oaRangeBase||simple-oaRangeTypeEnum,\n"
"    This oaRangeBase constructor creates an oaRangeBase object of the specified rangeType .\n"
"    rangeTypeIn\n"
"    The rangeType of object to construct.\n"
"  Paramegers: (oaRangeBase)\n"
"    Calls: (const oaRangeBase&)\n"
"    Signature: oaRangeBase||cref-oaRangeBase,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRangeBase_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRangeBase",
    sizeof(PyoaRangeBaseObject),
    0,
    (destructor)oaRangeBase_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRangeBase_tp_compare,	/* tp_compare */
    (reprfunc)oaRangeBase_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRangeBase_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRangeBase_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRangeBase_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRangeBase_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRangeBase_Type)<0) {
      printf("** PyType_Ready failed for: oaRangeBase\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRangeBase",
           (PyObject*)(&PyoaRangeBase_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRangeBase\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaRangeType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRangeType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRangeType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRangeTypeObject* self = (PyoaRangeTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaRangeTypeEnum)
    {
        PyParamoaRangeTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaRangeTypeEnum_Convert,&p1)) {
            self->value =  new oaRangeType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaRangeType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaRangeType)
    {
        PyParamoaRangeType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaRangeType_Convert,&p1)) {
            self->value= new oaRangeType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaRangeType, Choices are:\n"
        "    (oaRangeTypeEnum)\n"
        "    (oaString)\n"
        "    (oaRangeType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRangeType_tp_dealloc(PyoaRangeTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRangeType_tp_repr(PyObject *ob)
{
    PyParamoaRangeType value;
    int convert_status=PyoaRangeType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[33];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaRangeType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRangeType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRangeType v1;
    PyParamoaRangeType v2;
    int convert_status1=PyoaRangeType_Convert(ob1,&v1);
    int convert_status2=PyoaRangeType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRangeType_Convert(PyObject* ob,PyParamoaRangeType* result)
{
    if (ob == NULL) return 1;
    if (PyoaRangeType_Check(ob)) {
        result->SetData(  ((PyoaRangeTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRangeType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRangeType_FromoaRangeType(oaRangeType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaRangeType_Type.tp_alloc(&PyoaRangeType_Type,0);
        if (bself == NULL) return bself;
        PyoaRangeTypeObject* self = (PyoaRangeTypeObject*)bself;
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
static char oaRangeType_getName_doc[] = 
"Class: oaRangeType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the string name of the oaRangeTypeEnum value represented by this oaRangeType object.\n"
;

static PyObject*
oaRangeType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRangeType data;
    int convert_status=PyoaRangeType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRangeTypeObject* self=(PyoaRangeTypeObject*)ob;

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
static char oaRangeType_oaRangeTypeEnum_doc[] = 
"Class: oaRangeType, Function: oaRangeTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaRangeTypeEnum oaRangeTypeEnum() const\n"
"    Signature: operator oaRangeTypeEnum|simple-oaRangeTypeEnum|\n"
"    BrowseData: 1\n"
"    This operation recasts this oaRangeType object to the oaRangeTypeEnum value it represents.\n"
;

static PyObject*
oaRangeType_oaRangeTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRangeType data;
    int convert_status=PyoaRangeType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRangeTypeObject* self=(PyoaRangeTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaRangeTypeEnum result= (data.DataCall()->operator oaRangeTypeEnum());
        return PyoaRangeTypeEnum_FromoaRangeTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaRangeType_assign_doc[] = 
"Class: oaRangeType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRangeType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRangeType data;
  int convert_status=PyoaRangeType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRangeType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRangeType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRangeType_methodlist[] = {
    {"getName",(PyCFunction)oaRangeType_getName,METH_VARARGS,oaRangeType_getName_doc},
    {"oaRangeTypeEnum",(PyCFunction)oaRangeType_oaRangeTypeEnum,METH_VARARGS,oaRangeType_oaRangeTypeEnum_doc},
    {"assign",(PyCFunction)oaRangeType_tp_assign,METH_VARARGS,oaRangeType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRangeType_doc[] = 
"Class: oaRangeType\n"
"  oaRangeTypeEnum\n"
"  The oaRangeType class is an enumeration wrapper class for oaRangeTypeEnum values.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"Constructors:\n"
"  Paramegers: (oaRangeTypeEnum)\n"
"    Calls: oaRangeType(oaRangeTypeEnum valueIn)\n"
"    Signature: oaRangeType||simple-oaRangeTypeEnum,\n"
"    This constructor for an oaRangeType wrapper object takes an oaRangeTypeEnum value as input.\n"
"    valueIn\n"
"    An oaRangeTypeEnum value.\n"
"    Todo\n"
"    Check description of member function.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaRangeType(const oaString& name)\n"
"    Signature: oaRangeType||cref-oaString,\n"
"    This constructor for an oaRangeType wrapper object takes the string name of an oaRangeTypeEnum value as input.\n"
"    name\n"
"    The string name associated with an oaRangeTypeEnum value.\n"
"    oacInvalidRangeTypeName\n"
"  Paramegers: (oaRangeType)\n"
"    Calls: (const oaRangeType&)\n"
"    Signature: oaRangeType||cref-oaRangeType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRangeType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRangeType",
    sizeof(PyoaRangeTypeObject),
    0,
    (destructor)oaRangeType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRangeType_tp_compare,	/* tp_compare */
    (reprfunc)oaRangeType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRangeType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRangeType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRangeType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRangeType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRangeType_Type)<0) {
      printf("** PyType_Ready failed for: oaRangeType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRangeType",
           (PyObject*)(&PyoaRangeType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRangeType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaRangeTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaRangeTypeEnum_Convert(PyObject* ob,PyParamoaRangeTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacLessThanRangeType")==0) { result->SetData(oacLessThanRangeType); return 1;}
        if (strcasecmp(str,"oacLessThanEqualRangeType")==0) { result->SetData(oacLessThanEqualRangeType); return 1;}
        if (strcasecmp(str,"oacGreaterThanRangeType")==0) { result->SetData(oacGreaterThanRangeType); return 1;}
        if (strcasecmp(str,"oacGreaterThanEqualRangeType")==0) { result->SetData(oacGreaterThanEqualRangeType); return 1;}
        if (strcasecmp(str,"oacClosedRangeType")==0) { result->SetData(oacClosedRangeType); return 1;}
        if (strcasecmp(str,"oacOpenRangeType")==0) { result->SetData(oacOpenRangeType); return 1;}
        if (strcasecmp(str,"oacOpenLeftRangeType")==0) { result->SetData(oacOpenLeftRangeType); return 1;}
        if (strcasecmp(str,"oacOpenRightRangeType")==0) { result->SetData(oacOpenRightRangeType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaRangeTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRangeTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaRangeTypeEnum_FromoaRangeTypeEnum(oaRangeTypeEnum ob)
{
    if (ob==oacLessThanRangeType) return PyString_FromString("oacLessThanRangeType");
    if (ob==oacLessThanEqualRangeType) return PyString_FromString("oacLessThanEqualRangeType");
    if (ob==oacGreaterThanRangeType) return PyString_FromString("oacGreaterThanRangeType");
    if (ob==oacGreaterThanEqualRangeType) return PyString_FromString("oacGreaterThanEqualRangeType");
    if (ob==oacClosedRangeType) return PyString_FromString("oacClosedRangeType");
    if (ob==oacOpenRangeType) return PyString_FromString("oacOpenRangeType");
    if (ob==oacOpenLeftRangeType) return PyString_FromString("oacOpenLeftRangeType");
    if (ob==oacOpenRightRangeType) return PyString_FromString("oacOpenRightRangeType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaRangeTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaRangeTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaRangeTypeEnum_FromoaRangeTypeEnum(oaRangeTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaRangeTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaRangeTypeEnum_doc[] =
"Type convert function for enum: oaRangeTypeEnum";
                               
static PyMethodDef PyoaRangeTypeEnum_method =
  {"oaRangeTypeEnum",(PyCFunction)PyoaRangeTypeEnum_TypeFunction,METH_VARARGS,oaRangeTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaRangeTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacLessThanRangeType");
    PyDict_SetItemString(mod_dict,"oacLessThanRangeType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLessThanEqualRangeType");
    PyDict_SetItemString(mod_dict,"oacLessThanEqualRangeType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacGreaterThanRangeType");
    PyDict_SetItemString(mod_dict,"oacGreaterThanRangeType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacGreaterThanEqualRangeType");
    PyDict_SetItemString(mod_dict,"oacGreaterThanEqualRangeType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacClosedRangeType");
    PyDict_SetItemString(mod_dict,"oacClosedRangeType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacOpenRangeType");
    PyDict_SetItemString(mod_dict,"oacOpenRangeType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacOpenLeftRangeType");
    PyDict_SetItemString(mod_dict,"oacOpenLeftRangeType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacOpenRightRangeType");
    PyDict_SetItemString(mod_dict,"oacOpenRightRangeType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaRangeTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaRangeTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaRangeTypeEnum\n");
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
// Wrapper Implementation for Class: oaRange_oaInt4
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRange_oaInt4_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRange_oaInt4_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRange_oaInt4Object* self = (PyoaRange_oaInt4Object*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaRangeBase*)  new oaRange_oaInt4();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaRangeType,oaInt4)
    {
        PyParamoaRangeType p1;
        PyParamoaInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaRangeType_Convert,&p1,
              &PyoaInt4_Convert,&p2)) {
            self->value = (oaRangeBase*)  new oaRange_oaInt4(p1.Data(),p2.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaRangeType,oaInt4,oaInt4)
    {
        PyParamoaRangeType p1;
        PyParamoaInt4 p2;
        PyParamoaInt4 p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaRangeType_Convert,&p1,
              &PyoaInt4_Convert,&p2,
              &PyoaInt4_Convert,&p3)) {
            self->value = (oaRangeBase*)  new oaRange_oaInt4(p1.Data(),p2.Data(),p3.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaRange_oaInt4)
    {
        PyParamoaRange_oaInt4 p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaRange_oaInt4_Convert,&p1)) {
            self->value=(oaRangeBase*)  new oaRange_oaInt4(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaRange_oaInt4, Choices are:\n"
        "    ()\n"
        "    (oaRangeType,oaInt4)\n"
        "    (oaRangeType,oaInt4,oaInt4)\n"
        "    (oaRange_oaInt4)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRange_oaInt4_tp_dealloc(PyoaRange_oaInt4Object* self)
{
    if (!self->borrow) {
        delete (oaRange_oaInt4*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRange_oaInt4_tp_repr(PyObject *ob)
{
    PyParamoaRange_oaInt4 value;
    int convert_status=PyoaRange_oaInt4_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaRange_oaInt4::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRange_oaInt4_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRange_oaInt4 v1;
    PyParamoaRange_oaInt4 v2;
    int convert_status1=PyoaRange_oaInt4_Convert(ob1,&v1);
    int convert_status2=PyoaRange_oaInt4_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRange_oaInt4_Convert(PyObject* ob,PyParamoaRange_oaInt4* result)
{
    if (ob == NULL) return 1;
    if (PyoaRange_oaInt4_Check(ob)) {
        result->SetData( (oaRange_oaInt4*) ((PyoaRange_oaInt4Object*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRange_oaInt4 Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRange_oaInt4_FromoaRange_oaInt4(oaRange_oaInt4* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaRange_oaInt4_Type.tp_alloc(&PyoaRange_oaInt4_Type,0);
        if (bself == NULL) return bself;
        PyoaRange_oaInt4Object* self = (PyoaRange_oaInt4Object*)bself;
        self->value = (oaRangeBase*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRange_oaInt4_getLowerBound_doc[] = 
"Class: oaRange_oaInt4, Function: getLowerBound\n"
"  Paramegers: ()\n"
"    Calls: oaInt4 getLowerBound() const\n"
"    Signature: getLowerBound|simple-oaInt4|\n"
"    BrowseData: 1\n"
"    This function returns the lower bound of this range object. If the bound is not applicable for the range object, an oacInvalidBoundForRange exception is thrown.\n"
"    oacInvalidBoundForRange\n"
;

static PyObject*
oaRange_oaInt4_getLowerBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRange_oaInt4 data;
    int convert_status=PyoaRange_oaInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRange_oaInt4Object* self=(PyoaRange_oaInt4Object*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaInt4 result= (data.DataCall()->getLowerBound());
        return PyoaInt4_FromoaInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRange_oaInt4_getUpperBound_doc[] = 
"Class: oaRange_oaInt4, Function: getUpperBound\n"
"  Paramegers: ()\n"
"    Calls: oaInt4 getUpperBound() const\n"
"    Signature: getUpperBound|simple-oaInt4|\n"
"    BrowseData: 1\n"
"    This function returns the upper bound of this range object. If the bound is not applicable for the range object, an oacInvalidBoundForRange exception is thrown.\n"
"    oacInvalidBoundForRange\n"
;

static PyObject*
oaRange_oaInt4_getUpperBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRange_oaInt4 data;
    int convert_status=PyoaRange_oaInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRange_oaInt4Object* self=(PyoaRange_oaInt4Object*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaInt4 result= (data.DataCall()->getUpperBound());
        return PyoaInt4_FromoaInt4(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRange_oaInt4_setBounds_doc[] = 
"Class: oaRange_oaInt4, Function: setBounds\n"
"  Paramegers: (oaInt4,oaInt4)\n"
"    Calls: void setBounds(oaInt4 lowerBoundIn,oaInt4 upperBoundIn)\n"
"    Signature: setBounds|void-void|simple-oaInt4,simple-oaInt4,\n"
"    This function sets the lower and upper bounds of this oaRange object.\n"
"    lowerBoundIn\n"
"    The lower bound to set on this oaRange object.\n"
"    upperBoundIn\n"
"    The upper bound to set on this oaRange object.\n"
"    oacInvalidBoundForRange\n"
"    Todo\n"
"    Check description of member function. Specify which types may have lower and/or upper bounds set or how user can determine (by other calls). Check description of parameter.\n"
;

static PyObject*
oaRange_oaInt4_setBounds(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRange_oaInt4 data;
    int convert_status=PyoaRange_oaInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRange_oaInt4Object* self=(PyoaRange_oaInt4Object*)ob;

    PyParamoaInt4 p1;
    PyParamoaInt4 p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaInt4_Convert,&p1,
          &PyoaInt4_Convert,&p2)) {
        data.DataCall()->setBounds(p1.Data(),p2.Data());
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
static char oaRange_oaInt4_setLowerBound_doc[] = 
"Class: oaRange_oaInt4, Function: setLowerBound\n"
"  Paramegers: (oaInt4)\n"
"    Calls: void setLowerBound(oaInt4 lowerBoundIn)\n"
"    Signature: setLowerBound|void-void|simple-oaInt4,\n"
"    This function sets the lower bound of this oaRange object.\n"
"    lowerBoundIn\n"
"    The lower bound to set on this oaRange object.\n"
"    oacInvalidBoundForRange\n"
"    Todo\n"
"    Check description of member function. Specify which types may have lower and/or upper bounds set or how user can determine (by other calls). Check description of parameter.\n"
;

static PyObject*
oaRange_oaInt4_setLowerBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRange_oaInt4 data;
    int convert_status=PyoaRange_oaInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRange_oaInt4Object* self=(PyoaRange_oaInt4Object*)ob;

    PyParamoaInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaInt4_Convert,&p1)) {
        data.DataCall()->setLowerBound(p1.Data());
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
static char oaRange_oaInt4_setUpperBound_doc[] = 
"Class: oaRange_oaInt4, Function: setUpperBound\n"
"  Paramegers: (oaInt4)\n"
"    Calls: void setUpperBound(oaInt4 upperBoundIn)\n"
"    Signature: setUpperBound|void-void|simple-oaInt4,\n"
"    This function sets the upper bound of this oaRange object.\n"
"    upperBoundIn\n"
"    The upper bound to set on this oaRange object\n"
"    oacInvalidBoundForRange\n"
"    Todo\n"
"    Check description of member function. Specify which types may have lower and/or upper bounds set or how user can determine (by other calls). Check description of parameter.\n"
;

static PyObject*
oaRange_oaInt4_setUpperBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRange_oaInt4 data;
    int convert_status=PyoaRange_oaInt4_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRange_oaInt4Object* self=(PyoaRange_oaInt4Object*)ob;

    PyParamoaInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaInt4_Convert,&p1)) {
        data.DataCall()->setUpperBound(p1.Data());
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

static char oaRange_oaInt4_assign_doc[] = 
"Class: oaRange_oaInt4, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRange_oaInt4_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRange_oaInt4 data;
  int convert_status=PyoaRange_oaInt4_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRange_oaInt4 p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRange_oaInt4_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRange_oaInt4_methodlist[] = {
    {"getLowerBound",(PyCFunction)oaRange_oaInt4_getLowerBound,METH_VARARGS,oaRange_oaInt4_getLowerBound_doc},
    {"getUpperBound",(PyCFunction)oaRange_oaInt4_getUpperBound,METH_VARARGS,oaRange_oaInt4_getUpperBound_doc},
    {"setBounds",(PyCFunction)oaRange_oaInt4_setBounds,METH_VARARGS,oaRange_oaInt4_setBounds_doc},
    {"setLowerBound",(PyCFunction)oaRange_oaInt4_setLowerBound,METH_VARARGS,oaRange_oaInt4_setLowerBound_doc},
    {"setUpperBound",(PyCFunction)oaRange_oaInt4_setUpperBound,METH_VARARGS,oaRange_oaInt4_setUpperBound_doc},
    {"assign",(PyCFunction)oaRange_oaInt4_tp_assign,METH_VARARGS,oaRange_oaInt4_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRange_oaInt4_doc[] = 
"Class: oaRange_oaInt4\n"
"  Instantiations of this template class are used to define numerical ranges for different types.\n"
"  Todo\n"
"  Check description\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaRange_oaInt4()\n"
"    Signature: oaRange_oaInt4||\n"
"    This is the default constructor for the oaRange class.\n"
"  Paramegers: (oaRangeType,oaInt4)\n"
"    Calls: oaRange_oaInt4(oaRangeType type,oaInt4 value)\n"
"    Signature: oaRange_oaInt4||simple-oaRangeType,simple-oaInt4,\n"
"    This oaRange constructor creates a range object that has either lower bound or upper bound.\n"
"    type\n"
"    The oaRangeType of range object to construct.\n"
"    value\n"
"    The upper bound or lower bound based on the type.\n"
"    Todo\n"
"    Check description of member function and parameter. Add description of value parameter.\n"
"  Paramegers: (oaRangeType,oaInt4,oaInt4)\n"
"    Calls: oaRange_oaInt4(oaRangeType type,oaInt4 lowerBoundIn,oaInt4 upperBoundIn)\n"
"    Signature: oaRange_oaInt4||simple-oaRangeType,simple-oaInt4,simple-oaInt4,\n"
"    This oaRange constructor creates a range object that has both lower and upper bounds.\n"
"    type\n"
"    The oaRangeType of range object to construct.\n"
"    lowerBoundIn\n"
"    The lower bound to set on this range object.\n"
"    upperBoundIn\n"
"    The upper bound to set on this range object.\n"
"    Todo\n"
"    Check description of member function and parameters.\n"
"  Paramegers: (oaRange_oaInt4)\n"
"    Calls: (const oaRange_oaInt4&)\n"
"    Signature: oaRange_oaInt4||cref-oaRange_oaInt4,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRange_oaInt4_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRange_oaInt4",
    sizeof(PyoaRange_oaInt4Object),
    0,
    (destructor)oaRange_oaInt4_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRange_oaInt4_tp_compare,	/* tp_compare */
    (reprfunc)oaRange_oaInt4_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRange_oaInt4_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRange_oaInt4_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaRangeBase_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRange_oaInt4_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRange_oaInt4_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRange_oaInt4_Type)<0) {
      printf("** PyType_Ready failed for: oaRange_oaInt4\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRange_oaInt4",
           (PyObject*)(&PyoaRange_oaInt4_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRange_oaInt4\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaRange_oaUInt8
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRange_oaUInt8_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRange_oaUInt8_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRange_oaUInt8Object* self = (PyoaRange_oaUInt8Object*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaRangeBase*)  new oaRange_oaUInt8();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaRangeType,oaUInt8)
    {
        PyParamoaRangeType p1;
        PyParamoaUInt8 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaRangeType_Convert,&p1,
              &PyoaUInt8_Convert,&p2)) {
            self->value = (oaRangeBase*)  new oaRange_oaUInt8(p1.Data(),p2.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaRangeType,oaUInt8,oaUInt8)
    {
        PyParamoaRangeType p1;
        PyParamoaUInt8 p2;
        PyParamoaUInt8 p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaRangeType_Convert,&p1,
              &PyoaUInt8_Convert,&p2,
              &PyoaUInt8_Convert,&p3)) {
            self->value = (oaRangeBase*)  new oaRange_oaUInt8(p1.Data(),p2.Data(),p3.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaRange_oaUInt8)
    {
        PyParamoaRange_oaUInt8 p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaRange_oaUInt8_Convert,&p1)) {
            self->value=(oaRangeBase*)  new oaRange_oaUInt8(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaRange_oaUInt8, Choices are:\n"
        "    ()\n"
        "    (oaRangeType,oaUInt8)\n"
        "    (oaRangeType,oaUInt8,oaUInt8)\n"
        "    (oaRange_oaUInt8)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRange_oaUInt8_tp_dealloc(PyoaRange_oaUInt8Object* self)
{
    if (!self->borrow) {
        delete (oaRange_oaUInt8*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRange_oaUInt8_tp_repr(PyObject *ob)
{
    PyParamoaRange_oaUInt8 value;
    int convert_status=PyoaRange_oaUInt8_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaRange_oaUInt8::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRange_oaUInt8_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRange_oaUInt8 v1;
    PyParamoaRange_oaUInt8 v2;
    int convert_status1=PyoaRange_oaUInt8_Convert(ob1,&v1);
    int convert_status2=PyoaRange_oaUInt8_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRange_oaUInt8_Convert(PyObject* ob,PyParamoaRange_oaUInt8* result)
{
    if (ob == NULL) return 1;
    if (PyoaRange_oaUInt8_Check(ob)) {
        result->SetData( (oaRange_oaUInt8*) ((PyoaRange_oaUInt8Object*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRange_oaUInt8 Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRange_oaUInt8_FromoaRange_oaUInt8(oaRange_oaUInt8* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaRange_oaUInt8_Type.tp_alloc(&PyoaRange_oaUInt8_Type,0);
        if (bself == NULL) return bself;
        PyoaRange_oaUInt8Object* self = (PyoaRange_oaUInt8Object*)bself;
        self->value = (oaRangeBase*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRange_oaUInt8_getLowerBound_doc[] = 
"Class: oaRange_oaUInt8, Function: getLowerBound\n"
"  Paramegers: ()\n"
"    Calls: oaUInt8 getLowerBound() const\n"
"    Signature: getLowerBound|simple-oaUInt8|\n"
"    BrowseData: 1\n"
"    This function returns the lower bound of this range object. If the bound is not applicable for the range object, an oacInvalidBoundForRange exception is thrown.\n"
"    oacInvalidBoundForRange\n"
;

static PyObject*
oaRange_oaUInt8_getLowerBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRange_oaUInt8 data;
    int convert_status=PyoaRange_oaUInt8_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRange_oaUInt8Object* self=(PyoaRange_oaUInt8Object*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt8 result= (data.DataCall()->getLowerBound());
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
static char oaRange_oaUInt8_getUpperBound_doc[] = 
"Class: oaRange_oaUInt8, Function: getUpperBound\n"
"  Paramegers: ()\n"
"    Calls: oaUInt8 getUpperBound() const\n"
"    Signature: getUpperBound|simple-oaUInt8|\n"
"    BrowseData: 1\n"
"    This function returns the upper bound of this range object. If the bound is not applicable for the range object, an oacInvalidBoundForRange exception is thrown.\n"
"    oacInvalidBoundForRange\n"
;

static PyObject*
oaRange_oaUInt8_getUpperBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRange_oaUInt8 data;
    int convert_status=PyoaRange_oaUInt8_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRange_oaUInt8Object* self=(PyoaRange_oaUInt8Object*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt8 result= (data.DataCall()->getUpperBound());
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
static char oaRange_oaUInt8_setBounds_doc[] = 
"Class: oaRange_oaUInt8, Function: setBounds\n"
"  Paramegers: (oaUInt8,oaUInt8)\n"
"    Calls: void setBounds(oaUInt8 lowerBoundIn,oaUInt8 upperBoundIn)\n"
"    Signature: setBounds|void-void|simple-oaUInt8,simple-oaUInt8,\n"
"    This function sets the lower and upper bounds of this oaRange object.\n"
"    lowerBoundIn\n"
"    The lower bound to set on this oaRange object.\n"
"    upperBoundIn\n"
"    The upper bound to set on this oaRange object.\n"
"    oacInvalidBoundForRange\n"
"    Todo\n"
"    Check description of member function. Specify which types may have lower and/or upper bounds set or how user can determine (by other calls). Check description of parameter.\n"
;

static PyObject*
oaRange_oaUInt8_setBounds(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRange_oaUInt8 data;
    int convert_status=PyoaRange_oaUInt8_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRange_oaUInt8Object* self=(PyoaRange_oaUInt8Object*)ob;

    PyParamoaUInt8 p1;
    PyParamoaUInt8 p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaUInt8_Convert,&p1,
          &PyoaUInt8_Convert,&p2)) {
        data.DataCall()->setBounds(p1.Data(),p2.Data());
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
static char oaRange_oaUInt8_setLowerBound_doc[] = 
"Class: oaRange_oaUInt8, Function: setLowerBound\n"
"  Paramegers: (oaUInt8)\n"
"    Calls: void setLowerBound(oaUInt8 lowerBoundIn)\n"
"    Signature: setLowerBound|void-void|simple-oaUInt8,\n"
"    This function sets the lower bound of this oaRange object.\n"
"    lowerBoundIn\n"
"    The lower bound to set on this oaRange object.\n"
"    oacInvalidBoundForRange\n"
"    Todo\n"
"    Check description of member function. Specify which types may have lower and/or upper bounds set or how user can determine (by other calls). Check description of parameter.\n"
;

static PyObject*
oaRange_oaUInt8_setLowerBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRange_oaUInt8 data;
    int convert_status=PyoaRange_oaUInt8_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRange_oaUInt8Object* self=(PyoaRange_oaUInt8Object*)ob;

    PyParamoaUInt8 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt8_Convert,&p1)) {
        data.DataCall()->setLowerBound(p1.Data());
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
static char oaRange_oaUInt8_setUpperBound_doc[] = 
"Class: oaRange_oaUInt8, Function: setUpperBound\n"
"  Paramegers: (oaUInt8)\n"
"    Calls: void setUpperBound(oaUInt8 upperBoundIn)\n"
"    Signature: setUpperBound|void-void|simple-oaUInt8,\n"
"    This function sets the upper bound of this oaRange object.\n"
"    upperBoundIn\n"
"    The upper bound to set on this oaRange object\n"
"    oacInvalidBoundForRange\n"
"    Todo\n"
"    Check description of member function. Specify which types may have lower and/or upper bounds set or how user can determine (by other calls). Check description of parameter.\n"
;

static PyObject*
oaRange_oaUInt8_setUpperBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRange_oaUInt8 data;
    int convert_status=PyoaRange_oaUInt8_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRange_oaUInt8Object* self=(PyoaRange_oaUInt8Object*)ob;

    PyParamoaUInt8 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt8_Convert,&p1)) {
        data.DataCall()->setUpperBound(p1.Data());
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

static char oaRange_oaUInt8_assign_doc[] = 
"Class: oaRange_oaUInt8, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRange_oaUInt8_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRange_oaUInt8 data;
  int convert_status=PyoaRange_oaUInt8_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRange_oaUInt8 p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRange_oaUInt8_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRange_oaUInt8_methodlist[] = {
    {"getLowerBound",(PyCFunction)oaRange_oaUInt8_getLowerBound,METH_VARARGS,oaRange_oaUInt8_getLowerBound_doc},
    {"getUpperBound",(PyCFunction)oaRange_oaUInt8_getUpperBound,METH_VARARGS,oaRange_oaUInt8_getUpperBound_doc},
    {"setBounds",(PyCFunction)oaRange_oaUInt8_setBounds,METH_VARARGS,oaRange_oaUInt8_setBounds_doc},
    {"setLowerBound",(PyCFunction)oaRange_oaUInt8_setLowerBound,METH_VARARGS,oaRange_oaUInt8_setLowerBound_doc},
    {"setUpperBound",(PyCFunction)oaRange_oaUInt8_setUpperBound,METH_VARARGS,oaRange_oaUInt8_setUpperBound_doc},
    {"assign",(PyCFunction)oaRange_oaUInt8_tp_assign,METH_VARARGS,oaRange_oaUInt8_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRange_oaUInt8_doc[] = 
"Class: oaRange_oaUInt8\n"
"  Instantiations of this template class are used to define numerical ranges for different types.\n"
"  Todo\n"
"  Check description\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaRange_oaUInt8()\n"
"    Signature: oaRange_oaUInt8||\n"
"    This is the default constructor for the oaRange class.\n"
"  Paramegers: (oaRangeType,oaUInt8)\n"
"    Calls: oaRange_oaUInt8(oaRangeType type,oaUInt8 value)\n"
"    Signature: oaRange_oaUInt8||simple-oaRangeType,simple-oaUInt8,\n"
"    This oaRange constructor creates a range object that has either lower bound or upper bound.\n"
"    type\n"
"    The oaRangeType of range object to construct.\n"
"    value\n"
"    The upper bound or lower bound based on the type.\n"
"    Todo\n"
"    Check description of member function and parameter. Add description of value parameter.\n"
"  Paramegers: (oaRangeType,oaUInt8,oaUInt8)\n"
"    Calls: oaRange_oaUInt8(oaRangeType type,oaUInt8 lowerBoundIn,oaUInt8 upperBoundIn)\n"
"    Signature: oaRange_oaUInt8||simple-oaRangeType,simple-oaUInt8,simple-oaUInt8,\n"
"    This oaRange constructor creates a range object that has both lower and upper bounds.\n"
"    type\n"
"    The oaRangeType of range object to construct.\n"
"    lowerBoundIn\n"
"    The lower bound to set on this range object.\n"
"    upperBoundIn\n"
"    The upper bound to set on this range object.\n"
"    Todo\n"
"    Check description of member function and parameters.\n"
"  Paramegers: (oaRange_oaUInt8)\n"
"    Calls: (const oaRange_oaUInt8&)\n"
"    Signature: oaRange_oaUInt8||cref-oaRange_oaUInt8,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRange_oaUInt8_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRange_oaUInt8",
    sizeof(PyoaRange_oaUInt8Object),
    0,
    (destructor)oaRange_oaUInt8_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRange_oaUInt8_tp_compare,	/* tp_compare */
    (reprfunc)oaRange_oaUInt8_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRange_oaUInt8_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRange_oaUInt8_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaRangeBase_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRange_oaUInt8_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRange_oaUInt8_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRange_oaUInt8_Type)<0) {
      printf("** PyType_Ready failed for: oaRange_oaUInt8\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRange_oaUInt8",
           (PyObject*)(&PyoaRange_oaUInt8_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRange_oaUInt8\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaRect
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRect_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRect_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRectObject* self = (PyoaRectObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaRect)
    {
        PyParamoaRect p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaRect_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaRect, Choices are:\n"
        "    (oaRect)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRect_tp_dealloc(PyoaRectObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRect_tp_repr(PyObject *ob)
{
    PyParamoaRect value;
    int convert_status=PyoaRect_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[28];
    sprintf(buffer,"<oaRect::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRect_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRect v1;
    PyParamoaRect v2;
    int convert_status1=PyoaRect_Convert(ob1,&v1);
    int convert_status2=PyoaRect_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRect_Convert(PyObject* ob,PyParamoaRect* result)
{
    if (ob == NULL) return 1;
    if (PyoaRect_Check(ob)) {
        result->SetData( (oaRect**) ((PyoaRectObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRect Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRect_FromoaRect(oaRect** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaRect* data=*value;
        PyObject* bself = PyoaRect_Type.tp_alloc(&PyoaRect_Type,0);
        if (bself == NULL) return bself;
        PyoaRectObject* self = (PyoaRectObject*)bself;
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
PyObject* PyoaRect_FromoaRect(oaRect* data)
{
    if (data) {
       PyObject* bself = PyoaRect_Type.tp_alloc(&PyoaRect_Type,0);
       if (bself == NULL) return bself;
       PyoaRectObject* self = (PyoaRectObject*)bself;
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
static char oaRect_convertToPolygon_doc[] = 
"Class: oaRect, Function: convertToPolygon\n"
"  Paramegers: ()\n"
"    Calls: oaPolygon* convertToPolygon()\n"
"    Signature: convertToPolygon|ptr-oaPolygon|\n"
"    BrowseData: 1\n"
"    This function converts this rectangle into a polygon. The new polygon is returned as the same pointer as this rectangle.\n"
;

static PyObject*
oaRect_convertToPolygon(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRect data;
    int convert_status=PyoaRect_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRectObject* self=(PyoaRectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaPolygonp result= (data.DataCall()->convertToPolygon());
        return PyoaPolygon_FromoaPolygon(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRect_setBBox_doc[] = 
"Class: oaRect, Function: setBBox\n"
"  Paramegers: (oaBox)\n"
"    Calls: void setBBox(const oaBox& bBox)\n"
"    Signature: setBBox|void-void|cref-oaBox,\n"
"    This function sets the bounding box of this rectangle to the specified value. The new bBox is checked to verify it does not have zero area and is not inverted.\n"
"    bBox\n"
"    The oaBox that is set to this oaRect object\n"
"    oacRectBBoxInvalid\n"
;

static PyObject*
oaRect_setBBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRect data;
    int convert_status=PyoaRect_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRectObject* self=(PyoaRectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

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
static char oaRect_isNull_doc[] =
"Class: oaRect, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaRect_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaRect data;
    int convert_status=PyoaRect_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaRect_assign_doc[] = 
"Class: oaRect, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRect_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRect data;
  int convert_status=PyoaRect_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRect p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRect_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRect_methodlist[] = {
    {"convertToPolygon",(PyCFunction)oaRect_convertToPolygon,METH_VARARGS,oaRect_convertToPolygon_doc},
    {"setBBox",(PyCFunction)oaRect_setBBox,METH_VARARGS,oaRect_setBBox_doc},
    {"isNull",(PyCFunction)oaRect_tp_isNull,METH_VARARGS,oaRect_isNull_doc},
    {"assign",(PyCFunction)oaRect_tp_assign,METH_VARARGS,oaRect_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRect_doc[] = 
"Class: oaRect\n"
"  The oaRect class implements a rectangle shape.\n"
"Constructors:\n"
"  Paramegers: (oaRect)\n"
"    Calls: (const oaRect&)\n"
"    Signature: oaRect||cref-oaRect,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRect_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRect",
    sizeof(PyoaRectObject),
    0,
    (destructor)oaRect_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRect_tp_compare,	/* tp_compare */
    (reprfunc)oaRect_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRect_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRect_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaShape_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRect_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRect_static_create_doc[] = 
"Class: oaRect, Function: create\n"
"  Paramegers: (oaBlock,oaLayerNum,oaPurposeNum,oaBox)\n"
"    Calls: oaRect* create(oaBlock* block,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaBox& bBox)\n"
"    Signature: create|ptr-oaRect|ptr-oaBlock,simple-oaLayerNum,simple-oaPurposeNum,cref-oaBox,\n"
"    This function creates a rectangle with the specified attributes. The specified bBox is checked to verify it does not have zero area and it is not inverted.\n"
"    block\n"
"    The block in which to create the rectangle\n"
"    layerNum\n"
"    The number of the layer on which to create the rectangle\n"
"    purposeNum\n"
"    The number of the layer purpose to use to create the rectangle\n"
"    bBox\n"
"    The bounding box that sets this rectangle\n"
"    oacRectBBoxInvalid\n"
;

static PyObject*
oaRect_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBlock p1;
    PyParamoaLayerNum p2;
    PyParamoaPurposeNum p3;
    PyParamoaBox p4;
    if (PyArg_ParseTuple(args,"O&O&O&O&",
          &PyoaBlock_Convert,&p1,
          &PyoaLayerNum_Convert,&p2,
          &PyoaPurposeNum_Convert,&p3,
          &PyoaBox_Convert,&p4)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaRectp result= (oaRect::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
        return PyoaRect_FromoaRect(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaRect_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaRect_static_create,METH_VARARGS,oaRect_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRect_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRect_Type)<0) {
      printf("** PyType_Ready failed for: oaRect\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRect",
           (PyObject*)(&PyoaRect_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRect\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaRect_Type.tp_dict;
    for(method=oaRect_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaReducedModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaReducedModTypeEnum_Convert(PyObject* ob,PyParamoaReducedModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetValueReducedModType")==0) { result->SetData(oacSetValueReducedModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaReducedModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaReducedModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaReducedModTypeEnum_FromoaReducedModTypeEnum(oaReducedModTypeEnum ob)
{
    if (ob==oacSetValueReducedModType) return PyString_FromString("oacSetValueReducedModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaReducedModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaReducedModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaReducedModTypeEnum_FromoaReducedModTypeEnum(oaReducedModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaReducedModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaReducedModTypeEnum_doc[] =
"Type convert function for enum: oaReducedModTypeEnum";
                               
static PyMethodDef PyoaReducedModTypeEnum_method =
  {"oaReducedModTypeEnum",(PyCFunction)PyoaReducedModTypeEnum_TypeFunction,METH_VARARGS,oaReducedModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaReducedModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetValueReducedModType");
    PyDict_SetItemString(mod_dict,"oacSetValueReducedModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaReducedModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaReducedModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaReducedModTypeEnum\n");
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
// Wrapper Implementation for Class: oaReducedModel
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaReducedModel_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaReducedModel_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaReducedModelObject* self = (PyoaReducedModelObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaReducedModel)
    {
        PyParamoaReducedModel p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaReducedModel_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaReducedModel, Choices are:\n"
        "    (oaReducedModel)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaReducedModel_tp_dealloc(PyoaReducedModelObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaReducedModel_tp_repr(PyObject *ob)
{
    PyParamoaReducedModel value;
    int convert_status=PyoaReducedModel_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaReducedModel::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaReducedModel_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaReducedModel v1;
    PyParamoaReducedModel v2;
    int convert_status1=PyoaReducedModel_Convert(ob1,&v1);
    int convert_status2=PyoaReducedModel_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaReducedModel_Convert(PyObject* ob,PyParamoaReducedModel* result)
{
    if (ob == NULL) return 1;
    if (PyoaReducedModel_Check(ob)) {
        result->SetData( (oaReducedModel**) ((PyoaReducedModelObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaReducedModel Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaReducedModel_FromoaReducedModel(oaReducedModel** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaReducedModel* data=*value;
        if (data->getType()==oacPiElmoreType) return PyoaPiElmore_FromoaPiElmore((oaPiElmore**)value,borrow,lock);
        if (data->getType()==oacPiPoleResidueType) return PyoaPiPoleResidue_FromoaPiPoleResidue((oaPiPoleResidue**)value,borrow,lock);
        if (data->getType()==oacLumpedElmoreType) return PyoaLumpedElmore_FromoaLumpedElmore((oaLumpedElmore**)value,borrow,lock);
        PyObject* bself = PyoaReducedModel_Type.tp_alloc(&PyoaReducedModel_Type,0);
        if (bself == NULL) return bself;
        PyoaReducedModelObject* self = (PyoaReducedModelObject*)bself;
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
PyObject* PyoaReducedModel_FromoaReducedModel(oaReducedModel* data)
{
    if (data) {
        if (data->getType()==oacPiElmoreType) return PyoaPiElmore_FromoaPiElmore((oaPiElmore*)data);
        if (data->getType()==oacPiPoleResidueType) return PyoaPiPoleResidue_FromoaPiPoleResidue((oaPiPoleResidue*)data);
        if (data->getType()==oacLumpedElmoreType) return PyoaLumpedElmore_FromoaLumpedElmore((oaLumpedElmore*)data);
       PyObject* bself = PyoaReducedModel_Type.tp_alloc(&PyoaReducedModel_Type,0);
       if (bself == NULL) return bself;
       PyoaReducedModelObject* self = (PyoaReducedModelObject*)bself;
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
static char oaReducedModel_destroy_doc[] = 
"Class: oaReducedModel, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this reduced model object.\n"
;

static PyObject*
oaReducedModel_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReducedModel data;
    int convert_status=PyoaReducedModel_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReducedModelObject* self=(PyoaReducedModelObject*)ob;
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
static char oaReducedModel_getAnalysisPoint_doc[] = 
"Class: oaReducedModel, Function: getAnalysisPoint\n"
"  Paramegers: ()\n"
"    Calls: oaAnalysisPoint* getAnalysisPoint() const\n"
"    Signature: getAnalysisPoint|ptr-oaAnalysisPoint|\n"
"    BrowseData: 1\n"
"    This function returns the analysis point that this reduced model represents.\n"
;

static PyObject*
oaReducedModel_getAnalysisPoint(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReducedModel data;
    int convert_status=PyoaReducedModel_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReducedModelObject* self=(PyoaReducedModelObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaAnalysisPointp result= (data.DataCall()->getAnalysisPoint());
        return PyoaAnalysisPoint_FromoaAnalysisPoint(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaReducedModel_getDomain_doc[] = 
"Class: oaReducedModel, Function: getDomain\n"
"  Paramegers: ()\n"
"    Calls: oaDomain getDomain() const\n"
"    Signature: getDomain|simple-oaDomain|\n"
"    BrowseData: 1\n"
"    This function returns the domain for this reduced model, which is the same as the domain of the driver and receivers on this reduced model.\n"
;

static PyObject*
oaReducedModel_getDomain(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReducedModel data;
    int convert_status=PyoaReducedModel_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReducedModelObject* self=(PyoaReducedModelObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDomain* result= new oaDomain(data.DataCall()->getDomain());
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
static char oaReducedModel_getDriver_doc[] = 
"Class: oaReducedModel, Function: getDriver\n"
"  Paramegers: ()\n"
"    Calls: oaDesignObject* getDriver() const\n"
"    Signature: getDriver|ptr-oaDesignObject|\n"
"    BrowseData: 1\n"
"    This function returns the driver for this reduced model, which is a terminal or an instTerm. If the model is for an oaNet , then the driver will either be an oaTerm or an oaInstTerm . If the model is for an oaOccNet then the driver will either be an oaOccTerm or an oaOccInstTerm .\n"
;

static PyObject*
oaReducedModel_getDriver(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReducedModel data;
    int convert_status=PyoaReducedModel_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReducedModelObject* self=(PyoaReducedModelObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDesignObjectp result= (data.DataCall()->getDriver());
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
static char oaReducedModel_isNull_doc[] =
"Class: oaReducedModel, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaReducedModel_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaReducedModel data;
    int convert_status=PyoaReducedModel_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaReducedModel_assign_doc[] = 
"Class: oaReducedModel, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaReducedModel_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaReducedModel data;
  int convert_status=PyoaReducedModel_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaReducedModel p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaReducedModel_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaReducedModel_methodlist[] = {
    {"destroy",(PyCFunction)oaReducedModel_destroy,METH_VARARGS,oaReducedModel_destroy_doc},
    {"getAnalysisPoint",(PyCFunction)oaReducedModel_getAnalysisPoint,METH_VARARGS,oaReducedModel_getAnalysisPoint_doc},
    {"getDomain",(PyCFunction)oaReducedModel_getDomain,METH_VARARGS,oaReducedModel_getDomain_doc},
    {"getDriver",(PyCFunction)oaReducedModel_getDriver,METH_VARARGS,oaReducedModel_getDriver_doc},
    {"isNull",(PyCFunction)oaReducedModel_tp_isNull,METH_VARARGS,oaReducedModel_isNull_doc},
    {"assign",(PyCFunction)oaReducedModel_tp_assign,METH_VARARGS,oaReducedModel_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaReducedModel_doc[] = 
"Class: oaReducedModel\n"
"  The oaReducedModel class is an abstract base for all reduced model objects that model the parasitics seen by a driver of a net.\n"
"  ReducedModels are used as simplified representations of the electrical behavior of a net in order to be smaller and faster for delay calculation than a full detailed parasitic model. Reduced models are associated with a Terminal or InstTerm on a net to represent the behavior of the Net when that Terminal or InstTerm is driving it.\n"
"  ReducedModels may be created in the block and the occurrence domains. Those created in a hierarchical fashion with be stored on oaTerms and oaInstTerms. Those created for an expanded hierarchy will be stored on oaOccTerms and oaOccInstTerms.\n"
"  See oaParasiticNetwork for the representation of detailed parasitic networks.\n"
"  Note: Any change to the connectivity of the net that the oaReducedModel is on will cause the oaReducedModel to be destroyed. This includes creating, destroying, or moving Terminals or InstTerms.\n"
"  The oaReducedModel class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaReducedModel)\n"
"    Calls: (const oaReducedModel&)\n"
"    Signature: oaReducedModel||cref-oaReducedModel,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaReducedModel_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaReducedModel",
    sizeof(PyoaReducedModelObject),
    0,
    (destructor)oaReducedModel_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaReducedModel_tp_compare,	/* tp_compare */
    (reprfunc)oaReducedModel_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaReducedModel_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaReducedModel_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDesignObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaReducedModel_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaReducedModel_static_destroy_doc[] = 
"Class: oaReducedModel, Function: destroy\n"
"  Paramegers: (oaAnalysisPoint)\n"
"    Calls: void destroy(oaAnalysisPoint* ap)\n"
"    Signature: destroy|void-void|ptr-oaAnalysisPoint,\n"
"    This function destroys all reduced models that represent parasitics for the specified analysis point.\n"
"  Paramegers: (oaDesign)\n"
"    Calls: void destroy(oaDesign* design)\n"
"    Signature: destroy|void-void|ptr-oaDesign,\n"
"    This function destroys all reduced models in the specified design.\n"
;

static PyObject*
oaReducedModel_static_destroy(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaAnalysisPoint)
    {
        PyParamoaAnalysisPoint p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaAnalysisPoint_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaReducedModel::destroy(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign)
    {
        PyParamoaDesign p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaDesign_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaReducedModel::destroy(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaReducedModel, function: destroy, Choices are:\n"
        "    (oaAnalysisPoint)\n"
        "    (oaDesign)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaReducedModel_staticmethodlist[] = {
    {"static_destroy",(PyCFunction)oaReducedModel_static_destroy,METH_VARARGS,oaReducedModel_static_destroy_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaReducedModel_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaReducedModel_Type)<0) {
      printf("** PyType_Ready failed for: oaReducedModel\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaReducedModel",
           (PyObject*)(&PyoaReducedModel_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaReducedModel\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaReducedModel_Type.tp_dict;
    for(method=oaReducedModel_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaRef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRefObject* self = (PyoaRefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaRef)
    {
        PyParamoaRef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaRef_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaRef, Choices are:\n"
        "    (oaRef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRef_tp_dealloc(PyoaRefObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRef_tp_repr(PyObject *ob)
{
    PyParamoaRef value;
    int convert_status=PyoaRef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[27];
    sprintf(buffer,"<oaRef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRef v1;
    PyParamoaRef v2;
    int convert_status1=PyoaRef_Convert(ob1,&v1);
    int convert_status2=PyoaRef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRef_Convert(PyObject* ob,PyParamoaRef* result)
{
    if (ob == NULL) return 1;
    if (PyoaRef_Check(ob)) {
        result->SetData( (oaRef**) ((PyoaRefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRef_FromoaRef(oaRef** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaRef* data=*value;
        if (data->isVia()) return PyoaVia_FromoaVia((oaVia**)value,borrow,lock);
        if (data->isInst()) return PyoaInst_FromoaInst((oaInst**)value,borrow,lock);
        PyObject* bself = PyoaRef_Type.tp_alloc(&PyoaRef_Type,0);
        if (bself == NULL) return bself;
        PyoaRefObject* self = (PyoaRefObject*)bself;
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
PyObject* PyoaRef_FromoaRef(oaRef* data)
{
    if (data) {
        if (data->isVia()) return PyoaVia_FromoaVia((oaVia*)data);
        if (data->isInst()) return PyoaInst_FromoaInst((oaInst*)data);
       PyObject* bself = PyoaRef_Type.tp_alloc(&PyoaRef_Type,0);
       if (bself == NULL) return bself;
       PyoaRefObject* self = (PyoaRefObject*)bself;
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
static char oaRef_getHeader_doc[] = 
"Class: oaRef, Function: getHeader\n"
"  Paramegers: ()\n"
"    Calls: oaRefHeader* getHeader() const\n"
"    Signature: getHeader|ptr-oaRefHeader|\n"
"    BrowseData: 1\n"
"    This function returns the header for this reference.\n"
;

static PyObject*
oaRef_getHeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRef data;
    int convert_status=PyoaRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRefObject* self=(PyoaRefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaRefHeaderp result= (data.DataCall()->getHeader());
        return PyoaRefHeader_FromoaRefHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRef_getMaster_doc[] = 
"Class: oaRef, Function: getMaster\n"
"  Paramegers: ()\n"
"    Calls: oaDesign* getMaster() const\n"
"    Signature: getMaster|ptr-oaDesign|\n"
"    BrowseData: 1\n"
"    oaRef::getMaster\n"
"    This function returns the master for this reference. If the reference cannot be bound to a master, a NULL pointer is returned.\n"
;

static PyObject*
oaRef_getMaster(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRef data;
    int convert_status=PyoaRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRefObject* self=(PyoaRefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDesignp result= (data.DataCall()->getMaster());
        return PyoaDesign_FromoaDesign(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRef_getOrient_doc[] = 
"Class: oaRef, Function: getOrient\n"
"  Paramegers: ()\n"
"    Calls: oaOrient getOrient() const\n"
"    Signature: getOrient|simple-oaOrient|\n"
"    BrowseData: 1\n"
"    This function returns the orientation of this reference.\n"
;

static PyObject*
oaRef_getOrient(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRef data;
    int convert_status=PyoaRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRefObject* self=(PyoaRefObject*)ob;
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
static char oaRef_getOrigin_doc[] = 
"Class: oaRef, Function: getOrigin\n"
"  Paramegers: (oaPoint)\n"
"    Calls: void getOrigin(oaPoint& origin) const\n"
"    Signature: getOrigin|void-void|ref-oaPoint,\n"
"    BrowseData: 0,oaPoint\n"
"    This function fills out 'origin' with the origin of this reference.\n"
"    origin\n"
"    The origin of this ref object\n"
;

static PyObject*
oaRef_getOrigin(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRef data;
    int convert_status=PyoaRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRefObject* self=(PyoaRefObject*)ob;
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
static char oaRef_getTransform_doc[] = 
"Class: oaRef, Function: getTransform\n"
"  Paramegers: (oaTransform)\n"
"    Calls: void getTransform(oaTransform& xform) const\n"
"    Signature: getTransform|void-void|ref-oaTransform,\n"
"    BrowseData: 0,oaTransform\n"
"    This function fills out 'xform' with the transform of this reference.\n"
"    xform\n"
"    The transform of this ref object\n"
;

static PyObject*
oaRef_getTransform(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRef data;
    int convert_status=PyoaRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRefObject* self=(PyoaRefObject*)ob;
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
static char oaRef_isBound_doc[] = 
"Class: oaRef, Function: isBound\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isBound() const\n"
"    Signature: isBound|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this reference is bound.\n"
;

static PyObject*
oaRef_isBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRef data;
    int convert_status=PyoaRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRefObject* self=(PyoaRefObject*)ob;
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
static char oaRef_setOrient_doc[] = 
"Class: oaRef, Function: setOrient\n"
"  Paramegers: (oaOrient)\n"
"    Calls: void setOrient(oaOrient orient)\n"
"    Signature: setOrient|void-void|simple-oaOrient,\n"
"    This function sets the orientation for this ref object.\n"
"    orient\n"
"    The orientation to be set to this ref object\n"
;

static PyObject*
oaRef_setOrient(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRef data;
    int convert_status=PyoaRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRefObject* self=(PyoaRefObject*)ob;
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
static char oaRef_setOrigin_doc[] = 
"Class: oaRef, Function: setOrigin\n"
"  Paramegers: (oaPoint)\n"
"    Calls: void setOrigin(const oaPoint& origin)\n"
"    Signature: setOrigin|void-void|cref-oaPoint,\n"
"    This function sets the origin value for this ref object.\n"
"    origin\n"
"    The origin to be set to this ref object\n"
;

static PyObject*
oaRef_setOrigin(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRef data;
    int convert_status=PyoaRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRefObject* self=(PyoaRefObject*)ob;
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
static char oaRef_setTransform_doc[] = 
"Class: oaRef, Function: setTransform\n"
"  Paramegers: (oaTransform)\n"
"    Calls: void setTransform(const oaTransform& xform)\n"
"    Signature: setTransform|void-void|cref-oaTransform,\n"
"    This function sets the transform for this ref object.\n"
"    xform\n"
"    The transform value to be set for this ref object\n"
;

static PyObject*
oaRef_setTransform(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRef data;
    int convert_status=PyoaRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRefObject* self=(PyoaRefObject*)ob;
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
static char oaRef_isNull_doc[] =
"Class: oaRef, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaRef_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaRef data;
    int convert_status=PyoaRef_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaRef_assign_doc[] = 
"Class: oaRef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRef data;
  int convert_status=PyoaRef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRef_methodlist[] = {
    {"getHeader",(PyCFunction)oaRef_getHeader,METH_VARARGS,oaRef_getHeader_doc},
    {"getMaster",(PyCFunction)oaRef_getMaster,METH_VARARGS,oaRef_getMaster_doc},
    {"getOrient",(PyCFunction)oaRef_getOrient,METH_VARARGS,oaRef_getOrient_doc},
    {"getOrigin",(PyCFunction)oaRef_getOrigin,METH_VARARGS,oaRef_getOrigin_doc},
    {"getTransform",(PyCFunction)oaRef_getTransform,METH_VARARGS,oaRef_getTransform_doc},
    {"isBound",(PyCFunction)oaRef_isBound,METH_VARARGS,oaRef_isBound_doc},
    {"setOrient",(PyCFunction)oaRef_setOrient,METH_VARARGS,oaRef_setOrient_doc},
    {"setOrigin",(PyCFunction)oaRef_setOrigin,METH_VARARGS,oaRef_setOrigin_doc},
    {"setTransform",(PyCFunction)oaRef_setTransform,METH_VARARGS,oaRef_setTransform_doc},
    {"isNull",(PyCFunction)oaRef_tp_isNull,METH_VARARGS,oaRef_isNull_doc},
    {"assign",(PyCFunction)oaRef_tp_assign,METH_VARARGS,oaRef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRef_doc[] = 
"Class: oaRef\n"
"  This file contains the definition for the oaRef class. This is an abstract base for all types of instances and vias. It implements the functionality common to the two derived classes: oaInst and oaVia .\n"
"Constructors:\n"
"  Paramegers: (oaRef)\n"
"    Calls: (const oaRef&)\n"
"    Signature: oaRef||cref-oaRef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRef",
    sizeof(PyoaRefObject),
    0,
    (destructor)oaRef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRef_tp_compare,	/* tp_compare */
    (reprfunc)oaRef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaPinFig_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRef_Type)<0) {
      printf("** PyType_Ready failed for: oaRef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRef",
           (PyObject*)(&PyoaRef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaRefHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRefHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRefHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRefHeaderObject* self = (PyoaRefHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaRefHeader)
    {
        PyParamoaRefHeader p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaRefHeader_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaRefHeader, Choices are:\n"
        "    (oaRefHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRefHeader_tp_dealloc(PyoaRefHeaderObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRefHeader_tp_repr(PyObject *ob)
{
    PyParamoaRefHeader value;
    int convert_status=PyoaRefHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[33];
    sprintf(buffer,"<oaRefHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRefHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRefHeader v1;
    PyParamoaRefHeader v2;
    int convert_status1=PyoaRefHeader_Convert(ob1,&v1);
    int convert_status2=PyoaRefHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRefHeader_Convert(PyObject* ob,PyParamoaRefHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaRefHeader_Check(ob)) {
        result->SetData( (oaRefHeader**) ((PyoaRefHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRefHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRefHeader_FromoaRefHeader(oaRefHeader** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaRefHeader* data=*value;
        if (data->isViaHeader()) return PyoaViaHeader_FromoaViaHeader((oaViaHeader**)value,borrow,lock);
        if (data->getType()==oacInstHeaderType) return PyoaInstHeader_FromoaInstHeader((oaInstHeader**)value,borrow,lock);
        PyObject* bself = PyoaRefHeader_Type.tp_alloc(&PyoaRefHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaRefHeaderObject* self = (PyoaRefHeaderObject*)bself;
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
PyObject* PyoaRefHeader_FromoaRefHeader(oaRefHeader* data)
{
    if (data) {
        if (data->isViaHeader()) return PyoaViaHeader_FromoaViaHeader((oaViaHeader*)data);
        if (data->getType()==oacInstHeaderType) return PyoaInstHeader_FromoaInstHeader((oaInstHeader*)data);
       PyObject* bself = PyoaRefHeader_Type.tp_alloc(&PyoaRefHeader_Type,0);
       if (bself == NULL) return bself;
       PyoaRefHeaderObject* self = (PyoaRefHeaderObject*)bself;
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
static char oaRefHeader_getBBox_doc[] = 
"Class: oaRefHeader, Function: getBBox\n"
"  Paramegers: (oaBox)\n"
"    Calls: void getBBox(oaBox& bBox) const\n"
"    Signature: getBBox|void-void|ref-oaBox,\n"
"    BrowseData: 0,oaBox\n"
"    This function fills out 'bBox' with the bBox of this instHeader.\n"
"    bBox\n"
"    The calculated bBox.\n"
;

static PyObject*
oaRefHeader_getBBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRefHeader data;
    int convert_status=PyoaRefHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRefHeaderObject* self=(PyoaRefHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBox p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBox_Convert,&p1)) {
        data.DataCall()->getBBox(p1.Data());
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
static char oaRefHeader_getMaster_doc[] = 
"Class: oaRefHeader, Function: getMaster\n"
"  Paramegers: ()\n"
"    Calls: oaDesign* getMaster() const\n"
"    Signature: getMaster|ptr-oaDesign|\n"
"    BrowseData: 1\n"
"    This function attempts to return the master associated with the specified refHeader. If the refHeader cannot be bound, NULL will be returned.\n"
;

static PyObject*
oaRefHeader_getMaster(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRefHeader data;
    int convert_status=PyoaRefHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRefHeaderObject* self=(PyoaRefHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDesignp result= (data.DataCall()->getMaster());
        return PyoaDesign_FromoaDesign(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRefHeader_getMasterBBox_doc[] = 
"Class: oaRefHeader, Function: getMasterBBox\n"
"  Paramegers: (oaBox)\n"
"    Calls: void getMasterBBox(oaBox& bBox) const\n"
"    Signature: getMasterBBox|void-void|ref-oaBox,\n"
"    BrowseData: 0,oaBox\n"
"    This function fills out 'bBox' with the bBox of this refHeader's master. Note that if the master's bBox is inverted (because the master is empty), it will be set to zero.\n"
"    bBox\n"
"    The calculated bBox of the master.\n"
;

static PyObject*
oaRefHeader_getMasterBBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRefHeader data;
    int convert_status=PyoaRefHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRefHeaderObject* self=(PyoaRefHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBox p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBox_Convert,&p1)) {
        data.DataCall()->getMasterBBox(p1.Data());
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
static char oaRefHeader_getSuperHeader_doc[] = 
"Class: oaRefHeader, Function: getSuperHeader\n"
"  Paramegers: ()\n"
"    Calls: oaRefHeader* getSuperHeader() const\n"
"    Signature: getSuperHeader|ptr-oaRefHeader|\n"
"    BrowseData: 1\n"
"    This function returns the superHeader of this refHeader or NULL if it is not a subHeader.\n"
;

static PyObject*
oaRefHeader_getSuperHeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRefHeader data;
    int convert_status=PyoaRefHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRefHeaderObject* self=(PyoaRefHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaRefHeaderp result= (data.DataCall()->getSuperHeader());
        return PyoaRefHeader_FromoaRefHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRefHeader_isBound_doc[] = 
"Class: oaRefHeader, Function: isBound\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isBound() const\n"
"    Signature: isBound|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this refHeader is bound.\n"
;

static PyObject*
oaRefHeader_isBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRefHeader data;
    int convert_status=PyoaRefHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRefHeaderObject* self=(PyoaRefHeaderObject*)ob;
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
static char oaRefHeader_isSubHeader_doc[] = 
"Class: oaRefHeader, Function: isSubHeader\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isSubHeader() const\n"
"    Signature: isSubHeader|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this refHeader is a subHeader.\n"
;

static PyObject*
oaRefHeader_isSubHeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRefHeader data;
    int convert_status=PyoaRefHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRefHeaderObject* self=(PyoaRefHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isSubHeader());
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
static char oaRefHeader_isSuperHeader_doc[] = 
"Class: oaRefHeader, Function: isSuperHeader\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isSuperHeader() const\n"
"    Signature: isSuperHeader|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this refHeader is a superHeader.\n"
;

static PyObject*
oaRefHeader_isSuperHeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRefHeader data;
    int convert_status=PyoaRefHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRefHeaderObject* self=(PyoaRefHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isSuperHeader());
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
static char oaRefHeader_isNull_doc[] =
"Class: oaRefHeader, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaRefHeader_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaRefHeader data;
    int convert_status=PyoaRefHeader_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaRefHeader_assign_doc[] = 
"Class: oaRefHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRefHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRefHeader data;
  int convert_status=PyoaRefHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRefHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRefHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRefHeader_methodlist[] = {
    {"getBBox",(PyCFunction)oaRefHeader_getBBox,METH_VARARGS,oaRefHeader_getBBox_doc},
    {"getMaster",(PyCFunction)oaRefHeader_getMaster,METH_VARARGS,oaRefHeader_getMaster_doc},
    {"getMasterBBox",(PyCFunction)oaRefHeader_getMasterBBox,METH_VARARGS,oaRefHeader_getMasterBBox_doc},
    {"getSuperHeader",(PyCFunction)oaRefHeader_getSuperHeader,METH_VARARGS,oaRefHeader_getSuperHeader_doc},
    {"isBound",(PyCFunction)oaRefHeader_isBound,METH_VARARGS,oaRefHeader_isBound_doc},
    {"isSubHeader",(PyCFunction)oaRefHeader_isSubHeader,METH_VARARGS,oaRefHeader_isSubHeader_doc},
    {"isSuperHeader",(PyCFunction)oaRefHeader_isSuperHeader,METH_VARARGS,oaRefHeader_isSuperHeader_doc},
    {"isNull",(PyCFunction)oaRefHeader_tp_isNull,METH_VARARGS,oaRefHeader_isNull_doc},
    {"assign",(PyCFunction)oaRefHeader_tp_assign,METH_VARARGS,oaRefHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRefHeader_doc[] = 
"Class: oaRefHeader\n"
"  The oaRefHeader class is an abstract base class that encapsulates information about a particular design master referenced in another design and all of the instances or vias that use it. The oaRefHeader class is the base of oaInstHeader and oaViaHeader .\n"
"Constructors:\n"
"  Paramegers: (oaRefHeader)\n"
"    Calls: (const oaRefHeader&)\n"
"    Signature: oaRefHeader||cref-oaRefHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRefHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRefHeader",
    sizeof(PyoaRefHeaderObject),
    0,
    (destructor)oaRefHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRefHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaRefHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRefHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRefHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBlockObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRefHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRefHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRefHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaRefHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRefHeader",
           (PyObject*)(&PyoaRefHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRefHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaRegionQuery
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRegionQuery_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRegionQuery_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRegionQueryObject* self = (PyoaRegionQueryObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaRegionQuery, Choices are:\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRegionQuery_tp_dealloc(PyoaRegionQueryObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRegionQuery_tp_repr(PyObject *ob)
{
    PyParamoaRegionQuery value;
    int convert_status=PyoaRegionQuery_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaRegionQuery::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRegionQuery_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRegionQuery v1;
    PyParamoaRegionQuery v2;
    int convert_status1=PyoaRegionQuery_Convert(ob1,&v1);
    int convert_status2=PyoaRegionQuery_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRegionQuery_Convert(PyObject* ob,PyParamoaRegionQuery* result)
{
    if (ob == NULL) return 1;
    if (PyoaRegionQuery_Check(ob)) {
        result->SetData(  ((PyoaRegionQueryObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRegionQuery Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRegionQuery_FromoaRegionQuery(oaRegionQuery* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaRegionQuery_Type.tp_alloc(&PyoaRegionQuery_Type,0);
        if (bself == NULL) return bself;
        PyoaRegionQueryObject* self = (PyoaRegionQueryObject*)bself;
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
// Virtual Functions:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
void pyv_oaRegionQuery::endRef(oaRef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaRegionQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaRegionQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaRegionQuery::endRef(oaRef* p1,oaUInt4 p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaRegionQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaRegionQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaRegionQuery::endRef(oaRef* p1,oaUInt4 p2,oaUInt4 p3)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaRegionQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(3);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyTuple_SetItem(args,2,PyoaUInt4_FromoaUInt4(p3));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaRegionQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
oaBoolean pyv_oaRegionQuery::startRef(oaRef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaRegionQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaRegionQuery::startRef had an error.");
    }
    PyParamoaBoolean rv;
    if (PyoaBoolean_Convert(result,&rv)==0) {
        throw oaPythonException("Python Virtual Function oaBoolean::startRef has incorrect return type.");
    }
    Py_DECREF(result);
    return rv.Data();
}

// ------------------------------------------------------------------
oaBoolean pyv_oaRegionQuery::startRef(oaRef* p1,oaUInt4 p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaRegionQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaRegionQuery::startRef had an error.");
    }
    PyParamoaBoolean rv;
    if (PyoaBoolean_Convert(result,&rv)==0) {
        throw oaPythonException("Python Virtual Function oaBoolean::startRef has incorrect return type.");
    }
    Py_DECREF(result);
    return rv.Data();
}

// ------------------------------------------------------------------
oaBoolean pyv_oaRegionQuery::startRef(oaRef* p1,oaUInt4 p2,oaUInt4 p3)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaRegionQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(3);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyTuple_SetItem(args,2,PyoaUInt4_FromoaUInt4(p3));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaRegionQuery::startRef had an error.");
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
static char oaRegionQuery_abort_doc[] = 
"Class: oaRegionQuery, Function: abort\n"
"  Paramegers: ()\n"
"    Calls: void abort()\n"
"    Signature: abort|void-void|\n"
"    BrowseData: 0\n"
"    This function aborts the current query as soon as possible, returning control to the caller.\n"
;

static PyObject*
oaRegionQuery_abort(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRegionQuery data;
    int convert_status=PyoaRegionQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRegionQueryObject* self=(PyoaRegionQueryObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->abort();
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
static char oaRegionQuery_endRef_doc[] = 
"Class: oaRegionQuery, Function: endRef\n"
"  Paramegers: (oaRef)\n"
"    Calls: virtual void endRef(oaRef* ref)\n"
"    Signature: endRef|void-void|ptr-oaRef,simple-oaUInt4,simple-oaUInt4,\n"
"    This function is called by the query, if startRef returned true for the reference and after the specified reference is processed. If the reference is an arrayInst, each element of the array that overlaps the query region will be processed separately, in which case 'row' and 'col' indicate which element is being processed.\n"
"    If the maximum dimension of the ref's master is smaller than the filter size specified for the query, this reference will not be processed. In this case, neither startRef, nor endRef will be called for the reference.\n"
"    The user may override this function to be notified of the event.\n"
"    ref\n"
"    The pointer to an oaRef\n"
"    row\n"
"    The row index of the arrayInst\n"
"    col\n"
"    The col index of the arrayInst\n"
"  Paramegers: (oaRef,oaUInt4)\n"
"    Calls: virtual void endRef(oaRef* ref,oaUInt4 row)\n"
"    Signature: endRef|void-void|ptr-oaRef,simple-oaUInt4,simple-oaUInt4,\n"
"    This function is called by the query, if startRef returned true for the reference and after the specified reference is processed. If the reference is an arrayInst, each element of the array that overlaps the query region will be processed separately, in which case 'row' and 'col' indicate which element is being processed.\n"
"    If the maximum dimension of the ref's master is smaller than the filter size specified for the query, this reference will not be processed. In this case, neither startRef, nor endRef will be called for the reference.\n"
"    The user may override this function to be notified of the event.\n"
"    ref\n"
"    The pointer to an oaRef\n"
"    row\n"
"    The row index of the arrayInst\n"
"    col\n"
"    The col index of the arrayInst\n"
"  Paramegers: (oaRef,oaUInt4,oaUInt4)\n"
"    Calls: virtual void endRef(oaRef* ref,oaUInt4 row,oaUInt4 col)\n"
"    Signature: endRef|void-void|ptr-oaRef,simple-oaUInt4,simple-oaUInt4,\n"
"    This function is called by the query, if startRef returned true for the reference and after the specified reference is processed. If the reference is an arrayInst, each element of the array that overlaps the query region will be processed separately, in which case 'row' and 'col' indicate which element is being processed.\n"
"    If the maximum dimension of the ref's master is smaller than the filter size specified for the query, this reference will not be processed. In this case, neither startRef, nor endRef will be called for the reference.\n"
"    The user may override this function to be notified of the event.\n"
"    ref\n"
"    The pointer to an oaRef\n"
"    row\n"
"    The row index of the arrayInst\n"
"    col\n"
"    The col index of the arrayInst\n"
;

static PyObject*
oaRegionQuery_endRef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRegionQuery data;
    int convert_status=PyoaRegionQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRegionQueryObject* self=(PyoaRegionQueryObject*)ob;

    // Case: (oaRef)
    {
        PyParamoaRef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaRef_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->oaRegionQuery::endRef(p1.Data());
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
            data.DataCall()->oaRegionQuery::endRef(p1.Data(),p2.Data());
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
            data.DataCall()->oaRegionQuery::endRef(p1.Data(),p2.Data(),p3.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaRegionQuery, function: endRef, Choices are:\n"
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
static char oaRegionQuery_getCurrentRegion_doc[] = 
"Class: oaRegionQuery, Function: getCurrentRegion\n"
"  Paramegers: ()\n"
"    Calls: const oaBox& getCurrentRegion() const\n"
"    Signature: getCurrentRegion|cref-oaBox|\n"
"    BrowseData: 1\n"
"    This function returns the current region used by this query object in the current level of hierarchy being processed.\n"
;

static PyObject*
oaRegionQuery_getCurrentRegion(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRegionQuery data;
    int convert_status=PyoaRegionQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRegionQueryObject* self=(PyoaRegionQueryObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBox* result= new oaBox(data.DataCall()->getCurrentRegion());
        return PyoaBox_FromoaBox(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRegionQuery_getCurrentTransform_doc[] = 
"Class: oaRegionQuery, Function: getCurrentTransform\n"
"  Paramegers: ()\n"
"    Calls: const oaTransform& getCurrentTransform() const\n"
"    Signature: getCurrentTransform|cref-oaTransform|\n"
"    BrowseData: 1\n"
"    This function returns the current transformation of this query object in the reference frame of the design currently being processed.\n"
;

static PyObject*
oaRegionQuery_getCurrentTransform(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRegionQuery data;
    int convert_status=PyoaRegionQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRegionQueryObject* self=(PyoaRegionQueryObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaTransform* result= new oaTransform(data.DataCall()->getCurrentTransform());
        return PyoaTransform_FromoaTransform(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRegionQuery_getFilterSize_doc[] = 
"Class: oaRegionQuery, Function: getFilterSize\n"
"  Paramegers: ()\n"
"    Calls: oaDist getFilterSize() const\n"
"    Signature: getFilterSize|simple-oaDist|\n"
"    BrowseData: 1\n"
"    This function returns the size of the filter for the query.\n"
;

static PyObject*
oaRegionQuery_getFilterSize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRegionQuery data;
    int convert_status=PyoaRegionQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRegionQueryObject* self=(PyoaRegionQueryObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaDist result= (data.DataCall()->getFilterSize());
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
static char oaRegionQuery_getHierPath_doc[] = 
"Class: oaRegionQuery, Function: getHierPath\n"
"  Paramegers: (oaHierPath)\n"
"    Calls: void getHierPath(oaHierPath& hierPath) const\n"
"    Signature: getHierPath|void-void|ref-oaHierPath,\n"
"    BrowseData: 0,oaHierPath\n"
"    This function returns the current hierarchical path of this query object.\n"
"    hierPath\n"
"    The returned hierarchical path\n"
;

static PyObject*
oaRegionQuery_getHierPath(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRegionQuery data;
    int convert_status=PyoaRegionQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRegionQueryObject* self=(PyoaRegionQueryObject*)ob;

    PyParamoaHierPath p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaHierPath_Convert,&p1)) {
        data.DataCall()->getHierPath(p1.Data());
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
static char oaRegionQuery_getRegion_doc[] = 
"Class: oaRegionQuery, Function: getRegion\n"
"  Paramegers: ()\n"
"    Calls: const oaBox& getRegion() const\n"
"    Signature: getRegion|cref-oaBox|\n"
"    BrowseData: 1\n"
"    This function returns the region being searched in the reference frame of the portion of the design hierarchy currently being processed.\n"
;

static PyObject*
oaRegionQuery_getRegion(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRegionQuery data;
    int convert_status=PyoaRegionQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRegionQueryObject* self=(PyoaRegionQueryObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBox* result= new oaBox(data.DataCall()->getRegion());
        return PyoaBox_FromoaBox(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRegionQuery_getStartLevel_doc[] = 
"Class: oaRegionQuery, Function: getStartLevel\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getStartLevel() const\n"
"    Signature: getStartLevel|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the start search level of the current query.\n"
;

static PyObject*
oaRegionQuery_getStartLevel(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRegionQuery data;
    int convert_status=PyoaRegionQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRegionQueryObject* self=(PyoaRegionQueryObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getStartLevel());
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
static char oaRegionQuery_getStopLevel_doc[] = 
"Class: oaRegionQuery, Function: getStopLevel\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getStopLevel() const\n"
"    Signature: getStopLevel|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the stop search level of the current query.\n"
;

static PyObject*
oaRegionQuery_getStopLevel(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRegionQuery data;
    int convert_status=PyoaRegionQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRegionQueryObject* self=(PyoaRegionQueryObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getStopLevel());
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
static char oaRegionQuery_startRef_doc[] = 
"Class: oaRegionQuery, Function: startRef\n"
"  Paramegers: (oaRef)\n"
"    Calls: virtual oaBoolean startRef(oaRef* ref)\n"
"    Signature: startRef|simple-oaBoolean|ptr-oaRef,simple-oaUInt4,simple-oaUInt4,\n"
"    This function is called by the query just before the specified reference is processed. The user may override this function to be notified of the event. If desired, the user may return false from startRef() , indicating that the query should not descend into the reference's master. This is used to control if certain parts of the hierarchy gets traversed or not. The default implementation returns true, which means the query should descend into the ref's master.\n"
"    If the reference is an arrayInst, each element of the array that overlaps the query region will be processed separately, in which case 'row' and 'col' indicate which element is being processed.\n"
"    If the maximum dimension of the ref's master is smaller than the filter size specified for the query, this reference will not be processed. In this case, startRef will not be called for the reference.\n"
"    ref\n"
"    The pointer to an oaRef\n"
"    row\n"
"    The row index of the arrayInst\n"
"    col\n"
"    The col index of the arrayInst\n"
"  Paramegers: (oaRef,oaUInt4)\n"
"    Calls: virtual oaBoolean startRef(oaRef* ref,oaUInt4 row)\n"
"    Signature: startRef|simple-oaBoolean|ptr-oaRef,simple-oaUInt4,simple-oaUInt4,\n"
"    This function is called by the query just before the specified reference is processed. The user may override this function to be notified of the event. If desired, the user may return false from startRef() , indicating that the query should not descend into the reference's master. This is used to control if certain parts of the hierarchy gets traversed or not. The default implementation returns true, which means the query should descend into the ref's master.\n"
"    If the reference is an arrayInst, each element of the array that overlaps the query region will be processed separately, in which case 'row' and 'col' indicate which element is being processed.\n"
"    If the maximum dimension of the ref's master is smaller than the filter size specified for the query, this reference will not be processed. In this case, startRef will not be called for the reference.\n"
"    ref\n"
"    The pointer to an oaRef\n"
"    row\n"
"    The row index of the arrayInst\n"
"    col\n"
"    The col index of the arrayInst\n"
"  Paramegers: (oaRef,oaUInt4,oaUInt4)\n"
"    Calls: virtual oaBoolean startRef(oaRef* ref,oaUInt4 row,oaUInt4 col)\n"
"    Signature: startRef|simple-oaBoolean|ptr-oaRef,simple-oaUInt4,simple-oaUInt4,\n"
"    This function is called by the query just before the specified reference is processed. The user may override this function to be notified of the event. If desired, the user may return false from startRef() , indicating that the query should not descend into the reference's master. This is used to control if certain parts of the hierarchy gets traversed or not. The default implementation returns true, which means the query should descend into the ref's master.\n"
"    If the reference is an arrayInst, each element of the array that overlaps the query region will be processed separately, in which case 'row' and 'col' indicate which element is being processed.\n"
"    If the maximum dimension of the ref's master is smaller than the filter size specified for the query, this reference will not be processed. In this case, startRef will not be called for the reference.\n"
"    ref\n"
"    The pointer to an oaRef\n"
"    row\n"
"    The row index of the arrayInst\n"
"    col\n"
"    The col index of the arrayInst\n"
;

static PyObject*
oaRegionQuery_startRef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRegionQuery data;
    int convert_status=PyoaRegionQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRegionQueryObject* self=(PyoaRegionQueryObject*)ob;

    // Case: (oaRef)
    {
        PyParamoaRef p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaRef_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaBoolean result= (data.DataCall()->oaRegionQuery::startRef(p1.Data()));
            return PyoaBoolean_FromoaBoolean(result);
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
            oaBoolean result= (data.DataCall()->oaRegionQuery::startRef(p1.Data(),p2.Data()));
            return PyoaBoolean_FromoaBoolean(result);
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
            oaBoolean result= (data.DataCall()->oaRegionQuery::startRef(p1.Data(),p2.Data(),p3.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaRegionQuery, function: startRef, Choices are:\n"
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

static char oaRegionQuery_assign_doc[] = 
"Class: oaRegionQuery, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRegionQuery_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRegionQuery data;
  int convert_status=PyoaRegionQuery_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRegionQuery p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRegionQuery_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRegionQuery_methodlist[] = {
    {"abort",(PyCFunction)oaRegionQuery_abort,METH_VARARGS,oaRegionQuery_abort_doc},
    {"endRef",(PyCFunction)oaRegionQuery_endRef,METH_VARARGS,oaRegionQuery_endRef_doc},
    {"getCurrentRegion",(PyCFunction)oaRegionQuery_getCurrentRegion,METH_VARARGS,oaRegionQuery_getCurrentRegion_doc},
    {"getCurrentTransform",(PyCFunction)oaRegionQuery_getCurrentTransform,METH_VARARGS,oaRegionQuery_getCurrentTransform_doc},
    {"getFilterSize",(PyCFunction)oaRegionQuery_getFilterSize,METH_VARARGS,oaRegionQuery_getFilterSize_doc},
    {"getHierPath",(PyCFunction)oaRegionQuery_getHierPath,METH_VARARGS,oaRegionQuery_getHierPath_doc},
    {"getRegion",(PyCFunction)oaRegionQuery_getRegion,METH_VARARGS,oaRegionQuery_getRegion_doc},
    {"getStartLevel",(PyCFunction)oaRegionQuery_getStartLevel,METH_VARARGS,oaRegionQuery_getStartLevel_doc},
    {"getStopLevel",(PyCFunction)oaRegionQuery_getStopLevel,METH_VARARGS,oaRegionQuery_getStopLevel_doc},
    {"startRef",(PyCFunction)oaRegionQuery_startRef,METH_VARARGS,oaRegionQuery_startRef_doc},
    {"assign",(PyCFunction)oaRegionQuery_tp_assign,METH_VARARGS,oaRegionQuery_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRegionQuery_doc[] = 
"Class: oaRegionQuery\n"
"  The oaRegionQuery class is an abstract class that is the parent class to query classes for each type of figure. These classes implement a hierarchical query for figures within a specified rectangular region of a design hierarchy. RegionQuery is used to drive the graphical display of design hierarchies as well as find the set of objects that are neighbors to a given object for analysis.\n"
"  A Region Query descends through a design hierarchy from the top design with which it is constructed, producing all objects of a specified type in the specified query region. It should be noted that Region Query never opens instance masters that are not already open. In other words, it will not process the contents of instances unless their masters are already open. This is true regardless of the specified startLevel and stopLevel. If the caller wants to insure that a specified number of levels of design hierarchy are processed by Region Query, the caller should precede the call to RegionQuery with a call to oaDesign::openHier() .\n"
"  Applications use oaRegionQuery by creating their own class that derives from one of the oaRegionQuery subclasses, then implementing functions in their class for virtual functions declared in either the base or the derived oaRegionQuery class. These user-implemented functions will be called by the database to hand off the figures found in a specified region.\n"
"  A region query is initiated by a query() function in the figure-specific RegionQuery class, for example by oaShapeQuery::query() . The figures are then handed to the application by calls to the implemented virtual function with a name of the form queryFigure() , such as oaBoundaryQuery::queryBoundary() .\n"
"  Attributes are provided to allow applications to control how the query is performed. For example, the startLevel and stopLevel attributes allow applications to control the depth of hierarchy traversal, and filterSize allows applications to eliminate objects below a specified size threshold.\n"
"  If the application needs to keep track of where it is in the hierarchy, it can implement the startRef() member function, which returns a boolean value that can be set to FALSE to tell the database not to continue into this portion of the hierarchy.\n"
"Constructors:\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRegionQuery_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRegionQuery",
    sizeof(PyoaRegionQueryObject),
    0,
    (destructor)oaRegionQuery_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRegionQuery_tp_compare,	/* tp_compare */
    (reprfunc)oaRegionQuery_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRegionQuery_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRegionQuery_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRegionQuery_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRegionQuery_static_getPlugInName_doc[] = 
"Class: oaRegionQuery, Function: getPlugInName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getPlugInName(oaString& plugInName)\n"
"    Signature: getPlugInName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    oaRegionQuery::getPlugInName\n"
"    This function returns the name of the current plugIn used by region query. If there is no plugIn is initialized through the init() , the return value will an empty string.\n"
"    plugInName\n"
"    The returned plugIn name\n"
;

static PyObject*
oaRegionQuery_static_getPlugInName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        oaRegionQuery::getPlugInName(p1.Data());
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
static char oaRegionQuery_static_init_doc[] = 
"Class: oaRegionQuery, Function: init\n"
"  Paramegers: (oaString)\n"
"    Calls: void init(const oaString& plugInName)\n"
"    Signature: init|void-void|cref-oaString,\n"
"    oaRegionQuery::init\n"
"    This function initialized the plugIn for oaRegionQuery to use. An application can specify the default OpenAccess region query plugIn \"oaRQSystem\" or a customized one.\n"
"    plugInName\n"
"    The name of the plugIn\n"
"    oacRegionQueryAlreadyInitialized\n"
;

static PyObject*
oaRegionQuery_static_init(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        oaRegionQuery::init(p1.Data());
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
static PyMethodDef oaRegionQuery_staticmethodlist[] = {
    {"static_getPlugInName",(PyCFunction)oaRegionQuery_static_getPlugInName,METH_VARARGS,oaRegionQuery_static_getPlugInName_doc},
    {"static_init",(PyCFunction)oaRegionQuery_static_init,METH_VARARGS,oaRegionQuery_static_init_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRegionQuery_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRegionQuery_Type)<0) {
      printf("** PyType_Ready failed for: oaRegionQuery\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRegionQuery",
           (PyObject*)(&PyoaRegionQuery_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRegionQuery\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaRegionQuery_Type.tp_dict;
    for(method=oaRegionQuery_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaReservedViewType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaReservedViewType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaReservedViewType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaReservedViewTypeObject* self = (PyoaReservedViewTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaReservedViewTypeEnum)
    {
        PyParamoaReservedViewTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaReservedViewTypeEnum_Convert,&p1)) {
            self->value =  new oaReservedViewType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaReservedViewType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaReservedViewType)
    {
        PyParamoaReservedViewType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaReservedViewType_Convert,&p1)) {
            self->value= new oaReservedViewType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaReservedViewType, Choices are:\n"
        "    (oaReservedViewTypeEnum)\n"
        "    (oaString)\n"
        "    (oaReservedViewType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaReservedViewType_tp_dealloc(PyoaReservedViewTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaReservedViewType_tp_repr(PyObject *ob)
{
    PyParamoaReservedViewType value;
    int convert_status=PyoaReservedViewType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[40];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaReservedViewType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaReservedViewType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaReservedViewType v1;
    PyParamoaReservedViewType v2;
    int convert_status1=PyoaReservedViewType_Convert(ob1,&v1);
    int convert_status2=PyoaReservedViewType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaReservedViewType_Convert(PyObject* ob,PyParamoaReservedViewType* result)
{
    if (ob == NULL) return 1;
    if (PyoaReservedViewType_Check(ob)) {
        result->SetData(  ((PyoaReservedViewTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaReservedViewType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaReservedViewType_FromoaReservedViewType(oaReservedViewType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaReservedViewType_Type.tp_alloc(&PyoaReservedViewType_Type,0);
        if (bself == NULL) return bself;
        PyoaReservedViewTypeObject* self = (PyoaReservedViewTypeObject*)bself;
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
static char oaReservedViewType_getName_doc[] = 
"Class: oaReservedViewType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name of the oaReservedViewTypeEnum value set on this oaReservedViewType wrapper object.\n"
;

static PyObject*
oaReservedViewType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReservedViewType data;
    int convert_status=PyoaReservedViewType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReservedViewTypeObject* self=(PyoaReservedViewTypeObject*)ob;

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
static char oaReservedViewType_oaReservedViewTypeEnum_doc[] = 
"Class: oaReservedViewType, Function: oaReservedViewTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaReservedViewTypeEnum oaReservedViewTypeEnum() const\n"
"    Signature: operator oaReservedViewTypeEnum|simple-oaReservedViewTypeEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaReservedViewType object into its corresponding oaReservedViewTypeEnum value.\n"
;

static PyObject*
oaReservedViewType_oaReservedViewTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReservedViewType data;
    int convert_status=PyoaReservedViewType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReservedViewTypeObject* self=(PyoaReservedViewTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaReservedViewTypeEnum result= (data.DataCall()->operator oaReservedViewTypeEnum());
        return PyoaReservedViewTypeEnum_FromoaReservedViewTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaReservedViewType_assign_doc[] = 
"Class: oaReservedViewType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaReservedViewType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaReservedViewType data;
  int convert_status=PyoaReservedViewType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaReservedViewType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaReservedViewType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaReservedViewType_methodlist[] = {
    {"getName",(PyCFunction)oaReservedViewType_getName,METH_VARARGS,oaReservedViewType_getName_doc},
    {"oaReservedViewTypeEnum",(PyCFunction)oaReservedViewType_oaReservedViewTypeEnum,METH_VARARGS,oaReservedViewType_oaReservedViewTypeEnum_doc},
    {"assign",(PyCFunction)oaReservedViewType_tp_assign,METH_VARARGS,oaReservedViewType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaReservedViewType_doc[] = 
"Class: oaReservedViewType\n"
"  oaReservedViewTypeEnum\n"
"  The oaReservedViewType class is enum wrapper class that encapsulates oaReservedViewTypeEnum values.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"Constructors:\n"
"  Paramegers: (oaReservedViewTypeEnum)\n"
"    Calls: oaReservedViewType(oaReservedViewTypeEnum valueIn)\n"
"    Signature: oaReservedViewType||simple-oaReservedViewTypeEnum,\n"
"    This oaReservedViewType constructor takes an oaReservedViewTypeEnum value as input.\n"
"    valueIn\n"
"    a oaReservedViewTypeEnum value\n"
"  Paramegers: (oaString)\n"
"    Calls: oaReservedViewType(const oaString& name)\n"
"    Signature: oaReservedViewType||cref-oaString,\n"
"    This oaReservedViewType constructor takes an oaReservedViewTypeEnum oaString name as input.\n"
"    name\n"
"    the name associated with the oaReservedViewTypeEnum value to set on the constructed oaReservedViewType object\n"
"    oacInvalidReservedViewTypeName\n"
"  Paramegers: (oaReservedViewType)\n"
"    Calls: (const oaReservedViewType&)\n"
"    Signature: oaReservedViewType||cref-oaReservedViewType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaReservedViewType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaReservedViewType",
    sizeof(PyoaReservedViewTypeObject),
    0,
    (destructor)oaReservedViewType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaReservedViewType_tp_compare,	/* tp_compare */
    (reprfunc)oaReservedViewType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaReservedViewType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaReservedViewType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaReservedViewType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaReservedViewType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaReservedViewType_Type)<0) {
      printf("** PyType_Ready failed for: oaReservedViewType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaReservedViewType",
           (PyObject*)(&PyoaReservedViewType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaReservedViewType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaReservedViewTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaReservedViewTypeEnum_Convert(PyObject* ob,PyParamoaReservedViewTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacMaskLayout")==0) { result->SetData(oacMaskLayout); return 1;}
        if (strcasecmp(str,"oacSchematic")==0) { result->SetData(oacSchematic); return 1;}
        if (strcasecmp(str,"oacSchematicSymbol")==0) { result->SetData(oacSchematicSymbol); return 1;}
        if (strcasecmp(str,"oacNetlist")==0) { result->SetData(oacNetlist); return 1;}
        if (strcasecmp(str,"oacWafer")==0) { result->SetData(oacWafer); return 1;}
        if (strcasecmp(str,"oacVerilogAMSText")==0) { result->SetData(oacVerilogAMSText); return 1;}
        if (strcasecmp(str,"oacVHDLAMSText")==0) { result->SetData(oacVHDLAMSText); return 1;}
        if (strcasecmp(str,"oacVerilogText")==0) { result->SetData(oacVerilogText); return 1;}
        if (strcasecmp(str,"oacVHDLText")==0) { result->SetData(oacVHDLText); return 1;}
        if (strcasecmp(str,"oacVerilogAText")==0) { result->SetData(oacVerilogAText); return 1;}
        if (strcasecmp(str,"oacHierDesign")==0) { result->SetData(oacHierDesign); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaReservedViewTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaReservedViewTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaReservedViewTypeEnum_FromoaReservedViewTypeEnum(oaReservedViewTypeEnum ob)
{
    if (ob==oacMaskLayout) return PyString_FromString("oacMaskLayout");
    if (ob==oacSchematic) return PyString_FromString("oacSchematic");
    if (ob==oacSchematicSymbol) return PyString_FromString("oacSchematicSymbol");
    if (ob==oacNetlist) return PyString_FromString("oacNetlist");
    if (ob==oacWafer) return PyString_FromString("oacWafer");
    if (ob==oacVerilogAMSText) return PyString_FromString("oacVerilogAMSText");
    if (ob==oacVHDLAMSText) return PyString_FromString("oacVHDLAMSText");
    if (ob==oacVerilogText) return PyString_FromString("oacVerilogText");
    if (ob==oacVHDLText) return PyString_FromString("oacVHDLText");
    if (ob==oacVerilogAText) return PyString_FromString("oacVerilogAText");
    if (ob==oacHierDesign) return PyString_FromString("oacHierDesign");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaReservedViewTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaReservedViewTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaReservedViewTypeEnum_FromoaReservedViewTypeEnum(oaReservedViewTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaReservedViewTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaReservedViewTypeEnum_doc[] =
"Type convert function for enum: oaReservedViewTypeEnum";
                               
static PyMethodDef PyoaReservedViewTypeEnum_method =
  {"oaReservedViewTypeEnum",(PyCFunction)PyoaReservedViewTypeEnum_TypeFunction,METH_VARARGS,oaReservedViewTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaReservedViewTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacMaskLayout");
    PyDict_SetItemString(mod_dict,"oacMaskLayout",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSchematic");
    PyDict_SetItemString(mod_dict,"oacSchematic",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSchematicSymbol");
    PyDict_SetItemString(mod_dict,"oacSchematicSymbol",value);
    Py_DECREF(value);
    value=PyString_FromString("oacNetlist");
    PyDict_SetItemString(mod_dict,"oacNetlist",value);
    Py_DECREF(value);
    value=PyString_FromString("oacWafer");
    PyDict_SetItemString(mod_dict,"oacWafer",value);
    Py_DECREF(value);
    value=PyString_FromString("oacVerilogAMSText");
    PyDict_SetItemString(mod_dict,"oacVerilogAMSText",value);
    Py_DECREF(value);
    value=PyString_FromString("oacVHDLAMSText");
    PyDict_SetItemString(mod_dict,"oacVHDLAMSText",value);
    Py_DECREF(value);
    value=PyString_FromString("oacVerilogText");
    PyDict_SetItemString(mod_dict,"oacVerilogText",value);
    Py_DECREF(value);
    value=PyString_FromString("oacVHDLText");
    PyDict_SetItemString(mod_dict,"oacVHDLText",value);
    Py_DECREF(value);
    value=PyString_FromString("oacVerilogAText");
    PyDict_SetItemString(mod_dict,"oacVerilogAText",value);
    Py_DECREF(value);
    value=PyString_FromString("oacHierDesign");
    PyDict_SetItemString(mod_dict,"oacHierDesign",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaReservedViewTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaReservedViewTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaReservedViewTypeEnum\n");
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
// Wrapper Implementation for Class: oaResistor
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaResistor_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaResistor_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaResistorObject* self = (PyoaResistorObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaResistor)
    {
        PyParamoaResistor p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaResistor_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaResistor, Choices are:\n"
        "    (oaResistor)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaResistor_tp_dealloc(PyoaResistorObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaResistor_tp_repr(PyObject *ob)
{
    PyParamoaResistor value;
    int convert_status=PyoaResistor_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[32];
    sprintf(buffer,"<oaResistor::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaResistor_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaResistor v1;
    PyParamoaResistor v2;
    int convert_status1=PyoaResistor_Convert(ob1,&v1);
    int convert_status2=PyoaResistor_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaResistor_Convert(PyObject* ob,PyParamoaResistor* result)
{
    if (ob == NULL) return 1;
    if (PyoaResistor_Check(ob)) {
        result->SetData( (oaResistor**) ((PyoaResistorObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaResistor Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaResistor_FromoaResistor(oaResistor** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaResistor* data=*value;
        PyObject* bself = PyoaResistor_Type.tp_alloc(&PyoaResistor_Type,0);
        if (bself == NULL) return bself;
        PyoaResistorObject* self = (PyoaResistorObject*)bself;
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
PyObject* PyoaResistor_FromoaResistor(oaResistor* data)
{
    if (data) {
       PyObject* bself = PyoaResistor_Type.tp_alloc(&PyoaResistor_Type,0);
       if (bself == NULL) return bself;
       PyoaResistorObject* self = (PyoaResistorObject*)bself;
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
static char oaResistor_getCutArea_doc[] = 
"Class: oaResistor, Function: getCutArea\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCutArea() const\n"
"    Signature: getCutArea|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the cut area associated with this resistor.\n"
;

static PyObject*
oaResistor_getCutArea(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getCutArea());
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
static char oaResistor_getCutPerimeter_doc[] = 
"Class: oaResistor, Function: getCutPerimeter\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getCutPerimeter() const\n"
"    Signature: getCutPerimeter|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the cut area perimeter associated with this resistor.\n"
;

static PyObject*
oaResistor_getCutPerimeter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getCutPerimeter());
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
static char oaResistor_getHeight_doc[] = 
"Class: oaResistor, Function: getHeight\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getHeight() const\n"
"    Signature: getHeight|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the effective height associated with this resistor.\n"
;

static PyObject*
oaResistor_getHeight(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getHeight());
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
static char oaResistor_getLength_doc[] = 
"Class: oaResistor, Function: getLength\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getLength() const\n"
"    Signature: getLength|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the effective length associated with this resistor.\n"
;

static PyObject*
oaResistor_getLength(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getLength());
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
static char oaResistor_getNumCuts_doc[] = 
"Class: oaResistor, Function: getNumCuts\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumCuts() const\n"
"    Signature: getNumCuts|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of cuts associated with this resistor.\n"
;

static PyObject*
oaResistor_getNumCuts(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumCuts());
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
static char oaResistor_getWidth_doc[] = 
"Class: oaResistor, Function: getWidth\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getWidth() const\n"
"    Signature: getWidth|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the effective width associated with this resistor.\n"
;

static PyObject*
oaResistor_getWidth(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getWidth());
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
static char oaResistor_hasCutArea_doc[] = 
"Class: oaResistor, Function: hasCutArea\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasCutArea() const\n"
"    Signature: hasCutArea|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this resistor has cut area.\n"
;

static PyObject*
oaResistor_hasCutArea(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasCutArea());
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
static char oaResistor_hasCutPerimeter_doc[] = 
"Class: oaResistor, Function: hasCutPerimeter\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasCutPerimeter() const\n"
"    Signature: hasCutPerimeter|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this resistor has cut perimeter.\n"
;

static PyObject*
oaResistor_hasCutPerimeter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasCutPerimeter());
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
static char oaResistor_hasHeight_doc[] = 
"Class: oaResistor, Function: hasHeight\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasHeight() const\n"
"    Signature: hasHeight|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this resistor has height.\n"
;

static PyObject*
oaResistor_hasHeight(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasHeight());
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
static char oaResistor_hasLength_doc[] = 
"Class: oaResistor, Function: hasLength\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasLength() const\n"
"    Signature: hasLength|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this resistor has length.\n"
;

static PyObject*
oaResistor_hasLength(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasLength());
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
static char oaResistor_hasNumCuts_doc[] = 
"Class: oaResistor, Function: hasNumCuts\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasNumCuts() const\n"
"    Signature: hasNumCuts|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this resistor has number of cuts.\n"
;

static PyObject*
oaResistor_hasNumCuts(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasNumCuts());
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
static char oaResistor_hasWidth_doc[] = 
"Class: oaResistor, Function: hasWidth\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasWidth() const\n"
"    Signature: hasWidth|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether or not this resistor has width.\n"
;

static PyObject*
oaResistor_hasWidth(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasWidth());
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
static char oaResistor_setCutArea_doc[] = 
"Class: oaResistor, Function: setCutArea\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setCutArea(oaUInt4 cutArea)\n"
"    Signature: setCutArea|void-void|simple-oaUInt4,\n"
"    This function sets the cut area of this resistor to the specified value.\n"
"    cutArea\n"
"    the cut area to set on this oaResistor object\n"
;

static PyObject*
oaResistor_setCutArea(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setCutArea(p1.Data());
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
static char oaResistor_setCutPerimeter_doc[] = 
"Class: oaResistor, Function: setCutPerimeter\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setCutPerimeter(oaUInt4 cutPerimeter)\n"
"    Signature: setCutPerimeter|void-void|simple-oaUInt4,\n"
"    This function sets the cut perimeter of this resistor to the specified value.\n"
"    cutPerimeter\n"
"    the cut perimeter to set on this oaResistor object\n"
;

static PyObject*
oaResistor_setCutPerimeter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setCutPerimeter(p1.Data());
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
static char oaResistor_setHeight_doc[] = 
"Class: oaResistor, Function: setHeight\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setHeight(oaUInt4 height)\n"
"    Signature: setHeight|void-void|simple-oaUInt4,\n"
"    This function sets the effective height of this resistor to the specified height.\n"
"    height\n"
"    the effective height to set on this oaResistor object\n"
;

static PyObject*
oaResistor_setHeight(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setHeight(p1.Data());
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
static char oaResistor_setLength_doc[] = 
"Class: oaResistor, Function: setLength\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setLength(oaUInt4 length)\n"
"    Signature: setLength|void-void|simple-oaUInt4,\n"
"    This function sets the effective length of this resistor to the specified length.\n"
"    length\n"
"    the effective length to set on this oaResistor object\n"
;

static PyObject*
oaResistor_setLength(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setLength(p1.Data());
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
static char oaResistor_setNumCuts_doc[] = 
"Class: oaResistor, Function: setNumCuts\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setNumCuts(oaUInt4 numCuts)\n"
"    Signature: setNumCuts|void-void|simple-oaUInt4,\n"
"    This function sets the number of cuts of this resistor to the specified value.\n"
"    numCuts\n"
"    the number of cuts to set on this oaResistor object\n"
;

static PyObject*
oaResistor_setNumCuts(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setNumCuts(p1.Data());
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
static char oaResistor_setWidth_doc[] = 
"Class: oaResistor, Function: setWidth\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setWidth(oaUInt4 width)\n"
"    Signature: setWidth|void-void|simple-oaUInt4,\n"
"    This function sets the effective width of this resistor to the specified width.\n"
"    width\n"
"    the effective width to set on this oaResistor object\n"
;

static PyObject*
oaResistor_setWidth(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaResistorObject* self=(PyoaResistorObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setWidth(p1.Data());
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
static char oaResistor_isNull_doc[] =
"Class: oaResistor, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaResistor_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaResistor data;
    int convert_status=PyoaResistor_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaResistor_assign_doc[] = 
"Class: oaResistor, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaResistor_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaResistor data;
  int convert_status=PyoaResistor_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaResistor p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaResistor_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaResistor_methodlist[] = {
    {"getCutArea",(PyCFunction)oaResistor_getCutArea,METH_VARARGS,oaResistor_getCutArea_doc},
    {"getCutPerimeter",(PyCFunction)oaResistor_getCutPerimeter,METH_VARARGS,oaResistor_getCutPerimeter_doc},
    {"getHeight",(PyCFunction)oaResistor_getHeight,METH_VARARGS,oaResistor_getHeight_doc},
    {"getLength",(PyCFunction)oaResistor_getLength,METH_VARARGS,oaResistor_getLength_doc},
    {"getNumCuts",(PyCFunction)oaResistor_getNumCuts,METH_VARARGS,oaResistor_getNumCuts_doc},
    {"getWidth",(PyCFunction)oaResistor_getWidth,METH_VARARGS,oaResistor_getWidth_doc},
    {"hasCutArea",(PyCFunction)oaResistor_hasCutArea,METH_VARARGS,oaResistor_hasCutArea_doc},
    {"hasCutPerimeter",(PyCFunction)oaResistor_hasCutPerimeter,METH_VARARGS,oaResistor_hasCutPerimeter_doc},
    {"hasHeight",(PyCFunction)oaResistor_hasHeight,METH_VARARGS,oaResistor_hasHeight_doc},
    {"hasLength",(PyCFunction)oaResistor_hasLength,METH_VARARGS,oaResistor_hasLength_doc},
    {"hasNumCuts",(PyCFunction)oaResistor_hasNumCuts,METH_VARARGS,oaResistor_hasNumCuts_doc},
    {"hasWidth",(PyCFunction)oaResistor_hasWidth,METH_VARARGS,oaResistor_hasWidth_doc},
    {"setCutArea",(PyCFunction)oaResistor_setCutArea,METH_VARARGS,oaResistor_setCutArea_doc},
    {"setCutPerimeter",(PyCFunction)oaResistor_setCutPerimeter,METH_VARARGS,oaResistor_setCutPerimeter_doc},
    {"setHeight",(PyCFunction)oaResistor_setHeight,METH_VARARGS,oaResistor_setHeight_doc},
    {"setLength",(PyCFunction)oaResistor_setLength,METH_VARARGS,oaResistor_setLength_doc},
    {"setNumCuts",(PyCFunction)oaResistor_setNumCuts,METH_VARARGS,oaResistor_setNumCuts_doc},
    {"setWidth",(PyCFunction)oaResistor_setWidth,METH_VARARGS,oaResistor_setWidth_doc},
    {"isNull",(PyCFunction)oaResistor_tp_isNull,METH_VARARGS,oaResistor_isNull_doc},
    {"assign",(PyCFunction)oaResistor_tp_assign,METH_VARARGS,oaResistor_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaResistor_doc[] = 
"Class: oaResistor\n"
"  The oaResistor class represents a resistor in a parasitic network for a net. Each resistor object has one resistance value for each analysis point that the parasitic network represents.\n"
"Constructors:\n"
"  Paramegers: (oaResistor)\n"
"    Calls: (const oaResistor&)\n"
"    Signature: oaResistor||cref-oaResistor,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaResistor_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaResistor",
    sizeof(PyoaResistorObject),
    0,
    (destructor)oaResistor_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaResistor_tp_compare,	/* tp_compare */
    (reprfunc)oaResistor_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaResistor_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaResistor_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdDevice_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaResistor_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaResistor_static_create_doc[] = 
"Class: oaResistor, Function: create\n"
"  Paramegers: (oaNode,oaNode)\n"
"    Calls: oaResistor* create(oaNode* fromNode,oaNode* toNode)\n"
"    Signature: create|ptr-oaResistor|ptr-oaNode,ptr-oaNode,\n"
"    This function creates a resistor belonging to the specified parasitic network. The device created will not have an ID associated with it. The hasId() function will return false for these devices and the getId() function will return an oacInvalidDeviceID value.\n"
"    Resistors can be created between nodes in different partitions of the same root parasitic network, where one of the partitions must be an ancestor of the other. In this case, the resistor will be created in the lower level partition, and the node in the higher level partition must have an id so that it can be found when loading the lower level partition.\n"
"    fromNode\n"
"    The starting node for the inductor\n"
"    toNode\n"
"    The ending node for the inductor\n"
"    oacNodesNotInSameDesign\n"
"    oacNodesNotInSameNetwork\n"
"    oacNodesNotInRelatedPartitions\n"
"    oacAncestorNodeWithoutId\n"
"  Paramegers: (oaNode,oaNode,oaUInt4)\n"
"    Calls: oaResistor* create(oaNode* fromNode,oaNode* toNode,oaUInt4 id)\n"
"    Signature: create|ptr-oaResistor|ptr-oaNode,ptr-oaNode,simple-oaUInt4,\n"
"    This function creates a resistor belonging to the parasitic network containing fromNode and toNode . An exception will be thrown if the id is the reserved oacInvalidDeviceID value or if a device with the specified id value already exists. The hasId() function will return true for devices created with this function and the getId() function will return the user-specified id.\n"
"    Resistors can be created between nodes in different partitions of the same root parasitic network, where one of the partitions must be an ancestor of the other. In this case, the resistor will be created in the lower level partition, and the node in the higher level partition must have an id so that it can be found when loading the lower level partition.\n"
"    fromNode\n"
"    The starting node for the resistor\n"
"    toNode\n"
"    The ending node for the resistor\n"
"    id\n"
"    The unique ID to be assigned to the resistor created\n"
"    oacInvalidDeviceIdSpecified\n"
"    oacLocalDeviceIdExists\n"
"    oacNodesNotInSameDesign\n"
"    oacNodesNotInSameNetwork\n"
"    oacNodesNotInRelatedPartitions\n"
"    oacAncestorNodeWithoutId\n"
;

static PyObject*
oaResistor_static_create(PyObject* ob, PyObject *args)
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
            oaResistorp result= (oaResistor::create(p1.Data(),p2.Data()));
            return PyoaResistor_FromoaResistor(result);
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
            oaResistorp result= (oaResistor::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaResistor_FromoaResistor(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaResistor, function: create, Choices are:\n"
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
static PyMethodDef oaResistor_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaResistor_static_create,METH_VARARGS,oaResistor_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaResistor_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaResistor_Type)<0) {
      printf("** PyType_Ready failed for: oaResistor\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaResistor",
           (PyObject*)(&PyoaResistor_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaResistor\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaResistor_Type.tp_dict;
    for(method=oaResistor_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaReticle
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaReticle_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaReticle_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaReticleObject* self = (PyoaReticleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaReticle)
    {
        PyParamoaReticle p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaReticle_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaReticle, Choices are:\n"
        "    (oaReticle)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaReticle_tp_dealloc(PyoaReticleObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaReticle_tp_repr(PyObject *ob)
{
    PyParamoaReticle value;
    int convert_status=PyoaReticle_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[31];
    sprintf(buffer,"<oaReticle::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaReticle_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaReticle v1;
    PyParamoaReticle v2;
    int convert_status1=PyoaReticle_Convert(ob1,&v1);
    int convert_status2=PyoaReticle_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaReticle_Convert(PyObject* ob,PyParamoaReticle* result)
{
    if (ob == NULL) return 1;
    if (PyoaReticle_Check(ob)) {
        result->SetData( (oaReticle**) ((PyoaReticleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaReticle Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaReticle_FromoaReticle(oaReticle** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaReticle* data=*value;
        PyObject* bself = PyoaReticle_Type.tp_alloc(&PyoaReticle_Type,0);
        if (bself == NULL) return bself;
        PyoaReticleObject* self = (PyoaReticleObject*)bself;
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
PyObject* PyoaReticle_FromoaReticle(oaReticle* data)
{
    if (data) {
       PyObject* bself = PyoaReticle_Type.tp_alloc(&PyoaReticle_Type,0);
       if (bself == NULL) return bself;
       PyoaReticleObject* self = (PyoaReticleObject*)bself;
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
static char oaReticle_destroy_doc[] = 
"Class: oaReticle, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this reticle, removing it from the database.\n"
;

static PyObject*
oaReticle_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticle data;
    int convert_status=PyoaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleObject* self=(PyoaReticleObject*)ob;
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
static char oaReticle_getBoundary_doc[] = 
"Class: oaReticle, Function: getBoundary\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void getBoundary(oaPointArray& boundary) const\n"
"    Signature: getBoundary|void-void|ref-oaPointArray,\n"
"    BrowseData: 0,oaPointArray\n"
"    This function returns the boundary of this reticle in the given boundary oaPointArray .\n"
"    boundary\n"
"    The oaPointArray to return the reticle boundary in\n"
;

static PyObject*
oaReticle_getBoundary(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticle data;
    int convert_status=PyoaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleObject* self=(PyoaReticleObject*)ob;
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
static char oaReticle_getDesignInsts_doc[] = 
"Class: oaReticle, Function: getDesignInsts\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaDesignInst_oaReticle getDesignInsts() const\n"
"    Signature: getDesignInsts|simple-oaCollection_oaDesignInst_oaReticle|\n"
"    BrowseData: 1\n"
"    This function returns the collection of designInsts associated with this reticle.\n"
;

static PyObject*
oaReticle_getDesignInsts(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticle data;
    int convert_status=PyoaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleObject* self=(PyoaReticleObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaDesignInst_oaReticle* result= new oaCollection_oaDesignInst_oaReticle(data.DataCall()->getDesignInsts());
        return PyoaCollection_oaDesignInst_oaReticle_FromoaCollection_oaDesignInst_oaReticle(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaReticle_getDesignInstsIter_doc[] = 
"Class: oaReticle, Function: getDesignInstsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaDesignInst getDesignInstsIter() const\n"
"    Signature: getDesignInstsIter|simple-oaIter_oaDesignInst|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of designInsts associated with this reticle.\n"
;

static PyObject*
oaReticle_getDesignInstsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticle data;
    int convert_status=PyoaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleObject* self=(PyoaReticleObject*)ob;
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
static char oaReticle_getFrameInsts_doc[] = 
"Class: oaReticle, Function: getFrameInsts\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaFrameInst_oaReticle getFrameInsts() const\n"
"    Signature: getFrameInsts|simple-oaCollection_oaFrameInst_oaReticle|\n"
"    BrowseData: 1\n"
"    This function returns the collection of frameInsts associated with this reticle.\n"
;

static PyObject*
oaReticle_getFrameInsts(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticle data;
    int convert_status=PyoaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleObject* self=(PyoaReticleObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaFrameInst_oaReticle* result= new oaCollection_oaFrameInst_oaReticle(data.DataCall()->getFrameInsts());
        return PyoaCollection_oaFrameInst_oaReticle_FromoaCollection_oaFrameInst_oaReticle(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaReticle_getFrameInstsIter_doc[] = 
"Class: oaReticle, Function: getFrameInstsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaFrameInst getFrameInstsIter() const\n"
"    Signature: getFrameInstsIter|simple-oaIter_oaFrameInst|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of frameInsts associated with this reticle.\n"
;

static PyObject*
oaReticle_getFrameInstsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticle data;
    int convert_status=PyoaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleObject* self=(PyoaReticleObject*)ob;
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
static char oaReticle_getImages_doc[] = 
"Class: oaReticle, Function: getImages\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaImage_oaReticle getImages() const\n"
"    Signature: getImages|simple-oaCollection_oaImage_oaReticle|\n"
"    BrowseData: 1\n"
"    This function returns the collection of images associated with this reticle.\n"
;

static PyObject*
oaReticle_getImages(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticle data;
    int convert_status=PyoaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleObject* self=(PyoaReticleObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaImage_oaReticle* result= new oaCollection_oaImage_oaReticle(data.DataCall()->getImages());
        return PyoaCollection_oaImage_oaReticle_FromoaCollection_oaImage_oaReticle(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaReticle_getImagesIter_doc[] = 
"Class: oaReticle, Function: getImagesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaImage getImagesIter() const\n"
"    Signature: getImagesIter|simple-oaIter_oaImage|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of images associated with this reticle.\n"
;

static PyObject*
oaReticle_getImagesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticle data;
    int convert_status=PyoaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleObject* self=(PyoaReticleObject*)ob;
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
static char oaReticle_getName_doc[] = 
"Class: oaReticle, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of this reticle in the given string argument.\n"
"    name\n"
"    The oaString to return the name in\n"
;

static PyObject*
oaReticle_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticle data;
    int convert_status=PyoaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleObject* self=(PyoaReticleObject*)ob;
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
static char oaReticle_getScale_doc[] = 
"Class: oaReticle, Function: getScale\n"
"  Paramegers: ()\n"
"    Calls: oaFloat getScale() const\n"
"    Signature: getScale|simple-oaFloat|\n"
"    BrowseData: 1\n"
"    This function returns the scale factor associated with this reticle.\n"
;

static PyObject*
oaReticle_getScale(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticle data;
    int convert_status=PyoaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleObject* self=(PyoaReticleObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaFloat result= (data.DataCall()->getScale());
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
static char oaReticle_setBoundary_doc[] = 
"Class: oaReticle, Function: setBoundary\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void setBoundary(const oaPointArray& boundary)\n"
"    Signature: setBoundary|void-void|cref-oaPointArray,\n"
"    This function changes the boundary of this reticle to the specified boundary .\n"
"    boundary\n"
"    The oaPointArray that contains the new reticle boundary\n"
;

static PyObject*
oaReticle_setBoundary(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticle data;
    int convert_status=PyoaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleObject* self=(PyoaReticleObject*)ob;
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
static char oaReticle_setName_doc[] = 
"Class: oaReticle, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function sets the name of this reticle to the specified 'name'. An exception is thrown if another reticle already has the specified name.\n"
"    name\n"
"    The new name to give the reticle\n"
;

static PyObject*
oaReticle_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticle data;
    int convert_status=PyoaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleObject* self=(PyoaReticleObject*)ob;
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
static char oaReticle_setScale_doc[] = 
"Class: oaReticle, Function: setScale\n"
"  Paramegers: (oaFloat)\n"
"    Calls: void setScale(oaFloat scale)\n"
"    Signature: setScale|void-void|simple-oaFloat,\n"
"    This function changes the scale of this reticle to the specified scale.\n"
"    scale\n"
"    The new scale factor to give the reticle\n"
;

static PyObject*
oaReticle_setScale(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticle data;
    int convert_status=PyoaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleObject* self=(PyoaReticleObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaFloat p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaFloat_Convert,&p1)) {
        data.DataCall()->setScale(p1.Data());
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
static char oaReticle_isNull_doc[] =
"Class: oaReticle, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaReticle_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaReticle data;
    int convert_status=PyoaReticle_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaReticle_assign_doc[] = 
"Class: oaReticle, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaReticle_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaReticle data;
  int convert_status=PyoaReticle_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaReticle p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaReticle_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaReticle_methodlist[] = {
    {"destroy",(PyCFunction)oaReticle_destroy,METH_VARARGS,oaReticle_destroy_doc},
    {"getBoundary",(PyCFunction)oaReticle_getBoundary,METH_VARARGS,oaReticle_getBoundary_doc},
    {"getDesignInsts",(PyCFunction)oaReticle_getDesignInsts,METH_VARARGS,oaReticle_getDesignInsts_doc},
    {"getDesignInstsIter",(PyCFunction)oaReticle_getDesignInstsIter,METH_VARARGS,oaReticle_getDesignInstsIter_doc},
    {"getFrameInsts",(PyCFunction)oaReticle_getFrameInsts,METH_VARARGS,oaReticle_getFrameInsts_doc},
    {"getFrameInstsIter",(PyCFunction)oaReticle_getFrameInstsIter,METH_VARARGS,oaReticle_getFrameInstsIter_doc},
    {"getImages",(PyCFunction)oaReticle_getImages,METH_VARARGS,oaReticle_getImages_doc},
    {"getImagesIter",(PyCFunction)oaReticle_getImagesIter,METH_VARARGS,oaReticle_getImagesIter_doc},
    {"getName",(PyCFunction)oaReticle_getName,METH_VARARGS,oaReticle_getName_doc},
    {"getScale",(PyCFunction)oaReticle_getScale,METH_VARARGS,oaReticle_getScale_doc},
    {"setBoundary",(PyCFunction)oaReticle_setBoundary,METH_VARARGS,oaReticle_setBoundary_doc},
    {"setName",(PyCFunction)oaReticle_setName,METH_VARARGS,oaReticle_setName_doc},
    {"setScale",(PyCFunction)oaReticle_setScale,METH_VARARGS,oaReticle_setScale_doc},
    {"isNull",(PyCFunction)oaReticle_tp_isNull,METH_VARARGS,oaReticle_isNull_doc},
    {"assign",(PyCFunction)oaReticle_tp_assign,METH_VARARGS,oaReticle_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaReticle_doc[] = 
"Class: oaReticle\n"
"  The oaReticle class defines a structure that would be etched onto a silicon wafer during lithographic processing. The oaReticle was a boundary in which to fit the structure and a scale factor for the structure features. The structure may be defined by instances of designs (layouts) and instances of frames for more complicated structures.\n"
"  An oaReticle has a polygonal boundary. Two coincident and three collinear points are illegal, and if detected, cause an exception to be thrown. You can use oaPointArray::compress() to remove these combinations.\n"
"  The oaReticle class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaReticle)\n"
"    Calls: (const oaReticle&)\n"
"    Signature: oaReticle||cref-oaReticle,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaReticle_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaReticle",
    sizeof(PyoaReticleObject),
    0,
    (destructor)oaReticle_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaReticle_tp_compare,	/* tp_compare */
    (reprfunc)oaReticle_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaReticle_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaReticle_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaWaferObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaReticle_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaReticle_static_create_doc[] = 
"Class: oaReticle, Function: create\n"
"  Paramegers: (oaWafer,oaString,oaFloat,oaPointArray)\n"
"    Calls: oaReticle* create(oaWafer* wafer,const oaString& name,oaFloat scale,const oaPointArray& boundary)\n"
"    Signature: create|ptr-oaReticle|ptr-oaWafer,cref-oaString,simple-oaFloat,cref-oaPointArray,\n"
"    This function creates a reticle in the specified wafer with the given name and attributes. The specified boundary is checked to verify that there are at least three points and no collinear or coincident points. This function throws an exception if a reticle with the specified name already exists in the wafer.\n"
"    wafer\n"
"    The wafer in which to create the reticle\n"
"    name\n"
"    The name of the reticle to create\n"
"    scale\n"
"    The scale factor to apply to objects in the reticle\n"
"    boundary\n"
"    A pointArray specifying the reticle boundary\n"
;

static PyObject*
oaReticle_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    PyParamoaString p2;
    PyParamoaFloat p3;
    PyParamoaPointArray p4;
    if (PyArg_ParseTuple(args,"O&O&O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaString_Convert,&p2,
          &PyoaFloat_Convert,&p3,
          &PyoaPointArray_Convert,&p4)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaReticlep result= (oaReticle::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
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
static char oaReticle_static_find_doc[] = 
"Class: oaReticle, Function: find\n"
"  Paramegers: (oaWafer,oaString)\n"
"    Calls: oaReticle* find(const oaWafer* wafer,const oaString& name)\n"
"    Signature: find|ptr-oaReticle|cptr-oaWafer,cref-oaString,\n"
"    This function searches the specified wafer for a reticle with the specified name. The function returns the reticle if found. Otherwise, NULL is returned.\n"
"    wafer\n"
"    The wafer to search for the reticle\n"
"    name\n"
"    The name of the reticle to find\n"
;

static PyObject*
oaReticle_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaReticlep result= (oaReticle::find(p1.Data(),p2.Data()));
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
static PyMethodDef oaReticle_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaReticle_static_create,METH_VARARGS,oaReticle_static_create_doc},
    {"static_find",(PyCFunction)oaReticle_static_find,METH_VARARGS,oaReticle_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaReticle_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaReticle_Type)<0) {
      printf("** PyType_Ready failed for: oaReticle\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaReticle",
           (PyObject*)(&PyoaReticle_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaReticle\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaReticle_Type.tp_dict;
    for(method=oaReticle_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaReticleModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaReticleModTypeEnum_Convert(PyObject* ob,PyParamoaReticleModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetNameReticleModType")==0) { result->SetData(oacSetNameReticleModType); return 1;}
        if (strcasecmp(str,"oacSetScaleReticleModType")==0) { result->SetData(oacSetScaleReticleModType); return 1;}
        if (strcasecmp(str,"oacSetBoundaryReticleModType")==0) { result->SetData(oacSetBoundaryReticleModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaReticleModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaReticleModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaReticleModTypeEnum_FromoaReticleModTypeEnum(oaReticleModTypeEnum ob)
{
    if (ob==oacSetNameReticleModType) return PyString_FromString("oacSetNameReticleModType");
    if (ob==oacSetScaleReticleModType) return PyString_FromString("oacSetScaleReticleModType");
    if (ob==oacSetBoundaryReticleModType) return PyString_FromString("oacSetBoundaryReticleModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaReticleModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaReticleModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaReticleModTypeEnum_FromoaReticleModTypeEnum(oaReticleModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaReticleModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaReticleModTypeEnum_doc[] =
"Type convert function for enum: oaReticleModTypeEnum";
                               
static PyMethodDef PyoaReticleModTypeEnum_method =
  {"oaReticleModTypeEnum",(PyCFunction)PyoaReticleModTypeEnum_TypeFunction,METH_VARARGS,oaReticleModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaReticleModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetNameReticleModType");
    PyDict_SetItemString(mod_dict,"oacSetNameReticleModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetScaleReticleModType");
    PyDict_SetItemString(mod_dict,"oacSetScaleReticleModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetBoundaryReticleModType");
    PyDict_SetItemString(mod_dict,"oacSetBoundaryReticleModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaReticleModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaReticleModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaReticleModTypeEnum\n");
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
// Wrapper Implementation for Class: oaReticleRef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaReticleRef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaReticleRef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaReticleRefObject* self = (PyoaReticleRefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaReticleRef)
    {
        PyParamoaReticleRef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaReticleRef_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaReticleRef, Choices are:\n"
        "    (oaReticleRef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaReticleRef_tp_dealloc(PyoaReticleRefObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaReticleRef_tp_repr(PyObject *ob)
{
    PyParamoaReticleRef value;
    int convert_status=PyoaReticleRef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[34];
    sprintf(buffer,"<oaReticleRef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaReticleRef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaReticleRef v1;
    PyParamoaReticleRef v2;
    int convert_status1=PyoaReticleRef_Convert(ob1,&v1);
    int convert_status2=PyoaReticleRef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaReticleRef_Convert(PyObject* ob,PyParamoaReticleRef* result)
{
    if (ob == NULL) return 1;
    if (PyoaReticleRef_Check(ob)) {
        result->SetData( (oaReticleRef**) ((PyoaReticleRefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaReticleRef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaReticleRef_FromoaReticleRef(oaReticleRef** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaReticleRef* data=*value;
        PyObject* bself = PyoaReticleRef_Type.tp_alloc(&PyoaReticleRef_Type,0);
        if (bself == NULL) return bself;
        PyoaReticleRefObject* self = (PyoaReticleRefObject*)bself;
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
PyObject* PyoaReticleRef_FromoaReticleRef(oaReticleRef* data)
{
    if (data) {
       PyObject* bself = PyoaReticleRef_Type.tp_alloc(&PyoaReticleRef_Type,0);
       if (bself == NULL) return bself;
       PyoaReticleRefObject* self = (PyoaReticleRefObject*)bself;
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
static char oaReticleRef_destroy_doc[] = 
"Class: oaReticleRef, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this reticleRef, removing it from the database.\n"
;

static PyObject*
oaReticleRef_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticleRef data;
    int convert_status=PyoaReticleRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleRefObject* self=(PyoaReticleRefObject*)ob;
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
static char oaReticleRef_getCellName_doc[] = 
"Class: oaReticleRef, Function: getCellName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getCellName(oaScalarName& name) const\n"
"    Signature: getCellName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the cell name for the reticle associated with this reticleRef in the specified name.\n"
"    name\n"
"    The returned cell name\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getCellName(const oaNameSpace& ns,oaString& name) const\n"
"    Signature: getCellName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the cell name for the reticle associated with this reticleRef in the namespace specified.\n"
"    nameSpace\n"
"    The name space in which to return the name.\n"
"    name\n"
"    The returned cell name\n"
;

static PyObject*
oaReticleRef_getCellName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticleRef data;
    int convert_status=PyoaReticleRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleRefObject* self=(PyoaReticleRefObject*)ob;
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
        "No Arg-Matching Function found for class: oaReticleRef, function: getCellName, Choices are:\n"
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
static char oaReticleRef_getImages_doc[] = 
"Class: oaReticleRef, Function: getImages\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaImage_oaReticleRef getImages() const\n"
"    Signature: getImages|simple-oaCollection_oaImage_oaReticleRef|\n"
"    BrowseData: 1\n"
"    This function returns the collection of images associated with this reticle reference object.\n"
;

static PyObject*
oaReticleRef_getImages(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticleRef data;
    int convert_status=PyoaReticleRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleRefObject* self=(PyoaReticleRefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaImage_oaReticleRef* result= new oaCollection_oaImage_oaReticleRef(data.DataCall()->getImages());
        return PyoaCollection_oaImage_oaReticleRef_FromoaCollection_oaImage_oaReticleRef(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaReticleRef_getImagesIter_doc[] = 
"Class: oaReticleRef, Function: getImagesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaImage getImagesIter() const\n"
"    Signature: getImagesIter|simple-oaIter_oaImage|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of images associated with this reticle reference object.\n"
;

static PyObject*
oaReticleRef_getImagesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticleRef data;
    int convert_status=PyoaReticleRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleRefObject* self=(PyoaReticleRefObject*)ob;
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
static char oaReticleRef_getLibName_doc[] = 
"Class: oaReticleRef, Function: getLibName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getLibName(oaScalarName& name) const\n"
"    Signature: getLibName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the library name for the reticle associated with this reticleRef in the specified name.\n"
"    name\n"
"    The returned library name\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getLibName(const oaNameSpace& ns,oaString& name) const\n"
"    Signature: getLibName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the library name for the reticle associated with this reticleRef in the namespace specified.\n"
"    nameSpace\n"
"    The name space in which to return the name.\n"
"    name\n"
"    The returned library name\n"
;

static PyObject*
oaReticleRef_getLibName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticleRef data;
    int convert_status=PyoaReticleRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleRefObject* self=(PyoaReticleRefObject*)ob;
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
        "No Arg-Matching Function found for class: oaReticleRef, function: getLibName, Choices are:\n"
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
static char oaReticleRef_getReticleName_doc[] = 
"Class: oaReticleRef, Function: getReticleName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getReticleName(oaString& name) const\n"
"    Signature: getReticleName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of the reticle referenced by this reticleRef.\n"
"    name\n"
"    The returned reticle name\n"
;

static PyObject*
oaReticleRef_getReticleName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticleRef data;
    int convert_status=PyoaReticleRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleRefObject* self=(PyoaReticleRefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getReticleName(p1.Data());
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
static char oaReticleRef_getViewName_doc[] = 
"Class: oaReticleRef, Function: getViewName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getViewName(oaScalarName& name) const\n"
"    Signature: getViewName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the view name for the reticle associated with this reticleRef in the specified name.\n"
"    name\n"
"    The returned view name\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getViewName(const oaNameSpace& ns,oaString& name) const\n"
"    Signature: getViewName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the view name for the reticle associated with this reticleRef in the namespace specified.\n"
"    &nameSpace\n"
"    The name space in which to return the name.\n"
"    name\n"
"    The returned view name\n"
;

static PyObject*
oaReticleRef_getViewName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticleRef data;
    int convert_status=PyoaReticleRef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleRefObject* self=(PyoaReticleRefObject*)ob;
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
        "No Arg-Matching Function found for class: oaReticleRef, function: getViewName, Choices are:\n"
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
static char oaReticleRef_isNull_doc[] =
"Class: oaReticleRef, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaReticleRef_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaReticleRef data;
    int convert_status=PyoaReticleRef_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaReticleRef_assign_doc[] = 
"Class: oaReticleRef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaReticleRef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaReticleRef data;
  int convert_status=PyoaReticleRef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaReticleRef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaReticleRef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaReticleRef_methodlist[] = {
    {"destroy",(PyCFunction)oaReticleRef_destroy,METH_VARARGS,oaReticleRef_destroy_doc},
    {"getCellName",(PyCFunction)oaReticleRef_getCellName,METH_VARARGS,oaReticleRef_getCellName_doc},
    {"getImages",(PyCFunction)oaReticleRef_getImages,METH_VARARGS,oaReticleRef_getImages_doc},
    {"getImagesIter",(PyCFunction)oaReticleRef_getImagesIter,METH_VARARGS,oaReticleRef_getImagesIter_doc},
    {"getLibName",(PyCFunction)oaReticleRef_getLibName,METH_VARARGS,oaReticleRef_getLibName_doc},
    {"getReticleName",(PyCFunction)oaReticleRef_getReticleName,METH_VARARGS,oaReticleRef_getReticleName_doc},
    {"getViewName",(PyCFunction)oaReticleRef_getViewName,METH_VARARGS,oaReticleRef_getViewName_doc},
    {"isNull",(PyCFunction)oaReticleRef_tp_isNull,METH_VARARGS,oaReticleRef_isNull_doc},
    {"assign",(PyCFunction)oaReticleRef_tp_assign,METH_VARARGS,oaReticleRef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaReticleRef_doc[] = 
"Class: oaReticleRef\n"
"  The oaReticleRef class defines a reference to an oaReticle object in a different wafer database.\n"
"  The oaReticleRef class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaReticleRef)\n"
"    Calls: (const oaReticleRef&)\n"
"    Signature: oaReticleRef||cref-oaReticleRef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaReticleRef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaReticleRef",
    sizeof(PyoaReticleRefObject),
    0,
    (destructor)oaReticleRef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaReticleRef_tp_compare,	/* tp_compare */
    (reprfunc)oaReticleRef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaReticleRef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaReticleRef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaWaferObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaReticleRef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaReticleRef_static_create_doc[] = 
"Class: oaReticleRef, Function: create\n"
"  Paramegers: (oaWafer,oaString,oaScalarName,oaScalarName,oaScalarName)\n"
"    Calls: oaReticleRef* create(oaWafer* wafer,const oaString& reticleName,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName)\n"
"    Signature: create|ptr-oaReticleRef|ptr-oaWafer,cref-oaString,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,\n"
"    This function creates a reticleRef in the specified wafer with the given attributes. The reticleName specifies the name of the reticle in the wafer database with the specified library, cell, and view names. This function throws an exception if a reticleRef with the reticle name already exists in the wafer.\n"
"    wafer\n"
"    The wafer database in which to create the reticleRef.\n"
"    reticleName\n"
"    The name of the referenced reticle\n"
"    libName\n"
"    The library name of the wafer database containing the reticle\n"
"    cellName\n"
"    The cell name of the wafer database containing the reticle\n"
"    viewName\n"
"    The view name of the wafer database containing the reticle\n"
"    oacReticleRefAlreadyExists\n"
;

static PyObject*
oaReticleRef_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    PyParamoaString p2;
    PyParamoaScalarName p3;
    PyParamoaScalarName p4;
    PyParamoaScalarName p5;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaString_Convert,&p2,
          &PyoaScalarName_Convert,&p3,
          &PyoaScalarName_Convert,&p4,
          &PyoaScalarName_Convert,&p5)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaReticleRefp result= (oaReticleRef::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
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
static char oaReticleRef_static_find_doc[] = 
"Class: oaReticleRef, Function: find\n"
"  Paramegers: (oaWafer,oaString,oaScalarName,oaScalarName,oaScalarName)\n"
"    Calls: oaReticleRef* find(const oaWafer* wafer,const oaString& reticleName,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName)\n"
"    Signature: find|ptr-oaReticleRef|cptr-oaWafer,cref-oaString,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,\n"
"    This function searches the wafer for a reticle reference that has the given reticle name.\n"
"    wafer\n"
"    The wafer to search for the reticle\n"
"    reticleName\n"
"    The name of the reticle to find\n"
"    libName\n"
"    The library name of the wafer database containing the reticle\n"
"    cellName\n"
"    The cell name of the wafer database containing the reticle\n"
"    viewName\n"
"    The view name of the wafer database containing the reticle\n"
;

static PyObject*
oaReticleRef_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    PyParamoaString p2;
    PyParamoaScalarName p3;
    PyParamoaScalarName p4;
    PyParamoaScalarName p5;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaString_Convert,&p2,
          &PyoaScalarName_Convert,&p3,
          &PyoaScalarName_Convert,&p4,
          &PyoaScalarName_Convert,&p5)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaReticleRefp result= (oaReticleRef::find(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
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
static PyMethodDef oaReticleRef_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaReticleRef_static_create,METH_VARARGS,oaReticleRef_static_create_doc},
    {"static_find",(PyCFunction)oaReticleRef_static_find,METH_VARARGS,oaReticleRef_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaReticleRef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaReticleRef_Type)<0) {
      printf("** PyType_Ready failed for: oaReticleRef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaReticleRef",
           (PyObject*)(&PyoaReticleRef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaReticleRef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaReticleRef_Type.tp_dict;
    for(method=oaReticleRef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaReticleRefModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaReticleRefModTypeEnum_Convert(PyObject* ob,PyParamoaReticleRefModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetNameReticleRefModType")==0) { result->SetData(oacSetNameReticleRefModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaReticleRefModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaReticleRefModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaReticleRefModTypeEnum_FromoaReticleRefModTypeEnum(oaReticleRefModTypeEnum ob)
{
    if (ob==oacSetNameReticleRefModType) return PyString_FromString("oacSetNameReticleRefModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaReticleRefModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaReticleRefModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaReticleRefModTypeEnum_FromoaReticleRefModTypeEnum(oaReticleRefModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaReticleRefModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaReticleRefModTypeEnum_doc[] =
"Type convert function for enum: oaReticleRefModTypeEnum";
                               
static PyMethodDef PyoaReticleRefModTypeEnum_method =
  {"oaReticleRefModTypeEnum",(PyCFunction)PyoaReticleRefModTypeEnum_TypeFunction,METH_VARARGS,oaReticleRefModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaReticleRefModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetNameReticleRefModType");
    PyDict_SetItemString(mod_dict,"oacSetNameReticleRefModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaReticleRefModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaReticleRefModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaReticleRefModTypeEnum\n");
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
// Wrapper Implementation for Class: oaReticleUsage
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaReticleUsage_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaReticleUsage_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaReticleUsageObject* self = (PyoaReticleUsageObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaReticleUsageEnum)
    {
        PyParamoaReticleUsageEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaReticleUsageEnum_Convert,&p1)) {
            self->value =  new oaReticleUsage(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaReticleUsage(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaReticleUsage)
    {
        PyParamoaReticleUsage p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaReticleUsage_Convert,&p1)) {
            self->value= new oaReticleUsage(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaReticleUsage, Choices are:\n"
        "    (oaReticleUsageEnum)\n"
        "    (oaString)\n"
        "    (oaReticleUsage)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaReticleUsage_tp_dealloc(PyoaReticleUsageObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaReticleUsage_tp_repr(PyObject *ob)
{
    PyParamoaReticleUsage value;
    int convert_status=PyoaReticleUsage_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[36];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaReticleUsage::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaReticleUsage_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaReticleUsage v1;
    PyParamoaReticleUsage v2;
    int convert_status1=PyoaReticleUsage_Convert(ob1,&v1);
    int convert_status2=PyoaReticleUsage_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaReticleUsage_Convert(PyObject* ob,PyParamoaReticleUsage* result)
{
    if (ob == NULL) return 1;
    if (PyoaReticleUsage_Check(ob)) {
        result->SetData(  ((PyoaReticleUsageObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaReticleUsage Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaReticleUsage_FromoaReticleUsage(oaReticleUsage* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaReticleUsage_Type.tp_alloc(&PyoaReticleUsage_Type,0);
        if (bself == NULL) return bself;
        PyoaReticleUsageObject* self = (PyoaReticleUsageObject*)bself;
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
static char oaReticleUsage_getName_doc[] = 
"Class: oaReticleUsage, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name of this reticle usage.\n"
;

static PyObject*
oaReticleUsage_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticleUsage data;
    int convert_status=PyoaReticleUsage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleUsageObject* self=(PyoaReticleUsageObject*)ob;

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
static char oaReticleUsage_oaReticleUsageEnum_doc[] = 
"Class: oaReticleUsage, Function: oaReticleUsageEnum\n"
"  Paramegers: ()\n"
"    Calls: oaReticleUsageEnum oaReticleUsageEnum() const\n"
"    Signature: operator oaReticleUsageEnum|simple-oaReticleUsageEnum|\n"
"    BrowseData: 1\n"
"    This function returns the enum value corresponding to this reticle usage.\n"
;

static PyObject*
oaReticleUsage_oaReticleUsageEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaReticleUsage data;
    int convert_status=PyoaReticleUsage_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaReticleUsageObject* self=(PyoaReticleUsageObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaReticleUsageEnum result= (data.DataCall()->operator oaReticleUsageEnum());
        return PyoaReticleUsageEnum_FromoaReticleUsageEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaReticleUsage_assign_doc[] = 
"Class: oaReticleUsage, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaReticleUsage_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaReticleUsage data;
  int convert_status=PyoaReticleUsage_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaReticleUsage p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaReticleUsage_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaReticleUsage_methodlist[] = {
    {"getName",(PyCFunction)oaReticleUsage_getName,METH_VARARGS,oaReticleUsage_getName_doc},
    {"oaReticleUsageEnum",(PyCFunction)oaReticleUsage_oaReticleUsageEnum,METH_VARARGS,oaReticleUsage_oaReticleUsageEnum_doc},
    {"assign",(PyCFunction)oaReticleUsage_tp_assign,METH_VARARGS,oaReticleUsage_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaReticleUsage_doc[] = 
"Class: oaReticleUsage\n"
"  The oaReticleUsage class is an enum wrapper for the values that describe the reticle usage for the oaDesignInst .\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaReticleUsageEnum\n"
"Constructors:\n"
"  Paramegers: (oaReticleUsageEnum)\n"
"    Calls: oaReticleUsage(oaReticleUsageEnum valueIn)\n"
"    Signature: oaReticleUsage||simple-oaReticleUsageEnum,\n"
"    This is a constructor for the oaReticleUsage class enum wrapper.\n"
"    valueIn\n"
"  Paramegers: (oaString)\n"
"    Calls: oaReticleUsage(const oaString& name)\n"
"    Signature: oaReticleUsage||cref-oaString,\n"
"    This is a constructor for the oaReticleUsage class enum wrapper.\n"
"    name\n"
"    oacInvalidReticleUsageName\n"
"  Paramegers: (oaReticleUsage)\n"
"    Calls: (const oaReticleUsage&)\n"
"    Signature: oaReticleUsage||cref-oaReticleUsage,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaReticleUsage_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaReticleUsage",
    sizeof(PyoaReticleUsageObject),
    0,
    (destructor)oaReticleUsage_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaReticleUsage_tp_compare,	/* tp_compare */
    (reprfunc)oaReticleUsage_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaReticleUsage_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaReticleUsage_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaReticleUsage_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaReticleUsage_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaReticleUsage_Type)<0) {
      printf("** PyType_Ready failed for: oaReticleUsage\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaReticleUsage",
           (PyObject*)(&PyoaReticleUsage_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaReticleUsage\n");
       return -1;
    }
    return 0;
}

