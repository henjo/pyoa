
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModNetObject* self = (PyoaObserver_oaModNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaModNet* p=new pyv_oaObserver_oaModNet(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaModNet(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModNet* p=new pyv_oaObserver_oaModNet(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModNet)
    {
        PyParamoaObserver_oaModNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModNet_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaModNet* p=new pyv_oaObserver_oaModNet(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModNet, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModNet_tp_dealloc(PyoaObserver_oaModNetObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModNet_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModNet value;
    int convert_status=PyoaObserver_oaModNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaObserver_oaModNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModNet v1;
    PyParamoaObserver_oaModNet v2;
    int convert_status1=PyoaObserver_oaModNet_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModNet_Convert(PyObject* ob,PyParamoaObserver_oaModNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModNet_Check(ob)) {
        result->SetData( (oaObserver_oaModNet*) ((PyoaObserver_oaModNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModNet_FromoaObserver_oaModNet(oaObserver_oaModNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModNet_Type.tp_alloc(&PyoaObserver_oaModNet_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModNetObject* self = (PyoaObserver_oaModNetObject*)bself;
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
pyv_oaObserver_oaModNet::pyv_oaObserver_oaModNet(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModNet(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModNet::pyv_oaObserver_oaModNet(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModNet(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModNet::pyv_oaObserver_oaModNet(const oaObserver_oaModNet& p)
 : pyob(NULL),
   oaObserver_oaModNet(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModNet::onPostCreate(oaModNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModNet::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModNet_FromoaModNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModNet::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModNet::onPostModify(oaModNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModNet::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModNet_FromoaModNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModNet::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModNet::onPreDestroy(oaModNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModNet::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModNet_FromoaModNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModNet::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModNet::onPreModify(oaModNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModNet::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModNet_FromoaModNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModNet::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModNet_doc[] = 
"Class: oaObserver_oaModNet\n"
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
"    Calls: oaObserver_oaModNet(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModNet\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModNet(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModNet\n"
"  Paramegers: (oaObserver_oaModNet)\n"
"    Calls: (const oaObserver_oaModNet&)\n"
"    Signature: oaObserver_oaModNet||cref-oaObserver_oaModNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModNet",
    sizeof(PyoaObserver_oaModNetObject),
    0,
    (destructor)oaObserver_oaModNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModNet_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModNet_oaNetModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModNet_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModNet",
           (PyObject*)(&PyoaObserver_oaModNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModNetConnectDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModNetConnectDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModNetConnectDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModNetConnectDefObject* self = (PyoaObserver_oaModNetConnectDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModNetConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaModNetConnectDef* p=new pyv_oaObserver_oaModNetConnectDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaModNetConnectDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModNetConnectDef* p=new pyv_oaObserver_oaModNetConnectDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModNetConnectDef)
    {
        PyParamoaObserver_oaModNetConnectDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModNetConnectDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModNetConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaModNetConnectDef* p=new pyv_oaObserver_oaModNetConnectDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModNetConnectDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModNetConnectDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModNetConnectDef_tp_dealloc(PyoaObserver_oaModNetConnectDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModNetConnectDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModNetConnectDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModNetConnectDef value;
    int convert_status=PyoaObserver_oaModNetConnectDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaObserver_oaModNetConnectDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModNetConnectDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModNetConnectDef v1;
    PyParamoaObserver_oaModNetConnectDef v2;
    int convert_status1=PyoaObserver_oaModNetConnectDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModNetConnectDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModNetConnectDef_Convert(PyObject* ob,PyParamoaObserver_oaModNetConnectDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModNetConnectDef_Check(ob)) {
        result->SetData( (oaObserver_oaModNetConnectDef*) ((PyoaObserver_oaModNetConnectDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModNetConnectDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModNetConnectDef_FromoaObserver_oaModNetConnectDef(oaObserver_oaModNetConnectDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModNetConnectDef_Type.tp_alloc(&PyoaObserver_oaModNetConnectDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModNetConnectDefObject* self = (PyoaObserver_oaModNetConnectDefObject*)bself;
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
pyv_oaObserver_oaModNetConnectDef::pyv_oaObserver_oaModNetConnectDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModNetConnectDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModNetConnectDef::pyv_oaObserver_oaModNetConnectDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModNetConnectDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModNetConnectDef::pyv_oaObserver_oaModNetConnectDef(const oaObserver_oaModNetConnectDef& p)
 : pyob(NULL),
   oaObserver_oaModNetConnectDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModNetConnectDef::onPostCreate(oaModNetConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModNetConnectDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModNetConnectDef_FromoaModNetConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModNetConnectDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModNetConnectDef::onPostModify(oaModNetConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModNetConnectDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModNetConnectDef_FromoaModNetConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModNetConnectDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModNetConnectDef::onPreDestroy(oaModNetConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModNetConnectDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModNetConnectDef_FromoaModNetConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModNetConnectDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModNetConnectDef::onPreModify(oaModNetConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModNetConnectDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModNetConnectDef_FromoaModNetConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModNetConnectDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModNetConnectDef_doc[] = 
"Class: oaObserver_oaModNetConnectDef\n"
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
"    Calls: oaObserver_oaModNetConnectDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModNetConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModNetConnectDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModNetConnectDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModNetConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModNetConnectDef\n"
"  Paramegers: (oaObserver_oaModNetConnectDef)\n"
"    Calls: (const oaObserver_oaModNetConnectDef&)\n"
"    Signature: oaObserver_oaModNetConnectDef||cref-oaObserver_oaModNetConnectDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModNetConnectDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModNetConnectDef",
    sizeof(PyoaObserver_oaModNetConnectDefObject),
    0,
    (destructor)oaObserver_oaModNetConnectDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModNetConnectDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModNetConnectDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModNetConnectDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModNetConnectDef_oaConnectDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModNetConnectDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModNetConnectDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModNetConnectDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModNetConnectDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModNetConnectDef",
           (PyObject*)(&PyoaObserver_oaModNetConnectDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModNetConnectDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModScalarInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModScalarInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModScalarInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModScalarInstObject* self = (PyoaObserver_oaModScalarInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModScalarInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModScalarInst* p=new pyv_oaObserver_oaModScalarInst(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaModScalarInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModScalarInst* p=new pyv_oaObserver_oaModScalarInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModScalarInst)
    {
        PyParamoaObserver_oaModScalarInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModScalarInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModScalarInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModScalarInst* p=new pyv_oaObserver_oaModScalarInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModScalarInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModScalarInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModScalarInst_tp_dealloc(PyoaObserver_oaModScalarInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModScalarInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModScalarInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModScalarInst value;
    int convert_status=PyoaObserver_oaModScalarInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaModScalarInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModScalarInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModScalarInst v1;
    PyParamoaObserver_oaModScalarInst v2;
    int convert_status1=PyoaObserver_oaModScalarInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModScalarInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModScalarInst_Convert(PyObject* ob,PyParamoaObserver_oaModScalarInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModScalarInst_Check(ob)) {
        result->SetData( (oaObserver_oaModScalarInst*) ((PyoaObserver_oaModScalarInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModScalarInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModScalarInst_FromoaObserver_oaModScalarInst(oaObserver_oaModScalarInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModScalarInst_Type.tp_alloc(&PyoaObserver_oaModScalarInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModScalarInstObject* self = (PyoaObserver_oaModScalarInstObject*)bself;
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
pyv_oaObserver_oaModScalarInst::pyv_oaObserver_oaModScalarInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModScalarInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModScalarInst::pyv_oaObserver_oaModScalarInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModScalarInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModScalarInst::pyv_oaObserver_oaModScalarInst(const oaObserver_oaModScalarInst& p)
 : pyob(NULL),
   oaObserver_oaModScalarInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModScalarInst::onPostCreate(oaModScalarInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModScalarInst_FromoaModScalarInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModScalarInst::onPostModify(oaModScalarInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModScalarInst_FromoaModScalarInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModScalarInst::onPreDestroy(oaModScalarInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModScalarInst_FromoaModScalarInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModScalarInst::onPreModify(oaModScalarInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModScalarInst_FromoaModScalarInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModScalarInst_doc[] = 
"Class: oaObserver_oaModScalarInst\n"
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
"    Calls: oaObserver_oaModScalarInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModScalarInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModScalarInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModScalarInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModScalarInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModScalarInst\n"
"  Paramegers: (oaObserver_oaModScalarInst)\n"
"    Calls: (const oaObserver_oaModScalarInst&)\n"
"    Signature: oaObserver_oaModScalarInst||cref-oaObserver_oaModScalarInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModScalarInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModScalarInst",
    sizeof(PyoaObserver_oaModScalarInstObject),
    0,
    (destructor)oaObserver_oaModScalarInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModScalarInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModScalarInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModScalarInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModScalarInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModScalarInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModScalarInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModScalarInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModScalarInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModScalarInst",
           (PyObject*)(&PyoaObserver_oaModScalarInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModScalarInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModScalarNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModScalarNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModScalarNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModScalarNetObject* self = (PyoaObserver_oaModScalarNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModScalarNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaModScalarNet* p=new pyv_oaObserver_oaModScalarNet(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaModScalarNet(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModScalarNet* p=new pyv_oaObserver_oaModScalarNet(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModScalarNet)
    {
        PyParamoaObserver_oaModScalarNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModScalarNet_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModScalarNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaModScalarNet* p=new pyv_oaObserver_oaModScalarNet(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModScalarNet, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModScalarNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModScalarNet_tp_dealloc(PyoaObserver_oaModScalarNetObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModScalarNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModScalarNet_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModScalarNet value;
    int convert_status=PyoaObserver_oaModScalarNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaModScalarNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModScalarNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModScalarNet v1;
    PyParamoaObserver_oaModScalarNet v2;
    int convert_status1=PyoaObserver_oaModScalarNet_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModScalarNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModScalarNet_Convert(PyObject* ob,PyParamoaObserver_oaModScalarNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModScalarNet_Check(ob)) {
        result->SetData( (oaObserver_oaModScalarNet*) ((PyoaObserver_oaModScalarNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModScalarNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModScalarNet_FromoaObserver_oaModScalarNet(oaObserver_oaModScalarNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModScalarNet_Type.tp_alloc(&PyoaObserver_oaModScalarNet_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModScalarNetObject* self = (PyoaObserver_oaModScalarNetObject*)bself;
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
pyv_oaObserver_oaModScalarNet::pyv_oaObserver_oaModScalarNet(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModScalarNet(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModScalarNet::pyv_oaObserver_oaModScalarNet(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModScalarNet(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModScalarNet::pyv_oaObserver_oaModScalarNet(const oaObserver_oaModScalarNet& p)
 : pyob(NULL),
   oaObserver_oaModScalarNet(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModScalarNet::onPostCreate(oaModScalarNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarNet::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModScalarNet_FromoaModScalarNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarNet::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModScalarNet::onPostModify(oaModScalarNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarNet::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModScalarNet_FromoaModScalarNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarNet::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModScalarNet::onPreDestroy(oaModScalarNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarNet::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModScalarNet_FromoaModScalarNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarNet::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModScalarNet::onPreModify(oaModScalarNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarNet::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModScalarNet_FromoaModScalarNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarNet::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModScalarNet_doc[] = 
"Class: oaObserver_oaModScalarNet\n"
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
"    Calls: oaObserver_oaModScalarNet(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModScalarNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModScalarNet\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModScalarNet(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModScalarNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModScalarNet\n"
"  Paramegers: (oaObserver_oaModScalarNet)\n"
"    Calls: (const oaObserver_oaModScalarNet&)\n"
"    Signature: oaObserver_oaModScalarNet||cref-oaObserver_oaModScalarNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModScalarNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModScalarNet",
    sizeof(PyoaObserver_oaModScalarNetObject),
    0,
    (destructor)oaObserver_oaModScalarNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModScalarNet_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModScalarNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModScalarNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModScalarNet_oaNetModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModScalarNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModScalarNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModScalarNet_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModScalarNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModScalarNet",
           (PyObject*)(&PyoaObserver_oaModScalarNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModScalarNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModScalarTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModScalarTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModScalarTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModScalarTermObject* self = (PyoaObserver_oaModScalarTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModScalarTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaModScalarTerm* p=new pyv_oaObserver_oaModScalarTerm(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaModScalarTerm(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModScalarTerm* p=new pyv_oaObserver_oaModScalarTerm(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModScalarTerm)
    {
        PyParamoaObserver_oaModScalarTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModScalarTerm_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModScalarTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaModScalarTerm* p=new pyv_oaObserver_oaModScalarTerm(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModScalarTerm, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModScalarTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModScalarTerm_tp_dealloc(PyoaObserver_oaModScalarTermObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModScalarTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModScalarTerm_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModScalarTerm value;
    int convert_status=PyoaObserver_oaModScalarTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaModScalarTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModScalarTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModScalarTerm v1;
    PyParamoaObserver_oaModScalarTerm v2;
    int convert_status1=PyoaObserver_oaModScalarTerm_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModScalarTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModScalarTerm_Convert(PyObject* ob,PyParamoaObserver_oaModScalarTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModScalarTerm_Check(ob)) {
        result->SetData( (oaObserver_oaModScalarTerm*) ((PyoaObserver_oaModScalarTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModScalarTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModScalarTerm_FromoaObserver_oaModScalarTerm(oaObserver_oaModScalarTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModScalarTerm_Type.tp_alloc(&PyoaObserver_oaModScalarTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModScalarTermObject* self = (PyoaObserver_oaModScalarTermObject*)bself;
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
pyv_oaObserver_oaModScalarTerm::pyv_oaObserver_oaModScalarTerm(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModScalarTerm(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModScalarTerm::pyv_oaObserver_oaModScalarTerm(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModScalarTerm(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModScalarTerm::pyv_oaObserver_oaModScalarTerm(const oaObserver_oaModScalarTerm& p)
 : pyob(NULL),
   oaObserver_oaModScalarTerm(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModScalarTerm::onPostCreate(oaModScalarTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarTerm::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModScalarTerm_FromoaModScalarTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarTerm::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModScalarTerm::onPostModify(oaModScalarTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarTerm::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModScalarTerm_FromoaModScalarTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarTerm::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModScalarTerm::onPreDestroy(oaModScalarTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarTerm::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModScalarTerm_FromoaModScalarTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarTerm::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModScalarTerm::onPreModify(oaModScalarTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarTerm::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModScalarTerm_FromoaModScalarTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModScalarTerm::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModScalarTerm_doc[] = 
"Class: oaObserver_oaModScalarTerm\n"
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
"    Calls: oaObserver_oaModScalarTerm(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModScalarTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModScalarTerm\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModScalarTerm(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModScalarTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModScalarTerm\n"
"  Paramegers: (oaObserver_oaModScalarTerm)\n"
"    Calls: (const oaObserver_oaModScalarTerm&)\n"
"    Signature: oaObserver_oaModScalarTerm||cref-oaObserver_oaModScalarTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModScalarTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModScalarTerm",
    sizeof(PyoaObserver_oaModScalarTermObject),
    0,
    (destructor)oaObserver_oaModScalarTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModScalarTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModScalarTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModScalarTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModScalarTerm_oaTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModScalarTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModScalarTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModScalarTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModScalarTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModScalarTerm",
           (PyObject*)(&PyoaObserver_oaModScalarTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModScalarTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModTermObject* self = (PyoaObserver_oaModTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaModTerm* p=new pyv_oaObserver_oaModTerm(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaModTerm(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModTerm* p=new pyv_oaObserver_oaModTerm(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModTerm)
    {
        PyParamoaObserver_oaModTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModTerm_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaModTerm* p=new pyv_oaObserver_oaModTerm(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModTerm, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModTerm_tp_dealloc(PyoaObserver_oaModTermObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModTerm_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModTerm value;
    int convert_status=PyoaObserver_oaModTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaObserver_oaModTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModTerm v1;
    PyParamoaObserver_oaModTerm v2;
    int convert_status1=PyoaObserver_oaModTerm_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModTerm_Convert(PyObject* ob,PyParamoaObserver_oaModTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModTerm_Check(ob)) {
        result->SetData( (oaObserver_oaModTerm*) ((PyoaObserver_oaModTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModTerm_FromoaObserver_oaModTerm(oaObserver_oaModTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModTerm_Type.tp_alloc(&PyoaObserver_oaModTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModTermObject* self = (PyoaObserver_oaModTermObject*)bself;
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
pyv_oaObserver_oaModTerm::pyv_oaObserver_oaModTerm(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModTerm(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModTerm::pyv_oaObserver_oaModTerm(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModTerm(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModTerm::pyv_oaObserver_oaModTerm(const oaObserver_oaModTerm& p)
 : pyob(NULL),
   oaObserver_oaModTerm(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModTerm::onPostCreate(oaModTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModTerm::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModTerm_FromoaModTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModTerm::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModTerm::onPostModify(oaModTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModTerm::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModTerm_FromoaModTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModTerm::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModTerm::onPreDestroy(oaModTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModTerm::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModTerm_FromoaModTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModTerm::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModTerm::onPreModify(oaModTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModTerm::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModTerm_FromoaModTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModTerm::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModTerm_doc[] = 
"Class: oaObserver_oaModTerm\n"
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
"    Calls: oaObserver_oaModTerm(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModTerm\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModTerm(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModTerm\n"
"  Paramegers: (oaObserver_oaModTerm)\n"
"    Calls: (const oaObserver_oaModTerm&)\n"
"    Signature: oaObserver_oaModTerm||cref-oaObserver_oaModTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModTerm",
    sizeof(PyoaObserver_oaModTermObject),
    0,
    (destructor)oaObserver_oaModTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModTerm_oaTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModTerm",
           (PyObject*)(&PyoaObserver_oaModTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModTermConnectDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModTermConnectDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModTermConnectDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModTermConnectDefObject* self = (PyoaObserver_oaModTermConnectDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModTermConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaModTermConnectDef* p=new pyv_oaObserver_oaModTermConnectDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaModTermConnectDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModTermConnectDef* p=new pyv_oaObserver_oaModTermConnectDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModTermConnectDef)
    {
        PyParamoaObserver_oaModTermConnectDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModTermConnectDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModTermConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaModTermConnectDef* p=new pyv_oaObserver_oaModTermConnectDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModTermConnectDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModTermConnectDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModTermConnectDef_tp_dealloc(PyoaObserver_oaModTermConnectDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModTermConnectDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModTermConnectDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModTermConnectDef value;
    int convert_status=PyoaObserver_oaModTermConnectDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaObserver_oaModTermConnectDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModTermConnectDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModTermConnectDef v1;
    PyParamoaObserver_oaModTermConnectDef v2;
    int convert_status1=PyoaObserver_oaModTermConnectDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModTermConnectDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModTermConnectDef_Convert(PyObject* ob,PyParamoaObserver_oaModTermConnectDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModTermConnectDef_Check(ob)) {
        result->SetData( (oaObserver_oaModTermConnectDef*) ((PyoaObserver_oaModTermConnectDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModTermConnectDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModTermConnectDef_FromoaObserver_oaModTermConnectDef(oaObserver_oaModTermConnectDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModTermConnectDef_Type.tp_alloc(&PyoaObserver_oaModTermConnectDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModTermConnectDefObject* self = (PyoaObserver_oaModTermConnectDefObject*)bself;
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
pyv_oaObserver_oaModTermConnectDef::pyv_oaObserver_oaModTermConnectDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModTermConnectDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModTermConnectDef::pyv_oaObserver_oaModTermConnectDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModTermConnectDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModTermConnectDef::pyv_oaObserver_oaModTermConnectDef(const oaObserver_oaModTermConnectDef& p)
 : pyob(NULL),
   oaObserver_oaModTermConnectDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModTermConnectDef::onPostCreate(oaModTermConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModTermConnectDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModTermConnectDef_FromoaModTermConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModTermConnectDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModTermConnectDef::onPostModify(oaModTermConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModTermConnectDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModTermConnectDef_FromoaModTermConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModTermConnectDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModTermConnectDef::onPreDestroy(oaModTermConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModTermConnectDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModTermConnectDef_FromoaModTermConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModTermConnectDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModTermConnectDef::onPreModify(oaModTermConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModTermConnectDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModTermConnectDef_FromoaModTermConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModTermConnectDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModTermConnectDef_doc[] = 
"Class: oaObserver_oaModTermConnectDef\n"
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
"    Calls: oaObserver_oaModTermConnectDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModTermConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModTermConnectDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModTermConnectDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModTermConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModTermConnectDef\n"
"  Paramegers: (oaObserver_oaModTermConnectDef)\n"
"    Calls: (const oaObserver_oaModTermConnectDef&)\n"
"    Signature: oaObserver_oaModTermConnectDef||cref-oaObserver_oaModTermConnectDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModTermConnectDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModTermConnectDef",
    sizeof(PyoaObserver_oaModTermConnectDefObject),
    0,
    (destructor)oaObserver_oaModTermConnectDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModTermConnectDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModTermConnectDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModTermConnectDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModTermConnectDef_oaConnectDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModTermConnectDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModTermConnectDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModTermConnectDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModTermConnectDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModTermConnectDef",
           (PyObject*)(&PyoaObserver_oaModTermConnectDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModTermConnectDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModVectorInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModVectorInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModVectorInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModVectorInstObject* self = (PyoaObserver_oaModVectorInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModVectorInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModVectorInst* p=new pyv_oaObserver_oaModVectorInst(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaModVectorInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModVectorInst* p=new pyv_oaObserver_oaModVectorInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModVectorInst)
    {
        PyParamoaObserver_oaModVectorInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModVectorInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModVectorInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaModVectorInst* p=new pyv_oaObserver_oaModVectorInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModVectorInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModVectorInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModVectorInst_tp_dealloc(PyoaObserver_oaModVectorInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModVectorInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModVectorInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModVectorInst value;
    int convert_status=PyoaObserver_oaModVectorInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaModVectorInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModVectorInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModVectorInst v1;
    PyParamoaObserver_oaModVectorInst v2;
    int convert_status1=PyoaObserver_oaModVectorInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModVectorInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModVectorInst_Convert(PyObject* ob,PyParamoaObserver_oaModVectorInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModVectorInst_Check(ob)) {
        result->SetData( (oaObserver_oaModVectorInst*) ((PyoaObserver_oaModVectorInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModVectorInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModVectorInst_FromoaObserver_oaModVectorInst(oaObserver_oaModVectorInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModVectorInst_Type.tp_alloc(&PyoaObserver_oaModVectorInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModVectorInstObject* self = (PyoaObserver_oaModVectorInstObject*)bself;
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
pyv_oaObserver_oaModVectorInst::pyv_oaObserver_oaModVectorInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModVectorInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModVectorInst::pyv_oaObserver_oaModVectorInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModVectorInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModVectorInst::pyv_oaObserver_oaModVectorInst(const oaObserver_oaModVectorInst& p)
 : pyob(NULL),
   oaObserver_oaModVectorInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModVectorInst::onPostCreate(oaModVectorInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModVectorInst_FromoaModVectorInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModVectorInst::onPostModify(oaModVectorInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModVectorInst_FromoaModVectorInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModVectorInst::onPreDestroy(oaModVectorInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModVectorInst_FromoaModVectorInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModVectorInst::onPreModify(oaModVectorInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModVectorInst_FromoaModVectorInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModVectorInst_doc[] = 
"Class: oaObserver_oaModVectorInst\n"
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
"    Calls: oaObserver_oaModVectorInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModVectorInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModVectorInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModVectorInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModVectorInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModVectorInst\n"
"  Paramegers: (oaObserver_oaModVectorInst)\n"
"    Calls: (const oaObserver_oaModVectorInst&)\n"
"    Signature: oaObserver_oaModVectorInst||cref-oaObserver_oaModVectorInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModVectorInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModVectorInst",
    sizeof(PyoaObserver_oaModVectorInstObject),
    0,
    (destructor)oaObserver_oaModVectorInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModVectorInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModVectorInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModVectorInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModVectorInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModVectorInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModVectorInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModVectorInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModVectorInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModVectorInst",
           (PyObject*)(&PyoaObserver_oaModVectorInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModVectorInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModVectorInstBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModVectorInstBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModVectorInstBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModVectorInstBitObject* self = (PyoaObserver_oaModVectorInstBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModVectorInstBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaModVectorInstBit* p=new pyv_oaObserver_oaModVectorInstBit(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaModVectorInstBit(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModVectorInstBit* p=new pyv_oaObserver_oaModVectorInstBit(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModVectorInstBit)
    {
        PyParamoaObserver_oaModVectorInstBit p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModVectorInstBit_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModVectorInstBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaModVectorInstBit* p=new pyv_oaObserver_oaModVectorInstBit(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModVectorInstBit, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModVectorInstBit)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModVectorInstBit_tp_dealloc(PyoaObserver_oaModVectorInstBitObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModVectorInstBit*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModVectorInstBit_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModVectorInstBit value;
    int convert_status=PyoaObserver_oaModVectorInstBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaObserver_oaModVectorInstBit::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModVectorInstBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModVectorInstBit v1;
    PyParamoaObserver_oaModVectorInstBit v2;
    int convert_status1=PyoaObserver_oaModVectorInstBit_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModVectorInstBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModVectorInstBit_Convert(PyObject* ob,PyParamoaObserver_oaModVectorInstBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModVectorInstBit_Check(ob)) {
        result->SetData( (oaObserver_oaModVectorInstBit*) ((PyoaObserver_oaModVectorInstBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModVectorInstBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModVectorInstBit_FromoaObserver_oaModVectorInstBit(oaObserver_oaModVectorInstBit* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModVectorInstBit_Type.tp_alloc(&PyoaObserver_oaModVectorInstBit_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModVectorInstBitObject* self = (PyoaObserver_oaModVectorInstBitObject*)bself;
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
pyv_oaObserver_oaModVectorInstBit::pyv_oaObserver_oaModVectorInstBit(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModVectorInstBit(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModVectorInstBit::pyv_oaObserver_oaModVectorInstBit(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModVectorInstBit(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModVectorInstBit::pyv_oaObserver_oaModVectorInstBit(const oaObserver_oaModVectorInstBit& p)
 : pyob(NULL),
   oaObserver_oaModVectorInstBit(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModVectorInstBit::onPostCreate(oaModVectorInstBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInstBit::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModVectorInstBit_FromoaModVectorInstBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInstBit::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModVectorInstBit::onPostModify(oaModVectorInstBit* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInstBit::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModVectorInstBit_FromoaModVectorInstBit(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInstBit::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModVectorInstBit::onPreDestroy(oaModVectorInstBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInstBit::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModVectorInstBit_FromoaModVectorInstBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInstBit::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModVectorInstBit::onPreModify(oaModVectorInstBit* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInstBit::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModVectorInstBit_FromoaModVectorInstBit(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInstBit::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModVectorInstBit_doc[] = 
"Class: oaObserver_oaModVectorInstBit\n"
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
"    Calls: oaObserver_oaModVectorInstBit(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModVectorInstBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModVectorInstBit\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModVectorInstBit(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModVectorInstBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModVectorInstBit\n"
"  Paramegers: (oaObserver_oaModVectorInstBit)\n"
"    Calls: (const oaObserver_oaModVectorInstBit&)\n"
"    Signature: oaObserver_oaModVectorInstBit||cref-oaObserver_oaModVectorInstBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModVectorInstBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModVectorInstBit",
    sizeof(PyoaObserver_oaModVectorInstBitObject),
    0,
    (destructor)oaObserver_oaModVectorInstBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModVectorInstBit_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModVectorInstBit_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModVectorInstBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModVectorInstBit_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModVectorInstBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModVectorInstBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModVectorInstBit_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModVectorInstBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModVectorInstBit",
           (PyObject*)(&PyoaObserver_oaModVectorInstBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModVectorInstBit\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModVectorInstDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModVectorInstDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModVectorInstDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModVectorInstDefObject* self = (PyoaObserver_oaModVectorInstDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModVectorInstDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaModVectorInstDef* p=new pyv_oaObserver_oaModVectorInstDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaModVectorInstDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModVectorInstDef* p=new pyv_oaObserver_oaModVectorInstDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModVectorInstDef)
    {
        PyParamoaObserver_oaModVectorInstDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModVectorInstDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModVectorInstDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaModVectorInstDef* p=new pyv_oaObserver_oaModVectorInstDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModVectorInstDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModVectorInstDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModVectorInstDef_tp_dealloc(PyoaObserver_oaModVectorInstDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModVectorInstDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModVectorInstDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModVectorInstDef value;
    int convert_status=PyoaObserver_oaModVectorInstDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaObserver_oaModVectorInstDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModVectorInstDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModVectorInstDef v1;
    PyParamoaObserver_oaModVectorInstDef v2;
    int convert_status1=PyoaObserver_oaModVectorInstDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModVectorInstDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModVectorInstDef_Convert(PyObject* ob,PyParamoaObserver_oaModVectorInstDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModVectorInstDef_Check(ob)) {
        result->SetData( (oaObserver_oaModVectorInstDef*) ((PyoaObserver_oaModVectorInstDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModVectorInstDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModVectorInstDef_FromoaObserver_oaModVectorInstDef(oaObserver_oaModVectorInstDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModVectorInstDef_Type.tp_alloc(&PyoaObserver_oaModVectorInstDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModVectorInstDefObject* self = (PyoaObserver_oaModVectorInstDefObject*)bself;
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
pyv_oaObserver_oaModVectorInstDef::pyv_oaObserver_oaModVectorInstDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModVectorInstDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModVectorInstDef::pyv_oaObserver_oaModVectorInstDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModVectorInstDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModVectorInstDef::pyv_oaObserver_oaModVectorInstDef(const oaObserver_oaModVectorInstDef& p)
 : pyob(NULL),
   oaObserver_oaModVectorInstDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModVectorInstDef::onPostCreate(oaModVectorInstDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInstDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModVectorInstDef_FromoaModVectorInstDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInstDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModVectorInstDef::onPostModify(oaModVectorInstDef* p1,oaVectorInstDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInstDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModVectorInstDef_FromoaModVectorInstDef(p1));
    PyTuple_SetItem(args,1,PyoaVectorInstDefModTypeEnum_FromoaVectorInstDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInstDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModVectorInstDef::onPreDestroy(oaModVectorInstDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInstDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModVectorInstDef_FromoaModVectorInstDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInstDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModVectorInstDef::onPreModify(oaModVectorInstDef* p1,oaVectorInstDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInstDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModVectorInstDef_FromoaModVectorInstDef(p1));
    PyTuple_SetItem(args,1,PyoaVectorInstDefModTypeEnum_FromoaVectorInstDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModVectorInstDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModVectorInstDef_doc[] = 
"Class: oaObserver_oaModVectorInstDef\n"
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
"    Calls: oaObserver_oaModVectorInstDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModVectorInstDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModVectorInstDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModVectorInstDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModVectorInstDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModVectorInstDef\n"
"  Paramegers: (oaObserver_oaModVectorInstDef)\n"
"    Calls: (const oaObserver_oaModVectorInstDef&)\n"
"    Signature: oaObserver_oaModVectorInstDef||cref-oaObserver_oaModVectorInstDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModVectorInstDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModVectorInstDef",
    sizeof(PyoaObserver_oaModVectorInstDefObject),
    0,
    (destructor)oaObserver_oaModVectorInstDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModVectorInstDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModVectorInstDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModVectorInstDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModVectorInstDef_oaVectorInstDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModVectorInstDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModVectorInstDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModVectorInstDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModVectorInstDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModVectorInstDef",
           (PyObject*)(&PyoaObserver_oaModVectorInstDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModVectorInstDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaModule
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModule_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaModule_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaModuleObject* self = (PyoaObserver_oaModuleObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaModule(p1.Data());
            }
            else {
                pyv_oaObserver_oaModule* p=new pyv_oaObserver_oaModule(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaModule(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaModule* p=new pyv_oaObserver_oaModule(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaModule)
    {
        PyParamoaObserver_oaModule p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaModule_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaModule(p1.Data());
            }
            else {
                pyv_oaObserver_oaModule* p=new pyv_oaObserver_oaModule(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaModule, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaModule)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaModule_tp_dealloc(PyoaObserver_oaModuleObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaModule*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaModule_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaModule value;
    int convert_status=PyoaObserver_oaModule_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaObserver_oaModule::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaModule_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaModule v1;
    PyParamoaObserver_oaModule v2;
    int convert_status1=PyoaObserver_oaModule_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaModule_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaModule_Convert(PyObject* ob,PyParamoaObserver_oaModule* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaModule_Check(ob)) {
        result->SetData( (oaObserver_oaModule*) ((PyoaObserver_oaModuleObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaModule Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaModule_FromoaObserver_oaModule(oaObserver_oaModule* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaModule_Type.tp_alloc(&PyoaObserver_oaModule_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaModuleObject* self = (PyoaObserver_oaModuleObject*)bself;
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
pyv_oaObserver_oaModule::pyv_oaObserver_oaModule(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaModule(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModule::pyv_oaObserver_oaModule(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaModule(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaModule::pyv_oaObserver_oaModule(const oaObserver_oaModule& p)
 : pyob(NULL),
   oaObserver_oaModule(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModule::onPostCreate(oaModule* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModule::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModule_FromoaModule(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModule::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModule::onPostModify(oaModule* p1,oaModuleModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModule::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModule_FromoaModule(p1));
    PyTuple_SetItem(args,1,PyoaModuleModTypeEnum_FromoaModuleModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModule::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModule::onPreDestroy(oaModule* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModule::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaModule_FromoaModule(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModule::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaModule::onPreModify(oaModule* p1,oaModuleModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaModule::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaModule_FromoaModule(p1));
    PyTuple_SetItem(args,1,PyoaModuleModTypeEnum_FromoaModuleModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaModule::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaModule_doc[] = 
"Class: oaObserver_oaModule\n"
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
"    Calls: oaObserver_oaModule(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaModule||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModule\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaModule(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaModule||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaModule\n"
"  Paramegers: (oaObserver_oaModule)\n"
"    Calls: (const oaObserver_oaModule&)\n"
"    Signature: oaObserver_oaModule||cref-oaObserver_oaModule,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaModule_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaModule",
    sizeof(PyoaObserver_oaModuleObject),
    0,
    (destructor)oaObserver_oaModule_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaModule_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaModule_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaModule_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaModule_oaModuleModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaModule_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaModule_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaModule_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaModule\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaModule",
           (PyObject*)(&PyoaObserver_oaModule_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaModule\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaMutualInductor
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaMutualInductor_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaMutualInductor_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaMutualInductorObject* self = (PyoaObserver_oaMutualInductorObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaMutualInductor(p1.Data());
            }
            else {
                pyv_oaObserver_oaMutualInductor* p=new pyv_oaObserver_oaMutualInductor(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaMutualInductor(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaMutualInductor* p=new pyv_oaObserver_oaMutualInductor(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaMutualInductor)
    {
        PyParamoaObserver_oaMutualInductor p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaMutualInductor_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaMutualInductor(p1.Data());
            }
            else {
                pyv_oaObserver_oaMutualInductor* p=new pyv_oaObserver_oaMutualInductor(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaMutualInductor, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaMutualInductor)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaMutualInductor_tp_dealloc(PyoaObserver_oaMutualInductorObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaMutualInductor*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaMutualInductor_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaMutualInductor value;
    int convert_status=PyoaObserver_oaMutualInductor_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaObserver_oaMutualInductor::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaMutualInductor_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaMutualInductor v1;
    PyParamoaObserver_oaMutualInductor v2;
    int convert_status1=PyoaObserver_oaMutualInductor_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaMutualInductor_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaMutualInductor_Convert(PyObject* ob,PyParamoaObserver_oaMutualInductor* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaMutualInductor_Check(ob)) {
        result->SetData( (oaObserver_oaMutualInductor*) ((PyoaObserver_oaMutualInductorObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaMutualInductor Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaMutualInductor_FromoaObserver_oaMutualInductor(oaObserver_oaMutualInductor* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaMutualInductor_Type.tp_alloc(&PyoaObserver_oaMutualInductor_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaMutualInductorObject* self = (PyoaObserver_oaMutualInductorObject*)bself;
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
pyv_oaObserver_oaMutualInductor::pyv_oaObserver_oaMutualInductor(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaMutualInductor(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaMutualInductor::pyv_oaObserver_oaMutualInductor(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaMutualInductor(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaMutualInductor::pyv_oaObserver_oaMutualInductor(const oaObserver_oaMutualInductor& p)
 : pyob(NULL),
   oaObserver_oaMutualInductor(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaMutualInductor::onPostCreate(oaMutualInductor* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaMutualInductor::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaMutualInductor_FromoaMutualInductor(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaMutualInductor::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaMutualInductor::onPostModify(oaMutualInductor* p1,oaDeviceModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaMutualInductor::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaMutualInductor_FromoaMutualInductor(p1));
    PyTuple_SetItem(args,1,PyoaDeviceModTypeEnum_FromoaDeviceModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaMutualInductor::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaMutualInductor::onPreDestroy(oaMutualInductor* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaMutualInductor::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaMutualInductor_FromoaMutualInductor(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaMutualInductor::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaMutualInductor::onPreModify(oaMutualInductor* p1,oaDeviceModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaMutualInductor::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaMutualInductor_FromoaMutualInductor(p1));
    PyTuple_SetItem(args,1,PyoaDeviceModTypeEnum_FromoaDeviceModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaMutualInductor::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaMutualInductor_doc[] = 
"Class: oaObserver_oaMutualInductor\n"
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
"    Calls: oaObserver_oaMutualInductor(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaMutualInductor||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaMutualInductor\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaMutualInductor(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaMutualInductor||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaMutualInductor\n"
"  Paramegers: (oaObserver_oaMutualInductor)\n"
"    Calls: (const oaObserver_oaMutualInductor&)\n"
"    Signature: oaObserver_oaMutualInductor||cref-oaObserver_oaMutualInductor,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaMutualInductor_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaMutualInductor",
    sizeof(PyoaObserver_oaMutualInductorObject),
    0,
    (destructor)oaObserver_oaMutualInductor_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaMutualInductor_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaMutualInductor_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaMutualInductor_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaMutualInductor_oaDeviceModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaMutualInductor_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaMutualInductor_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaMutualInductor_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaMutualInductor\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaMutualInductor",
           (PyObject*)(&PyoaObserver_oaMutualInductor_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaMutualInductor\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaNetObject* self = (PyoaObserver_oaNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaNet* p=new pyv_oaObserver_oaNet(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaNet(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaNet* p=new pyv_oaObserver_oaNet(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaNet)
    {
        PyParamoaObserver_oaNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaNet_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaNet* p=new pyv_oaObserver_oaNet(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaNet, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaNet_tp_dealloc(PyoaObserver_oaNetObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaNet_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaNet value;
    int convert_status=PyoaObserver_oaNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaObserver_oaNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaNet v1;
    PyParamoaObserver_oaNet v2;
    int convert_status1=PyoaObserver_oaNet_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaNet_Convert(PyObject* ob,PyParamoaObserver_oaNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaNet_Check(ob)) {
        result->SetData( (oaObserver_oaNet*) ((PyoaObserver_oaNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaNet_FromoaObserver_oaNet(oaObserver_oaNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaNet_Type.tp_alloc(&PyoaObserver_oaNet_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaNetObject* self = (PyoaObserver_oaNetObject*)bself;
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
pyv_oaObserver_oaNet::pyv_oaObserver_oaNet(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaNet(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaNet::pyv_oaObserver_oaNet(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaNet(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaNet::pyv_oaObserver_oaNet(const oaObserver_oaNet& p)
 : pyob(NULL),
   oaObserver_oaNet(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaNet::onPostCreate(oaNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaNet::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaNet_FromoaNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaNet::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaNet::onPostModify(oaNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaNet::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaNet_FromoaNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaNet::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaNet::onPreDestroy(oaNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaNet::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaNet_FromoaNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaNet::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaNet::onPreModify(oaNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaNet::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaNet_FromoaNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaNet::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaNet_doc[] = 
"Class: oaObserver_oaNet\n"
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
"    Calls: oaObserver_oaNet(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaNet\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaNet(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaNet\n"
"  Paramegers: (oaObserver_oaNet)\n"
"    Calls: (const oaObserver_oaNet&)\n"
"    Signature: oaObserver_oaNet||cref-oaObserver_oaNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaNet",
    sizeof(PyoaObserver_oaNetObject),
    0,
    (destructor)oaObserver_oaNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaNet_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaNet_oaNetModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaNet_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaNet",
           (PyObject*)(&PyoaObserver_oaNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaNetConnectDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaNetConnectDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaNetConnectDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaNetConnectDefObject* self = (PyoaObserver_oaNetConnectDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaNetConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaNetConnectDef* p=new pyv_oaObserver_oaNetConnectDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaNetConnectDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaNetConnectDef* p=new pyv_oaObserver_oaNetConnectDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaNetConnectDef)
    {
        PyParamoaObserver_oaNetConnectDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaNetConnectDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaNetConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaNetConnectDef* p=new pyv_oaObserver_oaNetConnectDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaNetConnectDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaNetConnectDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaNetConnectDef_tp_dealloc(PyoaObserver_oaNetConnectDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaNetConnectDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaNetConnectDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaNetConnectDef value;
    int convert_status=PyoaObserver_oaNetConnectDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaNetConnectDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaNetConnectDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaNetConnectDef v1;
    PyParamoaObserver_oaNetConnectDef v2;
    int convert_status1=PyoaObserver_oaNetConnectDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaNetConnectDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaNetConnectDef_Convert(PyObject* ob,PyParamoaObserver_oaNetConnectDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaNetConnectDef_Check(ob)) {
        result->SetData( (oaObserver_oaNetConnectDef*) ((PyoaObserver_oaNetConnectDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaNetConnectDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaNetConnectDef_FromoaObserver_oaNetConnectDef(oaObserver_oaNetConnectDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaNetConnectDef_Type.tp_alloc(&PyoaObserver_oaNetConnectDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaNetConnectDefObject* self = (PyoaObserver_oaNetConnectDefObject*)bself;
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
pyv_oaObserver_oaNetConnectDef::pyv_oaObserver_oaNetConnectDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaNetConnectDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaNetConnectDef::pyv_oaObserver_oaNetConnectDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaNetConnectDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaNetConnectDef::pyv_oaObserver_oaNetConnectDef(const oaObserver_oaNetConnectDef& p)
 : pyob(NULL),
   oaObserver_oaNetConnectDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaNetConnectDef::onPostCreate(oaNetConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaNetConnectDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaNetConnectDef_FromoaNetConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaNetConnectDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaNetConnectDef::onPostModify(oaNetConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaNetConnectDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaNetConnectDef_FromoaNetConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaNetConnectDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaNetConnectDef::onPreDestroy(oaNetConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaNetConnectDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaNetConnectDef_FromoaNetConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaNetConnectDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaNetConnectDef::onPreModify(oaNetConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaNetConnectDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaNetConnectDef_FromoaNetConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaNetConnectDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaNetConnectDef_doc[] = 
"Class: oaObserver_oaNetConnectDef\n"
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
"    Calls: oaObserver_oaNetConnectDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaNetConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaNetConnectDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaNetConnectDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaNetConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaNetConnectDef\n"
"  Paramegers: (oaObserver_oaNetConnectDef)\n"
"    Calls: (const oaObserver_oaNetConnectDef&)\n"
"    Signature: oaObserver_oaNetConnectDef||cref-oaObserver_oaNetConnectDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaNetConnectDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaNetConnectDef",
    sizeof(PyoaObserver_oaNetConnectDefObject),
    0,
    (destructor)oaObserver_oaNetConnectDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaNetConnectDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaNetConnectDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaNetConnectDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaNetConnectDef_oaConnectDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaNetConnectDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaNetConnectDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaNetConnectDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaNetConnectDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaNetConnectDef",
           (PyObject*)(&PyoaObserver_oaNetConnectDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaNetConnectDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaNode
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaNode_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaNode_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaNodeObject* self = (PyoaObserver_oaNodeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaNode(p1.Data());
            }
            else {
                pyv_oaObserver_oaNode* p=new pyv_oaObserver_oaNode(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaNode(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaNode* p=new pyv_oaObserver_oaNode(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaNode)
    {
        PyParamoaObserver_oaNode p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaNode_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaNode(p1.Data());
            }
            else {
                pyv_oaObserver_oaNode* p=new pyv_oaObserver_oaNode(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaNode, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaNode)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaNode_tp_dealloc(PyoaObserver_oaNodeObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaNode*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaNode_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaNode value;
    int convert_status=PyoaObserver_oaNode_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaObserver_oaNode::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaNode_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaNode v1;
    PyParamoaObserver_oaNode v2;
    int convert_status1=PyoaObserver_oaNode_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaNode_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaNode_Convert(PyObject* ob,PyParamoaObserver_oaNode* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaNode_Check(ob)) {
        result->SetData( (oaObserver_oaNode*) ((PyoaObserver_oaNodeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaNode Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaNode_FromoaObserver_oaNode(oaObserver_oaNode* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaNode_Type.tp_alloc(&PyoaObserver_oaNode_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaNodeObject* self = (PyoaObserver_oaNodeObject*)bself;
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
pyv_oaObserver_oaNode::pyv_oaObserver_oaNode(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaNode(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaNode::pyv_oaObserver_oaNode(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaNode(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaNode::pyv_oaObserver_oaNode(const oaObserver_oaNode& p)
 : pyob(NULL),
   oaObserver_oaNode(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaNode::onPostCreate(oaNode* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaNode::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaNode_FromoaNode(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaNode::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaNode::onPostModify(oaNode* p1,oaNodeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaNode::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaNode_FromoaNode(p1));
    PyTuple_SetItem(args,1,PyoaNodeModTypeEnum_FromoaNodeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaNode::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaNode::onPreDestroy(oaNode* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaNode::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaNode_FromoaNode(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaNode::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaNode::onPreModify(oaNode* p1,oaNodeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaNode::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaNode_FromoaNode(p1));
    PyTuple_SetItem(args,1,PyoaNodeModTypeEnum_FromoaNodeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaNode::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaNode_doc[] = 
"Class: oaObserver_oaNode\n"
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
"    Calls: oaObserver_oaNode(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaNode||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaNode\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaNode(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaNode||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaNode\n"
"  Paramegers: (oaObserver_oaNode)\n"
"    Calls: (const oaObserver_oaNode&)\n"
"    Signature: oaObserver_oaNode||cref-oaObserver_oaNode,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaNode_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaNode",
    sizeof(PyoaObserver_oaNodeObject),
    0,
    (destructor)oaObserver_oaNode_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaNode_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaNode_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaNode_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaNode_oaNodeModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaNode_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaNode_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaNode_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaNode\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaNode",
           (PyObject*)(&PyoaObserver_oaNode_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaNode\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccArrayInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccArrayInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccArrayInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccArrayInstObject* self = (PyoaObserver_oaOccArrayInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccArrayInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccArrayInst* p=new pyv_oaObserver_oaOccArrayInst(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccArrayInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccArrayInst* p=new pyv_oaObserver_oaOccArrayInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccArrayInst)
    {
        PyParamoaObserver_oaOccArrayInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccArrayInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccArrayInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccArrayInst* p=new pyv_oaObserver_oaOccArrayInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccArrayInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccArrayInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccArrayInst_tp_dealloc(PyoaObserver_oaOccArrayInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccArrayInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccArrayInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccArrayInst value;
    int convert_status=PyoaObserver_oaOccArrayInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaOccArrayInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccArrayInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccArrayInst v1;
    PyParamoaObserver_oaOccArrayInst v2;
    int convert_status1=PyoaObserver_oaOccArrayInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccArrayInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccArrayInst_Convert(PyObject* ob,PyParamoaObserver_oaOccArrayInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccArrayInst_Check(ob)) {
        result->SetData( (oaObserver_oaOccArrayInst*) ((PyoaObserver_oaOccArrayInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccArrayInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccArrayInst_FromoaObserver_oaOccArrayInst(oaObserver_oaOccArrayInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccArrayInst_Type.tp_alloc(&PyoaObserver_oaOccArrayInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccArrayInstObject* self = (PyoaObserver_oaOccArrayInstObject*)bself;
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
pyv_oaObserver_oaOccArrayInst::pyv_oaObserver_oaOccArrayInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccArrayInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccArrayInst::pyv_oaObserver_oaOccArrayInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccArrayInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccArrayInst::pyv_oaObserver_oaOccArrayInst(const oaObserver_oaOccArrayInst& p)
 : pyob(NULL),
   oaObserver_oaOccArrayInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccArrayInst::onPostCreate(oaOccArrayInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccArrayInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccArrayInst_FromoaOccArrayInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccArrayInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccArrayInst::onPostModify(oaOccArrayInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccArrayInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccArrayInst_FromoaOccArrayInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccArrayInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccArrayInst::onPreDestroy(oaOccArrayInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccArrayInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccArrayInst_FromoaOccArrayInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccArrayInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccArrayInst::onPreModify(oaOccArrayInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccArrayInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccArrayInst_FromoaOccArrayInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccArrayInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccArrayInst_doc[] = 
"Class: oaObserver_oaOccArrayInst\n"
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
"    Calls: oaObserver_oaOccArrayInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccArrayInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccArrayInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccArrayInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccArrayInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccArrayInst\n"
"  Paramegers: (oaObserver_oaOccArrayInst)\n"
"    Calls: (const oaObserver_oaOccArrayInst&)\n"
"    Signature: oaObserver_oaOccArrayInst||cref-oaObserver_oaOccArrayInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccArrayInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccArrayInst",
    sizeof(PyoaObserver_oaOccArrayInstObject),
    0,
    (destructor)oaObserver_oaOccArrayInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccArrayInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccArrayInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccArrayInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccArrayInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccArrayInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccArrayInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccArrayInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccArrayInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccArrayInst",
           (PyObject*)(&PyoaObserver_oaOccArrayInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccArrayInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccAssignAssignment
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccAssignAssignment_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccAssignAssignment_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccAssignAssignmentObject* self = (PyoaObserver_oaOccAssignAssignmentObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccAssignAssignment(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccAssignAssignment* p=new pyv_oaObserver_oaOccAssignAssignment(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccAssignAssignment(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccAssignAssignment* p=new pyv_oaObserver_oaOccAssignAssignment(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccAssignAssignment)
    {
        PyParamoaObserver_oaOccAssignAssignment p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccAssignAssignment_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccAssignAssignment(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccAssignAssignment* p=new pyv_oaObserver_oaOccAssignAssignment(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccAssignAssignment, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccAssignAssignment)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccAssignAssignment_tp_dealloc(PyoaObserver_oaOccAssignAssignmentObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccAssignAssignment*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccAssignAssignment_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccAssignAssignment value;
    int convert_status=PyoaObserver_oaOccAssignAssignment_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaObserver_oaOccAssignAssignment::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccAssignAssignment_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccAssignAssignment v1;
    PyParamoaObserver_oaOccAssignAssignment v2;
    int convert_status1=PyoaObserver_oaOccAssignAssignment_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccAssignAssignment_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccAssignAssignment_Convert(PyObject* ob,PyParamoaObserver_oaOccAssignAssignment* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccAssignAssignment_Check(ob)) {
        result->SetData( (oaObserver_oaOccAssignAssignment*) ((PyoaObserver_oaOccAssignAssignmentObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccAssignAssignment Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccAssignAssignment_FromoaObserver_oaOccAssignAssignment(oaObserver_oaOccAssignAssignment* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccAssignAssignment_Type.tp_alloc(&PyoaObserver_oaOccAssignAssignment_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccAssignAssignmentObject* self = (PyoaObserver_oaOccAssignAssignmentObject*)bself;
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
pyv_oaObserver_oaOccAssignAssignment::pyv_oaObserver_oaOccAssignAssignment(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccAssignAssignment(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccAssignAssignment::pyv_oaObserver_oaOccAssignAssignment(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccAssignAssignment(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccAssignAssignment::pyv_oaObserver_oaOccAssignAssignment(const oaObserver_oaOccAssignAssignment& p)
 : pyob(NULL),
   oaObserver_oaOccAssignAssignment(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccAssignAssignment::onPostCreate(oaOccAssignAssignment* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignAssignment::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccAssignAssignment_FromoaOccAssignAssignment(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignAssignment::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccAssignAssignment::onPostModify(oaOccAssignAssignment* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignAssignment::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccAssignAssignment_FromoaOccAssignAssignment(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignAssignment::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccAssignAssignment::onPreDestroy(oaOccAssignAssignment* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignAssignment::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccAssignAssignment_FromoaOccAssignAssignment(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignAssignment::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccAssignAssignment::onPreModify(oaOccAssignAssignment* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignAssignment::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccAssignAssignment_FromoaOccAssignAssignment(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignAssignment::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccAssignAssignment_doc[] = 
"Class: oaObserver_oaOccAssignAssignment\n"
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
"    Calls: oaObserver_oaOccAssignAssignment(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccAssignAssignment||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccAssignAssignment\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccAssignAssignment(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccAssignAssignment||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccAssignAssignment\n"
"  Paramegers: (oaObserver_oaOccAssignAssignment)\n"
"    Calls: (const oaObserver_oaOccAssignAssignment&)\n"
"    Signature: oaObserver_oaOccAssignAssignment||cref-oaObserver_oaOccAssignAssignment,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccAssignAssignment_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccAssignAssignment",
    sizeof(PyoaObserver_oaOccAssignAssignmentObject),
    0,
    (destructor)oaObserver_oaOccAssignAssignment_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccAssignAssignment_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccAssignAssignment_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccAssignAssignment_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccAssignAssignment_oaAssignmentModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccAssignAssignment_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccAssignAssignment_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccAssignAssignment_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccAssignAssignment\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccAssignAssignment",
           (PyObject*)(&PyoaObserver_oaOccAssignAssignment_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccAssignAssignment\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccAssignValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccAssignValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccAssignValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccAssignValueObject* self = (PyoaObserver_oaOccAssignValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccAssignValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccAssignValue* p=new pyv_oaObserver_oaOccAssignValue(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccAssignValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccAssignValue* p=new pyv_oaObserver_oaOccAssignValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccAssignValue)
    {
        PyParamoaObserver_oaOccAssignValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccAssignValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccAssignValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccAssignValue* p=new pyv_oaObserver_oaOccAssignValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccAssignValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccAssignValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccAssignValue_tp_dealloc(PyoaObserver_oaOccAssignValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccAssignValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccAssignValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccAssignValue value;
    int convert_status=PyoaObserver_oaOccAssignValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaObserver_oaOccAssignValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccAssignValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccAssignValue v1;
    PyParamoaObserver_oaOccAssignValue v2;
    int convert_status1=PyoaObserver_oaOccAssignValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccAssignValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccAssignValue_Convert(PyObject* ob,PyParamoaObserver_oaOccAssignValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccAssignValue_Check(ob)) {
        result->SetData( (oaObserver_oaOccAssignValue*) ((PyoaObserver_oaOccAssignValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccAssignValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccAssignValue_FromoaObserver_oaOccAssignValue(oaObserver_oaOccAssignValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccAssignValue_Type.tp_alloc(&PyoaObserver_oaOccAssignValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccAssignValueObject* self = (PyoaObserver_oaOccAssignValueObject*)bself;
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
pyv_oaObserver_oaOccAssignValue::pyv_oaObserver_oaOccAssignValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccAssignValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccAssignValue::pyv_oaObserver_oaOccAssignValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccAssignValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccAssignValue::pyv_oaObserver_oaOccAssignValue(const oaObserver_oaOccAssignValue& p)
 : pyob(NULL),
   oaObserver_oaOccAssignValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccAssignValue::onPostCreate(oaOccAssignValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccAssignValue_FromoaOccAssignValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccAssignValue::onPostModify(oaOccAssignValue* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccAssignValue_FromoaOccAssignValue(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccAssignValue::onPreDestroy(oaOccAssignValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccAssignValue_FromoaOccAssignValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccAssignValue::onPreModify(oaOccAssignValue* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccAssignValue_FromoaOccAssignValue(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccAssignValue_doc[] = 
"Class: oaObserver_oaOccAssignValue\n"
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
"    Calls: oaObserver_oaOccAssignValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccAssignValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccAssignValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccAssignValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccAssignValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccAssignValue\n"
"  Paramegers: (oaObserver_oaOccAssignValue)\n"
"    Calls: (const oaObserver_oaOccAssignValue&)\n"
"    Signature: oaObserver_oaOccAssignValue||cref-oaObserver_oaOccAssignValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccAssignValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccAssignValue",
    sizeof(PyoaObserver_oaOccAssignValueObject),
    0,
    (destructor)oaObserver_oaOccAssignValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccAssignValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccAssignValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccAssignValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccAssignValue_oaAssignmentModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccAssignValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccAssignValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccAssignValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccAssignValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccAssignValue",
           (PyObject*)(&PyoaObserver_oaOccAssignValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccAssignValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccAssignment
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccAssignment_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccAssignment_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccAssignmentObject* self = (PyoaObserver_oaOccAssignmentObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccAssignment(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccAssignment* p=new pyv_oaObserver_oaOccAssignment(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccAssignment(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccAssignment* p=new pyv_oaObserver_oaOccAssignment(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccAssignment)
    {
        PyParamoaObserver_oaOccAssignment p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccAssignment_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccAssignment(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccAssignment* p=new pyv_oaObserver_oaOccAssignment(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccAssignment, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccAssignment)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccAssignment_tp_dealloc(PyoaObserver_oaOccAssignmentObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccAssignment*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccAssignment_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccAssignment value;
    int convert_status=PyoaObserver_oaOccAssignment_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaOccAssignment::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccAssignment_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccAssignment v1;
    PyParamoaObserver_oaOccAssignment v2;
    int convert_status1=PyoaObserver_oaOccAssignment_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccAssignment_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccAssignment_Convert(PyObject* ob,PyParamoaObserver_oaOccAssignment* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccAssignment_Check(ob)) {
        result->SetData( (oaObserver_oaOccAssignment*) ((PyoaObserver_oaOccAssignmentObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccAssignment Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccAssignment_FromoaObserver_oaOccAssignment(oaObserver_oaOccAssignment* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccAssignment_Type.tp_alloc(&PyoaObserver_oaOccAssignment_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccAssignmentObject* self = (PyoaObserver_oaOccAssignmentObject*)bself;
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
pyv_oaObserver_oaOccAssignment::pyv_oaObserver_oaOccAssignment(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccAssignment(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccAssignment::pyv_oaObserver_oaOccAssignment(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccAssignment(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccAssignment::pyv_oaObserver_oaOccAssignment(const oaObserver_oaOccAssignment& p)
 : pyob(NULL),
   oaObserver_oaOccAssignment(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccAssignment::onPostCreate(oaOccAssignment* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignment::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccAssignment_FromoaOccAssignment(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignment::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccAssignment::onPostModify(oaOccAssignment* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignment::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccAssignment_FromoaOccAssignment(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignment::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccAssignment::onPreDestroy(oaOccAssignment* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignment::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccAssignment_FromoaOccAssignment(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignment::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccAssignment::onPreModify(oaOccAssignment* p1,oaAssignmentModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignment::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccAssignment_FromoaOccAssignment(p1));
    PyTuple_SetItem(args,1,PyoaAssignmentModTypeEnum_FromoaAssignmentModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccAssignment::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccAssignment_doc[] = 
"Class: oaObserver_oaOccAssignment\n"
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
"    Calls: oaObserver_oaOccAssignment(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccAssignment||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccAssignment\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccAssignment(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccAssignment||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccAssignment\n"
"  Paramegers: (oaObserver_oaOccAssignment)\n"
"    Calls: (const oaObserver_oaOccAssignment&)\n"
"    Signature: oaObserver_oaOccAssignment||cref-oaObserver_oaOccAssignment,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccAssignment_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccAssignment",
    sizeof(PyoaObserver_oaOccAssignmentObject),
    0,
    (destructor)oaObserver_oaOccAssignment_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccAssignment_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccAssignment_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccAssignment_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccAssignment_oaAssignmentModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccAssignment_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccAssignment_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccAssignment_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccAssignment\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccAssignment",
           (PyObject*)(&PyoaObserver_oaOccAssignment_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccAssignment\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccBitInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBitInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccBitInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccBitInstObject* self = (PyoaObserver_oaOccBitInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBitInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBitInst* p=new pyv_oaObserver_oaOccBitInst(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBitInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccBitInst* p=new pyv_oaObserver_oaOccBitInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccBitInst)
    {
        PyParamoaObserver_oaOccBitInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccBitInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccBitInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBitInst* p=new pyv_oaObserver_oaOccBitInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccBitInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccBitInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccBitInst_tp_dealloc(PyoaObserver_oaOccBitInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccBitInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBitInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccBitInst value;
    int convert_status=PyoaObserver_oaOccBitInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaOccBitInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccBitInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccBitInst v1;
    PyParamoaObserver_oaOccBitInst v2;
    int convert_status1=PyoaObserver_oaOccBitInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccBitInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccBitInst_Convert(PyObject* ob,PyParamoaObserver_oaOccBitInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccBitInst_Check(ob)) {
        result->SetData( (oaObserver_oaOccBitInst*) ((PyoaObserver_oaOccBitInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccBitInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccBitInst_FromoaObserver_oaOccBitInst(oaObserver_oaOccBitInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccBitInst_Type.tp_alloc(&PyoaObserver_oaOccBitInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccBitInstObject* self = (PyoaObserver_oaOccBitInstObject*)bself;
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
pyv_oaObserver_oaOccBitInst::pyv_oaObserver_oaOccBitInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccBitInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBitInst::pyv_oaObserver_oaOccBitInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccBitInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBitInst::pyv_oaObserver_oaOccBitInst(const oaObserver_oaOccBitInst& p)
 : pyob(NULL),
   oaObserver_oaOccBitInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBitInst::onPostCreate(oaOccBitInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBitInst_FromoaOccBitInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBitInst::onPostModify(oaOccBitInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBitInst_FromoaOccBitInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBitInst::onPreDestroy(oaOccBitInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBitInst_FromoaOccBitInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBitInst::onPreModify(oaOccBitInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBitInst_FromoaOccBitInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccBitInst_doc[] = 
"Class: oaObserver_oaOccBitInst\n"
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
"    Calls: oaObserver_oaOccBitInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccBitInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBitInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccBitInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccBitInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBitInst\n"
"  Paramegers: (oaObserver_oaOccBitInst)\n"
"    Calls: (const oaObserver_oaOccBitInst&)\n"
"    Signature: oaObserver_oaOccBitInst||cref-oaObserver_oaOccBitInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccBitInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccBitInst",
    sizeof(PyoaObserver_oaOccBitInstObject),
    0,
    (destructor)oaObserver_oaOccBitInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccBitInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccBitInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccBitInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccBitInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccBitInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccBitInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccBitInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccBitInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccBitInst",
           (PyObject*)(&PyoaObserver_oaOccBitInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccBitInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccBitNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBitNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccBitNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccBitNetObject* self = (PyoaObserver_oaOccBitNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBitNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBitNet* p=new pyv_oaObserver_oaOccBitNet(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBitNet(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccBitNet* p=new pyv_oaObserver_oaOccBitNet(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccBitNet)
    {
        PyParamoaObserver_oaOccBitNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccBitNet_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccBitNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBitNet* p=new pyv_oaObserver_oaOccBitNet(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccBitNet, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccBitNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccBitNet_tp_dealloc(PyoaObserver_oaOccBitNetObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccBitNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBitNet_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccBitNet value;
    int convert_status=PyoaObserver_oaOccBitNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaObserver_oaOccBitNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccBitNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccBitNet v1;
    PyParamoaObserver_oaOccBitNet v2;
    int convert_status1=PyoaObserver_oaOccBitNet_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccBitNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccBitNet_Convert(PyObject* ob,PyParamoaObserver_oaOccBitNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccBitNet_Check(ob)) {
        result->SetData( (oaObserver_oaOccBitNet*) ((PyoaObserver_oaOccBitNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccBitNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccBitNet_FromoaObserver_oaOccBitNet(oaObserver_oaOccBitNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccBitNet_Type.tp_alloc(&PyoaObserver_oaOccBitNet_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccBitNetObject* self = (PyoaObserver_oaOccBitNetObject*)bself;
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
pyv_oaObserver_oaOccBitNet::pyv_oaObserver_oaOccBitNet(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccBitNet(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBitNet::pyv_oaObserver_oaOccBitNet(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccBitNet(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBitNet::pyv_oaObserver_oaOccBitNet(const oaObserver_oaOccBitNet& p)
 : pyob(NULL),
   oaObserver_oaOccBitNet(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBitNet::onPostCreate(oaOccBitNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitNet::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBitNet_FromoaOccBitNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitNet::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBitNet::onPostModify(oaOccBitNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitNet::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBitNet_FromoaOccBitNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitNet::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBitNet::onPreDestroy(oaOccBitNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitNet::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBitNet_FromoaOccBitNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitNet::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBitNet::onPreModify(oaOccBitNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitNet::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBitNet_FromoaOccBitNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitNet::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccBitNet_doc[] = 
"Class: oaObserver_oaOccBitNet\n"
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
"    Calls: oaObserver_oaOccBitNet(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccBitNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBitNet\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccBitNet(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccBitNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBitNet\n"
"  Paramegers: (oaObserver_oaOccBitNet)\n"
"    Calls: (const oaObserver_oaOccBitNet&)\n"
"    Signature: oaObserver_oaOccBitNet||cref-oaObserver_oaOccBitNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccBitNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccBitNet",
    sizeof(PyoaObserver_oaOccBitNetObject),
    0,
    (destructor)oaObserver_oaOccBitNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccBitNet_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccBitNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccBitNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccBitNet_oaNetModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccBitNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccBitNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccBitNet_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccBitNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccBitNet",
           (PyObject*)(&PyoaObserver_oaOccBitNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccBitNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccBitTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBitTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccBitTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccBitTermObject* self = (PyoaObserver_oaOccBitTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBitTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBitTerm* p=new pyv_oaObserver_oaOccBitTerm(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBitTerm(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccBitTerm* p=new pyv_oaObserver_oaOccBitTerm(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccBitTerm)
    {
        PyParamoaObserver_oaOccBitTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccBitTerm_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccBitTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBitTerm* p=new pyv_oaObserver_oaOccBitTerm(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccBitTerm, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccBitTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccBitTerm_tp_dealloc(PyoaObserver_oaOccBitTermObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccBitTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBitTerm_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccBitTerm value;
    int convert_status=PyoaObserver_oaOccBitTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaOccBitTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccBitTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccBitTerm v1;
    PyParamoaObserver_oaOccBitTerm v2;
    int convert_status1=PyoaObserver_oaOccBitTerm_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccBitTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccBitTerm_Convert(PyObject* ob,PyParamoaObserver_oaOccBitTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccBitTerm_Check(ob)) {
        result->SetData( (oaObserver_oaOccBitTerm*) ((PyoaObserver_oaOccBitTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccBitTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccBitTerm_FromoaObserver_oaOccBitTerm(oaObserver_oaOccBitTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccBitTerm_Type.tp_alloc(&PyoaObserver_oaOccBitTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccBitTermObject* self = (PyoaObserver_oaOccBitTermObject*)bself;
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
pyv_oaObserver_oaOccBitTerm::pyv_oaObserver_oaOccBitTerm(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccBitTerm(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBitTerm::pyv_oaObserver_oaOccBitTerm(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccBitTerm(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBitTerm::pyv_oaObserver_oaOccBitTerm(const oaObserver_oaOccBitTerm& p)
 : pyob(NULL),
   oaObserver_oaOccBitTerm(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBitTerm::onPostCreate(oaOccBitTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitTerm::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBitTerm_FromoaOccBitTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitTerm::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBitTerm::onPostModify(oaOccBitTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitTerm::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBitTerm_FromoaOccBitTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitTerm::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBitTerm::onPreDestroy(oaOccBitTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitTerm::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBitTerm_FromoaOccBitTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitTerm::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBitTerm::onPreModify(oaOccBitTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitTerm::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBitTerm_FromoaOccBitTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBitTerm::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccBitTerm_doc[] = 
"Class: oaObserver_oaOccBitTerm\n"
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
"    Calls: oaObserver_oaOccBitTerm(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccBitTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBitTerm\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccBitTerm(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccBitTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBitTerm\n"
"  Paramegers: (oaObserver_oaOccBitTerm)\n"
"    Calls: (const oaObserver_oaOccBitTerm&)\n"
"    Signature: oaObserver_oaOccBitTerm||cref-oaObserver_oaOccBitTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccBitTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccBitTerm",
    sizeof(PyoaObserver_oaOccBitTermObject),
    0,
    (destructor)oaObserver_oaOccBitTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccBitTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccBitTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccBitTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccBitTerm_oaTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccBitTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccBitTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccBitTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccBitTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccBitTerm",
           (PyObject*)(&PyoaObserver_oaOccBitTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccBitTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccBundleNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBundleNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccBundleNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccBundleNetObject* self = (PyoaObserver_oaOccBundleNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBundleNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBundleNet* p=new pyv_oaObserver_oaOccBundleNet(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBundleNet(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccBundleNet* p=new pyv_oaObserver_oaOccBundleNet(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccBundleNet)
    {
        PyParamoaObserver_oaOccBundleNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccBundleNet_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccBundleNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBundleNet* p=new pyv_oaObserver_oaOccBundleNet(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccBundleNet, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccBundleNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccBundleNet_tp_dealloc(PyoaObserver_oaOccBundleNetObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccBundleNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBundleNet_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccBundleNet value;
    int convert_status=PyoaObserver_oaOccBundleNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaOccBundleNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccBundleNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccBundleNet v1;
    PyParamoaObserver_oaOccBundleNet v2;
    int convert_status1=PyoaObserver_oaOccBundleNet_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccBundleNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccBundleNet_Convert(PyObject* ob,PyParamoaObserver_oaOccBundleNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccBundleNet_Check(ob)) {
        result->SetData( (oaObserver_oaOccBundleNet*) ((PyoaObserver_oaOccBundleNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccBundleNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccBundleNet_FromoaObserver_oaOccBundleNet(oaObserver_oaOccBundleNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccBundleNet_Type.tp_alloc(&PyoaObserver_oaOccBundleNet_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccBundleNetObject* self = (PyoaObserver_oaOccBundleNetObject*)bself;
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
pyv_oaObserver_oaOccBundleNet::pyv_oaObserver_oaOccBundleNet(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccBundleNet(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBundleNet::pyv_oaObserver_oaOccBundleNet(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccBundleNet(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBundleNet::pyv_oaObserver_oaOccBundleNet(const oaObserver_oaOccBundleNet& p)
 : pyob(NULL),
   oaObserver_oaOccBundleNet(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBundleNet::onPostCreate(oaOccBundleNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBundleNet::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBundleNet_FromoaOccBundleNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBundleNet::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBundleNet::onPostModify(oaOccBundleNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBundleNet::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBundleNet_FromoaOccBundleNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBundleNet::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBundleNet::onPreDestroy(oaOccBundleNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBundleNet::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBundleNet_FromoaOccBundleNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBundleNet::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBundleNet::onPreModify(oaOccBundleNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBundleNet::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBundleNet_FromoaOccBundleNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBundleNet::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccBundleNet_doc[] = 
"Class: oaObserver_oaOccBundleNet\n"
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
"    Calls: oaObserver_oaOccBundleNet(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccBundleNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBundleNet\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccBundleNet(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccBundleNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBundleNet\n"
"  Paramegers: (oaObserver_oaOccBundleNet)\n"
"    Calls: (const oaObserver_oaOccBundleNet&)\n"
"    Signature: oaObserver_oaOccBundleNet||cref-oaObserver_oaOccBundleNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccBundleNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccBundleNet",
    sizeof(PyoaObserver_oaOccBundleNetObject),
    0,
    (destructor)oaObserver_oaOccBundleNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccBundleNet_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccBundleNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccBundleNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccBundleNet_oaNetModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccBundleNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccBundleNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccBundleNet_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccBundleNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccBundleNet",
           (PyObject*)(&PyoaObserver_oaOccBundleNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccBundleNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccBundleTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBundleTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccBundleTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccBundleTermObject* self = (PyoaObserver_oaOccBundleTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBundleTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBundleTerm* p=new pyv_oaObserver_oaOccBundleTerm(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBundleTerm(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccBundleTerm* p=new pyv_oaObserver_oaOccBundleTerm(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccBundleTerm)
    {
        PyParamoaObserver_oaOccBundleTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccBundleTerm_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccBundleTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBundleTerm* p=new pyv_oaObserver_oaOccBundleTerm(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccBundleTerm, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccBundleTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccBundleTerm_tp_dealloc(PyoaObserver_oaOccBundleTermObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccBundleTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBundleTerm_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccBundleTerm value;
    int convert_status=PyoaObserver_oaOccBundleTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaOccBundleTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccBundleTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccBundleTerm v1;
    PyParamoaObserver_oaOccBundleTerm v2;
    int convert_status1=PyoaObserver_oaOccBundleTerm_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccBundleTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccBundleTerm_Convert(PyObject* ob,PyParamoaObserver_oaOccBundleTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccBundleTerm_Check(ob)) {
        result->SetData( (oaObserver_oaOccBundleTerm*) ((PyoaObserver_oaOccBundleTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccBundleTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccBundleTerm_FromoaObserver_oaOccBundleTerm(oaObserver_oaOccBundleTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccBundleTerm_Type.tp_alloc(&PyoaObserver_oaOccBundleTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccBundleTermObject* self = (PyoaObserver_oaOccBundleTermObject*)bself;
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
pyv_oaObserver_oaOccBundleTerm::pyv_oaObserver_oaOccBundleTerm(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccBundleTerm(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBundleTerm::pyv_oaObserver_oaOccBundleTerm(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccBundleTerm(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBundleTerm::pyv_oaObserver_oaOccBundleTerm(const oaObserver_oaOccBundleTerm& p)
 : pyob(NULL),
   oaObserver_oaOccBundleTerm(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBundleTerm::onPostCreate(oaOccBundleTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBundleTerm::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBundleTerm_FromoaOccBundleTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBundleTerm::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBundleTerm::onPostModify(oaOccBundleTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBundleTerm::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBundleTerm_FromoaOccBundleTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBundleTerm::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBundleTerm::onPreDestroy(oaOccBundleTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBundleTerm::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBundleTerm_FromoaOccBundleTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBundleTerm::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBundleTerm::onPreModify(oaOccBundleTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBundleTerm::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBundleTerm_FromoaOccBundleTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBundleTerm::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccBundleTerm_doc[] = 
"Class: oaObserver_oaOccBundleTerm\n"
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
"    Calls: oaObserver_oaOccBundleTerm(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccBundleTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBundleTerm\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccBundleTerm(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccBundleTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBundleTerm\n"
"  Paramegers: (oaObserver_oaOccBundleTerm)\n"
"    Calls: (const oaObserver_oaOccBundleTerm&)\n"
"    Signature: oaObserver_oaOccBundleTerm||cref-oaObserver_oaOccBundleTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccBundleTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccBundleTerm",
    sizeof(PyoaObserver_oaOccBundleTermObject),
    0,
    (destructor)oaObserver_oaOccBundleTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccBundleTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccBundleTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccBundleTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccBundleTerm_oaTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccBundleTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccBundleTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccBundleTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccBundleTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccBundleTerm",
           (PyObject*)(&PyoaObserver_oaOccBundleTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccBundleTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccBusNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBusNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccBusNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccBusNetObject* self = (PyoaObserver_oaOccBusNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBusNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBusNet* p=new pyv_oaObserver_oaOccBusNet(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBusNet(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccBusNet* p=new pyv_oaObserver_oaOccBusNet(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccBusNet)
    {
        PyParamoaObserver_oaOccBusNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccBusNet_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccBusNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBusNet* p=new pyv_oaObserver_oaOccBusNet(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccBusNet, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccBusNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccBusNet_tp_dealloc(PyoaObserver_oaOccBusNetObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccBusNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBusNet_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccBusNet value;
    int convert_status=PyoaObserver_oaOccBusNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaObserver_oaOccBusNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccBusNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccBusNet v1;
    PyParamoaObserver_oaOccBusNet v2;
    int convert_status1=PyoaObserver_oaOccBusNet_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccBusNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccBusNet_Convert(PyObject* ob,PyParamoaObserver_oaOccBusNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccBusNet_Check(ob)) {
        result->SetData( (oaObserver_oaOccBusNet*) ((PyoaObserver_oaOccBusNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccBusNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccBusNet_FromoaObserver_oaOccBusNet(oaObserver_oaOccBusNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccBusNet_Type.tp_alloc(&PyoaObserver_oaOccBusNet_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccBusNetObject* self = (PyoaObserver_oaOccBusNetObject*)bself;
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
pyv_oaObserver_oaOccBusNet::pyv_oaObserver_oaOccBusNet(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccBusNet(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBusNet::pyv_oaObserver_oaOccBusNet(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccBusNet(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBusNet::pyv_oaObserver_oaOccBusNet(const oaObserver_oaOccBusNet& p)
 : pyob(NULL),
   oaObserver_oaOccBusNet(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusNet::onPostCreate(oaOccBusNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNet::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBusNet_FromoaOccBusNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNet::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusNet::onPostModify(oaOccBusNet* p1,oaBusNetDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNet::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBusNet_FromoaOccBusNet(p1));
    PyTuple_SetItem(args,1,PyoaBusNetDefModTypeEnum_FromoaBusNetDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNet::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusNet::onPreDestroy(oaOccBusNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNet::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBusNet_FromoaOccBusNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNet::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusNet::onPreModify(oaOccBusNet* p1,oaBusNetDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNet::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBusNet_FromoaOccBusNet(p1));
    PyTuple_SetItem(args,1,PyoaBusNetDefModTypeEnum_FromoaBusNetDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNet::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccBusNet_doc[] = 
"Class: oaObserver_oaOccBusNet\n"
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
"    Calls: oaObserver_oaOccBusNet(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccBusNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBusNet\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccBusNet(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccBusNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBusNet\n"
"  Paramegers: (oaObserver_oaOccBusNet)\n"
"    Calls: (const oaObserver_oaOccBusNet&)\n"
"    Signature: oaObserver_oaOccBusNet||cref-oaObserver_oaOccBusNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccBusNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccBusNet",
    sizeof(PyoaObserver_oaOccBusNetObject),
    0,
    (destructor)oaObserver_oaOccBusNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccBusNet_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccBusNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccBusNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccBusNet_oaBusNetDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccBusNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccBusNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccBusNet_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccBusNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccBusNet",
           (PyObject*)(&PyoaObserver_oaOccBusNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccBusNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccBusNetBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBusNetBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccBusNetBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccBusNetBitObject* self = (PyoaObserver_oaOccBusNetBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBusNetBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBusNetBit* p=new pyv_oaObserver_oaOccBusNetBit(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBusNetBit(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccBusNetBit* p=new pyv_oaObserver_oaOccBusNetBit(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccBusNetBit)
    {
        PyParamoaObserver_oaOccBusNetBit p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccBusNetBit_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccBusNetBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBusNetBit* p=new pyv_oaObserver_oaOccBusNetBit(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccBusNetBit, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccBusNetBit)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccBusNetBit_tp_dealloc(PyoaObserver_oaOccBusNetBitObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccBusNetBit*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBusNetBit_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccBusNetBit value;
    int convert_status=PyoaObserver_oaOccBusNetBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaOccBusNetBit::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccBusNetBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccBusNetBit v1;
    PyParamoaObserver_oaOccBusNetBit v2;
    int convert_status1=PyoaObserver_oaOccBusNetBit_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccBusNetBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccBusNetBit_Convert(PyObject* ob,PyParamoaObserver_oaOccBusNetBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccBusNetBit_Check(ob)) {
        result->SetData( (oaObserver_oaOccBusNetBit*) ((PyoaObserver_oaOccBusNetBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccBusNetBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccBusNetBit_FromoaObserver_oaOccBusNetBit(oaObserver_oaOccBusNetBit* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccBusNetBit_Type.tp_alloc(&PyoaObserver_oaOccBusNetBit_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccBusNetBitObject* self = (PyoaObserver_oaOccBusNetBitObject*)bself;
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
pyv_oaObserver_oaOccBusNetBit::pyv_oaObserver_oaOccBusNetBit(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccBusNetBit(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBusNetBit::pyv_oaObserver_oaOccBusNetBit(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccBusNetBit(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBusNetBit::pyv_oaObserver_oaOccBusNetBit(const oaObserver_oaOccBusNetBit& p)
 : pyob(NULL),
   oaObserver_oaOccBusNetBit(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusNetBit::onPostCreate(oaOccBusNetBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNetBit::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBusNetBit_FromoaOccBusNetBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNetBit::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusNetBit::onPostModify(oaOccBusNetBit* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNetBit::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBusNetBit_FromoaOccBusNetBit(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNetBit::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusNetBit::onPreDestroy(oaOccBusNetBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNetBit::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBusNetBit_FromoaOccBusNetBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNetBit::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusNetBit::onPreModify(oaOccBusNetBit* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNetBit::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBusNetBit_FromoaOccBusNetBit(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNetBit::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccBusNetBit_doc[] = 
"Class: oaObserver_oaOccBusNetBit\n"
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
"    Calls: oaObserver_oaOccBusNetBit(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccBusNetBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBusNetBit\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccBusNetBit(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccBusNetBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBusNetBit\n"
"  Paramegers: (oaObserver_oaOccBusNetBit)\n"
"    Calls: (const oaObserver_oaOccBusNetBit&)\n"
"    Signature: oaObserver_oaOccBusNetBit||cref-oaObserver_oaOccBusNetBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccBusNetBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccBusNetBit",
    sizeof(PyoaObserver_oaOccBusNetBitObject),
    0,
    (destructor)oaObserver_oaOccBusNetBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccBusNetBit_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccBusNetBit_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccBusNetBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccBusNetBit_oaNetModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccBusNetBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccBusNetBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccBusNetBit_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccBusNetBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccBusNetBit",
           (PyObject*)(&PyoaObserver_oaOccBusNetBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccBusNetBit\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccBusNetDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBusNetDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccBusNetDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccBusNetDefObject* self = (PyoaObserver_oaOccBusNetDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBusNetDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBusNetDef* p=new pyv_oaObserver_oaOccBusNetDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBusNetDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccBusNetDef* p=new pyv_oaObserver_oaOccBusNetDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccBusNetDef)
    {
        PyParamoaObserver_oaOccBusNetDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccBusNetDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccBusNetDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBusNetDef* p=new pyv_oaObserver_oaOccBusNetDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccBusNetDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccBusNetDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccBusNetDef_tp_dealloc(PyoaObserver_oaOccBusNetDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccBusNetDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBusNetDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccBusNetDef value;
    int convert_status=PyoaObserver_oaOccBusNetDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaOccBusNetDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccBusNetDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccBusNetDef v1;
    PyParamoaObserver_oaOccBusNetDef v2;
    int convert_status1=PyoaObserver_oaOccBusNetDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccBusNetDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccBusNetDef_Convert(PyObject* ob,PyParamoaObserver_oaOccBusNetDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccBusNetDef_Check(ob)) {
        result->SetData( (oaObserver_oaOccBusNetDef*) ((PyoaObserver_oaOccBusNetDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccBusNetDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccBusNetDef_FromoaObserver_oaOccBusNetDef(oaObserver_oaOccBusNetDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccBusNetDef_Type.tp_alloc(&PyoaObserver_oaOccBusNetDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccBusNetDefObject* self = (PyoaObserver_oaOccBusNetDefObject*)bself;
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
pyv_oaObserver_oaOccBusNetDef::pyv_oaObserver_oaOccBusNetDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccBusNetDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBusNetDef::pyv_oaObserver_oaOccBusNetDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccBusNetDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBusNetDef::pyv_oaObserver_oaOccBusNetDef(const oaObserver_oaOccBusNetDef& p)
 : pyob(NULL),
   oaObserver_oaOccBusNetDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusNetDef::onPostCreate(oaOccBusNetDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNetDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBusNetDef_FromoaOccBusNetDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNetDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusNetDef::onPostModify(oaOccBusNetDef* p1,oaBusNetDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNetDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBusNetDef_FromoaOccBusNetDef(p1));
    PyTuple_SetItem(args,1,PyoaBusNetDefModTypeEnum_FromoaBusNetDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNetDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusNetDef::onPreDestroy(oaOccBusNetDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNetDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBusNetDef_FromoaOccBusNetDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNetDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusNetDef::onPreModify(oaOccBusNetDef* p1,oaBusNetDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNetDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBusNetDef_FromoaOccBusNetDef(p1));
    PyTuple_SetItem(args,1,PyoaBusNetDefModTypeEnum_FromoaBusNetDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusNetDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccBusNetDef_doc[] = 
"Class: oaObserver_oaOccBusNetDef\n"
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
"    Calls: oaObserver_oaOccBusNetDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccBusNetDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBusNetDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccBusNetDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccBusNetDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBusNetDef\n"
"  Paramegers: (oaObserver_oaOccBusNetDef)\n"
"    Calls: (const oaObserver_oaOccBusNetDef&)\n"
"    Signature: oaObserver_oaOccBusNetDef||cref-oaObserver_oaOccBusNetDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccBusNetDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccBusNetDef",
    sizeof(PyoaObserver_oaOccBusNetDefObject),
    0,
    (destructor)oaObserver_oaOccBusNetDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccBusNetDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccBusNetDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccBusNetDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccBusNetDef_oaBusNetDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccBusNetDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccBusNetDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccBusNetDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccBusNetDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccBusNetDef",
           (PyObject*)(&PyoaObserver_oaOccBusNetDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccBusNetDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccBusTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBusTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccBusTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccBusTermObject* self = (PyoaObserver_oaOccBusTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBusTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBusTerm* p=new pyv_oaObserver_oaOccBusTerm(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBusTerm(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccBusTerm* p=new pyv_oaObserver_oaOccBusTerm(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccBusTerm)
    {
        PyParamoaObserver_oaOccBusTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccBusTerm_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccBusTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBusTerm* p=new pyv_oaObserver_oaOccBusTerm(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccBusTerm, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccBusTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccBusTerm_tp_dealloc(PyoaObserver_oaOccBusTermObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccBusTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBusTerm_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccBusTerm value;
    int convert_status=PyoaObserver_oaOccBusTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaOccBusTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccBusTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccBusTerm v1;
    PyParamoaObserver_oaOccBusTerm v2;
    int convert_status1=PyoaObserver_oaOccBusTerm_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccBusTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccBusTerm_Convert(PyObject* ob,PyParamoaObserver_oaOccBusTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccBusTerm_Check(ob)) {
        result->SetData( (oaObserver_oaOccBusTerm*) ((PyoaObserver_oaOccBusTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccBusTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccBusTerm_FromoaObserver_oaOccBusTerm(oaObserver_oaOccBusTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccBusTerm_Type.tp_alloc(&PyoaObserver_oaOccBusTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccBusTermObject* self = (PyoaObserver_oaOccBusTermObject*)bself;
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
pyv_oaObserver_oaOccBusTerm::pyv_oaObserver_oaOccBusTerm(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccBusTerm(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBusTerm::pyv_oaObserver_oaOccBusTerm(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccBusTerm(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBusTerm::pyv_oaObserver_oaOccBusTerm(const oaObserver_oaOccBusTerm& p)
 : pyob(NULL),
   oaObserver_oaOccBusTerm(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusTerm::onPostCreate(oaOccBusTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTerm::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBusTerm_FromoaOccBusTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTerm::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusTerm::onPostModify(oaOccBusTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTerm::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBusTerm_FromoaOccBusTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTerm::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusTerm::onPreDestroy(oaOccBusTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTerm::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBusTerm_FromoaOccBusTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTerm::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusTerm::onPreModify(oaOccBusTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTerm::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBusTerm_FromoaOccBusTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTerm::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccBusTerm_doc[] = 
"Class: oaObserver_oaOccBusTerm\n"
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
"    Calls: oaObserver_oaOccBusTerm(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccBusTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBusTerm\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccBusTerm(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccBusTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBusTerm\n"
"  Paramegers: (oaObserver_oaOccBusTerm)\n"
"    Calls: (const oaObserver_oaOccBusTerm&)\n"
"    Signature: oaObserver_oaOccBusTerm||cref-oaObserver_oaOccBusTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccBusTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccBusTerm",
    sizeof(PyoaObserver_oaOccBusTermObject),
    0,
    (destructor)oaObserver_oaOccBusTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccBusTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccBusTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccBusTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccBusTerm_oaTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccBusTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccBusTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccBusTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccBusTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccBusTerm",
           (PyObject*)(&PyoaObserver_oaOccBusTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccBusTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccBusTermBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBusTermBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccBusTermBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccBusTermBitObject* self = (PyoaObserver_oaOccBusTermBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBusTermBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBusTermBit* p=new pyv_oaObserver_oaOccBusTermBit(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBusTermBit(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccBusTermBit* p=new pyv_oaObserver_oaOccBusTermBit(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccBusTermBit)
    {
        PyParamoaObserver_oaOccBusTermBit p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccBusTermBit_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccBusTermBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBusTermBit* p=new pyv_oaObserver_oaOccBusTermBit(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccBusTermBit, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccBusTermBit)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccBusTermBit_tp_dealloc(PyoaObserver_oaOccBusTermBitObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccBusTermBit*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBusTermBit_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccBusTermBit value;
    int convert_status=PyoaObserver_oaOccBusTermBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaOccBusTermBit::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccBusTermBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccBusTermBit v1;
    PyParamoaObserver_oaOccBusTermBit v2;
    int convert_status1=PyoaObserver_oaOccBusTermBit_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccBusTermBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccBusTermBit_Convert(PyObject* ob,PyParamoaObserver_oaOccBusTermBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccBusTermBit_Check(ob)) {
        result->SetData( (oaObserver_oaOccBusTermBit*) ((PyoaObserver_oaOccBusTermBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccBusTermBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccBusTermBit_FromoaObserver_oaOccBusTermBit(oaObserver_oaOccBusTermBit* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccBusTermBit_Type.tp_alloc(&PyoaObserver_oaOccBusTermBit_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccBusTermBitObject* self = (PyoaObserver_oaOccBusTermBitObject*)bself;
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
pyv_oaObserver_oaOccBusTermBit::pyv_oaObserver_oaOccBusTermBit(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccBusTermBit(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBusTermBit::pyv_oaObserver_oaOccBusTermBit(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccBusTermBit(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBusTermBit::pyv_oaObserver_oaOccBusTermBit(const oaObserver_oaOccBusTermBit& p)
 : pyob(NULL),
   oaObserver_oaOccBusTermBit(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusTermBit::onPostCreate(oaOccBusTermBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTermBit::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBusTermBit_FromoaOccBusTermBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTermBit::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusTermBit::onPostModify(oaOccBusTermBit* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTermBit::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBusTermBit_FromoaOccBusTermBit(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTermBit::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusTermBit::onPreDestroy(oaOccBusTermBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTermBit::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBusTermBit_FromoaOccBusTermBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTermBit::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusTermBit::onPreModify(oaOccBusTermBit* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTermBit::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBusTermBit_FromoaOccBusTermBit(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTermBit::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccBusTermBit_doc[] = 
"Class: oaObserver_oaOccBusTermBit\n"
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
"    Calls: oaObserver_oaOccBusTermBit(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccBusTermBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBusTermBit\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccBusTermBit(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccBusTermBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBusTermBit\n"
"  Paramegers: (oaObserver_oaOccBusTermBit)\n"
"    Calls: (const oaObserver_oaOccBusTermBit&)\n"
"    Signature: oaObserver_oaOccBusTermBit||cref-oaObserver_oaOccBusTermBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccBusTermBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccBusTermBit",
    sizeof(PyoaObserver_oaOccBusTermBitObject),
    0,
    (destructor)oaObserver_oaOccBusTermBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccBusTermBit_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccBusTermBit_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccBusTermBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccBusTermBit_oaTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccBusTermBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccBusTermBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccBusTermBit_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccBusTermBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccBusTermBit",
           (PyObject*)(&PyoaObserver_oaOccBusTermBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccBusTermBit\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccBusTermDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBusTermDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccBusTermDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccBusTermDefObject* self = (PyoaObserver_oaOccBusTermDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBusTermDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBusTermDef* p=new pyv_oaObserver_oaOccBusTermDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccBusTermDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccBusTermDef* p=new pyv_oaObserver_oaOccBusTermDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccBusTermDef)
    {
        PyParamoaObserver_oaOccBusTermDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccBusTermDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccBusTermDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccBusTermDef* p=new pyv_oaObserver_oaOccBusTermDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccBusTermDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccBusTermDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccBusTermDef_tp_dealloc(PyoaObserver_oaOccBusTermDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccBusTermDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccBusTermDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccBusTermDef value;
    int convert_status=PyoaObserver_oaOccBusTermDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaOccBusTermDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccBusTermDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccBusTermDef v1;
    PyParamoaObserver_oaOccBusTermDef v2;
    int convert_status1=PyoaObserver_oaOccBusTermDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccBusTermDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccBusTermDef_Convert(PyObject* ob,PyParamoaObserver_oaOccBusTermDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccBusTermDef_Check(ob)) {
        result->SetData( (oaObserver_oaOccBusTermDef*) ((PyoaObserver_oaOccBusTermDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccBusTermDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccBusTermDef_FromoaObserver_oaOccBusTermDef(oaObserver_oaOccBusTermDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccBusTermDef_Type.tp_alloc(&PyoaObserver_oaOccBusTermDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccBusTermDefObject* self = (PyoaObserver_oaOccBusTermDefObject*)bself;
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
pyv_oaObserver_oaOccBusTermDef::pyv_oaObserver_oaOccBusTermDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccBusTermDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBusTermDef::pyv_oaObserver_oaOccBusTermDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccBusTermDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccBusTermDef::pyv_oaObserver_oaOccBusTermDef(const oaObserver_oaOccBusTermDef& p)
 : pyob(NULL),
   oaObserver_oaOccBusTermDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusTermDef::onPostCreate(oaOccBusTermDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTermDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBusTermDef_FromoaOccBusTermDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTermDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusTermDef::onPostModify(oaOccBusTermDef* p1,oaBusTermDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTermDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBusTermDef_FromoaOccBusTermDef(p1));
    PyTuple_SetItem(args,1,PyoaBusTermDefModTypeEnum_FromoaBusTermDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTermDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusTermDef::onPreDestroy(oaOccBusTermDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTermDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccBusTermDef_FromoaOccBusTermDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTermDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccBusTermDef::onPreModify(oaOccBusTermDef* p1,oaBusTermDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTermDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccBusTermDef_FromoaOccBusTermDef(p1));
    PyTuple_SetItem(args,1,PyoaBusTermDefModTypeEnum_FromoaBusTermDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccBusTermDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccBusTermDef_doc[] = 
"Class: oaObserver_oaOccBusTermDef\n"
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
"    Calls: oaObserver_oaOccBusTermDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccBusTermDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBusTermDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccBusTermDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccBusTermDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccBusTermDef\n"
"  Paramegers: (oaObserver_oaOccBusTermDef)\n"
"    Calls: (const oaObserver_oaOccBusTermDef&)\n"
"    Signature: oaObserver_oaOccBusTermDef||cref-oaObserver_oaOccBusTermDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccBusTermDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccBusTermDef",
    sizeof(PyoaObserver_oaOccBusTermDefObject),
    0,
    (destructor)oaObserver_oaOccBusTermDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccBusTermDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccBusTermDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccBusTermDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccBusTermDef_oaBusTermDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccBusTermDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccBusTermDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccBusTermDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccBusTermDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccBusTermDef",
           (PyObject*)(&PyoaObserver_oaOccBusTermDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccBusTermDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccConnectDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccConnectDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccConnectDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccConnectDefObject* self = (PyoaObserver_oaOccConnectDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccConnectDef* p=new pyv_oaObserver_oaOccConnectDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccConnectDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccConnectDef* p=new pyv_oaObserver_oaOccConnectDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccConnectDef)
    {
        PyParamoaObserver_oaOccConnectDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccConnectDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccConnectDef* p=new pyv_oaObserver_oaOccConnectDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccConnectDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccConnectDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccConnectDef_tp_dealloc(PyoaObserver_oaOccConnectDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccConnectDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccConnectDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccConnectDef value;
    int convert_status=PyoaObserver_oaOccConnectDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaOccConnectDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccConnectDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccConnectDef v1;
    PyParamoaObserver_oaOccConnectDef v2;
    int convert_status1=PyoaObserver_oaOccConnectDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccConnectDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccConnectDef_Convert(PyObject* ob,PyParamoaObserver_oaOccConnectDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccConnectDef_Check(ob)) {
        result->SetData( (oaObserver_oaOccConnectDef*) ((PyoaObserver_oaOccConnectDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccConnectDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccConnectDef_FromoaObserver_oaOccConnectDef(oaObserver_oaOccConnectDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccConnectDef_Type.tp_alloc(&PyoaObserver_oaOccConnectDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccConnectDefObject* self = (PyoaObserver_oaOccConnectDefObject*)bself;
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
pyv_oaObserver_oaOccConnectDef::pyv_oaObserver_oaOccConnectDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccConnectDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccConnectDef::pyv_oaObserver_oaOccConnectDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccConnectDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccConnectDef::pyv_oaObserver_oaOccConnectDef(const oaObserver_oaOccConnectDef& p)
 : pyob(NULL),
   oaObserver_oaOccConnectDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccConnectDef::onPostCreate(oaOccConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccConnectDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccConnectDef_FromoaOccConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccConnectDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccConnectDef::onPostModify(oaOccConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccConnectDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccConnectDef_FromoaOccConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccConnectDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccConnectDef::onPreDestroy(oaOccConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccConnectDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccConnectDef_FromoaOccConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccConnectDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccConnectDef::onPreModify(oaOccConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccConnectDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccConnectDef_FromoaOccConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccConnectDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccConnectDef_doc[] = 
"Class: oaObserver_oaOccConnectDef\n"
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
"    Calls: oaObserver_oaOccConnectDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccConnectDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccConnectDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccConnectDef\n"
"  Paramegers: (oaObserver_oaOccConnectDef)\n"
"    Calls: (const oaObserver_oaOccConnectDef&)\n"
"    Signature: oaObserver_oaOccConnectDef||cref-oaObserver_oaOccConnectDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccConnectDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccConnectDef",
    sizeof(PyoaObserver_oaOccConnectDefObject),
    0,
    (destructor)oaObserver_oaOccConnectDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccConnectDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccConnectDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccConnectDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccConnectDef_oaConnectDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccConnectDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccConnectDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccConnectDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccConnectDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccConnectDef",
           (PyObject*)(&PyoaObserver_oaOccConnectDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccConnectDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccDesignInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccDesignInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccDesignInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccDesignInstObject* self = (PyoaObserver_oaOccDesignInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccDesignInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccDesignInst* p=new pyv_oaObserver_oaOccDesignInst(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccDesignInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccDesignInst* p=new pyv_oaObserver_oaOccDesignInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccDesignInst)
    {
        PyParamoaObserver_oaOccDesignInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccDesignInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccDesignInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccDesignInst* p=new pyv_oaObserver_oaOccDesignInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccDesignInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccDesignInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccDesignInst_tp_dealloc(PyoaObserver_oaOccDesignInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccDesignInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccDesignInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccDesignInst value;
    int convert_status=PyoaObserver_oaOccDesignInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaOccDesignInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccDesignInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccDesignInst v1;
    PyParamoaObserver_oaOccDesignInst v2;
    int convert_status1=PyoaObserver_oaOccDesignInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccDesignInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccDesignInst_Convert(PyObject* ob,PyParamoaObserver_oaOccDesignInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccDesignInst_Check(ob)) {
        result->SetData( (oaObserver_oaOccDesignInst*) ((PyoaObserver_oaOccDesignInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccDesignInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccDesignInst_FromoaObserver_oaOccDesignInst(oaObserver_oaOccDesignInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccDesignInst_Type.tp_alloc(&PyoaObserver_oaOccDesignInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccDesignInstObject* self = (PyoaObserver_oaOccDesignInstObject*)bself;
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
pyv_oaObserver_oaOccDesignInst::pyv_oaObserver_oaOccDesignInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccDesignInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccDesignInst::pyv_oaObserver_oaOccDesignInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccDesignInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccDesignInst::pyv_oaObserver_oaOccDesignInst(const oaObserver_oaOccDesignInst& p)
 : pyob(NULL),
   oaObserver_oaOccDesignInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccDesignInst::onPostCreate(oaOccDesignInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccDesignInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccDesignInst_FromoaOccDesignInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccDesignInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccDesignInst::onPostModify(oaOccDesignInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccDesignInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccDesignInst_FromoaOccDesignInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccDesignInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccDesignInst::onPreDestroy(oaOccDesignInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccDesignInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccDesignInst_FromoaOccDesignInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccDesignInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccDesignInst::onPreModify(oaOccDesignInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccDesignInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccDesignInst_FromoaOccDesignInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccDesignInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccDesignInst_doc[] = 
"Class: oaObserver_oaOccDesignInst\n"
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
"    Calls: oaObserver_oaOccDesignInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccDesignInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccDesignInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccDesignInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccDesignInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccDesignInst\n"
"  Paramegers: (oaObserver_oaOccDesignInst)\n"
"    Calls: (const oaObserver_oaOccDesignInst&)\n"
"    Signature: oaObserver_oaOccDesignInst||cref-oaObserver_oaOccDesignInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccDesignInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccDesignInst",
    sizeof(PyoaObserver_oaOccDesignInstObject),
    0,
    (destructor)oaObserver_oaOccDesignInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccDesignInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccDesignInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccDesignInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccDesignInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccDesignInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccDesignInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccDesignInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccDesignInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccDesignInst",
           (PyObject*)(&PyoaObserver_oaOccDesignInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccDesignInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccInstObject* self = (PyoaObserver_oaOccInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccInst* p=new pyv_oaObserver_oaOccInst(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccInst* p=new pyv_oaObserver_oaOccInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccInst)
    {
        PyParamoaObserver_oaOccInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccInst* p=new pyv_oaObserver_oaOccInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccInst_tp_dealloc(PyoaObserver_oaOccInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccInst value;
    int convert_status=PyoaObserver_oaOccInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaObserver_oaOccInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccInst v1;
    PyParamoaObserver_oaOccInst v2;
    int convert_status1=PyoaObserver_oaOccInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccInst_Convert(PyObject* ob,PyParamoaObserver_oaOccInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccInst_Check(ob)) {
        result->SetData( (oaObserver_oaOccInst*) ((PyoaObserver_oaOccInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccInst_FromoaObserver_oaOccInst(oaObserver_oaOccInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccInst_Type.tp_alloc(&PyoaObserver_oaOccInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccInstObject* self = (PyoaObserver_oaOccInstObject*)bself;
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
pyv_oaObserver_oaOccInst::pyv_oaObserver_oaOccInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccInst::pyv_oaObserver_oaOccInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccInst::pyv_oaObserver_oaOccInst(const oaObserver_oaOccInst& p)
 : pyob(NULL),
   oaObserver_oaOccInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccInst::onPostCreate(oaOccInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccInst_FromoaOccInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccInst::onPostModify(oaOccInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccInst_FromoaOccInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccInst::onPreDestroy(oaOccInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccInst_FromoaOccInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccInst::onPreModify(oaOccInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccInst_FromoaOccInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccInst_doc[] = 
"Class: oaObserver_oaOccInst\n"
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
"    Calls: oaObserver_oaOccInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccInst\n"
"  Paramegers: (oaObserver_oaOccInst)\n"
"    Calls: (const oaObserver_oaOccInst&)\n"
"    Signature: oaObserver_oaOccInst||cref-oaObserver_oaOccInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccInst",
    sizeof(PyoaObserver_oaOccInstObject),
    0,
    (destructor)oaObserver_oaOccInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccInst",
           (PyObject*)(&PyoaObserver_oaOccInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccInstHeaderObject* self = (PyoaObserver_oaOccInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccInstHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccInstHeader* p=new pyv_oaObserver_oaOccInstHeader(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccInstHeader(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccInstHeader* p=new pyv_oaObserver_oaOccInstHeader(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccInstHeader)
    {
        PyParamoaObserver_oaOccInstHeader p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccInstHeader_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccInstHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccInstHeader* p=new pyv_oaObserver_oaOccInstHeader(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccInstHeader, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccInstHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccInstHeader_tp_dealloc(PyoaObserver_oaOccInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccInstHeader value;
    int convert_status=PyoaObserver_oaOccInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaOccInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccInstHeader v1;
    PyParamoaObserver_oaOccInstHeader v2;
    int convert_status1=PyoaObserver_oaOccInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccInstHeader_Convert(PyObject* ob,PyParamoaObserver_oaOccInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccInstHeader_Check(ob)) {
        result->SetData( (oaObserver_oaOccInstHeader*) ((PyoaObserver_oaOccInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccInstHeader_FromoaObserver_oaOccInstHeader(oaObserver_oaOccInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccInstHeader_Type.tp_alloc(&PyoaObserver_oaOccInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccInstHeaderObject* self = (PyoaObserver_oaOccInstHeaderObject*)bself;
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
pyv_oaObserver_oaOccInstHeader::pyv_oaObserver_oaOccInstHeader(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccInstHeader(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccInstHeader::pyv_oaObserver_oaOccInstHeader(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccInstHeader(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccInstHeader::pyv_oaObserver_oaOccInstHeader(const oaObserver_oaOccInstHeader& p)
 : pyob(NULL),
   oaObserver_oaOccInstHeader(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccInstHeader::onPostCreate(oaOccInstHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInstHeader::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccInstHeader_FromoaOccInstHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInstHeader::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccInstHeader::onPostModify(oaOccInstHeader* p1,oaInstHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInstHeader::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccInstHeader_FromoaOccInstHeader(p1));
    PyTuple_SetItem(args,1,PyoaInstHeaderModTypeEnum_FromoaInstHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInstHeader::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccInstHeader::onPreDestroy(oaOccInstHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInstHeader::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccInstHeader_FromoaOccInstHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInstHeader::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccInstHeader::onPreModify(oaOccInstHeader* p1,oaInstHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInstHeader::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccInstHeader_FromoaOccInstHeader(p1));
    PyTuple_SetItem(args,1,PyoaInstHeaderModTypeEnum_FromoaInstHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInstHeader::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccInstHeader_doc[] = 
"Class: oaObserver_oaOccInstHeader\n"
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
"    Calls: oaObserver_oaOccInstHeader(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccInstHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccInstHeader\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccInstHeader(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccInstHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccInstHeader\n"
"  Paramegers: (oaObserver_oaOccInstHeader)\n"
"    Calls: (const oaObserver_oaOccInstHeader&)\n"
"    Signature: oaObserver_oaOccInstHeader||cref-oaObserver_oaOccInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccInstHeader",
    sizeof(PyoaObserver_oaOccInstHeaderObject),
    0,
    (destructor)oaObserver_oaOccInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccInstHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccInstHeader_oaInstHeaderModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccInstHeader",
           (PyObject*)(&PyoaObserver_oaOccInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccInstHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccInstTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccInstTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccInstTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccInstTermObject* self = (PyoaObserver_oaOccInstTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccInstTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccInstTerm* p=new pyv_oaObserver_oaOccInstTerm(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccInstTerm(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccInstTerm* p=new pyv_oaObserver_oaOccInstTerm(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccInstTerm)
    {
        PyParamoaObserver_oaOccInstTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccInstTerm_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccInstTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccInstTerm* p=new pyv_oaObserver_oaOccInstTerm(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccInstTerm, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccInstTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccInstTerm_tp_dealloc(PyoaObserver_oaOccInstTermObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccInstTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccInstTerm_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccInstTerm value;
    int convert_status=PyoaObserver_oaOccInstTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaObserver_oaOccInstTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccInstTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccInstTerm v1;
    PyParamoaObserver_oaOccInstTerm v2;
    int convert_status1=PyoaObserver_oaOccInstTerm_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccInstTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccInstTerm_Convert(PyObject* ob,PyParamoaObserver_oaOccInstTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccInstTerm_Check(ob)) {
        result->SetData( (oaObserver_oaOccInstTerm*) ((PyoaObserver_oaOccInstTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccInstTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccInstTerm_FromoaObserver_oaOccInstTerm(oaObserver_oaOccInstTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccInstTerm_Type.tp_alloc(&PyoaObserver_oaOccInstTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccInstTermObject* self = (PyoaObserver_oaOccInstTermObject*)bself;
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
pyv_oaObserver_oaOccInstTerm::pyv_oaObserver_oaOccInstTerm(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccInstTerm(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccInstTerm::pyv_oaObserver_oaOccInstTerm(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccInstTerm(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccInstTerm::pyv_oaObserver_oaOccInstTerm(const oaObserver_oaOccInstTerm& p)
 : pyob(NULL),
   oaObserver_oaOccInstTerm(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccInstTerm::onPostCreate(oaOccInstTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInstTerm::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccInstTerm_FromoaOccInstTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInstTerm::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccInstTerm::onPostModify(oaOccInstTerm* p1,oaInstTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInstTerm::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccInstTerm_FromoaOccInstTerm(p1));
    PyTuple_SetItem(args,1,PyoaInstTermModTypeEnum_FromoaInstTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInstTerm::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccInstTerm::onPreDestroy(oaOccInstTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInstTerm::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccInstTerm_FromoaOccInstTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInstTerm::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccInstTerm::onPreModify(oaOccInstTerm* p1,oaInstTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInstTerm::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccInstTerm_FromoaOccInstTerm(p1));
    PyTuple_SetItem(args,1,PyoaInstTermModTypeEnum_FromoaInstTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccInstTerm::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccInstTerm_doc[] = 
"Class: oaObserver_oaOccInstTerm\n"
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
"    Calls: oaObserver_oaOccInstTerm(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccInstTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccInstTerm\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccInstTerm(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccInstTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccInstTerm\n"
"  Paramegers: (oaObserver_oaOccInstTerm)\n"
"    Calls: (const oaObserver_oaOccInstTerm&)\n"
"    Signature: oaObserver_oaOccInstTerm||cref-oaObserver_oaOccInstTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccInstTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccInstTerm",
    sizeof(PyoaObserver_oaOccInstTermObject),
    0,
    (destructor)oaObserver_oaOccInstTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccInstTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccInstTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccInstTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccInstTerm_oaInstTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccInstTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccInstTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccInstTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccInstTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccInstTerm",
           (PyObject*)(&PyoaObserver_oaOccInstTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccInstTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccModuleBitInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccModuleBitInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccModuleBitInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccModuleBitInstObject* self = (PyoaObserver_oaOccModuleBitInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccModuleBitInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleBitInst* p=new pyv_oaObserver_oaOccModuleBitInst(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccModuleBitInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleBitInst* p=new pyv_oaObserver_oaOccModuleBitInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccModuleBitInst)
    {
        PyParamoaObserver_oaOccModuleBitInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccModuleBitInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccModuleBitInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleBitInst* p=new pyv_oaObserver_oaOccModuleBitInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccModuleBitInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccModuleBitInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccModuleBitInst_tp_dealloc(PyoaObserver_oaOccModuleBitInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccModuleBitInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccModuleBitInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccModuleBitInst value;
    int convert_status=PyoaObserver_oaOccModuleBitInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaObserver_oaOccModuleBitInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccModuleBitInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccModuleBitInst v1;
    PyParamoaObserver_oaOccModuleBitInst v2;
    int convert_status1=PyoaObserver_oaOccModuleBitInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccModuleBitInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccModuleBitInst_Convert(PyObject* ob,PyParamoaObserver_oaOccModuleBitInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccModuleBitInst_Check(ob)) {
        result->SetData( (oaObserver_oaOccModuleBitInst*) ((PyoaObserver_oaOccModuleBitInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccModuleBitInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccModuleBitInst_FromoaObserver_oaOccModuleBitInst(oaObserver_oaOccModuleBitInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccModuleBitInst_Type.tp_alloc(&PyoaObserver_oaOccModuleBitInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccModuleBitInstObject* self = (PyoaObserver_oaOccModuleBitInstObject*)bself;
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
pyv_oaObserver_oaOccModuleBitInst::pyv_oaObserver_oaOccModuleBitInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccModuleBitInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccModuleBitInst::pyv_oaObserver_oaOccModuleBitInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccModuleBitInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccModuleBitInst::pyv_oaObserver_oaOccModuleBitInst(const oaObserver_oaOccModuleBitInst& p)
 : pyob(NULL),
   oaObserver_oaOccModuleBitInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleBitInst::onPostCreate(oaOccModuleBitInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleBitInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccModuleBitInst_FromoaOccModuleBitInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleBitInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleBitInst::onPostModify(oaOccModuleBitInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleBitInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccModuleBitInst_FromoaOccModuleBitInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleBitInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleBitInst::onPreDestroy(oaOccModuleBitInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleBitInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccModuleBitInst_FromoaOccModuleBitInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleBitInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleBitInst::onPreModify(oaOccModuleBitInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleBitInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccModuleBitInst_FromoaOccModuleBitInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleBitInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccModuleBitInst_doc[] = 
"Class: oaObserver_oaOccModuleBitInst\n"
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
"    Calls: oaObserver_oaOccModuleBitInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccModuleBitInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccModuleBitInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccModuleBitInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccModuleBitInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccModuleBitInst\n"
"  Paramegers: (oaObserver_oaOccModuleBitInst)\n"
"    Calls: (const oaObserver_oaOccModuleBitInst&)\n"
"    Signature: oaObserver_oaOccModuleBitInst||cref-oaObserver_oaOccModuleBitInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccModuleBitInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccModuleBitInst",
    sizeof(PyoaObserver_oaOccModuleBitInstObject),
    0,
    (destructor)oaObserver_oaOccModuleBitInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccModuleBitInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccModuleBitInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccModuleBitInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccModuleBitInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccModuleBitInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccModuleBitInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccModuleBitInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccModuleBitInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccModuleBitInst",
           (PyObject*)(&PyoaObserver_oaOccModuleBitInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccModuleBitInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccModuleInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccModuleInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccModuleInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccModuleInstObject* self = (PyoaObserver_oaOccModuleInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccModuleInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleInst* p=new pyv_oaObserver_oaOccModuleInst(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccModuleInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleInst* p=new pyv_oaObserver_oaOccModuleInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccModuleInst)
    {
        PyParamoaObserver_oaOccModuleInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccModuleInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccModuleInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleInst* p=new pyv_oaObserver_oaOccModuleInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccModuleInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccModuleInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccModuleInst_tp_dealloc(PyoaObserver_oaOccModuleInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccModuleInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccModuleInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccModuleInst value;
    int convert_status=PyoaObserver_oaOccModuleInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaOccModuleInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccModuleInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccModuleInst v1;
    PyParamoaObserver_oaOccModuleInst v2;
    int convert_status1=PyoaObserver_oaOccModuleInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccModuleInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccModuleInst_Convert(PyObject* ob,PyParamoaObserver_oaOccModuleInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccModuleInst_Check(ob)) {
        result->SetData( (oaObserver_oaOccModuleInst*) ((PyoaObserver_oaOccModuleInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccModuleInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccModuleInst_FromoaObserver_oaOccModuleInst(oaObserver_oaOccModuleInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccModuleInst_Type.tp_alloc(&PyoaObserver_oaOccModuleInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccModuleInstObject* self = (PyoaObserver_oaOccModuleInstObject*)bself;
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
pyv_oaObserver_oaOccModuleInst::pyv_oaObserver_oaOccModuleInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccModuleInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccModuleInst::pyv_oaObserver_oaOccModuleInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccModuleInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccModuleInst::pyv_oaObserver_oaOccModuleInst(const oaObserver_oaOccModuleInst& p)
 : pyob(NULL),
   oaObserver_oaOccModuleInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleInst::onPostCreate(oaOccModuleInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccModuleInst_FromoaOccModuleInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleInst::onPostModify(oaOccModuleInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccModuleInst_FromoaOccModuleInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleInst::onPreDestroy(oaOccModuleInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccModuleInst_FromoaOccModuleInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleInst::onPreModify(oaOccModuleInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccModuleInst_FromoaOccModuleInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccModuleInst_doc[] = 
"Class: oaObserver_oaOccModuleInst\n"
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
"    Calls: oaObserver_oaOccModuleInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccModuleInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccModuleInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccModuleInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccModuleInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccModuleInst\n"
"  Paramegers: (oaObserver_oaOccModuleInst)\n"
"    Calls: (const oaObserver_oaOccModuleInst&)\n"
"    Signature: oaObserver_oaOccModuleInst||cref-oaObserver_oaOccModuleInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccModuleInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccModuleInst",
    sizeof(PyoaObserver_oaOccModuleInstObject),
    0,
    (destructor)oaObserver_oaOccModuleInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccModuleInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccModuleInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccModuleInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccModuleInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccModuleInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccModuleInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccModuleInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccModuleInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccModuleInst",
           (PyObject*)(&PyoaObserver_oaOccModuleInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccModuleInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccModuleInstHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccModuleInstHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccModuleInstHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccModuleInstHeaderObject* self = (PyoaObserver_oaOccModuleInstHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccModuleInstHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleInstHeader* p=new pyv_oaObserver_oaOccModuleInstHeader(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccModuleInstHeader(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleInstHeader* p=new pyv_oaObserver_oaOccModuleInstHeader(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccModuleInstHeader)
    {
        PyParamoaObserver_oaOccModuleInstHeader p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccModuleInstHeader_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccModuleInstHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleInstHeader* p=new pyv_oaObserver_oaOccModuleInstHeader(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccModuleInstHeader, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccModuleInstHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccModuleInstHeader_tp_dealloc(PyoaObserver_oaOccModuleInstHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccModuleInstHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccModuleInstHeader_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccModuleInstHeader value;
    int convert_status=PyoaObserver_oaOccModuleInstHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaObserver_oaOccModuleInstHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccModuleInstHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccModuleInstHeader v1;
    PyParamoaObserver_oaOccModuleInstHeader v2;
    int convert_status1=PyoaObserver_oaOccModuleInstHeader_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccModuleInstHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccModuleInstHeader_Convert(PyObject* ob,PyParamoaObserver_oaOccModuleInstHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccModuleInstHeader_Check(ob)) {
        result->SetData( (oaObserver_oaOccModuleInstHeader*) ((PyoaObserver_oaOccModuleInstHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccModuleInstHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccModuleInstHeader_FromoaObserver_oaOccModuleInstHeader(oaObserver_oaOccModuleInstHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccModuleInstHeader_Type.tp_alloc(&PyoaObserver_oaOccModuleInstHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccModuleInstHeaderObject* self = (PyoaObserver_oaOccModuleInstHeaderObject*)bself;
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
pyv_oaObserver_oaOccModuleInstHeader::pyv_oaObserver_oaOccModuleInstHeader(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccModuleInstHeader(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccModuleInstHeader::pyv_oaObserver_oaOccModuleInstHeader(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccModuleInstHeader(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccModuleInstHeader::pyv_oaObserver_oaOccModuleInstHeader(const oaObserver_oaOccModuleInstHeader& p)
 : pyob(NULL),
   oaObserver_oaOccModuleInstHeader(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleInstHeader::onPostCreate(oaOccModuleInstHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleInstHeader::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccModuleInstHeader_FromoaOccModuleInstHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleInstHeader::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleInstHeader::onPostModify(oaOccModuleInstHeader* p1,oaModuleInstHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleInstHeader::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccModuleInstHeader_FromoaOccModuleInstHeader(p1));
    PyTuple_SetItem(args,1,PyoaModuleInstHeaderModTypeEnum_FromoaModuleInstHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleInstHeader::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleInstHeader::onPreDestroy(oaOccModuleInstHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleInstHeader::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccModuleInstHeader_FromoaOccModuleInstHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleInstHeader::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleInstHeader::onPreModify(oaOccModuleInstHeader* p1,oaModuleInstHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleInstHeader::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccModuleInstHeader_FromoaOccModuleInstHeader(p1));
    PyTuple_SetItem(args,1,PyoaModuleInstHeaderModTypeEnum_FromoaModuleInstHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleInstHeader::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccModuleInstHeader_doc[] = 
"Class: oaObserver_oaOccModuleInstHeader\n"
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
"    Calls: oaObserver_oaOccModuleInstHeader(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccModuleInstHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccModuleInstHeader\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccModuleInstHeader(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccModuleInstHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccModuleInstHeader\n"
"  Paramegers: (oaObserver_oaOccModuleInstHeader)\n"
"    Calls: (const oaObserver_oaOccModuleInstHeader&)\n"
"    Signature: oaObserver_oaOccModuleInstHeader||cref-oaObserver_oaOccModuleInstHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccModuleInstHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccModuleInstHeader",
    sizeof(PyoaObserver_oaOccModuleInstHeaderObject),
    0,
    (destructor)oaObserver_oaOccModuleInstHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccModuleInstHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccModuleInstHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccModuleInstHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccModuleInstHeader_oaModuleInstHeaderModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccModuleInstHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccModuleInstHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccModuleInstHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccModuleInstHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccModuleInstHeader",
           (PyObject*)(&PyoaObserver_oaOccModuleInstHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccModuleInstHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccModuleScalarInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccModuleScalarInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccModuleScalarInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccModuleScalarInstObject* self = (PyoaObserver_oaOccModuleScalarInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccModuleScalarInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleScalarInst* p=new pyv_oaObserver_oaOccModuleScalarInst(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccModuleScalarInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleScalarInst* p=new pyv_oaObserver_oaOccModuleScalarInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccModuleScalarInst)
    {
        PyParamoaObserver_oaOccModuleScalarInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccModuleScalarInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccModuleScalarInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleScalarInst* p=new pyv_oaObserver_oaOccModuleScalarInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccModuleScalarInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccModuleScalarInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccModuleScalarInst_tp_dealloc(PyoaObserver_oaOccModuleScalarInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccModuleScalarInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccModuleScalarInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccModuleScalarInst value;
    int convert_status=PyoaObserver_oaOccModuleScalarInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaObserver_oaOccModuleScalarInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccModuleScalarInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccModuleScalarInst v1;
    PyParamoaObserver_oaOccModuleScalarInst v2;
    int convert_status1=PyoaObserver_oaOccModuleScalarInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccModuleScalarInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccModuleScalarInst_Convert(PyObject* ob,PyParamoaObserver_oaOccModuleScalarInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccModuleScalarInst_Check(ob)) {
        result->SetData( (oaObserver_oaOccModuleScalarInst*) ((PyoaObserver_oaOccModuleScalarInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccModuleScalarInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccModuleScalarInst_FromoaObserver_oaOccModuleScalarInst(oaObserver_oaOccModuleScalarInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccModuleScalarInst_Type.tp_alloc(&PyoaObserver_oaOccModuleScalarInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccModuleScalarInstObject* self = (PyoaObserver_oaOccModuleScalarInstObject*)bself;
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
pyv_oaObserver_oaOccModuleScalarInst::pyv_oaObserver_oaOccModuleScalarInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccModuleScalarInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccModuleScalarInst::pyv_oaObserver_oaOccModuleScalarInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccModuleScalarInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccModuleScalarInst::pyv_oaObserver_oaOccModuleScalarInst(const oaObserver_oaOccModuleScalarInst& p)
 : pyob(NULL),
   oaObserver_oaOccModuleScalarInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleScalarInst::onPostCreate(oaOccModuleScalarInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleScalarInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccModuleScalarInst_FromoaOccModuleScalarInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleScalarInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleScalarInst::onPostModify(oaOccModuleScalarInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleScalarInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccModuleScalarInst_FromoaOccModuleScalarInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleScalarInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleScalarInst::onPreDestroy(oaOccModuleScalarInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleScalarInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccModuleScalarInst_FromoaOccModuleScalarInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleScalarInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleScalarInst::onPreModify(oaOccModuleScalarInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleScalarInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccModuleScalarInst_FromoaOccModuleScalarInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleScalarInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccModuleScalarInst_doc[] = 
"Class: oaObserver_oaOccModuleScalarInst\n"
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
"    Calls: oaObserver_oaOccModuleScalarInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccModuleScalarInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccModuleScalarInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccModuleScalarInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccModuleScalarInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccModuleScalarInst\n"
"  Paramegers: (oaObserver_oaOccModuleScalarInst)\n"
"    Calls: (const oaObserver_oaOccModuleScalarInst&)\n"
"    Signature: oaObserver_oaOccModuleScalarInst||cref-oaObserver_oaOccModuleScalarInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccModuleScalarInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccModuleScalarInst",
    sizeof(PyoaObserver_oaOccModuleScalarInstObject),
    0,
    (destructor)oaObserver_oaOccModuleScalarInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccModuleScalarInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccModuleScalarInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccModuleScalarInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccModuleScalarInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccModuleScalarInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccModuleScalarInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccModuleScalarInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccModuleScalarInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccModuleScalarInst",
           (PyObject*)(&PyoaObserver_oaOccModuleScalarInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccModuleScalarInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccModuleVectorInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccModuleVectorInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccModuleVectorInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccModuleVectorInstObject* self = (PyoaObserver_oaOccModuleVectorInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccModuleVectorInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleVectorInst* p=new pyv_oaObserver_oaOccModuleVectorInst(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccModuleVectorInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleVectorInst* p=new pyv_oaObserver_oaOccModuleVectorInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccModuleVectorInst)
    {
        PyParamoaObserver_oaOccModuleVectorInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccModuleVectorInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccModuleVectorInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleVectorInst* p=new pyv_oaObserver_oaOccModuleVectorInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccModuleVectorInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccModuleVectorInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccModuleVectorInst_tp_dealloc(PyoaObserver_oaOccModuleVectorInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccModuleVectorInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccModuleVectorInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccModuleVectorInst value;
    int convert_status=PyoaObserver_oaOccModuleVectorInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[54];
    sprintf(buffer,"<oaObserver_oaOccModuleVectorInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccModuleVectorInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccModuleVectorInst v1;
    PyParamoaObserver_oaOccModuleVectorInst v2;
    int convert_status1=PyoaObserver_oaOccModuleVectorInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccModuleVectorInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccModuleVectorInst_Convert(PyObject* ob,PyParamoaObserver_oaOccModuleVectorInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccModuleVectorInst_Check(ob)) {
        result->SetData( (oaObserver_oaOccModuleVectorInst*) ((PyoaObserver_oaOccModuleVectorInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccModuleVectorInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccModuleVectorInst_FromoaObserver_oaOccModuleVectorInst(oaObserver_oaOccModuleVectorInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccModuleVectorInst_Type.tp_alloc(&PyoaObserver_oaOccModuleVectorInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccModuleVectorInstObject* self = (PyoaObserver_oaOccModuleVectorInstObject*)bself;
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
pyv_oaObserver_oaOccModuleVectorInst::pyv_oaObserver_oaOccModuleVectorInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccModuleVectorInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccModuleVectorInst::pyv_oaObserver_oaOccModuleVectorInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccModuleVectorInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccModuleVectorInst::pyv_oaObserver_oaOccModuleVectorInst(const oaObserver_oaOccModuleVectorInst& p)
 : pyob(NULL),
   oaObserver_oaOccModuleVectorInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleVectorInst::onPostCreate(oaOccModuleVectorInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleVectorInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccModuleVectorInst_FromoaOccModuleVectorInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleVectorInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleVectorInst::onPostModify(oaOccModuleVectorInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleVectorInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccModuleVectorInst_FromoaOccModuleVectorInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleVectorInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleVectorInst::onPreDestroy(oaOccModuleVectorInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleVectorInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccModuleVectorInst_FromoaOccModuleVectorInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleVectorInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleVectorInst::onPreModify(oaOccModuleVectorInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleVectorInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccModuleVectorInst_FromoaOccModuleVectorInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleVectorInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccModuleVectorInst_doc[] = 
"Class: oaObserver_oaOccModuleVectorInst\n"
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
"    Calls: oaObserver_oaOccModuleVectorInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccModuleVectorInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccModuleVectorInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccModuleVectorInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccModuleVectorInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccModuleVectorInst\n"
"  Paramegers: (oaObserver_oaOccModuleVectorInst)\n"
"    Calls: (const oaObserver_oaOccModuleVectorInst&)\n"
"    Signature: oaObserver_oaOccModuleVectorInst||cref-oaObserver_oaOccModuleVectorInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccModuleVectorInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccModuleVectorInst",
    sizeof(PyoaObserver_oaOccModuleVectorInstObject),
    0,
    (destructor)oaObserver_oaOccModuleVectorInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccModuleVectorInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccModuleVectorInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccModuleVectorInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccModuleVectorInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccModuleVectorInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccModuleVectorInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccModuleVectorInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccModuleVectorInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccModuleVectorInst",
           (PyObject*)(&PyoaObserver_oaOccModuleVectorInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccModuleVectorInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccModuleVectorInstBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccModuleVectorInstBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccModuleVectorInstBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccModuleVectorInstBitObject* self = (PyoaObserver_oaOccModuleVectorInstBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccModuleVectorInstBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleVectorInstBit* p=new pyv_oaObserver_oaOccModuleVectorInstBit(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccModuleVectorInstBit(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleVectorInstBit* p=new pyv_oaObserver_oaOccModuleVectorInstBit(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccModuleVectorInstBit)
    {
        PyParamoaObserver_oaOccModuleVectorInstBit p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccModuleVectorInstBit_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccModuleVectorInstBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccModuleVectorInstBit* p=new pyv_oaObserver_oaOccModuleVectorInstBit(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccModuleVectorInstBit, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccModuleVectorInstBit)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccModuleVectorInstBit_tp_dealloc(PyoaObserver_oaOccModuleVectorInstBitObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccModuleVectorInstBit*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccModuleVectorInstBit_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccModuleVectorInstBit value;
    int convert_status=PyoaObserver_oaOccModuleVectorInstBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[57];
    sprintf(buffer,"<oaObserver_oaOccModuleVectorInstBit::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccModuleVectorInstBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccModuleVectorInstBit v1;
    PyParamoaObserver_oaOccModuleVectorInstBit v2;
    int convert_status1=PyoaObserver_oaOccModuleVectorInstBit_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccModuleVectorInstBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccModuleVectorInstBit_Convert(PyObject* ob,PyParamoaObserver_oaOccModuleVectorInstBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccModuleVectorInstBit_Check(ob)) {
        result->SetData( (oaObserver_oaOccModuleVectorInstBit*) ((PyoaObserver_oaOccModuleVectorInstBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccModuleVectorInstBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccModuleVectorInstBit_FromoaObserver_oaOccModuleVectorInstBit(oaObserver_oaOccModuleVectorInstBit* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccModuleVectorInstBit_Type.tp_alloc(&PyoaObserver_oaOccModuleVectorInstBit_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccModuleVectorInstBitObject* self = (PyoaObserver_oaOccModuleVectorInstBitObject*)bself;
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
pyv_oaObserver_oaOccModuleVectorInstBit::pyv_oaObserver_oaOccModuleVectorInstBit(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccModuleVectorInstBit(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccModuleVectorInstBit::pyv_oaObserver_oaOccModuleVectorInstBit(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccModuleVectorInstBit(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccModuleVectorInstBit::pyv_oaObserver_oaOccModuleVectorInstBit(const oaObserver_oaOccModuleVectorInstBit& p)
 : pyob(NULL),
   oaObserver_oaOccModuleVectorInstBit(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleVectorInstBit::onPostCreate(oaOccModuleVectorInstBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleVectorInstBit::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccModuleVectorInstBit_FromoaOccModuleVectorInstBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleVectorInstBit::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleVectorInstBit::onPostModify(oaOccModuleVectorInstBit* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleVectorInstBit::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccModuleVectorInstBit_FromoaOccModuleVectorInstBit(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleVectorInstBit::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleVectorInstBit::onPreDestroy(oaOccModuleVectorInstBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleVectorInstBit::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccModuleVectorInstBit_FromoaOccModuleVectorInstBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleVectorInstBit::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccModuleVectorInstBit::onPreModify(oaOccModuleVectorInstBit* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleVectorInstBit::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccModuleVectorInstBit_FromoaOccModuleVectorInstBit(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccModuleVectorInstBit::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccModuleVectorInstBit_doc[] = 
"Class: oaObserver_oaOccModuleVectorInstBit\n"
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
"    Calls: oaObserver_oaOccModuleVectorInstBit(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccModuleVectorInstBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccModuleVectorInstBit\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccModuleVectorInstBit(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccModuleVectorInstBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccModuleVectorInstBit\n"
"  Paramegers: (oaObserver_oaOccModuleVectorInstBit)\n"
"    Calls: (const oaObserver_oaOccModuleVectorInstBit&)\n"
"    Signature: oaObserver_oaOccModuleVectorInstBit||cref-oaObserver_oaOccModuleVectorInstBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccModuleVectorInstBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccModuleVectorInstBit",
    sizeof(PyoaObserver_oaOccModuleVectorInstBitObject),
    0,
    (destructor)oaObserver_oaOccModuleVectorInstBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccModuleVectorInstBit_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccModuleVectorInstBit_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccModuleVectorInstBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccModuleVectorInstBit_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccModuleVectorInstBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccModuleVectorInstBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccModuleVectorInstBit_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccModuleVectorInstBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccModuleVectorInstBit",
           (PyObject*)(&PyoaObserver_oaOccModuleVectorInstBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccModuleVectorInstBit\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccNetObject* self = (PyoaObserver_oaOccNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccNet* p=new pyv_oaObserver_oaOccNet(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccNet(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccNet* p=new pyv_oaObserver_oaOccNet(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccNet)
    {
        PyParamoaObserver_oaOccNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccNet_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccNet* p=new pyv_oaObserver_oaOccNet(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccNet, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccNet_tp_dealloc(PyoaObserver_oaOccNetObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccNet_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccNet value;
    int convert_status=PyoaObserver_oaOccNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaObserver_oaOccNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccNet v1;
    PyParamoaObserver_oaOccNet v2;
    int convert_status1=PyoaObserver_oaOccNet_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccNet_Convert(PyObject* ob,PyParamoaObserver_oaOccNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccNet_Check(ob)) {
        result->SetData( (oaObserver_oaOccNet*) ((PyoaObserver_oaOccNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccNet_FromoaObserver_oaOccNet(oaObserver_oaOccNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccNet_Type.tp_alloc(&PyoaObserver_oaOccNet_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccNetObject* self = (PyoaObserver_oaOccNetObject*)bself;
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
pyv_oaObserver_oaOccNet::pyv_oaObserver_oaOccNet(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccNet(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccNet::pyv_oaObserver_oaOccNet(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccNet(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccNet::pyv_oaObserver_oaOccNet(const oaObserver_oaOccNet& p)
 : pyob(NULL),
   oaObserver_oaOccNet(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccNet::onPostCreate(oaOccNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccNet::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccNet_FromoaOccNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccNet::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccNet::onPostModify(oaOccNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccNet::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccNet_FromoaOccNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccNet::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccNet::onPreDestroy(oaOccNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccNet::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccNet_FromoaOccNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccNet::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccNet::onPreModify(oaOccNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccNet::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccNet_FromoaOccNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccNet::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccNet_doc[] = 
"Class: oaObserver_oaOccNet\n"
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
"    Calls: oaObserver_oaOccNet(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccNet\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccNet(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccNet\n"
"  Paramegers: (oaObserver_oaOccNet)\n"
"    Calls: (const oaObserver_oaOccNet&)\n"
"    Signature: oaObserver_oaOccNet||cref-oaObserver_oaOccNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccNet",
    sizeof(PyoaObserver_oaOccNetObject),
    0,
    (destructor)oaObserver_oaOccNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccNet_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccNet_oaNetModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccNet_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccNet",
           (PyObject*)(&PyoaObserver_oaOccNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccNetConnectDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccNetConnectDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccNetConnectDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccNetConnectDefObject* self = (PyoaObserver_oaOccNetConnectDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccNetConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccNetConnectDef* p=new pyv_oaObserver_oaOccNetConnectDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccNetConnectDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccNetConnectDef* p=new pyv_oaObserver_oaOccNetConnectDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccNetConnectDef)
    {
        PyParamoaObserver_oaOccNetConnectDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccNetConnectDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccNetConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccNetConnectDef* p=new pyv_oaObserver_oaOccNetConnectDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccNetConnectDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccNetConnectDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccNetConnectDef_tp_dealloc(PyoaObserver_oaOccNetConnectDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccNetConnectDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccNetConnectDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccNetConnectDef value;
    int convert_status=PyoaObserver_oaOccNetConnectDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaObserver_oaOccNetConnectDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccNetConnectDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccNetConnectDef v1;
    PyParamoaObserver_oaOccNetConnectDef v2;
    int convert_status1=PyoaObserver_oaOccNetConnectDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccNetConnectDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccNetConnectDef_Convert(PyObject* ob,PyParamoaObserver_oaOccNetConnectDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccNetConnectDef_Check(ob)) {
        result->SetData( (oaObserver_oaOccNetConnectDef*) ((PyoaObserver_oaOccNetConnectDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccNetConnectDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccNetConnectDef_FromoaObserver_oaOccNetConnectDef(oaObserver_oaOccNetConnectDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccNetConnectDef_Type.tp_alloc(&PyoaObserver_oaOccNetConnectDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccNetConnectDefObject* self = (PyoaObserver_oaOccNetConnectDefObject*)bself;
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
pyv_oaObserver_oaOccNetConnectDef::pyv_oaObserver_oaOccNetConnectDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccNetConnectDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccNetConnectDef::pyv_oaObserver_oaOccNetConnectDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccNetConnectDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccNetConnectDef::pyv_oaObserver_oaOccNetConnectDef(const oaObserver_oaOccNetConnectDef& p)
 : pyob(NULL),
   oaObserver_oaOccNetConnectDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccNetConnectDef::onPostCreate(oaOccNetConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccNetConnectDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccNetConnectDef_FromoaOccNetConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccNetConnectDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccNetConnectDef::onPostModify(oaOccNetConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccNetConnectDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccNetConnectDef_FromoaOccNetConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccNetConnectDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccNetConnectDef::onPreDestroy(oaOccNetConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccNetConnectDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccNetConnectDef_FromoaOccNetConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccNetConnectDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccNetConnectDef::onPreModify(oaOccNetConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccNetConnectDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccNetConnectDef_FromoaOccNetConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccNetConnectDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccNetConnectDef_doc[] = 
"Class: oaObserver_oaOccNetConnectDef\n"
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
"    Calls: oaObserver_oaOccNetConnectDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccNetConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccNetConnectDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccNetConnectDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccNetConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccNetConnectDef\n"
"  Paramegers: (oaObserver_oaOccNetConnectDef)\n"
"    Calls: (const oaObserver_oaOccNetConnectDef&)\n"
"    Signature: oaObserver_oaOccNetConnectDef||cref-oaObserver_oaOccNetConnectDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccNetConnectDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccNetConnectDef",
    sizeof(PyoaObserver_oaOccNetConnectDefObject),
    0,
    (destructor)oaObserver_oaOccNetConnectDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccNetConnectDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccNetConnectDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccNetConnectDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccNetConnectDef_oaConnectDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccNetConnectDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccNetConnectDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccNetConnectDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccNetConnectDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccNetConnectDef",
           (PyObject*)(&PyoaObserver_oaOccNetConnectDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccNetConnectDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccScalarInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccScalarInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccScalarInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccScalarInstObject* self = (PyoaObserver_oaOccScalarInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccScalarInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccScalarInst* p=new pyv_oaObserver_oaOccScalarInst(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccScalarInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccScalarInst* p=new pyv_oaObserver_oaOccScalarInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccScalarInst)
    {
        PyParamoaObserver_oaOccScalarInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccScalarInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccScalarInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccScalarInst* p=new pyv_oaObserver_oaOccScalarInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccScalarInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccScalarInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccScalarInst_tp_dealloc(PyoaObserver_oaOccScalarInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccScalarInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccScalarInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccScalarInst value;
    int convert_status=PyoaObserver_oaOccScalarInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaOccScalarInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccScalarInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccScalarInst v1;
    PyParamoaObserver_oaOccScalarInst v2;
    int convert_status1=PyoaObserver_oaOccScalarInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccScalarInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccScalarInst_Convert(PyObject* ob,PyParamoaObserver_oaOccScalarInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccScalarInst_Check(ob)) {
        result->SetData( (oaObserver_oaOccScalarInst*) ((PyoaObserver_oaOccScalarInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccScalarInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccScalarInst_FromoaObserver_oaOccScalarInst(oaObserver_oaOccScalarInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccScalarInst_Type.tp_alloc(&PyoaObserver_oaOccScalarInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccScalarInstObject* self = (PyoaObserver_oaOccScalarInstObject*)bself;
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
pyv_oaObserver_oaOccScalarInst::pyv_oaObserver_oaOccScalarInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccScalarInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccScalarInst::pyv_oaObserver_oaOccScalarInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccScalarInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccScalarInst::pyv_oaObserver_oaOccScalarInst(const oaObserver_oaOccScalarInst& p)
 : pyob(NULL),
   oaObserver_oaOccScalarInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccScalarInst::onPostCreate(oaOccScalarInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccScalarInst_FromoaOccScalarInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccScalarInst::onPostModify(oaOccScalarInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccScalarInst_FromoaOccScalarInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccScalarInst::onPreDestroy(oaOccScalarInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccScalarInst_FromoaOccScalarInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccScalarInst::onPreModify(oaOccScalarInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccScalarInst_FromoaOccScalarInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccScalarInst_doc[] = 
"Class: oaObserver_oaOccScalarInst\n"
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
"    Calls: oaObserver_oaOccScalarInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccScalarInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccScalarInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccScalarInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccScalarInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccScalarInst\n"
"  Paramegers: (oaObserver_oaOccScalarInst)\n"
"    Calls: (const oaObserver_oaOccScalarInst&)\n"
"    Signature: oaObserver_oaOccScalarInst||cref-oaObserver_oaOccScalarInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccScalarInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccScalarInst",
    sizeof(PyoaObserver_oaOccScalarInstObject),
    0,
    (destructor)oaObserver_oaOccScalarInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccScalarInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccScalarInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccScalarInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccScalarInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccScalarInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccScalarInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccScalarInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccScalarInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccScalarInst",
           (PyObject*)(&PyoaObserver_oaOccScalarInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccScalarInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccScalarNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccScalarNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccScalarNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccScalarNetObject* self = (PyoaObserver_oaOccScalarNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccScalarNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccScalarNet* p=new pyv_oaObserver_oaOccScalarNet(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccScalarNet(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccScalarNet* p=new pyv_oaObserver_oaOccScalarNet(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccScalarNet)
    {
        PyParamoaObserver_oaOccScalarNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccScalarNet_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccScalarNet(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccScalarNet* p=new pyv_oaObserver_oaOccScalarNet(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccScalarNet, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccScalarNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccScalarNet_tp_dealloc(PyoaObserver_oaOccScalarNetObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccScalarNet*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccScalarNet_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccScalarNet value;
    int convert_status=PyoaObserver_oaOccScalarNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaOccScalarNet::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccScalarNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccScalarNet v1;
    PyParamoaObserver_oaOccScalarNet v2;
    int convert_status1=PyoaObserver_oaOccScalarNet_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccScalarNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccScalarNet_Convert(PyObject* ob,PyParamoaObserver_oaOccScalarNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccScalarNet_Check(ob)) {
        result->SetData( (oaObserver_oaOccScalarNet*) ((PyoaObserver_oaOccScalarNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccScalarNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccScalarNet_FromoaObserver_oaOccScalarNet(oaObserver_oaOccScalarNet* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccScalarNet_Type.tp_alloc(&PyoaObserver_oaOccScalarNet_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccScalarNetObject* self = (PyoaObserver_oaOccScalarNetObject*)bself;
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
pyv_oaObserver_oaOccScalarNet::pyv_oaObserver_oaOccScalarNet(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccScalarNet(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccScalarNet::pyv_oaObserver_oaOccScalarNet(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccScalarNet(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccScalarNet::pyv_oaObserver_oaOccScalarNet(const oaObserver_oaOccScalarNet& p)
 : pyob(NULL),
   oaObserver_oaOccScalarNet(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccScalarNet::onPostCreate(oaOccScalarNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarNet::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccScalarNet_FromoaOccScalarNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarNet::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccScalarNet::onPostModify(oaOccScalarNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarNet::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccScalarNet_FromoaOccScalarNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarNet::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccScalarNet::onPreDestroy(oaOccScalarNet* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarNet::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccScalarNet_FromoaOccScalarNet(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarNet::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccScalarNet::onPreModify(oaOccScalarNet* p1,oaNetModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarNet::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccScalarNet_FromoaOccScalarNet(p1));
    PyTuple_SetItem(args,1,PyoaNetModTypeEnum_FromoaNetModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarNet::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccScalarNet_doc[] = 
"Class: oaObserver_oaOccScalarNet\n"
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
"    Calls: oaObserver_oaOccScalarNet(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccScalarNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccScalarNet\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccScalarNet(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccScalarNet||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccScalarNet\n"
"  Paramegers: (oaObserver_oaOccScalarNet)\n"
"    Calls: (const oaObserver_oaOccScalarNet&)\n"
"    Signature: oaObserver_oaOccScalarNet||cref-oaObserver_oaOccScalarNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccScalarNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccScalarNet",
    sizeof(PyoaObserver_oaOccScalarNetObject),
    0,
    (destructor)oaObserver_oaOccScalarNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccScalarNet_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccScalarNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccScalarNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccScalarNet_oaNetModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccScalarNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccScalarNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccScalarNet_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccScalarNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccScalarNet",
           (PyObject*)(&PyoaObserver_oaOccScalarNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccScalarNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccScalarTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccScalarTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccScalarTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccScalarTermObject* self = (PyoaObserver_oaOccScalarTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccScalarTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccScalarTerm* p=new pyv_oaObserver_oaOccScalarTerm(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccScalarTerm(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccScalarTerm* p=new pyv_oaObserver_oaOccScalarTerm(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccScalarTerm)
    {
        PyParamoaObserver_oaOccScalarTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccScalarTerm_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccScalarTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccScalarTerm* p=new pyv_oaObserver_oaOccScalarTerm(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccScalarTerm, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccScalarTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccScalarTerm_tp_dealloc(PyoaObserver_oaOccScalarTermObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccScalarTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccScalarTerm_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccScalarTerm value;
    int convert_status=PyoaObserver_oaOccScalarTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaOccScalarTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccScalarTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccScalarTerm v1;
    PyParamoaObserver_oaOccScalarTerm v2;
    int convert_status1=PyoaObserver_oaOccScalarTerm_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccScalarTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccScalarTerm_Convert(PyObject* ob,PyParamoaObserver_oaOccScalarTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccScalarTerm_Check(ob)) {
        result->SetData( (oaObserver_oaOccScalarTerm*) ((PyoaObserver_oaOccScalarTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccScalarTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccScalarTerm_FromoaObserver_oaOccScalarTerm(oaObserver_oaOccScalarTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccScalarTerm_Type.tp_alloc(&PyoaObserver_oaOccScalarTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccScalarTermObject* self = (PyoaObserver_oaOccScalarTermObject*)bself;
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
pyv_oaObserver_oaOccScalarTerm::pyv_oaObserver_oaOccScalarTerm(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccScalarTerm(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccScalarTerm::pyv_oaObserver_oaOccScalarTerm(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccScalarTerm(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccScalarTerm::pyv_oaObserver_oaOccScalarTerm(const oaObserver_oaOccScalarTerm& p)
 : pyob(NULL),
   oaObserver_oaOccScalarTerm(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccScalarTerm::onPostCreate(oaOccScalarTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarTerm::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccScalarTerm_FromoaOccScalarTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarTerm::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccScalarTerm::onPostModify(oaOccScalarTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarTerm::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccScalarTerm_FromoaOccScalarTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarTerm::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccScalarTerm::onPreDestroy(oaOccScalarTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarTerm::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccScalarTerm_FromoaOccScalarTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarTerm::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccScalarTerm::onPreModify(oaOccScalarTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarTerm::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccScalarTerm_FromoaOccScalarTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccScalarTerm::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccScalarTerm_doc[] = 
"Class: oaObserver_oaOccScalarTerm\n"
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
"    Calls: oaObserver_oaOccScalarTerm(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccScalarTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccScalarTerm\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccScalarTerm(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccScalarTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccScalarTerm\n"
"  Paramegers: (oaObserver_oaOccScalarTerm)\n"
"    Calls: (const oaObserver_oaOccScalarTerm&)\n"
"    Signature: oaObserver_oaOccScalarTerm||cref-oaObserver_oaOccScalarTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccScalarTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccScalarTerm",
    sizeof(PyoaObserver_oaOccScalarTermObject),
    0,
    (destructor)oaObserver_oaOccScalarTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccScalarTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccScalarTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccScalarTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccScalarTerm_oaTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccScalarTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccScalarTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccScalarTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccScalarTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccScalarTerm",
           (PyObject*)(&PyoaObserver_oaOccScalarTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccScalarTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccTermObject* self = (PyoaObserver_oaOccTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccTerm* p=new pyv_oaObserver_oaOccTerm(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccTerm(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccTerm* p=new pyv_oaObserver_oaOccTerm(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccTerm)
    {
        PyParamoaObserver_oaOccTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccTerm_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccTerm* p=new pyv_oaObserver_oaOccTerm(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccTerm, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccTerm_tp_dealloc(PyoaObserver_oaOccTermObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccTerm_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccTerm value;
    int convert_status=PyoaObserver_oaOccTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaObserver_oaOccTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccTerm v1;
    PyParamoaObserver_oaOccTerm v2;
    int convert_status1=PyoaObserver_oaOccTerm_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccTerm_Convert(PyObject* ob,PyParamoaObserver_oaOccTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccTerm_Check(ob)) {
        result->SetData( (oaObserver_oaOccTerm*) ((PyoaObserver_oaOccTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccTerm_FromoaObserver_oaOccTerm(oaObserver_oaOccTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccTerm_Type.tp_alloc(&PyoaObserver_oaOccTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccTermObject* self = (PyoaObserver_oaOccTermObject*)bself;
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
pyv_oaObserver_oaOccTerm::pyv_oaObserver_oaOccTerm(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccTerm(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccTerm::pyv_oaObserver_oaOccTerm(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccTerm(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccTerm::pyv_oaObserver_oaOccTerm(const oaObserver_oaOccTerm& p)
 : pyob(NULL),
   oaObserver_oaOccTerm(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccTerm::onPostCreate(oaOccTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccTerm::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccTerm_FromoaOccTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccTerm::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccTerm::onPostModify(oaOccTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccTerm::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccTerm_FromoaOccTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccTerm::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccTerm::onPreDestroy(oaOccTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccTerm::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccTerm_FromoaOccTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccTerm::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccTerm::onPreModify(oaOccTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccTerm::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccTerm_FromoaOccTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccTerm::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccTerm_doc[] = 
"Class: oaObserver_oaOccTerm\n"
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
"    Calls: oaObserver_oaOccTerm(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccTerm\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccTerm(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccTerm\n"
"  Paramegers: (oaObserver_oaOccTerm)\n"
"    Calls: (const oaObserver_oaOccTerm&)\n"
"    Signature: oaObserver_oaOccTerm||cref-oaObserver_oaOccTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccTerm",
    sizeof(PyoaObserver_oaOccTermObject),
    0,
    (destructor)oaObserver_oaOccTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccTerm_oaTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccTerm",
           (PyObject*)(&PyoaObserver_oaOccTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccTermConnectDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccTermConnectDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccTermConnectDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccTermConnectDefObject* self = (PyoaObserver_oaOccTermConnectDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccTermConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccTermConnectDef* p=new pyv_oaObserver_oaOccTermConnectDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccTermConnectDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccTermConnectDef* p=new pyv_oaObserver_oaOccTermConnectDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccTermConnectDef)
    {
        PyParamoaObserver_oaOccTermConnectDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccTermConnectDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccTermConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccTermConnectDef* p=new pyv_oaObserver_oaOccTermConnectDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccTermConnectDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccTermConnectDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccTermConnectDef_tp_dealloc(PyoaObserver_oaOccTermConnectDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccTermConnectDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccTermConnectDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccTermConnectDef value;
    int convert_status=PyoaObserver_oaOccTermConnectDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaObserver_oaOccTermConnectDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccTermConnectDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccTermConnectDef v1;
    PyParamoaObserver_oaOccTermConnectDef v2;
    int convert_status1=PyoaObserver_oaOccTermConnectDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccTermConnectDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccTermConnectDef_Convert(PyObject* ob,PyParamoaObserver_oaOccTermConnectDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccTermConnectDef_Check(ob)) {
        result->SetData( (oaObserver_oaOccTermConnectDef*) ((PyoaObserver_oaOccTermConnectDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccTermConnectDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccTermConnectDef_FromoaObserver_oaOccTermConnectDef(oaObserver_oaOccTermConnectDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccTermConnectDef_Type.tp_alloc(&PyoaObserver_oaOccTermConnectDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccTermConnectDefObject* self = (PyoaObserver_oaOccTermConnectDefObject*)bself;
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
pyv_oaObserver_oaOccTermConnectDef::pyv_oaObserver_oaOccTermConnectDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccTermConnectDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccTermConnectDef::pyv_oaObserver_oaOccTermConnectDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccTermConnectDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccTermConnectDef::pyv_oaObserver_oaOccTermConnectDef(const oaObserver_oaOccTermConnectDef& p)
 : pyob(NULL),
   oaObserver_oaOccTermConnectDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccTermConnectDef::onPostCreate(oaOccTermConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccTermConnectDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccTermConnectDef_FromoaOccTermConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccTermConnectDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccTermConnectDef::onPostModify(oaOccTermConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccTermConnectDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccTermConnectDef_FromoaOccTermConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccTermConnectDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccTermConnectDef::onPreDestroy(oaOccTermConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccTermConnectDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccTermConnectDef_FromoaOccTermConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccTermConnectDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccTermConnectDef::onPreModify(oaOccTermConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccTermConnectDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccTermConnectDef_FromoaOccTermConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccTermConnectDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccTermConnectDef_doc[] = 
"Class: oaObserver_oaOccTermConnectDef\n"
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
"    Calls: oaObserver_oaOccTermConnectDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccTermConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccTermConnectDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccTermConnectDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccTermConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccTermConnectDef\n"
"  Paramegers: (oaObserver_oaOccTermConnectDef)\n"
"    Calls: (const oaObserver_oaOccTermConnectDef&)\n"
"    Signature: oaObserver_oaOccTermConnectDef||cref-oaObserver_oaOccTermConnectDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccTermConnectDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccTermConnectDef",
    sizeof(PyoaObserver_oaOccTermConnectDefObject),
    0,
    (destructor)oaObserver_oaOccTermConnectDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccTermConnectDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccTermConnectDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccTermConnectDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccTermConnectDef_oaConnectDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccTermConnectDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccTermConnectDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccTermConnectDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccTermConnectDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccTermConnectDef",
           (PyObject*)(&PyoaObserver_oaOccTermConnectDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccTermConnectDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccVectorInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccVectorInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccVectorInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccVectorInstObject* self = (PyoaObserver_oaOccVectorInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccVectorInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccVectorInst* p=new pyv_oaObserver_oaOccVectorInst(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccVectorInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccVectorInst* p=new pyv_oaObserver_oaOccVectorInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccVectorInst)
    {
        PyParamoaObserver_oaOccVectorInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccVectorInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccVectorInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccVectorInst* p=new pyv_oaObserver_oaOccVectorInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccVectorInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccVectorInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccVectorInst_tp_dealloc(PyoaObserver_oaOccVectorInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccVectorInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccVectorInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccVectorInst value;
    int convert_status=PyoaObserver_oaOccVectorInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaOccVectorInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccVectorInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccVectorInst v1;
    PyParamoaObserver_oaOccVectorInst v2;
    int convert_status1=PyoaObserver_oaOccVectorInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccVectorInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccVectorInst_Convert(PyObject* ob,PyParamoaObserver_oaOccVectorInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccVectorInst_Check(ob)) {
        result->SetData( (oaObserver_oaOccVectorInst*) ((PyoaObserver_oaOccVectorInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccVectorInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccVectorInst_FromoaObserver_oaOccVectorInst(oaObserver_oaOccVectorInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccVectorInst_Type.tp_alloc(&PyoaObserver_oaOccVectorInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccVectorInstObject* self = (PyoaObserver_oaOccVectorInstObject*)bself;
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
pyv_oaObserver_oaOccVectorInst::pyv_oaObserver_oaOccVectorInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccVectorInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccVectorInst::pyv_oaObserver_oaOccVectorInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccVectorInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccVectorInst::pyv_oaObserver_oaOccVectorInst(const oaObserver_oaOccVectorInst& p)
 : pyob(NULL),
   oaObserver_oaOccVectorInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccVectorInst::onPostCreate(oaOccVectorInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccVectorInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccVectorInst_FromoaOccVectorInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccVectorInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccVectorInst::onPostModify(oaOccVectorInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccVectorInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccVectorInst_FromoaOccVectorInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccVectorInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccVectorInst::onPreDestroy(oaOccVectorInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccVectorInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccVectorInst_FromoaOccVectorInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccVectorInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccVectorInst::onPreModify(oaOccVectorInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccVectorInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccVectorInst_FromoaOccVectorInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccVectorInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccVectorInst_doc[] = 
"Class: oaObserver_oaOccVectorInst\n"
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
"    Calls: oaObserver_oaOccVectorInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccVectorInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccVectorInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccVectorInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccVectorInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccVectorInst\n"
"  Paramegers: (oaObserver_oaOccVectorInst)\n"
"    Calls: (const oaObserver_oaOccVectorInst&)\n"
"    Signature: oaObserver_oaOccVectorInst||cref-oaObserver_oaOccVectorInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccVectorInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccVectorInst",
    sizeof(PyoaObserver_oaOccVectorInstObject),
    0,
    (destructor)oaObserver_oaOccVectorInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccVectorInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccVectorInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccVectorInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccVectorInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccVectorInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccVectorInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccVectorInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccVectorInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccVectorInst",
           (PyObject*)(&PyoaObserver_oaOccVectorInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccVectorInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaOccVectorInstBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccVectorInstBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaOccVectorInstBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaOccVectorInstBitObject* self = (PyoaObserver_oaOccVectorInstBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaOccVectorInstBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccVectorInstBit* p=new pyv_oaObserver_oaOccVectorInstBit(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaOccVectorInstBit(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaOccVectorInstBit* p=new pyv_oaObserver_oaOccVectorInstBit(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaOccVectorInstBit)
    {
        PyParamoaObserver_oaOccVectorInstBit p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaOccVectorInstBit_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaOccVectorInstBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaOccVectorInstBit* p=new pyv_oaObserver_oaOccVectorInstBit(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaOccVectorInstBit, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaOccVectorInstBit)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaOccVectorInstBit_tp_dealloc(PyoaObserver_oaOccVectorInstBitObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaOccVectorInstBit*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaOccVectorInstBit_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaOccVectorInstBit value;
    int convert_status=PyoaObserver_oaOccVectorInstBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[51];
    sprintf(buffer,"<oaObserver_oaOccVectorInstBit::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaOccVectorInstBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaOccVectorInstBit v1;
    PyParamoaObserver_oaOccVectorInstBit v2;
    int convert_status1=PyoaObserver_oaOccVectorInstBit_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaOccVectorInstBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaOccVectorInstBit_Convert(PyObject* ob,PyParamoaObserver_oaOccVectorInstBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaOccVectorInstBit_Check(ob)) {
        result->SetData( (oaObserver_oaOccVectorInstBit*) ((PyoaObserver_oaOccVectorInstBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaOccVectorInstBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaOccVectorInstBit_FromoaObserver_oaOccVectorInstBit(oaObserver_oaOccVectorInstBit* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaOccVectorInstBit_Type.tp_alloc(&PyoaObserver_oaOccVectorInstBit_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaOccVectorInstBitObject* self = (PyoaObserver_oaOccVectorInstBitObject*)bself;
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
pyv_oaObserver_oaOccVectorInstBit::pyv_oaObserver_oaOccVectorInstBit(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaOccVectorInstBit(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccVectorInstBit::pyv_oaObserver_oaOccVectorInstBit(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaOccVectorInstBit(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaOccVectorInstBit::pyv_oaObserver_oaOccVectorInstBit(const oaObserver_oaOccVectorInstBit& p)
 : pyob(NULL),
   oaObserver_oaOccVectorInstBit(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccVectorInstBit::onPostCreate(oaOccVectorInstBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccVectorInstBit::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccVectorInstBit_FromoaOccVectorInstBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccVectorInstBit::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccVectorInstBit::onPostModify(oaOccVectorInstBit* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccVectorInstBit::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccVectorInstBit_FromoaOccVectorInstBit(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccVectorInstBit::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccVectorInstBit::onPreDestroy(oaOccVectorInstBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccVectorInstBit::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaOccVectorInstBit_FromoaOccVectorInstBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccVectorInstBit::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaOccVectorInstBit::onPreModify(oaOccVectorInstBit* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaOccVectorInstBit::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaOccVectorInstBit_FromoaOccVectorInstBit(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaOccVectorInstBit::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaOccVectorInstBit_doc[] = 
"Class: oaObserver_oaOccVectorInstBit\n"
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
"    Calls: oaObserver_oaOccVectorInstBit(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaOccVectorInstBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccVectorInstBit\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaOccVectorInstBit(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaOccVectorInstBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaOccVectorInstBit\n"
"  Paramegers: (oaObserver_oaOccVectorInstBit)\n"
"    Calls: (const oaObserver_oaOccVectorInstBit&)\n"
"    Signature: oaObserver_oaOccVectorInstBit||cref-oaObserver_oaOccVectorInstBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaOccVectorInstBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaOccVectorInstBit",
    sizeof(PyoaObserver_oaOccVectorInstBitObject),
    0,
    (destructor)oaObserver_oaOccVectorInstBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaOccVectorInstBit_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaOccVectorInstBit_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaOccVectorInstBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaOccVectorInstBit_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaOccVectorInstBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaOccVectorInstBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaOccVectorInstBit_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaOccVectorInstBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaOccVectorInstBit",
           (PyObject*)(&PyoaObserver_oaOccVectorInstBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaOccVectorInstBit\n");
       return -1;
    }
    return 0;
}

