
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
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
// Utility code for type convertion of low level oa types
// ------------------------------------------------------------------

#include "pyoa_header.h"

typedef oaChar* oaChar_p;
typedef char* char_p;

// -----------------------------------------------------
// Exception
// -----------------------------------------------------
PyObject* PyExec_OpenAccess=NULL;

void PyErr_OpenAccess(const oaException& exc)
{
    PyObject* lst=PyTuple_New(2);
    PyTuple_SetItem(lst,0,PyInt_FromLong(exc.getMsgId()));
    PyTuple_SetItem(lst,1,
                    PyString_FromStringAndSize((char*)(const char*)exc.getMsg(),
                                               exc.getMsg().getLength()));
    PyErr_SetObject(PyExec_OpenAccess,lst);
    Py_XDECREF(lst);
}


// -----------------------------------------------------
// None
// -----------------------------------------------------
int PyNone_Convert(PyObject* obj,void* result)
{
  if (obj == Py_None) return 1;
  return 0;
}
// -----------------------------------------------------
// int
// -----------------------------------------------------
int Pyint_Convert(PyObject* obj,int* result)
{
  long val = PyInt_AsLong(obj);
  if (val==-1 && PyErr_Occurred()) return 0;

  if ( ((long)(int) val) != val) {
    PyErr_SetString(PyExc_TypeError,
                     "value is out of range for int");
    return 0;
  }
  *result=val;
  return 1;
}

PyObject* Pyint_Fromint(int value)
{
  return PyInt_FromLong(value);
}

// -----------------------------------------------------
// char
// -----------------------------------------------------
int Pychar_Convert(PyObject* obj,char* result)
{
  if (PyString_Check(obj)) {
    Pyoa_ssize_t len;
    char* s;
    if (PyString_AsStringAndSize(obj,&s,&len)) return 0;
    if (len!=1) {
      PyErr_SetString(PyExc_TypeError,
                      "string of length 1 required for oaChar");
      return 0;
    }
    *result=s[0];
    return 1;
  }
  if (PyInt_Check(obj)) {
    long val = PyInt_AsLong(obj);
    if (val==-1 && PyErr_Occurred()) return 0;
    char value=char(val);
    if ( ((long)value) != val) {
      PyErr_SetString(PyExc_TypeError,
                     "value is out of range for char");
      return 0;
    }
    *result=value;
    return 1;
  }
  PyErr_SetString(PyExc_TypeError,
                     "string of length 1 or int required for oaChar");
  return 0;
}

PyObject* Pychar_Fromchar(char value)
{
  char str[4];
  str[0]=value;
  return PyString_FromStringAndSize(str,1);
}

int Pychar_Array_Convert(PyObject* ob,char_Array* result)
{
  if (PyString_Check(ob)) {
    Pyoa_ssize_t len;
    char* s;
    if (PyString_AsStringAndSize(ob,&s,&len)) return 0;
    result->Init(s,len);
    return 1;
  }
  PyErr_SetString(PyExc_TypeError,
                     "string required for char*");
  return 0;
}

PyObject* Pychar_Array_Fromchar_Array(const char_Array& value)
{
  PyObject* result=PyString_FromString((char*)value.data);
  return result;
}

PyObject* Pychar_Array_Fromchar_Array(const char* value,int len,PyObject* lock)
{
  PyObject* result=PyString_FromString((char*)value);
  return result;
}

// -----------------------------------------------------
// charp
// -----------------------------------------------------
int Pycharp_Convert(PyObject* obj,PyParamcharp* result)
{
  if (!PyString_Check(obj)) {
     PyErr_SetString(PyExc_TypeError,
                     "string value required for charp");
  }
  int len=PyString_Size(obj);
  charp data=new char[len+1];
  memcpy(data,PyString_AsString(obj),len);
  data[len]='\0';
  *result=data;
  return 1;
}

PyObject* Pycharp_Fromcharp(charp value)
{
  return PyString_FromString(value);
}

int Pycharp_Array_Convert(PyObject* ob,PyParamcharp_Array* result)
{
  if (PyList_Check(ob)) {
    int len=PyList_Size(ob);
    result->SetLen(len);
    PyParamcharp data;
    for(int i=0;i<len;i++) {
      PyObject* a=PyList_GetItem(ob,i);
      if (!Pycharp_Convert(a,&data)) return 0;
      result->SetItem(i,data);
    }
  }
  else if (PyTuple_Check(ob)) {
    int len=PyTuple_Size(ob);
    result->SetLen(len);
    PyParamcharp data;
    for(int i=0;i<len;i++) {
      PyObject* a=PyTuple_GetItem(ob,i);
      if (!Pycharp_Convert(a,&data)) return 0;
      result->SetItem(i,data);
    }
  }
  else {
    PyErr_SetString(PyExc_TypeError,
      "strings required as all members of charp_Array");
    return 0;
  }
  return 1;
}

PyObject* Pycharp_Array_Fromcharp_Array(const Pycharp_Array& value)
{
  int i;
  PyObject* lst=PyList_New(value.Len());
  for(i=0;i<value.Len();i++) {
    PyObject* ob=Pycharp_Fromcharp(value.GetItem(i));
    PyList_SetItem(lst,i,ob);
  }
  return lst;
}

// -----------------------------------------------------
// oaPythonException
// -----------------------------------------------------
oaPythonException::oaPythonException(const char* _msg)
  : oaException(oaUInt4(oacOSError))
{
  msg="Python Error: ";
  msg+=_msg;
  if (PyErr_Occurred()) {
    PyErr_Print();
  }
}
const oaString& oaPythonException::getFormatString() const
{
  static oaString value("Python Error: %s");
  return value;
}

// -----------------------------------------------------
// ObjectLocks
// -----------------------------------------------------
void PyoaLockObject(PyObject*& lst,PyObject* obj)
{
    if (lst==NULL) {
        lst=PyList_New(0);
    }
    PyList_Append(lst,obj);
}
// -----------------------------------------------------
// ValidateDb
// -----------------------------------------------------
int PyValidateDbObject(oaObject* ob,int param)
{
    if (ob) return 1;
    if (param==0)
        PyErr_SetString(PyExc_TypeError,
               "A Function call is not valid with a Null oaObject");
    else {
        char buffer[80];
        sprintf(buffer,"A NULL oaObject is not allowed for parameter %d",param);
        PyErr_SetString(PyExc_TypeError,buffer);
    }
    return 0;
}
int PyValidateDbObject(oaVCSystem* ob,int param)
{
    if (ob) return 1;
    if (param==0)
        PyErr_SetString(PyExc_TypeError,
               "A Function call is not valid with a Null oaVCSystem");
    else {
        char buffer[80];
        sprintf(buffer,"A NULL oaVCSystem is not allowed for parameter %d",param);
        PyErr_SetString(PyExc_TypeError,buffer);
    }
    return 0;
}
int PyValidateDbObject(oaEvalTextLink* ob,int param)
{
    if (ob) return 1;
    if (param==0)
        PyErr_SetString(PyExc_TypeError,
               "A Function call is not valid with a Null oaEvalTextLink");
    else {
        char buffer[80];
        sprintf(buffer,"A NULL oaEvalTextLink is not allowed for parameter %d",param);
        PyErr_SetString(PyExc_TypeError,buffer);
    }
    return 0;
}
int PyValidateDbObject(oaPcellLink* ob,int param)
{
    if (ob) return 1;
    if (param==0)
        PyErr_SetString(PyExc_TypeError,
               "A Function call is not valid with a Null oaPcellLink");
    else {
        char buffer[80];
        sprintf(buffer,"A NULL oaPcellLink is not allowed for parameter %d",param);
        PyErr_SetString(PyExc_TypeError,buffer);
    }
    return 0;
}
int PyValidateDbObject(oaBuildInfo* ob,int param)
{
    if (ob) return 1;
    if (param==0)
        PyErr_SetString(PyExc_TypeError,
               "A Function call is not valid with a Null oaBuildInfo");
    else {
        char buffer[80];
        sprintf(buffer,"A NULL oaBuildInfo is not allowed for parameter %d",param);
        PyErr_SetString(PyExc_TypeError,buffer);
    }
    return 0;
}

