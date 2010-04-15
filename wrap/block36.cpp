
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaImage
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaImage_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaImage_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaImageObject* self = (PyoaObserver_oaImageObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaImage(p1.Data());
            }
            else {
                pyv_oaObserver_oaImage* p=new pyv_oaObserver_oaImage(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaImage(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaImage* p=new pyv_oaObserver_oaImage(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaImage)
    {
        PyParamoaObserver_oaImage p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaImage_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaImage(p1.Data());
            }
            else {
                pyv_oaObserver_oaImage* p=new pyv_oaObserver_oaImage(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaImage, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaImage)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaImage_tp_dealloc(PyoaObserver_oaImageObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaImage*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaImage_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaImage value;
    int convert_status=PyoaObserver_oaImage_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaObserver_oaImage::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaImage_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaImage v1;
    PyParamoaObserver_oaImage v2;
    int convert_status1=PyoaObserver_oaImage_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaImage_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaImage_Convert(PyObject* ob,PyParamoaObserver_oaImage* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaImage_Check(ob)) {
        result->SetData( (oaObserver_oaImage*) ((PyoaObserver_oaImageObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaImage Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaImage_FromoaObserver_oaImage(oaObserver_oaImage* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaImage_Type.tp_alloc(&PyoaObserver_oaImage_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaImageObject* self = (PyoaObserver_oaImageObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaImage::pyv_oaObserver_oaImage(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaImage(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaImage::pyv_oaObserver_oaImage(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaImage(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaImage::pyv_oaObserver_oaImage(const oaObserver_oaImage& p)
 : pyob(NULL),
   oaObserver_oaImage(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaImage::onPostCreate(oaImage* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaImage::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaImage_FromoaImage(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaImage::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaImage::onPostModify(oaImage* p1,oaImageModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaImage::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaImage_FromoaImage(p1));
    PyTuple_SetItem(args,1,PyoaImageModTypeEnum_FromoaImageModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaImage::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaImage::onPreDestroy(oaImage* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaImage::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaImage_FromoaImage(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaImage::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaImage::onPreModify(oaImage* p1,oaImageModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaImage::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaImage_FromoaImage(p1));
    PyTuple_SetItem(args,1,PyoaImageModTypeEnum_FromoaImageModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaImage::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaImage_doc[] = 
"Class: oaObserver_oaImage\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaImage(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaImage||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaImage\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaImage(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaImage||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaImage\n"
"  Paramegers: (oaObserver_oaImage)\n"
"    Calls: (const oaObserver_oaImage&)\n"
"    Signature: oaObserver_oaImage||cref-oaObserver_oaImage,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaImage_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaImage",
    sizeof(PyoaObserver_oaImageObject),
    0,
    (destructor)oaObserver_oaImage_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaImage_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaImage_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaImage_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaImage_oaImageModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaImage_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaImage_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaImage_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaImage\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaImage",
           (PyObject*)(&PyoaObserver_oaImage_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaImage\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaInductor
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaInductor_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaInductor_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaInductorObject* self = (PyoaObserver_oaInductorObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaInductor(p1.Data());
            }
            else {
                pyv_oaObserver_oaInductor* p=new pyv_oaObserver_oaInductor(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaInductor(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaInductor* p=new pyv_oaObserver_oaInductor(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaInductor)
    {
        PyParamoaObserver_oaInductor p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaInductor_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaInductor(p1.Data());
            }
            else {
                pyv_oaObserver_oaInductor* p=new pyv_oaObserver_oaInductor(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaInductor, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaInductor)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaInductor_tp_dealloc(PyoaObserver_oaInductorObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaInductor*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaInductor_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaInductor value;
    int convert_status=PyoaObserver_oaInductor_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaObserver_oaInductor::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaInductor_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaInductor v1;
    PyParamoaObserver_oaInductor v2;
    int convert_status1=PyoaObserver_oaInductor_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaInductor_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaInductor_Convert(PyObject* ob,PyParamoaObserver_oaInductor* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaInductor_Check(ob)) {
        result->SetData( (oaObserver_oaInductor*) ((PyoaObserver_oaInductorObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaInductor Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaInductor_FromoaObserver_oaInductor(oaObserver_oaInductor* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaInductor_Type.tp_alloc(&PyoaObserver_oaInductor_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaInductorObject* self = (PyoaObserver_oaInductorObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaInductor::pyv_oaObserver_oaInductor(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaInductor(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaInductor::pyv_oaObserver_oaInductor(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaInductor(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaInductor::pyv_oaObserver_oaInductor(const oaObserver_oaInductor& p)
 : pyob(NULL),
   oaObserver_oaInductor(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInductor::onPostCreate(oaInductor* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInductor::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaInductor_FromoaInductor(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInductor::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInductor::onPostModify(oaInductor* p1,oaDeviceModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInductor::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaInductor_FromoaInductor(p1));
    PyTuple_SetItem(args,1,PyoaDeviceModTypeEnum_FromoaDeviceModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInductor::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInductor::onPreDestroy(oaInductor* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInductor::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaInductor_FromoaInductor(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInductor::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInductor::onPreModify(oaInductor* p1,oaDeviceModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInductor::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaInductor_FromoaInductor(p1));
    PyTuple_SetItem(args,1,PyoaDeviceModTypeEnum_FromoaDeviceModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInductor::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaInductor_doc[] = 
"Class: oaObserver_oaInductor\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaInductor(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaInductor||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaInductor\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaInductor(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaInductor||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaInductor\n"
"  Paramegers: (oaObserver_oaInductor)\n"
"    Calls: (const oaObserver_oaInductor&)\n"
"    Signature: oaObserver_oaInductor||cref-oaObserver_oaInductor,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaInductor_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaInductor",
    sizeof(PyoaObserver_oaInductorObject),
    0,
    (destructor)oaObserver_oaInductor_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaInductor_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaInductor_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaInductor_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaInductor_oaDeviceModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaInductor_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaInductor_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaInductor_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaInductor\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaInductor",
           (PyObject*)(&PyoaObserver_oaInductor_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaInductor\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaInstObject* self = (PyoaObserver_oaInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaInst* p=new pyv_oaObserver_oaInst(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaInst* p=new pyv_oaObserver_oaInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaInst)
    {
        PyParamoaObserver_oaInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaInst* p=new pyv_oaObserver_oaInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaInst_tp_dealloc(PyoaObserver_oaInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaInst value;
    int convert_status=PyoaObserver_oaInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaObserver_oaInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaInst v1;
    PyParamoaObserver_oaInst v2;
    int convert_status1=PyoaObserver_oaInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaInst_Convert(PyObject* ob,PyParamoaObserver_oaInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaInst_Check(ob)) {
        result->SetData( (oaObserver_oaInst*) ((PyoaObserver_oaInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaInst_FromoaObserver_oaInst(oaObserver_oaInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaInst_Type.tp_alloc(&PyoaObserver_oaInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaInstObject* self = (PyoaObserver_oaInstObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaInst::pyv_oaObserver_oaInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaInst::pyv_oaObserver_oaInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaInst::pyv_oaObserver_oaInst(const oaObserver_oaInst& p)
 : pyob(NULL),
   oaObserver_oaInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInst::onPostCreate(oaInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaInst_FromoaInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInst::onPostModify(oaInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaInst_FromoaInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInst::onPreDestroy(oaInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaInst_FromoaInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInst::onPreModify(oaInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaInst_FromoaInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaInst_doc[] = 
"Class: oaObserver_oaInst\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaInst\n"
"  Paramegers: (oaObserver_oaInst)\n"
"    Calls: (const oaObserver_oaInst&)\n"
"    Signature: oaObserver_oaInst||cref-oaObserver_oaInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaInst",
    sizeof(PyoaObserver_oaInstObject),
    0,
    (destructor)oaObserver_oaInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaInst",
           (PyObject*)(&PyoaObserver_oaInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaInstAttrDisplay
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaInstAttrDisplay_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaInstAttrDisplay_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaInstAttrDisplayObject* self = (PyoaObserver_oaInstAttrDisplayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaInstAttrDisplay(p1.Data());
            }
            else {
                pyv_oaObserver_oaInstAttrDisplay* p=new pyv_oaObserver_oaInstAttrDisplay(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaInstAttrDisplay(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaInstAttrDisplay* p=new pyv_oaObserver_oaInstAttrDisplay(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaInstAttrDisplay)
    {
        PyParamoaObserver_oaInstAttrDisplay p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaInstAttrDisplay_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaInstAttrDisplay(p1.Data());
            }
            else {
                pyv_oaObserver_oaInstAttrDisplay* p=new pyv_oaObserver_oaInstAttrDisplay(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaInstAttrDisplay, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaInstAttrDisplay)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaInstAttrDisplay_tp_dealloc(PyoaObserver_oaInstAttrDisplayObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaInstAttrDisplay*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaInstAttrDisplay_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaInstAttrDisplay value;
    int convert_status=PyoaObserver_oaInstAttrDisplay_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaObserver_oaInstAttrDisplay::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaInstAttrDisplay_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaInstAttrDisplay v1;
    PyParamoaObserver_oaInstAttrDisplay v2;
    int convert_status1=PyoaObserver_oaInstAttrDisplay_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaInstAttrDisplay_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaInstAttrDisplay_Convert(PyObject* ob,PyParamoaObserver_oaInstAttrDisplay* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaInstAttrDisplay_Check(ob)) {
        result->SetData( (oaObserver_oaInstAttrDisplay*) ((PyoaObserver_oaInstAttrDisplayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaInstAttrDisplay Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaInstAttrDisplay_FromoaObserver_oaInstAttrDisplay(oaObserver_oaInstAttrDisplay* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaInstAttrDisplay_Type.tp_alloc(&PyoaObserver_oaInstAttrDisplay_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaInstAttrDisplayObject* self = (PyoaObserver_oaInstAttrDisplayObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaInstAttrDisplay::pyv_oaObserver_oaInstAttrDisplay(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaInstAttrDisplay(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaInstAttrDisplay::pyv_oaObserver_oaInstAttrDisplay(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaInstAttrDisplay(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaInstAttrDisplay::pyv_oaObserver_oaInstAttrDisplay(const oaObserver_oaInstAttrDisplay& p)
 : pyob(NULL),
   oaObserver_oaInstAttrDisplay(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInstAttrDisplay::onPostCreate(oaInstAttrDisplay* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInstAttrDisplay::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaInstAttrDisplay_FromoaInstAttrDisplay(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInstAttrDisplay::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInstAttrDisplay::onPostModify(oaInstAttrDisplay* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInstAttrDisplay::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaInstAttrDisplay_FromoaInstAttrDisplay(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInstAttrDisplay::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInstAttrDisplay::onPreDestroy(oaInstAttrDisplay* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInstAttrDisplay::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaInstAttrDisplay_FromoaInstAttrDisplay(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInstAttrDisplay::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInstAttrDisplay::onPreModify(oaInstAttrDisplay* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInstAttrDisplay::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaInstAttrDisplay_FromoaInstAttrDisplay(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInstAttrDisplay::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaInstAttrDisplay_doc[] = 
"Class: oaObserver_oaInstAttrDisplay\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaInstAttrDisplay(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaInstAttrDisplay||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaInstAttrDisplay\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaInstAttrDisplay(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaInstAttrDisplay||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaInstAttrDisplay\n"
"  Paramegers: (oaObserver_oaInstAttrDisplay)\n"
"    Calls: (const oaObserver_oaInstAttrDisplay&)\n"
"    Signature: oaObserver_oaInstAttrDisplay||cref-oaObserver_oaInstAttrDisplay,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaInstAttrDisplay_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaInstAttrDisplay",
    sizeof(PyoaObserver_oaInstAttrDisplayObject),
    0,
    (destructor)oaObserver_oaInstAttrDisplay_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaInstAttrDisplay_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaInstAttrDisplay_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaInstAttrDisplay_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaInstAttrDisplay_oaShapeModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaInstAttrDisplay_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaInstAttrDisplay_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaInstAttrDisplay_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaInstAttrDisplay\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaInstAttrDisplay",
           (PyObject*)(&PyoaObserver_oaInstAttrDisplay_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaInstAttrDisplay\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaInstHeaderObject* self = (PyoaObserver_oaInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaInstHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaInstHeader* p=new pyv_oaObserver_oaInstHeader(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaInstHeader(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaInstHeader* p=new pyv_oaObserver_oaInstHeader(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaInstHeader)
    {
        PyParamoaObserver_oaInstHeader p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaInstHeader_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaInstHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaInstHeader* p=new pyv_oaObserver_oaInstHeader(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaInstHeader, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaInstHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaInstHeader_tp_dealloc(PyoaObserver_oaInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaInstHeader value;
    int convert_status=PyoaObserver_oaInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaInstHeader v1;
    PyParamoaObserver_oaInstHeader v2;
    int convert_status1=PyoaObserver_oaInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaInstHeader_Convert(PyObject* ob,PyParamoaObserver_oaInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaInstHeader_Check(ob)) {
        result->SetData( (oaObserver_oaInstHeader*) ((PyoaObserver_oaInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaInstHeader_FromoaObserver_oaInstHeader(oaObserver_oaInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaInstHeader_Type.tp_alloc(&PyoaObserver_oaInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaInstHeaderObject* self = (PyoaObserver_oaInstHeaderObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaInstHeader::pyv_oaObserver_oaInstHeader(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaInstHeader(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaInstHeader::pyv_oaObserver_oaInstHeader(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaInstHeader(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaInstHeader::pyv_oaObserver_oaInstHeader(const oaObserver_oaInstHeader& p)
 : pyob(NULL),
   oaObserver_oaInstHeader(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInstHeader::onPostCreate(oaInstHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInstHeader::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaInstHeader_FromoaInstHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInstHeader::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInstHeader::onPostModify(oaInstHeader* p1,oaInstHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInstHeader::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaInstHeader_FromoaInstHeader(p1));
    PyTuple_SetItem(args,1,PyoaInstHeaderModTypeEnum_FromoaInstHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInstHeader::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInstHeader::onPreDestroy(oaInstHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInstHeader::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaInstHeader_FromoaInstHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInstHeader::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInstHeader::onPreModify(oaInstHeader* p1,oaInstHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInstHeader::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaInstHeader_FromoaInstHeader(p1));
    PyTuple_SetItem(args,1,PyoaInstHeaderModTypeEnum_FromoaInstHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInstHeader::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaInstHeader_doc[] = 
"Class: oaObserver_oaInstHeader\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaInstHeader(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaInstHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaInstHeader\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaInstHeader(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaInstHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaInstHeader\n"
"  Paramegers: (oaObserver_oaInstHeader)\n"
"    Calls: (const oaObserver_oaInstHeader&)\n"
"    Signature: oaObserver_oaInstHeader||cref-oaObserver_oaInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaInstHeader",
    sizeof(PyoaObserver_oaInstHeaderObject),
    0,
    (destructor)oaObserver_oaInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaInstHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaInstHeader_oaInstHeaderModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaInstHeader",
           (PyObject*)(&PyoaObserver_oaInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaInstHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaInstPropDisplay
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaInstPropDisplay_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaInstPropDisplay_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaInstPropDisplayObject* self = (PyoaObserver_oaInstPropDisplayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaInstPropDisplay(p1.Data());
            }
            else {
                pyv_oaObserver_oaInstPropDisplay* p=new pyv_oaObserver_oaInstPropDisplay(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaInstPropDisplay(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaInstPropDisplay* p=new pyv_oaObserver_oaInstPropDisplay(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaInstPropDisplay)
    {
        PyParamoaObserver_oaInstPropDisplay p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaInstPropDisplay_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaInstPropDisplay(p1.Data());
            }
            else {
                pyv_oaObserver_oaInstPropDisplay* p=new pyv_oaObserver_oaInstPropDisplay(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaInstPropDisplay, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaInstPropDisplay)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaInstPropDisplay_tp_dealloc(PyoaObserver_oaInstPropDisplayObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaInstPropDisplay*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaInstPropDisplay_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaInstPropDisplay value;
    int convert_status=PyoaObserver_oaInstPropDisplay_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaObserver_oaInstPropDisplay::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaInstPropDisplay_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaInstPropDisplay v1;
    PyParamoaObserver_oaInstPropDisplay v2;
    int convert_status1=PyoaObserver_oaInstPropDisplay_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaInstPropDisplay_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaInstPropDisplay_Convert(PyObject* ob,PyParamoaObserver_oaInstPropDisplay* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaInstPropDisplay_Check(ob)) {
        result->SetData( (oaObserver_oaInstPropDisplay*) ((PyoaObserver_oaInstPropDisplayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaInstPropDisplay Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaInstPropDisplay_FromoaObserver_oaInstPropDisplay(oaObserver_oaInstPropDisplay* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaInstPropDisplay_Type.tp_alloc(&PyoaObserver_oaInstPropDisplay_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaInstPropDisplayObject* self = (PyoaObserver_oaInstPropDisplayObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaInstPropDisplay::pyv_oaObserver_oaInstPropDisplay(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaInstPropDisplay(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaInstPropDisplay::pyv_oaObserver_oaInstPropDisplay(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaInstPropDisplay(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaInstPropDisplay::pyv_oaObserver_oaInstPropDisplay(const oaObserver_oaInstPropDisplay& p)
 : pyob(NULL),
   oaObserver_oaInstPropDisplay(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInstPropDisplay::onPostCreate(oaInstPropDisplay* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInstPropDisplay::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaInstPropDisplay_FromoaInstPropDisplay(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInstPropDisplay::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInstPropDisplay::onPostModify(oaInstPropDisplay* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInstPropDisplay::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaInstPropDisplay_FromoaInstPropDisplay(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInstPropDisplay::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInstPropDisplay::onPreDestroy(oaInstPropDisplay* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInstPropDisplay::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaInstPropDisplay_FromoaInstPropDisplay(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInstPropDisplay::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInstPropDisplay::onPreModify(oaInstPropDisplay* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInstPropDisplay::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaInstPropDisplay_FromoaInstPropDisplay(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInstPropDisplay::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaInstPropDisplay_doc[] = 
"Class: oaObserver_oaInstPropDisplay\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaInstPropDisplay(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaInstPropDisplay||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaInstPropDisplay\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaInstPropDisplay(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaInstPropDisplay||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaInstPropDisplay\n"
"  Paramegers: (oaObserver_oaInstPropDisplay)\n"
"    Calls: (const oaObserver_oaInstPropDisplay&)\n"
"    Signature: oaObserver_oaInstPropDisplay||cref-oaObserver_oaInstPropDisplay,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaInstPropDisplay_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaInstPropDisplay",
    sizeof(PyoaObserver_oaInstPropDisplayObject),
    0,
    (destructor)oaObserver_oaInstPropDisplay_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaInstPropDisplay_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaInstPropDisplay_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaInstPropDisplay_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaInstPropDisplay_oaShapeModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaInstPropDisplay_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaInstPropDisplay_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaInstPropDisplay_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaInstPropDisplay\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaInstPropDisplay",
           (PyObject*)(&PyoaObserver_oaInstPropDisplay_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaInstPropDisplay\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaInstTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaInstTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaInstTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaInstTermObject* self = (PyoaObserver_oaInstTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaInstTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaInstTerm* p=new pyv_oaObserver_oaInstTerm(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaInstTerm(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaInstTerm* p=new pyv_oaObserver_oaInstTerm(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaInstTerm)
    {
        PyParamoaObserver_oaInstTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaInstTerm_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaInstTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaInstTerm* p=new pyv_oaObserver_oaInstTerm(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaInstTerm, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaInstTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaInstTerm_tp_dealloc(PyoaObserver_oaInstTermObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaInstTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaInstTerm_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaInstTerm value;
    int convert_status=PyoaObserver_oaInstTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaObserver_oaInstTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaInstTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaInstTerm v1;
    PyParamoaObserver_oaInstTerm v2;
    int convert_status1=PyoaObserver_oaInstTerm_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaInstTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaInstTerm_Convert(PyObject* ob,PyParamoaObserver_oaInstTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaInstTerm_Check(ob)) {
        result->SetData( (oaObserver_oaInstTerm*) ((PyoaObserver_oaInstTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaInstTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaInstTerm_FromoaObserver_oaInstTerm(oaObserver_oaInstTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaInstTerm_Type.tp_alloc(&PyoaObserver_oaInstTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaInstTermObject* self = (PyoaObserver_oaInstTermObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaInstTerm::pyv_oaObserver_oaInstTerm(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaInstTerm(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaInstTerm::pyv_oaObserver_oaInstTerm(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaInstTerm(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaInstTerm::pyv_oaObserver_oaInstTerm(const oaObserver_oaInstTerm& p)
 : pyob(NULL),
   oaObserver_oaInstTerm(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInstTerm::onPostCreate(oaInstTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInstTerm::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaInstTerm_FromoaInstTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInstTerm::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInstTerm::onPostModify(oaInstTerm* p1,oaInstTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInstTerm::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaInstTerm_FromoaInstTerm(p1));
    PyTuple_SetItem(args,1,PyoaInstTermModTypeEnum_FromoaInstTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInstTerm::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInstTerm::onPreDestroy(oaInstTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInstTerm::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaInstTerm_FromoaInstTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInstTerm::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInstTerm::onPreModify(oaInstTerm* p1,oaInstTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInstTerm::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaInstTerm_FromoaInstTerm(p1));
    PyTuple_SetItem(args,1,PyoaInstTermModTypeEnum_FromoaInstTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInstTerm::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaInstTerm_doc[] = 
"Class: oaObserver_oaInstTerm\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaInstTerm(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaInstTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaInstTerm\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaInstTerm(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaInstTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaInstTerm\n"
"  Paramegers: (oaObserver_oaInstTerm)\n"
"    Calls: (const oaObserver_oaInstTerm&)\n"
"    Signature: oaObserver_oaInstTerm||cref-oaObserver_oaInstTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaInstTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaInstTerm",
    sizeof(PyoaObserver_oaInstTermObject),
    0,
    (destructor)oaObserver_oaInstTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaInstTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaInstTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaInstTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaInstTerm_oaInstTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaInstTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaInstTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaInstTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaInstTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaInstTerm",
           (PyObject*)(&PyoaObserver_oaInstTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaInstTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaInt1DTblValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaInt1DTblValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaInt1DTblValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaInt1DTblValueObject* self = (PyoaObserver_oaInt1DTblValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaInt1DTblValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaInt1DTblValue* p=new pyv_oaObserver_oaInt1DTblValue(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaInt1DTblValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaInt1DTblValue* p=new pyv_oaObserver_oaInt1DTblValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaInt1DTblValue)
    {
        PyParamoaObserver_oaInt1DTblValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaInt1DTblValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaInt1DTblValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaInt1DTblValue* p=new pyv_oaObserver_oaInt1DTblValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaInt1DTblValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaInt1DTblValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaInt1DTblValue_tp_dealloc(PyoaObserver_oaInt1DTblValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaInt1DTblValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaInt1DTblValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaInt1DTblValue value;
    int convert_status=PyoaObserver_oaInt1DTblValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaInt1DTblValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaInt1DTblValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaInt1DTblValue v1;
    PyParamoaObserver_oaInt1DTblValue v2;
    int convert_status1=PyoaObserver_oaInt1DTblValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaInt1DTblValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaInt1DTblValue_Convert(PyObject* ob,PyParamoaObserver_oaInt1DTblValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaInt1DTblValue_Check(ob)) {
        result->SetData( (oaObserver_oaInt1DTblValue*) ((PyoaObserver_oaInt1DTblValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaInt1DTblValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaInt1DTblValue_FromoaObserver_oaInt1DTblValue(oaObserver_oaInt1DTblValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaInt1DTblValue_Type.tp_alloc(&PyoaObserver_oaInt1DTblValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaInt1DTblValueObject* self = (PyoaObserver_oaInt1DTblValueObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaInt1DTblValue::pyv_oaObserver_oaInt1DTblValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaInt1DTblValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaInt1DTblValue::pyv_oaObserver_oaInt1DTblValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaInt1DTblValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaInt1DTblValue::pyv_oaObserver_oaInt1DTblValue(const oaObserver_oaInt1DTblValue& p)
 : pyob(NULL),
   oaObserver_oaInt1DTblValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInt1DTblValue::onPostCreate(oaInt1DTblValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInt1DTblValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaInt1DTblValue_FromoaInt1DTblValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInt1DTblValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInt1DTblValue::onPostModify(oaInt1DTblValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInt1DTblValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaInt1DTblValue_FromoaInt1DTblValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInt1DTblValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInt1DTblValue::onPreDestroy(oaInt1DTblValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInt1DTblValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaInt1DTblValue_FromoaInt1DTblValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInt1DTblValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInt1DTblValue::onPreModify(oaInt1DTblValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInt1DTblValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaInt1DTblValue_FromoaInt1DTblValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInt1DTblValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaInt1DTblValue_doc[] = 
"Class: oaObserver_oaInt1DTblValue\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaInt1DTblValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaInt1DTblValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaInt1DTblValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaInt1DTblValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaInt1DTblValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaInt1DTblValue\n"
"  Paramegers: (oaObserver_oaInt1DTblValue)\n"
"    Calls: (const oaObserver_oaInt1DTblValue&)\n"
"    Signature: oaObserver_oaInt1DTblValue||cref-oaObserver_oaInt1DTblValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaInt1DTblValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaInt1DTblValue",
    sizeof(PyoaObserver_oaInt1DTblValueObject),
    0,
    (destructor)oaObserver_oaInt1DTblValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaInt1DTblValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaInt1DTblValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaInt1DTblValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaInt1DTblValue_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaInt1DTblValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaInt1DTblValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaInt1DTblValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaInt1DTblValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaInt1DTblValue",
           (PyObject*)(&PyoaObserver_oaInt1DTblValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaInt1DTblValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaInt2DTblValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaInt2DTblValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaInt2DTblValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaInt2DTblValueObject* self = (PyoaObserver_oaInt2DTblValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaInt2DTblValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaInt2DTblValue* p=new pyv_oaObserver_oaInt2DTblValue(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaInt2DTblValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaInt2DTblValue* p=new pyv_oaObserver_oaInt2DTblValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaInt2DTblValue)
    {
        PyParamoaObserver_oaInt2DTblValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaInt2DTblValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaInt2DTblValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaInt2DTblValue* p=new pyv_oaObserver_oaInt2DTblValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaInt2DTblValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaInt2DTblValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaInt2DTblValue_tp_dealloc(PyoaObserver_oaInt2DTblValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaInt2DTblValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaInt2DTblValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaInt2DTblValue value;
    int convert_status=PyoaObserver_oaInt2DTblValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaInt2DTblValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaInt2DTblValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaInt2DTblValue v1;
    PyParamoaObserver_oaInt2DTblValue v2;
    int convert_status1=PyoaObserver_oaInt2DTblValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaInt2DTblValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaInt2DTblValue_Convert(PyObject* ob,PyParamoaObserver_oaInt2DTblValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaInt2DTblValue_Check(ob)) {
        result->SetData( (oaObserver_oaInt2DTblValue*) ((PyoaObserver_oaInt2DTblValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaInt2DTblValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaInt2DTblValue_FromoaObserver_oaInt2DTblValue(oaObserver_oaInt2DTblValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaInt2DTblValue_Type.tp_alloc(&PyoaObserver_oaInt2DTblValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaInt2DTblValueObject* self = (PyoaObserver_oaInt2DTblValueObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaInt2DTblValue::pyv_oaObserver_oaInt2DTblValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaInt2DTblValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaInt2DTblValue::pyv_oaObserver_oaInt2DTblValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaInt2DTblValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaInt2DTblValue::pyv_oaObserver_oaInt2DTblValue(const oaObserver_oaInt2DTblValue& p)
 : pyob(NULL),
   oaObserver_oaInt2DTblValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInt2DTblValue::onPostCreate(oaInt2DTblValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInt2DTblValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaInt2DTblValue_FromoaInt2DTblValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInt2DTblValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInt2DTblValue::onPostModify(oaInt2DTblValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInt2DTblValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaInt2DTblValue_FromoaInt2DTblValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInt2DTblValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInt2DTblValue::onPreDestroy(oaInt2DTblValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInt2DTblValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaInt2DTblValue_FromoaInt2DTblValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInt2DTblValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaInt2DTblValue::onPreModify(oaInt2DTblValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaInt2DTblValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaInt2DTblValue_FromoaInt2DTblValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaInt2DTblValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaInt2DTblValue_doc[] = 
"Class: oaObserver_oaInt2DTblValue\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaInt2DTblValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaInt2DTblValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaInt2DTblValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaInt2DTblValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaInt2DTblValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaInt2DTblValue\n"
"  Paramegers: (oaObserver_oaInt2DTblValue)\n"
"    Calls: (const oaObserver_oaInt2DTblValue&)\n"
"    Signature: oaObserver_oaInt2DTblValue||cref-oaObserver_oaInt2DTblValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaInt2DTblValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaInt2DTblValue",
    sizeof(PyoaObserver_oaInt2DTblValueObject),
    0,
    (destructor)oaObserver_oaInt2DTblValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaInt2DTblValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaInt2DTblValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaInt2DTblValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaInt2DTblValue_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaInt2DTblValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaInt2DTblValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaInt2DTblValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaInt2DTblValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaInt2DTblValue",
           (PyObject*)(&PyoaObserver_oaInt2DTblValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaInt2DTblValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaIntDualIntArrayTblValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaIntDualIntArrayTblValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaIntDualIntArrayTblValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaIntDualIntArrayTblValueObject* self = (PyoaObserver_oaIntDualIntArrayTblValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaIntDualIntArrayTblValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaIntDualIntArrayTblValue* p=new pyv_oaObserver_oaIntDualIntArrayTblValue(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaIntDualIntArrayTblValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaIntDualIntArrayTblValue* p=new pyv_oaObserver_oaIntDualIntArrayTblValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaIntDualIntArrayTblValue)
    {
        PyParamoaObserver_oaIntDualIntArrayTblValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaIntDualIntArrayTblValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaIntDualIntArrayTblValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaIntDualIntArrayTblValue* p=new pyv_oaObserver_oaIntDualIntArrayTblValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaIntDualIntArrayTblValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaIntDualIntArrayTblValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaIntDualIntArrayTblValue_tp_dealloc(PyoaObserver_oaIntDualIntArrayTblValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaIntDualIntArrayTblValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaIntDualIntArrayTblValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaIntDualIntArrayTblValue value;
    int convert_status=PyoaObserver_oaIntDualIntArrayTblValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[58];
    sprintf(buffer,"<oaObserver_oaIntDualIntArrayTblValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaIntDualIntArrayTblValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaIntDualIntArrayTblValue v1;
    PyParamoaObserver_oaIntDualIntArrayTblValue v2;
    int convert_status1=PyoaObserver_oaIntDualIntArrayTblValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaIntDualIntArrayTblValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaIntDualIntArrayTblValue_Convert(PyObject* ob,PyParamoaObserver_oaIntDualIntArrayTblValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaIntDualIntArrayTblValue_Check(ob)) {
        result->SetData( (oaObserver_oaIntDualIntArrayTblValue*) ((PyoaObserver_oaIntDualIntArrayTblValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaIntDualIntArrayTblValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaIntDualIntArrayTblValue_FromoaObserver_oaIntDualIntArrayTblValue(oaObserver_oaIntDualIntArrayTblValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaIntDualIntArrayTblValue_Type.tp_alloc(&PyoaObserver_oaIntDualIntArrayTblValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaIntDualIntArrayTblValueObject* self = (PyoaObserver_oaIntDualIntArrayTblValueObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaIntDualIntArrayTblValue::pyv_oaObserver_oaIntDualIntArrayTblValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaIntDualIntArrayTblValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaIntDualIntArrayTblValue::pyv_oaObserver_oaIntDualIntArrayTblValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaIntDualIntArrayTblValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaIntDualIntArrayTblValue::pyv_oaObserver_oaIntDualIntArrayTblValue(const oaObserver_oaIntDualIntArrayTblValue& p)
 : pyob(NULL),
   oaObserver_oaIntDualIntArrayTblValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntDualIntArrayTblValue::onPostCreate(oaIntDualIntArrayTblValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntDualIntArrayTblValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaIntDualIntArrayTblValue_FromoaIntDualIntArrayTblValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntDualIntArrayTblValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntDualIntArrayTblValue::onPostModify(oaIntDualIntArrayTblValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntDualIntArrayTblValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaIntDualIntArrayTblValue_FromoaIntDualIntArrayTblValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntDualIntArrayTblValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntDualIntArrayTblValue::onPreDestroy(oaIntDualIntArrayTblValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntDualIntArrayTblValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaIntDualIntArrayTblValue_FromoaIntDualIntArrayTblValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntDualIntArrayTblValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntDualIntArrayTblValue::onPreModify(oaIntDualIntArrayTblValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntDualIntArrayTblValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaIntDualIntArrayTblValue_FromoaIntDualIntArrayTblValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntDualIntArrayTblValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaIntDualIntArrayTblValue_doc[] = 
"Class: oaObserver_oaIntDualIntArrayTblValue\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaIntDualIntArrayTblValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaIntDualIntArrayTblValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaIntDualIntArrayTblValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaIntDualIntArrayTblValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaIntDualIntArrayTblValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaIntDualIntArrayTblValue\n"
"  Paramegers: (oaObserver_oaIntDualIntArrayTblValue)\n"
"    Calls: (const oaObserver_oaIntDualIntArrayTblValue&)\n"
"    Signature: oaObserver_oaIntDualIntArrayTblValue||cref-oaObserver_oaIntDualIntArrayTblValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaIntDualIntArrayTblValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaIntDualIntArrayTblValue",
    sizeof(PyoaObserver_oaIntDualIntArrayTblValueObject),
    0,
    (destructor)oaObserver_oaIntDualIntArrayTblValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaIntDualIntArrayTblValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaIntDualIntArrayTblValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaIntDualIntArrayTblValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaIntDualIntArrayTblValue_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaIntDualIntArrayTblValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaIntDualIntArrayTblValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaIntDualIntArrayTblValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaIntDualIntArrayTblValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaIntDualIntArrayTblValue",
           (PyObject*)(&PyoaObserver_oaIntDualIntArrayTblValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaIntDualIntArrayTblValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaIntFltTblValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaIntFltTblValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaIntFltTblValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaIntFltTblValueObject* self = (PyoaObserver_oaIntFltTblValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaIntFltTblValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaIntFltTblValue* p=new pyv_oaObserver_oaIntFltTblValue(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaIntFltTblValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaIntFltTblValue* p=new pyv_oaObserver_oaIntFltTblValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaIntFltTblValue)
    {
        PyParamoaObserver_oaIntFltTblValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaIntFltTblValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaIntFltTblValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaIntFltTblValue* p=new pyv_oaObserver_oaIntFltTblValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaIntFltTblValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaIntFltTblValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaIntFltTblValue_tp_dealloc(PyoaObserver_oaIntFltTblValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaIntFltTblValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaIntFltTblValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaIntFltTblValue value;
    int convert_status=PyoaObserver_oaIntFltTblValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaObserver_oaIntFltTblValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaIntFltTblValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaIntFltTblValue v1;
    PyParamoaObserver_oaIntFltTblValue v2;
    int convert_status1=PyoaObserver_oaIntFltTblValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaIntFltTblValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaIntFltTblValue_Convert(PyObject* ob,PyParamoaObserver_oaIntFltTblValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaIntFltTblValue_Check(ob)) {
        result->SetData( (oaObserver_oaIntFltTblValue*) ((PyoaObserver_oaIntFltTblValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaIntFltTblValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaIntFltTblValue_FromoaObserver_oaIntFltTblValue(oaObserver_oaIntFltTblValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaIntFltTblValue_Type.tp_alloc(&PyoaObserver_oaIntFltTblValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaIntFltTblValueObject* self = (PyoaObserver_oaIntFltTblValueObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaIntFltTblValue::pyv_oaObserver_oaIntFltTblValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaIntFltTblValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaIntFltTblValue::pyv_oaObserver_oaIntFltTblValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaIntFltTblValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaIntFltTblValue::pyv_oaObserver_oaIntFltTblValue(const oaObserver_oaIntFltTblValue& p)
 : pyob(NULL),
   oaObserver_oaIntFltTblValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntFltTblValue::onPostCreate(oaIntFltTblValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntFltTblValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaIntFltTblValue_FromoaIntFltTblValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntFltTblValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntFltTblValue::onPostModify(oaIntFltTblValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntFltTblValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaIntFltTblValue_FromoaIntFltTblValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntFltTblValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntFltTblValue::onPreDestroy(oaIntFltTblValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntFltTblValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaIntFltTblValue_FromoaIntFltTblValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntFltTblValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntFltTblValue::onPreModify(oaIntFltTblValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntFltTblValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaIntFltTblValue_FromoaIntFltTblValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntFltTblValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaIntFltTblValue_doc[] = 
"Class: oaObserver_oaIntFltTblValue\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaIntFltTblValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaIntFltTblValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaIntFltTblValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaIntFltTblValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaIntFltTblValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaIntFltTblValue\n"
"  Paramegers: (oaObserver_oaIntFltTblValue)\n"
"    Calls: (const oaObserver_oaIntFltTblValue&)\n"
"    Signature: oaObserver_oaIntFltTblValue||cref-oaObserver_oaIntFltTblValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaIntFltTblValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaIntFltTblValue",
    sizeof(PyoaObserver_oaIntFltTblValueObject),
    0,
    (destructor)oaObserver_oaIntFltTblValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaIntFltTblValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaIntFltTblValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaIntFltTblValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaIntFltTblValue_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaIntFltTblValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaIntFltTblValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaIntFltTblValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaIntFltTblValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaIntFltTblValue",
           (PyObject*)(&PyoaObserver_oaIntFltTblValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaIntFltTblValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaIntProp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaIntProp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaIntProp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaIntPropObject* self = (PyoaObserver_oaIntPropObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaIntProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaIntProp* p=new pyv_oaObserver_oaIntProp(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaIntProp(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaIntProp* p=new pyv_oaObserver_oaIntProp(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaIntProp)
    {
        PyParamoaObserver_oaIntProp p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaIntProp_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaIntProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaIntProp* p=new pyv_oaObserver_oaIntProp(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaIntProp, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaIntProp)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaIntProp_tp_dealloc(PyoaObserver_oaIntPropObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaIntProp*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaIntProp_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaIntProp value;
    int convert_status=PyoaObserver_oaIntProp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaObserver_oaIntProp::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaIntProp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaIntProp v1;
    PyParamoaObserver_oaIntProp v2;
    int convert_status1=PyoaObserver_oaIntProp_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaIntProp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaIntProp_Convert(PyObject* ob,PyParamoaObserver_oaIntProp* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaIntProp_Check(ob)) {
        result->SetData( (oaObserver_oaIntProp*) ((PyoaObserver_oaIntPropObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaIntProp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaIntProp_FromoaObserver_oaIntProp(oaObserver_oaIntProp* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaIntProp_Type.tp_alloc(&PyoaObserver_oaIntProp_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaIntPropObject* self = (PyoaObserver_oaIntPropObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaIntProp::pyv_oaObserver_oaIntProp(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaIntProp(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaIntProp::pyv_oaObserver_oaIntProp(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaIntProp(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaIntProp::pyv_oaObserver_oaIntProp(const oaObserver_oaIntProp& p)
 : pyob(NULL),
   oaObserver_oaIntProp(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntProp::onPostCreate(oaIntProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntProp::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaIntProp_FromoaIntProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntProp::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntProp::onPostModify(oaIntProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntProp::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaIntProp_FromoaIntProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntProp::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntProp::onPreDestroy(oaIntProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntProp::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaIntProp_FromoaIntProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntProp::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntProp::onPreModify(oaIntProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntProp::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaIntProp_FromoaIntProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntProp::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaIntProp_doc[] = 
"Class: oaObserver_oaIntProp\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaIntProp(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaIntProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaIntProp\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaIntProp(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaIntProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaIntProp\n"
"  Paramegers: (oaObserver_oaIntProp)\n"
"    Calls: (const oaObserver_oaIntProp&)\n"
"    Signature: oaObserver_oaIntProp||cref-oaObserver_oaIntProp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaIntProp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaIntProp",
    sizeof(PyoaObserver_oaIntPropObject),
    0,
    (destructor)oaObserver_oaIntProp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaIntProp_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaIntProp_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaIntProp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaIntProp_oaPropModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaIntProp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaIntProp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaIntProp_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaIntProp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaIntProp",
           (PyObject*)(&PyoaObserver_oaIntProp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaIntProp\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaIntRangeProp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaIntRangeProp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaIntRangeProp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaIntRangePropObject* self = (PyoaObserver_oaIntRangePropObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaIntRangeProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaIntRangeProp* p=new pyv_oaObserver_oaIntRangeProp(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaIntRangeProp(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaIntRangeProp* p=new pyv_oaObserver_oaIntRangeProp(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaIntRangeProp)
    {
        PyParamoaObserver_oaIntRangeProp p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaIntRangeProp_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaIntRangeProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaIntRangeProp* p=new pyv_oaObserver_oaIntRangeProp(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaIntRangeProp, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaIntRangeProp)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaIntRangeProp_tp_dealloc(PyoaObserver_oaIntRangePropObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaIntRangeProp*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaIntRangeProp_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaIntRangeProp value;
    int convert_status=PyoaObserver_oaIntRangeProp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaIntRangeProp::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaIntRangeProp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaIntRangeProp v1;
    PyParamoaObserver_oaIntRangeProp v2;
    int convert_status1=PyoaObserver_oaIntRangeProp_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaIntRangeProp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaIntRangeProp_Convert(PyObject* ob,PyParamoaObserver_oaIntRangeProp* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaIntRangeProp_Check(ob)) {
        result->SetData( (oaObserver_oaIntRangeProp*) ((PyoaObserver_oaIntRangePropObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaIntRangeProp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaIntRangeProp_FromoaObserver_oaIntRangeProp(oaObserver_oaIntRangeProp* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaIntRangeProp_Type.tp_alloc(&PyoaObserver_oaIntRangeProp_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaIntRangePropObject* self = (PyoaObserver_oaIntRangePropObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaIntRangeProp::pyv_oaObserver_oaIntRangeProp(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaIntRangeProp(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaIntRangeProp::pyv_oaObserver_oaIntRangeProp(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaIntRangeProp(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaIntRangeProp::pyv_oaObserver_oaIntRangeProp(const oaObserver_oaIntRangeProp& p)
 : pyob(NULL),
   oaObserver_oaIntRangeProp(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntRangeProp::onPostCreate(oaIntRangeProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntRangeProp::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaIntRangeProp_FromoaIntRangeProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntRangeProp::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntRangeProp::onPostModify(oaIntRangeProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntRangeProp::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaIntRangeProp_FromoaIntRangeProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntRangeProp::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntRangeProp::onPreDestroy(oaIntRangeProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntRangeProp::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaIntRangeProp_FromoaIntRangeProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntRangeProp::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntRangeProp::onPreModify(oaIntRangeProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntRangeProp::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaIntRangeProp_FromoaIntRangeProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntRangeProp::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaIntRangeProp_doc[] = 
"Class: oaObserver_oaIntRangeProp\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaIntRangeProp(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaIntRangeProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaIntRangeProp\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaIntRangeProp(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaIntRangeProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaIntRangeProp\n"
"  Paramegers: (oaObserver_oaIntRangeProp)\n"
"    Calls: (const oaObserver_oaIntRangeProp&)\n"
"    Signature: oaObserver_oaIntRangeProp||cref-oaObserver_oaIntRangeProp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaIntRangeProp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaIntRangeProp",
    sizeof(PyoaObserver_oaIntRangePropObject),
    0,
    (destructor)oaObserver_oaIntRangeProp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaIntRangeProp_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaIntRangeProp_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaIntRangeProp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaIntRangeProp_oaPropModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaIntRangeProp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaIntRangeProp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaIntRangeProp_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaIntRangeProp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaIntRangeProp",
           (PyObject*)(&PyoaObserver_oaIntRangeProp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaIntRangeProp\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaIntRangeValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaIntRangeValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaIntRangeValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaIntRangeValueObject* self = (PyoaObserver_oaIntRangeValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaIntRangeValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaIntRangeValue* p=new pyv_oaObserver_oaIntRangeValue(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaIntRangeValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaIntRangeValue* p=new pyv_oaObserver_oaIntRangeValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaIntRangeValue)
    {
        PyParamoaObserver_oaIntRangeValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaIntRangeValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaIntRangeValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaIntRangeValue* p=new pyv_oaObserver_oaIntRangeValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaIntRangeValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaIntRangeValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaIntRangeValue_tp_dealloc(PyoaObserver_oaIntRangeValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaIntRangeValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaIntRangeValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaIntRangeValue value;
    int convert_status=PyoaObserver_oaIntRangeValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaIntRangeValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaIntRangeValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaIntRangeValue v1;
    PyParamoaObserver_oaIntRangeValue v2;
    int convert_status1=PyoaObserver_oaIntRangeValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaIntRangeValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaIntRangeValue_Convert(PyObject* ob,PyParamoaObserver_oaIntRangeValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaIntRangeValue_Check(ob)) {
        result->SetData( (oaObserver_oaIntRangeValue*) ((PyoaObserver_oaIntRangeValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaIntRangeValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaIntRangeValue_FromoaObserver_oaIntRangeValue(oaObserver_oaIntRangeValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaIntRangeValue_Type.tp_alloc(&PyoaObserver_oaIntRangeValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaIntRangeValueObject* self = (PyoaObserver_oaIntRangeValueObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaIntRangeValue::pyv_oaObserver_oaIntRangeValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaIntRangeValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaIntRangeValue::pyv_oaObserver_oaIntRangeValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaIntRangeValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaIntRangeValue::pyv_oaObserver_oaIntRangeValue(const oaObserver_oaIntRangeValue& p)
 : pyob(NULL),
   oaObserver_oaIntRangeValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntRangeValue::onPostCreate(oaIntRangeValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntRangeValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaIntRangeValue_FromoaIntRangeValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntRangeValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntRangeValue::onPostModify(oaIntRangeValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntRangeValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaIntRangeValue_FromoaIntRangeValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntRangeValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntRangeValue::onPreDestroy(oaIntRangeValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntRangeValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaIntRangeValue_FromoaIntRangeValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntRangeValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntRangeValue::onPreModify(oaIntRangeValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntRangeValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaIntRangeValue_FromoaIntRangeValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntRangeValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaIntRangeValue_doc[] = 
"Class: oaObserver_oaIntRangeValue\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaIntRangeValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaIntRangeValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaIntRangeValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaIntRangeValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaIntRangeValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaIntRangeValue\n"
"  Paramegers: (oaObserver_oaIntRangeValue)\n"
"    Calls: (const oaObserver_oaIntRangeValue&)\n"
"    Signature: oaObserver_oaIntRangeValue||cref-oaObserver_oaIntRangeValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaIntRangeValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaIntRangeValue",
    sizeof(PyoaObserver_oaIntRangeValueObject),
    0,
    (destructor)oaObserver_oaIntRangeValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaIntRangeValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaIntRangeValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaIntRangeValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaIntRangeValue_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaIntRangeValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaIntRangeValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaIntRangeValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaIntRangeValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaIntRangeValue",
           (PyObject*)(&PyoaObserver_oaIntRangeValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaIntRangeValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaIntValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaIntValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaIntValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaIntValueObject* self = (PyoaObserver_oaIntValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaIntValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaIntValue* p=new pyv_oaObserver_oaIntValue(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaIntValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaIntValue* p=new pyv_oaObserver_oaIntValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaIntValue)
    {
        PyParamoaObserver_oaIntValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaIntValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaIntValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaIntValue* p=new pyv_oaObserver_oaIntValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaIntValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaIntValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaIntValue_tp_dealloc(PyoaObserver_oaIntValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaIntValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaIntValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaIntValue value;
    int convert_status=PyoaObserver_oaIntValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaObserver_oaIntValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaIntValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaIntValue v1;
    PyParamoaObserver_oaIntValue v2;
    int convert_status1=PyoaObserver_oaIntValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaIntValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaIntValue_Convert(PyObject* ob,PyParamoaObserver_oaIntValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaIntValue_Check(ob)) {
        result->SetData( (oaObserver_oaIntValue*) ((PyoaObserver_oaIntValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaIntValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaIntValue_FromoaObserver_oaIntValue(oaObserver_oaIntValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaIntValue_Type.tp_alloc(&PyoaObserver_oaIntValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaIntValueObject* self = (PyoaObserver_oaIntValueObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaIntValue::pyv_oaObserver_oaIntValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaIntValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaIntValue::pyv_oaObserver_oaIntValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaIntValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaIntValue::pyv_oaObserver_oaIntValue(const oaObserver_oaIntValue& p)
 : pyob(NULL),
   oaObserver_oaIntValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntValue::onPostCreate(oaIntValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaIntValue_FromoaIntValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntValue::onPostModify(oaIntValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaIntValue_FromoaIntValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntValue::onPreDestroy(oaIntValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaIntValue_FromoaIntValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaIntValue::onPreModify(oaIntValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaIntValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaIntValue_FromoaIntValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaIntValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaIntValue_doc[] = 
"Class: oaObserver_oaIntValue\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaIntValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaIntValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaIntValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaIntValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaIntValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaIntValue\n"
"  Paramegers: (oaObserver_oaIntValue)\n"
"    Calls: (const oaObserver_oaIntValue&)\n"
"    Signature: oaObserver_oaIntValue||cref-oaObserver_oaIntValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaIntValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaIntValue",
    sizeof(PyoaObserver_oaIntValueObject),
    0,
    (destructor)oaObserver_oaIntValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaIntValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaIntValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaIntValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaIntValue_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaIntValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaIntValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaIntValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaIntValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaIntValue",
           (PyObject*)(&PyoaObserver_oaIntValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaIntValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaLPPHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLPPHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaLPPHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaLPPHeaderObject* self = (PyoaObserver_oaLPPHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLPPHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaLPPHeader* p=new pyv_oaObserver_oaLPPHeader(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLPPHeader(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaLPPHeader* p=new pyv_oaObserver_oaLPPHeader(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaLPPHeader)
    {
        PyParamoaObserver_oaLPPHeader p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaLPPHeader_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaLPPHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaLPPHeader* p=new pyv_oaObserver_oaLPPHeader(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaLPPHeader, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaLPPHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaLPPHeader_tp_dealloc(PyoaObserver_oaLPPHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaLPPHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLPPHeader_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaLPPHeader value;
    int convert_status=PyoaObserver_oaLPPHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaObserver_oaLPPHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaLPPHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaLPPHeader v1;
    PyParamoaObserver_oaLPPHeader v2;
    int convert_status1=PyoaObserver_oaLPPHeader_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaLPPHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaLPPHeader_Convert(PyObject* ob,PyParamoaObserver_oaLPPHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaLPPHeader_Check(ob)) {
        result->SetData( (oaObserver_oaLPPHeader*) ((PyoaObserver_oaLPPHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaLPPHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaLPPHeader_FromoaObserver_oaLPPHeader(oaObserver_oaLPPHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaLPPHeader_Type.tp_alloc(&PyoaObserver_oaLPPHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaLPPHeaderObject* self = (PyoaObserver_oaLPPHeaderObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaLPPHeader::pyv_oaObserver_oaLPPHeader(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaLPPHeader(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaLPPHeader::pyv_oaObserver_oaLPPHeader(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaLPPHeader(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaLPPHeader::pyv_oaObserver_oaLPPHeader(const oaObserver_oaLPPHeader& p)
 : pyob(NULL),
   oaObserver_oaLPPHeader(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLPPHeader::onPostCreate(oaLPPHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLPPHeader::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLPPHeader_FromoaLPPHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLPPHeader::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLPPHeader::onPostModify(oaLPPHeader* p1,oaLPPHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLPPHeader::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaLPPHeader_FromoaLPPHeader(p1));
    PyTuple_SetItem(args,1,PyoaLPPHeaderModTypeEnum_FromoaLPPHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLPPHeader::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLPPHeader::onPreDestroy(oaLPPHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLPPHeader::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLPPHeader_FromoaLPPHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLPPHeader::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLPPHeader::onPreModify(oaLPPHeader* p1,oaLPPHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLPPHeader::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaLPPHeader_FromoaLPPHeader(p1));
    PyTuple_SetItem(args,1,PyoaLPPHeaderModTypeEnum_FromoaLPPHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLPPHeader::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaLPPHeader_doc[] = 
"Class: oaObserver_oaLPPHeader\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaLPPHeader(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaLPPHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLPPHeader\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaLPPHeader(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaLPPHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLPPHeader\n"
"  Paramegers: (oaObserver_oaLPPHeader)\n"
"    Calls: (const oaObserver_oaLPPHeader&)\n"
"    Signature: oaObserver_oaLPPHeader||cref-oaObserver_oaLPPHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaLPPHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaLPPHeader",
    sizeof(PyoaObserver_oaLPPHeaderObject),
    0,
    (destructor)oaObserver_oaLPPHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaLPPHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaLPPHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaLPPHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaLPPHeader_oaLPPHeaderModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaLPPHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaLPPHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaLPPHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaLPPHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaLPPHeader",
           (PyObject*)(&PyoaObserver_oaLPPHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaLPPHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaLayer
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLayer_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaLayer_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaLayerObject* self = (PyoaObserver_oaLayerObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLayer(p1.Data());
            }
            else {
                pyv_oaObserver_oaLayer* p=new pyv_oaObserver_oaLayer(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLayer(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaLayer* p=new pyv_oaObserver_oaLayer(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaLayer)
    {
        PyParamoaObserver_oaLayer p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaLayer_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaLayer(p1.Data());
            }
            else {
                pyv_oaObserver_oaLayer* p=new pyv_oaObserver_oaLayer(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaLayer, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaLayer)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaLayer_tp_dealloc(PyoaObserver_oaLayerObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaLayer*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLayer_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaLayer value;
    int convert_status=PyoaObserver_oaLayer_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaObserver_oaLayer::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaLayer_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaLayer v1;
    PyParamoaObserver_oaLayer v2;
    int convert_status1=PyoaObserver_oaLayer_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaLayer_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaLayer_Convert(PyObject* ob,PyParamoaObserver_oaLayer* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaLayer_Check(ob)) {
        result->SetData( (oaObserver_oaLayer*) ((PyoaObserver_oaLayerObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaLayer Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaLayer_FromoaObserver_oaLayer(oaObserver_oaLayer* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaLayer_Type.tp_alloc(&PyoaObserver_oaLayer_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaLayerObject* self = (PyoaObserver_oaLayerObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaLayer::pyv_oaObserver_oaLayer(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaLayer(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaLayer::pyv_oaObserver_oaLayer(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaLayer(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaLayer::pyv_oaObserver_oaLayer(const oaObserver_oaLayer& p)
 : pyob(NULL),
   oaObserver_oaLayer(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLayer::onPostCreate(oaLayer* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLayer::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLayer_FromoaLayer(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLayer::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLayer::onPostModify(oaLayer* p1,oaLayerModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLayer::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaLayer_FromoaLayer(p1));
    PyTuple_SetItem(args,1,PyoaLayerModTypeEnum_FromoaLayerModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLayer::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLayer::onPreDestroy(oaLayer* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLayer::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLayer_FromoaLayer(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLayer::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLayer::onPreModify(oaLayer* p1,oaLayerModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLayer::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaLayer_FromoaLayer(p1));
    PyTuple_SetItem(args,1,PyoaLayerModTypeEnum_FromoaLayerModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLayer::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaLayer_doc[] = 
"Class: oaObserver_oaLayer\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaLayer(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaLayer||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLayer\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaLayer(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaLayer||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLayer\n"
"  Paramegers: (oaObserver_oaLayer)\n"
"    Calls: (const oaObserver_oaLayer&)\n"
"    Signature: oaObserver_oaLayer||cref-oaObserver_oaLayer,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaLayer_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaLayer",
    sizeof(PyoaObserver_oaLayerObject),
    0,
    (destructor)oaObserver_oaLayer_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaLayer_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaLayer_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaLayer_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaLayer_oaLayerModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaLayer_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaLayer_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaLayer_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaLayer\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaLayer",
           (PyObject*)(&PyoaObserver_oaLayer_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaLayer\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaLayerBlockage
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLayerBlockage_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaLayerBlockage_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaLayerBlockageObject* self = (PyoaObserver_oaLayerBlockageObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLayerBlockage(p1.Data());
            }
            else {
                pyv_oaObserver_oaLayerBlockage* p=new pyv_oaObserver_oaLayerBlockage(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLayerBlockage(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaLayerBlockage* p=new pyv_oaObserver_oaLayerBlockage(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaLayerBlockage)
    {
        PyParamoaObserver_oaLayerBlockage p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaLayerBlockage_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaLayerBlockage(p1.Data());
            }
            else {
                pyv_oaObserver_oaLayerBlockage* p=new pyv_oaObserver_oaLayerBlockage(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaLayerBlockage, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaLayerBlockage)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaLayerBlockage_tp_dealloc(PyoaObserver_oaLayerBlockageObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaLayerBlockage*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLayerBlockage_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaLayerBlockage value;
    int convert_status=PyoaObserver_oaLayerBlockage_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaLayerBlockage::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaLayerBlockage_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaLayerBlockage v1;
    PyParamoaObserver_oaLayerBlockage v2;
    int convert_status1=PyoaObserver_oaLayerBlockage_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaLayerBlockage_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaLayerBlockage_Convert(PyObject* ob,PyParamoaObserver_oaLayerBlockage* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaLayerBlockage_Check(ob)) {
        result->SetData( (oaObserver_oaLayerBlockage*) ((PyoaObserver_oaLayerBlockageObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaLayerBlockage Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaLayerBlockage_FromoaObserver_oaLayerBlockage(oaObserver_oaLayerBlockage* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaLayerBlockage_Type.tp_alloc(&PyoaObserver_oaLayerBlockage_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaLayerBlockageObject* self = (PyoaObserver_oaLayerBlockageObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaLayerBlockage::pyv_oaObserver_oaLayerBlockage(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaLayerBlockage(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaLayerBlockage::pyv_oaObserver_oaLayerBlockage(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaLayerBlockage(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaLayerBlockage::pyv_oaObserver_oaLayerBlockage(const oaObserver_oaLayerBlockage& p)
 : pyob(NULL),
   oaObserver_oaLayerBlockage(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLayerBlockage::onPostCreate(oaLayerBlockage* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerBlockage::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLayerBlockage_FromoaLayerBlockage(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerBlockage::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLayerBlockage::onPostModify(oaLayerBlockage* p1,oaBlockageModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerBlockage::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaLayerBlockage_FromoaLayerBlockage(p1));
    PyTuple_SetItem(args,1,PyoaBlockageModTypeEnum_FromoaBlockageModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerBlockage::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLayerBlockage::onPreDestroy(oaLayerBlockage* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerBlockage::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLayerBlockage_FromoaLayerBlockage(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerBlockage::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLayerBlockage::onPreModify(oaLayerBlockage* p1,oaBlockageModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerBlockage::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaLayerBlockage_FromoaLayerBlockage(p1));
    PyTuple_SetItem(args,1,PyoaBlockageModTypeEnum_FromoaBlockageModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerBlockage::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaLayerBlockage_doc[] = 
"Class: oaObserver_oaLayerBlockage\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaLayerBlockage(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaLayerBlockage||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLayerBlockage\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaLayerBlockage(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaLayerBlockage||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLayerBlockage\n"
"  Paramegers: (oaObserver_oaLayerBlockage)\n"
"    Calls: (const oaObserver_oaLayerBlockage&)\n"
"    Signature: oaObserver_oaLayerBlockage||cref-oaObserver_oaLayerBlockage,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaLayerBlockage_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaLayerBlockage",
    sizeof(PyoaObserver_oaLayerBlockageObject),
    0,
    (destructor)oaObserver_oaLayerBlockage_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaLayerBlockage_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaLayerBlockage_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaLayerBlockage_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaLayerBlockage_oaBlockageModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaLayerBlockage_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaLayerBlockage_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaLayerBlockage_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaLayerBlockage\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaLayerBlockage",
           (PyObject*)(&PyoaObserver_oaLayerBlockage_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaLayerBlockage\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaLayerHalo
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLayerHalo_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaLayerHalo_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaLayerHaloObject* self = (PyoaObserver_oaLayerHaloObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLayerHalo(p1.Data());
            }
            else {
                pyv_oaObserver_oaLayerHalo* p=new pyv_oaObserver_oaLayerHalo(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLayerHalo(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaLayerHalo* p=new pyv_oaObserver_oaLayerHalo(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaLayerHalo)
    {
        PyParamoaObserver_oaLayerHalo p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaLayerHalo_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaLayerHalo(p1.Data());
            }
            else {
                pyv_oaObserver_oaLayerHalo* p=new pyv_oaObserver_oaLayerHalo(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaLayerHalo, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaLayerHalo)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaLayerHalo_tp_dealloc(PyoaObserver_oaLayerHaloObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaLayerHalo*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLayerHalo_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaLayerHalo value;
    int convert_status=PyoaObserver_oaLayerHalo_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaObserver_oaLayerHalo::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaLayerHalo_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaLayerHalo v1;
    PyParamoaObserver_oaLayerHalo v2;
    int convert_status1=PyoaObserver_oaLayerHalo_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaLayerHalo_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaLayerHalo_Convert(PyObject* ob,PyParamoaObserver_oaLayerHalo* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaLayerHalo_Check(ob)) {
        result->SetData( (oaObserver_oaLayerHalo*) ((PyoaObserver_oaLayerHaloObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaLayerHalo Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaLayerHalo_FromoaObserver_oaLayerHalo(oaObserver_oaLayerHalo* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaLayerHalo_Type.tp_alloc(&PyoaObserver_oaLayerHalo_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaLayerHaloObject* self = (PyoaObserver_oaLayerHaloObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaLayerHalo::pyv_oaObserver_oaLayerHalo(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaLayerHalo(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaLayerHalo::pyv_oaObserver_oaLayerHalo(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaLayerHalo(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaLayerHalo::pyv_oaObserver_oaLayerHalo(const oaObserver_oaLayerHalo& p)
 : pyob(NULL),
   oaObserver_oaLayerHalo(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLayerHalo::onPostCreate(oaLayerHalo* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerHalo::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLayerHalo_FromoaLayerHalo(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerHalo::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLayerHalo::onPostModify(oaLayerHalo* p1,oaBlockageModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerHalo::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaLayerHalo_FromoaLayerHalo(p1));
    PyTuple_SetItem(args,1,PyoaBlockageModTypeEnum_FromoaBlockageModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerHalo::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLayerHalo::onPreDestroy(oaLayerHalo* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerHalo::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLayerHalo_FromoaLayerHalo(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerHalo::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLayerHalo::onPreModify(oaLayerHalo* p1,oaBlockageModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerHalo::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaLayerHalo_FromoaLayerHalo(p1));
    PyTuple_SetItem(args,1,PyoaBlockageModTypeEnum_FromoaBlockageModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerHalo::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaLayerHalo_doc[] = 
"Class: oaObserver_oaLayerHalo\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaLayerHalo(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaLayerHalo||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLayerHalo\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaLayerHalo(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaLayerHalo||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLayerHalo\n"
"  Paramegers: (oaObserver_oaLayerHalo)\n"
"    Calls: (const oaObserver_oaLayerHalo&)\n"
"    Signature: oaObserver_oaLayerHalo||cref-oaObserver_oaLayerHalo,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaLayerHalo_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaLayerHalo",
    sizeof(PyoaObserver_oaLayerHaloObject),
    0,
    (destructor)oaObserver_oaLayerHalo_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaLayerHalo_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaLayerHalo_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaLayerHalo_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaLayerHalo_oaBlockageModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaLayerHalo_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaLayerHalo_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaLayerHalo_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaLayerHalo\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaLayerHalo",
           (PyObject*)(&PyoaObserver_oaLayerHalo_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaLayerHalo\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaLayerHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLayerHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaLayerHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaLayerHeaderObject* self = (PyoaObserver_oaLayerHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLayerHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaLayerHeader* p=new pyv_oaObserver_oaLayerHeader(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLayerHeader(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaLayerHeader* p=new pyv_oaObserver_oaLayerHeader(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaLayerHeader)
    {
        PyParamoaObserver_oaLayerHeader p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaLayerHeader_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaLayerHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaLayerHeader* p=new pyv_oaObserver_oaLayerHeader(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaLayerHeader, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaLayerHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaLayerHeader_tp_dealloc(PyoaObserver_oaLayerHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaLayerHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLayerHeader_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaLayerHeader value;
    int convert_status=PyoaObserver_oaLayerHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaObserver_oaLayerHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaLayerHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaLayerHeader v1;
    PyParamoaObserver_oaLayerHeader v2;
    int convert_status1=PyoaObserver_oaLayerHeader_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaLayerHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaLayerHeader_Convert(PyObject* ob,PyParamoaObserver_oaLayerHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaLayerHeader_Check(ob)) {
        result->SetData( (oaObserver_oaLayerHeader*) ((PyoaObserver_oaLayerHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaLayerHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaLayerHeader_FromoaObserver_oaLayerHeader(oaObserver_oaLayerHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaLayerHeader_Type.tp_alloc(&PyoaObserver_oaLayerHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaLayerHeaderObject* self = (PyoaObserver_oaLayerHeaderObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaLayerHeader::pyv_oaObserver_oaLayerHeader(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaLayerHeader(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaLayerHeader::pyv_oaObserver_oaLayerHeader(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaLayerHeader(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaLayerHeader::pyv_oaObserver_oaLayerHeader(const oaObserver_oaLayerHeader& p)
 : pyob(NULL),
   oaObserver_oaLayerHeader(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLayerHeader::onPostCreate(oaLayerHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerHeader::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLayerHeader_FromoaLayerHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerHeader::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLayerHeader::onPostModify(oaLayerHeader* p1,oaLayerHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerHeader::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaLayerHeader_FromoaLayerHeader(p1));
    PyTuple_SetItem(args,1,PyoaLayerHeaderModTypeEnum_FromoaLayerHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerHeader::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLayerHeader::onPreDestroy(oaLayerHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerHeader::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLayerHeader_FromoaLayerHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerHeader::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLayerHeader::onPreModify(oaLayerHeader* p1,oaLayerHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerHeader::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaLayerHeader_FromoaLayerHeader(p1));
    PyTuple_SetItem(args,1,PyoaLayerHeaderModTypeEnum_FromoaLayerHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLayerHeader::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaLayerHeader_doc[] = 
"Class: oaObserver_oaLayerHeader\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaLayerHeader(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaLayerHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLayerHeader\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaLayerHeader(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaLayerHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLayerHeader\n"
"  Paramegers: (oaObserver_oaLayerHeader)\n"
"    Calls: (const oaObserver_oaLayerHeader&)\n"
"    Signature: oaObserver_oaLayerHeader||cref-oaObserver_oaLayerHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaLayerHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaLayerHeader",
    sizeof(PyoaObserver_oaLayerHeaderObject),
    0,
    (destructor)oaObserver_oaLayerHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaLayerHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaLayerHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaLayerHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaLayerHeader_oaLayerHeaderModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaLayerHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaLayerHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaLayerHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaLayerHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaLayerHeader",
           (PyObject*)(&PyoaObserver_oaLayerHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaLayerHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaLib
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLib_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaLib_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaLibObject* self = (PyoaObserver_oaLibObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLib(p1.Data());
            }
            else {
                pyv_oaObserver_oaLib* p=new pyv_oaObserver_oaLib(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLib(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaLib* p=new pyv_oaObserver_oaLib(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaLib, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaLib_tp_dealloc(PyoaObserver_oaLibObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaLib*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLib_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaLib value;
    int convert_status=PyoaObserver_oaLib_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaObserver_oaLib::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaLib_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaLib v1;
    PyParamoaObserver_oaLib v2;
    int convert_status1=PyoaObserver_oaLib_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaLib_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaLib_Convert(PyObject* ob,PyParamoaObserver_oaLib* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaLib_Check(ob)) {
        result->SetData( (oaObserver_oaLib*) ((PyoaObserver_oaLibObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaLib Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaLib_FromoaObserver_oaLib(oaObserver_oaLib* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaLib_Type.tp_alloc(&PyoaObserver_oaLib_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaLibObject* self = (PyoaObserver_oaLibObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaLib::pyv_oaObserver_oaLib(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaLib(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaLib::pyv_oaObserver_oaLib(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaLib(p1,p2)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLib::onPostCreate(oaLib* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLib::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLib_FromoaLib(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLib::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLib::onPostModify(oaLib* p1,oaDMLibModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLib::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaLib_FromoaLib(p1));
    PyTuple_SetItem(args,1,PyoaDMLibModTypeEnum_FromoaDMLibModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLib::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLib::onPostOpen(oaLib* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostOpen");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLib::onPostOpen was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLib_FromoaLib(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLib::onPostOpen had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLib::onPreClose(oaLib* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreClose");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLib::onPreClose was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLib_FromoaLib(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLib::onPreClose had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLib::onPreModify(oaLib* p1,oaDMLibModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLib::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaLib_FromoaLib(p1));
    PyTuple_SetItem(args,1,PyoaDMLibModTypeEnum_FromoaDMLibModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLib::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaLib_onPostCreate_doc[] = 
"Class: oaObserver_oaLib, Function: onPostCreate\n"
"  Paramegers: (oaLib)\n"
"    Calls: virtual void onPostCreate(oaLib* lib)\n"
"    Signature: onPostCreate|void-void|ptr-oaLib,\n"
"    This function is called after an oaLib object has been created. The application's derived observer class should implement this function to receive notification after an oaLib object is created.\n"
"    lib\n"
"    pointer to the created oaLib object\n"
;

static PyObject*
oaObserver_oaLib_onPostCreate(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaLib data;
    int convert_status=PyoaObserver_oaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaLibObject* self=(PyoaObserver_oaLibObject*)ob;

    PyParamoaLib p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLib_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaLib::onPostCreate(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaLib_onPostModify_doc[] = 
"Class: oaObserver_oaLib, Function: onPostModify\n"
"  Paramegers: (oaLib,oaDMLibModTypeEnum)\n"
"    Calls: virtual void onPostModify(oaLib* lib,oaDMLibModTypeEnum modType)\n"
"    Signature: onPostModify|void-void|ptr-oaLib,simple-oaDMLibModTypeEnum,\n"
"    This function is called after an oaLib object has been modified. The application's derived class should implement this function to receive notification when an oaLib object has been modified.\n"
"    lib\n"
"    A pointer to the modified oaLib object\n"
"    modType\n"
"    An oaDMLibModTypeEnum value that indicates the type of modification that was made\n"
;

static PyObject*
oaObserver_oaLib_onPostModify(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaLib data;
    int convert_status=PyoaObserver_oaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaLibObject* self=(PyoaObserver_oaLibObject*)ob;

    PyParamoaLib p1;
    PyParamoaDMLibModTypeEnum p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaLib_Convert,&p1,
          &PyoaDMLibModTypeEnum_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaLib::onPostModify(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaLib_onPostOpen_doc[] = 
"Class: oaObserver_oaLib, Function: onPostOpen\n"
"  Paramegers: (oaLib)\n"
"    Calls: virtual void onPostOpen(oaLib* lib)\n"
"    Signature: onPostOpen|void-void|ptr-oaLib,\n"
"    This function is called after an oaLib object has been opened. The application's derived class should implement this function to receive notification when an oaLib object has been opened.\n"
"    lib\n"
"    A pointer to the opened oaLib object\n"
;

static PyObject*
oaObserver_oaLib_onPostOpen(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaLib data;
    int convert_status=PyoaObserver_oaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaLibObject* self=(PyoaObserver_oaLibObject*)ob;

    PyParamoaLib p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLib_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaLib::onPostOpen(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaLib_onPreClose_doc[] = 
"Class: oaObserver_oaLib, Function: onPreClose\n"
"  Paramegers: (oaLib)\n"
"    Calls: virtual void onPreClose(oaLib* lib)\n"
"    Signature: onPreClose|void-void|ptr-oaLib,\n"
"    This function is called before an oaLib is closed. The application's derived class should implement this function to receive notification when a library object is about to be closed.\n"
"    lib\n"
"    A pointer to the library object to be closed\n"
;

static PyObject*
oaObserver_oaLib_onPreClose(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaLib data;
    int convert_status=PyoaObserver_oaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaLibObject* self=(PyoaObserver_oaLibObject*)ob;

    PyParamoaLib p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLib_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaLib::onPreClose(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaLib_onPreModify_doc[] = 
"Class: oaObserver_oaLib, Function: onPreModify\n"
"  Paramegers: (oaLib,oaDMLibModTypeEnum)\n"
"    Calls: virtual void onPreModify(oaLib* lib,oaDMLibModTypeEnum modType)\n"
"    Signature: onPreModify|void-void|ptr-oaLib,simple-oaDMLibModTypeEnum,\n"
"    This function is called before an oaLib object is modified. The application's derived class should implement this function to receive notification when an oaLib object is about to be modified.\n"
"    lib\n"
"    A pointer to the oaLib object to be modified\n"
"    modType\n"
"    An oaDMLibModTypeEnum value that indicates the type of modification to be made\n"
;

static PyObject*
oaObserver_oaLib_onPreModify(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaLib data;
    int convert_status=PyoaObserver_oaLib_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaLibObject* self=(PyoaObserver_oaLibObject*)ob;

    PyParamoaLib p1;
    PyParamoaDMLibModTypeEnum p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaLib_Convert,&p1,
          &PyoaDMLibModTypeEnum_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaLib::onPreModify(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaObserver_oaLib_assign_doc[] = 
"Class: oaObserver_oaLib, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaObserver_oaLib_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaObserver_oaLib data;
  int convert_status=PyoaObserver_oaLib_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaObserver_oaLib p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaObserver_oaLib_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaObserver_oaLib_methodlist[] = {
    {"onPostCreate",(PyCFunction)oaObserver_oaLib_onPostCreate,METH_VARARGS,oaObserver_oaLib_onPostCreate_doc},
    {"onPostModify",(PyCFunction)oaObserver_oaLib_onPostModify,METH_VARARGS,oaObserver_oaLib_onPostModify_doc},
    {"onPostOpen",(PyCFunction)oaObserver_oaLib_onPostOpen,METH_VARARGS,oaObserver_oaLib_onPostOpen_doc},
    {"onPreClose",(PyCFunction)oaObserver_oaLib_onPreClose,METH_VARARGS,oaObserver_oaLib_onPreClose_doc},
    {"onPreModify",(PyCFunction)oaObserver_oaLib_onPreModify,METH_VARARGS,oaObserver_oaLib_onPreModify_doc},
    {"assign",(PyCFunction)oaObserver_oaLib_tp_assign,METH_VARARGS,oaObserver_oaLib_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaLib_doc[] = 
"Class: oaObserver_oaLib\n"
"  This base template class can be used to derive observers for oaLib objects. It supports postCreate, postOpen, preModify, postModify, and preClose event notifications.\n"
"  See oaObserver for information on using Open Access observer template classes to derive and instantiate observers in an application.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaLib(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaLib||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLib\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaLib(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaLib||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLib\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaLib_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaLib",
    sizeof(PyoaObserver_oaLibObject),
    0,
    (destructor)oaObserver_oaLib_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaLib_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaLib_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaLib_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaObserver_oaLib_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseObserver_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaLib_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaLib_static_notifyPostCreateObservers_doc[] = 
"Class: oaObserver_oaLib, Function: notifyPostCreateObservers\n"
"  Paramegers: (oaLib)\n"
"    Calls: void notifyPostCreateObservers(oaLib* lib)\n"
"    Signature: notifyPostCreateObservers|void-void|ptr-oaLib,\n"
"    Function notifyPostCreateObservers\n"
;

static PyObject*
oaObserver_oaLib_static_notifyPostCreateObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLib_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaLib::notifyPostCreateObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaLib_static_notifyPostModifyObservers_doc[] = 
"Class: oaObserver_oaLib, Function: notifyPostModifyObservers\n"
"  Paramegers: (oaLib,oaDMLibModTypeEnum)\n"
"    Calls: void notifyPostModifyObservers(oaLib* lib,oaDMLibModTypeEnum modType)\n"
"    Signature: notifyPostModifyObservers|void-void|ptr-oaLib,simple-oaDMLibModTypeEnum,\n"
"    Function notifyPostModifyObservers\n"
;

static PyObject*
oaObserver_oaLib_static_notifyPostModifyObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib p1;
    PyParamoaDMLibModTypeEnum p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaLib_Convert,&p1,
          &PyoaDMLibModTypeEnum_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaLib::notifyPostModifyObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaLib_static_notifyPostOpenObservers_doc[] = 
"Class: oaObserver_oaLib, Function: notifyPostOpenObservers\n"
"  Paramegers: (oaLib)\n"
"    Calls: void notifyPostOpenObservers(oaLib* lib)\n"
"    Signature: notifyPostOpenObservers|void-void|ptr-oaLib,\n"
"    Function notifyPostOpenObservers\n"
;

static PyObject*
oaObserver_oaLib_static_notifyPostOpenObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLib_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaLib::notifyPostOpenObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaLib_static_notifyPreCloseObservers_doc[] = 
"Class: oaObserver_oaLib, Function: notifyPreCloseObservers\n"
"  Paramegers: (oaLib)\n"
"    Calls: void notifyPreCloseObservers(oaLib* lib)\n"
"    Signature: notifyPreCloseObservers|void-void|ptr-oaLib,\n"
"    Function notifyPreCloseObservers\n"
;

static PyObject*
oaObserver_oaLib_static_notifyPreCloseObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLib_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaLib::notifyPreCloseObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaLib_static_notifyPreModifyObservers_doc[] = 
"Class: oaObserver_oaLib, Function: notifyPreModifyObservers\n"
"  Paramegers: (oaLib,oaDMLibModTypeEnum)\n"
"    Calls: void notifyPreModifyObservers(oaLib* lib,oaDMLibModTypeEnum modType)\n"
"    Signature: notifyPreModifyObservers|void-void|ptr-oaLib,simple-oaDMLibModTypeEnum,\n"
"    Function notifyPreModifyObservers\n"
;

static PyObject*
oaObserver_oaLib_static_notifyPreModifyObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLib p1;
    PyParamoaDMLibModTypeEnum p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaLib_Convert,&p1,
          &PyoaDMLibModTypeEnum_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaLib::notifyPreModifyObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaObserver_oaLib_staticmethodlist[] = {
    {"static_notifyPostCreateObservers",(PyCFunction)oaObserver_oaLib_static_notifyPostCreateObservers,METH_VARARGS,oaObserver_oaLib_static_notifyPostCreateObservers_doc},
    {"static_notifyPostModifyObservers",(PyCFunction)oaObserver_oaLib_static_notifyPostModifyObservers,METH_VARARGS,oaObserver_oaLib_static_notifyPostModifyObservers_doc},
    {"static_notifyPostOpenObservers",(PyCFunction)oaObserver_oaLib_static_notifyPostOpenObservers,METH_VARARGS,oaObserver_oaLib_static_notifyPostOpenObservers_doc},
    {"static_notifyPreCloseObservers",(PyCFunction)oaObserver_oaLib_static_notifyPreCloseObservers,METH_VARARGS,oaObserver_oaLib_static_notifyPreCloseObservers_doc},
    {"static_notifyPreModifyObservers",(PyCFunction)oaObserver_oaLib_static_notifyPreModifyObservers,METH_VARARGS,oaObserver_oaLib_static_notifyPreModifyObservers_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaLib_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaLib_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaLib\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaLib",
           (PyObject*)(&PyoaObserver_oaLib_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaLib\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaObserver_oaLib_Type.tp_dict;
    for(method=oaObserver_oaLib_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaObserver_oaLibDefList
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLibDefList_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaLibDefList_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaLibDefListObject* self = (PyoaObserver_oaLibDefListObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLibDefList(p1.Data());
            }
            else {
                pyv_oaObserver_oaLibDefList* p=new pyv_oaObserver_oaLibDefList(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLibDefList(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaLibDefList* p=new pyv_oaObserver_oaLibDefList(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaLibDefList, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaLibDefList_tp_dealloc(PyoaObserver_oaLibDefListObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaLibDefList*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLibDefList_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaLibDefList value;
    int convert_status=PyoaObserver_oaLibDefList_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaLibDefList::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaLibDefList_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaLibDefList v1;
    PyParamoaObserver_oaLibDefList v2;
    int convert_status1=PyoaObserver_oaLibDefList_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaLibDefList_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaLibDefList_Convert(PyObject* ob,PyParamoaObserver_oaLibDefList* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaLibDefList_Check(ob)) {
        result->SetData( (oaObserver_oaLibDefList*) ((PyoaObserver_oaLibDefListObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaLibDefList Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaLibDefList_FromoaObserver_oaLibDefList(oaObserver_oaLibDefList* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaLibDefList_Type.tp_alloc(&PyoaObserver_oaLibDefList_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaLibDefListObject* self = (PyoaObserver_oaLibDefListObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaLibDefList::pyv_oaObserver_oaLibDefList(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaLibDefList(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaLibDefList::pyv_oaObserver_oaLibDefList(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaLibDefList(p1,p2)
{
}

// ------------------------------------------------------------------
oaBoolean pyv_oaObserver_oaLibDefList::onLoadWarnings(oaLibDefList* p1,const oaString& p2,oaLibDefListWarningTypeEnum p3)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onLoadWarnings");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLibDefList::onLoadWarnings was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(3);
    PyTuple_SetItem(args,0,PyoaLibDefList_FromoaLibDefList(p1));
    PyTuple_SetItem(args,1,PyoaString_FromoaString(p2));
    PyTuple_SetItem(args,2,PyoaLibDefListWarningTypeEnum_FromoaLibDefListWarningTypeEnum(p3));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLibDefList::onLoadWarnings had an error.");
    }
    PyParamoaBoolean rv;
    if (PyoaBoolean_Convert(result,&rv)==0) {
        throw oaPythonException("Python Virtual Function oaBoolean::onLoadWarnings has incorrect return type.");
    }
    Py_DECREF(result);
    return rv.Data();
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLibDefList::onPostOpenLibs(oaLibDefList* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostOpenLibs");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLibDefList::onPostOpenLibs was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLibDefList_FromoaLibDefList(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLibDefList::onPostOpenLibs had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
oaBoolean pyv_oaObserver_oaLibDefList::onPreOpenLibs(oaLibDefList* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreOpenLibs");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLibDefList::onPreOpenLibs was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLibDefList_FromoaLibDefList(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLibDefList::onPreOpenLibs had an error.");
    }
    PyParamoaBoolean rv;
    if (PyoaBoolean_Convert(result,&rv)==0) {
        throw oaPythonException("Python Virtual Function oaBoolean::onPreOpenLibs has incorrect return type.");
    }
    Py_DECREF(result);
    return rv.Data();
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaLibDefList_onLoadWarnings_doc[] = 
"Class: oaObserver_oaLibDefList, Function: onLoadWarnings\n"
"  Paramegers: (oaLibDefList,oaString,oaLibDefListWarningTypeEnum)\n"
"    Calls: virtual oaBoolean onLoadWarnings(oaLibDefList* defList,const oaString& msg,oaLibDefListWarningTypeEnum type)\n"
"    Signature: onLoadWarnings|simple-oaBoolean|ptr-oaLibDefList,cref-oaString,simple-oaLibDefListWarningTypeEnum,\n"
"    oaLibDefList::onLoadWarnings\n"
"    This function returns a warning message in msg and an oaLibDefFileWarningTypeEnum in type if there is an error when trying load or parse the oaLibDefList pointed to by defList or when trying to open the libraries defined or included in the oaLibDefList object pointed to by defList . This observer is notified during the oaLibDefList::openLibs() operation.\n"
"    Note: Although, for historical reasons, this observer has a return value that can be set by the user, its value has no effect on the OpenAccess calling (notification) code.\n"
"    defLst\n"
"    pointer to the oaLibDefList object that triggered the load warnings. Note that a NULL pointer is passed to defList if the default lib.defs file cannot be found or opened (when oaLibDefListWarningTypeEnum = oacNoDefaultLibDefListWarning || oacCannotOpenDefaultLibDefListWarning )\n"
"    msg\n"
"    warning message\n"
"    type\n"
"    oaLibDefListWarningTypeEnum value\n"
;

static PyObject*
oaObserver_oaLibDefList_onLoadWarnings(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaLibDefList data;
    int convert_status=PyoaObserver_oaLibDefList_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaLibDefListObject* self=(PyoaObserver_oaLibDefListObject*)ob;

    PyParamoaLibDefList p1;
    PyParamoaString p2;
    PyParamoaLibDefListWarningTypeEnum p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaLibDefList_Convert,&p1,
          &PyoaString_Convert,&p2,
          &PyoaLibDefListWarningTypeEnum_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaBoolean result= (data.DataCall()->oaObserver_oaLibDefList::onLoadWarnings(p1.Data(),p2.Data(),p3.Data()));
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
static char oaObserver_oaLibDefList_onPostOpenLibs_doc[] = 
"Class: oaObserver_oaLibDefList, Function: onPostOpenLibs\n"
"  Paramegers: (oaLibDefList)\n"
"    Calls: virtual void onPostOpenLibs(oaLibDefList* defList)\n"
"    Signature: onPostOpenLibs|void-void|ptr-oaLibDefList,\n"
"    This function is called after an oaLibDefList::openLibs call. The application's derived observer class should implement this function to receive notification after an oaLibDefList::openLibs call has been invoked.\n"
"    defList\n"
"    pointer to the oaLibDefList object on which the openLibs() was invoked\n"
;

static PyObject*
oaObserver_oaLibDefList_onPostOpenLibs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaLibDefList data;
    int convert_status=PyoaObserver_oaLibDefList_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaLibDefListObject* self=(PyoaObserver_oaLibDefListObject*)ob;

    PyParamoaLibDefList p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLibDefList_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaLibDefList::onPostOpenLibs(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaLibDefList_onPreOpenLibs_doc[] = 
"Class: oaObserver_oaLibDefList, Function: onPreOpenLibs\n"
"  Paramegers: (oaLibDefList)\n"
"    Calls: virtual oaBoolean onPreOpenLibs(oaLibDefList* defList)\n"
"    Signature: onPreOpenLibs|simple-oaBoolean|ptr-oaLibDefList,\n"
"    This function is called before an oaLibDefList::openLibs call. The application's derived observer class should implement this function to receive notification when an oaLibDefList::openLibs is about to be invoked. If the return value provided by the user derived observer is false, the operation is aborted.\n"
"    defList\n"
"    pointer to the oaLibDefList object on which the openLibs() is about to be invoked\n"
;

static PyObject*
oaObserver_oaLibDefList_onPreOpenLibs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaLibDefList data;
    int convert_status=PyoaObserver_oaLibDefList_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaLibDefListObject* self=(PyoaObserver_oaLibDefListObject*)ob;

    PyParamoaLibDefList p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLibDefList_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaBoolean result= (data.DataCall()->oaObserver_oaLibDefList::onPreOpenLibs(p1.Data()));
        return PyoaBoolean_FromoaBoolean(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaObserver_oaLibDefList_assign_doc[] = 
"Class: oaObserver_oaLibDefList, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaObserver_oaLibDefList_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaObserver_oaLibDefList data;
  int convert_status=PyoaObserver_oaLibDefList_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaObserver_oaLibDefList p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaObserver_oaLibDefList_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaObserver_oaLibDefList_methodlist[] = {
    {"onLoadWarnings",(PyCFunction)oaObserver_oaLibDefList_onLoadWarnings,METH_VARARGS,oaObserver_oaLibDefList_onLoadWarnings_doc},
    {"onPostOpenLibs",(PyCFunction)oaObserver_oaLibDefList_onPostOpenLibs,METH_VARARGS,oaObserver_oaLibDefList_onPostOpenLibs_doc},
    {"onPreOpenLibs",(PyCFunction)oaObserver_oaLibDefList_onPreOpenLibs,METH_VARARGS,oaObserver_oaLibDefList_onPreOpenLibs_doc},
    {"assign",(PyCFunction)oaObserver_oaLibDefList_tp_assign,METH_VARARGS,oaObserver_oaLibDefList_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaLibDefList_doc[] = 
"Class: oaObserver_oaLibDefList\n"
"  This base template class can be used to derive observers for oaLibDefList objects. It supports preOpen and postOpen and loadWarnings event notifications.\n"
"  See oaObserver for information on using Open Access observer template classes to derive and instantiate observers in an application.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaLibDefList(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaLibDefList||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLibDefList\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaLibDefList(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaLibDefList||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLibDefList\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaLibDefList_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaLibDefList",
    sizeof(PyoaObserver_oaLibDefListObject),
    0,
    (destructor)oaObserver_oaLibDefList_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaLibDefList_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaLibDefList_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaLibDefList_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaObserver_oaLibDefList_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseObserver_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaLibDefList_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaLibDefList_static_notifyLoadWarningsObservers_doc[] = 
"Class: oaObserver_oaLibDefList, Function: notifyLoadWarningsObservers\n"
"  Paramegers: (oaLibDefList,oaString,oaLibDefListWarningTypeEnum)\n"
"    Calls: oaBoolean notifyLoadWarningsObservers(oaLibDefList* defList,const oaString& msg,oaLibDefListWarningTypeEnum type)\n"
"    Signature: notifyLoadWarningsObservers|simple-oaBoolean|ptr-oaLibDefList,cref-oaString,simple-oaLibDefListWarningTypeEnum,\n"
"    Function notifyLoadWarningsObservers\n"
;

static PyObject*
oaObserver_oaLibDefList_static_notifyLoadWarningsObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefList p1;
    PyParamoaString p2;
    PyParamoaLibDefListWarningTypeEnum p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaLibDefList_Convert,&p1,
          &PyoaString_Convert,&p2,
          &PyoaLibDefListWarningTypeEnum_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaBoolean result= (oaObserver_oaLibDefList::notifyLoadWarningsObservers(p1.Data(),p2.Data(),p3.Data()));
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
static char oaObserver_oaLibDefList_static_notifyPostOpenLibsObservers_doc[] = 
"Class: oaObserver_oaLibDefList, Function: notifyPostOpenLibsObservers\n"
"  Paramegers: (oaLibDefList)\n"
"    Calls: void notifyPostOpenLibsObservers(oaLibDefList* defList)\n"
"    Signature: notifyPostOpenLibsObservers|void-void|ptr-oaLibDefList,\n"
"    Function notifyPostOpenLibsObservers\n"
;

static PyObject*
oaObserver_oaLibDefList_static_notifyPostOpenLibsObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefList p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLibDefList_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaLibDefList::notifyPostOpenLibsObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaLibDefList_static_notifyPreOpenLibsObservers_doc[] = 
"Class: oaObserver_oaLibDefList, Function: notifyPreOpenLibsObservers\n"
"  Paramegers: (oaLibDefList)\n"
"    Calls: oaBoolean notifyPreOpenLibsObservers(oaLibDefList* defList)\n"
"    Signature: notifyPreOpenLibsObservers|simple-oaBoolean|ptr-oaLibDefList,\n"
"    Function notifyPreOpenLibsObservers\n"
;

static PyObject*
oaObserver_oaLibDefList_static_notifyPreOpenLibsObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaLibDefList p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaLibDefList_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaBoolean result= (oaObserver_oaLibDefList::notifyPreOpenLibsObservers(p1.Data()));
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
static PyMethodDef oaObserver_oaLibDefList_staticmethodlist[] = {
    {"static_notifyLoadWarningsObservers",(PyCFunction)oaObserver_oaLibDefList_static_notifyLoadWarningsObservers,METH_VARARGS,oaObserver_oaLibDefList_static_notifyLoadWarningsObservers_doc},
    {"static_notifyPostOpenLibsObservers",(PyCFunction)oaObserver_oaLibDefList_static_notifyPostOpenLibsObservers,METH_VARARGS,oaObserver_oaLibDefList_static_notifyPostOpenLibsObservers_doc},
    {"static_notifyPreOpenLibsObservers",(PyCFunction)oaObserver_oaLibDefList_static_notifyPreOpenLibsObservers,METH_VARARGS,oaObserver_oaLibDefList_static_notifyPreOpenLibsObservers_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaLibDefList_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaLibDefList_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaLibDefList\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaLibDefList",
           (PyObject*)(&PyoaObserver_oaLibDefList_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaLibDefList\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaObserver_oaLibDefList_Type.tp_dict;
    for(method=oaObserver_oaLibDefList_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaObserver_oaLine
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLine_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaLine_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaLineObject* self = (PyoaObserver_oaLineObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLine(p1.Data());
            }
            else {
                pyv_oaObserver_oaLine* p=new pyv_oaObserver_oaLine(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLine(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaLine* p=new pyv_oaObserver_oaLine(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaLine)
    {
        PyParamoaObserver_oaLine p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaLine_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaLine(p1.Data());
            }
            else {
                pyv_oaObserver_oaLine* p=new pyv_oaObserver_oaLine(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaLine, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaLine)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaLine_tp_dealloc(PyoaObserver_oaLineObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaLine*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLine_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaLine value;
    int convert_status=PyoaObserver_oaLine_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaObserver_oaLine::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaLine_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaLine v1;
    PyParamoaObserver_oaLine v2;
    int convert_status1=PyoaObserver_oaLine_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaLine_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaLine_Convert(PyObject* ob,PyParamoaObserver_oaLine* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaLine_Check(ob)) {
        result->SetData( (oaObserver_oaLine*) ((PyoaObserver_oaLineObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaLine Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaLine_FromoaObserver_oaLine(oaObserver_oaLine* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaLine_Type.tp_alloc(&PyoaObserver_oaLine_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaLineObject* self = (PyoaObserver_oaLineObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaLine::pyv_oaObserver_oaLine(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaLine(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaLine::pyv_oaObserver_oaLine(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaLine(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaLine::pyv_oaObserver_oaLine(const oaObserver_oaLine& p)
 : pyob(NULL),
   oaObserver_oaLine(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLine::onPostCreate(oaLine* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLine::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLine_FromoaLine(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLine::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLine::onPostModify(oaLine* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLine::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaLine_FromoaLine(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLine::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLine::onPreDestroy(oaLine* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLine::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLine_FromoaLine(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLine::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLine::onPreModify(oaLine* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLine::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaLine_FromoaLine(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLine::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaLine_doc[] = 
"Class: oaObserver_oaLine\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaLine(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaLine||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLine\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaLine(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaLine||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLine\n"
"  Paramegers: (oaObserver_oaLine)\n"
"    Calls: (const oaObserver_oaLine&)\n"
"    Signature: oaObserver_oaLine||cref-oaObserver_oaLine,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaLine_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaLine",
    sizeof(PyoaObserver_oaLineObject),
    0,
    (destructor)oaObserver_oaLine_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaLine_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaLine_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaLine_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaLine_oaShapeModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaLine_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaLine_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaLine_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaLine\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaLine",
           (PyObject*)(&PyoaObserver_oaLine_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaLine\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaLumpedElmore
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLumpedElmore_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaLumpedElmore_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaLumpedElmoreObject* self = (PyoaObserver_oaLumpedElmoreObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLumpedElmore(p1.Data());
            }
            else {
                pyv_oaObserver_oaLumpedElmore* p=new pyv_oaObserver_oaLumpedElmore(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaLumpedElmore(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaLumpedElmore* p=new pyv_oaObserver_oaLumpedElmore(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaLumpedElmore)
    {
        PyParamoaObserver_oaLumpedElmore p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaLumpedElmore_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaLumpedElmore(p1.Data());
            }
            else {
                pyv_oaObserver_oaLumpedElmore* p=new pyv_oaObserver_oaLumpedElmore(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaLumpedElmore, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaLumpedElmore)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaLumpedElmore_tp_dealloc(PyoaObserver_oaLumpedElmoreObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaLumpedElmore*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaLumpedElmore_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaLumpedElmore value;
    int convert_status=PyoaObserver_oaLumpedElmore_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaLumpedElmore::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaLumpedElmore_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaLumpedElmore v1;
    PyParamoaObserver_oaLumpedElmore v2;
    int convert_status1=PyoaObserver_oaLumpedElmore_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaLumpedElmore_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaLumpedElmore_Convert(PyObject* ob,PyParamoaObserver_oaLumpedElmore* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaLumpedElmore_Check(ob)) {
        result->SetData( (oaObserver_oaLumpedElmore*) ((PyoaObserver_oaLumpedElmoreObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaLumpedElmore Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaLumpedElmore_FromoaObserver_oaLumpedElmore(oaObserver_oaLumpedElmore* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaLumpedElmore_Type.tp_alloc(&PyoaObserver_oaLumpedElmore_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaLumpedElmoreObject* self = (PyoaObserver_oaLumpedElmoreObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaLumpedElmore::pyv_oaObserver_oaLumpedElmore(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaLumpedElmore(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaLumpedElmore::pyv_oaObserver_oaLumpedElmore(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaLumpedElmore(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaLumpedElmore::pyv_oaObserver_oaLumpedElmore(const oaObserver_oaLumpedElmore& p)
 : pyob(NULL),
   oaObserver_oaLumpedElmore(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLumpedElmore::onPostCreate(oaLumpedElmore* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLumpedElmore::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLumpedElmore_FromoaLumpedElmore(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLumpedElmore::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLumpedElmore::onPostModify(oaLumpedElmore* p1,oaReducedModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLumpedElmore::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaLumpedElmore_FromoaLumpedElmore(p1));
    PyTuple_SetItem(args,1,PyoaReducedModTypeEnum_FromoaReducedModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLumpedElmore::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLumpedElmore::onPreDestroy(oaLumpedElmore* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLumpedElmore::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaLumpedElmore_FromoaLumpedElmore(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLumpedElmore::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaLumpedElmore::onPreModify(oaLumpedElmore* p1,oaReducedModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaLumpedElmore::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaLumpedElmore_FromoaLumpedElmore(p1));
    PyTuple_SetItem(args,1,PyoaReducedModTypeEnum_FromoaReducedModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaLumpedElmore::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaLumpedElmore_doc[] = 
"Class: oaObserver_oaLumpedElmore\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaLumpedElmore(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaLumpedElmore||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLumpedElmore\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaLumpedElmore(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaLumpedElmore||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaLumpedElmore\n"
"  Paramegers: (oaObserver_oaLumpedElmore)\n"
"    Calls: (const oaObserver_oaLumpedElmore&)\n"
"    Signature: oaObserver_oaLumpedElmore||cref-oaObserver_oaLumpedElmore,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaLumpedElmore_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaLumpedElmore",
    sizeof(PyoaObserver_oaLumpedElmoreObject),
    0,
    (destructor)oaObserver_oaLumpedElmore_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaLumpedElmore_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaLumpedElmore_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaLumpedElmore_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaLumpedElmore_oaReducedModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaLumpedElmore_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaLumpedElmore_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaLumpedElmore_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaLumpedElmore\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaLumpedElmore",
           (PyObject*)(&PyoaObserver_oaLumpedElmore_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaLumpedElmore\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaMarker
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaMarker_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaMarker_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaMarkerObject* self = (PyoaObserver_oaMarkerObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaMarker(p1.Data());
            }
            else {
                pyv_oaObserver_oaMarker* p=new pyv_oaObserver_oaMarker(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaMarker(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaMarker* p=new pyv_oaObserver_oaMarker(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaMarker)
    {
        PyParamoaObserver_oaMarker p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaMarker_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaMarker(p1.Data());
            }
            else {
                pyv_oaObserver_oaMarker* p=new pyv_oaObserver_oaMarker(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaMarker, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaMarker)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaMarker_tp_dealloc(PyoaObserver_oaMarkerObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaMarker*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaMarker_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaMarker value;
    int convert_status=PyoaObserver_oaMarker_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaObserver_oaMarker::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaMarker_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaMarker v1;
    PyParamoaObserver_oaMarker v2;
    int convert_status1=PyoaObserver_oaMarker_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaMarker_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaMarker_Convert(PyObject* ob,PyParamoaObserver_oaMarker* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaMarker_Check(ob)) {
        result->SetData( (oaObserver_oaMarker*) ((PyoaObserver_oaMarkerObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaMarker Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaMarker_FromoaObserver_oaMarker(oaObserver_oaMarker* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaMarker_Type.tp_alloc(&PyoaObserver_oaMarker_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaMarkerObject* self = (PyoaObserver_oaMarkerObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaMarker::pyv_oaObserver_oaMarker(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaMarker(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaMarker::pyv_oaObserver_oaMarker(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaMarker(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaMarker::pyv_oaObserver_oaMarker(const oaObserver_oaMarker& p)
 : pyob(NULL),
   oaObserver_oaMarker(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaMarker::onPostCreate(oaMarker* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaMarker::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaMarker_FromoaMarker(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaMarker::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaMarker::onPostModify(oaMarker* p1,oaMarkerModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaMarker::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaMarker_FromoaMarker(p1));
    PyTuple_SetItem(args,1,PyoaMarkerModTypeEnum_FromoaMarkerModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaMarker::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaMarker::onPreDestroy(oaMarker* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaMarker::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaMarker_FromoaMarker(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaMarker::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaMarker::onPreModify(oaMarker* p1,oaMarkerModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaMarker::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaMarker_FromoaMarker(p1));
    PyTuple_SetItem(args,1,PyoaMarkerModTypeEnum_FromoaMarkerModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaMarker::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaMarker_doc[] = 
"Class: oaObserver_oaMarker\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaMarker(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaMarker||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaMarker\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaMarker(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaMarker||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaMarker\n"
"  Paramegers: (oaObserver_oaMarker)\n"
"    Calls: (const oaObserver_oaMarker&)\n"
"    Signature: oaObserver_oaMarker||cref-oaObserver_oaMarker,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaMarker_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaMarker",
    sizeof(PyoaObserver_oaMarkerObject),
    0,
    (destructor)oaObserver_oaMarker_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaMarker_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaMarker_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaMarker_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaMarker_oaMarkerModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaMarker_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaMarker_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaMarker_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaMarker\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaMarker",
           (PyObject*)(&PyoaObserver_oaMarker_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaMarker\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModAssignAssignment
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModAssignAssignment_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModAssignAssignment_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModAssignAssignmentObject* self = (PyoaObserver_oaModAssignAssignmentObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModAssignAssignment(p1.Data());
            }
            else {
                pyv_oaObserver_oaModAssignAssignment* p=new pyv_oaObserver_oaModAssignAssignment(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModAssignAssignment(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModAssignAssignment* p=new pyv_oaObserver_oaModAssignAssignment(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModAssignAssignment)
    {
        PyParamoaObserver_oaModAssignAssignment p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModAssignAssignment_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModAssignAssignment(p1.Data());
            }
            else {
                pyv_oaObserver_oaModAssignAssignment* p=new pyv_oaObserver_oaModAssignAssignment(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModAssignAssignment, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModAssignAssignment)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModAssignAssignment_tp_dealloc(PyoaObserver_oaModAssignAssignmentObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModAssignAssignment*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModAssignAssignment_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModAssignAssignment value;
    int convert_status=PyoaObserver_oaModAssignAssignment_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaObserver_oaModAssignAssignment::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModAssignAssignment_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModAssignAssignment v1;
    PyParamoaObserver_oaModAssignAssignment v2;
    int convert_status1=PyoaObserver_oaModAssignAssignment_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModAssignAssignment_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModAssignAssignment_Convert(PyObject* ob,PyParamoaObserver_oaModAssignAssignment* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModAssignAssignment_Check(ob)) {
        result->SetData( (oaObserver_oaModAssignAssignment*) ((PyoaObserver_oaModAssignAssignmentObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModAssignAssignment Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModAssignAssignment_FromoaObserver_oaModAssignAssignment(oaObserver_oaModAssignAssignment* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModAssignAssignment_Type.tp_alloc(&PyoaObserver_oaModAssignAssignment_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModAssignAssignmentObject* self = (PyoaObserver_oaModAssignAssignmentObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModAssignAssignment::pyv_oaObserver_oaModAssignAssignment(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModAssignAssignment(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModAssignAssignment::pyv_oaObserver_oaModAssignAssignment(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModAssignAssignment(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModAssignAssignment::pyv_oaObserver_oaModAssignAssignment(const oaObserver_oaModAssignAssignment& p)
 : pyob(NULL),
   oaObserver_oaModAssignAssignment(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModAssignAssignment::onPostCreate(oaModAssignAssignment* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignAssignment::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModAssignAssignment_FromoaModAssignAssignment(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignAssignment::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModAssignAssignment::onPostModify(oaModAssignAssignment* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignAssignment::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModAssignAssignment_FromoaModAssignAssignment(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignAssignment::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModAssignAssignment::onPreDestroy(oaModAssignAssignment* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignAssignment::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModAssignAssignment_FromoaModAssignAssignment(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignAssignment::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModAssignAssignment::onPreModify(oaModAssignAssignment* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignAssignment::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModAssignAssignment_FromoaModAssignAssignment(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignAssignment::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModAssignAssignment_doc[] = 
"Class: oaObserver_oaModAssignAssignment\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModAssignAssignment(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModAssignAssignment||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModAssignAssignment\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModAssignAssignment(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModAssignAssignment||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModAssignAssignment\n"
"  Paramegers: (oaObserver_oaModAssignAssignment)\n"
"    Calls: (const oaObserver_oaModAssignAssignment&)\n"
"    Signature: oaObserver_oaModAssignAssignment||cref-oaObserver_oaModAssignAssignment,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModAssignAssignment_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModAssignAssignment",
    sizeof(PyoaObserver_oaModAssignAssignmentObject),
    0,
    (destructor)oaObserver_oaModAssignAssignment_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModAssignAssignment_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModAssignAssignment_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModAssignAssignment_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModAssignAssignment_oaAssignmentModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModAssignAssignment_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModAssignAssignment_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModAssignAssignment_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModAssignAssignment\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModAssignAssignment",
           (PyObject*)(&PyoaObserver_oaModAssignAssignment_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModAssignAssignment\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModAssignValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModAssignValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModAssignValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModAssignValueObject* self = (PyoaObserver_oaModAssignValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModAssignValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaModAssignValue* p=new pyv_oaObserver_oaModAssignValue(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModAssignValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModAssignValue* p=new pyv_oaObserver_oaModAssignValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModAssignValue)
    {
        PyParamoaObserver_oaModAssignValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModAssignValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModAssignValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaModAssignValue* p=new pyv_oaObserver_oaModAssignValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModAssignValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModAssignValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModAssignValue_tp_dealloc(PyoaObserver_oaModAssignValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModAssignValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModAssignValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModAssignValue value;
    int convert_status=PyoaObserver_oaModAssignValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaObserver_oaModAssignValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModAssignValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModAssignValue v1;
    PyParamoaObserver_oaModAssignValue v2;
    int convert_status1=PyoaObserver_oaModAssignValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModAssignValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModAssignValue_Convert(PyObject* ob,PyParamoaObserver_oaModAssignValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModAssignValue_Check(ob)) {
        result->SetData( (oaObserver_oaModAssignValue*) ((PyoaObserver_oaModAssignValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModAssignValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModAssignValue_FromoaObserver_oaModAssignValue(oaObserver_oaModAssignValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModAssignValue_Type.tp_alloc(&PyoaObserver_oaModAssignValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModAssignValueObject* self = (PyoaObserver_oaModAssignValueObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModAssignValue::pyv_oaObserver_oaModAssignValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModAssignValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModAssignValue::pyv_oaObserver_oaModAssignValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModAssignValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModAssignValue::pyv_oaObserver_oaModAssignValue(const oaObserver_oaModAssignValue& p)
 : pyob(NULL),
   oaObserver_oaModAssignValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModAssignValue::onPostCreate(oaModAssignValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModAssignValue_FromoaModAssignValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModAssignValue::onPostModify(oaModAssignValue* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModAssignValue_FromoaModAssignValue(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModAssignValue::onPreDestroy(oaModAssignValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModAssignValue_FromoaModAssignValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModAssignValue::onPreModify(oaModAssignValue* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModAssignValue_FromoaModAssignValue(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModAssignValue_doc[] = 
"Class: oaObserver_oaModAssignValue\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModAssignValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModAssignValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModAssignValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModAssignValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModAssignValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModAssignValue\n"
"  Paramegers: (oaObserver_oaModAssignValue)\n"
"    Calls: (const oaObserver_oaModAssignValue&)\n"
"    Signature: oaObserver_oaModAssignValue||cref-oaObserver_oaModAssignValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModAssignValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModAssignValue",
    sizeof(PyoaObserver_oaModAssignValueObject),
    0,
    (destructor)oaObserver_oaModAssignValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModAssignValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModAssignValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModAssignValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModAssignValue_oaAssignmentModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModAssignValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModAssignValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModAssignValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModAssignValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModAssignValue",
           (PyObject*)(&PyoaObserver_oaModAssignValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModAssignValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModAssignment
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModAssignment_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModAssignment_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModAssignmentObject* self = (PyoaObserver_oaModAssignmentObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModAssignment(p1.Data());
            }
            else {
                pyv_oaObserver_oaModAssignment* p=new pyv_oaObserver_oaModAssignment(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModAssignment(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModAssignment* p=new pyv_oaObserver_oaModAssignment(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModAssignment)
    {
        PyParamoaObserver_oaModAssignment p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModAssignment_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModAssignment(p1.Data());
            }
            else {
                pyv_oaObserver_oaModAssignment* p=new pyv_oaObserver_oaModAssignment(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModAssignment, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModAssignment)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModAssignment_tp_dealloc(PyoaObserver_oaModAssignmentObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModAssignment*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModAssignment_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModAssignment value;
    int convert_status=PyoaObserver_oaModAssignment_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaModAssignment::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModAssignment_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModAssignment v1;
    PyParamoaObserver_oaModAssignment v2;
    int convert_status1=PyoaObserver_oaModAssignment_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModAssignment_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModAssignment_Convert(PyObject* ob,PyParamoaObserver_oaModAssignment* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModAssignment_Check(ob)) {
        result->SetData( (oaObserver_oaModAssignment*) ((PyoaObserver_oaModAssignmentObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModAssignment Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModAssignment_FromoaObserver_oaModAssignment(oaObserver_oaModAssignment* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModAssignment_Type.tp_alloc(&PyoaObserver_oaModAssignment_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModAssignmentObject* self = (PyoaObserver_oaModAssignmentObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModAssignment::pyv_oaObserver_oaModAssignment(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModAssignment(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModAssignment::pyv_oaObserver_oaModAssignment(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModAssignment(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModAssignment::pyv_oaObserver_oaModAssignment(const oaObserver_oaModAssignment& p)
 : pyob(NULL),
   oaObserver_oaModAssignment(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModAssignment::onPostCreate(oaModAssignment* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignment::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModAssignment_FromoaModAssignment(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignment::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModAssignment::onPostModify(oaModAssignment* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignment::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModAssignment_FromoaModAssignment(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignment::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModAssignment::onPreDestroy(oaModAssignment* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignment::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModAssignment_FromoaModAssignment(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignment::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModAssignment::onPreModify(oaModAssignment* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignment::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModAssignment_FromoaModAssignment(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModAssignment::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModAssignment_doc[] = 
"Class: oaObserver_oaModAssignment\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModAssignment(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModAssignment||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModAssignment\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModAssignment(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModAssignment||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModAssignment\n"
"  Paramegers: (oaObserver_oaModAssignment)\n"
"    Calls: (const oaObserver_oaModAssignment&)\n"
"    Signature: oaObserver_oaModAssignment||cref-oaObserver_oaModAssignment,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModAssignment_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModAssignment",
    sizeof(PyoaObserver_oaModAssignmentObject),
    0,
    (destructor)oaObserver_oaModAssignment_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModAssignment_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModAssignment_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModAssignment_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModAssignment_oaAssignmentModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModAssignment_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModAssignment_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModAssignment_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModAssignment\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModAssignment",
           (PyObject*)(&PyoaObserver_oaModAssignment_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModAssignment\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModBitInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBitInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModBitInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModBitInstObject* self = (PyoaObserver_oaModBitInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBitInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBitInst* p=new pyv_oaObserver_oaModBitInst(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBitInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModBitInst* p=new pyv_oaObserver_oaModBitInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModBitInst)
    {
        PyParamoaObserver_oaModBitInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModBitInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModBitInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBitInst* p=new pyv_oaObserver_oaModBitInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModBitInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModBitInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModBitInst_tp_dealloc(PyoaObserver_oaModBitInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModBitInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBitInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModBitInst value;
    int convert_status=PyoaObserver_oaModBitInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaModBitInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModBitInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModBitInst v1;
    PyParamoaObserver_oaModBitInst v2;
    int convert_status1=PyoaObserver_oaModBitInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModBitInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModBitInst_Convert(PyObject* ob,PyParamoaObserver_oaModBitInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModBitInst_Check(ob)) {
        result->SetData( (oaObserver_oaModBitInst*) ((PyoaObserver_oaModBitInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModBitInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModBitInst_FromoaObserver_oaModBitInst(oaObserver_oaModBitInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModBitInst_Type.tp_alloc(&PyoaObserver_oaModBitInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModBitInstObject* self = (PyoaObserver_oaModBitInstObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModBitInst::pyv_oaObserver_oaModBitInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModBitInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBitInst::pyv_oaObserver_oaModBitInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModBitInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBitInst::pyv_oaObserver_oaModBitInst(const oaObserver_oaModBitInst& p)
 : pyob(NULL),
   oaObserver_oaModBitInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBitInst::onPostCreate(oaModBitInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBitInst_FromoaModBitInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBitInst::onPostModify(oaModBitInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBitInst_FromoaModBitInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBitInst::onPreDestroy(oaModBitInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBitInst_FromoaModBitInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBitInst::onPreModify(oaModBitInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBitInst_FromoaModBitInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModBitInst_doc[] = 
"Class: oaObserver_oaModBitInst\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModBitInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModBitInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBitInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModBitInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModBitInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBitInst\n"
"  Paramegers: (oaObserver_oaModBitInst)\n"
"    Calls: (const oaObserver_oaModBitInst&)\n"
"    Signature: oaObserver_oaModBitInst||cref-oaObserver_oaModBitInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModBitInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModBitInst",
    sizeof(PyoaObserver_oaModBitInstObject),
    0,
    (destructor)oaObserver_oaModBitInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModBitInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModBitInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModBitInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModBitInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModBitInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModBitInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModBitInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModBitInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModBitInst",
           (PyObject*)(&PyoaObserver_oaModBitInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModBitInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModBitNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBitNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModBitNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModBitNetObject* self = (PyoaObserver_oaModBitNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBitNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBitNet* p=new pyv_oaObserver_oaModBitNet(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBitNet(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModBitNet* p=new pyv_oaObserver_oaModBitNet(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModBitNet)
    {
        PyParamoaObserver_oaModBitNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModBitNet_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModBitNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBitNet* p=new pyv_oaObserver_oaModBitNet(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModBitNet, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModBitNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModBitNet_tp_dealloc(PyoaObserver_oaModBitNetObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModBitNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBitNet_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModBitNet value;
    int convert_status=PyoaObserver_oaModBitNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaObserver_oaModBitNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModBitNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModBitNet v1;
    PyParamoaObserver_oaModBitNet v2;
    int convert_status1=PyoaObserver_oaModBitNet_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModBitNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModBitNet_Convert(PyObject* ob,PyParamoaObserver_oaModBitNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModBitNet_Check(ob)) {
        result->SetData( (oaObserver_oaModBitNet*) ((PyoaObserver_oaModBitNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModBitNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModBitNet_FromoaObserver_oaModBitNet(oaObserver_oaModBitNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModBitNet_Type.tp_alloc(&PyoaObserver_oaModBitNet_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModBitNetObject* self = (PyoaObserver_oaModBitNetObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModBitNet::pyv_oaObserver_oaModBitNet(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModBitNet(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBitNet::pyv_oaObserver_oaModBitNet(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModBitNet(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBitNet::pyv_oaObserver_oaModBitNet(const oaObserver_oaModBitNet& p)
 : pyob(NULL),
   oaObserver_oaModBitNet(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBitNet::onPostCreate(oaModBitNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitNet::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBitNet_FromoaModBitNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitNet::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBitNet::onPostModify(oaModBitNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitNet::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBitNet_FromoaModBitNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitNet::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBitNet::onPreDestroy(oaModBitNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitNet::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBitNet_FromoaModBitNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitNet::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBitNet::onPreModify(oaModBitNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitNet::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBitNet_FromoaModBitNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitNet::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModBitNet_doc[] = 
"Class: oaObserver_oaModBitNet\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModBitNet(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModBitNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBitNet\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModBitNet(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModBitNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBitNet\n"
"  Paramegers: (oaObserver_oaModBitNet)\n"
"    Calls: (const oaObserver_oaModBitNet&)\n"
"    Signature: oaObserver_oaModBitNet||cref-oaObserver_oaModBitNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModBitNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModBitNet",
    sizeof(PyoaObserver_oaModBitNetObject),
    0,
    (destructor)oaObserver_oaModBitNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModBitNet_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModBitNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModBitNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModBitNet_oaNetModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModBitNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModBitNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModBitNet_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModBitNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModBitNet",
           (PyObject*)(&PyoaObserver_oaModBitNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModBitNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModBitTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBitTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModBitTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModBitTermObject* self = (PyoaObserver_oaModBitTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBitTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBitTerm* p=new pyv_oaObserver_oaModBitTerm(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBitTerm(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModBitTerm* p=new pyv_oaObserver_oaModBitTerm(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModBitTerm)
    {
        PyParamoaObserver_oaModBitTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModBitTerm_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModBitTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBitTerm* p=new pyv_oaObserver_oaModBitTerm(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModBitTerm, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModBitTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModBitTerm_tp_dealloc(PyoaObserver_oaModBitTermObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModBitTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBitTerm_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModBitTerm value;
    int convert_status=PyoaObserver_oaModBitTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaModBitTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModBitTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModBitTerm v1;
    PyParamoaObserver_oaModBitTerm v2;
    int convert_status1=PyoaObserver_oaModBitTerm_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModBitTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModBitTerm_Convert(PyObject* ob,PyParamoaObserver_oaModBitTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModBitTerm_Check(ob)) {
        result->SetData( (oaObserver_oaModBitTerm*) ((PyoaObserver_oaModBitTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModBitTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModBitTerm_FromoaObserver_oaModBitTerm(oaObserver_oaModBitTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModBitTerm_Type.tp_alloc(&PyoaObserver_oaModBitTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModBitTermObject* self = (PyoaObserver_oaModBitTermObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModBitTerm::pyv_oaObserver_oaModBitTerm(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModBitTerm(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBitTerm::pyv_oaObserver_oaModBitTerm(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModBitTerm(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBitTerm::pyv_oaObserver_oaModBitTerm(const oaObserver_oaModBitTerm& p)
 : pyob(NULL),
   oaObserver_oaModBitTerm(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBitTerm::onPostCreate(oaModBitTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitTerm::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBitTerm_FromoaModBitTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitTerm::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBitTerm::onPostModify(oaModBitTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitTerm::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBitTerm_FromoaModBitTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitTerm::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBitTerm::onPreDestroy(oaModBitTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitTerm::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBitTerm_FromoaModBitTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitTerm::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBitTerm::onPreModify(oaModBitTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitTerm::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBitTerm_FromoaModBitTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBitTerm::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModBitTerm_doc[] = 
"Class: oaObserver_oaModBitTerm\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModBitTerm(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModBitTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBitTerm\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModBitTerm(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModBitTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBitTerm\n"
"  Paramegers: (oaObserver_oaModBitTerm)\n"
"    Calls: (const oaObserver_oaModBitTerm&)\n"
"    Signature: oaObserver_oaModBitTerm||cref-oaObserver_oaModBitTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModBitTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModBitTerm",
    sizeof(PyoaObserver_oaModBitTermObject),
    0,
    (destructor)oaObserver_oaModBitTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModBitTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModBitTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModBitTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModBitTerm_oaTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModBitTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModBitTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModBitTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModBitTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModBitTerm",
           (PyObject*)(&PyoaObserver_oaModBitTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModBitTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModBundleNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBundleNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModBundleNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModBundleNetObject* self = (PyoaObserver_oaModBundleNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBundleNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBundleNet* p=new pyv_oaObserver_oaModBundleNet(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBundleNet(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModBundleNet* p=new pyv_oaObserver_oaModBundleNet(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModBundleNet)
    {
        PyParamoaObserver_oaModBundleNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModBundleNet_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModBundleNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBundleNet* p=new pyv_oaObserver_oaModBundleNet(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModBundleNet, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModBundleNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModBundleNet_tp_dealloc(PyoaObserver_oaModBundleNetObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModBundleNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBundleNet_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModBundleNet value;
    int convert_status=PyoaObserver_oaModBundleNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaModBundleNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModBundleNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModBundleNet v1;
    PyParamoaObserver_oaModBundleNet v2;
    int convert_status1=PyoaObserver_oaModBundleNet_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModBundleNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModBundleNet_Convert(PyObject* ob,PyParamoaObserver_oaModBundleNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModBundleNet_Check(ob)) {
        result->SetData( (oaObserver_oaModBundleNet*) ((PyoaObserver_oaModBundleNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModBundleNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModBundleNet_FromoaObserver_oaModBundleNet(oaObserver_oaModBundleNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModBundleNet_Type.tp_alloc(&PyoaObserver_oaModBundleNet_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModBundleNetObject* self = (PyoaObserver_oaModBundleNetObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModBundleNet::pyv_oaObserver_oaModBundleNet(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModBundleNet(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBundleNet::pyv_oaObserver_oaModBundleNet(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModBundleNet(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBundleNet::pyv_oaObserver_oaModBundleNet(const oaObserver_oaModBundleNet& p)
 : pyob(NULL),
   oaObserver_oaModBundleNet(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBundleNet::onPostCreate(oaModBundleNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBundleNet::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBundleNet_FromoaModBundleNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBundleNet::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBundleNet::onPostModify(oaModBundleNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBundleNet::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBundleNet_FromoaModBundleNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBundleNet::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBundleNet::onPreDestroy(oaModBundleNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBundleNet::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBundleNet_FromoaModBundleNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBundleNet::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBundleNet::onPreModify(oaModBundleNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBundleNet::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBundleNet_FromoaModBundleNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBundleNet::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModBundleNet_doc[] = 
"Class: oaObserver_oaModBundleNet\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModBundleNet(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModBundleNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBundleNet\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModBundleNet(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModBundleNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBundleNet\n"
"  Paramegers: (oaObserver_oaModBundleNet)\n"
"    Calls: (const oaObserver_oaModBundleNet&)\n"
"    Signature: oaObserver_oaModBundleNet||cref-oaObserver_oaModBundleNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModBundleNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModBundleNet",
    sizeof(PyoaObserver_oaModBundleNetObject),
    0,
    (destructor)oaObserver_oaModBundleNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModBundleNet_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModBundleNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModBundleNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModBundleNet_oaNetModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModBundleNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModBundleNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModBundleNet_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModBundleNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModBundleNet",
           (PyObject*)(&PyoaObserver_oaModBundleNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModBundleNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModBundleTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBundleTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModBundleTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModBundleTermObject* self = (PyoaObserver_oaModBundleTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBundleTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBundleTerm* p=new pyv_oaObserver_oaModBundleTerm(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBundleTerm(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModBundleTerm* p=new pyv_oaObserver_oaModBundleTerm(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModBundleTerm)
    {
        PyParamoaObserver_oaModBundleTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModBundleTerm_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModBundleTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBundleTerm* p=new pyv_oaObserver_oaModBundleTerm(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModBundleTerm, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModBundleTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModBundleTerm_tp_dealloc(PyoaObserver_oaModBundleTermObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModBundleTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBundleTerm_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModBundleTerm value;
    int convert_status=PyoaObserver_oaModBundleTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaModBundleTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModBundleTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModBundleTerm v1;
    PyParamoaObserver_oaModBundleTerm v2;
    int convert_status1=PyoaObserver_oaModBundleTerm_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModBundleTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModBundleTerm_Convert(PyObject* ob,PyParamoaObserver_oaModBundleTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModBundleTerm_Check(ob)) {
        result->SetData( (oaObserver_oaModBundleTerm*) ((PyoaObserver_oaModBundleTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModBundleTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModBundleTerm_FromoaObserver_oaModBundleTerm(oaObserver_oaModBundleTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModBundleTerm_Type.tp_alloc(&PyoaObserver_oaModBundleTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModBundleTermObject* self = (PyoaObserver_oaModBundleTermObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModBundleTerm::pyv_oaObserver_oaModBundleTerm(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModBundleTerm(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBundleTerm::pyv_oaObserver_oaModBundleTerm(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModBundleTerm(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBundleTerm::pyv_oaObserver_oaModBundleTerm(const oaObserver_oaModBundleTerm& p)
 : pyob(NULL),
   oaObserver_oaModBundleTerm(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBundleTerm::onPostCreate(oaModBundleTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBundleTerm::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBundleTerm_FromoaModBundleTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBundleTerm::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBundleTerm::onPostModify(oaModBundleTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBundleTerm::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBundleTerm_FromoaModBundleTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBundleTerm::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBundleTerm::onPreDestroy(oaModBundleTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBundleTerm::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBundleTerm_FromoaModBundleTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBundleTerm::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBundleTerm::onPreModify(oaModBundleTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBundleTerm::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBundleTerm_FromoaModBundleTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBundleTerm::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModBundleTerm_doc[] = 
"Class: oaObserver_oaModBundleTerm\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModBundleTerm(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModBundleTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBundleTerm\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModBundleTerm(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModBundleTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBundleTerm\n"
"  Paramegers: (oaObserver_oaModBundleTerm)\n"
"    Calls: (const oaObserver_oaModBundleTerm&)\n"
"    Signature: oaObserver_oaModBundleTerm||cref-oaObserver_oaModBundleTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModBundleTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModBundleTerm",
    sizeof(PyoaObserver_oaModBundleTermObject),
    0,
    (destructor)oaObserver_oaModBundleTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModBundleTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModBundleTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModBundleTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModBundleTerm_oaTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModBundleTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModBundleTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModBundleTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModBundleTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModBundleTerm",
           (PyObject*)(&PyoaObserver_oaModBundleTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModBundleTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModBusNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBusNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModBusNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModBusNetObject* self = (PyoaObserver_oaModBusNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBusNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBusNet* p=new pyv_oaObserver_oaModBusNet(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBusNet(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModBusNet* p=new pyv_oaObserver_oaModBusNet(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModBusNet)
    {
        PyParamoaObserver_oaModBusNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModBusNet_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModBusNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBusNet* p=new pyv_oaObserver_oaModBusNet(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModBusNet, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModBusNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModBusNet_tp_dealloc(PyoaObserver_oaModBusNetObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModBusNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBusNet_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModBusNet value;
    int convert_status=PyoaObserver_oaModBusNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaObserver_oaModBusNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModBusNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModBusNet v1;
    PyParamoaObserver_oaModBusNet v2;
    int convert_status1=PyoaObserver_oaModBusNet_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModBusNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModBusNet_Convert(PyObject* ob,PyParamoaObserver_oaModBusNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModBusNet_Check(ob)) {
        result->SetData( (oaObserver_oaModBusNet*) ((PyoaObserver_oaModBusNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModBusNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModBusNet_FromoaObserver_oaModBusNet(oaObserver_oaModBusNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModBusNet_Type.tp_alloc(&PyoaObserver_oaModBusNet_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModBusNetObject* self = (PyoaObserver_oaModBusNetObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModBusNet::pyv_oaObserver_oaModBusNet(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModBusNet(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBusNet::pyv_oaObserver_oaModBusNet(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModBusNet(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBusNet::pyv_oaObserver_oaModBusNet(const oaObserver_oaModBusNet& p)
 : pyob(NULL),
   oaObserver_oaModBusNet(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusNet::onPostCreate(oaModBusNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNet::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBusNet_FromoaModBusNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNet::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusNet::onPostModify(oaModBusNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNet::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBusNet_FromoaModBusNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNet::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusNet::onPreDestroy(oaModBusNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNet::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBusNet_FromoaModBusNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNet::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusNet::onPreModify(oaModBusNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNet::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBusNet_FromoaModBusNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNet::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModBusNet_doc[] = 
"Class: oaObserver_oaModBusNet\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModBusNet(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModBusNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBusNet\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModBusNet(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModBusNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBusNet\n"
"  Paramegers: (oaObserver_oaModBusNet)\n"
"    Calls: (const oaObserver_oaModBusNet&)\n"
"    Signature: oaObserver_oaModBusNet||cref-oaObserver_oaModBusNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModBusNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModBusNet",
    sizeof(PyoaObserver_oaModBusNetObject),
    0,
    (destructor)oaObserver_oaModBusNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModBusNet_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModBusNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModBusNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModBusNet_oaNetModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModBusNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModBusNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModBusNet_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModBusNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModBusNet",
           (PyObject*)(&PyoaObserver_oaModBusNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModBusNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModBusNetBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBusNetBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModBusNetBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModBusNetBitObject* self = (PyoaObserver_oaModBusNetBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBusNetBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBusNetBit* p=new pyv_oaObserver_oaModBusNetBit(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBusNetBit(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModBusNetBit* p=new pyv_oaObserver_oaModBusNetBit(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModBusNetBit)
    {
        PyParamoaObserver_oaModBusNetBit p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModBusNetBit_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModBusNetBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBusNetBit* p=new pyv_oaObserver_oaModBusNetBit(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModBusNetBit, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModBusNetBit)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModBusNetBit_tp_dealloc(PyoaObserver_oaModBusNetBitObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModBusNetBit*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBusNetBit_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModBusNetBit value;
    int convert_status=PyoaObserver_oaModBusNetBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaModBusNetBit::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModBusNetBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModBusNetBit v1;
    PyParamoaObserver_oaModBusNetBit v2;
    int convert_status1=PyoaObserver_oaModBusNetBit_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModBusNetBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModBusNetBit_Convert(PyObject* ob,PyParamoaObserver_oaModBusNetBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModBusNetBit_Check(ob)) {
        result->SetData( (oaObserver_oaModBusNetBit*) ((PyoaObserver_oaModBusNetBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModBusNetBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModBusNetBit_FromoaObserver_oaModBusNetBit(oaObserver_oaModBusNetBit* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModBusNetBit_Type.tp_alloc(&PyoaObserver_oaModBusNetBit_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModBusNetBitObject* self = (PyoaObserver_oaModBusNetBitObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModBusNetBit::pyv_oaObserver_oaModBusNetBit(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModBusNetBit(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBusNetBit::pyv_oaObserver_oaModBusNetBit(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModBusNetBit(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBusNetBit::pyv_oaObserver_oaModBusNetBit(const oaObserver_oaModBusNetBit& p)
 : pyob(NULL),
   oaObserver_oaModBusNetBit(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusNetBit::onPostCreate(oaModBusNetBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNetBit::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBusNetBit_FromoaModBusNetBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNetBit::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusNetBit::onPostModify(oaModBusNetBit* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNetBit::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBusNetBit_FromoaModBusNetBit(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNetBit::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusNetBit::onPreDestroy(oaModBusNetBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNetBit::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBusNetBit_FromoaModBusNetBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNetBit::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusNetBit::onPreModify(oaModBusNetBit* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNetBit::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBusNetBit_FromoaModBusNetBit(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNetBit::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModBusNetBit_doc[] = 
"Class: oaObserver_oaModBusNetBit\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModBusNetBit(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModBusNetBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBusNetBit\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModBusNetBit(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModBusNetBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBusNetBit\n"
"  Paramegers: (oaObserver_oaModBusNetBit)\n"
"    Calls: (const oaObserver_oaModBusNetBit&)\n"
"    Signature: oaObserver_oaModBusNetBit||cref-oaObserver_oaModBusNetBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModBusNetBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModBusNetBit",
    sizeof(PyoaObserver_oaModBusNetBitObject),
    0,
    (destructor)oaObserver_oaModBusNetBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModBusNetBit_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModBusNetBit_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModBusNetBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModBusNetBit_oaNetModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModBusNetBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModBusNetBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModBusNetBit_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModBusNetBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModBusNetBit",
           (PyObject*)(&PyoaObserver_oaModBusNetBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModBusNetBit\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModBusNetDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBusNetDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModBusNetDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModBusNetDefObject* self = (PyoaObserver_oaModBusNetDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBusNetDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBusNetDef* p=new pyv_oaObserver_oaModBusNetDef(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBusNetDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModBusNetDef* p=new pyv_oaObserver_oaModBusNetDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModBusNetDef)
    {
        PyParamoaObserver_oaModBusNetDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModBusNetDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModBusNetDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBusNetDef* p=new pyv_oaObserver_oaModBusNetDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModBusNetDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModBusNetDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModBusNetDef_tp_dealloc(PyoaObserver_oaModBusNetDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModBusNetDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBusNetDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModBusNetDef value;
    int convert_status=PyoaObserver_oaModBusNetDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaModBusNetDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModBusNetDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModBusNetDef v1;
    PyParamoaObserver_oaModBusNetDef v2;
    int convert_status1=PyoaObserver_oaModBusNetDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModBusNetDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModBusNetDef_Convert(PyObject* ob,PyParamoaObserver_oaModBusNetDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModBusNetDef_Check(ob)) {
        result->SetData( (oaObserver_oaModBusNetDef*) ((PyoaObserver_oaModBusNetDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModBusNetDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModBusNetDef_FromoaObserver_oaModBusNetDef(oaObserver_oaModBusNetDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModBusNetDef_Type.tp_alloc(&PyoaObserver_oaModBusNetDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModBusNetDefObject* self = (PyoaObserver_oaModBusNetDefObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModBusNetDef::pyv_oaObserver_oaModBusNetDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModBusNetDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBusNetDef::pyv_oaObserver_oaModBusNetDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModBusNetDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBusNetDef::pyv_oaObserver_oaModBusNetDef(const oaObserver_oaModBusNetDef& p)
 : pyob(NULL),
   oaObserver_oaModBusNetDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusNetDef::onPostCreate(oaModBusNetDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNetDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBusNetDef_FromoaModBusNetDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNetDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusNetDef::onPostModify(oaModBusNetDef* p1,oaBusNetDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNetDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBusNetDef_FromoaModBusNetDef(p1));
    PyTuple_SetItem(args,1,PyoaBusNetDefModTypeEnum_FromoaBusNetDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNetDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusNetDef::onPreDestroy(oaModBusNetDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNetDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBusNetDef_FromoaModBusNetDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNetDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusNetDef::onPreModify(oaModBusNetDef* p1,oaBusNetDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNetDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBusNetDef_FromoaModBusNetDef(p1));
    PyTuple_SetItem(args,1,PyoaBusNetDefModTypeEnum_FromoaBusNetDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusNetDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModBusNetDef_doc[] = 
"Class: oaObserver_oaModBusNetDef\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModBusNetDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModBusNetDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBusNetDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModBusNetDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModBusNetDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBusNetDef\n"
"  Paramegers: (oaObserver_oaModBusNetDef)\n"
"    Calls: (const oaObserver_oaModBusNetDef&)\n"
"    Signature: oaObserver_oaModBusNetDef||cref-oaObserver_oaModBusNetDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModBusNetDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModBusNetDef",
    sizeof(PyoaObserver_oaModBusNetDefObject),
    0,
    (destructor)oaObserver_oaModBusNetDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModBusNetDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModBusNetDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModBusNetDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModBusNetDef_oaBusNetDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModBusNetDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModBusNetDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModBusNetDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModBusNetDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModBusNetDef",
           (PyObject*)(&PyoaObserver_oaModBusNetDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModBusNetDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModBusTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBusTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModBusTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModBusTermObject* self = (PyoaObserver_oaModBusTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBusTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBusTerm* p=new pyv_oaObserver_oaModBusTerm(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBusTerm(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModBusTerm* p=new pyv_oaObserver_oaModBusTerm(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModBusTerm)
    {
        PyParamoaObserver_oaModBusTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModBusTerm_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModBusTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBusTerm* p=new pyv_oaObserver_oaModBusTerm(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModBusTerm, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModBusTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModBusTerm_tp_dealloc(PyoaObserver_oaModBusTermObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModBusTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBusTerm_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModBusTerm value;
    int convert_status=PyoaObserver_oaModBusTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaModBusTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModBusTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModBusTerm v1;
    PyParamoaObserver_oaModBusTerm v2;
    int convert_status1=PyoaObserver_oaModBusTerm_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModBusTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModBusTerm_Convert(PyObject* ob,PyParamoaObserver_oaModBusTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModBusTerm_Check(ob)) {
        result->SetData( (oaObserver_oaModBusTerm*) ((PyoaObserver_oaModBusTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModBusTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModBusTerm_FromoaObserver_oaModBusTerm(oaObserver_oaModBusTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModBusTerm_Type.tp_alloc(&PyoaObserver_oaModBusTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModBusTermObject* self = (PyoaObserver_oaModBusTermObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModBusTerm::pyv_oaObserver_oaModBusTerm(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModBusTerm(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBusTerm::pyv_oaObserver_oaModBusTerm(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModBusTerm(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBusTerm::pyv_oaObserver_oaModBusTerm(const oaObserver_oaModBusTerm& p)
 : pyob(NULL),
   oaObserver_oaModBusTerm(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusTerm::onPostCreate(oaModBusTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTerm::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBusTerm_FromoaModBusTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTerm::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusTerm::onPostModify(oaModBusTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTerm::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBusTerm_FromoaModBusTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTerm::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusTerm::onPreDestroy(oaModBusTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTerm::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBusTerm_FromoaModBusTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTerm::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusTerm::onPreModify(oaModBusTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTerm::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBusTerm_FromoaModBusTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTerm::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModBusTerm_doc[] = 
"Class: oaObserver_oaModBusTerm\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModBusTerm(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModBusTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBusTerm\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModBusTerm(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModBusTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBusTerm\n"
"  Paramegers: (oaObserver_oaModBusTerm)\n"
"    Calls: (const oaObserver_oaModBusTerm&)\n"
"    Signature: oaObserver_oaModBusTerm||cref-oaObserver_oaModBusTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModBusTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModBusTerm",
    sizeof(PyoaObserver_oaModBusTermObject),
    0,
    (destructor)oaObserver_oaModBusTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModBusTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModBusTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModBusTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModBusTerm_oaTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModBusTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModBusTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModBusTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModBusTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModBusTerm",
           (PyObject*)(&PyoaObserver_oaModBusTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModBusTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModBusTermBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBusTermBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModBusTermBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModBusTermBitObject* self = (PyoaObserver_oaModBusTermBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBusTermBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBusTermBit* p=new pyv_oaObserver_oaModBusTermBit(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBusTermBit(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModBusTermBit* p=new pyv_oaObserver_oaModBusTermBit(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModBusTermBit)
    {
        PyParamoaObserver_oaModBusTermBit p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModBusTermBit_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModBusTermBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBusTermBit* p=new pyv_oaObserver_oaModBusTermBit(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModBusTermBit, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModBusTermBit)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModBusTermBit_tp_dealloc(PyoaObserver_oaModBusTermBitObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModBusTermBit*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBusTermBit_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModBusTermBit value;
    int convert_status=PyoaObserver_oaModBusTermBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaModBusTermBit::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModBusTermBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModBusTermBit v1;
    PyParamoaObserver_oaModBusTermBit v2;
    int convert_status1=PyoaObserver_oaModBusTermBit_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModBusTermBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModBusTermBit_Convert(PyObject* ob,PyParamoaObserver_oaModBusTermBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModBusTermBit_Check(ob)) {
        result->SetData( (oaObserver_oaModBusTermBit*) ((PyoaObserver_oaModBusTermBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModBusTermBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModBusTermBit_FromoaObserver_oaModBusTermBit(oaObserver_oaModBusTermBit* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModBusTermBit_Type.tp_alloc(&PyoaObserver_oaModBusTermBit_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModBusTermBitObject* self = (PyoaObserver_oaModBusTermBitObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModBusTermBit::pyv_oaObserver_oaModBusTermBit(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModBusTermBit(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBusTermBit::pyv_oaObserver_oaModBusTermBit(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModBusTermBit(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBusTermBit::pyv_oaObserver_oaModBusTermBit(const oaObserver_oaModBusTermBit& p)
 : pyob(NULL),
   oaObserver_oaModBusTermBit(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusTermBit::onPostCreate(oaModBusTermBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTermBit::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBusTermBit_FromoaModBusTermBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTermBit::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusTermBit::onPostModify(oaModBusTermBit* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTermBit::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBusTermBit_FromoaModBusTermBit(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTermBit::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusTermBit::onPreDestroy(oaModBusTermBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTermBit::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBusTermBit_FromoaModBusTermBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTermBit::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusTermBit::onPreModify(oaModBusTermBit* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTermBit::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBusTermBit_FromoaModBusTermBit(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTermBit::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModBusTermBit_doc[] = 
"Class: oaObserver_oaModBusTermBit\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModBusTermBit(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModBusTermBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBusTermBit\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModBusTermBit(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModBusTermBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBusTermBit\n"
"  Paramegers: (oaObserver_oaModBusTermBit)\n"
"    Calls: (const oaObserver_oaModBusTermBit&)\n"
"    Signature: oaObserver_oaModBusTermBit||cref-oaObserver_oaModBusTermBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModBusTermBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModBusTermBit",
    sizeof(PyoaObserver_oaModBusTermBitObject),
    0,
    (destructor)oaObserver_oaModBusTermBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModBusTermBit_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModBusTermBit_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModBusTermBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModBusTermBit_oaTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModBusTermBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModBusTermBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModBusTermBit_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModBusTermBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModBusTermBit",
           (PyObject*)(&PyoaObserver_oaModBusTermBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModBusTermBit\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModBusTermDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBusTermDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModBusTermDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModBusTermDefObject* self = (PyoaObserver_oaModBusTermDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBusTermDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBusTermDef* p=new pyv_oaObserver_oaModBusTermDef(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModBusTermDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModBusTermDef* p=new pyv_oaObserver_oaModBusTermDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModBusTermDef)
    {
        PyParamoaObserver_oaModBusTermDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModBusTermDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModBusTermDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaModBusTermDef* p=new pyv_oaObserver_oaModBusTermDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModBusTermDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModBusTermDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModBusTermDef_tp_dealloc(PyoaObserver_oaModBusTermDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModBusTermDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModBusTermDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModBusTermDef value;
    int convert_status=PyoaObserver_oaModBusTermDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaModBusTermDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModBusTermDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModBusTermDef v1;
    PyParamoaObserver_oaModBusTermDef v2;
    int convert_status1=PyoaObserver_oaModBusTermDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModBusTermDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModBusTermDef_Convert(PyObject* ob,PyParamoaObserver_oaModBusTermDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModBusTermDef_Check(ob)) {
        result->SetData( (oaObserver_oaModBusTermDef*) ((PyoaObserver_oaModBusTermDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModBusTermDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModBusTermDef_FromoaObserver_oaModBusTermDef(oaObserver_oaModBusTermDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModBusTermDef_Type.tp_alloc(&PyoaObserver_oaModBusTermDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModBusTermDefObject* self = (PyoaObserver_oaModBusTermDefObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModBusTermDef::pyv_oaObserver_oaModBusTermDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModBusTermDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBusTermDef::pyv_oaObserver_oaModBusTermDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModBusTermDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModBusTermDef::pyv_oaObserver_oaModBusTermDef(const oaObserver_oaModBusTermDef& p)
 : pyob(NULL),
   oaObserver_oaModBusTermDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusTermDef::onPostCreate(oaModBusTermDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTermDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBusTermDef_FromoaModBusTermDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTermDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusTermDef::onPostModify(oaModBusTermDef* p1,oaBusTermDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTermDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBusTermDef_FromoaModBusTermDef(p1));
    PyTuple_SetItem(args,1,PyoaBusTermDefModTypeEnum_FromoaBusTermDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTermDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusTermDef::onPreDestroy(oaModBusTermDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTermDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModBusTermDef_FromoaModBusTermDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTermDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModBusTermDef::onPreModify(oaModBusTermDef* p1,oaBusTermDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTermDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModBusTermDef_FromoaModBusTermDef(p1));
    PyTuple_SetItem(args,1,PyoaBusTermDefModTypeEnum_FromoaBusTermDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModBusTermDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModBusTermDef_doc[] = 
"Class: oaObserver_oaModBusTermDef\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModBusTermDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModBusTermDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBusTermDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModBusTermDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModBusTermDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModBusTermDef\n"
"  Paramegers: (oaObserver_oaModBusTermDef)\n"
"    Calls: (const oaObserver_oaModBusTermDef&)\n"
"    Signature: oaObserver_oaModBusTermDef||cref-oaObserver_oaModBusTermDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModBusTermDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModBusTermDef",
    sizeof(PyoaObserver_oaModBusTermDefObject),
    0,
    (destructor)oaObserver_oaModBusTermDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModBusTermDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModBusTermDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModBusTermDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModBusTermDef_oaBusTermDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModBusTermDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModBusTermDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModBusTermDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModBusTermDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModBusTermDef",
           (PyObject*)(&PyoaObserver_oaModBusTermDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModBusTermDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModConnectDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModConnectDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModConnectDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModConnectDefObject* self = (PyoaObserver_oaModConnectDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaModConnectDef* p=new pyv_oaObserver_oaModConnectDef(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModConnectDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModConnectDef* p=new pyv_oaObserver_oaModConnectDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModConnectDef)
    {
        PyParamoaObserver_oaModConnectDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModConnectDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaModConnectDef* p=new pyv_oaObserver_oaModConnectDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModConnectDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModConnectDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModConnectDef_tp_dealloc(PyoaObserver_oaModConnectDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModConnectDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModConnectDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModConnectDef value;
    int convert_status=PyoaObserver_oaModConnectDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaModConnectDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModConnectDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModConnectDef v1;
    PyParamoaObserver_oaModConnectDef v2;
    int convert_status1=PyoaObserver_oaModConnectDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModConnectDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModConnectDef_Convert(PyObject* ob,PyParamoaObserver_oaModConnectDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModConnectDef_Check(ob)) {
        result->SetData( (oaObserver_oaModConnectDef*) ((PyoaObserver_oaModConnectDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModConnectDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModConnectDef_FromoaObserver_oaModConnectDef(oaObserver_oaModConnectDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModConnectDef_Type.tp_alloc(&PyoaObserver_oaModConnectDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModConnectDefObject* self = (PyoaObserver_oaModConnectDefObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModConnectDef::pyv_oaObserver_oaModConnectDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModConnectDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModConnectDef::pyv_oaObserver_oaModConnectDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModConnectDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModConnectDef::pyv_oaObserver_oaModConnectDef(const oaObserver_oaModConnectDef& p)
 : pyob(NULL),
   oaObserver_oaModConnectDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModConnectDef::onPostCreate(oaModConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModConnectDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModConnectDef_FromoaModConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModConnectDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModConnectDef::onPostModify(oaModConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModConnectDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModConnectDef_FromoaModConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModConnectDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModConnectDef::onPreDestroy(oaModConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModConnectDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModConnectDef_FromoaModConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModConnectDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModConnectDef::onPreModify(oaModConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModConnectDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModConnectDef_FromoaModConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModConnectDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModConnectDef_doc[] = 
"Class: oaObserver_oaModConnectDef\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModConnectDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModConnectDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModConnectDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModConnectDef\n"
"  Paramegers: (oaObserver_oaModConnectDef)\n"
"    Calls: (const oaObserver_oaModConnectDef&)\n"
"    Signature: oaObserver_oaModConnectDef||cref-oaObserver_oaModConnectDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModConnectDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModConnectDef",
    sizeof(PyoaObserver_oaModConnectDefObject),
    0,
    (destructor)oaObserver_oaModConnectDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModConnectDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModConnectDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModConnectDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModConnectDef_oaConnectDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModConnectDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModConnectDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModConnectDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModConnectDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModConnectDef",
           (PyObject*)(&PyoaObserver_oaModConnectDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModConnectDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModDesignInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModDesignInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModDesignInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModDesignInstObject* self = (PyoaObserver_oaModDesignInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModDesignInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModDesignInst* p=new pyv_oaObserver_oaModDesignInst(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModDesignInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModDesignInst* p=new pyv_oaObserver_oaModDesignInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModDesignInst)
    {
        PyParamoaObserver_oaModDesignInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModDesignInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModDesignInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModDesignInst* p=new pyv_oaObserver_oaModDesignInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModDesignInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModDesignInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModDesignInst_tp_dealloc(PyoaObserver_oaModDesignInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModDesignInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModDesignInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModDesignInst value;
    int convert_status=PyoaObserver_oaModDesignInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaModDesignInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModDesignInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModDesignInst v1;
    PyParamoaObserver_oaModDesignInst v2;
    int convert_status1=PyoaObserver_oaModDesignInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModDesignInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModDesignInst_Convert(PyObject* ob,PyParamoaObserver_oaModDesignInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModDesignInst_Check(ob)) {
        result->SetData( (oaObserver_oaModDesignInst*) ((PyoaObserver_oaModDesignInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModDesignInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModDesignInst_FromoaObserver_oaModDesignInst(oaObserver_oaModDesignInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModDesignInst_Type.tp_alloc(&PyoaObserver_oaModDesignInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModDesignInstObject* self = (PyoaObserver_oaModDesignInstObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModDesignInst::pyv_oaObserver_oaModDesignInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModDesignInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModDesignInst::pyv_oaObserver_oaModDesignInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModDesignInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModDesignInst::pyv_oaObserver_oaModDesignInst(const oaObserver_oaModDesignInst& p)
 : pyob(NULL),
   oaObserver_oaModDesignInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModDesignInst::onPostCreate(oaModDesignInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModDesignInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModDesignInst_FromoaModDesignInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModDesignInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModDesignInst::onPostModify(oaModDesignInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModDesignInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModDesignInst_FromoaModDesignInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModDesignInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModDesignInst::onPreDestroy(oaModDesignInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModDesignInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModDesignInst_FromoaModDesignInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModDesignInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModDesignInst::onPreModify(oaModDesignInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModDesignInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModDesignInst_FromoaModDesignInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModDesignInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModDesignInst_doc[] = 
"Class: oaObserver_oaModDesignInst\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModDesignInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModDesignInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModDesignInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModDesignInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModDesignInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModDesignInst\n"
"  Paramegers: (oaObserver_oaModDesignInst)\n"
"    Calls: (const oaObserver_oaModDesignInst&)\n"
"    Signature: oaObserver_oaModDesignInst||cref-oaObserver_oaModDesignInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModDesignInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModDesignInst",
    sizeof(PyoaObserver_oaModDesignInstObject),
    0,
    (destructor)oaObserver_oaModDesignInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModDesignInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModDesignInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModDesignInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModDesignInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModDesignInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModDesignInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModDesignInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModDesignInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModDesignInst",
           (PyObject*)(&PyoaObserver_oaModDesignInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModDesignInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModInstObject* self = (PyoaObserver_oaModInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModInst* p=new pyv_oaObserver_oaModInst(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModInst* p=new pyv_oaObserver_oaModInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModInst)
    {
        PyParamoaObserver_oaModInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModInst* p=new pyv_oaObserver_oaModInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModInst_tp_dealloc(PyoaObserver_oaModInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModInst value;
    int convert_status=PyoaObserver_oaModInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaObserver_oaModInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModInst v1;
    PyParamoaObserver_oaModInst v2;
    int convert_status1=PyoaObserver_oaModInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModInst_Convert(PyObject* ob,PyParamoaObserver_oaModInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModInst_Check(ob)) {
        result->SetData( (oaObserver_oaModInst*) ((PyoaObserver_oaModInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModInst_FromoaObserver_oaModInst(oaObserver_oaModInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModInst_Type.tp_alloc(&PyoaObserver_oaModInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModInstObject* self = (PyoaObserver_oaModInstObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModInst::pyv_oaObserver_oaModInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModInst::pyv_oaObserver_oaModInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModInst::pyv_oaObserver_oaModInst(const oaObserver_oaModInst& p)
 : pyob(NULL),
   oaObserver_oaModInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModInst::onPostCreate(oaModInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModInst_FromoaModInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModInst::onPostModify(oaModInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModInst_FromoaModInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModInst::onPreDestroy(oaModInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModInst_FromoaModInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModInst::onPreModify(oaModInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModInst_FromoaModInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModInst_doc[] = 
"Class: oaObserver_oaModInst\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModInst\n"
"  Paramegers: (oaObserver_oaModInst)\n"
"    Calls: (const oaObserver_oaModInst&)\n"
"    Signature: oaObserver_oaModInst||cref-oaObserver_oaModInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModInst",
    sizeof(PyoaObserver_oaModInstObject),
    0,
    (destructor)oaObserver_oaModInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModInst",
           (PyObject*)(&PyoaObserver_oaModInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModInstHeaderObject* self = (PyoaObserver_oaModInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModInstHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaModInstHeader* p=new pyv_oaObserver_oaModInstHeader(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModInstHeader(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModInstHeader* p=new pyv_oaObserver_oaModInstHeader(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModInstHeader)
    {
        PyParamoaObserver_oaModInstHeader p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModInstHeader_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModInstHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaModInstHeader* p=new pyv_oaObserver_oaModInstHeader(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModInstHeader, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModInstHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModInstHeader_tp_dealloc(PyoaObserver_oaModInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModInstHeader value;
    int convert_status=PyoaObserver_oaModInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaModInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModInstHeader v1;
    PyParamoaObserver_oaModInstHeader v2;
    int convert_status1=PyoaObserver_oaModInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModInstHeader_Convert(PyObject* ob,PyParamoaObserver_oaModInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModInstHeader_Check(ob)) {
        result->SetData( (oaObserver_oaModInstHeader*) ((PyoaObserver_oaModInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModInstHeader_FromoaObserver_oaModInstHeader(oaObserver_oaModInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModInstHeader_Type.tp_alloc(&PyoaObserver_oaModInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModInstHeaderObject* self = (PyoaObserver_oaModInstHeaderObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModInstHeader::pyv_oaObserver_oaModInstHeader(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModInstHeader(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModInstHeader::pyv_oaObserver_oaModInstHeader(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModInstHeader(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModInstHeader::pyv_oaObserver_oaModInstHeader(const oaObserver_oaModInstHeader& p)
 : pyob(NULL),
   oaObserver_oaModInstHeader(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModInstHeader::onPostCreate(oaModInstHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModInstHeader::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModInstHeader_FromoaModInstHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModInstHeader::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModInstHeader::onPostModify(oaModInstHeader* p1,oaInstHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModInstHeader::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModInstHeader_FromoaModInstHeader(p1));
    PyTuple_SetItem(args,1,PyoaInstHeaderModTypeEnum_FromoaInstHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModInstHeader::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModInstHeader::onPreDestroy(oaModInstHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModInstHeader::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModInstHeader_FromoaModInstHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModInstHeader::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModInstHeader::onPreModify(oaModInstHeader* p1,oaInstHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModInstHeader::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModInstHeader_FromoaModInstHeader(p1));
    PyTuple_SetItem(args,1,PyoaInstHeaderModTypeEnum_FromoaInstHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModInstHeader::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModInstHeader_doc[] = 
"Class: oaObserver_oaModInstHeader\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModInstHeader(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModInstHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModInstHeader\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModInstHeader(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModInstHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModInstHeader\n"
"  Paramegers: (oaObserver_oaModInstHeader)\n"
"    Calls: (const oaObserver_oaModInstHeader&)\n"
"    Signature: oaObserver_oaModInstHeader||cref-oaObserver_oaModInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModInstHeader",
    sizeof(PyoaObserver_oaModInstHeaderObject),
    0,
    (destructor)oaObserver_oaModInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModInstHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModInstHeader_oaInstHeaderModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModInstHeader",
           (PyObject*)(&PyoaObserver_oaModInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModInstHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModInstTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModInstTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModInstTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModInstTermObject* self = (PyoaObserver_oaModInstTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModInstTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaModInstTerm* p=new pyv_oaObserver_oaModInstTerm(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModInstTerm(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModInstTerm* p=new pyv_oaObserver_oaModInstTerm(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModInstTerm)
    {
        PyParamoaObserver_oaModInstTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModInstTerm_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModInstTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaModInstTerm* p=new pyv_oaObserver_oaModInstTerm(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModInstTerm, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModInstTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModInstTerm_tp_dealloc(PyoaObserver_oaModInstTermObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModInstTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModInstTerm_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModInstTerm value;
    int convert_status=PyoaObserver_oaModInstTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaObserver_oaModInstTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModInstTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModInstTerm v1;
    PyParamoaObserver_oaModInstTerm v2;
    int convert_status1=PyoaObserver_oaModInstTerm_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModInstTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModInstTerm_Convert(PyObject* ob,PyParamoaObserver_oaModInstTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModInstTerm_Check(ob)) {
        result->SetData( (oaObserver_oaModInstTerm*) ((PyoaObserver_oaModInstTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModInstTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModInstTerm_FromoaObserver_oaModInstTerm(oaObserver_oaModInstTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModInstTerm_Type.tp_alloc(&PyoaObserver_oaModInstTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModInstTermObject* self = (PyoaObserver_oaModInstTermObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModInstTerm::pyv_oaObserver_oaModInstTerm(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModInstTerm(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModInstTerm::pyv_oaObserver_oaModInstTerm(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModInstTerm(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModInstTerm::pyv_oaObserver_oaModInstTerm(const oaObserver_oaModInstTerm& p)
 : pyob(NULL),
   oaObserver_oaModInstTerm(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModInstTerm::onPostCreate(oaModInstTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModInstTerm::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModInstTerm_FromoaModInstTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModInstTerm::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModInstTerm::onPostModify(oaModInstTerm* p1,oaInstTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModInstTerm::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModInstTerm_FromoaModInstTerm(p1));
    PyTuple_SetItem(args,1,PyoaInstTermModTypeEnum_FromoaInstTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModInstTerm::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModInstTerm::onPreDestroy(oaModInstTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModInstTerm::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModInstTerm_FromoaModInstTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModInstTerm::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModInstTerm::onPreModify(oaModInstTerm* p1,oaInstTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModInstTerm::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModInstTerm_FromoaModInstTerm(p1));
    PyTuple_SetItem(args,1,PyoaInstTermModTypeEnum_FromoaInstTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModInstTerm::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModInstTerm_doc[] = 
"Class: oaObserver_oaModInstTerm\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModInstTerm(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModInstTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModInstTerm\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModInstTerm(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModInstTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModInstTerm\n"
"  Paramegers: (oaObserver_oaModInstTerm)\n"
"    Calls: (const oaObserver_oaModInstTerm&)\n"
"    Signature: oaObserver_oaModInstTerm||cref-oaObserver_oaModInstTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModInstTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModInstTerm",
    sizeof(PyoaObserver_oaModInstTermObject),
    0,
    (destructor)oaObserver_oaModInstTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModInstTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModInstTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModInstTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModInstTerm_oaInstTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModInstTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModInstTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModInstTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModInstTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModInstTerm",
           (PyObject*)(&PyoaObserver_oaModInstTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModInstTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModModuleBitInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModModuleBitInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModModuleBitInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModModuleBitInstObject* self = (PyoaObserver_oaModModuleBitInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModModuleBitInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModModuleBitInst* p=new pyv_oaObserver_oaModModuleBitInst(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModModuleBitInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModModuleBitInst* p=new pyv_oaObserver_oaModModuleBitInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModModuleBitInst)
    {
        PyParamoaObserver_oaModModuleBitInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModModuleBitInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModModuleBitInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModModuleBitInst* p=new pyv_oaObserver_oaModModuleBitInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModModuleBitInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModModuleBitInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModModuleBitInst_tp_dealloc(PyoaObserver_oaModModuleBitInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModModuleBitInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModModuleBitInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModModuleBitInst value;
    int convert_status=PyoaObserver_oaModModuleBitInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaObserver_oaModModuleBitInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModModuleBitInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModModuleBitInst v1;
    PyParamoaObserver_oaModModuleBitInst v2;
    int convert_status1=PyoaObserver_oaModModuleBitInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModModuleBitInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModModuleBitInst_Convert(PyObject* ob,PyParamoaObserver_oaModModuleBitInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModModuleBitInst_Check(ob)) {
        result->SetData( (oaObserver_oaModModuleBitInst*) ((PyoaObserver_oaModModuleBitInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModModuleBitInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModModuleBitInst_FromoaObserver_oaModModuleBitInst(oaObserver_oaModModuleBitInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModModuleBitInst_Type.tp_alloc(&PyoaObserver_oaModModuleBitInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModModuleBitInstObject* self = (PyoaObserver_oaModModuleBitInstObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModModuleBitInst::pyv_oaObserver_oaModModuleBitInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModModuleBitInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModModuleBitInst::pyv_oaObserver_oaModModuleBitInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModModuleBitInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModModuleBitInst::pyv_oaObserver_oaModModuleBitInst(const oaObserver_oaModModuleBitInst& p)
 : pyob(NULL),
   oaObserver_oaModModuleBitInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleBitInst::onPostCreate(oaModModuleBitInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleBitInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModModuleBitInst_FromoaModModuleBitInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleBitInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleBitInst::onPostModify(oaModModuleBitInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleBitInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModModuleBitInst_FromoaModModuleBitInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleBitInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleBitInst::onPreDestroy(oaModModuleBitInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleBitInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModModuleBitInst_FromoaModModuleBitInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleBitInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleBitInst::onPreModify(oaModModuleBitInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleBitInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModModuleBitInst_FromoaModModuleBitInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleBitInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModModuleBitInst_doc[] = 
"Class: oaObserver_oaModModuleBitInst\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModModuleBitInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModModuleBitInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModModuleBitInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModModuleBitInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModModuleBitInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModModuleBitInst\n"
"  Paramegers: (oaObserver_oaModModuleBitInst)\n"
"    Calls: (const oaObserver_oaModModuleBitInst&)\n"
"    Signature: oaObserver_oaModModuleBitInst||cref-oaObserver_oaModModuleBitInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModModuleBitInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModModuleBitInst",
    sizeof(PyoaObserver_oaModModuleBitInstObject),
    0,
    (destructor)oaObserver_oaModModuleBitInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModModuleBitInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModModuleBitInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModModuleBitInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModModuleBitInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModModuleBitInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModModuleBitInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModModuleBitInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModModuleBitInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModModuleBitInst",
           (PyObject*)(&PyoaObserver_oaModModuleBitInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModModuleBitInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModModuleInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModModuleInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModModuleInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModModuleInstObject* self = (PyoaObserver_oaModModuleInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModModuleInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModModuleInst* p=new pyv_oaObserver_oaModModuleInst(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModModuleInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModModuleInst* p=new pyv_oaObserver_oaModModuleInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModModuleInst)
    {
        PyParamoaObserver_oaModModuleInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModModuleInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModModuleInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModModuleInst* p=new pyv_oaObserver_oaModModuleInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModModuleInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModModuleInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModModuleInst_tp_dealloc(PyoaObserver_oaModModuleInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModModuleInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModModuleInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModModuleInst value;
    int convert_status=PyoaObserver_oaModModuleInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaModModuleInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModModuleInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModModuleInst v1;
    PyParamoaObserver_oaModModuleInst v2;
    int convert_status1=PyoaObserver_oaModModuleInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModModuleInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModModuleInst_Convert(PyObject* ob,PyParamoaObserver_oaModModuleInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModModuleInst_Check(ob)) {
        result->SetData( (oaObserver_oaModModuleInst*) ((PyoaObserver_oaModModuleInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModModuleInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModModuleInst_FromoaObserver_oaModModuleInst(oaObserver_oaModModuleInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModModuleInst_Type.tp_alloc(&PyoaObserver_oaModModuleInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModModuleInstObject* self = (PyoaObserver_oaModModuleInstObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModModuleInst::pyv_oaObserver_oaModModuleInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModModuleInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModModuleInst::pyv_oaObserver_oaModModuleInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModModuleInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModModuleInst::pyv_oaObserver_oaModModuleInst(const oaObserver_oaModModuleInst& p)
 : pyob(NULL),
   oaObserver_oaModModuleInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleInst::onPostCreate(oaModModuleInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModModuleInst_FromoaModModuleInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleInst::onPostModify(oaModModuleInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModModuleInst_FromoaModModuleInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleInst::onPreDestroy(oaModModuleInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModModuleInst_FromoaModModuleInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleInst::onPreModify(oaModModuleInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModModuleInst_FromoaModModuleInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModModuleInst_doc[] = 
"Class: oaObserver_oaModModuleInst\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModModuleInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModModuleInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModModuleInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModModuleInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModModuleInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModModuleInst\n"
"  Paramegers: (oaObserver_oaModModuleInst)\n"
"    Calls: (const oaObserver_oaModModuleInst&)\n"
"    Signature: oaObserver_oaModModuleInst||cref-oaObserver_oaModModuleInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModModuleInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModModuleInst",
    sizeof(PyoaObserver_oaModModuleInstObject),
    0,
    (destructor)oaObserver_oaModModuleInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModModuleInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModModuleInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModModuleInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModModuleInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModModuleInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModModuleInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModModuleInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModModuleInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModModuleInst",
           (PyObject*)(&PyoaObserver_oaModModuleInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModModuleInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModModuleInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModModuleInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModModuleInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModModuleInstHeaderObject* self = (PyoaObserver_oaModModuleInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModModuleInstHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaModModuleInstHeader* p=new pyv_oaObserver_oaModModuleInstHeader(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModModuleInstHeader(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModModuleInstHeader* p=new pyv_oaObserver_oaModModuleInstHeader(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModModuleInstHeader)
    {
        PyParamoaObserver_oaModModuleInstHeader p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModModuleInstHeader_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModModuleInstHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaModModuleInstHeader* p=new pyv_oaObserver_oaModModuleInstHeader(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModModuleInstHeader, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModModuleInstHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModModuleInstHeader_tp_dealloc(PyoaObserver_oaModModuleInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModModuleInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModModuleInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModModuleInstHeader value;
    int convert_status=PyoaObserver_oaModModuleInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaObserver_oaModModuleInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModModuleInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModModuleInstHeader v1;
    PyParamoaObserver_oaModModuleInstHeader v2;
    int convert_status1=PyoaObserver_oaModModuleInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModModuleInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModModuleInstHeader_Convert(PyObject* ob,PyParamoaObserver_oaModModuleInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModModuleInstHeader_Check(ob)) {
        result->SetData( (oaObserver_oaModModuleInstHeader*) ((PyoaObserver_oaModModuleInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModModuleInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModModuleInstHeader_FromoaObserver_oaModModuleInstHeader(oaObserver_oaModModuleInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModModuleInstHeader_Type.tp_alloc(&PyoaObserver_oaModModuleInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModModuleInstHeaderObject* self = (PyoaObserver_oaModModuleInstHeaderObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModModuleInstHeader::pyv_oaObserver_oaModModuleInstHeader(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModModuleInstHeader(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModModuleInstHeader::pyv_oaObserver_oaModModuleInstHeader(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModModuleInstHeader(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModModuleInstHeader::pyv_oaObserver_oaModModuleInstHeader(const oaObserver_oaModModuleInstHeader& p)
 : pyob(NULL),
   oaObserver_oaModModuleInstHeader(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleInstHeader::onPostCreate(oaModModuleInstHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleInstHeader::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModModuleInstHeader_FromoaModModuleInstHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleInstHeader::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleInstHeader::onPostModify(oaModModuleInstHeader* p1,oaModuleInstHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleInstHeader::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModModuleInstHeader_FromoaModModuleInstHeader(p1));
    PyTuple_SetItem(args,1,PyoaModuleInstHeaderModTypeEnum_FromoaModuleInstHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleInstHeader::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleInstHeader::onPreDestroy(oaModModuleInstHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleInstHeader::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModModuleInstHeader_FromoaModModuleInstHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleInstHeader::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleInstHeader::onPreModify(oaModModuleInstHeader* p1,oaModuleInstHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleInstHeader::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModModuleInstHeader_FromoaModModuleInstHeader(p1));
    PyTuple_SetItem(args,1,PyoaModuleInstHeaderModTypeEnum_FromoaModuleInstHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleInstHeader::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModModuleInstHeader_doc[] = 
"Class: oaObserver_oaModModuleInstHeader\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModModuleInstHeader(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModModuleInstHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModModuleInstHeader\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModModuleInstHeader(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModModuleInstHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModModuleInstHeader\n"
"  Paramegers: (oaObserver_oaModModuleInstHeader)\n"
"    Calls: (const oaObserver_oaModModuleInstHeader&)\n"
"    Signature: oaObserver_oaModModuleInstHeader||cref-oaObserver_oaModModuleInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModModuleInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModModuleInstHeader",
    sizeof(PyoaObserver_oaModModuleInstHeaderObject),
    0,
    (destructor)oaObserver_oaModModuleInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModModuleInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModModuleInstHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModModuleInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModModuleInstHeader_oaModuleInstHeaderModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModModuleInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModModuleInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModModuleInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModModuleInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModModuleInstHeader",
           (PyObject*)(&PyoaObserver_oaModModuleInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModModuleInstHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModModuleScalarInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModModuleScalarInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModModuleScalarInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModModuleScalarInstObject* self = (PyoaObserver_oaModModuleScalarInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModModuleScalarInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModModuleScalarInst* p=new pyv_oaObserver_oaModModuleScalarInst(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModModuleScalarInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModModuleScalarInst* p=new pyv_oaObserver_oaModModuleScalarInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModModuleScalarInst)
    {
        PyParamoaObserver_oaModModuleScalarInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModModuleScalarInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModModuleScalarInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModModuleScalarInst* p=new pyv_oaObserver_oaModModuleScalarInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModModuleScalarInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModModuleScalarInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModModuleScalarInst_tp_dealloc(PyoaObserver_oaModModuleScalarInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModModuleScalarInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModModuleScalarInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModModuleScalarInst value;
    int convert_status=PyoaObserver_oaModModuleScalarInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaObserver_oaModModuleScalarInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModModuleScalarInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModModuleScalarInst v1;
    PyParamoaObserver_oaModModuleScalarInst v2;
    int convert_status1=PyoaObserver_oaModModuleScalarInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModModuleScalarInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModModuleScalarInst_Convert(PyObject* ob,PyParamoaObserver_oaModModuleScalarInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModModuleScalarInst_Check(ob)) {
        result->SetData( (oaObserver_oaModModuleScalarInst*) ((PyoaObserver_oaModModuleScalarInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModModuleScalarInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModModuleScalarInst_FromoaObserver_oaModModuleScalarInst(oaObserver_oaModModuleScalarInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModModuleScalarInst_Type.tp_alloc(&PyoaObserver_oaModModuleScalarInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModModuleScalarInstObject* self = (PyoaObserver_oaModModuleScalarInstObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModModuleScalarInst::pyv_oaObserver_oaModModuleScalarInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModModuleScalarInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModModuleScalarInst::pyv_oaObserver_oaModModuleScalarInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModModuleScalarInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModModuleScalarInst::pyv_oaObserver_oaModModuleScalarInst(const oaObserver_oaModModuleScalarInst& p)
 : pyob(NULL),
   oaObserver_oaModModuleScalarInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleScalarInst::onPostCreate(oaModModuleScalarInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleScalarInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModModuleScalarInst_FromoaModModuleScalarInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleScalarInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleScalarInst::onPostModify(oaModModuleScalarInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleScalarInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModModuleScalarInst_FromoaModModuleScalarInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleScalarInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleScalarInst::onPreDestroy(oaModModuleScalarInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleScalarInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModModuleScalarInst_FromoaModModuleScalarInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleScalarInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleScalarInst::onPreModify(oaModModuleScalarInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleScalarInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModModuleScalarInst_FromoaModModuleScalarInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleScalarInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModModuleScalarInst_doc[] = 
"Class: oaObserver_oaModModuleScalarInst\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModModuleScalarInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModModuleScalarInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModModuleScalarInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModModuleScalarInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModModuleScalarInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModModuleScalarInst\n"
"  Paramegers: (oaObserver_oaModModuleScalarInst)\n"
"    Calls: (const oaObserver_oaModModuleScalarInst&)\n"
"    Signature: oaObserver_oaModModuleScalarInst||cref-oaObserver_oaModModuleScalarInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModModuleScalarInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModModuleScalarInst",
    sizeof(PyoaObserver_oaModModuleScalarInstObject),
    0,
    (destructor)oaObserver_oaModModuleScalarInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModModuleScalarInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModModuleScalarInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModModuleScalarInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModModuleScalarInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModModuleScalarInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModModuleScalarInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModModuleScalarInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModModuleScalarInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModModuleScalarInst",
           (PyObject*)(&PyoaObserver_oaModModuleScalarInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModModuleScalarInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModModuleVectorInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModModuleVectorInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModModuleVectorInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModModuleVectorInstObject* self = (PyoaObserver_oaModModuleVectorInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModModuleVectorInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModModuleVectorInst* p=new pyv_oaObserver_oaModModuleVectorInst(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModModuleVectorInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModModuleVectorInst* p=new pyv_oaObserver_oaModModuleVectorInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModModuleVectorInst)
    {
        PyParamoaObserver_oaModModuleVectorInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModModuleVectorInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModModuleVectorInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModModuleVectorInst* p=new pyv_oaObserver_oaModModuleVectorInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModModuleVectorInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModModuleVectorInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModModuleVectorInst_tp_dealloc(PyoaObserver_oaModModuleVectorInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModModuleVectorInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModModuleVectorInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModModuleVectorInst value;
    int convert_status=PyoaObserver_oaModModuleVectorInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaObserver_oaModModuleVectorInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModModuleVectorInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModModuleVectorInst v1;
    PyParamoaObserver_oaModModuleVectorInst v2;
    int convert_status1=PyoaObserver_oaModModuleVectorInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModModuleVectorInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModModuleVectorInst_Convert(PyObject* ob,PyParamoaObserver_oaModModuleVectorInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModModuleVectorInst_Check(ob)) {
        result->SetData( (oaObserver_oaModModuleVectorInst*) ((PyoaObserver_oaModModuleVectorInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModModuleVectorInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModModuleVectorInst_FromoaObserver_oaModModuleVectorInst(oaObserver_oaModModuleVectorInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModModuleVectorInst_Type.tp_alloc(&PyoaObserver_oaModModuleVectorInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModModuleVectorInstObject* self = (PyoaObserver_oaModModuleVectorInstObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModModuleVectorInst::pyv_oaObserver_oaModModuleVectorInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModModuleVectorInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModModuleVectorInst::pyv_oaObserver_oaModModuleVectorInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModModuleVectorInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModModuleVectorInst::pyv_oaObserver_oaModModuleVectorInst(const oaObserver_oaModModuleVectorInst& p)
 : pyob(NULL),
   oaObserver_oaModModuleVectorInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleVectorInst::onPostCreate(oaModModuleVectorInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleVectorInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModModuleVectorInst_FromoaModModuleVectorInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleVectorInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleVectorInst::onPostModify(oaModModuleVectorInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleVectorInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModModuleVectorInst_FromoaModModuleVectorInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleVectorInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleVectorInst::onPreDestroy(oaModModuleVectorInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleVectorInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModModuleVectorInst_FromoaModModuleVectorInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleVectorInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleVectorInst::onPreModify(oaModModuleVectorInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleVectorInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModModuleVectorInst_FromoaModModuleVectorInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleVectorInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModModuleVectorInst_doc[] = 
"Class: oaObserver_oaModModuleVectorInst\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModModuleVectorInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModModuleVectorInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModModuleVectorInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModModuleVectorInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModModuleVectorInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModModuleVectorInst\n"
"  Paramegers: (oaObserver_oaModModuleVectorInst)\n"
"    Calls: (const oaObserver_oaModModuleVectorInst&)\n"
"    Signature: oaObserver_oaModModuleVectorInst||cref-oaObserver_oaModModuleVectorInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModModuleVectorInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModModuleVectorInst",
    sizeof(PyoaObserver_oaModModuleVectorInstObject),
    0,
    (destructor)oaObserver_oaModModuleVectorInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModModuleVectorInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModModuleVectorInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModModuleVectorInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModModuleVectorInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModModuleVectorInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModModuleVectorInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModModuleVectorInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModModuleVectorInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModModuleVectorInst",
           (PyObject*)(&PyoaObserver_oaModModuleVectorInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModModuleVectorInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModModuleVectorInstBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModModuleVectorInstBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModModuleVectorInstBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModModuleVectorInstBitObject* self = (PyoaObserver_oaModModuleVectorInstBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModModuleVectorInstBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaModModuleVectorInstBit* p=new pyv_oaObserver_oaModModuleVectorInstBit(p1.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaBoolean)
    {
        PyParamoaUInt4 p1;
        PyParamoaBoolean p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaBoolean_Convert,&p2)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModModuleVectorInstBit(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModModuleVectorInstBit* p=new pyv_oaObserver_oaModModuleVectorInstBit(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModModuleVectorInstBit)
    {
        PyParamoaObserver_oaModModuleVectorInstBit p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModModuleVectorInstBit_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModModuleVectorInstBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaModModuleVectorInstBit* p=new pyv_oaObserver_oaModModuleVectorInstBit(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModModuleVectorInstBit, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModModuleVectorInstBit)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModModuleVectorInstBit_tp_dealloc(PyoaObserver_oaModModuleVectorInstBitObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModModuleVectorInstBit*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModModuleVectorInstBit_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModModuleVectorInstBit value;
    int convert_status=PyoaObserver_oaModModuleVectorInstBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[57];
    sprintf(buffer,"<oaObserver_oaModModuleVectorInstBit::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModModuleVectorInstBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModModuleVectorInstBit v1;
    PyParamoaObserver_oaModModuleVectorInstBit v2;
    int convert_status1=PyoaObserver_oaModModuleVectorInstBit_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModModuleVectorInstBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModModuleVectorInstBit_Convert(PyObject* ob,PyParamoaObserver_oaModModuleVectorInstBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModModuleVectorInstBit_Check(ob)) {
        result->SetData( (oaObserver_oaModModuleVectorInstBit*) ((PyoaObserver_oaModModuleVectorInstBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModModuleVectorInstBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModModuleVectorInstBit_FromoaObserver_oaModModuleVectorInstBit(oaObserver_oaModModuleVectorInstBit* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModModuleVectorInstBit_Type.tp_alloc(&PyoaObserver_oaModModuleVectorInstBit_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModModuleVectorInstBitObject* self = (PyoaObserver_oaModModuleVectorInstBitObject*)bself;
        self->value = (oaBaseObserver*)  data;
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
pyv_oaObserver_oaModModuleVectorInstBit::pyv_oaObserver_oaModModuleVectorInstBit(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModModuleVectorInstBit(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModModuleVectorInstBit::pyv_oaObserver_oaModModuleVectorInstBit(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModModuleVectorInstBit(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModModuleVectorInstBit::pyv_oaObserver_oaModModuleVectorInstBit(const oaObserver_oaModModuleVectorInstBit& p)
 : pyob(NULL),
   oaObserver_oaModModuleVectorInstBit(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleVectorInstBit::onPostCreate(oaModModuleVectorInstBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleVectorInstBit::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModModuleVectorInstBit_FromoaModModuleVectorInstBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleVectorInstBit::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleVectorInstBit::onPostModify(oaModModuleVectorInstBit* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleVectorInstBit::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModModuleVectorInstBit_FromoaModModuleVectorInstBit(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleVectorInstBit::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleVectorInstBit::onPreDestroy(oaModModuleVectorInstBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleVectorInstBit::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModModuleVectorInstBit_FromoaModModuleVectorInstBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleVectorInstBit::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModModuleVectorInstBit::onPreModify(oaModModuleVectorInstBit* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleVectorInstBit::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModModuleVectorInstBit_FromoaModModuleVectorInstBit(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModModuleVectorInstBit::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModModuleVectorInstBit_doc[] = 
"Class: oaObserver_oaModModuleVectorInstBit\n"
"  Observers are a set of classes that allow applications to request notification whenever certain changes occur to the state and contents of open databases. This allows a complex application to keep its internal state consistent with changes made by other code in the same process.\n"
"  The oaObserver<> class is an abstract template class used as the base class for observers in OpenAccess. OpenAccess defines which classes can have observers, and what the modification enum is for observers that provide modification notification. Observers are allowed at a certain level of the managed class hierarchy where the observer is expected to map to the needs of applications. For example, there is no oaFig observer. All the observers for figures are at a lower level of the class hierarchy. There is an observer for oaShapes. There is no observer specific to oaRects, and an application that only wants to know about changes to oaRects would have to create an oaShape observer and test the type of the shape in its oaShape observer notification functions. The OpenAccess Observer Table , below, lists the available OpenAccess observers and provides information about the notifications associated with each observer and the modification enum associated with each observer that provides modification notifications (see Observer Notification Functions for additional information).\n"
"  Callers use observers by:\n"
"  declaring their own derived class that inherits from the appropriate Observer<> base class. For a list of available observer template classes from which users can derive their own observer classes, see the Observer<oaClassName> (leftmost) column of the OpenAccess Observer Table , below.\n"
"  implementing virtual notification functions that correspond to events for which callers are requesting notification. For a description of the different notification functions associated with different observers, see Observer Notification Functions , below.\n"
"  constructing an instance of the derived class in order to register its functions in a given application.\n"
"  Observer Enable and Priority Settings\n"
"  Two important capabilities of all OpenAccess observer base classes are the following:\n"
"  1) Observers can be enabled or disabled as desired (either during construction -- or by calling the observer's enable() function). Disabled observers are not called. The enabled status of an observer can be checked by calling isEnabled().\n"
"  2) Observers are ordered by priority. Observers with higher priority (which means those with lower priority numbers) are called first. The priority of each observer is established during construction of the observer (see ).\n"
"  Observer Notification Functions\n"
"  The OpenAccess Observer hierarchy implements a standard set of observer notification functions, as described in Standard Notifications . OpenAccess also implements specialized notification functions for particular oaObserver classes, which are categorized as special notifications below.\n"
"  Note: The notification function category associated with each observer is listed in the Notification Functions (middle) column of the OpenAccess Observer Table, below.\n"
"  Standard Notifications\n"
"  Standard observers, which are derived from oaStdObserver , provide notification of object creation, destruction and modification, as follows:\n"
"  class myLibDefListObserver : public oaObserver<oaLibDefList> { public : myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn = true ); oaBoolean onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type); }; myLibDefListObserver::myLibDefListObserver(oaUInt4 priorityIn, oaBoolean enabledIn) :oaObserver< oaLibDefList >(priorityIn, enabledIn) { } oaBoolean myLibDefListObserver::onLoadWarnings( oaLibDefList *obj, const oaString &msg, oaLibDefListWarningTypeEnum type) { if (!obj) { cout << \"Error trying to open default libs.def file: \" << msg << endl; } else { oaString libDefPath; obj-> getPath (libDefPath); switch (type) { case oacSyntaxErrorLibDefListWarning: cout << \"Syntax error in \" << libDefPath << \": \" << msg << endl; break ; default : cout << libDefPath << \" load warning: \" << msg << endl; break ; } } return true ; }\n"
"  oaObserver Class Implementation Notes\n"
"  The oaObserver template class and its specializations are defined as oaVersionedObserver template and its corresponding specializations. This template has an additional non-type template argument for the version of the observer. The oaObserver identifier is defined in the header files as oaVersionedObserver. This is required to add new virtual functions to the specialization (such as the specialization for oaTech ). Application code must reference oaObserver. Direct reference of oaVersionedObserver is not supported. The implementation of the oaObserver class is transparent and applications must use oaObserver directly as before.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaModModuleVectorInstBit(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModModuleVectorInstBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModModuleVectorInstBit\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModModuleVectorInstBit(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModModuleVectorInstBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModModuleVectorInstBit\n"
"  Paramegers: (oaObserver_oaModModuleVectorInstBit)\n"
"    Calls: (const oaObserver_oaModModuleVectorInstBit&)\n"
"    Signature: oaObserver_oaModModuleVectorInstBit||cref-oaObserver_oaModModuleVectorInstBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModModuleVectorInstBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModModuleVectorInstBit",
    sizeof(PyoaObserver_oaModModuleVectorInstBitObject),
    0,
    (destructor)oaObserver_oaModModuleVectorInstBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModModuleVectorInstBit_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModModuleVectorInstBit_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModModuleVectorInstBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModModuleVectorInstBit_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModModuleVectorInstBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModModuleVectorInstBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModModuleVectorInstBit_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModModuleVectorInstBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModModuleVectorInstBit",
           (PyObject*)(&PyoaObserver_oaModModuleVectorInstBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModModuleVectorInstBit\n");
       return -1;
    }
    return 0;
}

