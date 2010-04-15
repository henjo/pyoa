
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaTermObject* self = (PyoaObserver_oaTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaTerm* p=new pyv_oaObserver_oaTerm(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaTerm(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaTerm* p=new pyv_oaObserver_oaTerm(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaTerm)
    {
        PyParamoaObserver_oaTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaTerm_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaTerm(p1.Data());
            }
            else {
                pyv_oaObserver_oaTerm* p=new pyv_oaObserver_oaTerm(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaTerm, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaTerm_tp_dealloc(PyoaObserver_oaTermObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaTerm*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaTerm_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaTerm value;
    int convert_status=PyoaObserver_oaTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaObserver_oaTerm::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaTerm v1;
    PyParamoaObserver_oaTerm v2;
    int convert_status1=PyoaObserver_oaTerm_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaTerm_Convert(PyObject* ob,PyParamoaObserver_oaTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaTerm_Check(ob)) {
        result->SetData( (oaObserver_oaTerm*) ((PyoaObserver_oaTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaTerm_FromoaObserver_oaTerm(oaObserver_oaTerm* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaTerm_Type.tp_alloc(&PyoaObserver_oaTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaTermObject* self = (PyoaObserver_oaTermObject*)bself;
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
pyv_oaObserver_oaTerm::pyv_oaObserver_oaTerm(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaTerm(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaTerm::pyv_oaObserver_oaTerm(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaTerm(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaTerm::pyv_oaObserver_oaTerm(const oaObserver_oaTerm& p)
 : pyob(NULL),
   oaObserver_oaTerm(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTerm::onPostCreate(oaTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTerm::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaTerm_FromoaTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTerm::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTerm::onPostModify(oaTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTerm::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaTerm_FromoaTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTerm::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTerm::onPreDestroy(oaTerm* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTerm::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaTerm_FromoaTerm(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTerm::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTerm::onPreModify(oaTerm* p1,oaTermModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTerm::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaTerm_FromoaTerm(p1));
    PyTuple_SetItem(args,1,PyoaTermModTypeEnum_FromoaTermModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTerm::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaTerm_doc[] = 
"Class: oaObserver_oaTerm\n"
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
"    Calls: oaObserver_oaTerm(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaTerm\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaTerm(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaTerm||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaTerm\n"
"  Paramegers: (oaObserver_oaTerm)\n"
"    Calls: (const oaObserver_oaTerm&)\n"
"    Signature: oaObserver_oaTerm||cref-oaObserver_oaTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaTerm",
    sizeof(PyoaObserver_oaTermObject),
    0,
    (destructor)oaObserver_oaTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaTerm_oaTermModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaTerm",
           (PyObject*)(&PyoaObserver_oaTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaTermConnectDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaTermConnectDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaTermConnectDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaTermConnectDefObject* self = (PyoaObserver_oaTermConnectDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaTermConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaTermConnectDef* p=new pyv_oaObserver_oaTermConnectDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaTermConnectDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaTermConnectDef* p=new pyv_oaObserver_oaTermConnectDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaTermConnectDef)
    {
        PyParamoaObserver_oaTermConnectDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaTermConnectDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaTermConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaTermConnectDef* p=new pyv_oaObserver_oaTermConnectDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaTermConnectDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaTermConnectDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaTermConnectDef_tp_dealloc(PyoaObserver_oaTermConnectDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaTermConnectDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaTermConnectDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaTermConnectDef value;
    int convert_status=PyoaObserver_oaTermConnectDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaObserver_oaTermConnectDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaTermConnectDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaTermConnectDef v1;
    PyParamoaObserver_oaTermConnectDef v2;
    int convert_status1=PyoaObserver_oaTermConnectDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaTermConnectDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaTermConnectDef_Convert(PyObject* ob,PyParamoaObserver_oaTermConnectDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaTermConnectDef_Check(ob)) {
        result->SetData( (oaObserver_oaTermConnectDef*) ((PyoaObserver_oaTermConnectDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaTermConnectDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaTermConnectDef_FromoaObserver_oaTermConnectDef(oaObserver_oaTermConnectDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaTermConnectDef_Type.tp_alloc(&PyoaObserver_oaTermConnectDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaTermConnectDefObject* self = (PyoaObserver_oaTermConnectDefObject*)bself;
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
pyv_oaObserver_oaTermConnectDef::pyv_oaObserver_oaTermConnectDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaTermConnectDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaTermConnectDef::pyv_oaObserver_oaTermConnectDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaTermConnectDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaTermConnectDef::pyv_oaObserver_oaTermConnectDef(const oaObserver_oaTermConnectDef& p)
 : pyob(NULL),
   oaObserver_oaTermConnectDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTermConnectDef::onPostCreate(oaTermConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTermConnectDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaTermConnectDef_FromoaTermConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTermConnectDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTermConnectDef::onPostModify(oaTermConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTermConnectDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaTermConnectDef_FromoaTermConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTermConnectDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTermConnectDef::onPreDestroy(oaTermConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTermConnectDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaTermConnectDef_FromoaTermConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTermConnectDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTermConnectDef::onPreModify(oaTermConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTermConnectDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaTermConnectDef_FromoaTermConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTermConnectDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaTermConnectDef_doc[] = 
"Class: oaObserver_oaTermConnectDef\n"
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
"    Calls: oaObserver_oaTermConnectDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaTermConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaTermConnectDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaTermConnectDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaTermConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaTermConnectDef\n"
"  Paramegers: (oaObserver_oaTermConnectDef)\n"
"    Calls: (const oaObserver_oaTermConnectDef&)\n"
"    Signature: oaObserver_oaTermConnectDef||cref-oaObserver_oaTermConnectDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaTermConnectDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaTermConnectDef",
    sizeof(PyoaObserver_oaTermConnectDefObject),
    0,
    (destructor)oaObserver_oaTermConnectDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaTermConnectDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaTermConnectDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaTermConnectDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaTermConnectDef_oaConnectDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaTermConnectDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaTermConnectDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaTermConnectDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaTermConnectDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaTermConnectDef",
           (PyObject*)(&PyoaObserver_oaTermConnectDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaTermConnectDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaText
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaText_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaText_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaTextObject* self = (PyoaObserver_oaTextObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaText(p1.Data());
            }
            else {
                pyv_oaObserver_oaText* p=new pyv_oaObserver_oaText(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaText(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaText* p=new pyv_oaObserver_oaText(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaText)
    {
        PyParamoaObserver_oaText p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaText_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaText(p1.Data());
            }
            else {
                pyv_oaObserver_oaText* p=new pyv_oaObserver_oaText(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaText, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaText)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaText_tp_dealloc(PyoaObserver_oaTextObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaText*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaText_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaText value;
    int convert_status=PyoaObserver_oaText_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaObserver_oaText::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaText_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaText v1;
    PyParamoaObserver_oaText v2;
    int convert_status1=PyoaObserver_oaText_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaText_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaText_Convert(PyObject* ob,PyParamoaObserver_oaText* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaText_Check(ob)) {
        result->SetData( (oaObserver_oaText*) ((PyoaObserver_oaTextObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaText Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaText_FromoaObserver_oaText(oaObserver_oaText* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaText_Type.tp_alloc(&PyoaObserver_oaText_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaTextObject* self = (PyoaObserver_oaTextObject*)bself;
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
pyv_oaObserver_oaText::pyv_oaObserver_oaText(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaText(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaText::pyv_oaObserver_oaText(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaText(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaText::pyv_oaObserver_oaText(const oaObserver_oaText& p)
 : pyob(NULL),
   oaObserver_oaText(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaText::onPostCreate(oaText* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaText::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaText_FromoaText(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaText::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaText::onPostModify(oaText* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaText::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaText_FromoaText(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaText::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaText::onPreDestroy(oaText* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaText::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaText_FromoaText(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaText::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaText::onPreModify(oaText* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaText::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaText_FromoaText(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaText::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaText_doc[] = 
"Class: oaObserver_oaText\n"
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
"    Calls: oaObserver_oaText(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaText||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaText\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaText(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaText||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaText\n"
"  Paramegers: (oaObserver_oaText)\n"
"    Calls: (const oaObserver_oaText&)\n"
"    Signature: oaObserver_oaText||cref-oaObserver_oaText,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaText_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaText",
    sizeof(PyoaObserver_oaTextObject),
    0,
    (destructor)oaObserver_oaText_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaText_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaText_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaText_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaText_oaShapeModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaText_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaText_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaText_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaText\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaText",
           (PyObject*)(&PyoaObserver_oaText_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaText\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaTextDisplay
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaTextDisplay_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaTextDisplay_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaTextDisplayObject* self = (PyoaObserver_oaTextDisplayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaTextDisplay(p1.Data());
            }
            else {
                pyv_oaObserver_oaTextDisplay* p=new pyv_oaObserver_oaTextDisplay(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaTextDisplay(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaTextDisplay* p=new pyv_oaObserver_oaTextDisplay(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaTextDisplay)
    {
        PyParamoaObserver_oaTextDisplay p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaTextDisplay_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaTextDisplay(p1.Data());
            }
            else {
                pyv_oaObserver_oaTextDisplay* p=new pyv_oaObserver_oaTextDisplay(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaTextDisplay, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaTextDisplay)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaTextDisplay_tp_dealloc(PyoaObserver_oaTextDisplayObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaTextDisplay*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaTextDisplay_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaTextDisplay value;
    int convert_status=PyoaObserver_oaTextDisplay_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaObserver_oaTextDisplay::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaTextDisplay_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaTextDisplay v1;
    PyParamoaObserver_oaTextDisplay v2;
    int convert_status1=PyoaObserver_oaTextDisplay_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaTextDisplay_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaTextDisplay_Convert(PyObject* ob,PyParamoaObserver_oaTextDisplay* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaTextDisplay_Check(ob)) {
        result->SetData( (oaObserver_oaTextDisplay*) ((PyoaObserver_oaTextDisplayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaTextDisplay Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaTextDisplay_FromoaObserver_oaTextDisplay(oaObserver_oaTextDisplay* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaTextDisplay_Type.tp_alloc(&PyoaObserver_oaTextDisplay_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaTextDisplayObject* self = (PyoaObserver_oaTextDisplayObject*)bself;
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
pyv_oaObserver_oaTextDisplay::pyv_oaObserver_oaTextDisplay(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaTextDisplay(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaTextDisplay::pyv_oaObserver_oaTextDisplay(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaTextDisplay(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaTextDisplay::pyv_oaObserver_oaTextDisplay(const oaObserver_oaTextDisplay& p)
 : pyob(NULL),
   oaObserver_oaTextDisplay(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTextDisplay::onPostCreate(oaTextDisplay* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTextDisplay::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaTextDisplay_FromoaTextDisplay(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTextDisplay::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTextDisplay::onPostModify(oaTextDisplay* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTextDisplay::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaTextDisplay_FromoaTextDisplay(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTextDisplay::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTextDisplay::onPreDestroy(oaTextDisplay* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTextDisplay::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaTextDisplay_FromoaTextDisplay(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTextDisplay::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTextDisplay::onPreModify(oaTextDisplay* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTextDisplay::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaTextDisplay_FromoaTextDisplay(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTextDisplay::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaTextDisplay_doc[] = 
"Class: oaObserver_oaTextDisplay\n"
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
"    Calls: oaObserver_oaTextDisplay(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaTextDisplay||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaTextDisplay\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaTextDisplay(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaTextDisplay||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaTextDisplay\n"
"  Paramegers: (oaObserver_oaTextDisplay)\n"
"    Calls: (const oaObserver_oaTextDisplay&)\n"
"    Signature: oaObserver_oaTextDisplay||cref-oaObserver_oaTextDisplay,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaTextDisplay_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaTextDisplay",
    sizeof(PyoaObserver_oaTextDisplayObject),
    0,
    (destructor)oaObserver_oaTextDisplay_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaTextDisplay_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaTextDisplay_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaTextDisplay_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaTextDisplay_oaShapeModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaTextDisplay_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaTextDisplay_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaTextDisplay_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaTextDisplay\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaTextDisplay",
           (PyObject*)(&PyoaObserver_oaTextDisplay_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaTextDisplay\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaTextOverride
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaTextOverride_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaTextOverride_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaTextOverrideObject* self = (PyoaObserver_oaTextOverrideObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaTextOverride(p1.Data());
            }
            else {
                pyv_oaObserver_oaTextOverride* p=new pyv_oaObserver_oaTextOverride(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaTextOverride(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaTextOverride* p=new pyv_oaObserver_oaTextOverride(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaTextOverride)
    {
        PyParamoaObserver_oaTextOverride p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaTextOverride_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaTextOverride(p1.Data());
            }
            else {
                pyv_oaObserver_oaTextOverride* p=new pyv_oaObserver_oaTextOverride(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaTextOverride, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaTextOverride)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaTextOverride_tp_dealloc(PyoaObserver_oaTextOverrideObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaTextOverride*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaTextOverride_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaTextOverride value;
    int convert_status=PyoaObserver_oaTextOverride_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaTextOverride::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaTextOverride_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaTextOverride v1;
    PyParamoaObserver_oaTextOverride v2;
    int convert_status1=PyoaObserver_oaTextOverride_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaTextOverride_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaTextOverride_Convert(PyObject* ob,PyParamoaObserver_oaTextOverride* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaTextOverride_Check(ob)) {
        result->SetData( (oaObserver_oaTextOverride*) ((PyoaObserver_oaTextOverrideObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaTextOverride Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaTextOverride_FromoaObserver_oaTextOverride(oaObserver_oaTextOverride* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaTextOverride_Type.tp_alloc(&PyoaObserver_oaTextOverride_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaTextOverrideObject* self = (PyoaObserver_oaTextOverrideObject*)bself;
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
pyv_oaObserver_oaTextOverride::pyv_oaObserver_oaTextOverride(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaTextOverride(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaTextOverride::pyv_oaObserver_oaTextOverride(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaTextOverride(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaTextOverride::pyv_oaObserver_oaTextOverride(const oaObserver_oaTextOverride& p)
 : pyob(NULL),
   oaObserver_oaTextOverride(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTextOverride::onPostCreate(oaTextOverride* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTextOverride::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaTextOverride_FromoaTextOverride(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTextOverride::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTextOverride::onPostModify(oaTextOverride* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTextOverride::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaTextOverride_FromoaTextOverride(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTextOverride::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTextOverride::onPreDestroy(oaTextOverride* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTextOverride::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaTextOverride_FromoaTextOverride(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTextOverride::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTextOverride::onPreModify(oaTextOverride* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTextOverride::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaTextOverride_FromoaTextOverride(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTextOverride::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaTextOverride_doc[] = 
"Class: oaObserver_oaTextOverride\n"
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
"    Calls: oaObserver_oaTextOverride(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaTextOverride||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaTextOverride\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaTextOverride(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaTextOverride||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaTextOverride\n"
"  Paramegers: (oaObserver_oaTextOverride)\n"
"    Calls: (const oaObserver_oaTextOverride&)\n"
"    Signature: oaObserver_oaTextOverride||cref-oaObserver_oaTextOverride,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaTextOverride_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaTextOverride",
    sizeof(PyoaObserver_oaTextOverrideObject),
    0,
    (destructor)oaObserver_oaTextOverride_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaTextOverride_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaTextOverride_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaTextOverride_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaTextOverride_oaShapeModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaTextOverride_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaTextOverride_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaTextOverride_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaTextOverride\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaTextOverride",
           (PyObject*)(&PyoaObserver_oaTextOverride_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaTextOverride\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaTimeProp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaTimeProp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaTimeProp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaTimePropObject* self = (PyoaObserver_oaTimePropObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaTimeProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaTimeProp* p=new pyv_oaObserver_oaTimeProp(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaTimeProp(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaTimeProp* p=new pyv_oaObserver_oaTimeProp(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaTimeProp)
    {
        PyParamoaObserver_oaTimeProp p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaTimeProp_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaTimeProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaTimeProp* p=new pyv_oaObserver_oaTimeProp(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaTimeProp, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaTimeProp)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaTimeProp_tp_dealloc(PyoaObserver_oaTimePropObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaTimeProp*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaTimeProp_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaTimeProp value;
    int convert_status=PyoaObserver_oaTimeProp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaObserver_oaTimeProp::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaTimeProp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaTimeProp v1;
    PyParamoaObserver_oaTimeProp v2;
    int convert_status1=PyoaObserver_oaTimeProp_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaTimeProp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaTimeProp_Convert(PyObject* ob,PyParamoaObserver_oaTimeProp* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaTimeProp_Check(ob)) {
        result->SetData( (oaObserver_oaTimeProp*) ((PyoaObserver_oaTimePropObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaTimeProp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaTimeProp_FromoaObserver_oaTimeProp(oaObserver_oaTimeProp* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaTimeProp_Type.tp_alloc(&PyoaObserver_oaTimeProp_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaTimePropObject* self = (PyoaObserver_oaTimePropObject*)bself;
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
pyv_oaObserver_oaTimeProp::pyv_oaObserver_oaTimeProp(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaTimeProp(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaTimeProp::pyv_oaObserver_oaTimeProp(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaTimeProp(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaTimeProp::pyv_oaObserver_oaTimeProp(const oaObserver_oaTimeProp& p)
 : pyob(NULL),
   oaObserver_oaTimeProp(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTimeProp::onPostCreate(oaTimeProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTimeProp::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaTimeProp_FromoaTimeProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTimeProp::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTimeProp::onPostModify(oaTimeProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTimeProp::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaTimeProp_FromoaTimeProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTimeProp::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTimeProp::onPreDestroy(oaTimeProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTimeProp::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaTimeProp_FromoaTimeProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTimeProp::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTimeProp::onPreModify(oaTimeProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTimeProp::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaTimeProp_FromoaTimeProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTimeProp::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaTimeProp_doc[] = 
"Class: oaObserver_oaTimeProp\n"
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
"    Calls: oaObserver_oaTimeProp(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaTimeProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaTimeProp\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaTimeProp(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaTimeProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaTimeProp\n"
"  Paramegers: (oaObserver_oaTimeProp)\n"
"    Calls: (const oaObserver_oaTimeProp&)\n"
"    Signature: oaObserver_oaTimeProp||cref-oaObserver_oaTimeProp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaTimeProp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaTimeProp",
    sizeof(PyoaObserver_oaTimePropObject),
    0,
    (destructor)oaObserver_oaTimeProp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaTimeProp_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaTimeProp_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaTimeProp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaTimeProp_oaPropModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaTimeProp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaTimeProp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaTimeProp_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaTimeProp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaTimeProp",
           (PyObject*)(&PyoaObserver_oaTimeProp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaTimeProp\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaTimeRangeProp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaTimeRangeProp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaTimeRangeProp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaTimeRangePropObject* self = (PyoaObserver_oaTimeRangePropObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaTimeRangeProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaTimeRangeProp* p=new pyv_oaObserver_oaTimeRangeProp(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaTimeRangeProp(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaTimeRangeProp* p=new pyv_oaObserver_oaTimeRangeProp(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaTimeRangeProp)
    {
        PyParamoaObserver_oaTimeRangeProp p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaTimeRangeProp_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaTimeRangeProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaTimeRangeProp* p=new pyv_oaObserver_oaTimeRangeProp(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaTimeRangeProp, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaTimeRangeProp)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaTimeRangeProp_tp_dealloc(PyoaObserver_oaTimeRangePropObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaTimeRangeProp*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaTimeRangeProp_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaTimeRangeProp value;
    int convert_status=PyoaObserver_oaTimeRangeProp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaTimeRangeProp::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaTimeRangeProp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaTimeRangeProp v1;
    PyParamoaObserver_oaTimeRangeProp v2;
    int convert_status1=PyoaObserver_oaTimeRangeProp_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaTimeRangeProp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaTimeRangeProp_Convert(PyObject* ob,PyParamoaObserver_oaTimeRangeProp* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaTimeRangeProp_Check(ob)) {
        result->SetData( (oaObserver_oaTimeRangeProp*) ((PyoaObserver_oaTimeRangePropObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaTimeRangeProp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaTimeRangeProp_FromoaObserver_oaTimeRangeProp(oaObserver_oaTimeRangeProp* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaTimeRangeProp_Type.tp_alloc(&PyoaObserver_oaTimeRangeProp_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaTimeRangePropObject* self = (PyoaObserver_oaTimeRangePropObject*)bself;
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
pyv_oaObserver_oaTimeRangeProp::pyv_oaObserver_oaTimeRangeProp(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaTimeRangeProp(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaTimeRangeProp::pyv_oaObserver_oaTimeRangeProp(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaTimeRangeProp(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaTimeRangeProp::pyv_oaObserver_oaTimeRangeProp(const oaObserver_oaTimeRangeProp& p)
 : pyob(NULL),
   oaObserver_oaTimeRangeProp(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTimeRangeProp::onPostCreate(oaTimeRangeProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTimeRangeProp::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaTimeRangeProp_FromoaTimeRangeProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTimeRangeProp::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTimeRangeProp::onPostModify(oaTimeRangeProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTimeRangeProp::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaTimeRangeProp_FromoaTimeRangeProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTimeRangeProp::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTimeRangeProp::onPreDestroy(oaTimeRangeProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTimeRangeProp::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaTimeRangeProp_FromoaTimeRangeProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTimeRangeProp::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTimeRangeProp::onPreModify(oaTimeRangeProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTimeRangeProp::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaTimeRangeProp_FromoaTimeRangeProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTimeRangeProp::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaTimeRangeProp_doc[] = 
"Class: oaObserver_oaTimeRangeProp\n"
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
"    Calls: oaObserver_oaTimeRangeProp(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaTimeRangeProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaTimeRangeProp\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaTimeRangeProp(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaTimeRangeProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaTimeRangeProp\n"
"  Paramegers: (oaObserver_oaTimeRangeProp)\n"
"    Calls: (const oaObserver_oaTimeRangeProp&)\n"
"    Signature: oaObserver_oaTimeRangeProp||cref-oaObserver_oaTimeRangeProp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaTimeRangeProp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaTimeRangeProp",
    sizeof(PyoaObserver_oaTimeRangePropObject),
    0,
    (destructor)oaObserver_oaTimeRangeProp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaTimeRangeProp_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaTimeRangeProp_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaTimeRangeProp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaTimeRangeProp_oaPropModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaTimeRangeProp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaTimeRangeProp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaTimeRangeProp_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaTimeRangeProp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaTimeRangeProp",
           (PyObject*)(&PyoaObserver_oaTimeRangeProp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaTimeRangeProp\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaTrackPattern
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaTrackPattern_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaTrackPattern_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaTrackPatternObject* self = (PyoaObserver_oaTrackPatternObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaTrackPattern(p1.Data());
            }
            else {
                pyv_oaObserver_oaTrackPattern* p=new pyv_oaObserver_oaTrackPattern(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaTrackPattern(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaTrackPattern* p=new pyv_oaObserver_oaTrackPattern(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaTrackPattern)
    {
        PyParamoaObserver_oaTrackPattern p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaTrackPattern_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaTrackPattern(p1.Data());
            }
            else {
                pyv_oaObserver_oaTrackPattern* p=new pyv_oaObserver_oaTrackPattern(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaTrackPattern, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaTrackPattern)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaTrackPattern_tp_dealloc(PyoaObserver_oaTrackPatternObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaTrackPattern*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaTrackPattern_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaTrackPattern value;
    int convert_status=PyoaObserver_oaTrackPattern_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaTrackPattern::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaTrackPattern_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaTrackPattern v1;
    PyParamoaObserver_oaTrackPattern v2;
    int convert_status1=PyoaObserver_oaTrackPattern_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaTrackPattern_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaTrackPattern_Convert(PyObject* ob,PyParamoaObserver_oaTrackPattern* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaTrackPattern_Check(ob)) {
        result->SetData( (oaObserver_oaTrackPattern*) ((PyoaObserver_oaTrackPatternObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaTrackPattern Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaTrackPattern_FromoaObserver_oaTrackPattern(oaObserver_oaTrackPattern* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaTrackPattern_Type.tp_alloc(&PyoaObserver_oaTrackPattern_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaTrackPatternObject* self = (PyoaObserver_oaTrackPatternObject*)bself;
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
pyv_oaObserver_oaTrackPattern::pyv_oaObserver_oaTrackPattern(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaTrackPattern(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaTrackPattern::pyv_oaObserver_oaTrackPattern(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaTrackPattern(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaTrackPattern::pyv_oaObserver_oaTrackPattern(const oaObserver_oaTrackPattern& p)
 : pyob(NULL),
   oaObserver_oaTrackPattern(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTrackPattern::onPostCreate(oaTrackPattern* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTrackPattern::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaTrackPattern_FromoaTrackPattern(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTrackPattern::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTrackPattern::onPostModify(oaTrackPattern* p1,oaTrackPatternModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTrackPattern::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaTrackPattern_FromoaTrackPattern(p1));
    PyTuple_SetItem(args,1,PyoaTrackPatternModTypeEnum_FromoaTrackPatternModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTrackPattern::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTrackPattern::onPreDestroy(oaTrackPattern* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTrackPattern::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaTrackPattern_FromoaTrackPattern(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTrackPattern::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaTrackPattern::onPreModify(oaTrackPattern* p1,oaTrackPatternModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaTrackPattern::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaTrackPattern_FromoaTrackPattern(p1));
    PyTuple_SetItem(args,1,PyoaTrackPatternModTypeEnum_FromoaTrackPatternModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaTrackPattern::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaTrackPattern_doc[] = 
"Class: oaObserver_oaTrackPattern\n"
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
"    Calls: oaObserver_oaTrackPattern(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaTrackPattern||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaTrackPattern\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaTrackPattern(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaTrackPattern||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaTrackPattern\n"
"  Paramegers: (oaObserver_oaTrackPattern)\n"
"    Calls: (const oaObserver_oaTrackPattern&)\n"
"    Signature: oaObserver_oaTrackPattern||cref-oaObserver_oaTrackPattern,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaTrackPattern_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaTrackPattern",
    sizeof(PyoaObserver_oaTrackPatternObject),
    0,
    (destructor)oaObserver_oaTrackPattern_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaTrackPattern_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaTrackPattern_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaTrackPattern_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaTrackPattern_oaTrackPatternModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaTrackPattern_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaTrackPattern_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaTrackPattern_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaTrackPattern\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaTrackPattern",
           (PyObject*)(&PyoaObserver_oaTrackPattern_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaTrackPattern\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaUInt8RangeValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaUInt8RangeValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaUInt8RangeValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaUInt8RangeValueObject* self = (PyoaObserver_oaUInt8RangeValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaUInt8RangeValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaUInt8RangeValue* p=new pyv_oaObserver_oaUInt8RangeValue(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaUInt8RangeValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaUInt8RangeValue* p=new pyv_oaObserver_oaUInt8RangeValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaUInt8RangeValue)
    {
        PyParamoaObserver_oaUInt8RangeValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaUInt8RangeValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaUInt8RangeValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaUInt8RangeValue* p=new pyv_oaObserver_oaUInt8RangeValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaUInt8RangeValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaUInt8RangeValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaUInt8RangeValue_tp_dealloc(PyoaObserver_oaUInt8RangeValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaUInt8RangeValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaUInt8RangeValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaUInt8RangeValue value;
    int convert_status=PyoaObserver_oaUInt8RangeValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaObserver_oaUInt8RangeValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaUInt8RangeValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaUInt8RangeValue v1;
    PyParamoaObserver_oaUInt8RangeValue v2;
    int convert_status1=PyoaObserver_oaUInt8RangeValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaUInt8RangeValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaUInt8RangeValue_Convert(PyObject* ob,PyParamoaObserver_oaUInt8RangeValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaUInt8RangeValue_Check(ob)) {
        result->SetData( (oaObserver_oaUInt8RangeValue*) ((PyoaObserver_oaUInt8RangeValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaUInt8RangeValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaUInt8RangeValue_FromoaObserver_oaUInt8RangeValue(oaObserver_oaUInt8RangeValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaUInt8RangeValue_Type.tp_alloc(&PyoaObserver_oaUInt8RangeValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaUInt8RangeValueObject* self = (PyoaObserver_oaUInt8RangeValueObject*)bself;
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
pyv_oaObserver_oaUInt8RangeValue::pyv_oaObserver_oaUInt8RangeValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaUInt8RangeValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaUInt8RangeValue::pyv_oaObserver_oaUInt8RangeValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaUInt8RangeValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaUInt8RangeValue::pyv_oaObserver_oaUInt8RangeValue(const oaObserver_oaUInt8RangeValue& p)
 : pyob(NULL),
   oaObserver_oaUInt8RangeValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaUInt8RangeValue::onPostCreate(oaUInt8RangeValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaUInt8RangeValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaUInt8RangeValue_FromoaUInt8RangeValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaUInt8RangeValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaUInt8RangeValue::onPostModify(oaUInt8RangeValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaUInt8RangeValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaUInt8RangeValue_FromoaUInt8RangeValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaUInt8RangeValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaUInt8RangeValue::onPreDestroy(oaUInt8RangeValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaUInt8RangeValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaUInt8RangeValue_FromoaUInt8RangeValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaUInt8RangeValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaUInt8RangeValue::onPreModify(oaUInt8RangeValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaUInt8RangeValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaUInt8RangeValue_FromoaUInt8RangeValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaUInt8RangeValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaUInt8RangeValue_doc[] = 
"Class: oaObserver_oaUInt8RangeValue\n"
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
"    Calls: oaObserver_oaUInt8RangeValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaUInt8RangeValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaUInt8RangeValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaUInt8RangeValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaUInt8RangeValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaUInt8RangeValue\n"
"  Paramegers: (oaObserver_oaUInt8RangeValue)\n"
"    Calls: (const oaObserver_oaUInt8RangeValue&)\n"
"    Signature: oaObserver_oaUInt8RangeValue||cref-oaObserver_oaUInt8RangeValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaUInt8RangeValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaUInt8RangeValue",
    sizeof(PyoaObserver_oaUInt8RangeValueObject),
    0,
    (destructor)oaObserver_oaUInt8RangeValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaUInt8RangeValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaUInt8RangeValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaUInt8RangeValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaUInt8RangeValue_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaUInt8RangeValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaUInt8RangeValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaUInt8RangeValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaUInt8RangeValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaUInt8RangeValue",
           (PyObject*)(&PyoaObserver_oaUInt8RangeValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaUInt8RangeValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaUInt8Value
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaUInt8Value_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaUInt8Value_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaUInt8ValueObject* self = (PyoaObserver_oaUInt8ValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaUInt8Value(p1.Data());
            }
            else {
                pyv_oaObserver_oaUInt8Value* p=new pyv_oaObserver_oaUInt8Value(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaUInt8Value(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaUInt8Value* p=new pyv_oaObserver_oaUInt8Value(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaUInt8Value)
    {
        PyParamoaObserver_oaUInt8Value p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaUInt8Value_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaUInt8Value(p1.Data());
            }
            else {
                pyv_oaObserver_oaUInt8Value* p=new pyv_oaObserver_oaUInt8Value(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaUInt8Value, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaUInt8Value)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaUInt8Value_tp_dealloc(PyoaObserver_oaUInt8ValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaUInt8Value*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaUInt8Value_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaUInt8Value value;
    int convert_status=PyoaObserver_oaUInt8Value_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaUInt8Value::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaUInt8Value_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaUInt8Value v1;
    PyParamoaObserver_oaUInt8Value v2;
    int convert_status1=PyoaObserver_oaUInt8Value_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaUInt8Value_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaUInt8Value_Convert(PyObject* ob,PyParamoaObserver_oaUInt8Value* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaUInt8Value_Check(ob)) {
        result->SetData( (oaObserver_oaUInt8Value*) ((PyoaObserver_oaUInt8ValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaUInt8Value Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaUInt8Value_FromoaObserver_oaUInt8Value(oaObserver_oaUInt8Value* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaUInt8Value_Type.tp_alloc(&PyoaObserver_oaUInt8Value_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaUInt8ValueObject* self = (PyoaObserver_oaUInt8ValueObject*)bself;
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
pyv_oaObserver_oaUInt8Value::pyv_oaObserver_oaUInt8Value(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaUInt8Value(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaUInt8Value::pyv_oaObserver_oaUInt8Value(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaUInt8Value(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaUInt8Value::pyv_oaObserver_oaUInt8Value(const oaObserver_oaUInt8Value& p)
 : pyob(NULL),
   oaObserver_oaUInt8Value(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaUInt8Value::onPostCreate(oaUInt8Value* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaUInt8Value::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaUInt8Value_FromoaUInt8Value(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaUInt8Value::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaUInt8Value::onPostModify(oaUInt8Value* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaUInt8Value::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaUInt8Value_FromoaUInt8Value(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaUInt8Value::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaUInt8Value::onPreDestroy(oaUInt8Value* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaUInt8Value::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaUInt8Value_FromoaUInt8Value(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaUInt8Value::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaUInt8Value::onPreModify(oaUInt8Value* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaUInt8Value::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaUInt8Value_FromoaUInt8Value(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaUInt8Value::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaUInt8Value_doc[] = 
"Class: oaObserver_oaUInt8Value\n"
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
"    Calls: oaObserver_oaUInt8Value(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaUInt8Value||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaUInt8Value\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaUInt8Value(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaUInt8Value||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaUInt8Value\n"
"  Paramegers: (oaObserver_oaUInt8Value)\n"
"    Calls: (const oaObserver_oaUInt8Value&)\n"
"    Signature: oaObserver_oaUInt8Value||cref-oaObserver_oaUInt8Value,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaUInt8Value_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaUInt8Value",
    sizeof(PyoaObserver_oaUInt8ValueObject),
    0,
    (destructor)oaObserver_oaUInt8Value_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaUInt8Value_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaUInt8Value_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaUInt8Value_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaUInt8Value_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaUInt8Value_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaUInt8Value_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaUInt8Value_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaUInt8Value\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaUInt8Value",
           (PyObject*)(&PyoaObserver_oaUInt8Value_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaUInt8Value\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaValueObject* self = (PyoaObserver_oaValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaValue* p=new pyv_oaObserver_oaValue(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaValue* p=new pyv_oaObserver_oaValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaValue)
    {
        PyParamoaObserver_oaValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaValue* p=new pyv_oaObserver_oaValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaValue_tp_dealloc(PyoaObserver_oaValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaValue value;
    int convert_status=PyoaObserver_oaValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaObserver_oaValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaValue v1;
    PyParamoaObserver_oaValue v2;
    int convert_status1=PyoaObserver_oaValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaValue_Convert(PyObject* ob,PyParamoaObserver_oaValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaValue_Check(ob)) {
        result->SetData( (oaObserver_oaValue*) ((PyoaObserver_oaValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaValue_FromoaObserver_oaValue(oaObserver_oaValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaValue_Type.tp_alloc(&PyoaObserver_oaValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaValueObject* self = (PyoaObserver_oaValueObject*)bself;
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
pyv_oaObserver_oaValue::pyv_oaObserver_oaValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaValue::pyv_oaObserver_oaValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaValue::pyv_oaObserver_oaValue(const oaObserver_oaValue& p)
 : pyob(NULL),
   oaObserver_oaValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaValue::onPostCreate(oaValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaValue_FromoaValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaValue::onPostModify(oaValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaValue_FromoaValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaValue::onPreDestroy(oaValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaValue_FromoaValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaValue::onPreModify(oaValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaValue_FromoaValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaValue_doc[] = 
"Class: oaObserver_oaValue\n"
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
"    Calls: oaObserver_oaValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaValue\n"
"  Paramegers: (oaObserver_oaValue)\n"
"    Calls: (const oaObserver_oaValue&)\n"
"    Signature: oaObserver_oaValue||cref-oaObserver_oaValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaValue",
    sizeof(PyoaObserver_oaValueObject),
    0,
    (destructor)oaObserver_oaValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaValue_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaValue",
           (PyObject*)(&PyoaObserver_oaValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaValueArrayValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaValueArrayValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaValueArrayValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaValueArrayValueObject* self = (PyoaObserver_oaValueArrayValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaValueArrayValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaValueArrayValue* p=new pyv_oaObserver_oaValueArrayValue(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaValueArrayValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaValueArrayValue* p=new pyv_oaObserver_oaValueArrayValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaValueArrayValue)
    {
        PyParamoaObserver_oaValueArrayValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaValueArrayValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaValueArrayValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaValueArrayValue* p=new pyv_oaObserver_oaValueArrayValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaValueArrayValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaValueArrayValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaValueArrayValue_tp_dealloc(PyoaObserver_oaValueArrayValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaValueArrayValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaValueArrayValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaValueArrayValue value;
    int convert_status=PyoaObserver_oaValueArrayValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaObserver_oaValueArrayValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaValueArrayValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaValueArrayValue v1;
    PyParamoaObserver_oaValueArrayValue v2;
    int convert_status1=PyoaObserver_oaValueArrayValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaValueArrayValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaValueArrayValue_Convert(PyObject* ob,PyParamoaObserver_oaValueArrayValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaValueArrayValue_Check(ob)) {
        result->SetData( (oaObserver_oaValueArrayValue*) ((PyoaObserver_oaValueArrayValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaValueArrayValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaValueArrayValue_FromoaObserver_oaValueArrayValue(oaObserver_oaValueArrayValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaValueArrayValue_Type.tp_alloc(&PyoaObserver_oaValueArrayValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaValueArrayValueObject* self = (PyoaObserver_oaValueArrayValueObject*)bself;
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
pyv_oaObserver_oaValueArrayValue::pyv_oaObserver_oaValueArrayValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaValueArrayValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaValueArrayValue::pyv_oaObserver_oaValueArrayValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaValueArrayValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaValueArrayValue::pyv_oaObserver_oaValueArrayValue(const oaObserver_oaValueArrayValue& p)
 : pyob(NULL),
   oaObserver_oaValueArrayValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaValueArrayValue::onPostCreate(oaValueArrayValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaValueArrayValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaValueArrayValue_FromoaValueArrayValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaValueArrayValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaValueArrayValue::onPostModify(oaValueArrayValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaValueArrayValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaValueArrayValue_FromoaValueArrayValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaValueArrayValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaValueArrayValue::onPreDestroy(oaValueArrayValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaValueArrayValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaValueArrayValue_FromoaValueArrayValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaValueArrayValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaValueArrayValue::onPreModify(oaValueArrayValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaValueArrayValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaValueArrayValue_FromoaValueArrayValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaValueArrayValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaValueArrayValue_doc[] = 
"Class: oaObserver_oaValueArrayValue\n"
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
"    Calls: oaObserver_oaValueArrayValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaValueArrayValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaValueArrayValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaValueArrayValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaValueArrayValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaValueArrayValue\n"
"  Paramegers: (oaObserver_oaValueArrayValue)\n"
"    Calls: (const oaObserver_oaValueArrayValue&)\n"
"    Signature: oaObserver_oaValueArrayValue||cref-oaObserver_oaValueArrayValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaValueArrayValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaValueArrayValue",
    sizeof(PyoaObserver_oaValueArrayValueObject),
    0,
    (destructor)oaObserver_oaValueArrayValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaValueArrayValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaValueArrayValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaValueArrayValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaValueArrayValue_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaValueArrayValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaValueArrayValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaValueArrayValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaValueArrayValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaValueArrayValue",
           (PyObject*)(&PyoaObserver_oaValueArrayValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaValueArrayValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaVectorInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaVectorInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaVectorInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaVectorInstObject* self = (PyoaObserver_oaVectorInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaVectorInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaVectorInst* p=new pyv_oaObserver_oaVectorInst(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaVectorInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaVectorInst* p=new pyv_oaObserver_oaVectorInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaVectorInst)
    {
        PyParamoaObserver_oaVectorInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaVectorInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaVectorInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaVectorInst* p=new pyv_oaObserver_oaVectorInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaVectorInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaVectorInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaVectorInst_tp_dealloc(PyoaObserver_oaVectorInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaVectorInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaVectorInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaVectorInst value;
    int convert_status=PyoaObserver_oaVectorInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaVectorInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaVectorInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaVectorInst v1;
    PyParamoaObserver_oaVectorInst v2;
    int convert_status1=PyoaObserver_oaVectorInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaVectorInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaVectorInst_Convert(PyObject* ob,PyParamoaObserver_oaVectorInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaVectorInst_Check(ob)) {
        result->SetData( (oaObserver_oaVectorInst*) ((PyoaObserver_oaVectorInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaVectorInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaVectorInst_FromoaObserver_oaVectorInst(oaObserver_oaVectorInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaVectorInst_Type.tp_alloc(&PyoaObserver_oaVectorInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaVectorInstObject* self = (PyoaObserver_oaVectorInstObject*)bself;
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
pyv_oaObserver_oaVectorInst::pyv_oaObserver_oaVectorInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaVectorInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaVectorInst::pyv_oaObserver_oaVectorInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaVectorInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaVectorInst::pyv_oaObserver_oaVectorInst(const oaObserver_oaVectorInst& p)
 : pyob(NULL),
   oaObserver_oaVectorInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaVectorInst::onPostCreate(oaVectorInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaVectorInst_FromoaVectorInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaVectorInst::onPostModify(oaVectorInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaVectorInst_FromoaVectorInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaVectorInst::onPreDestroy(oaVectorInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaVectorInst_FromoaVectorInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaVectorInst::onPreModify(oaVectorInst* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaVectorInst_FromoaVectorInst(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaVectorInst_doc[] = 
"Class: oaObserver_oaVectorInst\n"
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
"    Calls: oaObserver_oaVectorInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaVectorInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaVectorInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaVectorInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaVectorInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaVectorInst\n"
"  Paramegers: (oaObserver_oaVectorInst)\n"
"    Calls: (const oaObserver_oaVectorInst&)\n"
"    Signature: oaObserver_oaVectorInst||cref-oaObserver_oaVectorInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaVectorInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaVectorInst",
    sizeof(PyoaObserver_oaVectorInstObject),
    0,
    (destructor)oaObserver_oaVectorInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaVectorInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaVectorInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaVectorInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaVectorInst_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaVectorInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaVectorInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaVectorInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaVectorInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaVectorInst",
           (PyObject*)(&PyoaObserver_oaVectorInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaVectorInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaVectorInstBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaVectorInstBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaVectorInstBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaVectorInstBitObject* self = (PyoaObserver_oaVectorInstBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaVectorInstBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaVectorInstBit* p=new pyv_oaObserver_oaVectorInstBit(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaVectorInstBit(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaVectorInstBit* p=new pyv_oaObserver_oaVectorInstBit(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaVectorInstBit)
    {
        PyParamoaObserver_oaVectorInstBit p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaVectorInstBit_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaVectorInstBit(p1.Data());
            }
            else {
                pyv_oaObserver_oaVectorInstBit* p=new pyv_oaObserver_oaVectorInstBit(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaVectorInstBit, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaVectorInstBit)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaVectorInstBit_tp_dealloc(PyoaObserver_oaVectorInstBitObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaVectorInstBit*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaVectorInstBit_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaVectorInstBit value;
    int convert_status=PyoaObserver_oaVectorInstBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaVectorInstBit::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaVectorInstBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaVectorInstBit v1;
    PyParamoaObserver_oaVectorInstBit v2;
    int convert_status1=PyoaObserver_oaVectorInstBit_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaVectorInstBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaVectorInstBit_Convert(PyObject* ob,PyParamoaObserver_oaVectorInstBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaVectorInstBit_Check(ob)) {
        result->SetData( (oaObserver_oaVectorInstBit*) ((PyoaObserver_oaVectorInstBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaVectorInstBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaVectorInstBit_FromoaObserver_oaVectorInstBit(oaObserver_oaVectorInstBit* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaVectorInstBit_Type.tp_alloc(&PyoaObserver_oaVectorInstBit_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaVectorInstBitObject* self = (PyoaObserver_oaVectorInstBitObject*)bself;
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
pyv_oaObserver_oaVectorInstBit::pyv_oaObserver_oaVectorInstBit(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaVectorInstBit(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaVectorInstBit::pyv_oaObserver_oaVectorInstBit(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaVectorInstBit(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaVectorInstBit::pyv_oaObserver_oaVectorInstBit(const oaObserver_oaVectorInstBit& p)
 : pyob(NULL),
   oaObserver_oaVectorInstBit(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaVectorInstBit::onPostCreate(oaVectorInstBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInstBit::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaVectorInstBit_FromoaVectorInstBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInstBit::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaVectorInstBit::onPostModify(oaVectorInstBit* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInstBit::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaVectorInstBit_FromoaVectorInstBit(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInstBit::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaVectorInstBit::onPreDestroy(oaVectorInstBit* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInstBit::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaVectorInstBit_FromoaVectorInstBit(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInstBit::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaVectorInstBit::onPreModify(oaVectorInstBit* p1,oaInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInstBit::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaVectorInstBit_FromoaVectorInstBit(p1));
    PyTuple_SetItem(args,1,PyoaInstModTypeEnum_FromoaInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInstBit::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaVectorInstBit_doc[] = 
"Class: oaObserver_oaVectorInstBit\n"
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
"    Calls: oaObserver_oaVectorInstBit(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaVectorInstBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaVectorInstBit\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaVectorInstBit(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaVectorInstBit||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaVectorInstBit\n"
"  Paramegers: (oaObserver_oaVectorInstBit)\n"
"    Calls: (const oaObserver_oaVectorInstBit&)\n"
"    Signature: oaObserver_oaVectorInstBit||cref-oaObserver_oaVectorInstBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaVectorInstBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaVectorInstBit",
    sizeof(PyoaObserver_oaVectorInstBitObject),
    0,
    (destructor)oaObserver_oaVectorInstBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaVectorInstBit_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaVectorInstBit_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaVectorInstBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaVectorInstBit_oaInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaVectorInstBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaVectorInstBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaVectorInstBit_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaVectorInstBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaVectorInstBit",
           (PyObject*)(&PyoaObserver_oaVectorInstBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaVectorInstBit\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaVectorInstDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaVectorInstDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaVectorInstDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaVectorInstDefObject* self = (PyoaObserver_oaVectorInstDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaVectorInstDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaVectorInstDef* p=new pyv_oaObserver_oaVectorInstDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaVectorInstDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaVectorInstDef* p=new pyv_oaObserver_oaVectorInstDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaVectorInstDef)
    {
        PyParamoaObserver_oaVectorInstDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaVectorInstDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaVectorInstDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaVectorInstDef* p=new pyv_oaObserver_oaVectorInstDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaVectorInstDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaVectorInstDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaVectorInstDef_tp_dealloc(PyoaObserver_oaVectorInstDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaVectorInstDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaVectorInstDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaVectorInstDef value;
    int convert_status=PyoaObserver_oaVectorInstDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaVectorInstDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaVectorInstDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaVectorInstDef v1;
    PyParamoaObserver_oaVectorInstDef v2;
    int convert_status1=PyoaObserver_oaVectorInstDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaVectorInstDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaVectorInstDef_Convert(PyObject* ob,PyParamoaObserver_oaVectorInstDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaVectorInstDef_Check(ob)) {
        result->SetData( (oaObserver_oaVectorInstDef*) ((PyoaObserver_oaVectorInstDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaVectorInstDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaVectorInstDef_FromoaObserver_oaVectorInstDef(oaObserver_oaVectorInstDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaVectorInstDef_Type.tp_alloc(&PyoaObserver_oaVectorInstDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaVectorInstDefObject* self = (PyoaObserver_oaVectorInstDefObject*)bself;
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
pyv_oaObserver_oaVectorInstDef::pyv_oaObserver_oaVectorInstDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaVectorInstDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaVectorInstDef::pyv_oaObserver_oaVectorInstDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaVectorInstDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaVectorInstDef::pyv_oaObserver_oaVectorInstDef(const oaObserver_oaVectorInstDef& p)
 : pyob(NULL),
   oaObserver_oaVectorInstDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaVectorInstDef::onPostCreate(oaVectorInstDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInstDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaVectorInstDef_FromoaVectorInstDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInstDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaVectorInstDef::onPostModify(oaVectorInstDef* p1,oaVectorInstDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInstDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaVectorInstDef_FromoaVectorInstDef(p1));
    PyTuple_SetItem(args,1,PyoaVectorInstDefModTypeEnum_FromoaVectorInstDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInstDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaVectorInstDef::onPreDestroy(oaVectorInstDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInstDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaVectorInstDef_FromoaVectorInstDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInstDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaVectorInstDef::onPreModify(oaVectorInstDef* p1,oaVectorInstDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInstDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaVectorInstDef_FromoaVectorInstDef(p1));
    PyTuple_SetItem(args,1,PyoaVectorInstDefModTypeEnum_FromoaVectorInstDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaVectorInstDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaVectorInstDef_doc[] = 
"Class: oaObserver_oaVectorInstDef\n"
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
"    Calls: oaObserver_oaVectorInstDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaVectorInstDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaVectorInstDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaVectorInstDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaVectorInstDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaVectorInstDef\n"
"  Paramegers: (oaObserver_oaVectorInstDef)\n"
"    Calls: (const oaObserver_oaVectorInstDef&)\n"
"    Signature: oaObserver_oaVectorInstDef||cref-oaObserver_oaVectorInstDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaVectorInstDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaVectorInstDef",
    sizeof(PyoaObserver_oaVectorInstDefObject),
    0,
    (destructor)oaObserver_oaVectorInstDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaVectorInstDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaVectorInstDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaVectorInstDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaVectorInstDef_oaVectorInstDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaVectorInstDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaVectorInstDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaVectorInstDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaVectorInstDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaVectorInstDef",
           (PyObject*)(&PyoaObserver_oaVectorInstDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaVectorInstDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaVia
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaVia_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaVia_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaViaObject* self = (PyoaObserver_oaViaObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaVia(p1.Data());
            }
            else {
                pyv_oaObserver_oaVia* p=new pyv_oaObserver_oaVia(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaVia(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaVia* p=new pyv_oaObserver_oaVia(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaVia)
    {
        PyParamoaObserver_oaVia p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaVia_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaVia(p1.Data());
            }
            else {
                pyv_oaObserver_oaVia* p=new pyv_oaObserver_oaVia(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaVia, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaVia)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaVia_tp_dealloc(PyoaObserver_oaViaObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaVia*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaVia_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaVia value;
    int convert_status=PyoaObserver_oaVia_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaObserver_oaVia::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaVia_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaVia v1;
    PyParamoaObserver_oaVia v2;
    int convert_status1=PyoaObserver_oaVia_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaVia_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaVia_Convert(PyObject* ob,PyParamoaObserver_oaVia* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaVia_Check(ob)) {
        result->SetData( (oaObserver_oaVia*) ((PyoaObserver_oaViaObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaVia Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaVia_FromoaObserver_oaVia(oaObserver_oaVia* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaVia_Type.tp_alloc(&PyoaObserver_oaVia_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaViaObject* self = (PyoaObserver_oaViaObject*)bself;
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
pyv_oaObserver_oaVia::pyv_oaObserver_oaVia(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaVia(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaVia::pyv_oaObserver_oaVia(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaVia(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaVia::pyv_oaObserver_oaVia(const oaObserver_oaVia& p)
 : pyob(NULL),
   oaObserver_oaVia(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaVia::onPostCreate(oaVia* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaVia::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaVia_FromoaVia(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaVia::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaVia::onPostModify(oaVia* p1,oaViaModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaVia::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaVia_FromoaVia(p1));
    PyTuple_SetItem(args,1,PyoaViaModTypeEnum_FromoaViaModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaVia::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaVia::onPreDestroy(oaVia* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaVia::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaVia_FromoaVia(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaVia::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaVia::onPreModify(oaVia* p1,oaViaModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaVia::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaVia_FromoaVia(p1));
    PyTuple_SetItem(args,1,PyoaViaModTypeEnum_FromoaViaModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaVia::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaVia_doc[] = 
"Class: oaObserver_oaVia\n"
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
"    Calls: oaObserver_oaVia(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaVia||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaVia\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaVia(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaVia||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaVia\n"
"  Paramegers: (oaObserver_oaVia)\n"
"    Calls: (const oaObserver_oaVia&)\n"
"    Signature: oaObserver_oaVia||cref-oaObserver_oaVia,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaVia_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaVia",
    sizeof(PyoaObserver_oaViaObject),
    0,
    (destructor)oaObserver_oaVia_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaVia_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaVia_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaVia_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaVia_oaViaModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaVia_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaVia_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaVia_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaVia\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaVia",
           (PyObject*)(&PyoaObserver_oaVia_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaVia\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaViaDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaViaDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaViaDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaViaDefObject* self = (PyoaObserver_oaViaDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaViaDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaViaDef* p=new pyv_oaObserver_oaViaDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaViaDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaViaDef* p=new pyv_oaObserver_oaViaDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaViaDef)
    {
        PyParamoaObserver_oaViaDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaViaDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaViaDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaViaDef* p=new pyv_oaObserver_oaViaDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaViaDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaViaDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaViaDef_tp_dealloc(PyoaObserver_oaViaDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaViaDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaViaDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaViaDef value;
    int convert_status=PyoaObserver_oaViaDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaObserver_oaViaDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaViaDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaViaDef v1;
    PyParamoaObserver_oaViaDef v2;
    int convert_status1=PyoaObserver_oaViaDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaViaDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaViaDef_Convert(PyObject* ob,PyParamoaObserver_oaViaDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaViaDef_Check(ob)) {
        result->SetData( (oaObserver_oaViaDef*) ((PyoaObserver_oaViaDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaViaDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaViaDef_FromoaObserver_oaViaDef(oaObserver_oaViaDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaViaDef_Type.tp_alloc(&PyoaObserver_oaViaDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaViaDefObject* self = (PyoaObserver_oaViaDefObject*)bself;
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
pyv_oaObserver_oaViaDef::pyv_oaObserver_oaViaDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaViaDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaViaDef::pyv_oaObserver_oaViaDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaViaDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaViaDef::pyv_oaObserver_oaViaDef(const oaObserver_oaViaDef& p)
 : pyob(NULL),
   oaObserver_oaViaDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaViaDef::onPostCreate(oaViaDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaViaDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaViaDef_FromoaViaDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaViaDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaViaDef::onPostModify(oaViaDef* p1,oaViaDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaViaDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaViaDef_FromoaViaDef(p1));
    PyTuple_SetItem(args,1,PyoaViaDefModTypeEnum_FromoaViaDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaViaDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaViaDef::onPreDestroy(oaViaDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaViaDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaViaDef_FromoaViaDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaViaDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaViaDef::onPreModify(oaViaDef* p1,oaViaDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaViaDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaViaDef_FromoaViaDef(p1));
    PyTuple_SetItem(args,1,PyoaViaDefModTypeEnum_FromoaViaDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaViaDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaViaDef_doc[] = 
"Class: oaObserver_oaViaDef\n"
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
"    Calls: oaObserver_oaViaDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaViaDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaViaDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaViaDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaViaDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaViaDef\n"
"  Paramegers: (oaObserver_oaViaDef)\n"
"    Calls: (const oaObserver_oaViaDef&)\n"
"    Signature: oaObserver_oaViaDef||cref-oaObserver_oaViaDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaViaDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaViaDef",
    sizeof(PyoaObserver_oaViaDefObject),
    0,
    (destructor)oaObserver_oaViaDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaViaDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaViaDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaViaDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaViaDef_oaViaDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaViaDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaViaDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaViaDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaViaDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaViaDef",
           (PyObject*)(&PyoaObserver_oaViaDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaViaDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaViaHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaViaHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaViaHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaViaHeaderObject* self = (PyoaObserver_oaViaHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaViaHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaViaHeader* p=new pyv_oaObserver_oaViaHeader(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaViaHeader(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaViaHeader* p=new pyv_oaObserver_oaViaHeader(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaViaHeader)
    {
        PyParamoaObserver_oaViaHeader p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaViaHeader_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaViaHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaViaHeader* p=new pyv_oaObserver_oaViaHeader(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaViaHeader, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaViaHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaViaHeader_tp_dealloc(PyoaObserver_oaViaHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaViaHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaViaHeader_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaViaHeader value;
    int convert_status=PyoaObserver_oaViaHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaObserver_oaViaHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaViaHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaViaHeader v1;
    PyParamoaObserver_oaViaHeader v2;
    int convert_status1=PyoaObserver_oaViaHeader_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaViaHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaViaHeader_Convert(PyObject* ob,PyParamoaObserver_oaViaHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaViaHeader_Check(ob)) {
        result->SetData( (oaObserver_oaViaHeader*) ((PyoaObserver_oaViaHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaViaHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaViaHeader_FromoaObserver_oaViaHeader(oaObserver_oaViaHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaViaHeader_Type.tp_alloc(&PyoaObserver_oaViaHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaViaHeaderObject* self = (PyoaObserver_oaViaHeaderObject*)bself;
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
pyv_oaObserver_oaViaHeader::pyv_oaObserver_oaViaHeader(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaViaHeader(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaViaHeader::pyv_oaObserver_oaViaHeader(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaViaHeader(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaViaHeader::pyv_oaObserver_oaViaHeader(const oaObserver_oaViaHeader& p)
 : pyob(NULL),
   oaObserver_oaViaHeader(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaViaHeader::onPostCreate(oaViaHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaViaHeader::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaViaHeader_FromoaViaHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaViaHeader::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaViaHeader::onPostModify(oaViaHeader* p1,oaViaHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaViaHeader::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaViaHeader_FromoaViaHeader(p1));
    PyTuple_SetItem(args,1,PyoaViaHeaderModTypeEnum_FromoaViaHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaViaHeader::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaViaHeader::onPreDestroy(oaViaHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaViaHeader::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaViaHeader_FromoaViaHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaViaHeader::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaViaHeader::onPreModify(oaViaHeader* p1,oaViaHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaViaHeader::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaViaHeader_FromoaViaHeader(p1));
    PyTuple_SetItem(args,1,PyoaViaHeaderModTypeEnum_FromoaViaHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaViaHeader::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaViaHeader_doc[] = 
"Class: oaObserver_oaViaHeader\n"
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
"    Calls: oaObserver_oaViaHeader(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaViaHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaViaHeader\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaViaHeader(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaViaHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaViaHeader\n"
"  Paramegers: (oaObserver_oaViaHeader)\n"
"    Calls: (const oaObserver_oaViaHeader&)\n"
"    Signature: oaObserver_oaViaHeader||cref-oaObserver_oaViaHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaViaHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaViaHeader",
    sizeof(PyoaObserver_oaViaHeaderObject),
    0,
    (destructor)oaObserver_oaViaHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaViaHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaViaHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaViaHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaViaHeader_oaViaHeaderModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaViaHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaViaHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaViaHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaViaHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaViaHeader",
           (PyObject*)(&PyoaObserver_oaViaHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaViaHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaViaSpec
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaViaSpec_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaViaSpec_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaViaSpecObject* self = (PyoaObserver_oaViaSpecObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaViaSpec(p1.Data());
            }
            else {
                pyv_oaObserver_oaViaSpec* p=new pyv_oaObserver_oaViaSpec(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaViaSpec(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaViaSpec* p=new pyv_oaObserver_oaViaSpec(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaViaSpec)
    {
        PyParamoaObserver_oaViaSpec p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaViaSpec_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaViaSpec(p1.Data());
            }
            else {
                pyv_oaObserver_oaViaSpec* p=new pyv_oaObserver_oaViaSpec(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaViaSpec, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaViaSpec)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaViaSpec_tp_dealloc(PyoaObserver_oaViaSpecObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaViaSpec*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaViaSpec_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaViaSpec value;
    int convert_status=PyoaObserver_oaViaSpec_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaObserver_oaViaSpec::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaViaSpec_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaViaSpec v1;
    PyParamoaObserver_oaViaSpec v2;
    int convert_status1=PyoaObserver_oaViaSpec_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaViaSpec_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaViaSpec_Convert(PyObject* ob,PyParamoaObserver_oaViaSpec* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaViaSpec_Check(ob)) {
        result->SetData( (oaObserver_oaViaSpec*) ((PyoaObserver_oaViaSpecObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaViaSpec Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaViaSpec_FromoaObserver_oaViaSpec(oaObserver_oaViaSpec* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaViaSpec_Type.tp_alloc(&PyoaObserver_oaViaSpec_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaViaSpecObject* self = (PyoaObserver_oaViaSpecObject*)bself;
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
pyv_oaObserver_oaViaSpec::pyv_oaObserver_oaViaSpec(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaViaSpec(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaViaSpec::pyv_oaObserver_oaViaSpec(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaViaSpec(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaViaSpec::pyv_oaObserver_oaViaSpec(const oaObserver_oaViaSpec& p)
 : pyob(NULL),
   oaObserver_oaViaSpec(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaViaSpec::onPostCreate(oaViaSpec* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaViaSpec::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaViaSpec_FromoaViaSpec(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaViaSpec::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaViaSpec::onPostModify(oaViaSpec* p1,oaViaSpecModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaViaSpec::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaViaSpec_FromoaViaSpec(p1));
    PyTuple_SetItem(args,1,PyoaViaSpecModTypeEnum_FromoaViaSpecModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaViaSpec::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaViaSpec::onPreDestroy(oaViaSpec* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaViaSpec::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaViaSpec_FromoaViaSpec(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaViaSpec::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaViaSpec::onPreModify(oaViaSpec* p1,oaViaSpecModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaViaSpec::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaViaSpec_FromoaViaSpec(p1));
    PyTuple_SetItem(args,1,PyoaViaSpecModTypeEnum_FromoaViaSpecModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaViaSpec::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaViaSpec_doc[] = 
"Class: oaObserver_oaViaSpec\n"
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
"    Calls: oaObserver_oaViaSpec(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaViaSpec||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaViaSpec\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaViaSpec(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaViaSpec||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaViaSpec\n"
"  Paramegers: (oaObserver_oaViaSpec)\n"
"    Calls: (const oaObserver_oaViaSpec&)\n"
"    Signature: oaObserver_oaViaSpec||cref-oaObserver_oaViaSpec,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaViaSpec_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaViaSpec",
    sizeof(PyoaObserver_oaViaSpecObject),
    0,
    (destructor)oaObserver_oaViaSpec_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaViaSpec_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaViaSpec_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaViaSpec_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaViaSpec_oaViaSpecModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaViaSpec_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaViaSpec_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaViaSpec_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaViaSpec\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaViaSpec",
           (PyObject*)(&PyoaObserver_oaViaSpec_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaViaSpec\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaView
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaView_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaView_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaViewObject* self = (PyoaObserver_oaViewObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaView(p1.Data());
            }
            else {
                pyv_oaObserver_oaView* p=new pyv_oaObserver_oaView(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaView(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaView* p=new pyv_oaObserver_oaView(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaView)
    {
        PyParamoaObserver_oaView p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaView_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaView(p1.Data());
            }
            else {
                pyv_oaObserver_oaView* p=new pyv_oaObserver_oaView(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaView, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaView)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaView_tp_dealloc(PyoaObserver_oaViewObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaView*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaView_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaView value;
    int convert_status=PyoaObserver_oaView_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[39];
    sprintf(buffer,"<oaObserver_oaView::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaView_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaView v1;
    PyParamoaObserver_oaView v2;
    int convert_status1=PyoaObserver_oaView_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaView_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaView_Convert(PyObject* ob,PyParamoaObserver_oaView* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaView_Check(ob)) {
        result->SetData( (oaObserver_oaView*) ((PyoaObserver_oaViewObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaView Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaView_FromoaObserver_oaView(oaObserver_oaView* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaView_Type.tp_alloc(&PyoaObserver_oaView_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaViewObject* self = (PyoaObserver_oaViewObject*)bself;
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
pyv_oaObserver_oaView::pyv_oaObserver_oaView(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaView(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaView::pyv_oaObserver_oaView(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaView(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaView::pyv_oaObserver_oaView(const oaObserver_oaView& p)
 : pyob(NULL),
   oaObserver_oaView(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaView::onPostCreate(oaView* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaView::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaView_FromoaView(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaView::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaView::onPostModify(oaView* p1,oaViewModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaView::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaView_FromoaView(p1));
    PyTuple_SetItem(args,1,PyoaViewModTypeEnum_FromoaViewModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaView::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaView::onPreDestroy(oaView* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaView::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaView_FromoaView(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaView::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaView::onPreModify(oaView* p1,oaViewModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaView::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaView_FromoaView(p1));
    PyTuple_SetItem(args,1,PyoaViewModTypeEnum_FromoaViewModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaView::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaView_doc[] = 
"Class: oaObserver_oaView\n"
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
"    Calls: oaObserver_oaView(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaView||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaView\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaView(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaView||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaView\n"
"  Paramegers: (oaObserver_oaView)\n"
"    Calls: (const oaObserver_oaView&)\n"
"    Signature: oaObserver_oaView||cref-oaObserver_oaView,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaView_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaView",
    sizeof(PyoaObserver_oaViewObject),
    0,
    (destructor)oaObserver_oaView_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaView_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaView_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaView_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaView_oaViewModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaView_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaView_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaView_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaView\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaView",
           (PyObject*)(&PyoaObserver_oaView_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaView\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaViewType
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaViewType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaViewType_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaViewTypeObject* self = (PyoaObserver_oaViewTypeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaViewType(p1.Data());
            }
            else {
                pyv_oaObserver_oaViewType* p=new pyv_oaObserver_oaViewType(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaViewType(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaViewType* p=new pyv_oaObserver_oaViewType(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaViewType, Choices are:\n"
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
oaObserver_oaViewType_tp_dealloc(PyoaObserver_oaViewTypeObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaViewType*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaViewType_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaViewType value;
    int convert_status=PyoaObserver_oaViewType_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaObserver_oaViewType::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaViewType_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaViewType v1;
    PyParamoaObserver_oaViewType v2;
    int convert_status1=PyoaObserver_oaViewType_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaViewType_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaViewType_Convert(PyObject* ob,PyParamoaObserver_oaViewType* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaViewType_Check(ob)) {
        result->SetData( (oaObserver_oaViewType*) ((PyoaObserver_oaViewTypeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaViewType Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaViewType_FromoaObserver_oaViewType(oaObserver_oaViewType* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaViewType_Type.tp_alloc(&PyoaObserver_oaViewType_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaViewTypeObject* self = (PyoaObserver_oaViewTypeObject*)bself;
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
pyv_oaObserver_oaViewType::pyv_oaObserver_oaViewType(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaViewType(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaViewType::pyv_oaObserver_oaViewType(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaViewType(p1,p2)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaViewType::onPostCreate(oaViewType* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaViewType::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaViewType_FromoaViewType(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaViewType::onPostCreate had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaViewType_onPostCreate_doc[] = 
"Class: oaObserver_oaViewType, Function: onPostCreate\n"
"  Paramegers: (oaViewType)\n"
"    Calls: virtual void onPostCreate(oaViewType* viewType)\n"
"    Signature: onPostCreate|void-void|ptr-oaViewType,\n"
"    This function is called after an oaViewType object has been created. The application's derived observer class should implement this function to receive notification after an oaViewType object is created.\n"
"    viewType\n"
"    pointer to the created oaViewType object\n"
;

static PyObject*
oaObserver_oaViewType_onPostCreate(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaViewType data;
    int convert_status=PyoaObserver_oaViewType_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaViewTypeObject* self=(PyoaObserver_oaViewTypeObject*)ob;

    PyParamoaViewType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaViewType_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaViewType::onPostCreate(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaObserver_oaViewType_assign_doc[] = 
"Class: oaObserver_oaViewType, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaObserver_oaViewType_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaObserver_oaViewType data;
  int convert_status=PyoaObserver_oaViewType_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaObserver_oaViewType p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaObserver_oaViewType_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaObserver_oaViewType_methodlist[] = {
    {"onPostCreate",(PyCFunction)oaObserver_oaViewType_onPostCreate,METH_VARARGS,oaObserver_oaViewType_onPostCreate_doc},
    {"assign",(PyCFunction)oaObserver_oaViewType_tp_assign,METH_VARARGS,oaObserver_oaViewType_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaViewType_doc[] = 
"Class: oaObserver_oaViewType\n"
"  This base template class can be used to derive observers for oaViewType objects. It supports postCreate event notifications.\n"
"  See oaObserver for information on using Open Access observer template classes to derive and instantiate observers in an application.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaViewType(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaViewType||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaViewType\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaViewType(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaViewType||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaViewType\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaViewType_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaViewType",
    sizeof(PyoaObserver_oaViewTypeObject),
    0,
    (destructor)oaObserver_oaViewType_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaViewType_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaViewType_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaViewType_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaObserver_oaViewType_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseObserver_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaViewType_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaViewType_static_hasObservers_doc[] = 
"Class: oaObserver_oaViewType, Function: hasObservers\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasObservers()\n"
"    Signature: hasObservers|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if any observers for this type are active.\n"
;

static PyObject*
oaObserver_oaViewType_static_hasObservers(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (oaObserver_oaViewType::hasObservers());
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
static char oaObserver_oaViewType_static_notifyPostCreateObservers_doc[] = 
"Class: oaObserver_oaViewType, Function: notifyPostCreateObservers\n"
"  Paramegers: (oaViewType)\n"
"    Calls: void notifyPostCreateObservers(oaViewType* viewType)\n"
"    Signature: notifyPostCreateObservers|void-void|ptr-oaViewType,\n"
"    Function notifyPostCreateObservers\n"
;

static PyObject*
oaObserver_oaViewType_static_notifyPostCreateObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaViewType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaViewType_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaViewType::notifyPostCreateObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaObserver_oaViewType_staticmethodlist[] = {
    {"static_hasObservers",(PyCFunction)oaObserver_oaViewType_static_hasObservers,METH_VARARGS,oaObserver_oaViewType_static_hasObservers_doc},
    {"static_notifyPostCreateObservers",(PyCFunction)oaObserver_oaViewType_static_notifyPostCreateObservers,METH_VARARGS,oaObserver_oaViewType_static_notifyPostCreateObservers_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaViewType_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaViewType_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaViewType\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaViewType",
           (PyObject*)(&PyoaObserver_oaViewType_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaViewType\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaObserver_oaViewType_Type.tp_dict;
    for(method=oaObserver_oaViewType_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaObserver_oaWafer
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaWafer_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaWafer_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaWaferObject* self = (PyoaObserver_oaWaferObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaWafer(p1.Data());
            }
            else {
                pyv_oaObserver_oaWafer* p=new pyv_oaObserver_oaWafer(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaWafer(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaWafer* p=new pyv_oaObserver_oaWafer(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaWafer, Choices are:\n"
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
oaObserver_oaWafer_tp_dealloc(PyoaObserver_oaWaferObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaWafer*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaWafer_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaWafer value;
    int convert_status=PyoaObserver_oaWafer_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaObserver_oaWafer::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaWafer_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaWafer v1;
    PyParamoaObserver_oaWafer v2;
    int convert_status1=PyoaObserver_oaWafer_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaWafer_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaWafer_Convert(PyObject* ob,PyParamoaObserver_oaWafer* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaWafer_Check(ob)) {
        result->SetData( (oaObserver_oaWafer*) ((PyoaObserver_oaWaferObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaWafer Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaWafer_FromoaObserver_oaWafer(oaObserver_oaWafer* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaWafer_Type.tp_alloc(&PyoaObserver_oaWafer_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaWaferObject* self = (PyoaObserver_oaWaferObject*)bself;
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
pyv_oaObserver_oaWafer::pyv_oaObserver_oaWafer(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaWafer(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaWafer::pyv_oaObserver_oaWafer(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaWafer(p1,p2)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWafer::onFirstOpen(oaWafer* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onFirstOpen");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onFirstOpen was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaWafer_FromoaWafer(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onFirstOpen had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWafer::onPostModify(oaWafer* p1,oaWaferModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaWafer_FromoaWafer(p1));
    PyTuple_SetItem(args,1,PyoaWaferModTypeEnum_FromoaWaferModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWafer::onPostReopen(oaWafer* p1,oaChar p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostReopen");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPostReopen was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaWafer_FromoaWafer(p1));
    PyTuple_SetItem(args,1,PyoaChar_FromoaChar(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPostReopen had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWafer::onPostSave(oaWafer* p1,oaBoolean p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostSave");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPostSave was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaWafer_FromoaWafer(p1));
    PyTuple_SetItem(args,1,PyoaBoolean_FromoaBoolean(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPostSave had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWafer::onPostSaveAs(oaWafer* p1,const oaScalarName& p2,const oaScalarName& p3,const oaScalarName& p4,oaBoolean p5)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostSaveAs");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPostSaveAs was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(5);
    PyTuple_SetItem(args,0,PyoaWafer_FromoaWafer(p1));
    PyTuple_SetItem(args,1,PyoaScalarName_FromoaScalarName((oaScalarName*)(&p2),1));
    PyTuple_SetItem(args,2,PyoaScalarName_FromoaScalarName((oaScalarName*)(&p3),1));
    PyTuple_SetItem(args,3,PyoaScalarName_FromoaScalarName((oaScalarName*)(&p4),1));
    PyTuple_SetItem(args,4,PyoaBoolean_FromoaBoolean(p5));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPostSaveAs had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWafer::onPreModify(oaWafer* p1,oaWaferModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaWafer_FromoaWafer(p1));
    PyTuple_SetItem(args,1,PyoaWaferModTypeEnum_FromoaWaferModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPreModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWafer::onPreReopen(oaWafer* p1,oaChar p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreReopen");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPreReopen was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaWafer_FromoaWafer(p1));
    PyTuple_SetItem(args,1,PyoaChar_FromoaChar(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPreReopen had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWafer::onPreSave(oaWafer* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreSave");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPreSave was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaWafer_FromoaWafer(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPreSave had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWafer::onPreSaveAs(oaWafer* p1,const oaScalarName& p2,const oaScalarName& p3,const oaScalarName& p4)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreSaveAs");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPreSaveAs was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(4);
    PyTuple_SetItem(args,0,PyoaWafer_FromoaWafer(p1));
    PyTuple_SetItem(args,1,PyoaScalarName_FromoaScalarName((oaScalarName*)(&p2),1));
    PyTuple_SetItem(args,2,PyoaScalarName_FromoaScalarName((oaScalarName*)(&p3),1));
    PyTuple_SetItem(args,3,PyoaScalarName_FromoaScalarName((oaScalarName*)(&p4),1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPreSaveAs had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWafer::onPurge(oaWafer* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPurge");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPurge was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaWafer_FromoaWafer(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onPurge had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWafer::onTruncate(oaWafer* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onTruncate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onTruncate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaWafer_FromoaWafer(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWafer::onTruncate had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaWafer_onFirstOpen_doc[] = 
"Class: oaObserver_oaWafer, Function: onFirstOpen\n"
"  Paramegers: (oaWafer)\n"
"    Calls: virtual void onFirstOpen(oaWafer* wafer)\n"
"    Signature: onFirstOpen|void-void|ptr-oaWafer,\n"
"    This function is called when an oaWafer object is first opened. The application's derived class should implement this function to receive notification when an oaWafer object has been opened.\n"
"    wafer\n"
"    A pointer to the newly-opened oaWafer object\n"
;

static PyObject*
oaObserver_oaWafer_onFirstOpen(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaWafer data;
    int convert_status=PyoaObserver_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaWaferObject* self=(PyoaObserver_oaWaferObject*)ob;

    PyParamoaWafer p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaWafer_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaWafer::onFirstOpen(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_onPostModify_doc[] = 
"Class: oaObserver_oaWafer, Function: onPostModify\n"
"  Paramegers: (oaWafer,oaWaferModTypeEnum)\n"
"    Calls: virtual void onPostModify(oaWafer* wafer,oaWaferModTypeEnum modType)\n"
"    Signature: onPostModify|void-void|ptr-oaWafer,simple-oaWaferModTypeEnum,\n"
"    This function is called after an oaWafer object has been modified. The application's derived class should implement this function to receive notification when an oaWafer object has been modified.\n"
"    wafer\n"
"    A pointer to the modified oaWafer object\n"
"    modType\n"
"    The type of modification that was made\n"
;

static PyObject*
oaObserver_oaWafer_onPostModify(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaWafer data;
    int convert_status=PyoaObserver_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaWaferObject* self=(PyoaObserver_oaWaferObject*)ob;

    PyParamoaWafer p1;
    PyParamoaWaferModTypeEnum p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaWaferModTypeEnum_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaWafer::onPostModify(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_onPostReopen_doc[] = 
"Class: oaObserver_oaWafer, Function: onPostReopen\n"
"  Paramegers: (oaWafer,oaChar)\n"
"    Calls: virtual void onPostReopen(oaWafer* wafer,oaChar oldMode)\n"
"    Signature: onPostReopen|void-void|ptr-oaWafer,simple-oaChar,\n"
"    This function is called just after an oaWafer object is reopened using a new access mode. The application's derived class should implement this function to receive notification when an oaWafer object has been reopened in a new access mode.\n"
"    wafer\n"
"    A pointer to the oaWafer object with the mode change\n"
"    oldMode\n"
"    The mode with which the oaWafer object was previously opened\n"
;

static PyObject*
oaObserver_oaWafer_onPostReopen(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaWafer data;
    int convert_status=PyoaObserver_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaWaferObject* self=(PyoaObserver_oaWaferObject*)ob;

    PyParamoaWafer p1;
    PyParamoaChar p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaChar_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaWafer::onPostReopen(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_onPostSave_doc[] = 
"Class: oaObserver_oaWafer, Function: onPostSave\n"
"  Paramegers: (oaWafer,oaBoolean)\n"
"    Calls: virtual void onPostSave(oaWafer* wafer,oaBoolean succeeded)\n"
"    Signature: onPostSave|void-void|ptr-oaWafer,simple-oaBoolean,\n"
"    This function is called after an attempt to save an oaWafer object to disk. The application's derived class should implement this function to receive notification when a save has been attempted on an oaWafer object.\n"
"    wafer\n"
"    A pointer to the saved oaWafer object\n"
"    succeeded\n"
"    A boolean that indicates whether the save was successful\n"
;

static PyObject*
oaObserver_oaWafer_onPostSave(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaWafer data;
    int convert_status=PyoaObserver_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaWaferObject* self=(PyoaObserver_oaWaferObject*)ob;

    PyParamoaWafer p1;
    PyParamoaBoolean p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaBoolean_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaWafer::onPostSave(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_onPostSaveAs_doc[] = 
"Class: oaObserver_oaWafer, Function: onPostSaveAs\n"
"  Paramegers: (oaWafer,oaScalarName,oaScalarName,oaScalarName,oaBoolean)\n"
"    Calls: virtual void onPostSaveAs(oaWafer* wafer,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName,oaBoolean succeeded)\n"
"    Signature: onPostSaveAs|void-void|ptr-oaWafer,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,simple-oaBoolean,\n"
"    This function is called after an attempt has been made to save an oaWafer object to disk under a user-specified (usually new) library, cell and view names (through an oaWafer::saveAs call). The application's derived class should implement this function to receive notification when an attempt has been made to save an oaWafer object under user-specified library/cell/view names.\n"
"    wafer\n"
"    A pointer to the saved oaWafer object\n"
"    libName\n"
"    The library name of the saved oaWafer object\n"
"    cellName\n"
"    The cell name of the saved oaWafer object\n"
"    viewName\n"
"    The view name of the saved oaWafer object\n"
"    succeeded\n"
"    a boolean that indicates whether the save was successful\n"
;

static PyObject*
oaObserver_oaWafer_onPostSaveAs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaWafer data;
    int convert_status=PyoaObserver_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaWaferObject* self=(PyoaObserver_oaWaferObject*)ob;

    PyParamoaWafer p1;
    PyParamoaScalarName p2;
    PyParamoaScalarName p3;
    PyParamoaScalarName p4;
    PyParamoaBoolean p5;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaScalarName_Convert,&p3,
          &PyoaScalarName_Convert,&p4,
          &PyoaBoolean_Convert,&p5)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaWafer::onPostSaveAs(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_onPreModify_doc[] = 
"Class: oaObserver_oaWafer, Function: onPreModify\n"
"  Paramegers: (oaWafer,oaWaferModTypeEnum)\n"
"    Calls: virtual void onPreModify(oaWafer* wafer,oaWaferModTypeEnum modType)\n"
"    Signature: onPreModify|void-void|ptr-oaWafer,simple-oaWaferModTypeEnum,\n"
"    This function is called before an oaWafer object is modified. The application's derived class should implement this function to receive notification when an oaWafer object is about to be modified.\n"
"    wafer\n"
"    A pointer to the oaWafer object to be modified\n"
"    modType\n"
"    The type of modification to be made\n"
;

static PyObject*
oaObserver_oaWafer_onPreModify(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaWafer data;
    int convert_status=PyoaObserver_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaWaferObject* self=(PyoaObserver_oaWaferObject*)ob;

    PyParamoaWafer p1;
    PyParamoaWaferModTypeEnum p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaWaferModTypeEnum_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaWafer::onPreModify(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_onPreReopen_doc[] = 
"Class: oaObserver_oaWafer, Function: onPreReopen\n"
"  Paramegers: (oaWafer,oaChar)\n"
"    Calls: virtual void onPreReopen(oaWafer* wafer,oaChar newMode)\n"
"    Signature: onPreReopen|void-void|ptr-oaWafer,simple-oaChar,\n"
"    This function is called before an oaWafer object is reopened using a different access mode. The application's derived class should implement this function to receive notification when an oaWafer object is about to be reopened.\n"
"    wafer\n"
"    A pointer to the oaWafer object with the mode change\n"
"    newMode\n"
"    The new mode in which the oaWafer object will be reopened\n"
;

static PyObject*
oaObserver_oaWafer_onPreReopen(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaWafer data;
    int convert_status=PyoaObserver_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaWaferObject* self=(PyoaObserver_oaWaferObject*)ob;

    PyParamoaWafer p1;
    PyParamoaChar p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaChar_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaWafer::onPreReopen(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_onPreSave_doc[] = 
"Class: oaObserver_oaWafer, Function: onPreSave\n"
"  Paramegers: (oaWafer)\n"
"    Calls: virtual void onPreSave(oaWafer* wafer)\n"
"    Signature: onPreSave|void-void|ptr-oaWafer,\n"
"    This function is called just before an oaWafer object is saved to disk. The application's derived class should implement this function to receive notification when an oaWafer object is about to be saved.\n"
"    wafer\n"
"    A pointer to the oaWafer object to be saved\n"
;

static PyObject*
oaObserver_oaWafer_onPreSave(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaWafer data;
    int convert_status=PyoaObserver_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaWaferObject* self=(PyoaObserver_oaWaferObject*)ob;

    PyParamoaWafer p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaWafer_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaWafer::onPreSave(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_onPreSaveAs_doc[] = 
"Class: oaObserver_oaWafer, Function: onPreSaveAs\n"
"  Paramegers: (oaWafer,oaScalarName,oaScalarName,oaScalarName)\n"
"    Calls: virtual void onPreSaveAs(oaWafer* wafer,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName)\n"
"    Signature: onPreSaveAs|void-void|ptr-oaWafer,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,\n"
"    This function is called just before an attempt to save an oaWafer object to disk under user-specified (usually new) library, cell and view names (through an oaWafer::saveAs call). The application's derived class should implement this function to receive notification when an attempt is about to be made to save an oaWafer object under user-specified library/cell/view names.\n"
"    wafer\n"
"    A pointer to the oaWafer object about to be saved\n"
"    libName\n"
"    The library name of the oaWafer object to be saved\n"
"    cellName\n"
"    The cell name of the oaWafer object to be saved\n"
"    viewName\n"
"    The view name of the oaWafer object to be saved\n"
;

static PyObject*
oaObserver_oaWafer_onPreSaveAs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaWafer data;
    int convert_status=PyoaObserver_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaWaferObject* self=(PyoaObserver_oaWaferObject*)ob;

    PyParamoaWafer p1;
    PyParamoaScalarName p2;
    PyParamoaScalarName p3;
    PyParamoaScalarName p4;
    if (PyArg_ParseTuple(args,"O&O&O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaScalarName_Convert,&p3,
          &PyoaScalarName_Convert,&p4)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaWafer::onPreSaveAs(p1.Data(),p2.Data(),p3.Data(),p4.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_onPurge_doc[] = 
"Class: oaObserver_oaWafer, Function: onPurge\n"
"  Paramegers: (oaWafer)\n"
"    Calls: virtual void onPurge(oaWafer* wafer)\n"
"    Signature: onPurge|void-void|ptr-oaWafer,\n"
"    This function is called when an oaWafer object is about to be purged from memory. The application's derived class should implement this function to receive notification when an oaWafer object is about to be purged.\n"
"    wafer\n"
"    A pointer to the oaWafer object about to be purged\n"
;

static PyObject*
oaObserver_oaWafer_onPurge(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaWafer data;
    int convert_status=PyoaObserver_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaWaferObject* self=(PyoaObserver_oaWaferObject*)ob;

    PyParamoaWafer p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaWafer_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaWafer::onPurge(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_onTruncate_doc[] = 
"Class: oaObserver_oaWafer, Function: onTruncate\n"
"  Paramegers: (oaWafer)\n"
"    Calls: virtual void onTruncate(oaWafer* wafer)\n"
"    Signature: onTruncate|void-void|ptr-oaWafer,\n"
"    This function is called just before an oaWafer object is truncated (for example, after all its contents are removed). The application's derived class should implement this function to receive notification when an oaWafer object is about to be truncated.\n"
"    wafer\n"
"    A pointer to the oaWafer object about to be truncated\n"
;

static PyObject*
oaObserver_oaWafer_onTruncate(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaWafer data;
    int convert_status=PyoaObserver_oaWafer_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaWaferObject* self=(PyoaObserver_oaWaferObject*)ob;

    PyParamoaWafer p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaWafer_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaWafer::onTruncate(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaObserver_oaWafer_assign_doc[] = 
"Class: oaObserver_oaWafer, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaObserver_oaWafer_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaObserver_oaWafer data;
  int convert_status=PyoaObserver_oaWafer_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaObserver_oaWafer p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaObserver_oaWafer_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaObserver_oaWafer_methodlist[] = {
    {"onFirstOpen",(PyCFunction)oaObserver_oaWafer_onFirstOpen,METH_VARARGS,oaObserver_oaWafer_onFirstOpen_doc},
    {"onPostModify",(PyCFunction)oaObserver_oaWafer_onPostModify,METH_VARARGS,oaObserver_oaWafer_onPostModify_doc},
    {"onPostReopen",(PyCFunction)oaObserver_oaWafer_onPostReopen,METH_VARARGS,oaObserver_oaWafer_onPostReopen_doc},
    {"onPostSave",(PyCFunction)oaObserver_oaWafer_onPostSave,METH_VARARGS,oaObserver_oaWafer_onPostSave_doc},
    {"onPostSaveAs",(PyCFunction)oaObserver_oaWafer_onPostSaveAs,METH_VARARGS,oaObserver_oaWafer_onPostSaveAs_doc},
    {"onPreModify",(PyCFunction)oaObserver_oaWafer_onPreModify,METH_VARARGS,oaObserver_oaWafer_onPreModify_doc},
    {"onPreReopen",(PyCFunction)oaObserver_oaWafer_onPreReopen,METH_VARARGS,oaObserver_oaWafer_onPreReopen_doc},
    {"onPreSave",(PyCFunction)oaObserver_oaWafer_onPreSave,METH_VARARGS,oaObserver_oaWafer_onPreSave_doc},
    {"onPreSaveAs",(PyCFunction)oaObserver_oaWafer_onPreSaveAs,METH_VARARGS,oaObserver_oaWafer_onPreSaveAs_doc},
    {"onPurge",(PyCFunction)oaObserver_oaWafer_onPurge,METH_VARARGS,oaObserver_oaWafer_onPurge_doc},
    {"onTruncate",(PyCFunction)oaObserver_oaWafer_onTruncate,METH_VARARGS,oaObserver_oaWafer_onTruncate_doc},
    {"assign",(PyCFunction)oaObserver_oaWafer_tp_assign,METH_VARARGS,oaObserver_oaWafer_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaWafer_doc[] = 
"Class: oaObserver_oaWafer\n"
"  This base template class can be used to derive observers for oaWafer objects. It supports onFirstOpen, onPreReopen, onPostReopen, onPreModify, onPostModify, onPreSave, onPostSave, onPreSaveAs, onPostSaveAs, onPurge, and onTruncate event notifications.\n"
"  See oaObserver for information on using Open Access observer template classes to derive and instantiate observers in an application.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaWafer(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaWafer||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaWafer\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaWafer(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaWafer||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaWafer\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaWafer_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaWafer",
    sizeof(PyoaObserver_oaWaferObject),
    0,
    (destructor)oaObserver_oaWafer_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaWafer_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaWafer_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaWafer_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaObserver_oaWafer_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseObserver_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaWafer_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaWafer_static_notifyFirstOpenObservers_doc[] = 
"Class: oaObserver_oaWafer, Function: notifyFirstOpenObservers\n"
"  Paramegers: (oaWafer)\n"
"    Calls: void notifyFirstOpenObservers(oaWafer* w)\n"
"    Signature: notifyFirstOpenObservers|void-void|ptr-oaWafer,\n"
"    Function notifyFirstOpenObservers\n"
;

static PyObject*
oaObserver_oaWafer_static_notifyFirstOpenObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaWafer_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaWafer::notifyFirstOpenObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_static_notifyPostModifyObservers_doc[] = 
"Class: oaObserver_oaWafer, Function: notifyPostModifyObservers\n"
"  Paramegers: (oaWafer,oaWaferModTypeEnum)\n"
"    Calls: void notifyPostModifyObservers(oaWafer* r,oaWaferModTypeEnum mt)\n"
"    Signature: notifyPostModifyObservers|void-void|ptr-oaWafer,simple-oaWaferModTypeEnum,\n"
"    Function notifyPostModifyObservers\n"
;

static PyObject*
oaObserver_oaWafer_static_notifyPostModifyObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    PyParamoaWaferModTypeEnum p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaWaferModTypeEnum_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaWafer::notifyPostModifyObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_static_notifyPostReopenObservers_doc[] = 
"Class: oaObserver_oaWafer, Function: notifyPostReopenObservers\n"
"  Paramegers: (oaWafer,oaChar)\n"
"    Calls: void notifyPostReopenObservers(oaWafer* r,oaChar oldMode)\n"
"    Signature: notifyPostReopenObservers|void-void|ptr-oaWafer,simple-oaChar,\n"
"    Function notifyPostReopenObservers\n"
;

static PyObject*
oaObserver_oaWafer_static_notifyPostReopenObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    PyParamoaChar p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaChar_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaWafer::notifyPostReopenObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_static_notifyPostSaveAsObservers_doc[] = 
"Class: oaObserver_oaWafer, Function: notifyPostSaveAsObservers\n"
"  Paramegers: (oaWafer,oaScalarName,oaScalarName,oaScalarName,oaBoolean)\n"
"    Calls: void notifyPostSaveAsObservers(oaWafer* w,const oaScalarName& libN,const oaScalarName& cellN,const oaScalarName& viewN,oaBoolean didIt)\n"
"    Signature: notifyPostSaveAsObservers|void-void|ptr-oaWafer,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,simple-oaBoolean,\n"
"    Function notifyPostSaveAsObservers\n"
;

static PyObject*
oaObserver_oaWafer_static_notifyPostSaveAsObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    PyParamoaScalarName p2;
    PyParamoaScalarName p3;
    PyParamoaScalarName p4;
    PyParamoaBoolean p5;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaScalarName_Convert,&p3,
          &PyoaScalarName_Convert,&p4,
          &PyoaBoolean_Convert,&p5)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaWafer::notifyPostSaveAsObservers(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_static_notifyPostSaveObservers_doc[] = 
"Class: oaObserver_oaWafer, Function: notifyPostSaveObservers\n"
"  Paramegers: (oaWafer,oaBoolean)\n"
"    Calls: void notifyPostSaveObservers(oaWafer* r,oaBoolean succeeded)\n"
"    Signature: notifyPostSaveObservers|void-void|ptr-oaWafer,simple-oaBoolean,\n"
"    Function notifyPostSaveObservers\n"
;

static PyObject*
oaObserver_oaWafer_static_notifyPostSaveObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    PyParamoaBoolean p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaBoolean_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaWafer::notifyPostSaveObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_static_notifyPreModifyObservers_doc[] = 
"Class: oaObserver_oaWafer, Function: notifyPreModifyObservers\n"
"  Paramegers: (oaWafer,oaWaferModTypeEnum)\n"
"    Calls: void notifyPreModifyObservers(oaWafer* r,oaWaferModTypeEnum mt)\n"
"    Signature: notifyPreModifyObservers|void-void|ptr-oaWafer,simple-oaWaferModTypeEnum,\n"
"    Function notifyPreModifyObservers\n"
;

static PyObject*
oaObserver_oaWafer_static_notifyPreModifyObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    PyParamoaWaferModTypeEnum p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaWaferModTypeEnum_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaWafer::notifyPreModifyObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_static_notifyPreReopenObservers_doc[] = 
"Class: oaObserver_oaWafer, Function: notifyPreReopenObservers\n"
"  Paramegers: (oaWafer,oaChar)\n"
"    Calls: void notifyPreReopenObservers(oaWafer* r,oaChar newMode)\n"
"    Signature: notifyPreReopenObservers|void-void|ptr-oaWafer,simple-oaChar,\n"
"    Function notifyPreReopenObservers\n"
;

static PyObject*
oaObserver_oaWafer_static_notifyPreReopenObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    PyParamoaChar p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaChar_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaWafer::notifyPreReopenObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_static_notifyPreSaveAsObservers_doc[] = 
"Class: oaObserver_oaWafer, Function: notifyPreSaveAsObservers\n"
"  Paramegers: (oaWafer,oaScalarName,oaScalarName,oaScalarName)\n"
"    Calls: void notifyPreSaveAsObservers(oaWafer* w,const oaScalarName& libN,const oaScalarName& cellN,const oaScalarName& viewN)\n"
"    Signature: notifyPreSaveAsObservers|void-void|ptr-oaWafer,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,\n"
"    Function notifyPreSaveAsObservers\n"
;

static PyObject*
oaObserver_oaWafer_static_notifyPreSaveAsObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    PyParamoaScalarName p2;
    PyParamoaScalarName p3;
    PyParamoaScalarName p4;
    if (PyArg_ParseTuple(args,"O&O&O&O&",
          &PyoaWafer_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaScalarName_Convert,&p3,
          &PyoaScalarName_Convert,&p4)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaWafer::notifyPreSaveAsObservers(p1.Data(),p2.Data(),p3.Data(),p4.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_static_notifyPreSaveObservers_doc[] = 
"Class: oaObserver_oaWafer, Function: notifyPreSaveObservers\n"
"  Paramegers: (oaWafer)\n"
"    Calls: void notifyPreSaveObservers(oaWafer* r)\n"
"    Signature: notifyPreSaveObservers|void-void|ptr-oaWafer,\n"
"    Function notifyPreSaveObservers\n"
;

static PyObject*
oaObserver_oaWafer_static_notifyPreSaveObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaWafer_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaWafer::notifyPreSaveObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_static_notifyPurgeObservers_doc[] = 
"Class: oaObserver_oaWafer, Function: notifyPurgeObservers\n"
"  Paramegers: (oaWafer)\n"
"    Calls: void notifyPurgeObservers(oaWafer* w)\n"
"    Signature: notifyPurgeObservers|void-void|ptr-oaWafer,\n"
"    Function notifyPurgeObservers\n"
;

static PyObject*
oaObserver_oaWafer_static_notifyPurgeObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaWafer_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaWafer::notifyPurgeObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaWafer_static_notifyTruncateObservers_doc[] = 
"Class: oaObserver_oaWafer, Function: notifyTruncateObservers\n"
"  Paramegers: (oaWafer)\n"
"    Calls: void notifyTruncateObservers(oaWafer* r)\n"
"    Signature: notifyTruncateObservers|void-void|ptr-oaWafer,\n"
"    Function notifyTruncateObservers\n"
;

static PyObject*
oaObserver_oaWafer_static_notifyTruncateObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaWafer p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaWafer_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaWafer::notifyTruncateObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaObserver_oaWafer_staticmethodlist[] = {
    {"static_notifyFirstOpenObservers",(PyCFunction)oaObserver_oaWafer_static_notifyFirstOpenObservers,METH_VARARGS,oaObserver_oaWafer_static_notifyFirstOpenObservers_doc},
    {"static_notifyPostModifyObservers",(PyCFunction)oaObserver_oaWafer_static_notifyPostModifyObservers,METH_VARARGS,oaObserver_oaWafer_static_notifyPostModifyObservers_doc},
    {"static_notifyPostReopenObservers",(PyCFunction)oaObserver_oaWafer_static_notifyPostReopenObservers,METH_VARARGS,oaObserver_oaWafer_static_notifyPostReopenObservers_doc},
    {"static_notifyPostSaveAsObservers",(PyCFunction)oaObserver_oaWafer_static_notifyPostSaveAsObservers,METH_VARARGS,oaObserver_oaWafer_static_notifyPostSaveAsObservers_doc},
    {"static_notifyPostSaveObservers",(PyCFunction)oaObserver_oaWafer_static_notifyPostSaveObservers,METH_VARARGS,oaObserver_oaWafer_static_notifyPostSaveObservers_doc},
    {"static_notifyPreModifyObservers",(PyCFunction)oaObserver_oaWafer_static_notifyPreModifyObservers,METH_VARARGS,oaObserver_oaWafer_static_notifyPreModifyObservers_doc},
    {"static_notifyPreReopenObservers",(PyCFunction)oaObserver_oaWafer_static_notifyPreReopenObservers,METH_VARARGS,oaObserver_oaWafer_static_notifyPreReopenObservers_doc},
    {"static_notifyPreSaveAsObservers",(PyCFunction)oaObserver_oaWafer_static_notifyPreSaveAsObservers,METH_VARARGS,oaObserver_oaWafer_static_notifyPreSaveAsObservers_doc},
    {"static_notifyPreSaveObservers",(PyCFunction)oaObserver_oaWafer_static_notifyPreSaveObservers,METH_VARARGS,oaObserver_oaWafer_static_notifyPreSaveObservers_doc},
    {"static_notifyPurgeObservers",(PyCFunction)oaObserver_oaWafer_static_notifyPurgeObservers,METH_VARARGS,oaObserver_oaWafer_static_notifyPurgeObservers_doc},
    {"static_notifyTruncateObservers",(PyCFunction)oaObserver_oaWafer_static_notifyTruncateObservers,METH_VARARGS,oaObserver_oaWafer_static_notifyTruncateObservers_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaWafer_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaWafer_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaWafer\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaWafer",
           (PyObject*)(&PyoaObserver_oaWafer_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaWafer\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaObserver_oaWafer_Type.tp_dict;
    for(method=oaObserver_oaWafer_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaObserver_oaWaferDesc
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaWaferDesc_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaWaferDesc_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaWaferDescObject* self = (PyoaObserver_oaWaferDescObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaWaferDesc(p1.Data());
            }
            else {
                pyv_oaObserver_oaWaferDesc* p=new pyv_oaObserver_oaWaferDesc(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaWaferDesc(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaWaferDesc* p=new pyv_oaObserver_oaWaferDesc(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaWaferDesc)
    {
        PyParamoaObserver_oaWaferDesc p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaWaferDesc_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaWaferDesc(p1.Data());
            }
            else {
                pyv_oaObserver_oaWaferDesc* p=new pyv_oaObserver_oaWaferDesc(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaWaferDesc, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaWaferDesc)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaWaferDesc_tp_dealloc(PyoaObserver_oaWaferDescObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaWaferDesc*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaWaferDesc_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaWaferDesc value;
    int convert_status=PyoaObserver_oaWaferDesc_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaObserver_oaWaferDesc::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaWaferDesc_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaWaferDesc v1;
    PyParamoaObserver_oaWaferDesc v2;
    int convert_status1=PyoaObserver_oaWaferDesc_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaWaferDesc_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaWaferDesc_Convert(PyObject* ob,PyParamoaObserver_oaWaferDesc* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaWaferDesc_Check(ob)) {
        result->SetData( (oaObserver_oaWaferDesc*) ((PyoaObserver_oaWaferDescObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaWaferDesc Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaWaferDesc_FromoaObserver_oaWaferDesc(oaObserver_oaWaferDesc* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaWaferDesc_Type.tp_alloc(&PyoaObserver_oaWaferDesc_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaWaferDescObject* self = (PyoaObserver_oaWaferDescObject*)bself;
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
pyv_oaObserver_oaWaferDesc::pyv_oaObserver_oaWaferDesc(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaWaferDesc(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaWaferDesc::pyv_oaObserver_oaWaferDesc(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaWaferDesc(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaWaferDesc::pyv_oaObserver_oaWaferDesc(const oaObserver_oaWaferDesc& p)
 : pyob(NULL),
   oaObserver_oaWaferDesc(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWaferDesc::onPostCreate(oaWaferDesc* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWaferDesc::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaWaferDesc_FromoaWaferDesc(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWaferDesc::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWaferDesc::onPostModify(oaWaferDesc* p1,oaWaferDescModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWaferDesc::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaWaferDesc_FromoaWaferDesc(p1));
    PyTuple_SetItem(args,1,PyoaWaferDescModTypeEnum_FromoaWaferDescModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWaferDesc::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWaferDesc::onPreDestroy(oaWaferDesc* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWaferDesc::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaWaferDesc_FromoaWaferDesc(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWaferDesc::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWaferDesc::onPreModify(oaWaferDesc* p1,oaWaferDescModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWaferDesc::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaWaferDesc_FromoaWaferDesc(p1));
    PyTuple_SetItem(args,1,PyoaWaferDescModTypeEnum_FromoaWaferDescModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWaferDesc::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaWaferDesc_doc[] = 
"Class: oaObserver_oaWaferDesc\n"
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
"    Calls: oaObserver_oaWaferDesc(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaWaferDesc||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaWaferDesc\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaWaferDesc(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaWaferDesc||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaWaferDesc\n"
"  Paramegers: (oaObserver_oaWaferDesc)\n"
"    Calls: (const oaObserver_oaWaferDesc&)\n"
"    Signature: oaObserver_oaWaferDesc||cref-oaObserver_oaWaferDesc,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaWaferDesc_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaWaferDesc",
    sizeof(PyoaObserver_oaWaferDescObject),
    0,
    (destructor)oaObserver_oaWaferDesc_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaWaferDesc_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaWaferDesc_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaWaferDesc_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaWaferDesc_oaWaferDescModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaWaferDesc_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaWaferDesc_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaWaferDesc_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaWaferDesc\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaWaferDesc",
           (PyObject*)(&PyoaObserver_oaWaferDesc_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaWaferDesc\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaWaferFeature
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaWaferFeature_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaWaferFeature_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaWaferFeatureObject* self = (PyoaObserver_oaWaferFeatureObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaWaferFeature(p1.Data());
            }
            else {
                pyv_oaObserver_oaWaferFeature* p=new pyv_oaObserver_oaWaferFeature(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaWaferFeature(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaWaferFeature* p=new pyv_oaObserver_oaWaferFeature(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaWaferFeature)
    {
        PyParamoaObserver_oaWaferFeature p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaWaferFeature_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaWaferFeature(p1.Data());
            }
            else {
                pyv_oaObserver_oaWaferFeature* p=new pyv_oaObserver_oaWaferFeature(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaWaferFeature, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaWaferFeature)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaWaferFeature_tp_dealloc(PyoaObserver_oaWaferFeatureObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaWaferFeature*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaWaferFeature_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaWaferFeature value;
    int convert_status=PyoaObserver_oaWaferFeature_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaWaferFeature::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaWaferFeature_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaWaferFeature v1;
    PyParamoaObserver_oaWaferFeature v2;
    int convert_status1=PyoaObserver_oaWaferFeature_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaWaferFeature_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaWaferFeature_Convert(PyObject* ob,PyParamoaObserver_oaWaferFeature* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaWaferFeature_Check(ob)) {
        result->SetData( (oaObserver_oaWaferFeature*) ((PyoaObserver_oaWaferFeatureObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaWaferFeature Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaWaferFeature_FromoaObserver_oaWaferFeature(oaObserver_oaWaferFeature* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaWaferFeature_Type.tp_alloc(&PyoaObserver_oaWaferFeature_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaWaferFeatureObject* self = (PyoaObserver_oaWaferFeatureObject*)bself;
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
pyv_oaObserver_oaWaferFeature::pyv_oaObserver_oaWaferFeature(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaWaferFeature(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaWaferFeature::pyv_oaObserver_oaWaferFeature(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaWaferFeature(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaWaferFeature::pyv_oaObserver_oaWaferFeature(const oaObserver_oaWaferFeature& p)
 : pyob(NULL),
   oaObserver_oaWaferFeature(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWaferFeature::onPostCreate(oaWaferFeature* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWaferFeature::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaWaferFeature_FromoaWaferFeature(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWaferFeature::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWaferFeature::onPostModify(oaWaferFeature* p1,oaWaferFeatureModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWaferFeature::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaWaferFeature_FromoaWaferFeature(p1));
    PyTuple_SetItem(args,1,PyoaWaferFeatureModTypeEnum_FromoaWaferFeatureModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWaferFeature::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWaferFeature::onPreDestroy(oaWaferFeature* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWaferFeature::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaWaferFeature_FromoaWaferFeature(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWaferFeature::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaWaferFeature::onPreModify(oaWaferFeature* p1,oaWaferFeatureModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaWaferFeature::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaWaferFeature_FromoaWaferFeature(p1));
    PyTuple_SetItem(args,1,PyoaWaferFeatureModTypeEnum_FromoaWaferFeatureModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaWaferFeature::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaWaferFeature_doc[] = 
"Class: oaObserver_oaWaferFeature\n"
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
"    Calls: oaObserver_oaWaferFeature(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaWaferFeature||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaWaferFeature\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaWaferFeature(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaWaferFeature||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaWaferFeature\n"
"  Paramegers: (oaObserver_oaWaferFeature)\n"
"    Calls: (const oaObserver_oaWaferFeature&)\n"
"    Signature: oaObserver_oaWaferFeature||cref-oaObserver_oaWaferFeature,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaWaferFeature_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaWaferFeature",
    sizeof(PyoaObserver_oaWaferFeatureObject),
    0,
    (destructor)oaObserver_oaWaferFeature_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaWaferFeature_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaWaferFeature_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaWaferFeature_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaWaferFeature_oaWaferFeatureModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaWaferFeature_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaWaferFeature_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaWaferFeature_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaWaferFeature\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaWaferFeature",
           (PyObject*)(&PyoaObserver_oaWaferFeature_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaWaferFeature\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaOccArc
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccArc_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccArc_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccArcObject* self = (PyoaOccArcObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccArc)
    {
        PyParamoaOccArc p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccArc_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccArc, Choices are:\n"
        "    (oaOccArc)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccArc_tp_dealloc(PyoaOccArcObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccArc_tp_repr(PyObject *ob)
{
    PyParamoaOccArc value;
    int convert_status=PyoaOccArc_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[30];
    sprintf(buffer,"<oaOccArc::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaOccArc_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccArc v1;
    PyParamoaOccArc v2;
    int convert_status1=PyoaOccArc_Convert(ob1,&v1);
    int convert_status2=PyoaOccArc_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccArc_Convert(PyObject* ob,PyParamoaOccArc* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccArc_Check(ob)) {
        result->SetData( (oaOccArc**) ((PyoaOccArcObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccArc Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccArc_FromoaOccArc(oaOccArc** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccArc* data=*value;
        PyObject* bself = PyoaOccArc_Type.tp_alloc(&PyoaOccArc_Type,0);
        if (bself == NULL) return bself;
        PyoaOccArcObject* self = (PyoaOccArcObject*)bself;
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
PyObject* PyoaOccArc_FromoaOccArc(oaOccArc* data)
{
    if (data) {
       PyObject* bself = PyoaOccArc_Type.tp_alloc(&PyoaOccArc_Type,0);
       if (bself == NULL) return bself;
       PyoaOccArcObject* self = (PyoaOccArcObject*)bself;
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
static char oaOccArc_getEllipseBBox_doc[] = 
"Class: oaOccArc, Function: getEllipseBBox\n"
"  Paramegers: (oaBox)\n"
"    Calls: void getEllipseBBox(oaBox& bBox) const\n"
"    Signature: getEllipseBBox|void-void|ref-oaBox,\n"
"    BrowseData: 0,oaBox\n"
"    This function fills out the specified bBox with the ellipse box of this occArc.\n"
"    bBox\n"
"    Input bounding box to be filled in\n"
;

static PyObject*
oaOccArc_getEllipseBBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccArc data;
    int convert_status=PyoaOccArc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccArcObject* self=(PyoaOccArcObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBox p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBox_Convert,&p1)) {
        data.DataCall()->getEllipseBBox(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccArc_getPoints_doc[] = 
"Class: oaOccArc, Function: getPoints\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void getPoints(oaPointArray& points) const\n"
"    Signature: getPoints|void-void|ref-oaPointArray,simple-oaUInt4,\n"
"    BrowseData: 0,oaPointArray\n"
"    This function generates a line that represents the arc from which this occArc is generated, storing the result in 'points'. 'numPoints' indicates the number of points that will be used in creating the arc.\n"
"    points\n"
"    Point array to be filled in.\n"
"    numPoints\n"
"    The number of points that is used in creating the arc.\n"
"  Paramegers: (oaPointArray,oaUInt4)\n"
"    Calls: void getPoints(oaPointArray& points,oaUInt4 numSegs) const\n"
"    Signature: getPoints|void-void|ref-oaPointArray,simple-oaUInt4,\n"
"    This function generates a line that represents the arc from which this occArc is generated, storing the result in 'points'. 'numPoints' indicates the number of points that will be used in creating the arc.\n"
"    points\n"
"    Point array to be filled in.\n"
"    numPoints\n"
"    The number of points that is used in creating the arc.\n"
;

static PyObject*
oaOccArc_getPoints(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccArc data;
    int convert_status=PyoaOccArc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccArcObject* self=(PyoaOccArcObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaPointArray)
    {
        PyParamoaPointArray p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaPointArray_Convert,&p1)) {
            data.DataCall()->getPoints(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaPointArray,oaUInt4)
    {
        PyParamoaPointArray p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaPointArray_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            data.DataCall()->getPoints(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaOccArc, function: getPoints, Choices are:\n"
        "    (oaPointArray)\n"
        "    (oaPointArray,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccArc_getStartAngle_doc[] = 
"Class: oaOccArc, Function: getStartAngle\n"
"  Paramegers: ()\n"
"    Calls: oaDouble getStartAngle() const\n"
"    Signature: getStartAngle|simple-oaDouble|\n"
"    BrowseData: 1\n"
"    This function retrieves the start angle of this occArc in radians.\n"
;

static PyObject*
oaOccArc_getStartAngle(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccArc data;
    int convert_status=PyoaOccArc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccArcObject* self=(PyoaOccArcObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDouble result= (data.DataCall()->getStartAngle());
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
static char oaOccArc_getStopAngle_doc[] = 
"Class: oaOccArc, Function: getStopAngle\n"
"  Paramegers: ()\n"
"    Calls: oaDouble getStopAngle() const\n"
"    Signature: getStopAngle|simple-oaDouble|\n"
"    BrowseData: 1\n"
"    This function retrieves the stop angle of this occArc in radians.\n"
;

static PyObject*
oaOccArc_getStopAngle(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccArc data;
    int convert_status=PyoaOccArc_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccArcObject* self=(PyoaOccArcObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaDouble result= (data.DataCall()->getStopAngle());
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
static char oaOccArc_isNull_doc[] =
"Class: oaOccArc, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccArc_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccArc data;
    int convert_status=PyoaOccArc_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccArc_assign_doc[] = 
"Class: oaOccArc, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccArc_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccArc data;
  int convert_status=PyoaOccArc_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccArc p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccArc_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccArc_methodlist[] = {
    {"getEllipseBBox",(PyCFunction)oaOccArc_getEllipseBBox,METH_VARARGS,oaOccArc_getEllipseBBox_doc},
    {"getPoints",(PyCFunction)oaOccArc_getPoints,METH_VARARGS,oaOccArc_getPoints_doc},
    {"getStartAngle",(PyCFunction)oaOccArc_getStartAngle,METH_VARARGS,oaOccArc_getStartAngle_doc},
    {"getStopAngle",(PyCFunction)oaOccArc_getStopAngle,METH_VARARGS,oaOccArc_getStopAngle_doc},
    {"isNull",(PyCFunction)oaOccArc_tp_isNull,METH_VARARGS,oaOccArc_isNull_doc},
    {"assign",(PyCFunction)oaOccArc_tp_assign,METH_VARARGS,oaOccArc_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccArc_doc[] = 
"Class: oaOccArc\n"
"  The oaOccArc class implements an unique occurrence of an oaArc object in a design hierarchy.\n"
"Constructors:\n"
"  Paramegers: (oaOccArc)\n"
"    Calls: (const oaOccArc&)\n"
"    Signature: oaOccArc||cref-oaOccArc,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccArc_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccArc",
    sizeof(PyoaOccArcObject),
    0,
    (destructor)oaOccArc_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccArc_tp_compare,	/* tp_compare */
    (reprfunc)oaOccArc_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccArc_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccArc_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccShape_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccArc_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccArc_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccArc_Type)<0) {
      printf("** PyType_Ready failed for: oaOccArc\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccArc",
           (PyObject*)(&PyoaOccArc_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccArc\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaOccArrayInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccArrayInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccArrayInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccArrayInstObject* self = (PyoaOccArrayInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccArrayInst)
    {
        PyParamoaOccArrayInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccArrayInst_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccArrayInst, Choices are:\n"
        "    (oaOccArrayInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccArrayInst_tp_dealloc(PyoaOccArrayInstObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccArrayInst_tp_repr(PyObject *ob)
{
    PyParamoaOccArrayInst value;
    int convert_status=PyoaOccArrayInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaOccArrayInst::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaSimpleName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[36];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaOccArrayInst::");
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
oaOccArrayInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccArrayInst v1;
    PyParamoaOccArrayInst v2;
    int convert_status1=PyoaOccArrayInst_Convert(ob1,&v1);
    int convert_status2=PyoaOccArrayInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccArrayInst_Convert(PyObject* ob,PyParamoaOccArrayInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccArrayInst_Check(ob)) {
        result->SetData( (oaOccArrayInst**) ((PyoaOccArrayInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccArrayInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccArrayInst_FromoaOccArrayInst(oaOccArrayInst** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccArrayInst* data=*value;
        PyObject* bself = PyoaOccArrayInst_Type.tp_alloc(&PyoaOccArrayInst_Type,0);
        if (bself == NULL) return bself;
        PyoaOccArrayInstObject* self = (PyoaOccArrayInstObject*)bself;
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
PyObject* PyoaOccArrayInst_FromoaOccArrayInst(oaOccArrayInst* data)
{
    if (data) {
       PyObject* bself = PyoaOccArrayInst_Type.tp_alloc(&PyoaOccArrayInst_Type,0);
       if (bself == NULL) return bself;
       PyoaOccArrayInstObject* self = (PyoaOccArrayInstObject*)bself;
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
static char oaOccArrayInst_getInst_doc[] = 
"Class: oaOccArrayInst, Function: getInst\n"
"  Paramegers: ()\n"
"    Calls: oaArrayInst* getInst() const\n"
"    Signature: getInst|ptr-oaArrayInst|\n"
"    BrowseData: 1\n"
"    This function returns the corresponding instance in the block domain. NULL will be returned if the master design for this instance does not have a top block.\n"
"    A pointer to an oaInst\n"
;

static PyObject*
oaOccArrayInst_getInst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccArrayInst data;
    int convert_status=PyoaOccArrayInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccArrayInstObject* self=(PyoaOccArrayInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaArrayInstp result= (data.DataCall()->getInst());
        return PyoaArrayInst_FromoaArrayInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccArrayInst_getName_doc[] = 
"Class: oaOccArrayInst, Function: getName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getName(oaScalarName& name) const\n"
"    Signature: getName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the local name of this arrayInst in the specified name object. The name is relative to the parent occurrence of this arrayInst.\n"
"    name\n"
"    The returned instance name\n"
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
oaOccArrayInst_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccArrayInst data;
    int convert_status=PyoaOccArrayInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccArrayInstObject* self=(PyoaOccArrayInstObject*)ob;
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
        "No Arg-Matching Function found for class: oaOccArrayInst, function: getName, Choices are:\n"
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
static char oaOccArrayInst_getPathName_doc[] = 
"Class: oaOccArrayInst, Function: getPathName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getPathName(oaScalarName& pathName) const\n"
"    Signature: getPathName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the full path name of this arrayInst, relative to the top occurrence in the occurrence hierarchy containing this arrayInst.\n"
"    pathName\n"
"    The returned path name\n"
"  Paramegers: (oaSimpleName)\n"
"    Calls: void getPathName(oaSimpleName& pathName) const\n"
"    Signature: getPathName|void-void|ref-oaSimpleName,\n"
"    BrowseData: 0,oaSimpleName\n"
"    This function fills out pathName with the full path name of this instance, relative to the top occurrence in the occurrence hierarchy containing this instance.\n"
"    pathName\n"
"    The path name of the instance\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getPathName(const oaNameSpace& ns,oaString& pathName) const\n"
"    Signature: getPathName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the full path name of this instance in the specified nameSpace in the specified pathName string. The pathName is relative to the top occurrence in the occurrence hierarchy containing this instance.\n"
"    ns\n"
"    The nameSpace in which to return the name\n"
"    pathName\n"
"    The path name of the instance\n"
;

static PyObject*
oaOccArrayInst_getPathName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccArrayInst data;
    int convert_status=PyoaOccArrayInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccArrayInstObject* self=(PyoaOccArrayInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
            data.DataCall()->getPathName(p1.Data());
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
            data.DataCall()->getPathName(p1.Data());
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
            data.DataCall()->getPathName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaOccArrayInst, function: getPathName, Choices are:\n"
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
static char oaOccArrayInst_isNull_doc[] =
"Class: oaOccArrayInst, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccArrayInst_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccArrayInst data;
    int convert_status=PyoaOccArrayInst_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccArrayInst_assign_doc[] = 
"Class: oaOccArrayInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccArrayInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccArrayInst data;
  int convert_status=PyoaOccArrayInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccArrayInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccArrayInst_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccArrayInst_methodlist[] = {
    {"getInst",(PyCFunction)oaOccArrayInst_getInst,METH_VARARGS,oaOccArrayInst_getInst_doc},
    {"getName",(PyCFunction)oaOccArrayInst_getName,METH_VARARGS,oaOccArrayInst_getName_doc},
    {"getPathName",(PyCFunction)oaOccArrayInst_getPathName,METH_VARARGS,oaOccArrayInst_getPathName_doc},
    {"isNull",(PyCFunction)oaOccArrayInst_tp_isNull,METH_VARARGS,oaOccArrayInst_isNull_doc},
    {"assign",(PyCFunction)oaOccArrayInst_tp_assign,METH_VARARGS,oaOccArrayInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccArrayInst_doc[] = 
"Class: oaOccArrayInst\n"
"  The oaOccArrayInst class implements an occurrence of an oaArrayInst database object that represents an array of instances of one master design in the occurrence domain.\n"
"Constructors:\n"
"  Paramegers: (oaOccArrayInst)\n"
"    Calls: (const oaOccArrayInst&)\n"
"    Signature: oaOccArrayInst||cref-oaOccArrayInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccArrayInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccArrayInst",
    sizeof(PyoaOccArrayInstObject),
    0,
    (destructor)oaOccArrayInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccArrayInst_tp_compare,	/* tp_compare */
    (reprfunc)oaOccArrayInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccArrayInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccArrayInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccBitInst_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccArrayInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccArrayInst_static_find_doc[] = 
"Class: oaOccArrayInst, Function: find\n"
"  Paramegers: (oaOccurrence,oaScalarName)\n"
"    Calls: oaOccArrayInst* find(const oaOccurrence* occurrence,const oaScalarName& name)\n"
"    Signature: find|ptr-oaOccArrayInst|cptr-oaOccurrence,cref-oaScalarName,\n"
"    This function searches the specified occurrence for an arrayInst with the specified name . If name is hierarchical, then this function will descend into lower levels of occurrence hierarchy, expanding the hierarchy and binding the master designs as needed. The arrayInst is returned if found, otherwise NULL is returned.\n"
"    occurrence\n"
"    The occurrence in which to search\n"
"    name\n"
"    The name of the arrayInst to find\n"
"    A pointer to the oaOccArrayInst\n"
;

static PyObject*
oaOccArrayInst_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccurrence p1;
    PyParamoaScalarName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaOccurrence_Convert,&p1,
          &PyoaScalarName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaOccArrayInstp result= (oaOccArrayInst::find(p1.Data(),p2.Data()));
        return PyoaOccArrayInst_FromoaOccArrayInst(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaOccArrayInst_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaOccArrayInst_static_find,METH_VARARGS,oaOccArrayInst_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccArrayInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccArrayInst_Type)<0) {
      printf("** PyType_Ready failed for: oaOccArrayInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccArrayInst",
           (PyObject*)(&PyoaOccArrayInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccArrayInst\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaOccArrayInst_Type.tp_dict;
    for(method=oaOccArrayInst_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaOccAssignAssignment
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccAssignAssignment_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccAssignAssignment_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccAssignAssignmentObject* self = (PyoaOccAssignAssignmentObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccAssignAssignment)
    {
        PyParamoaOccAssignAssignment p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccAssignAssignment_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccAssignAssignment, Choices are:\n"
        "    (oaOccAssignAssignment)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccAssignAssignment_tp_dealloc(PyoaOccAssignAssignmentObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccAssignAssignment_tp_repr(PyObject *ob)
{
    PyParamoaOccAssignAssignment value;
    int convert_status=PyoaOccAssignAssignment_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaOccAssignAssignment::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[43];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaOccAssignAssignment::");
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
oaOccAssignAssignment_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccAssignAssignment v1;
    PyParamoaOccAssignAssignment v2;
    int convert_status1=PyoaOccAssignAssignment_Convert(ob1,&v1);
    int convert_status2=PyoaOccAssignAssignment_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccAssignAssignment_Convert(PyObject* ob,PyParamoaOccAssignAssignment* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccAssignAssignment_Check(ob)) {
        result->SetData( (oaOccAssignAssignment**) ((PyoaOccAssignAssignmentObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccAssignAssignment Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccAssignAssignment_FromoaOccAssignAssignment(oaOccAssignAssignment** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccAssignAssignment* data=*value;
        PyObject* bself = PyoaOccAssignAssignment_Type.tp_alloc(&PyoaOccAssignAssignment_Type,0);
        if (bself == NULL) return bself;
        PyoaOccAssignAssignmentObject* self = (PyoaOccAssignAssignmentObject*)bself;
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
PyObject* PyoaOccAssignAssignment_FromoaOccAssignAssignment(oaOccAssignAssignment* data)
{
    if (data) {
       PyObject* bself = PyoaOccAssignAssignment_Type.tp_alloc(&PyoaOccAssignAssignment_Type,0);
       if (bself == NULL) return bself;
       PyoaOccAssignAssignmentObject* self = (PyoaOccAssignAssignmentObject*)bself;
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
static char oaOccAssignAssignment_getAssignmentDef_doc[] = 
"Class: oaOccAssignAssignment, Function: getAssignmentDef\n"
"  Paramegers: (oaAssignmentDef)\n"
"    Calls: void getAssignmentDef(oaAssignmentDef& aDef) const\n"
"    Signature: getAssignmentDef|void-void|ref-oaAssignmentDef,\n"
"    BrowseData: 0,oaAssignmentDef\n"
"    This function retrieves the data associated with this assignment and returns it in the assignmentDef argument.\n"
;

static PyObject*
oaOccAssignAssignment_getAssignmentDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccAssignAssignment data;
    int convert_status=PyoaOccAssignAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccAssignAssignmentObject* self=(PyoaOccAssignAssignmentObject*)ob;
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
static char oaOccAssignAssignment_isNull_doc[] =
"Class: oaOccAssignAssignment, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccAssignAssignment_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccAssignAssignment data;
    int convert_status=PyoaOccAssignAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccAssignAssignment_assign_doc[] = 
"Class: oaOccAssignAssignment, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccAssignAssignment_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccAssignAssignment data;
  int convert_status=PyoaOccAssignAssignment_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccAssignAssignment p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccAssignAssignment_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccAssignAssignment_methodlist[] = {
    {"getAssignmentDef",(PyCFunction)oaOccAssignAssignment_getAssignmentDef,METH_VARARGS,oaOccAssignAssignment_getAssignmentDef_doc},
    {"isNull",(PyCFunction)oaOccAssignAssignment_tp_isNull,METH_VARARGS,oaOccAssignAssignment_isNull_doc},
    {"assign",(PyCFunction)oaOccAssignAssignment_tp_assign,METH_VARARGS,oaOccAssignAssignment_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccAssignAssignment_doc[] = 
"Class: oaOccAssignAssignment\n"
"  The oaOccAssignAssignment class implements a connection assignment that specifies assignment definition values to replace those specified in a corresponding oaOccConnectDef or a previously encountered oaOccAssignAssignment. Applications interpreting the connectivity continue searching up the design hierarchy for a connection assignment with the name specified in the oaOccAssignAssignment. If none is found, the assignment value is the default net name.\n"
"  This type of connection assignment is useful for integrating a block of intellectual property that contain connection definition. An oaOccAssignAssignment can be used to insure that connectivity traversal applications search for connection assignments consistently in the entire design hierarchy.\n"
"Constructors:\n"
"  Paramegers: (oaOccAssignAssignment)\n"
"    Calls: (const oaOccAssignAssignment&)\n"
"    Signature: oaOccAssignAssignment||cref-oaOccAssignAssignment,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccAssignAssignment_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccAssignAssignment",
    sizeof(PyoaOccAssignAssignmentObject),
    0,
    (destructor)oaOccAssignAssignment_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccAssignAssignment_tp_compare,	/* tp_compare */
    (reprfunc)oaOccAssignAssignment_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccAssignAssignment_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccAssignAssignment_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccAssignment_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccAssignAssignment_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccAssignAssignment_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccAssignAssignment_Type)<0) {
      printf("** PyType_Ready failed for: oaOccAssignAssignment\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccAssignAssignment",
           (PyObject*)(&PyoaOccAssignAssignment_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccAssignAssignment\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaOccAssignValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccAssignValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccAssignValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccAssignValueObject* self = (PyoaOccAssignValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccAssignValue)
    {
        PyParamoaOccAssignValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccAssignValue_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccAssignValue, Choices are:\n"
        "    (oaOccAssignValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccAssignValue_tp_dealloc(PyoaOccAssignValueObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccAssignValue_tp_repr(PyObject *ob)
{
    PyParamoaOccAssignValue value;
    int convert_status=PyoaOccAssignValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaOccAssignValue::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[38];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaOccAssignValue::");
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
oaOccAssignValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccAssignValue v1;
    PyParamoaOccAssignValue v2;
    int convert_status1=PyoaOccAssignValue_Convert(ob1,&v1);
    int convert_status2=PyoaOccAssignValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccAssignValue_Convert(PyObject* ob,PyParamoaOccAssignValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccAssignValue_Check(ob)) {
        result->SetData( (oaOccAssignValue**) ((PyoaOccAssignValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccAssignValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccAssignValue_FromoaOccAssignValue(oaOccAssignValue** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccAssignValue* data=*value;
        PyObject* bself = PyoaOccAssignValue_Type.tp_alloc(&PyoaOccAssignValue_Type,0);
        if (bself == NULL) return bself;
        PyoaOccAssignValueObject* self = (PyoaOccAssignValueObject*)bself;
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
PyObject* PyoaOccAssignValue_FromoaOccAssignValue(oaOccAssignValue* data)
{
    if (data) {
       PyObject* bself = PyoaOccAssignValue_Type.tp_alloc(&PyoaOccAssignValue_Type,0);
       if (bself == NULL) return bself;
       PyoaOccAssignValueObject* self = (PyoaOccAssignValueObject*)bself;
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
static char oaOccAssignValue_getValue_doc[] = 
"Class: oaOccAssignValue, Function: getValue\n"
"  Paramegers: (oaSimpleName)\n"
"    Calls: void getValue(oaSimpleName& netName) const\n"
"    Signature: getValue|void-void|ref-oaSimpleName,\n"
"    BrowseData: 0,oaSimpleName\n"
"    This function returns the netName of this oaOccAssignValue object. This netName specifies the name of a single-bit net to use to in resolving the connections associated with a corresponding oaOccConnectDef object in the design hierarchy.\n"
;

static PyObject*
oaOccAssignValue_getValue(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccAssignValue data;
    int convert_status=PyoaOccAssignValue_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccAssignValueObject* self=(PyoaOccAssignValueObject*)ob;
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
static char oaOccAssignValue_isNull_doc[] =
"Class: oaOccAssignValue, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccAssignValue_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccAssignValue data;
    int convert_status=PyoaOccAssignValue_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccAssignValue_assign_doc[] = 
"Class: oaOccAssignValue, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccAssignValue_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccAssignValue data;
  int convert_status=PyoaOccAssignValue_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccAssignValue p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccAssignValue_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccAssignValue_methodlist[] = {
    {"getValue",(PyCFunction)oaOccAssignValue_getValue,METH_VARARGS,oaOccAssignValue_getValue_doc},
    {"isNull",(PyCFunction)oaOccAssignValue_tp_isNull,METH_VARARGS,oaOccAssignValue_isNull_doc},
    {"assign",(PyCFunction)oaOccAssignValue_tp_assign,METH_VARARGS,oaOccAssignValue_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccAssignValue_doc[] = 
"Class: oaOccAssignValue\n"
"  The oaOccAssignValue class implements a connection assignment that specifies\n"
"  the name of the net to use in place of the name of the net associated with the corresponding oaOccNetConnectDef object\n"
"  the name of the net to use to externally connect to the terminal associated with the corresponding oaOccTermConnectDef object\n"
"Constructors:\n"
"  Paramegers: (oaOccAssignValue)\n"
"    Calls: (const oaOccAssignValue&)\n"
"    Signature: oaOccAssignValue||cref-oaOccAssignValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccAssignValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccAssignValue",
    sizeof(PyoaOccAssignValueObject),
    0,
    (destructor)oaOccAssignValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccAssignValue_tp_compare,	/* tp_compare */
    (reprfunc)oaOccAssignValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccAssignValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccAssignValue_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccAssignment_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccAssignValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccAssignValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccAssignValue_Type)<0) {
      printf("** PyType_Ready failed for: oaOccAssignValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccAssignValue",
           (PyObject*)(&PyoaOccAssignValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccAssignValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaOccAssignment
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccAssignment_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccAssignment_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccAssignmentObject* self = (PyoaOccAssignmentObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccAssignment)
    {
        PyParamoaOccAssignment p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccAssignment_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccAssignment, Choices are:\n"
        "    (oaOccAssignment)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccAssignment_tp_dealloc(PyoaOccAssignmentObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccAssignment_tp_repr(PyObject *ob)
{
    PyParamoaOccAssignment value;
    int convert_status=PyoaOccAssignment_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaOccAssignment::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaString sresult;
        value.DataCall()->getName(sresult);
    
        char addr[37];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaOccAssignment::");
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
oaOccAssignment_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccAssignment v1;
    PyParamoaOccAssignment v2;
    int convert_status1=PyoaOccAssignment_Convert(ob1,&v1);
    int convert_status2=PyoaOccAssignment_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccAssignment_Convert(PyObject* ob,PyParamoaOccAssignment* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccAssignment_Check(ob)) {
        result->SetData( (oaOccAssignment**) ((PyoaOccAssignmentObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccAssignment Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccAssignment_FromoaOccAssignment(oaOccAssignment** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccAssignment* data=*value;
        if (data->getType()==oacOccAssignAssignmentType) return PyoaOccAssignAssignment_FromoaOccAssignAssignment((oaOccAssignAssignment**)value,borrow,lock);
        if (data->getType()==oacOccAssignValueType) return PyoaOccAssignValue_FromoaOccAssignValue((oaOccAssignValue**)value,borrow,lock);
        PyObject* bself = PyoaOccAssignment_Type.tp_alloc(&PyoaOccAssignment_Type,0);
        if (bself == NULL) return bself;
        PyoaOccAssignmentObject* self = (PyoaOccAssignmentObject*)bself;
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
PyObject* PyoaOccAssignment_FromoaOccAssignment(oaOccAssignment* data)
{
    if (data) {
        if (data->getType()==oacOccAssignAssignmentType) return PyoaOccAssignAssignment_FromoaOccAssignAssignment((oaOccAssignAssignment*)data);
        if (data->getType()==oacOccAssignValueType) return PyoaOccAssignValue_FromoaOccAssignValue((oaOccAssignValue*)data);
       PyObject* bself = PyoaOccAssignment_Type.tp_alloc(&PyoaOccAssignment_Type,0);
       if (bself == NULL) return bself;
       PyoaOccAssignmentObject* self = (PyoaOccAssignmentObject*)bself;
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
static char oaOccAssignment_getInst_doc[] = 
"Class: oaOccAssignment, Function: getInst\n"
"  Paramegers: ()\n"
"    Calls: oaOccInst* getInst() const\n"
"    Signature: getInst|ptr-oaOccInst|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the instance with which this assignment is associated.\n"
;

static PyObject*
oaOccAssignment_getInst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccAssignment data;
    int convert_status=PyoaOccAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccAssignmentObject* self=(PyoaOccAssignmentObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaOccInstp result= (data.DataCall()->getInst());
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
static char oaOccAssignment_getName_doc[] = 
"Class: oaOccAssignment, Function: getName\n"
"  Paramegers: (oaString)\n"
"    Calls: void getName(oaString& name) const\n"
"    Signature: getName|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the name of this assignment in the given name string. This is the name that is searched for when resolving the connections for the oaOccNetConnectDef and oaOccTermConnectDef objects.\n"
;

static PyObject*
oaOccAssignment_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccAssignment data;
    int convert_status=PyoaOccAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccAssignmentObject* self=(PyoaOccAssignmentObject*)ob;
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
static char oaOccAssignment_isNull_doc[] =
"Class: oaOccAssignment, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccAssignment_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccAssignment data;
    int convert_status=PyoaOccAssignment_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccAssignment_assign_doc[] = 
"Class: oaOccAssignment, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccAssignment_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccAssignment data;
  int convert_status=PyoaOccAssignment_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccAssignment p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccAssignment_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccAssignment_methodlist[] = {
    {"getInst",(PyCFunction)oaOccAssignment_getInst,METH_VARARGS,oaOccAssignment_getInst_doc},
    {"getName",(PyCFunction)oaOccAssignment_getName,METH_VARARGS,oaOccAssignment_getName_doc},
    {"isNull",(PyCFunction)oaOccAssignment_tp_isNull,METH_VARARGS,oaOccAssignment_isNull_doc},
    {"assign",(PyCFunction)oaOccAssignment_tp_assign,METH_VARARGS,oaOccAssignment_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccAssignment_doc[] = 
"Class: oaOccAssignment\n"
"  In the occurrence domain it is not possible directly create any connectDefs or assignments. The occurrence domain versions of these classes are automatically created by OpenAccess as a reflection of objects created in the module or block domain. For further information, see oaConnectDef (and its derived classes) and oaAssignmentDef in the block domain and oaModConnectDef (and its derived classes) and oaModAssignment in the module domain.\n"
"  The oaOccAssignment class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaOccAssignment)\n"
"    Calls: (const oaOccAssignment&)\n"
"    Signature: oaOccAssignment||cref-oaOccAssignment,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccAssignment_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccAssignment",
    sizeof(PyoaOccAssignmentObject),
    0,
    (destructor)oaOccAssignment_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccAssignment_tp_compare,	/* tp_compare */
    (reprfunc)oaOccAssignment_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccAssignment_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccAssignment_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccAssignment_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccAssignment_static_find_doc[] = 
"Class: oaOccAssignment, Function: find\n"
"  Paramegers: (oaOccInst,oaString)\n"
"    Calls: oaOccAssignment* find(const oaOccInst* inst,const oaString& name)\n"
"    Signature: find|ptr-oaOccAssignment|cptr-oaOccInst,cref-oaString,\n"
"    This function searches the specified instance for an assignment with the specified lookup name .\n"
"    A pointer to the assignment, if found\n"
;

static PyObject*
oaOccAssignment_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInst p1;
    PyParamoaString p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaOccInst_Convert,&p1,
          &PyoaString_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaOccAssignmentp result= (oaOccAssignment::find(p1.Data(),p2.Data()));
        return PyoaOccAssignment_FromoaOccAssignment(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaOccAssignment_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaOccAssignment_static_find,METH_VARARGS,oaOccAssignment_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccAssignment_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccAssignment_Type)<0) {
      printf("** PyType_Ready failed for: oaOccAssignment\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccAssignment",
           (PyObject*)(&PyoaOccAssignment_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccAssignment\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaOccAssignment_Type.tp_dict;
    for(method=oaOccAssignment_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaOccAttrDisplay
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccAttrDisplay_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccAttrDisplay_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccAttrDisplayObject* self = (PyoaOccAttrDisplayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccAttrDisplay)
    {
        PyParamoaOccAttrDisplay p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccAttrDisplay_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccAttrDisplay, Choices are:\n"
        "    (oaOccAttrDisplay)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccAttrDisplay_tp_dealloc(PyoaOccAttrDisplayObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccAttrDisplay_tp_repr(PyObject *ob)
{
    PyParamoaOccAttrDisplay value;
    int convert_status=PyoaOccAttrDisplay_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaOccAttrDisplay::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaOccAttrDisplay_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccAttrDisplay v1;
    PyParamoaOccAttrDisplay v2;
    int convert_status1=PyoaOccAttrDisplay_Convert(ob1,&v1);
    int convert_status2=PyoaOccAttrDisplay_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccAttrDisplay_Convert(PyObject* ob,PyParamoaOccAttrDisplay* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccAttrDisplay_Check(ob)) {
        result->SetData( (oaOccAttrDisplay**) ((PyoaOccAttrDisplayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccAttrDisplay Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccAttrDisplay_FromoaOccAttrDisplay(oaOccAttrDisplay** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccAttrDisplay* data=*value;
        PyObject* bself = PyoaOccAttrDisplay_Type.tp_alloc(&PyoaOccAttrDisplay_Type,0);
        if (bself == NULL) return bself;
        PyoaOccAttrDisplayObject* self = (PyoaOccAttrDisplayObject*)bself;
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
PyObject* PyoaOccAttrDisplay_FromoaOccAttrDisplay(oaOccAttrDisplay* data)
{
    if (data) {
       PyObject* bself = PyoaOccAttrDisplay_Type.tp_alloc(&PyoaOccAttrDisplay_Type,0);
       if (bself == NULL) return bself;
       PyoaOccAttrDisplayObject* self = (PyoaOccAttrDisplayObject*)bself;
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
static char oaOccAttrDisplay_getAttribute_doc[] = 
"Class: oaOccAttrDisplay, Function: getAttribute\n"
"  Paramegers: ()\n"
"    Calls: oaAttrType getAttribute() const\n"
"    Signature: getAttribute|simple-oaAttrType|\n"
"    BrowseData: 1\n"
"    This function returns the attribute associated referenced by this attrDisplay object.\n"
;

static PyObject*
oaOccAttrDisplay_getAttribute(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccAttrDisplay data;
    int convert_status=PyoaOccAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccAttrDisplayObject* self=(PyoaOccAttrDisplayObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaAttrType* result= new oaAttrType(data.DataCall()->getAttribute());
        return PyoaAttrType_FromoaAttrType(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccAttrDisplay_getObject_doc[] = 
"Class: oaOccAttrDisplay, Function: getObject\n"
"  Paramegers: ()\n"
"    Calls: oaObject* getObject() const\n"
"    Signature: getObject|ptr-oaObject|\n"
"    BrowseData: 1\n"
"    This function returns the object associated with the attrDisplay object from which this occAttrDisplay is generated.\n"
;

static PyObject*
oaOccAttrDisplay_getObject(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccAttrDisplay data;
    int convert_status=PyoaOccAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccAttrDisplayObject* self=(PyoaOccAttrDisplayObject*)ob;
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
static char oaOccAttrDisplay_getText_doc[] = 
"Class: oaOccAttrDisplay, Function: getText\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getText(const oaNameSpace& ns,oaString& text) const\n"
"    Signature: getText|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the value of this attribute display according to the given nameSpace. The nameSpace is only valid for name type attributes.\n"
"    ns\n"
"    The nameSpace to be used.\n"
"    text\n"
"    The text string to be filled.\n"
;

static PyObject*
oaOccAttrDisplay_getText(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccAttrDisplay data;
    int convert_status=PyoaOccAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccAttrDisplayObject* self=(PyoaOccAttrDisplayObject*)ob;
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
static char oaOccAttrDisplay_isNull_doc[] =
"Class: oaOccAttrDisplay, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccAttrDisplay_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccAttrDisplay data;
    int convert_status=PyoaOccAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccAttrDisplay_assign_doc[] = 
"Class: oaOccAttrDisplay, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccAttrDisplay_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccAttrDisplay data;
  int convert_status=PyoaOccAttrDisplay_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccAttrDisplay p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccAttrDisplay_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccAttrDisplay_methodlist[] = {
    {"getAttribute",(PyCFunction)oaOccAttrDisplay_getAttribute,METH_VARARGS,oaOccAttrDisplay_getAttribute_doc},
    {"getObject",(PyCFunction)oaOccAttrDisplay_getObject,METH_VARARGS,oaOccAttrDisplay_getObject_doc},
    {"getText",(PyCFunction)oaOccAttrDisplay_getText,METH_VARARGS,oaOccAttrDisplay_getText_doc},
    {"isNull",(PyCFunction)oaOccAttrDisplay_tp_isNull,METH_VARARGS,oaOccAttrDisplay_isNull_doc},
    {"assign",(PyCFunction)oaOccAttrDisplay_tp_assign,METH_VARARGS,oaOccAttrDisplay_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccAttrDisplay_doc[] = 
"Class: oaOccAttrDisplay\n"
"  The oaOccAttrDisplay class implements an unique occurrence of an oaAttrDisplay object in a design hierarchy.\n"
"Constructors:\n"
"  Paramegers: (oaOccAttrDisplay)\n"
"    Calls: (const oaOccAttrDisplay&)\n"
"    Signature: oaOccAttrDisplay||cref-oaOccAttrDisplay,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccAttrDisplay_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccAttrDisplay",
    sizeof(PyoaOccAttrDisplayObject),
    0,
    (destructor)oaOccAttrDisplay_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccAttrDisplay_tp_compare,	/* tp_compare */
    (reprfunc)oaOccAttrDisplay_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccAttrDisplay_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccAttrDisplay_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccTextDisplay_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccAttrDisplay_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccAttrDisplay_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccAttrDisplay_Type)<0) {
      printf("** PyType_Ready failed for: oaOccAttrDisplay\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccAttrDisplay",
           (PyObject*)(&PyoaOccAttrDisplay_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccAttrDisplay\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaOccBitInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccBitInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccBitInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccBitInstObject* self = (PyoaOccBitInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccBitInst)
    {
        PyParamoaOccBitInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccBitInst_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccBitInst, Choices are:\n"
        "    (oaOccBitInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccBitInst_tp_dealloc(PyoaOccBitInstObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccBitInst_tp_repr(PyObject *ob)
{
    PyParamoaOccBitInst value;
    int convert_status=PyoaOccBitInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaOccBitInst::NULL>");
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
        buffer+=oaString("<oaOccBitInst::");
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
oaOccBitInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccBitInst v1;
    PyParamoaOccBitInst v2;
    int convert_status1=PyoaOccBitInst_Convert(ob1,&v1);
    int convert_status2=PyoaOccBitInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccBitInst_Convert(PyObject* ob,PyParamoaOccBitInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccBitInst_Check(ob)) {
        result->SetData( (oaOccBitInst**) ((PyoaOccBitInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccBitInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccBitInst_FromoaOccBitInst(oaOccBitInst** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccBitInst* data=*value;
        if (data->getType()==oacOccArrayInstType) return PyoaOccArrayInst_FromoaOccArrayInst((oaOccArrayInst**)value,borrow,lock);
        if (data->getType()==oacOccScalarInstType) return PyoaOccScalarInst_FromoaOccScalarInst((oaOccScalarInst**)value,borrow,lock);
        if (data->getType()==oacOccVectorInstBitType) return PyoaOccVectorInstBit_FromoaOccVectorInstBit((oaOccVectorInstBit**)value,borrow,lock);
        PyObject* bself = PyoaOccBitInst_Type.tp_alloc(&PyoaOccBitInst_Type,0);
        if (bself == NULL) return bself;
        PyoaOccBitInstObject* self = (PyoaOccBitInstObject*)bself;
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
PyObject* PyoaOccBitInst_FromoaOccBitInst(oaOccBitInst* data)
{
    if (data) {
        if (data->getType()==oacOccArrayInstType) return PyoaOccArrayInst_FromoaOccArrayInst((oaOccArrayInst*)data);
        if (data->getType()==oacOccScalarInstType) return PyoaOccScalarInst_FromoaOccScalarInst((oaOccScalarInst*)data);
        if (data->getType()==oacOccVectorInstBitType) return PyoaOccVectorInstBit_FromoaOccVectorInstBit((oaOccVectorInstBit*)data);
       PyObject* bself = PyoaOccBitInst_Type.tp_alloc(&PyoaOccBitInst_Type,0);
       if (bself == NULL) return bself;
       PyoaOccBitInstObject* self = (PyoaOccBitInstObject*)bself;
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
static char oaOccBitInst_doc[] = 
"Class: oaOccBitInst\n"
"  The oaOccBitInst class is the base for the scalar, occurrence instances of a design master.\n"
"  oaOccBitInst objects are always in the occurrence domain.\n"
"Constructors:\n"
"  Paramegers: (oaOccBitInst)\n"
"    Calls: (const oaOccBitInst&)\n"
"    Signature: oaOccBitInst||cref-oaOccBitInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccBitInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccBitInst",
    sizeof(PyoaOccBitInstObject),
    0,
    (destructor)oaOccBitInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccBitInst_tp_compare,	/* tp_compare */
    (reprfunc)oaOccBitInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccBitInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccDesignInst_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccBitInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccBitInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccBitInst_Type)<0) {
      printf("** PyType_Ready failed for: oaOccBitInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccBitInst",
           (PyObject*)(&PyoaOccBitInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccBitInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaOccBitNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccBitNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccBitNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccBitNetObject* self = (PyoaOccBitNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccBitNet)
    {
        PyParamoaOccBitNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccBitNet_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccBitNet, Choices are:\n"
        "    (oaOccBitNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccBitNet_tp_dealloc(PyoaOccBitNetObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccBitNet_tp_repr(PyObject *ob)
{
    PyParamoaOccBitNet value;
    int convert_status=PyoaOccBitNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaOccBitNet::NULL>");
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
        buffer+=oaString("<oaOccBitNet::");
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
oaOccBitNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccBitNet v1;
    PyParamoaOccBitNet v2;
    int convert_status1=PyoaOccBitNet_Convert(ob1,&v1);
    int convert_status2=PyoaOccBitNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccBitNet_Convert(PyObject* ob,PyParamoaOccBitNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccBitNet_Check(ob)) {
        result->SetData( (oaOccBitNet**) ((PyoaOccBitNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccBitNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccBitNet_FromoaOccBitNet(oaOccBitNet** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccBitNet* data=*value;
        if (data->getType()==oacOccBusNetBitType) return PyoaOccBusNetBit_FromoaOccBusNetBit((oaOccBusNetBit**)value,borrow,lock);
        if (data->getType()==oacOccScalarNetType) return PyoaOccScalarNet_FromoaOccScalarNet((oaOccScalarNet**)value,borrow,lock);
        PyObject* bself = PyoaOccBitNet_Type.tp_alloc(&PyoaOccBitNet_Type,0);
        if (bself == NULL) return bself;
        PyoaOccBitNetObject* self = (PyoaOccBitNetObject*)bself;
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
PyObject* PyoaOccBitNet_FromoaOccBitNet(oaOccBitNet* data)
{
    if (data) {
        if (data->getType()==oacOccBusNetBitType) return PyoaOccBusNetBit_FromoaOccBusNetBit((oaOccBusNetBit*)data);
        if (data->getType()==oacOccScalarNetType) return PyoaOccScalarNet_FromoaOccScalarNet((oaOccScalarNet*)data);
       PyObject* bself = PyoaOccBitNet_Type.tp_alloc(&PyoaOccBitNet_Type,0);
       if (bself == NULL) return bself;
       PyoaOccBitNetObject* self = (PyoaOccBitNetObject*)bself;
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
static char oaOccBitNet_getConnectDef_doc[] = 
"Class: oaOccBitNet, Function: getConnectDef\n"
"  Paramegers: ()\n"
"    Calls: oaOccNetConnectDef* getConnectDef() const\n"
"    Signature: getConnectDef|ptr-oaOccNetConnectDef|\n"
"    BrowseData: 1\n"
"    This function returns the connection definition associated with this net if there is one. NULL is returned if the net is not associated with a connection definition.\n"
;

static PyObject*
oaOccBitNet_getConnectDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBitNet data;
    int convert_status=PyoaOccBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBitNetObject* self=(PyoaOccBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaOccNetConnectDefp result= (data.DataCall()->getConnectDef());
        return PyoaOccNetConnectDef_FromoaOccNetConnectDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBitNet_getEquivalentNets_doc[] = 
"Class: oaOccBitNet, Function: getEquivalentNets\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaOccBitNet_oaOccBitNet getEquivalentNets() const\n"
"    Signature: getEquivalentNets|simple-oaCollection_oaOccBitNet_oaOccBitNet|\n"
"    BrowseData: 1\n"
"    This function returns a collection of nets equivalent to this net.\n"
"    This function gets the collection of all equivalent nets not including the net used to get the collection. The returned collection will be empty if there are no equivalent nets assigned to this net.\n"
;

static PyObject*
oaOccBitNet_getEquivalentNets(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBitNet data;
    int convert_status=PyoaOccBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBitNetObject* self=(PyoaOccBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaOccBitNet_oaOccBitNet* result= new oaCollection_oaOccBitNet_oaOccBitNet(data.DataCall()->getEquivalentNets());
        return PyoaCollection_oaOccBitNet_oaOccBitNet_FromoaCollection_oaOccBitNet_oaOccBitNet(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBitNet_getEquivalentNetsIter_doc[] = 
"Class: oaOccBitNet, Function: getEquivalentNetsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaOccBitNet getEquivalentNetsIter() const\n"
"    Signature: getEquivalentNetsIter|simple-oaIter_oaOccBitNet|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of nets equivalent to this net.\n"
"    This function gets the collection of all equivalent nets not including the net used to get the collection. The returned collection will be empty if there are no equivalent nets assigned to this net.\n"
;

static PyObject*
oaOccBitNet_getEquivalentNetsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBitNet data;
    int convert_status=PyoaOccBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBitNetObject* self=(PyoaOccBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaOccBitNet* result= new oaIter_oaOccBitNet(data.DataCall()->getEquivalentNets());
        return PyoaIter_oaOccBitNet_FromoaIter_oaOccBitNet(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBitNet_getParasiticConfidence_doc[] = 
"Class: oaOccBitNet, Function: getParasiticConfidence\n"
"  Paramegers: (oaUInt4,oaUInt4)\n"
"    Calls: void getParasiticConfidence(oaUInt4& minValue,oaUInt4& maxValue) const\n"
"    Signature: getParasiticConfidence|void-void|ref-oaUInt4,ref-oaUInt4,\n"
"    BrowseData: 0,oaUInt4,oaUInt4\n"
"    This function returns the min and max parasitic confidence values. These are defined to be between 0 and 100.\n"
"    minValue\n"
"    returned min parasitic confidence value\n"
"    maxValue\n"
"    returned max parasitic confidence value\n"
;

static PyObject*
oaOccBitNet_getParasiticConfidence(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBitNet data;
    int convert_status=PyoaOccBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBitNetObject* self=(PyoaOccBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    PyParamoaUInt4 p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaUInt4_Convert,&p1,
          &PyoaUInt4_Convert,&p2)) {
        data.DataCall()->getParasiticConfidence(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBitNet_getPreferredEquivalent_doc[] = 
"Class: oaOccBitNet, Function: getPreferredEquivalent\n"
"  Paramegers: ()\n"
"    Calls: oaOccBitNet* getPreferredEquivalent() const\n"
"    Signature: getPreferredEquivalent|ptr-oaOccBitNet|\n"
"    BrowseData: 1\n"
"    This function returns the preferred equivalent net associated with this net. If this net does not have any equivalents, the net itself is returned since it is considered the preferred equivalent of itself.\n"
;

static PyObject*
oaOccBitNet_getPreferredEquivalent(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBitNet data;
    int convert_status=PyoaOccBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBitNetObject* self=(PyoaOccBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBitNetp result= (data.DataCall()->getPreferredEquivalent());
        return PyoaOccBitNet_FromoaOccBitNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBitNet_isPreferredEquivalent_doc[] = 
"Class: oaOccBitNet, Function: isPreferredEquivalent\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isPreferredEquivalent() const\n"
"    Signature: isPreferredEquivalent|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this net is the preferred equivalent net in a set of equivalent nets. true is also returned if the net does not have any equivalents.\n"
;

static PyObject*
oaOccBitNet_isPreferredEquivalent(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBitNet data;
    int convert_status=PyoaOccBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBitNetObject* self=(PyoaOccBitNetObject*)ob;
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
static char oaOccBitNet_setParasiticConfidence_doc[] = 
"Class: oaOccBitNet, Function: setParasiticConfidence\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void setParasiticConfidence(oaUInt4 value)\n"
"    Signature: setParasiticConfidence|void-void|simple-oaUInt4,\n"
"    This function sets both the min and max parasitic confidence value for this net to the specified value . The parasitic confidence value must be between 0 and 100.\n"
"    value\n"
"    the min and max parasitic confidence value (from 0 to 100) to set on this net\n"
"    oacInvalidParasiticConfidenceValue\n"
"    oacCannotSetParasiticConfImplicitNet\n"
"  Paramegers: (oaUInt4,oaUInt4)\n"
"    Calls: void setParasiticConfidence(oaUInt4 minValue,oaUInt4 maxValue)\n"
"    Signature: setParasiticConfidence|void-void|simple-oaUInt4,simple-oaUInt4,\n"
"    This function sets the specified min ( minValue ) and max ( maxValue ) parasitic confidence values for this net. Parasitic confidence values must be between 0 and 100.\n"
"    minValue\n"
"    the min parasitic confidence value (from 0 to 100) to set on this net\n"
"    maxValue\n"
"    the max parasitic confidence value (from 0 to 100) to set on this net\n"
"    oacInvalidParasiticConfidenceValue\n"
"    oacCannotSetParasiticConfImplicitNet\n"
;

static PyObject*
oaOccBitNet_setParasiticConfidence(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBitNet data;
    int convert_status=PyoaOccBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBitNetObject* self=(PyoaOccBitNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            data.DataCall()->setParasiticConfidence(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4,oaUInt4)
    {
        PyParamoaUInt4 p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaUInt4_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            data.DataCall()->setParasiticConfidence(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaOccBitNet, function: setParasiticConfidence, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBitNet_isNull_doc[] =
"Class: oaOccBitNet, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccBitNet_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccBitNet data;
    int convert_status=PyoaOccBitNet_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccBitNet_assign_doc[] = 
"Class: oaOccBitNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccBitNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccBitNet data;
  int convert_status=PyoaOccBitNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccBitNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccBitNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccBitNet_methodlist[] = {
    {"getConnectDef",(PyCFunction)oaOccBitNet_getConnectDef,METH_VARARGS,oaOccBitNet_getConnectDef_doc},
    {"getEquivalentNets",(PyCFunction)oaOccBitNet_getEquivalentNets,METH_VARARGS,oaOccBitNet_getEquivalentNets_doc},
    {"getEquivalentNetsIter",(PyCFunction)oaOccBitNet_getEquivalentNetsIter,METH_VARARGS,oaOccBitNet_getEquivalentNetsIter_doc},
    {"getParasiticConfidence",(PyCFunction)oaOccBitNet_getParasiticConfidence,METH_VARARGS,oaOccBitNet_getParasiticConfidence_doc},
    {"getPreferredEquivalent",(PyCFunction)oaOccBitNet_getPreferredEquivalent,METH_VARARGS,oaOccBitNet_getPreferredEquivalent_doc},
    {"isPreferredEquivalent",(PyCFunction)oaOccBitNet_isPreferredEquivalent,METH_VARARGS,oaOccBitNet_isPreferredEquivalent_doc},
    {"setParasiticConfidence",(PyCFunction)oaOccBitNet_setParasiticConfidence,METH_VARARGS,oaOccBitNet_setParasiticConfidence_doc},
    {"isNull",(PyCFunction)oaOccBitNet_tp_isNull,METH_VARARGS,oaOccBitNet_isNull_doc},
    {"assign",(PyCFunction)oaOccBitNet_tp_assign,METH_VARARGS,oaOccBitNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBitNet_doc[] = 
"Class: oaOccBitNet\n"
"  The oaOccBitNet class is the base class for single-bit nets that are part of the design's logical description.\n"
"  You can have two or more bitNets that are equivalent. Equivalent bitNets are traversed separately or logically as the same net.\n"
"  You can create associate a connection definition, oaModNetConnectDef , with a bitNet.\n"
"Constructors:\n"
"  Paramegers: (oaOccBitNet)\n"
"    Calls: (const oaOccBitNet&)\n"
"    Signature: oaOccBitNet||cref-oaOccBitNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccBitNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccBitNet",
    sizeof(PyoaOccBitNetObject),
    0,
    (destructor)oaOccBitNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccBitNet_tp_compare,	/* tp_compare */
    (reprfunc)oaOccBitNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccBitNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccBitNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccNet_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccBitNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccBitNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccBitNet_Type)<0) {
      printf("** PyType_Ready failed for: oaOccBitNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccBitNet",
           (PyObject*)(&PyoaOccBitNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccBitNet\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaOccBitTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccBitTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccBitTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccBitTermObject* self = (PyoaOccBitTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccBitTerm)
    {
        PyParamoaOccBitTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccBitTerm_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccBitTerm, Choices are:\n"
        "    (oaOccBitTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccBitTerm_tp_dealloc(PyoaOccBitTermObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccBitTerm_tp_repr(PyObject *ob)
{
    PyParamoaOccBitTerm value;
    int convert_status=PyoaOccBitTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaOccBitTerm::NULL>");
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
        buffer+=oaString("<oaOccBitTerm::");
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
oaOccBitTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccBitTerm v1;
    PyParamoaOccBitTerm v2;
    int convert_status1=PyoaOccBitTerm_Convert(ob1,&v1);
    int convert_status2=PyoaOccBitTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccBitTerm_Convert(PyObject* ob,PyParamoaOccBitTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccBitTerm_Check(ob)) {
        result->SetData( (oaOccBitTerm**) ((PyoaOccBitTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccBitTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccBitTerm_FromoaOccBitTerm(oaOccBitTerm** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccBitTerm* data=*value;
        if (data->getType()==oacOccScalarTermType) return PyoaOccScalarTerm_FromoaOccScalarTerm((oaOccScalarTerm**)value,borrow,lock);
        if (data->getType()==oacOccBusTermBitType) return PyoaOccBusTermBit_FromoaOccBusTermBit((oaOccBusTermBit**)value,borrow,lock);
        PyObject* bself = PyoaOccBitTerm_Type.tp_alloc(&PyoaOccBitTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaOccBitTermObject* self = (PyoaOccBitTermObject*)bself;
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
PyObject* PyoaOccBitTerm_FromoaOccBitTerm(oaOccBitTerm* data)
{
    if (data) {
        if (data->getType()==oacOccScalarTermType) return PyoaOccScalarTerm_FromoaOccScalarTerm((oaOccScalarTerm*)data);
        if (data->getType()==oacOccBusTermBitType) return PyoaOccBusTermBit_FromoaOccBusTermBit((oaOccBusTermBit*)data);
       PyObject* bself = PyoaOccBitTerm_Type.tp_alloc(&PyoaOccBitTerm_Type,0);
       if (bself == NULL) return bself;
       PyoaOccBitTermObject* self = (PyoaOccBitTermObject*)bself;
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
static char oaOccBitTerm_getConnectDef_doc[] = 
"Class: oaOccBitTerm, Function: getConnectDef\n"
"  Paramegers: ()\n"
"    Calls: oaOccTermConnectDef* getConnectDef() const\n"
"    Signature: getConnectDef|ptr-oaOccTermConnectDef|\n"
"    BrowseData: 1\n"
"    This function returns the connection definition associated with this occurrence terminal. It returns NULL if no connection definition has been set on this terminal. The connection definition determines how to search up the instances in a hierarchy to find a default connection for this terminal. See oaOccConnectDef for more details.\n"
;

static PyObject*
oaOccBitTerm_getConnectDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBitTerm data;
    int convert_status=PyoaOccBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBitTermObject* self=(PyoaOccBitTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaOccTermConnectDefp result= (data.DataCall()->getConnectDef());
        return PyoaOccTermConnectDef_FromoaOccTermConnectDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBitTerm_isNull_doc[] =
"Class: oaOccBitTerm, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccBitTerm_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccBitTerm data;
    int convert_status=PyoaOccBitTerm_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccBitTerm_assign_doc[] = 
"Class: oaOccBitTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccBitTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccBitTerm data;
  int convert_status=PyoaOccBitTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccBitTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccBitTerm_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccBitTerm_methodlist[] = {
    {"getConnectDef",(PyCFunction)oaOccBitTerm_getConnectDef,METH_VARARGS,oaOccBitTerm_getConnectDef_doc},
    {"isNull",(PyCFunction)oaOccBitTerm_tp_isNull,METH_VARARGS,oaOccBitTerm_isNull_doc},
    {"assign",(PyCFunction)oaOccBitTerm_tp_assign,METH_VARARGS,oaOccBitTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBitTerm_doc[] = 
"Class: oaOccBitTerm\n"
"  The oaOccBitTerm class is the base class for single-bit terminals that are part of the design's occurrence description.\n"
"Constructors:\n"
"  Paramegers: (oaOccBitTerm)\n"
"    Calls: (const oaOccBitTerm&)\n"
"    Signature: oaOccBitTerm||cref-oaOccBitTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccBitTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccBitTerm",
    sizeof(PyoaOccBitTermObject),
    0,
    (destructor)oaOccBitTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccBitTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaOccBitTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccBitTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccBitTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccTerm_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccBitTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccBitTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccBitTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaOccBitTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccBitTerm",
           (PyObject*)(&PyoaOccBitTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccBitTerm\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaOccBundleNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccBundleNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccBundleNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccBundleNetObject* self = (PyoaOccBundleNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccBundleNet)
    {
        PyParamoaOccBundleNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccBundleNet_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccBundleNet, Choices are:\n"
        "    (oaOccBundleNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccBundleNet_tp_dealloc(PyoaOccBundleNetObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccBundleNet_tp_repr(PyObject *ob)
{
    PyParamoaOccBundleNet value;
    int convert_status=PyoaOccBundleNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaOccBundleNet::NULL>");
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
        buffer+=oaString("<oaOccBundleNet::");
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
oaOccBundleNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccBundleNet v1;
    PyParamoaOccBundleNet v2;
    int convert_status1=PyoaOccBundleNet_Convert(ob1,&v1);
    int convert_status2=PyoaOccBundleNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccBundleNet_Convert(PyObject* ob,PyParamoaOccBundleNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccBundleNet_Check(ob)) {
        result->SetData( (oaOccBundleNet**) ((PyoaOccBundleNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccBundleNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccBundleNet_FromoaOccBundleNet(oaOccBundleNet** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccBundleNet* data=*value;
        PyObject* bself = PyoaOccBundleNet_Type.tp_alloc(&PyoaOccBundleNet_Type,0);
        if (bself == NULL) return bself;
        PyoaOccBundleNetObject* self = (PyoaOccBundleNetObject*)bself;
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
PyObject* PyoaOccBundleNet_FromoaOccBundleNet(oaOccBundleNet* data)
{
    if (data) {
       PyObject* bself = PyoaOccBundleNet_Type.tp_alloc(&PyoaOccBundleNet_Type,0);
       if (bself == NULL) return bself;
       PyoaOccBundleNetObject* self = (PyoaOccBundleNetObject*)bself;
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
static char oaOccBundleNet_getMember_doc[] = 
"Class: oaOccBundleNet, Function: getMember\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaOccNet* getMember(oaUInt4 index) const\n"
"    Signature: getMember|ptr-oaOccNet|simple-oaUInt4,\n"
"    This function returns the specified member of this net at the specified bundle member index.\n"
"    memIndex\n"
"    The bundle member index of the net to be returned.\n"
"    A pointer to an oaModNet\n"
"    oacInvalidBundleNetMemberIndex\n"
;

static PyObject*
oaOccBundleNet_getMember(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBundleNet data;
    int convert_status=PyoaOccBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBundleNetObject* self=(PyoaOccBundleNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        oaOccNetp result= (data.DataCall()->getMember(p1.Data()));
        return PyoaOccNet_FromoaOccNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBundleNet_getMembers_doc[] = 
"Class: oaOccBundleNet, Function: getMembers\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaOccNet_oaOccBundleNet getMembers() const\n"
"    Signature: getMembers|simple-oaCollection_oaOccNet_oaOccBundleNet|\n"
"    BrowseData: 1\n"
"    This function returns a collection of the member nets in this oaOccBundleNet.\n"
;

static PyObject*
oaOccBundleNet_getMembers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBundleNet data;
    int convert_status=PyoaOccBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBundleNetObject* self=(PyoaOccBundleNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaOccNet_oaOccBundleNet* result= new oaCollection_oaOccNet_oaOccBundleNet(data.DataCall()->getMembers());
        return PyoaCollection_oaOccNet_oaOccBundleNet_FromoaCollection_oaOccNet_oaOccBundleNet(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBundleNet_getMembersIter_doc[] = 
"Class: oaOccBundleNet, Function: getMembersIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaOccNet getMembersIter() const\n"
"    Signature: getMembersIter|simple-oaIter_oaOccNet|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of the member nets in this oaOccBundleNet.\n"
;

static PyObject*
oaOccBundleNet_getMembersIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBundleNet data;
    int convert_status=PyoaOccBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBundleNetObject* self=(PyoaOccBundleNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaOccNet* result= new oaIter_oaOccNet(data.DataCall()->getMembers());
        return PyoaIter_oaOccNet_FromoaIter_oaOccNet(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBundleNet_getModNet_doc[] = 
"Class: oaOccBundleNet, Function: getModNet\n"
"  Paramegers: ()\n"
"    Calls: oaModBundleNet* getModNet() const\n"
"    Signature: getModNet|ptr-oaModBundleNet|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the corresponding net in the module domain. NULL will be returned if this net is an occurrence of a physical-only net.\n"
"    A pointer to an oaModNet\n"
;

static PyObject*
oaOccBundleNet_getModNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBundleNet data;
    int convert_status=PyoaOccBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBundleNetObject* self=(PyoaOccBundleNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaModBundleNetp result= (data.DataCall()->getModNet());
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
static char oaOccBundleNet_getName_doc[] = 
"Class: oaOccBundleNet, Function: getName\n"
"  Paramegers: (oaBundleName)\n"
"    Calls: void getName(oaBundleName& name) const\n"
"    Signature: getName|void-void|ref-oaBundleName,\n"
"    BrowseData: 0,oaBundleName\n"
"    This function returns the name of this occBundleNet.\n"
"    name\n"
"    The name of the occBundleNet to return\n"
"  Paramegers: (oaName)\n"
"    Calls: void getName(oaName& name) const\n"
"    Signature: getName|void-void|ref-oaName,\n"
"    BrowseData: 0,oaName\n"
"    This function returns the local name of this net within its parent occurrence.\n"
"    name\n"
"    The returned net name\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getName(const oaNameSpace& ns,oaString& name) const\n"
"    Signature: getName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the local name of this net in the specified nameSpace in the specified name string. The name is relative to the parent occurrence of this net.\n"
"    ns\n"
"    The nameSpace used to map the name\n"
"    name\n"
"    The returned net name\n"
;

static PyObject*
oaOccBundleNet_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBundleNet data;
    int convert_status=PyoaOccBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBundleNetObject* self=(PyoaOccBundleNetObject*)ob;
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
        "No Arg-Matching Function found for class: oaOccBundleNet, function: getName, Choices are:\n"
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
static char oaOccBundleNet_getNet_doc[] = 
"Class: oaOccBundleNet, Function: getNet\n"
"  Paramegers: ()\n"
"    Calls: oaBundleNet* getNet() const\n"
"    Signature: getNet|ptr-oaBundleNet|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the corresponding net in the block domain. NULL is returned if this occurrence net is not visible to the block domain.\n"
"    A pointer to an oaNet\n"
;

static PyObject*
oaOccBundleNet_getNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBundleNet data;
    int convert_status=PyoaOccBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBundleNetObject* self=(PyoaOccBundleNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBundleNetp result= (data.DataCall()->getNet());
        return PyoaBundleNet_FromoaBundleNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBundleNet_getNumMembers_doc[] = 
"Class: oaOccBundleNet, Function: getNumMembers\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumMembers() const\n"
"    Signature: getNumMembers|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of members in this oaOccBundleNet. Each member net in an oaOccBundleNet can repeat.\n"
;

static PyObject*
oaOccBundleNet_getNumMembers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBundleNet data;
    int convert_status=PyoaOccBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBundleNetObject* self=(PyoaOccBundleNetObject*)ob;
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
static char oaOccBundleNet_getPathName_doc[] = 
"Class: oaOccBundleNet, Function: getPathName\n"
"  Paramegers: (oaBundleName)\n"
"    Calls: void getPathName(oaBundleName& pathName) const\n"
"    Signature: getPathName|void-void|ref-oaBundleName,\n"
"    BrowseData: 0,oaBundleName\n"
"    This function returns the full path name of this bundleNet, relative to the top occurrence in the occurrence hierarchy containing this bundleNet.\n"
"    pathName\n"
"    The pathName of the occBundleNet to return\n"
"  Paramegers: (oaName)\n"
"    Calls: void getPathName(oaName& pathName) const\n"
"    Signature: getPathName|void-void|ref-oaName,\n"
"    BrowseData: 0,oaName\n"
"    This function returns the full path name of this net, relative to the top occurrence in the occurrence hierarchy containing this net.\n"
"    pathName\n"
"    The returned path name\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getPathName(const oaNameSpace& ns,oaString& pathName) const\n"
"    Signature: getPathName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the full path name of this net in the specified nameSpace in the specified pathName string. The pathName is relative to the top occurrence in the occurrence hierarchy containing this net.\n"
"    ns\n"
"    The nameSpace used to map the name\n"
"    pathName\n"
"    The returned path name\n"
;

static PyObject*
oaOccBundleNet_getPathName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBundleNet data;
    int convert_status=PyoaOccBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBundleNetObject* self=(PyoaOccBundleNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaBundleName)
    {
        PyParamoaBundleName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBundleName_Convert,&p1)) {
            data.DataCall()->getPathName(p1.Data());
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
            data.DataCall()->getPathName(p1.Data());
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
            data.DataCall()->getPathName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaOccBundleNet, function: getPathName, Choices are:\n"
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
static char oaOccBundleNet_getRepeat_doc[] = 
"Class: oaOccBundleNet, Function: getRepeat\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaUInt4 getRepeat(oaUInt4 index) const\n"
"    Signature: getRepeat|simple-oaUInt4|simple-oaUInt4,\n"
"    This function returns the repeat count for the specified member of this oaOccBundleNet.\n"
"    For example, for oaOccBundleNet a,b,c , the repeat count for each member is one. An oaOccBundleNet x,100*y[0:1] contains two members, and the repeat count for the second member is 100. The number of bits for the net is 201.\n"
"    memIndex\n"
"    The member number for which to return the repeat count\n"
"    An unsigned value indicating the repeat count for the specified member of the oaOccBundleNet\n"
"    oacInvalidBundleNetMemberIndex\n"
;

static PyObject*
oaOccBundleNet_getRepeat(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBundleNet data;
    int convert_status=PyoaOccBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBundleNetObject* self=(PyoaOccBundleNetObject*)ob;
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
static char oaOccBundleNet_isNull_doc[] =
"Class: oaOccBundleNet, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccBundleNet_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccBundleNet data;
    int convert_status=PyoaOccBundleNet_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccBundleNet_assign_doc[] = 
"Class: oaOccBundleNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccBundleNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccBundleNet data;
  int convert_status=PyoaOccBundleNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccBundleNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccBundleNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccBundleNet_methodlist[] = {
    {"getMember",(PyCFunction)oaOccBundleNet_getMember,METH_VARARGS,oaOccBundleNet_getMember_doc},
    {"getMembers",(PyCFunction)oaOccBundleNet_getMembers,METH_VARARGS,oaOccBundleNet_getMembers_doc},
    {"getMembersIter",(PyCFunction)oaOccBundleNet_getMembersIter,METH_VARARGS,oaOccBundleNet_getMembersIter_doc},
    {"getModNet",(PyCFunction)oaOccBundleNet_getModNet,METH_VARARGS,oaOccBundleNet_getModNet_doc},
    {"getName",(PyCFunction)oaOccBundleNet_getName,METH_VARARGS,oaOccBundleNet_getName_doc},
    {"getNet",(PyCFunction)oaOccBundleNet_getNet,METH_VARARGS,oaOccBundleNet_getNet_doc},
    {"getNumMembers",(PyCFunction)oaOccBundleNet_getNumMembers,METH_VARARGS,oaOccBundleNet_getNumMembers_doc},
    {"getPathName",(PyCFunction)oaOccBundleNet_getPathName,METH_VARARGS,oaOccBundleNet_getPathName_doc},
    {"getRepeat",(PyCFunction)oaOccBundleNet_getRepeat,METH_VARARGS,oaOccBundleNet_getRepeat_doc},
    {"isNull",(PyCFunction)oaOccBundleNet_tp_isNull,METH_VARARGS,oaOccBundleNet_isNull_doc},
    {"assign",(PyCFunction)oaOccBundleNet_tp_assign,METH_VARARGS,oaOccBundleNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBundleNet_doc[] = 
"Class: oaOccBundleNet\n"
"  This class implements a multi-bit net composed of one or more scalar nets, bus nets, or a combination of both. When an oaOccBundleNet is created, all member nets specified as part of the bundle name expression are added to it. The constituent scalar nets and bus nets are automatically created as implicit nets if they do not already exist.\n"
"Constructors:\n"
"  Paramegers: (oaOccBundleNet)\n"
"    Calls: (const oaOccBundleNet&)\n"
"    Signature: oaOccBundleNet||cref-oaOccBundleNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccBundleNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccBundleNet",
    sizeof(PyoaOccBundleNetObject),
    0,
    (destructor)oaOccBundleNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccBundleNet_tp_compare,	/* tp_compare */
    (reprfunc)oaOccBundleNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccBundleNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccBundleNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccNet_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccBundleNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBundleNet_static_find_doc[] = 
"Class: oaOccBundleNet, Function: find\n"
"  Paramegers: (oaOccurrence,oaBundleName)\n"
"    Calls: oaOccBundleNet* find(const oaOccurrence* occurrence,const oaBundleName& name)\n"
"    Signature: find|ptr-oaOccBundleNet|cptr-oaOccurrence,cref-oaBundleName,\n"
"    This function searches the specified occurrence looking for a bundleNet with the specified name . If the members of name are hierarchical, this function will descend into lower levels of occurrence hierarchy, expanding the hierarchy and binding the master designs as needed. If any of the members of name are hierarchical, every member must have the same hierarchical path or an exception is thrown. The bundleNet is returned if found, otherwise NULL is returned.\n"
"    occurrence\n"
"    The occurrence in which to search\n"
"    name\n"
"    The name of the bundle to find\n"
"    A pointer to the oaOccBundleNet\n"
;

static PyObject*
oaOccBundleNet_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccurrence p1;
    PyParamoaBundleName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaOccurrence_Convert,&p1,
          &PyoaBundleName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaOccBundleNetp result= (oaOccBundleNet::find(p1.Data(),p2.Data()));
        return PyoaOccBundleNet_FromoaOccBundleNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaOccBundleNet_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaOccBundleNet_static_find,METH_VARARGS,oaOccBundleNet_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccBundleNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccBundleNet_Type)<0) {
      printf("** PyType_Ready failed for: oaOccBundleNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccBundleNet",
           (PyObject*)(&PyoaOccBundleNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccBundleNet\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaOccBundleNet_Type.tp_dict;
    for(method=oaOccBundleNet_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaOccBundleTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccBundleTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccBundleTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccBundleTermObject* self = (PyoaOccBundleTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccBundleTerm)
    {
        PyParamoaOccBundleTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccBundleTerm_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccBundleTerm, Choices are:\n"
        "    (oaOccBundleTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccBundleTerm_tp_dealloc(PyoaOccBundleTermObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccBundleTerm_tp_repr(PyObject *ob)
{
    PyParamoaOccBundleTerm value;
    int convert_status=PyoaOccBundleTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaOccBundleTerm::NULL>");
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
        buffer+=oaString("<oaOccBundleTerm::");
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
oaOccBundleTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccBundleTerm v1;
    PyParamoaOccBundleTerm v2;
    int convert_status1=PyoaOccBundleTerm_Convert(ob1,&v1);
    int convert_status2=PyoaOccBundleTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccBundleTerm_Convert(PyObject* ob,PyParamoaOccBundleTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccBundleTerm_Check(ob)) {
        result->SetData( (oaOccBundleTerm**) ((PyoaOccBundleTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccBundleTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccBundleTerm_FromoaOccBundleTerm(oaOccBundleTerm** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccBundleTerm* data=*value;
        PyObject* bself = PyoaOccBundleTerm_Type.tp_alloc(&PyoaOccBundleTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaOccBundleTermObject* self = (PyoaOccBundleTermObject*)bself;
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
PyObject* PyoaOccBundleTerm_FromoaOccBundleTerm(oaOccBundleTerm* data)
{
    if (data) {
       PyObject* bself = PyoaOccBundleTerm_Type.tp_alloc(&PyoaOccBundleTerm_Type,0);
       if (bself == NULL) return bself;
       PyoaOccBundleTermObject* self = (PyoaOccBundleTermObject*)bself;
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
static char oaOccBundleTerm_getMember_doc[] = 
"Class: oaOccBundleTerm, Function: getMember\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaOccTerm* getMember(oaUInt4 index) const\n"
"    Signature: getMember|ptr-oaOccTerm|simple-oaUInt4,\n"
"    This function returns the memIndex member of this bundleTerm.\n"
"    memIndex\n"
"    The bundle member index of the member term to get\n"
"    A pointer to an oaOccTerm\n"
"    oacInvalidBundleTermMemberIndex\n"
;

static PyObject*
oaOccBundleTerm_getMember(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBundleTerm data;
    int convert_status=PyoaOccBundleTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBundleTermObject* self=(PyoaOccBundleTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        oaOccTermp result= (data.DataCall()->getMember(p1.Data()));
        return PyoaOccTerm_FromoaOccTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBundleTerm_getMembers_doc[] = 
"Class: oaOccBundleTerm, Function: getMembers\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaOccTerm_oaOccBundleTerm getMembers() const\n"
"    Signature: getMembers|simple-oaCollection_oaOccTerm_oaOccBundleTerm|\n"
"    BrowseData: 1\n"
"    This function returns a collection of member terms in this bundleTerm.\n"
;

static PyObject*
oaOccBundleTerm_getMembers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBundleTerm data;
    int convert_status=PyoaOccBundleTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBundleTermObject* self=(PyoaOccBundleTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaOccTerm_oaOccBundleTerm* result= new oaCollection_oaOccTerm_oaOccBundleTerm(data.DataCall()->getMembers());
        return PyoaCollection_oaOccTerm_oaOccBundleTerm_FromoaCollection_oaOccTerm_oaOccBundleTerm(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBundleTerm_getMembersIter_doc[] = 
"Class: oaOccBundleTerm, Function: getMembersIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaOccTerm getMembersIter() const\n"
"    Signature: getMembersIter|simple-oaIter_oaOccTerm|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of member terms in this bundleTerm.\n"
;

static PyObject*
oaOccBundleTerm_getMembersIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBundleTerm data;
    int convert_status=PyoaOccBundleTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBundleTermObject* self=(PyoaOccBundleTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaOccTerm* result= new oaIter_oaOccTerm(data.DataCall()->getMembers());
        return PyoaIter_oaOccTerm_FromoaIter_oaOccTerm(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBundleTerm_getModTerm_doc[] = 
"Class: oaOccBundleTerm, Function: getModTerm\n"
"  Paramegers: ()\n"
"    Calls: oaModBundleTerm* getModTerm() const\n"
"    Signature: getModTerm|ptr-oaModBundleTerm|\n"
"    BrowseData: 1\n"
"    This function returns the module terminal corresponding to this occurrence terminal if there is one. There is always either a module terminal or a block terminal ( oaBundleTerm ) or both. It returns NULL if there is no corresponding oaModBundleTerm .\n"
;

static PyObject*
oaOccBundleTerm_getModTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBundleTerm data;
    int convert_status=PyoaOccBundleTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBundleTermObject* self=(PyoaOccBundleTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaModBundleTermp result= (data.DataCall()->getModTerm());
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
static char oaOccBundleTerm_getName_doc[] = 
"Class: oaOccBundleTerm, Function: getName\n"
"  Paramegers: (oaBundleName)\n"
"    Calls: void getName(oaBundleName& name) const\n"
"    Signature: getName|void-void|ref-oaBundleName,\n"
"    BrowseData: 0,oaBundleName\n"
"    This function returns the name of this occBundleTerm.\n"
"    name\n"
"    The name of the occBundleTerm to return\n"
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
oaOccBundleTerm_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBundleTerm data;
    int convert_status=PyoaOccBundleTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBundleTermObject* self=(PyoaOccBundleTermObject*)ob;
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
        "No Arg-Matching Function found for class: oaOccBundleTerm, function: getName, Choices are:\n"
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
static char oaOccBundleTerm_getNumMembers_doc[] = 
"Class: oaOccBundleTerm, Function: getNumMembers\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumMembers() const\n"
"    Signature: getNumMembers|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of members in this bundleTerm.\n"
"    The number of member terminals in this bundleTerm\n"
;

static PyObject*
oaOccBundleTerm_getNumMembers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBundleTerm data;
    int convert_status=PyoaOccBundleTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBundleTermObject* self=(PyoaOccBundleTermObject*)ob;
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
static char oaOccBundleTerm_getTerm_doc[] = 
"Class: oaOccBundleTerm, Function: getTerm\n"
"  Paramegers: ()\n"
"    Calls: oaBundleTerm* getTerm() const\n"
"    Signature: getTerm|ptr-oaBundleTerm|\n"
"    BrowseData: 1\n"
"    This function returns the bundle terminal in the block domain that corresponds to this occurrence terminal if there is one. There is always either a module terminal ( oaModBundleTerm ) or a block terminal or both. It returns NULL if there is no corresponding oaBundleTerm .\n"
;

static PyObject*
oaOccBundleTerm_getTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBundleTerm data;
    int convert_status=PyoaOccBundleTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBundleTermObject* self=(PyoaOccBundleTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBundleTermp result= (data.DataCall()->getTerm());
        return PyoaBundleTerm_FromoaBundleTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBundleTerm_isNull_doc[] =
"Class: oaOccBundleTerm, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccBundleTerm_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccBundleTerm data;
    int convert_status=PyoaOccBundleTerm_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccBundleTerm_assign_doc[] = 
"Class: oaOccBundleTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccBundleTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccBundleTerm data;
  int convert_status=PyoaOccBundleTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccBundleTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccBundleTerm_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccBundleTerm_methodlist[] = {
    {"getMember",(PyCFunction)oaOccBundleTerm_getMember,METH_VARARGS,oaOccBundleTerm_getMember_doc},
    {"getMembers",(PyCFunction)oaOccBundleTerm_getMembers,METH_VARARGS,oaOccBundleTerm_getMembers_doc},
    {"getMembersIter",(PyCFunction)oaOccBundleTerm_getMembersIter,METH_VARARGS,oaOccBundleTerm_getMembersIter_doc},
    {"getModTerm",(PyCFunction)oaOccBundleTerm_getModTerm,METH_VARARGS,oaOccBundleTerm_getModTerm_doc},
    {"getName",(PyCFunction)oaOccBundleTerm_getName,METH_VARARGS,oaOccBundleTerm_getName_doc},
    {"getNumMembers",(PyCFunction)oaOccBundleTerm_getNumMembers,METH_VARARGS,oaOccBundleTerm_getNumMembers_doc},
    {"getTerm",(PyCFunction)oaOccBundleTerm_getTerm,METH_VARARGS,oaOccBundleTerm_getTerm_doc},
    {"isNull",(PyCFunction)oaOccBundleTerm_tp_isNull,METH_VARARGS,oaOccBundleTerm_isNull_doc},
    {"assign",(PyCFunction)oaOccBundleTerm_tp_assign,METH_VARARGS,oaOccBundleTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBundleTerm_doc[] = 
"Class: oaOccBundleTerm\n"
"  The oaOccBundleTerm class implements a multi-bit terminal for an occurrence with a name that is composed of one or more scalars or one or more busses, or a combination of scalars and busses. Its constituent occScalarTerms and occBusTermBits are automatically created as implicit terminals if they do not already exist. oaOccBundleTerm objects are associated with occurrence nets ( oaOccNet ) to represent connectivity. The number of bits implied by the name of the oaOccBundleTerm and the name of its oaOccNet must match.\n"
"  oaModBundleTerm , oaOccBundleTerm, and oaBundleTerm each represent bundle terminals in a different kind of hierarchy. In each case the master represents a level of hierarchy in the design. For oaOccBundleTerm, the master is an oaOccurrence , which corresponds to a unique usage of a module or a block in a design. Each oaOccurrence in a design will have a set of zero or more occBundleTerms.\n"
"  oaOccTerms are created automatically to reflect oaTerms and oaModTerms. When an oaBundleTerm is created in the block domain an oaOccBundleTerm is created automatically in the occurrence domain. When an oaModBundleTerm is created in the module domain an oaOccBundleTerm is created if that module is in the hierarchy under its design's top module.\n"
"Constructors:\n"
"  Paramegers: (oaOccBundleTerm)\n"
"    Calls: (const oaOccBundleTerm&)\n"
"    Signature: oaOccBundleTerm||cref-oaOccBundleTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccBundleTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccBundleTerm",
    sizeof(PyoaOccBundleTermObject),
    0,
    (destructor)oaOccBundleTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccBundleTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaOccBundleTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccBundleTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccBundleTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccTerm_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccBundleTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBundleTerm_static_find_doc[] = 
"Class: oaOccBundleTerm, Function: find\n"
"  Paramegers: (oaOccurrence,oaBundleName)\n"
"    Calls: oaOccBundleTerm* find(const oaOccurrence* occurrence,const oaBundleName& name)\n"
"    Signature: find|ptr-oaOccBundleTerm|cptr-oaOccurrence,cref-oaBundleName,\n"
"    This function searches the specified occurrence for a bundleTerm with the given name . The bundleTerm is returned if it exists. Otherwise, NULL is returned.\n"
"    occ\n"
"    The occurrence to search\n"
"    name\n"
"    The name of the terminal\n"
"    A pointer to an oaOccBundleTerm if found; otherwise, NULL is returned\n"
;

static PyObject*
oaOccBundleTerm_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccurrence p1;
    PyParamoaBundleName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaOccurrence_Convert,&p1,
          &PyoaBundleName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaOccBundleTermp result= (oaOccBundleTerm::find(p1.Data(),p2.Data()));
        return PyoaOccBundleTerm_FromoaOccBundleTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaOccBundleTerm_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaOccBundleTerm_static_find,METH_VARARGS,oaOccBundleTerm_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccBundleTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccBundleTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaOccBundleTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccBundleTerm",
           (PyObject*)(&PyoaOccBundleTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccBundleTerm\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaOccBundleTerm_Type.tp_dict;
    for(method=oaOccBundleTerm_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaOccBusNet
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccBusNet_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccBusNet_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccBusNetObject* self = (PyoaOccBusNetObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccBusNet)
    {
        PyParamoaOccBusNet p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccBusNet_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccBusNet, Choices are:\n"
        "    (oaOccBusNet)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccBusNet_tp_dealloc(PyoaOccBusNetObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccBusNet_tp_repr(PyObject *ob)
{
    PyParamoaOccBusNet value;
    int convert_status=PyoaOccBusNet_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaOccBusNet::NULL>");
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
        buffer+=oaString("<oaOccBusNet::");
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
oaOccBusNet_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccBusNet v1;
    PyParamoaOccBusNet v2;
    int convert_status1=PyoaOccBusNet_Convert(ob1,&v1);
    int convert_status2=PyoaOccBusNet_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccBusNet_Convert(PyObject* ob,PyParamoaOccBusNet* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccBusNet_Check(ob)) {
        result->SetData( (oaOccBusNet**) ((PyoaOccBusNetObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccBusNet Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccBusNet_FromoaOccBusNet(oaOccBusNet** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccBusNet* data=*value;
        PyObject* bself = PyoaOccBusNet_Type.tp_alloc(&PyoaOccBusNet_Type,0);
        if (bself == NULL) return bself;
        PyoaOccBusNetObject* self = (PyoaOccBusNetObject*)bself;
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
PyObject* PyoaOccBusNet_FromoaOccBusNet(oaOccBusNet* data)
{
    if (data) {
       PyObject* bself = PyoaOccBusNet_Type.tp_alloc(&PyoaOccBusNet_Type,0);
       if (bself == NULL) return bself;
       PyoaOccBusNetObject* self = (PyoaOccBusNetObject*)bself;
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
static char oaOccBusNet_getDef_doc[] = 
"Class: oaOccBusNet, Function: getDef\n"
"  Paramegers: ()\n"
"    Calls: oaOccBusNetDef* getDef() const\n"
"    Signature: getDef|ptr-oaOccBusNetDef|\n"
"    BrowseData: 1\n"
"    This function returns the busNetDef for this busNet.\n"
"    A pointer to an oaOccBusNetDef\n"
;

static PyObject*
oaOccBusNet_getDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNet data;
    int convert_status=PyoaOccBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetObject* self=(PyoaOccBusNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBusNetDefp result= (data.DataCall()->getDef());
        return PyoaOccBusNetDef_FromoaOccBusNetDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBusNet_getModNet_doc[] = 
"Class: oaOccBusNet, Function: getModNet\n"
"  Paramegers: ()\n"
"    Calls: oaModBusNet* getModNet() const\n"
"    Signature: getModNet|ptr-oaModBusNet|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the corresponding net in the module domain. NULL will be returned if this net is an occurrence of a physical-only net.\n"
"    A pointer to an oaModNet\n"
;

static PyObject*
oaOccBusNet_getModNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNet data;
    int convert_status=PyoaOccBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetObject* self=(PyoaOccBusNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusNetp result= (data.DataCall()->getModNet());
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
static char oaOccBusNet_getName_doc[] = 
"Class: oaOccBusNet, Function: getName\n"
"  Paramegers: (oaVectorName)\n"
"    Calls: void getName(oaVectorName& name) const\n"
"    Signature: getName|void-void|ref-oaVectorName,\n"
"    BrowseData: 0,oaVectorName\n"
"    oaOccBusNet::getName()\n"
"    This function returns the name of this occBusNet.\n"
"    name\n"
"    The name of the occBusNet to return\n"
"  Paramegers: (oaName)\n"
"    Calls: void getName(oaName& name) const\n"
"    Signature: getName|void-void|ref-oaName,\n"
"    BrowseData: 0,oaName\n"
"    This function returns the local name of this net within its parent occurrence.\n"
"    name\n"
"    The returned net name\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getName(const oaNameSpace& ns,oaString& name) const\n"
"    Signature: getName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the local name of this net in the specified nameSpace in the specified name string. The name is relative to the parent occurrence of this net.\n"
"    ns\n"
"    The nameSpace used to map the name\n"
"    name\n"
"    The returned net name\n"
;

static PyObject*
oaOccBusNet_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNet data;
    int convert_status=PyoaOccBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetObject* self=(PyoaOccBusNetObject*)ob;
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
        "No Arg-Matching Function found for class: oaOccBusNet, function: getName, Choices are:\n"
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
static char oaOccBusNet_getNet_doc[] = 
"Class: oaOccBusNet, Function: getNet\n"
"  Paramegers: ()\n"
"    Calls: oaBusNet* getNet() const\n"
"    Signature: getNet|ptr-oaBusNet|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the corresponding net in the block domain. NULL is returned if this occurrence net is not visible to the block domain.\n"
"    A pointer to an oaNet\n"
;

static PyObject*
oaOccBusNet_getNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNet data;
    int convert_status=PyoaOccBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetObject* self=(PyoaOccBusNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBusNetp result= (data.DataCall()->getNet());
        return PyoaBusNet_FromoaBusNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBusNet_getPathName_doc[] = 
"Class: oaOccBusNet, Function: getPathName\n"
"  Paramegers: (oaVectorName)\n"
"    Calls: void getPathName(oaVectorName& pathName) const\n"
"    Signature: getPathName|void-void|ref-oaVectorName,\n"
"    BrowseData: 0,oaVectorName\n"
"    This function returns the full path name of this busNet, relative to the top occurrence in the occurrence hierarchy containing this busNet.\n"
"    pathName\n"
"    The pathName of the occBusNet to return\n"
"  Paramegers: (oaName)\n"
"    Calls: void getPathName(oaName& pathName) const\n"
"    Signature: getPathName|void-void|ref-oaName,\n"
"    BrowseData: 0,oaName\n"
"    This function returns the full path name of this net, relative to the top occurrence in the occurrence hierarchy containing this net.\n"
"    pathName\n"
"    The returned path name\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getPathName(const oaNameSpace& ns,oaString& pathName) const\n"
"    Signature: getPathName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the full path name of this net in the specified nameSpace in the specified pathName string. The pathName is relative to the top occurrence in the occurrence hierarchy containing this net.\n"
"    ns\n"
"    The nameSpace used to map the name\n"
"    pathName\n"
"    The returned path name\n"
;

static PyObject*
oaOccBusNet_getPathName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNet data;
    int convert_status=PyoaOccBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetObject* self=(PyoaOccBusNetObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaVectorName)
    {
        PyParamoaVectorName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaVectorName_Convert,&p1)) {
            data.DataCall()->getPathName(p1.Data());
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
            data.DataCall()->getPathName(p1.Data());
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
            data.DataCall()->getPathName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaOccBusNet, function: getPathName, Choices are:\n"
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
static char oaOccBusNet_getStart_doc[] = 
"Class: oaOccBusNet, Function: getStart\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getStart() const\n"
"    Signature: getStart|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the starting index for this busNet.\n"
"    The starting index of this busNet\n"
;

static PyObject*
oaOccBusNet_getStart(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNet data;
    int convert_status=PyoaOccBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetObject* self=(PyoaOccBusNetObject*)ob;
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
static char oaOccBusNet_getStep_doc[] = 
"Class: oaOccBusNet, Function: getStep\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getStep() const\n"
"    Signature: getStep|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the step value for this busNet.\n"
"    The step value for this busNet\n"
;

static PyObject*
oaOccBusNet_getStep(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNet data;
    int convert_status=PyoaOccBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetObject* self=(PyoaOccBusNetObject*)ob;
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
static char oaOccBusNet_getStop_doc[] = 
"Class: oaOccBusNet, Function: getStop\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getStop() const\n"
"    Signature: getStop|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the ending index for this busNet.\n"
"    The ending index for this busNet\n"
;

static PyObject*
oaOccBusNet_getStop(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNet data;
    int convert_status=PyoaOccBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetObject* self=(PyoaOccBusNetObject*)ob;
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
static char oaOccBusNet_isNull_doc[] =
"Class: oaOccBusNet, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccBusNet_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccBusNet data;
    int convert_status=PyoaOccBusNet_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccBusNet_assign_doc[] = 
"Class: oaOccBusNet, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccBusNet_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccBusNet data;
  int convert_status=PyoaOccBusNet_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccBusNet p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccBusNet_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccBusNet_methodlist[] = {
    {"getDef",(PyCFunction)oaOccBusNet_getDef,METH_VARARGS,oaOccBusNet_getDef_doc},
    {"getModNet",(PyCFunction)oaOccBusNet_getModNet,METH_VARARGS,oaOccBusNet_getModNet_doc},
    {"getName",(PyCFunction)oaOccBusNet_getName,METH_VARARGS,oaOccBusNet_getName_doc},
    {"getNet",(PyCFunction)oaOccBusNet_getNet,METH_VARARGS,oaOccBusNet_getNet_doc},
    {"getPathName",(PyCFunction)oaOccBusNet_getPathName,METH_VARARGS,oaOccBusNet_getPathName_doc},
    {"getStart",(PyCFunction)oaOccBusNet_getStart,METH_VARARGS,oaOccBusNet_getStart_doc},
    {"getStep",(PyCFunction)oaOccBusNet_getStep,METH_VARARGS,oaOccBusNet_getStep_doc},
    {"getStop",(PyCFunction)oaOccBusNet_getStop,METH_VARARGS,oaOccBusNet_getStop_doc},
    {"isNull",(PyCFunction)oaOccBusNet_tp_isNull,METH_VARARGS,oaOccBusNet_isNull_doc},
    {"assign",(PyCFunction)oaOccBusNet_tp_assign,METH_VARARGS,oaOccBusNet_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBusNet_doc[] = 
"Class: oaOccBusNet\n"
"  The oaOccBusNet class implements a net that can represent one or more bits that are associated with a common base name and vector range specification. A busNet has a corresponding busNetDef that manages all busNets that share the same base name.\n"
"Constructors:\n"
"  Paramegers: (oaOccBusNet)\n"
"    Calls: (const oaOccBusNet&)\n"
"    Signature: oaOccBusNet||cref-oaOccBusNet,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccBusNet_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccBusNet",
    sizeof(PyoaOccBusNetObject),
    0,
    (destructor)oaOccBusNet_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccBusNet_tp_compare,	/* tp_compare */
    (reprfunc)oaOccBusNet_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccBusNet_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccBusNet_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccNet_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccBusNet_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBusNet_static_find_doc[] = 
"Class: oaOccBusNet, Function: find\n"
"  Paramegers: (oaOccurrence,oaScalarName,oaUInt4,oaUInt4,oaUInt4)\n"
"    Calls: oaOccBusNet* find(const oaOccurrence* occurrence,const oaScalarName& baseName,oaUInt4 start,oaUInt4 stop,oaUInt4 step)\n"
"    Signature: find|ptr-oaOccBusNet|cptr-oaOccurrence,cref-oaScalarName,simple-oaUInt4,simple-oaUInt4,simple-oaUInt4,\n"
"    This function searches the specified occurrence for a busNet with the specified baseName and start, stop, step indices. If baseName is hierarchical, this function will descend into lower levels of occurrence hierarchy, expanding the hierarchy and binding the master designs as needed. The busNet is returned if found, otherwise NULL is returned.\n"
"    occurrence\n"
"    The occurrence in which to search\n"
"    baseName\n"
"    The base name for the net\n"
"    start\n"
"    The starting index of the net\n"
"    stop\n"
"    The stopping index of the net\n"
"    step\n"
"    The index increment value from start to step; step should be greater than zero\n"
"    A pointer to the oaOccBusNet\n"
;

static PyObject*
oaOccBusNet_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccurrence p1;
    PyParamoaScalarName p2;
    PyParamoaUInt4 p3;
    PyParamoaUInt4 p4;
    PyParamoaUInt4 p5;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&",
          &PyoaOccurrence_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaUInt4_Convert,&p3,
          &PyoaUInt4_Convert,&p4,
          &PyoaUInt4_Convert,&p5)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaOccBusNetp result= (oaOccBusNet::find(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
        return PyoaOccBusNet_FromoaOccBusNet(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaOccBusNet_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaOccBusNet_static_find,METH_VARARGS,oaOccBusNet_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccBusNet_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccBusNet_Type)<0) {
      printf("** PyType_Ready failed for: oaOccBusNet\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccBusNet",
           (PyObject*)(&PyoaOccBusNet_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccBusNet\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaOccBusNet_Type.tp_dict;
    for(method=oaOccBusNet_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaOccBusNetBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccBusNetBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccBusNetBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccBusNetBitObject* self = (PyoaOccBusNetBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccBusNetBit)
    {
        PyParamoaOccBusNetBit p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccBusNetBit_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccBusNetBit, Choices are:\n"
        "    (oaOccBusNetBit)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccBusNetBit_tp_dealloc(PyoaOccBusNetBitObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccBusNetBit_tp_repr(PyObject *ob)
{
    PyParamoaOccBusNetBit value;
    int convert_status=PyoaOccBusNetBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaOccBusNetBit::NULL>");
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
        buffer+=oaString("<oaOccBusNetBit::");
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
oaOccBusNetBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccBusNetBit v1;
    PyParamoaOccBusNetBit v2;
    int convert_status1=PyoaOccBusNetBit_Convert(ob1,&v1);
    int convert_status2=PyoaOccBusNetBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccBusNetBit_Convert(PyObject* ob,PyParamoaOccBusNetBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccBusNetBit_Check(ob)) {
        result->SetData( (oaOccBusNetBit**) ((PyoaOccBusNetBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccBusNetBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccBusNetBit_FromoaOccBusNetBit(oaOccBusNetBit** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccBusNetBit* data=*value;
        PyObject* bself = PyoaOccBusNetBit_Type.tp_alloc(&PyoaOccBusNetBit_Type,0);
        if (bself == NULL) return bself;
        PyoaOccBusNetBitObject* self = (PyoaOccBusNetBitObject*)bself;
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
PyObject* PyoaOccBusNetBit_FromoaOccBusNetBit(oaOccBusNetBit* data)
{
    if (data) {
       PyObject* bself = PyoaOccBusNetBit_Type.tp_alloc(&PyoaOccBusNetBit_Type,0);
       if (bself == NULL) return bself;
       PyoaOccBusNetBitObject* self = (PyoaOccBusNetBitObject*)bself;
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
static char oaOccBusNetBit_getBitIndex_doc[] = 
"Class: oaOccBusNetBit, Function: getBitIndex\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getBitIndex() const\n"
"    Signature: getBitIndex|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the index for this busNetBit. Returns can include non-consecutive numbers.\n"
;

static PyObject*
oaOccBusNetBit_getBitIndex(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNetBit data;
    int convert_status=PyoaOccBusNetBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetBitObject* self=(PyoaOccBusNetBitObject*)ob;
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
static char oaOccBusNetBit_getDef_doc[] = 
"Class: oaOccBusNetBit, Function: getDef\n"
"  Paramegers: ()\n"
"    Calls: oaOccBusNetDef* getDef() const\n"
"    Signature: getDef|ptr-oaOccBusNetDef|\n"
"    BrowseData: 1\n"
"    This function returns the busNetDef associated with this busNetBit.\n"
;

static PyObject*
oaOccBusNetBit_getDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNetBit data;
    int convert_status=PyoaOccBusNetBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetBitObject* self=(PyoaOccBusNetBitObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBusNetDefp result= (data.DataCall()->getDef());
        return PyoaOccBusNetDef_FromoaOccBusNetDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBusNetBit_getModNet_doc[] = 
"Class: oaOccBusNetBit, Function: getModNet\n"
"  Paramegers: ()\n"
"    Calls: oaModBusNetBit* getModNet() const\n"
"    Signature: getModNet|ptr-oaModBusNetBit|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the corresponding net in the module domain. NULL will be returned if this net is an occurrence of a physical-only net.\n"
"    A pointer to an oaModNet\n"
;

static PyObject*
oaOccBusNetBit_getModNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNetBit data;
    int convert_status=PyoaOccBusNetBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetBitObject* self=(PyoaOccBusNetBitObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusNetBitp result= (data.DataCall()->getModNet());
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
static char oaOccBusNetBit_getName_doc[] = 
"Class: oaOccBusNetBit, Function: getName\n"
"  Paramegers: (oaVectorBitName)\n"
"    Calls: void getName(oaVectorBitName& name) const\n"
"    Signature: getName|void-void|ref-oaVectorBitName,\n"
"    BrowseData: 0,oaVectorBitName\n"
"    This function returns the name of this occBusNetBit.\n"
"    name\n"
"    The name of the occBusNetBit to return\n"
"  Paramegers: (oaName)\n"
"    Calls: void getName(oaName& name) const\n"
"    Signature: getName|void-void|ref-oaName,\n"
"    BrowseData: 0,oaName\n"
"    This function returns the local name of this net within its parent occurrence.\n"
"    name\n"
"    The returned net name\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getName(const oaNameSpace& ns,oaString& name) const\n"
"    Signature: getName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the local name of this net in the specified nameSpace in the specified name string. The name is relative to the parent occurrence of this net.\n"
"    ns\n"
"    The nameSpace used to map the name\n"
"    name\n"
"    The returned net name\n"
;

static PyObject*
oaOccBusNetBit_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNetBit data;
    int convert_status=PyoaOccBusNetBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetBitObject* self=(PyoaOccBusNetBitObject*)ob;
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
        "No Arg-Matching Function found for class: oaOccBusNetBit, function: getName, Choices are:\n"
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
static char oaOccBusNetBit_getNet_doc[] = 
"Class: oaOccBusNetBit, Function: getNet\n"
"  Paramegers: ()\n"
"    Calls: oaBusNetBit* getNet() const\n"
"    Signature: getNet|ptr-oaBusNetBit|\n"
"    BrowseData: 1\n"
"    This function returns a pointer to the corresponding net in the block domain. NULL is returned if this occurrence net is not visible to the block domain.\n"
"    A pointer to an oaNet\n"
;

static PyObject*
oaOccBusNetBit_getNet(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNetBit data;
    int convert_status=PyoaOccBusNetBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetBitObject* self=(PyoaOccBusNetBitObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBusNetBitp result= (data.DataCall()->getNet());
        return PyoaBusNetBit_FromoaBusNetBit(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBusNetBit_getPathName_doc[] = 
"Class: oaOccBusNetBit, Function: getPathName\n"
"  Paramegers: (oaVectorBitName)\n"
"    Calls: void getPathName(oaVectorBitName& pathName) const\n"
"    Signature: getPathName|void-void|ref-oaVectorBitName,\n"
"    BrowseData: 0,oaVectorBitName\n"
"    This function returns the full path name of this busNetBit, relative to the top occurrence in the occurrence hierarchy containing this busNetBit.\n"
"    pathName\n"
"    The pathName of the occBusNetBit to return\n"
"  Paramegers: (oaName)\n"
"    Calls: void getPathName(oaName& pathName) const\n"
"    Signature: getPathName|void-void|ref-oaName,\n"
"    BrowseData: 0,oaName\n"
"    This function returns the full path name of this net, relative to the top occurrence in the occurrence hierarchy containing this net.\n"
"    pathName\n"
"    The returned path name\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getPathName(const oaNameSpace& ns,oaString& pathName) const\n"
"    Signature: getPathName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the full path name of this net in the specified nameSpace in the specified pathName string. The pathName is relative to the top occurrence in the occurrence hierarchy containing this net.\n"
"    ns\n"
"    The nameSpace used to map the name\n"
"    pathName\n"
"    The returned path name\n"
;

static PyObject*
oaOccBusNetBit_getPathName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNetBit data;
    int convert_status=PyoaOccBusNetBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetBitObject* self=(PyoaOccBusNetBitObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaVectorBitName)
    {
        PyParamoaVectorBitName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaVectorBitName_Convert,&p1)) {
            data.DataCall()->getPathName(p1.Data());
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
            data.DataCall()->getPathName(p1.Data());
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
            data.DataCall()->getPathName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaOccBusNetBit, function: getPathName, Choices are:\n"
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
static char oaOccBusNetBit_isNull_doc[] =
"Class: oaOccBusNetBit, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccBusNetBit_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccBusNetBit data;
    int convert_status=PyoaOccBusNetBit_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccBusNetBit_assign_doc[] = 
"Class: oaOccBusNetBit, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccBusNetBit_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccBusNetBit data;
  int convert_status=PyoaOccBusNetBit_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccBusNetBit p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccBusNetBit_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccBusNetBit_methodlist[] = {
    {"getBitIndex",(PyCFunction)oaOccBusNetBit_getBitIndex,METH_VARARGS,oaOccBusNetBit_getBitIndex_doc},
    {"getDef",(PyCFunction)oaOccBusNetBit_getDef,METH_VARARGS,oaOccBusNetBit_getDef_doc},
    {"getModNet",(PyCFunction)oaOccBusNetBit_getModNet,METH_VARARGS,oaOccBusNetBit_getModNet_doc},
    {"getName",(PyCFunction)oaOccBusNetBit_getName,METH_VARARGS,oaOccBusNetBit_getName_doc},
    {"getNet",(PyCFunction)oaOccBusNetBit_getNet,METH_VARARGS,oaOccBusNetBit_getNet_doc},
    {"getPathName",(PyCFunction)oaOccBusNetBit_getPathName,METH_VARARGS,oaOccBusNetBit_getPathName_doc},
    {"isNull",(PyCFunction)oaOccBusNetBit_tp_isNull,METH_VARARGS,oaOccBusNetBit_isNull_doc},
    {"assign",(PyCFunction)oaOccBusNetBit_tp_assign,METH_VARARGS,oaOccBusNetBit_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBusNetBit_doc[] = 
"Class: oaOccBusNetBit\n"
"  The oaOccBusNetBit class implements an oaOccBitNet that represents a single bit of an oaOccBusNet which is a busNet in the occurrence domain. When a busNet is created in either the block or module domain, a corresponding set of busNetBits is automatically created and corresponding occurrence busNetBits are also created. When the busNet is destroyed, the automatically created busNetBits are also destroyed.\n"
"  oaModBusNetBit , oaOccBusNetmBit, and oaBusNetBit each represent a bit of a busNet on a different kind of master, where in each case the master represents a level of hierarchy in the design.\n"
"  For oaModBusNetBit , the master is a module, and each module in a design will have a set of zero or more oaModBusNetBits. For oaOccBusNetBit, the master is an oaOccurrence .\n"
"  For oaBusNet , the master is an oaBlock , and the top block for the design will have a set of zero or more modBusNetBits. Typically, many of the oaBusNetBits on the top oaBlock have a corresponding oaModBusNetBit on the top oaModule . All of the oaBusNetBits on the top oaBlock have a corresponding oaOccBusNetBit on the top oaOccurrence .\n"
"  When oaBusNetBit objects are created in the block domain, the corresponding oaModBusNetBit objects are automatically created on the top oaModule .\n"
"Constructors:\n"
"  Paramegers: (oaOccBusNetBit)\n"
"    Calls: (const oaOccBusNetBit&)\n"
"    Signature: oaOccBusNetBit||cref-oaOccBusNetBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccBusNetBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccBusNetBit",
    sizeof(PyoaOccBusNetBitObject),
    0,
    (destructor)oaOccBusNetBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccBusNetBit_tp_compare,	/* tp_compare */
    (reprfunc)oaOccBusNetBit_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccBusNetBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccBusNetBit_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccBitNet_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccBusNetBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBusNetBit_static_find_doc[] = 
"Class: oaOccBusNetBit, Function: find\n"
"  Paramegers: (oaOccurrence,oaScalarName,oaUInt4)\n"
"    Calls: oaOccBusNetBit* find(const oaOccurrence* occurrence,const oaScalarName& baseName,oaUInt4 bitIndex)\n"
"    Signature: find|ptr-oaOccBusNetBit|cptr-oaOccurrence,cref-oaScalarName,simple-oaUInt4,\n"
"    This function searches the specified occurrence looking for a busNetBit with the specified baseName and bitIndex . If baseName is hierarchical, this function will descend into lower levels of occurrence hierarchy, expanding the hierarchy and binding the master designs as needed. The busNetBit is returned if found, otherwise NULL is returned.\n"
"    occurrence\n"
"    The occurrence in which to search\n"
"    baseName\n"
"    The base name of the busNetBit to find\n"
"    bitIndex\n"
"    The bit index of the busNetBit to find\n"
"    A pointer to the oaOccBusNetBit\n"
;

static PyObject*
oaOccBusNetBit_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccurrence p1;
    PyParamoaScalarName p2;
    PyParamoaUInt4 p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaOccurrence_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaUInt4_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaOccBusNetBitp result= (oaOccBusNetBit::find(p1.Data(),p2.Data(),p3.Data()));
        return PyoaOccBusNetBit_FromoaOccBusNetBit(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaOccBusNetBit_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaOccBusNetBit_static_find,METH_VARARGS,oaOccBusNetBit_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccBusNetBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccBusNetBit_Type)<0) {
      printf("** PyType_Ready failed for: oaOccBusNetBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccBusNetBit",
           (PyObject*)(&PyoaOccBusNetBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccBusNetBit\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaOccBusNetBit_Type.tp_dict;
    for(method=oaOccBusNetBit_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaOccBusNetDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccBusNetDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccBusNetDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccBusNetDefObject* self = (PyoaOccBusNetDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccBusNetDef)
    {
        PyParamoaOccBusNetDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccBusNetDef_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccBusNetDef, Choices are:\n"
        "    (oaOccBusNetDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccBusNetDef_tp_dealloc(PyoaOccBusNetDefObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccBusNetDef_tp_repr(PyObject *ob)
{
    PyParamoaOccBusNetDef value;
    int convert_status=PyoaOccBusNetDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaOccBusNetDef::NULL>");
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
        buffer+=oaString("<oaOccBusNetDef::");
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
oaOccBusNetDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccBusNetDef v1;
    PyParamoaOccBusNetDef v2;
    int convert_status1=PyoaOccBusNetDef_Convert(ob1,&v1);
    int convert_status2=PyoaOccBusNetDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccBusNetDef_Convert(PyObject* ob,PyParamoaOccBusNetDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccBusNetDef_Check(ob)) {
        result->SetData( (oaOccBusNetDef**) ((PyoaOccBusNetDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccBusNetDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccBusNetDef_FromoaOccBusNetDef(oaOccBusNetDef** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccBusNetDef* data=*value;
        PyObject* bself = PyoaOccBusNetDef_Type.tp_alloc(&PyoaOccBusNetDef_Type,0);
        if (bself == NULL) return bself;
        PyoaOccBusNetDefObject* self = (PyoaOccBusNetDefObject*)bself;
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
PyObject* PyoaOccBusNetDef_FromoaOccBusNetDef(oaOccBusNetDef* data)
{
    if (data) {
       PyObject* bself = PyoaOccBusNetDef_Type.tp_alloc(&PyoaOccBusNetDef_Type,0);
       if (bself == NULL) return bself;
       PyoaOccBusNetDefObject* self = (PyoaOccBusNetDefObject*)bself;
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
static char oaOccBusNetDef_getBitOrder_doc[] = 
"Class: oaOccBusNetDef, Function: getBitOrder\n"
"  Paramegers: ()\n"
"    Calls: oaBitOrder getBitOrder() const\n"
"    Signature: getBitOrder|simple-oaBitOrder|\n"
"    BrowseData: 1\n"
"    This function returns the bitOrder associated with this oaOccBusNetDef.\n"
;

static PyObject*
oaOccBusNetDef_getBitOrder(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNetDef data;
    int convert_status=PyoaOccBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetDefObject* self=(PyoaOccBusNetDefObject*)ob;
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
static char oaOccBusNetDef_getBusNetBits_doc[] = 
"Class: oaOccBusNetDef, Function: getBusNetBits\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaOccBusNetBit_oaOccBusNetDef getBusNetBits() const\n"
"    Signature: getBusNetBits|simple-oaCollection_oaOccBusNetBit_oaOccBusNetDef|\n"
"    BrowseData: 1\n"
"    This function returns a collection of oaOccBusNetBit objects in this oaOccBusNetDef object.\n"
;

static PyObject*
oaOccBusNetDef_getBusNetBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNetDef data;
    int convert_status=PyoaOccBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetDefObject* self=(PyoaOccBusNetDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaOccBusNetBit_oaOccBusNetDef* result= new oaCollection_oaOccBusNetBit_oaOccBusNetDef(data.DataCall()->getBusNetBits());
        return PyoaCollection_oaOccBusNetBit_oaOccBusNetDef_FromoaCollection_oaOccBusNetBit_oaOccBusNetDef(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBusNetDef_getBusNetBitsIter_doc[] = 
"Class: oaOccBusNetDef, Function: getBusNetBitsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaOccBusNetBit getBusNetBitsIter() const\n"
"    Signature: getBusNetBitsIter|simple-oaIter_oaOccBusNetBit|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of oaOccBusNetBit objects in this oaOccBusNetDef object.\n"
;

static PyObject*
oaOccBusNetDef_getBusNetBitsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNetDef data;
    int convert_status=PyoaOccBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetDefObject* self=(PyoaOccBusNetDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaOccBusNetBit* result= new oaIter_oaOccBusNetBit(data.DataCall()->getBusNetBits());
        return PyoaIter_oaOccBusNetBit_FromoaIter_oaOccBusNetBit(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBusNetDef_getBusNets_doc[] = 
"Class: oaOccBusNetDef, Function: getBusNets\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaOccBusNet_oaOccBusNetDef getBusNets() const\n"
"    Signature: getBusNets|simple-oaCollection_oaOccBusNet_oaOccBusNetDef|\n"
"    BrowseData: 1\n"
"    This function returns a collection of oaOccBusNet objects in this oaOccBusNetDef object.\n"
;

static PyObject*
oaOccBusNetDef_getBusNets(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNetDef data;
    int convert_status=PyoaOccBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetDefObject* self=(PyoaOccBusNetDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaOccBusNet_oaOccBusNetDef* result= new oaCollection_oaOccBusNet_oaOccBusNetDef(data.DataCall()->getBusNets());
        return PyoaCollection_oaOccBusNet_oaOccBusNetDef_FromoaCollection_oaOccBusNet_oaOccBusNetDef(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBusNetDef_getBusNetsIter_doc[] = 
"Class: oaOccBusNetDef, Function: getBusNetsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaOccBusNet getBusNetsIter() const\n"
"    Signature: getBusNetsIter|simple-oaIter_oaOccBusNet|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of oaOccBusNet objects in this oaOccBusNetDef object.\n"
;

static PyObject*
oaOccBusNetDef_getBusNetsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNetDef data;
    int convert_status=PyoaOccBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetDefObject* self=(PyoaOccBusNetDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaOccBusNet* result= new oaIter_oaOccBusNet(data.DataCall()->getBusNets());
        return PyoaIter_oaOccBusNet_FromoaIter_oaOccBusNet(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBusNetDef_getMaxIndex_doc[] = 
"Class: oaOccBusNetDef, Function: getMaxIndex\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getMaxIndex() const\n"
"    Signature: getMaxIndex|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the largest bit number in use for this oaOccBusNetDef object. This is the largest index used across all busNets associated with this oaOccBusNetDef object.\n"
;

static PyObject*
oaOccBusNetDef_getMaxIndex(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNetDef data;
    int convert_status=PyoaOccBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetDefObject* self=(PyoaOccBusNetDefObject*)ob;
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
static char oaOccBusNetDef_getMinIndex_doc[] = 
"Class: oaOccBusNetDef, Function: getMinIndex\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getMinIndex() const\n"
"    Signature: getMinIndex|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the smallest bit number in use for this oaOccBusNetDef object. This is the smallest index used across all busNets associated with this oaOccBusNetDef object.\n"
;

static PyObject*
oaOccBusNetDef_getMinIndex(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNetDef data;
    int convert_status=PyoaOccBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetDefObject* self=(PyoaOccBusNetDefObject*)ob;
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
static char oaOccBusNetDef_getName_doc[] = 
"Class: oaOccBusNetDef, Function: getName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getName(oaScalarName& name) const\n"
"    Signature: getName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the local name of this busNetDef within its parent occurrence.\n"
"    name\n"
"    The returned busNetDef name\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getName(const oaNameSpace& ns,oaString& name) const\n"
"    Signature: getName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the local name of this busNetDef in the specified nameSpace in the specified name string. The name is relative to the parent occurrence of this busNetDef.\n"
"    ns\n"
"    The nameSpace used to map the name\n"
"    name\n"
"    The returned busNetDef name\n"
;

static PyObject*
oaOccBusNetDef_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNetDef data;
    int convert_status=PyoaOccBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetDefObject* self=(PyoaOccBusNetDefObject*)ob;
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
        "No Arg-Matching Function found for class: oaOccBusNetDef, function: getName, Choices are:\n"
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
static char oaOccBusNetDef_getNumBits_doc[] = 
"Class: oaOccBusNetDef, Function: getNumBits\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumBits() const\n"
"    Signature: getNumBits|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of bits covered by the busses in this oaOccBusNetDef. The number of bits is equal to abs(MSB - LSB) + 1; it is not necessarily the number of busNetBits present in this busNetDef. To get the number of busNetBits in this busnetDef, use oaOccBusNetDef::getBusNetBits() .getCount()\n"
;

static PyObject*
oaOccBusNetDef_getNumBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNetDef data;
    int convert_status=PyoaOccBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetDefObject* self=(PyoaOccBusNetDefObject*)ob;
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
static char oaOccBusNetDef_getPathName_doc[] = 
"Class: oaOccBusNetDef, Function: getPathName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getPathName(oaScalarName& pathName) const\n"
"    Signature: getPathName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the full path name of this busNetDef, relative to the top occurrence in the occurrence hierarchy containing this busNetDef.\n"
"    pathName\n"
"    The returned path name\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getPathName(const oaNameSpace& ns,oaString& pathName) const\n"
"    Signature: getPathName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the full path name of this busNetDef in the specified nameSpace in the specified pathName string. The pathName is relative to the top occurrence in the occurrence hierarchy containing this busNetDef.\n"
"    ns\n"
"    The nameSpace used to map the name\n"
"    pathName\n"
"    The returned path name\n"
;

static PyObject*
oaOccBusNetDef_getPathName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNetDef data;
    int convert_status=PyoaOccBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetDefObject* self=(PyoaOccBusNetDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaScalarName)
    {
        PyParamoaScalarName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaScalarName_Convert,&p1)) {
            data.DataCall()->getPathName(p1.Data());
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
            data.DataCall()->getPathName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaOccBusNetDef, function: getPathName, Choices are:\n"
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
static char oaOccBusNetDef_isImplicit_doc[] = 
"Class: oaOccBusNetDef, Function: isImplicit\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isImplicit() const\n"
"    Signature: isImplicit|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether this oaOccBusNetDef was implicitly created or not.\n"
;

static PyObject*
oaOccBusNetDef_isImplicit(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusNetDef data;
    int convert_status=PyoaOccBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusNetDefObject* self=(PyoaOccBusNetDefObject*)ob;
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
static char oaOccBusNetDef_isNull_doc[] =
"Class: oaOccBusNetDef, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccBusNetDef_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccBusNetDef data;
    int convert_status=PyoaOccBusNetDef_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccBusNetDef_assign_doc[] = 
"Class: oaOccBusNetDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccBusNetDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccBusNetDef data;
  int convert_status=PyoaOccBusNetDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccBusNetDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccBusNetDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccBusNetDef_methodlist[] = {
    {"getBitOrder",(PyCFunction)oaOccBusNetDef_getBitOrder,METH_VARARGS,oaOccBusNetDef_getBitOrder_doc},
    {"getBusNetBits",(PyCFunction)oaOccBusNetDef_getBusNetBits,METH_VARARGS,oaOccBusNetDef_getBusNetBits_doc},
    {"getBusNetBitsIter",(PyCFunction)oaOccBusNetDef_getBusNetBitsIter,METH_VARARGS,oaOccBusNetDef_getBusNetBitsIter_doc},
    {"getBusNets",(PyCFunction)oaOccBusNetDef_getBusNets,METH_VARARGS,oaOccBusNetDef_getBusNets_doc},
    {"getBusNetsIter",(PyCFunction)oaOccBusNetDef_getBusNetsIter,METH_VARARGS,oaOccBusNetDef_getBusNetsIter_doc},
    {"getMaxIndex",(PyCFunction)oaOccBusNetDef_getMaxIndex,METH_VARARGS,oaOccBusNetDef_getMaxIndex_doc},
    {"getMinIndex",(PyCFunction)oaOccBusNetDef_getMinIndex,METH_VARARGS,oaOccBusNetDef_getMinIndex_doc},
    {"getName",(PyCFunction)oaOccBusNetDef_getName,METH_VARARGS,oaOccBusNetDef_getName_doc},
    {"getNumBits",(PyCFunction)oaOccBusNetDef_getNumBits,METH_VARARGS,oaOccBusNetDef_getNumBits_doc},
    {"getPathName",(PyCFunction)oaOccBusNetDef_getPathName,METH_VARARGS,oaOccBusNetDef_getPathName_doc},
    {"isImplicit",(PyCFunction)oaOccBusNetDef_isImplicit,METH_VARARGS,oaOccBusNetDef_isImplicit_doc},
    {"isNull",(PyCFunction)oaOccBusNetDef_tp_isNull,METH_VARARGS,oaOccBusNetDef_isNull_doc},
    {"assign",(PyCFunction)oaOccBusNetDef_tp_assign,METH_VARARGS,oaOccBusNetDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBusNetDef_doc[] = 
"Class: oaOccBusNetDef\n"
"  The oaOccBusNetDef class implements the definition of an occurrence busNet, including its base name and bit-range. All busNets in an occurrence with the same base name are managed by the same busNet definition. The oaOccBusNetDef class tracks the minimum and maximum indices referred to by all of its corresponding busNet and busNetBit objects.\n"
"  A busNetDef can be 'sparse' (have missing bits). Busses do not have to start or end at zero. For example, a<22:25> is a legal bus name. Bus indexes must be non-negative.\n"
"  The oaOccBusNetDef class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaOccBusNetDef)\n"
"    Calls: (const oaOccBusNetDef&)\n"
"    Signature: oaOccBusNetDef||cref-oaOccBusNetDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccBusNetDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccBusNetDef",
    sizeof(PyoaOccBusNetDefObject),
    0,
    (destructor)oaOccBusNetDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccBusNetDef_tp_compare,	/* tp_compare */
    (reprfunc)oaOccBusNetDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccBusNetDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccBusNetDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccBusNetDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBusNetDef_static_find_doc[] = 
"Class: oaOccBusNetDef, Function: find\n"
"  Paramegers: (oaOccurrence,oaScalarName)\n"
"    Calls: oaOccBusNetDef* find(const oaOccurrence* occurrence,const oaScalarName& name)\n"
"    Signature: find|ptr-oaOccBusNetDef|cptr-oaOccurrence,cref-oaScalarName,\n"
"    This function searches the specified occurrence looking for a busNetDef with the specified baseName . If baseName is hierarchical, this function will descend into lower levels of occurrence hierarchy, expanding the hierarchy and binding the master designs as needed. The busNetDef is returned if found, otherwise NULL is returned.\n"
"    occurrence\n"
"    The occurrence in which to search\n"
"    baseName\n"
"    The base name of the busNetDef to find\n"
"    A pointer to the oaOccBusNetDef\n"
;

static PyObject*
oaOccBusNetDef_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccurrence p1;
    PyParamoaScalarName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaOccurrence_Convert,&p1,
          &PyoaScalarName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaOccBusNetDefp result= (oaOccBusNetDef::find(p1.Data(),p2.Data()));
        return PyoaOccBusNetDef_FromoaOccBusNetDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaOccBusNetDef_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaOccBusNetDef_static_find,METH_VARARGS,oaOccBusNetDef_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccBusNetDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccBusNetDef_Type)<0) {
      printf("** PyType_Ready failed for: oaOccBusNetDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccBusNetDef",
           (PyObject*)(&PyoaOccBusNetDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccBusNetDef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaOccBusNetDef_Type.tp_dict;
    for(method=oaOccBusNetDef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaOccBusTerm
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccBusTerm_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccBusTerm_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccBusTermObject* self = (PyoaOccBusTermObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccBusTerm)
    {
        PyParamoaOccBusTerm p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccBusTerm_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccBusTerm, Choices are:\n"
        "    (oaOccBusTerm)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccBusTerm_tp_dealloc(PyoaOccBusTermObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccBusTerm_tp_repr(PyObject *ob)
{
    PyParamoaOccBusTerm value;
    int convert_status=PyoaOccBusTerm_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaOccBusTerm::NULL>");
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
        buffer+=oaString("<oaOccBusTerm::");
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
oaOccBusTerm_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccBusTerm v1;
    PyParamoaOccBusTerm v2;
    int convert_status1=PyoaOccBusTerm_Convert(ob1,&v1);
    int convert_status2=PyoaOccBusTerm_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccBusTerm_Convert(PyObject* ob,PyParamoaOccBusTerm* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccBusTerm_Check(ob)) {
        result->SetData( (oaOccBusTerm**) ((PyoaOccBusTermObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccBusTerm Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccBusTerm_FromoaOccBusTerm(oaOccBusTerm** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccBusTerm* data=*value;
        PyObject* bself = PyoaOccBusTerm_Type.tp_alloc(&PyoaOccBusTerm_Type,0);
        if (bself == NULL) return bself;
        PyoaOccBusTermObject* self = (PyoaOccBusTermObject*)bself;
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
PyObject* PyoaOccBusTerm_FromoaOccBusTerm(oaOccBusTerm* data)
{
    if (data) {
       PyObject* bself = PyoaOccBusTerm_Type.tp_alloc(&PyoaOccBusTerm_Type,0);
       if (bself == NULL) return bself;
       PyoaOccBusTermObject* self = (PyoaOccBusTermObject*)bself;
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
static char oaOccBusTerm_getDef_doc[] = 
"Class: oaOccBusTerm, Function: getDef\n"
"  Paramegers: ()\n"
"    Calls: oaOccBusTermDef* getDef() const\n"
"    Signature: getDef|ptr-oaOccBusTermDef|\n"
"    BrowseData: 1\n"
"    This function returns the oaOccBusTermDef for this oaOccBusTerm object.\n"
"    A pointer to an oaOccBusTermDef\n"
;

static PyObject*
oaOccBusTerm_getDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTerm data;
    int convert_status=PyoaOccBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermObject* self=(PyoaOccBusTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBusTermDefp result= (data.DataCall()->getDef());
        return PyoaOccBusTermDef_FromoaOccBusTermDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBusTerm_getModTerm_doc[] = 
"Class: oaOccBusTerm, Function: getModTerm\n"
"  Paramegers: ()\n"
"    Calls: oaModBusTerm* getModTerm() const\n"
"    Signature: getModTerm|ptr-oaModBusTerm|\n"
"    BrowseData: 1\n"
"    This function returns the corresponding terminal in the module domain, or NULL if the terminal is not visible in the module domain.\n"
;

static PyObject*
oaOccBusTerm_getModTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTerm data;
    int convert_status=PyoaOccBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermObject* self=(PyoaOccBusTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusTermp result= (data.DataCall()->getModTerm());
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
static char oaOccBusTerm_getName_doc[] = 
"Class: oaOccBusTerm, Function: getName\n"
"  Paramegers: (oaVectorName)\n"
"    Calls: void getName(oaVectorName& name) const\n"
"    Signature: getName|void-void|ref-oaVectorName,\n"
"    BrowseData: 0,oaVectorName\n"
"    This function returns the name of this occBusTerm.\n"
"    name\n"
"    The name of the occBusTerm to return\n"
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
oaOccBusTerm_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTerm data;
    int convert_status=PyoaOccBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermObject* self=(PyoaOccBusTermObject*)ob;
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
        "No Arg-Matching Function found for class: oaOccBusTerm, function: getName, Choices are:\n"
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
static char oaOccBusTerm_getStart_doc[] = 
"Class: oaOccBusTerm, Function: getStart\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getStart() const\n"
"    Signature: getStart|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the starting index for this oaOccBusTerm object.\n"
"    The starting index for this oaOccBusTerm\n"
;

static PyObject*
oaOccBusTerm_getStart(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTerm data;
    int convert_status=PyoaOccBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermObject* self=(PyoaOccBusTermObject*)ob;
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
static char oaOccBusTerm_getStep_doc[] = 
"Class: oaOccBusTerm, Function: getStep\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getStep() const\n"
"    Signature: getStep|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the stepping index for this oaOccBusTerm object.\n"
"    The step value for this oaOccBusTerm\n"
;

static PyObject*
oaOccBusTerm_getStep(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTerm data;
    int convert_status=PyoaOccBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermObject* self=(PyoaOccBusTermObject*)ob;
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
static char oaOccBusTerm_getStop_doc[] = 
"Class: oaOccBusTerm, Function: getStop\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getStop() const\n"
"    Signature: getStop|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the ending index for this oaOccBusTerm object.\n"
"    The ending index for this oaOccBusTerm\n"
;

static PyObject*
oaOccBusTerm_getStop(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTerm data;
    int convert_status=PyoaOccBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermObject* self=(PyoaOccBusTermObject*)ob;
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
static char oaOccBusTerm_getTerm_doc[] = 
"Class: oaOccBusTerm, Function: getTerm\n"
"  Paramegers: ()\n"
"    Calls: oaBusTerm* getTerm() const\n"
"    Signature: getTerm|ptr-oaBusTerm|\n"
"    BrowseData: 1\n"
"    This function returns the corresponding terminal in the block domain, or NULL if the terminal is not visible in the block domain.\n"
;

static PyObject*
oaOccBusTerm_getTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTerm data;
    int convert_status=PyoaOccBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermObject* self=(PyoaOccBusTermObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBusTermp result= (data.DataCall()->getTerm());
        return PyoaBusTerm_FromoaBusTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBusTerm_isNull_doc[] =
"Class: oaOccBusTerm, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccBusTerm_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccBusTerm data;
    int convert_status=PyoaOccBusTerm_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccBusTerm_assign_doc[] = 
"Class: oaOccBusTerm, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccBusTerm_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccBusTerm data;
  int convert_status=PyoaOccBusTerm_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccBusTerm p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccBusTerm_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccBusTerm_methodlist[] = {
    {"getDef",(PyCFunction)oaOccBusTerm_getDef,METH_VARARGS,oaOccBusTerm_getDef_doc},
    {"getModTerm",(PyCFunction)oaOccBusTerm_getModTerm,METH_VARARGS,oaOccBusTerm_getModTerm_doc},
    {"getName",(PyCFunction)oaOccBusTerm_getName,METH_VARARGS,oaOccBusTerm_getName_doc},
    {"getStart",(PyCFunction)oaOccBusTerm_getStart,METH_VARARGS,oaOccBusTerm_getStart_doc},
    {"getStep",(PyCFunction)oaOccBusTerm_getStep,METH_VARARGS,oaOccBusTerm_getStep_doc},
    {"getStop",(PyCFunction)oaOccBusTerm_getStop,METH_VARARGS,oaOccBusTerm_getStop_doc},
    {"getTerm",(PyCFunction)oaOccBusTerm_getTerm,METH_VARARGS,oaOccBusTerm_getTerm_doc},
    {"isNull",(PyCFunction)oaOccBusTerm_tp_isNull,METH_VARARGS,oaOccBusTerm_isNull_doc},
    {"assign",(PyCFunction)oaOccBusTerm_tp_assign,METH_VARARGS,oaOccBusTerm_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBusTerm_doc[] = 
"Class: oaOccBusTerm\n"
"  The oaOccBusTerm class implements a terminal in the occurrence domain that represents one or more bits that are associated by a common baseName and vector-range specification. An oaOccBusTerm object has a corresponding oaOccBusTermDef object that manages all oaOccBusTerm objects that share the same baseName.\n"
"  oaModBusTerm , oaOccBusTerm, and oaBusTerm each represent bus terminals on a different kind of master, where in each case the master represents a level of hierarchy in the design.\n"
"  For oaOccBusTerm, the master is an oaOccurrence , which corresponds to a unique usage of a module or a block in a design. Each oaOccurrence in a design will have a set of zero or more occBusTerms.\n"
"  For oaModBusTerm , the master is an oaModule . For oaBusTerm , the master is an oaBlock , and the top block for the design will have a set of zero or more modBusTerms. Typically, many of the oaBusTerms on the top oaBlock have a corresponding oaModBusTerm on the top oaModule . The top oaOccurrence will have a corresponding oaOccBusTerm for each busTerm in the union of the terminals between the top oaModule and the top oaBlock .\n"
"  When oaBusTerm objects are created in the block domain, the corresponding oaOccBusTerm objects are automatically created on the top oaOccurrence .\n"
"Constructors:\n"
"  Paramegers: (oaOccBusTerm)\n"
"    Calls: (const oaOccBusTerm&)\n"
"    Signature: oaOccBusTerm||cref-oaOccBusTerm,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccBusTerm_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccBusTerm",
    sizeof(PyoaOccBusTermObject),
    0,
    (destructor)oaOccBusTerm_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccBusTerm_tp_compare,	/* tp_compare */
    (reprfunc)oaOccBusTerm_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccBusTerm_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccBusTerm_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccTerm_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccBusTerm_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBusTerm_static_find_doc[] = 
"Class: oaOccBusTerm, Function: find\n"
"  Paramegers: (oaOccurrence,oaScalarName,oaUInt4,oaUInt4,oaUInt4)\n"
"    Calls: oaOccBusTerm* find(const oaOccurrence* occurrence,const oaScalarName& name,oaUInt4 start,oaUInt4 stop,oaUInt4 step)\n"
"    Signature: find|ptr-oaOccBusTerm|cptr-oaOccurrence,cref-oaScalarName,simple-oaUInt4,simple-oaUInt4,simple-oaUInt4,\n"
"    This function searches the specified occ for an oaOccBusTerm object with the specified baseName and start , stop , and step indices. The oaOccBusTerm object is returned if found. Otherwise, NULL is returned.\n"
"    occ\n"
"    The occurrence to search for the oaOccBusTerm\n"
"    baseName\n"
"    The baseName for the oaOccBusTerm\n"
"    start\n"
"    The starting index of the oaOccBusTerm\n"
"    stop\n"
"    The stopping index of the oaOccBusTerm\n"
"    step\n"
"    The step value of the oaOccBusTerm\n"
"    A pointer to an oaOccBusTerm\n"
;

static PyObject*
oaOccBusTerm_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccurrence p1;
    PyParamoaScalarName p2;
    PyParamoaUInt4 p3;
    PyParamoaUInt4 p4;
    PyParamoaUInt4 p5;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&",
          &PyoaOccurrence_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaUInt4_Convert,&p3,
          &PyoaUInt4_Convert,&p4,
          &PyoaUInt4_Convert,&p5)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaOccBusTermp result= (oaOccBusTerm::find(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data()));
        return PyoaOccBusTerm_FromoaOccBusTerm(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaOccBusTerm_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaOccBusTerm_static_find,METH_VARARGS,oaOccBusTerm_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccBusTerm_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccBusTerm_Type)<0) {
      printf("** PyType_Ready failed for: oaOccBusTerm\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccBusTerm",
           (PyObject*)(&PyoaOccBusTerm_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccBusTerm\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaOccBusTerm_Type.tp_dict;
    for(method=oaOccBusTerm_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaOccBusTermBit
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccBusTermBit_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccBusTermBit_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccBusTermBitObject* self = (PyoaOccBusTermBitObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccBusTermBit)
    {
        PyParamoaOccBusTermBit p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccBusTermBit_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccBusTermBit, Choices are:\n"
        "    (oaOccBusTermBit)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccBusTermBit_tp_dealloc(PyoaOccBusTermBitObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccBusTermBit_tp_repr(PyObject *ob)
{
    PyParamoaOccBusTermBit value;
    int convert_status=PyoaOccBusTermBit_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaOccBusTermBit::NULL>");
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
        buffer+=oaString("<oaOccBusTermBit::");
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
oaOccBusTermBit_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccBusTermBit v1;
    PyParamoaOccBusTermBit v2;
    int convert_status1=PyoaOccBusTermBit_Convert(ob1,&v1);
    int convert_status2=PyoaOccBusTermBit_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccBusTermBit_Convert(PyObject* ob,PyParamoaOccBusTermBit* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccBusTermBit_Check(ob)) {
        result->SetData( (oaOccBusTermBit**) ((PyoaOccBusTermBitObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccBusTermBit Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccBusTermBit_FromoaOccBusTermBit(oaOccBusTermBit** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccBusTermBit* data=*value;
        PyObject* bself = PyoaOccBusTermBit_Type.tp_alloc(&PyoaOccBusTermBit_Type,0);
        if (bself == NULL) return bself;
        PyoaOccBusTermBitObject* self = (PyoaOccBusTermBitObject*)bself;
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
PyObject* PyoaOccBusTermBit_FromoaOccBusTermBit(oaOccBusTermBit* data)
{
    if (data) {
       PyObject* bself = PyoaOccBusTermBit_Type.tp_alloc(&PyoaOccBusTermBit_Type,0);
       if (bself == NULL) return bself;
       PyoaOccBusTermBitObject* self = (PyoaOccBusTermBitObject*)bself;
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
static char oaOccBusTermBit_getBitIndex_doc[] = 
"Class: oaOccBusTermBit, Function: getBitIndex\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getBitIndex() const\n"
"    Signature: getBitIndex|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the index for this busTermBit.\n"
;

static PyObject*
oaOccBusTermBit_getBitIndex(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTermBit data;
    int convert_status=PyoaOccBusTermBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermBitObject* self=(PyoaOccBusTermBitObject*)ob;
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
static char oaOccBusTermBit_getDef_doc[] = 
"Class: oaOccBusTermBit, Function: getDef\n"
"  Paramegers: ()\n"
"    Calls: oaOccBusTermDef* getDef() const\n"
"    Signature: getDef|ptr-oaOccBusTermDef|\n"
"    BrowseData: 1\n"
"    This function returns the occBusTermDef associated with this terminal.\n"
;

static PyObject*
oaOccBusTermBit_getDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTermBit data;
    int convert_status=PyoaOccBusTermBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermBitObject* self=(PyoaOccBusTermBitObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaOccBusTermDefp result= (data.DataCall()->getDef());
        return PyoaOccBusTermDef_FromoaOccBusTermDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBusTermBit_getModTerm_doc[] = 
"Class: oaOccBusTermBit, Function: getModTerm\n"
"  Paramegers: ()\n"
"    Calls: oaModBusTermBit* getModTerm() const\n"
"    Signature: getModTerm|ptr-oaModBusTermBit|\n"
"    BrowseData: 1\n"
"    This function returns the corresponding terminal in the module domain, or NULL if the terminal is not visible in the module domain.\n"
;

static PyObject*
oaOccBusTermBit_getModTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTermBit data;
    int convert_status=PyoaOccBusTermBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermBitObject* self=(PyoaOccBusTermBitObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaModBusTermBitp result= (data.DataCall()->getModTerm());
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
static char oaOccBusTermBit_getName_doc[] = 
"Class: oaOccBusTermBit, Function: getName\n"
"  Paramegers: (oaVectorBitName)\n"
"    Calls: void getName(oaVectorBitName& name) const\n"
"    Signature: getName|void-void|ref-oaVectorBitName,\n"
"    BrowseData: 0,oaVectorBitName\n"
"    This function returns the name of this occBusTermBit.\n"
"    name\n"
"    The name of the occBusTermBit to return\n"
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
oaOccBusTermBit_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTermBit data;
    int convert_status=PyoaOccBusTermBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermBitObject* self=(PyoaOccBusTermBitObject*)ob;
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
        "No Arg-Matching Function found for class: oaOccBusTermBit, function: getName, Choices are:\n"
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
static char oaOccBusTermBit_getTerm_doc[] = 
"Class: oaOccBusTermBit, Function: getTerm\n"
"  Paramegers: ()\n"
"    Calls: oaBusTermBit* getTerm() const\n"
"    Signature: getTerm|ptr-oaBusTermBit|\n"
"    BrowseData: 1\n"
"    This function returns the corresponding terminal in the block domain, or NULL if the terminal is not visible in the block domain.\n"
;

static PyObject*
oaOccBusTermBit_getTerm(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTermBit data;
    int convert_status=PyoaOccBusTermBit_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermBitObject* self=(PyoaOccBusTermBitObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBusTermBitp result= (data.DataCall()->getTerm());
        return PyoaBusTermBit_FromoaBusTermBit(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBusTermBit_isNull_doc[] =
"Class: oaOccBusTermBit, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccBusTermBit_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccBusTermBit data;
    int convert_status=PyoaOccBusTermBit_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccBusTermBit_assign_doc[] = 
"Class: oaOccBusTermBit, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccBusTermBit_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccBusTermBit data;
  int convert_status=PyoaOccBusTermBit_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccBusTermBit p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccBusTermBit_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccBusTermBit_methodlist[] = {
    {"getBitIndex",(PyCFunction)oaOccBusTermBit_getBitIndex,METH_VARARGS,oaOccBusTermBit_getBitIndex_doc},
    {"getDef",(PyCFunction)oaOccBusTermBit_getDef,METH_VARARGS,oaOccBusTermBit_getDef_doc},
    {"getModTerm",(PyCFunction)oaOccBusTermBit_getModTerm,METH_VARARGS,oaOccBusTermBit_getModTerm_doc},
    {"getName",(PyCFunction)oaOccBusTermBit_getName,METH_VARARGS,oaOccBusTermBit_getName_doc},
    {"getTerm",(PyCFunction)oaOccBusTermBit_getTerm,METH_VARARGS,oaOccBusTermBit_getTerm_doc},
    {"isNull",(PyCFunction)oaOccBusTermBit_tp_isNull,METH_VARARGS,oaOccBusTermBit_isNull_doc},
    {"assign",(PyCFunction)oaOccBusTermBit_tp_assign,METH_VARARGS,oaOccBusTermBit_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBusTermBit_doc[] = 
"Class: oaOccBusTermBit\n"
"  The oaOccBusTermBit class implements a single bit of an oaOccBusTerm , a busTerm in the occurrence domain. oaModBusTermBit objects are never created or destroyed by applications. oaModBusTermBit objects are created or destroyed automatically as oaOccBusTerm objects are created or destroyed.\n"
"  The oaOccBusTermBits are always implicit terminals. They cannot have their connected net changed with moveToNet(), nor can they have pins created on them.\n"
"  oaOccBusTermBit, oaModBusTermBit , and oaBusTermBit each represent a bit of a busTerminal on a different kind of master, where in each case the master represents a level of hierarchy in the design.\n"
"  For oaOccBusTermBit, the master is an oaOccurrence , and each occurrence in a design will have a set of zero or more oaOccBusTermBits.\n"
"  For oaModBusTermBit , the master is an oaModule . For oaBusTerm , the master is an oaBlock , and the top block for the design will have a set of zero or more modBusTermBits. Typically, many of the oaBusTermBits on the top oaBlock have a corresponding oaModBusTerm on the top oaModule . The top oaOccurrence will have a corresponding oaOccBusTermBit for each busTermBit in the union of the terminals between the top oaModule and the top oaBlock .\n"
"  When oaBusTermBit objects are created in the block domain, the corresponding oaOccBusTermBit objects are automatically created on the top oaOccurrence .\n"
"Constructors:\n"
"  Paramegers: (oaOccBusTermBit)\n"
"    Calls: (const oaOccBusTermBit&)\n"
"    Signature: oaOccBusTermBit||cref-oaOccBusTermBit,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccBusTermBit_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccBusTermBit",
    sizeof(PyoaOccBusTermBitObject),
    0,
    (destructor)oaOccBusTermBit_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccBusTermBit_tp_compare,	/* tp_compare */
    (reprfunc)oaOccBusTermBit_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccBusTermBit_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccBusTermBit_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccBitTerm_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccBusTermBit_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBusTermBit_static_find_doc[] = 
"Class: oaOccBusTermBit, Function: find\n"
"  Paramegers: (oaOccurrence,oaScalarName,oaUInt4)\n"
"    Calls: oaOccBusTermBit* find(const oaOccurrence* occurrence,const oaScalarName& baseName,oaUInt4 bitIndex)\n"
"    Signature: find|ptr-oaOccBusTermBit|cptr-oaOccurrence,cref-oaScalarName,simple-oaUInt4,\n"
"    This function searches the specified occurrence for a busTermBit with the specified baseName and bitIndex . The busTermBit is returned if found. Otherwise, NULL is returned.\n"
"    occ\n"
"    The occurrence to search for the busTermBit\n"
"    baseName\n"
"    The base name for the busTermBit\n"
"    bitIndex\n"
"    The bit index for the busTermBit\n"
"    A pointer to an oaOccBusTermBit\n"
;

static PyObject*
oaOccBusTermBit_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccurrence p1;
    PyParamoaScalarName p2;
    PyParamoaUInt4 p3;
    if (PyArg_ParseTuple(args,"O&O&O&",
          &PyoaOccurrence_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaUInt4_Convert,&p3)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaOccBusTermBitp result= (oaOccBusTermBit::find(p1.Data(),p2.Data(),p3.Data()));
        return PyoaOccBusTermBit_FromoaOccBusTermBit(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaOccBusTermBit_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaOccBusTermBit_static_find,METH_VARARGS,oaOccBusTermBit_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccBusTermBit_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccBusTermBit_Type)<0) {
      printf("** PyType_Ready failed for: oaOccBusTermBit\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccBusTermBit",
           (PyObject*)(&PyoaOccBusTermBit_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccBusTermBit\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaOccBusTermBit_Type.tp_dict;
    for(method=oaOccBusTermBit_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaOccBusTermDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccBusTermDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccBusTermDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccBusTermDefObject* self = (PyoaOccBusTermDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccBusTermDef)
    {
        PyParamoaOccBusTermDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccBusTermDef_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccBusTermDef, Choices are:\n"
        "    (oaOccBusTermDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccBusTermDef_tp_dealloc(PyoaOccBusTermDefObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccBusTermDef_tp_repr(PyObject *ob)
{
    PyParamoaOccBusTermDef value;
    int convert_status=PyoaOccBusTermDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaOccBusTermDef::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaScalarName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[37];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaOccBusTermDef::");
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
oaOccBusTermDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccBusTermDef v1;
    PyParamoaOccBusTermDef v2;
    int convert_status1=PyoaOccBusTermDef_Convert(ob1,&v1);
    int convert_status2=PyoaOccBusTermDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccBusTermDef_Convert(PyObject* ob,PyParamoaOccBusTermDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccBusTermDef_Check(ob)) {
        result->SetData( (oaOccBusTermDef**) ((PyoaOccBusTermDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccBusTermDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccBusTermDef_FromoaOccBusTermDef(oaOccBusTermDef** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccBusTermDef* data=*value;
        PyObject* bself = PyoaOccBusTermDef_Type.tp_alloc(&PyoaOccBusTermDef_Type,0);
        if (bself == NULL) return bself;
        PyoaOccBusTermDefObject* self = (PyoaOccBusTermDefObject*)bself;
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
PyObject* PyoaOccBusTermDef_FromoaOccBusTermDef(oaOccBusTermDef* data)
{
    if (data) {
       PyObject* bself = PyoaOccBusTermDef_Type.tp_alloc(&PyoaOccBusTermDef_Type,0);
       if (bself == NULL) return bself;
       PyoaOccBusTermDefObject* self = (PyoaOccBusTermDefObject*)bself;
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
static char oaOccBusTermDef_getBitOrder_doc[] = 
"Class: oaOccBusTermDef, Function: getBitOrder\n"
"  Paramegers: ()\n"
"    Calls: oaBitOrder getBitOrder() const\n"
"    Signature: getBitOrder|simple-oaBitOrder|\n"
"    BrowseData: 1\n"
"    This function returns the bitOrder associated with this oaOccBusTermDef object.\n"
;

static PyObject*
oaOccBusTermDef_getBitOrder(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTermDef data;
    int convert_status=PyoaOccBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermDefObject* self=(PyoaOccBusTermDefObject*)ob;
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
static char oaOccBusTermDef_getBusTermBits_doc[] = 
"Class: oaOccBusTermDef, Function: getBusTermBits\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaOccBusTermBit_oaOccBusTermDef getBusTermBits() const\n"
"    Signature: getBusTermBits|simple-oaCollection_oaOccBusTermBit_oaOccBusTermDef|\n"
"    BrowseData: 1\n"
"    This function returns a collection of busTermBits in this busTermDef.\n"
;

static PyObject*
oaOccBusTermDef_getBusTermBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTermDef data;
    int convert_status=PyoaOccBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermDefObject* self=(PyoaOccBusTermDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaOccBusTermBit_oaOccBusTermDef* result= new oaCollection_oaOccBusTermBit_oaOccBusTermDef(data.DataCall()->getBusTermBits());
        return PyoaCollection_oaOccBusTermBit_oaOccBusTermDef_FromoaCollection_oaOccBusTermBit_oaOccBusTermDef(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBusTermDef_getBusTermBitsIter_doc[] = 
"Class: oaOccBusTermDef, Function: getBusTermBitsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaOccBusTermBit getBusTermBitsIter() const\n"
"    Signature: getBusTermBitsIter|simple-oaIter_oaOccBusTermBit|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of busTermBits in this busTermDef.\n"
;

static PyObject*
oaOccBusTermDef_getBusTermBitsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTermDef data;
    int convert_status=PyoaOccBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermDefObject* self=(PyoaOccBusTermDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaOccBusTermBit* result= new oaIter_oaOccBusTermBit(data.DataCall()->getBusTermBits());
        return PyoaIter_oaOccBusTermBit_FromoaIter_oaOccBusTermBit(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBusTermDef_getBusTerms_doc[] = 
"Class: oaOccBusTermDef, Function: getBusTerms\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaOccBusTerm_oaOccBusTermDef getBusTerms() const\n"
"    Signature: getBusTerms|simple-oaCollection_oaOccBusTerm_oaOccBusTermDef|\n"
"    BrowseData: 1\n"
"    This function returns a collection of busTerms in this busTermDef.\n"
;

static PyObject*
oaOccBusTermDef_getBusTerms(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTermDef data;
    int convert_status=PyoaOccBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermDefObject* self=(PyoaOccBusTermDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaOccBusTerm_oaOccBusTermDef* result= new oaCollection_oaOccBusTerm_oaOccBusTermDef(data.DataCall()->getBusTerms());
        return PyoaCollection_oaOccBusTerm_oaOccBusTermDef_FromoaCollection_oaOccBusTerm_oaOccBusTermDef(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBusTermDef_getBusTermsIter_doc[] = 
"Class: oaOccBusTermDef, Function: getBusTermsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaOccBusTerm getBusTermsIter() const\n"
"    Signature: getBusTermsIter|simple-oaIter_oaOccBusTerm|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of busTerms in this busTermDef.\n"
;

static PyObject*
oaOccBusTermDef_getBusTermsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTermDef data;
    int convert_status=PyoaOccBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermDefObject* self=(PyoaOccBusTermDefObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaOccBusTerm* result= new oaIter_oaOccBusTerm(data.DataCall()->getBusTerms());
        return PyoaIter_oaOccBusTerm_FromoaIter_oaOccBusTerm(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccBusTermDef_getMaxIndex_doc[] = 
"Class: oaOccBusTermDef, Function: getMaxIndex\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getMaxIndex() const\n"
"    Signature: getMaxIndex|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the largest bit number in use for this oaOccBusTermDef object. This is the largest index used across all oaOccBusTerms associated with this oaOccBusTermDef object.\n"
;

static PyObject*
oaOccBusTermDef_getMaxIndex(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTermDef data;
    int convert_status=PyoaOccBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermDefObject* self=(PyoaOccBusTermDefObject*)ob;
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
static char oaOccBusTermDef_getMinIndex_doc[] = 
"Class: oaOccBusTermDef, Function: getMinIndex\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getMinIndex() const\n"
"    Signature: getMinIndex|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the smallest bit number in use for this oaOccBusTermDef object. This is the smallest index used across all oaOccBusTerms associated with this oaOccBusTermDef object.\n"
;

static PyObject*
oaOccBusTermDef_getMinIndex(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTermDef data;
    int convert_status=PyoaOccBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermDefObject* self=(PyoaOccBusTermDefObject*)ob;
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
static char oaOccBusTermDef_getName_doc[] = 
"Class: oaOccBusTermDef, Function: getName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getName(oaScalarName& name) const\n"
"    Signature: getName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the name of this oaOccBusTermDef object.\n"
"    name\n"
"    The scalar name in which to return the name of this oaOccBusTermDef\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getName(const oaNameSpace& ns,oaString& name) const\n"
"    Signature: getName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the name string of this oaOccBusTermDef in the specified nameSpace.\n"
"    ns\n"
"    The nameSpace to use when getting the name string\n"
"    name\n"
"    Returns the string name of this oaOccBusTermDef\n"
;

static PyObject*
oaOccBusTermDef_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTermDef data;
    int convert_status=PyoaOccBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermDefObject* self=(PyoaOccBusTermDefObject*)ob;
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
        "No Arg-Matching Function found for class: oaOccBusTermDef, function: getName, Choices are:\n"
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
static char oaOccBusTermDef_getNumBits_doc[] = 
"Class: oaOccBusTermDef, Function: getNumBits\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumBits() const\n"
"    Signature: getNumBits|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of bits covered by the busses in this oaOccBusTermDef. The number of bits is equal to abs(maxIndex - minIndex) + 1; it is not necessarily the number of busTermBits present in this busTermDef. To get the number of busTermBits in this busTermDef, use oaOccBusTermDef::getBusTermBits() .getCount() .\n"
;

static PyObject*
oaOccBusTermDef_getNumBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTermDef data;
    int convert_status=PyoaOccBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermDefObject* self=(PyoaOccBusTermDefObject*)ob;
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
static char oaOccBusTermDef_isImplicit_doc[] = 
"Class: oaOccBusTermDef, Function: isImplicit\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isImplicit() const\n"
"    Signature: isImplicit|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating whether this oaOccBusTermDef was implicitly created or not.\n"
;

static PyObject*
oaOccBusTermDef_isImplicit(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccBusTermDef data;
    int convert_status=PyoaOccBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccBusTermDefObject* self=(PyoaOccBusTermDefObject*)ob;
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
static char oaOccBusTermDef_isNull_doc[] =
"Class: oaOccBusTermDef, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccBusTermDef_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccBusTermDef data;
    int convert_status=PyoaOccBusTermDef_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccBusTermDef_assign_doc[] = 
"Class: oaOccBusTermDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccBusTermDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccBusTermDef data;
  int convert_status=PyoaOccBusTermDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccBusTermDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccBusTermDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccBusTermDef_methodlist[] = {
    {"getBitOrder",(PyCFunction)oaOccBusTermDef_getBitOrder,METH_VARARGS,oaOccBusTermDef_getBitOrder_doc},
    {"getBusTermBits",(PyCFunction)oaOccBusTermDef_getBusTermBits,METH_VARARGS,oaOccBusTermDef_getBusTermBits_doc},
    {"getBusTermBitsIter",(PyCFunction)oaOccBusTermDef_getBusTermBitsIter,METH_VARARGS,oaOccBusTermDef_getBusTermBitsIter_doc},
    {"getBusTerms",(PyCFunction)oaOccBusTermDef_getBusTerms,METH_VARARGS,oaOccBusTermDef_getBusTerms_doc},
    {"getBusTermsIter",(PyCFunction)oaOccBusTermDef_getBusTermsIter,METH_VARARGS,oaOccBusTermDef_getBusTermsIter_doc},
    {"getMaxIndex",(PyCFunction)oaOccBusTermDef_getMaxIndex,METH_VARARGS,oaOccBusTermDef_getMaxIndex_doc},
    {"getMinIndex",(PyCFunction)oaOccBusTermDef_getMinIndex,METH_VARARGS,oaOccBusTermDef_getMinIndex_doc},
    {"getName",(PyCFunction)oaOccBusTermDef_getName,METH_VARARGS,oaOccBusTermDef_getName_doc},
    {"getNumBits",(PyCFunction)oaOccBusTermDef_getNumBits,METH_VARARGS,oaOccBusTermDef_getNumBits_doc},
    {"isImplicit",(PyCFunction)oaOccBusTermDef_isImplicit,METH_VARARGS,oaOccBusTermDef_isImplicit_doc},
    {"isNull",(PyCFunction)oaOccBusTermDef_tp_isNull,METH_VARARGS,oaOccBusTermDef_isNull_doc},
    {"assign",(PyCFunction)oaOccBusTermDef_tp_assign,METH_VARARGS,oaOccBusTermDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBusTermDef_doc[] = 
"Class: oaOccBusTermDef\n"
"  The oaOccBusTermDef class defines an object that manages all oaOccBusTerms with the same base name in the module domain. An oaOccBusTermDef also tracks the least significant and most significant bits of all of its oaOccBusTerms, as well as all of the corresponding oaOccBusTermBits.\n"
"  A bus definition can be 'sparse' (have missing bits). Busses do not have to start or end at zero. For example, a<22:25> is a legal bus name. Bus indexes must be non-negative.\n"
"  oaModBusTermDef , oaOccBusTermDef, and oaBusTermDef each manage the bus terminals on a different kind of master, where in each case the master represents a level of hierarchy in the design.\n"
"  For oaOccBusTermDef, the master is an oaOccurrence , which corresponds to a unique usage of a module or a block in a design. Each oaOccurrence in a design will have a set of zero or more occBusTermDefs.\n"
"  For oaModBusTermDef , the master is an oaModule . For oaBusTermDef , the master is an oaBlock , and the top block for the design will have a set of zero or more modBusTermDefs. Typically, many of the oaBusTermDefs on the top oaBlock have a corresponding oaModBusTermDef on the top oaModule . The top oaOccurrence will have a corresponding oaOccBusTermDef for each busTermDef in the union of the terminals between the top oaModule and the top oaBlock .\n"
"  The oaOccBusTermDef class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaOccBusTermDef)\n"
"    Calls: (const oaOccBusTermDef&)\n"
"    Signature: oaOccBusTermDef||cref-oaOccBusTermDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccBusTermDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccBusTermDef",
    sizeof(PyoaOccBusTermDefObject),
    0,
    (destructor)oaOccBusTermDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccBusTermDef_tp_compare,	/* tp_compare */
    (reprfunc)oaOccBusTermDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccBusTermDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccBusTermDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccBusTermDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccBusTermDef_static_find_doc[] = 
"Class: oaOccBusTermDef, Function: find\n"
"  Paramegers: (oaOccurrence,oaScalarName)\n"
"    Calls: oaOccBusTermDef* find(const oaOccurrence* occurrence,const oaScalarName& name)\n"
"    Signature: find|ptr-oaOccBusTermDef|cptr-oaOccurrence,cref-oaScalarName,\n"
"    This function searches the specified occurrence for a busTermDef with the specified name. The busTermDef is returned if found. Otherwise, NULL is returned.\n"
;

static PyObject*
oaOccBusTermDef_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccurrence p1;
    PyParamoaScalarName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaOccurrence_Convert,&p1,
          &PyoaScalarName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaOccBusTermDefp result= (oaOccBusTermDef::find(p1.Data(),p2.Data()));
        return PyoaOccBusTermDef_FromoaOccBusTermDef(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaOccBusTermDef_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaOccBusTermDef_static_find,METH_VARARGS,oaOccBusTermDef_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccBusTermDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccBusTermDef_Type)<0) {
      printf("** PyType_Ready failed for: oaOccBusTermDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccBusTermDef",
           (PyObject*)(&PyoaOccBusTermDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccBusTermDef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaOccBusTermDef_Type.tp_dict;
    for(method=oaOccBusTermDef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaOccConnectDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccConnectDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccConnectDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccConnectDefObject* self = (PyoaOccConnectDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccConnectDef)
    {
        PyParamoaOccConnectDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccConnectDef_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccConnectDef, Choices are:\n"
        "    (oaOccConnectDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccConnectDef_tp_dealloc(PyoaOccConnectDefObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccConnectDef_tp_repr(PyObject *ob)
{
    PyParamoaOccConnectDef value;
    int convert_status=PyoaOccConnectDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[37];
    sprintf(buffer,"<oaOccConnectDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaOccConnectDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccConnectDef v1;
    PyParamoaOccConnectDef v2;
    int convert_status1=PyoaOccConnectDef_Convert(ob1,&v1);
    int convert_status2=PyoaOccConnectDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccConnectDef_Convert(PyObject* ob,PyParamoaOccConnectDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccConnectDef_Check(ob)) {
        result->SetData( (oaOccConnectDef**) ((PyoaOccConnectDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccConnectDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccConnectDef_FromoaOccConnectDef(oaOccConnectDef** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccConnectDef* data=*value;
        if (data->getType()==oacOccTermConnectDefType) return PyoaOccTermConnectDef_FromoaOccTermConnectDef((oaOccTermConnectDef**)value,borrow,lock);
        if (data->getType()==oacOccNetConnectDefType) return PyoaOccNetConnectDef_FromoaOccNetConnectDef((oaOccNetConnectDef**)value,borrow,lock);
        PyObject* bself = PyoaOccConnectDef_Type.tp_alloc(&PyoaOccConnectDef_Type,0);
        if (bself == NULL) return bself;
        PyoaOccConnectDefObject* self = (PyoaOccConnectDefObject*)bself;
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
PyObject* PyoaOccConnectDef_FromoaOccConnectDef(oaOccConnectDef* data)
{
    if (data) {
        if (data->getType()==oacOccTermConnectDefType) return PyoaOccTermConnectDef_FromoaOccTermConnectDef((oaOccTermConnectDef*)data);
        if (data->getType()==oacOccNetConnectDefType) return PyoaOccNetConnectDef_FromoaOccNetConnectDef((oaOccNetConnectDef*)data);
       PyObject* bself = PyoaOccConnectDef_Type.tp_alloc(&PyoaOccConnectDef_Type,0);
       if (bself == NULL) return bself;
       PyoaOccConnectDefObject* self = (PyoaOccConnectDefObject*)bself;
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
static char oaOccConnectDef_getAssignmentDef_doc[] = 
"Class: oaOccConnectDef, Function: getAssignmentDef\n"
"  Paramegers: (oaAssignmentDef)\n"
"    Calls: void getAssignmentDef(oaAssignmentDef& assignmentDef) const\n"
"    Signature: getAssignmentDef|void-void|ref-oaAssignmentDef,\n"
"    BrowseData: 0,oaAssignmentDef\n"
"    This function returns the connection definition of this oaOccConnectDef in the specified assignmentDef .\n"
;

static PyObject*
oaOccConnectDef_getAssignmentDef(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccConnectDef data;
    int convert_status=PyoaOccConnectDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccConnectDefObject* self=(PyoaOccConnectDefObject*)ob;
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
static char oaOccConnectDef_isNull_doc[] =
"Class: oaOccConnectDef, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccConnectDef_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccConnectDef data;
    int convert_status=PyoaOccConnectDef_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccConnectDef_assign_doc[] = 
"Class: oaOccConnectDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccConnectDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccConnectDef data;
  int convert_status=PyoaOccConnectDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccConnectDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccConnectDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccConnectDef_methodlist[] = {
    {"getAssignmentDef",(PyCFunction)oaOccConnectDef_getAssignmentDef,METH_VARARGS,oaOccConnectDef_getAssignmentDef_doc},
    {"isNull",(PyCFunction)oaOccConnectDef_tp_isNull,METH_VARARGS,oaOccConnectDef_isNull_doc},
    {"assign",(PyCFunction)oaOccConnectDef_tp_assign,METH_VARARGS,oaOccConnectDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccConnectDef_doc[] = 
"Class: oaOccConnectDef\n"
"  In the occurrence domain it is not possible directly create any connectDefs or assignments. The occurrence domain versions of these classes are automatically created by OpenAccess as a reflection of objects created in the block or module domain. For further information, see oaConnectDef (and its derived classes) and oaAssignmentDef in the block domain and oaModConnectDef (and its derived classes) and oaModAssignment in the module domain.\n"
"  The oaOccConnectDef class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaOccConnectDef)\n"
"    Calls: (const oaOccConnectDef&)\n"
"    Signature: oaOccConnectDef||cref-oaOccConnectDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccConnectDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccConnectDef",
    sizeof(PyoaOccConnectDefObject),
    0,
    (destructor)oaOccConnectDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccConnectDef_tp_compare,	/* tp_compare */
    (reprfunc)oaOccConnectDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccConnectDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccConnectDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccConnectDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccConnectDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccConnectDef_Type)<0) {
      printf("** PyType_Ready failed for: oaOccConnectDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccConnectDef",
           (PyObject*)(&PyoaOccConnectDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccConnectDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaOccDesignInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccDesignInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccDesignInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccDesignInstObject* self = (PyoaOccDesignInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccDesignInst)
    {
        PyParamoaOccDesignInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccDesignInst_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccDesignInst, Choices are:\n"
        "    (oaOccDesignInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccDesignInst_tp_dealloc(PyoaOccDesignInstObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccDesignInst_tp_repr(PyObject *ob)
{
    PyParamoaOccDesignInst value;
    int convert_status=PyoaOccDesignInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaOccDesignInst::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaSimpleName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[37];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaOccDesignInst::");
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
oaOccDesignInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccDesignInst v1;
    PyParamoaOccDesignInst v2;
    int convert_status1=PyoaOccDesignInst_Convert(ob1,&v1);
    int convert_status2=PyoaOccDesignInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccDesignInst_Convert(PyObject* ob,PyParamoaOccDesignInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccDesignInst_Check(ob)) {
        result->SetData( (oaOccDesignInst**) ((PyoaOccDesignInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccDesignInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccDesignInst_FromoaOccDesignInst(oaOccDesignInst** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccDesignInst* data=*value;
        if (data->isOccBitInst()) return PyoaOccBitInst_FromoaOccBitInst((oaOccBitInst**)value,borrow,lock);
        if (data->getType()==oacOccVectorInstType) return PyoaOccVectorInst_FromoaOccVectorInst((oaOccVectorInst**)value,borrow,lock);
        PyObject* bself = PyoaOccDesignInst_Type.tp_alloc(&PyoaOccDesignInst_Type,0);
        if (bself == NULL) return bself;
        PyoaOccDesignInstObject* self = (PyoaOccDesignInstObject*)bself;
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
PyObject* PyoaOccDesignInst_FromoaOccDesignInst(oaOccDesignInst* data)
{
    if (data) {
        if (data->isOccBitInst()) return PyoaOccBitInst_FromoaOccBitInst((oaOccBitInst*)data);
        if (data->getType()==oacOccVectorInstType) return PyoaOccVectorInst_FromoaOccVectorInst((oaOccVectorInst*)data);
       PyObject* bself = PyoaOccDesignInst_Type.tp_alloc(&PyoaOccDesignInst_Type,0);
       if (bself == NULL) return bself;
       PyoaOccDesignInstObject* self = (PyoaOccDesignInstObject*)bself;
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
static char oaOccDesignInst_findParam_doc[] = 
"Class: oaOccDesignInst, Function: findParam\n"
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
oaOccDesignInst_findParam(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccDesignInst data;
    int convert_status=PyoaOccDesignInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccDesignInstObject* self=(PyoaOccDesignInstObject*)ob;
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
static char oaOccDesignInst_getCellName_doc[] = 
"Class: oaOccDesignInst, Function: getCellName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getCellName(oaScalarName& cellName) const\n"
"    Signature: getCellName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the cell name for the master design referenced by this instance.\n"
"    cellName\n"
"    The name of the cell for the master design\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getCellName(const oaNameSpace& ns,oaString& cellName) const\n"
"    Signature: getCellName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the cell name for the master design referenced by this instance in the namespace specified.\n"
"    ns\n"
"    The namespace for the cell name\n"
"    cellName\n"
"    The cell name for the master design\n"
;

static PyObject*
oaOccDesignInst_getCellName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccDesignInst data;
    int convert_status=PyoaOccDesignInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccDesignInstObject* self=(PyoaOccDesignInstObject*)ob;
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
        "No Arg-Matching Function found for class: oaOccDesignInst, function: getCellName, Choices are:\n"
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
static char oaOccDesignInst_getHeader_doc[] = 
"Class: oaOccDesignInst, Function: getHeader\n"
"  Paramegers: ()\n"
"    Calls: oaOccInstHeader* getHeader() const\n"
"    Signature: getHeader|ptr-oaOccInstHeader|\n"
"    BrowseData: 1\n"
"    This function returns the occurrence instHeader associated with this instance. The instHeader is a collection of the attributes that are common to all instances of a particular master.\n"
"    The pointer to the instance header\n"
;

static PyObject*
oaOccDesignInst_getHeader(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccDesignInst data;
    int convert_status=PyoaOccDesignInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccDesignInstObject* self=(PyoaOccDesignInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaOccInstHeaderp result= (data.DataCall()->getHeader());
        return PyoaOccInstHeader_FromoaOccInstHeader(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccDesignInst_getLibName_doc[] = 
"Class: oaOccDesignInst, Function: getLibName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getLibName(oaScalarName& libName) const\n"
"    Signature: getLibName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the library name for the master design referenced by this instance.\n"
"    libName\n"
"    The name of the library for the master design\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getLibName(const oaNameSpace& ns,oaString& libName) const\n"
"    Signature: getLibName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the library name for the master design referenced by this instance in the namespace specified.\n"
"    ns\n"
"    The namespace for the library name\n"
"    libName\n"
"    The library name for the master design\n"
;

static PyObject*
oaOccDesignInst_getLibName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccDesignInst data;
    int convert_status=PyoaOccDesignInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccDesignInstObject* self=(PyoaOccDesignInstObject*)ob;
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
        "No Arg-Matching Function found for class: oaOccDesignInst, function: getLibName, Choices are:\n"
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
static char oaOccDesignInst_getMaster_doc[] = 
"Class: oaOccDesignInst, Function: getMaster\n"
"  Paramegers: ()\n"
"    Calls: oaDesign* getMaster() const\n"
"    Signature: getMaster|ptr-oaDesign|\n"
"    BrowseData: 1\n"
"    This function attempts to return the master associated with this instance. If the instance is not previously bound, it attempts to open the master and bind this instance. If the instance cannot be bound, NULL is returned.\n"
;

static PyObject*
oaOccDesignInst_getMaster(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccDesignInst data;
    int convert_status=PyoaOccDesignInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccDesignInstObject* self=(PyoaOccDesignInstObject*)ob;
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
static char oaOccDesignInst_getParams_doc[] = 
"Class: oaOccDesignInst, Function: getParams\n"
"  Paramegers: (oaParamArray)\n"
"    Calls: void getParams(oaParamArray& params) const\n"
"    Signature: getParams|void-void|ref-oaParamArray,\n"
"    BrowseData: 0,oaParamArray\n"
"    This function fills out params with the parameters associated with this instHeader. This call only returns the non-default parameters that were specified during creation or through calls to setParams() on the instances. If this instHeader is not associated with a Pcell master or uses all default parameters, params will have a numParams of zero.\n"
;

static PyObject*
oaOccDesignInst_getParams(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccDesignInst data;
    int convert_status=PyoaOccDesignInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccDesignInstObject* self=(PyoaOccDesignInstObject*)ob;
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
static char oaOccDesignInst_getViewName_doc[] = 
"Class: oaOccDesignInst, Function: getViewName\n"
"  Paramegers: (oaScalarName)\n"
"    Calls: void getViewName(oaScalarName& viewName) const\n"
"    Signature: getViewName|void-void|ref-oaScalarName,\n"
"    BrowseData: 0,oaScalarName\n"
"    This function returns the view name for the master design referenced by this instance.\n"
"    viewName\n"
"    The name of the view for the master design\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getViewName(const oaNameSpace& ns,oaString& viewName) const\n"
"    Signature: getViewName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the view name for the master design referenced by this instance in the namespace specified.\n"
"    ns\n"
"    The namespace for the view name\n"
"    viewName\n"
"    The view name for the master design\n"
;

static PyObject*
oaOccDesignInst_getViewName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccDesignInst data;
    int convert_status=PyoaOccDesignInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccDesignInstObject* self=(PyoaOccDesignInstObject*)ob;
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
        "No Arg-Matching Function found for class: oaOccDesignInst, function: getViewName, Choices are:\n"
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
static char oaOccDesignInst_isNull_doc[] =
"Class: oaOccDesignInst, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccDesignInst_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccDesignInst data;
    int convert_status=PyoaOccDesignInst_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccDesignInst_assign_doc[] = 
"Class: oaOccDesignInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccDesignInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccDesignInst data;
  int convert_status=PyoaOccDesignInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccDesignInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccDesignInst_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccDesignInst_methodlist[] = {
    {"findParam",(PyCFunction)oaOccDesignInst_findParam,METH_VARARGS,oaOccDesignInst_findParam_doc},
    {"getCellName",(PyCFunction)oaOccDesignInst_getCellName,METH_VARARGS,oaOccDesignInst_getCellName_doc},
    {"getHeader",(PyCFunction)oaOccDesignInst_getHeader,METH_VARARGS,oaOccDesignInst_getHeader_doc},
    {"getLibName",(PyCFunction)oaOccDesignInst_getLibName,METH_VARARGS,oaOccDesignInst_getLibName_doc},
    {"getMaster",(PyCFunction)oaOccDesignInst_getMaster,METH_VARARGS,oaOccDesignInst_getMaster_doc},
    {"getParams",(PyCFunction)oaOccDesignInst_getParams,METH_VARARGS,oaOccDesignInst_getParams_doc},
    {"getViewName",(PyCFunction)oaOccDesignInst_getViewName,METH_VARARGS,oaOccDesignInst_getViewName_doc},
    {"isNull",(PyCFunction)oaOccDesignInst_tp_isNull,METH_VARARGS,oaOccDesignInst_isNull_doc},
    {"assign",(PyCFunction)oaOccDesignInst_tp_assign,METH_VARARGS,oaOccDesignInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccDesignInst_doc[] = 
"Class: oaOccDesignInst\n"
"  The oaOccDesignInst class implements an occurrence of an instance of a design master.\n"
"  oaOccDesignInst objects are always in the occurrence domain.\n"
"Constructors:\n"
"  Paramegers: (oaOccDesignInst)\n"
"    Calls: (const oaOccDesignInst&)\n"
"    Signature: oaOccDesignInst||cref-oaOccDesignInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccDesignInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccDesignInst",
    sizeof(PyoaOccDesignInstObject),
    0,
    (destructor)oaOccDesignInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccDesignInst_tp_compare,	/* tp_compare */
    (reprfunc)oaOccDesignInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccDesignInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccDesignInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccInst_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccDesignInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccDesignInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccDesignInst_Type)<0) {
      printf("** PyType_Ready failed for: oaOccDesignInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccDesignInst",
           (PyObject*)(&PyoaOccDesignInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccDesignInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaOccDonut
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccDonut_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccDonut_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccDonutObject* self = (PyoaOccDonutObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccDonut)
    {
        PyParamoaOccDonut p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccDonut_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccDonut, Choices are:\n"
        "    (oaOccDonut)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccDonut_tp_dealloc(PyoaOccDonutObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccDonut_tp_repr(PyObject *ob)
{
    PyParamoaOccDonut value;
    int convert_status=PyoaOccDonut_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[32];
    sprintf(buffer,"<oaOccDonut::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaOccDonut_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccDonut v1;
    PyParamoaOccDonut v2;
    int convert_status1=PyoaOccDonut_Convert(ob1,&v1);
    int convert_status2=PyoaOccDonut_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccDonut_Convert(PyObject* ob,PyParamoaOccDonut* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccDonut_Check(ob)) {
        result->SetData( (oaOccDonut**) ((PyoaOccDonutObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccDonut Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccDonut_FromoaOccDonut(oaOccDonut** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccDonut* data=*value;
        PyObject* bself = PyoaOccDonut_Type.tp_alloc(&PyoaOccDonut_Type,0);
        if (bself == NULL) return bself;
        PyoaOccDonutObject* self = (PyoaOccDonutObject*)bself;
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
PyObject* PyoaOccDonut_FromoaOccDonut(oaOccDonut* data)
{
    if (data) {
       PyObject* bself = PyoaOccDonut_Type.tp_alloc(&PyoaOccDonut_Type,0);
       if (bself == NULL) return bself;
       PyoaOccDonutObject* self = (PyoaOccDonutObject*)bself;
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
static char oaOccDonut_getBoundary_doc[] = 
"Class: oaOccDonut, Function: getBoundary\n"
"  Paramegers: (oaPointArray)\n"
"    Calls: void getBoundary(oaPointArray& points) const\n"
"    Signature: getBoundary|void-void|ref-oaPointArray,simple-oaUInt4,\n"
"    BrowseData: 0,oaPointArray\n"
"    This function fills out 'points' with the boundary polygon of the donut from which this occDonut is generated. The polygon is generated with the number of sides specified by 'numSides'.\n"
"    points\n"
"    The point array to be filled with the boundary polygon of this occDonut\n"
"    numSides\n"
"    The number of sides of the boundary polygon\n"
"    oacDonutNumSidesInvalid\n"
"  Paramegers: (oaPointArray,oaUInt4)\n"
"    Calls: void getBoundary(oaPointArray& points,oaUInt4 numSides) const\n"
"    Signature: getBoundary|void-void|ref-oaPointArray,simple-oaUInt4,\n"
"    This function fills out 'points' with the boundary polygon of the donut from which this occDonut is generated. The polygon is generated with the number of sides specified by 'numSides'.\n"
"    points\n"
"    The point array to be filled with the boundary polygon of this occDonut\n"
"    numSides\n"
"    The number of sides of the boundary polygon\n"
"    oacDonutNumSidesInvalid\n"
;

static PyObject*
oaOccDonut_getBoundary(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccDonut data;
    int convert_status=PyoaOccDonut_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccDonutObject* self=(PyoaOccDonutObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaPointArray)
    {
        PyParamoaPointArray p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaPointArray_Convert,&p1)) {
            data.DataCall()->getBoundary(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    // Case: (oaPointArray,oaUInt4)
    {
        PyParamoaPointArray p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaPointArray_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            data.DataCall()->getBoundary(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaOccDonut, function: getBoundary, Choices are:\n"
        "    (oaPointArray)\n"
        "    (oaPointArray,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccDonut_getCenter_doc[] = 
"Class: oaOccDonut, Function: getCenter\n"
"  Paramegers: (oaPoint)\n"
"    Calls: void getCenter(oaPoint& point) const\n"
"    Signature: getCenter|void-void|ref-oaPoint,\n"
"    BrowseData: 0,oaPoint\n"
"    This function fills out 'point' with the center point of this occDonut.\n"
"    point\n"
"    The point to be filled with the center point of this occDonut\n"
;

static PyObject*
oaOccDonut_getCenter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccDonut data;
    int convert_status=PyoaOccDonut_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccDonutObject* self=(PyoaOccDonutObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPoint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPoint_Convert,&p1)) {
        data.DataCall()->getCenter(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccDonut_getHoleBBox_doc[] = 
"Class: oaOccDonut, Function: getHoleBBox\n"
"  Paramegers: (oaBox)\n"
"    Calls: void getHoleBBox(oaBox& bBox) const\n"
"    Signature: getHoleBBox|void-void|ref-oaBox,\n"
"    BrowseData: 0,oaBox\n"
"    This function fills out 'bBox' with the hole bBox of this occDonut.\n"
"    bBox\n"
"    The bounding box to be filled\n"
;

static PyObject*
oaOccDonut_getHoleBBox(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccDonut data;
    int convert_status=PyoaOccDonut_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccDonutObject* self=(PyoaOccDonutObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaBox p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaBox_Convert,&p1)) {
        data.DataCall()->getHoleBBox(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccDonut_getHoleRadius_doc[] = 
"Class: oaOccDonut, Function: getHoleRadius\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getHoleRadius() const\n"
"    Signature: getHoleRadius|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the inner radius of this occDonut.\n"
;

static PyObject*
oaOccDonut_getHoleRadius(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccDonut data;
    int convert_status=PyoaOccDonut_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccDonutObject* self=(PyoaOccDonutObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getHoleRadius());
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
static char oaOccDonut_getRadius_doc[] = 
"Class: oaOccDonut, Function: getRadius\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getRadius() const\n"
"    Signature: getRadius|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the outer radius of this occDonut.\n"
;

static PyObject*
oaOccDonut_getRadius(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccDonut data;
    int convert_status=PyoaOccDonut_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccDonutObject* self=(PyoaOccDonutObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaUInt4 result= (data.DataCall()->getRadius());
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
static char oaOccDonut_isNull_doc[] =
"Class: oaOccDonut, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccDonut_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccDonut data;
    int convert_status=PyoaOccDonut_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccDonut_assign_doc[] = 
"Class: oaOccDonut, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccDonut_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccDonut data;
  int convert_status=PyoaOccDonut_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccDonut p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccDonut_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccDonut_methodlist[] = {
    {"getBoundary",(PyCFunction)oaOccDonut_getBoundary,METH_VARARGS,oaOccDonut_getBoundary_doc},
    {"getCenter",(PyCFunction)oaOccDonut_getCenter,METH_VARARGS,oaOccDonut_getCenter_doc},
    {"getHoleBBox",(PyCFunction)oaOccDonut_getHoleBBox,METH_VARARGS,oaOccDonut_getHoleBBox_doc},
    {"getHoleRadius",(PyCFunction)oaOccDonut_getHoleRadius,METH_VARARGS,oaOccDonut_getHoleRadius_doc},
    {"getRadius",(PyCFunction)oaOccDonut_getRadius,METH_VARARGS,oaOccDonut_getRadius_doc},
    {"isNull",(PyCFunction)oaOccDonut_tp_isNull,METH_VARARGS,oaOccDonut_isNull_doc},
    {"assign",(PyCFunction)oaOccDonut_tp_assign,METH_VARARGS,oaOccDonut_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccDonut_doc[] = 
"Class: oaOccDonut\n"
"  The oaOccDonut class implements an unique occurrence of an oaDonut object in a design hierarchy.\n"
"Constructors:\n"
"  Paramegers: (oaOccDonut)\n"
"    Calls: (const oaOccDonut&)\n"
"    Signature: oaOccDonut||cref-oaOccDonut,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccDonut_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccDonut",
    sizeof(PyoaOccDonutObject),
    0,
    (destructor)oaOccDonut_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccDonut_tp_compare,	/* tp_compare */
    (reprfunc)oaOccDonut_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccDonut_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccDonut_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccShape_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccDonut_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccDonut_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccDonut_Type)<0) {
      printf("** PyType_Ready failed for: oaOccDonut\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccDonut",
           (PyObject*)(&PyoaOccDonut_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccDonut\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaOccDot
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccDot_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccDot_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccDotObject* self = (PyoaOccDotObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccDot)
    {
        PyParamoaOccDot p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccDot_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccDot, Choices are:\n"
        "    (oaOccDot)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccDot_tp_dealloc(PyoaOccDotObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccDot_tp_repr(PyObject *ob)
{
    PyParamoaOccDot value;
    int convert_status=PyoaOccDot_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[30];
    sprintf(buffer,"<oaOccDot::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaOccDot_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccDot v1;
    PyParamoaOccDot v2;
    int convert_status1=PyoaOccDot_Convert(ob1,&v1);
    int convert_status2=PyoaOccDot_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccDot_Convert(PyObject* ob,PyParamoaOccDot* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccDot_Check(ob)) {
        result->SetData( (oaOccDot**) ((PyoaOccDotObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccDot Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccDot_FromoaOccDot(oaOccDot** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccDot* data=*value;
        PyObject* bself = PyoaOccDot_Type.tp_alloc(&PyoaOccDot_Type,0);
        if (bself == NULL) return bself;
        PyoaOccDotObject* self = (PyoaOccDotObject*)bself;
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
PyObject* PyoaOccDot_FromoaOccDot(oaOccDot* data)
{
    if (data) {
       PyObject* bself = PyoaOccDot_Type.tp_alloc(&PyoaOccDot_Type,0);
       if (bself == NULL) return bself;
       PyoaOccDotObject* self = (PyoaOccDotObject*)bself;
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
static char oaOccDot_getHeight_doc[] = 
"Class: oaOccDot, Function: getHeight\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getHeight() const\n"
"    Signature: getHeight|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the height of this occDot.\n"
;

static PyObject*
oaOccDot_getHeight(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccDot data;
    int convert_status=PyoaOccDot_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccDotObject* self=(PyoaOccDotObject*)ob;
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
static char oaOccDot_getLocation_doc[] = 
"Class: oaOccDot, Function: getLocation\n"
"  Paramegers: (oaPoint)\n"
"    Calls: void getLocation(oaPoint& point) const\n"
"    Signature: getLocation|void-void|ref-oaPoint,\n"
"    BrowseData: 0,oaPoint\n"
"    This function fills out 'location' with the location of this occDot.\n"
"    point\n"
"    The point to be filled with the location of this occDot\n"
;

static PyObject*
oaOccDot_getLocation(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccDot data;
    int convert_status=PyoaOccDot_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccDotObject* self=(PyoaOccDotObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPoint p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaPoint_Convert,&p1)) {
        data.DataCall()->getLocation(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccDot_getWidth_doc[] = 
"Class: oaOccDot, Function: getWidth\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getWidth() const\n"
"    Signature: getWidth|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the width of this occDot.\n"
;

static PyObject*
oaOccDot_getWidth(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccDot data;
    int convert_status=PyoaOccDot_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccDotObject* self=(PyoaOccDotObject*)ob;
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
static char oaOccDot_isNull_doc[] =
"Class: oaOccDot, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccDot_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccDot data;
    int convert_status=PyoaOccDot_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccDot_assign_doc[] = 
"Class: oaOccDot, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccDot_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccDot data;
  int convert_status=PyoaOccDot_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccDot p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccDot_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccDot_methodlist[] = {
    {"getHeight",(PyCFunction)oaOccDot_getHeight,METH_VARARGS,oaOccDot_getHeight_doc},
    {"getLocation",(PyCFunction)oaOccDot_getLocation,METH_VARARGS,oaOccDot_getLocation_doc},
    {"getWidth",(PyCFunction)oaOccDot_getWidth,METH_VARARGS,oaOccDot_getWidth_doc},
    {"isNull",(PyCFunction)oaOccDot_tp_isNull,METH_VARARGS,oaOccDot_isNull_doc},
    {"assign",(PyCFunction)oaOccDot_tp_assign,METH_VARARGS,oaOccDot_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccDot_doc[] = 
"Class: oaOccDot\n"
"  The oaOccDot class implements an unique occurrence of an oaDot object in a design hierarchy.\n"
"Constructors:\n"
"  Paramegers: (oaOccDot)\n"
"    Calls: (const oaOccDot&)\n"
"    Signature: oaOccDot||cref-oaOccDot,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccDot_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccDot",
    sizeof(PyoaOccDotObject),
    0,
    (destructor)oaOccDot_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccDot_tp_compare,	/* tp_compare */
    (reprfunc)oaOccDot_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccDot_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccDot_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccShape_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccDot_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccDot_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccDot_Type)<0) {
      printf("** PyType_Ready failed for: oaOccDot\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccDot",
           (PyObject*)(&PyoaOccDot_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccDot\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaOccEllipse
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccEllipse_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccEllipse_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccEllipseObject* self = (PyoaOccEllipseObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccEllipse)
    {
        PyParamoaOccEllipse p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccEllipse_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccEllipse, Choices are:\n"
        "    (oaOccEllipse)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccEllipse_tp_dealloc(PyoaOccEllipseObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccEllipse_tp_repr(PyObject *ob)
{
    PyParamoaOccEllipse value;
    int convert_status=PyoaOccEllipse_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[34];
    sprintf(buffer,"<oaOccEllipse::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaOccEllipse_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccEllipse v1;
    PyParamoaOccEllipse v2;
    int convert_status1=PyoaOccEllipse_Convert(ob1,&v1);
    int convert_status2=PyoaOccEllipse_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccEllipse_Convert(PyObject* ob,PyParamoaOccEllipse* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccEllipse_Check(ob)) {
        result->SetData( (oaOccEllipse**) ((PyoaOccEllipseObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccEllipse Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccEllipse_FromoaOccEllipse(oaOccEllipse** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccEllipse* data=*value;
        PyObject* bself = PyoaOccEllipse_Type.tp_alloc(&PyoaOccEllipse_Type,0);
        if (bself == NULL) return bself;
        PyoaOccEllipseObject* self = (PyoaOccEllipseObject*)bself;
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
PyObject* PyoaOccEllipse_FromoaOccEllipse(oaOccEllipse* data)
{
    if (data) {
       PyObject* bself = PyoaOccEllipse_Type.tp_alloc(&PyoaOccEllipse_Type,0);
       if (bself == NULL) return bself;
       PyoaOccEllipseObject* self = (PyoaOccEllipseObject*)bself;
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
static char oaOccEllipse_getBoundary_doc[] = 
"Class: oaOccEllipse, Function: getBoundary\n"
"  Paramegers: (oaPointArray,oaUInt4)\n"
"    Calls: void getBoundary(oaPointArray& points,oaUInt4 numSides) const\n"
"    Signature: getBoundary|void-void|ref-oaPointArray,simple-oaUInt4,\n"
"    This function fills out the specified 'points' with the bounding polygon of this occEllipse. The polygon is generated with the number of sides specified by 'numSides'. This function throws an exception if the specified 'numSides' is less than three.\n"
"    points\n"
"    The location for the returned array of points for the occEllipse\n"
"    numSides\n"
"    The number of sides that define the bounding polygon\n"
"    oacEllipseNumSidesInvalid\n"
;

static PyObject*
oaOccEllipse_getBoundary(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccEllipse data;
    int convert_status=PyoaOccEllipse_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccEllipseObject* self=(PyoaOccEllipseObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaPointArray p1;
    PyParamoaUInt4 p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaPointArray_Convert,&p1,
          &PyoaUInt4_Convert,&p2)) {
        data.DataCall()->getBoundary(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccEllipse_isNull_doc[] =
"Class: oaOccEllipse, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccEllipse_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccEllipse data;
    int convert_status=PyoaOccEllipse_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccEllipse_assign_doc[] = 
"Class: oaOccEllipse, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccEllipse_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccEllipse data;
  int convert_status=PyoaOccEllipse_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccEllipse p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccEllipse_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccEllipse_methodlist[] = {
    {"getBoundary",(PyCFunction)oaOccEllipse_getBoundary,METH_VARARGS,oaOccEllipse_getBoundary_doc},
    {"isNull",(PyCFunction)oaOccEllipse_tp_isNull,METH_VARARGS,oaOccEllipse_isNull_doc},
    {"assign",(PyCFunction)oaOccEllipse_tp_assign,METH_VARARGS,oaOccEllipse_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccEllipse_doc[] = 
"Class: oaOccEllipse\n"
"  The oaOccEllipse class implements an unique occurrence of an oaEllipse object in a design hierarchy.\n"
"Constructors:\n"
"  Paramegers: (oaOccEllipse)\n"
"    Calls: (const oaOccEllipse&)\n"
"    Signature: oaOccEllipse||cref-oaOccEllipse,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccEllipse_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccEllipse",
    sizeof(PyoaOccEllipseObject),
    0,
    (destructor)oaOccEllipse_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccEllipse_tp_compare,	/* tp_compare */
    (reprfunc)oaOccEllipse_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccEllipse_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccEllipse_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccShape_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccEllipse_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccEllipse_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccEllipse_Type)<0) {
      printf("** PyType_Ready failed for: oaOccEllipse\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccEllipse",
           (PyObject*)(&PyoaOccEllipse_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccEllipse\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaOccEvalText
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccEvalText_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccEvalText_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccEvalTextObject* self = (PyoaOccEvalTextObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccEvalText)
    {
        PyParamoaOccEvalText p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccEvalText_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccEvalText, Choices are:\n"
        "    (oaOccEvalText)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccEvalText_tp_dealloc(PyoaOccEvalTextObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccEvalText_tp_repr(PyObject *ob)
{
    PyParamoaOccEvalText value;
    int convert_status=PyoaOccEvalText_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[35];
    sprintf(buffer,"<oaOccEvalText::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaOccEvalText_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccEvalText v1;
    PyParamoaOccEvalText v2;
    int convert_status1=PyoaOccEvalText_Convert(ob1,&v1);
    int convert_status2=PyoaOccEvalText_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccEvalText_Convert(PyObject* ob,PyParamoaOccEvalText* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccEvalText_Check(ob)) {
        result->SetData( (oaOccEvalText**) ((PyoaOccEvalTextObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccEvalText Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccEvalText_FromoaOccEvalText(oaOccEvalText** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccEvalText* data=*value;
        PyObject* bself = PyoaOccEvalText_Type.tp_alloc(&PyoaOccEvalText_Type,0);
        if (bself == NULL) return bself;
        PyoaOccEvalTextObject* self = (PyoaOccEvalTextObject*)bself;
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
PyObject* PyoaOccEvalText_FromoaOccEvalText(oaOccEvalText* data)
{
    if (data) {
       PyObject* bself = PyoaOccEvalText_Type.tp_alloc(&PyoaOccEvalText_Type,0);
       if (bself == NULL) return bself;
       PyoaOccEvalTextObject* self = (PyoaOccEvalTextObject*)bself;
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
static char oaOccEvalText_getExpression_doc[] = 
"Class: oaOccEvalText, Function: getExpression\n"
"  Paramegers: (oaString)\n"
"    Calls: void getExpression(oaString& text) const\n"
"    Signature: getExpression|void-void|ref-oaString,\n"
"    BrowseData: 0,oaString\n"
"    This function returns the text expression used by this eval text object.\n"
"    text\n"
"    The text string to be filled\n"
;

static PyObject*
oaOccEvalText_getExpression(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccEvalText data;
    int convert_status=PyoaOccEvalText_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccEvalTextObject* self=(PyoaOccEvalTextObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->getExpression(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccEvalText_isNull_doc[] =
"Class: oaOccEvalText, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccEvalText_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccEvalText data;
    int convert_status=PyoaOccEvalText_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccEvalText_assign_doc[] = 
"Class: oaOccEvalText, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccEvalText_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccEvalText data;
  int convert_status=PyoaOccEvalText_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccEvalText p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccEvalText_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccEvalText_methodlist[] = {
    {"getExpression",(PyCFunction)oaOccEvalText_getExpression,METH_VARARGS,oaOccEvalText_getExpression_doc},
    {"isNull",(PyCFunction)oaOccEvalText_tp_isNull,METH_VARARGS,oaOccEvalText_isNull_doc},
    {"assign",(PyCFunction)oaOccEvalText_tp_assign,METH_VARARGS,oaOccEvalText_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccEvalText_doc[] = 
"Class: oaOccEvalText\n"
"  The oaOccEvalText class implements an unique occurrence of an oaEvalText object in a design hierarchy.\n"
"Constructors:\n"
"  Paramegers: (oaOccEvalText)\n"
"    Calls: (const oaOccEvalText&)\n"
"    Signature: oaOccEvalText||cref-oaOccEvalText,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccEvalText_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccEvalText",
    sizeof(PyoaOccEvalTextObject),
    0,
    (destructor)oaOccEvalText_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccEvalText_tp_compare,	/* tp_compare */
    (reprfunc)oaOccEvalText_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccEvalText_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccEvalText_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccText_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccEvalText_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccEvalText_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccEvalText_Type)<0) {
      printf("** PyType_Ready failed for: oaOccEvalText\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccEvalText",
           (PyObject*)(&PyoaOccEvalText_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccEvalText\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaOccHeaderModTypeEnum
// ==================================================================

// ------------------------------------------------------------------

int
PyoaOccHeaderModTypeEnum_Convert(PyObject* ob,PyParamoaOccHeaderModTypeEnum* result)
{
    if (ob == NULL) return 1;
    if (PyString_Check(ob)) {
        char* str=PyString_AsString(ob);
        if (strcasecmp(str,"oacCreateOccDataTblModType")==0) { result->SetData(oacCreateOccDataTblModType); return 1;}
        if (strcasecmp(str,"oacDestroyOccDataTblModType")==0) { result->SetData(oacDestroyOccDataTblModType); return 1;}
    }            
    if (PyInt_Check(ob)) {
        long val=PyInt_AsLong(ob);
        result->SetData((oaOccHeaderModTypeEnum)val);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccHeaderModTypeEnum Failed");
    return 0;
}
// ------------------------------------------------------------------

PyObject* PyoaOccHeaderModTypeEnum_FromoaOccHeaderModTypeEnum(oaOccHeaderModTypeEnum ob)
{
    if (ob==oacCreateOccDataTblModType) return PyString_FromString("oacCreateOccDataTblModType");
    if (ob==oacDestroyOccDataTblModType) return PyString_FromString("oacDestroyOccDataTblModType");

    Py_INCREF(Py_None);
    return Py_None;
}

// ------------------------------------------------------------------
//  Enum Typecast function:
// ------------------------------------------------------------------

static PyObject*
PyoaOccHeaderModTypeEnum_TypeFunction(PyObject* mod,PyObject* args)
{
    int v;
    oaOccHeaderModTypeEnum e;
    if (PyArg_ParseTuple(args,(char*)"i",&v)) {
       return PyoaOccHeaderModTypeEnum_FromoaOccHeaderModTypeEnum(oaOccHeaderModTypeEnum(v));
    }
    PyErr_Clear();
    if (PyArg_ParseTuple(args,(char*)"O&",&PyoaOccHeaderModTypeEnum_Convert,&e)) {
       return PyInt_FromLong(long(e));
    }
    return NULL;
}
static char oaOccHeaderModTypeEnum_doc[] =
"Type convert function for enum: oaOccHeaderModTypeEnum";
                               
static PyMethodDef PyoaOccHeaderModTypeEnum_method =
  {"oaOccHeaderModTypeEnum",(PyCFunction)PyoaOccHeaderModTypeEnum_TypeFunction,METH_VARARGS,oaOccHeaderModTypeEnum_doc};
  

// ------------------------------------------------------------------
//  Enum Init:
// ------------------------------------------------------------------

int
PyoaOccHeaderModTypeEnum_TypeInit(PyObject* mod_dict)
{
    // Put Enum values in Dictionary
    PyObject* value;
    value=PyString_FromString("oacCreateOccDataTblModType");
    PyDict_SetItemString(mod_dict,"oacCreateOccDataTblModType",value);
    Py_DECREF(value);
    value=PyString_FromString("oacDestroyOccDataTblModType");
    PyDict_SetItemString(mod_dict,"oacDestroyOccDataTblModType",value);
    Py_DECREF(value);

    // Put Enum name function in Dictionary
    value=PyCFunction_New(&PyoaOccHeaderModTypeEnum_method,NULL);
    if (PyDict_SetItemString(mod_dict,"oaOccHeaderModTypeEnum",value)!=0) {
    Py_DECREF(value);
        printf("** Failed to add enum function to module dictionary for: oaOccHeaderModTypeEnum\n");
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
// Wrapper Implementation for Class: oaOccInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccInstObject* self = (PyoaOccInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccInst)
    {
        PyParamoaOccInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccInst_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccInst, Choices are:\n"
        "    (oaOccInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccInst_tp_dealloc(PyoaOccInstObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccInst_tp_repr(PyObject *ob)
{
    PyParamoaOccInst value;
    int convert_status=PyoaOccInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;
    if (!value.Data()) {
        oaString buffer("<oaOccInst::NULL>");
        result=PyString_FromString((char*)(const char*)buffer);
    }
    else {
        oaSimpleName name;
        oaString sresult;
        value.DataCall()->getName(name);
        name.get(sresult);
    
        char addr[31];
        sprintf(addr,DISPLAY_FORMAT,POINTER_AS_DISPLAY(value.DataCall()));
        oaString buffer;
        buffer+=oaString("<oaOccInst::");
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
oaOccInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccInst v1;
    PyParamoaOccInst v2;
    int convert_status1=PyoaOccInst_Convert(ob1,&v1);
    int convert_status2=PyoaOccInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccInst_Convert(PyObject* ob,PyParamoaOccInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccInst_Check(ob)) {
        result->SetData( (oaOccInst**) ((PyoaOccInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccInst_FromoaOccInst(oaOccInst** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccInst* data=*value;
        if (data->isOccModuleInst()) return PyoaOccModuleInst_FromoaOccModuleInst((oaOccModuleInst**)value,borrow,lock);
        if (data->isOccDesignInst()) return PyoaOccDesignInst_FromoaOccDesignInst((oaOccDesignInst**)value,borrow,lock);
        PyObject* bself = PyoaOccInst_Type.tp_alloc(&PyoaOccInst_Type,0);
        if (bself == NULL) return bself;
        PyoaOccInstObject* self = (PyoaOccInstObject*)bself;
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
PyObject* PyoaOccInst_FromoaOccInst(oaOccInst* data)
{
    if (data) {
        if (data->isOccModuleInst()) return PyoaOccModuleInst_FromoaOccModuleInst((oaOccModuleInst*)data);
        if (data->isOccDesignInst()) return PyoaOccDesignInst_FromoaOccDesignInst((oaOccDesignInst*)data);
       PyObject* bself = PyoaOccInst_Type.tp_alloc(&PyoaOccInst_Type,0);
       if (bself == NULL) return bself;
       PyoaOccInstObject* self = (PyoaOccInstObject*)bself;
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
static char oaOccInst_getAssignments_doc[] = 
"Class: oaOccInst, Function: getAssignments\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaOccAssignment_oaOccInst getAssignments() const\n"
"    Signature: getAssignments|simple-oaCollection_oaOccAssignment_oaOccInst|\n"
"    BrowseData: 1\n"
"    This function returns a collection of occurrence assignments associated with this instance.\n"
;

static PyObject*
oaOccInst_getAssignments(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInst data;
    int convert_status=PyoaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstObject* self=(PyoaOccInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaCollection_oaOccAssignment_oaOccInst* result= new oaCollection_oaOccAssignment_oaOccInst(data.DataCall()->getAssignments());
        return PyoaCollection_oaOccAssignment_oaOccInst_FromoaCollection_oaOccAssignment_oaOccInst(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccInst_getAssignmentsIter_doc[] = 
"Class: oaOccInst, Function: getAssignmentsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaOccAssignment getAssignmentsIter() const\n"
"    Signature: getAssignmentsIter|simple-oaIter_oaOccAssignment|\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of occurrence assignments associated with this instance.\n"
;

static PyObject*
oaOccInst_getAssignmentsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInst data;
    int convert_status=PyoaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstObject* self=(PyoaOccInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaIter_oaOccAssignment* result= new oaIter_oaOccAssignment(data.DataCall()->getAssignments());
        return PyoaIter_oaOccAssignment_FromoaIter_oaOccAssignment(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaOccInst_getInst_doc[] = 
"Class: oaOccInst, Function: getInst\n"
"  Paramegers: ()\n"
"    Calls: oaInst* getInst() const\n"
"    Signature: getInst|ptr-oaInst|\n"
"    BrowseData: 1\n"
"    This function returns the corresponding instance in the block domain. NULL will be returned if the master design for this instance does not have a top block.\n"
"    A pointer to an oaInst\n"
;

static PyObject*
oaOccInst_getInst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInst data;
    int convert_status=PyoaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstObject* self=(PyoaOccInstObject*)ob;
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
static char oaOccInst_getInstTerms_doc[] = 
"Class: oaOccInst, Function: getInstTerms\n"
"  Paramegers: ()\n"
"    Calls: oaCollection_oaOccInstTerm_oaOccInst getInstTerms() const\n"
"    Signature: getInstTerms|simple-oaCollection_oaOccInstTerm_oaOccInst|simple-oaUInt4,\n"
"    BrowseData: 1\n"
"    This function returns a collection of occurrence instTerms associated with this instance.\n"
"    filterFlags\n"
"    Specifies what the collection contains. The bits flags are defined as follows:\n"
"    oacInstTermIterNotImplicit: the collection will only contain instTerms that were explicitly created\n"
"    oacInstTermIterSingleBit: the collection will only contain instTerms that make a single-bit connection\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaCollection_oaOccInstTerm_oaOccInst getInstTerms(oaUInt4 filterFlags) const\n"
"    Signature: getInstTerms|simple-oaCollection_oaOccInstTerm_oaOccInst|simple-oaUInt4,\n"
"    This function returns a collection of occurrence instTerms associated with this instance.\n"
"    filterFlags\n"
"    Specifies what the collection contains. The bits flags are defined as follows:\n"
"    oacInstTermIterNotImplicit: the collection will only contain instTerms that were explicitly created\n"
"    oacInstTermIterSingleBit: the collection will only contain instTerms that make a single-bit connection\n"
;

static PyObject*
oaOccInst_getInstTerms(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInst data;
    int convert_status=PyoaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstObject* self=(PyoaOccInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaCollection_oaOccInstTerm_oaOccInst* result= new oaCollection_oaOccInstTerm_oaOccInst(data.DataCall()->getInstTerms());
            return PyoaCollection_oaOccInstTerm_oaOccInst_FromoaCollection_oaOccInstTerm_oaOccInst(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            oaCollection_oaOccInstTerm_oaOccInst* result= new oaCollection_oaOccInstTerm_oaOccInst(data.DataCall()->getInstTerms(p1.Data()));
            return PyoaCollection_oaOccInstTerm_oaOccInst_FromoaCollection_oaOccInstTerm_oaOccInst(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaOccInst, function: getInstTerms, Choices are:\n"
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
static char oaOccInst_getInstTermsIter_doc[] = 
"Class: oaOccInst, Function: getInstTermsIter\n"
"  Paramegers: ()\n"
"    Calls: oaIter_oaOccInstTerm getInstTermsIter() const\n"
"    Signature: getInstTermsIter|simple-oaIter_oaOccInstTerm|simple-oaUInt4,\n"
"    BrowseData: 1\n"
"    This function returns an Iterator over the following collection: This function returns a collection of occurrence instTerms associated with this instance.\n"
"    filterFlags\n"
"    Specifies what the collection contains. The bits flags are defined as follows:\n"
"    oacInstTermIterNotImplicit: the collection will only contain instTerms that were explicitly created\n"
"    oacInstTermIterSingleBit: the collection will only contain instTerms that make a single-bit connection\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaIter_oaOccInstTerm getInstTermsIter(oaUInt4 filterFlags) const\n"
"    Signature: getInstTermsIter|simple-oaIter_oaOccInstTerm|simple-oaUInt4,\n"
"    This function returns an Iterator over the following collection: This function returns a collection of occurrence instTerms associated with this instance.\n"
"    filterFlags\n"
"    Specifies what the collection contains. The bits flags are defined as follows:\n"
"    oacInstTermIterNotImplicit: the collection will only contain instTerms that were explicitly created\n"
"    oacInstTermIterSingleBit: the collection will only contain instTerms that make a single-bit connection\n"
;

static PyObject*
oaOccInst_getInstTermsIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInst data;
    int convert_status=PyoaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstObject* self=(PyoaOccInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaIter_oaOccInstTerm* result= new oaIter_oaOccInstTerm(data.DataCall()->getInstTerms());
            return PyoaIter_oaOccInstTerm_FromoaIter_oaOccInstTerm(result,0,NULL);
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            oaIter_oaOccInstTerm* result= new oaIter_oaOccInstTerm(data.DataCall()->getInstTerms(p1.Data()));
            return PyoaIter_oaOccInstTerm_FromoaIter_oaOccInstTerm(result,0,NULL);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaOccInst, function: getInstTermsIter, Choices are:\n"
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
static char oaOccInst_getMasterOccurrence_doc[] = 
"Class: oaOccInst, Function: getMasterOccurrence\n"
"  Paramegers: ()\n"
"    Calls: oaOccurrence* getMasterOccurrence() const\n"
"    Signature: getMasterOccurrence|ptr-oaOccurrence|simple-oaBoolean,\n"
"    BrowseData: 1\n"
"    oaOccInst::getMasterOccurrence\n"
"    This function attempts to return the master associated with this instance. If expand is true and the instance cannot be bound, NULL is returned. An exception will be thrown if the instance is a vectorInst or an implicit vectorInstBit, as there is no occurrence hierarchy beneath those types of instances.\n"
"    An application will generally make a pass over the occurrence hierarchy calling getMasterOccurrence with expand set to true to expand the hierarchy to the desired depth. Later traversals will set expand to false so the traversal does not cause additional expansion. See oaOccTraverser for a utility class that can simplify walking the occurrence hierarchy\n"
"    expand\n"
"    Specifies whether to expand the occurrence hierarchy to include the master occurrence for this instance, if it has not yet been expanded in the current session.\n"
"    oacCannotGetVectorInstOccurrence\n"
"    oacCannotGetImplicitInstOccurrence\n"
"  Paramegers: (oaBoolean)\n"
"    Calls: oaOccurrence* getMasterOccurrence(oaBoolean expand) const\n"
"    Signature: getMasterOccurrence|ptr-oaOccurrence|simple-oaBoolean,\n"
"    oaOccInst::getMasterOccurrence\n"
"    This function attempts to return the master associated with this instance. If expand is true and the instance cannot be bound, NULL is returned. An exception will be thrown if the instance is a vectorInst or an implicit vectorInstBit, as there is no occurrence hierarchy beneath those types of instances.\n"
"    An application will generally make a pass over the occurrence hierarchy calling getMasterOccurrence with expand set to true to expand the hierarchy to the desired depth. Later traversals will set expand to false so the traversal does not cause additional expansion. See oaOccTraverser for a utility class that can simplify walking the occurrence hierarchy\n"
"    expand\n"
"    Specifies whether to expand the occurrence hierarchy to include the master occurrence for this instance, if it has not yet been expanded in the current session.\n"
"    oacCannotGetVectorInstOccurrence\n"
"    oacCannotGetImplicitInstOccurrence\n"
;

static PyObject*
oaOccInst_getMasterOccurrence(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInst data;
    int convert_status=PyoaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstObject* self=(PyoaOccInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            oaOccurrencep result= (data.DataCall()->getMasterOccurrence());
            return PyoaOccurrence_FromoaOccurrence(result);
        }
    }
    PyErr_Clear();
    // Case: (oaBoolean)
    {
        PyParamoaBoolean p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaBoolean_Convert,&p1)) {
            oaOccurrencep result= (data.DataCall()->getMasterOccurrence(p1.Data()));
            return PyoaOccurrence_FromoaOccurrence(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaOccInst, function: getMasterOccurrence, Choices are:\n"
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
static char oaOccInst_getModInst_doc[] = 
"Class: oaOccInst, Function: getModInst\n"
"  Paramegers: ()\n"
"    Calls: oaModInst* getModInst() const\n"
"    Signature: getModInst|ptr-oaModInst|\n"
"    BrowseData: 1\n"
"    This function returns the corresponding instance in the module domain. NULL will be returned if this instance is an occurrence of a physical-only instance.\n"
"    A pointer to an oaModInst\n"
;

static PyObject*
oaOccInst_getModInst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInst data;
    int convert_status=PyoaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstObject* self=(PyoaOccInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaModInstp result= (data.DataCall()->getModInst());
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
static char oaOccInst_getName_doc[] = 
"Class: oaOccInst, Function: getName\n"
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
oaOccInst_getName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInst data;
    int convert_status=PyoaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstObject* self=(PyoaOccInstObject*)ob;
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
        "No Arg-Matching Function found for class: oaOccInst, function: getName, Choices are:\n"
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
static char oaOccInst_getNumBits_doc[] = 
"Class: oaOccInst, Function: getNumBits\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getNumBits() const\n"
"    Signature: getNumBits|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the number of bits of this instance. This function always returns '1' for scalar and array instances. The function can return '1' or more for vector instances.\n"
;

static PyObject*
oaOccInst_getNumBits(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInst data;
    int convert_status=PyoaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstObject* self=(PyoaOccInstObject*)ob;
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
static char oaOccInst_getPathName_doc[] = 
"Class: oaOccInst, Function: getPathName\n"
"  Paramegers: (oaSimpleName)\n"
"    Calls: void getPathName(oaSimpleName& pathName) const\n"
"    Signature: getPathName|void-void|ref-oaSimpleName,\n"
"    BrowseData: 0,oaSimpleName\n"
"    This function fills out pathName with the full path name of this instance, relative to the top occurrence in the occurrence hierarchy containing this instance.\n"
"    pathName\n"
"    The path name of the instance\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getPathName(const oaNameSpace& ns,oaString& pathName) const\n"
"    Signature: getPathName|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the full path name of this instance in the specified nameSpace in the specified pathName string. The pathName is relative to the top occurrence in the occurrence hierarchy containing this instance.\n"
"    ns\n"
"    The nameSpace in which to return the name\n"
"    pathName\n"
"    The path name of the instance\n"
;

static PyObject*
oaOccInst_getPathName(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInst data;
    int convert_status=PyoaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstObject* self=(PyoaOccInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    // Case: (oaSimpleName)
    {
        PyParamoaSimpleName p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaSimpleName_Convert,&p1)) {
            data.DataCall()->getPathName(p1.Data());
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
            data.DataCall()->getPathName(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaOccInst, function: getPathName, Choices are:\n"
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
static char oaOccInst_isBound_doc[] = 
"Class: oaOccInst, Function: isBound\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isBound() const\n"
"    Signature: isBound|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this instance is currently bound to its master. An instance is bound to its master if some traversal is made from the instance to the master or an object in the master. If the instance is bound, then its master is in memory and the linkage from the instance to the master is established.\n"
"    true if the instance is bound, otherwise false\n"
;

static PyObject*
oaOccInst_isBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInst data;
    int convert_status=PyoaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstObject* self=(PyoaOccInstObject*)ob;
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
static char oaOccInst_isImplicit_doc[] = 
"Class: oaOccInst, Function: isImplicit\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isImplicit() const\n"
"    Signature: isImplicit|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this instance is implicit, having been automatically created as a result of the creation of a vectorInst.\n"
;

static PyObject*
oaOccInst_isImplicit(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInst data;
    int convert_status=PyoaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstObject* self=(PyoaOccInstObject*)ob;
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
static char oaOccInst_isOccDesignInst_doc[] = 
"Class: oaOccInst, Function: isOccDesignInst\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isOccDesignInst() const\n"
"    Signature: isOccDesignInst|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function determines if this object is an instance of one of the classes derived from the oaOccDesignInst class. The function returns a boolean value of true if the oaOccInst is an oaOccDesignInst .\n"
;

static PyObject*
oaOccInst_isOccDesignInst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInst data;
    int convert_status=PyoaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstObject* self=(PyoaOccInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isOccDesignInst());
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
static char oaOccInst_isOccModuleInst_doc[] = 
"Class: oaOccInst, Function: isOccModuleInst\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isOccModuleInst() const\n"
"    Signature: isOccModuleInst|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function determines if this object is an instance of one of the classes derived from the oaOccModuleInst class. The function returns a boolean value of true if the oaOccInst is an oaOccModuleInst .\n"
;

static PyObject*
oaOccInst_isOccModuleInst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInst data;
    int convert_status=PyoaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstObject* self=(PyoaOccInstObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (data.DataCall()->isOccModuleInst());
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
static char oaOccInst_usesTermPositions_doc[] = 
"Class: oaOccInst, Function: usesTermPositions\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean usesTermPositions() const\n"
"    Signature: usesTermPositions|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean indicating how connections to this instance have been made. If the instTerms associated with this instance connect to terminal positions, this function returns 'true'. Otherwise, this function returns 'false'. Note that if the collection of instTerms for this instance is empty, this function will also return 'false'.\n"
;

static PyObject*
oaOccInst_usesTermPositions(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInst data;
    int convert_status=PyoaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstObject* self=(PyoaOccInstObject*)ob;
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
static char oaOccInst_isNull_doc[] =
"Class: oaOccInst, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccInst_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccInst data;
    int convert_status=PyoaOccInst_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccInst_assign_doc[] = 
"Class: oaOccInst, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccInst_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccInst data;
  int convert_status=PyoaOccInst_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccInst p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccInst_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccInst_methodlist[] = {
    {"getAssignments",(PyCFunction)oaOccInst_getAssignments,METH_VARARGS,oaOccInst_getAssignments_doc},
    {"getAssignmentsIter",(PyCFunction)oaOccInst_getAssignmentsIter,METH_VARARGS,oaOccInst_getAssignmentsIter_doc},
    {"getInst",(PyCFunction)oaOccInst_getInst,METH_VARARGS,oaOccInst_getInst_doc},
    {"getInstTerms",(PyCFunction)oaOccInst_getInstTerms,METH_VARARGS,oaOccInst_getInstTerms_doc},
    {"getInstTermsIter",(PyCFunction)oaOccInst_getInstTermsIter,METH_VARARGS,oaOccInst_getInstTermsIter_doc},
    {"getMasterOccurrence",(PyCFunction)oaOccInst_getMasterOccurrence,METH_VARARGS,oaOccInst_getMasterOccurrence_doc},
    {"getModInst",(PyCFunction)oaOccInst_getModInst,METH_VARARGS,oaOccInst_getModInst_doc},
    {"getName",(PyCFunction)oaOccInst_getName,METH_VARARGS,oaOccInst_getName_doc},
    {"getNumBits",(PyCFunction)oaOccInst_getNumBits,METH_VARARGS,oaOccInst_getNumBits_doc},
    {"getPathName",(PyCFunction)oaOccInst_getPathName,METH_VARARGS,oaOccInst_getPathName_doc},
    {"isBound",(PyCFunction)oaOccInst_isBound,METH_VARARGS,oaOccInst_isBound_doc},
    {"isImplicit",(PyCFunction)oaOccInst_isImplicit,METH_VARARGS,oaOccInst_isImplicit_doc},
    {"isOccDesignInst",(PyCFunction)oaOccInst_isOccDesignInst,METH_VARARGS,oaOccInst_isOccDesignInst_doc},
    {"isOccModuleInst",(PyCFunction)oaOccInst_isOccModuleInst,METH_VARARGS,oaOccInst_isOccModuleInst_doc},
    {"usesTermPositions",(PyCFunction)oaOccInst_usesTermPositions,METH_VARARGS,oaOccInst_usesTermPositions_doc},
    {"isNull",(PyCFunction)oaOccInst_tp_isNull,METH_VARARGS,oaOccInst_isNull_doc},
    {"assign",(PyCFunction)oaOccInst_tp_assign,METH_VARARGS,oaOccInst_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccInst_doc[] = 
"Class: oaOccInst\n"
"  The oaOccInst class is an abstract base class for occurrence instances. An occurrence instance is the reflection of either an oaModInst or an oaInst in the occurrence hierarchy. The occurrence hierarchy is the completely unfolded version of the union of the module and block hierarchies. See Understanding OpenAccess Embedded Module Hierarchy in the Programmers Guide for a discussion of the occurrence hierarchy.\n"
"  An oaOccInst may correspond to an oaModInst , an oaInst , or both:\n"
"  If the occInst is an occurrence of an oaModModuleInst (it will be an oaOccModuleScalarInst , or an oaOccModuleVectorInst ) then it will only have a corresponding oaModInst .\n"
"  If the occInst is an occurrence of an oaModInst that is not visible in the block domain, then it will only have a corresponding oaModInst .\n"
"  If the occInst is an occurrence of an oaInst that is not visible in the module domain, then it will only have a corresponding oaInst . It will be either an oaOccScalarInst an oaOccVectorInst or an oaOccArrayInst in this case.\n"
"  Otherwise the occInst will have both a corresponding oaModInst and a corresponding oaInst .\n"
"  An oaOccInst will always have an oaOccurrence that is its parent .\n"
"  An oaOccInst will always have an oaOccurrence that is its master except at the frontier which is the bottom level of the occurrence hierarchy.\n"
"  All occurrence instances have names. These names are non-hierarchical names that are scoped relative to the parent occurrence. For an occInst that is an occurrence of an oaModInst its name is the name of the oaModInst . For an occurrence of an oaInst that doesn't have an oaModInst (a physical-only instance) its name is the name of that oaInst .\n"
"  OccInsts always have an InstHeader which is one of oaOccInstHeader or oaOccModuleInstHeader . This header contains the attributes that are common for all of the occInsts with the same master within the same parent occurrence.\n"
"  The oaOccInst class can be observed by deriving from\n"
"Constructors:\n"
"  Paramegers: (oaOccInst)\n"
"    Calls: (const oaOccInst&)\n"
"    Signature: oaOccInst||cref-oaOccInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccInst",
    sizeof(PyoaOccInstObject),
    0,
    (destructor)oaOccInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccInst_tp_compare,	/* tp_compare */
    (reprfunc)oaOccInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccInst_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccObject_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccInst_static_find_doc[] = 
"Class: oaOccInst, Function: find\n"
"  Paramegers: (oaOccurrence,oaSimpleName)\n"
"    Calls: oaOccInst* find(const oaOccurrence* occurrence,const oaSimpleName& name)\n"
"    Signature: find|ptr-oaOccInst|cptr-oaOccurrence,cref-oaSimpleName,\n"
"    This function searches the specified occurrence looking for an instance with the specified name . If name is hierarchical, this function will descend into lower levels of occurrence hierarchy, expanding the hierarchy and binding the master designs as needed. The instance is returned if found, otherwise NULL is returned.\n"
"    occurrence\n"
"    The occurrence domain to search\n"
"    name\n"
"    The instance name to find\n"
"    A pointer to an oaOccInst\n"
;

static PyObject*
oaOccInst_static_find(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccurrence p1;
    PyParamoaSimpleName p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaOccurrence_Convert,&p1,
          &PyoaSimpleName_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaOccInstp result= (oaOccInst::find(p1.Data(),p2.Data()));
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
static PyMethodDef oaOccInst_staticmethodlist[] = {
    {"static_find",(PyCFunction)oaOccInst_static_find,METH_VARARGS,oaOccInst_static_find_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccInst_Type)<0) {
      printf("** PyType_Ready failed for: oaOccInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccInst",
           (PyObject*)(&PyoaOccInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccInst\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaOccInst_Type.tp_dict;
    for(method=oaOccInst_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaOccInstAttrDisplay
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaOccInstAttrDisplay_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaOccInstAttrDisplay_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaOccInstAttrDisplayObject* self = (PyoaOccInstAttrDisplayObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaOccInstAttrDisplay)
    {
        PyParamoaOccInstAttrDisplay p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaOccInstAttrDisplay_Convert,&p1)) {
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
        "No Arg-Matching Constructor found for class: oaOccInstAttrDisplay, Choices are:\n"
        "    (oaOccInstAttrDisplay)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaOccInstAttrDisplay_tp_dealloc(PyoaOccInstAttrDisplayObject* self)
{
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaOccInstAttrDisplay_tp_repr(PyObject *ob)
{
    PyParamoaOccInstAttrDisplay value;
    int convert_status=PyoaOccInstAttrDisplay_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaOccInstAttrDisplay::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaOccInstAttrDisplay_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaOccInstAttrDisplay v1;
    PyParamoaOccInstAttrDisplay v2;
    int convert_status1=PyoaOccInstAttrDisplay_Convert(ob1,&v1);
    int convert_status2=PyoaOccInstAttrDisplay_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaOccInstAttrDisplay_Convert(PyObject* ob,PyParamoaOccInstAttrDisplay* result)
{
    if (ob == NULL) return 1;
    if (PyoaOccInstAttrDisplay_Check(ob)) {
        result->SetData( (oaOccInstAttrDisplay**) ((PyoaOccInstAttrDisplayObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaOccInstAttrDisplay Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaOccInstAttrDisplay_FromoaOccInstAttrDisplay(oaOccInstAttrDisplay** value,int borrow,PyObject* lock)
{
    if (value && *value) {
        oaOccInstAttrDisplay* data=*value;
        PyObject* bself = PyoaOccInstAttrDisplay_Type.tp_alloc(&PyoaOccInstAttrDisplay_Type,0);
        if (bself == NULL) return bself;
        PyoaOccInstAttrDisplayObject* self = (PyoaOccInstAttrDisplayObject*)bself;
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
PyObject* PyoaOccInstAttrDisplay_FromoaOccInstAttrDisplay(oaOccInstAttrDisplay* data)
{
    if (data) {
       PyObject* bself = PyoaOccInstAttrDisplay_Type.tp_alloc(&PyoaOccInstAttrDisplay_Type,0);
       if (bself == NULL) return bself;
       PyoaOccInstAttrDisplayObject* self = (PyoaOccInstAttrDisplayObject*)bself;
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
static char oaOccInstAttrDisplay_getInst_doc[] = 
"Class: oaOccInstAttrDisplay, Function: getInst\n"
"  Paramegers: ()\n"
"    Calls: oaInst* getInst() const\n"
"    Signature: getInst|ptr-oaInst|\n"
"    BrowseData: 1\n"
"    This function returns the instance associated with this instAttrDisplay object.\n"
;

static PyObject*
oaOccInstAttrDisplay_getInst(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInstAttrDisplay data;
    int convert_status=PyoaOccInstAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstAttrDisplayObject* self=(PyoaOccInstAttrDisplayObject*)ob;
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
static char oaOccInstAttrDisplay_getMasterAttribute_doc[] = 
"Class: oaOccInstAttrDisplay, Function: getMasterAttribute\n"
"  Paramegers: ()\n"
"    Calls: oaDesignAttrType getMasterAttribute() const\n"
"    Signature: getMasterAttribute|simple-oaDesignAttrType|\n"
"    BrowseData: 1\n"
"    This function returns the master attributes associated with this instAttrDisplay object.\n"
;

static PyObject*
oaOccInstAttrDisplay_getMasterAttribute(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInstAttrDisplay data;
    int convert_status=PyoaOccInstAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstAttrDisplayObject* self=(PyoaOccInstAttrDisplayObject*)ob;
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
static char oaOccInstAttrDisplay_getText_doc[] = 
"Class: oaOccInstAttrDisplay, Function: getText\n"
"  Paramegers: (oaNameSpace,oaString)\n"
"    Calls: void getText(const oaNameSpace& ns,oaString& text) const\n"
"    Signature: getText|void-void|cref-oaNameSpace,ref-oaString,\n"
"    This function returns the value of this attribute display according to the given nameSpace. The nameSpace is only valid for name type attributes.\n"
"    ns\n"
"    The nameSpace to be used\n"
"    text\n"
"    The text string to be filled\n"
;

static PyObject*
oaOccInstAttrDisplay_getText(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInstAttrDisplay data;
    int convert_status=PyoaOccInstAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstAttrDisplayObject* self=(PyoaOccInstAttrDisplayObject*)ob;
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
static char oaOccInstAttrDisplay_isBound_doc[] = 
"Class: oaOccInstAttrDisplay, Function: isBound\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isBound() const\n"
"    Signature: isBound|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean which indicates whether this text display is currently bound.\n"
;

static PyObject*
oaOccInstAttrDisplay_isBound(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaOccInstAttrDisplay data;
    int convert_status=PyoaOccInstAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaOccInstAttrDisplayObject* self=(PyoaOccInstAttrDisplayObject*)ob;
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
static char oaOccInstAttrDisplay_isNull_doc[] =
"Class: oaOccInstAttrDisplay, Function: isNull\n"
"  Parameters: () \n"
"    This functions returns 1 if the DbPointer is NULL, and 0 otherwise.\n"
;

static PyObject*
oaOccInstAttrDisplay_tp_isNull(PyObject* ob, PyObject *args)
{
    PyParamoaOccInstAttrDisplay data;
    int convert_status=PyoaOccInstAttrDisplay_Convert(ob,&data);
    assert(convert_status!=0);
    if (data.DataCall()==NULL)
        return PyInt_FromLong(1);
    else
        return PyInt_FromLong(0);
}
static char oaOccInstAttrDisplay_assign_doc[] = 
"Class: oaOccInstAttrDisplay, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaOccInstAttrDisplay_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaOccInstAttrDisplay data;
  int convert_status=PyoaOccInstAttrDisplay_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaOccInstAttrDisplay p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaOccInstAttrDisplay_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaOccInstAttrDisplay_methodlist[] = {
    {"getInst",(PyCFunction)oaOccInstAttrDisplay_getInst,METH_VARARGS,oaOccInstAttrDisplay_getInst_doc},
    {"getMasterAttribute",(PyCFunction)oaOccInstAttrDisplay_getMasterAttribute,METH_VARARGS,oaOccInstAttrDisplay_getMasterAttribute_doc},
    {"getText",(PyCFunction)oaOccInstAttrDisplay_getText,METH_VARARGS,oaOccInstAttrDisplay_getText_doc},
    {"isBound",(PyCFunction)oaOccInstAttrDisplay_isBound,METH_VARARGS,oaOccInstAttrDisplay_isBound_doc},
    {"isNull",(PyCFunction)oaOccInstAttrDisplay_tp_isNull,METH_VARARGS,oaOccInstAttrDisplay_isNull_doc},
    {"assign",(PyCFunction)oaOccInstAttrDisplay_tp_assign,METH_VARARGS,oaOccInstAttrDisplay_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaOccInstAttrDisplay_doc[] = 
"Class: oaOccInstAttrDisplay\n"
"  The oaOccInstAttrDisplay class implements an unique occurrence of an oaInstAttrDisplay object in a design hierarchy.\n"
"Constructors:\n"
"  Paramegers: (oaOccInstAttrDisplay)\n"
"    Calls: (const oaOccInstAttrDisplay&)\n"
"    Signature: oaOccInstAttrDisplay||cref-oaOccInstAttrDisplay,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaOccInstAttrDisplay_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaOccInstAttrDisplay",
    sizeof(PyoaOccInstAttrDisplayObject),
    0,
    (destructor)oaOccInstAttrDisplay_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaOccInstAttrDisplay_tp_compare,	/* tp_compare */
    (reprfunc)oaOccInstAttrDisplay_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaOccInstAttrDisplay_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaOccInstAttrDisplay_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaOccTextDisplay_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaOccInstAttrDisplay_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaOccInstAttrDisplay_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaOccInstAttrDisplay_Type)<0) {
      printf("** PyType_Ready failed for: oaOccInstAttrDisplay\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaOccInstAttrDisplay",
           (PyObject*)(&PyoaOccInstAttrDisplay_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaOccInstAttrDisplay\n");
       return -1;
    }
    return 0;
}

