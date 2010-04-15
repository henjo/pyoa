
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaReticleUsageEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaReticleUsageEnum_Convert(PyObject* ob,PyParamoaReticleUsageEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacDieReticleUsage")==0) { result->SetData(oacDieReticleUsage); return 1;}
        if (strcasecmp(str,"oacAlignmentReticleUsage")==0) { result->SetData(oacAlignmentReticleUsage); return 1;}
        if (strcasecmp(str,"oacBarCodeReticleUsage")==0) { result->SetData(oacBarCodeReticleUsage); return 1;}
        if (strcasecmp(str,"oacIdentificationReticleUsage")==0) { result->SetData(oacIdentificationReticleUsage); return 1;}
        if (strcasecmp(str,"oacDieSealReticleUsage")==0) { result->SetData(oacDieSealReticleUsage); return 1;}
        if (strcasecmp(str,"oacDieNumberReticleUsage")==0) { result->SetData(oacDieNumberReticleUsage); return 1;}
        if (strcasecmp(str,"oacLogoReticleUsage")==0) { result->SetData(oacLogoReticleUsage); return 1;}
        if (strcasecmp(str,"oacElectricalReticleUsage")==0) { result->SetData(oacElectricalReticleUsage); return 1;}
        if (strcasecmp(str,"oacOpticalReticleUsage")==0) { result->SetData(oacOpticalReticleUsage); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaReticleUsageEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaReticleUsageEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaReticleUsageEnum_FromoaReticleUsageEnum(oaReticleUsageEnum ob)
{
    if (ob==oacDieReticleUsage) return PyString_FromString("oacDieReticleUsage");
    if (ob==oacAlignmentReticleUsage) return PyString_FromString("oacAlignmentReticleUsage");
    if (ob==oacBarCodeReticleUsage) return PyString_FromString("oacBarCodeReticleUsage");
    if (ob==oacIdentificationReticleUsage) return PyString_FromString("oacIdentificationReticleUsage");
    if (ob==oacDieSealReticleUsage) return PyString_FromString("oacDieSealReticleUsage");
    if (ob==oacDieNumberReticleUsage) return PyString_FromString("oacDieNumberReticleUsage");
    if (ob==oacLogoReticleUsage) return PyString_FromString("oacLogoReticleUsage");
    if (ob==oacElectricalReticleUsage) return PyString_FromString("oacElectricalReticleUsage");
    if (ob==oacOpticalReticleUsage) return PyString_FromString("oacOpticalReticleUsage");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaReticleUsageEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaReticleUsageEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaReticleUsageEnum_FromoaReticleUsageEnum(oaReticleUsageEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaReticleUsageEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaReticleUsageEnum_doc[] =
"Type convert function for enum: oaReticleUsageEnum";
                               
static PyMethodDef PyoaReticleUsageEnum_method =
  {"oaReticleUsageEnum",(PyCFunction)PyoaReticleUsageEnum_TypeFunction,METH_VARARGS,oaReticleUsageEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaReticleUsageEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacDieReticleUsage");
    PyDict_SetItemString(mod_dict,"oacDieReticleUsage",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAlignmentReticleUsage");
    PyDict_SetItemString(mod_dict,"oacAlignmentReticleUsage",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBarCodeReticleUsage");
    PyDict_SetItemString(mod_dict,"oacBarCodeReticleUsage",value);
    Py_DECREF(value);
    value=PyString_FromString("oacIdentificationReticleUsage");
    PyDict_SetItemString(mod_dict,"oacIdentificationReticleUsage",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDieSealReticleUsage");
    PyDict_SetItemString(mod_dict,"oacDieSealReticleUsage",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDieNumberReticleUsage");
    PyDict_SetItemString(mod_dict,"oacDieNumberReticleUsage",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLogoReticleUsage");
    PyDict_SetItemString(mod_dict,"oacLogoReticleUsage",value);
    Py_DECREF(value);
    value=PyString_FromString("oacElectricalReticleUsage");
    PyDict_SetItemString(mod_dict,"oacElectricalReticleUsage",value);
    Py_DECREF(value);
    value=PyString_FromString("oacOpticalReticleUsage");
    PyDict_SetItemString(mod_dict,"oacOpticalReticleUsage",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaReticleUsageEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaReticleUsageEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaReticleUsageEnum\n");
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
// Wrapper Implementation for Class: oaRoute
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRoute_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRoute_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRouteObject* self = (PyoaRouteObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaRoute)
    {
        PyParamoaRoute p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaRoute_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaRoute, Choices are:\n"
        "    (oaRoute)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRoute_tp_dealloc(PyoaRouteObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRoute_tp_repr(PyObject *ob)
{
    PyParamoaRoute value;
    int convert_status=PyoaRoute_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[29];
    sprintf(buffer,"<oaRoute::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRoute_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRoute v1;
    PyParamoaRoute v2;
    int convert_status1=PyoaRoute_Convert(ob1,&v1);
    int convert_status2=PyoaRoute_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRoute_Convert(PyObject* ob,PyParamoaRoute* result)
{
    if (ob == NULL) return 1;
    if (PyoaRoute_Check(ob)) {
        result->SetData( (oaRoute**) ((PyoaRouteObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRoute Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRoute_FromoaRoute(oaRoute** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaRoute* data=*value;
        PyObject* bself = PyoaRoute_Type.tp_alloc(&PyoaRoute_Type,0);
        if (bself == NULL) return bself;
        PyoaRouteObject* self = (PyoaRouteObject*)bself;
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
PyObject* PyoaRoute_FromoaRoute(oaRoute* data)
{
    if (data) {
       PyObject* bself = PyoaRoute_Type.tp_alloc(&PyoaRoute_Type,0);
       if (bself == NULL) return bself;
       PyoaRouteObject* self = (PyoaRouteObject*)bself;
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
static char oaRoute_destroyObjects_doc[] = 
"Class: oaRoute, Function: destroyObjects\n"
"  Paramegers: ()\n"
"    Calls: void destroyObjects()\n"
"    Signature: destroyObjects|void-void|\n"
"    BrowseData: 0\n"
"    oaRoute::destroyObjects\n"
"    This function first disassociates this route from all of its objects and then destroys all the objects that were part of it.\n"
;

static PyObject*
oaRoute_destroyObjects(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->destroyObjects();
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRoute_getBeginConn_doc[] = 
"Class: oaRoute, Function: getBeginConn\n"
"  Paramegers: ()\n"
"    Calls: oaBlockObject* getBeginConn() const\n"
"    Signature: getBeginConn|ptr-oaBlockObject|\n"
"    BrowseData: 1\n"
"    oaRoute::getBeginConn\n"
"    This function returns the beginning connection object of this route. If this route does not have a beginning connection object, NULL is returned.\n"
"    A beginning connection object may be an oaTerm , oaInstTerm , oaSteiner , oaPin , oaShape or oaVia .\n"
;

static PyObject*
oaRoute_getBeginConn(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBlockObjectp result= (data.DataCall()->getBeginConn());
        return PyoaBlockObject_FromoaBlockObject(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRoute_getDefaultConstraintGroup_doc[] = 
"Class: oaRoute, Function: getDefaultConstraintGroup\n"
"  Paramegers: ()\n"
"    Calls: oaConstraintGroup* getDefaultConstraintGroup() const\n"
"    Signature: getDefaultConstraintGroup|ptr-oaConstraintGroup|\n"
"    BrowseData: 1\n"
"    This function returns the constraint group for this route. If no constraints exist on the route, a new constraint group is created.\n"
"    Todo\n"
"    Check function description\n"
;

static PyObject*
oaRoute_getDefaultConstraintGroup(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
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
static char oaRoute_getEndConn_doc[] = 
"Class: oaRoute, Function: getEndConn\n"
"  Paramegers: ()\n"
"    Calls: oaBlockObject* getEndConn() const\n"
"    Signature: getEndConn|ptr-oaBlockObject|\n"
"    BrowseData: 1\n"
"    oaRoute::getEndConn\n"
"    This function returns the end connection object of this route. If this route does not have a end connection object, NULL is returned.\n"
"    An end connection object may be an oaTerm , oaInstTerm , oaSteiner , oaPin , oaShape or oaVia .\n"
;

static PyObject*
oaRoute_getEndConn(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBlockObjectp result= (data.DataCall()->getEndConn());
        return PyoaBlockObject_FromoaBlockObject(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRoute_getNumObjects_doc[] = 
"Class: oaRoute, Function: getNumObjects\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumObjects() const\n"
"    Signature: getNumObjects|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of objects that this route contains.\n"
;

static PyObject*
oaRoute_getNumObjects(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumObjects());
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
static char oaRoute_getObjects_doc[] = 
"Class: oaRoute, Function: getObjects\n"
"  Paramegers: (oaRouteObjectArray)\n"
"    Calls: void getObjects(oaRouteObjectArray& objects) const\n"
"    Signature: getObjects|void-void|ref-oaRouteObjectArray,\n"
"    BrowseData: 0,oaRouteObjectArray\n"
"    oaRoute::getObjects\n"
"    This function retrieves the ordered set of objects associated with this route and returns them via the specified 'objects' array.\n"
"    objects\n"
"    A reference to an oaRouteObjectArray object to be populated\n"
;

static PyObject*
oaRoute_getObjects(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaRouteObjectArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRouteObjectArray_Convert,&p1)) {
        data.DataCall()->getObjects(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRoute_getRouteStatus_doc[] = 
"Class: oaRoute, Function: getRouteStatus\n"
"  Paramegers: ()\n"
"    Calls: oaRouteStatus getRouteStatus() const\n"
"    Signature: getRouteStatus|simple-oaRouteStatus|\n"
"    BrowseData: 1\n"
"    oaRoute::getRouteStatus\n"
"    This function returns the route status of this route.\n"
;

static PyObject*
oaRoute_getRouteStatus(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaRouteStatus* result= new oaRouteStatus(data.DataCall()->getRouteStatus());
        return PyoaRouteStatus_FromoaRouteStatus(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRoute_hasDefaultConstraintGroup_doc[] = 
"Class: oaRoute, Function: hasDefaultConstraintGroup\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasDefaultConstraintGroup() const\n"
"    Signature: hasDefaultConstraintGroup|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether there are constraints associated with this route. Constraints in this constraint group apply to the objects in the oaRoute's oaRouteArray, namely its oaPathSegs, oaVias, and oaGuides.\n"
"    Todo\n"
"    Check function description\n"
;

static PyObject*
oaRoute_hasDefaultConstraintGroup(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
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
static char oaRoute_hasGuide_doc[] = 
"Class: oaRoute, Function: hasGuide\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasGuide() const\n"
"    Signature: hasGuide|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    oaRoute::hasGuide\n"
"    This function returns a boolean indicating whether or not this route has one or more guides in it.\n"
;

static PyObject*
oaRoute_hasGuide(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->hasGuide());
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
static char oaRoute_isContiguous_doc[] = 
"Class: oaRoute, Function: isContiguous\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isContiguous() const\n"
"    Signature: isContiguous|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    oaRoute::isContiguous\n"
"    This function returns a Boolean value indicating whether all objects in the route, which may be oaPathSegs, oaVias and/or oaGuides, are contiguous. Since a route can span multiple layers, the contiguity of a route is determined on the basis of the points at which each adjacent object connects to the next and the layer where each connection is made.\n"
"    Specifically, this function returns true if the end point of each object matches the begin point of the next object on the route and if the layers of objects at their connection points match.\n"
"    Note that this function returns true for single-object routes or zero-object (empty) routes.\n"
"    For vias, the via origin is both the begin and end point. The layer usage depends on the via direction set on the via (see oaVia::setDirection ). For example, if the direction is set to oacLayer1ToLayer2ViaDirection, the via's layer1 must match the element before the Via and its layer2 must match the element after it. This function returns false for vias that are not bound to a viaDef.\n"
"    For guides, if the begin/end layer has not been specified, this function assumes that the guide begin/end layer matches any layer specified for the adjacent object.\n"
;

static PyObject*
oaRoute_isContiguous(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isContiguous());
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
static char oaRoute_isGlobal_doc[] = 
"Class: oaRoute, Function: isGlobal\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isGlobal() const\n"
"    Signature: isGlobal|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    oaRoute::isGlobal\n"
"    This function returns true if this is a global route, false otherwise.\n"
;

static PyObject*
oaRoute_isGlobal(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isGlobal());
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
static char oaRoute_setBeginConn_doc[] = 
"Class: oaRoute, Function: setBeginConn\n"
"  Paramegers: (oaBlockObject)\n"
"    Calls: void setBeginConn(oaBlockObject* object)\n"
"    Signature: setBeginConn|void-void|ptr-oaBlockObject,\n"
"    oaRoute::setBeginConn\n"
"    This function sets the beginning connection object of this route to the specified object . If this route already has a beginning connection object, it is disconnected first.\n"
"    A beginning connection object may be an oaTerm , oaInstTerm , oaSteiner , oaPin , oaShape or oaVia .\n"
"    object\n"
"    The object to be connected to the begin of this route.\n"
"    oacInvalidRouteConnObj\n"
"    oacRouteAndConnNotInSameBlock\n"
"    oacCannotSetRouteObjAsRouteConn\n"
;

static PyObject*
oaRoute_setBeginConn(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBlockObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBlockObject_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setBeginConn(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRoute_setEndConn_doc[] = 
"Class: oaRoute, Function: setEndConn\n"
"  Paramegers: (oaBlockObject)\n"
"    Calls: void setEndConn(oaBlockObject* object)\n"
"    Signature: setEndConn|void-void|ptr-oaBlockObject,\n"
"    oaRoute::setEndConn\n"
"    This function sets the end connection object of this route to the specified object. If this route already has a end connection object, it is disconnected first.\n"
"    An end connection object may be an oaTerm , oaInstTerm , oaSteiner , oaPin , oaShape or oaVia .\n"
"    object\n"
"    The object to be connected to the end of this route.\n"
"    oacInvalidRouteConnObj\n"
"    oacRouteAndConnNotInSameBlock\n"
"    oacCannotSetRouteObjAsRouteConn\n"
;

static PyObject*
oaRoute_setEndConn(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBlockObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBlockObject_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setEndConn(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRoute_setGlobal_doc[] = 
"Class: oaRoute, Function: setGlobal\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: void setGlobal(oaBoolean global)\n"
"    Signature: setGlobal|void-void|simple-oaBoolean,\n"
"    oaRoute::setGlobal\n"
"    This function sets the global attribute of this route to the specified value.\n"
;

static PyObject*
oaRoute_setGlobal(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBoolean p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBoolean_Convert,&p1)) {
        data.DataCall()->setGlobal(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRoute_setObjects_doc[] = 
"Class: oaRoute, Function: setObjects\n"
"  Paramegers: (oaRouteObjectArray)\n"
"    Calls: void setObjects(const oaRouteObjectArray& objects)\n"
"    Signature: setObjects|void-void|cref-oaRouteObjectArray,\n"
"    oaRoute::setObjects\n"
"    This function sets the objects of this route to the specified objects. If the route had any existing objects, they are removed from the route first. If the route is connected to a net, each object in the new set of route objects is effectively considered to be on that net. Only pathSegs, vias and guides are qualified to become a route object and they need to be in the same block as the route. A pathSeg or via that implements a pin is disqualified to be a route object. A pathSeg or via that is currently acting as a route connecting object also cannot become part of a route. If both the route and the object being added to it are connected to a net, the net needs to be the same. Also, the set of objects specified to be added to the route should be unique.\n"
"    objects\n"
"    A reference to an oaRouteObjectArray object holding the new set of objects for this route\n"
"    oacObjectNotValidForRoute\n"
"    oacRouteAndObjectNotInSameBlock\n"
"    oacCannotAddPinFigToRoute\n"
"    oacCannotAddRouteConnFigToRoute\n"
"    oacCannotAddFigToRouteOnDifferentNet\n"
"    oacCannotAddSameFigToRouteAgain\n"
;

static PyObject*
oaRoute_setObjects(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaRouteObjectArray p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRouteObjectArray_Convert,&p1)) {
        data.DataCall()->setObjects(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRoute_setRouteStatus_doc[] = 
"Class: oaRoute, Function: setRouteStatus\n"
"  Paramegers: (oaRouteStatus)\n"
"    Calls: void setRouteStatus(const oaRouteStatus& routeStatus)\n"
"    Signature: setRouteStatus|void-void|cref-oaRouteStatus,\n"
"    oaRoute::setRouteStatus\n"
"    This function sets the route status attribute of this route to the specified value.\n"
;

static PyObject*
oaRoute_setRouteStatus(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaRouteStatus p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRouteStatus_Convert,&p1)) {
        data.DataCall()->setRouteStatus(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRoute_unsetBeginConn_doc[] = 
"Class: oaRoute, Function: unsetBeginConn\n"
"  Paramegers: ()\n"
"    Calls: void unsetBeginConn()\n"
"    Signature: unsetBeginConn|void-void|\n"
"    BrowseData: 0\n"
"    oaRoute::unsetBeginConn\n"
"    This function attempts to disconnect this route from its beginning connection object. If this route does not have a beginning connection object, this function does nothing.\n"
;

static PyObject*
oaRoute_unsetBeginConn(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->unsetBeginConn();
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRoute_unsetEndConn_doc[] = 
"Class: oaRoute, Function: unsetEndConn\n"
"  Paramegers: ()\n"
"    Calls: void unsetEndConn()\n"
"    Signature: unsetEndConn|void-void|\n"
"    BrowseData: 0\n"
"    oaRoute::unsetEndConn\n"
"    This function disconnects this route from its end connection object. If this route does not have a end connection object, this function does nothing.\n"
;

static PyObject*
oaRoute_unsetEndConn(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->unsetEndConn();
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRoute_unsetObjects_doc[] = 
"Class: oaRoute, Function: unsetObjects\n"
"  Paramegers: ()\n"
"    Calls: void unsetObjects()\n"
"    Signature: unsetObjects|void-void|\n"
"    BrowseData: 0\n"
"    oaRoute::unsetObjects\n"
"    This function disassociates this route from all of its objects. If the route was connected to a net, the disassociated objects acquire the route's net as part of disassociation process.\n"
;

static PyObject*
oaRoute_unsetObjects(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteObject* self=(PyoaRouteObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->unsetObjects();
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRoute_isNull_doc[] =
"Class: oaRoute, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaRoute_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaRoute data;
    int convert_status=PyoaRoute_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaRoute_assign_doc[] = 
"Class: oaRoute, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRoute_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRoute data;
  int convert_status=PyoaRoute_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRoute p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRoute_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRoute_methodlist[] = {
    {"destroyObjects",(PyCFunction)oaRoute_destroyObjects,METH_VARARGS,oaRoute_destroyObjects_doc},
    {"getBeginConn",(PyCFunction)oaRoute_getBeginConn,METH_VARARGS,oaRoute_getBeginConn_doc},
    {"getDefaultConstraintGroup",(PyCFunction)oaRoute_getDefaultConstraintGroup,METH_VARARGS,oaRoute_getDefaultConstraintGroup_doc},
    {"getEndConn",(PyCFunction)oaRoute_getEndConn,METH_VARARGS,oaRoute_getEndConn_doc},
    {"getNumObjects",(PyCFunction)oaRoute_getNumObjects,METH_VARARGS,oaRoute_getNumObjects_doc},
    {"getObjects",(PyCFunction)oaRoute_getObjects,METH_VARARGS,oaRoute_getObjects_doc},
    {"getRouteStatus",(PyCFunction)oaRoute_getRouteStatus,METH_VARARGS,oaRoute_getRouteStatus_doc},
    {"hasDefaultConstraintGroup",(PyCFunction)oaRoute_hasDefaultConstraintGroup,METH_VARARGS,oaRoute_hasDefaultConstraintGroup_doc},
    {"hasGuide",(PyCFunction)oaRoute_hasGuide,METH_VARARGS,oaRoute_hasGuide_doc},
    {"isContiguous",(PyCFunction)oaRoute_isContiguous,METH_VARARGS,oaRoute_isContiguous_doc},
    {"isGlobal",(PyCFunction)oaRoute_isGlobal,METH_VARARGS,oaRoute_isGlobal_doc},
    {"setBeginConn",(PyCFunction)oaRoute_setBeginConn,METH_VARARGS,oaRoute_setBeginConn_doc},
    {"setEndConn",(PyCFunction)oaRoute_setEndConn,METH_VARARGS,oaRoute_setEndConn_doc},
    {"setGlobal",(PyCFunction)oaRoute_setGlobal,METH_VARARGS,oaRoute_setGlobal_doc},
    {"setObjects",(PyCFunction)oaRoute_setObjects,METH_VARARGS,oaRoute_setObjects_doc},
    {"setRouteStatus",(PyCFunction)oaRoute_setRouteStatus,METH_VARARGS,oaRoute_setRouteStatus_doc},
    {"unsetBeginConn",(PyCFunction)oaRoute_unsetBeginConn,METH_VARARGS,oaRoute_unsetBeginConn_doc},
    {"unsetEndConn",(PyCFunction)oaRoute_unsetEndConn,METH_VARARGS,oaRoute_unsetEndConn_doc},
    {"unsetObjects",(PyCFunction)oaRoute_unsetObjects,METH_VARARGS,oaRoute_unsetObjects_doc},
    {"isNull",(PyCFunction)oaRoute_tp_isNull,METH_VARARGS,oaRoute_isNull_doc},
    {"assign",(PyCFunction)oaRoute_tp_assign,METH_VARARGS,oaRoute_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRoute_doc[] = 
"Class: oaRoute\n"
"  The oaRoute class represents a physical point-to-point connection that is part of a wire. An oaRoute contains a sequence of objects that may describe both the routing segments on given layers and the vias between those layers. An oaRoute (Route) may contain segments on multiple layers, but a Route may not branch.\n"
"  Routes are used to represent the symbolic routing used by high capacity routers. They specify end-point connected routes that also indicate the objects they connect. Other routing may be geometric, which often is used for power and ground nets and other hand crafted nets. Geometric routing is defined with oaShapes and oaVias directly connected to their net without the use of an oaRoute.\n"
"  Routes can either represent global routes or detailed routes. Global routes are approximate routes that are routed through a sequence of Gcell grid locations. Detailed routes express the complete route geometry with the exact coordinates of each segment and via.\n"
"  The objects in a Route may be instances of oaPathSeg , oaVia , and oaGuide . These objects are created separately from the Route and then are added to the Route. Callers can set or retrieve the elements of a Route using an oaRouteObjectArray .\n"
"  Routes may specify the two objects that they connect. These BeginConn and EndConn objects must be one of:\n"
"  An oaTerm , oaInstTerm or oaPin to which the route connects\n"
"  An oaSteiner where the Route ends (where the net branches)\n"
"  An oaShape or oaVia that is part of geometric routing\n"
"  Routes should be constructed so that the end points and layers of each object match those of the adjacent object. The database checks this status with the isContiguous member function.\n"
"  Routes may have a default oaConstraintGroup associated with them that specifies the rules that the router follows when the oaRoute is constructed. Routing rules can be in the default constraint group of the route itself, or routing rules can be on the oNet, oaBlock , or oaDesign to which the Route belongs. Routing rules can also be in the default constraint group of the oaBoundary that contains the oaRoute.\n"
"  A design may satisfy a connection on a net by abutment, where no additional wire is needed because the pins to be connected overlap. In this case the design should indicate that the connection is fully routed by creating an empty route. In the case that there are abutted pins and also additional routing on the net, this means there should be two empty routes (for the two abutted pins) that connect to a steiner. An additional non-empty route would also connect to that steiner.\n"
"  The oaRoute class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaRoute)\n"
"    Calls: (const oaRoute&)\n"
"    Signature: oaRoute||cref-oaRoute,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRoute_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRoute",
    sizeof(PyoaRouteObject),
    0,
    (destructor)oaRoute_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRoute_tp_compare,	/* tp_compare */
    (reprfunc)oaRoute_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRoute_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRoute_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConnFig_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRoute_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRoute_static_create_doc[] = 
"Class: oaRoute, Function: create\n"
"  Paramegers: (oaBlock)\n"
"    Calls: oaRoute* create(oaBlock* block)\n"
"    Signature: create|ptr-oaRoute|ptr-oaBlock,ptr-oaNet,simple-oaBoolean,simple-oaRouteStatus,\n"
"    oaRoute::create\n"
"    This function creates a route with the specified attributes.\n"
"    An exception is thrown if a net is specified but it is from a different block than the one specified.\n"
"    block\n"
"    The block in which the route is to be created\n"
"    net\n"
"    The net to which the route may be attached\n"
"    isGlobal\n"
"    A boolean indicating whether it should be a global route\n"
"    stat\n"
"    The initial routing status to be assigned to the new route\n"
"    oacNetFigNotInSameBlock\n"
"  Paramegers: (oaBlock,oaNet)\n"
"    Calls: oaRoute* create(oaBlock* block,oaNet* net)\n"
"    Signature: create|ptr-oaRoute|ptr-oaBlock,ptr-oaNet,simple-oaBoolean,simple-oaRouteStatus,\n"
"    oaRoute::create\n"
"    This function creates a route with the specified attributes.\n"
"    An exception is thrown if a net is specified but it is from a different block than the one specified.\n"
"    block\n"
"    The block in which the route is to be created\n"
"    net\n"
"    The net to which the route may be attached\n"
"    isGlobal\n"
"    A boolean indicating whether it should be a global route\n"
"    stat\n"
"    The initial routing status to be assigned to the new route\n"
"    oacNetFigNotInSameBlock\n"
"  Paramegers: (oaBlock,oaNet,oaBoolean)\n"
"    Calls: oaRoute* create(oaBlock* block,oaNet* net,oaBoolean isGlobal)\n"
"    Signature: create|ptr-oaRoute|ptr-oaBlock,ptr-oaNet,simple-oaBoolean,simple-oaRouteStatus,\n"
"    oaRoute::create\n"
"    This function creates a route with the specified attributes.\n"
"    An exception is thrown if a net is specified but it is from a different block than the one specified.\n"
"    block\n"
"    The block in which the route is to be created\n"
"    net\n"
"    The net to which the route may be attached\n"
"    isGlobal\n"
"    A boolean indicating whether it should be a global route\n"
"    stat\n"
"    The initial routing status to be assigned to the new route\n"
"    oacNetFigNotInSameBlock\n"
"  Paramegers: (oaBlock,oaNet,oaBoolean,oaRouteStatus)\n"
"    Calls: oaRoute* create(oaBlock* block,oaNet* net,oaBoolean isGlobal,oaRouteStatus stat)\n"
"    Signature: create|ptr-oaRoute|ptr-oaBlock,ptr-oaNet,simple-oaBoolean,simple-oaRouteStatus,\n"
"    oaRoute::create\n"
"    This function creates a route with the specified attributes.\n"
"    An exception is thrown if a net is specified but it is from a different block than the one specified.\n"
"    block\n"
"    The block in which the route is to be created\n"
"    net\n"
"    The net to which the route may be attached\n"
"    isGlobal\n"
"    A boolean indicating whether it should be a global route\n"
"    stat\n"
"    The initial routing status to be assigned to the new route\n"
"    oacNetFigNotInSameBlock\n"
;

static PyObject*
oaRoute_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaBlock)
    {
        PyParamoaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBlock_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaRoutep result= (oaRoute::create(p1.Data()));
            return PyoaRoute_FromoaRoute(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaNet)
    {
        PyParamoaBlock p1;
        PyParamoaNet p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaNet_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaRoutep result= (oaRoute::create(p1.Data(),p2.Data()));
            return PyoaRoute_FromoaRoute(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaNet,oaBoolean)
    {
        PyParamoaBlock p1;
        PyParamoaNet p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaNet_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaRoutep result= (oaRoute::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaRoute_FromoaRoute(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaNet,oaBoolean,oaRouteStatus)
    {
        PyParamoaBlock p1;
        PyParamoaNet p2;
        PyParamoaBoolean p3;
        PyParamoaRouteStatus p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaNet_Convert,&p2,
              &PyoaBoolean_Convert,&p3,
              &PyoaRouteStatus_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaRoutep result= (oaRoute::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaRoute_FromoaRoute(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaRoute, function: create, Choices are:\n"
        "    (oaBlock)\n"
        "    (oaBlock,oaNet)\n"
        "    (oaBlock,oaNet,oaBoolean)\n"
        "    (oaBlock,oaNet,oaBoolean,oaRouteStatus)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaRoute_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaRoute_static_create,METH_VARARGS,oaRoute_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRoute_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRoute_Type)<0) {
      printf("** PyType_Ready failed for: oaRoute\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRoute",
           (PyObject*)(&PyoaRoute_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRoute\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaRoute_Type.tp_dict;
    for(method=oaRoute_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaRouteMethod
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRouteMethod_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRouteMethod_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRouteMethodObject* self = (PyoaRouteMethodObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaRouteMethodEnum)
    {
        PyParamoaRouteMethodEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaRouteMethodEnum_Convert,&p1)) {
            self->value =  new oaRouteMethod(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaRouteMethod(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaRouteMethod)
    {
        PyParamoaRouteMethod p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaRouteMethod_Convert,&p1)) {
            self->value= new oaRouteMethod(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaRouteMethod, Choices are:\n"
        "    (oaRouteMethodEnum)\n"
        "    (oaString)\n"
        "    (oaRouteMethod)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRouteMethod_tp_dealloc(PyoaRouteMethodObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRouteMethod_tp_repr(PyObject *ob)
{
    PyParamoaRouteMethod value;
    int convert_status=PyoaRouteMethod_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[35];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaRouteMethod::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRouteMethod_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRouteMethod v1;
    PyParamoaRouteMethod v2;
    int convert_status1=PyoaRouteMethod_Convert(ob1,&v1);
    int convert_status2=PyoaRouteMethod_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRouteMethod_Convert(PyObject* ob,PyParamoaRouteMethod* result)
{
    if (ob == NULL) return 1;
    if (PyoaRouteMethod_Check(ob)) {
        result->SetData(  ((PyoaRouteMethodObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRouteMethod Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRouteMethod_FromoaRouteMethod(oaRouteMethod* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaRouteMethod_Type.tp_alloc(&PyoaRouteMethod_Type,0);
        if (bself == NULL) return bself;
        PyoaRouteMethodObject* self = (PyoaRouteMethodObject*)bself;
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
static char oaRouteMethod_getName_doc[] = 
"Class: oaRouteMethod, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName()\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaRouteMethodEnum object.\n"
;

static PyObject*
oaRouteMethod_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRouteMethod data;
    int convert_status=PyoaRouteMethod_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteMethodObject* self=(PyoaRouteMethodObject*)ob;

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
static char oaRouteMethod_oaRouteMethodEnum_doc[] = 
"Class: oaRouteMethod, Function: oaRouteMethodEnum\n"
"  Paramegers: ()\n"
"    Calls: oaRouteMethodEnum oaRouteMethodEnum() const\n"
"    Signature: operator oaRouteMethodEnum|simple-oaRouteMethodEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaRouteMethod object into the corresponding #oaRouteMethodEnum value.\n"
;

static PyObject*
oaRouteMethod_oaRouteMethodEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRouteMethod data;
    int convert_status=PyoaRouteMethod_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteMethodObject* self=(PyoaRouteMethodObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaRouteMethodEnum result= (data.DataCall()->operator oaRouteMethodEnum());
        return PyoaRouteMethodEnum_FromoaRouteMethodEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaRouteMethod_assign_doc[] = 
"Class: oaRouteMethod, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRouteMethod_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRouteMethod data;
  int convert_status=PyoaRouteMethod_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRouteMethod p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRouteMethod_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRouteMethod_methodlist[] = {
    {"getName",(PyCFunction)oaRouteMethod_getName,METH_VARARGS,oaRouteMethod_getName_doc},
    {"oaRouteMethodEnum",(PyCFunction)oaRouteMethod_oaRouteMethodEnum,METH_VARARGS,oaRouteMethod_oaRouteMethodEnum_doc},
    {"assign",(PyCFunction)oaRouteMethod_tp_assign,METH_VARARGS,oaRouteMethod_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRouteMethod_doc[] = 
"Class: oaRouteMethod\n"
"  The oaRouteMethod class is an enum wrapper that describes the different styles of routing that may be done to a given oaTerm or oaInstTerm . This may be used to control which router is used to route the connection. See oaBitTerm::getRouteMethod and oaInstTerm::getRouteMethod for its usage.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaRouteMethodEnum\n"
"Constructors:\n"
"  Paramegers: (oaRouteMethodEnum)\n"
"    Calls: oaRouteMethod(oaRouteMethodEnum valueIn)\n"
"    Signature: oaRouteMethod||simple-oaRouteMethodEnum,\n"
"    This function constructs an instance of an oaRouteMethod class using the specified #oaRouteMethodEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaRouteMethod(const oaString& name)\n"
"    Signature: oaRouteMethod||cref-oaString,\n"
"    This function constructs an instance of an oaRouteMethod class using the #oaRouteMethodEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaRouteMethodEnum.\n"
"    oacInvalidRouteMethodName\n"
"  Paramegers: (oaRouteMethod)\n"
"    Calls: (const oaRouteMethod&)\n"
"    Signature: oaRouteMethod||cref-oaRouteMethod,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRouteMethod_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRouteMethod",
    sizeof(PyoaRouteMethodObject),
    0,
    (destructor)oaRouteMethod_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRouteMethod_tp_compare,	/* tp_compare */
    (reprfunc)oaRouteMethod_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRouteMethod_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRouteMethod_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRouteMethod_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRouteMethod_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRouteMethod_Type)<0) {
      printf("** PyType_Ready failed for: oaRouteMethod\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRouteMethod",
           (PyObject*)(&PyoaRouteMethod_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRouteMethod\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaRouteMethodEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaRouteMethodEnum_Convert(PyObject* ob,PyParamoaRouteMethodEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacGeometricRouteMethod")==0) { result->SetData(oacGeometricRouteMethod); return 1;}
        if (strcasecmp(str,"oacSymbolicRouteMethod")==0) { result->SetData(oacSymbolicRouteMethod); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaRouteMethodEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRouteMethodEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaRouteMethodEnum_FromoaRouteMethodEnum(oaRouteMethodEnum ob)
{
    if (ob==oacGeometricRouteMethod) return PyString_FromString("oacGeometricRouteMethod");
    if (ob==oacSymbolicRouteMethod) return PyString_FromString("oacSymbolicRouteMethod");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaRouteMethodEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaRouteMethodEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaRouteMethodEnum_FromoaRouteMethodEnum(oaRouteMethodEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaRouteMethodEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaRouteMethodEnum_doc[] =
"Type convert function for enum: oaRouteMethodEnum";
                               
static PyMethodDef PyoaRouteMethodEnum_method =
  {"oaRouteMethodEnum",(PyCFunction)PyoaRouteMethodEnum_TypeFunction,METH_VARARGS,oaRouteMethodEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaRouteMethodEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacGeometricRouteMethod");
    PyDict_SetItemString(mod_dict,"oacGeometricRouteMethod",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSymbolicRouteMethod");
    PyDict_SetItemString(mod_dict,"oacSymbolicRouteMethod",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaRouteMethodEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaRouteMethodEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaRouteMethodEnum\n");
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
// Wrapper Implementation for Class: oaRouteModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaRouteModTypeEnum_Convert(PyObject* ob,PyParamoaRouteModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetStatusRouteModType")==0) { result->SetData(oacSetStatusRouteModType); return 1;}
        if (strcasecmp(str,"oacSetBeginConnRouteModType")==0) { result->SetData(oacSetBeginConnRouteModType); return 1;}
        if (strcasecmp(str,"oacSetEndConnRouteModType")==0) { result->SetData(oacSetEndConnRouteModType); return 1;}
        if (strcasecmp(str,"oacUnsetBeginConnRouteModType")==0) { result->SetData(oacUnsetBeginConnRouteModType); return 1;}
        if (strcasecmp(str,"oacUnsetEndConnRouteModType")==0) { result->SetData(oacUnsetEndConnRouteModType); return 1;}
        if (strcasecmp(str,"oacAddToNetRouteModType")==0) { result->SetData(oacAddToNetRouteModType); return 1;}
        if (strcasecmp(str,"oacRemoveFromNetRouteModType")==0) { result->SetData(oacRemoveFromNetRouteModType); return 1;}
        if (strcasecmp(str,"oacSetTopologyRouteModType")==0) { result->SetData(oacSetTopologyRouteModType); return 1;}
        if (strcasecmp(str,"oacSetGlobalRouteModType")==0) { result->SetData(oacSetGlobalRouteModType); return 1;}
        if (strcasecmp(str,"oacMoveRouteModType")==0) { result->SetData(oacMoveRouteModType); return 1;}
        if (strcasecmp(str,"oacSetObjectsRouteModType")==0) { result->SetData(oacSetObjectsRouteModType); return 1;}
        if (strcasecmp(str,"oacAddToFigGroupRouteModType")==0) { result->SetData(oacAddToFigGroupRouteModType); return 1;}
        if (strcasecmp(str,"oacRemoveFromFigGroupRouteModType")==0) { result->SetData(oacRemoveFromFigGroupRouteModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaRouteModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRouteModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaRouteModTypeEnum_FromoaRouteModTypeEnum(oaRouteModTypeEnum ob)
{
    if (ob==oacSetStatusRouteModType) return PyString_FromString("oacSetStatusRouteModType");
    if (ob==oacSetBeginConnRouteModType) return PyString_FromString("oacSetBeginConnRouteModType");
    if (ob==oacSetEndConnRouteModType) return PyString_FromString("oacSetEndConnRouteModType");
    if (ob==oacUnsetBeginConnRouteModType) return PyString_FromString("oacUnsetBeginConnRouteModType");
    if (ob==oacUnsetEndConnRouteModType) return PyString_FromString("oacUnsetEndConnRouteModType");
    if (ob==oacAddToNetRouteModType) return PyString_FromString("oacAddToNetRouteModType");
    if (ob==oacRemoveFromNetRouteModType) return PyString_FromString("oacRemoveFromNetRouteModType");
    if (ob==oacSetTopologyRouteModType) return PyString_FromString("oacSetTopologyRouteModType");
    if (ob==oacSetGlobalRouteModType) return PyString_FromString("oacSetGlobalRouteModType");
    if (ob==oacMoveRouteModType) return PyString_FromString("oacMoveRouteModType");
    if (ob==oacSetObjectsRouteModType) return PyString_FromString("oacSetObjectsRouteModType");
    if (ob==oacAddToFigGroupRouteModType) return PyString_FromString("oacAddToFigGroupRouteModType");
    if (ob==oacRemoveFromFigGroupRouteModType) return PyString_FromString("oacRemoveFromFigGroupRouteModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaRouteModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaRouteModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaRouteModTypeEnum_FromoaRouteModTypeEnum(oaRouteModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaRouteModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaRouteModTypeEnum_doc[] =
"Type convert function for enum: oaRouteModTypeEnum";
                               
static PyMethodDef PyoaRouteModTypeEnum_method =
  {"oaRouteModTypeEnum",(PyCFunction)PyoaRouteModTypeEnum_TypeFunction,METH_VARARGS,oaRouteModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaRouteModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetStatusRouteModType");
    PyDict_SetItemString(mod_dict,"oacSetStatusRouteModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetBeginConnRouteModType");
    PyDict_SetItemString(mod_dict,"oacSetBeginConnRouteModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetEndConnRouteModType");
    PyDict_SetItemString(mod_dict,"oacSetEndConnRouteModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacUnsetBeginConnRouteModType");
    PyDict_SetItemString(mod_dict,"oacUnsetBeginConnRouteModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacUnsetEndConnRouteModType");
    PyDict_SetItemString(mod_dict,"oacUnsetEndConnRouteModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAddToNetRouteModType");
    PyDict_SetItemString(mod_dict,"oacAddToNetRouteModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRemoveFromNetRouteModType");
    PyDict_SetItemString(mod_dict,"oacRemoveFromNetRouteModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetTopologyRouteModType");
    PyDict_SetItemString(mod_dict,"oacSetTopologyRouteModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetGlobalRouteModType");
    PyDict_SetItemString(mod_dict,"oacSetGlobalRouteModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacMoveRouteModType");
    PyDict_SetItemString(mod_dict,"oacMoveRouteModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetObjectsRouteModType");
    PyDict_SetItemString(mod_dict,"oacSetObjectsRouteModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAddToFigGroupRouteModType");
    PyDict_SetItemString(mod_dict,"oacAddToFigGroupRouteModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRemoveFromFigGroupRouteModType");
    PyDict_SetItemString(mod_dict,"oacRemoveFromFigGroupRouteModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaRouteModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaRouteModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaRouteModTypeEnum\n");
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
// Wrapper Implementation for Class: oaRouteObjectArray
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRouteObjectArray_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRouteObjectArray_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRouteObjectArrayObject* self = (PyoaRouteObjectArrayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaArrayBase_oaFig*)  new oaRouteObjectArray();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->value = (oaArrayBase_oaFig*)  new oaRouteObjectArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaRouteObjectArray)
    {
        PyParamoaRouteObjectArray p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaRouteObjectArray_Convert,&p1)) {
            self->value=(oaArrayBase_oaFig*)  new oaRouteObjectArray(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaRouteObjectArray, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaRouteObjectArray)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRouteObjectArray_tp_dealloc(PyoaRouteObjectArrayObject* self)
{
    if (!self->borrow) {
        delete (oaRouteObjectArray*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRouteObjectArray_tp_repr(PyObject *ob)
{
    PyParamoaRouteObjectArray value;
    int convert_status=PyoaRouteObjectArray_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaRouteObjectArray::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRouteObjectArray_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRouteObjectArray v1;
    PyParamoaRouteObjectArray v2;
    int convert_status1=PyoaRouteObjectArray_Convert(ob1,&v1);
    int convert_status2=PyoaRouteObjectArray_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRouteObjectArray_Convert(PyObject* ob,PyParamoaRouteObjectArray* result)
{
    if (ob == NULL) return 1;
    if (PyoaRouteObjectArray_Check(ob)) {
        result->SetData( (oaRouteObjectArray*) ((PyoaRouteObjectArrayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRouteObjectArray Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRouteObjectArray_FromoaRouteObjectArray(oaRouteObjectArray* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaRouteObjectArray_Type.tp_alloc(&PyoaRouteObjectArray_Type,0);
        if (bself == NULL) return bself;
        PyoaRouteObjectArrayObject* self = (PyoaRouteObjectArrayObject*)bself;
        self->value = (oaArrayBase_oaFig*)  data;
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
static char oaRouteObjectArray_doc[] = 
"Class: oaRouteObjectArray\n"
"  The oaRouteObjectArray class implements an array of objects associated with a route. oaRouteObjectArray objects can be used to populate oaRoute objects or extract the objects of an oaRoute object.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaRouteObjectArray()\n"
"    Signature: oaRouteObjectArray||simple-oaUInt4,\n"
"    This constructor creates an oaRouteObjectArray object with an initial size that can handle the specified 'sizeIn' number of objects.\n"
"    sizeIn\n"
"    The initial size with which the object array will be created\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaRouteObjectArray(oaUInt4 sizeIn)\n"
"    Signature: oaRouteObjectArray||simple-oaUInt4,\n"
"    This constructor creates an oaRouteObjectArray object with an initial size that can handle the specified 'sizeIn' number of objects.\n"
"    sizeIn\n"
"    The initial size with which the object array will be created\n"
"  Paramegers: (oaRouteObjectArray)\n"
"    Calls: (const oaRouteObjectArray&)\n"
"    Signature: oaRouteObjectArray||cref-oaRouteObjectArray,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRouteObjectArray_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRouteObjectArray",
    sizeof(PyoaRouteObjectArrayObject),
    0,
    (destructor)oaRouteObjectArray_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRouteObjectArray_tp_compare,	/* tp_compare */
    (reprfunc)oaRouteObjectArray_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRouteObjectArray_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaArray_oaFig_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRouteObjectArray_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRouteObjectArray_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRouteObjectArray_Type)<0) {
      printf("** PyType_Ready failed for: oaRouteObjectArray\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRouteObjectArray",
           (PyObject*)(&PyoaRouteObjectArray_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRouteObjectArray\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaRouteOptimizer
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRouteOptimizer_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRouteOptimizer_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRouteOptimizerObject* self = (PyoaRouteOptimizerObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaRouteOptimizer();
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaRouteOptimizer, Choices are:\n"
        "    ()\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRouteOptimizer_tp_dealloc(PyoaRouteOptimizerObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRouteOptimizer_tp_repr(PyObject *ob)
{
    PyParamoaRouteOptimizer value;
    int convert_status=PyoaRouteOptimizer_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaRouteOptimizer::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRouteOptimizer_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRouteOptimizer v1;
    PyParamoaRouteOptimizer v2;
    int convert_status1=PyoaRouteOptimizer_Convert(ob1,&v1);
    int convert_status2=PyoaRouteOptimizer_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRouteOptimizer_Convert(PyObject* ob,PyParamoaRouteOptimizer* result)
{
    if (ob == NULL) return 1;
    if (PyoaRouteOptimizer_Check(ob)) {
        result->SetData(  ((PyoaRouteOptimizerObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRouteOptimizer Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRouteOptimizer_FromoaRouteOptimizer(oaRouteOptimizer* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaRouteOptimizer_Type.tp_alloc(&PyoaRouteOptimizer_Type,0);
        if (bself == NULL) return bself;
        PyoaRouteOptimizerObject* self = (PyoaRouteOptimizerObject*)bself;
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
static char oaRouteOptimizer_calcVMSize_doc[] = 
"Class: oaRouteOptimizer, Function: calcVMSize\n"
"  Paramegers: ()\n"
"    Calls: oaUInt8 calcVMSize()\n"
"    Signature: calcVMSize|simple-oaUInt8|\n"
"    BrowseData: 1\n"
"    This function calculates the amount of virtual memory used by the route optimizer object and all of its associated data structures. As a route optimizer object is used, its retained virtual memory grows to the size required to accommodate the largest net with optimized routes. Once the optimization is complete, applications can determine how much memory was used before deleting the route optimization object (the memory is returned to the system when the route optimization object is deleted).\n"
;

static PyObject*
oaRouteOptimizer_calcVMSize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRouteOptimizer data;
    int convert_status=PyoaRouteOptimizer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteOptimizerObject* self=(PyoaRouteOptimizerObject*)ob;

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
static char oaRouteOptimizer_optimize_doc[] = 
"Class: oaRouteOptimizer, Function: optimize\n"
"  Paramegers: (oaNet)\n"
"    Calls: oaBoolean optimize(oaNet* net)\n"
"    Signature: optimize|simple-oaBoolean|ptr-oaNet,simple-oaUInt4,\n"
"    This function optimizes the path segments, routes, shapes, pins, instance terminals, and instance pins on the specified net using the method set by the flags argument. Any path segments or routes that existed before the optimization are deleted and replaced with a minimal set of optimized routes that have their start and end connections properly set.\n"
"    By default, the created routes are symbolic unless the flags are set to GeometricOnly or GeometricDefault and the route segments originated from paths.\n"
"    net\n"
"    The net to optimize\n"
"    flags\n"
"    The route optimizer controls\n"
"    oacROGeometricOnly creates geometric routes regardless of whether the routes meet the specification for a symbolic route. This flag is used primarily when optimizing custom routes.\n"
"    oacROGeometricDefault creates geometric routes for routes without an associated original route or routeSpec. If an associated routeSpec does exist, a symbolic route is created.\n"
"    oacROPreserveGuides preserves any guides (zero-segment routes) that exist when the original route-inspiring objects are deleted. If this flag is omitted, any guides present are deleted along with the original path segments and routes.\n"
"    oacROPreserveSteiners preserves any steiner objects found in the input data (normally, these are discarded and recomputed when necessary). If a Steiner is necessary for optimization and one does not exist at the needed junction point, it is created.\n"
"    oacROPreserveSteinerPins preserves any steiner pin objects found in the input data. A steiner pin has an associated area instead of a single point.\n"
"  Paramegers: (oaNet,oaUInt4)\n"
"    Calls: oaBoolean optimize(oaNet* net,oaUInt4 flags)\n"
"    Signature: optimize|simple-oaBoolean|ptr-oaNet,simple-oaUInt4,\n"
"    This function optimizes the path segments, routes, shapes, pins, instance terminals, and instance pins on the specified net using the method set by the flags argument. Any path segments or routes that existed before the optimization are deleted and replaced with a minimal set of optimized routes that have their start and end connections properly set.\n"
"    By default, the created routes are symbolic unless the flags are set to GeometricOnly or GeometricDefault and the route segments originated from paths.\n"
"    net\n"
"    The net to optimize\n"
"    flags\n"
"    The route optimizer controls\n"
"    oacROGeometricOnly creates geometric routes regardless of whether the routes meet the specification for a symbolic route. This flag is used primarily when optimizing custom routes.\n"
"    oacROGeometricDefault creates geometric routes for routes without an associated original route or routeSpec. If an associated routeSpec does exist, a symbolic route is created.\n"
"    oacROPreserveGuides preserves any guides (zero-segment routes) that exist when the original route-inspiring objects are deleted. If this flag is omitted, any guides present are deleted along with the original path segments and routes.\n"
"    oacROPreserveSteiners preserves any steiner objects found in the input data (normally, these are discarded and recomputed when necessary). If a Steiner is necessary for optimization and one does not exist at the needed junction point, it is created.\n"
"    oacROPreserveSteinerPins preserves any steiner pin objects found in the input data. A steiner pin has an associated area instead of a single point.\n"
"  Paramegers: (oaBlock)\n"
"    Calls: oaBoolean optimize(oaBlock* block)\n"
"    Signature: optimize|simple-oaBoolean|ptr-oaBlock,simple-oaUInt4,\n"
"    This function optimizes each path and route in the specified design using the process specified by the flags argument.\n"
"    By default, the created routes are symbolic unless the flags are set to GeometricOnly or GeometricDefault and the route segments originated from paths.\n"
"    block\n"
"    The block to optimize\n"
"    flags\n"
"    The route optimizer controls\n"
"    oacROGeometricDefault creates geometric routes for routes without an associated original route or routeSpec. If an associated routeSpec does exist, a symbolic route is created.\n"
"    oacROGeometricOnly creates geometric routes regardless of whether the routes meet the specification for a symbolic route. This flag is used primarily when optimizing custom routes.\n"
"    oacROPreserveGuides preserves any guides (zero-segment routes) that exist when the original route-inspiring objects are deleted. If this flag is omitted, any guides present are deleted along with the original path segments and routes.\n"
"    oacROPreserveSteiners preserves any steiner objects found in the input data (normally, these are discarded and recomputed when necessary). If a Steiner is necessary for optimization and one does not exist at the needed junction point, it is created.\n"
"    oacROPreserveSteinerPins preserves any steiner pin objects found in the input data. A steiner pin has an associated area instead of a single point.\n"
"  Paramegers: (oaBlock,oaUInt4)\n"
"    Calls: oaBoolean optimize(oaBlock* block,oaUInt4 flags)\n"
"    Signature: optimize|simple-oaBoolean|ptr-oaBlock,simple-oaUInt4,\n"
"    This function optimizes each path and route in the specified design using the process specified by the flags argument.\n"
"    By default, the created routes are symbolic unless the flags are set to GeometricOnly or GeometricDefault and the route segments originated from paths.\n"
"    block\n"
"    The block to optimize\n"
"    flags\n"
"    The route optimizer controls\n"
"    oacROGeometricDefault creates geometric routes for routes without an associated original route or routeSpec. If an associated routeSpec does exist, a symbolic route is created.\n"
"    oacROGeometricOnly creates geometric routes regardless of whether the routes meet the specification for a symbolic route. This flag is used primarily when optimizing custom routes.\n"
"    oacROPreserveGuides preserves any guides (zero-segment routes) that exist when the original route-inspiring objects are deleted. If this flag is omitted, any guides present are deleted along with the original path segments and routes.\n"
"    oacROPreserveSteiners preserves any steiner objects found in the input data (normally, these are discarded and recomputed when necessary). If a Steiner is necessary for optimization and one does not exist at the needed junction point, it is created.\n"
"    oacROPreserveSteinerPins preserves any steiner pin objects found in the input data. A steiner pin has an associated area instead of a single point.\n"
;

static PyObject*
oaRouteOptimizer_optimize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRouteOptimizer data;
    int convert_status=PyoaRouteOptimizer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteOptimizerObject* self=(PyoaRouteOptimizerObject*)ob;

    // Case: (oaNet)
    {
        PyParamoaNet p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaNet_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaBoolean result= (data.DataCall()->optimize(p1.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaNet,oaUInt4)
    {
        PyParamoaNet p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaNet_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaBoolean result= (data.DataCall()->optimize(p1.Data(),p2.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock)
    {
        PyParamoaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBlock_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaBoolean result= (data.DataCall()->optimize(p1.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaUInt4)
    {
        PyParamoaBlock p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaBoolean result= (data.DataCall()->optimize(p1.Data(),p2.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaRouteOptimizer, function: optimize, Choices are:\n"
        "    (oaNet)\n"
        "    (oaNet,oaUInt4)\n"
        "    (oaBlock)\n"
        "    (oaBlock,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaRouteOptimizer_assign_doc[] = 
"Class: oaRouteOptimizer, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRouteOptimizer_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRouteOptimizer data;
  int convert_status=PyoaRouteOptimizer_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRouteOptimizer p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRouteOptimizer_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRouteOptimizer_methodlist[] = {
    {"calcVMSize",(PyCFunction)oaRouteOptimizer_calcVMSize,METH_VARARGS,oaRouteOptimizer_calcVMSize_doc},
    {"optimize",(PyCFunction)oaRouteOptimizer_optimize,METH_VARARGS,oaRouteOptimizer_optimize_doc},
    {"assign",(PyCFunction)oaRouteOptimizer_tp_assign,METH_VARARGS,oaRouteOptimizer_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRouteOptimizer_doc[] = 
"Class: oaRouteOptimizer\n"
"  The oaRouteOptimizer class optimizes the routes on a net according to the specified control options. This class is typically used to create an oaRouteOptimizer object, use the object to optimize the routes for a large number of nets, and then destroy the object.\n"
"  During optimization, Steiner objects are created and deleted as required. When optimization is complete, the optimized routes cover exactly the same area covered by the original path segments and routes.\n"
"  Generally, routes are joined together and then split where necessary. Divisions can occur at one of these points:\n"
"  a Steiner point (where three or more routes connect)\n"
"  a pin or instance pin\n"
"  a two-route intersection where the two routes have different routeSpecs or different types (symbolic vs. geometric)\n"
"  Connection and division points for route optimization are determined by the shapes found at the top level, plus the pin shapes and instance pin shapes.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaRouteOptimizer()\n"
"    Signature: oaRouteOptimizer||\n"
"    This function constructs the route optimizer object.\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRouteOptimizer_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRouteOptimizer",
    sizeof(PyoaRouteOptimizerObject),
    0,
    (destructor)oaRouteOptimizer_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRouteOptimizer_tp_compare,	/* tp_compare */
    (reprfunc)oaRouteOptimizer_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRouteOptimizer_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRouteOptimizer_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRouteOptimizer_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRouteOptimizer_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRouteOptimizer_Type)<0) {
      printf("** PyType_Ready failed for: oaRouteOptimizer\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRouteOptimizer",
           (PyObject*)(&PyoaRouteOptimizer_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRouteOptimizer\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaRoutePattern
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRoutePattern_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRoutePattern_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRoutePatternObject* self = (PyoaRoutePatternObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaRoutePatternEnum)
    {
        PyParamoaRoutePatternEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaRoutePatternEnum_Convert,&p1)) {
            self->value =  new oaRoutePattern(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaRoutePattern(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaRoutePattern)
    {
        PyParamoaRoutePattern p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaRoutePattern_Convert,&p1)) {
            self->value= new oaRoutePattern(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaRoutePattern, Choices are:\n"
        "    (oaRoutePatternEnum)\n"
        "    (oaString)\n"
        "    (oaRoutePattern)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRoutePattern_tp_dealloc(PyoaRoutePatternObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRoutePattern_tp_repr(PyObject *ob)
{
    PyParamoaRoutePattern value;
    int convert_status=PyoaRoutePattern_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[36];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaRoutePattern::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRoutePattern_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRoutePattern v1;
    PyParamoaRoutePattern v2;
    int convert_status1=PyoaRoutePattern_Convert(ob1,&v1);
    int convert_status2=PyoaRoutePattern_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRoutePattern_Convert(PyObject* ob,PyParamoaRoutePattern* result)
{
    if (ob == NULL) return 1;
    if (PyoaRoutePattern_Check(ob)) {
        result->SetData(  ((PyoaRoutePatternObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRoutePattern Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRoutePattern_FromoaRoutePattern(oaRoutePattern* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaRoutePattern_Type.tp_alloc(&PyoaRoutePattern_Type,0);
        if (bself == NULL) return bself;
        PyoaRoutePatternObject* self = (PyoaRoutePatternObject*)bself;
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
static char oaRoutePattern_getName_doc[] = 
"Class: oaRoutePattern, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaRoutePatternEnum object.\n"
;

static PyObject*
oaRoutePattern_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoutePattern data;
    int convert_status=PyoaRoutePattern_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRoutePatternObject* self=(PyoaRoutePatternObject*)ob;

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
static char oaRoutePattern_oaRoutePatternEnum_doc[] = 
"Class: oaRoutePattern, Function: oaRoutePatternEnum\n"
"  Paramegers: ()\n"
"    Calls: oaRoutePatternEnum oaRoutePatternEnum() const\n"
"    Signature: operator oaRoutePatternEnum|simple-oaRoutePatternEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaRoutePattern object into the corresponding #oaRoutePatternEnum value.\n"
;

static PyObject*
oaRoutePattern_oaRoutePatternEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRoutePattern data;
    int convert_status=PyoaRoutePattern_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRoutePatternObject* self=(PyoaRoutePatternObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaRoutePatternEnum result= (data.DataCall()->operator oaRoutePatternEnum());
        return PyoaRoutePatternEnum_FromoaRoutePatternEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaRoutePattern_assign_doc[] = 
"Class: oaRoutePattern, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRoutePattern_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRoutePattern data;
  int convert_status=PyoaRoutePattern_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRoutePattern p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRoutePattern_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRoutePattern_methodlist[] = {
    {"getName",(PyCFunction)oaRoutePattern_getName,METH_VARARGS,oaRoutePattern_getName_doc},
    {"oaRoutePatternEnum",(PyCFunction)oaRoutePattern_oaRoutePatternEnum,METH_VARARGS,oaRoutePattern_oaRoutePatternEnum_doc},
    {"assign",(PyCFunction)oaRoutePattern_tp_assign,METH_VARARGS,oaRoutePattern_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRoutePattern_doc[] = 
"Class: oaRoutePattern\n"
"  The oaRoutePattern class encapsulates the enumerated values that describe the routing pattern for the associated net.\n"
"  oaRoutePatternEnum\n"
"Constructors:\n"
"  Paramegers: (oaRoutePatternEnum)\n"
"    Calls: oaRoutePattern(oaRoutePatternEnum valueIn)\n"
"    Signature: oaRoutePattern||simple-oaRoutePatternEnum,\n"
"    This function constructs an instance of an oaRoutePattern class using the specified #oaRoutePatternEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaRoutePattern(const oaString& name)\n"
"    Signature: oaRoutePattern||cref-oaString,\n"
"    This function constructs an instance of an oaRoutePattern class using the #oaRoutePatternEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaRoutePatternEnum.\n"
"    oacInvalidRoutePatternTypeName\n"
"  Paramegers: (oaRoutePattern)\n"
"    Calls: (const oaRoutePattern&)\n"
"    Signature: oaRoutePattern||cref-oaRoutePattern,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRoutePattern_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRoutePattern",
    sizeof(PyoaRoutePatternObject),
    0,
    (destructor)oaRoutePattern_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRoutePattern_tp_compare,	/* tp_compare */
    (reprfunc)oaRoutePattern_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRoutePattern_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRoutePattern_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRoutePattern_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRoutePattern_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRoutePattern_Type)<0) {
      printf("** PyType_Ready failed for: oaRoutePattern\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRoutePattern",
           (PyObject*)(&PyoaRoutePattern_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRoutePattern\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaRoutePatternEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaRoutePatternEnum_Convert(PyObject* ob,PyParamoaRoutePatternEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSteinerRoutePattern")==0) { result->SetData(oacSteinerRoutePattern); return 1;}
        if (strcasecmp(str,"oacBalancedRoutePattern")==0) { result->SetData(oacBalancedRoutePattern); return 1;}
        if (strcasecmp(str,"oacTrunkRoutePattern")==0) { result->SetData(oacTrunkRoutePattern); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaRoutePatternEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRoutePatternEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaRoutePatternEnum_FromoaRoutePatternEnum(oaRoutePatternEnum ob)
{
    if (ob==oacSteinerRoutePattern) return PyString_FromString("oacSteinerRoutePattern");
    if (ob==oacBalancedRoutePattern) return PyString_FromString("oacBalancedRoutePattern");
    if (ob==oacTrunkRoutePattern) return PyString_FromString("oacTrunkRoutePattern");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaRoutePatternEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaRoutePatternEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaRoutePatternEnum_FromoaRoutePatternEnum(oaRoutePatternEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaRoutePatternEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaRoutePatternEnum_doc[] =
"Type convert function for enum: oaRoutePatternEnum";
                               
static PyMethodDef PyoaRoutePatternEnum_method =
  {"oaRoutePatternEnum",(PyCFunction)PyoaRoutePatternEnum_TypeFunction,METH_VARARGS,oaRoutePatternEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaRoutePatternEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSteinerRoutePattern");
    PyDict_SetItemString(mod_dict,"oacSteinerRoutePattern",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBalancedRoutePattern");
    PyDict_SetItemString(mod_dict,"oacBalancedRoutePattern",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTrunkRoutePattern");
    PyDict_SetItemString(mod_dict,"oacTrunkRoutePattern",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaRoutePatternEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaRoutePatternEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaRoutePatternEnum\n");
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
// Wrapper Implementation for Class: oaRouteStatus
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRouteStatus_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRouteStatus_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRouteStatusObject* self = (PyoaRouteStatusObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaRouteStatusEnum)
    {
        PyParamoaRouteStatusEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaRouteStatusEnum_Convert,&p1)) {
            self->value =  new oaRouteStatus(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaRouteStatus(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaRouteStatus)
    {
        PyParamoaRouteStatus p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaRouteStatus_Convert,&p1)) {
            self->value= new oaRouteStatus(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaRouteStatus, Choices are:\n"
        "    (oaRouteStatusEnum)\n"
        "    (oaString)\n"
        "    (oaRouteStatus)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRouteStatus_tp_dealloc(PyoaRouteStatusObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRouteStatus_tp_repr(PyObject *ob)
{
    PyParamoaRouteStatus value;
    int convert_status=PyoaRouteStatus_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[35];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaRouteStatus::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRouteStatus_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRouteStatus v1;
    PyParamoaRouteStatus v2;
    int convert_status1=PyoaRouteStatus_Convert(ob1,&v1);
    int convert_status2=PyoaRouteStatus_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRouteStatus_Convert(PyObject* ob,PyParamoaRouteStatus* result)
{
    if (ob == NULL) return 1;
    if (PyoaRouteStatus_Check(ob)) {
        result->SetData(  ((PyoaRouteStatusObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRouteStatus Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRouteStatus_FromoaRouteStatus(oaRouteStatus* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaRouteStatus_Type.tp_alloc(&PyoaRouteStatus_Type,0);
        if (bself == NULL) return bself;
        PyoaRouteStatusObject* self = (PyoaRouteStatusObject*)bself;
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
static char oaRouteStatus_getName_doc[] = 
"Class: oaRouteStatus, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaRouteStatusEnum object.\n"
;

static PyObject*
oaRouteStatus_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRouteStatus data;
    int convert_status=PyoaRouteStatus_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteStatusObject* self=(PyoaRouteStatusObject*)ob;

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
static char oaRouteStatus_oaRouteStatusEnum_doc[] = 
"Class: oaRouteStatus, Function: oaRouteStatusEnum\n"
"  Paramegers: ()\n"
"    Calls: oaRouteStatusEnum oaRouteStatusEnum() const\n"
"    Signature: operator oaRouteStatusEnum|simple-oaRouteStatusEnum|\n"
"    BrowseData: 1\n"
"    This function casts this oaRouteStatus object into the corresponding #oaRouteStatusEnum value.\n"
;

static PyObject*
oaRouteStatus_oaRouteStatusEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRouteStatus data;
    int convert_status=PyoaRouteStatus_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteStatusObject* self=(PyoaRouteStatusObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaRouteStatusEnum result= (data.DataCall()->operator oaRouteStatusEnum());
        return PyoaRouteStatusEnum_FromoaRouteStatusEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaRouteStatus_assign_doc[] = 
"Class: oaRouteStatus, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRouteStatus_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRouteStatus data;
  int convert_status=PyoaRouteStatus_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRouteStatus p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRouteStatus_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRouteStatus_methodlist[] = {
    {"getName",(PyCFunction)oaRouteStatus_getName,METH_VARARGS,oaRouteStatus_getName_doc},
    {"oaRouteStatusEnum",(PyCFunction)oaRouteStatus_oaRouteStatusEnum,METH_VARARGS,oaRouteStatus_oaRouteStatusEnum_doc},
    {"assign",(PyCFunction)oaRouteStatus_tp_assign,METH_VARARGS,oaRouteStatus_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRouteStatus_doc[] = 
"Class: oaRouteStatus\n"
"  The oaRouteStatus class encapsulates the enumerated values that describe the different routing status values\n"
"  oaRouteStatusEnum\n"
"Constructors:\n"
"  Paramegers: (oaRouteStatusEnum)\n"
"    Calls: oaRouteStatus(oaRouteStatusEnum valueIn)\n"
"    Signature: oaRouteStatus||simple-oaRouteStatusEnum,\n"
"    This function constructs an instance of an oaRouteStatus class using the specified #oaRouteStatusEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaRouteStatus(const oaString& name)\n"
"    Signature: oaRouteStatus||cref-oaString,\n"
"    This function constructs an instance of an oaRouteStatus class using the #oaRouteStatusEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaRouteStatusEnum.\n"
"    oacInvalidRouteStatusTypeName\n"
"  Paramegers: (oaRouteStatus)\n"
"    Calls: (const oaRouteStatus&)\n"
"    Signature: oaRouteStatus||cref-oaRouteStatus,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRouteStatus_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRouteStatus",
    sizeof(PyoaRouteStatusObject),
    0,
    (destructor)oaRouteStatus_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRouteStatus_tp_compare,	/* tp_compare */
    (reprfunc)oaRouteStatus_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRouteStatus_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRouteStatus_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRouteStatus_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRouteStatus_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRouteStatus_Type)<0) {
      printf("** PyType_Ready failed for: oaRouteStatus\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRouteStatus",
           (PyObject*)(&PyoaRouteStatus_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRouteStatus\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaRouteStatusEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaRouteStatusEnum_Convert(PyObject* ob,PyParamoaRouteStatusEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacNormalRouteStatus")==0) { result->SetData(oacNormalRouteStatus); return 1;}
        if (strcasecmp(str,"oacFixedRouteStatus")==0) { result->SetData(oacFixedRouteStatus); return 1;}
        if (strcasecmp(str,"oacLockedRouteStatus")==0) { result->SetData(oacLockedRouteStatus); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaRouteStatusEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRouteStatusEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaRouteStatusEnum_FromoaRouteStatusEnum(oaRouteStatusEnum ob)
{
    if (ob==oacNormalRouteStatus) return PyString_FromString("oacNormalRouteStatus");
    if (ob==oacFixedRouteStatus) return PyString_FromString("oacFixedRouteStatus");
    if (ob==oacLockedRouteStatus) return PyString_FromString("oacLockedRouteStatus");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaRouteStatusEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaRouteStatusEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaRouteStatusEnum_FromoaRouteStatusEnum(oaRouteStatusEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaRouteStatusEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaRouteStatusEnum_doc[] =
"Type convert function for enum: oaRouteStatusEnum";
                               
static PyMethodDef PyoaRouteStatusEnum_method =
  {"oaRouteStatusEnum",(PyCFunction)PyoaRouteStatusEnum_TypeFunction,METH_VARARGS,oaRouteStatusEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaRouteStatusEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacNormalRouteStatus");
    PyDict_SetItemString(mod_dict,"oacNormalRouteStatus",value);
    Py_DECREF(value);
    value=PyString_FromString("oacFixedRouteStatus");
    PyDict_SetItemString(mod_dict,"oacFixedRouteStatus",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLockedRouteStatus");
    PyDict_SetItemString(mod_dict,"oacLockedRouteStatus",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaRouteStatusEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaRouteStatusEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaRouteStatusEnum\n");
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
// Wrapper Implementation for Class: oaRouteTopology
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRouteTopology_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRouteTopology_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRouteTopologyObject* self = (PyoaRouteTopologyObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaRouteTopologyEnum)
    {
        PyParamoaRouteTopologyEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaRouteTopologyEnum_Convert,&p1)) {
            self->value =  new oaRouteTopology(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaRouteTopology(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaRouteTopology)
    {
        PyParamoaRouteTopology p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaRouteTopology_Convert,&p1)) {
            self->value= new oaRouteTopology(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaRouteTopology, Choices are:\n"
        "    (oaRouteTopologyEnum)\n"
        "    (oaString)\n"
        "    (oaRouteTopology)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRouteTopology_tp_dealloc(PyoaRouteTopologyObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRouteTopology_tp_repr(PyObject *ob)
{
    PyParamoaRouteTopology value;
    int convert_status=PyoaRouteTopology_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[37];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaRouteTopology::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRouteTopology_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRouteTopology v1;
    PyParamoaRouteTopology v2;
    int convert_status1=PyoaRouteTopology_Convert(ob1,&v1);
    int convert_status2=PyoaRouteTopology_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRouteTopology_Convert(PyObject* ob,PyParamoaRouteTopology* result)
{
    if (ob == NULL) return 1;
    if (PyoaRouteTopology_Check(ob)) {
        result->SetData(  ((PyoaRouteTopologyObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRouteTopology Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRouteTopology_FromoaRouteTopology(oaRouteTopology* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaRouteTopology_Type.tp_alloc(&PyoaRouteTopology_Type,0);
        if (bself == NULL) return bself;
        PyoaRouteTopologyObject* self = (PyoaRouteTopologyObject*)bself;
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
static char oaRouteTopology_getName_doc[] = 
"Class: oaRouteTopology, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaRouteTopologyEnum object.\n"
;

static PyObject*
oaRouteTopology_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRouteTopology data;
    int convert_status=PyoaRouteTopology_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteTopologyObject* self=(PyoaRouteTopologyObject*)ob;

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
static char oaRouteTopology_oaRouteTopologyEnum_doc[] = 
"Class: oaRouteTopology, Function: oaRouteTopologyEnum\n"
"  Paramegers: ()\n"
"    Calls: oaRouteTopologyEnum oaRouteTopologyEnum() const\n"
"    Signature: operator oaRouteTopologyEnum|simple-oaRouteTopologyEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaRouteTopology object into the corresponding #oaRouteTopologyEnum value.\n"
;

static PyObject*
oaRouteTopology_oaRouteTopologyEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRouteTopology data;
    int convert_status=PyoaRouteTopology_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRouteTopologyObject* self=(PyoaRouteTopologyObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaRouteTopologyEnum result= (data.DataCall()->operator oaRouteTopologyEnum());
        return PyoaRouteTopologyEnum_FromoaRouteTopologyEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaRouteTopology_assign_doc[] = 
"Class: oaRouteTopology, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRouteTopology_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRouteTopology data;
  int convert_status=PyoaRouteTopology_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRouteTopology p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRouteTopology_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRouteTopology_methodlist[] = {
    {"getName",(PyCFunction)oaRouteTopology_getName,METH_VARARGS,oaRouteTopology_getName_doc},
    {"oaRouteTopologyEnum",(PyCFunction)oaRouteTopology_oaRouteTopologyEnum,METH_VARARGS,oaRouteTopology_oaRouteTopologyEnum_doc},
    {"assign",(PyCFunction)oaRouteTopology_tp_assign,METH_VARARGS,oaRouteTopology_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRouteTopology_doc[] = 
"Class: oaRouteTopology\n"
"  The oaRouteTopology class encapsulates the enumerated values that describe the different routing topology values.\n"
"  oaRouteTopologyEnum\n"
"Constructors:\n"
"  Paramegers: (oaRouteTopologyEnum)\n"
"    Calls: oaRouteTopology(oaRouteTopologyEnum valueIn)\n"
"    Signature: oaRouteTopology||simple-oaRouteTopologyEnum,\n"
"    This function constructs an instance of an oaRouteTopology class using the specified enum value. The enum values are defined in #oaRouteTopologyEnum.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaRouteTopology(const oaString& name)\n"
"    Signature: oaRouteTopology||cref-oaString,\n"
"    This function constructs an instance of an oaRouteTopology class using the #oaRouteTopologyEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaRouteTopologyEnum.\n"
"    oacInvalidRouteTopologyName\n"
"  Paramegers: (oaRouteTopology)\n"
"    Calls: (const oaRouteTopology&)\n"
"    Signature: oaRouteTopology||cref-oaRouteTopology,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRouteTopology_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRouteTopology",
    sizeof(PyoaRouteTopologyObject),
    0,
    (destructor)oaRouteTopology_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRouteTopology_tp_compare,	/* tp_compare */
    (reprfunc)oaRouteTopology_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRouteTopology_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRouteTopology_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRouteTopology_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRouteTopology_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRouteTopology_Type)<0) {
      printf("** PyType_Ready failed for: oaRouteTopology\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRouteTopology",
           (PyObject*)(&PyoaRouteTopology_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRouteTopology\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaRouteTopologyEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaRouteTopologyEnum_Convert(PyObject* ob,PyParamoaRouteTopologyEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacNoneRouteTopology")==0) { result->SetData(oacNoneRouteTopology); return 1;}
        if (strcasecmp(str,"oacStripeRouteTopology")==0) { result->SetData(oacStripeRouteTopology); return 1;}
        if (strcasecmp(str,"oacStandardCellWireRouteTopology")==0) { result->SetData(oacStandardCellWireRouteTopology); return 1;}
        if (strcasecmp(str,"oacIOWireRouteTopology")==0) { result->SetData(oacIOWireRouteTopology); return 1;}
        if (strcasecmp(str,"oacBlockWireRouteTopology")==0) { result->SetData(oacBlockWireRouteTopology); return 1;}
        if (strcasecmp(str,"oacRingRouteTopology")==0) { result->SetData(oacRingRouteTopology); return 1;}
        if (strcasecmp(str,"oacPadRingRouteTopology")==0) { result->SetData(oacPadRingRouteTopology); return 1;}
        if (strcasecmp(str,"oacBlockRingRouteTopology")==0) { result->SetData(oacBlockRingRouteTopology); return 1;}
        if (strcasecmp(str,"oacCoreWireRouteTopology")==0) { result->SetData(oacCoreWireRouteTopology); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaRouteTopologyEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRouteTopologyEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaRouteTopologyEnum_FromoaRouteTopologyEnum(oaRouteTopologyEnum ob)
{
    if (ob==oacNoneRouteTopology) return PyString_FromString("oacNoneRouteTopology");
    if (ob==oacStripeRouteTopology) return PyString_FromString("oacStripeRouteTopology");
    if (ob==oacStandardCellWireRouteTopology) return PyString_FromString("oacStandardCellWireRouteTopology");
    if (ob==oacIOWireRouteTopology) return PyString_FromString("oacIOWireRouteTopology");
    if (ob==oacBlockWireRouteTopology) return PyString_FromString("oacBlockWireRouteTopology");
    if (ob==oacRingRouteTopology) return PyString_FromString("oacRingRouteTopology");
    if (ob==oacPadRingRouteTopology) return PyString_FromString("oacPadRingRouteTopology");
    if (ob==oacBlockRingRouteTopology) return PyString_FromString("oacBlockRingRouteTopology");
    if (ob==oacCoreWireRouteTopology) return PyString_FromString("oacCoreWireRouteTopology");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaRouteTopologyEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaRouteTopologyEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaRouteTopologyEnum_FromoaRouteTopologyEnum(oaRouteTopologyEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaRouteTopologyEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaRouteTopologyEnum_doc[] =
"Type convert function for enum: oaRouteTopologyEnum";
                               
static PyMethodDef PyoaRouteTopologyEnum_method =
  {"oaRouteTopologyEnum",(PyCFunction)PyoaRouteTopologyEnum_TypeFunction,METH_VARARGS,oaRouteTopologyEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaRouteTopologyEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacNoneRouteTopology");
    PyDict_SetItemString(mod_dict,"oacNoneRouteTopology",value);
    Py_DECREF(value);
    value=PyString_FromString("oacStripeRouteTopology");
    PyDict_SetItemString(mod_dict,"oacStripeRouteTopology",value);
    Py_DECREF(value);
    value=PyString_FromString("oacStandardCellWireRouteTopology");
    PyDict_SetItemString(mod_dict,"oacStandardCellWireRouteTopology",value);
    Py_DECREF(value);
    value=PyString_FromString("oacIOWireRouteTopology");
    PyDict_SetItemString(mod_dict,"oacIOWireRouteTopology",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBlockWireRouteTopology");
    PyDict_SetItemString(mod_dict,"oacBlockWireRouteTopology",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRingRouteTopology");
    PyDict_SetItemString(mod_dict,"oacRingRouteTopology",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPadRingRouteTopology");
    PyDict_SetItemString(mod_dict,"oacPadRingRouteTopology",value);
    Py_DECREF(value);
    value=PyString_FromString("oacBlockRingRouteTopology");
    PyDict_SetItemString(mod_dict,"oacBlockRingRouteTopology",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCoreWireRouteTopology");
    PyDict_SetItemString(mod_dict,"oacCoreWireRouteTopology",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaRouteTopologyEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaRouteTopologyEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaRouteTopologyEnum\n");
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
// Wrapper Implementation for Class: oaRow
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRow_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRow_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRowObject* self = (PyoaRowObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaRow)
    {
        PyParamoaRow p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaRow_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaRow, Choices are:\n"
        "    (oaRow)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRow_tp_dealloc(PyoaRowObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRow_tp_repr(PyObject *ob)
{
    PyParamoaRow value;
    int convert_status=PyoaRow_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaRow::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[27];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaRow::");
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
oaRow_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRow v1;
    PyParamoaRow v2;
    int convert_status1=PyoaRow_Convert(ob1,&v1);
    int convert_status2=PyoaRow_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRow_Convert(PyObject* ob,PyParamoaRow* result)
{
    if (ob == NULL) return 1;
    if (PyoaRow_Check(ob)) {
        result->SetData( (oaRow**) ((PyoaRowObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRow Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRow_FromoaRow(oaRow** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaRow* data=*value;
        PyObject* bself = PyoaRow_Type.tp_alloc(&PyoaRow_Type,0);
        if (bself == NULL) return bself;
        PyoaRowObject* self = (PyoaRowObject*)bself;
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
PyObject* PyoaRow_FromoaRow(oaRow* data)
{
    if (data) {
       PyObject* bself = PyoaRow_Type.tp_alloc(&PyoaRow_Type,0);
       if (bself == NULL) return bself;
       PyoaRowObject* self = (PyoaRowObject*)bself;
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
static char oaRow_getHeader_doc[] = 
"Class: oaRow, Function: getHeader\n"
"  Paramegers: ()\n"
"    Calls: oaRowHeader* getHeader() const\n"
"    Signature: getHeader|ptr-oaRowHeader|\n"
"    BrowseData: 1\n"
"    This function returns the oaRowHeader object associated with this row.\n"
;

static PyObject*
oaRow_getHeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowObject* self=(PyoaRowObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaRowHeaderp result= (data.DataCall()->getHeader());
        return PyoaRowHeader_FromoaRowHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRow_getName_doc[] = 
"Class: oaRow, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function fills out name with the name of this row.\n"
"    name\n"
"    The row name\n"
;

static PyObject*
oaRow_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowObject* self=(PyoaRowObject*)ob;
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
static char oaRow_getNumSites_doc[] = 
"Class: oaRow, Function: getNumSites\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumSites() const\n"
"    Signature: getNumSites|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of sites of this row.\n"
;

static PyObject*
oaRow_getNumSites(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowObject* self=(PyoaRowObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getNumSites());
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
static char oaRow_getOrient_doc[] = 
"Class: oaRow, Function: getOrient\n"
"  Paramegers: ()\n"
"    Calls: oaOrient getOrient() const\n"
"    Signature: getOrient|simple-oaOrient|\n"
"    BrowseData: 1\n"
"    This function returns the orientation of this row.\n"
;

static PyObject*
oaRow_getOrient(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowObject* self=(PyoaRowObject*)ob;
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
static char oaRow_getOrigin_doc[] = 
"Class: oaRow, Function: getOrigin\n"
"  Paramegers: (oaPoint)\n"
"    Calls: void getOrigin(oaPoint& origin) const\n"
"    Signature: getOrigin|void-void|ref-oaPoint,\n"
"    BrowseData: 0,oaPoint\n"
"    This function fills out origin with the origin of this row.\n"
"    origin\n"
"    The row origin\n"
;

static PyObject*
oaRow_getOrigin(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowObject* self=(PyoaRowObject*)ob;
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
static char oaRow_getSiteDef_doc[] = 
"Class: oaRow, Function: getSiteDef\n"
"  Paramegers: ()\n"
"    Calls: oaSiteDef* getSiteDef() const\n"
"    Signature: getSiteDef|ptr-oaSiteDef|\n"
"    BrowseData: 1\n"
"    This function attempts to return the siteDef associated with this row. If the row cannot bound, NULL is returned.\n"
;

static PyObject*
oaRow_getSiteDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowObject* self=(PyoaRowObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

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
static char oaRow_getSiteDefName_doc[] = 
"Class: oaRow, Function: getSiteDefName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getSiteDefName(oaString& name) const\n"
"    Signature: getSiteDefName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function attempts to return the name of the siteDef object associated with this row.\n"
"    name\n"
"    The siteDef object name\n"
;

static PyObject*
oaRow_getSiteDefName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowObject* self=(PyoaRowObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getSiteDefName(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRow_getSiteOrient_doc[] = 
"Class: oaRow, Function: getSiteOrient\n"
"  Paramegers: ()\n"
"    Calls: oaOrient getSiteOrient() const\n"
"    Signature: getSiteOrient|simple-oaOrient|\n"
"    BrowseData: 1\n"
"    This function returns the orientation of site associated with this row.\n"
;

static PyObject*
oaRow_getSiteOrient(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowObject* self=(PyoaRowObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaOrient* result= new oaOrient(data.DataCall()->getSiteOrient());
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
static char oaRow_getSiteSpacing_doc[] = 
"Class: oaRow, Function: getSiteSpacing\n"
"  Paramegers: ()\n"
"    Calls: oaDist getSiteSpacing() const\n"
"    Signature: getSiteSpacing|simple-oaDist|\n"
"    BrowseData: 1\n"
"    This function returns the spacing between the sites in this row.\n"
;

static PyObject*
oaRow_getSiteSpacing(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowObject* self=(PyoaRowObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDist result= (data.DataCall()->getSiteSpacing());
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
static char oaRow_isBound_doc[] = 
"Class: oaRow, Function: isBound\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isBound() const\n"
"    Signature: isBound|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if the siteDef associated with this row is currently bound to the master.\n"
;

static PyObject*
oaRow_isBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowObject* self=(PyoaRowObject*)ob;
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
static char oaRow_setName_doc[] = 
"Class: oaRow, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function sets the name of this row to the specified value.\n"
"    name\n"
"    The row name\n"
;

static PyObject*
oaRow_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowObject* self=(PyoaRowObject*)ob;
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
static char oaRow_setNumSites_doc[] = 
"Class: oaRow, Function: setNumSites\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setNumSites(oaUInt4 numSites)\n"
"    Signature: setNumSites|void-void|simple-oaUInt4,\n"
"    This function sets the number of sites of this row to the specified value.\n"
"    numSites\n"
"    The number of sites in this row\n"
"    oacRowZeroNumSitesNotAllowed\n"
;

static PyObject*
oaRow_setNumSites(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowObject* self=(PyoaRowObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setNumSites(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRow_setOrient_doc[] = 
"Class: oaRow, Function: setOrient\n"
"  Paramegers: (oaOrient)\n"
"    Calls: void setOrient(oaOrient orient)\n"
"    Signature: setOrient|void-void|simple-oaOrient,\n"
"    This function sets the orientation of this row to the specified value.\n"
"    orient\n"
"    The row orientation\n"
;

static PyObject*
oaRow_setOrient(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowObject* self=(PyoaRowObject*)ob;
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
static char oaRow_setOrigin_doc[] = 
"Class: oaRow, Function: setOrigin\n"
"  Paramegers: (oaPoint)\n"
"    Calls: void setOrigin(const oaPoint& origin)\n"
"    Signature: setOrigin|void-void|cref-oaPoint,\n"
"    This function sets the origin of the row to the specified origin .\n"
"    origin\n"
"    The origin to set\n"
;

static PyObject*
oaRow_setOrigin(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowObject* self=(PyoaRowObject*)ob;
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
static char oaRow_setSiteDef_doc[] = 
"Class: oaRow, Function: setSiteDef\n"
"  Paramegers: (oaSiteDef)\n"
"    Calls: void setSiteDef(const oaSiteDef* siteDef)\n"
"    Signature: setSiteDef|void-void|cptr-oaSiteDef,\n"
"    This function sets the siteDef of this row to the specified siteDef .\n"
"    siteDef\n"
"    The siteDef name\n"
;

static PyObject*
oaRow_setSiteDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowObject* self=(PyoaRowObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaSiteDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSiteDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setSiteDef(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRow_setSiteOrient_doc[] = 
"Class: oaRow, Function: setSiteOrient\n"
"  Paramegers: (oaOrient)\n"
"    Calls: void setSiteOrient(const oaOrient& siteOrient)\n"
"    Signature: setSiteOrient|void-void|cref-oaOrient,\n"
"    This function sets the site orientation of this row to the specified value.\n"
"    siteOrient\n"
"    The site orientation of this row\n"
;

static PyObject*
oaRow_setSiteOrient(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowObject* self=(PyoaRowObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaOrient p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaOrient_Convert,&p1)) {
        data.DataCall()->setSiteOrient(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRow_setSiteSpacing_doc[] = 
"Class: oaRow, Function: setSiteSpacing\n"
"  Paramegers: (oaDist)\n"
"    Calls: void setSiteSpacing(oaDist siteSpacing)\n"
"    Signature: setSiteSpacing|void-void|simple-oaDist,\n"
"    This function sets the spacing between the sites of this row to the specified value.\n"
"    siteSpacing\n"
"    The spacing for the sites of this row\n"
;

static PyObject*
oaRow_setSiteSpacing(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowObject* self=(PyoaRowObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDist p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDist_Convert,&p1)) {
        data.DataCall()->setSiteSpacing(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRow_isNull_doc[] =
"Class: oaRow, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaRow_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaRow data;
    int convert_status=PyoaRow_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaRow_assign_doc[] = 
"Class: oaRow, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRow_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRow data;
  int convert_status=PyoaRow_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRow p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRow_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRow_methodlist[] = {
    {"getHeader",(PyCFunction)oaRow_getHeader,METH_VARARGS,oaRow_getHeader_doc},
    {"getName",(PyCFunction)oaRow_getName,METH_VARARGS,oaRow_getName_doc},
    {"getNumSites",(PyCFunction)oaRow_getNumSites,METH_VARARGS,oaRow_getNumSites_doc},
    {"getOrient",(PyCFunction)oaRow_getOrient,METH_VARARGS,oaRow_getOrient_doc},
    {"getOrigin",(PyCFunction)oaRow_getOrigin,METH_VARARGS,oaRow_getOrigin_doc},
    {"getSiteDef",(PyCFunction)oaRow_getSiteDef,METH_VARARGS,oaRow_getSiteDef_doc},
    {"getSiteDefName",(PyCFunction)oaRow_getSiteDefName,METH_VARARGS,oaRow_getSiteDefName_doc},
    {"getSiteOrient",(PyCFunction)oaRow_getSiteOrient,METH_VARARGS,oaRow_getSiteOrient_doc},
    {"getSiteSpacing",(PyCFunction)oaRow_getSiteSpacing,METH_VARARGS,oaRow_getSiteSpacing_doc},
    {"isBound",(PyCFunction)oaRow_isBound,METH_VARARGS,oaRow_isBound_doc},
    {"setName",(PyCFunction)oaRow_setName,METH_VARARGS,oaRow_setName_doc},
    {"setNumSites",(PyCFunction)oaRow_setNumSites,METH_VARARGS,oaRow_setNumSites_doc},
    {"setOrient",(PyCFunction)oaRow_setOrient,METH_VARARGS,oaRow_setOrient_doc},
    {"setOrigin",(PyCFunction)oaRow_setOrigin,METH_VARARGS,oaRow_setOrigin_doc},
    {"setSiteDef",(PyCFunction)oaRow_setSiteDef,METH_VARARGS,oaRow_setSiteDef_doc},
    {"setSiteOrient",(PyCFunction)oaRow_setSiteOrient,METH_VARARGS,oaRow_setSiteOrient_doc},
    {"setSiteSpacing",(PyCFunction)oaRow_setSiteSpacing,METH_VARARGS,oaRow_setSiteSpacing_doc},
    {"isNull",(PyCFunction)oaRow_tp_isNull,METH_VARARGS,oaRow_isNull_doc},
    {"assign",(PyCFunction)oaRow_tp_assign,METH_VARARGS,oaRow_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRow_doc[] = 
"Class: oaRow\n"
"  The oaRow class implements a row of sites where an instance can be placed. A row represents a potential location for placement of standard cells, macros, or devices. A row is defined as an area associated with an oaSiteDef . The oaSiteDef has information allowing for the specification of the placeable objects within a row. A row is a repetition of a site element in a given direction (horizontal or vertical). The orientation of these site elements in a row is relative to the orientation of the row.\n"
"  The oaRow class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaRow)\n"
"    Calls: (const oaRow&)\n"
"    Signature: oaRow||cref-oaRow,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRow_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRow",
    sizeof(PyoaRowObject),
    0,
    (destructor)oaRow_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRow_tp_compare,	/* tp_compare */
    (reprfunc)oaRow_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRow_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRow_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaFig_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRow_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRow_static_create_doc[] = 
"Class: oaRow, Function: create\n"
"  Paramegers: (oaBlock,oaSiteDef,oaString,oaPoint,oaOrient,oaUInt4,oaOrient)\n"
"    Calls: oaRow* create(oaBlock* block,oaSiteDef* siteDef,const oaString& name,const oaPoint& origin,const oaOrient& rowOrient,oaUInt4 numSites,const oaOrient& siteOrient)\n"
"    Signature: create|ptr-oaRow|ptr-oaBlock,ptr-oaSiteDef,cref-oaString,cref-oaPoint,cref-oaOrient,simple-oaUInt4,cref-oaOrient,simple-oaDist,\n"
"    This function creates a row object with the specified attributes. This function lets you specify the siteDef object to associate with the new row and the name for the new row.\n"
"    An exception is thrown if the siteDef is from a technology database that is not included in the graph of referenced technology databases for the technology database currently bound to the design containing the row.\n"
"    oaRow* if the row was created\n"
"    block\n"
"    The block in which to create the row\n"
"    siteDef\n"
"    The siteDef that associates with the row\n"
"    name\n"
"    The row name\n"
"    origin\n"
"    The origin of the row\n"
"    rowOrient\n"
"    The orientation of the row\n"
"    numSites\n"
"    The number of sites of the row\n"
"    siteOrient\n"
"    The orientation of the sites\n"
"    siteSpacing\n"
"    The optional spacing between the sites\n"
"    oacRowNameExists\n"
"    oacRowZeroNumSitesNotAllowed\n"
"    oacSiteDefNotInTechAssociatedWithDesign\n"
"  Paramegers: (oaBlock,oaSiteDef,oaString,oaPoint,oaOrient,oaUInt4,oaOrient,oaDist)\n"
"    Calls: oaRow* create(oaBlock* block,oaSiteDef* siteDef,const oaString& name,const oaPoint& origin,const oaOrient& rowOrient,oaUInt4 numSites,const oaOrient& siteOrient,oaDist siteSpacing)\n"
"    Signature: create|ptr-oaRow|ptr-oaBlock,ptr-oaSiteDef,cref-oaString,cref-oaPoint,cref-oaOrient,simple-oaUInt4,cref-oaOrient,simple-oaDist,\n"
"    This function creates a row object with the specified attributes. This function lets you specify the siteDef object to associate with the new row and the name for the new row.\n"
"    An exception is thrown if the siteDef is from a technology database that is not included in the graph of referenced technology databases for the technology database currently bound to the design containing the row.\n"
"    oaRow* if the row was created\n"
"    block\n"
"    The block in which to create the row\n"
"    siteDef\n"
"    The siteDef that associates with the row\n"
"    name\n"
"    The row name\n"
"    origin\n"
"    The origin of the row\n"
"    rowOrient\n"
"    The orientation of the row\n"
"    numSites\n"
"    The number of sites of the row\n"
"    siteOrient\n"
"    The orientation of the sites\n"
"    siteSpacing\n"
"    The optional spacing between the sites\n"
"    oacRowNameExists\n"
"    oacRowZeroNumSitesNotAllowed\n"
"    oacSiteDefNotInTechAssociatedWithDesign\n"
"  Paramegers: (oaBlock,oaSiteDef,oaPoint,oaOrient,oaUInt4,oaOrient)\n"
"    Calls: oaRow* create(oaBlock* block,oaSiteDef* siteDef,const oaPoint& origin,const oaOrient& rowOrient,oaUInt4 numSites,const oaOrient& siteOrient)\n"
"    Signature: create|ptr-oaRow|ptr-oaBlock,ptr-oaSiteDef,cref-oaPoint,cref-oaOrient,simple-oaUInt4,cref-oaOrient,simple-oaDist,\n"
"    This function creates a row object with the specified attributes. This function lets you specify the siteDef object to associate with the new row. A name for the new row is automatically generated with the default prefix \"R__\\%d\", where d refers to a unique integer.\n"
"    An exception is thrown if the siteDef is from a technology database that is not included in the graph of referenced technology databases for the technology database currently bound to the design containing the row.\n"
"    oaRow* if the row was created\n"
"    block\n"
"    The block in which to create the row\n"
"    siteDef\n"
"    The siteDef that associates with the row\n"
"    origin\n"
"    The origin of the row\n"
"    rowOrient\n"
"    The orientation of the row\n"
"    numSites\n"
"    The number of sites of the row\n"
"    siteOrient\n"
"    The orientation of the sites relative to the row\n"
"    siteSpacing\n"
"    The optional spacing between the sites\n"
"    oacRowZeroNumSitesNotAllowed\n"
"    oacSiteDefNotInTechAssociatedWithDesign\n"
"  Paramegers: (oaBlock,oaSiteDef,oaPoint,oaOrient,oaUInt4,oaOrient,oaDist)\n"
"    Calls: oaRow* create(oaBlock* block,oaSiteDef* siteDef,const oaPoint& origin,const oaOrient& rowOrient,oaUInt4 numSites,const oaOrient& siteOrient,oaDist siteSpacing)\n"
"    Signature: create|ptr-oaRow|ptr-oaBlock,ptr-oaSiteDef,cref-oaPoint,cref-oaOrient,simple-oaUInt4,cref-oaOrient,simple-oaDist,\n"
"    This function creates a row object with the specified attributes. This function lets you specify the siteDef object to associate with the new row. A name for the new row is automatically generated with the default prefix \"R__\\%d\", where d refers to a unique integer.\n"
"    An exception is thrown if the siteDef is from a technology database that is not included in the graph of referenced technology databases for the technology database currently bound to the design containing the row.\n"
"    oaRow* if the row was created\n"
"    block\n"
"    The block in which to create the row\n"
"    siteDef\n"
"    The siteDef that associates with the row\n"
"    origin\n"
"    The origin of the row\n"
"    rowOrient\n"
"    The orientation of the row\n"
"    numSites\n"
"    The number of sites of the row\n"
"    siteOrient\n"
"    The orientation of the sites relative to the row\n"
"    siteSpacing\n"
"    The optional spacing between the sites\n"
"    oacRowZeroNumSitesNotAllowed\n"
"    oacSiteDefNotInTechAssociatedWithDesign\n"
;

static PyObject*
oaRow_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaBlock,oaSiteDef,oaString,oaPoint,oaOrient,oaUInt4,oaOrient)
    {
        PyParamoaBlock p1;
        PyParamoaSiteDef p2;
        PyParamoaString p3;
        PyParamoaPoint p4;
        PyParamoaOrient p5;
        PyParamoaUInt4 p6;
        PyParamoaOrient p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaSiteDef_Convert,&p2,
              &PyoaString_Convert,&p3,
              &PyoaPoint_Convert,&p4,
              &PyoaOrient_Convert,&p5,
              &PyoaUInt4_Convert,&p6,
              &PyoaOrient_Convert,&p7)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaRowp result= (oaRow::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data()));
            return PyoaRow_FromoaRow(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaSiteDef,oaString,oaPoint,oaOrient,oaUInt4,oaOrient,oaDist)
    {
        PyParamoaBlock p1;
        PyParamoaSiteDef p2;
        PyParamoaString p3;
        PyParamoaPoint p4;
        PyParamoaOrient p5;
        PyParamoaUInt4 p6;
        PyParamoaOrient p7;
        PyParamoaDist p8;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaSiteDef_Convert,&p2,
              &PyoaString_Convert,&p3,
              &PyoaPoint_Convert,&p4,
              &PyoaOrient_Convert,&p5,
              &PyoaUInt4_Convert,&p6,
              &PyoaOrient_Convert,&p7,
              &PyoaDist_Convert,&p8)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaRowp result= (oaRow::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data()));
            return PyoaRow_FromoaRow(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaSiteDef,oaPoint,oaOrient,oaUInt4,oaOrient)
    {
        PyParamoaBlock p1;
        PyParamoaSiteDef p2;
        PyParamoaPoint p3;
        PyParamoaOrient p4;
        PyParamoaUInt4 p5;
        PyParamoaOrient p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaSiteDef_Convert,&p2,
              &PyoaPoint_Convert,&p3,
              &PyoaOrient_Convert,&p4,
              &PyoaUInt4_Convert,&p5,
              &PyoaOrient_Convert,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaRowp result= (oaRow::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data()));
            return PyoaRow_FromoaRow(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaSiteDef,oaPoint,oaOrient,oaUInt4,oaOrient,oaDist)
    {
        PyParamoaBlock p1;
        PyParamoaSiteDef p2;
        PyParamoaPoint p3;
        PyParamoaOrient p4;
        PyParamoaUInt4 p5;
        PyParamoaOrient p6;
        PyParamoaDist p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaSiteDef_Convert,&p2,
              &PyoaPoint_Convert,&p3,
              &PyoaOrient_Convert,&p4,
              &PyoaUInt4_Convert,&p5,
              &PyoaOrient_Convert,&p6,
              &PyoaDist_Convert,&p7)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaRowp result= (oaRow::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data()));
            return PyoaRow_FromoaRow(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaRow, function: create, Choices are:\n"
        "    (oaBlock,oaSiteDef,oaString,oaPoint,oaOrient,oaUInt4,oaOrient)\n"
        "    (oaBlock,oaSiteDef,oaString,oaPoint,oaOrient,oaUInt4,oaOrient,oaDist)\n"
        "    (oaBlock,oaSiteDef,oaPoint,oaOrient,oaUInt4,oaOrient)\n"
        "    (oaBlock,oaSiteDef,oaPoint,oaOrient,oaUInt4,oaOrient,oaDist)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRow_static_find_doc[] = 
"Class: oaRow, Function: find\n"
"  Paramegers: (oaBlock,oaString)\n"
"    Calls: oaRow* find(const oaBlock* block,const oaString& name)\n"
"    Signature: find|ptr-oaRow|cptr-oaBlock,cref-oaString,\n"
"    This function searches the specified design for a row with the specified name. If the row is found, it is returned. Otherwise, NULL is returned.\n"
"    block\n"
"    The block to search\n"
"    name\n"
"    The name of the oaRow object to find\n"
"    The oaRow pointer or NULL\n"
;

static PyObject*
oaRow_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBlock p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaBlock_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaRowp result= (oaRow::find(p1.Data(),p2.Data()));
        return PyoaRow_FromoaRow(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaRow_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaRow_static_create,METH_VARARGS,oaRow_static_create_doc},
    {"static_find",(PyCFunction)oaRow_static_find,METH_VARARGS,oaRow_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRow_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRow_Type)<0) {
      printf("** PyType_Ready failed for: oaRow\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRow",
           (PyObject*)(&PyoaRow_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRow\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaRow_Type.tp_dict;
    for(method=oaRow_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaRowFlipType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRowFlipType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRowFlipType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRowFlipTypeObject* self = (PyoaRowFlipTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaRowFlipTypeEnum)
    {
        PyParamoaRowFlipTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaRowFlipTypeEnum_Convert,&p1)) {
            self->value =  new oaRowFlipType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaRowFlipType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaRowFlipType)
    {
        PyParamoaRowFlipType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaRowFlipType_Convert,&p1)) {
            self->value= new oaRowFlipType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaRowFlipType, Choices are:\n"
        "    (oaRowFlipTypeEnum)\n"
        "    (oaString)\n"
        "    (oaRowFlipType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRowFlipType_tp_dealloc(PyoaRowFlipTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRowFlipType_tp_repr(PyObject *ob)
{
    PyParamoaRowFlipType value;
    int convert_status=PyoaRowFlipType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[35];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaRowFlipType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRowFlipType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRowFlipType v1;
    PyParamoaRowFlipType v2;
    int convert_status1=PyoaRowFlipType_Convert(ob1,&v1);
    int convert_status2=PyoaRowFlipType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRowFlipType_Convert(PyObject* ob,PyParamoaRowFlipType* result)
{
    if (ob == NULL) return 1;
    if (PyoaRowFlipType_Check(ob)) {
        result->SetData(  ((PyoaRowFlipTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRowFlipType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRowFlipType_FromoaRowFlipType(oaRowFlipType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaRowFlipType_Type.tp_alloc(&PyoaRowFlipType_Type,0);
        if (bself == NULL) return bself;
        PyoaRowFlipTypeObject* self = (PyoaRowFlipTypeObject*)bself;
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
static char oaRowFlipType_getName_doc[] = 
"Class: oaRowFlipType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaRowFlipTypeEnum object.\n"
;

static PyObject*
oaRowFlipType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRowFlipType data;
    int convert_status=PyoaRowFlipType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowFlipTypeObject* self=(PyoaRowFlipTypeObject*)ob;

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
static char oaRowFlipType_oaRowFlipTypeEnum_doc[] = 
"Class: oaRowFlipType, Function: oaRowFlipTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaRowFlipTypeEnum oaRowFlipTypeEnum() const\n"
"    Signature: operator oaRowFlipTypeEnum|simple-oaRowFlipTypeEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaRowFlipType object into the corresponding #oaRowFlipTypeEnum value.\n"
;

static PyObject*
oaRowFlipType_oaRowFlipTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRowFlipType data;
    int convert_status=PyoaRowFlipType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowFlipTypeObject* self=(PyoaRowFlipTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaRowFlipTypeEnum result= (data.DataCall()->operator oaRowFlipTypeEnum());
        return PyoaRowFlipTypeEnum_FromoaRowFlipTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaRowFlipType_assign_doc[] = 
"Class: oaRowFlipType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRowFlipType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRowFlipType data;
  int convert_status=PyoaRowFlipType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRowFlipType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRowFlipType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRowFlipType_methodlist[] = {
    {"getName",(PyCFunction)oaRowFlipType_getName,METH_VARARGS,oaRowFlipType_getName_doc},
    {"oaRowFlipTypeEnum",(PyCFunction)oaRowFlipType_oaRowFlipTypeEnum,METH_VARARGS,oaRowFlipType_oaRowFlipTypeEnum_doc},
    {"assign",(PyCFunction)oaRowFlipType_tp_assign,METH_VARARGS,oaRowFlipType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRowFlipType_doc[] = 
"Class: oaRowFlipType\n"
"  The oaRowFlipType class is an enum wrapper that indicates whether alternate rows in an oaCoreBoxSpec are flipped with respect to the primary orientation of the sites in that row. See oaCoreBoxSpec::setRowFlipType for an example of its use.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaRowFlipTypeEnum\n"
"Constructors:\n"
"  Paramegers: (oaRowFlipTypeEnum)\n"
"    Calls: oaRowFlipType(oaRowFlipTypeEnum typeIn)\n"
"    Signature: oaRowFlipType||simple-oaRowFlipTypeEnum,\n"
"    This function constructs an instance of an oaRowFlipType object using the specified #oaRowFlipTypeEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaRowFlipType(const oaString& name)\n"
"    Signature: oaRowFlipType||cref-oaString,\n"
"    This function constructs an instance of an oaRowFlipType class using the #oaRowFlipTypeEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaRowFlipTypeEnum.\n"
"    oacInvalidCoreRowFlipTypeName\n"
"  Paramegers: (oaRowFlipType)\n"
"    Calls: (const oaRowFlipType&)\n"
"    Signature: oaRowFlipType||cref-oaRowFlipType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRowFlipType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRowFlipType",
    sizeof(PyoaRowFlipTypeObject),
    0,
    (destructor)oaRowFlipType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRowFlipType_tp_compare,	/* tp_compare */
    (reprfunc)oaRowFlipType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRowFlipType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRowFlipType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRowFlipType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRowFlipType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRowFlipType_Type)<0) {
      printf("** PyType_Ready failed for: oaRowFlipType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRowFlipType",
           (PyObject*)(&PyoaRowFlipType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRowFlipType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaRowFlipTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaRowFlipTypeEnum_Convert(PyObject* ob,PyParamoaRowFlipTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacNoRowFlipType")==0) { result->SetData(oacNoRowFlipType); return 1;}
        if (strcasecmp(str,"oacEvenRowFlipType")==0) { result->SetData(oacEvenRowFlipType); return 1;}
        if (strcasecmp(str,"oacOddRowFlipType")==0) { result->SetData(oacOddRowFlipType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaRowFlipTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRowFlipTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaRowFlipTypeEnum_FromoaRowFlipTypeEnum(oaRowFlipTypeEnum ob)
{
    if (ob==oacNoRowFlipType) return PyString_FromString("oacNoRowFlipType");
    if (ob==oacEvenRowFlipType) return PyString_FromString("oacEvenRowFlipType");
    if (ob==oacOddRowFlipType) return PyString_FromString("oacOddRowFlipType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaRowFlipTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaRowFlipTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaRowFlipTypeEnum_FromoaRowFlipTypeEnum(oaRowFlipTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaRowFlipTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaRowFlipTypeEnum_doc[] =
"Type convert function for enum: oaRowFlipTypeEnum";
                               
static PyMethodDef PyoaRowFlipTypeEnum_method =
  {"oaRowFlipTypeEnum",(PyCFunction)PyoaRowFlipTypeEnum_TypeFunction,METH_VARARGS,oaRowFlipTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaRowFlipTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacNoRowFlipType");
    PyDict_SetItemString(mod_dict,"oacNoRowFlipType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacEvenRowFlipType");
    PyDict_SetItemString(mod_dict,"oacEvenRowFlipType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacOddRowFlipType");
    PyDict_SetItemString(mod_dict,"oacOddRowFlipType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaRowFlipTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaRowFlipTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaRowFlipTypeEnum\n");
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
// Wrapper Implementation for Class: oaRowHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRowHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRowHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRowHeaderObject* self = (PyoaRowHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaRowHeader)
    {
        PyParamoaRowHeader p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaRowHeader_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaRowHeader, Choices are:\n"
        "    (oaRowHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRowHeader_tp_dealloc(PyoaRowHeaderObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRowHeader_tp_repr(PyObject *ob)
{
    PyParamoaRowHeader value;
    int convert_status=PyoaRowHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[33];
    sprintf(buffer,"<oaRowHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRowHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRowHeader v1;
    PyParamoaRowHeader v2;
    int convert_status1=PyoaRowHeader_Convert(ob1,&v1);
    int convert_status2=PyoaRowHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRowHeader_Convert(PyObject* ob,PyParamoaRowHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaRowHeader_Check(ob)) {
        result->SetData( (oaRowHeader**) ((PyoaRowHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRowHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRowHeader_FromoaRowHeader(oaRowHeader** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaRowHeader* data=*value;
        PyObject* bself = PyoaRowHeader_Type.tp_alloc(&PyoaRowHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaRowHeaderObject* self = (PyoaRowHeaderObject*)bself;
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
PyObject* PyoaRowHeader_FromoaRowHeader(oaRowHeader* data)
{
    if (data) {
       PyObject* bself = PyoaRowHeader_Type.tp_alloc(&PyoaRowHeader_Type,0);
       if (bself == NULL) return bself;
       PyoaRowHeaderObject* self = (PyoaRowHeaderObject*)bself;
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
static char oaRowHeader_getBBox_doc[] = 
"Class: oaRowHeader, Function: getBBox\n"
"  Paramegers: (oaBox)\n"
"    Calls: void getBBox(oaBox& bBox) const\n"
"    Signature: getBBox|void-void|ref-oaBox,\n"
"    BrowseData: 0,oaBox\n"
"    This function fills bBox with the bounding box of all rows associated with the rowHeader. This is used to quickly determine whether any rows of the siteDef are in a region of interest. The function returns a bounding box in the coordinate space of the rowHeader's design.\n"
;

static PyObject*
oaRowHeader_getBBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRowHeader data;
    int convert_status=PyoaRowHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowHeaderObject* self=(PyoaRowHeaderObject*)ob;
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
static char oaRowHeader_getRows_doc[] = 
"Class: oaRowHeader, Function: getRows\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaRow_oaRowHeader getRows() const\n"
"    Signature: getRows|simple-oaCollection_oaRow_oaRowHeader|\n"
"    BrowseData: 1\n"
"    This function returns a collection of rows in this rowHeader.\n"
;

static PyObject*
oaRowHeader_getRows(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRowHeader data;
    int convert_status=PyoaRowHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowHeaderObject* self=(PyoaRowHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaRow_oaRowHeader* result= new oaCollection_oaRow_oaRowHeader(data.DataCall()->getRows());
        return PyoaCollection_oaRow_oaRowHeader_FromoaCollection_oaRow_oaRowHeader(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRowHeader_getRowsIter_doc[] = 
"Class: oaRowHeader, Function: getRowsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaRow getRowsIter() const\n"
"    Signature: getRowsIter|simple-oaIter_oaRow|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of rows in this rowHeader.\n"
;

static PyObject*
oaRowHeader_getRowsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRowHeader data;
    int convert_status=PyoaRowHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowHeaderObject* self=(PyoaRowHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaRow* result= new oaIter_oaRow(data.DataCall()->getRows());
        return PyoaIter_oaRow_FromoaIter_oaRow(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRowHeader_getSiteDef_doc[] = 
"Class: oaRowHeader, Function: getSiteDef\n"
"  Paramegers: ()\n"
"    Calls: oaSiteDef* getSiteDef() const\n"
"    Signature: getSiteDef|ptr-oaSiteDef|\n"
"    BrowseData: 1\n"
"    This function attempts to return the siteDef associated with this rowHeader. If the rowHeader is bound, a pointer to the siteDef is returned. Otherwise, NULL is returned.\n"
;

static PyObject*
oaRowHeader_getSiteDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRowHeader data;
    int convert_status=PyoaRowHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowHeaderObject* self=(PyoaRowHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

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
static char oaRowHeader_getSiteDefHeight_doc[] = 
"Class: oaRowHeader, Function: getSiteDefHeight\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getSiteDefHeight() const\n"
"    Signature: getSiteDefHeight|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the height of the siteDef referenced by this rowHeader.\n"
;

static PyObject*
oaRowHeader_getSiteDefHeight(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRowHeader data;
    int convert_status=PyoaRowHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowHeaderObject* self=(PyoaRowHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getSiteDefHeight());
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
static char oaRowHeader_getSiteDefName_doc[] = 
"Class: oaRowHeader, Function: getSiteDefName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getSiteDefName(oaString& siteDefName) const\n"
"    Signature: getSiteDefName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function fills in the given string with the name of the siteDef referenced by this rowHeader.\n"
;

static PyObject*
oaRowHeader_getSiteDefName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRowHeader data;
    int convert_status=PyoaRowHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowHeaderObject* self=(PyoaRowHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getSiteDefName(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaRowHeader_getSiteDefWidth_doc[] = 
"Class: oaRowHeader, Function: getSiteDefWidth\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getSiteDefWidth() const\n"
"    Signature: getSiteDefWidth|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the width of the siteDef referenced by this rowHeader.\n"
;

static PyObject*
oaRowHeader_getSiteDefWidth(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRowHeader data;
    int convert_status=PyoaRowHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowHeaderObject* self=(PyoaRowHeaderObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getSiteDefWidth());
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
static char oaRowHeader_isBound_doc[] = 
"Class: oaRowHeader, Function: isBound\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isBound() const\n"
"    Signature: isBound|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this rowHeader is bound. If the rowHeader is bound, the siteDef is read in the linkage from the rowHeader and is established by traversing from a row to that siteDef.\n"
;

static PyObject*
oaRowHeader_isBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRowHeader data;
    int convert_status=PyoaRowHeader_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowHeaderObject* self=(PyoaRowHeaderObject*)ob;
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
static char oaRowHeader_isNull_doc[] =
"Class: oaRowHeader, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaRowHeader_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaRowHeader data;
    int convert_status=PyoaRowHeader_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaRowHeader_assign_doc[] = 
"Class: oaRowHeader, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRowHeader_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRowHeader data;
  int convert_status=PyoaRowHeader_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRowHeader p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRowHeader_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRowHeader_methodlist[] = {
    {"getBBox",(PyCFunction)oaRowHeader_getBBox,METH_VARARGS,oaRowHeader_getBBox_doc},
    {"getRows",(PyCFunction)oaRowHeader_getRows,METH_VARARGS,oaRowHeader_getRows_doc},
    {"getRowsIter",(PyCFunction)oaRowHeader_getRowsIter,METH_VARARGS,oaRowHeader_getRowsIter_doc},
    {"getSiteDef",(PyCFunction)oaRowHeader_getSiteDef,METH_VARARGS,oaRowHeader_getSiteDef_doc},
    {"getSiteDefHeight",(PyCFunction)oaRowHeader_getSiteDefHeight,METH_VARARGS,oaRowHeader_getSiteDefHeight_doc},
    {"getSiteDefName",(PyCFunction)oaRowHeader_getSiteDefName,METH_VARARGS,oaRowHeader_getSiteDefName_doc},
    {"getSiteDefWidth",(PyCFunction)oaRowHeader_getSiteDefWidth,METH_VARARGS,oaRowHeader_getSiteDefWidth_doc},
    {"isBound",(PyCFunction)oaRowHeader_isBound,METH_VARARGS,oaRowHeader_isBound_doc},
    {"isNull",(PyCFunction)oaRowHeader_tp_isNull,METH_VARARGS,oaRowHeader_isNull_doc},
    {"assign",(PyCFunction)oaRowHeader_tp_assign,METH_VARARGS,oaRowHeader_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRowHeader_doc[] = 
"Class: oaRowHeader\n"
"  The oaRowHeader class implements an object that contains information about a particular siteDef and all of the rows it uses.\n"
"  The oaRowHeader class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaRowHeader)\n"
"    Calls: (const oaRowHeader&)\n"
"    Signature: oaRowHeader||cref-oaRowHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRowHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRowHeader",
    sizeof(PyoaRowHeaderObject),
    0,
    (destructor)oaRowHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRowHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaRowHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRowHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRowHeader_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBlockObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRowHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRowHeader_static_find_doc[] = 
"Class: oaRowHeader, Function: find\n"
"  Paramegers: (oaBlock,oaSiteDef)\n"
"    Calls: oaRowHeader* find(const oaBlock* block,const oaSiteDef* siteDef)\n"
"    Signature: find|ptr-oaRowHeader|cptr-oaBlock,cptr-oaSiteDef,\n"
"    This function searches the specified block for a rowHeader with the specified siteDef pointer.\n"
"  Paramegers: (oaBlock,oaString)\n"
"    Calls: oaRowHeader* find(const oaBlock* block,const oaString& siteDefName)\n"
"    Signature: find|ptr-oaRowHeader|cptr-oaBlock,cref-oaString,\n"
"    This function searches the specified block for a rowHeader with the specified siteDefName .\n"
;

static PyObject*
oaRowHeader_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaBlock,oaSiteDef)
    {
        PyParamoaBlock p1;
        PyParamoaSiteDef p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaSiteDef_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaRowHeaderp result= (oaRowHeader::find(p1.Data(),p2.Data()));
            return PyoaRowHeader_FromoaRowHeader(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaString)
    {
        PyParamoaBlock p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaRowHeaderp result= (oaRowHeader::find(p1.Data(),p2.Data()));
            return PyoaRowHeader_FromoaRowHeader(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaRowHeader, function: find, Choices are:\n"
        "    (oaBlock,oaSiteDef)\n"
        "    (oaBlock,oaString)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaRowHeader_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaRowHeader_static_find,METH_VARARGS,oaRowHeader_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRowHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRowHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaRowHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRowHeader",
           (PyObject*)(&PyoaRowHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRowHeader\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaRowHeader_Type.tp_dict;
    for(method=oaRowHeader_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaRowHeaderModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaRowHeaderModTypeEnum_Convert(PyObject* ob,PyParamoaRowHeaderModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacBindRowHeaderModType")==0) { result->SetData(oacBindRowHeaderModType); return 1;}
        if (strcasecmp(str,"oacUnbindRowHeaderModType")==0) { result->SetData(oacUnbindRowHeaderModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaRowHeaderModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRowHeaderModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaRowHeaderModTypeEnum_FromoaRowHeaderModTypeEnum(oaRowHeaderModTypeEnum ob)
{
    if (ob==oacBindRowHeaderModType) return PyString_FromString("oacBindRowHeaderModType");
    if (ob==oacUnbindRowHeaderModType) return PyString_FromString("oacUnbindRowHeaderModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaRowHeaderModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaRowHeaderModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaRowHeaderModTypeEnum_FromoaRowHeaderModTypeEnum(oaRowHeaderModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaRowHeaderModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaRowHeaderModTypeEnum_doc[] =
"Type convert function for enum: oaRowHeaderModTypeEnum";
                               
static PyMethodDef PyoaRowHeaderModTypeEnum_method =
  {"oaRowHeaderModTypeEnum",(PyCFunction)PyoaRowHeaderModTypeEnum_TypeFunction,METH_VARARGS,oaRowHeaderModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaRowHeaderModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacBindRowHeaderModType");
    PyDict_SetItemString(mod_dict,"oacBindRowHeaderModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacUnbindRowHeaderModType");
    PyDict_SetItemString(mod_dict,"oacUnbindRowHeaderModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaRowHeaderModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaRowHeaderModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaRowHeaderModTypeEnum\n");
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
// Wrapper Implementation for Class: oaRowModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaRowModTypeEnum_Convert(PyObject* ob,PyParamoaRowModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetRowHeaderRowModType")==0) { result->SetData(oacSetRowHeaderRowModType); return 1;}
        if (strcasecmp(str,"oacSetNameRowModType")==0) { result->SetData(oacSetNameRowModType); return 1;}
        if (strcasecmp(str,"oacSetTransformRowModType")==0) { result->SetData(oacSetTransformRowModType); return 1;}
        if (strcasecmp(str,"oacSetNumSitesRowModType")==0) { result->SetData(oacSetNumSitesRowModType); return 1;}
        if (strcasecmp(str,"oacSetSiteSpacingRowModType")==0) { result->SetData(oacSetSiteSpacingRowModType); return 1;}
        if (strcasecmp(str,"oacAddToFigGroupRowModType")==0) { result->SetData(oacAddToFigGroupRowModType); return 1;}
        if (strcasecmp(str,"oacRemoveFromFigGroupRowModType")==0) { result->SetData(oacRemoveFromFigGroupRowModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaRowModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRowModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaRowModTypeEnum_FromoaRowModTypeEnum(oaRowModTypeEnum ob)
{
    if (ob==oacSetRowHeaderRowModType) return PyString_FromString("oacSetRowHeaderRowModType");
    if (ob==oacSetNameRowModType) return PyString_FromString("oacSetNameRowModType");
    if (ob==oacSetTransformRowModType) return PyString_FromString("oacSetTransformRowModType");
    if (ob==oacSetNumSitesRowModType) return PyString_FromString("oacSetNumSitesRowModType");
    if (ob==oacSetSiteSpacingRowModType) return PyString_FromString("oacSetSiteSpacingRowModType");
    if (ob==oacAddToFigGroupRowModType) return PyString_FromString("oacAddToFigGroupRowModType");
    if (ob==oacRemoveFromFigGroupRowModType) return PyString_FromString("oacRemoveFromFigGroupRowModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaRowModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaRowModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaRowModTypeEnum_FromoaRowModTypeEnum(oaRowModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaRowModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaRowModTypeEnum_doc[] =
"Type convert function for enum: oaRowModTypeEnum";
                               
static PyMethodDef PyoaRowModTypeEnum_method =
  {"oaRowModTypeEnum",(PyCFunction)PyoaRowModTypeEnum_TypeFunction,METH_VARARGS,oaRowModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaRowModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetRowHeaderRowModType");
    PyDict_SetItemString(mod_dict,"oacSetRowHeaderRowModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetNameRowModType");
    PyDict_SetItemString(mod_dict,"oacSetNameRowModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetTransformRowModType");
    PyDict_SetItemString(mod_dict,"oacSetTransformRowModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetNumSitesRowModType");
    PyDict_SetItemString(mod_dict,"oacSetNumSitesRowModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetSiteSpacingRowModType");
    PyDict_SetItemString(mod_dict,"oacSetSiteSpacingRowModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAddToFigGroupRowModType");
    PyDict_SetItemString(mod_dict,"oacAddToFigGroupRowModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRemoveFromFigGroupRowModType");
    PyDict_SetItemString(mod_dict,"oacRemoveFromFigGroupRowModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaRowModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaRowModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaRowModTypeEnum\n");
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
// Wrapper Implementation for Class: oaRowQuery
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRowQuery_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRowQuery_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRowQueryObject* self = (PyoaRowQueryObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    if (is_raw) {
        PyErr_SetString(PyExc_TypeError,
            "No Constructor for pure-virtual class: oaRowQuery");
    }
    else {
        pyv_oaRowQuery* p = new pyv_oaRowQuery();
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
oaRowQuery_tp_dealloc(PyoaRowQueryObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRowQuery_tp_repr(PyObject *ob)
{
    PyParamoaRowQuery value;
    int convert_status=PyoaRowQuery_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[32];
    sprintf(buffer,"<oaRowQuery::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRowQuery_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRowQuery v1;
    PyParamoaRowQuery v2;
    int convert_status1=PyoaRowQuery_Convert(ob1,&v1);
    int convert_status2=PyoaRowQuery_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRowQuery_Convert(PyObject* ob,PyParamoaRowQuery* result)
{
    if (ob == NULL) return 1;
    if (PyoaRowQuery_Check(ob)) {
        result->SetData( (oaRowQuery*) ((PyoaRowQueryObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRowQuery Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRowQuery_FromoaRowQuery(oaRowQuery* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaRowQuery_Type.tp_alloc(&PyoaRowQuery_Type,0);
        if (bself == NULL) return bself;
        PyoaRowQueryObject* self = (PyoaRowQueryObject*)bself;
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
pyv_oaRowQuery::pyv_oaRowQuery()
 : pyob(NULL),
   oaRowQuery()
{
}

// ------------------------------------------------------------------
pyv_oaRowQuery::pyv_oaRowQuery(const oaRowQuery& p)
 : pyob(NULL),
   oaRowQuery(p)
{
}

// ------------------------------------------------------------------
void pyv_oaRowQuery::queryRow(oaRow* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"queryRow");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaRowQuery::queryRow was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaRow_FromoaRow(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaRowQuery::queryRow had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaRowQuery::endRef(oaRef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaRowQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaRowQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaRowQuery::endRef(oaRef* p1,oaUInt4 p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaRowQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaRowQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaRowQuery::endRef(oaRef* p1,oaUInt4 p2,oaUInt4 p3)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaRowQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(3);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyTuple_SetItem(args,2,PyoaUInt4_FromoaUInt4(p3));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaRowQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
oaBoolean pyv_oaRowQuery::startRef(oaRef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaRowQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaRowQuery::startRef had an error.");
    }
    PyParamoaBoolean rv;
    if (PyoaBoolean_Convert(result,&rv)==0) {
        throw oaPythonException("Python Virtual Function oaBoolean::startRef has incorrect return type.");
    }
    Py_DECREF(result);
    return rv.Data();
}

// ------------------------------------------------------------------
oaBoolean pyv_oaRowQuery::startRef(oaRef* p1,oaUInt4 p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaRowQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaRowQuery::startRef had an error.");
    }
    PyParamoaBoolean rv;
    if (PyoaBoolean_Convert(result,&rv)==0) {
        throw oaPythonException("Python Virtual Function oaBoolean::startRef has incorrect return type.");
    }
    Py_DECREF(result);
    return rv.Data();
}

// ------------------------------------------------------------------
oaBoolean pyv_oaRowQuery::startRef(oaRef* p1,oaUInt4 p2,oaUInt4 p3)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaRowQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(3);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyTuple_SetItem(args,2,PyoaUInt4_FromoaUInt4(p3));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaRowQuery::startRef had an error.");
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
static char oaRowQuery_query_doc[] = 
"Class: oaRowQuery, Function: query\n"
"  Paramegers: (oaDesign,oaBox)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating rows in the specified region of the specified design hierarchy.\n"
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
"    This function begins the query process to start generating rows in the specified region of the specified design hierarchy.\n"
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
"    This function begins the query process to start generating rows in the specified region of the specified design hierarchy.\n"
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
"    This function begins the query process to start generating rows in the specified region of the specified design hierarchy.\n"
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
"    This function begins the query process to start generating rows in the specified region of the specified design hierarchy.\n"
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
"    The level of block hierarchy to start the querying\n"
"  Paramegers: (oaDesign,oaBox,oaTransform,oaDist)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region,const oaTransform& xform,oaDist filterSize)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,cref-oaTransform,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating rows in the specified region of the specified design hierarchy.\n"
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
"    The level of block hierarchy to start the querying\n"
"  Paramegers: (oaDesign,oaBox,oaTransform,oaDist,oaUInt4)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region,const oaTransform& xform,oaDist filterSize,oaUInt4 startLevel)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,cref-oaTransform,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating rows in the specified region of the specified design hierarchy.\n"
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
"    The level of block hierarchy to start the querying\n"
"  Paramegers: (oaDesign,oaBox,oaTransform,oaDist,oaUInt4,oaUInt4)\n"
"    Calls: void query(oaDesign* topDesign,const oaBox& region,const oaTransform& xform,oaDist filterSize,oaUInt4 startLevel,oaUInt4 stopLevel)\n"
"    Signature: query|void-void|ptr-oaDesign,cref-oaBox,cref-oaTransform,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating rows in the specified region of the specified design hierarchy.\n"
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
"    The level of block hierarchy to start the querying\n"
;

static PyObject*
oaRowQuery_query(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRowQuery data;
    int convert_status=PyoaRowQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowQueryObject* self=(PyoaRowQueryObject*)ob;

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
        "No Arg-Matching Function found for class: oaRowQuery, function: query, Choices are:\n"
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
static char oaRowQuery_queryRow_doc[] = 
"Class: oaRowQuery, Function: queryRow\n"
"  Paramegers: (oaRow)\n"
"    Calls: virtual void queryRow(oaRow* row)\n"
"    Signature: queryRow|void-void|ptr-oaRow,\n"
"    This function processes each result of the row query.\n"
"    row\n"
"    Pointer to the oaRow object that is being queried\n"
;

static PyObject*
oaRowQuery_queryRow(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRowQuery data;
    int convert_status=PyoaRowQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowQueryObject* self=(PyoaRowQueryObject*)ob;

    PyParamoaRow p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRow_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        PyErr_SetString(PyExc_TypeError,
            "Call to Pure-Virtual Function class: oaRowQuery, function: queryRow");
            return NULL;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaRowQuery_assign_doc[] = 
"Class: oaRowQuery, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRowQuery_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRowQuery data;
  int convert_status=PyoaRowQuery_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRowQuery p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRowQuery_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRowQuery_methodlist[] = {
    {"query",(PyCFunction)oaRowQuery_query,METH_VARARGS,oaRowQuery_query_doc},
    {"queryRow",(PyCFunction)oaRowQuery_queryRow,METH_VARARGS,oaRowQuery_queryRow_doc},
    {"assign",(PyCFunction)oaRowQuery_tp_assign,METH_VARARGS,oaRowQuery_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRowQuery_doc[] = 
"Class: oaRowQuery\n"
"  The oaRowQuery class implements functionality to query a specified region in a design hierarchy and quickly return all rows that overlap the region.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaRowQuery()\n"
"    Signature: oaRowQuery||\n"
"    The constructor of oaRowQuery.\n"
"  Paramegers: (oaRowQuery)\n"
"    Calls: (const oaRowQuery&)\n"
"    Signature: oaRowQuery||cref-oaRowQuery,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRowQuery_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRowQuery",
    sizeof(PyoaRowQueryObject),
    0,
    (destructor)oaRowQuery_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRowQuery_tp_compare,	/* tp_compare */
    (reprfunc)oaRowQuery_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRowQuery_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRowQuery_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaRegionQuery_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRowQuery_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRowQuery_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRowQuery_Type)<0) {
      printf("** PyType_Ready failed for: oaRowQuery\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRowQuery",
           (PyObject*)(&PyoaRowQuery_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRowQuery\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaRowSpacingType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaRowSpacingType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaRowSpacingType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaRowSpacingTypeObject* self = (PyoaRowSpacingTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaRowSpacingTypeEnum)
    {
        PyParamoaRowSpacingTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaRowSpacingTypeEnum_Convert,&p1)) {
            self->value =  new oaRowSpacingType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaRowSpacingType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaRowSpacingType)
    {
        PyParamoaRowSpacingType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaRowSpacingType_Convert,&p1)) {
            self->value= new oaRowSpacingType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaRowSpacingType, Choices are:\n"
        "    (oaRowSpacingTypeEnum)\n"
        "    (oaString)\n"
        "    (oaRowSpacingType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaRowSpacingType_tp_dealloc(PyoaRowSpacingTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaRowSpacingType_tp_repr(PyObject *ob)
{
    PyParamoaRowSpacingType value;
    int convert_status=PyoaRowSpacingType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[38];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaRowSpacingType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaRowSpacingType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaRowSpacingType v1;
    PyParamoaRowSpacingType v2;
    int convert_status1=PyoaRowSpacingType_Convert(ob1,&v1);
    int convert_status2=PyoaRowSpacingType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaRowSpacingType_Convert(PyObject* ob,PyParamoaRowSpacingType* result)
{
    if (ob == NULL) return 1;
    if (PyoaRowSpacingType_Check(ob)) {
        result->SetData(  ((PyoaRowSpacingTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRowSpacingType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaRowSpacingType_FromoaRowSpacingType(oaRowSpacingType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaRowSpacingType_Type.tp_alloc(&PyoaRowSpacingType_Type,0);
        if (bself == NULL) return bself;
        PyoaRowSpacingTypeObject* self = (PyoaRowSpacingTypeObject*)bself;
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
static char oaRowSpacingType_getName_doc[] = 
"Class: oaRowSpacingType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaRowSpacingTypeEnum object.\n"
;

static PyObject*
oaRowSpacingType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRowSpacingType data;
    int convert_status=PyoaRowSpacingType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowSpacingTypeObject* self=(PyoaRowSpacingTypeObject*)ob;

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
static char oaRowSpacingType_oaRowSpacingTypeEnum_doc[] = 
"Class: oaRowSpacingType, Function: oaRowSpacingTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaRowSpacingTypeEnum oaRowSpacingTypeEnum() const\n"
"    Signature: operator oaRowSpacingTypeEnum|simple-oaRowSpacingTypeEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaRowSpacingType object into the corresponding #oaRowSpacingTypeEnum value.\n"
;

static PyObject*
oaRowSpacingType_oaRowSpacingTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaRowSpacingType data;
    int convert_status=PyoaRowSpacingType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaRowSpacingTypeObject* self=(PyoaRowSpacingTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaRowSpacingTypeEnum result= (data.DataCall()->operator oaRowSpacingTypeEnum());
        return PyoaRowSpacingTypeEnum_FromoaRowSpacingTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaRowSpacingType_assign_doc[] = 
"Class: oaRowSpacingType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaRowSpacingType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaRowSpacingType data;
  int convert_status=PyoaRowSpacingType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaRowSpacingType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaRowSpacingType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaRowSpacingType_methodlist[] = {
    {"getName",(PyCFunction)oaRowSpacingType_getName,METH_VARARGS,oaRowSpacingType_getName_doc},
    {"oaRowSpacingTypeEnum",(PyCFunction)oaRowSpacingType_oaRowSpacingTypeEnum,METH_VARARGS,oaRowSpacingType_oaRowSpacingTypeEnum_doc},
    {"assign",(PyCFunction)oaRowSpacingType_tp_assign,METH_VARARGS,oaRowSpacingType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaRowSpacingType_doc[] = 
"Class: oaRowSpacingType\n"
"  The oaRowSpacingType class is an enum wrapper that indicates which rows the extra spacing between rows in an oaCoreBoxSpec applies to. See oaCoreBoxSpec::setRowSpacingType for an example of its use.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaRowSpacingTypeEnum\n"
"Constructors:\n"
"  Paramegers: (oaRowSpacingTypeEnum)\n"
"    Calls: oaRowSpacingType(oaRowSpacingTypeEnum typeIn)\n"
"    Signature: oaRowSpacingType||simple-oaRowSpacingTypeEnum,\n"
"    This function constructs an instance of an oaRowSpacingType object using the specified #oaRowSpacingTypeEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaRowSpacingType(const oaString& name)\n"
"    Signature: oaRowSpacingType||cref-oaString,\n"
"    This function constructs an instance of an oaRowSpacingType class using the #oaRowSpacingTypeEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaRowSpacingTypeEnum.\n"
"    oacInvalidRowSpacingTypeName\n"
"  Paramegers: (oaRowSpacingType)\n"
"    Calls: (const oaRowSpacingType&)\n"
"    Signature: oaRowSpacingType||cref-oaRowSpacingType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaRowSpacingType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaRowSpacingType",
    sizeof(PyoaRowSpacingTypeObject),
    0,
    (destructor)oaRowSpacingType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaRowSpacingType_tp_compare,	/* tp_compare */
    (reprfunc)oaRowSpacingType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaRowSpacingType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaRowSpacingType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaRowSpacingType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaRowSpacingType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaRowSpacingType_Type)<0) {
      printf("** PyType_Ready failed for: oaRowSpacingType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaRowSpacingType",
           (PyObject*)(&PyoaRowSpacingType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaRowSpacingType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaRowSpacingTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaRowSpacingTypeEnum_Convert(PyObject* ob,PyParamoaRowSpacingTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacEveryRowSpacingType")==0) { result->SetData(oacEveryRowSpacingType); return 1;}
        if (strcasecmp(str,"oacEvenRowSpacingType")==0) { result->SetData(oacEvenRowSpacingType); return 1;}
        if (strcasecmp(str,"oacOddRowSpacingType")==0) { result->SetData(oacOddRowSpacingType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaRowSpacingTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaRowSpacingTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaRowSpacingTypeEnum_FromoaRowSpacingTypeEnum(oaRowSpacingTypeEnum ob)
{
    if (ob==oacEveryRowSpacingType) return PyString_FromString("oacEveryRowSpacingType");
    if (ob==oacEvenRowSpacingType) return PyString_FromString("oacEvenRowSpacingType");
    if (ob==oacOddRowSpacingType) return PyString_FromString("oacOddRowSpacingType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaRowSpacingTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaRowSpacingTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaRowSpacingTypeEnum_FromoaRowSpacingTypeEnum(oaRowSpacingTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaRowSpacingTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaRowSpacingTypeEnum_doc[] =
"Type convert function for enum: oaRowSpacingTypeEnum";
                               
static PyMethodDef PyoaRowSpacingTypeEnum_method =
  {"oaRowSpacingTypeEnum",(PyCFunction)PyoaRowSpacingTypeEnum_TypeFunction,METH_VARARGS,oaRowSpacingTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaRowSpacingTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacEveryRowSpacingType");
    PyDict_SetItemString(mod_dict,"oacEveryRowSpacingType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacEvenRowSpacingType");
    PyDict_SetItemString(mod_dict,"oacEvenRowSpacingType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacOddRowSpacingType");
    PyDict_SetItemString(mod_dict,"oacOddRowSpacingType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaRowSpacingTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaRowSpacingTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaRowSpacingTypeEnum\n");
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
// Wrapper Implementation for Class: oaScalarInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaScalarInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaScalarInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaScalarInstObject* self = (PyoaScalarInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaScalarInst)
    {
        PyParamoaScalarInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaScalarInst_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaScalarInst, Choices are:\n"
        "    (oaScalarInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaScalarInst_tp_dealloc(PyoaScalarInstObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaScalarInst_tp_repr(PyObject *ob)
{
    PyParamoaScalarInst value;
    int convert_status=PyoaScalarInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaScalarInst::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaScalarName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[34];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaScalarInst::");
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
oaScalarInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaScalarInst v1;
    PyParamoaScalarInst v2;
    int convert_status1=PyoaScalarInst_Convert(ob1,&v1);
    int convert_status2=PyoaScalarInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaScalarInst_Convert(PyObject* ob,PyParamoaScalarInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaScalarInst_Check(ob)) {
        result->SetData( (oaScalarInst**) ((PyoaScalarInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaScalarInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaScalarInst_FromoaScalarInst(oaScalarInst** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaScalarInst* data=*value;
        PyObject* bself = PyoaScalarInst_Type.tp_alloc(&PyoaScalarInst_Type,0);
        if (bself == NULL) return bself;
        PyoaScalarInstObject* self = (PyoaScalarInstObject*)bself;
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
PyObject* PyoaScalarInst_FromoaScalarInst(oaScalarInst* data)
{
    if (data) {
       PyObject* bself = PyoaScalarInst_Type.tp_alloc(&PyoaScalarInst_Type,0);
       if (bself == NULL) return bself;
       PyoaScalarInstObject* self = (PyoaScalarInstObject*)bself;
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
static char oaScalarInst_getName_doc[] = 
"Class: oaScalarInst, Function: getName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getName(oaScalarName& name) const\n"
"    Signature: getName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the name of this scalarInst in the name argument.\n"
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
oaScalarInst_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarInst data;
    int convert_status=PyoaScalarInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScalarInstObject* self=(PyoaScalarInstObject*)ob;
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
        "No Arg-Matching Function found for class: oaScalarInst, function: getName, Choices are:\n"
        "    (oaScalarName)\n"
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
static char oaScalarInst_setName_doc[] = 
"Class: oaScalarInst, Function: setName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void setName(const oaScalarName& name)\n"
"    Signature: setName|void-void|cref-oaScalarName,\n"
"    This function changes the name of this instance to the specified name .\n"
"    Exceptions are thrown if:\n"
"    the new name does not imply a scalar name\n"
"    an instance already exists with the given name\n"
"    a vectorInstDef exists with the given name\n"
"    oacInvalidHierInstName\n"
"    oacInstNameExists\n"
"    oacInstNameOverlapsOtherInst\n"
;

static PyObject*
oaScalarInst_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarInst data;
    int convert_status=PyoaScalarInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScalarInstObject* self=(PyoaScalarInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaScalarName p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaScalarName_Convert,&p1)) {
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
static char oaScalarInst_isNull_doc[] =
"Class: oaScalarInst, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaScalarInst_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaScalarInst data;
    int convert_status=PyoaScalarInst_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaScalarInst_assign_doc[] = 
"Class: oaScalarInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaScalarInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaScalarInst data;
  int convert_status=PyoaScalarInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaScalarInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaScalarInst_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaScalarInst_methodlist[] = {
    {"getName",(PyCFunction)oaScalarInst_getName,METH_VARARGS,oaScalarInst_getName_doc},
    {"setName",(PyCFunction)oaScalarInst_setName,METH_VARARGS,oaScalarInst_setName_doc},
    {"isNull",(PyCFunction)oaScalarInst_tp_isNull,METH_VARARGS,oaScalarInst_isNull_doc},
    {"assign",(PyCFunction)oaScalarInst_tp_assign,METH_VARARGS,oaScalarInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaScalarInst_doc[] = 
"Class: oaScalarInst\n"
"  The oaScalarInst class implements a scalar (single-bit) instance. This is the most common kind of instance. This class has a simple name with no index.\n"
"  oaScalarInst objects are always in the block domain. They may be physical-only instances that are only in the block hierarchy, or they can be cross-domain instances that directly correspond to an oaModScalarInst in the module domain and an oaOccScalarInst in the occurrence domain.\n"
"Constructors:\n"
"  Paramegers: (oaScalarInst)\n"
"    Calls: (const oaScalarInst&)\n"
"    Signature: oaScalarInst||cref-oaScalarInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaScalarInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaScalarInst",
    sizeof(PyoaScalarInstObject),
    0,
    (destructor)oaScalarInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaScalarInst_tp_compare,	/* tp_compare */
    (reprfunc)oaScalarInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaScalarInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaScalarInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBitInst_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaScalarInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaScalarInst_static_create_doc[] = 
"Class: oaScalarInst, Function: create\n"
"  Paramegers: (oaBlock,oaDesign,oaScalarName,oaTransform)\n"
"    Calls: oaScalarInst* create(oaBlock* block,oaDesign* master,const oaScalarName& name,const oaTransform& xform)\n"
"    Signature: create|ptr-oaScalarInst|ptr-oaBlock,ptr-oaDesign,cref-oaScalarName,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,\n"
"    This function create an oaScalarInst object with the specified attributes. This function lets you specify the master design and name for the new instance. Exceptions are thrown if:\n"
"    the new name does not imply a scalar name\n"
"    an instance already exists with the given name\n"
"    a vectorInstDef exist with the given name\n"
"    block\n"
"    The block in which to create the instance\n"
"    master\n"
"    A pointer to the instance master\n"
"    name\n"
"    The instance name\n"
"    xform\n"
"    The transform for the instance\n"
"    params\n"
"    Optional parameter array for pCell instances\n"
"    view\n"
"    Specifies whether this instance is visible in the module domain\n"
"    status\n"
"    Specifies the placement status of this instance\n"
"    oacInvalidSuperMaster\n"
"    oacParamsSuppliedForNonPCellInstMaster\n"
"    oacInvalidHierInstName\n"
"    oacInstNameExists\n"
"    oacInstNameOverlapsOtherInst\n"
"  Paramegers: (oaBlock,oaDesign,oaScalarName,oaTransform,oaParamArray)\n"
"    Calls: oaScalarInst* create(oaBlock* block,oaDesign* master,const oaScalarName& name,const oaTransform& xform,const oaParamArray* params)\n"
"    Signature: create|ptr-oaScalarInst|ptr-oaBlock,ptr-oaDesign,cref-oaScalarName,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,\n"
"    This function create an oaScalarInst object with the specified attributes. This function lets you specify the master design and name for the new instance. Exceptions are thrown if:\n"
"    the new name does not imply a scalar name\n"
"    an instance already exists with the given name\n"
"    a vectorInstDef exist with the given name\n"
"    block\n"
"    The block in which to create the instance\n"
"    master\n"
"    A pointer to the instance master\n"
"    name\n"
"    The instance name\n"
"    xform\n"
"    The transform for the instance\n"
"    params\n"
"    Optional parameter array for pCell instances\n"
"    view\n"
"    Specifies whether this instance is visible in the module domain\n"
"    status\n"
"    Specifies the placement status of this instance\n"
"    oacInvalidSuperMaster\n"
"    oacParamsSuppliedForNonPCellInstMaster\n"
"    oacInvalidHierInstName\n"
"    oacInstNameExists\n"
"    oacInstNameOverlapsOtherInst\n"
"  Paramegers: (oaBlock,oaDesign,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility)\n"
"    Calls: oaScalarInst* create(oaBlock* block,oaDesign* master,const oaScalarName& name,const oaTransform& xform,const oaParamArray* params,oaBlockDomainVisibility view)\n"
"    Signature: create|ptr-oaScalarInst|ptr-oaBlock,ptr-oaDesign,cref-oaScalarName,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,\n"
"    This function create an oaScalarInst object with the specified attributes. This function lets you specify the master design and name for the new instance. Exceptions are thrown if:\n"
"    the new name does not imply a scalar name\n"
"    an instance already exists with the given name\n"
"    a vectorInstDef exist with the given name\n"
"    block\n"
"    The block in which to create the instance\n"
"    master\n"
"    A pointer to the instance master\n"
"    name\n"
"    The instance name\n"
"    xform\n"
"    The transform for the instance\n"
"    params\n"
"    Optional parameter array for pCell instances\n"
"    view\n"
"    Specifies whether this instance is visible in the module domain\n"
"    status\n"
"    Specifies the placement status of this instance\n"
"    oacInvalidSuperMaster\n"
"    oacParamsSuppliedForNonPCellInstMaster\n"
"    oacInvalidHierInstName\n"
"    oacInstNameExists\n"
"    oacInstNameOverlapsOtherInst\n"
"  Paramegers: (oaBlock,oaDesign,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility,oaPlacementStatus)\n"
"    Calls: oaScalarInst* create(oaBlock* block,oaDesign* master,const oaScalarName& name,const oaTransform& xform,const oaParamArray* params,oaBlockDomainVisibility view,oaPlacementStatus status)\n"
"    Signature: create|ptr-oaScalarInst|ptr-oaBlock,ptr-oaDesign,cref-oaScalarName,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,\n"
"    This function create an oaScalarInst object with the specified attributes. This function lets you specify the master design and name for the new instance. Exceptions are thrown if:\n"
"    the new name does not imply a scalar name\n"
"    an instance already exists with the given name\n"
"    a vectorInstDef exist with the given name\n"
"    block\n"
"    The block in which to create the instance\n"
"    master\n"
"    A pointer to the instance master\n"
"    name\n"
"    The instance name\n"
"    xform\n"
"    The transform for the instance\n"
"    params\n"
"    Optional parameter array for pCell instances\n"
"    view\n"
"    Specifies whether this instance is visible in the module domain\n"
"    status\n"
"    Specifies the placement status of this instance\n"
"    oacInvalidSuperMaster\n"
"    oacParamsSuppliedForNonPCellInstMaster\n"
"    oacInvalidHierInstName\n"
"    oacInstNameExists\n"
"    oacInstNameOverlapsOtherInst\n"
"  Paramegers: (oaBlock,oaDesign,oaTransform)\n"
"    Calls: oaScalarInst* create(oaBlock* block,oaDesign* master,const oaTransform& xform)\n"
"    Signature: create|ptr-oaScalarInst|ptr-oaBlock,ptr-oaDesign,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,\n"
"    This function create an oaScalarInst object with the specified attributes. This function lets you specify the master design. A name for the new instance is automatically generated.\n"
"    block\n"
"    The block in which to create the instance\n"
"    master\n"
"    A pointer to the instance master\n"
"    xform\n"
"    The transform for the instance\n"
"    params\n"
"    Optional parameter array for pCell instances\n"
"    view\n"
"    Specifies whether this instance is visible in the module domain\n"
"    status\n"
"    Specifies the placement status of this instance\n"
"    oacInvalidSuperMaster\n"
"    oacParamsSuppliedForNonPCellInstMaster\n"
"  Paramegers: (oaBlock,oaDesign,oaTransform,oaParamArray)\n"
"    Calls: oaScalarInst* create(oaBlock* block,oaDesign* master,const oaTransform& xform,const oaParamArray* params)\n"
"    Signature: create|ptr-oaScalarInst|ptr-oaBlock,ptr-oaDesign,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,\n"
"    This function create an oaScalarInst object with the specified attributes. This function lets you specify the master design. A name for the new instance is automatically generated.\n"
"    block\n"
"    The block in which to create the instance\n"
"    master\n"
"    A pointer to the instance master\n"
"    xform\n"
"    The transform for the instance\n"
"    params\n"
"    Optional parameter array for pCell instances\n"
"    view\n"
"    Specifies whether this instance is visible in the module domain\n"
"    status\n"
"    Specifies the placement status of this instance\n"
"    oacInvalidSuperMaster\n"
"    oacParamsSuppliedForNonPCellInstMaster\n"
"  Paramegers: (oaBlock,oaDesign,oaTransform,oaParamArray,oaBlockDomainVisibility)\n"
"    Calls: oaScalarInst* create(oaBlock* block,oaDesign* master,const oaTransform& xform,const oaParamArray* params,oaBlockDomainVisibility view)\n"
"    Signature: create|ptr-oaScalarInst|ptr-oaBlock,ptr-oaDesign,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,\n"
"    This function create an oaScalarInst object with the specified attributes. This function lets you specify the master design. A name for the new instance is automatically generated.\n"
"    block\n"
"    The block in which to create the instance\n"
"    master\n"
"    A pointer to the instance master\n"
"    xform\n"
"    The transform for the instance\n"
"    params\n"
"    Optional parameter array for pCell instances\n"
"    view\n"
"    Specifies whether this instance is visible in the module domain\n"
"    status\n"
"    Specifies the placement status of this instance\n"
"    oacInvalidSuperMaster\n"
"    oacParamsSuppliedForNonPCellInstMaster\n"
"  Paramegers: (oaBlock,oaDesign,oaTransform,oaParamArray,oaBlockDomainVisibility,oaPlacementStatus)\n"
"    Calls: oaScalarInst* create(oaBlock* block,oaDesign* master,const oaTransform& xform,const oaParamArray* params,oaBlockDomainVisibility view,oaPlacementStatus status)\n"
"    Signature: create|ptr-oaScalarInst|ptr-oaBlock,ptr-oaDesign,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,\n"
"    This function create an oaScalarInst object with the specified attributes. This function lets you specify the master design. A name for the new instance is automatically generated.\n"
"    block\n"
"    The block in which to create the instance\n"
"    master\n"
"    A pointer to the instance master\n"
"    xform\n"
"    The transform for the instance\n"
"    params\n"
"    Optional parameter array for pCell instances\n"
"    view\n"
"    Specifies whether this instance is visible in the module domain\n"
"    status\n"
"    Specifies the placement status of this instance\n"
"    oacInvalidSuperMaster\n"
"    oacParamsSuppliedForNonPCellInstMaster\n"
"  Paramegers: (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaScalarName,oaTransform)\n"
"    Calls: oaScalarInst* create(oaBlock* block,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName,const oaScalarName& name,const oaTransform& xform)\n"
"    Signature: create|ptr-oaScalarInst|ptr-oaBlock,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,\n"
"    This function creates an oaScalarInst object with the specified attributes. The name for the instance is specified. Exceptions are thrown if:\n"
"    the new name does not imply a scalar name\n"
"    an instance already exists with the given name\n"
"    a vectorInstDef exists with the given name\n"
"    block\n"
"    The block in which to create the instance\n"
"    libName\n"
"    The libName of the instance master\n"
"    cellName\n"
"    The cellName of the instance master\n"
"    viewName\n"
"    The viewName of the instance master\n"
"    name\n"
"    The instance name\n"
"    xform\n"
"    The transform for the instance\n"
"    params\n"
"    Optional parameter array for pCell instances\n"
"    view\n"
"    Specifies whether this instance is visible in the module domain\n"
"    status\n"
"    Specifies the placement status of this instance\n"
"    oacParamsSuppliedForNonPCellInstMaster\n"
"    oacInvalidHierInstName\n"
"    oacInstNameExists\n"
"    oacInstNameOverlapsOtherInst\n"
"  Paramegers: (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray)\n"
"    Calls: oaScalarInst* create(oaBlock* block,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName,const oaScalarName& name,const oaTransform& xform,const oaParamArray* params)\n"
"    Signature: create|ptr-oaScalarInst|ptr-oaBlock,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,\n"
"    This function creates an oaScalarInst object with the specified attributes. The name for the instance is specified. Exceptions are thrown if:\n"
"    the new name does not imply a scalar name\n"
"    an instance already exists with the given name\n"
"    a vectorInstDef exists with the given name\n"
"    block\n"
"    The block in which to create the instance\n"
"    libName\n"
"    The libName of the instance master\n"
"    cellName\n"
"    The cellName of the instance master\n"
"    viewName\n"
"    The viewName of the instance master\n"
"    name\n"
"    The instance name\n"
"    xform\n"
"    The transform for the instance\n"
"    params\n"
"    Optional parameter array for pCell instances\n"
"    view\n"
"    Specifies whether this instance is visible in the module domain\n"
"    status\n"
"    Specifies the placement status of this instance\n"
"    oacParamsSuppliedForNonPCellInstMaster\n"
"    oacInvalidHierInstName\n"
"    oacInstNameExists\n"
"    oacInstNameOverlapsOtherInst\n"
"  Paramegers: (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility)\n"
"    Calls: oaScalarInst* create(oaBlock* block,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName,const oaScalarName& name,const oaTransform& xform,const oaParamArray* params,oaBlockDomainVisibility view)\n"
"    Signature: create|ptr-oaScalarInst|ptr-oaBlock,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,\n"
"    This function creates an oaScalarInst object with the specified attributes. The name for the instance is specified. Exceptions are thrown if:\n"
"    the new name does not imply a scalar name\n"
"    an instance already exists with the given name\n"
"    a vectorInstDef exists with the given name\n"
"    block\n"
"    The block in which to create the instance\n"
"    libName\n"
"    The libName of the instance master\n"
"    cellName\n"
"    The cellName of the instance master\n"
"    viewName\n"
"    The viewName of the instance master\n"
"    name\n"
"    The instance name\n"
"    xform\n"
"    The transform for the instance\n"
"    params\n"
"    Optional parameter array for pCell instances\n"
"    view\n"
"    Specifies whether this instance is visible in the module domain\n"
"    status\n"
"    Specifies the placement status of this instance\n"
"    oacParamsSuppliedForNonPCellInstMaster\n"
"    oacInvalidHierInstName\n"
"    oacInstNameExists\n"
"    oacInstNameOverlapsOtherInst\n"
"  Paramegers: (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility,oaPlacementStatus)\n"
"    Calls: oaScalarInst* create(oaBlock* block,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName,const oaScalarName& name,const oaTransform& xform,const oaParamArray* params,oaBlockDomainVisibility view,oaPlacementStatus status)\n"
"    Signature: create|ptr-oaScalarInst|ptr-oaBlock,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,\n"
"    This function creates an oaScalarInst object with the specified attributes. The name for the instance is specified. Exceptions are thrown if:\n"
"    the new name does not imply a scalar name\n"
"    an instance already exists with the given name\n"
"    a vectorInstDef exists with the given name\n"
"    block\n"
"    The block in which to create the instance\n"
"    libName\n"
"    The libName of the instance master\n"
"    cellName\n"
"    The cellName of the instance master\n"
"    viewName\n"
"    The viewName of the instance master\n"
"    name\n"
"    The instance name\n"
"    xform\n"
"    The transform for the instance\n"
"    params\n"
"    Optional parameter array for pCell instances\n"
"    view\n"
"    Specifies whether this instance is visible in the module domain\n"
"    status\n"
"    Specifies the placement status of this instance\n"
"    oacParamsSuppliedForNonPCellInstMaster\n"
"    oacInvalidHierInstName\n"
"    oacInstNameExists\n"
"    oacInstNameOverlapsOtherInst\n"
"  Paramegers: (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaTransform)\n"
"    Calls: oaScalarInst* create(oaBlock* block,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName,const oaTransform& xform)\n"
"    Signature: create|ptr-oaScalarInst|ptr-oaBlock,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,\n"
"    This function creates an oaScalarInst object with the specified attributes. The name for the instance is generated automatically by this create function, with the default name prefix I__%d, where d refers to an integer it will generate to make this name unique.\n"
"    block\n"
"    The block in which to create the instance\n"
"    libName\n"
"    The libName of the instance master\n"
"    cellName\n"
"    The cellName of the instance master\n"
"    viewName\n"
"    The viewName of the instance master\n"
"    xform\n"
"    The transform for the instance\n"
"    params\n"
"    Optional parameter array for pCell instances\n"
"    view\n"
"    Specifies whether this instance is visible in the module domain\n"
"    status\n"
"    Specifies the placement status of this instance\n"
"    oacParamsSuppliedForNonPCellInstMaster\n"
"  Paramegers: (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray)\n"
"    Calls: oaScalarInst* create(oaBlock* block,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName,const oaTransform& xform,const oaParamArray* params)\n"
"    Signature: create|ptr-oaScalarInst|ptr-oaBlock,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,\n"
"    This function creates an oaScalarInst object with the specified attributes. The name for the instance is generated automatically by this create function, with the default name prefix I__%d, where d refers to an integer it will generate to make this name unique.\n"
"    block\n"
"    The block in which to create the instance\n"
"    libName\n"
"    The libName of the instance master\n"
"    cellName\n"
"    The cellName of the instance master\n"
"    viewName\n"
"    The viewName of the instance master\n"
"    xform\n"
"    The transform for the instance\n"
"    params\n"
"    Optional parameter array for pCell instances\n"
"    view\n"
"    Specifies whether this instance is visible in the module domain\n"
"    status\n"
"    Specifies the placement status of this instance\n"
"    oacParamsSuppliedForNonPCellInstMaster\n"
"  Paramegers: (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility)\n"
"    Calls: oaScalarInst* create(oaBlock* block,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName,const oaTransform& xform,const oaParamArray* params,oaBlockDomainVisibility view)\n"
"    Signature: create|ptr-oaScalarInst|ptr-oaBlock,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,\n"
"    This function creates an oaScalarInst object with the specified attributes. The name for the instance is generated automatically by this create function, with the default name prefix I__%d, where d refers to an integer it will generate to make this name unique.\n"
"    block\n"
"    The block in which to create the instance\n"
"    libName\n"
"    The libName of the instance master\n"
"    cellName\n"
"    The cellName of the instance master\n"
"    viewName\n"
"    The viewName of the instance master\n"
"    xform\n"
"    The transform for the instance\n"
"    params\n"
"    Optional parameter array for pCell instances\n"
"    view\n"
"    Specifies whether this instance is visible in the module domain\n"
"    status\n"
"    Specifies the placement status of this instance\n"
"    oacParamsSuppliedForNonPCellInstMaster\n"
"  Paramegers: (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility,oaPlacementStatus)\n"
"    Calls: oaScalarInst* create(oaBlock* block,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName,const oaTransform& xform,const oaParamArray* params,oaBlockDomainVisibility view,oaPlacementStatus status)\n"
"    Signature: create|ptr-oaScalarInst|ptr-oaBlock,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,cref-oaTransform,cptr-oaParamArray,simple-oaBlockDomainVisibility,simple-oaPlacementStatus,\n"
"    This function creates an oaScalarInst object with the specified attributes. The name for the instance is generated automatically by this create function, with the default name prefix I__%d, where d refers to an integer it will generate to make this name unique.\n"
"    block\n"
"    The block in which to create the instance\n"
"    libName\n"
"    The libName of the instance master\n"
"    cellName\n"
"    The cellName of the instance master\n"
"    viewName\n"
"    The viewName of the instance master\n"
"    xform\n"
"    The transform for the instance\n"
"    params\n"
"    Optional parameter array for pCell instances\n"
"    view\n"
"    Specifies whether this instance is visible in the module domain\n"
"    status\n"
"    Specifies the placement status of this instance\n"
"    oacParamsSuppliedForNonPCellInstMaster\n"
;

static PyObject*
oaScalarInst_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaBlock,oaDesign,oaScalarName,oaTransform)
    {
        PyParamoaBlock p1;
        PyParamoaDesign p2;
        PyParamoaScalarName p3;
        PyParamoaTransform p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaDesign_Convert,&p2,
              &PyoaScalarName_Convert,&p3,
              &PyoaTransform_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaScalarInstp result= (oaScalarInst::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaScalarInst_FromoaScalarInst(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaDesign,oaScalarName,oaTransform,oaParamArray)
    {
        PyParamoaBlock p1;
        PyParamoaDesign p2;
        PyParamoaScalarName p3;
        PyParamoaTransform p4;
        PyParamoaParamArray p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaDesign_Convert,&p2,
              &PyoaScalarName_Convert,&p3,
              &PyoaTransform_Convert,&p4,
              &PyoaParamArray_ConvertAof,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaScalarInstp result= (oaScalarInst::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.DataAof()));
            return PyoaScalarInst_FromoaScalarInst(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaDesign,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility)
    {
        PyParamoaBlock p1;
        PyParamoaDesign p2;
        PyParamoaScalarName p3;
        PyParamoaTransform p4;
        PyParamoaParamArray p5;
        PyParamoaBlockDomainVisibility p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaDesign_Convert,&p2,
              &PyoaScalarName_Convert,&p3,
              &PyoaTransform_Convert,&p4,
              &PyoaParamArray_ConvertAof,&p5,
              &PyoaBlockDomainVisibility_Convert,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaScalarInstp result= (oaScalarInst::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.DataAof(),p6.Data()));
            return PyoaScalarInst_FromoaScalarInst(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaDesign,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility,oaPlacementStatus)
    {
        PyParamoaBlock p1;
        PyParamoaDesign p2;
        PyParamoaScalarName p3;
        PyParamoaTransform p4;
        PyParamoaParamArray p5;
        PyParamoaBlockDomainVisibility p6;
        PyParamoaPlacementStatus p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaDesign_Convert,&p2,
              &PyoaScalarName_Convert,&p3,
              &PyoaTransform_Convert,&p4,
              &PyoaParamArray_ConvertAof,&p5,
              &PyoaBlockDomainVisibility_Convert,&p6,
              &PyoaPlacementStatus_Convert,&p7)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaScalarInstp result= (oaScalarInst::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.DataAof(),p6.Data(),p7.Data()));
            return PyoaScalarInst_FromoaScalarInst(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaDesign,oaTransform)
    {
        PyParamoaBlock p1;
        PyParamoaDesign p2;
        PyParamoaTransform p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaDesign_Convert,&p2,
              &PyoaTransform_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaScalarInstp result= (oaScalarInst::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaScalarInst_FromoaScalarInst(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaDesign,oaTransform,oaParamArray)
    {
        PyParamoaBlock p1;
        PyParamoaDesign p2;
        PyParamoaTransform p3;
        PyParamoaParamArray p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaDesign_Convert,&p2,
              &PyoaTransform_Convert,&p3,
              &PyoaParamArray_ConvertAof,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaScalarInstp result= (oaScalarInst::create(p1.Data(),p2.Data(),p3.Data(),p4.DataAof()));
            return PyoaScalarInst_FromoaScalarInst(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaDesign,oaTransform,oaParamArray,oaBlockDomainVisibility)
    {
        PyParamoaBlock p1;
        PyParamoaDesign p2;
        PyParamoaTransform p3;
        PyParamoaParamArray p4;
        PyParamoaBlockDomainVisibility p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaDesign_Convert,&p2,
              &PyoaTransform_Convert,&p3,
              &PyoaParamArray_ConvertAof,&p4,
              &PyoaBlockDomainVisibility_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaScalarInstp result= (oaScalarInst::create(p1.Data(),p2.Data(),p3.Data(),p4.DataAof(),p5.Data()));
            return PyoaScalarInst_FromoaScalarInst(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaDesign,oaTransform,oaParamArray,oaBlockDomainVisibility,oaPlacementStatus)
    {
        PyParamoaBlock p1;
        PyParamoaDesign p2;
        PyParamoaTransform p3;
        PyParamoaParamArray p4;
        PyParamoaBlockDomainVisibility p5;
        PyParamoaPlacementStatus p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaDesign_Convert,&p2,
              &PyoaTransform_Convert,&p3,
              &PyoaParamArray_ConvertAof,&p4,
              &PyoaBlockDomainVisibility_Convert,&p5,
              &PyoaPlacementStatus_Convert,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaScalarInstp result= (oaScalarInst::create(p1.Data(),p2.Data(),p3.Data(),p4.DataAof(),p5.Data(),p6.Data()));
            return PyoaScalarInst_FromoaScalarInst(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaScalarName,oaTransform)
    {
        PyParamoaBlock p1;
        PyParamoaScalarName p2;
        PyParamoaScalarName p3;
        PyParamoaScalarName p4;
        PyParamoaScalarName p5;
        PyParamoaTransform p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaScalarName_Convert,&p3,
              &PyoaScalarName_Convert,&p4,
              &PyoaScalarName_Convert,&p5,
              &PyoaTransform_Convert,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarInstp result= (oaScalarInst::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data()));
            return PyoaScalarInst_FromoaScalarInst(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray)
    {
        PyParamoaBlock p1;
        PyParamoaScalarName p2;
        PyParamoaScalarName p3;
        PyParamoaScalarName p4;
        PyParamoaScalarName p5;
        PyParamoaTransform p6;
        PyParamoaParamArray p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaScalarName_Convert,&p3,
              &PyoaScalarName_Convert,&p4,
              &PyoaScalarName_Convert,&p5,
              &PyoaTransform_Convert,&p6,
              &PyoaParamArray_ConvertAof,&p7)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarInstp result= (oaScalarInst::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.DataAof()));
            return PyoaScalarInst_FromoaScalarInst(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility)
    {
        PyParamoaBlock p1;
        PyParamoaScalarName p2;
        PyParamoaScalarName p3;
        PyParamoaScalarName p4;
        PyParamoaScalarName p5;
        PyParamoaTransform p6;
        PyParamoaParamArray p7;
        PyParamoaBlockDomainVisibility p8;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaScalarName_Convert,&p3,
              &PyoaScalarName_Convert,&p4,
              &PyoaScalarName_Convert,&p5,
              &PyoaTransform_Convert,&p6,
              &PyoaParamArray_ConvertAof,&p7,
              &PyoaBlockDomainVisibility_Convert,&p8)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarInstp result= (oaScalarInst::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.DataAof(),p8.Data()));
            return PyoaScalarInst_FromoaScalarInst(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility,oaPlacementStatus)
    {
        PyParamoaBlock p1;
        PyParamoaScalarName p2;
        PyParamoaScalarName p3;
        PyParamoaScalarName p4;
        PyParamoaScalarName p5;
        PyParamoaTransform p6;
        PyParamoaParamArray p7;
        PyParamoaBlockDomainVisibility p8;
        PyParamoaPlacementStatus p9;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaScalarName_Convert,&p3,
              &PyoaScalarName_Convert,&p4,
              &PyoaScalarName_Convert,&p5,
              &PyoaTransform_Convert,&p6,
              &PyoaParamArray_ConvertAof,&p7,
              &PyoaBlockDomainVisibility_Convert,&p8,
              &PyoaPlacementStatus_Convert,&p9)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarInstp result= (oaScalarInst::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.DataAof(),p8.Data(),p9.Data()));
            return PyoaScalarInst_FromoaScalarInst(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaTransform)
    {
        PyParamoaBlock p1;
        PyParamoaScalarName p2;
        PyParamoaScalarName p3;
        PyParamoaScalarName p4;
        PyParamoaTransform p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaScalarName_Convert,&p3,
              &PyoaScalarName_Convert,&p4,
              &PyoaTransform_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarInstp result= (oaScalarInst::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaScalarInst_FromoaScalarInst(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray)
    {
        PyParamoaBlock p1;
        PyParamoaScalarName p2;
        PyParamoaScalarName p3;
        PyParamoaScalarName p4;
        PyParamoaTransform p5;
        PyParamoaParamArray p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaScalarName_Convert,&p3,
              &PyoaScalarName_Convert,&p4,
              &PyoaTransform_Convert,&p5,
              &PyoaParamArray_ConvertAof,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarInstp result= (oaScalarInst::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.DataAof()));
            return PyoaScalarInst_FromoaScalarInst(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility)
    {
        PyParamoaBlock p1;
        PyParamoaScalarName p2;
        PyParamoaScalarName p3;
        PyParamoaScalarName p4;
        PyParamoaTransform p5;
        PyParamoaParamArray p6;
        PyParamoaBlockDomainVisibility p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaScalarName_Convert,&p3,
              &PyoaScalarName_Convert,&p4,
              &PyoaTransform_Convert,&p5,
              &PyoaParamArray_ConvertAof,&p6,
              &PyoaBlockDomainVisibility_Convert,&p7)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarInstp result= (oaScalarInst::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.DataAof(),p7.Data()));
            return PyoaScalarInst_FromoaScalarInst(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility,oaPlacementStatus)
    {
        PyParamoaBlock p1;
        PyParamoaScalarName p2;
        PyParamoaScalarName p3;
        PyParamoaScalarName p4;
        PyParamoaTransform p5;
        PyParamoaParamArray p6;
        PyParamoaBlockDomainVisibility p7;
        PyParamoaPlacementStatus p8;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaScalarName_Convert,&p3,
              &PyoaScalarName_Convert,&p4,
              &PyoaTransform_Convert,&p5,
              &PyoaParamArray_ConvertAof,&p6,
              &PyoaBlockDomainVisibility_Convert,&p7,
              &PyoaPlacementStatus_Convert,&p8)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarInstp result= (oaScalarInst::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.DataAof(),p7.Data(),p8.Data()));
            return PyoaScalarInst_FromoaScalarInst(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaScalarInst, function: create, Choices are:\n"
        "    (oaBlock,oaDesign,oaScalarName,oaTransform)\n"
        "    (oaBlock,oaDesign,oaScalarName,oaTransform,oaParamArray)\n"
        "    (oaBlock,oaDesign,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility)\n"
        "    (oaBlock,oaDesign,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility,oaPlacementStatus)\n"
        "    (oaBlock,oaDesign,oaTransform)\n"
        "    (oaBlock,oaDesign,oaTransform,oaParamArray)\n"
        "    (oaBlock,oaDesign,oaTransform,oaParamArray,oaBlockDomainVisibility)\n"
        "    (oaBlock,oaDesign,oaTransform,oaParamArray,oaBlockDomainVisibility,oaPlacementStatus)\n"
        "    (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaScalarName,oaTransform)\n"
        "    (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray)\n"
        "    (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility)\n"
        "    (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility,oaPlacementStatus)\n"
        "    (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaTransform)\n"
        "    (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray)\n"
        "    (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility)\n"
        "    (oaBlock,oaScalarName,oaScalarName,oaScalarName,oaTransform,oaParamArray,oaBlockDomainVisibility,oaPlacementStatus)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScalarInst_static_find_doc[] = 
"Class: oaScalarInst, Function: find\n"
"  Paramegers: (oaBlock,oaScalarName)\n"
"    Calls: oaScalarInst* find(const oaBlock* block,const oaScalarName& name)\n"
"    Signature: find|ptr-oaScalarInst|cptr-oaBlock,cref-oaScalarName,\n"
"    This function searches the specified design for a scalarInst with the specified name. If the name is found, the function returns the scalar instance. Otherwise, NULL is returned.\n"
"    The oaScalarInst pointer or NULL\n"
;

static PyObject*
oaScalarInst_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBlock p1;
    PyParamoaScalarName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaBlock_Convert,&p1,
          &PyoaScalarName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaScalarInstp result= (oaScalarInst::find(p1.Data(),p2.Data()));
        return PyoaScalarInst_FromoaScalarInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScalarInst_static_isValidName_doc[] = 
"Class: oaScalarInst, Function: isValidName\n"
"  Paramegers: (oaBlock,oaScalarName)\n"
"    Calls: oaBoolean isValidName(const oaBlock* block,const oaScalarName& name)\n"
"    Signature: isValidName|simple-oaBoolean|cptr-oaBlock,cref-oaScalarName,\n"
"    This function returns a boolean value that indicates if the specified name is valid for a new oaScalarInst in the specified block .\n"
;

static PyObject*
oaScalarInst_static_isValidName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBlock p1;
    PyParamoaScalarName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaBlock_Convert,&p1,
          &PyoaScalarName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaBoolean result= (oaScalarInst::isValidName(p1.Data(),p2.Data()));
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
static PyMethodDef oaScalarInst_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaScalarInst_static_create,METH_VARARGS,oaScalarInst_static_create_doc},
    {"static_find",(PyCFunction)oaScalarInst_static_find,METH_VARARGS,oaScalarInst_static_find_doc},
    {"static_isValidName",(PyCFunction)oaScalarInst_static_isValidName,METH_VARARGS,oaScalarInst_static_isValidName_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaScalarInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaScalarInst_Type)<0) {
      printf("** PyType_Ready failed for: oaScalarInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaScalarInst",
           (PyObject*)(&PyoaScalarInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaScalarInst\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaScalarInst_Type.tp_dict;
    for(method=oaScalarInst_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaScalarName
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaScalarName_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaScalarName_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaScalarNameObject* self = (PyoaScalarNameObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value = (oaNameBase*)  new oaScalarName();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaNameSpace,[oaChar])
    {
        PyParamoaNameSpace p1;
        PyParamoaChar_Array p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaNameSpace_Convert,&p1,
              &PyoaChar_Array_Convert,&p2)) {
            self->value = (oaNameBase*)  new oaScalarName(p1.Data(),p2.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
            self->value = (oaNameBase*)  new oaScalarName(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaScalarName, Choices are:\n"
        "    ()\n"
        "    (oaNameSpace,[oaChar])\n"
        "    (oaScalarName)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaScalarName_tp_dealloc(PyoaScalarNameObject* self)
{
    if (!self->borrow) {
        delete (oaScalarName*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaScalarName_tp_repr(PyObject *ob)
{
    PyParamoaScalarName value;
    int convert_status=PyoaScalarName_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult;
    value.DataCall()->get(sresult);

    char addr[34];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaScalarName::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaScalarName_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaScalarName v1;
    PyParamoaScalarName v2;
    int convert_status1=PyoaScalarName_Convert(ob1,&v1);
    int convert_status2=PyoaScalarName_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    if (v1.Data()==v2.Data()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaScalarName_Convert(PyObject* ob,PyParamoaScalarName* result)
{
    if (ob == NULL) return 1;
    if (PyoaScalarName_Check(ob)) {
        result->SetData( (oaScalarName*) ((PyoaScalarNameObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaScalarName Failed");
    return 0;
}
int
PyoaScalarName_ConvertAof(PyObject* ob,PyParamoaScalarName* result)
{
    if (ob == NULL) return 1;
    if (ob==Py_None) {
        result->SetData(NULL);
        return 1;
    }
    if (PyoaScalarName_Check(ob)) {
        result->SetData( (oaScalarName*) ((PyoaScalarNameObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaScalarName Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaScalarName_FromoaScalarName(oaScalarName* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaScalarName_Type.tp_alloc(&PyoaScalarName_Type,0);
        if (bself == NULL) return bself;
        PyoaScalarNameObject* self = (PyoaScalarNameObject*)bself;
        self->value = (oaNameBase*)  data;
        self->locks = NULL;
        self->borrow = borrow;
        if (lock) PyoaLockObject(self->locks,lock);
        return bself;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaScalarName_append_doc[] = 
"Class: oaScalarName, Function: append\n"
"  Paramegers: (oaNameSpace,[oaChar],oaUInt4,oaUInt4)\n"
"    Calls: void append(const oaNameSpace& nSpace,const oaChar* in,oaUInt4 len,oaUInt4 flags)\n"
"    Signature: append|void-void|cref-oaNameSpace,cptr-oaChar,simple-oaUInt4,simple-oaUInt4,\n"
"    Function append\n"
"  Paramegers: (oaNameMem)\n"
"    Calls: void append(const oaNameMem& in)\n"
"    Signature: append|void-void|cref-oaNameMem,\n"
"    This function appends the specified member to this name.\n"
"    in\n"
"    The member to append.\n"
;

static PyObject*
oaScalarName_append(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarName data;
    int convert_status=PyoaScalarName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScalarNameObject* self=(PyoaScalarNameObject*)ob;

    // Case: (oaNameSpace,[oaChar],oaUInt4,oaUInt4)
    {
        PyParamoaNameSpace p1;
        PyParamoaChar_Array p2;
        PyParamoaUInt4 p3;
        PyParamoaUInt4 p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaNameSpace_Convert,&p1,
              &PyoaChar_Array_Convert,&p2,
              &PyoaUInt4_Convert,&p3,
              &PyoaUInt4_Convert,&p4)) {
            data.DataCall()->append(p1.Data(),p2.Data(),p3.Data(),p4.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaNameMem)
    {
        PyParamoaNameMem p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaNameMem_Convert,&p1)) {
            data.DataCall()->append(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaScalarName, function: append, Choices are:\n"
        "    (oaNameSpace,[oaChar],oaUInt4,oaUInt4)\n"
        "    (oaNameMem)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScalarName_get_doc[] = 
"Class: oaScalarName, Function: get\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void get(const oaNameSpace& nSpace,oaString& out) const\n"
"    Signature: get|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns this name mapped into the specified nameSpace.\n"
"    nSpace\n"
"    The nameSpace in which to map this name\n"
"    out\n"
"    The string in which to output the mapped name\n"
"  Paramegers: (oaString)\n"
"    Calls: void get(oaString& out) const\n"
"    Signature: get|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns this name mapped into the oaNative nameSpace.\n"
"    out\n"
"    The string in which to output the mapped name\n"
;

static PyObject*
oaScalarName_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarName data;
    int convert_status=PyoaScalarName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScalarNameObject* self=(PyoaScalarNameObject*)ob;

    // Case: (oaNameSpace,oaString)
    {
        PyParamoaNameSpace p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaNameSpace_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            data.DataCall()->get(p1.Data(),p2.Data());
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
            data.DataCall()->get(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaScalarName, function: get, Choices are:\n"
        "    (oaNameSpace,oaString)\n"
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
static char oaScalarName_getNumBits_doc[] = 
"Class: oaScalarName, Function: getNumBits\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumBits() const\n"
"    Signature: getNumBits|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of bits this scalar name represents. It returns 0 if this scalar name is empty, and 1 otherwise.\n"
;

static PyObject*
oaScalarName_getNumBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarName data;
    int convert_status=PyoaScalarName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScalarNameObject* self=(PyoaScalarNameObject*)ob;

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
static char oaScalarName_init_doc[] = 
"Class: oaScalarName, Function: init\n"
"  Paramegers: (oaNameSpace,[oaChar])\n"
"    Calls: void init(const oaNameSpace& nSpace,const oaChar* in)\n"
"    Signature: init|void-void|cref-oaNameSpace,cptr-oaChar,\n"
"    This function initializes the oaScalarName object by clearing previously stored name data, then re-initializes its value to the string specified by in , evaluating it in the specified nameSpace. This allows reuse of the oaName object to improve application performance and capacity.\n"
"    nSpace\n"
"    The nameSpace in which to evaluate the string\n"
"    in\n"
"    The input string to evaluate\n"
"    oacInvalidNameLength\n"
"    oacInvalidNameSyntax\n"
;

static PyObject*
oaScalarName_init(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarName data;
    int convert_status=PyoaScalarName_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScalarNameObject* self=(PyoaScalarNameObject*)ob;

    PyParamoaNameSpace p1;
    PyParamoaChar_Array p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaNameSpace_Convert,&p1,
          &PyoaChar_Array_Convert,&p2)) {
        data.DataCall()->init(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaScalarName_assign_doc[] = 
"Class: oaScalarName, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaScalarName_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaScalarName data;
  int convert_status=PyoaScalarName_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaScalarName p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaScalarName_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaScalarName_methodlist[] = {
    {"append",(PyCFunction)oaScalarName_append,METH_VARARGS,oaScalarName_append_doc},
    {"get",(PyCFunction)oaScalarName_get,METH_VARARGS,oaScalarName_get_doc},
    {"getNumBits",(PyCFunction)oaScalarName_getNumBits,METH_VARARGS,oaScalarName_getNumBits_doc},
    {"init",(PyCFunction)oaScalarName_init,METH_VARARGS,oaScalarName_init_doc},
    {"assign",(PyCFunction)oaScalarName_tp_assign,METH_VARARGS,oaScalarName_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaScalarName_doc[] = 
"Class: oaScalarName\n"
"  The oaScalarName utility class represents the name of an object that has no associated index. It is one of the oaName related classes that hold names for objects that can be mapped to various name spaces. Scalar names can be hierarchical. In conjunction with oaNameSpace objects, this class facilitates mapping names from one namespace to another. See the Name Mapping Section in the Programmers Guide for more information about mapping names between different namespaces.\n"
"  For developers implementing a new namespace, the new namespace must provide support for scalar names.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaScalarName()\n"
"    Signature: oaScalarName||\n"
"    This function constructs an empty oaScalarName object.\n"
"  Paramegers: (oaNameSpace,[oaChar])\n"
"    Calls: oaScalarName(const oaNameSpace& nSpace,const oaChar* in)\n"
"    Signature: oaScalarName||cref-oaNameSpace,cptr-oaChar,\n"
"    This function constructs an oaScalarName object, evaluating the specified input string in the specified nameSpace.\n"
"    nSpace\n"
"    The nameSpace in which to evaluate the string\n"
"    in\n"
"    The input string to evaluate\n"
"    oacInvalidNameLength\n"
"    oacInvalidNameSyntax\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: oaScalarName(const oaScalarName& in)\n"
"    Signature: oaScalarName||cref-oaScalarName,\n"
"    This function constructs a copy of an oaScalarName object that is identical to the specified oaScalarName.\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: (const oaScalarName&)\n"
"    Signature: oaScalarName||cref-oaScalarName,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaScalarName_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaScalarName",
    sizeof(PyoaScalarNameObject),
    0,
    (destructor)oaScalarName_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaScalarName_tp_compare,	/* tp_compare */
    (reprfunc)oaScalarName_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaScalarName_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaScalarName_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaNameBase_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaScalarName_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaScalarName_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaScalarName_Type)<0) {
      printf("** PyType_Ready failed for: oaScalarName\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaScalarName",
           (PyObject*)(&PyoaScalarName_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaScalarName\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaScalarNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaScalarNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaScalarNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaScalarNetObject* self = (PyoaScalarNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaScalarNet)
    {
        PyParamoaScalarNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaScalarNet_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaScalarNet, Choices are:\n"
        "    (oaScalarNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaScalarNet_tp_dealloc(PyoaScalarNetObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaScalarNet_tp_repr(PyObject *ob)
{
    PyParamoaScalarNet value;
    int convert_status=PyoaScalarNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaScalarNet::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaScalarName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[33];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaScalarNet::");
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
oaScalarNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaScalarNet v1;
    PyParamoaScalarNet v2;
    int convert_status1=PyoaScalarNet_Convert(ob1,&v1);
    int convert_status2=PyoaScalarNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaScalarNet_Convert(PyObject* ob,PyParamoaScalarNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaScalarNet_Check(ob)) {
        result->SetData( (oaScalarNet**) ((PyoaScalarNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaScalarNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaScalarNet_FromoaScalarNet(oaScalarNet** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaScalarNet* data=*value;
        PyObject* bself = PyoaScalarNet_Type.tp_alloc(&PyoaScalarNet_Type,0);
        if (bself == NULL) return bself;
        PyoaScalarNetObject* self = (PyoaScalarNetObject*)bself;
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
PyObject* PyoaScalarNet_FromoaScalarNet(oaScalarNet* data)
{
    if (data) {
       PyObject* bself = PyoaScalarNet_Type.tp_alloc(&PyoaScalarNet_Type,0);
       if (bself == NULL) return bself;
       PyoaScalarNetObject* self = (PyoaScalarNetObject*)bself;
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
static char oaScalarNet_getName_doc[] = 
"Class: oaScalarNet, Function: getName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getName(oaScalarName& name) const\n"
"    Signature: getName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the name of this scalar net.\n"
"    name\n"
"    The net name to return\n"
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
oaScalarNet_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarNet data;
    int convert_status=PyoaScalarNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScalarNetObject* self=(PyoaScalarNetObject*)ob;
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
        "No Arg-Matching Function found for class: oaScalarNet, function: getName, Choices are:\n"
        "    (oaScalarName)\n"
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
static char oaScalarNet_setName_doc[] = 
"Class: oaScalarNet, Function: setName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void setName(const oaScalarName& name)\n"
"    Signature: setName|void-void|cref-oaScalarName,\n"
"    This function changes the name of this net to the specified name. The function fails if this net is an implicit net or this net is a net in a bundle net.\n"
"    name\n"
"    The new name for the scalar net\n"
"    oacCannotSetNameOfImplicitNet\n"
"    oacCannotSetNameOfNetInBundleNet\n"
"    oacNetExists\n"
"    oacScalarNetNameMatchesBusBaseName\n"
;

static PyObject*
oaScalarNet_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarNet data;
    int convert_status=PyoaScalarNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScalarNetObject* self=(PyoaScalarNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaScalarName p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaScalarName_Convert,&p1)) {
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
static char oaScalarNet_isNull_doc[] =
"Class: oaScalarNet, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaScalarNet_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaScalarNet data;
    int convert_status=PyoaScalarNet_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaScalarNet_assign_doc[] = 
"Class: oaScalarNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaScalarNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaScalarNet data;
  int convert_status=PyoaScalarNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaScalarNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaScalarNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaScalarNet_methodlist[] = {
    {"getName",(PyCFunction)oaScalarNet_getName,METH_VARARGS,oaScalarNet_getName_doc},
    {"setName",(PyCFunction)oaScalarNet_setName,METH_VARARGS,oaScalarNet_setName_doc},
    {"isNull",(PyCFunction)oaScalarNet_tp_isNull,METH_VARARGS,oaScalarNet_isNull_doc},
    {"assign",(PyCFunction)oaScalarNet_tp_assign,METH_VARARGS,oaScalarNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaScalarNet_doc[] = 
"Class: oaScalarNet\n"
"  The oaScalarNet class implements a scalar (single-bit) net.\n"
"Constructors:\n"
"  Paramegers: (oaScalarNet)\n"
"    Calls: (const oaScalarNet&)\n"
"    Signature: oaScalarNet||cref-oaScalarNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaScalarNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaScalarNet",
    sizeof(PyoaScalarNetObject),
    0,
    (destructor)oaScalarNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaScalarNet_tp_compare,	/* tp_compare */
    (reprfunc)oaScalarNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaScalarNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaScalarNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBitNet_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaScalarNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaScalarNet_static_create_doc[] = 
"Class: oaScalarNet, Function: create\n"
"  Paramegers: (oaBlock,oaScalarName)\n"
"    Calls: oaScalarNet* create(oaBlock* block,const oaScalarName& name)\n"
"    Signature: create|ptr-oaScalarNet|ptr-oaBlock,cref-oaScalarName,simple-oaSigType,simple-oaBoolean,simple-oaBlockDomainVisibility,\n"
"    This function creates a scalarNet with the specified name. The function checks the specified name to verify it is unused. If the name is used on an implicit net, that implicit net is set to explicit and nothing else is processed.\n"
"    block\n"
"    The block name\n"
"    name\n"
"    The name of the scalar net to create\n"
"    sigType\n"
"    The signal type\n"
"    isGlobal\n"
"    The flag to indicate global net; the default is false\n"
"    view\n"
"    Specifies whether this net is visible in the module domain\n"
"    oacNetExists\n"
"    oacScalarNetNameMatchesBusBaseName\n"
"  Paramegers: (oaBlock,oaScalarName,oaSigType)\n"
"    Calls: oaScalarNet* create(oaBlock* block,const oaScalarName& name,oaSigType sigType)\n"
"    Signature: create|ptr-oaScalarNet|ptr-oaBlock,cref-oaScalarName,simple-oaSigType,simple-oaBoolean,simple-oaBlockDomainVisibility,\n"
"    This function creates a scalarNet with the specified name. The function checks the specified name to verify it is unused. If the name is used on an implicit net, that implicit net is set to explicit and nothing else is processed.\n"
"    block\n"
"    The block name\n"
"    name\n"
"    The name of the scalar net to create\n"
"    sigType\n"
"    The signal type\n"
"    isGlobal\n"
"    The flag to indicate global net; the default is false\n"
"    view\n"
"    Specifies whether this net is visible in the module domain\n"
"    oacNetExists\n"
"    oacScalarNetNameMatchesBusBaseName\n"
"  Paramegers: (oaBlock,oaScalarName,oaSigType,oaBoolean)\n"
"    Calls: oaScalarNet* create(oaBlock* block,const oaScalarName& name,oaSigType sigType,oaBoolean isGlobal)\n"
"    Signature: create|ptr-oaScalarNet|ptr-oaBlock,cref-oaScalarName,simple-oaSigType,simple-oaBoolean,simple-oaBlockDomainVisibility,\n"
"    This function creates a scalarNet with the specified name. The function checks the specified name to verify it is unused. If the name is used on an implicit net, that implicit net is set to explicit and nothing else is processed.\n"
"    block\n"
"    The block name\n"
"    name\n"
"    The name of the scalar net to create\n"
"    sigType\n"
"    The signal type\n"
"    isGlobal\n"
"    The flag to indicate global net; the default is false\n"
"    view\n"
"    Specifies whether this net is visible in the module domain\n"
"    oacNetExists\n"
"    oacScalarNetNameMatchesBusBaseName\n"
"  Paramegers: (oaBlock,oaScalarName,oaSigType,oaBoolean,oaBlockDomainVisibility)\n"
"    Calls: oaScalarNet* create(oaBlock* block,const oaScalarName& name,oaSigType sigType,oaBoolean isGlobal,oaBlockDomainVisibility view)\n"
"    Signature: create|ptr-oaScalarNet|ptr-oaBlock,cref-oaScalarName,simple-oaSigType,simple-oaBoolean,simple-oaBlockDomainVisibility,\n"
"    This function creates a scalarNet with the specified name. The function checks the specified name to verify it is unused. If the name is used on an implicit net, that implicit net is set to explicit and nothing else is processed.\n"
"    block\n"
"    The block name\n"
"    name\n"
"    The name of the scalar net to create\n"
"    sigType\n"
"    The signal type\n"
"    isGlobal\n"
"    The flag to indicate global net; the default is false\n"
"    view\n"
"    Specifies whether this net is visible in the module domain\n"
"    oacNetExists\n"
"    oacScalarNetNameMatchesBusBaseName\n"
"  Paramegers: (oaBlock)\n"
"    Calls: oaScalarNet* create(oaBlock* block)\n"
"    Signature: create|ptr-oaScalarNet|ptr-oaBlock,simple-oaSigType,simple-oaBoolean,simple-oaBlockDomainVisibility,\n"
"    This function creates a scalarNet in the specified block with an automatically generated name. The default name prefix for automatically generated names is N__%d, d referring to a unique integer.\n"
"    block\n"
"    The block name\n"
"    sigType\n"
"    The signal type; the default value is oacSignalSigType\n"
"    isGlobal\n"
"    The flag to indicate global net; the default is false\n"
"    view\n"
"    Specifies whether this net is visible in the module domain\n"
"    oacScalarNetNameMatchesBusBaseName\n"
"  Paramegers: (oaBlock,oaSigType)\n"
"    Calls: oaScalarNet* create(oaBlock* block,oaSigType sigType)\n"
"    Signature: create|ptr-oaScalarNet|ptr-oaBlock,simple-oaSigType,simple-oaBoolean,simple-oaBlockDomainVisibility,\n"
"    This function creates a scalarNet in the specified block with an automatically generated name. The default name prefix for automatically generated names is N__%d, d referring to a unique integer.\n"
"    block\n"
"    The block name\n"
"    sigType\n"
"    The signal type; the default value is oacSignalSigType\n"
"    isGlobal\n"
"    The flag to indicate global net; the default is false\n"
"    view\n"
"    Specifies whether this net is visible in the module domain\n"
"    oacScalarNetNameMatchesBusBaseName\n"
"  Paramegers: (oaBlock,oaSigType,oaBoolean)\n"
"    Calls: oaScalarNet* create(oaBlock* block,oaSigType sigType,oaBoolean isGlobal)\n"
"    Signature: create|ptr-oaScalarNet|ptr-oaBlock,simple-oaSigType,simple-oaBoolean,simple-oaBlockDomainVisibility,\n"
"    This function creates a scalarNet in the specified block with an automatically generated name. The default name prefix for automatically generated names is N__%d, d referring to a unique integer.\n"
"    block\n"
"    The block name\n"
"    sigType\n"
"    The signal type; the default value is oacSignalSigType\n"
"    isGlobal\n"
"    The flag to indicate global net; the default is false\n"
"    view\n"
"    Specifies whether this net is visible in the module domain\n"
"    oacScalarNetNameMatchesBusBaseName\n"
"  Paramegers: (oaBlock,oaSigType,oaBoolean,oaBlockDomainVisibility)\n"
"    Calls: oaScalarNet* create(oaBlock* block,oaSigType sigType,oaBoolean isGlobal,oaBlockDomainVisibility view)\n"
"    Signature: create|ptr-oaScalarNet|ptr-oaBlock,simple-oaSigType,simple-oaBoolean,simple-oaBlockDomainVisibility,\n"
"    This function creates a scalarNet in the specified block with an automatically generated name. The default name prefix for automatically generated names is N__%d, d referring to a unique integer.\n"
"    block\n"
"    The block name\n"
"    sigType\n"
"    The signal type; the default value is oacSignalSigType\n"
"    isGlobal\n"
"    The flag to indicate global net; the default is false\n"
"    view\n"
"    Specifies whether this net is visible in the module domain\n"
"    oacScalarNetNameMatchesBusBaseName\n"
;

static PyObject*
oaScalarNet_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaBlock,oaScalarName)
    {
        PyParamoaBlock p1;
        PyParamoaScalarName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaScalarName_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarNetp result= (oaScalarNet::create(p1.Data(),p2.Data()));
            return PyoaScalarNet_FromoaScalarNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaScalarName,oaSigType)
    {
        PyParamoaBlock p1;
        PyParamoaScalarName p2;
        PyParamoaSigType p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaSigType_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarNetp result= (oaScalarNet::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaScalarNet_FromoaScalarNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaScalarName,oaSigType,oaBoolean)
    {
        PyParamoaBlock p1;
        PyParamoaScalarName p2;
        PyParamoaSigType p3;
        PyParamoaBoolean p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaSigType_Convert,&p3,
              &PyoaBoolean_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarNetp result= (oaScalarNet::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaScalarNet_FromoaScalarNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaScalarName,oaSigType,oaBoolean,oaBlockDomainVisibility)
    {
        PyParamoaBlock p1;
        PyParamoaScalarName p2;
        PyParamoaSigType p3;
        PyParamoaBoolean p4;
        PyParamoaBlockDomainVisibility p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaSigType_Convert,&p3,
              &PyoaBoolean_Convert,&p4,
              &PyoaBlockDomainVisibility_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarNetp result= (oaScalarNet::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaScalarNet_FromoaScalarNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock)
    {
        PyParamoaBlock p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBlock_Convert,&p1)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarNetp result= (oaScalarNet::create(p1.Data()));
            return PyoaScalarNet_FromoaScalarNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaSigType)
    {
        PyParamoaBlock p1;
        PyParamoaSigType p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaSigType_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarNetp result= (oaScalarNet::create(p1.Data(),p2.Data()));
            return PyoaScalarNet_FromoaScalarNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaSigType,oaBoolean)
    {
        PyParamoaBlock p1;
        PyParamoaSigType p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaSigType_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarNetp result= (oaScalarNet::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaScalarNet_FromoaScalarNet(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaSigType,oaBoolean,oaBlockDomainVisibility)
    {
        PyParamoaBlock p1;
        PyParamoaSigType p2;
        PyParamoaBoolean p3;
        PyParamoaBlockDomainVisibility p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaSigType_Convert,&p2,
              &PyoaBoolean_Convert,&p3,
              &PyoaBlockDomainVisibility_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarNetp result= (oaScalarNet::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaScalarNet_FromoaScalarNet(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaScalarNet, function: create, Choices are:\n"
        "    (oaBlock,oaScalarName)\n"
        "    (oaBlock,oaScalarName,oaSigType)\n"
        "    (oaBlock,oaScalarName,oaSigType,oaBoolean)\n"
        "    (oaBlock,oaScalarName,oaSigType,oaBoolean,oaBlockDomainVisibility)\n"
        "    (oaBlock)\n"
        "    (oaBlock,oaSigType)\n"
        "    (oaBlock,oaSigType,oaBoolean)\n"
        "    (oaBlock,oaSigType,oaBoolean,oaBlockDomainVisibility)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScalarNet_static_find_doc[] = 
"Class: oaScalarNet, Function: find\n"
"  Paramegers: (oaBlock,oaScalarName)\n"
"    Calls: oaScalarNet* find(const oaBlock* block,const oaScalarName& name)\n"
"    Signature: find|ptr-oaScalarNet|cptr-oaBlock,cref-oaScalarName,\n"
"    This function searches the specified block for a scalarNet with the specified name. The function returns the net if it is found. Otherwise, NULL is returned.\n"
"    block\n"
"    The block to search\n"
"    name\n"
"    The scalar net name to find\n"
"    The scalar net name or NULL\n"
;

static PyObject*
oaScalarNet_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBlock p1;
    PyParamoaScalarName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaBlock_Convert,&p1,
          &PyoaScalarName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaScalarNetp result= (oaScalarNet::find(p1.Data(),p2.Data()));
        return PyoaScalarNet_FromoaScalarNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScalarNet_static_isValidName_doc[] = 
"Class: oaScalarNet, Function: isValidName\n"
"  Paramegers: (oaBlock,oaScalarName)\n"
"    Calls: oaBoolean isValidName(const oaBlock* block,const oaScalarName& name)\n"
"    Signature: isValidName|simple-oaBoolean|cptr-oaBlock,cref-oaScalarName,\n"
"    This function returns a boolean value that indicates if the specified name is valid for a new oaScalarNet in the specified block.\n"
"    block\n"
"    The block to search\n"
"    name\n"
"    The scalar net name to find\n"
;

static PyObject*
oaScalarNet_static_isValidName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBlock p1;
    PyParamoaScalarName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaBlock_Convert,&p1,
          &PyoaScalarName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaBoolean result= (oaScalarNet::isValidName(p1.Data(),p2.Data()));
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
static PyMethodDef oaScalarNet_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaScalarNet_static_create,METH_VARARGS,oaScalarNet_static_create_doc},
    {"static_find",(PyCFunction)oaScalarNet_static_find,METH_VARARGS,oaScalarNet_static_find_doc},
    {"static_isValidName",(PyCFunction)oaScalarNet_static_isValidName,METH_VARARGS,oaScalarNet_static_isValidName_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaScalarNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaScalarNet_Type)<0) {
      printf("** PyType_Ready failed for: oaScalarNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaScalarNet",
           (PyObject*)(&PyoaScalarNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaScalarNet\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaScalarNet_Type.tp_dict;
    for(method=oaScalarNet_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaScalarSiteDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaScalarSiteDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaScalarSiteDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaScalarSiteDefObject* self = (PyoaScalarSiteDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaScalarSiteDef)
    {
        PyParamoaScalarSiteDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaScalarSiteDef_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaScalarSiteDef, Choices are:\n"
        "    (oaScalarSiteDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaScalarSiteDef_tp_dealloc(PyoaScalarSiteDefObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaScalarSiteDef_tp_repr(PyObject *ob)
{
    PyParamoaScalarSiteDef value;
    int convert_status=PyoaScalarSiteDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaScalarSiteDef::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[37];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaScalarSiteDef::");
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
oaScalarSiteDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaScalarSiteDef v1;
    PyParamoaScalarSiteDef v2;
    int convert_status1=PyoaScalarSiteDef_Convert(ob1,&v1);
    int convert_status2=PyoaScalarSiteDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaScalarSiteDef_Convert(PyObject* ob,PyParamoaScalarSiteDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaScalarSiteDef_Check(ob)) {
        result->SetData( (oaScalarSiteDef**) ((PyoaScalarSiteDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaScalarSiteDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaScalarSiteDef_FromoaScalarSiteDef(oaScalarSiteDef** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaScalarSiteDef* data=*value;
        PyObject* bself = PyoaScalarSiteDef_Type.tp_alloc(&PyoaScalarSiteDef_Type,0);
        if (bself == NULL) return bself;
        PyoaScalarSiteDefObject* self = (PyoaScalarSiteDefObject*)bself;
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
PyObject* PyoaScalarSiteDef_FromoaScalarSiteDef(oaScalarSiteDef* data)
{
    if (data) {
       PyObject* bself = PyoaScalarSiteDef_Type.tp_alloc(&PyoaScalarSiteDef_Type,0);
       if (bself == NULL) return bself;
       PyoaScalarSiteDefObject* self = (PyoaScalarSiteDefObject*)bself;
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
static char oaScalarSiteDef_setHeight_doc[] = 
"Class: oaScalarSiteDef, Function: setHeight\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setHeight(oaUInt4 height)\n"
"    Signature: setHeight|void-void|simple-oaUInt4,\n"
"    This function sets the height of the siteDef.\n"
;

static PyObject*
oaScalarSiteDef_setHeight(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarSiteDef data;
    int convert_status=PyoaScalarSiteDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScalarSiteDefObject* self=(PyoaScalarSiteDefObject*)ob;
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
static char oaScalarSiteDef_setWidth_doc[] = 
"Class: oaScalarSiteDef, Function: setWidth\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setWidth(oaUInt4 width)\n"
"    Signature: setWidth|void-void|simple-oaUInt4,\n"
"    This function sets the width of the siteDef.\n"
;

static PyObject*
oaScalarSiteDef_setWidth(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarSiteDef data;
    int convert_status=PyoaScalarSiteDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScalarSiteDefObject* self=(PyoaScalarSiteDefObject*)ob;
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
static char oaScalarSiteDef_isNull_doc[] =
"Class: oaScalarSiteDef, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaScalarSiteDef_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaScalarSiteDef data;
    int convert_status=PyoaScalarSiteDef_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaScalarSiteDef_assign_doc[] = 
"Class: oaScalarSiteDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaScalarSiteDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaScalarSiteDef data;
  int convert_status=PyoaScalarSiteDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaScalarSiteDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaScalarSiteDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaScalarSiteDef_methodlist[] = {
    {"setHeight",(PyCFunction)oaScalarSiteDef_setHeight,METH_VARARGS,oaScalarSiteDef_setHeight_doc},
    {"setWidth",(PyCFunction)oaScalarSiteDef_setWidth,METH_VARARGS,oaScalarSiteDef_setWidth_doc},
    {"isNull",(PyCFunction)oaScalarSiteDef_tp_isNull,METH_VARARGS,oaScalarSiteDef_isNull_doc},
    {"assign",(PyCFunction)oaScalarSiteDef_tp_assign,METH_VARARGS,oaScalarSiteDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaScalarSiteDef_doc[] = 
"Class: oaScalarSiteDef\n"
"  The oaScalarSiteDef class defines a site where you can place cells in a row. A site A scalar site has width and height information, as well as the type and symmetry information inherited from oaSiteDef .\n"
"Constructors:\n"
"  Paramegers: (oaScalarSiteDef)\n"
"    Calls: (const oaScalarSiteDef&)\n"
"    Signature: oaScalarSiteDef||cref-oaScalarSiteDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaScalarSiteDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaScalarSiteDef",
    sizeof(PyoaScalarSiteDefObject),
    0,
    (destructor)oaScalarSiteDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaScalarSiteDef_tp_compare,	/* tp_compare */
    (reprfunc)oaScalarSiteDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaScalarSiteDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaScalarSiteDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaSiteDef_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaScalarSiteDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaScalarSiteDef_static_create_doc[] = 
"Class: oaScalarSiteDef, Function: create\n"
"  Paramegers: (oaTech,oaString,oaSiteDefType,oaUInt4,oaUInt4)\n"
"    Calls: oaScalarSiteDef* create(oaTech* tech,const oaString& name,oaSiteDefType type,oaUInt4 width,oaUInt4 height)\n"
"    Signature: create|ptr-oaScalarSiteDef|ptr-oaTech,cref-oaString,simple-oaSiteDefType,simple-oaUInt4,simple-oaUInt4,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an oaScalarSiteDef object in the specified technology database with the specified attributes.\n"
"    tech\n"
"    The technology database in which to create the siteDef\n"
"    name\n"
"    The name of the siteDef to create\n"
"    type\n"
"    The type of siteDef to create\n"
"    width\n"
"    The width of the siteDef to create\n"
"    height\n"
"    The height of the siteDef to create\n"
"    isSymmetricInX\n"
"    The X symmetry of the siteDef to create\n"
"    isSymmetricInY\n"
"    The Y symmetry of the siteDef to create\n"
"    isSymmetricInRot\n"
"    The rotation symmetry of the siteDef to create\n"
"    oacSiteDefExists\n"
"  Paramegers: (oaTech,oaString,oaSiteDefType,oaUInt4,oaUInt4,oaBoolean)\n"
"    Calls: oaScalarSiteDef* create(oaTech* tech,const oaString& name,oaSiteDefType type,oaUInt4 width,oaUInt4 height,oaBoolean isSymmetricInX)\n"
"    Signature: create|ptr-oaScalarSiteDef|ptr-oaTech,cref-oaString,simple-oaSiteDefType,simple-oaUInt4,simple-oaUInt4,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an oaScalarSiteDef object in the specified technology database with the specified attributes.\n"
"    tech\n"
"    The technology database in which to create the siteDef\n"
"    name\n"
"    The name of the siteDef to create\n"
"    type\n"
"    The type of siteDef to create\n"
"    width\n"
"    The width of the siteDef to create\n"
"    height\n"
"    The height of the siteDef to create\n"
"    isSymmetricInX\n"
"    The X symmetry of the siteDef to create\n"
"    isSymmetricInY\n"
"    The Y symmetry of the siteDef to create\n"
"    isSymmetricInRot\n"
"    The rotation symmetry of the siteDef to create\n"
"    oacSiteDefExists\n"
"  Paramegers: (oaTech,oaString,oaSiteDefType,oaUInt4,oaUInt4,oaBoolean,oaBoolean)\n"
"    Calls: oaScalarSiteDef* create(oaTech* tech,const oaString& name,oaSiteDefType type,oaUInt4 width,oaUInt4 height,oaBoolean isSymmetricInX,oaBoolean isSymmetricInY)\n"
"    Signature: create|ptr-oaScalarSiteDef|ptr-oaTech,cref-oaString,simple-oaSiteDefType,simple-oaUInt4,simple-oaUInt4,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an oaScalarSiteDef object in the specified technology database with the specified attributes.\n"
"    tech\n"
"    The technology database in which to create the siteDef\n"
"    name\n"
"    The name of the siteDef to create\n"
"    type\n"
"    The type of siteDef to create\n"
"    width\n"
"    The width of the siteDef to create\n"
"    height\n"
"    The height of the siteDef to create\n"
"    isSymmetricInX\n"
"    The X symmetry of the siteDef to create\n"
"    isSymmetricInY\n"
"    The Y symmetry of the siteDef to create\n"
"    isSymmetricInRot\n"
"    The rotation symmetry of the siteDef to create\n"
"    oacSiteDefExists\n"
"  Paramegers: (oaTech,oaString,oaSiteDefType,oaUInt4,oaUInt4,oaBoolean,oaBoolean,oaBoolean)\n"
"    Calls: oaScalarSiteDef* create(oaTech* tech,const oaString& name,oaSiteDefType type,oaUInt4 width,oaUInt4 height,oaBoolean isSymmetricInX,oaBoolean isSymmetricInY,oaBoolean isSymmetricInRot)\n"
"    Signature: create|ptr-oaScalarSiteDef|ptr-oaTech,cref-oaString,simple-oaSiteDefType,simple-oaUInt4,simple-oaUInt4,simple-oaBoolean,simple-oaBoolean,simple-oaBoolean,\n"
"    This function creates an oaScalarSiteDef object in the specified technology database with the specified attributes.\n"
"    tech\n"
"    The technology database in which to create the siteDef\n"
"    name\n"
"    The name of the siteDef to create\n"
"    type\n"
"    The type of siteDef to create\n"
"    width\n"
"    The width of the siteDef to create\n"
"    height\n"
"    The height of the siteDef to create\n"
"    isSymmetricInX\n"
"    The X symmetry of the siteDef to create\n"
"    isSymmetricInY\n"
"    The Y symmetry of the siteDef to create\n"
"    isSymmetricInRot\n"
"    The rotation symmetry of the siteDef to create\n"
"    oacSiteDefExists\n"
;

static PyObject*
oaScalarSiteDef_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaTech,oaString,oaSiteDefType,oaUInt4,oaUInt4)
    {
        PyParamoaTech p1;
        PyParamoaString p2;
        PyParamoaSiteDefType p3;
        PyParamoaUInt4 p4;
        PyParamoaUInt4 p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaSiteDefType_Convert,&p3,
              &PyoaUInt4_Convert,&p4,
              &PyoaUInt4_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarSiteDefp result= (oaScalarSiteDef::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
            return PyoaScalarSiteDef_FromoaScalarSiteDef(result);
        }
    }
    PyErr_Clear();
    // Case: (oaTech,oaString,oaSiteDefType,oaUInt4,oaUInt4,oaBoolean)
    {
        PyParamoaTech p1;
        PyParamoaString p2;
        PyParamoaSiteDefType p3;
        PyParamoaUInt4 p4;
        PyParamoaUInt4 p5;
        PyParamoaBoolean p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaSiteDefType_Convert,&p3,
              &PyoaUInt4_Convert,&p4,
              &PyoaUInt4_Convert,&p5,
              &PyoaBoolean_Convert,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarSiteDefp result= (oaScalarSiteDef::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data()));
            return PyoaScalarSiteDef_FromoaScalarSiteDef(result);
        }
    }
    PyErr_Clear();
    // Case: (oaTech,oaString,oaSiteDefType,oaUInt4,oaUInt4,oaBoolean,oaBoolean)
    {
        PyParamoaTech p1;
        PyParamoaString p2;
        PyParamoaSiteDefType p3;
        PyParamoaUInt4 p4;
        PyParamoaUInt4 p5;
        PyParamoaBoolean p6;
        PyParamoaBoolean p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaSiteDefType_Convert,&p3,
              &PyoaUInt4_Convert,&p4,
              &PyoaUInt4_Convert,&p5,
              &PyoaBoolean_Convert,&p6,
              &PyoaBoolean_Convert,&p7)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarSiteDefp result= (oaScalarSiteDef::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data()));
            return PyoaScalarSiteDef_FromoaScalarSiteDef(result);
        }
    }
    PyErr_Clear();
    // Case: (oaTech,oaString,oaSiteDefType,oaUInt4,oaUInt4,oaBoolean,oaBoolean,oaBoolean)
    {
        PyParamoaTech p1;
        PyParamoaString p2;
        PyParamoaSiteDefType p3;
        PyParamoaUInt4 p4;
        PyParamoaUInt4 p5;
        PyParamoaBoolean p6;
        PyParamoaBoolean p7;
        PyParamoaBoolean p8;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&",
              &PyoaTech_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaSiteDefType_Convert,&p3,
              &PyoaUInt4_Convert,&p4,
              &PyoaUInt4_Convert,&p5,
              &PyoaBoolean_Convert,&p6,
              &PyoaBoolean_Convert,&p7,
              &PyoaBoolean_Convert,&p8)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarSiteDefp result= (oaScalarSiteDef::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data()));
            return PyoaScalarSiteDef_FromoaScalarSiteDef(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaScalarSiteDef, function: create, Choices are:\n"
        "    (oaTech,oaString,oaSiteDefType,oaUInt4,oaUInt4)\n"
        "    (oaTech,oaString,oaSiteDefType,oaUInt4,oaUInt4,oaBoolean)\n"
        "    (oaTech,oaString,oaSiteDefType,oaUInt4,oaUInt4,oaBoolean,oaBoolean)\n"
        "    (oaTech,oaString,oaSiteDefType,oaUInt4,oaUInt4,oaBoolean,oaBoolean,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaScalarSiteDef_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaScalarSiteDef_static_create,METH_VARARGS,oaScalarSiteDef_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaScalarSiteDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaScalarSiteDef_Type)<0) {
      printf("** PyType_Ready failed for: oaScalarSiteDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaScalarSiteDef",
           (PyObject*)(&PyoaScalarSiteDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaScalarSiteDef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaScalarSiteDef_Type.tp_dict;
    for(method=oaScalarSiteDef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaScalarTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaScalarTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaScalarTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaScalarTermObject* self = (PyoaScalarTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaScalarTerm)
    {
        PyParamoaScalarTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaScalarTerm_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaScalarTerm, Choices are:\n"
        "    (oaScalarTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaScalarTerm_tp_dealloc(PyoaScalarTermObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaScalarTerm_tp_repr(PyObject *ob)
{
    PyParamoaScalarTerm value;
    int convert_status=PyoaScalarTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaScalarTerm::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaScalarName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[34];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaScalarTerm::");
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
oaScalarTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaScalarTerm v1;
    PyParamoaScalarTerm v2;
    int convert_status1=PyoaScalarTerm_Convert(ob1,&v1);
    int convert_status2=PyoaScalarTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaScalarTerm_Convert(PyObject* ob,PyParamoaScalarTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaScalarTerm_Check(ob)) {
        result->SetData( (oaScalarTerm**) ((PyoaScalarTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaScalarTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaScalarTerm_FromoaScalarTerm(oaScalarTerm** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaScalarTerm* data=*value;
        PyObject* bself = PyoaScalarTerm_Type.tp_alloc(&PyoaScalarTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaScalarTermObject* self = (PyoaScalarTermObject*)bself;
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
PyObject* PyoaScalarTerm_FromoaScalarTerm(oaScalarTerm* data)
{
    if (data) {
       PyObject* bself = PyoaScalarTerm_Type.tp_alloc(&PyoaScalarTerm_Type,0);
       if (bself == NULL) return bself;
       PyoaScalarTermObject* self = (PyoaScalarTermObject*)bself;
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
static char oaScalarTerm_getName_doc[] = 
"Class: oaScalarTerm, Function: getName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getName(oaScalarName& name) const\n"
"    Signature: getName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the name of this terminal in the name argument.\n"
"    name\n"
"    The name of the scalar terminal to return\n"
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
oaScalarTerm_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarTerm data;
    int convert_status=PyoaScalarTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScalarTermObject* self=(PyoaScalarTermObject*)ob;
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
        "No Arg-Matching Function found for class: oaScalarTerm, function: getName, Choices are:\n"
        "    (oaScalarName)\n"
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
static char oaScalarTerm_setName_doc[] = 
"Class: oaScalarTerm, Function: setName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void setName(const oaScalarName& name)\n"
"    Signature: setName|void-void|cref-oaScalarName,\n"
"    This function changes the name of this terminal to the specified name .\n"
"    name\n"
"    The new terminal name\n"
"    oacCannotSetNameOfImplicitTerm\n"
"    oacCannotSetNameOfTermInBundleTerm\n"
"    oacScalarTermNameMatchesBusBaseName\n"
"    oacTermExists\n"
;

static PyObject*
oaScalarTerm_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScalarTerm data;
    int convert_status=PyoaScalarTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScalarTermObject* self=(PyoaScalarTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaScalarName p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaScalarName_Convert,&p1)) {
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
static char oaScalarTerm_isNull_doc[] =
"Class: oaScalarTerm, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaScalarTerm_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaScalarTerm data;
    int convert_status=PyoaScalarTerm_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaScalarTerm_assign_doc[] = 
"Class: oaScalarTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaScalarTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaScalarTerm data;
  int convert_status=PyoaScalarTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaScalarTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaScalarTerm_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaScalarTerm_methodlist[] = {
    {"getName",(PyCFunction)oaScalarTerm_getName,METH_VARARGS,oaScalarTerm_getName_doc},
    {"setName",(PyCFunction)oaScalarTerm_setName,METH_VARARGS,oaScalarTerm_setName_doc},
    {"isNull",(PyCFunction)oaScalarTerm_tp_isNull,METH_VARARGS,oaScalarTerm_isNull_doc},
    {"assign",(PyCFunction)oaScalarTerm_tp_assign,METH_VARARGS,oaScalarTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaScalarTerm_doc[] = 
"Class: oaScalarTerm\n"
"  The oaScalarTerm class implements a scalar terminal on an oaBlock . Scalar terminals are single bit and have a name without an index. A scalar terminal must be created on a single-bit net, though the net name does not have to be scalar.\n"
"  oaScalarTerm objects are always in the block domain. oaScalarTerms may be physical-only terminals that are only in the block hierarchy, or they can be cross-domain terminals that directly correspond to an oaModScalarTerm in the module domain and an oaOccScalarTerm in the occurrence domain.\n"
"Constructors:\n"
"  Paramegers: (oaScalarTerm)\n"
"    Calls: (const oaScalarTerm&)\n"
"    Signature: oaScalarTerm||cref-oaScalarTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaScalarTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaScalarTerm",
    sizeof(PyoaScalarTermObject),
    0,
    (destructor)oaScalarTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaScalarTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaScalarTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaScalarTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaScalarTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBitTerm_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaScalarTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaScalarTerm_static_create_doc[] = 
"Class: oaScalarTerm, Function: create\n"
"  Paramegers: (oaBitNet,oaScalarName)\n"
"    Calls: oaScalarTerm* create(oaBitNet* net,const oaScalarName& name)\n"
"    Signature: create|ptr-oaScalarTerm|ptr-oaBitNet,cref-oaScalarName,simple-oaTermType,simple-oaBlockDomainVisibility,\n"
"    This function creates an oaScalarTerm object on the specified net with the specified attributes. The function checks the net to verify that it is valid.\n"
"    net\n"
"    The bit net to check\n"
"    name\n"
"    The name of the scalar terminal to create\n"
"    type\n"
"    The terminal type\n"
"    view\n"
"    Specifies whether this net is visible in the module domain\n"
"    A pointer to the created scalar terminal\n"
"    oacCannotCreateTermWithImplicitNet\n"
"    oacTermExists\n"
"    oacTermMemberExists\n"
"    oacScalarTermNameMatchesBusBaseName\n"
"    oacImplicitModuleTermExists\n"
"    oacInvalidHierTermName\n"
"    oacTermNetMustBeInUniqueOccHier\n"
"  Paramegers: (oaBitNet,oaScalarName,oaTermType)\n"
"    Calls: oaScalarTerm* create(oaBitNet* net,const oaScalarName& name,oaTermType type)\n"
"    Signature: create|ptr-oaScalarTerm|ptr-oaBitNet,cref-oaScalarName,simple-oaTermType,simple-oaBlockDomainVisibility,\n"
"    This function creates an oaScalarTerm object on the specified net with the specified attributes. The function checks the net to verify that it is valid.\n"
"    net\n"
"    The bit net to check\n"
"    name\n"
"    The name of the scalar terminal to create\n"
"    type\n"
"    The terminal type\n"
"    view\n"
"    Specifies whether this net is visible in the module domain\n"
"    A pointer to the created scalar terminal\n"
"    oacCannotCreateTermWithImplicitNet\n"
"    oacTermExists\n"
"    oacTermMemberExists\n"
"    oacScalarTermNameMatchesBusBaseName\n"
"    oacImplicitModuleTermExists\n"
"    oacInvalidHierTermName\n"
"    oacTermNetMustBeInUniqueOccHier\n"
"  Paramegers: (oaBitNet,oaScalarName,oaTermType,oaBlockDomainVisibility)\n"
"    Calls: oaScalarTerm* create(oaBitNet* net,const oaScalarName& name,oaTermType type,oaBlockDomainVisibility view)\n"
"    Signature: create|ptr-oaScalarTerm|ptr-oaBitNet,cref-oaScalarName,simple-oaTermType,simple-oaBlockDomainVisibility,\n"
"    This function creates an oaScalarTerm object on the specified net with the specified attributes. The function checks the net to verify that it is valid.\n"
"    net\n"
"    The bit net to check\n"
"    name\n"
"    The name of the scalar terminal to create\n"
"    type\n"
"    The terminal type\n"
"    view\n"
"    Specifies whether this net is visible in the module domain\n"
"    A pointer to the created scalar terminal\n"
"    oacCannotCreateTermWithImplicitNet\n"
"    oacTermExists\n"
"    oacTermMemberExists\n"
"    oacScalarTermNameMatchesBusBaseName\n"
"    oacImplicitModuleTermExists\n"
"    oacInvalidHierTermName\n"
"    oacTermNetMustBeInUniqueOccHier\n"
;

static PyObject*
oaScalarTerm_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaBitNet,oaScalarName)
    {
        PyParamoaBitNet p1;
        PyParamoaScalarName p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaBitNet_Convert,&p1,
              &PyoaScalarName_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarTermp result= (oaScalarTerm::create(p1.Data(),p2.Data()));
            return PyoaScalarTerm_FromoaScalarTerm(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBitNet,oaScalarName,oaTermType)
    {
        PyParamoaBitNet p1;
        PyParamoaScalarName p2;
        PyParamoaTermType p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaBitNet_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaTermType_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarTermp result= (oaScalarTerm::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaScalarTerm_FromoaScalarTerm(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBitNet,oaScalarName,oaTermType,oaBlockDomainVisibility)
    {
        PyParamoaBitNet p1;
        PyParamoaScalarName p2;
        PyParamoaTermType p3;
        PyParamoaBlockDomainVisibility p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaBitNet_Convert,&p1,
              &PyoaScalarName_Convert,&p2,
              &PyoaTermType_Convert,&p3,
              &PyoaBlockDomainVisibility_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScalarTermp result= (oaScalarTerm::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaScalarTerm_FromoaScalarTerm(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaScalarTerm, function: create, Choices are:\n"
        "    (oaBitNet,oaScalarName)\n"
        "    (oaBitNet,oaScalarName,oaTermType)\n"
        "    (oaBitNet,oaScalarName,oaTermType,oaBlockDomainVisibility)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScalarTerm_static_find_doc[] = 
"Class: oaScalarTerm, Function: find\n"
"  Paramegers: (oaBlock,oaScalarName)\n"
"    Calls: oaScalarTerm* find(const oaBlock* block,const oaScalarName& name)\n"
"    Signature: find|ptr-oaScalarTerm|cptr-oaBlock,cref-oaScalarName,\n"
"    This function searches the specified block for a scalarTerm with the specified name. The function returns a pointer to the oaScalarTerm if it is found. Otherwise, NULL is returned.\n"
"    block\n"
"    The block to search\n"
"    name\n"
"    The name of the scalar terminal to find\n"
"    A pointer to the scalar terminal, if found; otherwise, NULL is returned\n"
;

static PyObject*
oaScalarTerm_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBlock p1;
    PyParamoaScalarName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaBlock_Convert,&p1,
          &PyoaScalarName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaScalarTermp result= (oaScalarTerm::find(p1.Data(),p2.Data()));
        return PyoaScalarTerm_FromoaScalarTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScalarTerm_static_isValidName_doc[] = 
"Class: oaScalarTerm, Function: isValidName\n"
"  Paramegers: (oaBlock,oaScalarName)\n"
"    Calls: oaBoolean isValidName(const oaBlock* block,const oaScalarName& name)\n"
"    Signature: isValidName|simple-oaBoolean|cptr-oaBlock,cref-oaScalarName,\n"
"    This function returns a boolean value that indicates if specified name is valid for a new oaScalarTerm object on the specified block.\n"
"    block\n"
"    The block to search\n"
"    name\n"
"    The name of the scalar terminal to return\n"
;

static PyObject*
oaScalarTerm_static_isValidName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBlock p1;
    PyParamoaScalarName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaBlock_Convert,&p1,
          &PyoaScalarName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaBoolean result= (oaScalarTerm::isValidName(p1.Data(),p2.Data()));
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
static PyMethodDef oaScalarTerm_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaScalarTerm_static_create,METH_VARARGS,oaScalarTerm_static_create_doc},
    {"static_find",(PyCFunction)oaScalarTerm_static_find,METH_VARARGS,oaScalarTerm_static_find_doc},
    {"static_isValidName",(PyCFunction)oaScalarTerm_static_isValidName,METH_VARARGS,oaScalarTerm_static_isValidName_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaScalarTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaScalarTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaScalarTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaScalarTerm",
           (PyObject*)(&PyoaScalarTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaScalarTerm\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaScalarTerm_Type.tp_dict;
    for(method=oaScalarTerm_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaScanChain
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaScanChain_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaScanChain_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaScanChainObject* self = (PyoaScanChainObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaScanChain)
    {
        PyParamoaScanChain p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaScanChain_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaScanChain, Choices are:\n"
        "    (oaScanChain)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaScanChain_tp_dealloc(PyoaScanChainObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaScanChain_tp_repr(PyObject *ob)
{
    PyParamoaScanChain value;
    int convert_status=PyoaScanChain_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaScanChain::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[33];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaScanChain::");
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
oaScanChain_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaScanChain v1;
    PyParamoaScanChain v2;
    int convert_status1=PyoaScanChain_Convert(ob1,&v1);
    int convert_status2=PyoaScanChain_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaScanChain_Convert(PyObject* ob,PyParamoaScanChain* result)
{
    if (ob == NULL) return 1;
    if (PyoaScanChain_Check(ob)) {
        result->SetData( (oaScanChain**) ((PyoaScanChainObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaScanChain Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaScanChain_FromoaScanChain(oaScanChain** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaScanChain* data=*value;
        PyObject* bself = PyoaScanChain_Type.tp_alloc(&PyoaScanChain_Type,0);
        if (bself == NULL) return bself;
        PyoaScanChainObject* self = (PyoaScanChainObject*)bself;
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
PyObject* PyoaScanChain_FromoaScanChain(oaScanChain* data)
{
    if (data) {
       PyObject* bself = PyoaScanChain_Type.tp_alloc(&PyoaScanChain_Type,0);
       if (bself == NULL) return bself;
       PyoaScanChainObject* self = (PyoaScanChainObject*)bself;
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
static char oaScanChain_destroy_doc[] = 
"Class: oaScanChain, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this scan chain, removing it from the database.\n"
;

static PyObject*
oaScanChain_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChain data;
    int convert_status=PyoaScanChain_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainObject* self=(PyoaScanChainObject*)ob;
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
static char oaScanChain_getMaxBits_doc[] = 
"Class: oaScanChain, Function: getMaxBits\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getMaxBits() const\n"
"    Signature: getMaxBits|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the maximum number bits that can be stored in this scan chain. A value of zero is interpeted as an unlimited bit length value.\n"
"    oacCannotSetMaxBits\n"
"    If this is called on a scanChain without a partition name\n"
;

static PyObject*
oaScanChain_getMaxBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChain data;
    int convert_status=PyoaScanChain_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainObject* self=(PyoaScanChainObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getMaxBits());
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
static char oaScanChain_getName_doc[] = 
"Class: oaScanChain, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function fills out name with the name of this scan chain.\n"
;

static PyObject*
oaScanChain_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChain data;
    int convert_status=PyoaScanChain_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainObject* self=(PyoaScanChainObject*)ob;
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
static char oaScanChain_getPartitionName_doc[] = 
"Class: oaScanChain, Function: getPartitionName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getPartitionName(oaString& name) const\n"
"    Signature: getPartitionName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function fills out name with the partition name of this scanChain.\n"
;

static PyObject*
oaScanChain_getPartitionName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChain data;
    int convert_status=PyoaScanChain_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainObject* self=(PyoaScanChainObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getPartitionName(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScanChain_getScanChainSets_doc[] = 
"Class: oaScanChain, Function: getScanChainSets\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaScanChainSet_oaScanChain getScanChainSets() const\n"
"    Signature: getScanChainSets|simple-oaCollection_oaScanChainSet_oaScanChain|simple-oaUInt4,\n"
"    BrowseData: 1\n"
"    This function returns a collection of scan chain sets in this scanChain.\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaCollection_oaScanChainSet_oaScanChain getScanChainSets(oaUInt4 flag) const\n"
"    Signature: getScanChainSets|simple-oaCollection_oaScanChainSet_oaScanChain|simple-oaUInt4,\n"
"    This function returns a collection of scan chain sets in this scanChain.\n"
;

static PyObject*
oaScanChain_getScanChainSets(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChain data;
    int convert_status=PyoaScanChain_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainObject* self=(PyoaScanChainObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaCollection_oaScanChainSet_oaScanChain* result= new oaCollection_oaScanChainSet_oaScanChain(data.DataCall()->getScanChainSets());
            return PyoaCollection_oaScanChainSet_oaScanChain_FromoaCollection_oaScanChainSet_oaScanChain(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            oaCollection_oaScanChainSet_oaScanChain* result= new oaCollection_oaScanChainSet_oaScanChain(data.DataCall()->getScanChainSets(p1.Data()));
            return PyoaCollection_oaScanChainSet_oaScanChain_FromoaCollection_oaScanChainSet_oaScanChain(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaScanChain, function: getScanChainSets, Choices are:\n"
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
static char oaScanChain_getScanChainSetsIter_doc[] = 
"Class: oaScanChain, Function: getScanChainSetsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaScanChainSet getScanChainSetsIter() const\n"
"    Signature: getScanChainSetsIter|simple-oaIter_oaScanChainSet|simple-oaUInt4,\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of scan chain sets in this scanChain.\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaIter_oaScanChainSet getScanChainSetsIter(oaUInt4 flag) const\n"
"    Signature: getScanChainSetsIter|simple-oaIter_oaScanChainSet|simple-oaUInt4,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of scan chain sets in this scanChain.\n"
;

static PyObject*
oaScanChain_getScanChainSetsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChain data;
    int convert_status=PyoaScanChain_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainObject* self=(PyoaScanChainObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaIter_oaScanChainSet* result= new oaIter_oaScanChainSet(data.DataCall()->getScanChainSets());
            return PyoaIter_oaScanChainSet_FromoaIter_oaScanChainSet(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            oaIter_oaScanChainSet* result= new oaIter_oaScanChainSet(data.DataCall()->getScanChainSets(p1.Data()));
            return PyoaIter_oaScanChainSet_FromoaIter_oaScanChainSet(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaScanChain, function: getScanChainSetsIter, Choices are:\n"
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
static char oaScanChain_getStartObject_doc[] = 
"Class: oaScanChain, Function: getStartObject\n"
"  Paramegers: ()\n"
"    Calls: oaDesignObject* getStartObject() const\n"
"    Signature: getStartObject|ptr-oaDesignObject|\n"
"    BrowseData: 1\n"
"    This function returns the starting object in the scan chain. The returned object can be an oaBitTerm , oaInstTerm , or oaScanChainInst .\n"
;

static PyObject*
oaScanChain_getStartObject(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChain data;
    int convert_status=PyoaScanChain_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainObject* self=(PyoaScanChainObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDesignObjectp result= (data.DataCall()->getStartObject());
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
static char oaScanChain_getStopObject_doc[] = 
"Class: oaScanChain, Function: getStopObject\n"
"  Paramegers: ()\n"
"    Calls: oaDesignObject* getStopObject() const\n"
"    Signature: getStopObject|ptr-oaDesignObject|\n"
"    BrowseData: 1\n"
"    This function returns the stopping object in the scan chain. The returned object can be an an oaBitTerm , oaInstTerm , or oaScanChainInst .\n"
;

static PyObject*
oaScanChain_getStopObject(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChain data;
    int convert_status=PyoaScanChain_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainObject* self=(PyoaScanChainObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDesignObjectp result= (data.DataCall()->getStopObject());
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
static char oaScanChain_setMaxBits_doc[] = 
"Class: oaScanChain, Function: setMaxBits\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setMaxBits(oaUInt4 maxBits)\n"
"    Signature: setMaxBits|void-void|simple-oaUInt4,\n"
"    This function changes the maximum number of bits allowed on this scan chain.\n"
"    oacCannotSetMaxBits\n"
"    If this is called on a scanChain without a partition name\n"
;

static PyObject*
oaScanChain_setMaxBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChain data;
    int convert_status=PyoaScanChain_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainObject* self=(PyoaScanChainObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setMaxBits(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScanChain_setName_doc[] = 
"Class: oaScanChain, Function: setName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setName(const oaString& name)\n"
"    Signature: setName|void-void|cref-oaString,\n"
"    This function changes the name of this scan chain to the specified name .\n"
"    oacScanChainExists\n"
"    If a scan chain with the specified name already exists.\n"
;

static PyObject*
oaScanChain_setName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChain data;
    int convert_status=PyoaScanChain_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainObject* self=(PyoaScanChainObject*)ob;
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
static char oaScanChain_setPartitionName_doc[] = 
"Class: oaScanChain, Function: setPartitionName\n"
"  Paramegers: (oaString)\n"
"    Calls: void setPartitionName(const oaString& name)\n"
"    Signature: setPartitionName|void-void|cref-oaString,\n"
"    This function changes the name of this scan chain partition to the specified name.\n"
;

static PyObject*
oaScanChain_setPartitionName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChain data;
    int convert_status=PyoaScanChain_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainObject* self=(PyoaScanChainObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->setPartitionName(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScanChain_setStartObject_doc[] = 
"Class: oaScanChain, Function: setStartObject\n"
"  Paramegers: (oaDesignObject)\n"
"    Calls: void setStartObject(oaDesignObject* object)\n"
"    Signature: setStartObject|void-void|ptr-oaDesignObject,\n"
"    This function sets or changes the starting object in the scan chain. The specified object can be either an oaBitTerm , oaInstTerm , or oaScanChainInst .\n"
"    oacInvalidScanChainObject\n"
"    if the start object is not an oaBitTerm , oaInstTerm , or oaScanChain\n"
;

static PyObject*
oaScanChain_setStartObject(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChain data;
    int convert_status=PyoaScanChain_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainObject* self=(PyoaScanChainObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDesignObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesignObject_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setStartObject(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScanChain_setStopObject_doc[] = 
"Class: oaScanChain, Function: setStopObject\n"
"  Paramegers: (oaDesignObject)\n"
"    Calls: void setStopObject(oaDesignObject* object)\n"
"    Signature: setStopObject|void-void|ptr-oaDesignObject,\n"
"    This function sets or changes the stopping object in the scan chain. This specified object can be an oaBitTerm , oaInstTerm , or oaScanChainInst .\n"
"    oacInvalidScanChainObject\n"
"    if the stop object is not an oaBitTerm , oaInstTerm , or oaScanChain\n"
;

static PyObject*
oaScanChain_setStopObject(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChain data;
    int convert_status=PyoaScanChain_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainObject* self=(PyoaScanChainObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaDesignObject p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesignObject_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setStopObject(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScanChain_isNull_doc[] =
"Class: oaScanChain, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaScanChain_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaScanChain data;
    int convert_status=PyoaScanChain_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaScanChain_assign_doc[] = 
"Class: oaScanChain, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaScanChain_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaScanChain data;
  int convert_status=PyoaScanChain_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaScanChain p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaScanChain_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaScanChain_methodlist[] = {
    {"destroy",(PyCFunction)oaScanChain_destroy,METH_VARARGS,oaScanChain_destroy_doc},
    {"getMaxBits",(PyCFunction)oaScanChain_getMaxBits,METH_VARARGS,oaScanChain_getMaxBits_doc},
    {"getName",(PyCFunction)oaScanChain_getName,METH_VARARGS,oaScanChain_getName_doc},
    {"getPartitionName",(PyCFunction)oaScanChain_getPartitionName,METH_VARARGS,oaScanChain_getPartitionName_doc},
    {"getScanChainSets",(PyCFunction)oaScanChain_getScanChainSets,METH_VARARGS,oaScanChain_getScanChainSets_doc},
    {"getScanChainSetsIter",(PyCFunction)oaScanChain_getScanChainSetsIter,METH_VARARGS,oaScanChain_getScanChainSetsIter_doc},
    {"getStartObject",(PyCFunction)oaScanChain_getStartObject,METH_VARARGS,oaScanChain_getStartObject_doc},
    {"getStopObject",(PyCFunction)oaScanChain_getStopObject,METH_VARARGS,oaScanChain_getStopObject_doc},
    {"setMaxBits",(PyCFunction)oaScanChain_setMaxBits,METH_VARARGS,oaScanChain_setMaxBits_doc},
    {"setName",(PyCFunction)oaScanChain_setName,METH_VARARGS,oaScanChain_setName_doc},
    {"setPartitionName",(PyCFunction)oaScanChain_setPartitionName,METH_VARARGS,oaScanChain_setPartitionName_doc},
    {"setStartObject",(PyCFunction)oaScanChain_setStartObject,METH_VARARGS,oaScanChain_setStartObject_doc},
    {"setStopObject",(PyCFunction)oaScanChain_setStopObject,METH_VARARGS,oaScanChain_setStopObject_doc},
    {"isNull",(PyCFunction)oaScanChain_tp_isNull,METH_VARARGS,oaScanChain_isNull_doc},
    {"assign",(PyCFunction)oaScanChain_tp_assign,METH_VARARGS,oaScanChain_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaScanChain_doc[] = 
"Class: oaScanChain\n"
"  Scan chains are a common technique used to make designs testable . With scan chains, a series of registers, often called scan latches , are linked together as a shift register so that test patterns can be written into those registers by putting the design in test mode and shifting the desired values in. After a test is run the result values can be read out in the same manner. Designs may have more than one scan chain.\n"
"  Scan chains often get special treatment by place and route tools which can take advantage of the fact that their detailed order and partitioning into individual scan chains can be done late in the design flow.\n"
"  OpenAccess will model scan chains at several stages of their specification. It can indicate which cells are scan latches and which instTerms on those cells are the scan-in and scan-out connections. This is represented with the oaScanChainInst class.\n"
"  OpenAccess will model sets of scan latches that will belong to a given scan chain with the oaScanChainSet class. These sets can specify either that the order of the scan latches in the set is fixed or that they are unordered and can be moved.\n"
"  Finally, OpenAccess will model the grouping of scan sets into whole scan chains with the oaScanChain class. Where the design wants to limit the length of each scan chain and have multiple scan chains instead of one long one, the scan chains can have a partition name. The scan chain sets within such a scan chain may be swapped with other scan chains with the same partition name.\n"
"  OpenAccess does not store the complete connectivity of the scan chain, just the scan latches and scan in and scan out terminals.\n"
"  The oaScanChain class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaScanChain)\n"
"    Calls: (const oaScanChain&)\n"
"    Signature: oaScanChain||cref-oaScanChain,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaScanChain_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaScanChain",
    sizeof(PyoaScanChainObject),
    0,
    (destructor)oaScanChain_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaScanChain_tp_compare,	/* tp_compare */
    (reprfunc)oaScanChain_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaScanChain_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaScanChain_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBlockObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaScanChain_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaScanChain_static_create_doc[] = 
"Class: oaScanChain, Function: create\n"
"  Paramegers: (oaBlock,oaString)\n"
"    Calls: oaScanChain* create(oaBlock* block,const oaString& name)\n"
"    Signature: create|ptr-oaScanChain|ptr-oaBlock,cref-oaString,ptr-oaBlockObject,ptr-oaBlockObject,ptr-oaString,simple-oaUInt4,\n"
"    This function creates a scan chain. The scan chain can specify the primary scan-in and scan-out points for this chain.\n"
"    block\n"
"    The block in which to create the scan chain\n"
"    name\n"
"    The name of the scan chain to create\n"
"    startObject\n"
"    The scan-in object for the scan chain: an oaBitTerm , oaInstTerm , or oaScanChainInst .\n"
"    stopObject\n"
"    The scan-out object for the scan chain: an oaBitTerm , oaInstTerm , or oaScanChainInst ..\n"
"    partitionName\n"
"    The name of the scan chain partition\n"
"    maxBits\n"
"    The maximum number of data bits that can be contained in the oaScanChainInsts that belong to the oaScanChainSets that get associated with this scan chain\n"
"    oacCannotSetMaxBits\n"
"    If maxBits is used on a scanChain without a partition name\n"
"    oacInvalidScanChainName\n"
"    If the name is NULL\n"
"    oacScanChainExists\n"
"    If the name is already in use\n"
"    oacInvalidScanChainObject\n"
"    if the start or stop object is not an oaBitTerm , oaInstTerm , or oaScanChain\n"
"  Paramegers: (oaBlock,oaString,oaBlockObject)\n"
"    Calls: oaScanChain* create(oaBlock* block,const oaString& name,oaBlockObject* startObject)\n"
"    Signature: create|ptr-oaScanChain|ptr-oaBlock,cref-oaString,ptr-oaBlockObject,ptr-oaBlockObject,ptr-oaString,simple-oaUInt4,\n"
"    This function creates a scan chain. The scan chain can specify the primary scan-in and scan-out points for this chain.\n"
"    block\n"
"    The block in which to create the scan chain\n"
"    name\n"
"    The name of the scan chain to create\n"
"    startObject\n"
"    The scan-in object for the scan chain: an oaBitTerm , oaInstTerm , or oaScanChainInst .\n"
"    stopObject\n"
"    The scan-out object for the scan chain: an oaBitTerm , oaInstTerm , or oaScanChainInst ..\n"
"    partitionName\n"
"    The name of the scan chain partition\n"
"    maxBits\n"
"    The maximum number of data bits that can be contained in the oaScanChainInsts that belong to the oaScanChainSets that get associated with this scan chain\n"
"    oacCannotSetMaxBits\n"
"    If maxBits is used on a scanChain without a partition name\n"
"    oacInvalidScanChainName\n"
"    If the name is NULL\n"
"    oacScanChainExists\n"
"    If the name is already in use\n"
"    oacInvalidScanChainObject\n"
"    if the start or stop object is not an oaBitTerm , oaInstTerm , or oaScanChain\n"
"  Paramegers: (oaBlock,oaString,oaBlockObject,oaBlockObject)\n"
"    Calls: oaScanChain* create(oaBlock* block,const oaString& name,oaBlockObject* startObject,oaBlockObject* stopObject)\n"
"    Signature: create|ptr-oaScanChain|ptr-oaBlock,cref-oaString,ptr-oaBlockObject,ptr-oaBlockObject,ptr-oaString,simple-oaUInt4,\n"
"    This function creates a scan chain. The scan chain can specify the primary scan-in and scan-out points for this chain.\n"
"    block\n"
"    The block in which to create the scan chain\n"
"    name\n"
"    The name of the scan chain to create\n"
"    startObject\n"
"    The scan-in object for the scan chain: an oaBitTerm , oaInstTerm , or oaScanChainInst .\n"
"    stopObject\n"
"    The scan-out object for the scan chain: an oaBitTerm , oaInstTerm , or oaScanChainInst ..\n"
"    partitionName\n"
"    The name of the scan chain partition\n"
"    maxBits\n"
"    The maximum number of data bits that can be contained in the oaScanChainInsts that belong to the oaScanChainSets that get associated with this scan chain\n"
"    oacCannotSetMaxBits\n"
"    If maxBits is used on a scanChain without a partition name\n"
"    oacInvalidScanChainName\n"
"    If the name is NULL\n"
"    oacScanChainExists\n"
"    If the name is already in use\n"
"    oacInvalidScanChainObject\n"
"    if the start or stop object is not an oaBitTerm , oaInstTerm , or oaScanChain\n"
"  Paramegers: (oaBlock,oaString,oaBlockObject,oaBlockObject,oaString)\n"
"    Calls: oaScanChain* create(oaBlock* block,const oaString& name,oaBlockObject* startObject,oaBlockObject* stopObject,oaString* partitionName)\n"
"    Signature: create|ptr-oaScanChain|ptr-oaBlock,cref-oaString,ptr-oaBlockObject,ptr-oaBlockObject,ptr-oaString,simple-oaUInt4,\n"
"    This function creates a scan chain. The scan chain can specify the primary scan-in and scan-out points for this chain.\n"
"    block\n"
"    The block in which to create the scan chain\n"
"    name\n"
"    The name of the scan chain to create\n"
"    startObject\n"
"    The scan-in object for the scan chain: an oaBitTerm , oaInstTerm , or oaScanChainInst .\n"
"    stopObject\n"
"    The scan-out object for the scan chain: an oaBitTerm , oaInstTerm , or oaScanChainInst ..\n"
"    partitionName\n"
"    The name of the scan chain partition\n"
"    maxBits\n"
"    The maximum number of data bits that can be contained in the oaScanChainInsts that belong to the oaScanChainSets that get associated with this scan chain\n"
"    oacCannotSetMaxBits\n"
"    If maxBits is used on a scanChain without a partition name\n"
"    oacInvalidScanChainName\n"
"    If the name is NULL\n"
"    oacScanChainExists\n"
"    If the name is already in use\n"
"    oacInvalidScanChainObject\n"
"    if the start or stop object is not an oaBitTerm , oaInstTerm , or oaScanChain\n"
"  Paramegers: (oaBlock,oaString,oaBlockObject,oaBlockObject,oaString,oaUInt4)\n"
"    Calls: oaScanChain* create(oaBlock* block,const oaString& name,oaBlockObject* startObject,oaBlockObject* stopObject,oaString* partitionName,oaUInt4 maxBits)\n"
"    Signature: create|ptr-oaScanChain|ptr-oaBlock,cref-oaString,ptr-oaBlockObject,ptr-oaBlockObject,ptr-oaString,simple-oaUInt4,\n"
"    This function creates a scan chain. The scan chain can specify the primary scan-in and scan-out points for this chain.\n"
"    block\n"
"    The block in which to create the scan chain\n"
"    name\n"
"    The name of the scan chain to create\n"
"    startObject\n"
"    The scan-in object for the scan chain: an oaBitTerm , oaInstTerm , or oaScanChainInst .\n"
"    stopObject\n"
"    The scan-out object for the scan chain: an oaBitTerm , oaInstTerm , or oaScanChainInst ..\n"
"    partitionName\n"
"    The name of the scan chain partition\n"
"    maxBits\n"
"    The maximum number of data bits that can be contained in the oaScanChainInsts that belong to the oaScanChainSets that get associated with this scan chain\n"
"    oacCannotSetMaxBits\n"
"    If maxBits is used on a scanChain without a partition name\n"
"    oacInvalidScanChainName\n"
"    If the name is NULL\n"
"    oacScanChainExists\n"
"    If the name is already in use\n"
"    oacInvalidScanChainObject\n"
"    if the start or stop object is not an oaBitTerm , oaInstTerm , or oaScanChain\n"
;

static PyObject*
oaScanChain_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaBlock,oaString)
    {
        PyParamoaBlock p1;
        PyParamoaString p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaString_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            oaScanChainp result= (oaScanChain::create(p1.Data(),p2.Data()));
            return PyoaScanChain_FromoaScanChain(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaString,oaBlockObject)
    {
        PyParamoaBlock p1;
        PyParamoaString p2;
        PyParamoaBlockObject p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaBlockObject_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaScanChainp result= (oaScanChain::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaScanChain_FromoaScanChain(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaString,oaBlockObject,oaBlockObject)
    {
        PyParamoaBlock p1;
        PyParamoaString p2;
        PyParamoaBlockObject p3;
        PyParamoaBlockObject p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaBlockObject_Convert,&p3,
              &PyoaBlockObject_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            if (!PyValidateDbObject(p4.Data(),4)) return NULL;
            oaScanChainp result= (oaScanChain::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaScanChain_FromoaScanChain(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaString,oaBlockObject,oaBlockObject,oaString)
    {
        PyParamoaBlock p1;
        PyParamoaString p2;
        PyParamoaBlockObject p3;
        PyParamoaBlockObject p4;
        PyParamoaString p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaBlockObject_Convert,&p3,
              &PyoaBlockObject_Convert,&p4,
              &PyoaString_ConvertAof,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            if (!PyValidateDbObject(p4.Data(),4)) return NULL;
            oaScanChainp result= (oaScanChain::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.DataAof()));
            return PyoaScanChain_FromoaScanChain(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBlock,oaString,oaBlockObject,oaBlockObject,oaString,oaUInt4)
    {
        PyParamoaBlock p1;
        PyParamoaString p2;
        PyParamoaBlockObject p3;
        PyParamoaBlockObject p4;
        PyParamoaString p5;
        PyParamoaUInt4 p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaBlock_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaBlockObject_Convert,&p3,
              &PyoaBlockObject_Convert,&p4,
              &PyoaString_ConvertAof,&p5,
              &PyoaUInt4_Convert,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            if (!PyValidateDbObject(p4.Data(),4)) return NULL;
            oaScanChainp result= (oaScanChain::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.DataAof(),p6.Data()));
            return PyoaScanChain_FromoaScanChain(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaScanChain, function: create, Choices are:\n"
        "    (oaBlock,oaString)\n"
        "    (oaBlock,oaString,oaBlockObject)\n"
        "    (oaBlock,oaString,oaBlockObject,oaBlockObject)\n"
        "    (oaBlock,oaString,oaBlockObject,oaBlockObject,oaString)\n"
        "    (oaBlock,oaString,oaBlockObject,oaBlockObject,oaString,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScanChain_static_find_doc[] = 
"Class: oaScanChain, Function: find\n"
"  Paramegers: (oaBlock,oaString)\n"
"    Calls: oaScanChain* find(const oaBlock* block,const oaString& name)\n"
"    Signature: find|ptr-oaScanChain|cptr-oaBlock,cref-oaString,\n"
"    This function searches the specified block for a scan chain with the specified name . If the scan chain is found, it is returned. Otherwise, NULL is returned.\n"
;

static PyObject*
oaScanChain_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaBlock p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaBlock_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaScanChainp result= (oaScanChain::find(p1.Data(),p2.Data()));
        return PyoaScanChain_FromoaScanChain(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaScanChain_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaScanChain_static_create,METH_VARARGS,oaScanChain_static_create_doc},
    {"static_find",(PyCFunction)oaScanChain_static_find,METH_VARARGS,oaScanChain_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaScanChain_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaScanChain_Type)<0) {
      printf("** PyType_Ready failed for: oaScanChain\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaScanChain",
           (PyObject*)(&PyoaScanChain_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaScanChain\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaScanChain_Type.tp_dict;
    for(method=oaScanChain_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaScanChainInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaScanChainInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaScanChainInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaScanChainInstObject* self = (PyoaScanChainInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaScanChainInst)
    {
        PyParamoaScanChainInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaScanChainInst_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaScanChainInst, Choices are:\n"
        "    (oaScanChainInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaScanChainInst_tp_dealloc(PyoaScanChainInstObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaScanChainInst_tp_repr(PyObject *ob)
{
    PyParamoaScanChainInst value;
    int convert_status=PyoaScanChainInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaScanChainInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaScanChainInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaScanChainInst v1;
    PyParamoaScanChainInst v2;
    int convert_status1=PyoaScanChainInst_Convert(ob1,&v1);
    int convert_status2=PyoaScanChainInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaScanChainInst_Convert(PyObject* ob,PyParamoaScanChainInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaScanChainInst_Check(ob)) {
        result->SetData( (oaScanChainInst**) ((PyoaScanChainInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaScanChainInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaScanChainInst_FromoaScanChainInst(oaScanChainInst** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaScanChainInst* data=*value;
        PyObject* bself = PyoaScanChainInst_Type.tp_alloc(&PyoaScanChainInst_Type,0);
        if (bself == NULL) return bself;
        PyoaScanChainInstObject* self = (PyoaScanChainInstObject*)bself;
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
PyObject* PyoaScanChainInst_FromoaScanChainInst(oaScanChainInst* data)
{
    if (data) {
       PyObject* bself = PyoaScanChainInst_Type.tp_alloc(&PyoaScanChainInst_Type,0);
       if (bself == NULL) return bself;
       PyoaScanChainInstObject* self = (PyoaScanChainInstObject*)bself;
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
static char oaScanChainInst_destroy_doc[] = 
"Class: oaScanChainInst, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this scan chain instance, removing it from the database. The oaInst that it pointed to is unaffected.\n"
;

static PyObject*
oaScanChainInst_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChainInst data;
    int convert_status=PyoaScanChainInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainInstObject* self=(PyoaScanChainInstObject*)ob;
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
static char oaScanChainInst_getInInstTerm_doc[] = 
"Class: oaScanChainInst, Function: getInInstTerm\n"
"  Paramegers: ()\n"
"    Calls: oaInstTerm* getInInstTerm() const\n"
"    Signature: getInInstTerm|ptr-oaInstTerm|\n"
"    BrowseData: 1\n"
"    This function returns the scan-in instance terminal associated with this scan chain instance.\n"
;

static PyObject*
oaScanChainInst_getInInstTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChainInst data;
    int convert_status=PyoaScanChainInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainInstObject* self=(PyoaScanChainInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaInstTermp result= (data.DataCall()->getInInstTerm());
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
static char oaScanChainInst_getInstance_doc[] = 
"Class: oaScanChainInst, Function: getInstance\n"
"  Paramegers: ()\n"
"    Calls: oaInst* getInstance() const\n"
"    Signature: getInstance|ptr-oaInst|\n"
"    BrowseData: 1\n"
"    This function returns the instance associated with this scan chain instance object.\n"
;

static PyObject*
oaScanChainInst_getInstance(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChainInst data;
    int convert_status=PyoaScanChainInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainInstObject* self=(PyoaScanChainInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaInstp result= (data.DataCall()->getInstance());
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
static char oaScanChainInst_getOutInstTerm_doc[] = 
"Class: oaScanChainInst, Function: getOutInstTerm\n"
"  Paramegers: ()\n"
"    Calls: oaInstTerm* getOutInstTerm() const\n"
"    Signature: getOutInstTerm|ptr-oaInstTerm|\n"
"    BrowseData: 1\n"
"    This function returns the scan-out instance terminal associated with this scan chain instance.\n"
;

static PyObject*
oaScanChainInst_getOutInstTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChainInst data;
    int convert_status=PyoaScanChainInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainInstObject* self=(PyoaScanChainInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaInstTermp result= (data.DataCall()->getOutInstTerm());
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
static char oaScanChainInst_getSeqBitLength_doc[] = 
"Class: oaScanChainInst, Function: getSeqBitLength\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getSeqBitLength() const\n"
"    Signature: getSeqBitLength|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of sequential bits this instance represents in a scanChain partition.\n"
;

static PyObject*
oaScanChainInst_getSeqBitLength(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChainInst data;
    int convert_status=PyoaScanChainInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainInstObject* self=(PyoaScanChainInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getSeqBitLength());
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
static char oaScanChainInst_setInInstTerm_doc[] = 
"Class: oaScanChainInst, Function: setInInstTerm\n"
"  Paramegers: (oaInstTerm)\n"
"    Calls: void setInInstTerm(oaInstTerm* term)\n"
"    Signature: setInInstTerm|void-void|ptr-oaInstTerm,\n"
"    This function sets the scan-in instance terminal for this scan chain instance.\n"
"    oacInvalidScanChainInstTerm\n"
"    If one of the oaInstTerms is in another design or database.\n"
"    oacInstTermAlreadyInScanChain\n"
"    If an attempt is made to call the function with an oaInstTerm that is already part of a scan chain.\n"
"    oacScanChainInstTermsNotOnSameInst\n"
"    If an attempt is made to specify input or output oaInstTerms that are not on the same instance.\n"
;

static PyObject*
oaScanChainInst_setInInstTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChainInst data;
    int convert_status=PyoaScanChainInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainInstObject* self=(PyoaScanChainInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaInstTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaInstTerm_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setInInstTerm(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScanChainInst_setInstTerms_doc[] = 
"Class: oaScanChainInst, Function: setInstTerms\n"
"  Paramegers: (oaInstTerm,oaInstTerm)\n"
"    Calls: void setInstTerms(oaInstTerm* inInstTerm,oaInstTerm* outInstTerm)\n"
"    Signature: setInstTerms|void-void|ptr-oaInstTerm,ptr-oaInstTerm,\n"
"    This function sets both the scan-in and scan-out instance terminals associated with this scan chain instance.\n"
"    oacInvalidScanChainInstTerm\n"
"    If one of the oaInstTerms is in another design or database.\n"
"    oacInstTermAlreadyInScanChain\n"
"    If an attempt is made to call the function with an oaInstTerm that is already part of a scan chain.\n"
"    oacScanChainInstTermsNotOnSameInst\n"
"    If an attempt is made to specify input or output oaInstTerms that are not on the same instance.\n"
;

static PyObject*
oaScanChainInst_setInstTerms(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChainInst data;
    int convert_status=PyoaScanChainInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainInstObject* self=(PyoaScanChainInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaInstTerm p1;
    PyParamoaInstTerm p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaInstTerm_Convert,&p1,
          &PyoaInstTerm_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        data.DataCall()->setInstTerms(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScanChainInst_setOutInstTerm_doc[] = 
"Class: oaScanChainInst, Function: setOutInstTerm\n"
"  Paramegers: (oaInstTerm)\n"
"    Calls: void setOutInstTerm(oaInstTerm* term)\n"
"    Signature: setOutInstTerm|void-void|ptr-oaInstTerm,\n"
"    This function sets the scan-out instance terminal associated with this scan chain instance.\n"
"    oacInvalidScanChainInstTerm\n"
"    If one of the oaInstTerms is in another design or database.\n"
"    oacInstTermAlreadyInScanChain\n"
"    If an attempt is made to call the function with an oaInstTerm that is already part of a scan chain.\n"
"    oacScanChainInstTermsNotOnSameInst\n"
"    If an attempt is made to specify input or output oaInstTerms that are not on the same instance.\n"
;

static PyObject*
oaScanChainInst_setOutInstTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChainInst data;
    int convert_status=PyoaScanChainInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainInstObject* self=(PyoaScanChainInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaInstTerm p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaInstTerm_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setOutInstTerm(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScanChainInst_setSeqBitLength_doc[] = 
"Class: oaScanChainInst, Function: setSeqBitLength\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setSeqBitLength(oaUInt4 numBits)\n"
"    Signature: setSeqBitLength|void-void|simple-oaUInt4,\n"
"    This function sets the number of sequential bits this scanChainInst represents in a partition length.\n"
;

static PyObject*
oaScanChainInst_setSeqBitLength(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChainInst data;
    int convert_status=PyoaScanChainInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainInstObject* self=(PyoaScanChainInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->setSeqBitLength(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScanChainInst_isNull_doc[] =
"Class: oaScanChainInst, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaScanChainInst_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaScanChainInst data;
    int convert_status=PyoaScanChainInst_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaScanChainInst_assign_doc[] = 
"Class: oaScanChainInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaScanChainInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaScanChainInst data;
  int convert_status=PyoaScanChainInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaScanChainInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaScanChainInst_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaScanChainInst_methodlist[] = {
    {"destroy",(PyCFunction)oaScanChainInst_destroy,METH_VARARGS,oaScanChainInst_destroy_doc},
    {"getInInstTerm",(PyCFunction)oaScanChainInst_getInInstTerm,METH_VARARGS,oaScanChainInst_getInInstTerm_doc},
    {"getInstance",(PyCFunction)oaScanChainInst_getInstance,METH_VARARGS,oaScanChainInst_getInstance_doc},
    {"getOutInstTerm",(PyCFunction)oaScanChainInst_getOutInstTerm,METH_VARARGS,oaScanChainInst_getOutInstTerm_doc},
    {"getSeqBitLength",(PyCFunction)oaScanChainInst_getSeqBitLength,METH_VARARGS,oaScanChainInst_getSeqBitLength_doc},
    {"setInInstTerm",(PyCFunction)oaScanChainInst_setInInstTerm,METH_VARARGS,oaScanChainInst_setInInstTerm_doc},
    {"setInstTerms",(PyCFunction)oaScanChainInst_setInstTerms,METH_VARARGS,oaScanChainInst_setInstTerms_doc},
    {"setOutInstTerm",(PyCFunction)oaScanChainInst_setOutInstTerm,METH_VARARGS,oaScanChainInst_setOutInstTerm_doc},
    {"setSeqBitLength",(PyCFunction)oaScanChainInst_setSeqBitLength,METH_VARARGS,oaScanChainInst_setSeqBitLength_doc},
    {"isNull",(PyCFunction)oaScanChainInst_tp_isNull,METH_VARARGS,oaScanChainInst_isNull_doc},
    {"assign",(PyCFunction)oaScanChainInst_tp_assign,METH_VARARGS,oaScanChainInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaScanChainInst_doc[] = 
"Class: oaScanChainInst\n"
"  The oaScanChainInst designates a scan latch instance in a scan chain and its scan-in and scan-out instTerms. oaScanChainInsts are grouped into sets by the oaScanChainSet class. Scan chain sets, in turn, are grouped into complete scan chains by the oaScanChain class. See the oaScanChain class for more discussion.\n"
"  The oaScanChainInst class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaScanChainInst)\n"
"    Calls: (const oaScanChainInst&)\n"
"    Signature: oaScanChainInst||cref-oaScanChainInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaScanChainInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaScanChainInst",
    sizeof(PyoaScanChainInstObject),
    0,
    (destructor)oaScanChainInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaScanChainInst_tp_compare,	/* tp_compare */
    (reprfunc)oaScanChainInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaScanChainInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaScanChainInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBlockObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaScanChainInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaScanChainInst_static_create_doc[] = 
"Class: oaScanChainInst, Function: create\n"
"  Paramegers: (oaScanChainSet,oaInstTerm,oaInstTerm)\n"
"    Calls: oaScanChainInst* create(oaScanChainSet* set,oaInstTerm* inTerm,oaInstTerm* outTerm)\n"
"    Signature: create|ptr-oaScanChainInst|ptr-oaScanChainSet,ptr-oaInstTerm,ptr-oaInstTerm,\n"
"    This function creates a scanChain instance in the specified scan chain set. The InstTerms may be NULL. If both instTerms are present, then they must be on a single instance.\n"
"    oacInvalidScanChainInstTerm\n"
"    If one of the oaInstTerms is in another design or database.\n"
"    oacInstTermAlreadyInScanChain\n"
"    If an attempt is made to call the function with an oaInstTerm that is already part of a scan chain.\n"
"    oacScanChainInstTermsNotOnSameInst\n"
"    If an attempt is made to specify input or output oaInstTerms that are not on the same instance.\n"
;

static PyObject*
oaScanChainInst_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChainSet p1;
    PyParamoaInstTerm p2;
    PyParamoaInstTerm p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaScanChainSet_Convert,&p1,
          &PyoaInstTerm_Convert,&p2,
          &PyoaInstTerm_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        if (!PyValidateDbObject(p3.Data(),3)) return NULL;
        oaScanChainInstp result= (oaScanChainInst::create(p1.Data(),p2.Data(),p3.Data()));
        return PyoaScanChainInst_FromoaScanChainInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaScanChainInst_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaScanChainInst_static_create,METH_VARARGS,oaScanChainInst_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaScanChainInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaScanChainInst_Type)<0) {
      printf("** PyType_Ready failed for: oaScanChainInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaScanChainInst",
           (PyObject*)(&PyoaScanChainInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaScanChainInst\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaScanChainInst_Type.tp_dict;
    for(method=oaScanChainInst_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaScanChainInstModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaScanChainInstModTypeEnum_Convert(PyObject* ob,PyParamoaScanChainInstModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetInInstTermScanChainInstModType")==0) { result->SetData(oacSetInInstTermScanChainInstModType); return 1;}
        if (strcasecmp(str,"oacSetOutInstTermScanChainInstModType")==0) { result->SetData(oacSetOutInstTermScanChainInstModType); return 1;}
        if (strcasecmp(str,"oacSetInstTermsScanChainInstModType")==0) { result->SetData(oacSetInstTermsScanChainInstModType); return 1;}
        if (strcasecmp(str,"oacScanChainSetScanChainInstModType")==0) { result->SetData(oacScanChainSetScanChainInstModType); return 1;}
        if (strcasecmp(str,"oacSetSeqBitLenScanChainInstModType")==0) { result->SetData(oacSetSeqBitLenScanChainInstModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaScanChainInstModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaScanChainInstModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaScanChainInstModTypeEnum_FromoaScanChainInstModTypeEnum(oaScanChainInstModTypeEnum ob)
{
    if (ob==oacSetInInstTermScanChainInstModType) return PyString_FromString("oacSetInInstTermScanChainInstModType");
    if (ob==oacSetOutInstTermScanChainInstModType) return PyString_FromString("oacSetOutInstTermScanChainInstModType");
    if (ob==oacSetInstTermsScanChainInstModType) return PyString_FromString("oacSetInstTermsScanChainInstModType");
    if (ob==oacScanChainSetScanChainInstModType) return PyString_FromString("oacScanChainSetScanChainInstModType");
    if (ob==oacSetSeqBitLenScanChainInstModType) return PyString_FromString("oacSetSeqBitLenScanChainInstModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaScanChainInstModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaScanChainInstModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaScanChainInstModTypeEnum_FromoaScanChainInstModTypeEnum(oaScanChainInstModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaScanChainInstModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaScanChainInstModTypeEnum_doc[] =
"Type convert function for enum: oaScanChainInstModTypeEnum";
                               
static PyMethodDef PyoaScanChainInstModTypeEnum_method =
  {"oaScanChainInstModTypeEnum",(PyCFunction)PyoaScanChainInstModTypeEnum_TypeFunction,METH_VARARGS,oaScanChainInstModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaScanChainInstModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetInInstTermScanChainInstModType");
    PyDict_SetItemString(mod_dict,"oacSetInInstTermScanChainInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetOutInstTermScanChainInstModType");
    PyDict_SetItemString(mod_dict,"oacSetOutInstTermScanChainInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetInstTermsScanChainInstModType");
    PyDict_SetItemString(mod_dict,"oacSetInstTermsScanChainInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacScanChainSetScanChainInstModType");
    PyDict_SetItemString(mod_dict,"oacScanChainSetScanChainInstModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetSeqBitLenScanChainInstModType");
    PyDict_SetItemString(mod_dict,"oacSetSeqBitLenScanChainInstModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaScanChainInstModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaScanChainInstModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaScanChainInstModTypeEnum\n");
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
// Wrapper Implementation for Class: oaScanChainModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaScanChainModTypeEnum_Convert(PyObject* ob,PyParamoaScanChainModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetNameScanChainModType")==0) { result->SetData(oacSetNameScanChainModType); return 1;}
        if (strcasecmp(str,"oacSetStartObjectScanChainModType")==0) { result->SetData(oacSetStartObjectScanChainModType); return 1;}
        if (strcasecmp(str,"oacSetStopObjectScanChainModType")==0) { result->SetData(oacSetStopObjectScanChainModType); return 1;}
        if (strcasecmp(str,"oacSetOrderedSetScanChainModType")==0) { result->SetData(oacSetOrderedSetScanChainModType); return 1;}
        if (strcasecmp(str,"oacSetUnorderedSetScanChainModType")==0) { result->SetData(oacSetUnorderedSetScanChainModType); return 1;}
        if (strcasecmp(str,"oacSetPartitionNameScanChainModType")==0) { result->SetData(oacSetPartitionNameScanChainModType); return 1;}
        if (strcasecmp(str,"oacSetMaxBitsScanChainModType")==0) { result->SetData(oacSetMaxBitsScanChainModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaScanChainModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaScanChainModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaScanChainModTypeEnum_FromoaScanChainModTypeEnum(oaScanChainModTypeEnum ob)
{
    if (ob==oacSetNameScanChainModType) return PyString_FromString("oacSetNameScanChainModType");
    if (ob==oacSetStartObjectScanChainModType) return PyString_FromString("oacSetStartObjectScanChainModType");
    if (ob==oacSetStopObjectScanChainModType) return PyString_FromString("oacSetStopObjectScanChainModType");
    if (ob==oacSetOrderedSetScanChainModType) return PyString_FromString("oacSetOrderedSetScanChainModType");
    if (ob==oacSetUnorderedSetScanChainModType) return PyString_FromString("oacSetUnorderedSetScanChainModType");
    if (ob==oacSetPartitionNameScanChainModType) return PyString_FromString("oacSetPartitionNameScanChainModType");
    if (ob==oacSetMaxBitsScanChainModType) return PyString_FromString("oacSetMaxBitsScanChainModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaScanChainModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaScanChainModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaScanChainModTypeEnum_FromoaScanChainModTypeEnum(oaScanChainModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaScanChainModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaScanChainModTypeEnum_doc[] =
"Type convert function for enum: oaScanChainModTypeEnum";
                               
static PyMethodDef PyoaScanChainModTypeEnum_method =
  {"oaScanChainModTypeEnum",(PyCFunction)PyoaScanChainModTypeEnum_TypeFunction,METH_VARARGS,oaScanChainModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaScanChainModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetNameScanChainModType");
    PyDict_SetItemString(mod_dict,"oacSetNameScanChainModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetStartObjectScanChainModType");
    PyDict_SetItemString(mod_dict,"oacSetStartObjectScanChainModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetStopObjectScanChainModType");
    PyDict_SetItemString(mod_dict,"oacSetStopObjectScanChainModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetOrderedSetScanChainModType");
    PyDict_SetItemString(mod_dict,"oacSetOrderedSetScanChainModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetUnorderedSetScanChainModType");
    PyDict_SetItemString(mod_dict,"oacSetUnorderedSetScanChainModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetPartitionNameScanChainModType");
    PyDict_SetItemString(mod_dict,"oacSetPartitionNameScanChainModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetMaxBitsScanChainModType");
    PyDict_SetItemString(mod_dict,"oacSetMaxBitsScanChainModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaScanChainModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaScanChainModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaScanChainModTypeEnum\n");
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
// Wrapper Implementation for Class: oaScanChainSet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaScanChainSet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaScanChainSet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaScanChainSetObject* self = (PyoaScanChainSetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaScanChainSet)
    {
        PyParamoaScanChainSet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaScanChainSet_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaScanChainSet, Choices are:\n"
        "    (oaScanChainSet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaScanChainSet_tp_dealloc(PyoaScanChainSetObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaScanChainSet_tp_repr(PyObject *ob)
{
    PyParamoaScanChainSet value;
    int convert_status=PyoaScanChainSet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[36];
    sprintf(buffer,"<oaScanChainSet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaScanChainSet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaScanChainSet v1;
    PyParamoaScanChainSet v2;
    int convert_status1=PyoaScanChainSet_Convert(ob1,&v1);
    int convert_status2=PyoaScanChainSet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaScanChainSet_Convert(PyObject* ob,PyParamoaScanChainSet* result)
{
    if (ob == NULL) return 1;
    if (PyoaScanChainSet_Check(ob)) {
        result->SetData( (oaScanChainSet**) ((PyoaScanChainSetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaScanChainSet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaScanChainSet_FromoaScanChainSet(oaScanChainSet** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaScanChainSet* data=*value;
        PyObject* bself = PyoaScanChainSet_Type.tp_alloc(&PyoaScanChainSet_Type,0);
        if (bself == NULL) return bself;
        PyoaScanChainSetObject* self = (PyoaScanChainSetObject*)bself;
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
PyObject* PyoaScanChainSet_FromoaScanChainSet(oaScanChainSet* data)
{
    if (data) {
       PyObject* bself = PyoaScanChainSet_Type.tp_alloc(&PyoaScanChainSet_Type,0);
       if (bself == NULL) return bself;
       PyoaScanChainSetObject* self = (PyoaScanChainSetObject*)bself;
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
static char oaScanChainSet_destroy_doc[] = 
"Class: oaScanChainSet, Function: destroy\n"
"  Paramegers: ()\n"
"    Calls: void destroy()\n"
"    Signature: destroy|void-void|\n"
"    BrowseData: 0\n"
"    This function destroys this scan chain set, removing it from the database.\n"
;

static PyObject*
oaScanChainSet_destroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChainSet data;
    int convert_status=PyoaScanChainSet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainSetObject* self=(PyoaScanChainSetObject*)ob;
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
static char oaScanChainSet_getInstances_doc[] = 
"Class: oaScanChainSet, Function: getInstances\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaScanChainInst_oaScanChainSet getInstances() const\n"
"    Signature: getInstances|simple-oaCollection_oaScanChainInst_oaScanChainSet|\n"
"    BrowseData: 1\n"
"    This function returns a collection of the scan instances in this set.\n"
;

static PyObject*
oaScanChainSet_getInstances(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChainSet data;
    int convert_status=PyoaScanChainSet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainSetObject* self=(PyoaScanChainSetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaScanChainInst_oaScanChainSet* result= new oaCollection_oaScanChainInst_oaScanChainSet(data.DataCall()->getInstances());
        return PyoaCollection_oaScanChainInst_oaScanChainSet_FromoaCollection_oaScanChainInst_oaScanChainSet(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScanChainSet_getInstancesIter_doc[] = 
"Class: oaScanChainSet, Function: getInstancesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaScanChainInst getInstancesIter() const\n"
"    Signature: getInstancesIter|simple-oaIter_oaScanChainInst|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of the scan instances in this set.\n"
;

static PyObject*
oaScanChainSet_getInstancesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChainSet data;
    int convert_status=PyoaScanChainSet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainSetObject* self=(PyoaScanChainSetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaScanChainInst* result= new oaIter_oaScanChainInst(data.DataCall()->getInstances());
        return PyoaIter_oaScanChainInst_FromoaIter_oaScanChainInst(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaScanChainSet_isNull_doc[] =
"Class: oaScanChainSet, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaScanChainSet_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaScanChainSet data;
    int convert_status=PyoaScanChainSet_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaScanChainSet_assign_doc[] = 
"Class: oaScanChainSet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaScanChainSet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaScanChainSet data;
  int convert_status=PyoaScanChainSet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaScanChainSet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaScanChainSet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaScanChainSet_methodlist[] = {
    {"destroy",(PyCFunction)oaScanChainSet_destroy,METH_VARARGS,oaScanChainSet_destroy_doc},
    {"getInstances",(PyCFunction)oaScanChainSet_getInstances,METH_VARARGS,oaScanChainSet_getInstances_doc},
    {"getInstancesIter",(PyCFunction)oaScanChainSet_getInstancesIter,METH_VARARGS,oaScanChainSet_getInstancesIter_doc},
    {"isNull",(PyCFunction)oaScanChainSet_tp_isNull,METH_VARARGS,oaScanChainSet_isNull_doc},
    {"assign",(PyCFunction)oaScanChainSet_tp_assign,METH_VARARGS,oaScanChainSet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaScanChainSet_doc[] = 
"Class: oaScanChainSet\n"
"  The oaScanChainSet class collects a set of oaScanChainInst objects that are intended to be implemented on a single scan chain. The complete scan chain may have multiple oaScanChainSets. See oaScanChain for a discussion of the scan chain data model.\n"
"  The oaScanChainSet class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaScanChainSet)\n"
"    Calls: (const oaScanChainSet&)\n"
"    Signature: oaScanChainSet||cref-oaScanChainSet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaScanChainSet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaScanChainSet",
    sizeof(PyoaScanChainSetObject),
    0,
    (destructor)oaScanChainSet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaScanChainSet_tp_compare,	/* tp_compare */
    (reprfunc)oaScanChainSet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaScanChainSet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaScanChainSet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBlockObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaScanChainSet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaScanChainSet_static_create_doc[] = 
"Class: oaScanChainSet, Function: create\n"
"  Paramegers: (oaScanChain,oaScanChainSetType)\n"
"    Calls: oaScanChainSet* create(oaScanChain* scanChain,oaScanChainSetType setType)\n"
"    Signature: create|ptr-oaScanChainSet|ptr-oaScanChain,simple-oaScanChainSetType,\n"
"    This function creates a new set to collect scan instances in the specified oaScanChain object. This set may specify the intended order of the instances in the final design, or it may be unordered to indicate that the ordering will be determined later. At most one set in any scan chain may be unordered.\n"
"    scanChain\n"
"    The scan chain in which to create an instance set\n"
"    setType\n"
"    Indicates whether this set is ordered or unordered\n"
"    oacErrorCanOnlyHaveOneUnorderedSet\n"
;

static PyObject*
oaScanChainSet_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChain p1;
    PyParamoaScanChainSetType p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaScanChain_Convert,&p1,
          &PyoaScanChainSetType_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaScanChainSetp result= (oaScanChainSet::create(p1.Data(),p2.Data()));
        return PyoaScanChainSet_FromoaScanChainSet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaScanChainSet_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaScanChainSet_static_create,METH_VARARGS,oaScanChainSet_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaScanChainSet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaScanChainSet_Type)<0) {
      printf("** PyType_Ready failed for: oaScanChainSet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaScanChainSet",
           (PyObject*)(&PyoaScanChainSet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaScanChainSet\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaScanChainSet_Type.tp_dict;
    for(method=oaScanChainSet_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaScanChainSetModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaScanChainSetModTypeEnum_Convert(PyObject* ob,PyParamoaScanChainSetModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaScanChainSetModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaScanChainSetModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaScanChainSetModTypeEnum_FromoaScanChainSetModTypeEnum(oaScanChainSetModTypeEnum ob)
{

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaScanChainSetModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaScanChainSetModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaScanChainSetModTypeEnum_FromoaScanChainSetModTypeEnum(oaScanChainSetModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaScanChainSetModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaScanChainSetModTypeEnum_doc[] =
"Type convert function for enum: oaScanChainSetModTypeEnum";
                               
static PyMethodDef PyoaScanChainSetModTypeEnum_method =
  {"oaScanChainSetModTypeEnum",(PyCFunction)PyoaScanChainSetModTypeEnum_TypeFunction,METH_VARARGS,oaScanChainSetModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaScanChainSetModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaScanChainSetModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaScanChainSetModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaScanChainSetModTypeEnum\n");
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
// Wrapper Implementation for Class: oaScanChainSetType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaScanChainSetType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaScanChainSetType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaScanChainSetTypeObject* self = (PyoaScanChainSetTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaScanChainSetTypeEnum)
    {
        PyParamoaScanChainSetTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScanChainSetTypeEnum_Convert,&p1)) {
            self->value =  new oaScanChainSetType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaScanChainSetType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaScanChainSetType)
    {
        PyParamoaScanChainSetType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaScanChainSetType_Convert,&p1)) {
            self->value= new oaScanChainSetType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaScanChainSetType, Choices are:\n"
        "    (oaScanChainSetTypeEnum)\n"
        "    (oaString)\n"
        "    (oaScanChainSetType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaScanChainSetType_tp_dealloc(PyoaScanChainSetTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaScanChainSetType_tp_repr(PyObject *ob)
{
    PyParamoaScanChainSetType value;
    int convert_status=PyoaScanChainSetType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[40];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaScanChainSetType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaScanChainSetType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaScanChainSetType v1;
    PyParamoaScanChainSetType v2;
    int convert_status1=PyoaScanChainSetType_Convert(ob1,&v1);
    int convert_status2=PyoaScanChainSetType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaScanChainSetType_Convert(PyObject* ob,PyParamoaScanChainSetType* result)
{
    if (ob == NULL) return 1;
    if (PyoaScanChainSetType_Check(ob)) {
        result->SetData(  ((PyoaScanChainSetTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaScanChainSetType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaScanChainSetType_FromoaScanChainSetType(oaScanChainSetType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaScanChainSetType_Type.tp_alloc(&PyoaScanChainSetType_Type,0);
        if (bself == NULL) return bself;
        PyoaScanChainSetTypeObject* self = (PyoaScanChainSetTypeObject*)bself;
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
static char oaScanChainSetType_getName_doc[] = 
"Class: oaScanChainSetType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaScanChainSetTypeEnum object.\n"
;

static PyObject*
oaScanChainSetType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChainSetType data;
    int convert_status=PyoaScanChainSetType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainSetTypeObject* self=(PyoaScanChainSetTypeObject*)ob;

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
static char oaScanChainSetType_oaScanChainSetTypeEnum_doc[] = 
"Class: oaScanChainSetType, Function: oaScanChainSetTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaScanChainSetTypeEnum oaScanChainSetTypeEnum() const\n"
"    Signature: operator oaScanChainSetTypeEnum|simple-oaScanChainSetTypeEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaScanChainSetType object into the corresponding #oaScanChainSetTypeEnum value.\n"
;

static PyObject*
oaScanChainSetType_oaScanChainSetTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaScanChainSetType data;
    int convert_status=PyoaScanChainSetType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaScanChainSetTypeObject* self=(PyoaScanChainSetTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaScanChainSetTypeEnum result= (data.DataCall()->operator oaScanChainSetTypeEnum());
        return PyoaScanChainSetTypeEnum_FromoaScanChainSetTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaScanChainSetType_assign_doc[] = 
"Class: oaScanChainSetType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaScanChainSetType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaScanChainSetType data;
  int convert_status=PyoaScanChainSetType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaScanChainSetType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaScanChainSetType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaScanChainSetType_methodlist[] = {
    {"getName",(PyCFunction)oaScanChainSetType_getName,METH_VARARGS,oaScanChainSetType_getName_doc},
    {"oaScanChainSetTypeEnum",(PyCFunction)oaScanChainSetType_oaScanChainSetTypeEnum,METH_VARARGS,oaScanChainSetType_oaScanChainSetTypeEnum_doc},
    {"assign",(PyCFunction)oaScanChainSetType_tp_assign,METH_VARARGS,oaScanChainSetType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaScanChainSetType_doc[] = 
"Class: oaScanChainSetType\n"
"  The oaScanChainSetType is an enum wrapper class that specifies if an oaScanChainSet is ordered.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaScanChainSetTypeEnum\n"
"Constructors:\n"
"  Paramegers: (oaScanChainSetTypeEnum)\n"
"    Calls: oaScanChainSetType(oaScanChainSetTypeEnum valueIn)\n"
"    Signature: oaScanChainSetType||simple-oaScanChainSetTypeEnum,\n"
"    This function constructs an instance of an oaScanChainSetType class using the specified #oaScanChainSetTypeEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaScanChainSetType(const oaString& name)\n"
"    Signature: oaScanChainSetType||cref-oaString,\n"
"    This function constructs an instance of a oaScanChainSetType class using the #oaScanChainSetTypeEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaScanChainSetTypeEnum.\n"
"    oacInvalidScanChainSetTypeName\n"
"  Paramegers: (oaScanChainSetType)\n"
"    Calls: (const oaScanChainSetType&)\n"
"    Signature: oaScanChainSetType||cref-oaScanChainSetType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaScanChainSetType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaScanChainSetType",
    sizeof(PyoaScanChainSetTypeObject),
    0,
    (destructor)oaScanChainSetType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaScanChainSetType_tp_compare,	/* tp_compare */
    (reprfunc)oaScanChainSetType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaScanChainSetType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaScanChainSetType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaScanChainSetType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaScanChainSetType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaScanChainSetType_Type)<0) {
      printf("** PyType_Ready failed for: oaScanChainSetType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaScanChainSetType",
           (PyObject*)(&PyoaScanChainSetType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaScanChainSetType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaScanChainSetTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaScanChainSetTypeEnum_Convert(PyObject* ob,PyParamoaScanChainSetTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacOrderedScanChainSetType")==0) { result->SetData(oacOrderedScanChainSetType); return 1;}
        if (strcasecmp(str,"oacUnorderedScanChainSetType")==0) { result->SetData(oacUnorderedScanChainSetType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaScanChainSetTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaScanChainSetTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaScanChainSetTypeEnum_FromoaScanChainSetTypeEnum(oaScanChainSetTypeEnum ob)
{
    if (ob==oacOrderedScanChainSetType) return PyString_FromString("oacOrderedScanChainSetType");
    if (ob==oacUnorderedScanChainSetType) return PyString_FromString("oacUnorderedScanChainSetType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaScanChainSetTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaScanChainSetTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaScanChainSetTypeEnum_FromoaScanChainSetTypeEnum(oaScanChainSetTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaScanChainSetTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaScanChainSetTypeEnum_doc[] =
"Type convert function for enum: oaScanChainSetTypeEnum";
                               
static PyMethodDef PyoaScanChainSetTypeEnum_method =
  {"oaScanChainSetTypeEnum",(PyCFunction)PyoaScanChainSetTypeEnum_TypeFunction,METH_VARARGS,oaScanChainSetTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaScanChainSetTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacOrderedScanChainSetType");
    PyDict_SetItemString(mod_dict,"oacOrderedScanChainSetType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacUnorderedScanChainSetType");
    PyDict_SetItemString(mod_dict,"oacUnorderedScanChainSetType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaScanChainSetTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaScanChainSetTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaScanChainSetTypeEnum\n");
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
// Wrapper Implementation for Class: oaSegStyle
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaSegStyle_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaSegStyle_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaSegStyleObject* self = (PyoaSegStyleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaSegStyle();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaDist,oaEndStyle,oaEndStyle)
    {
        PyParamoaDist p1;
        PyParamoaEndStyle p2;
        PyParamoaEndStyle p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaDist_Convert,&p1,
              &PyoaEndStyle_Convert,&p2,
              &PyoaEndStyle_Convert,&p3)) {
            self->value =  new oaSegStyle(p1.Data(),p2.Data(),p3.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaDist,oaEndStyle,oaEndStyle,oaDist)
    {
        PyParamoaDist p1;
        PyParamoaEndStyle p2;
        PyParamoaEndStyle p3;
        PyParamoaDist p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaDist_Convert,&p1,
              &PyoaEndStyle_Convert,&p2,
              &PyoaEndStyle_Convert,&p3,
              &PyoaDist_Convert,&p4)) {
            self->value =  new oaSegStyle(p1.Data(),p2.Data(),p3.Data(),p4.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaDist,oaEndStyle,oaEndStyle,oaDist,oaDist)
    {
        PyParamoaDist p1;
        PyParamoaEndStyle p2;
        PyParamoaEndStyle p3;
        PyParamoaDist p4;
        PyParamoaDist p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaDist_Convert,&p1,
              &PyoaEndStyle_Convert,&p2,
              &PyoaEndStyle_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaDist_Convert,&p5)) {
            self->value =  new oaSegStyle(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaEndStyle,oaEndStyle,oaDist,oaDist,oaDist,oaDist)
    {
        PyParamoaEndStyle p1;
        PyParamoaEndStyle p2;
        PyParamoaDist p3;
        PyParamoaDist p4;
        PyParamoaDist p5;
        PyParamoaDist p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaEndStyle_Convert,&p1,
              &PyoaEndStyle_Convert,&p2,
              &PyoaDist_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaDist_Convert,&p5,
              &PyoaDist_Convert,&p6)) {
            self->value =  new oaSegStyle(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaEndStyle,oaEndStyle,oaDist,oaDist,oaDist,oaDist,oaDist)
    {
        PyParamoaEndStyle p1;
        PyParamoaEndStyle p2;
        PyParamoaDist p3;
        PyParamoaDist p4;
        PyParamoaDist p5;
        PyParamoaDist p6;
        PyParamoaDist p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaEndStyle_Convert,&p1,
              &PyoaEndStyle_Convert,&p2,
              &PyoaDist_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaDist_Convert,&p5,
              &PyoaDist_Convert,&p6,
              &PyoaDist_Convert,&p7)) {
            self->value =  new oaSegStyle(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaEndStyle,oaDist,oaDist,oaDist,oaDist,oaEndStyle)
    {
        PyParamoaEndStyle p1;
        PyParamoaDist p2;
        PyParamoaDist p3;
        PyParamoaDist p4;
        PyParamoaDist p5;
        PyParamoaEndStyle p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaEndStyle_Convert,&p1,
              &PyoaDist_Convert,&p2,
              &PyoaDist_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaDist_Convert,&p5,
              &PyoaEndStyle_Convert,&p6)) {
            self->value =  new oaSegStyle(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaEndStyle,oaDist,oaDist,oaDist,oaDist,oaEndStyle,oaDist)
    {
        PyParamoaEndStyle p1;
        PyParamoaDist p2;
        PyParamoaDist p3;
        PyParamoaDist p4;
        PyParamoaDist p5;
        PyParamoaEndStyle p6;
        PyParamoaDist p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaEndStyle_Convert,&p1,
              &PyoaDist_Convert,&p2,
              &PyoaDist_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaDist_Convert,&p5,
              &PyoaEndStyle_Convert,&p6,
              &PyoaDist_Convert,&p7)) {
            self->value =  new oaSegStyle(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaEndStyle,oaDist,oaDist,oaDist,oaDist,oaEndStyle,oaDist,oaDist,oaDist,oaDist)
    {
        PyParamoaEndStyle p1;
        PyParamoaDist p2;
        PyParamoaDist p3;
        PyParamoaDist p4;
        PyParamoaDist p5;
        PyParamoaEndStyle p6;
        PyParamoaDist p7;
        PyParamoaDist p8;
        PyParamoaDist p9;
        PyParamoaDist p10;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&O&O&",
              &PyoaEndStyle_Convert,&p1,
              &PyoaDist_Convert,&p2,
              &PyoaDist_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaDist_Convert,&p5,
              &PyoaEndStyle_Convert,&p6,
              &PyoaDist_Convert,&p7,
              &PyoaDist_Convert,&p8,
              &PyoaDist_Convert,&p9,
              &PyoaDist_Convert,&p10)) {
            self->value =  new oaSegStyle(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data(),p9.Data(),p10.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaSegStyle)
    {
        PyParamoaSegStyle p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaSegStyle_Convert,&p1)) {
            self->value =  new oaSegStyle(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaSegStyle, Choices are:\n"
        "    ()\n"
        "    (oaDist,oaEndStyle,oaEndStyle)\n"
        "    (oaDist,oaEndStyle,oaEndStyle,oaDist)\n"
        "    (oaDist,oaEndStyle,oaEndStyle,oaDist,oaDist)\n"
        "    (oaEndStyle,oaEndStyle,oaDist,oaDist,oaDist,oaDist)\n"
        "    (oaEndStyle,oaEndStyle,oaDist,oaDist,oaDist,oaDist,oaDist)\n"
        "    (oaEndStyle,oaDist,oaDist,oaDist,oaDist,oaEndStyle)\n"
        "    (oaEndStyle,oaDist,oaDist,oaDist,oaDist,oaEndStyle,oaDist)\n"
        "    (oaEndStyle,oaDist,oaDist,oaDist,oaDist,oaEndStyle,oaDist,oaDist,oaDist,oaDist)\n"
        "    (oaSegStyle)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaSegStyle_tp_dealloc(PyoaSegStyleObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaSegStyle_tp_repr(PyObject *ob)
{
    PyParamoaSegStyle value;
    int convert_status=PyoaSegStyle_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[32];
    sprintf(buffer,"<oaSegStyle::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaSegStyle_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaSegStyle v1;
    PyParamoaSegStyle v2;
    int convert_status1=PyoaSegStyle_Convert(ob1,&v1);
    int convert_status2=PyoaSegStyle_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    if (v1.Data()==v2.Data()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaSegStyle_Convert(PyObject* ob,PyParamoaSegStyle* result)
{
    if (ob == NULL) return 1;
    if (PyoaSegStyle_Check(ob)) {
        result->SetData(  ((PyoaSegStyleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaSegStyle Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaSegStyle_FromoaSegStyle(oaSegStyle* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaSegStyle_Type.tp_alloc(&PyoaSegStyle_Type,0);
        if (bself == NULL) return bself;
        PyoaSegStyleObject* self = (PyoaSegStyleObject*)bself;
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
static char oaSegStyle_getBeginExt_doc[] = 
"Class: oaSegStyle, Function: getBeginExt\n"
"  Paramegers: ()\n"
"    Calls: oaDist getBeginExt() const\n"
"    Signature: getBeginExt|simple-oaDist|\n"
"    BrowseData: 1\n"
"    This function returns the regular begin extension this object represents for an oaPathSeg object to which it may be applied. The return value is valid only if the begin endStyle is variable or custom chamfered. A zero is returned if the begin endStyle is truncate, extend or chamfer.\n"
"  Paramegers: (oaDist,oaDist,oaDist,oaDist)\n"
"    Calls: void getBeginExt(oaDist& ext,oaDist& leftDiagExt,oaDist& rightDiagExt,oaDist& rightHalfWidth) const\n"
"    Signature: getBeginExt|void-void|ref-oaDist,ref-oaDist,ref-oaDist,ref-oaDist,\n"
"    BrowseData: 0,oaDist,oaDist,oaDist,oaDist\n"
"    This function returns the custom begin extension values this object represents for an oaPathSeg object to which it may be applied. All returned values are valid if the begin endStyle is custom chamfered. Only 'ext' is valid if the begin endStyle is variable. For all other endStyles the returned values will be zero.\n"
"    ext\n"
"    This parameter gets populated with the regular begin extension\n"
"    leftDiagExt\n"
"    This parameter gets populated with the left diagonal extension\n"
"    rightDiagExt\n"
"    This parameter gets populated with the right diagonal extension\n"
"    rightHalfWidth\n"
"    This parameter gets populated with the right half width\n"
;

static PyObject*
oaSegStyle_getBeginExt(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegStyle data;
    int convert_status=PyoaSegStyle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegStyleObject* self=(PyoaSegStyleObject*)ob;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaDist result= (data.DataCall()->getBeginExt());
            return PyoaDist_FromoaDist(result);
        }
    }
    PyErr_Clear();
    // Case: (oaDist,oaDist,oaDist,oaDist)
    {
        PyParamoaDist p1;
        PyParamoaDist p2;
        PyParamoaDist p3;
        PyParamoaDist p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaDist_Convert,&p1,
              &PyoaDist_Convert,&p2,
              &PyoaDist_Convert,&p3,
              &PyoaDist_Convert,&p4)) {
            data.DataCall()->getBeginExt(p1.Data(),p2.Data(),p3.Data(),p4.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaSegStyle, function: getBeginExt, Choices are:\n"
        "    ()\n"
        "    (oaDist,oaDist,oaDist,oaDist)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSegStyle_getBeginStyle_doc[] = 
"Class: oaSegStyle, Function: getBeginStyle\n"
"  Paramegers: ()\n"
"    Calls: oaEndStyle getBeginStyle() const\n"
"    Signature: getBeginStyle|simple-oaEndStyle|\n"
"    BrowseData: 1\n"
"    This function returns an oaEndStyle object that this object represents for the beginning of an oaPathSeg object to which it may be applied.\n"
;

static PyObject*
oaSegStyle_getBeginStyle(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegStyle data;
    int convert_status=PyoaSegStyle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegStyleObject* self=(PyoaSegStyleObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaEndStyle* result= new oaEndStyle(data.DataCall()->getBeginStyle());
        return PyoaEndStyle_FromoaEndStyle(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSegStyle_getEndExt_doc[] = 
"Class: oaSegStyle, Function: getEndExt\n"
"  Paramegers: ()\n"
"    Calls: oaDist getEndExt() const\n"
"    Signature: getEndExt|simple-oaDist|\n"
"    BrowseData: 1\n"
"    This function returns the regular end extension this object represents for an oaPathSeg object to which it may be applied. The return value is valid only if the end endStyle is variable or custom chamfered. A zero is returned if the end endStyle is truncate, extend or chamfer.\n"
"  Paramegers: (oaDist,oaDist,oaDist,oaDist)\n"
"    Calls: void getEndExt(oaDist& ext,oaDist& leftDiagExt,oaDist& rightDiagExt,oaDist& rightHalfWidth) const\n"
"    Signature: getEndExt|void-void|ref-oaDist,ref-oaDist,ref-oaDist,ref-oaDist,\n"
"    BrowseData: 0,oaDist,oaDist,oaDist,oaDist\n"
"    This function returns the custom end extension values this object represents for an oaPathSeg object to which it may be applied. All returned values are valid if the end endStyle is custom chamfered. Only 'ext' is valid if the end endStyle is variable. For all other endStyles the returned values will be zero.\n"
"    ext\n"
"    This parameter gets populated with the regular end extension\n"
"    leftDiagExt\n"
"    This parameter gets populated with the left diagonal extension\n"
"    rightDiagExt\n"
"    This parameter gets populated with the right diagonal extension\n"
"    rightHalfWidth\n"
"    This parameter gets populated with the right half width\n"
;

static PyObject*
oaSegStyle_getEndExt(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegStyle data;
    int convert_status=PyoaSegStyle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegStyleObject* self=(PyoaSegStyleObject*)ob;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaDist result= (data.DataCall()->getEndExt());
            return PyoaDist_FromoaDist(result);
        }
    }
    PyErr_Clear();
    // Case: (oaDist,oaDist,oaDist,oaDist)
    {
        PyParamoaDist p1;
        PyParamoaDist p2;
        PyParamoaDist p3;
        PyParamoaDist p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaDist_Convert,&p1,
              &PyoaDist_Convert,&p2,
              &PyoaDist_Convert,&p3,
              &PyoaDist_Convert,&p4)) {
            data.DataCall()->getEndExt(p1.Data(),p2.Data(),p3.Data(),p4.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaSegStyle, function: getEndExt, Choices are:\n"
        "    ()\n"
        "    (oaDist,oaDist,oaDist,oaDist)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSegStyle_getEndStyle_doc[] = 
"Class: oaSegStyle, Function: getEndStyle\n"
"  Paramegers: ()\n"
"    Calls: oaEndStyle getEndStyle() const\n"
"    Signature: getEndStyle|simple-oaEndStyle|\n"
"    BrowseData: 1\n"
"    This function returns an oaEndStyle object that this object represents for the end of an oaPathSeg object to which it may be applied.\n"
;

static PyObject*
oaSegStyle_getEndStyle(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegStyle data;
    int convert_status=PyoaSegStyle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegStyleObject* self=(PyoaSegStyleObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaEndStyle* result= new oaEndStyle(data.DataCall()->getEndStyle());
        return PyoaEndStyle_FromoaEndStyle(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSegStyle_getWidth_doc[] = 
"Class: oaSegStyle, Function: getWidth\n"
"  Paramegers: ()\n"
"    Calls: oaDist getWidth() const\n"
"    Signature: getWidth|simple-oaDist|\n"
"    BrowseData: 1\n"
"    This function returns the width that this osSegStyle object currently represents. The returned value can be either be in regular orthogonal units or diagonal units based on the user context.\n"
;

static PyObject*
oaSegStyle_getWidth(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegStyle data;
    int convert_status=PyoaSegStyle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegStyleObject* self=(PyoaSegStyleObject*)ob;

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
static char oaSegStyle_setBeginStyle_doc[] = 
"Class: oaSegStyle, Function: setBeginStyle\n"
"  Paramegers: (oaEndStyle)\n"
"    Calls: void setBeginStyle(oaEndStyle style)\n"
"    Signature: setBeginStyle|void-void|simple-oaEndStyle,simple-oaDist,\n"
"    This function sets the begin endStyle for this segStyle and should be used for the non-custom endStyles only. If an extension 'ext' is specified, the style must be variable. An exception is thrown if these criteria are not met. If the end endStyle is a custom endStyle, the width gets adjusted to be double that of the endRightHalfWidth. Otherwise, it remains unchanged.\n"
"    The value of 'ext' should be specified in regular database units if the style is to be used for orthogonal segments and in diagonal database units if the intended use is for diagonal segments.\n"
"    style\n"
"    The new end style that this object will represent for the beginning of an oaPathSeg .\n"
"    ext\n"
"    The extension value that this object will represent for the beginning of an oaPathSeg\n"
"    oacCustomEndStyleNotAllowedForBegin\n"
"    oacInvalidSegStyleBeginExtValue\n"
"  Paramegers: (oaEndStyle,oaDist)\n"
"    Calls: void setBeginStyle(oaEndStyle style,oaDist ext)\n"
"    Signature: setBeginStyle|void-void|simple-oaEndStyle,simple-oaDist,\n"
"    This function sets the begin endStyle for this segStyle and should be used for the non-custom endStyles only. If an extension 'ext' is specified, the style must be variable. An exception is thrown if these criteria are not met. If the end endStyle is a custom endStyle, the width gets adjusted to be double that of the endRightHalfWidth. Otherwise, it remains unchanged.\n"
"    The value of 'ext' should be specified in regular database units if the style is to be used for orthogonal segments and in diagonal database units if the intended use is for diagonal segments.\n"
"    style\n"
"    The new end style that this object will represent for the beginning of an oaPathSeg .\n"
"    ext\n"
"    The extension value that this object will represent for the beginning of an oaPathSeg\n"
"    oacCustomEndStyleNotAllowedForBegin\n"
"    oacInvalidSegStyleBeginExtValue\n"
"  Paramegers: (oaEndStyle,oaDist,oaDist,oaDist,oaDist)\n"
"    Calls: void setBeginStyle(oaEndStyle style,oaDist ext,oaDist leftDiagExt,oaDist rightDiagExt,oaDist rightHalfWidth)\n"
"    Signature: setBeginStyle|void-void|simple-oaEndStyle,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaDist,\n"
"    This function sets the begin endStyle of this segStyle, and should be used for setting custom endStyles only. An exception is thrown if this requirement is not met. The width of this object is adjusted according to whether the segStyle at the end is custom or non-custom.\n"
"    The ext and rightHalfWidth values should be specified in regular database units if this segStyle is intended to be used for orthogonal segments. These values should be set in diagonal database units if it is intended to be used for diagonal segments.\n"
"    Conversely, the leftDiagExt and rightDiagExt values should be specified in diagonal database units if this segStyle is intended to be used for orthogonal segments, and they should be set in regular database units if it is intended to be used for diagonal segments.\n"
"    style\n"
"    The oaEndStyle to be used for the beginning of an oaPathSeg\n"
"    ext\n"
"    The extension to be used at the beginning of an oaPathSeg\n"
"    leftDiagExt\n"
"    The left diagonal extension to be used at the beginning of an oaPathSeg\n"
"    rightDiagExt\n"
"    The right diagonal extension to be used at the beginning of an oaPathSeg\n"
"    rightHalfWidth\n"
"    The right half width to be used at the beginning of an oaPathSeg\n"
"    oacOnlyCustomEndStyleAllowedForBegin\n"
;

static PyObject*
oaSegStyle_setBeginStyle(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegStyle data;
    int convert_status=PyoaSegStyle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegStyleObject* self=(PyoaSegStyleObject*)ob;

    // Case: (oaEndStyle)
    {
        PyParamoaEndStyle p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaEndStyle_Convert,&p1)) {
            data.DataCall()->setBeginStyle(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaEndStyle,oaDist)
    {
        PyParamoaEndStyle p1;
        PyParamoaDist p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaEndStyle_Convert,&p1,
              &PyoaDist_Convert,&p2)) {
            data.DataCall()->setBeginStyle(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaEndStyle,oaDist,oaDist,oaDist,oaDist)
    {
        PyParamoaEndStyle p1;
        PyParamoaDist p2;
        PyParamoaDist p3;
        PyParamoaDist p4;
        PyParamoaDist p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaEndStyle_Convert,&p1,
              &PyoaDist_Convert,&p2,
              &PyoaDist_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaDist_Convert,&p5)) {
            data.DataCall()->setBeginStyle(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaSegStyle, function: setBeginStyle, Choices are:\n"
        "    (oaEndStyle)\n"
        "    (oaEndStyle,oaDist)\n"
        "    (oaEndStyle,oaDist,oaDist,oaDist,oaDist)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSegStyle_setEndStyle_doc[] = 
"Class: oaSegStyle, Function: setEndStyle\n"
"  Paramegers: (oaEndStyle)\n"
"    Calls: void setEndStyle(oaEndStyle style)\n"
"    Signature: setEndStyle|void-void|simple-oaEndStyle,simple-oaDist,\n"
"    This function sets the end endStyle for this segStyle and should be used for the non-custom endStyles only. If an extension 'ext' is specified, the style must be variable. An exception is thrown if these criteria are not met. If the begin endStyle is a custom endStyle, the width gets adjusted to be double that of the beginRightHalfWidth. Otherwise, it remains unchanged.\n"
"    The value of 'ext' should be specified in regular database units if the style is to be used for orthogonal segments and in diagonal database units if the intended use is for diagonal segments.\n"
"    style\n"
"    The new end style that this object will represent for the end of an oaPathSeg . The style should be a regular end style.\n"
"    ext\n"
"    The extension value that this object will represent for the end of an oaPathSeg\n"
"    oacCustomEndStyleNotAllowedForEnd\n"
"    oacInvalidSegStyleEndExtValue\n"
"  Paramegers: (oaEndStyle,oaDist)\n"
"    Calls: void setEndStyle(oaEndStyle style,oaDist ext)\n"
"    Signature: setEndStyle|void-void|simple-oaEndStyle,simple-oaDist,\n"
"    This function sets the end endStyle for this segStyle and should be used for the non-custom endStyles only. If an extension 'ext' is specified, the style must be variable. An exception is thrown if these criteria are not met. If the begin endStyle is a custom endStyle, the width gets adjusted to be double that of the beginRightHalfWidth. Otherwise, it remains unchanged.\n"
"    The value of 'ext' should be specified in regular database units if the style is to be used for orthogonal segments and in diagonal database units if the intended use is for diagonal segments.\n"
"    style\n"
"    The new end style that this object will represent for the end of an oaPathSeg . The style should be a regular end style.\n"
"    ext\n"
"    The extension value that this object will represent for the end of an oaPathSeg\n"
"    oacCustomEndStyleNotAllowedForEnd\n"
"    oacInvalidSegStyleEndExtValue\n"
"  Paramegers: (oaEndStyle,oaDist,oaDist,oaDist,oaDist)\n"
"    Calls: void setEndStyle(oaEndStyle style,oaDist ext,oaDist leftDiagExt,oaDist rightDiagExt,oaDist rightHalfWidth)\n"
"    Signature: setEndStyle|void-void|simple-oaEndStyle,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaDist,\n"
"    This function sets the end endStyle of this segStyle and should be used for setting custom endStyles only. An exception is thrown if this requirement is not met. The width of this object gets adjusted based on whether the segStyle at the begin is custom or non-custom.\n"
"    The 'ext' and 'rightHalfWidth' values should be specified in regular database units if this segStyle is intended to be used for orthogonal segments and in diagonal database units if it is intended to be used for diagonal segments.\n"
"    The 'leftDiagExt' and 'rightDiagExt' values should be specified in diagonal database units if this segStyle is intended to be used for orthogonal segments and in regular database units if it is intended to be used for diagonal segments.\n"
"    style\n"
"    The oaEndStyle to be used for the end of an oaPathSeg\n"
"    ext\n"
"    The extension to be used at the end of an oaPathSeg\n"
"    leftDiagExt\n"
"    The left diagonal extension to be used at the end of an oaPathSeg\n"
"    rightDiagExt\n"
"    The right diagonal extension to be used at the end of an oaPathSeg\n"
"    rightHalfWidth\n"
"    The right half width to be used at the end of an oaPathSeg\n"
"    oacOnlyCustomEndStyleAllowedForEnd\n"
;

static PyObject*
oaSegStyle_setEndStyle(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegStyle data;
    int convert_status=PyoaSegStyle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegStyleObject* self=(PyoaSegStyleObject*)ob;

    // Case: (oaEndStyle)
    {
        PyParamoaEndStyle p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaEndStyle_Convert,&p1)) {
            data.DataCall()->setEndStyle(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaEndStyle,oaDist)
    {
        PyParamoaEndStyle p1;
        PyParamoaDist p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaEndStyle_Convert,&p1,
              &PyoaDist_Convert,&p2)) {
            data.DataCall()->setEndStyle(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaEndStyle,oaDist,oaDist,oaDist,oaDist)
    {
        PyParamoaEndStyle p1;
        PyParamoaDist p2;
        PyParamoaDist p3;
        PyParamoaDist p4;
        PyParamoaDist p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaEndStyle_Convert,&p1,
              &PyoaDist_Convert,&p2,
              &PyoaDist_Convert,&p3,
              &PyoaDist_Convert,&p4,
              &PyoaDist_Convert,&p5)) {
            data.DataCall()->setEndStyle(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaSegStyle, function: setEndStyle, Choices are:\n"
        "    (oaEndStyle)\n"
        "    (oaEndStyle,oaDist)\n"
        "    (oaEndStyle,oaDist,oaDist,oaDist,oaDist)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSegStyle_setWidth_doc[] = 
"Class: oaSegStyle, Function: setWidth\n"
"  Paramegers: (oaDist)\n"
"    Calls: void setWidth(oaDist widthIn)\n"
"    Signature: setWidth|void-void|simple-oaDist,\n"
"    This function sets the width of this segStyle. The width cannot be changed if both ends are custom chamfered. An exception will be thrown for this case. If only one end is custom-chamfered, the right half-width of that custom end is adjusted to be half the specified 'widthIn' value. For all other cases, the width applies directly and implies to all dependent extensions.\n"
"    widthIn\n"
"    The new width value to assign to this oaSegStyle object\n"
"    oacCannotChangeWidthForBothCustomEnds\n"
"    oacEvenWidthRequiredForSegStyle\n"
;

static PyObject*
oaSegStyle_setWidth(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegStyle data;
    int convert_status=PyoaSegStyle_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegStyleObject* self=(PyoaSegStyleObject*)ob;

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

static char oaSegStyle_assign_doc[] = 
"Class: oaSegStyle, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaSegStyle_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaSegStyle data;
  int convert_status=PyoaSegStyle_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaSegStyle p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaSegStyle_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaSegStyle_methodlist[] = {
    {"getBeginExt",(PyCFunction)oaSegStyle_getBeginExt,METH_VARARGS,oaSegStyle_getBeginExt_doc},
    {"getBeginStyle",(PyCFunction)oaSegStyle_getBeginStyle,METH_VARARGS,oaSegStyle_getBeginStyle_doc},
    {"getEndExt",(PyCFunction)oaSegStyle_getEndExt,METH_VARARGS,oaSegStyle_getEndExt_doc},
    {"getEndStyle",(PyCFunction)oaSegStyle_getEndStyle,METH_VARARGS,oaSegStyle_getEndStyle_doc},
    {"getWidth",(PyCFunction)oaSegStyle_getWidth,METH_VARARGS,oaSegStyle_getWidth_doc},
    {"setBeginStyle",(PyCFunction)oaSegStyle_setBeginStyle,METH_VARARGS,oaSegStyle_setBeginStyle_doc},
    {"setEndStyle",(PyCFunction)oaSegStyle_setEndStyle,METH_VARARGS,oaSegStyle_setEndStyle_doc},
    {"setWidth",(PyCFunction)oaSegStyle_setWidth,METH_VARARGS,oaSegStyle_setWidth_doc},
    {"assign",(PyCFunction)oaSegStyle_tp_assign,METH_VARARGS,oaSegStyle_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaSegStyle_doc[] = 
"Class: oaSegStyle\n"
"  The oaSegStyle class implements a utility class whose objects are used to specify and retrieve the width and the two end styles for an oaPathSeg object. oaSegStyle objects by themselves are not persistent but become persistent when associated with one or more oaPathSeg objects.\n"
"  Its supporting classes includes the oaEndStyle class, which implements an enumerated type representing the different styles the end of a path segment may have.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaSegStyle()\n"
"    Signature: oaSegStyle||\n"
"    This constructor for the oaSegStyle class creates an empty oaSegStyle object. An object created with this constructor will have zero width and truncated begin and end endStyles.\n"
"  Paramegers: (oaDist,oaEndStyle,oaEndStyle)\n"
"    Calls: oaSegStyle(oaDist width,oaEndStyle beginStyleIn,oaEndStyle endStyleIn)\n"
"    Signature: oaSegStyle||simple-oaDist,simple-oaEndStyle,simple-oaEndStyle,simple-oaDist,simple-oaDist,\n"
"    This constructor for the oaSegStyle class should be used when neither of the begin or end styles are custom chamfered styles. The begin and end extensions are optional and should be specified only if the corresponding end style is variable. The specified width should be an even number. An appropriate exception will be thrown if any of these requirements are not met.\n"
"    The 'width, 'beginExtIn' and 'endExtIn' values should be specified in regular database units if this segStyle is intended to be used for orthogonal segments and in diagonal database units if it is intended to be used for diagonal segments.\n"
"    Additionally, it is required that the 'width' value be an even number of units.\n"
"    width\n"
"    The width for the intended oaPathSeg that will use this object\n"
"    beginStyleIn\n"
"    The oaEndStyle to use at the beginning of an oaPathSeg\n"
"    endStyleIn\n"
"    The oaEndStyle to use the end of an oaPathSeg\n"
"    beginExtIn\n"
"    The extension to use at the beginning of an oaPathSeg if 'beginStyleIn' is the variable endStyle\n"
"    endExtIn\n"
"    The extension to use at the end of an oaPathSeg if 'endStyleIn' is the variable endStyle\n"
"    oacEvenWidthRequiredForSegStyle\n"
"    oacCustomEndStyleNotAllowed\n"
"    oacInvalidSegStyleBeginExtValue\n"
"    oacInvalidSegStyleEndExtValue\n"
"  Paramegers: (oaDist,oaEndStyle,oaEndStyle,oaDist)\n"
"    Calls: oaSegStyle(oaDist width,oaEndStyle beginStyleIn,oaEndStyle endStyleIn,oaDist beginExtIn)\n"
"    Signature: oaSegStyle||simple-oaDist,simple-oaEndStyle,simple-oaEndStyle,simple-oaDist,simple-oaDist,\n"
"    This constructor for the oaSegStyle class should be used when neither of the begin or end styles are custom chamfered styles. The begin and end extensions are optional and should be specified only if the corresponding end style is variable. The specified width should be an even number. An appropriate exception will be thrown if any of these requirements are not met.\n"
"    The 'width, 'beginExtIn' and 'endExtIn' values should be specified in regular database units if this segStyle is intended to be used for orthogonal segments and in diagonal database units if it is intended to be used for diagonal segments.\n"
"    Additionally, it is required that the 'width' value be an even number of units.\n"
"    width\n"
"    The width for the intended oaPathSeg that will use this object\n"
"    beginStyleIn\n"
"    The oaEndStyle to use at the beginning of an oaPathSeg\n"
"    endStyleIn\n"
"    The oaEndStyle to use the end of an oaPathSeg\n"
"    beginExtIn\n"
"    The extension to use at the beginning of an oaPathSeg if 'beginStyleIn' is the variable endStyle\n"
"    endExtIn\n"
"    The extension to use at the end of an oaPathSeg if 'endStyleIn' is the variable endStyle\n"
"    oacEvenWidthRequiredForSegStyle\n"
"    oacCustomEndStyleNotAllowed\n"
"    oacInvalidSegStyleBeginExtValue\n"
"    oacInvalidSegStyleEndExtValue\n"
"  Paramegers: (oaDist,oaEndStyle,oaEndStyle,oaDist,oaDist)\n"
"    Calls: oaSegStyle(oaDist width,oaEndStyle beginStyleIn,oaEndStyle endStyleIn,oaDist beginExtIn,oaDist endExtIn)\n"
"    Signature: oaSegStyle||simple-oaDist,simple-oaEndStyle,simple-oaEndStyle,simple-oaDist,simple-oaDist,\n"
"    This constructor for the oaSegStyle class should be used when neither of the begin or end styles are custom chamfered styles. The begin and end extensions are optional and should be specified only if the corresponding end style is variable. The specified width should be an even number. An appropriate exception will be thrown if any of these requirements are not met.\n"
"    The 'width, 'beginExtIn' and 'endExtIn' values should be specified in regular database units if this segStyle is intended to be used for orthogonal segments and in diagonal database units if it is intended to be used for diagonal segments.\n"
"    Additionally, it is required that the 'width' value be an even number of units.\n"
"    width\n"
"    The width for the intended oaPathSeg that will use this object\n"
"    beginStyleIn\n"
"    The oaEndStyle to use at the beginning of an oaPathSeg\n"
"    endStyleIn\n"
"    The oaEndStyle to use the end of an oaPathSeg\n"
"    beginExtIn\n"
"    The extension to use at the beginning of an oaPathSeg if 'beginStyleIn' is the variable endStyle\n"
"    endExtIn\n"
"    The extension to use at the end of an oaPathSeg if 'endStyleIn' is the variable endStyle\n"
"    oacEvenWidthRequiredForSegStyle\n"
"    oacCustomEndStyleNotAllowed\n"
"    oacInvalidSegStyleBeginExtValue\n"
"    oacInvalidSegStyleEndExtValue\n"
"  Paramegers: (oaEndStyle,oaEndStyle,oaDist,oaDist,oaDist,oaDist)\n"
"    Calls: oaSegStyle(oaEndStyle beginStyleIn,oaEndStyle endStyleIn,oaDist endExtIn,oaDist endLeftDiagExtIn,oaDist endRightDiagExtIn,oaDist endRightHalfWidthIn)\n"
"    Signature: oaSegStyle||simple-oaEndStyle,simple-oaEndStyle,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaDist,\n"
"    This constructor for the oaSegStyle class should be used when begin endStyle is not custom chamfered while the end endStyle is custom chamfered. The begin extension beginExtIn is optional and should be specified only if the begin endStyle, beginStyleIn , is \"variable\". The width for this segStyle defaults to being twice the endRightHalfWidthIn value specified. An appropriate exception will be thrown if any of the above requirements are not met.\n"
"    The beginExtIn , endExtIn and ' endRightHalfWidthIn values should be specified in regular database units if this segStyle is intended to be used for orthogonal segments and in diagonal database units if it is intended to be used for diagonal segments.\n"
"    The endLeftDiagExtIn and endRightDiagExtIn values should be specified in in diagonal database units if this segStyle is intended to be used for orthogonal segments and in regular database units if it is intended to be used for diagonal segments.\n"
"    beginStyleIn\n"
"    The oaEndStyle to use at the beginning of an oaPathSeg\n"
"    endStyleIn\n"
"    The oaEndStyle to use at the end of an oaPathSeg\n"
"    endExtIn\n"
"    The extension to use at the end of an oaPathSeg for custom chamfering\n"
"    endLeftDiagExtIn\n"
"    The left diagonal extension to use at the end of an oaPathSeg for custom chamfering\n"
"    endRightDiagExtIn\n"
"    The right diagonal extension to use at the end of an oaPathSeg for custom chamfering\n"
"    endRightHalfWidthIn\n"
"    The right half width to use at the end of an oaPathSeg for custom chamfering\n"
"    beginExtIn\n"
"    The extension to use at the beginning of an oaPathSeg if 'beginStyleIn' is the variable endStyle\n"
"    oacCustomEndStyleNotAllowedForBegin\n"
"    oacOnlyCustomEndStyleAllowedForEnd\n"
"    oacInvalidSegStyleBeginExtValue\n"
"  Paramegers: (oaEndStyle,oaEndStyle,oaDist,oaDist,oaDist,oaDist,oaDist)\n"
"    Calls: oaSegStyle(oaEndStyle beginStyleIn,oaEndStyle endStyleIn,oaDist endExtIn,oaDist endLeftDiagExtIn,oaDist endRightDiagExtIn,oaDist endRightHalfWidthIn,oaDist beginExtIn)\n"
"    Signature: oaSegStyle||simple-oaEndStyle,simple-oaEndStyle,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaDist,\n"
"    This constructor for the oaSegStyle class should be used when begin endStyle is not custom chamfered while the end endStyle is custom chamfered. The begin extension beginExtIn is optional and should be specified only if the begin endStyle, beginStyleIn , is \"variable\". The width for this segStyle defaults to being twice the endRightHalfWidthIn value specified. An appropriate exception will be thrown if any of the above requirements are not met.\n"
"    The beginExtIn , endExtIn and ' endRightHalfWidthIn values should be specified in regular database units if this segStyle is intended to be used for orthogonal segments and in diagonal database units if it is intended to be used for diagonal segments.\n"
"    The endLeftDiagExtIn and endRightDiagExtIn values should be specified in in diagonal database units if this segStyle is intended to be used for orthogonal segments and in regular database units if it is intended to be used for diagonal segments.\n"
"    beginStyleIn\n"
"    The oaEndStyle to use at the beginning of an oaPathSeg\n"
"    endStyleIn\n"
"    The oaEndStyle to use at the end of an oaPathSeg\n"
"    endExtIn\n"
"    The extension to use at the end of an oaPathSeg for custom chamfering\n"
"    endLeftDiagExtIn\n"
"    The left diagonal extension to use at the end of an oaPathSeg for custom chamfering\n"
"    endRightDiagExtIn\n"
"    The right diagonal extension to use at the end of an oaPathSeg for custom chamfering\n"
"    endRightHalfWidthIn\n"
"    The right half width to use at the end of an oaPathSeg for custom chamfering\n"
"    beginExtIn\n"
"    The extension to use at the beginning of an oaPathSeg if 'beginStyleIn' is the variable endStyle\n"
"    oacCustomEndStyleNotAllowedForBegin\n"
"    oacOnlyCustomEndStyleAllowedForEnd\n"
"    oacInvalidSegStyleBeginExtValue\n"
"  Paramegers: (oaEndStyle,oaDist,oaDist,oaDist,oaDist,oaEndStyle)\n"
"    Calls: oaSegStyle(oaEndStyle beginStyleIn,oaDist beginExtIn,oaDist beginLeftDiagExtIn,oaDist beginRightDiagExtIn,oaDist beginRightHalfWidthIn,oaEndStyle endStyleIn)\n"
"    Signature: oaSegStyle||simple-oaEndStyle,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaEndStyle,simple-oaDist,\n"
"    This constructor for the oaSegStyle class should be used when end endStyle is not custom chamfered while the begin endStyle is custom chamfered. The end extension endExtIn is optional and should be specified only if the end endStyleIn is \"variable\". The width for this segStyle defaults to being the double of the beginRightHalfWidthIn value specified. An exception will be thrown if the above requirements are not met.\n"
"    The beginExtIn , beginRightHalfWidthIn and endExtIn values should be specified in regular database units if this segStyle is intended to be used for orthogonal segments and in diagonal database units if it is intended to be used for diagonal segments.\n"
"    The beginLeftDiagExtIn and beginRightDiagExtIn values should be specified in in diagonal database units if this segStyle is intended to be used for orthogonal segments and in regular database units if it is intended to be used for diagonal segments.\n"
"    beginStyleIn\n"
"    The oaEndStyle to use at the beginning of an oaPathSeg\n"
"    beginExtIn\n"
"    The extension to use at the beginning of an oaPathSeg for custom chamfering\n"
"    beginLeftDiagExtIn\n"
"    The left diagonal extension to use at the beginning of an oaPathSeg for custom chamfering\n"
"    beginRightDiagExtIn\n"
"    The right diagonal extension to use at the beginning of an oaPathSeg for custom chamfering\n"
"    beginRightHalfWidthIn\n"
"    The right half to use at the beginning of an oaPathSeg for custom chamfering\n"
"    endStyleIn\n"
"    The oaEndStyle to use at the end of an oaPathSeg\n"
"    endExtIn\n"
"    The extension to use at the end of an oaPathSeg if 'endStyleIn' is the variable endStyle\n"
"    oacCustomEndStyleNotAllowedForEnd\n"
"    oacOnlyCustomEndStyleAllowedForBegin\n"
"    oacInvalidSegStyleEndExtValue\n"
"  Paramegers: (oaEndStyle,oaDist,oaDist,oaDist,oaDist,oaEndStyle,oaDist)\n"
"    Calls: oaSegStyle(oaEndStyle beginStyleIn,oaDist beginExtIn,oaDist beginLeftDiagExtIn,oaDist beginRightDiagExtIn,oaDist beginRightHalfWidthIn,oaEndStyle endStyleIn,oaDist endExtIn)\n"
"    Signature: oaSegStyle||simple-oaEndStyle,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaEndStyle,simple-oaDist,\n"
"    This constructor for the oaSegStyle class should be used when end endStyle is not custom chamfered while the begin endStyle is custom chamfered. The end extension endExtIn is optional and should be specified only if the end endStyleIn is \"variable\". The width for this segStyle defaults to being the double of the beginRightHalfWidthIn value specified. An exception will be thrown if the above requirements are not met.\n"
"    The beginExtIn , beginRightHalfWidthIn and endExtIn values should be specified in regular database units if this segStyle is intended to be used for orthogonal segments and in diagonal database units if it is intended to be used for diagonal segments.\n"
"    The beginLeftDiagExtIn and beginRightDiagExtIn values should be specified in in diagonal database units if this segStyle is intended to be used for orthogonal segments and in regular database units if it is intended to be used for diagonal segments.\n"
"    beginStyleIn\n"
"    The oaEndStyle to use at the beginning of an oaPathSeg\n"
"    beginExtIn\n"
"    The extension to use at the beginning of an oaPathSeg for custom chamfering\n"
"    beginLeftDiagExtIn\n"
"    The left diagonal extension to use at the beginning of an oaPathSeg for custom chamfering\n"
"    beginRightDiagExtIn\n"
"    The right diagonal extension to use at the beginning of an oaPathSeg for custom chamfering\n"
"    beginRightHalfWidthIn\n"
"    The right half to use at the beginning of an oaPathSeg for custom chamfering\n"
"    endStyleIn\n"
"    The oaEndStyle to use at the end of an oaPathSeg\n"
"    endExtIn\n"
"    The extension to use at the end of an oaPathSeg if 'endStyleIn' is the variable endStyle\n"
"    oacCustomEndStyleNotAllowedForEnd\n"
"    oacOnlyCustomEndStyleAllowedForBegin\n"
"    oacInvalidSegStyleEndExtValue\n"
"  Paramegers: (oaEndStyle,oaDist,oaDist,oaDist,oaDist,oaEndStyle,oaDist,oaDist,oaDist,oaDist)\n"
"    Calls: oaSegStyle(oaEndStyle beginStyleIn,oaDist beginExtIn,oaDist beginLeftDiagExtIn,oaDist beginRightDiagExtIn,oaDist beginRightHalfWidthIn,oaEndStyle endStyleIn,oaDist endExtIn,oaDist endLeftDiagExtIn,oaDist endRightDiagExtIn,oaDist endRightHalfWidthIn)\n"
"    Signature: oaSegStyle||simple-oaEndStyle,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaEndStyle,simple-oaDist,simple-oaDist,simple-oaDist,simple-oaDist,\n"
"    This constructor for the oaSegStyle class should be used when both begin and end endStyles are custom chamfered. The width for this segStyle defaults to the sum of beginRightHalfWidthIn and endRightHalfWidthIn . An exception will be thrown if the above requirements are not met.\n"
"    The beginExtIn , beginRightHalfWidthIn , endExtIn and endRightHalfWidth values should be specified in regular database units if this segStyle is intended to be used for orthogonal segments and in diagonal database units if it is intended to be used for diagonal segments.\n"
"    The beginLeftDiagExtIn , beginRightDiagExtIn , endLeftDiagExtIn and em endRightDiagExtIn values should be specified in diagonal database units if this segStyle is intended to be used for orthogonal segments and in regular database units if it is intended to be used for diagonal segments.\n"
"    beginStyleIn\n"
"    The oaEndStyle to use at the beginning of an oaPathSeg\n"
"    beginExtIn\n"
"    The extension to use at the beginning of an oaPathSeg\n"
"    beginLeftDiagExtIn\n"
"    The left diagonal extension to use at the beginning of an oaPathSeg\n"
"    beginRightDiagExtIn\n"
"    The right diagonal extension to use at the beginning of an oaPathSeg\n"
"    beginRightHalfWidthIn\n"
"    The right extension to use at the beginning of an oaPathSeg\n"
"    endStyleIn\n"
"    The oaEndStyle to use at the end of an oaPathSeg\n"
"    endExtIn\n"
"    The extension to use at the end of an oaPathSeg\n"
"    endLeftDiagExtIn\n"
"    The left diagonal extension to use at the end of an oaPathSeg\n"
"    endRightDiagExtIn\n"
"    The right diagonal extension to use at the end of an oaPathSeg\n"
"    endRightHalfWidthIn\n"
"    The right extension to use at the end of an oaPathSeg\n"
"    oacOnlyCustomEndStylesAllowed\n"
"  Paramegers: (oaSegStyle)\n"
"    Calls: oaSegStyle(const oaSegStyle& segStyleIn)\n"
"    Signature: oaSegStyle||cref-oaSegStyle,\n"
"    This copy constructor for the oaSegStyle class creates a copy of the specified oaSegStyle object 'segStyleIn'.\n"
"    segStyleIn\n"
"    The oaSegStyle object to copy\n"
"  Paramegers: (oaSegStyle)\n"
"    Calls: (const oaSegStyle&)\n"
"    Signature: oaSegStyle||cref-oaSegStyle,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaSegStyle_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaSegStyle",
    sizeof(PyoaSegStyleObject),
    0,
    (destructor)oaSegStyle_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaSegStyle_tp_compare,	/* tp_compare */
    (reprfunc)oaSegStyle_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaSegStyle_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaSegStyle_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaSegStyle_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaSegStyle_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaSegStyle_Type)<0) {
      printf("** PyType_Ready failed for: oaSegStyle\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaSegStyle",
           (PyObject*)(&PyoaSegStyle_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaSegStyle\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaSegment
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaSegment_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaSegment_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaSegmentObject* self = (PyoaSegmentObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            self->value =  new oaSegment();
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaPoint,oaPoint)
    {
        PyParamoaPoint p1;
        PyParamoaPoint p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaPoint_Convert,&p1,
              &PyoaPoint_Convert,&p2)) {
            self->value =  new oaSegment(p1.Data(),p2.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaVector,oaPoint)
    {
        PyParamoaVector p1;
        PyParamoaPoint p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaVector_Convert,&p1,
              &PyoaPoint_Convert,&p2)) {
            self->value =  new oaSegment(p1.Data(),p2.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaSegment)
    {
        PyParamoaSegment p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaSegment_Convert,&p1)) {
            self->value= new oaSegment(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaSegment, Choices are:\n"
        "    ()\n"
        "    (oaPoint,oaPoint)\n"
        "    (oaVector,oaPoint)\n"
        "    (oaSegment)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaSegment_tp_dealloc(PyoaSegmentObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaSegment_tp_repr(PyObject *ob)
{
    PyParamoaSegment value;
    int convert_status=PyoaSegment_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[31];
    sprintf(buffer,"<oaSegment::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaSegment_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaSegment v1;
    PyParamoaSegment v2;
    int convert_status1=PyoaSegment_Convert(ob1,&v1);
    int convert_status2=PyoaSegment_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    if (v1.Data()==v2.Data()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaSegment_Convert(PyObject* ob,PyParamoaSegment* result)
{
    if (ob == NULL) return 1;
    if (PyoaSegment_Check(ob)) {
        result->SetData(  ((PyoaSegmentObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaSegment Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaSegment_FromoaSegment(oaSegment* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaSegment_Type.tp_alloc(&PyoaSegment_Type,0);
        if (bself == NULL) return bself;
        PyoaSegmentObject* self = (PyoaSegmentObject*)bself;
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
static char oaSegment_collinearContains_doc[] = 
"Class: oaSegment, Function: collinearContains\n"
"  Paramegers: (oaPoint)\n"
"    Calls: oaBoolean collinearContains(const oaPoint& point) const\n"
"    Signature: collinearContains|simple-oaBoolean|cref-oaPoint,simple-oaBoolean,\n"
"    This function returns true if the specified collinear point lies on this segment. The flag includeEnds specifies whether the ends of the segments should be included or not.\n"
"    point\n"
"    point to check\n"
"    includeEnds\n"
"    specifies whether the ends of the segments should be included or not\n"
"  Paramegers: (oaPoint,oaBoolean)\n"
"    Calls: oaBoolean collinearContains(const oaPoint& point,oaBoolean includeEnds) const\n"
"    Signature: collinearContains|simple-oaBoolean|cref-oaPoint,simple-oaBoolean,\n"
"    This function returns true if the specified collinear point lies on this segment. The flag includeEnds specifies whether the ends of the segments should be included or not.\n"
"    point\n"
"    point to check\n"
"    includeEnds\n"
"    specifies whether the ends of the segments should be included or not\n"
;

static PyObject*
oaSegment_collinearContains(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegment data;
    int convert_status=PyoaSegment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegmentObject* self=(PyoaSegmentObject*)ob;

    // Case: (oaPoint)
    {
        PyParamoaPoint p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaPoint_Convert,&p1)) {
            oaBoolean result= (data.DataCall()->collinearContains(p1.Data()));
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
            oaBoolean result= (data.DataCall()->collinearContains(p1.Data(),p2.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaSegment, function: collinearContains, Choices are:\n"
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
static char oaSegment_contains_doc[] = 
"Class: oaSegment, Function: contains\n"
"  Paramegers: (oaPoint)\n"
"    Calls: oaBoolean contains(const oaPoint& point) const\n"
"    Signature: contains|simple-oaBoolean|cref-oaPoint,simple-oaBoolean,\n"
"    This function returns true if the specified point lies on this segment.\n"
"    point\n"
"    The point that must lie on the segment\n"
"    includeEnds\n"
"    specifies whether the ends of the segments should be included or not\n"
"  Paramegers: (oaPoint,oaBoolean)\n"
"    Calls: oaBoolean contains(const oaPoint& point,oaBoolean includeEnds) const\n"
"    Signature: contains|simple-oaBoolean|cref-oaPoint,simple-oaBoolean,\n"
"    This function returns true if the specified point lies on this segment.\n"
"    point\n"
"    The point that must lie on the segment\n"
"    includeEnds\n"
"    specifies whether the ends of the segments should be included or not\n"
;

static PyObject*
oaSegment_contains(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegment data;
    int convert_status=PyoaSegment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegmentObject* self=(PyoaSegmentObject*)ob;

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
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaSegment, function: contains, Choices are:\n"
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
static char oaSegment_distanceFrom2_doc[] = 
"Class: oaSegment, Function: distanceFrom2\n"
"  Paramegers: (oaPoint)\n"
"    Calls: oaDouble distanceFrom2(const oaPoint& point) const\n"
"    Signature: distanceFrom2|simple-oaDouble|cref-oaPoint,\n"
"    This function returns the square of the distance from the specified point to the closest point on this segment. This function is faster than the previous function, but does not determine the location of the point.\n"
"    point\n"
"    The measurement point\n"
"  Paramegers: (oaPoint,oaPoint)\n"
"    Calls: oaDouble distanceFrom2(const oaPoint& point,oaPoint& loc) const\n"
"    Signature: distanceFrom2|simple-oaDouble|cref-oaPoint,ref-oaPoint,\n"
"    This function finds the location on the segment that is closest to the specified point and returns the square of the distance from this location to the point.\n"
"    point\n"
"    The measurement point\n"
"    loc\n"
"    The location on the segment\n"
;

static PyObject*
oaSegment_distanceFrom2(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegment data;
    int convert_status=PyoaSegment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegmentObject* self=(PyoaSegmentObject*)ob;

    // Case: (oaPoint)
    {
        PyParamoaPoint p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaPoint_Convert,&p1)) {
            oaDouble result= (data.DataCall()->distanceFrom2(p1.Data()));
            return PyoaDouble_FromoaDouble(result);
        }
    }
    PyErr_Clear();
    // Case: (oaPoint,oaPoint)
    {
        PyParamoaPoint p1;
        PyParamoaPoint p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaPoint_Convert,&p1,
              &PyoaPoint_Convert,&p2)) {
            oaDouble result= (data.DataCall()->distanceFrom2(p1.Data(),p2.Data()));
            return PyoaDouble_FromoaDouble(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaSegment, function: distanceFrom2, Choices are:\n"
        "    (oaPoint)\n"
        "    (oaPoint,oaPoint)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSegment_getDeltaX_doc[] = 
"Class: oaSegment, Function: getDeltaX\n"
"  Paramegers: ()\n"
"    Calls: oaOffset getDeltaX() const\n"
"    Signature: getDeltaX|simple-oaOffset|\n"
"    BrowseData: 1\n"
"    This function returns the deltaX between the head and tail of this segment.\n"
;

static PyObject*
oaSegment_getDeltaX(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegment data;
    int convert_status=PyoaSegment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegmentObject* self=(PyoaSegmentObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOffset result= (data.DataCall()->getDeltaX());
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
static char oaSegment_getDeltaY_doc[] = 
"Class: oaSegment, Function: getDeltaY\n"
"  Paramegers: ()\n"
"    Calls: oaOffset getDeltaY() const\n"
"    Signature: getDeltaY|simple-oaOffset|\n"
"    BrowseData: 1\n"
"    This function returns the deltaY between the head and tail of this segment.\n"
;

static PyObject*
oaSegment_getDeltaY(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegment data;
    int convert_status=PyoaSegment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegmentObject* self=(PyoaSegmentObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaOffset result= (data.DataCall()->getDeltaY());
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
static char oaSegment_head_doc[] = 
"Class: oaSegment, Function: head\n"
"  Paramegers: ()\n"
"    Calls: oaPoint& head()\n"
"    Signature: head|ref-oaPoint|\n"
"    BrowseData: 1\n"
"    This function returns the head point of this segment.\n"
;

static PyObject*
oaSegment_head(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegment data;
    int convert_status=PyoaSegment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegmentObject* self=(PyoaSegmentObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPoint* result=&(data.DataCall()->head());
        return PyoaPoint_FromoaPoint(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSegment_intersects_doc[] = 
"Class: oaSegment, Function: intersects\n"
"  Paramegers: (oaSegment)\n"
"    Calls: oaBoolean intersects(const oaSegment& seg) const\n"
"    Signature: intersects|simple-oaBoolean|cref-oaSegment,simple-oaBoolean,\n"
"    This function returns true if this segment intersects segment seg . This function intersects segment seg quickly, but this function does not inform you where the intersection occurs. This function is faster than the previous function.\n"
"    seg\n"
"    The name of the segment to intersect\n"
"    includeEnds\n"
"    Includes the ends of the segments\n"
"  Paramegers: (oaSegment,oaBoolean)\n"
"    Calls: oaBoolean intersects(const oaSegment& seg,oaBoolean includeEnds) const\n"
"    Signature: intersects|simple-oaBoolean|cref-oaSegment,simple-oaBoolean,\n"
"    This function returns true if this segment intersects segment seg . This function intersects segment seg quickly, but this function does not inform you where the intersection occurs. This function is faster than the previous function.\n"
"    seg\n"
"    The name of the segment to intersect\n"
"    includeEnds\n"
"    Includes the ends of the segments\n"
"  Paramegers: (oaSegment,oaBoolean,oaBoolean)\n"
"    Calls: oaBoolean intersects(const oaSegment& seg,oaBoolean includeEnds,oaBoolean includeOverlap) const\n"
"    Signature: intersects|simple-oaBoolean|cref-oaSegment,simple-oaBoolean,simple-oaBoolean,\n"
"    This function returns true if this segment intersects segment seg . The flag includeEnds specifies whether the ends of the segments should be included or not. It does this in a fast way, although it doesn't tell you where the intersection occurs.\n"
"    The flag, allowOverlap , determines whether or not overlapping segments are viewed as intersecting (true = yes; false = no).\n"
"    seg\n"
"    includeEnds\n"
"    includeOverlap\n"
"    Todo\n"
"    Check description of member function (description of includeOverlap correct?). Add description of each parameter.\n"
"  Paramegers: (oaSegment,oaPoint)\n"
"    Calls: oaBoolean intersects(const oaSegment& seg,oaPoint& iPt) const\n"
"    Signature: intersects|simple-oaBoolean|cref-oaSegment,ref-oaPoint,simple-oaBoolean,\n"
"    This function finds the point of intersection between this segment and segment seg .\n"
"    seg\n"
"    The name of the segment to intersect\n"
"    iPt\n"
"    The point of intersection\n"
"    mustIntersect\n"
"    Specifies that the point of intersection must lie on both segments\n"
"  Paramegers: (oaSegment,oaPoint,oaBoolean)\n"
"    Calls: oaBoolean intersects(const oaSegment& seg,oaPoint& iPt,oaBoolean mustIntersect) const\n"
"    Signature: intersects|simple-oaBoolean|cref-oaSegment,ref-oaPoint,simple-oaBoolean,\n"
"    This function finds the point of intersection between this segment and segment seg .\n"
"    seg\n"
"    The name of the segment to intersect\n"
"    iPt\n"
"    The point of intersection\n"
"    mustIntersect\n"
"    Specifies that the point of intersection must lie on both segments\n"
;

static PyObject*
oaSegment_intersects(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegment data;
    int convert_status=PyoaSegment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegmentObject* self=(PyoaSegmentObject*)ob;

    // Case: (oaSegment)
    {
        PyParamoaSegment p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaSegment_Convert,&p1)) {
            oaBoolean result= (data.DataCall()->intersects(p1.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaSegment,oaBoolean)
    {
        PyParamoaSegment p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaSegment_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            oaBoolean result= (data.DataCall()->intersects(p1.Data(),p2.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaSegment,oaBoolean,oaBoolean)
    {
        PyParamoaSegment p1;
        PyParamoaBoolean p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaSegment_Convert,&p1,
              &PyoaBoolean_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            oaBoolean result= (data.DataCall()->intersects(p1.Data(),p2.Data(),p3.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaSegment,oaPoint)
    {
        PyParamoaSegment p1;
        PyParamoaPoint p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaSegment_Convert,&p1,
              &PyoaPoint_Convert,&p2)) {
            oaBoolean result= (data.DataCall()->intersects(p1.Data(),p2.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    // Case: (oaSegment,oaPoint,oaBoolean)
    {
        PyParamoaSegment p1;
        PyParamoaPoint p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaSegment_Convert,&p1,
              &PyoaPoint_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            oaBoolean result= (data.DataCall()->intersects(p1.Data(),p2.Data(),p3.Data()));
            return PyoaBoolean_FromoaBoolean(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaSegment, function: intersects, Choices are:\n"
        "    (oaSegment)\n"
        "    (oaSegment,oaBoolean)\n"
        "    (oaSegment,oaBoolean,oaBoolean)\n"
        "    (oaSegment,oaPoint)\n"
        "    (oaSegment,oaPoint,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSegment_isHorizontal_doc[] = 
"Class: oaSegment, Function: isHorizontal\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isHorizontal() const\n"
"    Signature: isHorizontal|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if the slope of the segment is zero.\n"
;

static PyObject*
oaSegment_isHorizontal(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegment data;
    int convert_status=PyoaSegment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegmentObject* self=(PyoaSegmentObject*)ob;

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
static char oaSegment_isOrthogonal_doc[] = 
"Class: oaSegment, Function: isOrthogonal\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isOrthogonal() const\n"
"    Signature: isOrthogonal|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if the slope of the segment is zero or +/- infinity.\n"
;

static PyObject*
oaSegment_isOrthogonal(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegment data;
    int convert_status=PyoaSegment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegmentObject* self=(PyoaSegmentObject*)ob;

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
static char oaSegment_isVertical_doc[] = 
"Class: oaSegment, Function: isVertical\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isVertical() const\n"
"    Signature: isVertical|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if the slope of the segment is +/- infinity.\n"
;

static PyObject*
oaSegment_isVertical(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegment data;
    int convert_status=PyoaSegment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegmentObject* self=(PyoaSegmentObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isVertical());
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
static char oaSegment_set_doc[] = 
"Class: oaSegment, Function: set\n"
"  Paramegers: (oaPoint,oaPoint)\n"
"    Calls: void set(const oaPoint& head,const oaPoint& tail)\n"
"    Signature: set|void-void|cref-oaPoint,cref-oaPoint,\n"
"    This function sets the segment to have the specified end points.\n"
"    head\n"
"    The head of the segment\n"
"    tail\n"
"    The tail of the segment\n"
"  Paramegers: (oaVector,oaPoint)\n"
"    Calls: void set(const oaVector& vec,const oaPoint& ref)\n"
"    Signature: set|void-void|cref-oaVector,cref-oaPoint,\n"
"    This function sets the segment to start at the given reference point and point along the specified vector.\n"
"    vec\n"
"    The vector from the head\n"
"    ref\n"
"    The head of the segment\n"
;

static PyObject*
oaSegment_set(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegment data;
    int convert_status=PyoaSegment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegmentObject* self=(PyoaSegmentObject*)ob;

    // Case: (oaPoint,oaPoint)
    {
        PyParamoaPoint p1;
        PyParamoaPoint p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaPoint_Convert,&p1,
              &PyoaPoint_Convert,&p2)) {
            data.DataCall()->set(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaVector,oaPoint)
    {
        PyParamoaVector p1;
        PyParamoaPoint p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaVector_Convert,&p1,
              &PyoaPoint_Convert,&p2)) {
            data.DataCall()->set(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaSegment, function: set, Choices are:\n"
        "    (oaPoint,oaPoint)\n"
        "    (oaVector,oaPoint)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSegment_tail_doc[] = 
"Class: oaSegment, Function: tail\n"
"  Paramegers: ()\n"
"    Calls: oaPoint& tail()\n"
"    Signature: tail|ref-oaPoint|\n"
"    BrowseData: 1\n"
"    This function returns the tail point of this segment.\n"
;

static PyObject*
oaSegment_tail(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegment data;
    int convert_status=PyoaSegment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegmentObject* self=(PyoaSegmentObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPoint* result=&(data.DataCall()->tail());
        return PyoaPoint_FromoaPoint(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSegment_x1_doc[] = 
"Class: oaSegment, Function: x1\n"
"  Paramegers: ()\n"
"    Calls: oaCoord& x1()\n"
"    Signature: x1|ref-oaCoord|\n"
"    BrowseData: 1\n"
"    This function returns a reference to the X value of the head point of this segment.\n"
;

static PyObject*
oaSegment_x1(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegment data;
    int convert_status=PyoaSegment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegmentObject* self=(PyoaSegmentObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaCoord* result=&(data.DataCall()->x1());
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
static char oaSegment_x2_doc[] = 
"Class: oaSegment, Function: x2\n"
"  Paramegers: ()\n"
"    Calls: oaCoord& x2()\n"
"    Signature: x2|ref-oaCoord|\n"
"    BrowseData: 1\n"
"    This function returns a reference to the X value of the tail point of this segment.\n"
;

static PyObject*
oaSegment_x2(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegment data;
    int convert_status=PyoaSegment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegmentObject* self=(PyoaSegmentObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaCoord* result=&(data.DataCall()->x2());
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
static char oaSegment_y1_doc[] = 
"Class: oaSegment, Function: y1\n"
"  Paramegers: ()\n"
"    Calls: oaCoord& y1()\n"
"    Signature: y1|ref-oaCoord|\n"
"    BrowseData: 1\n"
"    This function returns a reference to the Y value of the head point of this segment.\n"
;

static PyObject*
oaSegment_y1(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegment data;
    int convert_status=PyoaSegment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegmentObject* self=(PyoaSegmentObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaCoord* result=&(data.DataCall()->y1());
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
static char oaSegment_y2_doc[] = 
"Class: oaSegment, Function: y2\n"
"  Paramegers: ()\n"
"    Calls: oaCoord& y2()\n"
"    Signature: y2|ref-oaCoord|\n"
"    BrowseData: 1\n"
"    This function returns a reference to the Y value of the tail point of this segment.\n"
;

static PyObject*
oaSegment_y2(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSegment data;
    int convert_status=PyoaSegment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSegmentObject* self=(PyoaSegmentObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaCoord* result=&(data.DataCall()->y2());
        return PyoaCoord_FromoaCoord(result,1,ob);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaSegment_assign_doc[] = 
"Class: oaSegment, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaSegment_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaSegment data;
  int convert_status=PyoaSegment_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaSegment p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaSegment_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaSegment_methodlist[] = {
    {"collinearContains",(PyCFunction)oaSegment_collinearContains,METH_VARARGS,oaSegment_collinearContains_doc},
    {"contains",(PyCFunction)oaSegment_contains,METH_VARARGS,oaSegment_contains_doc},
    {"distanceFrom2",(PyCFunction)oaSegment_distanceFrom2,METH_VARARGS,oaSegment_distanceFrom2_doc},
    {"getDeltaX",(PyCFunction)oaSegment_getDeltaX,METH_VARARGS,oaSegment_getDeltaX_doc},
    {"getDeltaY",(PyCFunction)oaSegment_getDeltaY,METH_VARARGS,oaSegment_getDeltaY_doc},
    {"head",(PyCFunction)oaSegment_head,METH_VARARGS,oaSegment_head_doc},
    {"intersects",(PyCFunction)oaSegment_intersects,METH_VARARGS,oaSegment_intersects_doc},
    {"isHorizontal",(PyCFunction)oaSegment_isHorizontal,METH_VARARGS,oaSegment_isHorizontal_doc},
    {"isOrthogonal",(PyCFunction)oaSegment_isOrthogonal,METH_VARARGS,oaSegment_isOrthogonal_doc},
    {"isVertical",(PyCFunction)oaSegment_isVertical,METH_VARARGS,oaSegment_isVertical_doc},
    {"set",(PyCFunction)oaSegment_set,METH_VARARGS,oaSegment_set_doc},
    {"tail",(PyCFunction)oaSegment_tail,METH_VARARGS,oaSegment_tail_doc},
    {"x1",(PyCFunction)oaSegment_x1,METH_VARARGS,oaSegment_x1_doc},
    {"x2",(PyCFunction)oaSegment_x2,METH_VARARGS,oaSegment_x2_doc},
    {"y1",(PyCFunction)oaSegment_y1,METH_VARARGS,oaSegment_y1_doc},
    {"y2",(PyCFunction)oaSegment_y2,METH_VARARGS,oaSegment_y2_doc},
    {"assign",(PyCFunction)oaSegment_tp_assign,METH_VARARGS,oaSegment_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaSegment_doc[] = 
"Class: oaSegment\n"
"  The oaSegment class is a utility class the represents a line segment. It is available for general application use. It is not used for the API of any managed class. oaBox::overlaps can be called with an oaSegment.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaSegment()\n"
"    Signature: oaSegment||\n"
"    This function constructs an empty oaSegment instance.\n"
"  Paramegers: (oaPoint,oaPoint)\n"
"    Calls: oaSegment(const oaPoint& headIn,const oaPoint& tailIn)\n"
"    Signature: oaSegment||cref-oaPoint,cref-oaPoint,\n"
"    This function constructs an oaSegment instance and initializes the segment by specifying the end points.\n"
"    headIn\n"
"    The head of the segment\n"
"    tailIn\n"
"    The tail of the segment\n"
"  Paramegers: (oaVector,oaPoint)\n"
"    Calls: oaSegment(const oaVector& vec,const oaPoint& ref)\n"
"    Signature: oaSegment||cref-oaVector,cref-oaPoint,\n"
"    This function constructs an oaSegment instance and initializes the segment by specifying the head and a vector from the head.\n"
"    vec\n"
"    The vector from the head\n"
"    ref\n"
"    The head of the segment\n"
"  Paramegers: (oaSegment)\n"
"    Calls: (const oaSegment&)\n"
"    Signature: oaSegment||cref-oaSegment,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaSegment_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaSegment",
    sizeof(PyoaSegmentObject),
    0,
    (destructor)oaSegment_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaSegment_tp_compare,	/* tp_compare */
    (reprfunc)oaSegment_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaSegment_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaSegment_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaSegment_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaSegment_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaSegment_Type)<0) {
      printf("** PyType_Ready failed for: oaSegment\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaSegment",
           (PyObject*)(&PyoaSegment_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaSegment\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaSeriesRL
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaSeriesRL_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaSeriesRL_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaSeriesRLObject* self = (PyoaSeriesRLObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaSeriesRL)
    {
        PyParamoaSeriesRL p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaSeriesRL_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaSeriesRL, Choices are:\n"
        "    (oaSeriesRL)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaSeriesRL_tp_dealloc(PyoaSeriesRLObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaSeriesRL_tp_repr(PyObject *ob)
{
    PyParamoaSeriesRL value;
    int convert_status=PyoaSeriesRL_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[32];
    sprintf(buffer,"<oaSeriesRL::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaSeriesRL_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaSeriesRL v1;
    PyParamoaSeriesRL v2;
    int convert_status1=PyoaSeriesRL_Convert(ob1,&v1);
    int convert_status2=PyoaSeriesRL_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaSeriesRL_Convert(PyObject* ob,PyParamoaSeriesRL* result)
{
    if (ob == NULL) return 1;
    if (PyoaSeriesRL_Check(ob)) {
        result->SetData( (oaSeriesRL**) ((PyoaSeriesRLObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaSeriesRL Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaSeriesRL_FromoaSeriesRL(oaSeriesRL** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaSeriesRL* data=*value;
        PyObject* bself = PyoaSeriesRL_Type.tp_alloc(&PyoaSeriesRL_Type,0);
        if (bself == NULL) return bself;
        PyoaSeriesRLObject* self = (PyoaSeriesRLObject*)bself;
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
PyObject* PyoaSeriesRL_FromoaSeriesRL(oaSeriesRL* data)
{
    if (data) {
       PyObject* bself = PyoaSeriesRL_Type.tp_alloc(&PyoaSeriesRL_Type,0);
       if (bself == NULL) return bself;
       PyoaSeriesRLObject* self = (PyoaSeriesRLObject*)bself;
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
static char oaSeriesRL_getEndpoint_doc[] = 
"Class: oaSeriesRL, Function: getEndpoint\n"
"  Paramegers: (oaNode)\n"
"    Calls: oaEndpointType getEndpoint(oaNode* node) const\n"
"    Signature: getEndpoint|simple-oaEndpointType|ptr-oaNode,\n"
"    This function returns the endpoint of this device to which node is connected.\n"
"    node\n"
"    The node whose endPointType is to be queried\n"
"    oacDeviceNotConnectedToNode\n"
;

static PyObject*
oaSeriesRL_getEndpoint(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSeriesRL data;
    int convert_status=PyoaSeriesRL_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSeriesRLObject* self=(PyoaSeriesRLObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaNode p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaNode_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaEndpointType* result= new oaEndpointType(data.DataCall()->getEndpoint(p1.Data()));
        return PyoaEndpointType_FromoaEndpointType(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSeriesRL_getNode_doc[] = 
"Class: oaSeriesRL, Function: getNode\n"
"  Paramegers: (oaEndpointType)\n"
"    Calls: oaNode* getNode(oaEndpointType endpoint) const\n"
"    Signature: getNode|ptr-oaNode|simple-oaEndpointType,\n"
"    This function returns the node connected to the specified endpoint of this device.\n"
"    endpoint\n"
"    The endPointType of the device for which the corresponding node is to be obtained\n"
;

static PyObject*
oaSeriesRL_getNode(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSeriesRL data;
    int convert_status=PyoaSeriesRL_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSeriesRLObject* self=(PyoaSeriesRLObject*)ob;
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
static char oaSeriesRL_getOtherNode_doc[] = 
"Class: oaSeriesRL, Function: getOtherNode\n"
"  Paramegers: (oaNode)\n"
"    Calls: oaNode* getOtherNode(oaNode* node) const\n"
"    Signature: getOtherNode|ptr-oaNode|ptr-oaNode,\n"
"    This function returns the node connected to the other endpoint of this device (the endpoint that is not connected to node ).\n"
"    node\n"
"    The node connected at the other end of the device\n"
;

static PyObject*
oaSeriesRL_getOtherNode(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSeriesRL data;
    int convert_status=PyoaSeriesRL_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSeriesRLObject* self=(PyoaSeriesRLObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaNode p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaNode_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaNodep result= (data.DataCall()->getOtherNode(p1.Data()));
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
static char oaSeriesRL_getValue_doc[] = 
"Class: oaSeriesRL, Function: getValue\n"
"  Paramegers: (oaAnalysisPoint,oaFloat,oaFloat)\n"
"    Calls: void getValue(const oaAnalysisPoint* ap,oaFloat& resistance,oaFloat& inductance) const\n"
"    Signature: getValue|void-void|cptr-oaAnalysisPoint,ref-oaFloat,ref-oaFloat,\n"
"    This function gets the resistance and inductance values of this device for a particular analysis point.\n"
"    OpenAccess assumes resistance is specified in Ohms and inductance in Henrys.\n"
"    ap\n"
"    The analysis point for this device for which the resistance and inductance are to be queried\n"
"    resistance\n"
"    A reference to an oaFloat to be populated with the resistance value in Ohms\n"
"    inductance\n"
"    A reference to an oaFloat to be populated with the inductance value in Henrys\n"
;

static PyObject*
oaSeriesRL_getValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSeriesRL data;
    int convert_status=PyoaSeriesRL_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSeriesRLObject* self=(PyoaSeriesRLObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaAnalysisPoint p1;
    PyParamoaFloat p2;
    PyParamoaFloat p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaAnalysisPoint_Convert,&p1,
          &PyoaFloat_Convert,&p2,
          &PyoaFloat_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->getValue(p1.Data(),p2.Data(),p3.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSeriesRL_setValue_doc[] = 
"Class: oaSeriesRL, Function: setValue\n"
"  Paramegers: (oaAnalysisPoint,oaFloat,oaFloat)\n"
"    Calls: void setValue(const oaAnalysisPoint* ap,oaFloat resistance,oaFloat inductance)\n"
"    Signature: setValue|void-void|cptr-oaAnalysisPoint,simple-oaFloat,simple-oaFloat,\n"
"    This function sets the resistance and inductance values of this device for a particular analysis point.\n"
"    OpenAccess assumes resistance is specified in Ohms and inductance in Henrys.\n"
"    ap\n"
"    The analysis point for this device for which the resistance and inductance are to be set\n"
"    resistance\n"
"    An oaFloat holding the resistance value in Ohms\n"
"    inductance\n"
"    An oaFloat holding the inductance value in Henrys\n"
;

static PyObject*
oaSeriesRL_setValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSeriesRL data;
    int convert_status=PyoaSeriesRL_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSeriesRLObject* self=(PyoaSeriesRLObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaAnalysisPoint p1;
    PyParamoaFloat p2;
    PyParamoaFloat p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaAnalysisPoint_Convert,&p1,
          &PyoaFloat_Convert,&p2,
          &PyoaFloat_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setValue(p1.Data(),p2.Data(),p3.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSeriesRL_isNull_doc[] =
"Class: oaSeriesRL, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaSeriesRL_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaSeriesRL data;
    int convert_status=PyoaSeriesRL_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaSeriesRL_assign_doc[] = 
"Class: oaSeriesRL, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaSeriesRL_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaSeriesRL data;
  int convert_status=PyoaSeriesRL_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaSeriesRL p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaSeriesRL_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaSeriesRL_methodlist[] = {
    {"getEndpoint",(PyCFunction)oaSeriesRL_getEndpoint,METH_VARARGS,oaSeriesRL_getEndpoint_doc},
    {"getNode",(PyCFunction)oaSeriesRL_getNode,METH_VARARGS,oaSeriesRL_getNode_doc},
    {"getOtherNode",(PyCFunction)oaSeriesRL_getOtherNode,METH_VARARGS,oaSeriesRL_getOtherNode_doc},
    {"getValue",(PyCFunction)oaSeriesRL_getValue,METH_VARARGS,oaSeriesRL_getValue_doc},
    {"setValue",(PyCFunction)oaSeriesRL_setValue,METH_VARARGS,oaSeriesRL_setValue_doc},
    {"isNull",(PyCFunction)oaSeriesRL_tp_isNull,METH_VARARGS,oaSeriesRL_isNull_doc},
    {"assign",(PyCFunction)oaSeriesRL_tp_assign,METH_VARARGS,oaSeriesRL_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaSeriesRL_doc[] = 
"Class: oaSeriesRL\n"
"  The oaSeriesRL class represents a resistor and inductor connected in series, where the node between the two devices is not of interest. Each oaSeriesRL object has both a resistance value and an inductance value for each analysis point that the parasitic network represents.\n"
"Constructors:\n"
"  Paramegers: (oaSeriesRL)\n"
"    Calls: (const oaSeriesRL&)\n"
"    Signature: oaSeriesRL||cref-oaSeriesRL,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaSeriesRL_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaSeriesRL",
    sizeof(PyoaSeriesRLObject),
    0,
    (destructor)oaSeriesRL_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaSeriesRL_tp_compare,	/* tp_compare */
    (reprfunc)oaSeriesRL_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaSeriesRL_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaSeriesRL_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaDevice_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaSeriesRL_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaSeriesRL_static_create_doc[] = 
"Class: oaSeriesRL, Function: create\n"
"  Paramegers: (oaNode,oaNode)\n"
"    Calls: oaSeriesRL* create(oaNode* fromNode,oaNode* toNode)\n"
"    Signature: create|ptr-oaSeriesRL|ptr-oaNode,ptr-oaNode,\n"
"    This function creates a seriesRL device belonging to the specified parasitic network. The device created will not have an ID associated with it. The hasId() function will return false for these devices, and the getId() function will return an oacInvalidDeviceID value.\n"
"    SeriesRL devices can be created between nodes in different partitions of the same root parasitic network, where one of the partitions must be an ancestor of the other. In this case, the seriesRL device will be created in the lower level partition, and the node in the higher level partition must have an id so that it can be found when loading the lower level partition.\n"
"    fromNode\n"
"    The start node for the seriesRL device\n"
"    toNode\n"
"    The end node for the seriesRL device\n"
"    oacNodesNotInSameDesign\n"
"    oacNodesNotInSameNetwork\n"
"    oacNodesNotInRelatedPartitions\n"
"    oacAncestorNodeWithoutId\n"
"  Paramegers: (oaNode,oaNode,oaUInt4)\n"
"    Calls: oaSeriesRL* create(oaNode* fromNode,oaNode* toNode,oaUInt4 id)\n"
"    Signature: create|ptr-oaSeriesRL|ptr-oaNode,ptr-oaNode,simple-oaUInt4,\n"
"    This function creates a seriesRL device belonging to the parasitic network containing fromNode and toNode . An explicit unique ID id is required to be specified. An exception will be thrown if the id is the reserved oacInvalidDeviceID value or if a device with the specified id value already exists. The hasId() function will return true for devices created with this function and the getId() function will return the user-specified id.\n"
"    SeriesRL devices can be created between nodes in different partitions of the same root parasitic network, where one of the partitions must be an ancestor of the other. In this case, the seriesRL device will be created in the lower level partition, and the node in the higher level partition must have an id so that it can be found when loading the lower level partition.\n"
"    fromNode\n"
"    The start node for the seriesRL device\n"
"    toNode\n"
"    The end node for the seriesRL device\n"
"    id\n"
"    The unique ID to be assigned to this device\n"
"    oacInvalidDeviceIdSpecified\n"
"    oacLocalDeviceIdExists\n"
"    oacNodesNotInSameDesign\n"
"    oacNodesNotInSameNetwork\n"
"    oacNodesNotInRelatedPartitions\n"
"    oacAncestorNodeWithoutId\n"
;

static PyObject*
oaSeriesRL_static_create(PyObject* ob, PyObject *args)
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
            oaSeriesRLp result= (oaSeriesRL::create(p1.Data(),p2.Data()));
            return PyoaSeriesRL_FromoaSeriesRL(result);
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
            oaSeriesRLp result= (oaSeriesRL::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaSeriesRL_FromoaSeriesRL(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaSeriesRL, function: create, Choices are:\n"
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
static PyMethodDef oaSeriesRL_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaSeriesRL_static_create,METH_VARARGS,oaSeriesRL_static_create_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaSeriesRL_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaSeriesRL_Type)<0) {
      printf("** PyType_Ready failed for: oaSeriesRL\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaSeriesRL",
           (PyObject*)(&PyoaSeriesRL_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaSeriesRL\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaSeriesRL_Type.tp_dict;
    for(method=oaSeriesRL_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaSession
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaSession_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaSession_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaSessionObject* self = (PyoaSessionObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaSession)
    {
        PyParamoaSession p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaSession_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaSession, Choices are:\n"
        "    (oaSession)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaSession_tp_dealloc(PyoaSessionObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaSession_tp_repr(PyObject *ob)
{
    PyParamoaSession value;
    int convert_status=PyoaSession_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[31];
    sprintf(buffer,"<oaSession::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaSession_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaSession v1;
    PyParamoaSession v2;
    int convert_status1=PyoaSession_Convert(ob1,&v1);
    int convert_status2=PyoaSession_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaSession_Convert(PyObject* ob,PyParamoaSession* result)
{
    if (ob == NULL) return 1;
    if (PyoaSession_Check(ob)) {
        result->SetData( (oaSession**) ((PyoaSessionObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaSession Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaSession_FromoaSession(oaSession** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaSession* data=*value;
        PyObject* bself = PyoaSession_Type.tp_alloc(&PyoaSession_Type,0);
        if (bself == NULL) return bself;
        PyoaSessionObject* self = (PyoaSessionObject*)bself;
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
PyObject* PyoaSession_FromoaSession(oaSession* data)
{
    if (data) {
       PyObject* bself = PyoaSession_Type.tp_alloc(&PyoaSession_Type,0);
       if (bself == NULL) return bself;
       PyoaSessionObject* self = (PyoaSessionObject*)bself;
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
static char oaSession_calcVMSize_doc[] = 
"Class: oaSession, Function: calcVMSize\n"
"  Paramegers: ()\n"
"    Calls: oaUInt8 calcVMSize() const\n"
"    Signature: calcVMSize|simple-oaUInt8|\n"
"    BrowseData: 1\n"
"    This function calculates and returns the amount of virtual memory that OpenAccess is currently using, including all open databases.\n"
;

static PyObject*
oaSession_calcVMSize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSession data;
    int convert_status=PyoaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSessionObject* self=(PyoaSessionObject*)ob;
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
static char oaSession_getAppDefs_doc[] = 
"Class: oaSession, Function: getAppDefs\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaAppDef_oaSession getAppDefs()\n"
"    Signature: getAppDefs|simple-oaCollection_oaAppDef_oaSession|\n"
"    BrowseData: 1\n"
"    This function returns the collection of extensions that are currently defined.\n"
;

static PyObject*
oaSession_getAppDefs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSession data;
    int convert_status=PyoaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSessionObject* self=(PyoaSessionObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaAppDef_oaSession* result= new oaCollection_oaAppDef_oaSession(data.DataCall()->getAppDefs());
        return PyoaCollection_oaAppDef_oaSession_FromoaCollection_oaAppDef_oaSession(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSession_getAppDefsIter_doc[] = 
"Class: oaSession, Function: getAppDefsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaAppDef getAppDefsIter()\n"
"    Signature: getAppDefsIter|simple-oaIter_oaAppDef|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of extensions that are currently defined.\n"
;

static PyObject*
oaSession_getAppDefsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSession data;
    int convert_status=PyoaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSessionObject* self=(PyoaSessionObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaAppDef* result= new oaIter_oaAppDef(data.DataCall()->getAppDefs());
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
static char oaSession_getAppObjectDefs_doc[] = 
"Class: oaSession, Function: getAppObjectDefs\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaAppObjectDef_oaSession getAppObjectDefs()\n"
"    Signature: getAppObjectDefs|simple-oaCollection_oaAppObjectDef_oaSession|\n"
"    BrowseData: 1\n"
"    This function returns a collection of all oaAppObjectDefs currently defined.\n"
;

static PyObject*
oaSession_getAppObjectDefs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSession data;
    int convert_status=PyoaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSessionObject* self=(PyoaSessionObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaAppObjectDef_oaSession* result= new oaCollection_oaAppObjectDef_oaSession(data.DataCall()->getAppObjectDefs());
        return PyoaCollection_oaAppObjectDef_oaSession_FromoaCollection_oaAppObjectDef_oaSession(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSession_getAppObjectDefsIter_doc[] = 
"Class: oaSession, Function: getAppObjectDefsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaAppObjectDef getAppObjectDefsIter()\n"
"    Signature: getAppObjectDefsIter|simple-oaIter_oaAppObjectDef|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of all oaAppObjectDefs currently defined.\n"
;

static PyObject*
oaSession_getAppObjectDefsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSession data;
    int convert_status=PyoaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSessionObject* self=(PyoaSessionObject*)ob;
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
static char oaSession_getConstraintDefs_doc[] = 
"Class: oaSession, Function: getConstraintDefs\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaConstraintDef_oaSession getConstraintDefs() const\n"
"    Signature: getConstraintDefs|simple-oaCollection_oaConstraintDef_oaSession|\n"
"    BrowseData: 1\n"
"    This function returns the collection of all currently defined constraint definitions.\n"
;

static PyObject*
oaSession_getConstraintDefs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSession data;
    int convert_status=PyoaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSessionObject* self=(PyoaSessionObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaConstraintDef_oaSession* result= new oaCollection_oaConstraintDef_oaSession(data.DataCall()->getConstraintDefs());
        return PyoaCollection_oaConstraintDef_oaSession_FromoaCollection_oaConstraintDef_oaSession(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSession_getConstraintDefsIter_doc[] = 
"Class: oaSession, Function: getConstraintDefsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaConstraintDef getConstraintDefsIter() const\n"
"    Signature: getConstraintDefsIter|simple-oaIter_oaConstraintDef|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of all currently defined constraint definitions.\n"
;

static PyObject*
oaSession_getConstraintDefsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSession data;
    int convert_status=PyoaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSessionObject* self=(PyoaSessionObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaConstraintDef* result= new oaIter_oaConstraintDef(data.DataCall()->getConstraintDefs());
        return PyoaIter_oaConstraintDef_FromoaIter_oaConstraintDef(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSession_getConstraintParamDefs_doc[] = 
"Class: oaSession, Function: getConstraintParamDefs\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaConstraintParamDef_oaSession getConstraintParamDefs() const\n"
"    Signature: getConstraintParamDefs|simple-oaCollection_oaConstraintParamDef_oaSession|\n"
"    BrowseData: 1\n"
"    This function returns the collection of constraint parameter definitions that are currently defined.\n"
;

static PyObject*
oaSession_getConstraintParamDefs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSession data;
    int convert_status=PyoaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSessionObject* self=(PyoaSessionObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaConstraintParamDef_oaSession* result= new oaCollection_oaConstraintParamDef_oaSession(data.DataCall()->getConstraintParamDefs());
        return PyoaCollection_oaConstraintParamDef_oaSession_FromoaCollection_oaConstraintParamDef_oaSession(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSession_getConstraintParamDefsIter_doc[] = 
"Class: oaSession, Function: getConstraintParamDefsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaConstraintParamDef getConstraintParamDefsIter() const\n"
"    Signature: getConstraintParamDefsIter|simple-oaIter_oaConstraintParamDef|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of constraint parameter definitions that are currently defined.\n"
;

static PyObject*
oaSession_getConstraintParamDefsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSession data;
    int convert_status=PyoaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSessionObject* self=(PyoaSessionObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaConstraintParamDef* result= new oaIter_oaConstraintParamDef(data.DataCall()->getConstraintParamDefs());
        return PyoaIter_oaConstraintParamDef_FromoaIter_oaConstraintParamDef(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSession_getDerivedLayerDefs_doc[] = 
"Class: oaSession, Function: getDerivedLayerDefs\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaDerivedLayerDef_oaSession getDerivedLayerDefs() const\n"
"    Signature: getDerivedLayerDefs|simple-oaCollection_oaDerivedLayerDef_oaSession|\n"
"    BrowseData: 1\n"
"    This function returns the collection of all currently defined derived layer definitions.\n"
;

static PyObject*
oaSession_getDerivedLayerDefs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSession data;
    int convert_status=PyoaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSessionObject* self=(PyoaSessionObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaDerivedLayerDef_oaSession* result= new oaCollection_oaDerivedLayerDef_oaSession(data.DataCall()->getDerivedLayerDefs());
        return PyoaCollection_oaDerivedLayerDef_oaSession_FromoaCollection_oaDerivedLayerDef_oaSession(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSession_getDerivedLayerDefsIter_doc[] = 
"Class: oaSession, Function: getDerivedLayerDefsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaDerivedLayerDef getDerivedLayerDefsIter() const\n"
"    Signature: getDerivedLayerDefsIter|simple-oaIter_oaDerivedLayerDef|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of all currently defined derived layer definitions.\n"
;

static PyObject*
oaSession_getDerivedLayerDefsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSession data;
    int convert_status=PyoaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSessionObject* self=(PyoaSessionObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaDerivedLayerDef* result= new oaIter_oaDerivedLayerDef(data.DataCall()->getDerivedLayerDefs());
        return PyoaIter_oaDerivedLayerDef_FromoaIter_oaDerivedLayerDef(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSession_getDerivedLayerParamDefs_doc[] = 
"Class: oaSession, Function: getDerivedLayerParamDefs\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaDerivedLayerParamDef_oaSession getDerivedLayerParamDefs() const\n"
"    Signature: getDerivedLayerParamDefs|simple-oaCollection_oaDerivedLayerParamDef_oaSession|\n"
"    BrowseData: 1\n"
"    This function returns the collection of all currently defined derived layer parameter definitions.\n"
;

static PyObject*
oaSession_getDerivedLayerParamDefs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSession data;
    int convert_status=PyoaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSessionObject* self=(PyoaSessionObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaDerivedLayerParamDef_oaSession* result= new oaCollection_oaDerivedLayerParamDef_oaSession(data.DataCall()->getDerivedLayerParamDefs());
        return PyoaCollection_oaDerivedLayerParamDef_oaSession_FromoaCollection_oaDerivedLayerParamDef_oaSession(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSession_getDerivedLayerParamDefsIter_doc[] = 
"Class: oaSession, Function: getDerivedLayerParamDefsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaDerivedLayerParamDef getDerivedLayerParamDefsIter() const\n"
"    Signature: getDerivedLayerParamDefsIter|simple-oaIter_oaDerivedLayerParamDef|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns the collection of all currently defined derived layer parameter definitions.\n"
;

static PyObject*
oaSession_getDerivedLayerParamDefsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSession data;
    int convert_status=PyoaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSessionObject* self=(PyoaSessionObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaDerivedLayerParamDef* result= new oaIter_oaDerivedLayerParamDef(data.DataCall()->getDerivedLayerParamDefs());
        return PyoaIter_oaDerivedLayerParamDef_FromoaIter_oaDerivedLayerParamDef(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSession_minimizeVM_doc[] = 
"Class: oaSession, Function: minimizeVM\n"
"  Paramegers: ()\n"
"    Calls: void minimizeVM()\n"
"    Signature: minimizeVM|void-void|\n"
"    BrowseData: 0\n"
"    This function minimizes the amount of virtual memory currently used by OpenAccess. It releases memory OpenAccess is holding in reserve for future use, as well as dynamically allocated data structures that can be rebuilt as needed. Any libraries and databases that are in memory remain in memory, no objects are destroyed, and no object pointers are invalidated by this function.\n"
"    Applications can call this function in several scenarios:\n"
"    An application loads a number of OpenAccess databases, builds application-specific data structures, purges all of the databases, runs some algorithms that require large chunks of memory, then reopens the OpenAccess databases to annotate the results.\n"
"    An application loads a number of OpenAccess databases, builds application-specific data structures, purges all of the databases, then wants to recover all of the memory used by OA.\n"
"    An application creates or edits an OpenAccess database, causing OpenAccess to build transient data structures, then wants to minimize the memory used by the database before starting a phase of processing that interacts with OpenAccess in different ways.\n"
"    In the first two cases, minimizeVM() should be called after purging the OpenAccess databases. In the third case minimizeVM() should be called between the different phases of processing.\n"
"    This function should be called sparingly, as it can have a substantial impact on the performance of subsequent operations.\n"
;

static PyObject*
oaSession_minimizeVM(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSession data;
    int convert_status=PyoaSession_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSessionObject* self=(PyoaSessionObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->minimizeVM();
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSession_isNull_doc[] =
"Class: oaSession, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaSession_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaSession data;
    int convert_status=PyoaSession_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaSession_assign_doc[] = 
"Class: oaSession, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaSession_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaSession data;
  int convert_status=PyoaSession_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaSession p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaSession_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaSession_methodlist[] = {
    {"calcVMSize",(PyCFunction)oaSession_calcVMSize,METH_VARARGS,oaSession_calcVMSize_doc},
    {"getAppDefs",(PyCFunction)oaSession_getAppDefs,METH_VARARGS,oaSession_getAppDefs_doc},
    {"getAppDefsIter",(PyCFunction)oaSession_getAppDefsIter,METH_VARARGS,oaSession_getAppDefsIter_doc},
    {"getAppObjectDefs",(PyCFunction)oaSession_getAppObjectDefs,METH_VARARGS,oaSession_getAppObjectDefs_doc},
    {"getAppObjectDefsIter",(PyCFunction)oaSession_getAppObjectDefsIter,METH_VARARGS,oaSession_getAppObjectDefsIter_doc},
    {"getConstraintDefs",(PyCFunction)oaSession_getConstraintDefs,METH_VARARGS,oaSession_getConstraintDefs_doc},
    {"getConstraintDefsIter",(PyCFunction)oaSession_getConstraintDefsIter,METH_VARARGS,oaSession_getConstraintDefsIter_doc},
    {"getConstraintParamDefs",(PyCFunction)oaSession_getConstraintParamDefs,METH_VARARGS,oaSession_getConstraintParamDefs_doc},
    {"getConstraintParamDefsIter",(PyCFunction)oaSession_getConstraintParamDefsIter,METH_VARARGS,oaSession_getConstraintParamDefsIter_doc},
    {"getDerivedLayerDefs",(PyCFunction)oaSession_getDerivedLayerDefs,METH_VARARGS,oaSession_getDerivedLayerDefs_doc},
    {"getDerivedLayerDefsIter",(PyCFunction)oaSession_getDerivedLayerDefsIter,METH_VARARGS,oaSession_getDerivedLayerDefsIter_doc},
    {"getDerivedLayerParamDefs",(PyCFunction)oaSession_getDerivedLayerParamDefs,METH_VARARGS,oaSession_getDerivedLayerParamDefs_doc},
    {"getDerivedLayerParamDefsIter",(PyCFunction)oaSession_getDerivedLayerParamDefsIter,METH_VARARGS,oaSession_getDerivedLayerParamDefsIter_doc},
    {"minimizeVM",(PyCFunction)oaSession_minimizeVM,METH_VARARGS,oaSession_minimizeVM_doc},
    {"isNull",(PyCFunction)oaSession_tp_isNull,METH_VARARGS,oaSession_isNull_doc},
    {"assign",(PyCFunction)oaSession_tp_assign,METH_VARARGS,oaSession_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaSession_doc[] = 
"Class: oaSession\n"
"  The oaSession class implements a session database. This is a non-persistent \"database\" which is used as the database parent for session-wide information. This session information is represented by the object classes which inherit from oaSessionObject , such as oaAppDef and oaViewType .\n"
"  A session database is automatically created and maintained as needed by the OpenAccess implementation. There is only one session database per OpenAccess session.\n"
"Constructors:\n"
"  Paramegers: (oaSession)\n"
"    Calls: (const oaSession&)\n"
"    Signature: oaSession||cref-oaSession,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaSession_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaSession",
    sizeof(PyoaSessionObject),
    0,
    (destructor)oaSession_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaSession_tp_compare,	/* tp_compare */
    (reprfunc)oaSession_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaSession_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaSession_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaSessionObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaSession_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaSession_static_get_doc[] = 
"Class: oaSession, Function: get\n"
"  Paramegers: ()\n"
"    Calls: oaSession* get()\n"
"    Signature: get|ptr-oaSession|\n"
"    BrowseData: 1\n"
"    This function returns the global session object.\n"
;

static PyObject*
oaSession_static_get(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaSessionp result= (oaSession::get());
        return PyoaSession_FromoaSession(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaSession_staticmethodlist[] = {
    {"static_get",(PyCFunction)oaSession_static_get,METH_VARARGS,oaSession_static_get_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaSession_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaSession_Type)<0) {
      printf("** PyType_Ready failed for: oaSession\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaSession",
           (PyObject*)(&PyoaSession_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaSession\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaSession_Type.tp_dict;
    for(method=oaSession_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaSessionDataTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaSessionDataTypeEnum_Convert(PyObject* ob,PyParamoaSessionDataTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSessionDataType")==0) { result->SetData(oacSessionDataType); return 1;}
        if (strcasecmp(str,"oacSessionAppObjectDataType")==0) { result->SetData(oacSessionAppObjectDataType); return 1;}
        if (strcasecmp(str,"oacSessionPropDataType")==0) { result->SetData(oacSessionPropDataType); return 1;}
        if (strcasecmp(str,"oacSessionGroupDataType")==0) { result->SetData(oacSessionGroupDataType); return 1;}
        if (strcasecmp(str,"oacSessionGroupMemDataType")==0) { result->SetData(oacSessionGroupMemDataType); return 1;}
        if (strcasecmp(str,"oacSessionAvatarDataType")==0) { result->SetData(oacSessionAvatarDataType); return 1;}
        if (strcasecmp(str,"oacSessionValueDataType")==0) { result->SetData(oacSessionValueDataType); return 1;}
        if (strcasecmp(str,"oacSessionConstraintParamDefDataType")==0) { result->SetData(oacSessionConstraintParamDefDataType); return 1;}
        if (strcasecmp(str,"oacSessionConstraintParamDataType")==0) { result->SetData(oacSessionConstraintParamDataType); return 1;}
        if (strcasecmp(str,"oacSessionConstraintDefDataType")==0) { result->SetData(oacSessionConstraintDefDataType); return 1;}
        if (strcasecmp(str,"oacSessionConstraintDataType")==0) { result->SetData(oacSessionConstraintDataType); return 1;}
        if (strcasecmp(str,"oacSessionConstraintGroupDataType")==0) { result->SetData(oacSessionConstraintGroupDataType); return 1;}
        if (strcasecmp(str,"oacSessionConstraintGroupMemDataType")==0) { result->SetData(oacSessionConstraintGroupMemDataType); return 1;}
        if (strcasecmp(str,"oacSessionConstraintGroupHeaderDataType")==0) { result->SetData(oacSessionConstraintGroupHeaderDataType); return 1;}
        if (strcasecmp(str,"oacLibDefListDataType")==0) { result->SetData(oacLibDefListDataType); return 1;}
        if (strcasecmp(str,"oacLibDefListMemDataType")==0) { result->SetData(oacLibDefListMemDataType); return 1;}
        if (strcasecmp(str,"oacViewTypeDataType")==0) { result->SetData(oacViewTypeDataType); return 1;}
        if (strcasecmp(str,"oacAppDefDataType")==0) { result->SetData(oacAppDefDataType); return 1;}
        if (strcasecmp(str,"oacAppObjectDefDataType")==0) { result->SetData(oacAppObjectDefDataType); return 1;}
        if (strcasecmp(str,"oacSessionFeatureDataType")==0) { result->SetData(oacSessionFeatureDataType); return 1;}
        if (strcasecmp(str,"oacSessionFeaturePolicyDataType")==0) { result->SetData(oacSessionFeaturePolicyDataType); return 1;}
        if (strcasecmp(str,"oacSessionDerivedLayerParamDefDataType")==0) { result->SetData(oacSessionDerivedLayerParamDefDataType); return 1;}
        if (strcasecmp(str,"oacSessionDerivedLayerDefDataType")==0) { result->SetData(oacSessionDerivedLayerDefDataType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaSessionDataTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaSessionDataTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaSessionDataTypeEnum_FromoaSessionDataTypeEnum(oaSessionDataTypeEnum ob)
{
    if (ob==oacSessionDataType) return PyString_FromString("oacSessionDataType");
    if (ob==oacSessionAppObjectDataType) return PyString_FromString("oacSessionAppObjectDataType");
    if (ob==oacSessionPropDataType) return PyString_FromString("oacSessionPropDataType");
    if (ob==oacSessionGroupDataType) return PyString_FromString("oacSessionGroupDataType");
    if (ob==oacSessionGroupMemDataType) return PyString_FromString("oacSessionGroupMemDataType");
    if (ob==oacSessionAvatarDataType) return PyString_FromString("oacSessionAvatarDataType");
    if (ob==oacSessionValueDataType) return PyString_FromString("oacSessionValueDataType");
    if (ob==oacSessionConstraintParamDefDataType) return PyString_FromString("oacSessionConstraintParamDefDataType");
    if (ob==oacSessionConstraintParamDataType) return PyString_FromString("oacSessionConstraintParamDataType");
    if (ob==oacSessionConstraintDefDataType) return PyString_FromString("oacSessionConstraintDefDataType");
    if (ob==oacSessionConstraintDataType) return PyString_FromString("oacSessionConstraintDataType");
    if (ob==oacSessionConstraintGroupDataType) return PyString_FromString("oacSessionConstraintGroupDataType");
    if (ob==oacSessionConstraintGroupMemDataType) return PyString_FromString("oacSessionConstraintGroupMemDataType");
    if (ob==oacSessionConstraintGroupHeaderDataType) return PyString_FromString("oacSessionConstraintGroupHeaderDataType");
    if (ob==oacLibDefListDataType) return PyString_FromString("oacLibDefListDataType");
    if (ob==oacLibDefListMemDataType) return PyString_FromString("oacLibDefListMemDataType");
    if (ob==oacViewTypeDataType) return PyString_FromString("oacViewTypeDataType");
    if (ob==oacAppDefDataType) return PyString_FromString("oacAppDefDataType");
    if (ob==oacAppObjectDefDataType) return PyString_FromString("oacAppObjectDefDataType");
    if (ob==oacSessionFeatureDataType) return PyString_FromString("oacSessionFeatureDataType");
    if (ob==oacSessionFeaturePolicyDataType) return PyString_FromString("oacSessionFeaturePolicyDataType");
    if (ob==oacSessionDerivedLayerParamDefDataType) return PyString_FromString("oacSessionDerivedLayerParamDefDataType");
    if (ob==oacSessionDerivedLayerDefDataType) return PyString_FromString("oacSessionDerivedLayerDefDataType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaSessionDataTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaSessionDataTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaSessionDataTypeEnum_FromoaSessionDataTypeEnum(oaSessionDataTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaSessionDataTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaSessionDataTypeEnum_doc[] =
"Type convert function for enum: oaSessionDataTypeEnum";
                               
static PyMethodDef PyoaSessionDataTypeEnum_method =
  {"oaSessionDataTypeEnum",(PyCFunction)PyoaSessionDataTypeEnum_TypeFunction,METH_VARARGS,oaSessionDataTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaSessionDataTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSessionDataType");
    PyDict_SetItemString(mod_dict,"oacSessionDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionAppObjectDataType");
    PyDict_SetItemString(mod_dict,"oacSessionAppObjectDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionPropDataType");
    PyDict_SetItemString(mod_dict,"oacSessionPropDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionGroupDataType");
    PyDict_SetItemString(mod_dict,"oacSessionGroupDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionGroupMemDataType");
    PyDict_SetItemString(mod_dict,"oacSessionGroupMemDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionAvatarDataType");
    PyDict_SetItemString(mod_dict,"oacSessionAvatarDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionValueDataType");
    PyDict_SetItemString(mod_dict,"oacSessionValueDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionConstraintParamDefDataType");
    PyDict_SetItemString(mod_dict,"oacSessionConstraintParamDefDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionConstraintParamDataType");
    PyDict_SetItemString(mod_dict,"oacSessionConstraintParamDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionConstraintDefDataType");
    PyDict_SetItemString(mod_dict,"oacSessionConstraintDefDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionConstraintDataType");
    PyDict_SetItemString(mod_dict,"oacSessionConstraintDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionConstraintGroupDataType");
    PyDict_SetItemString(mod_dict,"oacSessionConstraintGroupDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionConstraintGroupMemDataType");
    PyDict_SetItemString(mod_dict,"oacSessionConstraintGroupMemDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionConstraintGroupHeaderDataType");
    PyDict_SetItemString(mod_dict,"oacSessionConstraintGroupHeaderDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibDefListDataType");
    PyDict_SetItemString(mod_dict,"oacLibDefListDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLibDefListMemDataType");
    PyDict_SetItemString(mod_dict,"oacLibDefListMemDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacViewTypeDataType");
    PyDict_SetItemString(mod_dict,"oacViewTypeDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAppDefDataType");
    PyDict_SetItemString(mod_dict,"oacAppDefDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAppObjectDefDataType");
    PyDict_SetItemString(mod_dict,"oacAppObjectDefDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionFeatureDataType");
    PyDict_SetItemString(mod_dict,"oacSessionFeatureDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionFeaturePolicyDataType");
    PyDict_SetItemString(mod_dict,"oacSessionFeaturePolicyDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionDerivedLayerParamDefDataType");
    PyDict_SetItemString(mod_dict,"oacSessionDerivedLayerParamDefDataType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSessionDerivedLayerDefDataType");
    PyDict_SetItemString(mod_dict,"oacSessionDerivedLayerDefDataType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaSessionDataTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaSessionDataTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaSessionDataTypeEnum\n");
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
// Wrapper Implementation for Class: oaSessionObject
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaSessionObject_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaSessionObject_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaSessionObjectObject* self = (PyoaSessionObjectObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaSessionObject)
    {
        PyParamoaSessionObject p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaSessionObject_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaSessionObject, Choices are:\n"
        "    (oaSessionObject)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaSessionObject_tp_dealloc(PyoaSessionObjectObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaSessionObject_tp_repr(PyObject *ob)
{
    PyParamoaSessionObject value;
    int convert_status=PyoaSessionObject_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaSessionObject::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaSessionObject_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaSessionObject v1;
    PyParamoaSessionObject v2;
    int convert_status1=PyoaSessionObject_Convert(ob1,&v1);
    int convert_status2=PyoaSessionObject_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaSessionObject_Convert(PyObject* ob,PyParamoaSessionObject* result)
{
    if (ob == NULL) return 1;
    if (PyoaSessionObject_Check(ob)) {
        result->SetData( (oaSessionObject**) ((PyoaSessionObjectObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaSessionObject Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaSessionObject_FromoaSessionObject(oaSessionObject** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaSessionObject* data=*value;
        if (data->getType()==oacLayerConstraintDefType) return PyoaLayerConstraintDef_FromoaLayerConstraintDef((oaLayerConstraintDef**)value,borrow,lock);
        if (data->getType()==oacDerivedLayerParamDefType) return PyoaDerivedLayerParamDef_FromoaDerivedLayerParamDef((oaDerivedLayerParamDef**)value,borrow,lock);
        if (data->getType()==oacLibDefListType) return PyoaLibDefList_FromoaLibDefList((oaLibDefList**)value,borrow,lock);
        if (data->getType()==oacLayerArrayConstraintDefType) return PyoaLayerArrayConstraintDef_FromoaLayerArrayConstraintDef((oaLayerArrayConstraintDef**)value,borrow,lock);
        if (data->getType()==oacLibDefListRefType) return PyoaLibDefListRef_FromoaLibDefListRef((oaLibDefListRef**)value,borrow,lock);
        if (data->getType()==oacLayerPairConstraintDefType) return PyoaLayerPairConstraintDef_FromoaLayerPairConstraintDef((oaLayerPairConstraintDef**)value,borrow,lock);
        if (data->getType()==oacViewTypeType) return PyoaViewType_FromoaViewType((oaViewType**)value,borrow,lock);
        if (data->getType()==oacLibDefType) return PyoaLibDef_FromoaLibDef((oaLibDef**)value,borrow,lock);
        if (data->getType()==oacFeatureType) return PyoaFeature_FromoaFeature((oaFeature**)value,borrow,lock);
        if (data->getType()==oacSimpleConstraintDefType) return PyoaSimpleConstraintDef_FromoaSimpleConstraintDef((oaSimpleConstraintDef**)value,borrow,lock);
        if (data->getType()==oacAppObjectDefType) return PyoaAppObjectDef_FromoaAppObjectDef((oaAppObjectDef**)value,borrow,lock);
        if (data->getType()==oacConstraintParamDefType) return PyoaConstraintParamDef_FromoaConstraintParamDef((oaConstraintParamDef**)value,borrow,lock);
        if (data->getType()==oacSessionType) return PyoaSession_FromoaSession((oaSession**)value,borrow,lock);
        if (data->getType()==oacDerivedLayerDefType) return PyoaDerivedLayerDef_FromoaDerivedLayerDef((oaDerivedLayerDef**)value,borrow,lock);
        PyObject* bself = PyoaSessionObject_Type.tp_alloc(&PyoaSessionObject_Type,0);
        if (bself == NULL) return bself;
        PyoaSessionObjectObject* self = (PyoaSessionObjectObject*)bself;
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
PyObject* PyoaSessionObject_FromoaSessionObject(oaSessionObject* data)
{
    if (data) {
        if (data->getType()==oacLayerConstraintDefType) return PyoaLayerConstraintDef_FromoaLayerConstraintDef((oaLayerConstraintDef*)data);
        if (data->getType()==oacDerivedLayerParamDefType) return PyoaDerivedLayerParamDef_FromoaDerivedLayerParamDef((oaDerivedLayerParamDef*)data);
        if (data->getType()==oacLibDefListType) return PyoaLibDefList_FromoaLibDefList((oaLibDefList*)data);
        if (data->getType()==oacLayerArrayConstraintDefType) return PyoaLayerArrayConstraintDef_FromoaLayerArrayConstraintDef((oaLayerArrayConstraintDef*)data);
        if (data->getType()==oacLibDefListRefType) return PyoaLibDefListRef_FromoaLibDefListRef((oaLibDefListRef*)data);
        if (data->getType()==oacLayerPairConstraintDefType) return PyoaLayerPairConstraintDef_FromoaLayerPairConstraintDef((oaLayerPairConstraintDef*)data);
        if (data->getType()==oacViewTypeType) return PyoaViewType_FromoaViewType((oaViewType*)data);
        if (data->getType()==oacLibDefType) return PyoaLibDef_FromoaLibDef((oaLibDef*)data);
        if (data->getType()==oacFeatureType) return PyoaFeature_FromoaFeature((oaFeature*)data);
        if (data->getType()==oacSimpleConstraintDefType) return PyoaSimpleConstraintDef_FromoaSimpleConstraintDef((oaSimpleConstraintDef*)data);
        if (data->getType()==oacAppObjectDefType) return PyoaAppObjectDef_FromoaAppObjectDef((oaAppObjectDef*)data);
        if (data->getType()==oacConstraintParamDefType) return PyoaConstraintParamDef_FromoaConstraintParamDef((oaConstraintParamDef*)data);
        if (data->getType()==oacSessionType) return PyoaSession_FromoaSession((oaSession*)data);
        if (data->getType()==oacDerivedLayerDefType) return PyoaDerivedLayerDef_FromoaDerivedLayerDef((oaDerivedLayerDef*)data);
       PyObject* bself = PyoaSessionObject_Type.tp_alloc(&PyoaSessionObject_Type,0);
       if (bself == NULL) return bself;
       PyoaSessionObjectObject* self = (PyoaSessionObjectObject*)bself;
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
static char oaSessionObject_getSession_doc[] = 
"Class: oaSessionObject, Function: getSession\n"
"  Paramegers: ()\n"
"    Calls: oaSession* getSession() const\n"
"    Signature: getSession|ptr-oaSession|\n"
"    BrowseData: 1\n"
"    This function returns the oaSession database associated with this oaSessionObject.\n"
;

static PyObject*
oaSessionObject_getSession(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSessionObject data;
    int convert_status=PyoaSessionObject_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSessionObjectObject* self=(PyoaSessionObjectObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaSessionp result= (data.DataCall()->getSession());
        return PyoaSession_FromoaSession(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSessionObject_isNull_doc[] =
"Class: oaSessionObject, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaSessionObject_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaSessionObject data;
    int convert_status=PyoaSessionObject_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaSessionObject_assign_doc[] = 
"Class: oaSessionObject, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaSessionObject_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaSessionObject data;
  int convert_status=PyoaSessionObject_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaSessionObject p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaSessionObject_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaSessionObject_methodlist[] = {
    {"getSession",(PyCFunction)oaSessionObject_getSession,METH_VARARGS,oaSessionObject_getSession_doc},
    {"isNull",(PyCFunction)oaSessionObject_tp_isNull,METH_VARARGS,oaSessionObject_isNull_doc},
    {"assign",(PyCFunction)oaSessionObject_tp_assign,METH_VARARGS,oaSessionObject_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaSessionObject_doc[] = 
"Class: oaSessionObject\n"
"  The oaSessionObject class is an abstract class that is the base for all OpenAccess session objects.\n"
"  The oaSession database is a non-persistent database which serves as the database parent to all session objects. Session objects are transient objects which are valid across the entire OA session.\n"
"  Session objects may have a persistent representation which is tied to a persistent database such as a oaDesign , oaTech or oaLib database. In some cases, the session objects represent a union or superset of information compiled from databases which are opened in the OA session.\n"
"  It is not legal to create properties or appDefs on session objects, nor is it legal to add these objects to groups.\n"
"Constructors:\n"
"  Paramegers: (oaSessionObject)\n"
"    Calls: (const oaSessionObject&)\n"
"    Signature: oaSessionObject||cref-oaSessionObject,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaSessionObject_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaSessionObject",
    sizeof(PyoaSessionObjectObject),
    0,
    (destructor)oaSessionObject_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaSessionObject_tp_compare,	/* tp_compare */
    (reprfunc)oaSessionObject_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaSessionObject_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaSessionObject_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaSessionObject_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaSessionObject_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaSessionObject_Type)<0) {
      printf("** PyType_Ready failed for: oaSessionObject\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaSessionObject",
           (PyObject*)(&PyoaSessionObject_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaSessionObject\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaShape
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaShape_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaShape_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaShapeObject* self = (PyoaShapeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaShape)
    {
        PyParamoaShape p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaShape_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaShape, Choices are:\n"
        "    (oaShape)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaShape_tp_dealloc(PyoaShapeObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaShape_tp_repr(PyObject *ob)
{
    PyParamoaShape value;
    int convert_status=PyoaShape_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[29];
    sprintf(buffer,"<oaShape::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaShape_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaShape v1;
    PyParamoaShape v2;
    int convert_status1=PyoaShape_Convert(ob1,&v1);
    int convert_status2=PyoaShape_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaShape_Convert(PyObject* ob,PyParamoaShape* result)
{
    if (ob == NULL) return 1;
    if (PyoaShape_Check(ob)) {
        result->SetData( (oaShape**) ((PyoaShapeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaShape Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaShape_FromoaShape(oaShape** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaShape* data=*value;
        if (data->getType()==oacLineType) return PyoaLine_FromoaLine((oaLine**)value,borrow,lock);
        if (data->getType()==oacPathType) return PyoaPath_FromoaPath((oaPath**)value,borrow,lock);
        if (data->getType()==oacDonutType) return PyoaDonut_FromoaDonut((oaDonut**)value,borrow,lock);
        if (data->isTextDisplay()) return PyoaTextDisplay_FromoaTextDisplay((oaTextDisplay**)value,borrow,lock);
        if (data->getType()==oacRectType) return PyoaRect_FromoaRect((oaRect**)value,borrow,lock);
        if (data->getType()==oacPathSegType) return PyoaPathSeg_FromoaPathSeg((oaPathSeg**)value,borrow,lock);
        if (data->getType()==oacTextType) return PyoaText_FromoaText((oaText**)value,borrow,lock);
        if (data->getType()==oacArcType) return PyoaArc_FromoaArc((oaArc**)value,borrow,lock);
        if (data->getType()==oacEllipseType) return PyoaEllipse_FromoaEllipse((oaEllipse**)value,borrow,lock);
        if (data->getType()==oacPolygonType) return PyoaPolygon_FromoaPolygon((oaPolygon**)value,borrow,lock);
        if (data->getType()==oacEvalTextType) return PyoaEvalText_FromoaEvalText((oaEvalText**)value,borrow,lock);
        if (data->getType()==oacDotType) return PyoaDot_FromoaDot((oaDot**)value,borrow,lock);
        PyObject* bself = PyoaShape_Type.tp_alloc(&PyoaShape_Type,0);
        if (bself == NULL) return bself;
        PyoaShapeObject* self = (PyoaShapeObject*)bself;
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
PyObject* PyoaShape_FromoaShape(oaShape* data)
{
    if (data) {
        if (data->getType()==oacLineType) return PyoaLine_FromoaLine((oaLine*)data);
        if (data->getType()==oacPathType) return PyoaPath_FromoaPath((oaPath*)data);
        if (data->getType()==oacDonutType) return PyoaDonut_FromoaDonut((oaDonut*)data);
        if (data->isTextDisplay()) return PyoaTextDisplay_FromoaTextDisplay((oaTextDisplay*)data);
        if (data->getType()==oacRectType) return PyoaRect_FromoaRect((oaRect*)data);
        if (data->getType()==oacPathSegType) return PyoaPathSeg_FromoaPathSeg((oaPathSeg*)data);
        if (data->getType()==oacTextType) return PyoaText_FromoaText((oaText*)data);
        if (data->getType()==oacArcType) return PyoaArc_FromoaArc((oaArc*)data);
        if (data->getType()==oacEllipseType) return PyoaEllipse_FromoaEllipse((oaEllipse*)data);
        if (data->getType()==oacPolygonType) return PyoaPolygon_FromoaPolygon((oaPolygon*)data);
        if (data->getType()==oacEvalTextType) return PyoaEvalText_FromoaEvalText((oaEvalText*)data);
        if (data->getType()==oacDotType) return PyoaDot_FromoaDot((oaDot*)data);
       PyObject* bself = PyoaShape_Type.tp_alloc(&PyoaShape_Type,0);
       if (bself == NULL) return bself;
       PyoaShapeObject* self = (PyoaShapeObject*)bself;
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
static char oaShape_getConnRoutes_doc[] = 
"Class: oaShape, Function: getConnRoutes\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaRoute_oaShape getConnRoutes() const\n"
"    Signature: getConnRoutes|simple-oaCollection_oaRoute_oaShape|\n"
"    BrowseData: 1\n"
"    This function returns a collection of routes that are connected to this shape. Each route in the collection has this shape as either its startConn, endConn, or both.\n"
;

static PyObject*
oaShape_getConnRoutes(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeObject* self=(PyoaShapeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaRoute_oaShape* result= new oaCollection_oaRoute_oaShape(data.DataCall()->getConnRoutes());
        return PyoaCollection_oaRoute_oaShape_FromoaCollection_oaRoute_oaShape(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaShape_getConnRoutesIter_doc[] = 
"Class: oaShape, Function: getConnRoutesIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaRoute getConnRoutesIter() const\n"
"    Signature: getConnRoutesIter|simple-oaIter_oaRoute|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of routes that are connected to this shape. Each route in the collection has this shape as either its startConn, endConn, or both.\n"
;

static PyObject*
oaShape_getConnRoutesIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeObject* self=(PyoaShapeObject*)ob;
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
static char oaShape_getHeader_doc[] = 
"Class: oaShape, Function: getHeader\n"
"  Paramegers: ()\n"
"    Calls: oaLPPHeader* getHeader() const\n"
"    Signature: getHeader|ptr-oaLPPHeader|\n"
"    BrowseData: 1\n"
"    This function returns the layer/purpose pair header associated with this shape.\n"
"    oacInvalidShape\n"
;

static PyObject*
oaShape_getHeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeObject* self=(PyoaShapeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLPPHeaderp result= (data.DataCall()->getHeader());
        return PyoaLPPHeader_FromoaLPPHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaShape_getLayerNum_doc[] = 
"Class: oaShape, Function: getLayerNum\n"
"  Paramegers: ()\n"
"    Calls: oaLayerNum getLayerNum() const\n"
"    Signature: getLayerNum|simple-oaLayerNum|\n"
"    BrowseData: 1\n"
"    This function returns the layer number associated with this shape.\n"
"    oacInvalidShape\n"
;

static PyObject*
oaShape_getLayerNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeObject* self=(PyoaShapeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerNum result= (data.DataCall()->getLayerNum());
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
static char oaShape_getPurposeNum_doc[] = 
"Class: oaShape, Function: getPurposeNum\n"
"  Paramegers: ()\n"
"    Calls: oaPurposeNum getPurposeNum() const\n"
"    Signature: getPurposeNum|simple-oaPurposeNum|\n"
"    BrowseData: 1\n"
"    This function returns the purpose number associated with this shape.\n"
"    oacInvalidShape\n"
;

static PyObject*
oaShape_getPurposeNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeObject* self=(PyoaShapeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaPurposeNum result= (data.DataCall()->getPurposeNum());
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
static char oaShape_getRouteStatus_doc[] = 
"Class: oaShape, Function: getRouteStatus\n"
"  Paramegers: ()\n"
"    Calls: oaRouteStatus getRouteStatus() const\n"
"    Signature: getRouteStatus|simple-oaRouteStatus|\n"
"    BrowseData: 1\n"
"    This function returns the route status of this shape.\n"
"    oacInvalidShape\n"
;

static PyObject*
oaShape_getRouteStatus(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeObject* self=(PyoaShapeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaRouteStatus* result= new oaRouteStatus(data.DataCall()->getRouteStatus());
        return PyoaRouteStatus_FromoaRouteStatus(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaShape_getShieldedNet1_doc[] = 
"Class: oaShape, Function: getShieldedNet1\n"
"  Paramegers: ()\n"
"    Calls: oaBitNet* getShieldedNet1() const\n"
"    Signature: getShieldedNet1|ptr-oaBitNet|\n"
"    BrowseData: 1\n"
"    This function returns the first net that this shape is shielding. A shape may shield up to two nets.\n"
;

static PyObject*
oaShape_getShieldedNet1(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeObject* self=(PyoaShapeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBitNetp result= (data.DataCall()->getShieldedNet1());
        return PyoaBitNet_FromoaBitNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaShape_getShieldedNet2_doc[] = 
"Class: oaShape, Function: getShieldedNet2\n"
"  Paramegers: ()\n"
"    Calls: oaBitNet* getShieldedNet2() const\n"
"    Signature: getShieldedNet2|ptr-oaBitNet|\n"
"    BrowseData: 1\n"
"    This function returns the second net that this shape is shielding. A shape may shield up to two nets.\n"
;

static PyObject*
oaShape_getShieldedNet2(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeObject* self=(PyoaShapeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBitNetp result= (data.DataCall()->getShieldedNet2());
        return PyoaBitNet_FromoaBitNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaShape_isUnShielded_doc[] = 
"Class: oaShape, Function: isUnShielded\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isUnShielded() const\n"
"    Signature: isUnShielded|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if this shape is not shielded.\n"
;

static PyObject*
oaShape_isUnShielded(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeObject* self=(PyoaShapeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isUnShielded());
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
static char oaShape_setLPP_doc[] = 
"Class: oaShape, Function: setLPP\n"
"  Paramegers: (oaLayerNum,oaPurposeNum)\n"
"    Calls: void setLPP(oaLayerNum layerNum,oaPurposeNum purposeNum)\n"
"    Signature: setLPP|void-void|simple-oaLayerNum,simple-oaPurposeNum,\n"
"    This function moves this shape to the specified layer/purpose pair. The new layer/purpose pair is created if it does not exist. The old layer/purpose pair is deleted if it becomes empty.\n"
"    layerNum\n"
"    The layer number of the specified layer-purpose pair\n"
"    purposeNum\n"
"    The purpose number of the specified layer-purpose pair\n"
"    oacInvalidShape\n"
;

static PyObject*
oaShape_setLPP(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeObject* self=(PyoaShapeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaLayerNum p1;
    PyParamoaPurposeNum p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaLayerNum_Convert,&p1,
          &PyoaPurposeNum_Convert,&p2)) {
        data.DataCall()->setLPP(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaShape_setLayerNum_doc[] = 
"Class: oaShape, Function: setLayerNum\n"
"  Paramegers: (oaLayerNum)\n"
"    Calls: void setLayerNum(oaLayerNum layerNum)\n"
"    Signature: setLayerNum|void-void|simple-oaLayerNum,\n"
"    This function moves this shape to the specified layer number. The new layer/purpose pair is created if it does not exist. The old layer/purpose pair is deleted if it becomes empty.\n"
"    oacInvalidShape\n"
;

static PyObject*
oaShape_setLayerNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeObject* self=(PyoaShapeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaLayerNum p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLayerNum_Convert,&p1)) {
        data.DataCall()->setLayerNum(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaShape_setPurposeNum_doc[] = 
"Class: oaShape, Function: setPurposeNum\n"
"  Paramegers: (oaPurposeNum)\n"
"    Calls: void setPurposeNum(oaPurposeNum purposeNum)\n"
"    Signature: setPurposeNum|void-void|simple-oaPurposeNum,\n"
"    This function moves this shape to the specified purpose number. The new layer/purpose pair is created if it does not exist. The old layer/purpose pair is deleted if it becomes empty.\n"
"    oacInvalidShape\n"
;

static PyObject*
oaShape_setPurposeNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeObject* self=(PyoaShapeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPurposeNum p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPurposeNum_Convert,&p1)) {
        data.DataCall()->setPurposeNum(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaShape_setRouteStatus_doc[] = 
"Class: oaShape, Function: setRouteStatus\n"
"  Paramegers: (oaRouteStatus)\n"
"    Calls: void setRouteStatus(const oaRouteStatus& routeStatus)\n"
"    Signature: setRouteStatus|void-void|cref-oaRouteStatus,\n"
"    This function sets the route status attribute of this shape to the specified oaRouteStatus value.\n"
"    oacInvalidShape\n"
;

static PyObject*
oaShape_setRouteStatus(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeObject* self=(PyoaShapeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaRouteStatus p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaRouteStatus_Convert,&p1)) {
        data.DataCall()->setRouteStatus(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaShape_setShieldedNet1_doc[] = 
"Class: oaShape, Function: setShieldedNet1\n"
"  Paramegers: (oaBitNet)\n"
"    Calls: void setShieldedNet1(oaBitNet* net)\n"
"    Signature: setShieldedNet1|void-void|ptr-oaBitNet,\n"
"    This function sets the first shielded net for this shape to the specified bit net. A shape may shield up to two nets. A NULL pointer resets the attribute. Exceptions are thrown if the net is not in the same database as this shape.\n"
"    net\n"
"    Bit net that is shielded by this shape\n"
"    oacNetFigNotInSameBlock\n"
"    oacObjectAlreadyShieldsNet\n"
;

static PyObject*
oaShape_setShieldedNet1(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeObject* self=(PyoaShapeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBitNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBitNet_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setShieldedNet1(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaShape_setShieldedNet2_doc[] = 
"Class: oaShape, Function: setShieldedNet2\n"
"  Paramegers: (oaBitNet)\n"
"    Calls: void setShieldedNet2(oaBitNet* net)\n"
"    Signature: setShieldedNet2|void-void|ptr-oaBitNet,\n"
"    This function sets the second shielded net for this shape to the specified bit net. A shape may shield up to two nets. A NULL pointer resets the attribute. Exceptions are thrown if the net is not in the same database as this shape.\n"
"    net\n"
"    Bit net that is shielded by this shape\n"
"    oacNetFigNotInSameBlock\n"
"    oacObjectAlreadyShieldsNet\n"
;

static PyObject*
oaShape_setShieldedNet2(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeObject* self=(PyoaShapeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBitNet p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBitNet_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->setShieldedNet2(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaShape_setUnShielded_doc[] = 
"Class: oaShape, Function: setUnShielded\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: void setUnShielded(oaBoolean unShielded)\n"
"    Signature: setUnShielded|void-void|simple-oaBoolean,\n"
"    This function sets the unShielded attribute of this shape to the specified value.\n"
"    unShielded\n"
"    value\n"
;

static PyObject*
oaShape_setUnShielded(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeObject* self=(PyoaShapeObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBoolean p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBoolean_Convert,&p1)) {
        data.DataCall()->setUnShielded(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaShape_transform_doc[] = 
"Class: oaShape, Function: transform\n"
"  Paramegers: (oaDouble,oaDouble)\n"
"    Calls: void transform(oaDouble scale,oaDouble angle)\n"
"    Signature: transform|void-void|simple-oaDouble,simple-oaDouble,\n"
"    This function transforms this shape by the specified scale factor and rotation angle . The rotation angle is specified in radians. When the angle is not a multiple of Pi/2, rectangles are converted to polygons. PathSegs have a more specilized nature and can only be rotated by angles that are a multiple of Pi/2 to ensure that the orthogonal/diagonal nature of the pathSeg is preserved.\n"
"    For ellipses and arcs, the transform is applied to their control points, and for both, their control points are based upon the bounding box. When a non-90-degree transform is applied to a box, it is applied to each corner of the box. The bounding box from the resulting points is then applied to the ellipse or the arc.\n"
"    It is the caller's responsibility to scale and rotate instances.\n"
;

static PyObject*
oaShape_transform(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeObject* self=(PyoaShapeObject*)ob;
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
static char oaShape_isNull_doc[] =
"Class: oaShape, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaShape_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaShape data;
    int convert_status=PyoaShape_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaShape_assign_doc[] = 
"Class: oaShape, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaShape_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaShape data;
  int convert_status=PyoaShape_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaShape p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaShape_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaShape_methodlist[] = {
    {"getConnRoutes",(PyCFunction)oaShape_getConnRoutes,METH_VARARGS,oaShape_getConnRoutes_doc},
    {"getConnRoutesIter",(PyCFunction)oaShape_getConnRoutesIter,METH_VARARGS,oaShape_getConnRoutesIter_doc},
    {"getHeader",(PyCFunction)oaShape_getHeader,METH_VARARGS,oaShape_getHeader_doc},
    {"getLayerNum",(PyCFunction)oaShape_getLayerNum,METH_VARARGS,oaShape_getLayerNum_doc},
    {"getPurposeNum",(PyCFunction)oaShape_getPurposeNum,METH_VARARGS,oaShape_getPurposeNum_doc},
    {"getRouteStatus",(PyCFunction)oaShape_getRouteStatus,METH_VARARGS,oaShape_getRouteStatus_doc},
    {"getShieldedNet1",(PyCFunction)oaShape_getShieldedNet1,METH_VARARGS,oaShape_getShieldedNet1_doc},
    {"getShieldedNet2",(PyCFunction)oaShape_getShieldedNet2,METH_VARARGS,oaShape_getShieldedNet2_doc},
    {"isUnShielded",(PyCFunction)oaShape_isUnShielded,METH_VARARGS,oaShape_isUnShielded_doc},
    {"setLPP",(PyCFunction)oaShape_setLPP,METH_VARARGS,oaShape_setLPP_doc},
    {"setLayerNum",(PyCFunction)oaShape_setLayerNum,METH_VARARGS,oaShape_setLayerNum_doc},
    {"setPurposeNum",(PyCFunction)oaShape_setPurposeNum,METH_VARARGS,oaShape_setPurposeNum_doc},
    {"setRouteStatus",(PyCFunction)oaShape_setRouteStatus,METH_VARARGS,oaShape_setRouteStatus_doc},
    {"setShieldedNet1",(PyCFunction)oaShape_setShieldedNet1,METH_VARARGS,oaShape_setShieldedNet1_doc},
    {"setShieldedNet2",(PyCFunction)oaShape_setShieldedNet2,METH_VARARGS,oaShape_setShieldedNet2_doc},
    {"setUnShielded",(PyCFunction)oaShape_setUnShielded,METH_VARARGS,oaShape_setUnShielded_doc},
    {"transform",(PyCFunction)oaShape_transform,METH_VARARGS,oaShape_transform_doc},
    {"isNull",(PyCFunction)oaShape_tp_isNull,METH_VARARGS,oaShape_isNull_doc},
    {"assign",(PyCFunction)oaShape_tp_assign,METH_VARARGS,oaShape_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaShape_doc[] = 
"Class: oaShape\n"
"  The oaShape class is an abstract base for classes that define specific geometry at specific locations in a design. Together with routes, shapes specify all the manufacturable geometry in a chip layout. Shapes can also be used for more abstract purposes. The Text shape classes provide viewable labels on design objects.\n"
"  All shapes are placed on an oaLayer and an oaPurpose . The design API identifies these by the layer and purpose numbers. The corresponding names are found in the technology database.\n"
"  Optionally, shapes can also belong to either an oaNet or an oaPin to provide part of the physical implementation of that object.\n"
"  The oaShape class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaShape)\n"
"    Calls: (const oaShape&)\n"
"    Signature: oaShape||cref-oaShape,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaShape_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaShape",
    sizeof(PyoaShapeObject),
    0,
    (destructor)oaShape_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaShape_tp_compare,	/* tp_compare */
    (reprfunc)oaShape_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaShape_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaShape_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaPinFig_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaShape_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaShape_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaShape_Type)<0) {
      printf("** PyType_Ready failed for: oaShape\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaShape",
           (PyObject*)(&PyoaShape_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaShape\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaShapeModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaShapeModTypeEnum_Convert(PyObject* ob,PyParamoaShapeModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSetLPPShapeModType")==0) { result->SetData(oacSetLPPShapeModType); return 1;}
        if (strcasecmp(str,"oacSetLayerNumShapeModType")==0) { result->SetData(oacSetLayerNumShapeModType); return 1;}
        if (strcasecmp(str,"oacSetPurposeNumShapeModType")==0) { result->SetData(oacSetPurposeNumShapeModType); return 1;}
        if (strcasecmp(str,"oacSetRouteStatusShapeModType")==0) { result->SetData(oacSetRouteStatusShapeModType); return 1;}
        if (strcasecmp(str,"oacAddToNetShapeModType")==0) { result->SetData(oacAddToNetShapeModType); return 1;}
        if (strcasecmp(str,"oacRemoveFromNetShapeModType")==0) { result->SetData(oacRemoveFromNetShapeModType); return 1;}
        if (strcasecmp(str,"oacAddToPinShapeModType")==0) { result->SetData(oacAddToPinShapeModType); return 1;}
        if (strcasecmp(str,"oacRemoveFromPinShapeModType")==0) { result->SetData(oacRemoveFromPinShapeModType); return 1;}
        if (strcasecmp(str,"oacSetShieldedNet1ShapeModType")==0) { result->SetData(oacSetShieldedNet1ShapeModType); return 1;}
        if (strcasecmp(str,"oacSetShieldedNet2ShapeModType")==0) { result->SetData(oacSetShieldedNet2ShapeModType); return 1;}
        if (strcasecmp(str,"oacSetUnShieldedShapeModType")==0) { result->SetData(oacSetUnShieldedShapeModType); return 1;}
        if (strcasecmp(str,"oacArcSetShapeModType")==0) { result->SetData(oacArcSetShapeModType); return 1;}
        if (strcasecmp(str,"oacArcConvertToLineShapeModType")==0) { result->SetData(oacArcConvertToLineShapeModType); return 1;}
        if (strcasecmp(str,"oacArcTransformShapeModType")==0) { result->SetData(oacArcTransformShapeModType); return 1;}
        if (strcasecmp(str,"oacDonutSetCenterShapeModType")==0) { result->SetData(oacDonutSetCenterShapeModType); return 1;}
        if (strcasecmp(str,"oacDonutSetRadiusShapeModType")==0) { result->SetData(oacDonutSetRadiusShapeModType); return 1;}
        if (strcasecmp(str,"oacDonutSetHoleRadiusShapeModType")==0) { result->SetData(oacDonutSetHoleRadiusShapeModType); return 1;}
        if (strcasecmp(str,"oacDonutSetRadiiShapeModType")==0) { result->SetData(oacDonutSetRadiiShapeModType); return 1;}
        if (strcasecmp(str,"oacDonutConvertToPolygonShapeModType")==0) { result->SetData(oacDonutConvertToPolygonShapeModType); return 1;}
        if (strcasecmp(str,"oacDonutTransformShapeModType")==0) { result->SetData(oacDonutTransformShapeModType); return 1;}
        if (strcasecmp(str,"oacDotSetLocationShapeModType")==0) { result->SetData(oacDotSetLocationShapeModType); return 1;}
        if (strcasecmp(str,"oacDotSetWidthShapeModType")==0) { result->SetData(oacDotSetWidthShapeModType); return 1;}
        if (strcasecmp(str,"oacDotSetHeightShapeModType")==0) { result->SetData(oacDotSetHeightShapeModType); return 1;}
        if (strcasecmp(str,"oacDotTransformShapeModType")==0) { result->SetData(oacDotTransformShapeModType); return 1;}
        if (strcasecmp(str,"oacEllipseSetBBoxShapeModType")==0) { result->SetData(oacEllipseSetBBoxShapeModType); return 1;}
        if (strcasecmp(str,"oacEllipseConvertToPolygonShapeModType")==0) { result->SetData(oacEllipseConvertToPolygonShapeModType); return 1;}
        if (strcasecmp(str,"oacEllipseLocationShapeModType")==0) { result->SetData(oacEllipseLocationShapeModType); return 1;}
        if (strcasecmp(str,"oacLineSetPointsShapeModType")==0) { result->SetData(oacLineSetPointsShapeModType); return 1;}
        if (strcasecmp(str,"oacLineConvertToArcShapeModType")==0) { result->SetData(oacLineConvertToArcShapeModType); return 1;}
        if (strcasecmp(str,"oacPathSetWidthShapeModType")==0) { result->SetData(oacPathSetWidthShapeModType); return 1;}
        if (strcasecmp(str,"oacPathSetPointsShapeModType")==0) { result->SetData(oacPathSetPointsShapeModType); return 1;}
        if (strcasecmp(str,"oacPathSetStyleShapeModType")==0) { result->SetData(oacPathSetStyleShapeModType); return 1;}
        if (strcasecmp(str,"oacPathSetBeginExtShapeModType")==0) { result->SetData(oacPathSetBeginExtShapeModType); return 1;}
        if (strcasecmp(str,"oacPathSetEndExtShapeModType")==0) { result->SetData(oacPathSetEndExtShapeModType); return 1;}
        if (strcasecmp(str,"oacPathConvertToPolygonShapeModType")==0) { result->SetData(oacPathConvertToPolygonShapeModType); return 1;}
        if (strcasecmp(str,"oacPathTransformShapeModType")==0) { result->SetData(oacPathTransformShapeModType); return 1;}
        if (strcasecmp(str,"oacPathSetAllShapeModType")==0) { result->SetData(oacPathSetAllShapeModType); return 1;}
        if (strcasecmp(str,"oacPolygonSetPointsShapeModType")==0) { result->SetData(oacPolygonSetPointsShapeModType); return 1;}
        if (strcasecmp(str,"oacPolygonConvertToDonutShapeModType")==0) { result->SetData(oacPolygonConvertToDonutShapeModType); return 1;}
        if (strcasecmp(str,"oacPolygonConvertToEllipseShapeModType")==0) { result->SetData(oacPolygonConvertToEllipseShapeModType); return 1;}
        if (strcasecmp(str,"oacPolygonConvertToPathShapeModType")==0) { result->SetData(oacPolygonConvertToPathShapeModType); return 1;}
        if (strcasecmp(str,"oacPolygonConvertToRectShapeModType")==0) { result->SetData(oacPolygonConvertToRectShapeModType); return 1;}
        if (strcasecmp(str,"oacPolygonTransformToRectShapeModType")==0) { result->SetData(oacPolygonTransformToRectShapeModType); return 1;}
        if (strcasecmp(str,"oacRectSetBBoxShapeModType")==0) { result->SetData(oacRectSetBBoxShapeModType); return 1;}
        if (strcasecmp(str,"oacRectConvertToPolygonShapeModType")==0) { result->SetData(oacRectConvertToPolygonShapeModType); return 1;}
        if (strcasecmp(str,"oacRectTransformToPolygonShapeModType")==0) { result->SetData(oacRectTransformToPolygonShapeModType); return 1;}
        if (strcasecmp(str,"oacTextDisplayInvalidateShapeModType")==0) { result->SetData(oacTextDisplayInvalidateShapeModType); return 1;}
        if (strcasecmp(str,"oacTextDisplaySetOriginShapeModType")==0) { result->SetData(oacTextDisplaySetOriginShapeModType); return 1;}
        if (strcasecmp(str,"oacTextDisplaySetAlignmentShapeModType")==0) { result->SetData(oacTextDisplaySetAlignmentShapeModType); return 1;}
        if (strcasecmp(str,"oacTextDisplaySetOrientShapeModType")==0) { result->SetData(oacTextDisplaySetOrientShapeModType); return 1;}
        if (strcasecmp(str,"oacTextDisplaySetTransformShapeModType")==0) { result->SetData(oacTextDisplaySetTransformShapeModType); return 1;}
        if (strcasecmp(str,"oacTextDisplaySetFontShapeModType")==0) { result->SetData(oacTextDisplaySetFontShapeModType); return 1;}
        if (strcasecmp(str,"oacTextDisplaySetHeightShapeModType")==0) { result->SetData(oacTextDisplaySetHeightShapeModType); return 1;}
        if (strcasecmp(str,"oacTextDisplaySetFormatShapeModType")==0) { result->SetData(oacTextDisplaySetFormatShapeModType); return 1;}
        if (strcasecmp(str,"oacTextDisplaySetInterfaceShapeModType")==0) { result->SetData(oacTextDisplaySetInterfaceShapeModType); return 1;}
        if (strcasecmp(str,"oacTextDisplaySetOverbarShapeModType")==0) { result->SetData(oacTextDisplaySetOverbarShapeModType); return 1;}
        if (strcasecmp(str,"oacTextDisplaySetVisibleShapeModType")==0) { result->SetData(oacTextDisplaySetVisibleShapeModType); return 1;}
        if (strcasecmp(str,"oacTextDisplaySetDraftingShapeModType")==0) { result->SetData(oacTextDisplaySetDraftingShapeModType); return 1;}
        if (strcasecmp(str,"oacTextDisplayTransformShapeModType")==0) { result->SetData(oacTextDisplayTransformShapeModType); return 1;}
        if (strcasecmp(str,"oacTextDisplaySetAllShapeModType")==0) { result->SetData(oacTextDisplaySetAllShapeModType); return 1;}
        if (strcasecmp(str,"oacPropDisplaySetPropShapeModType")==0) { result->SetData(oacPropDisplaySetPropShapeModType); return 1;}
        if (strcasecmp(str,"oacTextSetOriginShapeModType")==0) { result->SetData(oacTextSetOriginShapeModType); return 1;}
        if (strcasecmp(str,"oacTextSetTextShapeModType")==0) { result->SetData(oacTextSetTextShapeModType); return 1;}
        if (strcasecmp(str,"oacTextSetAlignmentShapeModType")==0) { result->SetData(oacTextSetAlignmentShapeModType); return 1;}
        if (strcasecmp(str,"oacTextSetOrientShapeModType")==0) { result->SetData(oacTextSetOrientShapeModType); return 1;}
        if (strcasecmp(str,"oacTextSetTransformShapeModType")==0) { result->SetData(oacTextSetTransformShapeModType); return 1;}
        if (strcasecmp(str,"oacTextSetFontShapeModType")==0) { result->SetData(oacTextSetFontShapeModType); return 1;}
        if (strcasecmp(str,"oacTextSetHeightShapeModType")==0) { result->SetData(oacTextSetHeightShapeModType); return 1;}
        if (strcasecmp(str,"oacTextSetEvalTextLinkShapeModType")==0) { result->SetData(oacTextSetEvalTextLinkShapeModType); return 1;}
        if (strcasecmp(str,"oacTextSetOverbarShapeModType")==0) { result->SetData(oacTextSetOverbarShapeModType); return 1;}
        if (strcasecmp(str,"oacTextSetVisibleShapeModType")==0) { result->SetData(oacTextSetVisibleShapeModType); return 1;}
        if (strcasecmp(str,"oacTextSetDraftingShapeModType")==0) { result->SetData(oacTextSetDraftingShapeModType); return 1;}
        if (strcasecmp(str,"oacTextTransformShapeModType")==0) { result->SetData(oacTextTransformShapeModType); return 1;}
        if (strcasecmp(str,"oacTextSetAllShapeModType")==0) { result->SetData(oacTextSetAllShapeModType); return 1;}
        if (strcasecmp(str,"oacAttrDisplaySetObjectModType")==0) { result->SetData(oacAttrDisplaySetObjectModType); return 1;}
        if (strcasecmp(str,"oacPathSegSetWidthShapeModType")==0) { result->SetData(oacPathSegSetWidthShapeModType); return 1;}
        if (strcasecmp(str,"oacPathSegSetPointsShapeModType")==0) { result->SetData(oacPathSegSetPointsShapeModType); return 1;}
        if (strcasecmp(str,"oacPathSegSetStyleShapeModType")==0) { result->SetData(oacPathSegSetStyleShapeModType); return 1;}
        if (strcasecmp(str,"oacPathSegTransformShapeModType")==0) { result->SetData(oacPathSegTransformShapeModType); return 1;}
        if (strcasecmp(str,"oacPathSegSetAllShapeModType")==0) { result->SetData(oacPathSegSetAllShapeModType); return 1;}
        if (strcasecmp(str,"oacPathSegSetRouteTopologyShapeModType")==0) { result->SetData(oacPathSegSetRouteTopologyShapeModType); return 1;}
        if (strcasecmp(str,"oacAddToFigGroupShapeModType")==0) { result->SetData(oacAddToFigGroupShapeModType); return 1;}
        if (strcasecmp(str,"oacRemoveFromFigGroupShapeModType")==0) { result->SetData(oacRemoveFromFigGroupShapeModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaShapeModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaShapeModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(oaShapeModTypeEnum ob)
{
    if (ob==oacSetLPPShapeModType) return PyString_FromString("oacSetLPPShapeModType");
    if (ob==oacSetLayerNumShapeModType) return PyString_FromString("oacSetLayerNumShapeModType");
    if (ob==oacSetPurposeNumShapeModType) return PyString_FromString("oacSetPurposeNumShapeModType");
    if (ob==oacSetRouteStatusShapeModType) return PyString_FromString("oacSetRouteStatusShapeModType");
    if (ob==oacAddToNetShapeModType) return PyString_FromString("oacAddToNetShapeModType");
    if (ob==oacRemoveFromNetShapeModType) return PyString_FromString("oacRemoveFromNetShapeModType");
    if (ob==oacAddToPinShapeModType) return PyString_FromString("oacAddToPinShapeModType");
    if (ob==oacRemoveFromPinShapeModType) return PyString_FromString("oacRemoveFromPinShapeModType");
    if (ob==oacSetShieldedNet1ShapeModType) return PyString_FromString("oacSetShieldedNet1ShapeModType");
    if (ob==oacSetShieldedNet2ShapeModType) return PyString_FromString("oacSetShieldedNet2ShapeModType");
    if (ob==oacSetUnShieldedShapeModType) return PyString_FromString("oacSetUnShieldedShapeModType");
    if (ob==oacArcSetShapeModType) return PyString_FromString("oacArcSetShapeModType");
    if (ob==oacArcConvertToLineShapeModType) return PyString_FromString("oacArcConvertToLineShapeModType");
    if (ob==oacArcTransformShapeModType) return PyString_FromString("oacArcTransformShapeModType");
    if (ob==oacDonutSetCenterShapeModType) return PyString_FromString("oacDonutSetCenterShapeModType");
    if (ob==oacDonutSetRadiusShapeModType) return PyString_FromString("oacDonutSetRadiusShapeModType");
    if (ob==oacDonutSetHoleRadiusShapeModType) return PyString_FromString("oacDonutSetHoleRadiusShapeModType");
    if (ob==oacDonutSetRadiiShapeModType) return PyString_FromString("oacDonutSetRadiiShapeModType");
    if (ob==oacDonutConvertToPolygonShapeModType) return PyString_FromString("oacDonutConvertToPolygonShapeModType");
    if (ob==oacDonutTransformShapeModType) return PyString_FromString("oacDonutTransformShapeModType");
    if (ob==oacDotSetLocationShapeModType) return PyString_FromString("oacDotSetLocationShapeModType");
    if (ob==oacDotSetWidthShapeModType) return PyString_FromString("oacDotSetWidthShapeModType");
    if (ob==oacDotSetHeightShapeModType) return PyString_FromString("oacDotSetHeightShapeModType");
    if (ob==oacDotTransformShapeModType) return PyString_FromString("oacDotTransformShapeModType");
    if (ob==oacEllipseSetBBoxShapeModType) return PyString_FromString("oacEllipseSetBBoxShapeModType");
    if (ob==oacEllipseConvertToPolygonShapeModType) return PyString_FromString("oacEllipseConvertToPolygonShapeModType");
    if (ob==oacEllipseLocationShapeModType) return PyString_FromString("oacEllipseLocationShapeModType");
    if (ob==oacLineSetPointsShapeModType) return PyString_FromString("oacLineSetPointsShapeModType");
    if (ob==oacLineConvertToArcShapeModType) return PyString_FromString("oacLineConvertToArcShapeModType");
    if (ob==oacPathSetWidthShapeModType) return PyString_FromString("oacPathSetWidthShapeModType");
    if (ob==oacPathSetPointsShapeModType) return PyString_FromString("oacPathSetPointsShapeModType");
    if (ob==oacPathSetStyleShapeModType) return PyString_FromString("oacPathSetStyleShapeModType");
    if (ob==oacPathSetBeginExtShapeModType) return PyString_FromString("oacPathSetBeginExtShapeModType");
    if (ob==oacPathSetEndExtShapeModType) return PyString_FromString("oacPathSetEndExtShapeModType");
    if (ob==oacPathConvertToPolygonShapeModType) return PyString_FromString("oacPathConvertToPolygonShapeModType");
    if (ob==oacPathTransformShapeModType) return PyString_FromString("oacPathTransformShapeModType");
    if (ob==oacPathSetAllShapeModType) return PyString_FromString("oacPathSetAllShapeModType");
    if (ob==oacPolygonSetPointsShapeModType) return PyString_FromString("oacPolygonSetPointsShapeModType");
    if (ob==oacPolygonConvertToDonutShapeModType) return PyString_FromString("oacPolygonConvertToDonutShapeModType");
    if (ob==oacPolygonConvertToEllipseShapeModType) return PyString_FromString("oacPolygonConvertToEllipseShapeModType");
    if (ob==oacPolygonConvertToPathShapeModType) return PyString_FromString("oacPolygonConvertToPathShapeModType");
    if (ob==oacPolygonConvertToRectShapeModType) return PyString_FromString("oacPolygonConvertToRectShapeModType");
    if (ob==oacPolygonTransformToRectShapeModType) return PyString_FromString("oacPolygonTransformToRectShapeModType");
    if (ob==oacRectSetBBoxShapeModType) return PyString_FromString("oacRectSetBBoxShapeModType");
    if (ob==oacRectConvertToPolygonShapeModType) return PyString_FromString("oacRectConvertToPolygonShapeModType");
    if (ob==oacRectTransformToPolygonShapeModType) return PyString_FromString("oacRectTransformToPolygonShapeModType");
    if (ob==oacTextDisplayInvalidateShapeModType) return PyString_FromString("oacTextDisplayInvalidateShapeModType");
    if (ob==oacTextDisplaySetOriginShapeModType) return PyString_FromString("oacTextDisplaySetOriginShapeModType");
    if (ob==oacTextDisplaySetAlignmentShapeModType) return PyString_FromString("oacTextDisplaySetAlignmentShapeModType");
    if (ob==oacTextDisplaySetOrientShapeModType) return PyString_FromString("oacTextDisplaySetOrientShapeModType");
    if (ob==oacTextDisplaySetTransformShapeModType) return PyString_FromString("oacTextDisplaySetTransformShapeModType");
    if (ob==oacTextDisplaySetFontShapeModType) return PyString_FromString("oacTextDisplaySetFontShapeModType");
    if (ob==oacTextDisplaySetHeightShapeModType) return PyString_FromString("oacTextDisplaySetHeightShapeModType");
    if (ob==oacTextDisplaySetFormatShapeModType) return PyString_FromString("oacTextDisplaySetFormatShapeModType");
    if (ob==oacTextDisplaySetInterfaceShapeModType) return PyString_FromString("oacTextDisplaySetInterfaceShapeModType");
    if (ob==oacTextDisplaySetOverbarShapeModType) return PyString_FromString("oacTextDisplaySetOverbarShapeModType");
    if (ob==oacTextDisplaySetVisibleShapeModType) return PyString_FromString("oacTextDisplaySetVisibleShapeModType");
    if (ob==oacTextDisplaySetDraftingShapeModType) return PyString_FromString("oacTextDisplaySetDraftingShapeModType");
    if (ob==oacTextDisplayTransformShapeModType) return PyString_FromString("oacTextDisplayTransformShapeModType");
    if (ob==oacTextDisplaySetAllShapeModType) return PyString_FromString("oacTextDisplaySetAllShapeModType");
    if (ob==oacPropDisplaySetPropShapeModType) return PyString_FromString("oacPropDisplaySetPropShapeModType");
    if (ob==oacTextSetOriginShapeModType) return PyString_FromString("oacTextSetOriginShapeModType");
    if (ob==oacTextSetTextShapeModType) return PyString_FromString("oacTextSetTextShapeModType");
    if (ob==oacTextSetAlignmentShapeModType) return PyString_FromString("oacTextSetAlignmentShapeModType");
    if (ob==oacTextSetOrientShapeModType) return PyString_FromString("oacTextSetOrientShapeModType");
    if (ob==oacTextSetTransformShapeModType) return PyString_FromString("oacTextSetTransformShapeModType");
    if (ob==oacTextSetFontShapeModType) return PyString_FromString("oacTextSetFontShapeModType");
    if (ob==oacTextSetHeightShapeModType) return PyString_FromString("oacTextSetHeightShapeModType");
    if (ob==oacTextSetEvalTextLinkShapeModType) return PyString_FromString("oacTextSetEvalTextLinkShapeModType");
    if (ob==oacTextSetOverbarShapeModType) return PyString_FromString("oacTextSetOverbarShapeModType");
    if (ob==oacTextSetVisibleShapeModType) return PyString_FromString("oacTextSetVisibleShapeModType");
    if (ob==oacTextSetDraftingShapeModType) return PyString_FromString("oacTextSetDraftingShapeModType");
    if (ob==oacTextTransformShapeModType) return PyString_FromString("oacTextTransformShapeModType");
    if (ob==oacTextSetAllShapeModType) return PyString_FromString("oacTextSetAllShapeModType");
    if (ob==oacAttrDisplaySetObjectModType) return PyString_FromString("oacAttrDisplaySetObjectModType");
    if (ob==oacPathSegSetWidthShapeModType) return PyString_FromString("oacPathSegSetWidthShapeModType");
    if (ob==oacPathSegSetPointsShapeModType) return PyString_FromString("oacPathSegSetPointsShapeModType");
    if (ob==oacPathSegSetStyleShapeModType) return PyString_FromString("oacPathSegSetStyleShapeModType");
    if (ob==oacPathSegTransformShapeModType) return PyString_FromString("oacPathSegTransformShapeModType");
    if (ob==oacPathSegSetAllShapeModType) return PyString_FromString("oacPathSegSetAllShapeModType");
    if (ob==oacPathSegSetRouteTopologyShapeModType) return PyString_FromString("oacPathSegSetRouteTopologyShapeModType");
    if (ob==oacAddToFigGroupShapeModType) return PyString_FromString("oacAddToFigGroupShapeModType");
    if (ob==oacRemoveFromFigGroupShapeModType) return PyString_FromString("oacRemoveFromFigGroupShapeModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaShapeModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaShapeModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(oaShapeModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaShapeModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaShapeModTypeEnum_doc[] =
"Type convert function for enum: oaShapeModTypeEnum";
                               
static PyMethodDef PyoaShapeModTypeEnum_method =
  {"oaShapeModTypeEnum",(PyCFunction)PyoaShapeModTypeEnum_TypeFunction,METH_VARARGS,oaShapeModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaShapeModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSetLPPShapeModType");
    PyDict_SetItemString(mod_dict,"oacSetLPPShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetLayerNumShapeModType");
    PyDict_SetItemString(mod_dict,"oacSetLayerNumShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetPurposeNumShapeModType");
    PyDict_SetItemString(mod_dict,"oacSetPurposeNumShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetRouteStatusShapeModType");
    PyDict_SetItemString(mod_dict,"oacSetRouteStatusShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAddToNetShapeModType");
    PyDict_SetItemString(mod_dict,"oacAddToNetShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRemoveFromNetShapeModType");
    PyDict_SetItemString(mod_dict,"oacRemoveFromNetShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAddToPinShapeModType");
    PyDict_SetItemString(mod_dict,"oacAddToPinShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRemoveFromPinShapeModType");
    PyDict_SetItemString(mod_dict,"oacRemoveFromPinShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetShieldedNet1ShapeModType");
    PyDict_SetItemString(mod_dict,"oacSetShieldedNet1ShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetShieldedNet2ShapeModType");
    PyDict_SetItemString(mod_dict,"oacSetShieldedNet2ShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacSetUnShieldedShapeModType");
    PyDict_SetItemString(mod_dict,"oacSetUnShieldedShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacArcSetShapeModType");
    PyDict_SetItemString(mod_dict,"oacArcSetShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacArcConvertToLineShapeModType");
    PyDict_SetItemString(mod_dict,"oacArcConvertToLineShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacArcTransformShapeModType");
    PyDict_SetItemString(mod_dict,"oacArcTransformShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDonutSetCenterShapeModType");
    PyDict_SetItemString(mod_dict,"oacDonutSetCenterShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDonutSetRadiusShapeModType");
    PyDict_SetItemString(mod_dict,"oacDonutSetRadiusShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDonutSetHoleRadiusShapeModType");
    PyDict_SetItemString(mod_dict,"oacDonutSetHoleRadiusShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDonutSetRadiiShapeModType");
    PyDict_SetItemString(mod_dict,"oacDonutSetRadiiShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDonutConvertToPolygonShapeModType");
    PyDict_SetItemString(mod_dict,"oacDonutConvertToPolygonShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDonutTransformShapeModType");
    PyDict_SetItemString(mod_dict,"oacDonutTransformShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDotSetLocationShapeModType");
    PyDict_SetItemString(mod_dict,"oacDotSetLocationShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDotSetWidthShapeModType");
    PyDict_SetItemString(mod_dict,"oacDotSetWidthShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDotSetHeightShapeModType");
    PyDict_SetItemString(mod_dict,"oacDotSetHeightShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDotTransformShapeModType");
    PyDict_SetItemString(mod_dict,"oacDotTransformShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacEllipseSetBBoxShapeModType");
    PyDict_SetItemString(mod_dict,"oacEllipseSetBBoxShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacEllipseConvertToPolygonShapeModType");
    PyDict_SetItemString(mod_dict,"oacEllipseConvertToPolygonShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacEllipseLocationShapeModType");
    PyDict_SetItemString(mod_dict,"oacEllipseLocationShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLineSetPointsShapeModType");
    PyDict_SetItemString(mod_dict,"oacLineSetPointsShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacLineConvertToArcShapeModType");
    PyDict_SetItemString(mod_dict,"oacLineConvertToArcShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPathSetWidthShapeModType");
    PyDict_SetItemString(mod_dict,"oacPathSetWidthShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPathSetPointsShapeModType");
    PyDict_SetItemString(mod_dict,"oacPathSetPointsShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPathSetStyleShapeModType");
    PyDict_SetItemString(mod_dict,"oacPathSetStyleShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPathSetBeginExtShapeModType");
    PyDict_SetItemString(mod_dict,"oacPathSetBeginExtShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPathSetEndExtShapeModType");
    PyDict_SetItemString(mod_dict,"oacPathSetEndExtShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPathConvertToPolygonShapeModType");
    PyDict_SetItemString(mod_dict,"oacPathConvertToPolygonShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPathTransformShapeModType");
    PyDict_SetItemString(mod_dict,"oacPathTransformShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPathSetAllShapeModType");
    PyDict_SetItemString(mod_dict,"oacPathSetAllShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPolygonSetPointsShapeModType");
    PyDict_SetItemString(mod_dict,"oacPolygonSetPointsShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPolygonConvertToDonutShapeModType");
    PyDict_SetItemString(mod_dict,"oacPolygonConvertToDonutShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPolygonConvertToEllipseShapeModType");
    PyDict_SetItemString(mod_dict,"oacPolygonConvertToEllipseShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPolygonConvertToPathShapeModType");
    PyDict_SetItemString(mod_dict,"oacPolygonConvertToPathShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPolygonConvertToRectShapeModType");
    PyDict_SetItemString(mod_dict,"oacPolygonConvertToRectShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPolygonTransformToRectShapeModType");
    PyDict_SetItemString(mod_dict,"oacPolygonTransformToRectShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRectSetBBoxShapeModType");
    PyDict_SetItemString(mod_dict,"oacRectSetBBoxShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRectConvertToPolygonShapeModType");
    PyDict_SetItemString(mod_dict,"oacRectConvertToPolygonShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRectTransformToPolygonShapeModType");
    PyDict_SetItemString(mod_dict,"oacRectTransformToPolygonShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextDisplayInvalidateShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextDisplayInvalidateShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextDisplaySetOriginShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextDisplaySetOriginShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextDisplaySetAlignmentShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextDisplaySetAlignmentShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextDisplaySetOrientShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextDisplaySetOrientShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextDisplaySetTransformShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextDisplaySetTransformShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextDisplaySetFontShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextDisplaySetFontShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextDisplaySetHeightShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextDisplaySetHeightShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextDisplaySetFormatShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextDisplaySetFormatShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextDisplaySetInterfaceShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextDisplaySetInterfaceShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextDisplaySetOverbarShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextDisplaySetOverbarShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextDisplaySetVisibleShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextDisplaySetVisibleShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextDisplaySetDraftingShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextDisplaySetDraftingShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextDisplayTransformShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextDisplayTransformShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextDisplaySetAllShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextDisplaySetAllShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPropDisplaySetPropShapeModType");
    PyDict_SetItemString(mod_dict,"oacPropDisplaySetPropShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextSetOriginShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextSetOriginShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextSetTextShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextSetTextShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextSetAlignmentShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextSetAlignmentShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextSetOrientShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextSetOrientShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextSetTransformShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextSetTransformShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextSetFontShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextSetFontShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextSetHeightShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextSetHeightShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextSetEvalTextLinkShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextSetEvalTextLinkShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextSetOverbarShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextSetOverbarShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextSetVisibleShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextSetVisibleShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextSetDraftingShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextSetDraftingShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextTransformShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextTransformShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTextSetAllShapeModType");
    PyDict_SetItemString(mod_dict,"oacTextSetAllShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAttrDisplaySetObjectModType");
    PyDict_SetItemString(mod_dict,"oacAttrDisplaySetObjectModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPathSegSetWidthShapeModType");
    PyDict_SetItemString(mod_dict,"oacPathSegSetWidthShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPathSegSetPointsShapeModType");
    PyDict_SetItemString(mod_dict,"oacPathSegSetPointsShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPathSegSetStyleShapeModType");
    PyDict_SetItemString(mod_dict,"oacPathSegSetStyleShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPathSegTransformShapeModType");
    PyDict_SetItemString(mod_dict,"oacPathSegTransformShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPathSegSetAllShapeModType");
    PyDict_SetItemString(mod_dict,"oacPathSegSetAllShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPathSegSetRouteTopologyShapeModType");
    PyDict_SetItemString(mod_dict,"oacPathSegSetRouteTopologyShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAddToFigGroupShapeModType");
    PyDict_SetItemString(mod_dict,"oacAddToFigGroupShapeModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacRemoveFromFigGroupShapeModType");
    PyDict_SetItemString(mod_dict,"oacRemoveFromFigGroupShapeModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaShapeModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaShapeModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaShapeModTypeEnum\n");
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
// Wrapper Implementation for Class: oaShapeQuery
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaShapeQuery_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaShapeQuery_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaShapeQueryObject* self = (PyoaShapeQueryObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    if (is_raw) {
        PyErr_SetString(PyExc_TypeError,
            "No Constructor for pure-virtual class: oaShapeQuery");
    }
    else {
        pyv_oaShapeQuery* p = new pyv_oaShapeQuery();
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
oaShapeQuery_tp_dealloc(PyoaShapeQueryObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaShapeQuery_tp_repr(PyObject *ob)
{
    PyParamoaShapeQuery value;
    int convert_status=PyoaShapeQuery_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[34];
    sprintf(buffer,"<oaShapeQuery::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaShapeQuery_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaShapeQuery v1;
    PyParamoaShapeQuery v2;
    int convert_status1=PyoaShapeQuery_Convert(ob1,&v1);
    int convert_status2=PyoaShapeQuery_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaShapeQuery_Convert(PyObject* ob,PyParamoaShapeQuery* result)
{
    if (ob == NULL) return 1;
    if (PyoaShapeQuery_Check(ob)) {
        result->SetData( (oaShapeQuery*) ((PyoaShapeQueryObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaShapeQuery Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaShapeQuery_FromoaShapeQuery(oaShapeQuery* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaShapeQuery_Type.tp_alloc(&PyoaShapeQuery_Type,0);
        if (bself == NULL) return bself;
        PyoaShapeQueryObject* self = (PyoaShapeQueryObject*)bself;
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
pyv_oaShapeQuery::pyv_oaShapeQuery()
 : pyob(NULL),
   oaShapeQuery()
{
}

// ------------------------------------------------------------------
pyv_oaShapeQuery::pyv_oaShapeQuery(const oaShapeQuery& p)
 : pyob(NULL),
   oaShapeQuery(p)
{
}

// ------------------------------------------------------------------
void pyv_oaShapeQuery::queryShape(oaShape* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"queryShape");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaShapeQuery::queryShape was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaShape_FromoaShape(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaShapeQuery::queryShape had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaShapeQuery::endRef(oaRef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaShapeQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaShapeQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaShapeQuery::endRef(oaRef* p1,oaUInt4 p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaShapeQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaShapeQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaShapeQuery::endRef(oaRef* p1,oaUInt4 p2,oaUInt4 p3)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"endRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaShapeQuery::endRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(3);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyTuple_SetItem(args,2,PyoaUInt4_FromoaUInt4(p3));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaShapeQuery::endRef had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
oaBoolean pyv_oaShapeQuery::startRef(oaRef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaShapeQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaShapeQuery::startRef had an error.");
    }
    PyParamoaBoolean rv;
    if (PyoaBoolean_Convert(result,&rv)==0) {
        throw oaPythonException("Python Virtual Function oaBoolean::startRef has incorrect return type.");
    }
    Py_DECREF(result);
    return rv.Data();
}

// ------------------------------------------------------------------
oaBoolean pyv_oaShapeQuery::startRef(oaRef* p1,oaUInt4 p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaShapeQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaShapeQuery::startRef had an error.");
    }
    PyParamoaBoolean rv;
    if (PyoaBoolean_Convert(result,&rv)==0) {
        throw oaPythonException("Python Virtual Function oaBoolean::startRef has incorrect return type.");
    }
    Py_DECREF(result);
    return rv.Data();
}

// ------------------------------------------------------------------
oaBoolean pyv_oaShapeQuery::startRef(oaRef* p1,oaUInt4 p2,oaUInt4 p3)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"startRef");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaShapeQuery::startRef was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(3);
    PyTuple_SetItem(args,0,PyoaRef_FromoaRef(p1));
    PyTuple_SetItem(args,1,PyoaUInt4_FromoaUInt4(p2));
    PyTuple_SetItem(args,2,PyoaUInt4_FromoaUInt4(p3));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaShapeQuery::startRef had an error.");
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
static char oaShapeQuery_getLayerNum_doc[] = 
"Class: oaShapeQuery, Function: getLayerNum\n"
"  Paramegers: ()\n"
"    Calls: oaLayerNum getLayerNum() const\n"
"    Signature: getLayerNum|simple-oaLayerNum|\n"
"    BrowseData: 1\n"
"    This function returns the layer number associated with this shape query.\n"
;

static PyObject*
oaShapeQuery_getLayerNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShapeQuery data;
    int convert_status=PyoaShapeQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeQueryObject* self=(PyoaShapeQueryObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaLayerNum result= (data.DataCall()->getLayerNum());
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
static char oaShapeQuery_getOccShape_doc[] = 
"Class: oaShapeQuery, Function: getOccShape\n"
"  Paramegers: (oaShape)\n"
"    Calls: oaOccShape* getOccShape(oaShape* shape) const\n"
"    Signature: getOccShape|ptr-oaOccShape|ptr-oaShape,\n"
"    This function returns the occShape associated with the specified shape in a design hierarchy. If the occShape does not exist, one will be generated and returned.\n"
"    shape\n"
"    The shape from which the occShape will be generated\n"
;

static PyObject*
oaShapeQuery_getOccShape(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShapeQuery data;
    int convert_status=PyoaShapeQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeQueryObject* self=(PyoaShapeQueryObject*)ob;

    PyParamoaShape p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaShape_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaOccShapep result= (data.DataCall()->getOccShape(p1.Data()));
        return PyoaOccShape_FromoaOccShape(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaShapeQuery_getPurposeNum_doc[] = 
"Class: oaShapeQuery, Function: getPurposeNum\n"
"  Paramegers: ()\n"
"    Calls: oaPurposeNum getPurposeNum() const\n"
"    Signature: getPurposeNum|simple-oaPurposeNum|\n"
"    BrowseData: 1\n"
"    This function returns the purpose number associated with this shape query.\n"
;

static PyObject*
oaShapeQuery_getPurposeNum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShapeQuery data;
    int convert_status=PyoaShapeQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeQueryObject* self=(PyoaShapeQueryObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaPurposeNum result= (data.DataCall()->getPurposeNum());
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
static char oaShapeQuery_query_doc[] = 
"Class: oaShapeQuery, Function: query\n"
"  Paramegers: (oaDesign,oaLayerNum,oaPurposeNum,oaBox)\n"
"    Calls: void query(oaDesign* topDesign,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaBox& region)\n"
"    Signature: query|void-void|ptr-oaDesign,simple-oaLayerNum,simple-oaPurposeNum,cref-oaBox,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating shapes on the specified layer/purpose in the specified region of the specified design hierarchy.\n"
"    A valid layer number and purpose number must be provided to the shape query, and the query produces all shapes in the design hierarchy on that layer and purpose. If there isn't an oaLPPHeader corresponding to the specified layer and purpose numbers, the query does not produces any shapes.\n"
"    The top block of any given design will have an LPPHeader for every LPPHeader that exists in the block of every bound, instantiated design in its hierarchy. In order to produce all layer/purpose shapes of interest in a design, the application can get a collection of oaLPPHeaders in the top block, then for each LPPHeader in the collection the application can use the oaShapeQuery class to query the shapes for the layerNum and purposeNum from that LPPHeader.\n"
"    topDesign\n"
"    The specified design for performing object querying\n"
"    layerNum\n"
"    Only query object with this layer number\n"
"    purposeNum\n"
"    Only query object with this purpose number\n"
"    region\n"
"    The region of interest\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to stop the querying\n"
"  Paramegers: (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaDist)\n"
"    Calls: void query(oaDesign* topDesign,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaBox& region,oaDist filterSize)\n"
"    Signature: query|void-void|ptr-oaDesign,simple-oaLayerNum,simple-oaPurposeNum,cref-oaBox,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating shapes on the specified layer/purpose in the specified region of the specified design hierarchy.\n"
"    A valid layer number and purpose number must be provided to the shape query, and the query produces all shapes in the design hierarchy on that layer and purpose. If there isn't an oaLPPHeader corresponding to the specified layer and purpose numbers, the query does not produces any shapes.\n"
"    The top block of any given design will have an LPPHeader for every LPPHeader that exists in the block of every bound, instantiated design in its hierarchy. In order to produce all layer/purpose shapes of interest in a design, the application can get a collection of oaLPPHeaders in the top block, then for each LPPHeader in the collection the application can use the oaShapeQuery class to query the shapes for the layerNum and purposeNum from that LPPHeader.\n"
"    topDesign\n"
"    The specified design for performing object querying\n"
"    layerNum\n"
"    Only query object with this layer number\n"
"    purposeNum\n"
"    Only query object with this purpose number\n"
"    region\n"
"    The region of interest\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to stop the querying\n"
"  Paramegers: (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaDist,oaUInt4)\n"
"    Calls: void query(oaDesign* topDesign,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaBox& region,oaDist filterSize,oaUInt4 startLevel)\n"
"    Signature: query|void-void|ptr-oaDesign,simple-oaLayerNum,simple-oaPurposeNum,cref-oaBox,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating shapes on the specified layer/purpose in the specified region of the specified design hierarchy.\n"
"    A valid layer number and purpose number must be provided to the shape query, and the query produces all shapes in the design hierarchy on that layer and purpose. If there isn't an oaLPPHeader corresponding to the specified layer and purpose numbers, the query does not produces any shapes.\n"
"    The top block of any given design will have an LPPHeader for every LPPHeader that exists in the block of every bound, instantiated design in its hierarchy. In order to produce all layer/purpose shapes of interest in a design, the application can get a collection of oaLPPHeaders in the top block, then for each LPPHeader in the collection the application can use the oaShapeQuery class to query the shapes for the layerNum and purposeNum from that LPPHeader.\n"
"    topDesign\n"
"    The specified design for performing object querying\n"
"    layerNum\n"
"    Only query object with this layer number\n"
"    purposeNum\n"
"    Only query object with this purpose number\n"
"    region\n"
"    The region of interest\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to stop the querying\n"
"  Paramegers: (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaDist,oaUInt4,oaUInt4)\n"
"    Calls: void query(oaDesign* topDesign,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaBox& region,oaDist filterSize,oaUInt4 startLevel,oaUInt4 stopLevel)\n"
"    Signature: query|void-void|ptr-oaDesign,simple-oaLayerNum,simple-oaPurposeNum,cref-oaBox,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating shapes on the specified layer/purpose in the specified region of the specified design hierarchy.\n"
"    A valid layer number and purpose number must be provided to the shape query, and the query produces all shapes in the design hierarchy on that layer and purpose. If there isn't an oaLPPHeader corresponding to the specified layer and purpose numbers, the query does not produces any shapes.\n"
"    The top block of any given design will have an LPPHeader for every LPPHeader that exists in the block of every bound, instantiated design in its hierarchy. In order to produce all layer/purpose shapes of interest in a design, the application can get a collection of oaLPPHeaders in the top block, then for each LPPHeader in the collection the application can use the oaShapeQuery class to query the shapes for the layerNum and purposeNum from that LPPHeader.\n"
"    topDesign\n"
"    The specified design for performing object querying\n"
"    layerNum\n"
"    Only query object with this layer number\n"
"    purposeNum\n"
"    Only query object with this purpose number\n"
"    region\n"
"    The region of interest\n"
"    filterSize\n"
"    Only query objects whose size is equal to or larger than filterSize\n"
"    startLevel\n"
"    The level of block hierarchy to start the querying\n"
"    stopLevel\n"
"    The level of block hierarchy to stop the querying\n"
"  Paramegers: (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaTransform)\n"
"    Calls: void query(oaDesign* topDesign,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaBox& region,const oaTransform& xform)\n"
"    Signature: query|void-void|ptr-oaDesign,simple-oaLayerNum,simple-oaPurposeNum,cref-oaBox,cref-oaTransform,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating shapes on the specified layer/purpose in the specified region of the specified design hierarchy.\n"
"    A valid layer number and purpose number must be provided to the shape query, and the query produces all shapes in the design hierarchy on that layer and purpose. If there isn't an oaLPPHeader corresponding to the specified layer and purpose numbers, the query does not produces any shapes.\n"
"    The top block of any given design will have an LPPHeader for every LPPHeader that exists in the block of every bound, instantiated design in its hierarchy. In order to produce all layer/purpose shapes of interest in a design, the application can get a collection of oaLPPHeaders in the top block, then for each LPPHeader in the collection the application can use the oaShapeQuery class to query the shapes for the layerNum and purposeNum from that LPPHeader.\n"
"    topDesign\n"
"    Pointer to the top design\n"
"    layerNum\n"
"    Only query object with this layer number\n"
"    purposeNum\n"
"    Only query object with this purpose number\n"
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
"  Paramegers: (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaTransform,oaDist)\n"
"    Calls: void query(oaDesign* topDesign,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaBox& region,const oaTransform& xform,oaDist filterSize)\n"
"    Signature: query|void-void|ptr-oaDesign,simple-oaLayerNum,simple-oaPurposeNum,cref-oaBox,cref-oaTransform,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating shapes on the specified layer/purpose in the specified region of the specified design hierarchy.\n"
"    A valid layer number and purpose number must be provided to the shape query, and the query produces all shapes in the design hierarchy on that layer and purpose. If there isn't an oaLPPHeader corresponding to the specified layer and purpose numbers, the query does not produces any shapes.\n"
"    The top block of any given design will have an LPPHeader for every LPPHeader that exists in the block of every bound, instantiated design in its hierarchy. In order to produce all layer/purpose shapes of interest in a design, the application can get a collection of oaLPPHeaders in the top block, then for each LPPHeader in the collection the application can use the oaShapeQuery class to query the shapes for the layerNum and purposeNum from that LPPHeader.\n"
"    topDesign\n"
"    Pointer to the top design\n"
"    layerNum\n"
"    Only query object with this layer number\n"
"    purposeNum\n"
"    Only query object with this purpose number\n"
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
"  Paramegers: (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaTransform,oaDist,oaUInt4)\n"
"    Calls: void query(oaDesign* topDesign,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaBox& region,const oaTransform& xform,oaDist filterSize,oaUInt4 startLevel)\n"
"    Signature: query|void-void|ptr-oaDesign,simple-oaLayerNum,simple-oaPurposeNum,cref-oaBox,cref-oaTransform,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating shapes on the specified layer/purpose in the specified region of the specified design hierarchy.\n"
"    A valid layer number and purpose number must be provided to the shape query, and the query produces all shapes in the design hierarchy on that layer and purpose. If there isn't an oaLPPHeader corresponding to the specified layer and purpose numbers, the query does not produces any shapes.\n"
"    The top block of any given design will have an LPPHeader for every LPPHeader that exists in the block of every bound, instantiated design in its hierarchy. In order to produce all layer/purpose shapes of interest in a design, the application can get a collection of oaLPPHeaders in the top block, then for each LPPHeader in the collection the application can use the oaShapeQuery class to query the shapes for the layerNum and purposeNum from that LPPHeader.\n"
"    topDesign\n"
"    Pointer to the top design\n"
"    layerNum\n"
"    Only query object with this layer number\n"
"    purposeNum\n"
"    Only query object with this purpose number\n"
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
"  Paramegers: (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaTransform,oaDist,oaUInt4,oaUInt4)\n"
"    Calls: void query(oaDesign* topDesign,oaLayerNum layerNum,oaPurposeNum purposeNum,const oaBox& region,const oaTransform& xform,oaDist filterSize,oaUInt4 startLevel,oaUInt4 stopLevel)\n"
"    Signature: query|void-void|ptr-oaDesign,simple-oaLayerNum,simple-oaPurposeNum,cref-oaBox,cref-oaTransform,simple-oaDist,simple-oaUInt4,simple-oaUInt4,\n"
"    This function begins the query process to start generating shapes on the specified layer/purpose in the specified region of the specified design hierarchy.\n"
"    A valid layer number and purpose number must be provided to the shape query, and the query produces all shapes in the design hierarchy on that layer and purpose. If there isn't an oaLPPHeader corresponding to the specified layer and purpose numbers, the query does not produces any shapes.\n"
"    The top block of any given design will have an LPPHeader for every LPPHeader that exists in the block of every bound, instantiated design in its hierarchy. In order to produce all layer/purpose shapes of interest in a design, the application can get a collection of oaLPPHeaders in the top block, then for each LPPHeader in the collection the application can use the oaShapeQuery class to query the shapes for the layerNum and purposeNum from that LPPHeader.\n"
"    topDesign\n"
"    Pointer to the top design\n"
"    layerNum\n"
"    Only query object with this layer number\n"
"    purposeNum\n"
"    Only query object with this purpose number\n"
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
oaShapeQuery_query(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShapeQuery data;
    int convert_status=PyoaShapeQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeQueryObject* self=(PyoaShapeQueryObject*)ob;

    // Case: (oaDesign,oaLayerNum,oaPurposeNum,oaBox)
    {
        PyParamoaDesign p1;
        PyParamoaLayerNum p2;
        PyParamoaPurposeNum p3;
        PyParamoaBox p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaPurposeNum_Convert,&p3,
              &PyoaBox_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaDist)
    {
        PyParamoaDesign p1;
        PyParamoaLayerNum p2;
        PyParamoaPurposeNum p3;
        PyParamoaBox p4;
        PyParamoaDist p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaPurposeNum_Convert,&p3,
              &PyoaBox_Convert,&p4,
              &PyoaDist_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaDist,oaUInt4)
    {
        PyParamoaDesign p1;
        PyParamoaLayerNum p2;
        PyParamoaPurposeNum p3;
        PyParamoaBox p4;
        PyParamoaDist p5;
        PyParamoaUInt4 p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaPurposeNum_Convert,&p3,
              &PyoaBox_Convert,&p4,
              &PyoaDist_Convert,&p5,
              &PyoaUInt4_Convert,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaDist,oaUInt4,oaUInt4)
    {
        PyParamoaDesign p1;
        PyParamoaLayerNum p2;
        PyParamoaPurposeNum p3;
        PyParamoaBox p4;
        PyParamoaDist p5;
        PyParamoaUInt4 p6;
        PyParamoaUInt4 p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaPurposeNum_Convert,&p3,
              &PyoaBox_Convert,&p4,
              &PyoaDist_Convert,&p5,
              &PyoaUInt4_Convert,&p6,
              &PyoaUInt4_Convert,&p7)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaTransform)
    {
        PyParamoaDesign p1;
        PyParamoaLayerNum p2;
        PyParamoaPurposeNum p3;
        PyParamoaBox p4;
        PyParamoaTransform p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaPurposeNum_Convert,&p3,
              &PyoaBox_Convert,&p4,
              &PyoaTransform_Convert,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaTransform,oaDist)
    {
        PyParamoaDesign p1;
        PyParamoaLayerNum p2;
        PyParamoaPurposeNum p3;
        PyParamoaBox p4;
        PyParamoaTransform p5;
        PyParamoaDist p6;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaPurposeNum_Convert,&p3,
              &PyoaBox_Convert,&p4,
              &PyoaTransform_Convert,&p5,
              &PyoaDist_Convert,&p6)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaTransform,oaDist,oaUInt4)
    {
        PyParamoaDesign p1;
        PyParamoaLayerNum p2;
        PyParamoaPurposeNum p3;
        PyParamoaBox p4;
        PyParamoaTransform p5;
        PyParamoaDist p6;
        PyParamoaUInt4 p7;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaPurposeNum_Convert,&p3,
              &PyoaBox_Convert,&p4,
              &PyoaTransform_Convert,&p5,
              &PyoaDist_Convert,&p6,
              &PyoaUInt4_Convert,&p7)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaTransform,oaDist,oaUInt4,oaUInt4)
    {
        PyParamoaDesign p1;
        PyParamoaLayerNum p2;
        PyParamoaPurposeNum p3;
        PyParamoaBox p4;
        PyParamoaTransform p5;
        PyParamoaDist p6;
        PyParamoaUInt4 p7;
        PyParamoaUInt4 p8;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&O&O&O&",
              &PyoaDesign_Convert,&p1,
              &PyoaLayerNum_Convert,&p2,
              &PyoaPurposeNum_Convert,&p3,
              &PyoaBox_Convert,&p4,
              &PyoaTransform_Convert,&p5,
              &PyoaDist_Convert,&p6,
              &PyoaUInt4_Convert,&p7,
              &PyoaUInt4_Convert,&p8)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            data.DataCall()->query(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data(),p6.Data(),p7.Data(),p8.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaShapeQuery, function: query, Choices are:\n"
        "    (oaDesign,oaLayerNum,oaPurposeNum,oaBox)\n"
        "    (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaDist)\n"
        "    (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaDist,oaUInt4)\n"
        "    (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaDist,oaUInt4,oaUInt4)\n"
        "    (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaTransform)\n"
        "    (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaTransform,oaDist)\n"
        "    (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaTransform,oaDist,oaUInt4)\n"
        "    (oaDesign,oaLayerNum,oaPurposeNum,oaBox,oaTransform,oaDist,oaUInt4,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaShapeQuery_queryShape_doc[] = 
"Class: oaShapeQuery, Function: queryShape\n"
"  Paramegers: (oaShape)\n"
"    Calls: virtual void queryShape(oaShape* shape)\n"
"    Signature: queryShape|void-void|ptr-oaShape,\n"
"    This function processes each result of the shape query.\n"
"    shape\n"
"    Pointer to a shape found during querying\n"
;

static PyObject*
oaShapeQuery_queryShape(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaShapeQuery data;
    int convert_status=PyoaShapeQuery_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaShapeQueryObject* self=(PyoaShapeQueryObject*)ob;

    PyParamoaShape p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaShape_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        PyErr_SetString(PyExc_TypeError,
            "Call to Pure-Virtual Function class: oaShapeQuery, function: queryShape");
            return NULL;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaShapeQuery_assign_doc[] = 
"Class: oaShapeQuery, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaShapeQuery_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaShapeQuery data;
  int convert_status=PyoaShapeQuery_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaShapeQuery p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaShapeQuery_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaShapeQuery_methodlist[] = {
    {"getLayerNum",(PyCFunction)oaShapeQuery_getLayerNum,METH_VARARGS,oaShapeQuery_getLayerNum_doc},
    {"getOccShape",(PyCFunction)oaShapeQuery_getOccShape,METH_VARARGS,oaShapeQuery_getOccShape_doc},
    {"getPurposeNum",(PyCFunction)oaShapeQuery_getPurposeNum,METH_VARARGS,oaShapeQuery_getPurposeNum_doc},
    {"query",(PyCFunction)oaShapeQuery_query,METH_VARARGS,oaShapeQuery_query_doc},
    {"queryShape",(PyCFunction)oaShapeQuery_queryShape,METH_VARARGS,oaShapeQuery_queryShape_doc},
    {"assign",(PyCFunction)oaShapeQuery_tp_assign,METH_VARARGS,oaShapeQuery_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaShapeQuery_doc[] = 
"Class: oaShapeQuery\n"
"  The oaShapeQuery is used to examine and return shapes in oaVias and oaDesigns. Note that stepping into a Via counts as a level of hierarchy. Hence to use oaShapeQuery to find the pin shapes in the master for an instTerm, the query should descend two levels: the first level descends to the master, and the second level will be traversed if the pin contains an oaVia .\n"
"  The sequence of virtual functions that get called during the query is as follows.\n"
"  oaShapeQuery::queryShape(oaShape *shape) - For shapes in a design\n"
"  oaRegionQuery::startRef(oaRef *ref, oaUInt4 row, oaUInt4 col)\n"
"  oaShapeQuery::queryShape(oaShape *shape) - For shapes in the oaRef that is being processed.\n"
"  oaRegionQuery::endRef(oaRef *ref, oaUInt4 row, oaUInt4 col)\n"
"  The query descends the hierarchy of an oaRef , if the maximum dimension of the ref's master is larger than the filter size of the query and if the startRef function call returns true for that ref. If then produces shapes recursively in its hierarchy. endRef function for an oaRef gets called if the query descends into its hierarchy. See documentation on startRef and endRef for additional information.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaShapeQuery()\n"
"    Signature: oaShapeQuery||\n"
"    This is the constructor for the oaShapeQuery class.\n"
"  Paramegers: (oaShapeQuery)\n"
"    Calls: (const oaShapeQuery&)\n"
"    Signature: oaShapeQuery||cref-oaShapeQuery,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaShapeQuery_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaShapeQuery",
    sizeof(PyoaShapeQueryObject),
    0,
    (destructor)oaShapeQuery_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaShapeQuery_tp_compare,	/* tp_compare */
    (reprfunc)oaShapeQuery_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaShapeQuery_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaShapeQuery_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaRegionQuery_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaShapeQuery_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaShapeQuery_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaShapeQuery_Type)<0) {
      printf("** PyType_Ready failed for: oaShapeQuery\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaShapeQuery",
           (PyObject*)(&PyoaShapeQuery_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaShapeQuery\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaSigType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaSigType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaSigType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaSigTypeObject* self = (PyoaSigTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaSigTypeEnum)
    {
        PyParamoaSigTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaSigTypeEnum_Convert,&p1)) {
            self->value =  new oaSigType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaSigType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaSigType)
    {
        PyParamoaSigType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaSigType_Convert,&p1)) {
            self->value= new oaSigType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaSigType, Choices are:\n"
        "    (oaSigTypeEnum)\n"
        "    (oaString)\n"
        "    (oaSigType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaSigType_tp_dealloc(PyoaSigTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaSigType_tp_repr(PyObject *ob)
{
    PyParamoaSigType value;
    int convert_status=PyoaSigType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[31];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaSigType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaSigType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaSigType v1;
    PyParamoaSigType v2;
    int convert_status1=PyoaSigType_Convert(ob1,&v1);
    int convert_status2=PyoaSigType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaSigType_Convert(PyObject* ob,PyParamoaSigType* result)
{
    if (ob == NULL) return 1;
    if (PyoaSigType_Check(ob)) {
        result->SetData(  ((PyoaSigTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaSigType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaSigType_FromoaSigType(oaSigType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaSigType_Type.tp_alloc(&PyoaSigType_Type,0);
        if (bself == NULL) return bself;
        PyoaSigTypeObject* self = (PyoaSigTypeObject*)bself;
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
static char oaSigType_getName_doc[] = 
"Class: oaSigType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name string associated with the encapsulated #oaSigTypeEnum object.\n"
;

static PyObject*
oaSigType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSigType data;
    int convert_status=PyoaSigType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSigTypeObject* self=(PyoaSigTypeObject*)ob;

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
static char oaSigType_oaSigTypeEnum_doc[] = 
"Class: oaSigType, Function: oaSigTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaSigTypeEnum oaSigTypeEnum() const\n"
"    Signature: operator oaSigTypeEnum|simple-oaSigTypeEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaSigType object into the corresponding #oaSigTypeEnum value.\n"
;

static PyObject*
oaSigType_oaSigTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSigType data;
    int convert_status=PyoaSigType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSigTypeObject* self=(PyoaSigTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaSigTypeEnum result= (data.DataCall()->operator oaSigTypeEnum());
        return PyoaSigTypeEnum_FromoaSigTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaSigType_assign_doc[] = 
"Class: oaSigType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaSigType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaSigType data;
  int convert_status=PyoaSigType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaSigType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaSigType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaSigType_methodlist[] = {
    {"getName",(PyCFunction)oaSigType_getName,METH_VARARGS,oaSigType_getName_doc},
    {"oaSigTypeEnum",(PyCFunction)oaSigType_oaSigTypeEnum,METH_VARARGS,oaSigType_oaSigTypeEnum_doc},
    {"assign",(PyCFunction)oaSigType_tp_assign,METH_VARARGS,oaSigType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaSigType_doc[] = 
"Class: oaSigType\n"
"  The oaSigType class encapsulates the enumerated values that describe the different uses of a net object.\n"
"  oaSigTypeEnum\n"
"Constructors:\n"
"  Paramegers: (oaSigTypeEnum)\n"
"    Calls: oaSigType(oaSigTypeEnum valueIn)\n"
"    Signature: oaSigType||simple-oaSigTypeEnum,\n"
"    This function constructs an instance of an oaSigType class using the specified #oaSigTypeEnum value.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaSigType(const oaString& name)\n"
"    Signature: oaSigType||cref-oaString,\n"
"    This function constructs an instance of an oaSigType class using the #oaSigTypeEnum associated with the specified string name . This name must be defined in the legal set of names associated with #oaSigTypeEnum.\n"
"    oacInvalidSigTypeName\n"
"  Paramegers: (oaSigType)\n"
"    Calls: (const oaSigType&)\n"
"    Signature: oaSigType||cref-oaSigType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaSigType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaSigType",
    sizeof(PyoaSigTypeObject),
    0,
    (destructor)oaSigType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaSigType_tp_compare,	/* tp_compare */
    (reprfunc)oaSigType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaSigType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaSigType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaSigType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaSigType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaSigType_Type)<0) {
      printf("** PyType_Ready failed for: oaSigType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaSigType",
           (PyObject*)(&PyoaSigType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaSigType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaSigTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaSigTypeEnum_Convert(PyObject* ob,PyParamoaSigTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacSignalSigType")==0) { result->SetData(oacSignalSigType); return 1;}
        if (strcasecmp(str,"oacPowerSigType")==0) { result->SetData(oacPowerSigType); return 1;}
        if (strcasecmp(str,"oacGroundSigType")==0) { result->SetData(oacGroundSigType); return 1;}
        if (strcasecmp(str,"oacClockSigType")==0) { result->SetData(oacClockSigType); return 1;}
        if (strcasecmp(str,"oacTieoffSigType")==0) { result->SetData(oacTieoffSigType); return 1;}
        if (strcasecmp(str,"oacTieHiSigType")==0) { result->SetData(oacTieHiSigType); return 1;}
        if (strcasecmp(str,"oacTieLoSigType")==0) { result->SetData(oacTieLoSigType); return 1;}
        if (strcasecmp(str,"oacAnalogSigType")==0) { result->SetData(oacAnalogSigType); return 1;}
        if (strcasecmp(str,"oacScanSigType")==0) { result->SetData(oacScanSigType); return 1;}
        if (strcasecmp(str,"oacResetSigType")==0) { result->SetData(oacResetSigType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaSigTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaSigTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaSigTypeEnum_FromoaSigTypeEnum(oaSigTypeEnum ob)
{
    if (ob==oacSignalSigType) return PyString_FromString("oacSignalSigType");
    if (ob==oacPowerSigType) return PyString_FromString("oacPowerSigType");
    if (ob==oacGroundSigType) return PyString_FromString("oacGroundSigType");
    if (ob==oacClockSigType) return PyString_FromString("oacClockSigType");
    if (ob==oacTieoffSigType) return PyString_FromString("oacTieoffSigType");
    if (ob==oacTieHiSigType) return PyString_FromString("oacTieHiSigType");
    if (ob==oacTieLoSigType) return PyString_FromString("oacTieLoSigType");
    if (ob==oacAnalogSigType) return PyString_FromString("oacAnalogSigType");
    if (ob==oacScanSigType) return PyString_FromString("oacScanSigType");
    if (ob==oacResetSigType) return PyString_FromString("oacResetSigType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaSigTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaSigTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaSigTypeEnum_FromoaSigTypeEnum(oaSigTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaSigTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaSigTypeEnum_doc[] =
"Type convert function for enum: oaSigTypeEnum";
                               
static PyMethodDef PyoaSigTypeEnum_method =
  {"oaSigTypeEnum",(PyCFunction)PyoaSigTypeEnum_TypeFunction,METH_VARARGS,oaSigTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaSigTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacSignalSigType");
    PyDict_SetItemString(mod_dict,"oacSignalSigType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacPowerSigType");
    PyDict_SetItemString(mod_dict,"oacPowerSigType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacGroundSigType");
    PyDict_SetItemString(mod_dict,"oacGroundSigType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacClockSigType");
    PyDict_SetItemString(mod_dict,"oacClockSigType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTieoffSigType");
    PyDict_SetItemString(mod_dict,"oacTieoffSigType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTieHiSigType");
    PyDict_SetItemString(mod_dict,"oacTieHiSigType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacTieLoSigType");
    PyDict_SetItemString(mod_dict,"oacTieLoSigType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacAnalogSigType");
    PyDict_SetItemString(mod_dict,"oacAnalogSigType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacScanSigType");
    PyDict_SetItemString(mod_dict,"oacScanSigType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacResetSigType");
    PyDict_SetItemString(mod_dict,"oacResetSigType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaSigTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaSigTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaSigTypeEnum\n");
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
// Wrapper Implementation for Class: oaSimpleConstraint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaSimpleConstraint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaSimpleConstraint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaSimpleConstraintObject* self = (PyoaSimpleConstraintObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaSimpleConstraint)
    {
        PyParamoaSimpleConstraint p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaSimpleConstraint_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaSimpleConstraint, Choices are:\n"
        "    (oaSimpleConstraint)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaSimpleConstraint_tp_dealloc(PyoaSimpleConstraintObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaSimpleConstraint_tp_repr(PyObject *ob)
{
    PyParamoaSimpleConstraint value;
    int convert_status=PyoaSimpleConstraint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaSimpleConstraint::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaSimpleConstraint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaSimpleConstraint v1;
    PyParamoaSimpleConstraint v2;
    int convert_status1=PyoaSimpleConstraint_Convert(ob1,&v1);
    int convert_status2=PyoaSimpleConstraint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaSimpleConstraint_Convert(PyObject* ob,PyParamoaSimpleConstraint* result)
{
    if (ob == NULL) return 1;
    if (PyoaSimpleConstraint_Check(ob)) {
        result->SetData( (oaSimpleConstraint**) ((PyoaSimpleConstraintObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaSimpleConstraint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaSimpleConstraint_FromoaSimpleConstraint(oaSimpleConstraint** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaSimpleConstraint* data=*value;
        PyObject* bself = PyoaSimpleConstraint_Type.tp_alloc(&PyoaSimpleConstraint_Type,0);
        if (bself == NULL) return bself;
        PyoaSimpleConstraintObject* self = (PyoaSimpleConstraintObject*)bself;
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
PyObject* PyoaSimpleConstraint_FromoaSimpleConstraint(oaSimpleConstraint* data)
{
    if (data) {
       PyObject* bself = PyoaSimpleConstraint_Type.tp_alloc(&PyoaSimpleConstraint_Type,0);
       if (bself == NULL) return bself;
       PyoaSimpleConstraintObject* self = (PyoaSimpleConstraintObject*)bself;
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
static char oaSimpleConstraint_doc[] = 
"Class: oaSimpleConstraint\n"
"  The oaSimpleConstraint class represents a basic constraint object that is defined by its oaSimpleConstraintDef . A simple constraint has a value associated with it and potentially a list of constraint parameters. A simple constraint may or may not be a hard constraint. A hard constraint is a constraint that must be met.\n"
"  oaSimpleConstraints always have a value, and are created in the same database as that value. oaSimpleConstraints get applied to objects by being placed in an oaConstraintGroup .\n"
"Constructors:\n"
"  Paramegers: (oaSimpleConstraint)\n"
"    Calls: (const oaSimpleConstraint&)\n"
"    Signature: oaSimpleConstraint||cref-oaSimpleConstraint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaSimpleConstraint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaSimpleConstraint",
    sizeof(PyoaSimpleConstraintObject),
    0,
    (destructor)oaSimpleConstraint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaSimpleConstraint_tp_compare,	/* tp_compare */
    (reprfunc)oaSimpleConstraint_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaSimpleConstraint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConstraint_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaSimpleConstraint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaSimpleConstraint_static_create_doc[] = 
"Class: oaSimpleConstraint, Function: create\n"
"  Paramegers: (oaSimpleConstraintDef,oaValue)\n"
"    Calls: oaSimpleConstraint* create(const oaSimpleConstraintDef* def,oaValue* value)\n"
"    Signature: create|ptr-oaSimpleConstraint|cptr-oaSimpleConstraintDef,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an auto-named constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    def\n"
"    Simple Constraint definition\n"
"    value\n"
"    Constraint value\n"
"    isHard\n"
"    Boolean indicating whether constraint must be met\n"
"    params\n"
"    Optional constraint parameters\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
"  Paramegers: (oaSimpleConstraintDef,oaValue,oaBoolean)\n"
"    Calls: oaSimpleConstraint* create(const oaSimpleConstraintDef* def,oaValue* value,oaBoolean isHard)\n"
"    Signature: create|ptr-oaSimpleConstraint|cptr-oaSimpleConstraintDef,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an auto-named constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    def\n"
"    Simple Constraint definition\n"
"    value\n"
"    Constraint value\n"
"    isHard\n"
"    Boolean indicating whether constraint must be met\n"
"    params\n"
"    Optional constraint parameters\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
"  Paramegers: (oaSimpleConstraintDef,oaValue,oaBoolean,oaConstraintParamArray)\n"
"    Calls: oaSimpleConstraint* create(const oaSimpleConstraintDef* def,oaValue* value,oaBoolean isHard,const oaConstraintParamArray* params)\n"
"    Signature: create|ptr-oaSimpleConstraint|cptr-oaSimpleConstraintDef,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an auto-named constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    def\n"
"    Simple Constraint definition\n"
"    value\n"
"    Constraint value\n"
"    isHard\n"
"    Boolean indicating whether constraint must be met\n"
"    params\n"
"    Optional constraint parameters\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
"  Paramegers: (oaSimpleConstraintDef,oaString,oaValue)\n"
"    Calls: oaSimpleConstraint* create(const oaSimpleConstraintDef* def,const oaString& name,oaValue* value)\n"
"    Signature: create|ptr-oaSimpleConstraint|cptr-oaSimpleConstraintDef,cref-oaString,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an explicitly name constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    def\n"
"    Simple Constraint definition\n"
"    name\n"
"    Constraint name\n"
"    value\n"
"    Constraint value\n"
"    isHard\n"
"    Boolean indicating whether constraint must be met\n"
"    params\n"
"    Optional constraint parameters\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
"  Paramegers: (oaSimpleConstraintDef,oaString,oaValue,oaBoolean)\n"
"    Calls: oaSimpleConstraint* create(const oaSimpleConstraintDef* def,const oaString& name,oaValue* value,oaBoolean isHard)\n"
"    Signature: create|ptr-oaSimpleConstraint|cptr-oaSimpleConstraintDef,cref-oaString,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an explicitly name constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    def\n"
"    Simple Constraint definition\n"
"    name\n"
"    Constraint name\n"
"    value\n"
"    Constraint value\n"
"    isHard\n"
"    Boolean indicating whether constraint must be met\n"
"    params\n"
"    Optional constraint parameters\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
"  Paramegers: (oaSimpleConstraintDef,oaString,oaValue,oaBoolean,oaConstraintParamArray)\n"
"    Calls: oaSimpleConstraint* create(const oaSimpleConstraintDef* def,const oaString& name,oaValue* value,oaBoolean isHard,const oaConstraintParamArray* params)\n"
"    Signature: create|ptr-oaSimpleConstraint|cptr-oaSimpleConstraintDef,cref-oaString,ptr-oaValue,simple-oaBoolean,cptr-oaConstraintParamArray,\n"
"    This function creates an explicitly name constraint with the specified attributes. The constraint is created in the same database as the value. The constraint parameters must also exist in the same database as the value.\n"
"    def\n"
"    Simple Constraint definition\n"
"    name\n"
"    Constraint name\n"
"    value\n"
"    Constraint value\n"
"    isHard\n"
"    Boolean indicating whether constraint must be met\n"
"    params\n"
"    Optional constraint parameters\n"
"    oacValueAlreadyOwned\n"
"    oacConstraintParamAlreadyOwned\n"
;

static PyObject*
oaSimpleConstraint_static_create(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaSimpleConstraintDef,oaValue)
    {
        PyParamoaSimpleConstraintDef p1;
        PyParamoaValue p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaSimpleConstraintDef_Convert,&p1,
              &PyoaValue_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaSimpleConstraintp result= (oaSimpleConstraint::create(p1.Data(),p2.Data()));
            return PyoaSimpleConstraint_FromoaSimpleConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaSimpleConstraintDef,oaValue,oaBoolean)
    {
        PyParamoaSimpleConstraintDef p1;
        PyParamoaValue p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaSimpleConstraintDef_Convert,&p1,
              &PyoaValue_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaSimpleConstraintp result= (oaSimpleConstraint::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaSimpleConstraint_FromoaSimpleConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaSimpleConstraintDef,oaValue,oaBoolean,oaConstraintParamArray)
    {
        PyParamoaSimpleConstraintDef p1;
        PyParamoaValue p2;
        PyParamoaBoolean p3;
        PyParamoaConstraintParamArray p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaSimpleConstraintDef_Convert,&p1,
              &PyoaValue_Convert,&p2,
              &PyoaBoolean_Convert,&p3,
              &PyoaConstraintParamArray_ConvertAof,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaSimpleConstraintp result= (oaSimpleConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.DataAof()));
            return PyoaSimpleConstraint_FromoaSimpleConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaSimpleConstraintDef,oaString,oaValue)
    {
        PyParamoaSimpleConstraintDef p1;
        PyParamoaString p2;
        PyParamoaValue p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaSimpleConstraintDef_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaValue_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaSimpleConstraintp result= (oaSimpleConstraint::create(p1.Data(),p2.Data(),p3.Data()));
            return PyoaSimpleConstraint_FromoaSimpleConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaSimpleConstraintDef,oaString,oaValue,oaBoolean)
    {
        PyParamoaSimpleConstraintDef p1;
        PyParamoaString p2;
        PyParamoaValue p3;
        PyParamoaBoolean p4;
        if (PyArg_ParseTuple(args,"O&O&O&O&",
              &PyoaSimpleConstraintDef_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaValue_Convert,&p3,
              &PyoaBoolean_Convert,&p4)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaSimpleConstraintp result= (oaSimpleConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
            return PyoaSimpleConstraint_FromoaSimpleConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaSimpleConstraintDef,oaString,oaValue,oaBoolean,oaConstraintParamArray)
    {
        PyParamoaSimpleConstraintDef p1;
        PyParamoaString p2;
        PyParamoaValue p3;
        PyParamoaBoolean p4;
        PyParamoaConstraintParamArray p5;
        if (PyArg_ParseTuple(args,"O&O&O&O&O&",
              &PyoaSimpleConstraintDef_Convert,&p1,
              &PyoaString_Convert,&p2,
              &PyoaValue_Convert,&p3,
              &PyoaBoolean_Convert,&p4,
              &PyoaConstraintParamArray_ConvertAof,&p5)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p3.Data(),3)) return NULL;
            oaSimpleConstraintp result= (oaSimpleConstraint::create(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.DataAof()));
            return PyoaSimpleConstraint_FromoaSimpleConstraint(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaSimpleConstraint, function: create, Choices are:\n"
        "    (oaSimpleConstraintDef,oaValue)\n"
        "    (oaSimpleConstraintDef,oaValue,oaBoolean)\n"
        "    (oaSimpleConstraintDef,oaValue,oaBoolean,oaConstraintParamArray)\n"
        "    (oaSimpleConstraintDef,oaString,oaValue)\n"
        "    (oaSimpleConstraintDef,oaString,oaValue,oaBoolean)\n"
        "    (oaSimpleConstraintDef,oaString,oaValue,oaBoolean,oaConstraintParamArray)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSimpleConstraint_static_find_doc[] = 
"Class: oaSimpleConstraint, Function: find\n"
"  Paramegers: (oaConstraintGroup,oaSimpleConstraintDef)\n"
"    Calls: oaSimpleConstraint* find(const oaConstraintGroup* group,const oaSimpleConstraintDef* def)\n"
"    Signature: find|ptr-oaSimpleConstraint|cptr-oaConstraintGroup,cptr-oaSimpleConstraintDef,simple-oaBoolean,\n"
"    This function returns the first hard or soft constraint in the group with the definition specified.\n"
"    group\n"
"    Constraint group to search\n"
"    def\n"
"    Simple Constraint definition to search for\n"
"    hard\n"
"    Boolean indicating whether or not the constraint to be searched for is hard or soft\n"
"  Paramegers: (oaConstraintGroup,oaSimpleConstraintDef,oaBoolean)\n"
"    Calls: oaSimpleConstraint* find(const oaConstraintGroup* group,const oaSimpleConstraintDef* def,oaBoolean hardOnly)\n"
"    Signature: find|ptr-oaSimpleConstraint|cptr-oaConstraintGroup,cptr-oaSimpleConstraintDef,simple-oaBoolean,\n"
"    This function returns the first hard or soft constraint in the group with the definition specified.\n"
"    group\n"
"    Constraint group to search\n"
"    def\n"
"    Simple Constraint definition to search for\n"
"    hard\n"
"    Boolean indicating whether or not the constraint to be searched for is hard or soft\n"
;

static PyObject*
oaSimpleConstraint_static_find(PyObject* ob, PyObject *args)
{
  try {
    // Case: (oaConstraintGroup,oaSimpleConstraintDef)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaSimpleConstraintDef p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaSimpleConstraintDef_Convert,&p2)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaSimpleConstraintp result= (oaSimpleConstraint::find(p1.Data(),p2.Data()));
            return PyoaSimpleConstraint_FromoaSimpleConstraint(result);
        }
    }
    PyErr_Clear();
    // Case: (oaConstraintGroup,oaSimpleConstraintDef,oaBoolean)
    {
        PyParamoaConstraintGroup p1;
        PyParamoaSimpleConstraintDef p2;
        PyParamoaBoolean p3;
        if (PyArg_ParseTuple(args,"O&O&O&",
              &PyoaConstraintGroup_Convert,&p1,
              &PyoaSimpleConstraintDef_Convert,&p2,
              &PyoaBoolean_Convert,&p3)) {
            if (!PyValidateDbObject(p1.Data(),1)) return NULL;
            if (!PyValidateDbObject(p2.Data(),2)) return NULL;
            oaSimpleConstraintp result= (oaSimpleConstraint::find(p1.Data(),p2.Data(),p3.Data()));
            return PyoaSimpleConstraint_FromoaSimpleConstraint(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaSimpleConstraint, function: find, Choices are:\n"
        "    (oaConstraintGroup,oaSimpleConstraintDef)\n"
        "    (oaConstraintGroup,oaSimpleConstraintDef,oaBoolean)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSimpleConstraint_static_getConstraints_doc[] = 
"Class: oaSimpleConstraint, Function: getConstraints\n"
"  Paramegers: (oaConstraintGroup,oaSimpleConstraintDef)\n"
"    Calls: oaCollection_oaSimpleConstraint_oaConstraintGroup getConstraints(const oaConstraintGroup* group,const oaSimpleConstraintDef* def)\n"
"    Signature: getConstraints|simple-oaCollection_oaSimpleConstraint_oaConstraintGroup|cptr-oaConstraintGroup,cptr-oaSimpleConstraintDef,\n"
"    This function returns a collection of simple constraints in the specified group whose definition matches the one given. If no definition is specified, all simple constraints in that group are returned.\n"
"    group\n"
"    The group to search in\n"
"    def\n"
"    The simple constraint definition to filter for\n"
;

static PyObject*
oaSimpleConstraint_static_getConstraints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroup p1;
    PyParamoaSimpleConstraintDef p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaConstraintGroup_Convert,&p1,
          &PyoaSimpleConstraintDef_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        oaCollection_oaSimpleConstraint_oaConstraintGroup* result= new oaCollection_oaSimpleConstraint_oaConstraintGroup(oaSimpleConstraint::getConstraints(p1.Data(),p2.Data()));
        return PyoaCollection_oaSimpleConstraint_oaConstraintGroup_FromoaCollection_oaSimpleConstraint_oaConstraintGroup(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSimpleConstraint_static_getConstraintsIter_doc[] = 
"Class: oaSimpleConstraint, Function: getConstraintsIter\n"
"  Paramegers: (oaConstraintGroup,oaSimpleConstraintDef)\n"
"    Calls: oaIter_oaSimpleConstraint getConstraintsIter(const oaConstraintGroup* group,const oaSimpleConstraintDef* def)\n"
"    Signature: getConstraintsIter|simple-oaIter_oaSimpleConstraint|cptr-oaConstraintGroup,cptr-oaSimpleConstraintDef,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of simple constraints in the specified group whose definition matches the one given. If no definition is specified, all simple constraints in that group are returned.\n"
"    group\n"
"    The group to search in\n"
"    def\n"
"    The simple constraint definition to filter for\n"
;

static PyObject*
oaSimpleConstraint_static_getConstraintsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintGroup p1;
    PyParamoaSimpleConstraintDef p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaConstraintGroup_Convert,&p1,
          &PyoaSimpleConstraintDef_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        if (!PyValidateDbObject(p2.Data(),2)) return NULL;
        oaIter_oaSimpleConstraint* result= new oaIter_oaSimpleConstraint(oaSimpleConstraint::getConstraints(p1.Data(),p2.Data()));
        return PyoaIter_oaSimpleConstraint_FromoaIter_oaSimpleConstraint(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaSimpleConstraint_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaSimpleConstraint_static_create,METH_VARARGS,oaSimpleConstraint_static_create_doc},
    {"static_find",(PyCFunction)oaSimpleConstraint_static_find,METH_VARARGS,oaSimpleConstraint_static_find_doc},
    {"static_getConstraints",(PyCFunction)oaSimpleConstraint_static_getConstraints,METH_VARARGS,oaSimpleConstraint_static_getConstraints_doc},
    {"static_getConstraintsIter",(PyCFunction)oaSimpleConstraint_static_getConstraintsIter,METH_VARARGS,oaSimpleConstraint_static_getConstraintsIter_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaSimpleConstraint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaSimpleConstraint_Type)<0) {
      printf("** PyType_Ready failed for: oaSimpleConstraint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaSimpleConstraint",
           (PyObject*)(&PyoaSimpleConstraint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaSimpleConstraint\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaSimpleConstraint_Type.tp_dict;
    for(method=oaSimpleConstraint_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaSimpleConstraintDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaSimpleConstraintDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaSimpleConstraintDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaSimpleConstraintDefObject* self = (PyoaSimpleConstraintDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaSimpleConstraintDef)
    {
        PyParamoaSimpleConstraintDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaSimpleConstraintDef_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaSimpleConstraintDef, Choices are:\n"
        "    (oaSimpleConstraintDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaSimpleConstraintDef_tp_dealloc(PyoaSimpleConstraintDefObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaSimpleConstraintDef_tp_repr(PyObject *ob)
{
    PyParamoaSimpleConstraintDef value;
    int convert_status=PyoaSimpleConstraintDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaSimpleConstraintDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaSimpleConstraintDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaSimpleConstraintDef v1;
    PyParamoaSimpleConstraintDef v2;
    int convert_status1=PyoaSimpleConstraintDef_Convert(ob1,&v1);
    int convert_status2=PyoaSimpleConstraintDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaSimpleConstraintDef_Convert(PyObject* ob,PyParamoaSimpleConstraintDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaSimpleConstraintDef_Check(ob)) {
        result->SetData( (oaSimpleConstraintDef**) ((PyoaSimpleConstraintDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaSimpleConstraintDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaSimpleConstraintDef_FromoaSimpleConstraintDef(oaSimpleConstraintDef** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaSimpleConstraintDef* data=*value;
        PyObject* bself = PyoaSimpleConstraintDef_Type.tp_alloc(&PyoaSimpleConstraintDef_Type,0);
        if (bself == NULL) return bself;
        PyoaSimpleConstraintDefObject* self = (PyoaSimpleConstraintDefObject*)bself;
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
PyObject* PyoaSimpleConstraintDef_FromoaSimpleConstraintDef(oaSimpleConstraintDef* data)
{
    if (data) {
       PyObject* bself = PyoaSimpleConstraintDef_Type.tp_alloc(&PyoaSimpleConstraintDef_Type,0);
       if (bself == NULL) return bself;
       PyoaSimpleConstraintDefObject* self = (PyoaSimpleConstraintDefObject*)bself;
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
static char oaSimpleConstraintDef_doc[] = 
"Class: oaSimpleConstraintDef\n"
"  The oaSimpleConstraintDef object specifies a definition for a simple constraint. The definition contains a name, a list of databases that the constraint can be created in, and a list of types of oaValues that are allowed for the constraint. The names for constraint definitions must be unique.\n"
"Constructors:\n"
"  Paramegers: (oaSimpleConstraintDef)\n"
"    Calls: (const oaSimpleConstraintDef&)\n"
"    Signature: oaSimpleConstraintDef||cref-oaSimpleConstraintDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaSimpleConstraintDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaSimpleConstraintDef",
    sizeof(PyoaSimpleConstraintDefObject),
    0,
    (destructor)oaSimpleConstraintDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaSimpleConstraintDef_tp_compare,	/* tp_compare */
    (reprfunc)oaSimpleConstraintDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaSimpleConstraintDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaConstraintDef_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaSimpleConstraintDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaSimpleConstraintDef_static_create_doc[] = 
"Class: oaSimpleConstraintDef, Function: create\n"
"  Paramegers: (oaString,oaSubset_oaType,oaSubset_oaType,oaSubset_oaDBType)\n"
"    Calls: oaSimpleConstraintDef* create(const oaString& name,const oaSubset_oaType& allowedValues,const oaSubset_oaType& allowedObjects,const oaSubset_oaDBType& allowedDB)\n"
"    Signature: create|ptr-oaSimpleConstraintDef|cref-oaString,cref-oaSubset_oaType,cref-oaSubset_oaType,cref-oaSubset_oaDBType,\n"
"    This function creates a new simple constraint definition with the specified attributes.\n"
"    name\n"
"    The name of the new definition.\n"
"    allowedValues\n"
"    The value types that constraints with this definition can have.\n"
"    allowedObjects\n"
"    The objects that constraints with this definition can be attached to.\n"
"    allowedDB\n"
"    The databases that constraints with this definition can be created in.\n"
"    oacConstraintDefExists\n"
"    oacInvalidValueType\n"
;

static PyObject*
oaSimpleConstraintDef_static_create(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    PyParamoaSubset_oaType p2;
    PyParamoaSubset_oaType p3;
    PyParamoaSubset_oaDBType p4;
    if (PyArg_ParseTuple(args,"O&O&O&O&",
          &PyoaString_Convert,&p1,
          &PyoaSubset_oaType_Convert,&p2,
          &PyoaSubset_oaType_Convert,&p3,
          &PyoaSubset_oaDBType_Convert,&p4)) {
        oaSimpleConstraintDefp result= (oaSimpleConstraintDef::create(p1.Data(),p2.Data(),p3.Data(),p4.Data()));
        return PyoaSimpleConstraintDef_FromoaSimpleConstraintDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaSimpleConstraintDef_static_get_doc[] = 
"Class: oaSimpleConstraintDef, Function: get\n"
"  Paramegers: (oaSimpleConstraintType)\n"
"    Calls: oaSimpleConstraintDef* get(oaSimpleConstraintType type)\n"
"    Signature: get|ptr-oaSimpleConstraintDef|simple-oaSimpleConstraintType,\n"
"    This function returns the built-in simple constraint definition of the type specified.\n"
"    type\n"
"    The built in simple constraint type to get.\n"
;

static PyObject*
oaSimpleConstraintDef_static_get(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSimpleConstraintType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaSimpleConstraintType_Convert,&p1)) {
        oaSimpleConstraintDefp result= (oaSimpleConstraintDef::get(p1.Data()));
        return PyoaSimpleConstraintDef_FromoaSimpleConstraintDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaSimpleConstraintDef_staticmethodlist[] = {
    {"static_create",(PyCFunction)oaSimpleConstraintDef_static_create,METH_VARARGS,oaSimpleConstraintDef_static_create_doc},
    {"static_get",(PyCFunction)oaSimpleConstraintDef_static_get,METH_VARARGS,oaSimpleConstraintDef_static_get_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaSimpleConstraintDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaSimpleConstraintDef_Type)<0) {
      printf("** PyType_Ready failed for: oaSimpleConstraintDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaSimpleConstraintDef",
           (PyObject*)(&PyoaSimpleConstraintDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaSimpleConstraintDef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaSimpleConstraintDef_Type.tp_dict;
    for(method=oaSimpleConstraintDef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaSimpleConstraintType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaSimpleConstraintType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaSimpleConstraintType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaSimpleConstraintTypeObject* self = (PyoaSimpleConstraintTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaSimpleConstraintTypeEnum)
    {
        PyParamoaSimpleConstraintTypeEnum p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaSimpleConstraintTypeEnum_Convert,&p1)) {
            self->value =  new oaSimpleConstraintType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            self->value =  new oaSimpleConstraintType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaSimpleConstraintType)
    {
        PyParamoaSimpleConstraintType p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaSimpleConstraintType_Convert,&p1)) {
            self->value= new oaSimpleConstraintType(p1.Data());
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaSimpleConstraintType, Choices are:\n"
        "    (oaSimpleConstraintTypeEnum)\n"
        "    (oaString)\n"
        "    (oaSimpleConstraintType)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaSimpleConstraintType_tp_dealloc(PyoaSimpleConstraintTypeObject* self)
{
    if (!self->borrow) {
        delete (self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaSimpleConstraintType_tp_repr(PyObject *ob)
{
    PyParamoaSimpleConstraintType value;
    int convert_status=PyoaSimpleConstraintType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    oaString sresult(value.DataCall()->getName());

    char addr[44];
    sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
    oaString buffer;
    buffer+=oaString("<oaSimpleConstraintType::");
    buffer+=oaString(addr);
    buffer+=oaString("::");
    buffer+=oaString(sresult);
    buffer+=oaString(">");
    result=PyString_FromString((char*)(const char*)buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaSimpleConstraintType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaSimpleConstraintType v1;
    PyParamoaSimpleConstraintType v2;
    int convert_status1=PyoaSimpleConstraintType_Convert(ob1,&v1);
    int convert_status2=PyoaSimpleConstraintType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaSimpleConstraintType_Convert(PyObject* ob,PyParamoaSimpleConstraintType* result)
{
    if (ob == NULL) return 1;
    if (PyoaSimpleConstraintType_Check(ob)) {
        result->SetData(  ((PyoaSimpleConstraintTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaSimpleConstraintType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaSimpleConstraintType_FromoaSimpleConstraintType(oaSimpleConstraintType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaSimpleConstraintType_Type.tp_alloc(&PyoaSimpleConstraintType_Type,0);
        if (bself == NULL) return bself;
        PyoaSimpleConstraintTypeObject* self = (PyoaSimpleConstraintTypeObject*)bself;
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
static char oaSimpleConstraintType_getName_doc[] = 
"Class: oaSimpleConstraintType, Function: getName\n"
"  Paramegers: ()\n"
"    Calls: const oaString& getName() const\n"
"    Signature: getName|cref-oaString|\n"
"    BrowseData: 1\n"
"    This function returns the name associated with the encapsulated oaSimpleConstraintTypeEnum object.\n"
;

static PyObject*
oaSimpleConstraintType_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSimpleConstraintType data;
    int convert_status=PyoaSimpleConstraintType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSimpleConstraintTypeObject* self=(PyoaSimpleConstraintTypeObject*)ob;

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
static char oaSimpleConstraintType_oaSimpleConstraintTypeEnum_doc[] = 
"Class: oaSimpleConstraintType, Function: oaSimpleConstraintTypeEnum\n"
"  Paramegers: ()\n"
"    Calls: oaSimpleConstraintTypeEnum oaSimpleConstraintTypeEnum() const\n"
"    Signature: operator oaSimpleConstraintTypeEnum|simple-oaSimpleConstraintTypeEnum|\n"
"    BrowseData: 1\n"
"    This operator casts this oaSimpleConstraintType object into the corresponding oaSimpleConstraintTeypEnum.\n"
;

static PyObject*
oaSimpleConstraintType_oaSimpleConstraintTypeEnum(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaSimpleConstraintType data;
    int convert_status=PyoaSimpleConstraintType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaSimpleConstraintTypeObject* self=(PyoaSimpleConstraintTypeObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        oaSimpleConstraintTypeEnum result= (data.DataCall()->operator oaSimpleConstraintTypeEnum());
        return PyoaSimpleConstraintTypeEnum_FromoaSimpleConstraintTypeEnum(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaSimpleConstraintType_assign_doc[] = 
"Class: oaSimpleConstraintType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaSimpleConstraintType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaSimpleConstraintType data;
  int convert_status=PyoaSimpleConstraintType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaSimpleConstraintType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaSimpleConstraintType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaSimpleConstraintType_methodlist[] = {
    {"getName",(PyCFunction)oaSimpleConstraintType_getName,METH_VARARGS,oaSimpleConstraintType_getName_doc},
    {"oaSimpleConstraintTypeEnum",(PyCFunction)oaSimpleConstraintType_oaSimpleConstraintTypeEnum,METH_VARARGS,oaSimpleConstraintType_oaSimpleConstraintTypeEnum_doc},
    {"assign",(PyCFunction)oaSimpleConstraintType_tp_assign,METH_VARARGS,oaSimpleConstraintType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaSimpleConstraintType_doc[] = 
"Class: oaSimpleConstraintType\n"
"  The oaSimpleConstraintType class is an enum wrapper class for oaSimpleConstraintTypeEnum values.\n"
"  See Enum Wrappers in the Programmers Guide for a discussion of enum wrappers.\n"
"  oaSimpleConstraintTypeEnum\n"
"Constructors:\n"
"  Paramegers: (oaSimpleConstraintTypeEnum)\n"
"    Calls: oaSimpleConstraintType(oaSimpleConstraintTypeEnum typeIn)\n"
"    Signature: oaSimpleConstraintType||simple-oaSimpleConstraintTypeEnum,\n"
"    This function constructs an instance of an oaSimpleConstraintType class using the specified oaSimpleConstraintTypeEnum value.\n"
"    typeIn\n"
"    The simple constraint type.\n"
"  Paramegers: (oaString)\n"
"    Calls: oaSimpleConstraintType(const oaString& name)\n"
"    Signature: oaSimpleConstraintType||cref-oaString,\n"
"    This function creates an instance of an oaSimpleConstraintType class using the oaSimpleConstraintTypeEnum associated with the specified string name. This name must be defined in the legal set of names associated with oaSimpleConstraintTypeEnum.\n"
"    name\n"
"    The name of a simple constraint type.\n"
"    oacInvalidSimpleConstraintTypeName\n"
"  Paramegers: (oaSimpleConstraintType)\n"
"    Calls: (const oaSimpleConstraintType&)\n"
"    Signature: oaSimpleConstraintType||cref-oaSimpleConstraintType,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaSimpleConstraintType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaSimpleConstraintType",
    sizeof(PyoaSimpleConstraintTypeObject),
    0,
    (destructor)oaSimpleConstraintType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaSimpleConstraintType_tp_compare,	/* tp_compare */
    (reprfunc)oaSimpleConstraintType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaSimpleConstraintType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaSimpleConstraintType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    0,					/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaSimpleConstraintType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaSimpleConstraintType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaSimpleConstraintType_Type)<0) {
      printf("** PyType_Ready failed for: oaSimpleConstraintType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaSimpleConstraintType",
           (PyObject*)(&PyoaSimpleConstraintType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaSimpleConstraintType\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaSimpleConstraintTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaSimpleConstraintTypeEnum_Convert(PyObject* ob,PyParamoaSimpleConstraintTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacValidRoutingLayers")==0) { result->SetData(oacValidRoutingLayers); return 1;}
        if (strcasecmp(str,"oacValidRoutingVias")==0) { result->SetData(oacValidRoutingVias); return 1;}
        if (strcasecmp(str,"oacCumMetalAntenna")==0) { result->SetData(oacCumMetalAntenna); return 1;}
        if (strcasecmp(str,"oacCumViaAntenna")==0) { result->SetData(oacCumViaAntenna); return 1;}
        if (strcasecmp(str,"oacViaStackLimit")==0) { result->SetData(oacViaStackLimit); return 1;}
        if (strcasecmp(str,"oacHorizontalPlacementGridPitch")==0) { result->SetData(oacHorizontalPlacementGridPitch); return 1;}
        if (strcasecmp(str,"oacHorizontalPlacementGridOffset")==0) { result->SetData(oacHorizontalPlacementGridOffset); return 1;}
        if (strcasecmp(str,"oacVerticalPlacementGridPitch")==0) { result->SetData(oacVerticalPlacementGridPitch); return 1;}
        if (strcasecmp(str,"oacVerticalPlacementGridOffset")==0) { result->SetData(oacVerticalPlacementGridOffset); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaSimpleConstraintTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaSimpleConstraintTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaSimpleConstraintTypeEnum_FromoaSimpleConstraintTypeEnum(oaSimpleConstraintTypeEnum ob)
{
    if (ob==oacValidRoutingLayers) return PyString_FromString("oacValidRoutingLayers");
    if (ob==oacValidRoutingVias) return PyString_FromString("oacValidRoutingVias");
    if (ob==oacCumMetalAntenna) return PyString_FromString("oacCumMetalAntenna");
    if (ob==oacCumViaAntenna) return PyString_FromString("oacCumViaAntenna");
    if (ob==oacViaStackLimit) return PyString_FromString("oacViaStackLimit");
    if (ob==oacHorizontalPlacementGridPitch) return PyString_FromString("oacHorizontalPlacementGridPitch");
    if (ob==oacHorizontalPlacementGridOffset) return PyString_FromString("oacHorizontalPlacementGridOffset");
    if (ob==oacVerticalPlacementGridPitch) return PyString_FromString("oacVerticalPlacementGridPitch");
    if (ob==oacVerticalPlacementGridOffset) return PyString_FromString("oacVerticalPlacementGridOffset");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaSimpleConstraintTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaSimpleConstraintTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaSimpleConstraintTypeEnum_FromoaSimpleConstraintTypeEnum(oaSimpleConstraintTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaSimpleConstraintTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaSimpleConstraintTypeEnum_doc[] =
"Type convert function for enum: oaSimpleConstraintTypeEnum";
                               
static PyMethodDef PyoaSimpleConstraintTypeEnum_method =
  {"oaSimpleConstraintTypeEnum",(PyCFunction)PyoaSimpleConstraintTypeEnum_TypeFunction,METH_VARARGS,oaSimpleConstraintTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaSimpleConstraintTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacValidRoutingLayers");
    PyDict_SetItemString(mod_dict,"oacValidRoutingLayers",value);
    Py_DECREF(value);
    value=PyString_FromString("oacValidRoutingVias");
    PyDict_SetItemString(mod_dict,"oacValidRoutingVias",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCumMetalAntenna");
    PyDict_SetItemString(mod_dict,"oacCumMetalAntenna",value);
    Py_DECREF(value);
    value=PyString_FromString("oacCumViaAntenna");
    PyDict_SetItemString(mod_dict,"oacCumViaAntenna",value);
    Py_DECREF(value);
    value=PyString_FromString("oacViaStackLimit");
    PyDict_SetItemString(mod_dict,"oacViaStackLimit",value);
    Py_DECREF(value);
    value=PyString_FromString("oacHorizontalPlacementGridPitch");
    PyDict_SetItemString(mod_dict,"oacHorizontalPlacementGridPitch",value);
    Py_DECREF(value);
    value=PyString_FromString("oacHorizontalPlacementGridOffset");
    PyDict_SetItemString(mod_dict,"oacHorizontalPlacementGridOffset",value);
    Py_DECREF(value);
    value=PyString_FromString("oacVerticalPlacementGridPitch");
    PyDict_SetItemString(mod_dict,"oacVerticalPlacementGridPitch",value);
    Py_DECREF(value);
    value=PyString_FromString("oacVerticalPlacementGridOffset");
    PyDict_SetItemString(mod_dict,"oacVerticalPlacementGridOffset",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaSimpleConstraintTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaSimpleConstraintTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaSimpleConstraintTypeEnum\n");
        return -1;
    }
    Py_DECREF(value);
    return 0;
}
