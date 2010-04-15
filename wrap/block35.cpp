
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaCellView
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaCellView_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaCellView_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaCellViewObject* self = (PyoaObserver_oaCellViewObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaCellView(p1.Data());
            }
            else {
                pyv_oaObserver_oaCellView* p=new pyv_oaObserver_oaCellView(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaCellView(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaCellView* p=new pyv_oaObserver_oaCellView(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaCellView)
    {
        PyParamoaObserver_oaCellView p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaCellView_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaCellView(p1.Data());
            }
            else {
                pyv_oaObserver_oaCellView* p=new pyv_oaObserver_oaCellView(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaCellView, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaCellView)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaCellView_tp_dealloc(PyoaObserver_oaCellViewObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaCellView*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaCellView_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaCellView value;
    int convert_status=PyoaObserver_oaCellView_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaObserver_oaCellView::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaCellView_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaCellView v1;
    PyParamoaObserver_oaCellView v2;
    int convert_status1=PyoaObserver_oaCellView_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaCellView_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaCellView_Convert(PyObject* ob,PyParamoaObserver_oaCellView* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaCellView_Check(ob)) {
        result->SetData( (oaObserver_oaCellView*) ((PyoaObserver_oaCellViewObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaCellView Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaCellView_FromoaObserver_oaCellView(oaObserver_oaCellView* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaCellView_Type.tp_alloc(&PyoaObserver_oaCellView_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaCellViewObject* self = (PyoaObserver_oaCellViewObject*)bself;
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
pyv_oaObserver_oaCellView::pyv_oaObserver_oaCellView(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaCellView(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaCellView::pyv_oaObserver_oaCellView(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaCellView(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaCellView::pyv_oaObserver_oaCellView(const oaObserver_oaCellView& p)
 : pyob(NULL),
   oaObserver_oaCellView(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCellView::onPostCreate(oaCellView* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCellView::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaCellView_FromoaCellView(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCellView::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCellView::onPostModify(oaCellView* p1,oaCellViewModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCellView::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaCellView_FromoaCellView(p1));
    PyTuple_SetItem(args,1,PyoaCellViewModTypeEnum_FromoaCellViewModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCellView::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCellView::onPreDestroy(oaCellView* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCellView::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaCellView_FromoaCellView(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCellView::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCellView::onPreModify(oaCellView* p1,oaCellViewModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCellView::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaCellView_FromoaCellView(p1));
    PyTuple_SetItem(args,1,PyoaCellViewModTypeEnum_FromoaCellViewModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCellView::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaCellView_doc[] = 
"Class: oaObserver_oaCellView\n"
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
"    Calls: oaObserver_oaCellView(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaCellView||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaCellView\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaCellView(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaCellView||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaCellView\n"
"  Paramegers: (oaObserver_oaCellView)\n"
"    Calls: (const oaObserver_oaCellView&)\n"
"    Signature: oaObserver_oaCellView||cref-oaObserver_oaCellView,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaCellView_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaCellView",
    sizeof(PyoaObserver_oaCellViewObject),
    0,
    (destructor)oaObserver_oaCellView_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaCellView_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaCellView_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaCellView_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaCellView_oaCellViewModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaCellView_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaCellView_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaCellView_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaCellView\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaCellView",
           (PyObject*)(&PyoaObserver_oaCellView_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaCellView\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaCluster
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaCluster_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaCluster_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaClusterObject* self = (PyoaObserver_oaClusterObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaCluster(p1.Data());
            }
            else {
                pyv_oaObserver_oaCluster* p=new pyv_oaObserver_oaCluster(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaCluster(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaCluster* p=new pyv_oaObserver_oaCluster(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaCluster)
    {
        PyParamoaObserver_oaCluster p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaCluster_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaCluster(p1.Data());
            }
            else {
                pyv_oaObserver_oaCluster* p=new pyv_oaObserver_oaCluster(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaCluster, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaCluster)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaCluster_tp_dealloc(PyoaObserver_oaClusterObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaCluster*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaCluster_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaCluster value;
    int convert_status=PyoaObserver_oaCluster_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaObserver_oaCluster::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaCluster_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaCluster v1;
    PyParamoaObserver_oaCluster v2;
    int convert_status1=PyoaObserver_oaCluster_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaCluster_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaCluster_Convert(PyObject* ob,PyParamoaObserver_oaCluster* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaCluster_Check(ob)) {
        result->SetData( (oaObserver_oaCluster*) ((PyoaObserver_oaClusterObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaCluster Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaCluster_FromoaObserver_oaCluster(oaObserver_oaCluster* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaCluster_Type.tp_alloc(&PyoaObserver_oaCluster_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaClusterObject* self = (PyoaObserver_oaClusterObject*)bself;
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
pyv_oaObserver_oaCluster::pyv_oaObserver_oaCluster(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaCluster(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaCluster::pyv_oaObserver_oaCluster(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaCluster(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaCluster::pyv_oaObserver_oaCluster(const oaObserver_oaCluster& p)
 : pyob(NULL),
   oaObserver_oaCluster(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCluster::onPostCreate(oaCluster* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCluster::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaCluster_FromoaCluster(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCluster::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCluster::onPostModify(oaCluster* p1,oaClusterModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCluster::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaCluster_FromoaCluster(p1));
    PyTuple_SetItem(args,1,PyoaClusterModTypeEnum_FromoaClusterModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCluster::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCluster::onPreDestroy(oaCluster* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCluster::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaCluster_FromoaCluster(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCluster::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCluster::onPreModify(oaCluster* p1,oaClusterModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCluster::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaCluster_FromoaCluster(p1));
    PyTuple_SetItem(args,1,PyoaClusterModTypeEnum_FromoaClusterModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCluster::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaCluster_doc[] = 
"Class: oaObserver_oaCluster\n"
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
"    Calls: oaObserver_oaCluster(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaCluster||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaCluster\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaCluster(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaCluster||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaCluster\n"
"  Paramegers: (oaObserver_oaCluster)\n"
"    Calls: (const oaObserver_oaCluster&)\n"
"    Signature: oaObserver_oaCluster||cref-oaObserver_oaCluster,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaCluster_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaCluster",
    sizeof(PyoaObserver_oaClusterObject),
    0,
    (destructor)oaObserver_oaCluster_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaCluster_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaCluster_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaCluster_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaCluster_oaClusterModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaCluster_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaCluster_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaCluster_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaCluster\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaCluster",
           (PyObject*)(&PyoaObserver_oaCluster_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaCluster\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaClusterBoundary
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaClusterBoundary_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaClusterBoundary_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaClusterBoundaryObject* self = (PyoaObserver_oaClusterBoundaryObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaClusterBoundary(p1.Data());
            }
            else {
                pyv_oaObserver_oaClusterBoundary* p=new pyv_oaObserver_oaClusterBoundary(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaClusterBoundary(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaClusterBoundary* p=new pyv_oaObserver_oaClusterBoundary(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaClusterBoundary)
    {
        PyParamoaObserver_oaClusterBoundary p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaClusterBoundary_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaClusterBoundary(p1.Data());
            }
            else {
                pyv_oaObserver_oaClusterBoundary* p=new pyv_oaObserver_oaClusterBoundary(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaClusterBoundary, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaClusterBoundary)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaClusterBoundary_tp_dealloc(PyoaObserver_oaClusterBoundaryObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaClusterBoundary*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaClusterBoundary_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaClusterBoundary value;
    int convert_status=PyoaObserver_oaClusterBoundary_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaObserver_oaClusterBoundary::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaClusterBoundary_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaClusterBoundary v1;
    PyParamoaObserver_oaClusterBoundary v2;
    int convert_status1=PyoaObserver_oaClusterBoundary_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaClusterBoundary_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaClusterBoundary_Convert(PyObject* ob,PyParamoaObserver_oaClusterBoundary* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaClusterBoundary_Check(ob)) {
        result->SetData( (oaObserver_oaClusterBoundary*) ((PyoaObserver_oaClusterBoundaryObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaClusterBoundary Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaClusterBoundary_FromoaObserver_oaClusterBoundary(oaObserver_oaClusterBoundary* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaClusterBoundary_Type.tp_alloc(&PyoaObserver_oaClusterBoundary_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaClusterBoundaryObject* self = (PyoaObserver_oaClusterBoundaryObject*)bself;
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
pyv_oaObserver_oaClusterBoundary::pyv_oaObserver_oaClusterBoundary(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaClusterBoundary(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaClusterBoundary::pyv_oaObserver_oaClusterBoundary(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaClusterBoundary(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaClusterBoundary::pyv_oaObserver_oaClusterBoundary(const oaObserver_oaClusterBoundary& p)
 : pyob(NULL),
   oaObserver_oaClusterBoundary(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaClusterBoundary::onPostCreate(oaClusterBoundary* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaClusterBoundary::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaClusterBoundary_FromoaClusterBoundary(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaClusterBoundary::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaClusterBoundary::onPostModify(oaClusterBoundary* p1,oaBoundaryModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaClusterBoundary::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaClusterBoundary_FromoaClusterBoundary(p1));
    PyTuple_SetItem(args,1,PyoaBoundaryModTypeEnum_FromoaBoundaryModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaClusterBoundary::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaClusterBoundary::onPreDestroy(oaClusterBoundary* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaClusterBoundary::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaClusterBoundary_FromoaClusterBoundary(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaClusterBoundary::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaClusterBoundary::onPreModify(oaClusterBoundary* p1,oaBoundaryModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaClusterBoundary::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaClusterBoundary_FromoaClusterBoundary(p1));
    PyTuple_SetItem(args,1,PyoaBoundaryModTypeEnum_FromoaBoundaryModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaClusterBoundary::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaClusterBoundary_doc[] = 
"Class: oaObserver_oaClusterBoundary\n"
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
"    Calls: oaObserver_oaClusterBoundary(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaClusterBoundary||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaClusterBoundary\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaClusterBoundary(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaClusterBoundary||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaClusterBoundary\n"
"  Paramegers: (oaObserver_oaClusterBoundary)\n"
"    Calls: (const oaObserver_oaClusterBoundary&)\n"
"    Signature: oaObserver_oaClusterBoundary||cref-oaObserver_oaClusterBoundary,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaClusterBoundary_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaClusterBoundary",
    sizeof(PyoaObserver_oaClusterBoundaryObject),
    0,
    (destructor)oaObserver_oaClusterBoundary_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaClusterBoundary_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaClusterBoundary_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaClusterBoundary_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaClusterBoundary_oaBoundaryModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaClusterBoundary_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaClusterBoundary_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaClusterBoundary_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaClusterBoundary\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaClusterBoundary",
           (PyObject*)(&PyoaObserver_oaClusterBoundary_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaClusterBoundary\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaConnectDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaConnectDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaConnectDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaConnectDefObject* self = (PyoaObserver_oaConnectDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaConnectDef* p=new pyv_oaObserver_oaConnectDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaConnectDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaConnectDef* p=new pyv_oaObserver_oaConnectDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaConnectDef)
    {
        PyParamoaObserver_oaConnectDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaConnectDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaConnectDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaConnectDef* p=new pyv_oaObserver_oaConnectDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaConnectDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaConnectDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaConnectDef_tp_dealloc(PyoaObserver_oaConnectDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaConnectDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaConnectDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaConnectDef value;
    int convert_status=PyoaObserver_oaConnectDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaConnectDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaConnectDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaConnectDef v1;
    PyParamoaObserver_oaConnectDef v2;
    int convert_status1=PyoaObserver_oaConnectDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaConnectDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaConnectDef_Convert(PyObject* ob,PyParamoaObserver_oaConnectDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaConnectDef_Check(ob)) {
        result->SetData( (oaObserver_oaConnectDef*) ((PyoaObserver_oaConnectDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaConnectDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaConnectDef_FromoaObserver_oaConnectDef(oaObserver_oaConnectDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaConnectDef_Type.tp_alloc(&PyoaObserver_oaConnectDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaConnectDefObject* self = (PyoaObserver_oaConnectDefObject*)bself;
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
pyv_oaObserver_oaConnectDef::pyv_oaObserver_oaConnectDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaConnectDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaConnectDef::pyv_oaObserver_oaConnectDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaConnectDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaConnectDef::pyv_oaObserver_oaConnectDef(const oaObserver_oaConnectDef& p)
 : pyob(NULL),
   oaObserver_oaConnectDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConnectDef::onPostCreate(oaConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConnectDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaConnectDef_FromoaConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConnectDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConnectDef::onPostModify(oaConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConnectDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaConnectDef_FromoaConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConnectDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConnectDef::onPreDestroy(oaConnectDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConnectDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaConnectDef_FromoaConnectDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConnectDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConnectDef::onPreModify(oaConnectDef* p1,oaConnectDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConnectDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaConnectDef_FromoaConnectDef(p1));
    PyTuple_SetItem(args,1,PyoaConnectDefModTypeEnum_FromoaConnectDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConnectDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaConnectDef_doc[] = 
"Class: oaObserver_oaConnectDef\n"
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
"    Calls: oaObserver_oaConnectDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaConnectDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaConnectDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaConnectDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaConnectDef\n"
"  Paramegers: (oaObserver_oaConnectDef)\n"
"    Calls: (const oaObserver_oaConnectDef&)\n"
"    Signature: oaObserver_oaConnectDef||cref-oaObserver_oaConnectDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaConnectDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaConnectDef",
    sizeof(PyoaObserver_oaConnectDefObject),
    0,
    (destructor)oaObserver_oaConnectDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaConnectDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaConnectDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaConnectDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaConnectDef_oaConnectDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaConnectDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaConnectDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaConnectDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaConnectDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaConnectDef",
           (PyObject*)(&PyoaObserver_oaConnectDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaConnectDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaConstraint
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaConstraint_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaConstraint_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaConstraintObject* self = (PyoaObserver_oaConstraintObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaConstraint(p1.Data());
            }
            else {
                pyv_oaObserver_oaConstraint* p=new pyv_oaObserver_oaConstraint(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaConstraint(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaConstraint* p=new pyv_oaObserver_oaConstraint(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaConstraint)
    {
        PyParamoaObserver_oaConstraint p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaConstraint_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaConstraint(p1.Data());
            }
            else {
                pyv_oaObserver_oaConstraint* p=new pyv_oaObserver_oaConstraint(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaConstraint, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaConstraint)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaConstraint_tp_dealloc(PyoaObserver_oaConstraintObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaConstraint*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaConstraint_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaConstraint value;
    int convert_status=PyoaObserver_oaConstraint_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaConstraint::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaConstraint_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaConstraint v1;
    PyParamoaObserver_oaConstraint v2;
    int convert_status1=PyoaObserver_oaConstraint_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaConstraint_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaConstraint_Convert(PyObject* ob,PyParamoaObserver_oaConstraint* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaConstraint_Check(ob)) {
        result->SetData( (oaObserver_oaConstraint*) ((PyoaObserver_oaConstraintObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaConstraint Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaConstraint_FromoaObserver_oaConstraint(oaObserver_oaConstraint* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaConstraint_Type.tp_alloc(&PyoaObserver_oaConstraint_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaConstraintObject* self = (PyoaObserver_oaConstraintObject*)bself;
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
pyv_oaObserver_oaConstraint::pyv_oaObserver_oaConstraint(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaConstraint(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaConstraint::pyv_oaObserver_oaConstraint(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaConstraint(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaConstraint::pyv_oaObserver_oaConstraint(const oaObserver_oaConstraint& p)
 : pyob(NULL),
   oaObserver_oaConstraint(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraint::onPostCreate(oaConstraint* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraint::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaConstraint_FromoaConstraint(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraint::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraint::onPostModify(oaConstraint* p1,oaConstraintModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraint::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaConstraint_FromoaConstraint(p1));
    PyTuple_SetItem(args,1,PyoaConstraintModTypeEnum_FromoaConstraintModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraint::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraint::onPreDestroy(oaConstraint* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraint::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaConstraint_FromoaConstraint(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraint::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraint::onPreModify(oaConstraint* p1,oaConstraintModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraint::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaConstraint_FromoaConstraint(p1));
    PyTuple_SetItem(args,1,PyoaConstraintModTypeEnum_FromoaConstraintModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraint::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaConstraint_doc[] = 
"Class: oaObserver_oaConstraint\n"
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
"    Calls: oaObserver_oaConstraint(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaConstraint||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaConstraint\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaConstraint(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaConstraint||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaConstraint\n"
"  Paramegers: (oaObserver_oaConstraint)\n"
"    Calls: (const oaObserver_oaConstraint&)\n"
"    Signature: oaObserver_oaConstraint||cref-oaObserver_oaConstraint,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaConstraint_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaConstraint",
    sizeof(PyoaObserver_oaConstraintObject),
    0,
    (destructor)oaObserver_oaConstraint_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaConstraint_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaConstraint_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaConstraint_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaConstraint_oaConstraintModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaConstraint_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaConstraint_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaConstraint_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaConstraint\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaConstraint",
           (PyObject*)(&PyoaObserver_oaConstraint_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaConstraint\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaConstraintDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaConstraintDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaConstraintDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaConstraintDefObject* self = (PyoaObserver_oaConstraintDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaConstraintDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaConstraintDef* p=new pyv_oaObserver_oaConstraintDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaConstraintDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaConstraintDef* p=new pyv_oaObserver_oaConstraintDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaConstraintDef, Choices are:\n"
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
oaObserver_oaConstraintDef_tp_dealloc(PyoaObserver_oaConstraintDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaConstraintDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaConstraintDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaConstraintDef value;
    int convert_status=PyoaObserver_oaConstraintDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaConstraintDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaConstraintDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaConstraintDef v1;
    PyParamoaObserver_oaConstraintDef v2;
    int convert_status1=PyoaObserver_oaConstraintDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaConstraintDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaConstraintDef_Convert(PyObject* ob,PyParamoaObserver_oaConstraintDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaConstraintDef_Check(ob)) {
        result->SetData( (oaObserver_oaConstraintDef*) ((PyoaObserver_oaConstraintDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaConstraintDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaConstraintDef_FromoaObserver_oaConstraintDef(oaObserver_oaConstraintDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaConstraintDef_Type.tp_alloc(&PyoaObserver_oaConstraintDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaConstraintDefObject* self = (PyoaObserver_oaConstraintDefObject*)bself;
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
pyv_oaObserver_oaConstraintDef::pyv_oaObserver_oaConstraintDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaConstraintDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaConstraintDef::pyv_oaObserver_oaConstraintDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaConstraintDef(p1,p2)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintDef::onConflict(const oaString& p1,oaType p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onConflict");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintDef::onConflict was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaString_FromoaString(p1));
    PyTuple_SetItem(args,1,PyoaType_FromoaType(&p2,1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintDef::onConflict had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintDef::onPostCreate(oaConstraintDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaConstraintDef_FromoaConstraintDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintDef::onPreDestroy(oaConstraintDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaConstraintDef_FromoaConstraintDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaConstraintDef_onConflict_doc[] = 
"Class: oaObserver_oaConstraintDef, Function: onConflict\n"
"  Paramegers: (oaString,oaType)\n"
"    Calls: virtual void onConflict(const oaString& name,oaType defType)\n"
"    Signature: onConflict|void-void|cref-oaString,simple-oaType,\n"
"    This function is called if an on-disk oaConstraintDef conflicts with an existing oaConstraintDef definition. Note that that all data associated with the conflicting definition, including the definition itself, will be destroyed following this notification.\n"
"    name\n"
"    name of the conflicting oaConstraintDef\n"
"    defType\n"
"    type of the conflicting oaConstraintDef\n"
;

static PyObject*
oaObserver_oaConstraintDef_onConflict(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaConstraintDef data;
    int convert_status=PyoaObserver_oaConstraintDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaConstraintDefObject* self=(PyoaObserver_oaConstraintDefObject*)ob;

    PyParamoaString p1;
    PyParamoaType p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaString_Convert,&p1,
          &PyoaType_Convert,&p2)) {
        data.DataCall()->oaObserver_oaConstraintDef::onConflict(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaConstraintDef_onPostCreate_doc[] = 
"Class: oaObserver_oaConstraintDef, Function: onPostCreate\n"
"  Paramegers: (oaConstraintDef)\n"
"    Calls: virtual void onPostCreate(oaConstraintDef* def)\n"
"    Signature: onPostCreate|void-void|ptr-oaConstraintDef,\n"
"    This function is called after an oaConstraintDef is created. The application's derived observer class should implement this function to receive notification after an oaConstraintDef is created.\n"
"    def\n"
"    pointer to the created oaConstraintDef object\n"
;

static PyObject*
oaObserver_oaConstraintDef_onPostCreate(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaConstraintDef data;
    int convert_status=PyoaObserver_oaConstraintDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaConstraintDefObject* self=(PyoaObserver_oaConstraintDefObject*)ob;

    PyParamoaConstraintDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaConstraintDef::onPostCreate(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaConstraintDef_onPreDestroy_doc[] = 
"Class: oaObserver_oaConstraintDef, Function: onPreDestroy\n"
"  Paramegers: (oaConstraintDef)\n"
"    Calls: virtual void onPreDestroy(oaConstraintDef* def)\n"
"    Signature: onPreDestroy|void-void|ptr-oaConstraintDef,\n"
"    This function is called before an oaConstraintDef is destroyed. The application's derived observer class should implement this function to receive notification when an oaConstraintDef is about to be destroyed.\n"
"    def\n"
"    pointer to the oaConstraintDef object about to be destroyed\n"
;

static PyObject*
oaObserver_oaConstraintDef_onPreDestroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaConstraintDef data;
    int convert_status=PyoaObserver_oaConstraintDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaConstraintDefObject* self=(PyoaObserver_oaConstraintDefObject*)ob;

    PyParamoaConstraintDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaConstraintDef::onPreDestroy(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaObserver_oaConstraintDef_assign_doc[] = 
"Class: oaObserver_oaConstraintDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaObserver_oaConstraintDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaObserver_oaConstraintDef data;
  int convert_status=PyoaObserver_oaConstraintDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaObserver_oaConstraintDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaObserver_oaConstraintDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaObserver_oaConstraintDef_methodlist[] = {
    {"onConflict",(PyCFunction)oaObserver_oaConstraintDef_onConflict,METH_VARARGS,oaObserver_oaConstraintDef_onConflict_doc},
    {"onPostCreate",(PyCFunction)oaObserver_oaConstraintDef_onPostCreate,METH_VARARGS,oaObserver_oaConstraintDef_onPostCreate_doc},
    {"onPreDestroy",(PyCFunction)oaObserver_oaConstraintDef_onPreDestroy,METH_VARARGS,oaObserver_oaConstraintDef_onPreDestroy_doc},
    {"assign",(PyCFunction)oaObserver_oaConstraintDef_tp_assign,METH_VARARGS,oaObserver_oaConstraintDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaConstraintDef_doc[] = 
"Class: oaObserver_oaConstraintDef\n"
"  This base template class can be used to derive observers for oaConstraintDef objects. It supports It supports postCreate, preDestroy, and onConflict event notifications.\n"
"  See oaObserver for information on using OpenAccess observer template classes to derive and instantiate observers in an application.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaConstraintDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaConstraintDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaConstraintDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaConstraintDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaConstraintDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaConstraintDef\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaConstraintDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaConstraintDef",
    sizeof(PyoaObserver_oaConstraintDefObject),
    0,
    (destructor)oaObserver_oaConstraintDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaConstraintDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaConstraintDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaConstraintDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaObserver_oaConstraintDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseObserver_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaConstraintDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaConstraintDef_static_hasObservers_doc[] = 
"Class: oaObserver_oaConstraintDef, Function: hasObservers\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasObservers()\n"
"    Signature: hasObservers|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if any observers for this type are active.\n"
;

static PyObject*
oaObserver_oaConstraintDef_static_hasObservers(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (oaObserver_oaConstraintDef::hasObservers());
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
static char oaObserver_oaConstraintDef_static_notifyOnConflictObservers_doc[] = 
"Class: oaObserver_oaConstraintDef, Function: notifyOnConflictObservers\n"
"  Paramegers: (oaString,oaType)\n"
"    Calls: void notifyOnConflictObservers(const oaString& name,oaType defType)\n"
"    Signature: notifyOnConflictObservers|void-void|cref-oaString,simple-oaType,\n"
"    Function notifyOnConflictObservers\n"
;

static PyObject*
oaObserver_oaConstraintDef_static_notifyOnConflictObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    PyParamoaType p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaString_Convert,&p1,
          &PyoaType_Convert,&p2)) {
        oaObserver_oaConstraintDef::notifyOnConflictObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaConstraintDef_static_notifyPostCreateObservers_doc[] = 
"Class: oaObserver_oaConstraintDef, Function: notifyPostCreateObservers\n"
"  Paramegers: (oaConstraintDef)\n"
"    Calls: void notifyPostCreateObservers(oaConstraintDef* def)\n"
"    Signature: notifyPostCreateObservers|void-void|ptr-oaConstraintDef,\n"
"    Function notifyPostCreateObservers\n"
;

static PyObject*
oaObserver_oaConstraintDef_static_notifyPostCreateObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaConstraintDef::notifyPostCreateObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaConstraintDef_static_notifyPreDestroyObservers_doc[] = 
"Class: oaObserver_oaConstraintDef, Function: notifyPreDestroyObservers\n"
"  Paramegers: (oaConstraintDef)\n"
"    Calls: void notifyPreDestroyObservers(oaConstraintDef* def)\n"
"    Signature: notifyPreDestroyObservers|void-void|ptr-oaConstraintDef,\n"
"    Function notifyPreDestroyObservers\n"
;

static PyObject*
oaObserver_oaConstraintDef_static_notifyPreDestroyObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaConstraintDef::notifyPreDestroyObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaObserver_oaConstraintDef_staticmethodlist[] = {
    {"static_hasObservers",(PyCFunction)oaObserver_oaConstraintDef_static_hasObservers,METH_VARARGS,oaObserver_oaConstraintDef_static_hasObservers_doc},
    {"static_notifyOnConflictObservers",(PyCFunction)oaObserver_oaConstraintDef_static_notifyOnConflictObservers,METH_VARARGS,oaObserver_oaConstraintDef_static_notifyOnConflictObservers_doc},
    {"static_notifyPostCreateObservers",(PyCFunction)oaObserver_oaConstraintDef_static_notifyPostCreateObservers,METH_VARARGS,oaObserver_oaConstraintDef_static_notifyPostCreateObservers_doc},
    {"static_notifyPreDestroyObservers",(PyCFunction)oaObserver_oaConstraintDef_static_notifyPreDestroyObservers,METH_VARARGS,oaObserver_oaConstraintDef_static_notifyPreDestroyObservers_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaConstraintDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaConstraintDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaConstraintDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaConstraintDef",
           (PyObject*)(&PyoaObserver_oaConstraintDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaConstraintDef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaObserver_oaConstraintDef_Type.tp_dict;
    for(method=oaObserver_oaConstraintDef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaObserver_oaConstraintGroup
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaConstraintGroup_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaConstraintGroup_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaConstraintGroupObject* self = (PyoaObserver_oaConstraintGroupObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaConstraintGroup(p1.Data());
            }
            else {
                pyv_oaObserver_oaConstraintGroup* p=new pyv_oaObserver_oaConstraintGroup(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaConstraintGroup(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaConstraintGroup* p=new pyv_oaObserver_oaConstraintGroup(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaConstraintGroup)
    {
        PyParamoaObserver_oaConstraintGroup p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaConstraintGroup_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaConstraintGroup(p1.Data());
            }
            else {
                pyv_oaObserver_oaConstraintGroup* p=new pyv_oaObserver_oaConstraintGroup(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaConstraintGroup, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaConstraintGroup)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaConstraintGroup_tp_dealloc(PyoaObserver_oaConstraintGroupObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaConstraintGroup*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaConstraintGroup_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaConstraintGroup value;
    int convert_status=PyoaObserver_oaConstraintGroup_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaObserver_oaConstraintGroup::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaConstraintGroup_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaConstraintGroup v1;
    PyParamoaObserver_oaConstraintGroup v2;
    int convert_status1=PyoaObserver_oaConstraintGroup_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaConstraintGroup_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaConstraintGroup_Convert(PyObject* ob,PyParamoaObserver_oaConstraintGroup* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaConstraintGroup_Check(ob)) {
        result->SetData( (oaObserver_oaConstraintGroup*) ((PyoaObserver_oaConstraintGroupObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaConstraintGroup Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaConstraintGroup_FromoaObserver_oaConstraintGroup(oaObserver_oaConstraintGroup* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaConstraintGroup_Type.tp_alloc(&PyoaObserver_oaConstraintGroup_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaConstraintGroupObject* self = (PyoaObserver_oaConstraintGroupObject*)bself;
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
pyv_oaObserver_oaConstraintGroup::pyv_oaObserver_oaConstraintGroup(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaConstraintGroup(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaConstraintGroup::pyv_oaObserver_oaConstraintGroup(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaConstraintGroup(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaConstraintGroup::pyv_oaObserver_oaConstraintGroup(const oaObserver_oaConstraintGroup& p)
 : pyob(NULL),
   oaObserver_oaConstraintGroup(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintGroup::onPostCreate(oaConstraintGroup* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintGroup::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaConstraintGroup_FromoaConstraintGroup(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintGroup::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintGroup::onPostModify(oaConstraintGroup* p1,oaConstraintGroupModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintGroup::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaConstraintGroup_FromoaConstraintGroup(p1));
    PyTuple_SetItem(args,1,PyoaConstraintGroupModTypeEnum_FromoaConstraintGroupModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintGroup::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintGroup::onPreDestroy(oaConstraintGroup* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintGroup::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaConstraintGroup_FromoaConstraintGroup(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintGroup::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintGroup::onPreModify(oaConstraintGroup* p1,oaConstraintGroupModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintGroup::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaConstraintGroup_FromoaConstraintGroup(p1));
    PyTuple_SetItem(args,1,PyoaConstraintGroupModTypeEnum_FromoaConstraintGroupModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintGroup::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaConstraintGroup_doc[] = 
"Class: oaObserver_oaConstraintGroup\n"
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
"    Calls: oaObserver_oaConstraintGroup(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaConstraintGroup||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaConstraintGroup\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaConstraintGroup(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaConstraintGroup||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaConstraintGroup\n"
"  Paramegers: (oaObserver_oaConstraintGroup)\n"
"    Calls: (const oaObserver_oaConstraintGroup&)\n"
"    Signature: oaObserver_oaConstraintGroup||cref-oaObserver_oaConstraintGroup,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaConstraintGroup_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaConstraintGroup",
    sizeof(PyoaObserver_oaConstraintGroupObject),
    0,
    (destructor)oaObserver_oaConstraintGroup_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaConstraintGroup_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaConstraintGroup_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaConstraintGroup_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaConstraintGroup_oaConstraintGroupModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaConstraintGroup_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaConstraintGroup_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaConstraintGroup_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaConstraintGroup\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaConstraintGroup",
           (PyObject*)(&PyoaObserver_oaConstraintGroup_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaConstraintGroup\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaConstraintGroupMem
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaConstraintGroupMem_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaConstraintGroupMem_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaConstraintGroupMemObject* self = (PyoaObserver_oaConstraintGroupMemObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaConstraintGroupMem(p1.Data());
            }
            else {
                pyv_oaObserver_oaConstraintGroupMem* p=new pyv_oaObserver_oaConstraintGroupMem(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaConstraintGroupMem(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaConstraintGroupMem* p=new pyv_oaObserver_oaConstraintGroupMem(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaConstraintGroupMem)
    {
        PyParamoaObserver_oaConstraintGroupMem p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaConstraintGroupMem_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaConstraintGroupMem(p1.Data());
            }
            else {
                pyv_oaObserver_oaConstraintGroupMem* p=new pyv_oaObserver_oaConstraintGroupMem(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaConstraintGroupMem, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaConstraintGroupMem)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaConstraintGroupMem_tp_dealloc(PyoaObserver_oaConstraintGroupMemObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaConstraintGroupMem*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaConstraintGroupMem_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaConstraintGroupMem value;
    int convert_status=PyoaObserver_oaConstraintGroupMem_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[53];
    sprintf(buffer,"<oaObserver_oaConstraintGroupMem::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaConstraintGroupMem_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaConstraintGroupMem v1;
    PyParamoaObserver_oaConstraintGroupMem v2;
    int convert_status1=PyoaObserver_oaConstraintGroupMem_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaConstraintGroupMem_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaConstraintGroupMem_Convert(PyObject* ob,PyParamoaObserver_oaConstraintGroupMem* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaConstraintGroupMem_Check(ob)) {
        result->SetData( (oaObserver_oaConstraintGroupMem*) ((PyoaObserver_oaConstraintGroupMemObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaConstraintGroupMem Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaConstraintGroupMem_FromoaObserver_oaConstraintGroupMem(oaObserver_oaConstraintGroupMem* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaConstraintGroupMem_Type.tp_alloc(&PyoaObserver_oaConstraintGroupMem_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaConstraintGroupMemObject* self = (PyoaObserver_oaConstraintGroupMemObject*)bself;
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
pyv_oaObserver_oaConstraintGroupMem::pyv_oaObserver_oaConstraintGroupMem(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaConstraintGroupMem(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaConstraintGroupMem::pyv_oaObserver_oaConstraintGroupMem(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaConstraintGroupMem(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaConstraintGroupMem::pyv_oaObserver_oaConstraintGroupMem(const oaObserver_oaConstraintGroupMem& p)
 : pyob(NULL),
   oaObserver_oaConstraintGroupMem(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintGroupMem::onPostCreate(oaConstraintGroupMem* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintGroupMem::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaConstraintGroupMem_FromoaConstraintGroupMem(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintGroupMem::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintGroupMem::onPostModify(oaConstraintGroupMem* p1,oaConstraintGroupMemModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintGroupMem::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaConstraintGroupMem_FromoaConstraintGroupMem(p1));
    PyTuple_SetItem(args,1,PyoaConstraintGroupMemModTypeEnum_FromoaConstraintGroupMemModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintGroupMem::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintGroupMem::onPreDestroy(oaConstraintGroupMem* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintGroupMem::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaConstraintGroupMem_FromoaConstraintGroupMem(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintGroupMem::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintGroupMem::onPreModify(oaConstraintGroupMem* p1,oaConstraintGroupMemModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintGroupMem::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaConstraintGroupMem_FromoaConstraintGroupMem(p1));
    PyTuple_SetItem(args,1,PyoaConstraintGroupMemModTypeEnum_FromoaConstraintGroupMemModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintGroupMem::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaConstraintGroupMem_doc[] = 
"Class: oaObserver_oaConstraintGroupMem\n"
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
"    Calls: oaObserver_oaConstraintGroupMem(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaConstraintGroupMem||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaConstraintGroupMem\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaConstraintGroupMem(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaConstraintGroupMem||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaConstraintGroupMem\n"
"  Paramegers: (oaObserver_oaConstraintGroupMem)\n"
"    Calls: (const oaObserver_oaConstraintGroupMem&)\n"
"    Signature: oaObserver_oaConstraintGroupMem||cref-oaObserver_oaConstraintGroupMem,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaConstraintGroupMem_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaConstraintGroupMem",
    sizeof(PyoaObserver_oaConstraintGroupMemObject),
    0,
    (destructor)oaObserver_oaConstraintGroupMem_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaConstraintGroupMem_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaConstraintGroupMem_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaConstraintGroupMem_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaConstraintGroupMem_oaConstraintGroupMemModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaConstraintGroupMem_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaConstraintGroupMem_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaConstraintGroupMem_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaConstraintGroupMem\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaConstraintGroupMem",
           (PyObject*)(&PyoaObserver_oaConstraintGroupMem_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaConstraintGroupMem\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaConstraintParam
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaConstraintParam_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaConstraintParam_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaConstraintParamObject* self = (PyoaObserver_oaConstraintParamObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaConstraintParam(p1.Data());
            }
            else {
                pyv_oaObserver_oaConstraintParam* p=new pyv_oaObserver_oaConstraintParam(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaConstraintParam(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaConstraintParam* p=new pyv_oaObserver_oaConstraintParam(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaConstraintParam)
    {
        PyParamoaObserver_oaConstraintParam p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaConstraintParam_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaConstraintParam(p1.Data());
            }
            else {
                pyv_oaObserver_oaConstraintParam* p=new pyv_oaObserver_oaConstraintParam(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaConstraintParam, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaConstraintParam)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaConstraintParam_tp_dealloc(PyoaObserver_oaConstraintParamObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaConstraintParam*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaConstraintParam_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaConstraintParam value;
    int convert_status=PyoaObserver_oaConstraintParam_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaObserver_oaConstraintParam::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaConstraintParam_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaConstraintParam v1;
    PyParamoaObserver_oaConstraintParam v2;
    int convert_status1=PyoaObserver_oaConstraintParam_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaConstraintParam_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaConstraintParam_Convert(PyObject* ob,PyParamoaObserver_oaConstraintParam* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaConstraintParam_Check(ob)) {
        result->SetData( (oaObserver_oaConstraintParam*) ((PyoaObserver_oaConstraintParamObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaConstraintParam Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaConstraintParam_FromoaObserver_oaConstraintParam(oaObserver_oaConstraintParam* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaConstraintParam_Type.tp_alloc(&PyoaObserver_oaConstraintParam_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaConstraintParamObject* self = (PyoaObserver_oaConstraintParamObject*)bself;
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
pyv_oaObserver_oaConstraintParam::pyv_oaObserver_oaConstraintParam(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaConstraintParam(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaConstraintParam::pyv_oaObserver_oaConstraintParam(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaConstraintParam(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaConstraintParam::pyv_oaObserver_oaConstraintParam(const oaObserver_oaConstraintParam& p)
 : pyob(NULL),
   oaObserver_oaConstraintParam(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintParam::onPostCreate(oaConstraintParam* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintParam::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaConstraintParam_FromoaConstraintParam(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintParam::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintParam::onPostModify(oaConstraintParam* p1,oaConstraintParamModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintParam::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaConstraintParam_FromoaConstraintParam(p1));
    PyTuple_SetItem(args,1,PyoaConstraintParamModTypeEnum_FromoaConstraintParamModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintParam::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintParam::onPreDestroy(oaConstraintParam* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintParam::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaConstraintParam_FromoaConstraintParam(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintParam::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintParam::onPreModify(oaConstraintParam* p1,oaConstraintParamModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintParam::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaConstraintParam_FromoaConstraintParam(p1));
    PyTuple_SetItem(args,1,PyoaConstraintParamModTypeEnum_FromoaConstraintParamModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintParam::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaConstraintParam_doc[] = 
"Class: oaObserver_oaConstraintParam\n"
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
"    Calls: oaObserver_oaConstraintParam(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaConstraintParam||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaConstraintParam\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaConstraintParam(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaConstraintParam||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaConstraintParam\n"
"  Paramegers: (oaObserver_oaConstraintParam)\n"
"    Calls: (const oaObserver_oaConstraintParam&)\n"
"    Signature: oaObserver_oaConstraintParam||cref-oaObserver_oaConstraintParam,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaConstraintParam_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaConstraintParam",
    sizeof(PyoaObserver_oaConstraintParamObject),
    0,
    (destructor)oaObserver_oaConstraintParam_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaConstraintParam_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaConstraintParam_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaConstraintParam_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaConstraintParam_oaConstraintParamModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaConstraintParam_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaConstraintParam_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaConstraintParam_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaConstraintParam\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaConstraintParam",
           (PyObject*)(&PyoaObserver_oaConstraintParam_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaConstraintParam\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaConstraintParamDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaConstraintParamDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaConstraintParamDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaConstraintParamDefObject* self = (PyoaObserver_oaConstraintParamDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaConstraintParamDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaConstraintParamDef* p=new pyv_oaObserver_oaConstraintParamDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaConstraintParamDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaConstraintParamDef* p=new pyv_oaObserver_oaConstraintParamDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaConstraintParamDef, Choices are:\n"
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
oaObserver_oaConstraintParamDef_tp_dealloc(PyoaObserver_oaConstraintParamDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaConstraintParamDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaConstraintParamDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaConstraintParamDef value;
    int convert_status=PyoaObserver_oaConstraintParamDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[53];
    sprintf(buffer,"<oaObserver_oaConstraintParamDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaConstraintParamDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaConstraintParamDef v1;
    PyParamoaObserver_oaConstraintParamDef v2;
    int convert_status1=PyoaObserver_oaConstraintParamDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaConstraintParamDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaConstraintParamDef_Convert(PyObject* ob,PyParamoaObserver_oaConstraintParamDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaConstraintParamDef_Check(ob)) {
        result->SetData( (oaObserver_oaConstraintParamDef*) ((PyoaObserver_oaConstraintParamDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaConstraintParamDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaConstraintParamDef_FromoaObserver_oaConstraintParamDef(oaObserver_oaConstraintParamDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaConstraintParamDef_Type.tp_alloc(&PyoaObserver_oaConstraintParamDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaConstraintParamDefObject* self = (PyoaObserver_oaConstraintParamDefObject*)bself;
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
pyv_oaObserver_oaConstraintParamDef::pyv_oaObserver_oaConstraintParamDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaConstraintParamDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaConstraintParamDef::pyv_oaObserver_oaConstraintParamDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaConstraintParamDef(p1,p2)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintParamDef::onConflict(const oaString& p1,oaType p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onConflict");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintParamDef::onConflict was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaString_FromoaString(p1));
    PyTuple_SetItem(args,1,PyoaType_FromoaType(&p2,1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintParamDef::onConflict had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintParamDef::onPostCreate(oaConstraintParamDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintParamDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaConstraintParamDef_FromoaConstraintParamDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintParamDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaConstraintParamDef::onPreDestroy(oaConstraintParamDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintParamDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaConstraintParamDef_FromoaConstraintParamDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaConstraintParamDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaConstraintParamDef_onConflict_doc[] = 
"Class: oaObserver_oaConstraintParamDef, Function: onConflict\n"
"  Paramegers: (oaString,oaType)\n"
"    Calls: virtual void onConflict(const oaString& name,oaType valueType)\n"
"    Signature: onConflict|void-void|cref-oaString,simple-oaType,\n"
"    This function is called if an on-disk oaConstraintParamDef conflicts with an existing oaConstraintParamDef definition. Note that that all data associated with the conflicting definition, including the definition itself, will be destroyed following this notification.\n"
"    name\n"
"    name of the conflicting oaConstraintParamDef\n"
"    valueType\n"
"    type of the conflicting oaConstraintParamDef\n"
;

static PyObject*
oaObserver_oaConstraintParamDef_onConflict(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaConstraintParamDef data;
    int convert_status=PyoaObserver_oaConstraintParamDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaConstraintParamDefObject* self=(PyoaObserver_oaConstraintParamDefObject*)ob;

    PyParamoaString p1;
    PyParamoaType p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaString_Convert,&p1,
          &PyoaType_Convert,&p2)) {
        data.DataCall()->oaObserver_oaConstraintParamDef::onConflict(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaConstraintParamDef_onPostCreate_doc[] = 
"Class: oaObserver_oaConstraintParamDef, Function: onPostCreate\n"
"  Paramegers: (oaConstraintParamDef)\n"
"    Calls: virtual void onPostCreate(oaConstraintParamDef* def)\n"
"    Signature: onPostCreate|void-void|ptr-oaConstraintParamDef,\n"
"    This function is called after an oaConstraintParamDef is created. The application's derived observer class should implement this function to receive notification after an oaConstraintParamDef is created.\n"
"    def\n"
"    pointer to the created oaConstraintParamDef object\n"
;

static PyObject*
oaObserver_oaConstraintParamDef_onPostCreate(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaConstraintParamDef data;
    int convert_status=PyoaObserver_oaConstraintParamDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaConstraintParamDefObject* self=(PyoaObserver_oaConstraintParamDefObject*)ob;

    PyParamoaConstraintParamDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintParamDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaConstraintParamDef::onPostCreate(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaConstraintParamDef_onPreDestroy_doc[] = 
"Class: oaObserver_oaConstraintParamDef, Function: onPreDestroy\n"
"  Paramegers: (oaConstraintParamDef)\n"
"    Calls: virtual void onPreDestroy(oaConstraintParamDef* def)\n"
"    Signature: onPreDestroy|void-void|ptr-oaConstraintParamDef,\n"
"    This function is called before an oaConstraintParamDef is destroyed. The application's derived observer class should implement this function to receive notification when an oaConstraintParamDef is about to be destroyed.\n"
"    def\n"
"    pointer to the oaConstraintParamDef about to be destroyed\n"
;

static PyObject*
oaObserver_oaConstraintParamDef_onPreDestroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaConstraintParamDef data;
    int convert_status=PyoaObserver_oaConstraintParamDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaConstraintParamDefObject* self=(PyoaObserver_oaConstraintParamDefObject*)ob;

    PyParamoaConstraintParamDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintParamDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaConstraintParamDef::onPreDestroy(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaObserver_oaConstraintParamDef_assign_doc[] = 
"Class: oaObserver_oaConstraintParamDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaObserver_oaConstraintParamDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaObserver_oaConstraintParamDef data;
  int convert_status=PyoaObserver_oaConstraintParamDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaObserver_oaConstraintParamDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaObserver_oaConstraintParamDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaObserver_oaConstraintParamDef_methodlist[] = {
    {"onConflict",(PyCFunction)oaObserver_oaConstraintParamDef_onConflict,METH_VARARGS,oaObserver_oaConstraintParamDef_onConflict_doc},
    {"onPostCreate",(PyCFunction)oaObserver_oaConstraintParamDef_onPostCreate,METH_VARARGS,oaObserver_oaConstraintParamDef_onPostCreate_doc},
    {"onPreDestroy",(PyCFunction)oaObserver_oaConstraintParamDef_onPreDestroy,METH_VARARGS,oaObserver_oaConstraintParamDef_onPreDestroy_doc},
    {"assign",(PyCFunction)oaObserver_oaConstraintParamDef_tp_assign,METH_VARARGS,oaObserver_oaConstraintParamDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaConstraintParamDef_doc[] = 
"Class: oaObserver_oaConstraintParamDef\n"
"  This base template class can be used to derive observers for oaConstraintParamDef objects. It supports preDestroy, postCreate and onConflict event notifications.\n"
"  See oaObserver for information on using OpenAccess observer template classes to derive and instantiate observers in an application.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaConstraintParamDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaConstraintParamDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaConstraintParamDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaConstraintParamDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaConstraintParamDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaConstraintParamDef\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaConstraintParamDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaConstraintParamDef",
    sizeof(PyoaObserver_oaConstraintParamDefObject),
    0,
    (destructor)oaObserver_oaConstraintParamDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaConstraintParamDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaConstraintParamDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaConstraintParamDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaObserver_oaConstraintParamDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseObserver_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaConstraintParamDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaConstraintParamDef_static_hasObservers_doc[] = 
"Class: oaObserver_oaConstraintParamDef, Function: hasObservers\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasObservers()\n"
"    Signature: hasObservers|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if any observers for this type are active.\n"
;

static PyObject*
oaObserver_oaConstraintParamDef_static_hasObservers(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (oaObserver_oaConstraintParamDef::hasObservers());
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
static char oaObserver_oaConstraintParamDef_static_notifyOnConflictObservers_doc[] = 
"Class: oaObserver_oaConstraintParamDef, Function: notifyOnConflictObservers\n"
"  Paramegers: (oaString,oaType)\n"
"    Calls: void notifyOnConflictObservers(const oaString& name,oaType valueType)\n"
"    Signature: notifyOnConflictObservers|void-void|cref-oaString,simple-oaType,\n"
"    Function notifyOnConflictObservers\n"
;

static PyObject*
oaObserver_oaConstraintParamDef_static_notifyOnConflictObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    PyParamoaType p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaString_Convert,&p1,
          &PyoaType_Convert,&p2)) {
        oaObserver_oaConstraintParamDef::notifyOnConflictObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaConstraintParamDef_static_notifyPostCreateObservers_doc[] = 
"Class: oaObserver_oaConstraintParamDef, Function: notifyPostCreateObservers\n"
"  Paramegers: (oaConstraintParamDef)\n"
"    Calls: void notifyPostCreateObservers(oaConstraintParamDef* def)\n"
"    Signature: notifyPostCreateObservers|void-void|ptr-oaConstraintParamDef,\n"
"    Function notifyPostCreateObservers\n"
;

static PyObject*
oaObserver_oaConstraintParamDef_static_notifyPostCreateObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParamDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintParamDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaConstraintParamDef::notifyPostCreateObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaConstraintParamDef_static_notifyPreDestroyObservers_doc[] = 
"Class: oaObserver_oaConstraintParamDef, Function: notifyPreDestroyObservers\n"
"  Paramegers: (oaConstraintParamDef)\n"
"    Calls: void notifyPreDestroyObservers(oaConstraintParamDef* def)\n"
"    Signature: notifyPreDestroyObservers|void-void|ptr-oaConstraintParamDef,\n"
"    Function notifyPreDestroyObservers\n"
;

static PyObject*
oaObserver_oaConstraintParamDef_static_notifyPreDestroyObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaConstraintParamDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaConstraintParamDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaConstraintParamDef::notifyPreDestroyObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaObserver_oaConstraintParamDef_staticmethodlist[] = {
    {"static_hasObservers",(PyCFunction)oaObserver_oaConstraintParamDef_static_hasObservers,METH_VARARGS,oaObserver_oaConstraintParamDef_static_hasObservers_doc},
    {"static_notifyOnConflictObservers",(PyCFunction)oaObserver_oaConstraintParamDef_static_notifyOnConflictObservers,METH_VARARGS,oaObserver_oaConstraintParamDef_static_notifyOnConflictObservers_doc},
    {"static_notifyPostCreateObservers",(PyCFunction)oaObserver_oaConstraintParamDef_static_notifyPostCreateObservers,METH_VARARGS,oaObserver_oaConstraintParamDef_static_notifyPostCreateObservers_doc},
    {"static_notifyPreDestroyObservers",(PyCFunction)oaObserver_oaConstraintParamDef_static_notifyPreDestroyObservers,METH_VARARGS,oaObserver_oaConstraintParamDef_static_notifyPreDestroyObservers_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaConstraintParamDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaConstraintParamDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaConstraintParamDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaConstraintParamDef",
           (PyObject*)(&PyoaObserver_oaConstraintParamDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaConstraintParamDef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaObserver_oaConstraintParamDef_Type.tp_dict;
    for(method=oaObserver_oaConstraintParamDef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaObserver_oaCouplingCap
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaCouplingCap_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaCouplingCap_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaCouplingCapObject* self = (PyoaObserver_oaCouplingCapObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaCouplingCap(p1.Data());
            }
            else {
                pyv_oaObserver_oaCouplingCap* p=new pyv_oaObserver_oaCouplingCap(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaCouplingCap(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaCouplingCap* p=new pyv_oaObserver_oaCouplingCap(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaCouplingCap)
    {
        PyParamoaObserver_oaCouplingCap p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaCouplingCap_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaCouplingCap(p1.Data());
            }
            else {
                pyv_oaObserver_oaCouplingCap* p=new pyv_oaObserver_oaCouplingCap(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaCouplingCap, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaCouplingCap)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaCouplingCap_tp_dealloc(PyoaObserver_oaCouplingCapObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaCouplingCap*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaCouplingCap_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaCouplingCap value;
    int convert_status=PyoaObserver_oaCouplingCap_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaObserver_oaCouplingCap::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaCouplingCap_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaCouplingCap v1;
    PyParamoaObserver_oaCouplingCap v2;
    int convert_status1=PyoaObserver_oaCouplingCap_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaCouplingCap_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaCouplingCap_Convert(PyObject* ob,PyParamoaObserver_oaCouplingCap* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaCouplingCap_Check(ob)) {
        result->SetData( (oaObserver_oaCouplingCap*) ((PyoaObserver_oaCouplingCapObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaCouplingCap Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaCouplingCap_FromoaObserver_oaCouplingCap(oaObserver_oaCouplingCap* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaCouplingCap_Type.tp_alloc(&PyoaObserver_oaCouplingCap_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaCouplingCapObject* self = (PyoaObserver_oaCouplingCapObject*)bself;
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
pyv_oaObserver_oaCouplingCap::pyv_oaObserver_oaCouplingCap(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaCouplingCap(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaCouplingCap::pyv_oaObserver_oaCouplingCap(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaCouplingCap(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaCouplingCap::pyv_oaObserver_oaCouplingCap(const oaObserver_oaCouplingCap& p)
 : pyob(NULL),
   oaObserver_oaCouplingCap(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCouplingCap::onPostCreate(oaCouplingCap* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCouplingCap::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaCouplingCap_FromoaCouplingCap(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCouplingCap::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCouplingCap::onPostModify(oaCouplingCap* p1,oaDeviceModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCouplingCap::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaCouplingCap_FromoaCouplingCap(p1));
    PyTuple_SetItem(args,1,PyoaDeviceModTypeEnum_FromoaDeviceModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCouplingCap::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCouplingCap::onPreDestroy(oaCouplingCap* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCouplingCap::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaCouplingCap_FromoaCouplingCap(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCouplingCap::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCouplingCap::onPreModify(oaCouplingCap* p1,oaDeviceModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCouplingCap::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaCouplingCap_FromoaCouplingCap(p1));
    PyTuple_SetItem(args,1,PyoaDeviceModTypeEnum_FromoaDeviceModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCouplingCap::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaCouplingCap_doc[] = 
"Class: oaObserver_oaCouplingCap\n"
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
"    Calls: oaObserver_oaCouplingCap(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaCouplingCap||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaCouplingCap\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaCouplingCap(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaCouplingCap||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaCouplingCap\n"
"  Paramegers: (oaObserver_oaCouplingCap)\n"
"    Calls: (const oaObserver_oaCouplingCap&)\n"
"    Signature: oaObserver_oaCouplingCap||cref-oaObserver_oaCouplingCap,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaCouplingCap_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaCouplingCap",
    sizeof(PyoaObserver_oaCouplingCapObject),
    0,
    (destructor)oaObserver_oaCouplingCap_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaCouplingCap_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaCouplingCap_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaCouplingCap_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaCouplingCap_oaDeviceModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaCouplingCap_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaCouplingCap_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaCouplingCap_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaCouplingCap\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaCouplingCap",
           (PyObject*)(&PyoaObserver_oaCouplingCap_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaCouplingCap\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaCustomVia
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaCustomVia_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaCustomVia_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaCustomViaObject* self = (PyoaObserver_oaCustomViaObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaCustomVia(p1.Data());
            }
            else {
                pyv_oaObserver_oaCustomVia* p=new pyv_oaObserver_oaCustomVia(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaCustomVia(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaCustomVia* p=new pyv_oaObserver_oaCustomVia(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaCustomVia)
    {
        PyParamoaObserver_oaCustomVia p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaCustomVia_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaCustomVia(p1.Data());
            }
            else {
                pyv_oaObserver_oaCustomVia* p=new pyv_oaObserver_oaCustomVia(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaCustomVia, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaCustomVia)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaCustomVia_tp_dealloc(PyoaObserver_oaCustomViaObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaCustomVia*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaCustomVia_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaCustomVia value;
    int convert_status=PyoaObserver_oaCustomVia_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaObserver_oaCustomVia::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaCustomVia_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaCustomVia v1;
    PyParamoaObserver_oaCustomVia v2;
    int convert_status1=PyoaObserver_oaCustomVia_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaCustomVia_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaCustomVia_Convert(PyObject* ob,PyParamoaObserver_oaCustomVia* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaCustomVia_Check(ob)) {
        result->SetData( (oaObserver_oaCustomVia*) ((PyoaObserver_oaCustomViaObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaCustomVia Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaCustomVia_FromoaObserver_oaCustomVia(oaObserver_oaCustomVia* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaCustomVia_Type.tp_alloc(&PyoaObserver_oaCustomVia_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaCustomViaObject* self = (PyoaObserver_oaCustomViaObject*)bself;
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
pyv_oaObserver_oaCustomVia::pyv_oaObserver_oaCustomVia(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaCustomVia(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaCustomVia::pyv_oaObserver_oaCustomVia(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaCustomVia(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaCustomVia::pyv_oaObserver_oaCustomVia(const oaObserver_oaCustomVia& p)
 : pyob(NULL),
   oaObserver_oaCustomVia(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCustomVia::onPostCreate(oaCustomVia* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomVia::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaCustomVia_FromoaCustomVia(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomVia::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCustomVia::onPostModify(oaCustomVia* p1,oaViaModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomVia::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaCustomVia_FromoaCustomVia(p1));
    PyTuple_SetItem(args,1,PyoaViaModTypeEnum_FromoaViaModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomVia::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCustomVia::onPreDestroy(oaCustomVia* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomVia::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaCustomVia_FromoaCustomVia(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomVia::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCustomVia::onPreModify(oaCustomVia* p1,oaViaModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomVia::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaCustomVia_FromoaCustomVia(p1));
    PyTuple_SetItem(args,1,PyoaViaModTypeEnum_FromoaViaModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomVia::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaCustomVia_doc[] = 
"Class: oaObserver_oaCustomVia\n"
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
"    Calls: oaObserver_oaCustomVia(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaCustomVia||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaCustomVia\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaCustomVia(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaCustomVia||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaCustomVia\n"
"  Paramegers: (oaObserver_oaCustomVia)\n"
"    Calls: (const oaObserver_oaCustomVia&)\n"
"    Signature: oaObserver_oaCustomVia||cref-oaObserver_oaCustomVia,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaCustomVia_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaCustomVia",
    sizeof(PyoaObserver_oaCustomViaObject),
    0,
    (destructor)oaObserver_oaCustomVia_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaCustomVia_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaCustomVia_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaCustomVia_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaCustomVia_oaViaModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaCustomVia_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaCustomVia_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaCustomVia_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaCustomVia\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaCustomVia",
           (PyObject*)(&PyoaObserver_oaCustomVia_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaCustomVia\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaCustomViaDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaCustomViaDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaCustomViaDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaCustomViaDefObject* self = (PyoaObserver_oaCustomViaDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaCustomViaDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaCustomViaDef* p=new pyv_oaObserver_oaCustomViaDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaCustomViaDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaCustomViaDef* p=new pyv_oaObserver_oaCustomViaDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaCustomViaDef)
    {
        PyParamoaObserver_oaCustomViaDef p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaCustomViaDef_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaCustomViaDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaCustomViaDef* p=new pyv_oaObserver_oaCustomViaDef(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaCustomViaDef, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaCustomViaDef)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaCustomViaDef_tp_dealloc(PyoaObserver_oaCustomViaDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaCustomViaDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaCustomViaDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaCustomViaDef value;
    int convert_status=PyoaObserver_oaCustomViaDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaCustomViaDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaCustomViaDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaCustomViaDef v1;
    PyParamoaObserver_oaCustomViaDef v2;
    int convert_status1=PyoaObserver_oaCustomViaDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaCustomViaDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaCustomViaDef_Convert(PyObject* ob,PyParamoaObserver_oaCustomViaDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaCustomViaDef_Check(ob)) {
        result->SetData( (oaObserver_oaCustomViaDef*) ((PyoaObserver_oaCustomViaDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaCustomViaDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaCustomViaDef_FromoaObserver_oaCustomViaDef(oaObserver_oaCustomViaDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaCustomViaDef_Type.tp_alloc(&PyoaObserver_oaCustomViaDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaCustomViaDefObject* self = (PyoaObserver_oaCustomViaDefObject*)bself;
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
pyv_oaObserver_oaCustomViaDef::pyv_oaObserver_oaCustomViaDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaCustomViaDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaCustomViaDef::pyv_oaObserver_oaCustomViaDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaCustomViaDef(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaCustomViaDef::pyv_oaObserver_oaCustomViaDef(const oaObserver_oaCustomViaDef& p)
 : pyob(NULL),
   oaObserver_oaCustomViaDef(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCustomViaDef::onPostCreate(oaCustomViaDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomViaDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaCustomViaDef_FromoaCustomViaDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomViaDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCustomViaDef::onPostModify(oaCustomViaDef* p1,oaViaDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomViaDef::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaCustomViaDef_FromoaCustomViaDef(p1));
    PyTuple_SetItem(args,1,PyoaViaDefModTypeEnum_FromoaViaDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomViaDef::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCustomViaDef::onPreDestroy(oaCustomViaDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomViaDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaCustomViaDef_FromoaCustomViaDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomViaDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCustomViaDef::onPreModify(oaCustomViaDef* p1,oaViaDefModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomViaDef::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaCustomViaDef_FromoaCustomViaDef(p1));
    PyTuple_SetItem(args,1,PyoaViaDefModTypeEnum_FromoaViaDefModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomViaDef::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaCustomViaDef_doc[] = 
"Class: oaObserver_oaCustomViaDef\n"
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
"    Calls: oaObserver_oaCustomViaDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaCustomViaDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaCustomViaDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaCustomViaDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaCustomViaDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaCustomViaDef\n"
"  Paramegers: (oaObserver_oaCustomViaDef)\n"
"    Calls: (const oaObserver_oaCustomViaDef&)\n"
"    Signature: oaObserver_oaCustomViaDef||cref-oaObserver_oaCustomViaDef,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaCustomViaDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaCustomViaDef",
    sizeof(PyoaObserver_oaCustomViaDefObject),
    0,
    (destructor)oaObserver_oaCustomViaDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaCustomViaDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaCustomViaDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaCustomViaDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaCustomViaDef_oaViaDefModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaCustomViaDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaCustomViaDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaCustomViaDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaCustomViaDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaCustomViaDef",
           (PyObject*)(&PyoaObserver_oaCustomViaDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaCustomViaDef\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaCustomViaHeader
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaCustomViaHeader_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaCustomViaHeader_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaCustomViaHeaderObject* self = (PyoaObserver_oaCustomViaHeaderObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaCustomViaHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaCustomViaHeader* p=new pyv_oaObserver_oaCustomViaHeader(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaCustomViaHeader(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaCustomViaHeader* p=new pyv_oaObserver_oaCustomViaHeader(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaCustomViaHeader)
    {
        PyParamoaObserver_oaCustomViaHeader p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaCustomViaHeader_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaCustomViaHeader(p1.Data());
            }
            else {
                pyv_oaObserver_oaCustomViaHeader* p=new pyv_oaObserver_oaCustomViaHeader(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaCustomViaHeader, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaCustomViaHeader)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaCustomViaHeader_tp_dealloc(PyoaObserver_oaCustomViaHeaderObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaCustomViaHeader*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaCustomViaHeader_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaCustomViaHeader value;
    int convert_status=PyoaObserver_oaCustomViaHeader_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaObserver_oaCustomViaHeader::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaCustomViaHeader_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaCustomViaHeader v1;
    PyParamoaObserver_oaCustomViaHeader v2;
    int convert_status1=PyoaObserver_oaCustomViaHeader_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaCustomViaHeader_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaCustomViaHeader_Convert(PyObject* ob,PyParamoaObserver_oaCustomViaHeader* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaCustomViaHeader_Check(ob)) {
        result->SetData( (oaObserver_oaCustomViaHeader*) ((PyoaObserver_oaCustomViaHeaderObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaCustomViaHeader Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaCustomViaHeader_FromoaObserver_oaCustomViaHeader(oaObserver_oaCustomViaHeader* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaCustomViaHeader_Type.tp_alloc(&PyoaObserver_oaCustomViaHeader_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaCustomViaHeaderObject* self = (PyoaObserver_oaCustomViaHeaderObject*)bself;
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
pyv_oaObserver_oaCustomViaHeader::pyv_oaObserver_oaCustomViaHeader(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaCustomViaHeader(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaCustomViaHeader::pyv_oaObserver_oaCustomViaHeader(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaCustomViaHeader(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaCustomViaHeader::pyv_oaObserver_oaCustomViaHeader(const oaObserver_oaCustomViaHeader& p)
 : pyob(NULL),
   oaObserver_oaCustomViaHeader(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCustomViaHeader::onPostCreate(oaCustomViaHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomViaHeader::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaCustomViaHeader_FromoaCustomViaHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomViaHeader::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCustomViaHeader::onPostModify(oaCustomViaHeader* p1,oaViaHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomViaHeader::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaCustomViaHeader_FromoaCustomViaHeader(p1));
    PyTuple_SetItem(args,1,PyoaViaHeaderModTypeEnum_FromoaViaHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomViaHeader::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCustomViaHeader::onPreDestroy(oaCustomViaHeader* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomViaHeader::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaCustomViaHeader_FromoaCustomViaHeader(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomViaHeader::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaCustomViaHeader::onPreModify(oaCustomViaHeader* p1,oaViaHeaderModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomViaHeader::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaCustomViaHeader_FromoaCustomViaHeader(p1));
    PyTuple_SetItem(args,1,PyoaViaHeaderModTypeEnum_FromoaViaHeaderModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaCustomViaHeader::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaCustomViaHeader_doc[] = 
"Class: oaObserver_oaCustomViaHeader\n"
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
"    Calls: oaObserver_oaCustomViaHeader(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaCustomViaHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaCustomViaHeader\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaCustomViaHeader(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaCustomViaHeader||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaCustomViaHeader\n"
"  Paramegers: (oaObserver_oaCustomViaHeader)\n"
"    Calls: (const oaObserver_oaCustomViaHeader&)\n"
"    Signature: oaObserver_oaCustomViaHeader||cref-oaObserver_oaCustomViaHeader,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaCustomViaHeader_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaCustomViaHeader",
    sizeof(PyoaObserver_oaCustomViaHeaderObject),
    0,
    (destructor)oaObserver_oaCustomViaHeader_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaCustomViaHeader_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaCustomViaHeader_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaCustomViaHeader_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaCustomViaHeader_oaViaHeaderModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaCustomViaHeader_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaCustomViaHeader_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaCustomViaHeader_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaCustomViaHeader\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaCustomViaHeader",
           (PyObject*)(&PyoaObserver_oaCustomViaHeader_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaCustomViaHeader\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaDMData
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDMData_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaDMData_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaDMDataObject* self = (PyoaObserver_oaDMDataObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaDMData(p1.Data());
            }
            else {
                pyv_oaObserver_oaDMData* p=new pyv_oaObserver_oaDMData(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaDMData(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaDMData* p=new pyv_oaObserver_oaDMData(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaDMData, Choices are:\n"
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
oaObserver_oaDMData_tp_dealloc(PyoaObserver_oaDMDataObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaDMData*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDMData_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaDMData value;
    int convert_status=PyoaObserver_oaDMData_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaObserver_oaDMData::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaDMData_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaDMData v1;
    PyParamoaObserver_oaDMData v2;
    int convert_status1=PyoaObserver_oaDMData_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaDMData_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaDMData_Convert(PyObject* ob,PyParamoaObserver_oaDMData* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaDMData_Check(ob)) {
        result->SetData( (oaObserver_oaDMData*) ((PyoaObserver_oaDMDataObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaDMData Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaDMData_FromoaObserver_oaDMData(oaObserver_oaDMData* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaDMData_Type.tp_alloc(&PyoaObserver_oaDMData_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaDMDataObject* self = (PyoaObserver_oaDMDataObject*)bself;
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
pyv_oaObserver_oaDMData::pyv_oaObserver_oaDMData(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaDMData(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDMData::pyv_oaObserver_oaDMData(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaDMData(p1,p2)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDMData::onFirstOpen(oaDMData* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onFirstOpen");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDMData::onFirstOpen was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDMData_FromoaDMData(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDMData::onFirstOpen had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDMData::onPostReopen(oaDMData* p1,oaChar p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostReopen");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDMData::onPostReopen was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDMData_FromoaDMData(p1));
    PyTuple_SetItem(args,1,PyoaChar_FromoaChar(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDMData::onPostReopen had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDMData::onPostSave(oaDMData* p1,oaBoolean p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostSave");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDMData::onPostSave was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDMData_FromoaDMData(p1));
    PyTuple_SetItem(args,1,PyoaBoolean_FromoaBoolean(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDMData::onPostSave had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDMData::onPreReopen(oaDMData* p1,oaChar p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreReopen");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDMData::onPreReopen was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDMData_FromoaDMData(p1));
    PyTuple_SetItem(args,1,PyoaChar_FromoaChar(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDMData::onPreReopen had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDMData::onPreSave(oaDMData* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreSave");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDMData::onPreSave was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDMData_FromoaDMData(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDMData::onPreSave had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDMData::onPurge(oaDMData* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPurge");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDMData::onPurge was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDMData_FromoaDMData(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDMData::onPurge had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDMData::onTruncate(oaDMData* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onTruncate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDMData::onTruncate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDMData_FromoaDMData(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDMData::onTruncate had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDMData_onFirstOpen_doc[] = 
"Class: oaObserver_oaDMData, Function: onFirstOpen\n"
"  Paramegers: (oaDMData)\n"
"    Calls: virtual void onFirstOpen(oaDMData* dmData)\n"
"    Signature: onFirstOpen|void-void|ptr-oaDMData,\n"
"    This function is called when an oaDMData object is first opened. The application's derived class should implement this function to receive notification when an oaDMData object has been opened.\n"
"    dmData\n"
"    A pointer to the newly-opened oaDMData\n"
;

static PyObject*
oaObserver_oaDMData_onFirstOpen(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDMData data;
    int convert_status=PyoaObserver_oaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDMDataObject* self=(PyoaObserver_oaDMDataObject*)ob;

    PyParamoaDMData p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMData_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDMData::onFirstOpen(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDMData_onPostReopen_doc[] = 
"Class: oaObserver_oaDMData, Function: onPostReopen\n"
"  Paramegers: (oaDMData,oaChar)\n"
"    Calls: virtual void onPostReopen(oaDMData* dmData,oaChar oldMode)\n"
"    Signature: onPostReopen|void-void|ptr-oaDMData,simple-oaChar,\n"
"    This function is called just after an oaDMData object is reopened using a new access mode. The application's derived class should implement this function to receive notification when an oaDMData object has been reopened in a new access mode.\n"
"    dmData\n"
"    A pointer to the oaDMData object with the mode change\n"
"    oldMode\n"
"    The mode with which the design was previously opened\n"
;

static PyObject*
oaObserver_oaDMData_onPostReopen(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDMData data;
    int convert_status=PyoaObserver_oaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDMDataObject* self=(PyoaObserver_oaDMDataObject*)ob;

    PyParamoaDMData p1;
    PyParamoaChar p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDMData_Convert,&p1,
          &PyoaChar_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDMData::onPostReopen(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDMData_onPostSave_doc[] = 
"Class: oaObserver_oaDMData, Function: onPostSave\n"
"  Paramegers: (oaDMData,oaBoolean)\n"
"    Calls: virtual void onPostSave(oaDMData* dmData,oaBoolean succeeded)\n"
"    Signature: onPostSave|void-void|ptr-oaDMData,simple-oaBoolean,\n"
"    This function is called after an attempt to save an oaDMData object to disk. The application's derived class should implement this function to receive notification when a save has been attempted on an oaDMData object.\n"
"    dmData\n"
"    A pointer to the saved oaDMData object\n"
"    succeeded\n"
"    A boolean that indicates whether the save was successful\n"
;

static PyObject*
oaObserver_oaDMData_onPostSave(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDMData data;
    int convert_status=PyoaObserver_oaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDMDataObject* self=(PyoaObserver_oaDMDataObject*)ob;

    PyParamoaDMData p1;
    PyParamoaBoolean p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDMData_Convert,&p1,
          &PyoaBoolean_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDMData::onPostSave(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDMData_onPreReopen_doc[] = 
"Class: oaObserver_oaDMData, Function: onPreReopen\n"
"  Paramegers: (oaDMData,oaChar)\n"
"    Calls: virtual void onPreReopen(oaDMData* dmData,oaChar newMode)\n"
"    Signature: onPreReopen|void-void|ptr-oaDMData,simple-oaChar,\n"
"    This function is called before an oaDMData object is reopened using a different access mode. The application's derived class should implement this function to receive notification when an oaDMData object is about to be reopened.\n"
"    dmData\n"
"    A pointer to the oaDMData object with the mode change\n"
"    newMode\n"
"    The new mode in which the design will be reopened\n"
;

static PyObject*
oaObserver_oaDMData_onPreReopen(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDMData data;
    int convert_status=PyoaObserver_oaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDMDataObject* self=(PyoaObserver_oaDMDataObject*)ob;

    PyParamoaDMData p1;
    PyParamoaChar p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDMData_Convert,&p1,
          &PyoaChar_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDMData::onPreReopen(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDMData_onPreSave_doc[] = 
"Class: oaObserver_oaDMData, Function: onPreSave\n"
"  Paramegers: (oaDMData)\n"
"    Calls: virtual void onPreSave(oaDMData* dmData)\n"
"    Signature: onPreSave|void-void|ptr-oaDMData,\n"
"    This function is called just before an oaDMData object is saved to the disk. The application's derived class should implement this function to receive notification when an oaDMData object is about to be saved.\n"
"    dmData\n"
"    A pointer to the oaDMData about to be saved\n"
;

static PyObject*
oaObserver_oaDMData_onPreSave(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDMData data;
    int convert_status=PyoaObserver_oaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDMDataObject* self=(PyoaObserver_oaDMDataObject*)ob;

    PyParamoaDMData p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMData_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDMData::onPreSave(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDMData_onPurge_doc[] = 
"Class: oaObserver_oaDMData, Function: onPurge\n"
"  Paramegers: (oaDMData)\n"
"    Calls: virtual void onPurge(oaDMData* dmData)\n"
"    Signature: onPurge|void-void|ptr-oaDMData,\n"
"    This function is called when a oaDMData object is about to be purged from memory. The application's derived class should implement this function to receive notification when an oaDMData object is about to be purged.\n"
"    dmData\n"
"    A pointer to the oaDMData object about to be purged\n"
;

static PyObject*
oaObserver_oaDMData_onPurge(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDMData data;
    int convert_status=PyoaObserver_oaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDMDataObject* self=(PyoaObserver_oaDMDataObject*)ob;

    PyParamoaDMData p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMData_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDMData::onPurge(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDMData_onTruncate_doc[] = 
"Class: oaObserver_oaDMData, Function: onTruncate\n"
"  Paramegers: (oaDMData)\n"
"    Calls: virtual void onTruncate(oaDMData* dmData)\n"
"    Signature: onTruncate|void-void|ptr-oaDMData,\n"
"    This function is called just before an oaDMData object is truncated (for example, after all contents are removed). The application's derived class should implement this function to receive notification when an oaDMData object is about to be truncated.\n"
"    dmData\n"
"    A pointer to the oaDMData object about to be truncated\n"
;

static PyObject*
oaObserver_oaDMData_onTruncate(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDMData data;
    int convert_status=PyoaObserver_oaDMData_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDMDataObject* self=(PyoaObserver_oaDMDataObject*)ob;

    PyParamoaDMData p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMData_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDMData::onTruncate(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaObserver_oaDMData_assign_doc[] = 
"Class: oaObserver_oaDMData, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaObserver_oaDMData_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaObserver_oaDMData data;
  int convert_status=PyoaObserver_oaDMData_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaObserver_oaDMData p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaObserver_oaDMData_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaObserver_oaDMData_methodlist[] = {
    {"onFirstOpen",(PyCFunction)oaObserver_oaDMData_onFirstOpen,METH_VARARGS,oaObserver_oaDMData_onFirstOpen_doc},
    {"onPostReopen",(PyCFunction)oaObserver_oaDMData_onPostReopen,METH_VARARGS,oaObserver_oaDMData_onPostReopen_doc},
    {"onPostSave",(PyCFunction)oaObserver_oaDMData_onPostSave,METH_VARARGS,oaObserver_oaDMData_onPostSave_doc},
    {"onPreReopen",(PyCFunction)oaObserver_oaDMData_onPreReopen,METH_VARARGS,oaObserver_oaDMData_onPreReopen_doc},
    {"onPreSave",(PyCFunction)oaObserver_oaDMData_onPreSave,METH_VARARGS,oaObserver_oaDMData_onPreSave_doc},
    {"onPurge",(PyCFunction)oaObserver_oaDMData_onPurge,METH_VARARGS,oaObserver_oaDMData_onPurge_doc},
    {"onTruncate",(PyCFunction)oaObserver_oaDMData_onTruncate,METH_VARARGS,oaObserver_oaDMData_onTruncate_doc},
    {"assign",(PyCFunction)oaObserver_oaDMData_tp_assign,METH_VARARGS,oaObserver_oaDMData_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDMData_doc[] = 
"Class: oaObserver_oaDMData\n"
"  oaObserver<oaDMData> is a base observer class for oaDMData object observers. It supports onFirstOpen, onPurge, onPreSave, onPostSave, onPreReopen, onPostReopen, and onTruncate event notifications.\n"
"  See oaObserver for information on using Open Access observer template classes to derive and instantiate observers in an application.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaDMData(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaDMData||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDMData\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaDMData(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaDMData||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDMData\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaDMData_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaDMData",
    sizeof(PyoaObserver_oaDMDataObject),
    0,
    (destructor)oaObserver_oaDMData_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaDMData_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaDMData_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaDMData_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaObserver_oaDMData_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseObserver_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaDMData_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDMData_static_notifyFirstOpenObservers_doc[] = 
"Class: oaObserver_oaDMData, Function: notifyFirstOpenObservers\n"
"  Paramegers: (oaDMData)\n"
"    Calls: void notifyFirstOpenObservers(oaDMData* dmData)\n"
"    Signature: notifyFirstOpenObservers|void-void|ptr-oaDMData,\n"
"    Function notifyFirstOpenObservers\n"
;

static PyObject*
oaObserver_oaDMData_static_notifyFirstOpenObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMData_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDMData::notifyFirstOpenObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDMData_static_notifyPostReopenObservers_doc[] = 
"Class: oaObserver_oaDMData, Function: notifyPostReopenObservers\n"
"  Paramegers: (oaDMData,oaChar)\n"
"    Calls: void notifyPostReopenObservers(oaDMData* dmData,oaChar oldMode)\n"
"    Signature: notifyPostReopenObservers|void-void|ptr-oaDMData,simple-oaChar,\n"
"    Function notifyPostReopenObservers\n"
;

static PyObject*
oaObserver_oaDMData_static_notifyPostReopenObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData p1;
    PyParamoaChar p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDMData_Convert,&p1,
          &PyoaChar_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDMData::notifyPostReopenObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDMData_static_notifyPostSaveObservers_doc[] = 
"Class: oaObserver_oaDMData, Function: notifyPostSaveObservers\n"
"  Paramegers: (oaDMData,oaBoolean)\n"
"    Calls: void notifyPostSaveObservers(oaDMData* dmData,oaBoolean succeeded)\n"
"    Signature: notifyPostSaveObservers|void-void|ptr-oaDMData,simple-oaBoolean,\n"
"    Function notifyPostSaveObservers\n"
;

static PyObject*
oaObserver_oaDMData_static_notifyPostSaveObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData p1;
    PyParamoaBoolean p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDMData_Convert,&p1,
          &PyoaBoolean_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDMData::notifyPostSaveObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDMData_static_notifyPreReopenObservers_doc[] = 
"Class: oaObserver_oaDMData, Function: notifyPreReopenObservers\n"
"  Paramegers: (oaDMData,oaChar)\n"
"    Calls: void notifyPreReopenObservers(oaDMData* dmData,oaChar newMode)\n"
"    Signature: notifyPreReopenObservers|void-void|ptr-oaDMData,simple-oaChar,\n"
"    Function notifyPreReopenObservers\n"
;

static PyObject*
oaObserver_oaDMData_static_notifyPreReopenObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData p1;
    PyParamoaChar p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDMData_Convert,&p1,
          &PyoaChar_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDMData::notifyPreReopenObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDMData_static_notifyPreSaveObservers_doc[] = 
"Class: oaObserver_oaDMData, Function: notifyPreSaveObservers\n"
"  Paramegers: (oaDMData)\n"
"    Calls: void notifyPreSaveObservers(oaDMData* dmData)\n"
"    Signature: notifyPreSaveObservers|void-void|ptr-oaDMData,\n"
"    Function notifyPreSaveObservers\n"
;

static PyObject*
oaObserver_oaDMData_static_notifyPreSaveObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMData_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDMData::notifyPreSaveObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDMData_static_notifyPurgeObservers_doc[] = 
"Class: oaObserver_oaDMData, Function: notifyPurgeObservers\n"
"  Paramegers: (oaDMData)\n"
"    Calls: void notifyPurgeObservers(oaDMData* dmData)\n"
"    Signature: notifyPurgeObservers|void-void|ptr-oaDMData,\n"
"    Function notifyPurgeObservers\n"
;

static PyObject*
oaObserver_oaDMData_static_notifyPurgeObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMData_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDMData::notifyPurgeObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDMData_static_notifyTruncateObservers_doc[] = 
"Class: oaObserver_oaDMData, Function: notifyTruncateObservers\n"
"  Paramegers: (oaDMData)\n"
"    Calls: void notifyTruncateObservers(oaDMData* dmData)\n"
"    Signature: notifyTruncateObservers|void-void|ptr-oaDMData,\n"
"    Function notifyTruncateObservers\n"
;

static PyObject*
oaObserver_oaDMData_static_notifyTruncateObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDMData p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDMData_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDMData::notifyTruncateObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaObserver_oaDMData_staticmethodlist[] = {
    {"static_notifyFirstOpenObservers",(PyCFunction)oaObserver_oaDMData_static_notifyFirstOpenObservers,METH_VARARGS,oaObserver_oaDMData_static_notifyFirstOpenObservers_doc},
    {"static_notifyPostReopenObservers",(PyCFunction)oaObserver_oaDMData_static_notifyPostReopenObservers,METH_VARARGS,oaObserver_oaDMData_static_notifyPostReopenObservers_doc},
    {"static_notifyPostSaveObservers",(PyCFunction)oaObserver_oaDMData_static_notifyPostSaveObservers,METH_VARARGS,oaObserver_oaDMData_static_notifyPostSaveObservers_doc},
    {"static_notifyPreReopenObservers",(PyCFunction)oaObserver_oaDMData_static_notifyPreReopenObservers,METH_VARARGS,oaObserver_oaDMData_static_notifyPreReopenObservers_doc},
    {"static_notifyPreSaveObservers",(PyCFunction)oaObserver_oaDMData_static_notifyPreSaveObservers,METH_VARARGS,oaObserver_oaDMData_static_notifyPreSaveObservers_doc},
    {"static_notifyPurgeObservers",(PyCFunction)oaObserver_oaDMData_static_notifyPurgeObservers,METH_VARARGS,oaObserver_oaDMData_static_notifyPurgeObservers_doc},
    {"static_notifyTruncateObservers",(PyCFunction)oaObserver_oaDMData_static_notifyTruncateObservers,METH_VARARGS,oaObserver_oaDMData_static_notifyTruncateObservers_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaDMData_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaDMData_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaDMData\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaDMData",
           (PyObject*)(&PyoaObserver_oaDMData_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaDMData\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaObserver_oaDMData_Type.tp_dict;
    for(method=oaObserver_oaDMData_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaObserver_oaDMFile
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDMFile_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaDMFile_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaDMFileObject* self = (PyoaObserver_oaDMFileObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaDMFile(p1.Data());
            }
            else {
                pyv_oaObserver_oaDMFile* p=new pyv_oaObserver_oaDMFile(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaDMFile(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaDMFile* p=new pyv_oaObserver_oaDMFile(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaDMFile)
    {
        PyParamoaObserver_oaDMFile p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaDMFile_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaDMFile(p1.Data());
            }
            else {
                pyv_oaObserver_oaDMFile* p=new pyv_oaObserver_oaDMFile(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaDMFile, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaDMFile)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaDMFile_tp_dealloc(PyoaObserver_oaDMFileObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaDMFile*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDMFile_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaDMFile value;
    int convert_status=PyoaObserver_oaDMFile_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaObserver_oaDMFile::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaDMFile_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaDMFile v1;
    PyParamoaObserver_oaDMFile v2;
    int convert_status1=PyoaObserver_oaDMFile_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaDMFile_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaDMFile_Convert(PyObject* ob,PyParamoaObserver_oaDMFile* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaDMFile_Check(ob)) {
        result->SetData( (oaObserver_oaDMFile*) ((PyoaObserver_oaDMFileObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaDMFile Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaDMFile_FromoaObserver_oaDMFile(oaObserver_oaDMFile* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaDMFile_Type.tp_alloc(&PyoaObserver_oaDMFile_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaDMFileObject* self = (PyoaObserver_oaDMFileObject*)bself;
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
pyv_oaObserver_oaDMFile::pyv_oaObserver_oaDMFile(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaDMFile(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDMFile::pyv_oaObserver_oaDMFile(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaDMFile(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDMFile::pyv_oaObserver_oaDMFile(const oaObserver_oaDMFile& p)
 : pyob(NULL),
   oaObserver_oaDMFile(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDMFile::onPostCreate(oaDMFile* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDMFile::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDMFile_FromoaDMFile(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDMFile::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDMFile::onPostModify(oaDMFile* p1,oaDMFileModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDMFile::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDMFile_FromoaDMFile(p1));
    PyTuple_SetItem(args,1,PyoaDMFileModTypeEnum_FromoaDMFileModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDMFile::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDMFile::onPreDestroy(oaDMFile* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDMFile::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDMFile_FromoaDMFile(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDMFile::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDMFile::onPreModify(oaDMFile* p1,oaDMFileModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDMFile::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDMFile_FromoaDMFile(p1));
    PyTuple_SetItem(args,1,PyoaDMFileModTypeEnum_FromoaDMFileModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDMFile::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDMFile_doc[] = 
"Class: oaObserver_oaDMFile\n"
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
"    Calls: oaObserver_oaDMFile(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaDMFile||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDMFile\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaDMFile(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaDMFile||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDMFile\n"
"  Paramegers: (oaObserver_oaDMFile)\n"
"    Calls: (const oaObserver_oaDMFile&)\n"
"    Signature: oaObserver_oaDMFile||cref-oaObserver_oaDMFile,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaDMFile_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaDMFile",
    sizeof(PyoaObserver_oaDMFileObject),
    0,
    (destructor)oaObserver_oaDMFile_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaDMFile_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaDMFile_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaDMFile_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaDMFile_oaDMFileModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaDMFile_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaDMFile_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaDMFile_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaDMFile\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaDMFile",
           (PyObject*)(&PyoaObserver_oaDMFile_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaDMFile\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaDerivedLayer
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDerivedLayer_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaDerivedLayer_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaDerivedLayerObject* self = (PyoaObserver_oaDerivedLayerObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaDerivedLayer(p1.Data());
            }
            else {
                pyv_oaObserver_oaDerivedLayer* p=new pyv_oaObserver_oaDerivedLayer(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaDerivedLayer(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaDerivedLayer* p=new pyv_oaObserver_oaDerivedLayer(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaDerivedLayer)
    {
        PyParamoaObserver_oaDerivedLayer p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaDerivedLayer_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaDerivedLayer(p1.Data());
            }
            else {
                pyv_oaObserver_oaDerivedLayer* p=new pyv_oaObserver_oaDerivedLayer(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaDerivedLayer, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaDerivedLayer)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaDerivedLayer_tp_dealloc(PyoaObserver_oaDerivedLayerObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaDerivedLayer*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDerivedLayer_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaDerivedLayer value;
    int convert_status=PyoaObserver_oaDerivedLayer_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaDerivedLayer::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaDerivedLayer_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaDerivedLayer v1;
    PyParamoaObserver_oaDerivedLayer v2;
    int convert_status1=PyoaObserver_oaDerivedLayer_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaDerivedLayer_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaDerivedLayer_Convert(PyObject* ob,PyParamoaObserver_oaDerivedLayer* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaDerivedLayer_Check(ob)) {
        result->SetData( (oaObserver_oaDerivedLayer*) ((PyoaObserver_oaDerivedLayerObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaDerivedLayer Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaDerivedLayer_FromoaObserver_oaDerivedLayer(oaObserver_oaDerivedLayer* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaDerivedLayer_Type.tp_alloc(&PyoaObserver_oaDerivedLayer_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaDerivedLayerObject* self = (PyoaObserver_oaDerivedLayerObject*)bself;
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
pyv_oaObserver_oaDerivedLayer::pyv_oaObserver_oaDerivedLayer(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaDerivedLayer(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDerivedLayer::pyv_oaObserver_oaDerivedLayer(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaDerivedLayer(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDerivedLayer::pyv_oaObserver_oaDerivedLayer(const oaObserver_oaDerivedLayer& p)
 : pyob(NULL),
   oaObserver_oaDerivedLayer(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDerivedLayer::onPostCreate(oaDerivedLayer* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayer::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDerivedLayer_FromoaDerivedLayer(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayer::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDerivedLayer::onPostModify(oaDerivedLayer* p1,oaLayerModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayer::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDerivedLayer_FromoaDerivedLayer(p1));
    PyTuple_SetItem(args,1,PyoaLayerModTypeEnum_FromoaLayerModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayer::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDerivedLayer::onPreDestroy(oaDerivedLayer* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayer::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDerivedLayer_FromoaDerivedLayer(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayer::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDerivedLayer::onPreModify(oaDerivedLayer* p1,oaLayerModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayer::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDerivedLayer_FromoaDerivedLayer(p1));
    PyTuple_SetItem(args,1,PyoaLayerModTypeEnum_FromoaLayerModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayer::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDerivedLayer_doc[] = 
"Class: oaObserver_oaDerivedLayer\n"
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
"    Calls: oaObserver_oaDerivedLayer(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaDerivedLayer||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDerivedLayer\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaDerivedLayer(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaDerivedLayer||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDerivedLayer\n"
"  Paramegers: (oaObserver_oaDerivedLayer)\n"
"    Calls: (const oaObserver_oaDerivedLayer&)\n"
"    Signature: oaObserver_oaDerivedLayer||cref-oaObserver_oaDerivedLayer,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaDerivedLayer_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaDerivedLayer",
    sizeof(PyoaObserver_oaDerivedLayerObject),
    0,
    (destructor)oaObserver_oaDerivedLayer_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaDerivedLayer_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaDerivedLayer_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaDerivedLayer_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaDerivedLayer_oaLayerModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaDerivedLayer_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaDerivedLayer_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaDerivedLayer_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaDerivedLayer\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaDerivedLayer",
           (PyObject*)(&PyoaObserver_oaDerivedLayer_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaDerivedLayer\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaDerivedLayerDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDerivedLayerDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaDerivedLayerDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaDerivedLayerDefObject* self = (PyoaObserver_oaDerivedLayerDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaDerivedLayerDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaDerivedLayerDef* p=new pyv_oaObserver_oaDerivedLayerDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaDerivedLayerDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaDerivedLayerDef* p=new pyv_oaObserver_oaDerivedLayerDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaDerivedLayerDef, Choices are:\n"
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
oaObserver_oaDerivedLayerDef_tp_dealloc(PyoaObserver_oaDerivedLayerDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaDerivedLayerDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDerivedLayerDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaDerivedLayerDef value;
    int convert_status=PyoaObserver_oaDerivedLayerDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaObserver_oaDerivedLayerDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaDerivedLayerDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaDerivedLayerDef v1;
    PyParamoaObserver_oaDerivedLayerDef v2;
    int convert_status1=PyoaObserver_oaDerivedLayerDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaDerivedLayerDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaDerivedLayerDef_Convert(PyObject* ob,PyParamoaObserver_oaDerivedLayerDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaDerivedLayerDef_Check(ob)) {
        result->SetData( (oaObserver_oaDerivedLayerDef*) ((PyoaObserver_oaDerivedLayerDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaDerivedLayerDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaDerivedLayerDef_FromoaObserver_oaDerivedLayerDef(oaObserver_oaDerivedLayerDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaDerivedLayerDef_Type.tp_alloc(&PyoaObserver_oaDerivedLayerDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaDerivedLayerDefObject* self = (PyoaObserver_oaDerivedLayerDefObject*)bself;
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
pyv_oaObserver_oaDerivedLayerDef::pyv_oaObserver_oaDerivedLayerDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaDerivedLayerDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDerivedLayerDef::pyv_oaObserver_oaDerivedLayerDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaDerivedLayerDef(p1,p2)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDerivedLayerDef::onConflict(const oaString& p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onConflict");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerDef::onConflict was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaString_FromoaString(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerDef::onConflict had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDerivedLayerDef::onPostCreate(oaDerivedLayerDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDerivedLayerDef_FromoaDerivedLayerDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDerivedLayerDef::onPreDestroy(oaDerivedLayerDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDerivedLayerDef_FromoaDerivedLayerDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDerivedLayerDef_onConflict_doc[] = 
"Class: oaObserver_oaDerivedLayerDef, Function: onConflict\n"
"  Paramegers: (oaString)\n"
"    Calls: virtual void onConflict(const oaString& name)\n"
"    Signature: onConflict|void-void|cref-oaString,\n"
"    This function is called if an on-disk oaDerivedLayerDef conflicts with an existing oaDerivedLayerDef definition. Note that all data associated with the conflicting definition, including the definition itself, is destroyed following this notification.\n"
"    name\n"
"    The name of the conflicting oaDerivedLayerDef .\n"
;

static PyObject*
oaObserver_oaDerivedLayerDef_onConflict(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDerivedLayerDef data;
    int convert_status=PyoaObserver_oaDerivedLayerDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDerivedLayerDefObject* self=(PyoaObserver_oaDerivedLayerDefObject*)ob;

    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        data.DataCall()->oaObserver_oaDerivedLayerDef::onConflict(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDerivedLayerDef_onPostCreate_doc[] = 
"Class: oaObserver_oaDerivedLayerDef, Function: onPostCreate\n"
"  Paramegers: (oaDerivedLayerDef)\n"
"    Calls: virtual void onPostCreate(oaDerivedLayerDef* def)\n"
"    Signature: onPostCreate|void-void|ptr-oaDerivedLayerDef,\n"
"    This function is called after an oaDerivedLayerDef is created. The application's derived observer class should implement this function to receive notification after an oaDerivedLayerDef is created.\n"
"    def\n"
"    pointer to the created oaDerivedLayerDef object\n"
;

static PyObject*
oaObserver_oaDerivedLayerDef_onPostCreate(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDerivedLayerDef data;
    int convert_status=PyoaObserver_oaDerivedLayerDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDerivedLayerDefObject* self=(PyoaObserver_oaDerivedLayerDefObject*)ob;

    PyParamoaDerivedLayerDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDerivedLayerDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDerivedLayerDef::onPostCreate(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDerivedLayerDef_onPreDestroy_doc[] = 
"Class: oaObserver_oaDerivedLayerDef, Function: onPreDestroy\n"
"  Paramegers: (oaDerivedLayerDef)\n"
"    Calls: virtual void onPreDestroy(oaDerivedLayerDef* def)\n"
"    Signature: onPreDestroy|void-void|ptr-oaDerivedLayerDef,\n"
"    This function is called before an oaDerivedLayerDef is destroyed. The application's derived observer class should implement this function to receive notification when an oaDerivedLayerDef is about to be destroyed.\n"
"    def\n"
"    pointer to the oaDerivedLayerDef object about to be destroyed\n"
;

static PyObject*
oaObserver_oaDerivedLayerDef_onPreDestroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDerivedLayerDef data;
    int convert_status=PyoaObserver_oaDerivedLayerDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDerivedLayerDefObject* self=(PyoaObserver_oaDerivedLayerDefObject*)ob;

    PyParamoaDerivedLayerDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDerivedLayerDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDerivedLayerDef::onPreDestroy(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaObserver_oaDerivedLayerDef_assign_doc[] = 
"Class: oaObserver_oaDerivedLayerDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaObserver_oaDerivedLayerDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaObserver_oaDerivedLayerDef data;
  int convert_status=PyoaObserver_oaDerivedLayerDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaObserver_oaDerivedLayerDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaObserver_oaDerivedLayerDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaObserver_oaDerivedLayerDef_methodlist[] = {
    {"onConflict",(PyCFunction)oaObserver_oaDerivedLayerDef_onConflict,METH_VARARGS,oaObserver_oaDerivedLayerDef_onConflict_doc},
    {"onPostCreate",(PyCFunction)oaObserver_oaDerivedLayerDef_onPostCreate,METH_VARARGS,oaObserver_oaDerivedLayerDef_onPostCreate_doc},
    {"onPreDestroy",(PyCFunction)oaObserver_oaDerivedLayerDef_onPreDestroy,METH_VARARGS,oaObserver_oaDerivedLayerDef_onPreDestroy_doc},
    {"assign",(PyCFunction)oaObserver_oaDerivedLayerDef_tp_assign,METH_VARARGS,oaObserver_oaDerivedLayerDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDerivedLayerDef_doc[] = 
"Class: oaObserver_oaDerivedLayerDef\n"
"  This base template class can be used to derive observers for oaDerivedLayerDef objects. It supports postCreate, preDestroy, and onConflict event notifications.\n"
"  See oaObserver for information on using OpenAccess observer template classes to derive and instantiate observers in an application.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaDerivedLayerDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaDerivedLayerDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDerivedLayerDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaDerivedLayerDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaDerivedLayerDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDerivedLayerDef\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaDerivedLayerDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaDerivedLayerDef",
    sizeof(PyoaObserver_oaDerivedLayerDefObject),
    0,
    (destructor)oaObserver_oaDerivedLayerDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaDerivedLayerDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaDerivedLayerDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaDerivedLayerDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaObserver_oaDerivedLayerDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseObserver_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaDerivedLayerDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDerivedLayerDef_static_hasObservers_doc[] = 
"Class: oaObserver_oaDerivedLayerDef, Function: hasObservers\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasObservers()\n"
"    Signature: hasObservers|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if any observers for this type are active.\n"
;

static PyObject*
oaObserver_oaDerivedLayerDef_static_hasObservers(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (oaObserver_oaDerivedLayerDef::hasObservers());
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
static char oaObserver_oaDerivedLayerDef_static_notifyOnConflictObservers_doc[] = 
"Class: oaObserver_oaDerivedLayerDef, Function: notifyOnConflictObservers\n"
"  Paramegers: (oaString)\n"
"    Calls: void notifyOnConflictObservers(const oaString& name)\n"
"    Signature: notifyOnConflictObservers|void-void|cref-oaString,\n"
"    Function notifyOnConflictObservers\n"
;

static PyObject*
oaObserver_oaDerivedLayerDef_static_notifyOnConflictObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaString_Convert,&p1)) {
        oaObserver_oaDerivedLayerDef::notifyOnConflictObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDerivedLayerDef_static_notifyPostCreateObservers_doc[] = 
"Class: oaObserver_oaDerivedLayerDef, Function: notifyPostCreateObservers\n"
"  Paramegers: (oaDerivedLayerDef)\n"
"    Calls: void notifyPostCreateObservers(oaDerivedLayerDef* def)\n"
"    Signature: notifyPostCreateObservers|void-void|ptr-oaDerivedLayerDef,\n"
"    Function notifyPostCreateObservers\n"
;

static PyObject*
oaObserver_oaDerivedLayerDef_static_notifyPostCreateObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDerivedLayerDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDerivedLayerDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDerivedLayerDef::notifyPostCreateObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDerivedLayerDef_static_notifyPreDestroyObservers_doc[] = 
"Class: oaObserver_oaDerivedLayerDef, Function: notifyPreDestroyObservers\n"
"  Paramegers: (oaDerivedLayerDef)\n"
"    Calls: void notifyPreDestroyObservers(oaDerivedLayerDef* def)\n"
"    Signature: notifyPreDestroyObservers|void-void|ptr-oaDerivedLayerDef,\n"
"    Function notifyPreDestroyObservers\n"
;

static PyObject*
oaObserver_oaDerivedLayerDef_static_notifyPreDestroyObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDerivedLayerDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDerivedLayerDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDerivedLayerDef::notifyPreDestroyObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaObserver_oaDerivedLayerDef_staticmethodlist[] = {
    {"static_hasObservers",(PyCFunction)oaObserver_oaDerivedLayerDef_static_hasObservers,METH_VARARGS,oaObserver_oaDerivedLayerDef_static_hasObservers_doc},
    {"static_notifyOnConflictObservers",(PyCFunction)oaObserver_oaDerivedLayerDef_static_notifyOnConflictObservers,METH_VARARGS,oaObserver_oaDerivedLayerDef_static_notifyOnConflictObservers_doc},
    {"static_notifyPostCreateObservers",(PyCFunction)oaObserver_oaDerivedLayerDef_static_notifyPostCreateObservers,METH_VARARGS,oaObserver_oaDerivedLayerDef_static_notifyPostCreateObservers_doc},
    {"static_notifyPreDestroyObservers",(PyCFunction)oaObserver_oaDerivedLayerDef_static_notifyPreDestroyObservers,METH_VARARGS,oaObserver_oaDerivedLayerDef_static_notifyPreDestroyObservers_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaDerivedLayerDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaDerivedLayerDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaDerivedLayerDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaDerivedLayerDef",
           (PyObject*)(&PyoaObserver_oaDerivedLayerDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaDerivedLayerDef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaObserver_oaDerivedLayerDef_Type.tp_dict;
    for(method=oaObserver_oaDerivedLayerDef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaObserver_oaDerivedLayerParam
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDerivedLayerParam_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaDerivedLayerParam_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaDerivedLayerParamObject* self = (PyoaObserver_oaDerivedLayerParamObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaDerivedLayerParam(p1.Data());
            }
            else {
                pyv_oaObserver_oaDerivedLayerParam* p=new pyv_oaObserver_oaDerivedLayerParam(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaDerivedLayerParam(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaDerivedLayerParam* p=new pyv_oaObserver_oaDerivedLayerParam(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaDerivedLayerParam)
    {
        PyParamoaObserver_oaDerivedLayerParam p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaDerivedLayerParam_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaDerivedLayerParam(p1.Data());
            }
            else {
                pyv_oaObserver_oaDerivedLayerParam* p=new pyv_oaObserver_oaDerivedLayerParam(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaDerivedLayerParam, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaDerivedLayerParam)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaDerivedLayerParam_tp_dealloc(PyoaObserver_oaDerivedLayerParamObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaDerivedLayerParam*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDerivedLayerParam_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaDerivedLayerParam value;
    int convert_status=PyoaObserver_oaDerivedLayerParam_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaObserver_oaDerivedLayerParam::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaDerivedLayerParam_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaDerivedLayerParam v1;
    PyParamoaObserver_oaDerivedLayerParam v2;
    int convert_status1=PyoaObserver_oaDerivedLayerParam_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaDerivedLayerParam_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaDerivedLayerParam_Convert(PyObject* ob,PyParamoaObserver_oaDerivedLayerParam* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaDerivedLayerParam_Check(ob)) {
        result->SetData( (oaObserver_oaDerivedLayerParam*) ((PyoaObserver_oaDerivedLayerParamObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaDerivedLayerParam Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaDerivedLayerParam_FromoaObserver_oaDerivedLayerParam(oaObserver_oaDerivedLayerParam* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaDerivedLayerParam_Type.tp_alloc(&PyoaObserver_oaDerivedLayerParam_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaDerivedLayerParamObject* self = (PyoaObserver_oaDerivedLayerParamObject*)bself;
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
pyv_oaObserver_oaDerivedLayerParam::pyv_oaObserver_oaDerivedLayerParam(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaDerivedLayerParam(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDerivedLayerParam::pyv_oaObserver_oaDerivedLayerParam(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaDerivedLayerParam(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDerivedLayerParam::pyv_oaObserver_oaDerivedLayerParam(const oaObserver_oaDerivedLayerParam& p)
 : pyob(NULL),
   oaObserver_oaDerivedLayerParam(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDerivedLayerParam::onPostCreate(oaDerivedLayerParam* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerParam::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDerivedLayerParam_FromoaDerivedLayerParam(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerParam::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDerivedLayerParam::onPostModify(oaDerivedLayerParam* p1,oaDerivedLayerParamModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerParam::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDerivedLayerParam_FromoaDerivedLayerParam(p1));
    PyTuple_SetItem(args,1,PyoaDerivedLayerParamModTypeEnum_FromoaDerivedLayerParamModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerParam::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDerivedLayerParam::onPreDestroy(oaDerivedLayerParam* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerParam::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDerivedLayerParam_FromoaDerivedLayerParam(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerParam::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDerivedLayerParam::onPreModify(oaDerivedLayerParam* p1,oaDerivedLayerParamModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerParam::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDerivedLayerParam_FromoaDerivedLayerParam(p1));
    PyTuple_SetItem(args,1,PyoaDerivedLayerParamModTypeEnum_FromoaDerivedLayerParamModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerParam::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDerivedLayerParam_doc[] = 
"Class: oaObserver_oaDerivedLayerParam\n"
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
"    Calls: oaObserver_oaDerivedLayerParam(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaDerivedLayerParam||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDerivedLayerParam\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaDerivedLayerParam(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaDerivedLayerParam||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDerivedLayerParam\n"
"  Paramegers: (oaObserver_oaDerivedLayerParam)\n"
"    Calls: (const oaObserver_oaDerivedLayerParam&)\n"
"    Signature: oaObserver_oaDerivedLayerParam||cref-oaObserver_oaDerivedLayerParam,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaDerivedLayerParam_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaDerivedLayerParam",
    sizeof(PyoaObserver_oaDerivedLayerParamObject),
    0,
    (destructor)oaObserver_oaDerivedLayerParam_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaDerivedLayerParam_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaDerivedLayerParam_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaDerivedLayerParam_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaDerivedLayerParam_oaDerivedLayerParamModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaDerivedLayerParam_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaDerivedLayerParam_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaDerivedLayerParam_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaDerivedLayerParam\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaDerivedLayerParam",
           (PyObject*)(&PyoaObserver_oaDerivedLayerParam_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaDerivedLayerParam\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaDerivedLayerParamDef
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDerivedLayerParamDef_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaDerivedLayerParamDef_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaDerivedLayerParamDefObject* self = (PyoaObserver_oaDerivedLayerParamDefObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaDerivedLayerParamDef(p1.Data());
            }
            else {
                pyv_oaObserver_oaDerivedLayerParamDef* p=new pyv_oaObserver_oaDerivedLayerParamDef(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaDerivedLayerParamDef(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaDerivedLayerParamDef* p=new pyv_oaObserver_oaDerivedLayerParamDef(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaDerivedLayerParamDef, Choices are:\n"
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
oaObserver_oaDerivedLayerParamDef_tp_dealloc(PyoaObserver_oaDerivedLayerParamDefObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaDerivedLayerParamDef*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDerivedLayerParamDef_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaDerivedLayerParamDef value;
    int convert_status=PyoaObserver_oaDerivedLayerParamDef_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[55];
    sprintf(buffer,"<oaObserver_oaDerivedLayerParamDef::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaDerivedLayerParamDef_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaDerivedLayerParamDef v1;
    PyParamoaObserver_oaDerivedLayerParamDef v2;
    int convert_status1=PyoaObserver_oaDerivedLayerParamDef_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaDerivedLayerParamDef_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaDerivedLayerParamDef_Convert(PyObject* ob,PyParamoaObserver_oaDerivedLayerParamDef* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaDerivedLayerParamDef_Check(ob)) {
        result->SetData( (oaObserver_oaDerivedLayerParamDef*) ((PyoaObserver_oaDerivedLayerParamDefObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaDerivedLayerParamDef Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaDerivedLayerParamDef_FromoaObserver_oaDerivedLayerParamDef(oaObserver_oaDerivedLayerParamDef* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaDerivedLayerParamDef_Type.tp_alloc(&PyoaObserver_oaDerivedLayerParamDef_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaDerivedLayerParamDefObject* self = (PyoaObserver_oaDerivedLayerParamDefObject*)bself;
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
pyv_oaObserver_oaDerivedLayerParamDef::pyv_oaObserver_oaDerivedLayerParamDef(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaDerivedLayerParamDef(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDerivedLayerParamDef::pyv_oaObserver_oaDerivedLayerParamDef(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaDerivedLayerParamDef(p1,p2)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDerivedLayerParamDef::onConflict(const oaString& p1,oaType p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onConflict");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerParamDef::onConflict was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaString_FromoaString(p1));
    PyTuple_SetItem(args,1,PyoaType_FromoaType(&p2,1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerParamDef::onConflict had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDerivedLayerParamDef::onPostCreate(oaDerivedLayerParamDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerParamDef::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDerivedLayerParamDef_FromoaDerivedLayerParamDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerParamDef::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDerivedLayerParamDef::onPreDestroy(oaDerivedLayerParamDef* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerParamDef::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDerivedLayerParamDef_FromoaDerivedLayerParamDef(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDerivedLayerParamDef::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDerivedLayerParamDef_onConflict_doc[] = 
"Class: oaObserver_oaDerivedLayerParamDef, Function: onConflict\n"
"  Paramegers: (oaString,oaType)\n"
"    Calls: virtual void onConflict(const oaString& name,oaType valueType)\n"
"    Signature: onConflict|void-void|cref-oaString,simple-oaType,\n"
"    This function is called if an on-disk oaDerivedLayerParamDef conflicts with an existing oaDerivedLayerParamDef definition. Note that that all data associated with the conflicting definition, including the definition itself, will be destroyed following this notification.\n"
"    name\n"
"    name of the conflicting oaDerivedLayerParamDef\n"
"    valueType\n"
"    type of the conflicting oaDerivedLayerParamDef\n"
;

static PyObject*
oaObserver_oaDerivedLayerParamDef_onConflict(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDerivedLayerParamDef data;
    int convert_status=PyoaObserver_oaDerivedLayerParamDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDerivedLayerParamDefObject* self=(PyoaObserver_oaDerivedLayerParamDefObject*)ob;

    PyParamoaString p1;
    PyParamoaType p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaString_Convert,&p1,
          &PyoaType_Convert,&p2)) {
        data.DataCall()->oaObserver_oaDerivedLayerParamDef::onConflict(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDerivedLayerParamDef_onPostCreate_doc[] = 
"Class: oaObserver_oaDerivedLayerParamDef, Function: onPostCreate\n"
"  Paramegers: (oaDerivedLayerParamDef)\n"
"    Calls: virtual void onPostCreate(oaDerivedLayerParamDef* def)\n"
"    Signature: onPostCreate|void-void|ptr-oaDerivedLayerParamDef,\n"
"    This function is called after an oaDerivedLayerParamDef is created. The application's derived observer class should implement this function to receive notification after an oaDerivedLayerParamDef is created.\n"
"    def\n"
"    pointer to the created oaDerivedLayerParamDef object\n"
;

static PyObject*
oaObserver_oaDerivedLayerParamDef_onPostCreate(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDerivedLayerParamDef data;
    int convert_status=PyoaObserver_oaDerivedLayerParamDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDerivedLayerParamDefObject* self=(PyoaObserver_oaDerivedLayerParamDefObject*)ob;

    PyParamoaDerivedLayerParamDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDerivedLayerParamDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDerivedLayerParamDef::onPostCreate(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDerivedLayerParamDef_onPreDestroy_doc[] = 
"Class: oaObserver_oaDerivedLayerParamDef, Function: onPreDestroy\n"
"  Paramegers: (oaDerivedLayerParamDef)\n"
"    Calls: virtual void onPreDestroy(oaDerivedLayerParamDef* def)\n"
"    Signature: onPreDestroy|void-void|ptr-oaDerivedLayerParamDef,\n"
"    This function is called before an oaDerivedLayerParamDef is destroyed. The application's derived observer class should implement this function to receive notification when an oaDerivedLayerParamDef is about to be destroyed.\n"
"    def\n"
"    pointer to the oaDerivedLayerParamDef object about to be destroyed\n"
;

static PyObject*
oaObserver_oaDerivedLayerParamDef_onPreDestroy(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDerivedLayerParamDef data;
    int convert_status=PyoaObserver_oaDerivedLayerParamDef_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDerivedLayerParamDefObject* self=(PyoaObserver_oaDerivedLayerParamDefObject*)ob;

    PyParamoaDerivedLayerParamDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDerivedLayerParamDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDerivedLayerParamDef::onPreDestroy(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaObserver_oaDerivedLayerParamDef_assign_doc[] = 
"Class: oaObserver_oaDerivedLayerParamDef, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaObserver_oaDerivedLayerParamDef_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaObserver_oaDerivedLayerParamDef data;
  int convert_status=PyoaObserver_oaDerivedLayerParamDef_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaObserver_oaDerivedLayerParamDef p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaObserver_oaDerivedLayerParamDef_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaObserver_oaDerivedLayerParamDef_methodlist[] = {
    {"onConflict",(PyCFunction)oaObserver_oaDerivedLayerParamDef_onConflict,METH_VARARGS,oaObserver_oaDerivedLayerParamDef_onConflict_doc},
    {"onPostCreate",(PyCFunction)oaObserver_oaDerivedLayerParamDef_onPostCreate,METH_VARARGS,oaObserver_oaDerivedLayerParamDef_onPostCreate_doc},
    {"onPreDestroy",(PyCFunction)oaObserver_oaDerivedLayerParamDef_onPreDestroy,METH_VARARGS,oaObserver_oaDerivedLayerParamDef_onPreDestroy_doc},
    {"assign",(PyCFunction)oaObserver_oaDerivedLayerParamDef_tp_assign,METH_VARARGS,oaObserver_oaDerivedLayerParamDef_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDerivedLayerParamDef_doc[] = 
"Class: oaObserver_oaDerivedLayerParamDef\n"
"  This base template class can be used to derive observers for oaDerivedLayerParamDef objects. It supports postCreate, preDestroy, and onConflict event notifications.\n"
"  See oaObserver for information on using OpenAccess observer template classes to derive and instantiate observers in an application.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaDerivedLayerParamDef(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaDerivedLayerParamDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDerivedLayerParamDef\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaDerivedLayerParamDef(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaDerivedLayerParamDef||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDerivedLayerParamDef\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaDerivedLayerParamDef_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaDerivedLayerParamDef",
    sizeof(PyoaObserver_oaDerivedLayerParamDefObject),
    0,
    (destructor)oaObserver_oaDerivedLayerParamDef_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaDerivedLayerParamDef_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaDerivedLayerParamDef_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaDerivedLayerParamDef_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaObserver_oaDerivedLayerParamDef_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseObserver_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaDerivedLayerParamDef_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDerivedLayerParamDef_static_hasObservers_doc[] = 
"Class: oaObserver_oaDerivedLayerParamDef, Function: hasObservers\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean hasObservers()\n"
"    Signature: hasObservers|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns true if any observers for this type are active.\n"
;

static PyObject*
oaObserver_oaDerivedLayerParamDef_static_hasObservers(PyObject* ob, PyObject *args)
{
  try {
    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result= (oaObserver_oaDerivedLayerParamDef::hasObservers());
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
static char oaObserver_oaDerivedLayerParamDef_static_notifyOnConflictObservers_doc[] = 
"Class: oaObserver_oaDerivedLayerParamDef, Function: notifyOnConflictObservers\n"
"  Paramegers: (oaString,oaType)\n"
"    Calls: void notifyOnConflictObservers(const oaString& name,oaType valueType)\n"
"    Signature: notifyOnConflictObservers|void-void|cref-oaString,simple-oaType,\n"
"    Function notifyOnConflictObservers\n"
;

static PyObject*
oaObserver_oaDerivedLayerParamDef_static_notifyOnConflictObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString p1;
    PyParamoaType p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaString_Convert,&p1,
          &PyoaType_Convert,&p2)) {
        oaObserver_oaDerivedLayerParamDef::notifyOnConflictObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDerivedLayerParamDef_static_notifyPostCreateObservers_doc[] = 
"Class: oaObserver_oaDerivedLayerParamDef, Function: notifyPostCreateObservers\n"
"  Paramegers: (oaDerivedLayerParamDef)\n"
"    Calls: void notifyPostCreateObservers(oaDerivedLayerParamDef* def)\n"
"    Signature: notifyPostCreateObservers|void-void|ptr-oaDerivedLayerParamDef,\n"
"    Function notifyPostCreateObservers\n"
;

static PyObject*
oaObserver_oaDerivedLayerParamDef_static_notifyPostCreateObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDerivedLayerParamDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDerivedLayerParamDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDerivedLayerParamDef::notifyPostCreateObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDerivedLayerParamDef_static_notifyPreDestroyObservers_doc[] = 
"Class: oaObserver_oaDerivedLayerParamDef, Function: notifyPreDestroyObservers\n"
"  Paramegers: (oaDerivedLayerParamDef)\n"
"    Calls: void notifyPreDestroyObservers(oaDerivedLayerParamDef* def)\n"
"    Signature: notifyPreDestroyObservers|void-void|ptr-oaDerivedLayerParamDef,\n"
"    Function notifyPreDestroyObservers\n"
;

static PyObject*
oaObserver_oaDerivedLayerParamDef_static_notifyPreDestroyObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDerivedLayerParamDef p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDerivedLayerParamDef_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDerivedLayerParamDef::notifyPreDestroyObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaObserver_oaDerivedLayerParamDef_staticmethodlist[] = {
    {"static_hasObservers",(PyCFunction)oaObserver_oaDerivedLayerParamDef_static_hasObservers,METH_VARARGS,oaObserver_oaDerivedLayerParamDef_static_hasObservers_doc},
    {"static_notifyOnConflictObservers",(PyCFunction)oaObserver_oaDerivedLayerParamDef_static_notifyOnConflictObservers,METH_VARARGS,oaObserver_oaDerivedLayerParamDef_static_notifyOnConflictObservers_doc},
    {"static_notifyPostCreateObservers",(PyCFunction)oaObserver_oaDerivedLayerParamDef_static_notifyPostCreateObservers,METH_VARARGS,oaObserver_oaDerivedLayerParamDef_static_notifyPostCreateObservers_doc},
    {"static_notifyPreDestroyObservers",(PyCFunction)oaObserver_oaDerivedLayerParamDef_static_notifyPreDestroyObservers,METH_VARARGS,oaObserver_oaDerivedLayerParamDef_static_notifyPreDestroyObservers_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaDerivedLayerParamDef_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaDerivedLayerParamDef_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaDerivedLayerParamDef\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaDerivedLayerParamDef",
           (PyObject*)(&PyoaObserver_oaDerivedLayerParamDef_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaDerivedLayerParamDef\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaObserver_oaDerivedLayerParamDef_Type.tp_dict;
    for(method=oaObserver_oaDerivedLayerParamDef_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaObserver_oaDesign
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDesign_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaDesign_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaDesignObject* self = (PyoaObserver_oaDesignObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaDesign(p1.Data());
            }
            else {
                pyv_oaObserver_oaDesign* p=new pyv_oaObserver_oaDesign(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaDesign(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaDesign* p=new pyv_oaObserver_oaDesign(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaDesign, Choices are:\n"
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
oaObserver_oaDesign_tp_dealloc(PyoaObserver_oaDesignObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaDesign*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDesign_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaDesign value;
    int convert_status=PyoaObserver_oaDesign_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaObserver_oaDesign::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaDesign_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaDesign v1;
    PyParamoaObserver_oaDesign v2;
    int convert_status1=PyoaObserver_oaDesign_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaDesign_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaDesign_Convert(PyObject* ob,PyParamoaObserver_oaDesign* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaDesign_Check(ob)) {
        result->SetData( (oaObserver_oaDesign*) ((PyoaObserver_oaDesignObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaDesign Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaDesign_FromoaObserver_oaDesign(oaObserver_oaDesign* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaDesign_Type.tp_alloc(&PyoaObserver_oaDesign_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaDesignObject* self = (PyoaObserver_oaDesignObject*)bself;
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
pyv_oaObserver_oaDesign::pyv_oaObserver_oaDesign(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaDesign(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDesign::pyv_oaObserver_oaDesign(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaDesign(p1,p2)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDesign::onFirstOpen(oaDesign* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onFirstOpen");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onFirstOpen was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDesign_FromoaDesign(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onFirstOpen had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDesign::onPostModify(oaDesign* p1,oaDesignModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDesign_FromoaDesign(p1));
    PyTuple_SetItem(args,1,PyoaDesignModTypeEnum_FromoaDesignModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDesign::onPostReopen(oaDesign* p1,oaChar p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostReopen");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPostReopen was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDesign_FromoaDesign(p1));
    PyTuple_SetItem(args,1,PyoaChar_FromoaChar(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPostReopen had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDesign::onPostSave(oaDesign* p1,oaBoolean p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostSave");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPostSave was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDesign_FromoaDesign(p1));
    PyTuple_SetItem(args,1,PyoaBoolean_FromoaBoolean(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPostSave had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDesign::onPostSaveAs(oaDesign* p1,const oaScalarName& p2,const oaScalarName& p3,const oaScalarName& p4,oaBoolean p5)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostSaveAs");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPostSaveAs was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(5);
    PyTuple_SetItem(args,0,PyoaDesign_FromoaDesign(p1));
    PyTuple_SetItem(args,1,PyoaScalarName_FromoaScalarName((oaScalarName*)(&p2),1));
    PyTuple_SetItem(args,2,PyoaScalarName_FromoaScalarName((oaScalarName*)(&p3),1));
    PyTuple_SetItem(args,3,PyoaScalarName_FromoaScalarName((oaScalarName*)(&p4),1));
    PyTuple_SetItem(args,4,PyoaBoolean_FromoaBoolean(p5));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPostSaveAs had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDesign::onPreModify(oaDesign* p1,oaDesignModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDesign_FromoaDesign(p1));
    PyTuple_SetItem(args,1,PyoaDesignModTypeEnum_FromoaDesignModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPreModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDesign::onPreReopen(oaDesign* p1,oaChar p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreReopen");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPreReopen was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDesign_FromoaDesign(p1));
    PyTuple_SetItem(args,1,PyoaChar_FromoaChar(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPreReopen had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDesign::onPreSave(oaDesign* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreSave");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPreSave was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDesign_FromoaDesign(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPreSave had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDesign::onPreSaveAs(oaDesign* p1,const oaScalarName& p2,const oaScalarName& p3,const oaScalarName& p4)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreSaveAs");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPreSaveAs was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(4);
    PyTuple_SetItem(args,0,PyoaDesign_FromoaDesign(p1));
    PyTuple_SetItem(args,1,PyoaScalarName_FromoaScalarName((oaScalarName*)(&p2),1));
    PyTuple_SetItem(args,2,PyoaScalarName_FromoaScalarName((oaScalarName*)(&p3),1));
    PyTuple_SetItem(args,3,PyoaScalarName_FromoaScalarName((oaScalarName*)(&p4),1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPreSaveAs had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDesign::onPurge(oaDesign* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPurge");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPurge was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDesign_FromoaDesign(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onPurge had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDesign::onTruncate(oaDesign* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onTruncate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onTruncate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDesign_FromoaDesign(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDesign::onTruncate had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
// FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDesign_onFirstOpen_doc[] = 
"Class: oaObserver_oaDesign, Function: onFirstOpen\n"
"  Paramegers: (oaDesign)\n"
"    Calls: virtual void onFirstOpen(oaDesign* design)\n"
"    Signature: onFirstOpen|void-void|ptr-oaDesign,\n"
"    onFirstOpen\n"
"    This function is called when a design is first opened. The application's derived class should implement this function to receive notification when an oaDesign object has been opened.\n"
"    design\n"
"    A pointer to the newly-opened design\n"
;

static PyObject*
oaObserver_oaDesign_onFirstOpen(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDesign data;
    int convert_status=PyoaObserver_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDesignObject* self=(PyoaObserver_oaDesignObject*)ob;

    PyParamoaDesign p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesign_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDesign::onFirstOpen(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_onPostModify_doc[] = 
"Class: oaObserver_oaDesign, Function: onPostModify\n"
"  Paramegers: (oaDesign,oaDesignModTypeEnum)\n"
"    Calls: virtual void onPostModify(oaDesign* design,oaDesignModTypeEnum modType)\n"
"    Signature: onPostModify|void-void|ptr-oaDesign,simple-oaDesignModTypeEnum,\n"
"    onPostModify\n"
"    This function is called after an oaDesign object has been modified. The application's derived class should implement this function to receive notification after an oaDesign object has been modified.\n"
"    design\n"
"    A pointer to the modified oaDesign object\n"
"    modType\n"
"    The type of modification that was made\n"
;

static PyObject*
oaObserver_oaDesign_onPostModify(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDesign data;
    int convert_status=PyoaObserver_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDesignObject* self=(PyoaObserver_oaDesignObject*)ob;

    PyParamoaDesign p1;
    PyParamoaDesignModTypeEnum p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDesign_Convert,&p1,
          &PyoaDesignModTypeEnum_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDesign::onPostModify(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_onPostReopen_doc[] = 
"Class: oaObserver_oaDesign, Function: onPostReopen\n"
"  Paramegers: (oaDesign,oaChar)\n"
"    Calls: virtual void onPostReopen(oaDesign* design,oaChar oldMode)\n"
"    Signature: onPostReopen|void-void|ptr-oaDesign,simple-oaChar,\n"
"    onPostReopen\n"
"    This function is called just after a design is reopened using a new access mode. The application's derived class should implement this function to receive notification when an oaDesign object has been reopened in a new access mode.\n"
"    design\n"
"    A pointer to the design with the mode change\n"
"    oldMode\n"
"    The mode with which the design was previously opened\n"
;

static PyObject*
oaObserver_oaDesign_onPostReopen(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDesign data;
    int convert_status=PyoaObserver_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDesignObject* self=(PyoaObserver_oaDesignObject*)ob;

    PyParamoaDesign p1;
    PyParamoaChar p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDesign_Convert,&p1,
          &PyoaChar_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDesign::onPostReopen(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_onPostSave_doc[] = 
"Class: oaObserver_oaDesign, Function: onPostSave\n"
"  Paramegers: (oaDesign,oaBoolean)\n"
"    Calls: virtual void onPostSave(oaDesign* design,oaBoolean succeeded)\n"
"    Signature: onPostSave|void-void|ptr-oaDesign,simple-oaBoolean,\n"
"    onPostSave\n"
"    This function is called after an attempt to save a design to disk. The application's derived class should implement this function to receive notification when a save has been attempted on an oaDesign object.\n"
"    design\n"
"    A pointer to the saved design\n"
"    succeeded\n"
"    A boolean that indicates whether the save was successful\n"
;

static PyObject*
oaObserver_oaDesign_onPostSave(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDesign data;
    int convert_status=PyoaObserver_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDesignObject* self=(PyoaObserver_oaDesignObject*)ob;

    PyParamoaDesign p1;
    PyParamoaBoolean p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDesign_Convert,&p1,
          &PyoaBoolean_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDesign::onPostSave(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_onPostSaveAs_doc[] = 
"Class: oaObserver_oaDesign, Function: onPostSaveAs\n"
"  Paramegers: (oaDesign,oaScalarName,oaScalarName,oaScalarName,oaBoolean)\n"
"    Calls: virtual void onPostSaveAs(oaDesign* design,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName,oaBoolean succeeded)\n"
"    Signature: onPostSaveAs|void-void|ptr-oaDesign,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,simple-oaBoolean,\n"
"    onPostSaveAs\n"
"    This function is called after an attempt has been made to save a design to disk under user-specified (usually new) library, cell and view names (through an oaDesign::saveAs call). The application's derived class should implement this function to receive notification when an attempt has been made to save an oaDesign object under user-specified library/cell/view names.\n"
"    design\n"
"    A pointer to the saved design\n"
"    libName\n"
"    The library name of the saved design\n"
"    cellName\n"
"    The cell name of the saved design\n"
"    viewName\n"
"    The view name of the saved design\n"
"    succeeded\n"
"    a boolean that indicates whether the save was successful\n"
;

static PyObject*
oaObserver_oaDesign_onPostSaveAs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDesign data;
    int convert_status=PyoaObserver_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDesignObject* self=(PyoaObserver_oaDesignObject*)ob;

    PyParamoaDesign p1;
    PyParamoaScalarName p2;
    PyParamoaScalarName p3;
    PyParamoaScalarName p4;
    PyParamoaBoolean p5;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&",
          &PyoaDesign_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaScalarName_Convert,&p3,
          &PyoaScalarName_Convert,&p4,
          &PyoaBoolean_Convert,&p5)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDesign::onPostSaveAs(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_onPreModify_doc[] = 
"Class: oaObserver_oaDesign, Function: onPreModify\n"
"  Paramegers: (oaDesign,oaDesignModTypeEnum)\n"
"    Calls: virtual void onPreModify(oaDesign* design,oaDesignModTypeEnum modType)\n"
"    Signature: onPreModify|void-void|ptr-oaDesign,simple-oaDesignModTypeEnum,\n"
"    onPreModify\n"
"    This function is called before an oaDesign object is modified. The application's derived class should implement this function to receive notification when an oaDesign object is about to be modified.\n"
"    design\n"
"    A pointer to the oaDesign object to be modified\n"
"    modType\n"
"    The type of modification to be made\n"
;

static PyObject*
oaObserver_oaDesign_onPreModify(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDesign data;
    int convert_status=PyoaObserver_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDesignObject* self=(PyoaObserver_oaDesignObject*)ob;

    PyParamoaDesign p1;
    PyParamoaDesignModTypeEnum p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDesign_Convert,&p1,
          &PyoaDesignModTypeEnum_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDesign::onPreModify(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_onPreReopen_doc[] = 
"Class: oaObserver_oaDesign, Function: onPreReopen\n"
"  Paramegers: (oaDesign,oaChar)\n"
"    Calls: virtual void onPreReopen(oaDesign* design,oaChar newMode)\n"
"    Signature: onPreReopen|void-void|ptr-oaDesign,simple-oaChar,\n"
"    onPreReopen\n"
"    This function is called before a design is reopened using a different access mode. The application's derived class should implement this function to receive notification when an oaDesign object is about to be reopened.\n"
"    design\n"
"    A pointer to the design with the mode change\n"
"    newMode\n"
"    The new mode in which the design will be reopened\n"
;

static PyObject*
oaObserver_oaDesign_onPreReopen(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDesign data;
    int convert_status=PyoaObserver_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDesignObject* self=(PyoaObserver_oaDesignObject*)ob;

    PyParamoaDesign p1;
    PyParamoaChar p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDesign_Convert,&p1,
          &PyoaChar_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDesign::onPreReopen(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_onPreSave_doc[] = 
"Class: oaObserver_oaDesign, Function: onPreSave\n"
"  Paramegers: (oaDesign)\n"
"    Calls: virtual void onPreSave(oaDesign* design)\n"
"    Signature: onPreSave|void-void|ptr-oaDesign,\n"
"    onPreSave\n"
"    This function is called just before a design is saved to the disk. The application's derived class should implement this function to receive notification when an oaDesign object is about to be saved.\n"
"    design\n"
"    A pointer to the design about to be saved\n"
;

static PyObject*
oaObserver_oaDesign_onPreSave(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDesign data;
    int convert_status=PyoaObserver_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDesignObject* self=(PyoaObserver_oaDesignObject*)ob;

    PyParamoaDesign p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesign_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDesign::onPreSave(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_onPreSaveAs_doc[] = 
"Class: oaObserver_oaDesign, Function: onPreSaveAs\n"
"  Paramegers: (oaDesign,oaScalarName,oaScalarName,oaScalarName)\n"
"    Calls: virtual void onPreSaveAs(oaDesign* design,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName)\n"
"    Signature: onPreSaveAs|void-void|ptr-oaDesign,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,\n"
"    onPreSaveAs\n"
"    This function is called just before an attempt to save a design to disk under user-specified (usually new) library, cell and view names (through an oaDesign::saveAs call). The application's derived class should implement this function to receive notification when an attempt is about to be made to save an oaDesign object under user-specified library/cell/view names.\n"
"    design\n"
"    A pointer to the design about to be saved\n"
"    libName\n"
"    The library name of the design to be saved\n"
"    cellName\n"
"    The cell name of the design to be saved\n"
"    viewName\n"
"    The view name of the design to be saved\n"
;

static PyObject*
oaObserver_oaDesign_onPreSaveAs(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDesign data;
    int convert_status=PyoaObserver_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDesignObject* self=(PyoaObserver_oaDesignObject*)ob;

    PyParamoaDesign p1;
    PyParamoaScalarName p2;
    PyParamoaScalarName p3;
    PyParamoaScalarName p4;
    if (PyArg_ParseTuple(args,"O&O&O&O&",
          &PyoaDesign_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaScalarName_Convert,&p3,
          &PyoaScalarName_Convert,&p4)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDesign::onPreSaveAs(p1.Data(),p2.Data(),p3.Data(),p4.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_onPurge_doc[] = 
"Class: oaObserver_oaDesign, Function: onPurge\n"
"  Paramegers: (oaDesign)\n"
"    Calls: virtual void onPurge(oaDesign* design)\n"
"    Signature: onPurge|void-void|ptr-oaDesign,\n"
"    onPurge\n"
"    This function is called when a design is about to be purged from memory. The application's derived class should implement this function to receive notification when an oaDesign object is about to be purged.\n"
"    design\n"
"    A pointer to the design about to be purged\n"
;

static PyObject*
oaObserver_oaDesign_onPurge(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDesign data;
    int convert_status=PyoaObserver_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDesignObject* self=(PyoaObserver_oaDesignObject*)ob;

    PyParamoaDesign p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesign_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDesign::onPurge(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_onTruncate_doc[] = 
"Class: oaObserver_oaDesign, Function: onTruncate\n"
"  Paramegers: (oaDesign)\n"
"    Calls: virtual void onTruncate(oaDesign* design)\n"
"    Signature: onTruncate|void-void|ptr-oaDesign,\n"
"    onTruncate\n"
"    This function is called just before a design is truncated (for example, after all contents are removed). The application's derived class should implement this function to receive notification when an oaDesign object is about to be truncated.\n"
"    design\n"
"    A pointer to the design about to be truncated\n"
;

static PyObject*
oaObserver_oaDesign_onTruncate(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaObserver_oaDesign data;
    int convert_status=PyoaObserver_oaDesign_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaObserver_oaDesignObject* self=(PyoaObserver_oaDesignObject*)ob;

    PyParamoaDesign p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesign_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        data.DataCall()->oaObserver_oaDesign::onTruncate(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

static char oaObserver_oaDesign_assign_doc[] = 
"Class: oaObserver_oaDesign, Function: set\n"
"  Paramegers: (oaDouble)\n"
"    This function sets the current value.\n"
;

static PyObject*
oaObserver_oaDesign_tp_assign(PyObject* ob, PyObject *args)
{
  PyParamoaObserver_oaDesign data;
  int convert_status=PyoaObserver_oaDesign_Convert(ob,&data);
  assert(convert_status!=0);
  try {
    PyParamoaObserver_oaDesign p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaObserver_oaDesign_Convert,&p1)) {
        data.Data()=p1.Data();
        Py_INCREF(ob);
        return ob;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ------------------------------------------------------------------
//  Function Methods Table:
// ------------------------------------------------------------------

static PyMethodDef oaObserver_oaDesign_methodlist[] = {
    {"onFirstOpen",(PyCFunction)oaObserver_oaDesign_onFirstOpen,METH_VARARGS,oaObserver_oaDesign_onFirstOpen_doc},
    {"onPostModify",(PyCFunction)oaObserver_oaDesign_onPostModify,METH_VARARGS,oaObserver_oaDesign_onPostModify_doc},
    {"onPostReopen",(PyCFunction)oaObserver_oaDesign_onPostReopen,METH_VARARGS,oaObserver_oaDesign_onPostReopen_doc},
    {"onPostSave",(PyCFunction)oaObserver_oaDesign_onPostSave,METH_VARARGS,oaObserver_oaDesign_onPostSave_doc},
    {"onPostSaveAs",(PyCFunction)oaObserver_oaDesign_onPostSaveAs,METH_VARARGS,oaObserver_oaDesign_onPostSaveAs_doc},
    {"onPreModify",(PyCFunction)oaObserver_oaDesign_onPreModify,METH_VARARGS,oaObserver_oaDesign_onPreModify_doc},
    {"onPreReopen",(PyCFunction)oaObserver_oaDesign_onPreReopen,METH_VARARGS,oaObserver_oaDesign_onPreReopen_doc},
    {"onPreSave",(PyCFunction)oaObserver_oaDesign_onPreSave,METH_VARARGS,oaObserver_oaDesign_onPreSave_doc},
    {"onPreSaveAs",(PyCFunction)oaObserver_oaDesign_onPreSaveAs,METH_VARARGS,oaObserver_oaDesign_onPreSaveAs_doc},
    {"onPurge",(PyCFunction)oaObserver_oaDesign_onPurge,METH_VARARGS,oaObserver_oaDesign_onPurge_doc},
    {"onTruncate",(PyCFunction)oaObserver_oaDesign_onTruncate,METH_VARARGS,oaObserver_oaDesign_onTruncate_doc},
    {"assign",(PyCFunction)oaObserver_oaDesign_tp_assign,METH_VARARGS,oaObserver_oaDesign_assign_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDesign_doc[] = 
"Class: oaObserver_oaDesign\n"
"  This base template class can be used to derive observers for oaDesign objects. It supports open, purge, preSave, postSave, preSaveAs, postSaveAs, preReopen, postReopen, and truncate event notifications.\n"
"  See oaObserver for information on using Open Access observer template classes to derive and instantiate observers in an application.\n"
"Constructors:\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: oaObserver_oaDesign(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaDesign||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDesign\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaDesign(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaDesign||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDesign\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaDesign_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaDesign",
    sizeof(PyoaObserver_oaDesignObject),
    0,
    (destructor)oaObserver_oaDesign_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaDesign_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaDesign_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaDesign_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    oaObserver_oaDesign_methodlist,	/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaBaseObserver_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaDesign_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
// Static FunctionMethods:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDesign_static_notifyFirstOpenObservers_doc[] = 
"Class: oaObserver_oaDesign, Function: notifyFirstOpenObservers\n"
"  Paramegers: (oaDesign)\n"
"    Calls: void notifyFirstOpenObservers(oaDesign* design)\n"
"    Signature: notifyFirstOpenObservers|void-void|ptr-oaDesign,\n"
"    Function notifyFirstOpenObservers\n"
;

static PyObject*
oaObserver_oaDesign_static_notifyFirstOpenObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDesign p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesign_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDesign::notifyFirstOpenObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_static_notifyPostModifyObservers_doc[] = 
"Class: oaObserver_oaDesign, Function: notifyPostModifyObservers\n"
"  Paramegers: (oaDesign,oaDesignModTypeEnum)\n"
"    Calls: void notifyPostModifyObservers(oaDesign* design,oaDesignModTypeEnum modType)\n"
"    Signature: notifyPostModifyObservers|void-void|ptr-oaDesign,simple-oaDesignModTypeEnum,\n"
"    Function notifyPostModifyObservers\n"
;

static PyObject*
oaObserver_oaDesign_static_notifyPostModifyObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDesign p1;
    PyParamoaDesignModTypeEnum p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDesign_Convert,&p1,
          &PyoaDesignModTypeEnum_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDesign::notifyPostModifyObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_static_notifyPostReopenObservers_doc[] = 
"Class: oaObserver_oaDesign, Function: notifyPostReopenObservers\n"
"  Paramegers: (oaDesign,oaChar)\n"
"    Calls: void notifyPostReopenObservers(oaDesign* design,oaChar oldMode)\n"
"    Signature: notifyPostReopenObservers|void-void|ptr-oaDesign,simple-oaChar,\n"
"    Function notifyPostReopenObservers\n"
;

static PyObject*
oaObserver_oaDesign_static_notifyPostReopenObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDesign p1;
    PyParamoaChar p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDesign_Convert,&p1,
          &PyoaChar_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDesign::notifyPostReopenObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_static_notifyPostSaveAsObservers_doc[] = 
"Class: oaObserver_oaDesign, Function: notifyPostSaveAsObservers\n"
"  Paramegers: (oaDesign,oaScalarName,oaScalarName,oaScalarName,oaBoolean)\n"
"    Calls: void notifyPostSaveAsObservers(oaDesign* design,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName,oaBoolean succeeded)\n"
"    Signature: notifyPostSaveAsObservers|void-void|ptr-oaDesign,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,simple-oaBoolean,\n"
"    Function notifyPostSaveAsObservers\n"
;

static PyObject*
oaObserver_oaDesign_static_notifyPostSaveAsObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDesign p1;
    PyParamoaScalarName p2;
    PyParamoaScalarName p3;
    PyParamoaScalarName p4;
    PyParamoaBoolean p5;
    if (PyArg_ParseTuple(args,"O&O&O&O&O&",
          &PyoaDesign_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaScalarName_Convert,&p3,
          &PyoaScalarName_Convert,&p4,
          &PyoaBoolean_Convert,&p5)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDesign::notifyPostSaveAsObservers(p1.Data(),p2.Data(),p3.Data(),p4.Data(),p5.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_static_notifyPostSaveObservers_doc[] = 
"Class: oaObserver_oaDesign, Function: notifyPostSaveObservers\n"
"  Paramegers: (oaDesign,oaBoolean)\n"
"    Calls: void notifyPostSaveObservers(oaDesign* design,oaBoolean succeeded)\n"
"    Signature: notifyPostSaveObservers|void-void|ptr-oaDesign,simple-oaBoolean,\n"
"    Function notifyPostSaveObservers\n"
;

static PyObject*
oaObserver_oaDesign_static_notifyPostSaveObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDesign p1;
    PyParamoaBoolean p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDesign_Convert,&p1,
          &PyoaBoolean_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDesign::notifyPostSaveObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_static_notifyPreModifyObservers_doc[] = 
"Class: oaObserver_oaDesign, Function: notifyPreModifyObservers\n"
"  Paramegers: (oaDesign,oaDesignModTypeEnum)\n"
"    Calls: void notifyPreModifyObservers(oaDesign* design,oaDesignModTypeEnum modType)\n"
"    Signature: notifyPreModifyObservers|void-void|ptr-oaDesign,simple-oaDesignModTypeEnum,\n"
"    Function notifyPreModifyObservers\n"
;

static PyObject*
oaObserver_oaDesign_static_notifyPreModifyObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDesign p1;
    PyParamoaDesignModTypeEnum p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDesign_Convert,&p1,
          &PyoaDesignModTypeEnum_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDesign::notifyPreModifyObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_static_notifyPreReopenObservers_doc[] = 
"Class: oaObserver_oaDesign, Function: notifyPreReopenObservers\n"
"  Paramegers: (oaDesign,oaChar)\n"
"    Calls: void notifyPreReopenObservers(oaDesign* design,oaChar newMode)\n"
"    Signature: notifyPreReopenObservers|void-void|ptr-oaDesign,simple-oaChar,\n"
"    Function notifyPreReopenObservers\n"
;

static PyObject*
oaObserver_oaDesign_static_notifyPreReopenObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDesign p1;
    PyParamoaChar p2;
    if (PyArg_ParseTuple(args,"O&O&",
          &PyoaDesign_Convert,&p1,
          &PyoaChar_Convert,&p2)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDesign::notifyPreReopenObservers(p1.Data(),p2.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_static_notifyPreSaveAsObservers_doc[] = 
"Class: oaObserver_oaDesign, Function: notifyPreSaveAsObservers\n"
"  Paramegers: (oaDesign,oaScalarName,oaScalarName,oaScalarName)\n"
"    Calls: void notifyPreSaveAsObservers(oaDesign* design,const oaScalarName& libName,const oaScalarName& cellName,const oaScalarName& viewName)\n"
"    Signature: notifyPreSaveAsObservers|void-void|ptr-oaDesign,cref-oaScalarName,cref-oaScalarName,cref-oaScalarName,\n"
"    Function notifyPreSaveAsObservers\n"
;

static PyObject*
oaObserver_oaDesign_static_notifyPreSaveAsObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDesign p1;
    PyParamoaScalarName p2;
    PyParamoaScalarName p3;
    PyParamoaScalarName p4;
    if (PyArg_ParseTuple(args,"O&O&O&O&",
          &PyoaDesign_Convert,&p1,
          &PyoaScalarName_Convert,&p2,
          &PyoaScalarName_Convert,&p3,
          &PyoaScalarName_Convert,&p4)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDesign::notifyPreSaveAsObservers(p1.Data(),p2.Data(),p3.Data(),p4.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_static_notifyPreSaveObservers_doc[] = 
"Class: oaObserver_oaDesign, Function: notifyPreSaveObservers\n"
"  Paramegers: (oaDesign)\n"
"    Calls: void notifyPreSaveObservers(oaDesign* design)\n"
"    Signature: notifyPreSaveObservers|void-void|ptr-oaDesign,\n"
"    Function notifyPreSaveObservers\n"
;

static PyObject*
oaObserver_oaDesign_static_notifyPreSaveObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDesign p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesign_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDesign::notifyPreSaveObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_static_notifyPurgeObservers_doc[] = 
"Class: oaObserver_oaDesign, Function: notifyPurgeObservers\n"
"  Paramegers: (oaDesign)\n"
"    Calls: void notifyPurgeObservers(oaDesign* design)\n"
"    Signature: notifyPurgeObservers|void-void|ptr-oaDesign,\n"
"    Function notifyPurgeObservers\n"
;

static PyObject*
oaObserver_oaDesign_static_notifyPurgeObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDesign p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesign_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDesign::notifyPurgeObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaObserver_oaDesign_static_notifyTruncateObservers_doc[] = 
"Class: oaObserver_oaDesign, Function: notifyTruncateObservers\n"
"  Paramegers: (oaDesign)\n"
"    Calls: void notifyTruncateObservers(oaDesign* design)\n"
"    Signature: notifyTruncateObservers|void-void|ptr-oaDesign,\n"
"    Function notifyTruncateObservers\n"
;

static PyObject*
oaObserver_oaDesign_static_notifyTruncateObservers(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaDesign p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaDesign_Convert,&p1)) {
        if (!PyValidateDbObject(p1.Data(),1)) return NULL;
        oaObserver_oaDesign::notifyTruncateObservers(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static PyMethodDef oaObserver_oaDesign_staticmethodlist[] = {
    {"static_notifyFirstOpenObservers",(PyCFunction)oaObserver_oaDesign_static_notifyFirstOpenObservers,METH_VARARGS,oaObserver_oaDesign_static_notifyFirstOpenObservers_doc},
    {"static_notifyPostModifyObservers",(PyCFunction)oaObserver_oaDesign_static_notifyPostModifyObservers,METH_VARARGS,oaObserver_oaDesign_static_notifyPostModifyObservers_doc},
    {"static_notifyPostReopenObservers",(PyCFunction)oaObserver_oaDesign_static_notifyPostReopenObservers,METH_VARARGS,oaObserver_oaDesign_static_notifyPostReopenObservers_doc},
    {"static_notifyPostSaveAsObservers",(PyCFunction)oaObserver_oaDesign_static_notifyPostSaveAsObservers,METH_VARARGS,oaObserver_oaDesign_static_notifyPostSaveAsObservers_doc},
    {"static_notifyPostSaveObservers",(PyCFunction)oaObserver_oaDesign_static_notifyPostSaveObservers,METH_VARARGS,oaObserver_oaDesign_static_notifyPostSaveObservers_doc},
    {"static_notifyPreModifyObservers",(PyCFunction)oaObserver_oaDesign_static_notifyPreModifyObservers,METH_VARARGS,oaObserver_oaDesign_static_notifyPreModifyObservers_doc},
    {"static_notifyPreReopenObservers",(PyCFunction)oaObserver_oaDesign_static_notifyPreReopenObservers,METH_VARARGS,oaObserver_oaDesign_static_notifyPreReopenObservers_doc},
    {"static_notifyPreSaveAsObservers",(PyCFunction)oaObserver_oaDesign_static_notifyPreSaveAsObservers,METH_VARARGS,oaObserver_oaDesign_static_notifyPreSaveAsObservers_doc},
    {"static_notifyPreSaveObservers",(PyCFunction)oaObserver_oaDesign_static_notifyPreSaveObservers,METH_VARARGS,oaObserver_oaDesign_static_notifyPreSaveObservers_doc},
    {"static_notifyPurgeObservers",(PyCFunction)oaObserver_oaDesign_static_notifyPurgeObservers,METH_VARARGS,oaObserver_oaDesign_static_notifyPurgeObservers_doc},
    {"static_notifyTruncateObservers",(PyCFunction)oaObserver_oaDesign_static_notifyTruncateObservers,METH_VARARGS,oaObserver_oaDesign_static_notifyTruncateObservers_doc},
   {NULL,NULL,0,NULL}
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaDesign_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaDesign_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaDesign\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaDesign",
           (PyObject*)(&PyoaObserver_oaDesign_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaDesign\n");
       return -1;
    }

    PyObject *dict, *value;
    PyMethodDef *method;
    dict=PyoaObserver_oaDesign_Type.tp_dict;
    for(method=oaObserver_oaDesign_staticmethodlist;method->ml_name!=NULL;method++) {
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
// Wrapper Implementation for Class: oaObserver_oaDesignInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDesignInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaDesignInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaDesignInstObject* self = (PyoaObserver_oaDesignInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaDesignInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaDesignInst* p=new pyv_oaObserver_oaDesignInst(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaDesignInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaDesignInst* p=new pyv_oaObserver_oaDesignInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaDesignInst)
    {
        PyParamoaObserver_oaDesignInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaDesignInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaDesignInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaDesignInst* p=new pyv_oaObserver_oaDesignInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaDesignInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaDesignInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaDesignInst_tp_dealloc(PyoaObserver_oaDesignInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaDesignInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDesignInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaDesignInst value;
    int convert_status=PyoaObserver_oaDesignInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaDesignInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaDesignInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaDesignInst v1;
    PyParamoaObserver_oaDesignInst v2;
    int convert_status1=PyoaObserver_oaDesignInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaDesignInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaDesignInst_Convert(PyObject* ob,PyParamoaObserver_oaDesignInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaDesignInst_Check(ob)) {
        result->SetData( (oaObserver_oaDesignInst*) ((PyoaObserver_oaDesignInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaDesignInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaDesignInst_FromoaObserver_oaDesignInst(oaObserver_oaDesignInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaDesignInst_Type.tp_alloc(&PyoaObserver_oaDesignInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaDesignInstObject* self = (PyoaObserver_oaDesignInstObject*)bself;
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
pyv_oaObserver_oaDesignInst::pyv_oaObserver_oaDesignInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaDesignInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDesignInst::pyv_oaObserver_oaDesignInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaDesignInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDesignInst::pyv_oaObserver_oaDesignInst(const oaObserver_oaDesignInst& p)
 : pyob(NULL),
   oaObserver_oaDesignInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDesignInst::onPostCreate(oaDesignInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDesignInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDesignInst_FromoaDesignInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDesignInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDesignInst::onPostModify(oaDesignInst* p1,oaDesignInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDesignInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDesignInst_FromoaDesignInst(p1));
    PyTuple_SetItem(args,1,PyoaDesignInstModTypeEnum_FromoaDesignInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDesignInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDesignInst::onPreDestroy(oaDesignInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDesignInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDesignInst_FromoaDesignInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDesignInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDesignInst::onPreModify(oaDesignInst* p1,oaDesignInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDesignInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDesignInst_FromoaDesignInst(p1));
    PyTuple_SetItem(args,1,PyoaDesignInstModTypeEnum_FromoaDesignInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDesignInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDesignInst_doc[] = 
"Class: oaObserver_oaDesignInst\n"
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
"    Calls: oaObserver_oaDesignInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaDesignInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDesignInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaDesignInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaDesignInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDesignInst\n"
"  Paramegers: (oaObserver_oaDesignInst)\n"
"    Calls: (const oaObserver_oaDesignInst&)\n"
"    Signature: oaObserver_oaDesignInst||cref-oaObserver_oaDesignInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaDesignInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaDesignInst",
    sizeof(PyoaObserver_oaDesignInstObject),
    0,
    (destructor)oaObserver_oaDesignInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaDesignInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaDesignInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaDesignInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaDesignInst_oaDesignInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaDesignInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaDesignInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaDesignInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaDesignInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaDesignInst",
           (PyObject*)(&PyoaObserver_oaDesignInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaDesignInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaDevice
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDevice_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaDevice_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaDeviceObject* self = (PyoaObserver_oaDeviceObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaDevice(p1.Data());
            }
            else {
                pyv_oaObserver_oaDevice* p=new pyv_oaObserver_oaDevice(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaDevice(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaDevice* p=new pyv_oaObserver_oaDevice(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaDevice)
    {
        PyParamoaObserver_oaDevice p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaDevice_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaDevice(p1.Data());
            }
            else {
                pyv_oaObserver_oaDevice* p=new pyv_oaObserver_oaDevice(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaDevice, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaDevice)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaDevice_tp_dealloc(PyoaObserver_oaDeviceObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaDevice*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDevice_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaDevice value;
    int convert_status=PyoaObserver_oaDevice_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaObserver_oaDevice::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaDevice_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaDevice v1;
    PyParamoaObserver_oaDevice v2;
    int convert_status1=PyoaObserver_oaDevice_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaDevice_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaDevice_Convert(PyObject* ob,PyParamoaObserver_oaDevice* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaDevice_Check(ob)) {
        result->SetData( (oaObserver_oaDevice*) ((PyoaObserver_oaDeviceObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaDevice Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaDevice_FromoaObserver_oaDevice(oaObserver_oaDevice* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaDevice_Type.tp_alloc(&PyoaObserver_oaDevice_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaDeviceObject* self = (PyoaObserver_oaDeviceObject*)bself;
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
pyv_oaObserver_oaDevice::pyv_oaObserver_oaDevice(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaDevice(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDevice::pyv_oaObserver_oaDevice(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaDevice(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDevice::pyv_oaObserver_oaDevice(const oaObserver_oaDevice& p)
 : pyob(NULL),
   oaObserver_oaDevice(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDevice::onPostCreate(oaDevice* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDevice::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDevice_FromoaDevice(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDevice::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDevice::onPostModify(oaDevice* p1,oaDeviceModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDevice::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDevice_FromoaDevice(p1));
    PyTuple_SetItem(args,1,PyoaDeviceModTypeEnum_FromoaDeviceModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDevice::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDevice::onPreDestroy(oaDevice* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDevice::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDevice_FromoaDevice(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDevice::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDevice::onPreModify(oaDevice* p1,oaDeviceModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDevice::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDevice_FromoaDevice(p1));
    PyTuple_SetItem(args,1,PyoaDeviceModTypeEnum_FromoaDeviceModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDevice::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDevice_doc[] = 
"Class: oaObserver_oaDevice\n"
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
"    Calls: oaObserver_oaDevice(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaDevice||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDevice\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaDevice(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaDevice||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDevice\n"
"  Paramegers: (oaObserver_oaDevice)\n"
"    Calls: (const oaObserver_oaDevice&)\n"
"    Signature: oaObserver_oaDevice||cref-oaObserver_oaDevice,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaDevice_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaDevice",
    sizeof(PyoaObserver_oaDeviceObject),
    0,
    (destructor)oaObserver_oaDevice_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaDevice_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaDevice_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaDevice_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaDevice_oaDeviceModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaDevice_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaDevice_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaDevice_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaDevice\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaDevice",
           (PyObject*)(&PyoaObserver_oaDevice_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaDevice\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaDiode
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDiode_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaDiode_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaDiodeObject* self = (PyoaObserver_oaDiodeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaDiode(p1.Data());
            }
            else {
                pyv_oaObserver_oaDiode* p=new pyv_oaObserver_oaDiode(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaDiode(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaDiode* p=new pyv_oaObserver_oaDiode(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaDiode)
    {
        PyParamoaObserver_oaDiode p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaDiode_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaDiode(p1.Data());
            }
            else {
                pyv_oaObserver_oaDiode* p=new pyv_oaObserver_oaDiode(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaDiode, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaDiode)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaDiode_tp_dealloc(PyoaObserver_oaDiodeObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaDiode*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDiode_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaDiode value;
    int convert_status=PyoaObserver_oaDiode_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaObserver_oaDiode::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaDiode_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaDiode v1;
    PyParamoaObserver_oaDiode v2;
    int convert_status1=PyoaObserver_oaDiode_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaDiode_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaDiode_Convert(PyObject* ob,PyParamoaObserver_oaDiode* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaDiode_Check(ob)) {
        result->SetData( (oaObserver_oaDiode*) ((PyoaObserver_oaDiodeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaDiode Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaDiode_FromoaObserver_oaDiode(oaObserver_oaDiode* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaDiode_Type.tp_alloc(&PyoaObserver_oaDiode_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaDiodeObject* self = (PyoaObserver_oaDiodeObject*)bself;
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
pyv_oaObserver_oaDiode::pyv_oaObserver_oaDiode(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaDiode(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDiode::pyv_oaObserver_oaDiode(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaDiode(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDiode::pyv_oaObserver_oaDiode(const oaObserver_oaDiode& p)
 : pyob(NULL),
   oaObserver_oaDiode(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDiode::onPostCreate(oaDiode* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDiode::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDiode_FromoaDiode(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDiode::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDiode::onPostModify(oaDiode* p1,oaDeviceModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDiode::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDiode_FromoaDiode(p1));
    PyTuple_SetItem(args,1,PyoaDeviceModTypeEnum_FromoaDeviceModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDiode::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDiode::onPreDestroy(oaDiode* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDiode::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDiode_FromoaDiode(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDiode::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDiode::onPreModify(oaDiode* p1,oaDeviceModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDiode::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDiode_FromoaDiode(p1));
    PyTuple_SetItem(args,1,PyoaDeviceModTypeEnum_FromoaDeviceModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDiode::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDiode_doc[] = 
"Class: oaObserver_oaDiode\n"
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
"    Calls: oaObserver_oaDiode(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaDiode||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDiode\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaDiode(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaDiode||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDiode\n"
"  Paramegers: (oaObserver_oaDiode)\n"
"    Calls: (const oaObserver_oaDiode&)\n"
"    Signature: oaObserver_oaDiode||cref-oaObserver_oaDiode,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaDiode_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaDiode",
    sizeof(PyoaObserver_oaDiodeObject),
    0,
    (destructor)oaObserver_oaDiode_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaDiode_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaDiode_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaDiode_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaDiode_oaDeviceModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaDiode_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaDiode_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaDiode_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaDiode\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaDiode",
           (PyObject*)(&PyoaObserver_oaDiode_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaDiode\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaDonut
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDonut_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaDonut_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaDonutObject* self = (PyoaObserver_oaDonutObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaDonut(p1.Data());
            }
            else {
                pyv_oaObserver_oaDonut* p=new pyv_oaObserver_oaDonut(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaDonut(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaDonut* p=new pyv_oaObserver_oaDonut(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaDonut)
    {
        PyParamoaObserver_oaDonut p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaDonut_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaDonut(p1.Data());
            }
            else {
                pyv_oaObserver_oaDonut* p=new pyv_oaObserver_oaDonut(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaDonut, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaDonut)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaDonut_tp_dealloc(PyoaObserver_oaDonutObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaDonut*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDonut_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaDonut value;
    int convert_status=PyoaObserver_oaDonut_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaObserver_oaDonut::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaDonut_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaDonut v1;
    PyParamoaObserver_oaDonut v2;
    int convert_status1=PyoaObserver_oaDonut_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaDonut_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaDonut_Convert(PyObject* ob,PyParamoaObserver_oaDonut* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaDonut_Check(ob)) {
        result->SetData( (oaObserver_oaDonut*) ((PyoaObserver_oaDonutObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaDonut Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaDonut_FromoaObserver_oaDonut(oaObserver_oaDonut* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaDonut_Type.tp_alloc(&PyoaObserver_oaDonut_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaDonutObject* self = (PyoaObserver_oaDonutObject*)bself;
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
pyv_oaObserver_oaDonut::pyv_oaObserver_oaDonut(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaDonut(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDonut::pyv_oaObserver_oaDonut(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaDonut(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDonut::pyv_oaObserver_oaDonut(const oaObserver_oaDonut& p)
 : pyob(NULL),
   oaObserver_oaDonut(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDonut::onPostCreate(oaDonut* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDonut::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDonut_FromoaDonut(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDonut::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDonut::onPostModify(oaDonut* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDonut::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDonut_FromoaDonut(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDonut::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDonut::onPreDestroy(oaDonut* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDonut::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDonut_FromoaDonut(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDonut::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDonut::onPreModify(oaDonut* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDonut::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDonut_FromoaDonut(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDonut::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDonut_doc[] = 
"Class: oaObserver_oaDonut\n"
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
"    Calls: oaObserver_oaDonut(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaDonut||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDonut\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaDonut(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaDonut||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDonut\n"
"  Paramegers: (oaObserver_oaDonut)\n"
"    Calls: (const oaObserver_oaDonut&)\n"
"    Signature: oaObserver_oaDonut||cref-oaObserver_oaDonut,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaDonut_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaDonut",
    sizeof(PyoaObserver_oaDonutObject),
    0,
    (destructor)oaObserver_oaDonut_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaDonut_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaDonut_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaDonut_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaDonut_oaShapeModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaDonut_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaDonut_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaDonut_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaDonut\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaDonut",
           (PyObject*)(&PyoaObserver_oaDonut_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaDonut\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaDot
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDot_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaDot_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaDotObject* self = (PyoaObserver_oaDotObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaDot(p1.Data());
            }
            else {
                pyv_oaObserver_oaDot* p=new pyv_oaObserver_oaDot(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaDot(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaDot* p=new pyv_oaObserver_oaDot(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaDot)
    {
        PyParamoaObserver_oaDot p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaDot_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaDot(p1.Data());
            }
            else {
                pyv_oaObserver_oaDot* p=new pyv_oaObserver_oaDot(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaDot, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaDot)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaDot_tp_dealloc(PyoaObserver_oaDotObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaDot*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDot_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaDot value;
    int convert_status=PyoaObserver_oaDot_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[38];
    sprintf(buffer,"<oaObserver_oaDot::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaDot_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaDot v1;
    PyParamoaObserver_oaDot v2;
    int convert_status1=PyoaObserver_oaDot_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaDot_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaDot_Convert(PyObject* ob,PyParamoaObserver_oaDot* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaDot_Check(ob)) {
        result->SetData( (oaObserver_oaDot*) ((PyoaObserver_oaDotObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaDot Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaDot_FromoaObserver_oaDot(oaObserver_oaDot* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaDot_Type.tp_alloc(&PyoaObserver_oaDot_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaDotObject* self = (PyoaObserver_oaDotObject*)bself;
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
pyv_oaObserver_oaDot::pyv_oaObserver_oaDot(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaDot(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDot::pyv_oaObserver_oaDot(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaDot(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDot::pyv_oaObserver_oaDot(const oaObserver_oaDot& p)
 : pyob(NULL),
   oaObserver_oaDot(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDot::onPostCreate(oaDot* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDot::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDot_FromoaDot(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDot::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDot::onPostModify(oaDot* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDot::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDot_FromoaDot(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDot::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDot::onPreDestroy(oaDot* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDot::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDot_FromoaDot(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDot::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDot::onPreModify(oaDot* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDot::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDot_FromoaDot(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDot::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDot_doc[] = 
"Class: oaObserver_oaDot\n"
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
"    Calls: oaObserver_oaDot(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaDot||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDot\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaDot(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaDot||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDot\n"
"  Paramegers: (oaObserver_oaDot)\n"
"    Calls: (const oaObserver_oaDot&)\n"
"    Signature: oaObserver_oaDot||cref-oaObserver_oaDot,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaDot_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaDot",
    sizeof(PyoaObserver_oaDotObject),
    0,
    (destructor)oaObserver_oaDot_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaDot_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaDot_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaDot_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaDot_oaShapeModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaDot_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaDot_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaDot_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaDot\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaDot",
           (PyObject*)(&PyoaObserver_oaDot_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaDot\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaDoubleProp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDoubleProp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaDoubleProp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaDoublePropObject* self = (PyoaObserver_oaDoublePropObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaDoubleProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaDoubleProp* p=new pyv_oaObserver_oaDoubleProp(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaDoubleProp(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaDoubleProp* p=new pyv_oaObserver_oaDoubleProp(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaDoubleProp)
    {
        PyParamoaObserver_oaDoubleProp p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaDoubleProp_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaDoubleProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaDoubleProp* p=new pyv_oaObserver_oaDoubleProp(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaDoubleProp, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaDoubleProp)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaDoubleProp_tp_dealloc(PyoaObserver_oaDoublePropObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaDoubleProp*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDoubleProp_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaDoubleProp value;
    int convert_status=PyoaObserver_oaDoubleProp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[45];
    sprintf(buffer,"<oaObserver_oaDoubleProp::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaDoubleProp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaDoubleProp v1;
    PyParamoaObserver_oaDoubleProp v2;
    int convert_status1=PyoaObserver_oaDoubleProp_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaDoubleProp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaDoubleProp_Convert(PyObject* ob,PyParamoaObserver_oaDoubleProp* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaDoubleProp_Check(ob)) {
        result->SetData( (oaObserver_oaDoubleProp*) ((PyoaObserver_oaDoublePropObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaDoubleProp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaDoubleProp_FromoaObserver_oaDoubleProp(oaObserver_oaDoubleProp* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaDoubleProp_Type.tp_alloc(&PyoaObserver_oaDoubleProp_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaDoublePropObject* self = (PyoaObserver_oaDoublePropObject*)bself;
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
pyv_oaObserver_oaDoubleProp::pyv_oaObserver_oaDoubleProp(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaDoubleProp(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDoubleProp::pyv_oaObserver_oaDoubleProp(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaDoubleProp(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDoubleProp::pyv_oaObserver_oaDoubleProp(const oaObserver_oaDoubleProp& p)
 : pyob(NULL),
   oaObserver_oaDoubleProp(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDoubleProp::onPostCreate(oaDoubleProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDoubleProp::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDoubleProp_FromoaDoubleProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDoubleProp::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDoubleProp::onPostModify(oaDoubleProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDoubleProp::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDoubleProp_FromoaDoubleProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDoubleProp::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDoubleProp::onPreDestroy(oaDoubleProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDoubleProp::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDoubleProp_FromoaDoubleProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDoubleProp::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDoubleProp::onPreModify(oaDoubleProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDoubleProp::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDoubleProp_FromoaDoubleProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDoubleProp::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDoubleProp_doc[] = 
"Class: oaObserver_oaDoubleProp\n"
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
"    Calls: oaObserver_oaDoubleProp(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaDoubleProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDoubleProp\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaDoubleProp(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaDoubleProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDoubleProp\n"
"  Paramegers: (oaObserver_oaDoubleProp)\n"
"    Calls: (const oaObserver_oaDoubleProp&)\n"
"    Signature: oaObserver_oaDoubleProp||cref-oaObserver_oaDoubleProp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaDoubleProp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaDoubleProp",
    sizeof(PyoaObserver_oaDoublePropObject),
    0,
    (destructor)oaObserver_oaDoubleProp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaDoubleProp_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaDoubleProp_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaDoubleProp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaDoubleProp_oaPropModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaDoubleProp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaDoubleProp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaDoubleProp_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaDoubleProp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaDoubleProp",
           (PyObject*)(&PyoaObserver_oaDoubleProp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaDoubleProp\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaDoubleRangeProp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDoubleRangeProp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaDoubleRangeProp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaDoubleRangePropObject* self = (PyoaObserver_oaDoubleRangePropObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaDoubleRangeProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaDoubleRangeProp* p=new pyv_oaObserver_oaDoubleRangeProp(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaDoubleRangeProp(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaDoubleRangeProp* p=new pyv_oaObserver_oaDoubleRangeProp(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaDoubleRangeProp)
    {
        PyParamoaObserver_oaDoubleRangeProp p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaDoubleRangeProp_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaDoubleRangeProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaDoubleRangeProp* p=new pyv_oaObserver_oaDoubleRangeProp(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaDoubleRangeProp, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaDoubleRangeProp)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaDoubleRangeProp_tp_dealloc(PyoaObserver_oaDoubleRangePropObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaDoubleRangeProp*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDoubleRangeProp_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaDoubleRangeProp value;
    int convert_status=PyoaObserver_oaDoubleRangeProp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[50];
    sprintf(buffer,"<oaObserver_oaDoubleRangeProp::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaDoubleRangeProp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaDoubleRangeProp v1;
    PyParamoaObserver_oaDoubleRangeProp v2;
    int convert_status1=PyoaObserver_oaDoubleRangeProp_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaDoubleRangeProp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaDoubleRangeProp_Convert(PyObject* ob,PyParamoaObserver_oaDoubleRangeProp* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaDoubleRangeProp_Check(ob)) {
        result->SetData( (oaObserver_oaDoubleRangeProp*) ((PyoaObserver_oaDoubleRangePropObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaDoubleRangeProp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaDoubleRangeProp_FromoaObserver_oaDoubleRangeProp(oaObserver_oaDoubleRangeProp* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaDoubleRangeProp_Type.tp_alloc(&PyoaObserver_oaDoubleRangeProp_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaDoubleRangePropObject* self = (PyoaObserver_oaDoubleRangePropObject*)bself;
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
pyv_oaObserver_oaDoubleRangeProp::pyv_oaObserver_oaDoubleRangeProp(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaDoubleRangeProp(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDoubleRangeProp::pyv_oaObserver_oaDoubleRangeProp(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaDoubleRangeProp(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDoubleRangeProp::pyv_oaObserver_oaDoubleRangeProp(const oaObserver_oaDoubleRangeProp& p)
 : pyob(NULL),
   oaObserver_oaDoubleRangeProp(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDoubleRangeProp::onPostCreate(oaDoubleRangeProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDoubleRangeProp::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDoubleRangeProp_FromoaDoubleRangeProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDoubleRangeProp::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDoubleRangeProp::onPostModify(oaDoubleRangeProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDoubleRangeProp::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDoubleRangeProp_FromoaDoubleRangeProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDoubleRangeProp::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDoubleRangeProp::onPreDestroy(oaDoubleRangeProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDoubleRangeProp::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDoubleRangeProp_FromoaDoubleRangeProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDoubleRangeProp::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDoubleRangeProp::onPreModify(oaDoubleRangeProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDoubleRangeProp::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDoubleRangeProp_FromoaDoubleRangeProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDoubleRangeProp::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDoubleRangeProp_doc[] = 
"Class: oaObserver_oaDoubleRangeProp\n"
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
"    Calls: oaObserver_oaDoubleRangeProp(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaDoubleRangeProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDoubleRangeProp\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaDoubleRangeProp(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaDoubleRangeProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDoubleRangeProp\n"
"  Paramegers: (oaObserver_oaDoubleRangeProp)\n"
"    Calls: (const oaObserver_oaDoubleRangeProp&)\n"
"    Signature: oaObserver_oaDoubleRangeProp||cref-oaObserver_oaDoubleRangeProp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaDoubleRangeProp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaDoubleRangeProp",
    sizeof(PyoaObserver_oaDoubleRangePropObject),
    0,
    (destructor)oaObserver_oaDoubleRangeProp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaDoubleRangeProp_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaDoubleRangeProp_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaDoubleRangeProp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaDoubleRangeProp_oaPropModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaDoubleRangeProp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaDoubleRangeProp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaDoubleRangeProp_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaDoubleRangeProp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaDoubleRangeProp",
           (PyObject*)(&PyoaObserver_oaDoubleRangeProp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaDoubleRangeProp\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaDualInt1DTblValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDualInt1DTblValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaDualInt1DTblValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaDualInt1DTblValueObject* self = (PyoaObserver_oaDualInt1DTblValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaDualInt1DTblValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaDualInt1DTblValue* p=new pyv_oaObserver_oaDualInt1DTblValue(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaDualInt1DTblValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaDualInt1DTblValue* p=new pyv_oaObserver_oaDualInt1DTblValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaDualInt1DTblValue)
    {
        PyParamoaObserver_oaDualInt1DTblValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaDualInt1DTblValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaDualInt1DTblValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaDualInt1DTblValue* p=new pyv_oaObserver_oaDualInt1DTblValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaDualInt1DTblValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaDualInt1DTblValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaDualInt1DTblValue_tp_dealloc(PyoaObserver_oaDualInt1DTblValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaDualInt1DTblValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDualInt1DTblValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaDualInt1DTblValue value;
    int convert_status=PyoaObserver_oaDualInt1DTblValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaObserver_oaDualInt1DTblValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaDualInt1DTblValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaDualInt1DTblValue v1;
    PyParamoaObserver_oaDualInt1DTblValue v2;
    int convert_status1=PyoaObserver_oaDualInt1DTblValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaDualInt1DTblValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaDualInt1DTblValue_Convert(PyObject* ob,PyParamoaObserver_oaDualInt1DTblValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaDualInt1DTblValue_Check(ob)) {
        result->SetData( (oaObserver_oaDualInt1DTblValue*) ((PyoaObserver_oaDualInt1DTblValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaDualInt1DTblValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaDualInt1DTblValue_FromoaObserver_oaDualInt1DTblValue(oaObserver_oaDualInt1DTblValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaDualInt1DTblValue_Type.tp_alloc(&PyoaObserver_oaDualInt1DTblValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaDualInt1DTblValueObject* self = (PyoaObserver_oaDualInt1DTblValueObject*)bself;
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
pyv_oaObserver_oaDualInt1DTblValue::pyv_oaObserver_oaDualInt1DTblValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaDualInt1DTblValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDualInt1DTblValue::pyv_oaObserver_oaDualInt1DTblValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaDualInt1DTblValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDualInt1DTblValue::pyv_oaObserver_oaDualInt1DTblValue(const oaObserver_oaDualInt1DTblValue& p)
 : pyob(NULL),
   oaObserver_oaDualInt1DTblValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDualInt1DTblValue::onPostCreate(oaDualInt1DTblValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDualInt1DTblValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDualInt1DTblValue_FromoaDualInt1DTblValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDualInt1DTblValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDualInt1DTblValue::onPostModify(oaDualInt1DTblValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDualInt1DTblValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDualInt1DTblValue_FromoaDualInt1DTblValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDualInt1DTblValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDualInt1DTblValue::onPreDestroy(oaDualInt1DTblValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDualInt1DTblValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDualInt1DTblValue_FromoaDualInt1DTblValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDualInt1DTblValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDualInt1DTblValue::onPreModify(oaDualInt1DTblValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDualInt1DTblValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDualInt1DTblValue_FromoaDualInt1DTblValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDualInt1DTblValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDualInt1DTblValue_doc[] = 
"Class: oaObserver_oaDualInt1DTblValue\n"
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
"    Calls: oaObserver_oaDualInt1DTblValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaDualInt1DTblValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDualInt1DTblValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaDualInt1DTblValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaDualInt1DTblValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDualInt1DTblValue\n"
"  Paramegers: (oaObserver_oaDualInt1DTblValue)\n"
"    Calls: (const oaObserver_oaDualInt1DTblValue&)\n"
"    Signature: oaObserver_oaDualInt1DTblValue||cref-oaObserver_oaDualInt1DTblValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaDualInt1DTblValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaDualInt1DTblValue",
    sizeof(PyoaObserver_oaDualInt1DTblValueObject),
    0,
    (destructor)oaObserver_oaDualInt1DTblValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaDualInt1DTblValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaDualInt1DTblValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaDualInt1DTblValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaDualInt1DTblValue_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaDualInt1DTblValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaDualInt1DTblValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaDualInt1DTblValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaDualInt1DTblValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaDualInt1DTblValue",
           (PyObject*)(&PyoaObserver_oaDualInt1DTblValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaDualInt1DTblValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaDualIntValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDualIntValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaDualIntValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaDualIntValueObject* self = (PyoaObserver_oaDualIntValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaDualIntValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaDualIntValue* p=new pyv_oaObserver_oaDualIntValue(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaDualIntValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaDualIntValue* p=new pyv_oaObserver_oaDualIntValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaDualIntValue)
    {
        PyParamoaObserver_oaDualIntValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaDualIntValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaDualIntValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaDualIntValue* p=new pyv_oaObserver_oaDualIntValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaDualIntValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaDualIntValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaDualIntValue_tp_dealloc(PyoaObserver_oaDualIntValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaDualIntValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaDualIntValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaDualIntValue value;
    int convert_status=PyoaObserver_oaDualIntValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaDualIntValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaDualIntValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaDualIntValue v1;
    PyParamoaObserver_oaDualIntValue v2;
    int convert_status1=PyoaObserver_oaDualIntValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaDualIntValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaDualIntValue_Convert(PyObject* ob,PyParamoaObserver_oaDualIntValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaDualIntValue_Check(ob)) {
        result->SetData( (oaObserver_oaDualIntValue*) ((PyoaObserver_oaDualIntValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaDualIntValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaDualIntValue_FromoaObserver_oaDualIntValue(oaObserver_oaDualIntValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaDualIntValue_Type.tp_alloc(&PyoaObserver_oaDualIntValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaDualIntValueObject* self = (PyoaObserver_oaDualIntValueObject*)bself;
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
pyv_oaObserver_oaDualIntValue::pyv_oaObserver_oaDualIntValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaDualIntValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDualIntValue::pyv_oaObserver_oaDualIntValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaDualIntValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaDualIntValue::pyv_oaObserver_oaDualIntValue(const oaObserver_oaDualIntValue& p)
 : pyob(NULL),
   oaObserver_oaDualIntValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDualIntValue::onPostCreate(oaDualIntValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDualIntValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDualIntValue_FromoaDualIntValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDualIntValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDualIntValue::onPostModify(oaDualIntValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDualIntValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDualIntValue_FromoaDualIntValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDualIntValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDualIntValue::onPreDestroy(oaDualIntValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDualIntValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaDualIntValue_FromoaDualIntValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDualIntValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaDualIntValue::onPreModify(oaDualIntValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaDualIntValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaDualIntValue_FromoaDualIntValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaDualIntValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaDualIntValue_doc[] = 
"Class: oaObserver_oaDualIntValue\n"
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
"    Calls: oaObserver_oaDualIntValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaDualIntValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDualIntValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaDualIntValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaDualIntValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaDualIntValue\n"
"  Paramegers: (oaObserver_oaDualIntValue)\n"
"    Calls: (const oaObserver_oaDualIntValue&)\n"
"    Signature: oaObserver_oaDualIntValue||cref-oaObserver_oaDualIntValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaDualIntValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaDualIntValue",
    sizeof(PyoaObserver_oaDualIntValueObject),
    0,
    (destructor)oaObserver_oaDualIntValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaDualIntValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaDualIntValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaDualIntValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaDualIntValue_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaDualIntValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaDualIntValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaDualIntValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaDualIntValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaDualIntValue",
           (PyObject*)(&PyoaObserver_oaDualIntValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaDualIntValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaEllipse
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaEllipse_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaEllipse_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaEllipseObject* self = (PyoaObserver_oaEllipseObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaEllipse(p1.Data());
            }
            else {
                pyv_oaObserver_oaEllipse* p=new pyv_oaObserver_oaEllipse(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaEllipse(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaEllipse* p=new pyv_oaObserver_oaEllipse(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaEllipse)
    {
        PyParamoaObserver_oaEllipse p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaEllipse_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaEllipse(p1.Data());
            }
            else {
                pyv_oaObserver_oaEllipse* p=new pyv_oaObserver_oaEllipse(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaEllipse, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaEllipse)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaEllipse_tp_dealloc(PyoaObserver_oaEllipseObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaEllipse*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaEllipse_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaEllipse value;
    int convert_status=PyoaObserver_oaEllipse_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[42];
    sprintf(buffer,"<oaObserver_oaEllipse::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaEllipse_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaEllipse v1;
    PyParamoaObserver_oaEllipse v2;
    int convert_status1=PyoaObserver_oaEllipse_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaEllipse_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaEllipse_Convert(PyObject* ob,PyParamoaObserver_oaEllipse* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaEllipse_Check(ob)) {
        result->SetData( (oaObserver_oaEllipse*) ((PyoaObserver_oaEllipseObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaEllipse Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaEllipse_FromoaObserver_oaEllipse(oaObserver_oaEllipse* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaEllipse_Type.tp_alloc(&PyoaObserver_oaEllipse_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaEllipseObject* self = (PyoaObserver_oaEllipseObject*)bself;
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
pyv_oaObserver_oaEllipse::pyv_oaObserver_oaEllipse(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaEllipse(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaEllipse::pyv_oaObserver_oaEllipse(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaEllipse(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaEllipse::pyv_oaObserver_oaEllipse(const oaObserver_oaEllipse& p)
 : pyob(NULL),
   oaObserver_oaEllipse(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaEllipse::onPostCreate(oaEllipse* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaEllipse::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaEllipse_FromoaEllipse(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaEllipse::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaEllipse::onPostModify(oaEllipse* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaEllipse::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaEllipse_FromoaEllipse(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaEllipse::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaEllipse::onPreDestroy(oaEllipse* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaEllipse::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaEllipse_FromoaEllipse(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaEllipse::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaEllipse::onPreModify(oaEllipse* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaEllipse::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaEllipse_FromoaEllipse(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaEllipse::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaEllipse_doc[] = 
"Class: oaObserver_oaEllipse\n"
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
"    Calls: oaObserver_oaEllipse(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaEllipse||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaEllipse\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaEllipse(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaEllipse||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaEllipse\n"
"  Paramegers: (oaObserver_oaEllipse)\n"
"    Calls: (const oaObserver_oaEllipse&)\n"
"    Signature: oaObserver_oaEllipse||cref-oaObserver_oaEllipse,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaEllipse_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaEllipse",
    sizeof(PyoaObserver_oaEllipseObject),
    0,
    (destructor)oaObserver_oaEllipse_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaEllipse_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaEllipse_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaEllipse_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaEllipse_oaShapeModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaEllipse_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaEllipse_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaEllipse_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaEllipse\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaEllipse",
           (PyObject*)(&PyoaObserver_oaEllipse_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaEllipse\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaElmore
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaElmore_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaElmore_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaElmoreObject* self = (PyoaObserver_oaElmoreObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaElmore(p1.Data());
            }
            else {
                pyv_oaObserver_oaElmore* p=new pyv_oaObserver_oaElmore(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaElmore(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaElmore* p=new pyv_oaObserver_oaElmore(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaElmore)
    {
        PyParamoaObserver_oaElmore p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaElmore_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaElmore(p1.Data());
            }
            else {
                pyv_oaObserver_oaElmore* p=new pyv_oaObserver_oaElmore(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaElmore, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaElmore)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaElmore_tp_dealloc(PyoaObserver_oaElmoreObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaElmore*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaElmore_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaElmore value;
    int convert_status=PyoaObserver_oaElmore_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[41];
    sprintf(buffer,"<oaObserver_oaElmore::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaElmore_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaElmore v1;
    PyParamoaObserver_oaElmore v2;
    int convert_status1=PyoaObserver_oaElmore_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaElmore_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaElmore_Convert(PyObject* ob,PyParamoaObserver_oaElmore* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaElmore_Check(ob)) {
        result->SetData( (oaObserver_oaElmore*) ((PyoaObserver_oaElmoreObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaElmore Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaElmore_FromoaObserver_oaElmore(oaObserver_oaElmore* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaElmore_Type.tp_alloc(&PyoaObserver_oaElmore_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaElmoreObject* self = (PyoaObserver_oaElmoreObject*)bself;
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
pyv_oaObserver_oaElmore::pyv_oaObserver_oaElmore(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaElmore(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaElmore::pyv_oaObserver_oaElmore(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaElmore(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaElmore::pyv_oaObserver_oaElmore(const oaObserver_oaElmore& p)
 : pyob(NULL),
   oaObserver_oaElmore(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaElmore::onPostCreate(oaElmore* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaElmore::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaElmore_FromoaElmore(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaElmore::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaElmore::onPostModify(oaElmore* p1,oaElmoreModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaElmore::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaElmore_FromoaElmore(p1));
    PyTuple_SetItem(args,1,PyoaElmoreModTypeEnum_FromoaElmoreModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaElmore::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaElmore::onPreDestroy(oaElmore* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaElmore::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaElmore_FromoaElmore(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaElmore::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaElmore::onPreModify(oaElmore* p1,oaElmoreModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaElmore::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaElmore_FromoaElmore(p1));
    PyTuple_SetItem(args,1,PyoaElmoreModTypeEnum_FromoaElmoreModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaElmore::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaElmore_doc[] = 
"Class: oaObserver_oaElmore\n"
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
"    Calls: oaObserver_oaElmore(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaElmore||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaElmore\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaElmore(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaElmore||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaElmore\n"
"  Paramegers: (oaObserver_oaElmore)\n"
"    Calls: (const oaObserver_oaElmore&)\n"
"    Signature: oaObserver_oaElmore||cref-oaObserver_oaElmore,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaElmore_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaElmore",
    sizeof(PyoaObserver_oaElmoreObject),
    0,
    (destructor)oaObserver_oaElmore_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaElmore_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaElmore_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaElmore_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaElmore_oaElmoreModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaElmore_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaElmore_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaElmore_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaElmore\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaElmore",
           (PyObject*)(&PyoaObserver_oaElmore_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaElmore\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaEnumProp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaEnumProp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaEnumProp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaEnumPropObject* self = (PyoaObserver_oaEnumPropObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaEnumProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaEnumProp* p=new pyv_oaObserver_oaEnumProp(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaEnumProp(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaEnumProp* p=new pyv_oaObserver_oaEnumProp(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaEnumProp)
    {
        PyParamoaObserver_oaEnumProp p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaEnumProp_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaEnumProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaEnumProp* p=new pyv_oaObserver_oaEnumProp(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaEnumProp, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaEnumProp)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaEnumProp_tp_dealloc(PyoaObserver_oaEnumPropObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaEnumProp*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaEnumProp_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaEnumProp value;
    int convert_status=PyoaObserver_oaEnumProp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaObserver_oaEnumProp::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaEnumProp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaEnumProp v1;
    PyParamoaObserver_oaEnumProp v2;
    int convert_status1=PyoaObserver_oaEnumProp_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaEnumProp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaEnumProp_Convert(PyObject* ob,PyParamoaObserver_oaEnumProp* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaEnumProp_Check(ob)) {
        result->SetData( (oaObserver_oaEnumProp*) ((PyoaObserver_oaEnumPropObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaEnumProp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaEnumProp_FromoaObserver_oaEnumProp(oaObserver_oaEnumProp* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaEnumProp_Type.tp_alloc(&PyoaObserver_oaEnumProp_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaEnumPropObject* self = (PyoaObserver_oaEnumPropObject*)bself;
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
pyv_oaObserver_oaEnumProp::pyv_oaObserver_oaEnumProp(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaEnumProp(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaEnumProp::pyv_oaObserver_oaEnumProp(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaEnumProp(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaEnumProp::pyv_oaObserver_oaEnumProp(const oaObserver_oaEnumProp& p)
 : pyob(NULL),
   oaObserver_oaEnumProp(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaEnumProp::onPostCreate(oaEnumProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaEnumProp::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaEnumProp_FromoaEnumProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaEnumProp::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaEnumProp::onPostModify(oaEnumProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaEnumProp::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaEnumProp_FromoaEnumProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaEnumProp::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaEnumProp::onPreDestroy(oaEnumProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaEnumProp::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaEnumProp_FromoaEnumProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaEnumProp::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaEnumProp::onPreModify(oaEnumProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaEnumProp::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaEnumProp_FromoaEnumProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaEnumProp::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaEnumProp_doc[] = 
"Class: oaObserver_oaEnumProp\n"
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
"    Calls: oaObserver_oaEnumProp(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaEnumProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaEnumProp\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaEnumProp(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaEnumProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaEnumProp\n"
"  Paramegers: (oaObserver_oaEnumProp)\n"
"    Calls: (const oaObserver_oaEnumProp&)\n"
"    Signature: oaObserver_oaEnumProp||cref-oaObserver_oaEnumProp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaEnumProp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaEnumProp",
    sizeof(PyoaObserver_oaEnumPropObject),
    0,
    (destructor)oaObserver_oaEnumProp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaEnumProp_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaEnumProp_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaEnumProp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaEnumProp_oaPropModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaEnumProp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaEnumProp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaEnumProp_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaEnumProp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaEnumProp",
           (PyObject*)(&PyoaObserver_oaEnumProp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaEnumProp\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaEvalText
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaEvalText_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaEvalText_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaEvalTextObject* self = (PyoaObserver_oaEvalTextObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaEvalText(p1.Data());
            }
            else {
                pyv_oaObserver_oaEvalText* p=new pyv_oaObserver_oaEvalText(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaEvalText(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaEvalText* p=new pyv_oaObserver_oaEvalText(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaEvalText)
    {
        PyParamoaObserver_oaEvalText p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaEvalText_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaEvalText(p1.Data());
            }
            else {
                pyv_oaObserver_oaEvalText* p=new pyv_oaObserver_oaEvalText(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaEvalText, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaEvalText)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaEvalText_tp_dealloc(PyoaObserver_oaEvalTextObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaEvalText*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaEvalText_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaEvalText value;
    int convert_status=PyoaObserver_oaEvalText_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaObserver_oaEvalText::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaEvalText_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaEvalText v1;
    PyParamoaObserver_oaEvalText v2;
    int convert_status1=PyoaObserver_oaEvalText_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaEvalText_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaEvalText_Convert(PyObject* ob,PyParamoaObserver_oaEvalText* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaEvalText_Check(ob)) {
        result->SetData( (oaObserver_oaEvalText*) ((PyoaObserver_oaEvalTextObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaEvalText Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaEvalText_FromoaObserver_oaEvalText(oaObserver_oaEvalText* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaEvalText_Type.tp_alloc(&PyoaObserver_oaEvalText_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaEvalTextObject* self = (PyoaObserver_oaEvalTextObject*)bself;
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
pyv_oaObserver_oaEvalText::pyv_oaObserver_oaEvalText(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaEvalText(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaEvalText::pyv_oaObserver_oaEvalText(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaEvalText(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaEvalText::pyv_oaObserver_oaEvalText(const oaObserver_oaEvalText& p)
 : pyob(NULL),
   oaObserver_oaEvalText(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaEvalText::onPostCreate(oaEvalText* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaEvalText::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaEvalText_FromoaEvalText(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaEvalText::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaEvalText::onPostModify(oaEvalText* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaEvalText::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaEvalText_FromoaEvalText(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaEvalText::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaEvalText::onPreDestroy(oaEvalText* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaEvalText::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaEvalText_FromoaEvalText(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaEvalText::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaEvalText::onPreModify(oaEvalText* p1,oaShapeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaEvalText::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaEvalText_FromoaEvalText(p1));
    PyTuple_SetItem(args,1,PyoaShapeModTypeEnum_FromoaShapeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaEvalText::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaEvalText_doc[] = 
"Class: oaObserver_oaEvalText\n"
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
"    Calls: oaObserver_oaEvalText(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaEvalText||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaEvalText\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaEvalText(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaEvalText||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaEvalText\n"
"  Paramegers: (oaObserver_oaEvalText)\n"
"    Calls: (const oaObserver_oaEvalText&)\n"
"    Signature: oaObserver_oaEvalText||cref-oaObserver_oaEvalText,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaEvalText_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaEvalText",
    sizeof(PyoaObserver_oaEvalTextObject),
    0,
    (destructor)oaObserver_oaEvalText_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaEvalText_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaEvalText_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaEvalText_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaEvalText_oaShapeModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaEvalText_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaEvalText_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaEvalText_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaEvalText\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaEvalText",
           (PyObject*)(&PyoaObserver_oaEvalText_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaEvalText\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaFigGroup
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFigGroup_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaFigGroup_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaFigGroupObject* self = (PyoaObserver_oaFigGroupObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaFigGroup(p1.Data());
            }
            else {
                pyv_oaObserver_oaFigGroup* p=new pyv_oaObserver_oaFigGroup(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaFigGroup(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaFigGroup* p=new pyv_oaObserver_oaFigGroup(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaFigGroup)
    {
        PyParamoaObserver_oaFigGroup p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaFigGroup_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaFigGroup(p1.Data());
            }
            else {
                pyv_oaObserver_oaFigGroup* p=new pyv_oaObserver_oaFigGroup(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaFigGroup, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaFigGroup)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaFigGroup_tp_dealloc(PyoaObserver_oaFigGroupObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaFigGroup*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFigGroup_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaFigGroup value;
    int convert_status=PyoaObserver_oaFigGroup_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaObserver_oaFigGroup::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaFigGroup_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaFigGroup v1;
    PyParamoaObserver_oaFigGroup v2;
    int convert_status1=PyoaObserver_oaFigGroup_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaFigGroup_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaFigGroup_Convert(PyObject* ob,PyParamoaObserver_oaFigGroup* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaFigGroup_Check(ob)) {
        result->SetData( (oaObserver_oaFigGroup*) ((PyoaObserver_oaFigGroupObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaFigGroup Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaFigGroup_FromoaObserver_oaFigGroup(oaObserver_oaFigGroup* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaFigGroup_Type.tp_alloc(&PyoaObserver_oaFigGroup_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaFigGroupObject* self = (PyoaObserver_oaFigGroupObject*)bself;
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
pyv_oaObserver_oaFigGroup::pyv_oaObserver_oaFigGroup(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaFigGroup(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFigGroup::pyv_oaObserver_oaFigGroup(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaFigGroup(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFigGroup::pyv_oaObserver_oaFigGroup(const oaObserver_oaFigGroup& p)
 : pyob(NULL),
   oaObserver_oaFigGroup(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFigGroup::onPostCreate(oaFigGroup* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFigGroup::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFigGroup_FromoaFigGroup(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFigGroup::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFigGroup::onPostModify(oaFigGroup* p1,oaFigGroupModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFigGroup::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFigGroup_FromoaFigGroup(p1));
    PyTuple_SetItem(args,1,PyoaFigGroupModTypeEnum_FromoaFigGroupModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFigGroup::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFigGroup::onPreDestroy(oaFigGroup* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFigGroup::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFigGroup_FromoaFigGroup(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFigGroup::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFigGroup::onPreModify(oaFigGroup* p1,oaFigGroupModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFigGroup::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFigGroup_FromoaFigGroup(p1));
    PyTuple_SetItem(args,1,PyoaFigGroupModTypeEnum_FromoaFigGroupModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFigGroup::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaFigGroup_doc[] = 
"Class: oaObserver_oaFigGroup\n"
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
"    Calls: oaObserver_oaFigGroup(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaFigGroup||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFigGroup\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaFigGroup(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaFigGroup||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFigGroup\n"
"  Paramegers: (oaObserver_oaFigGroup)\n"
"    Calls: (const oaObserver_oaFigGroup&)\n"
"    Signature: oaObserver_oaFigGroup||cref-oaObserver_oaFigGroup,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaFigGroup_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaFigGroup",
    sizeof(PyoaObserver_oaFigGroupObject),
    0,
    (destructor)oaObserver_oaFigGroup_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaFigGroup_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaFigGroup_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaFigGroup_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaFigGroup_oaFigGroupModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaFigGroup_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaFigGroup_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaFigGroup_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaFigGroup\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaFigGroup",
           (PyObject*)(&PyoaObserver_oaFigGroup_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaFigGroup\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaFigGroupMem
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFigGroupMem_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaFigGroupMem_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaFigGroupMemObject* self = (PyoaObserver_oaFigGroupMemObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaFigGroupMem(p1.Data());
            }
            else {
                pyv_oaObserver_oaFigGroupMem* p=new pyv_oaObserver_oaFigGroupMem(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaFigGroupMem(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaFigGroupMem* p=new pyv_oaObserver_oaFigGroupMem(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaFigGroupMem)
    {
        PyParamoaObserver_oaFigGroupMem p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaFigGroupMem_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaFigGroupMem(p1.Data());
            }
            else {
                pyv_oaObserver_oaFigGroupMem* p=new pyv_oaObserver_oaFigGroupMem(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaFigGroupMem, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaFigGroupMem)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaFigGroupMem_tp_dealloc(PyoaObserver_oaFigGroupMemObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaFigGroupMem*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFigGroupMem_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaFigGroupMem value;
    int convert_status=PyoaObserver_oaFigGroupMem_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaObserver_oaFigGroupMem::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaFigGroupMem_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaFigGroupMem v1;
    PyParamoaObserver_oaFigGroupMem v2;
    int convert_status1=PyoaObserver_oaFigGroupMem_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaFigGroupMem_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaFigGroupMem_Convert(PyObject* ob,PyParamoaObserver_oaFigGroupMem* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaFigGroupMem_Check(ob)) {
        result->SetData( (oaObserver_oaFigGroupMem*) ((PyoaObserver_oaFigGroupMemObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaFigGroupMem Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaFigGroupMem_FromoaObserver_oaFigGroupMem(oaObserver_oaFigGroupMem* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaFigGroupMem_Type.tp_alloc(&PyoaObserver_oaFigGroupMem_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaFigGroupMemObject* self = (PyoaObserver_oaFigGroupMemObject*)bself;
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
pyv_oaObserver_oaFigGroupMem::pyv_oaObserver_oaFigGroupMem(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaFigGroupMem(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFigGroupMem::pyv_oaObserver_oaFigGroupMem(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaFigGroupMem(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFigGroupMem::pyv_oaObserver_oaFigGroupMem(const oaObserver_oaFigGroupMem& p)
 : pyob(NULL),
   oaObserver_oaFigGroupMem(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFigGroupMem::onPostCreate(oaFigGroupMem* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFigGroupMem::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFigGroupMem_FromoaFigGroupMem(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFigGroupMem::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFigGroupMem::onPostModify(oaFigGroupMem* p1,oaFigGroupMemModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFigGroupMem::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFigGroupMem_FromoaFigGroupMem(p1));
    PyTuple_SetItem(args,1,PyoaFigGroupMemModTypeEnum_FromoaFigGroupMemModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFigGroupMem::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFigGroupMem::onPreDestroy(oaFigGroupMem* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFigGroupMem::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFigGroupMem_FromoaFigGroupMem(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFigGroupMem::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFigGroupMem::onPreModify(oaFigGroupMem* p1,oaFigGroupMemModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFigGroupMem::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFigGroupMem_FromoaFigGroupMem(p1));
    PyTuple_SetItem(args,1,PyoaFigGroupMemModTypeEnum_FromoaFigGroupMemModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFigGroupMem::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaFigGroupMem_doc[] = 
"Class: oaObserver_oaFigGroupMem\n"
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
"    Calls: oaObserver_oaFigGroupMem(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaFigGroupMem||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFigGroupMem\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaFigGroupMem(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaFigGroupMem||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFigGroupMem\n"
"  Paramegers: (oaObserver_oaFigGroupMem)\n"
"    Calls: (const oaObserver_oaFigGroupMem&)\n"
"    Signature: oaObserver_oaFigGroupMem||cref-oaObserver_oaFigGroupMem,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaFigGroupMem_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaFigGroupMem",
    sizeof(PyoaObserver_oaFigGroupMemObject),
    0,
    (destructor)oaObserver_oaFigGroupMem_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaFigGroupMem_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaFigGroupMem_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaFigGroupMem_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaFigGroupMem_oaFigGroupMemModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaFigGroupMem_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaFigGroupMem_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaFigGroupMem_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaFigGroupMem\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaFigGroupMem",
           (PyObject*)(&PyoaObserver_oaFigGroupMem_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaFigGroupMem\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaFloatProp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFloatProp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaFloatProp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaFloatPropObject* self = (PyoaObserver_oaFloatPropObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaFloatProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaFloatProp* p=new pyv_oaObserver_oaFloatProp(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaFloatProp(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaFloatProp* p=new pyv_oaObserver_oaFloatProp(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaFloatProp)
    {
        PyParamoaObserver_oaFloatProp p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaFloatProp_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaFloatProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaFloatProp* p=new pyv_oaObserver_oaFloatProp(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaFloatProp, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaFloatProp)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaFloatProp_tp_dealloc(PyoaObserver_oaFloatPropObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaFloatProp*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFloatProp_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaFloatProp value;
    int convert_status=PyoaObserver_oaFloatProp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaObserver_oaFloatProp::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaFloatProp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaFloatProp v1;
    PyParamoaObserver_oaFloatProp v2;
    int convert_status1=PyoaObserver_oaFloatProp_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaFloatProp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaFloatProp_Convert(PyObject* ob,PyParamoaObserver_oaFloatProp* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaFloatProp_Check(ob)) {
        result->SetData( (oaObserver_oaFloatProp*) ((PyoaObserver_oaFloatPropObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaFloatProp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaFloatProp_FromoaObserver_oaFloatProp(oaObserver_oaFloatProp* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaFloatProp_Type.tp_alloc(&PyoaObserver_oaFloatProp_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaFloatPropObject* self = (PyoaObserver_oaFloatPropObject*)bself;
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
pyv_oaObserver_oaFloatProp::pyv_oaObserver_oaFloatProp(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaFloatProp(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFloatProp::pyv_oaObserver_oaFloatProp(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaFloatProp(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFloatProp::pyv_oaObserver_oaFloatProp(const oaObserver_oaFloatProp& p)
 : pyob(NULL),
   oaObserver_oaFloatProp(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFloatProp::onPostCreate(oaFloatProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFloatProp::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFloatProp_FromoaFloatProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFloatProp::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFloatProp::onPostModify(oaFloatProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFloatProp::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFloatProp_FromoaFloatProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFloatProp::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFloatProp::onPreDestroy(oaFloatProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFloatProp::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFloatProp_FromoaFloatProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFloatProp::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFloatProp::onPreModify(oaFloatProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFloatProp::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFloatProp_FromoaFloatProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFloatProp::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaFloatProp_doc[] = 
"Class: oaObserver_oaFloatProp\n"
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
"    Calls: oaObserver_oaFloatProp(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaFloatProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFloatProp\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaFloatProp(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaFloatProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFloatProp\n"
"  Paramegers: (oaObserver_oaFloatProp)\n"
"    Calls: (const oaObserver_oaFloatProp&)\n"
"    Signature: oaObserver_oaFloatProp||cref-oaObserver_oaFloatProp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaFloatProp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaFloatProp",
    sizeof(PyoaObserver_oaFloatPropObject),
    0,
    (destructor)oaObserver_oaFloatProp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaFloatProp_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaFloatProp_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaFloatProp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaFloatProp_oaPropModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaFloatProp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaFloatProp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaFloatProp_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaFloatProp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaFloatProp",
           (PyObject*)(&PyoaObserver_oaFloatProp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaFloatProp\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaFloatRangeProp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFloatRangeProp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaFloatRangeProp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaFloatRangePropObject* self = (PyoaObserver_oaFloatRangePropObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaFloatRangeProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaFloatRangeProp* p=new pyv_oaObserver_oaFloatRangeProp(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaFloatRangeProp(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaFloatRangeProp* p=new pyv_oaObserver_oaFloatRangeProp(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaFloatRangeProp)
    {
        PyParamoaObserver_oaFloatRangeProp p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaFloatRangeProp_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaFloatRangeProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaFloatRangeProp* p=new pyv_oaObserver_oaFloatRangeProp(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaFloatRangeProp, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaFloatRangeProp)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaFloatRangeProp_tp_dealloc(PyoaObserver_oaFloatRangePropObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaFloatRangeProp*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFloatRangeProp_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaFloatRangeProp value;
    int convert_status=PyoaObserver_oaFloatRangeProp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[49];
    sprintf(buffer,"<oaObserver_oaFloatRangeProp::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaFloatRangeProp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaFloatRangeProp v1;
    PyParamoaObserver_oaFloatRangeProp v2;
    int convert_status1=PyoaObserver_oaFloatRangeProp_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaFloatRangeProp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaFloatRangeProp_Convert(PyObject* ob,PyParamoaObserver_oaFloatRangeProp* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaFloatRangeProp_Check(ob)) {
        result->SetData( (oaObserver_oaFloatRangeProp*) ((PyoaObserver_oaFloatRangePropObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaFloatRangeProp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaFloatRangeProp_FromoaObserver_oaFloatRangeProp(oaObserver_oaFloatRangeProp* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaFloatRangeProp_Type.tp_alloc(&PyoaObserver_oaFloatRangeProp_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaFloatRangePropObject* self = (PyoaObserver_oaFloatRangePropObject*)bself;
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
pyv_oaObserver_oaFloatRangeProp::pyv_oaObserver_oaFloatRangeProp(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaFloatRangeProp(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFloatRangeProp::pyv_oaObserver_oaFloatRangeProp(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaFloatRangeProp(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFloatRangeProp::pyv_oaObserver_oaFloatRangeProp(const oaObserver_oaFloatRangeProp& p)
 : pyob(NULL),
   oaObserver_oaFloatRangeProp(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFloatRangeProp::onPostCreate(oaFloatRangeProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFloatRangeProp::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFloatRangeProp_FromoaFloatRangeProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFloatRangeProp::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFloatRangeProp::onPostModify(oaFloatRangeProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFloatRangeProp::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFloatRangeProp_FromoaFloatRangeProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFloatRangeProp::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFloatRangeProp::onPreDestroy(oaFloatRangeProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFloatRangeProp::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFloatRangeProp_FromoaFloatRangeProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFloatRangeProp::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFloatRangeProp::onPreModify(oaFloatRangeProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFloatRangeProp::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFloatRangeProp_FromoaFloatRangeProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFloatRangeProp::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaFloatRangeProp_doc[] = 
"Class: oaObserver_oaFloatRangeProp\n"
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
"    Calls: oaObserver_oaFloatRangeProp(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaFloatRangeProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFloatRangeProp\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaFloatRangeProp(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaFloatRangeProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFloatRangeProp\n"
"  Paramegers: (oaObserver_oaFloatRangeProp)\n"
"    Calls: (const oaObserver_oaFloatRangeProp&)\n"
"    Signature: oaObserver_oaFloatRangeProp||cref-oaObserver_oaFloatRangeProp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaFloatRangeProp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaFloatRangeProp",
    sizeof(PyoaObserver_oaFloatRangePropObject),
    0,
    (destructor)oaObserver_oaFloatRangeProp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaFloatRangeProp_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaFloatRangeProp_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaFloatRangeProp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaFloatRangeProp_oaPropModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaFloatRangeProp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaFloatRangeProp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaFloatRangeProp_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaFloatRangeProp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaFloatRangeProp",
           (PyObject*)(&PyoaObserver_oaFloatRangeProp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaFloatRangeProp\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaFlt1DTblValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFlt1DTblValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaFlt1DTblValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaFlt1DTblValueObject* self = (PyoaObserver_oaFlt1DTblValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaFlt1DTblValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaFlt1DTblValue* p=new pyv_oaObserver_oaFlt1DTblValue(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaFlt1DTblValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaFlt1DTblValue* p=new pyv_oaObserver_oaFlt1DTblValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaFlt1DTblValue)
    {
        PyParamoaObserver_oaFlt1DTblValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaFlt1DTblValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaFlt1DTblValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaFlt1DTblValue* p=new pyv_oaObserver_oaFlt1DTblValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaFlt1DTblValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaFlt1DTblValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaFlt1DTblValue_tp_dealloc(PyoaObserver_oaFlt1DTblValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaFlt1DTblValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFlt1DTblValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaFlt1DTblValue value;
    int convert_status=PyoaObserver_oaFlt1DTblValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaFlt1DTblValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaFlt1DTblValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaFlt1DTblValue v1;
    PyParamoaObserver_oaFlt1DTblValue v2;
    int convert_status1=PyoaObserver_oaFlt1DTblValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaFlt1DTblValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaFlt1DTblValue_Convert(PyObject* ob,PyParamoaObserver_oaFlt1DTblValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaFlt1DTblValue_Check(ob)) {
        result->SetData( (oaObserver_oaFlt1DTblValue*) ((PyoaObserver_oaFlt1DTblValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaFlt1DTblValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaFlt1DTblValue_FromoaObserver_oaFlt1DTblValue(oaObserver_oaFlt1DTblValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaFlt1DTblValue_Type.tp_alloc(&PyoaObserver_oaFlt1DTblValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaFlt1DTblValueObject* self = (PyoaObserver_oaFlt1DTblValueObject*)bself;
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
pyv_oaObserver_oaFlt1DTblValue::pyv_oaObserver_oaFlt1DTblValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaFlt1DTblValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFlt1DTblValue::pyv_oaObserver_oaFlt1DTblValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaFlt1DTblValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFlt1DTblValue::pyv_oaObserver_oaFlt1DTblValue(const oaObserver_oaFlt1DTblValue& p)
 : pyob(NULL),
   oaObserver_oaFlt1DTblValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFlt1DTblValue::onPostCreate(oaFlt1DTblValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFlt1DTblValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFlt1DTblValue_FromoaFlt1DTblValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFlt1DTblValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFlt1DTblValue::onPostModify(oaFlt1DTblValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFlt1DTblValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFlt1DTblValue_FromoaFlt1DTblValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFlt1DTblValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFlt1DTblValue::onPreDestroy(oaFlt1DTblValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFlt1DTblValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFlt1DTblValue_FromoaFlt1DTblValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFlt1DTblValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFlt1DTblValue::onPreModify(oaFlt1DTblValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFlt1DTblValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFlt1DTblValue_FromoaFlt1DTblValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFlt1DTblValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaFlt1DTblValue_doc[] = 
"Class: oaObserver_oaFlt1DTblValue\n"
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
"    Calls: oaObserver_oaFlt1DTblValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaFlt1DTblValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFlt1DTblValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaFlt1DTblValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaFlt1DTblValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFlt1DTblValue\n"
"  Paramegers: (oaObserver_oaFlt1DTblValue)\n"
"    Calls: (const oaObserver_oaFlt1DTblValue&)\n"
"    Signature: oaObserver_oaFlt1DTblValue||cref-oaObserver_oaFlt1DTblValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaFlt1DTblValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaFlt1DTblValue",
    sizeof(PyoaObserver_oaFlt1DTblValueObject),
    0,
    (destructor)oaObserver_oaFlt1DTblValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaFlt1DTblValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaFlt1DTblValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaFlt1DTblValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaFlt1DTblValue_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaFlt1DTblValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaFlt1DTblValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaFlt1DTblValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaFlt1DTblValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaFlt1DTblValue",
           (PyObject*)(&PyoaObserver_oaFlt1DTblValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaFlt1DTblValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaFlt2DTblValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFlt2DTblValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaFlt2DTblValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaFlt2DTblValueObject* self = (PyoaObserver_oaFlt2DTblValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaFlt2DTblValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaFlt2DTblValue* p=new pyv_oaObserver_oaFlt2DTblValue(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaFlt2DTblValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaFlt2DTblValue* p=new pyv_oaObserver_oaFlt2DTblValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaFlt2DTblValue)
    {
        PyParamoaObserver_oaFlt2DTblValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaFlt2DTblValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaFlt2DTblValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaFlt2DTblValue* p=new pyv_oaObserver_oaFlt2DTblValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaFlt2DTblValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaFlt2DTblValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaFlt2DTblValue_tp_dealloc(PyoaObserver_oaFlt2DTblValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaFlt2DTblValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFlt2DTblValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaFlt2DTblValue value;
    int convert_status=PyoaObserver_oaFlt2DTblValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[48];
    sprintf(buffer,"<oaObserver_oaFlt2DTblValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaFlt2DTblValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaFlt2DTblValue v1;
    PyParamoaObserver_oaFlt2DTblValue v2;
    int convert_status1=PyoaObserver_oaFlt2DTblValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaFlt2DTblValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaFlt2DTblValue_Convert(PyObject* ob,PyParamoaObserver_oaFlt2DTblValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaFlt2DTblValue_Check(ob)) {
        result->SetData( (oaObserver_oaFlt2DTblValue*) ((PyoaObserver_oaFlt2DTblValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaFlt2DTblValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaFlt2DTblValue_FromoaObserver_oaFlt2DTblValue(oaObserver_oaFlt2DTblValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaFlt2DTblValue_Type.tp_alloc(&PyoaObserver_oaFlt2DTblValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaFlt2DTblValueObject* self = (PyoaObserver_oaFlt2DTblValueObject*)bself;
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
pyv_oaObserver_oaFlt2DTblValue::pyv_oaObserver_oaFlt2DTblValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaFlt2DTblValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFlt2DTblValue::pyv_oaObserver_oaFlt2DTblValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaFlt2DTblValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFlt2DTblValue::pyv_oaObserver_oaFlt2DTblValue(const oaObserver_oaFlt2DTblValue& p)
 : pyob(NULL),
   oaObserver_oaFlt2DTblValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFlt2DTblValue::onPostCreate(oaFlt2DTblValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFlt2DTblValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFlt2DTblValue_FromoaFlt2DTblValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFlt2DTblValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFlt2DTblValue::onPostModify(oaFlt2DTblValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFlt2DTblValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFlt2DTblValue_FromoaFlt2DTblValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFlt2DTblValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFlt2DTblValue::onPreDestroy(oaFlt2DTblValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFlt2DTblValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFlt2DTblValue_FromoaFlt2DTblValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFlt2DTblValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFlt2DTblValue::onPreModify(oaFlt2DTblValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFlt2DTblValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFlt2DTblValue_FromoaFlt2DTblValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFlt2DTblValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaFlt2DTblValue_doc[] = 
"Class: oaObserver_oaFlt2DTblValue\n"
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
"    Calls: oaObserver_oaFlt2DTblValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaFlt2DTblValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFlt2DTblValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaFlt2DTblValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaFlt2DTblValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFlt2DTblValue\n"
"  Paramegers: (oaObserver_oaFlt2DTblValue)\n"
"    Calls: (const oaObserver_oaFlt2DTblValue&)\n"
"    Signature: oaObserver_oaFlt2DTblValue||cref-oaObserver_oaFlt2DTblValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaFlt2DTblValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaFlt2DTblValue",
    sizeof(PyoaObserver_oaFlt2DTblValueObject),
    0,
    (destructor)oaObserver_oaFlt2DTblValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaFlt2DTblValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaFlt2DTblValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaFlt2DTblValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaFlt2DTblValue_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaFlt2DTblValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaFlt2DTblValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaFlt2DTblValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaFlt2DTblValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaFlt2DTblValue",
           (PyObject*)(&PyoaObserver_oaFlt2DTblValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaFlt2DTblValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaFltIntFltTblValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFltIntFltTblValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaFltIntFltTblValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaFltIntFltTblValueObject* self = (PyoaObserver_oaFltIntFltTblValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaFltIntFltTblValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaFltIntFltTblValue* p=new pyv_oaObserver_oaFltIntFltTblValue(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaFltIntFltTblValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaFltIntFltTblValue* p=new pyv_oaObserver_oaFltIntFltTblValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaFltIntFltTblValue)
    {
        PyParamoaObserver_oaFltIntFltTblValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaFltIntFltTblValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaFltIntFltTblValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaFltIntFltTblValue* p=new pyv_oaObserver_oaFltIntFltTblValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaFltIntFltTblValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaFltIntFltTblValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaFltIntFltTblValue_tp_dealloc(PyoaObserver_oaFltIntFltTblValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaFltIntFltTblValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFltIntFltTblValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaFltIntFltTblValue value;
    int convert_status=PyoaObserver_oaFltIntFltTblValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[52];
    sprintf(buffer,"<oaObserver_oaFltIntFltTblValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaFltIntFltTblValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaFltIntFltTblValue v1;
    PyParamoaObserver_oaFltIntFltTblValue v2;
    int convert_status1=PyoaObserver_oaFltIntFltTblValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaFltIntFltTblValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaFltIntFltTblValue_Convert(PyObject* ob,PyParamoaObserver_oaFltIntFltTblValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaFltIntFltTblValue_Check(ob)) {
        result->SetData( (oaObserver_oaFltIntFltTblValue*) ((PyoaObserver_oaFltIntFltTblValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaFltIntFltTblValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaFltIntFltTblValue_FromoaObserver_oaFltIntFltTblValue(oaObserver_oaFltIntFltTblValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaFltIntFltTblValue_Type.tp_alloc(&PyoaObserver_oaFltIntFltTblValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaFltIntFltTblValueObject* self = (PyoaObserver_oaFltIntFltTblValueObject*)bself;
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
pyv_oaObserver_oaFltIntFltTblValue::pyv_oaObserver_oaFltIntFltTblValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaFltIntFltTblValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFltIntFltTblValue::pyv_oaObserver_oaFltIntFltTblValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaFltIntFltTblValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFltIntFltTblValue::pyv_oaObserver_oaFltIntFltTblValue(const oaObserver_oaFltIntFltTblValue& p)
 : pyob(NULL),
   oaObserver_oaFltIntFltTblValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFltIntFltTblValue::onPostCreate(oaFltIntFltTblValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFltIntFltTblValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFltIntFltTblValue_FromoaFltIntFltTblValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFltIntFltTblValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFltIntFltTblValue::onPostModify(oaFltIntFltTblValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFltIntFltTblValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFltIntFltTblValue_FromoaFltIntFltTblValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFltIntFltTblValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFltIntFltTblValue::onPreDestroy(oaFltIntFltTblValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFltIntFltTblValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFltIntFltTblValue_FromoaFltIntFltTblValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFltIntFltTblValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFltIntFltTblValue::onPreModify(oaFltIntFltTblValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFltIntFltTblValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFltIntFltTblValue_FromoaFltIntFltTblValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFltIntFltTblValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaFltIntFltTblValue_doc[] = 
"Class: oaObserver_oaFltIntFltTblValue\n"
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
"    Calls: oaObserver_oaFltIntFltTblValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaFltIntFltTblValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFltIntFltTblValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaFltIntFltTblValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaFltIntFltTblValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFltIntFltTblValue\n"
"  Paramegers: (oaObserver_oaFltIntFltTblValue)\n"
"    Calls: (const oaObserver_oaFltIntFltTblValue&)\n"
"    Signature: oaObserver_oaFltIntFltTblValue||cref-oaObserver_oaFltIntFltTblValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaFltIntFltTblValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaFltIntFltTblValue",
    sizeof(PyoaObserver_oaFltIntFltTblValueObject),
    0,
    (destructor)oaObserver_oaFltIntFltTblValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaFltIntFltTblValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaFltIntFltTblValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaFltIntFltTblValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaFltIntFltTblValue_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaFltIntFltTblValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaFltIntFltTblValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaFltIntFltTblValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaFltIntFltTblValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaFltIntFltTblValue",
           (PyObject*)(&PyoaObserver_oaFltIntFltTblValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaFltIntFltTblValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaFltValue
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFltValue_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaFltValue_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaFltValueObject* self = (PyoaObserver_oaFltValueObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaFltValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaFltValue* p=new pyv_oaObserver_oaFltValue(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaFltValue(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaFltValue* p=new pyv_oaObserver_oaFltValue(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaFltValue)
    {
        PyParamoaObserver_oaFltValue p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaFltValue_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaFltValue(p1.Data());
            }
            else {
                pyv_oaObserver_oaFltValue* p=new pyv_oaObserver_oaFltValue(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaFltValue, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaFltValue)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaFltValue_tp_dealloc(PyoaObserver_oaFltValueObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaFltValue*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFltValue_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaFltValue value;
    int convert_status=PyoaObserver_oaFltValue_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaObserver_oaFltValue::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaFltValue_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaFltValue v1;
    PyParamoaObserver_oaFltValue v2;
    int convert_status1=PyoaObserver_oaFltValue_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaFltValue_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaFltValue_Convert(PyObject* ob,PyParamoaObserver_oaFltValue* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaFltValue_Check(ob)) {
        result->SetData( (oaObserver_oaFltValue*) ((PyoaObserver_oaFltValueObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaFltValue Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaFltValue_FromoaObserver_oaFltValue(oaObserver_oaFltValue* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaFltValue_Type.tp_alloc(&PyoaObserver_oaFltValue_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaFltValueObject* self = (PyoaObserver_oaFltValueObject*)bself;
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
pyv_oaObserver_oaFltValue::pyv_oaObserver_oaFltValue(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaFltValue(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFltValue::pyv_oaObserver_oaFltValue(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaFltValue(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFltValue::pyv_oaObserver_oaFltValue(const oaObserver_oaFltValue& p)
 : pyob(NULL),
   oaObserver_oaFltValue(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFltValue::onPostCreate(oaFltValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFltValue::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFltValue_FromoaFltValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFltValue::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFltValue::onPostModify(oaFltValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFltValue::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFltValue_FromoaFltValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFltValue::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFltValue::onPreDestroy(oaFltValue* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFltValue::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFltValue_FromoaFltValue(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFltValue::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFltValue::onPreModify(oaFltValue* p1,oaValueModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFltValue::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFltValue_FromoaFltValue(p1));
    PyTuple_SetItem(args,1,PyoaValueModTypeEnum_FromoaValueModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFltValue::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaFltValue_doc[] = 
"Class: oaObserver_oaFltValue\n"
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
"    Calls: oaObserver_oaFltValue(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaFltValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFltValue\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaFltValue(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaFltValue||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFltValue\n"
"  Paramegers: (oaObserver_oaFltValue)\n"
"    Calls: (const oaObserver_oaFltValue&)\n"
"    Signature: oaObserver_oaFltValue||cref-oaObserver_oaFltValue,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaFltValue_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaFltValue",
    sizeof(PyoaObserver_oaFltValueObject),
    0,
    (destructor)oaObserver_oaFltValue_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaFltValue_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaFltValue_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaFltValue_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaFltValue_oaValueModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaFltValue_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaFltValue_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaFltValue_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaFltValue\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaFltValue",
           (PyObject*)(&PyoaObserver_oaFltValue_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaFltValue\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaFrame
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFrame_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaFrame_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaFrameObject* self = (PyoaObserver_oaFrameObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaFrame(p1.Data());
            }
            else {
                pyv_oaObserver_oaFrame* p=new pyv_oaObserver_oaFrame(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaFrame(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaFrame* p=new pyv_oaObserver_oaFrame(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaFrame)
    {
        PyParamoaObserver_oaFrame p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaFrame_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaFrame(p1.Data());
            }
            else {
                pyv_oaObserver_oaFrame* p=new pyv_oaObserver_oaFrame(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaFrame, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaFrame)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaFrame_tp_dealloc(PyoaObserver_oaFrameObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaFrame*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFrame_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaFrame value;
    int convert_status=PyoaObserver_oaFrame_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaObserver_oaFrame::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaFrame_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaFrame v1;
    PyParamoaObserver_oaFrame v2;
    int convert_status1=PyoaObserver_oaFrame_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaFrame_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaFrame_Convert(PyObject* ob,PyParamoaObserver_oaFrame* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaFrame_Check(ob)) {
        result->SetData( (oaObserver_oaFrame*) ((PyoaObserver_oaFrameObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaFrame Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaFrame_FromoaObserver_oaFrame(oaObserver_oaFrame* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaFrame_Type.tp_alloc(&PyoaObserver_oaFrame_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaFrameObject* self = (PyoaObserver_oaFrameObject*)bself;
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
pyv_oaObserver_oaFrame::pyv_oaObserver_oaFrame(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaFrame(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFrame::pyv_oaObserver_oaFrame(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaFrame(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFrame::pyv_oaObserver_oaFrame(const oaObserver_oaFrame& p)
 : pyob(NULL),
   oaObserver_oaFrame(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFrame::onPostCreate(oaFrame* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFrame::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFrame_FromoaFrame(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFrame::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFrame::onPostModify(oaFrame* p1,oaFrameModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFrame::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFrame_FromoaFrame(p1));
    PyTuple_SetItem(args,1,PyoaFrameModTypeEnum_FromoaFrameModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFrame::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFrame::onPreDestroy(oaFrame* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFrame::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFrame_FromoaFrame(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFrame::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFrame::onPreModify(oaFrame* p1,oaFrameModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFrame::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFrame_FromoaFrame(p1));
    PyTuple_SetItem(args,1,PyoaFrameModTypeEnum_FromoaFrameModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFrame::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaFrame_doc[] = 
"Class: oaObserver_oaFrame\n"
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
"    Calls: oaObserver_oaFrame(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaFrame||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFrame\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaFrame(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaFrame||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFrame\n"
"  Paramegers: (oaObserver_oaFrame)\n"
"    Calls: (const oaObserver_oaFrame&)\n"
"    Signature: oaObserver_oaFrame||cref-oaObserver_oaFrame,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaFrame_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaFrame",
    sizeof(PyoaObserver_oaFrameObject),
    0,
    (destructor)oaObserver_oaFrame_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaFrame_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaFrame_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaFrame_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaFrame_oaFrameModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaFrame_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaFrame_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaFrame_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaFrame\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaFrame",
           (PyObject*)(&PyoaObserver_oaFrame_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaFrame\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaFrameInst
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFrameInst_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaFrameInst_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaFrameInstObject* self = (PyoaObserver_oaFrameInstObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaFrameInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaFrameInst* p=new pyv_oaObserver_oaFrameInst(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaFrameInst(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaFrameInst* p=new pyv_oaObserver_oaFrameInst(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaFrameInst)
    {
        PyParamoaObserver_oaFrameInst p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaFrameInst_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaFrameInst(p1.Data());
            }
            else {
                pyv_oaObserver_oaFrameInst* p=new pyv_oaObserver_oaFrameInst(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaFrameInst, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaFrameInst)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaFrameInst_tp_dealloc(PyoaObserver_oaFrameInstObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaFrameInst*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaFrameInst_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaFrameInst value;
    int convert_status=PyoaObserver_oaFrameInst_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[44];
    sprintf(buffer,"<oaObserver_oaFrameInst::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaFrameInst_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaFrameInst v1;
    PyParamoaObserver_oaFrameInst v2;
    int convert_status1=PyoaObserver_oaFrameInst_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaFrameInst_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaFrameInst_Convert(PyObject* ob,PyParamoaObserver_oaFrameInst* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaFrameInst_Check(ob)) {
        result->SetData( (oaObserver_oaFrameInst*) ((PyoaObserver_oaFrameInstObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaFrameInst Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaFrameInst_FromoaObserver_oaFrameInst(oaObserver_oaFrameInst* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaFrameInst_Type.tp_alloc(&PyoaObserver_oaFrameInst_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaFrameInstObject* self = (PyoaObserver_oaFrameInstObject*)bself;
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
pyv_oaObserver_oaFrameInst::pyv_oaObserver_oaFrameInst(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaFrameInst(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFrameInst::pyv_oaObserver_oaFrameInst(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaFrameInst(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaFrameInst::pyv_oaObserver_oaFrameInst(const oaObserver_oaFrameInst& p)
 : pyob(NULL),
   oaObserver_oaFrameInst(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFrameInst::onPostCreate(oaFrameInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFrameInst::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFrameInst_FromoaFrameInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFrameInst::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFrameInst::onPostModify(oaFrameInst* p1,oaFrameInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFrameInst::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFrameInst_FromoaFrameInst(p1));
    PyTuple_SetItem(args,1,PyoaFrameInstModTypeEnum_FromoaFrameInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFrameInst::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFrameInst::onPreDestroy(oaFrameInst* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFrameInst::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaFrameInst_FromoaFrameInst(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFrameInst::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaFrameInst::onPreModify(oaFrameInst* p1,oaFrameInstModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaFrameInst::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaFrameInst_FromoaFrameInst(p1));
    PyTuple_SetItem(args,1,PyoaFrameInstModTypeEnum_FromoaFrameInstModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaFrameInst::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaFrameInst_doc[] = 
"Class: oaObserver_oaFrameInst\n"
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
"    Calls: oaObserver_oaFrameInst(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaFrameInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFrameInst\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaFrameInst(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaFrameInst||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaFrameInst\n"
"  Paramegers: (oaObserver_oaFrameInst)\n"
"    Calls: (const oaObserver_oaFrameInst&)\n"
"    Signature: oaObserver_oaFrameInst||cref-oaObserver_oaFrameInst,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaFrameInst_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaFrameInst",
    sizeof(PyoaObserver_oaFrameInstObject),
    0,
    (destructor)oaObserver_oaFrameInst_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaFrameInst_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaFrameInst_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaFrameInst_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaFrameInst_oaFrameInstModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaFrameInst_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaFrameInst_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaFrameInst_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaFrameInst\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaFrameInst",
           (PyObject*)(&PyoaObserver_oaFrameInst_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaFrameInst\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaGCellPattern
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaGCellPattern_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaGCellPattern_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaGCellPatternObject* self = (PyoaObserver_oaGCellPatternObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaGCellPattern(p1.Data());
            }
            else {
                pyv_oaObserver_oaGCellPattern* p=new pyv_oaObserver_oaGCellPattern(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaGCellPattern(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaGCellPattern* p=new pyv_oaObserver_oaGCellPattern(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaGCellPattern)
    {
        PyParamoaObserver_oaGCellPattern p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaGCellPattern_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaGCellPattern(p1.Data());
            }
            else {
                pyv_oaObserver_oaGCellPattern* p=new pyv_oaObserver_oaGCellPattern(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaGCellPattern, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaGCellPattern)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaGCellPattern_tp_dealloc(PyoaObserver_oaGCellPatternObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaGCellPattern*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaGCellPattern_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaGCellPattern value;
    int convert_status=PyoaObserver_oaGCellPattern_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaGCellPattern::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaGCellPattern_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaGCellPattern v1;
    PyParamoaObserver_oaGCellPattern v2;
    int convert_status1=PyoaObserver_oaGCellPattern_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaGCellPattern_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaGCellPattern_Convert(PyObject* ob,PyParamoaObserver_oaGCellPattern* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaGCellPattern_Check(ob)) {
        result->SetData( (oaObserver_oaGCellPattern*) ((PyoaObserver_oaGCellPatternObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaGCellPattern Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaGCellPattern_FromoaObserver_oaGCellPattern(oaObserver_oaGCellPattern* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaGCellPattern_Type.tp_alloc(&PyoaObserver_oaGCellPattern_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaGCellPatternObject* self = (PyoaObserver_oaGCellPatternObject*)bself;
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
pyv_oaObserver_oaGCellPattern::pyv_oaObserver_oaGCellPattern(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaGCellPattern(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaGCellPattern::pyv_oaObserver_oaGCellPattern(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaGCellPattern(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaGCellPattern::pyv_oaObserver_oaGCellPattern(const oaObserver_oaGCellPattern& p)
 : pyob(NULL),
   oaObserver_oaGCellPattern(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGCellPattern::onPostCreate(oaGCellPattern* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGCellPattern::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaGCellPattern_FromoaGCellPattern(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGCellPattern::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGCellPattern::onPostModify(oaGCellPattern* p1,oaGCellPatternModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGCellPattern::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaGCellPattern_FromoaGCellPattern(p1));
    PyTuple_SetItem(args,1,PyoaGCellPatternModTypeEnum_FromoaGCellPatternModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGCellPattern::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGCellPattern::onPreDestroy(oaGCellPattern* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGCellPattern::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaGCellPattern_FromoaGCellPattern(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGCellPattern::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGCellPattern::onPreModify(oaGCellPattern* p1,oaGCellPatternModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGCellPattern::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaGCellPattern_FromoaGCellPattern(p1));
    PyTuple_SetItem(args,1,PyoaGCellPatternModTypeEnum_FromoaGCellPatternModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGCellPattern::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaGCellPattern_doc[] = 
"Class: oaObserver_oaGCellPattern\n"
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
"    Calls: oaObserver_oaGCellPattern(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaGCellPattern||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaGCellPattern\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaGCellPattern(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaGCellPattern||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaGCellPattern\n"
"  Paramegers: (oaObserver_oaGCellPattern)\n"
"    Calls: (const oaObserver_oaGCellPattern&)\n"
"    Signature: oaObserver_oaGCellPattern||cref-oaObserver_oaGCellPattern,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaGCellPattern_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaGCellPattern",
    sizeof(PyoaObserver_oaGCellPatternObject),
    0,
    (destructor)oaObserver_oaGCellPattern_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaGCellPattern_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaGCellPattern_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaGCellPattern_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaGCellPattern_oaGCellPatternModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaGCellPattern_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaGCellPattern_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaGCellPattern_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaGCellPattern\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaGCellPattern",
           (PyObject*)(&PyoaObserver_oaGCellPattern_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaGCellPattern\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaGroundedNode
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaGroundedNode_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaGroundedNode_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaGroundedNodeObject* self = (PyoaObserver_oaGroundedNodeObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaGroundedNode(p1.Data());
            }
            else {
                pyv_oaObserver_oaGroundedNode* p=new pyv_oaObserver_oaGroundedNode(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaGroundedNode(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaGroundedNode* p=new pyv_oaObserver_oaGroundedNode(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaGroundedNode)
    {
        PyParamoaObserver_oaGroundedNode p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaGroundedNode_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaGroundedNode(p1.Data());
            }
            else {
                pyv_oaObserver_oaGroundedNode* p=new pyv_oaObserver_oaGroundedNode(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaGroundedNode, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaGroundedNode)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaGroundedNode_tp_dealloc(PyoaObserver_oaGroundedNodeObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaGroundedNode*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaGroundedNode_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaGroundedNode value;
    int convert_status=PyoaObserver_oaGroundedNode_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[47];
    sprintf(buffer,"<oaObserver_oaGroundedNode::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaGroundedNode_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaGroundedNode v1;
    PyParamoaObserver_oaGroundedNode v2;
    int convert_status1=PyoaObserver_oaGroundedNode_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaGroundedNode_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaGroundedNode_Convert(PyObject* ob,PyParamoaObserver_oaGroundedNode* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaGroundedNode_Check(ob)) {
        result->SetData( (oaObserver_oaGroundedNode*) ((PyoaObserver_oaGroundedNodeObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaGroundedNode Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaGroundedNode_FromoaObserver_oaGroundedNode(oaObserver_oaGroundedNode* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaGroundedNode_Type.tp_alloc(&PyoaObserver_oaGroundedNode_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaGroundedNodeObject* self = (PyoaObserver_oaGroundedNodeObject*)bself;
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
pyv_oaObserver_oaGroundedNode::pyv_oaObserver_oaGroundedNode(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaGroundedNode(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaGroundedNode::pyv_oaObserver_oaGroundedNode(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaGroundedNode(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaGroundedNode::pyv_oaObserver_oaGroundedNode(const oaObserver_oaGroundedNode& p)
 : pyob(NULL),
   oaObserver_oaGroundedNode(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGroundedNode::onPostCreate(oaGroundedNode* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGroundedNode::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaGroundedNode_FromoaGroundedNode(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGroundedNode::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGroundedNode::onPostModify(oaGroundedNode* p1,oaNodeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGroundedNode::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaGroundedNode_FromoaGroundedNode(p1));
    PyTuple_SetItem(args,1,PyoaNodeModTypeEnum_FromoaNodeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGroundedNode::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGroundedNode::onPreDestroy(oaGroundedNode* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGroundedNode::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaGroundedNode_FromoaGroundedNode(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGroundedNode::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGroundedNode::onPreModify(oaGroundedNode* p1,oaNodeModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGroundedNode::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaGroundedNode_FromoaGroundedNode(p1));
    PyTuple_SetItem(args,1,PyoaNodeModTypeEnum_FromoaNodeModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGroundedNode::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaGroundedNode_doc[] = 
"Class: oaObserver_oaGroundedNode\n"
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
"    Calls: oaObserver_oaGroundedNode(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaGroundedNode||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaGroundedNode\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaGroundedNode(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaGroundedNode||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaGroundedNode\n"
"  Paramegers: (oaObserver_oaGroundedNode)\n"
"    Calls: (const oaObserver_oaGroundedNode&)\n"
"    Signature: oaObserver_oaGroundedNode||cref-oaObserver_oaGroundedNode,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaGroundedNode_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaGroundedNode",
    sizeof(PyoaObserver_oaGroundedNodeObject),
    0,
    (destructor)oaObserver_oaGroundedNode_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaGroundedNode_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaGroundedNode_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaGroundedNode_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaGroundedNode_oaNodeModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaGroundedNode_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaGroundedNode_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaGroundedNode_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaGroundedNode\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaGroundedNode",
           (PyObject*)(&PyoaObserver_oaGroundedNode_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaGroundedNode\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaGroup
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaGroup_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaGroup_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaGroupObject* self = (PyoaObserver_oaGroupObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaGroup(p1.Data());
            }
            else {
                pyv_oaObserver_oaGroup* p=new pyv_oaObserver_oaGroup(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaGroup(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaGroup* p=new pyv_oaObserver_oaGroup(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaGroup)
    {
        PyParamoaObserver_oaGroup p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaGroup_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaGroup(p1.Data());
            }
            else {
                pyv_oaObserver_oaGroup* p=new pyv_oaObserver_oaGroup(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaGroup, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaGroup)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaGroup_tp_dealloc(PyoaObserver_oaGroupObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaGroup*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaGroup_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaGroup value;
    int convert_status=PyoaObserver_oaGroup_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaObserver_oaGroup::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaGroup_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaGroup v1;
    PyParamoaObserver_oaGroup v2;
    int convert_status1=PyoaObserver_oaGroup_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaGroup_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaGroup_Convert(PyObject* ob,PyParamoaObserver_oaGroup* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaGroup_Check(ob)) {
        result->SetData( (oaObserver_oaGroup*) ((PyoaObserver_oaGroupObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaGroup Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaGroup_FromoaObserver_oaGroup(oaObserver_oaGroup* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaGroup_Type.tp_alloc(&PyoaObserver_oaGroup_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaGroupObject* self = (PyoaObserver_oaGroupObject*)bself;
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
pyv_oaObserver_oaGroup::pyv_oaObserver_oaGroup(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaGroup(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaGroup::pyv_oaObserver_oaGroup(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaGroup(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaGroup::pyv_oaObserver_oaGroup(const oaObserver_oaGroup& p)
 : pyob(NULL),
   oaObserver_oaGroup(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGroup::onPostCreate(oaGroup* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGroup::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaGroup_FromoaGroup(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGroup::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGroup::onPostModify(oaGroup* p1,oaGroupModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGroup::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaGroup_FromoaGroup(p1));
    PyTuple_SetItem(args,1,PyoaGroupModTypeEnum_FromoaGroupModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGroup::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGroup::onPreDestroy(oaGroup* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGroup::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaGroup_FromoaGroup(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGroup::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGroup::onPreModify(oaGroup* p1,oaGroupModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGroup::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaGroup_FromoaGroup(p1));
    PyTuple_SetItem(args,1,PyoaGroupModTypeEnum_FromoaGroupModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGroup::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaGroup_doc[] = 
"Class: oaObserver_oaGroup\n"
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
"    Calls: oaObserver_oaGroup(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaGroup||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaGroup\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaGroup(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaGroup||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaGroup\n"
"  Paramegers: (oaObserver_oaGroup)\n"
"    Calls: (const oaObserver_oaGroup&)\n"
"    Signature: oaObserver_oaGroup||cref-oaObserver_oaGroup,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaGroup_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaGroup",
    sizeof(PyoaObserver_oaGroupObject),
    0,
    (destructor)oaObserver_oaGroup_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaGroup_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaGroup_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaGroup_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaGroup_oaGroupModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaGroup_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaGroup_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaGroup_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaGroup\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaGroup",
           (PyObject*)(&PyoaObserver_oaGroup_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaGroup\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaGroupMember
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaGroupMember_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaGroupMember_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaGroupMemberObject* self = (PyoaObserver_oaGroupMemberObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaGroupMember(p1.Data());
            }
            else {
                pyv_oaObserver_oaGroupMember* p=new pyv_oaObserver_oaGroupMember(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaGroupMember(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaGroupMember* p=new pyv_oaObserver_oaGroupMember(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaGroupMember)
    {
        PyParamoaObserver_oaGroupMember p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaGroupMember_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaGroupMember(p1.Data());
            }
            else {
                pyv_oaObserver_oaGroupMember* p=new pyv_oaObserver_oaGroupMember(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaGroupMember, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaGroupMember)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaGroupMember_tp_dealloc(PyoaObserver_oaGroupMemberObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaGroupMember*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaGroupMember_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaGroupMember value;
    int convert_status=PyoaObserver_oaGroupMember_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[46];
    sprintf(buffer,"<oaObserver_oaGroupMember::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaGroupMember_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaGroupMember v1;
    PyParamoaObserver_oaGroupMember v2;
    int convert_status1=PyoaObserver_oaGroupMember_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaGroupMember_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaGroupMember_Convert(PyObject* ob,PyParamoaObserver_oaGroupMember* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaGroupMember_Check(ob)) {
        result->SetData( (oaObserver_oaGroupMember*) ((PyoaObserver_oaGroupMemberObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaGroupMember Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaGroupMember_FromoaObserver_oaGroupMember(oaObserver_oaGroupMember* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaGroupMember_Type.tp_alloc(&PyoaObserver_oaGroupMember_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaGroupMemberObject* self = (PyoaObserver_oaGroupMemberObject*)bself;
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
pyv_oaObserver_oaGroupMember::pyv_oaObserver_oaGroupMember(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaGroupMember(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaGroupMember::pyv_oaObserver_oaGroupMember(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaGroupMember(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaGroupMember::pyv_oaObserver_oaGroupMember(const oaObserver_oaGroupMember& p)
 : pyob(NULL),
   oaObserver_oaGroupMember(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGroupMember::onPostCreate(oaGroupMember* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGroupMember::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaGroupMember_FromoaGroupMember(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGroupMember::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGroupMember::onPostModify(oaGroupMember* p1,oaGroupMemberModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGroupMember::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaGroupMember_FromoaGroupMember(p1));
    PyTuple_SetItem(args,1,PyoaGroupMemberModTypeEnum_FromoaGroupMemberModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGroupMember::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGroupMember::onPreDestroy(oaGroupMember* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGroupMember::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaGroupMember_FromoaGroupMember(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGroupMember::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGroupMember::onPreModify(oaGroupMember* p1,oaGroupMemberModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGroupMember::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaGroupMember_FromoaGroupMember(p1));
    PyTuple_SetItem(args,1,PyoaGroupMemberModTypeEnum_FromoaGroupMemberModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGroupMember::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaGroupMember_doc[] = 
"Class: oaObserver_oaGroupMember\n"
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
"    Calls: oaObserver_oaGroupMember(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaGroupMember||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaGroupMember\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaGroupMember(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaGroupMember||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaGroupMember\n"
"  Paramegers: (oaObserver_oaGroupMember)\n"
"    Calls: (const oaObserver_oaGroupMember&)\n"
"    Signature: oaObserver_oaGroupMember||cref-oaObserver_oaGroupMember,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaGroupMember_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaGroupMember",
    sizeof(PyoaObserver_oaGroupMemberObject),
    0,
    (destructor)oaObserver_oaGroupMember_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaGroupMember_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaGroupMember_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaGroupMember_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaGroupMember_oaGroupMemberModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaGroupMember_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaGroupMember_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaGroupMember_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaGroupMember\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaGroupMember",
           (PyObject*)(&PyoaObserver_oaGroupMember_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaGroupMember\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaGuide
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaGuide_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaGuide_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaGuideObject* self = (PyoaObserver_oaGuideObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaGuide(p1.Data());
            }
            else {
                pyv_oaObserver_oaGuide* p=new pyv_oaObserver_oaGuide(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaGuide(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaGuide* p=new pyv_oaObserver_oaGuide(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaGuide)
    {
        PyParamoaObserver_oaGuide p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaGuide_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaGuide(p1.Data());
            }
            else {
                pyv_oaObserver_oaGuide* p=new pyv_oaObserver_oaGuide(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaGuide, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaGuide)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaGuide_tp_dealloc(PyoaObserver_oaGuideObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaGuide*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaGuide_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaGuide value;
    int convert_status=PyoaObserver_oaGuide_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[40];
    sprintf(buffer,"<oaObserver_oaGuide::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaGuide_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaGuide v1;
    PyParamoaObserver_oaGuide v2;
    int convert_status1=PyoaObserver_oaGuide_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaGuide_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaGuide_Convert(PyObject* ob,PyParamoaObserver_oaGuide* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaGuide_Check(ob)) {
        result->SetData( (oaObserver_oaGuide*) ((PyoaObserver_oaGuideObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaGuide Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaGuide_FromoaObserver_oaGuide(oaObserver_oaGuide* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaGuide_Type.tp_alloc(&PyoaObserver_oaGuide_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaGuideObject* self = (PyoaObserver_oaGuideObject*)bself;
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
pyv_oaObserver_oaGuide::pyv_oaObserver_oaGuide(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaGuide(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaGuide::pyv_oaObserver_oaGuide(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaGuide(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaGuide::pyv_oaObserver_oaGuide(const oaObserver_oaGuide& p)
 : pyob(NULL),
   oaObserver_oaGuide(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGuide::onPostCreate(oaGuide* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGuide::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaGuide_FromoaGuide(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGuide::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGuide::onPostModify(oaGuide* p1,oaGuideModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGuide::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaGuide_FromoaGuide(p1));
    PyTuple_SetItem(args,1,PyoaGuideModTypeEnum_FromoaGuideModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGuide::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGuide::onPreDestroy(oaGuide* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGuide::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaGuide_FromoaGuide(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGuide::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaGuide::onPreModify(oaGuide* p1,oaGuideModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaGuide::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaGuide_FromoaGuide(p1));
    PyTuple_SetItem(args,1,PyoaGuideModTypeEnum_FromoaGuideModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaGuide::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaGuide_doc[] = 
"Class: oaObserver_oaGuide\n"
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
"    Calls: oaObserver_oaGuide(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaGuide||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaGuide\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaGuide(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaGuide||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaGuide\n"
"  Paramegers: (oaObserver_oaGuide)\n"
"    Calls: (const oaObserver_oaGuide&)\n"
"    Signature: oaObserver_oaGuide||cref-oaObserver_oaGuide,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaGuide_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaGuide",
    sizeof(PyoaObserver_oaGuideObject),
    0,
    (destructor)oaObserver_oaGuide_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaGuide_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaGuide_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaGuide_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaGuide_oaGuideModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaGuide_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaGuide_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaGuide_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaGuide\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaGuide",
           (PyObject*)(&PyoaObserver_oaGuide_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaGuide\n");
       return -1;
    }
    return 0;
}


/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaObserver_oaHierProp
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaHierProp_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaObserver_oaHierProp_Type);
    PyObject* bself = type->tp_alloc(type,0);
    if (bself == NULL) return bself;
    PyoaObserver_oaHierPropObject* self = (PyoaObserver_oaHierPropObject*)bself;
    self->locks = NULL;
    self->borrow = 0;
    static char *kwlist [] = { NULL } ;
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            if (is_raw) {
                self->value = (oaBaseObserver*)  new oaObserver_oaHierProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaHierProp* p=new pyv_oaObserver_oaHierProp(p1.Data());
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
                self->value = (oaBaseObserver*)  new oaObserver_oaHierProp(p1.Data(),p2.Data());
            }
            else {
                pyv_oaObserver_oaHierProp* p=new pyv_oaObserver_oaHierProp(p1.Data(),p2.Data());
                p->pyob=self;
                self->value= (oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    // Case: (oaObserver_oaHierProp)
    {
        PyParamoaObserver_oaHierProp p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaObserver_oaHierProp_Convert,&p1)) {
            if (is_raw) {
                self->value=(oaBaseObserver*)  new oaObserver_oaHierProp(p1.Data());
            }
            else {
                pyv_oaObserver_oaHierProp* p=new pyv_oaObserver_oaHierProp(p1.Data());
            p->pyob=self;
                self->value=(oaBaseObserver*) p;
            }
            return bself;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaObserver_oaHierProp, Choices are:\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaBoolean)\n"
        "    (oaObserver_oaHierProp)\n"
    );
    Py_DECREF(self);
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static void
oaObserver_oaHierProp_tp_dealloc(PyoaObserver_oaHierPropObject* self)
{
    if (!self->borrow) {
        delete (oaObserver_oaHierProp*)(self->value);
    }
    Py_XDECREF(self->locks);
    self->ob_type->tp_free((PyObject*)self);
}

// ------------------------------------------------------------------
static PyObject*
oaObserver_oaHierProp_tp_repr(PyObject *ob)
{
    PyParamoaObserver_oaHierProp value;
    int convert_status=PyoaObserver_oaHierProp_Convert(ob,&value);
    assert(convert_status!=0);
    PyObject* result;

    char buffer[43];
    sprintf(buffer,"<oaObserver_oaHierProp::" DISPLAY_FORMAT ">",POINTER_AS_DISPLAY(value.DataCall()));
    result=PyString_FromString(buffer);
    return result;
}
        
// ------------------------------------------------------------------
static int
oaObserver_oaHierProp_tp_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaObserver_oaHierProp v1;
    PyParamoaObserver_oaHierProp v2;
    int convert_status1=PyoaObserver_oaHierProp_Convert(ob1,&v1);
    int convert_status2=PyoaObserver_oaHierProp_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    if (v1.DataCall()==v2.DataCall()) return 0;
    return 1;
}
        
// ------------------------------------------------------------------
int
PyoaObserver_oaHierProp_Convert(PyObject* ob,PyParamoaObserver_oaHierProp* result)
{
    if (ob == NULL) return 1;
    if (PyoaObserver_oaHierProp_Check(ob)) {
        result->SetData( (oaObserver_oaHierProp*) ((PyoaObserver_oaHierPropObject*)ob)->value);
        return 1;
    }
    PyErr_SetString(PyExc_TypeError,
        "Convertion of parameter to class: oaObserver_oaHierProp Failed");
    return 0;
}
// ------------------------------------------------------------------
PyObject* PyoaObserver_oaHierProp_FromoaObserver_oaHierProp(oaObserver_oaHierProp* data,int borrow,PyObject* lock)
{
    if (data) {
        PyObject* bself = PyoaObserver_oaHierProp_Type.tp_alloc(&PyoaObserver_oaHierProp_Type,0);
        if (bself == NULL) return bself;
        PyoaObserver_oaHierPropObject* self = (PyoaObserver_oaHierPropObject*)bself;
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
pyv_oaObserver_oaHierProp::pyv_oaObserver_oaHierProp(oaUInt4 p1)
 : pyob(NULL),
   oaObserver_oaHierProp(p1)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaHierProp::pyv_oaObserver_oaHierProp(oaUInt4 p1,oaBoolean p2)
 : pyob(NULL),
   oaObserver_oaHierProp(p1,p2)
{
}

// ------------------------------------------------------------------
pyv_oaObserver_oaHierProp::pyv_oaObserver_oaHierProp(const oaObserver_oaHierProp& p)
 : pyob(NULL),
   oaObserver_oaHierProp(p)
{
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaHierProp::onPostCreate(oaHierProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostCreate");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaHierProp::onPostCreate was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaHierProp_FromoaHierProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaHierProp::onPostCreate had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaHierProp::onPostModify(oaHierProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPostModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaHierProp::onPostModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaHierProp_FromoaHierProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaHierProp::onPostModify had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaHierProp::onPreDestroy(oaHierProp* p1)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreDestroy");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaHierProp::onPreDestroy was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(1);
    PyTuple_SetItem(args,0,PyoaHierProp_FromoaHierProp(p1));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaHierProp::onPreDestroy had an error.");
    }
    Py_DECREF(result);
}

// ------------------------------------------------------------------
void pyv_oaObserver_oaHierProp::onPreModify(oaHierProp* p1,oaPropModTypeEnum p2)
{
    PyObject* md=PyObject_GetAttrString((PyObject*)pyob,"onPreModify");
    if (!PyCallable_Check(md)) {
        Py_DECREF(md);
        throw oaPythonException("Python Virtual Function oaObserver_oaHierProp::onPreModify was unable to find a callable python routine.");
    }
    PyObject* args=PyTuple_New(2);
    PyTuple_SetItem(args,0,PyoaHierProp_FromoaHierProp(p1));
    PyTuple_SetItem(args,1,PyoaPropModTypeEnum_FromoaPropModTypeEnum(p2));
    PyObject* result=PyObject_CallObject(md,args);
    Py_DECREF(md);
    Py_DECREF(args);
    if (result==NULL) {
        throw oaPythonException("Python Virtual Function oaObserver_oaHierProp::onPreModify had an error.");
    }
    Py_DECREF(result);
}


// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaObserver_oaHierProp_doc[] = 
"Class: oaObserver_oaHierProp\n"
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
"    Calls: oaObserver_oaHierProp(oaUInt4 priorityIn)\n"
"    Signature: oaObserver_oaHierProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaHierProp\n"
"  Paramegers: (oaUInt4,oaBoolean)\n"
"    Calls: oaObserver_oaHierProp(oaUInt4 priorityIn,oaBoolean enabledIn)\n"
"    Signature: oaObserver_oaHierProp||simple-oaUInt4,simple-oaBoolean,\n"
"    Constructor oaObserver_oaHierProp\n"
"  Paramegers: (oaObserver_oaHierProp)\n"
"    Calls: (const oaObserver_oaHierProp&)\n"
"    Signature: oaObserver_oaHierProp||cref-oaObserver_oaHierProp,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaObserver_oaHierProp_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaObserver_oaHierProp",
    sizeof(PyoaObserver_oaHierPropObject),
    0,
    (destructor)oaObserver_oaHierProp_tp_dealloc,	/* tp_dealloc */
    0,	/* tp_print */
    0,					/* tp_getattr */
    0,					/* tp_setattr */
    (cmpfunc)oaObserver_oaHierProp_tp_compare,	/* tp_compare */
    (reprfunc)oaObserver_oaHierProp_tp_repr,	/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    0,					/* tp_as_hash */
    0,					/* tp_as_call */
    0,					/* tp_str */
    0,					/* tp_getattro */
    0,					/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaObserver_oaHierProp_doc,	/* tp_doc */
    0,					/* tp_traverse */
    0,					/* tp_clear */
    0,					/* tp_richcompre */
    0,					/* tp_weaklistoffset */
    0,					/* tp_iter */
    0,					/* tp_iternext */
    0,					/* tp_methods */
    0,					/* tp_members */
    0,					/* tp_getset */
    &PyoaStdObserver_oaHierProp_oaPropModTypeEnum_Type,	/* tp_base */
    0,					/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    0,					/* tp_init */
    PyType_GenericAlloc,	/* tp_alloc */
    oaObserver_oaHierProp_new,	/* tp_new */
    _PyObject_Del,	/* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaObserver_oaHierProp_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaObserver_oaHierProp_Type)<0) {
      printf("** PyType_Ready failed for: oaObserver_oaHierProp\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaObserver_oaHierProp",
           (PyObject*)(&PyoaObserver_oaHierProp_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaObserver_oaHierProp\n");
       return -1;
    }
    return 0;
}
