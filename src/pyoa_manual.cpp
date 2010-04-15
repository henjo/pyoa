
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

// ------------------------------------------------------------------
// Code to Manually implement some wrappers
// ------------------------------------------------------------------

#include "pyoa_header.h"

// -----------------------------------------------------
// Externs
// -----------------------------------------------------
PyObject* openaccess_oaBaseInit(PyObject *self, PyObject *args)
{
  try {
    {
        if (PyArg_ParseTuple(args,"")) {
          oaBaseInit();
          Py_INCREF(Py_None);
          return Py_None;
        }
    }
    PyErr_Clear();
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaUInt4_Convert,&p1)) {
            oaBaseInit(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    {
        PyParamoaUInt4 p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,(char*)"O&O&",
              &PyoaUInt4_Convert,&p1,&PyoaUInt4_Convert,&p2)) {
            oaBaseInit(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    {
        PyParamoaUInt4 p1;
        PyParamoaUInt4 p2;
        PyParamoaUInt4 p3;
        if (PyArg_ParseTuple(args,(char*)"O&O&O&",
              &PyoaUInt4_Convert,&p1,&PyoaUInt4_Convert,&p2,&PyoaUInt4_Convert,&p3)) {
            oaBaseInit(p1.Data(),p2.Data(),p3.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found: oaBaseInit, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaUInt4)\n"
        "    (oaUInt4,oaUInt4,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* openaccess_oaTechInit(PyObject *self, PyObject *args)
{
  try {
    {
        if (PyArg_ParseTuple(args,"")) {
          oaTechInit();
          Py_INCREF(Py_None);
          return Py_None;
        }
    }
    PyErr_Clear();
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaUInt4_Convert,&p1)) {
            oaTechInit(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    {
        PyParamoaUInt4 p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,(char*)"O&O&",
              &PyoaUInt4_Convert,&p1,&PyoaUInt4_Convert,&p2)) {
            oaTechInit(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    {
        PyParamoaUInt4 p1;
        PyParamoaUInt4 p2;
        PyParamoaUInt4 p3;
        if (PyArg_ParseTuple(args,(char*)"O&O&O&",
              &PyoaUInt4_Convert,&p1,&PyoaUInt4_Convert,&p2,&PyoaUInt4_Convert,&p3)) {
            oaTechInit(p1.Data(),p2.Data(),p3.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found: oaTechInit, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaUInt4)\n"
        "    (oaUInt4,oaUInt4,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* openaccess_oaDesignInit(PyObject *self, PyObject *args)
{
  try {
    {
        if (PyArg_ParseTuple(args,"")) {
          oaDesignInit();
          Py_INCREF(Py_None);
          return Py_None;
        }
    }
    PyErr_Clear();
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaUInt4_Convert,&p1)) {
            oaDesignInit(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    {
        PyParamoaUInt4 p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,(char*)"O&O&",
              &PyoaUInt4_Convert,&p1,&PyoaUInt4_Convert,&p2)) {
            oaDesignInit(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    {
        PyParamoaUInt4 p1;
        PyParamoaUInt4 p2;
        PyParamoaUInt4 p3;
        if (PyArg_ParseTuple(args,(char*)"O&O&O&",
              &PyoaUInt4_Convert,&p1,&PyoaUInt4_Convert,&p2,&PyoaUInt4_Convert,&p3)) {
            oaDesignInit(p1.Data(),p2.Data(),p3.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found: oaDesignInit, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaUInt4)\n"
        "    (oaUInt4,oaUInt4,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* openaccess_oaDMInit(PyObject *self, PyObject *args)
{
  try {
    {
        if (PyArg_ParseTuple(args,"")) {
          oaDMInit();
          Py_INCREF(Py_None);
          return Py_None;
        }
    }
    PyErr_Clear();
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaUInt4_Convert,&p1)) {
            oaDMInit(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    {
        PyParamoaUInt4 p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,(char*)"O&O&",
              &PyoaUInt4_Convert,&p1,&PyoaUInt4_Convert,&p2)) {
            oaDMInit(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    {
        PyParamoaUInt4 p1;
        PyParamoaUInt4 p2;
        PyParamoaUInt4 p3;
        if (PyArg_ParseTuple(args,(char*)"O&O&O&",
              &PyoaUInt4_Convert,&p1,&PyoaUInt4_Convert,&p2,&PyoaUInt4_Convert,&p3)) {
            oaDMInit(p1.Data(),p2.Data(),p3.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found: oaDMInit, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaUInt4)\n"
        "    (oaUInt4,oaUInt4,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// ------------------------------------------------------------------
PyObject* openaccess_oaWaferInit(PyObject* ob, PyObject *args)
{
  try {
    {
        if (PyArg_ParseTuple(args,"")) {
          oaWaferInit();
          Py_INCREF(Py_None);
          return Py_None;
        }
    }
    PyErr_Clear();
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaUInt4_Convert,&p1)) {
            oaWaferInit(p1.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    {
        PyParamoaUInt4 p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,(char*)"O&O&",
              &PyoaUInt4_Convert,&p1,&PyoaUInt4_Convert,&p2)) {
            oaWaferInit(p1.Data(),p2.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    {
        PyParamoaUInt4 p1;
        PyParamoaUInt4 p2;
        PyParamoaUInt4 p3;
        if (PyArg_ParseTuple(args,(char*)"O&O&O&",
              &PyoaUInt4_Convert,&p1,&PyoaUInt4_Convert,&p2,&PyoaUInt4_Convert,&p3)) {
            oaWaferInit(p1.Data(),p2.Data(),p3.Data());
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found: oaWaferInit, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    (oaUInt4,oaUInt4)\n"
        "    (oaUInt4,oaUInt4,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// ------------------------------------------------------------------
static PyObject*
openaccess_oaStartDaemon(PyObject* ob, PyObject *args)
{
  try {
    char* p1;
    if (PyArg_ParseTuple(args,"s",&p1)) {
        oaStartDaemon(p1);
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// ==================================================================
// Special Iterators:
//   oaBoolean getNext(oaString)
// ==================================================================
// -----------------------------------------------------
// oaDirIter
// -----------------------------------------------------
PyObject* oaDirIter_iternext(PyObject *self)
{
  try {
    PyParamoaDirIter ob;
    int convert_status=PyoaDirIter_Convert(self,&ob);
    assert(convert_status!=0);
    oaString p1;
    oaBoolean result=ob.DataCall()->getNext(p1);
    if (!result) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaString_FromoaString(p1);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* oaDirIter_getNext(PyObject *self, PyObject *args)
{
  try {
    PyParamoaDirIter ob;
    int convert_status=PyoaDirIter_Convert(self,&ob);
    assert(convert_status!=0);

    oaString p1;
    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result=ob.DataCall()->getNext(p1);
        if (result) {
            return PyoaString_FromoaString(p1);
        }
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* oaDirIter_next(PyObject *self, PyObject *args)
{
  try {
    PyParamoaDirIter ob;
    int convert_status=PyoaDirIter_Convert(self,&ob);
    assert(convert_status!=0);

    oaString p1;
    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result=ob.DataCall()->getNext(p1);
        if (result) {
            return PyoaString_FromoaString(p1);
        }
        PyErr_SetObject(PyExc_StopIteration,Py_None);
        return NULL;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// -----------------------------------------------------
// oaEnumPropIter
// -----------------------------------------------------
PyObject* oaEnumPropIter_iternext(PyObject *self)
{
  try {
    PyParamoaEnumPropIter ob;
    int convert_status=PyoaEnumPropIter_Convert(self,&ob);
    assert(convert_status!=0);
    oaString p1;
    oaBoolean result=ob.DataCall()->getNext(p1);
    if (!result) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaString_FromoaString(p1);
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* oaEnumPropIter_getNext(PyObject *self, PyObject *args)
{
  try {
    PyParamoaEnumPropIter ob;
    int convert_status=PyoaEnumPropIter_Convert(self,&ob);
    assert(convert_status!=0);

    oaString p1;
    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result=ob.DataCall()->getNext(p1);
        if (result) {
            return PyoaString_FromoaString(p1);
        }
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* oaEnumPropIter_next(PyObject *self, PyObject *args)
{
  try {
    PyParamoaEnumPropIter ob;
    int convert_status=PyoaEnumPropIter_Convert(self,&ob);
    assert(convert_status!=0);

    oaString p1;
    if (PyArg_ParseTuple(args,"")) {
        oaBoolean result=ob.DataCall()->getNext(p1);
        if (result) {
            return PyoaString_FromoaString(p1);
        }
        PyErr_SetObject(PyExc_StopIteration,Py_None);
        return NULL;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ==================================================================
// Special Iterators:
//   oaObject* getNext(oaUInt4)
// ==================================================================
// -----------------------------------------------------
// oaMemNetIter
// -----------------------------------------------------
PyObject* oaMemNetIter_iternext(PyObject *self)
{
  try {
    PyParamoaMemNetIter ob;
    int convert_status=PyoaMemNetIter_Convert(self,&ob);
    assert(convert_status!=0);
    oaUInt4 p1;
    oaNet* result=ob.DataCall()->getNext(p1);
    if (!result) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    PyObject* lst=PyList_New(2);
    PyList_SetItem(lst,0,PyoaNet_FromoaNet(result));
    PyList_SetItem(lst,1,PyoaUInt4_FromoaUInt4(p1));
    return lst;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* oaMemNetIter_getNext(PyObject *self, PyObject *args)
{
  try {
    PyParamoaMemNetIter ob;
    int convert_status=PyoaMemNetIter_Convert(self,&ob);
    assert(convert_status!=0);

    oaUInt4 p1;
    if (PyArg_ParseTuple(args,"")) {
        oaNet* result=ob.DataCall()->getNext(p1);
        if (result) {
            PyObject* lst=PyList_New(2);
            PyList_SetItem(lst,0,PyoaNet_FromoaNet(result));
            PyList_SetItem(lst,1,PyoaUInt4_FromoaUInt4(p1));
            return lst;
        }
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* oaMemNetIter_next(PyObject *self, PyObject *args)
{
  try {
    PyParamoaMemNetIter ob;
    int convert_status=PyoaMemNetIter_Convert(self,&ob);
    assert(convert_status!=0);

    oaUInt4 p1;
    if (PyArg_ParseTuple(args,"")) {
        oaNet* result=ob.DataCall()->getNext(p1);
        if (result) {
            PyObject* lst=PyList_New(2);
            PyList_SetItem(lst,0,PyoaNet_FromoaNet(result));
            PyList_SetItem(lst,1,PyoaUInt4_FromoaUInt4(p1));
            return lst;
        }
        PyErr_SetObject(PyExc_StopIteration,Py_None);
        return NULL;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// -----------------------------------------------------
// oaModMemNetIter
// -----------------------------------------------------
PyObject* oaModMemNetIter_iternext(PyObject *self)
{
  try {
    PyParamoaModMemNetIter ob;
    int convert_status=PyoaModMemNetIter_Convert(self,&ob);
    assert(convert_status!=0);
    oaUInt4 p1;
    oaModNet* result=ob.DataCall()->getNext(p1);
    if (!result) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    PyObject* lst=PyList_New(2);
    PyList_SetItem(lst,0,PyoaModNet_FromoaModNet(result));
    PyList_SetItem(lst,1,PyoaUInt4_FromoaUInt4(p1));
    return lst;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* oaModMemNetIter_getNext(PyObject *self, PyObject *args)
{
  try {
    PyParamoaModMemNetIter ob;
    int convert_status=PyoaModMemNetIter_Convert(self,&ob);
    assert(convert_status!=0);

    oaUInt4 p1;
    if (PyArg_ParseTuple(args,"")) {
        oaModNet* result=ob.DataCall()->getNext(p1);
        if (result) {
            PyObject* lst=PyList_New(2);
            PyList_SetItem(lst,0,PyoaModNet_FromoaModNet(result));
            PyList_SetItem(lst,1,PyoaUInt4_FromoaUInt4(p1));
            return lst;
        }
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* oaModMemNetIter_next(PyObject *self, PyObject *args)
{
  try {
    PyParamoaModMemNetIter ob;
    int convert_status=PyoaModMemNetIter_Convert(self,&ob);
    assert(convert_status!=0);

    oaUInt4 p1;
    if (PyArg_ParseTuple(args,"")) {
        oaModNet* result=ob.DataCall()->getNext(p1);
        if (result) {
            PyObject* lst=PyList_New(2);
            PyList_SetItem(lst,0,PyoaModNet_FromoaModNet(result));
            PyList_SetItem(lst,1,PyoaUInt4_FromoaUInt4(p1));
            return lst;
        }
        PyErr_SetObject(PyExc_StopIteration,Py_None);
        return NULL;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// -----------------------------------------------------
// oaOccMemNetIter
// -----------------------------------------------------
PyObject* oaOccMemNetIter_iternext(PyObject *self)
{
  try {
    PyParamoaOccMemNetIter ob;
    int convert_status=PyoaOccMemNetIter_Convert(self,&ob);
    assert(convert_status!=0);
    oaUInt4 p1;
    oaOccNet* result=ob.DataCall()->getNext(p1);
    if (!result) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    PyObject* lst=PyList_New(2);
    PyList_SetItem(lst,0,PyoaOccNet_FromoaOccNet(result));
    PyList_SetItem(lst,1,PyoaUInt4_FromoaUInt4(p1));
    return lst;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* oaOccMemNetIter_getNext(PyObject *self, PyObject *args)
{
  try {
    PyParamoaOccMemNetIter ob;
    int convert_status=PyoaOccMemNetIter_Convert(self,&ob);
    assert(convert_status!=0);

    oaUInt4 p1;
    if (PyArg_ParseTuple(args,"")) {
        oaOccNet* result=ob.DataCall()->getNext(p1);
        if (result) {
            PyObject* lst=PyList_New(2);
            PyList_SetItem(lst,0,PyoaOccNet_FromoaOccNet(result));
            PyList_SetItem(lst,1,PyoaUInt4_FromoaUInt4(p1));
            return lst;
        }
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* oaOccMemNetIter_next(PyObject *self, PyObject *args)
{
  try {
    PyParamoaOccMemNetIter ob;
    int convert_status=PyoaOccMemNetIter_Convert(self,&ob);
    assert(convert_status!=0);

    oaUInt4 p1;
    if (PyArg_ParseTuple(args,"")) {
        oaOccNet* result=ob.DataCall()->getNext(p1);
        if (result) {
            PyObject* lst=PyList_New(2);
            PyList_SetItem(lst,0,PyoaOccNet_FromoaOccNet(result));
            PyList_SetItem(lst,1,PyoaUInt4_FromoaUInt4(p1));
            return lst;
        }
        PyErr_SetObject(PyExc_StopIteration,Py_None);
        return NULL;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ==================================================================
// Special Iterators:
//   oaObjectRef getNext()
// ==================================================================
// -----------------------------------------------------
// oaDMObjectStatusRefIter
// -----------------------------------------------------
PyObject* oaDMObjectStatusRefIter_iternext(PyObject *self)
{
  try {
    PyParamoaDMObjectStatusRefIter ob;
    int convert_status=PyoaDMObjectStatusRefIter_Convert(self,&ob);
    assert(convert_status!=0);
    oaDMObjectStatusRef result=ob.DataCall()->getNext();
    if (result.getObject()==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaDMObjectStatusRef_FromoaDMObjectStatusRef(new oaDMObjectStatusRef(result));
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* oaDMObjectStatusRefIter_getNext(PyObject *self, PyObject *args)
{
  try {
    PyParamoaDMObjectStatusRefIter ob;
    int convert_status=PyoaDMObjectStatusRefIter_Convert(self,&ob);
    assert(convert_status!=0);

    if (PyArg_ParseTuple(args,"")) {
        oaDMObjectStatusRef result=ob.DataCall()->getNext();
        if (result.getObject()!=NULL) {
            return PyoaDMObjectStatusRef_FromoaDMObjectStatusRef(new oaDMObjectStatusRef(result));
        }
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* oaDMObjectStatusRefIter_next(PyObject *self, PyObject *args)
{
  try {
    PyParamoaDMObjectStatusRefIter ob;
    int convert_status=PyoaDMObjectStatusRefIter_Convert(self,&ob);
    assert(convert_status!=0);

    oaString p1;
    if (PyArg_ParseTuple(args,"")) {
        oaDMObjectStatusRef result=ob.DataCall()->getNext();
        if (result.getObject()!=NULL) {
            return PyoaDMObjectStatusRef_FromoaDMObjectStatusRef(new oaDMObjectStatusRef(result));
        }
        PyErr_SetObject(PyExc_StopIteration,Py_None);
        return NULL;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// -----------------------------------------------------
// oaDMObjectVersionRefIter
// -----------------------------------------------------
PyObject* oaDMObjectVersionRefIter_iternext(PyObject *self)
{
  try {
    PyParamoaDMObjectVersionRefIter ob;
    int convert_status=PyoaDMObjectVersionRefIter_Convert(self,&ob);
    assert(convert_status!=0);
    oaDMObjectVersionRef result=ob.DataCall()->getNext();
    if (result.getObject()==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaDMObjectVersionRef_FromoaDMObjectVersionRef(new oaDMObjectVersionRef(result));
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* oaDMObjectVersionRefIter_getNext(PyObject *self, PyObject *args)
{
  try {
    PyParamoaDMObjectVersionRefIter ob;
    int convert_status=PyoaDMObjectVersionRefIter_Convert(self,&ob);
    assert(convert_status!=0);

    if (PyArg_ParseTuple(args,"")) {
        oaDMObjectVersionRef result=ob.DataCall()->getNext();
        if (result.getObject()!=NULL) {
            return PyoaDMObjectVersionRef_FromoaDMObjectVersionRef(new oaDMObjectVersionRef(result));
        }
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* oaDMObjectVersionRefIter_next(PyObject *self, PyObject *args)
{
  try {
    PyParamoaDMObjectVersionRefIter ob;
    int convert_status=PyoaDMObjectVersionRefIter_Convert(self,&ob);
    assert(convert_status!=0);

    oaString p1;
    if (PyArg_ParseTuple(args,"")) {
        oaDMObjectVersionRef result=ob.DataCall()->getNext();
        if (result.getObject()!=NULL) {
            return PyoaDMObjectVersionRef_FromoaDMObjectVersionRef(new oaDMObjectVersionRef(result));
        }
        PyErr_SetObject(PyExc_StopIteration,Py_None);
        return NULL;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// -----------------------------------------------------
// oaVCVersionIter
// -----------------------------------------------------
PyObject* oaVCVersionIter_iternext(PyObject *self)
{
  try {
    PyParamoaVCVersionIter ob;
    int convert_status=PyoaVCVersionIter_Convert(self,&ob);
    assert(convert_status!=0);
    oaVCVersion result=ob.DataCall()->getNext();
    if (result.getRaw()==NULL) {
       PyErr_SetObject(PyExc_StopIteration,Py_None);
       return NULL;
    }
    return PyoaVCVersion_FromoaVCVersion(new oaVCVersion(result));
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* oaVCVersionIter_getNext(PyObject *self, PyObject *args)
{
  try {
    PyParamoaVCVersionIter ob;
    int convert_status=PyoaVCVersionIter_Convert(self,&ob);
    assert(convert_status!=0);

    if (PyArg_ParseTuple(args,"")) {
        oaVCVersion result=ob.DataCall()->getNext();
        if (result.getRaw()!=NULL) {
            return PyoaVCVersion_FromoaVCVersion(new oaVCVersion(result));
        }
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// -----------------------------------------------------
PyObject* oaVCVersionIter_next(PyObject *self, PyObject *args)
{
  try {
    PyParamoaVCVersionIter ob;
    int convert_status=PyoaVCVersionIter_Convert(self,&ob);
    assert(convert_status!=0);

    oaString p1;
    if (PyArg_ParseTuple(args,"")) {
        oaVCVersion result=ob.DataCall()->getNext();
        if (result.getRaw()!=NULL) {
            return PyoaVCVersion_FromoaVCVersion(new oaVCVersion(result));
        }
        PyErr_SetObject(PyExc_StopIteration,Py_None);
        return NULL;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}


// -----------------------------------------------------
// oaRegionQuery_get_getTopCellView
// -----------------------------------------------------
#if 0
PyObject* oaRegionQuery_getTopCellView(PyObject *self, PyObject *args)
{
  try {
    oaRegionQuery* ob;
    int convert_status=PyoaRegionQuery_Convert(self,&ob);
        assert(convert_status!=0);

    if (PyArg_ParseTuple(args,"")) {
        oaCellView* result;
        result=(oaCellView*) ob->getTopCellView(); // Remove Const
        return PyoaCellView_FromoaCellView(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
#endif

// -----------------------------------------------------
// TBD
PyObject* oaBuildInfo_static_getPackages(PyObject *self, PyObject *args)
{
  Py_INCREF(Py_None);
  return Py_None;
}

// -----------------------------------------------------
// This needs a type cast
PyObject*
oaTech_getAppDefsByDataTypeIter(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaTech data;
    int convert_status=PyoaTech_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaTechObject* self=(PyoaTechObject*)ob;
    if (!PyValidateDbObject(data.Data(),0)) return NULL;

    PyParamoaTechDataType p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaTechDataType_Convert,&p1)) {
        oaIter_oaAppDef* result= new oaIter_oaAppDef(
          // Add required typecast
          (const oaCollection<oaAppDef, oaObject>&)
          (data.DataCall()->getAppDefsByDataType(p1.Data())));
        return PyoaIter_oaAppDef_FromoaIter_oaAppDef(result,0,NULL);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
