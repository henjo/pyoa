
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#include "pyoa_header.h"


// ==================================================================
// Wrapper Implementation for Class: oaString
// ==================================================================


// ==================================================================
// Alloc/Dealloc Routines
// ==================================================================

// ------------------------------------------------------------------
static PyObject*
oaString_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
  try {
    int is_raw=(type==&PyoaString_Type);
    PyObject* gself = type->tp_alloc(type,0);
    if (gself == NULL) return gself;
    PyoaStringObject* self = (PyoaStringObject*)gself;
    self->data = '\0';
    self->value = &(self->data);
    self->borrow = 0;
    self->locks=NULL;
    static char *kwlist [] = { NULL } ;
    // Case: ()
    {
        if (PyArg_ParseTuple(args,"")) {
            return gself;
        }
    }
    PyErr_Clear();
    // Case: (oaUInt4)
    {
        PyParamoaUInt4 p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaUInt4_Convert,&p1)) {
            self->data = oaString(p1.Data());
            return gself;
        }
    }
    PyErr_Clear();
    // Case: ([char])
    {
        PyParamchar_Array p1;
        if (PyArg_ParseTuple(args,"O&",
              &Pychar_Array_Convert,&p1)) {
            self->data = oaString(p1.Data());
            return gself;
        }
    }
    PyErr_Clear();
    // Case: ([char],oaUInt4)
    {
        PyParamchar_Array p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &Pychar_Array_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            self->data = oaString(p1.Data(),p2.Data());
            return gself;
        }
    }
    PyErr_Clear();
    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,(char*)"O&",
              &PyoaString_Convert,&p1)) {
            self->data=p1.Data();
            return gself;
        }
    }
    // Error
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Constructor found for class: oaString, Choices are:\n"
        "    ()\n"
        "    (oaUInt4)\n"
        "    ([char])\n"
        "    ([char],oaUInt4)\n"
        "    (oaString)\n"
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
oaString_dealloc(PyObject* gself)
{
    PyoaStringObject* self = (PyoaStringObject*)gself;
    Py_XDECREF(self->locks);
    self->ob_type->tp_free(gself);
}

// ------------------------------------------------------------------
static PyObject*
oaString_str(PyObject *ob)
{
    PyParamoaString value;
    int convert_status=PyoaString_Convert(ob,&value);
    assert(convert_status!=0);
    return PyString_FromString((const char*)(value.Data()));
}
// ------------------------------------------------------------------
static PyObject*
oaString_repr(PyObject *ob)
{
    PyObject* str=oaString_str(ob);
    PyObject* result=PyObject_Repr(str);
    Py_DECREF(str);
    return result;
}

// ------------------------------------------------------------------
static int
oaString_compare(PyObject *ob1,PyObject* ob2)
{
    PyParamoaString v1;
    PyParamoaString v2;
    int convert_status1=PyoaString_Convert(ob1,&v1);
    int convert_status2=PyoaString_Convert(ob2,&v2);
    assert(convert_status1!=0);
    assert(convert_status2!=0);
    return strcmp(v1.Data(),v2.Data());
}

// ------------------------------------------------------------------
int
PyoaString_Convert(PyObject* ob,PyParamoaString* result)
{
  if (ob == NULL) return 1;
  if (PyoaString_Check(ob)) {
    result->SetData(((PyoaStringObject*)ob)->value);
    return 1;
  }
  if (PyString_Check(ob)) {
    Pyoa_ssize_t len;
    char* s;
    if (PyString_AsStringAndSize(ob,&s,&len)) return 0;
    result->GiveData(new oaString(s));
    return 1;
  }
  PyErr_SetString(PyExc_TypeError,
      "Convertion of parameter to class: oaString Failed");
  return 0;
}

// ------------------------------------------------------------------
int
PyoaString_ConvertAof(PyObject* ob,PyParamoaString* result)
{
  if (ob == NULL) return 1;
  if (ob==Py_None) {
    result->SetData(NULL);
    return 1;
  }
  if (PyoaString_Check(ob)) {
    result->SetData(((PyoaStringObject*)ob)->value);
    return 1;
  }
  if (PyString_Check(ob)) {
    Pyoa_ssize_t len;
    char* s;
    if (PyString_AsStringAndSize(ob,&s,&len)) return 0;
    result->GiveData(new oaString(s));
    return 1;
  }
  PyErr_SetString(PyExc_TypeError,
      "Convertion of parameter to class: oaString Failed");
  return 0;
}

// ------------------------------------------------------------------
PyObject* PyoaString_FromoaString(const oaString& value)
{
  PyObject* gself = PyoaString_Type.tp_alloc(&PyoaString_Type,0);
  if (gself == NULL) return gself;
  PyoaStringObject* self = (PyoaStringObject*)gself;
  self->data = value;
  self->value = &(self->data);
  self->borrow = 0;
  self->locks=NULL;
  return gself;
}

// ------------------------------------------------------------------
PyObject* PyoaString_FromoaString(oaString* value,int borrow,PyObject* lock)
{
  PyObject* gself = PyoaString_Type.tp_alloc(&PyoaString_Type,0);
  if (gself == NULL) return gself;
  PyoaStringObject* self = (PyoaStringObject*)gself;
  //self->data = ; // Default intizialize
  self->value = value;
  self->borrow = borrow;
  self->locks=NULL;
  if (lock) PyoaLockObject(self->locks,lock);
  return gself;
}

// ------------------------------------------------------------------
// Methods
// ------------------------------------------------------------------
static char oaString_assign_doc[] =
"Class: oaString, Function: assign\n"
"  Paramegers: (oaString)\n"
"    This function assigns the current value.\n"
;

static PyObject*
oaString_assign(PyObject* ob, PyObject *args)
{
  PyParamoaString data;
  int convert_status=PyoaString_Convert(ob,&data);
  try {
    PyParamoaString p1;
    if (PyArg_ParseTuple(args,(char*)"O&",
          &PyoaString_Convert,&p1)) {
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
static char oaString_str_doc[] =
"Class: oaString, Function: str\n"
"  Paramegers: ()\n"
"    This function returns the current value as a string.\n"
;

static PyObject*
oaString_str(PyObject* ob, PyObject *args)
{
  PyParamoaString data;
  int convert_status=PyoaString_Convert(ob,&data);
  try {
    if (PyArg_ParseTuple(args,(char*)"")) {
      return PyString_FromString((const char*)(data.Data()));
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}
// ------------------------------------------------------------------
static char oaString_getLength_doc[] =
"Class: oaString, Function: getLength\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getLength() const\n"
"    Signature: getLength|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the length of this string. The value represents the number of characters in this string excluding the trailing NULL character.\n"
;

static PyObject*
oaString_getLength(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString data;
    int convert_status=PyoaString_Convert(ob,&data);
    assert(convert_status!=0);

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
static char oaString_getSize_doc[] =
"Class: oaString, Function: getSize\n"
"  Paramegers: ()\n"
"    Calls: oaUInt4 getSize() const\n"
"    Signature: getSize|simple-oaUInt4|\n"
"    BrowseData: 1\n"
"    This function returns the size of the space allocated by this oaString.\n"
;

static PyObject*
oaString_getSize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString data;
    int convert_status=PyoaString_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaStringObject* self=(PyoaStringObject*)ob;

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
static char oaString_index_doc[] =
"Class: oaString, Function: index\n"
"  Paramegers: (char)\n"
"    Calls: oaUInt4 index(char c) const\n"
"    Signature: index|simple-oaUInt4|simple-char,simple-oaUInt4,\n"
"    This function searches this string and returns an index to the first occurrence of the specified character. If the character is not found, the index to the terminating NULL character is returned. You can specify an optional initial offset into the string. Parameters: c The character to find\n"
"    offset The initial offset into the string\n"
"    Returns: An integer representing the position of the character in this string\n"
"  Paramegers: (char,oaUInt4)\n"
"    Calls: oaUInt4 index(char c,oaUInt4 offset) const\n"
"    Signature: index|simple-oaUInt4|simple-char,simple-oaUInt4,\n"
"    This function searches this string and returns an index to the first occurrence of the specified character. If the character is not found, the index to the terminating NULL character is returned. You can specify an optional initial offset into the string. Parameters: c The character to find\n"
"    offset The initial offset into the string\n"
"    Returns: An integer representing the position of the character in this string\n"
;

static PyObject*
oaString_index(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString data;
    int convert_status=PyoaString_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaStringObject* self=(PyoaStringObject*)ob;

    // Case: (char)
    {
        PyParamchar p1;
        if (PyArg_ParseTuple(args,"O&",
              &Pychar_Convert,&p1)) {
            oaUInt4 result= (data.DataCall()->index(p1));
            return PyoaUInt4_FromoaUInt4(result);
        }
    }
    PyErr_Clear();
    // Case: (char,oaUInt4)
    {
        PyParamchar p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &Pychar_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            oaUInt4 result= (data.DataCall()->index(p1,p2.Data()));
            return PyoaUInt4_FromoaUInt4(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaString, function: index, Choices are:\n"
        "    (char)\n"
        "    (char,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaString_isEmpty_doc[] =
"Class: oaString, Function: isEmpty\n"
"  Paramegers: ()\n"
"    Calls: oaBoolean isEmpty() const\n"
"    Signature: isEmpty|simple-oaBoolean|\n"
"    BrowseData: 1\n"
"    This function returns a boolean value that indicates if this string is empty.\n"
;

static PyObject*
oaString_isEmpty(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString data;
    int convert_status=PyoaString_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaStringObject* self=(PyoaStringObject*)ob;

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

// ------------------------------------------------------------------
static char oaString_resize_doc[] =
"Class: oaString, Function: resize\n"
"  Paramegers: (oaUInt4)\n"
"    Calls: void resize(oaUInt4 size)\n"
"    Signature: resize|void-void|simple-oaUInt4,\n"
"    This function increases the amount of space allocated by this string to newSize .\n"
;

static PyObject*
oaString_resize(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString data;
    int convert_status=PyoaString_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaStringObject* self=(PyoaStringObject*)ob;

    PyParamoaUInt4 p1;
    if (PyArg_ParseTuple(args,"O&",
          &PyoaUInt4_Convert,&p1)) {
        data.DataCall()->resize(p1.Data());
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaString_substr_doc[] =
"Class: oaString, Function: substr\n"
"  Paramegers: (oaString)\n"
"    Calls: oaUInt4 substr(const oaString& sub) const\n"
"    Signature: substr|simple-oaUInt4|cref-oaString,simple-oaUInt4,\n"
"    This function searches this string and returns the index to the first occurrence of the specified substring. If this function does not find the substring, this function returns the index of the terminating NULL value. You can specify an optional initial offset into the string. Parameters: sub The substring to find\n"
"    offset The initial offset into the string\n"
"  Paramegers: (oaString,oaUInt4)\n"
"    Calls: oaUInt4 substr(const oaString& sub,oaUInt4 offset) const\n"
"    Signature: substr|simple-oaUInt4|cref-oaString,simple-oaUInt4,\n"
"    This function searches this string and returns the index to the first occurrence of the specified substring. If this function does not find the substring, this function returns the index of the terminating NULL value. You can specify an optional initial offset into the string. Parameters: sub The substring to find\n"
"    offset The initial offset into the string\n"
;

static PyObject*
oaString_substr(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString data;
    int convert_status=PyoaString_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaStringObject* self=(PyoaStringObject*)ob;

    // Case: (oaString)
    {
        PyParamoaString p1;
        if (PyArg_ParseTuple(args,"O&",
              &PyoaString_Convert,&p1)) {
            oaUInt4 result= (data.DataCall()->substr(p1.Data()));
            return PyoaUInt4_FromoaUInt4(result);
        }
    }
    PyErr_Clear();
    // Case: (oaString,oaUInt4)
    {
        PyParamoaString p1;
        PyParamoaUInt4 p2;
        if (PyArg_ParseTuple(args,"O&O&",
              &PyoaString_Convert,&p1,
              &PyoaUInt4_Convert,&p2)) {
            oaUInt4 result= (data.DataCall()->substr(p1.Data(),p2.Data()));
            return PyoaUInt4_FromoaUInt4(result);
        }
    }
    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError,
        "No Arg-Matching Function found for class: oaString, function: substr, Choices are:\n"
        "    (oaString)\n"
        "    (oaString,oaUInt4)\n"
    );
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaString_toInt_doc[] =
"Class: oaString, Function: toInt\n"
"  Paramegers: ()\n"
"    Calls: int toInt() const\n"
"    Signature: toInt|simple-int|\n"
"    BrowseData: 1\n"
"    This function converts the string to an integer. See the system function atoi for details.\n"
"    Returns: Zero if the conversion fails\n"
;

static PyObject*
oaString_toInt(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString data;
    int convert_status=PyoaString_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaStringObject* self=(PyoaStringObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        int result= (data.DataCall()->toInt());
        return Pyint_Fromint(result);
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaString_toLower_doc[] =
"Class: oaString, Function: toLower\n"
"  Paramegers: ()\n"
"    Calls: void toLower()\n"
"    Signature: toLower|void-void|\n"
"    BrowseData: 0\n"
"    This function converts this string to lowercase.\n"
;

static PyObject*
oaString_toLower(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString data;
    int convert_status=PyoaString_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaStringObject* self=(PyoaStringObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->toLower();
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
  }
  catch (oaException &excp) {
    PyErr_OpenAccess(excp);
    return NULL;
  }
}

// ------------------------------------------------------------------
static char oaString_toUpper_doc[] =
"Class: oaString, Function: toUpper\n"
"  Paramegers: ()\n"
"    Calls: void toUpper()\n"
"    Signature: toUpper|void-void|\n"
"    BrowseData: 0\n"
"    This function converts this string to uppercase.\n"
;

static PyObject*
oaString_toUpper(PyObject* ob, PyObject *args)
{
  try {
    PyParamoaString data;
    int convert_status=PyoaString_Convert(ob,&data);
    assert(convert_status!=0);
    PyoaStringObject* self=(PyoaStringObject*)ob;

    if (PyArg_ParseTuple(args,"")) {
        data.DataCall()->toUpper();
        Py_INCREF(Py_None);
        return Py_None;
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
static PyMethodDef oaString_methodlist[] = {
    {"assign",(PyCFunction)oaString_assign,METH_VARARGS,oaString_assign_doc},
    {"str",(PyCFunction)oaString_str,METH_VARARGS,oaString_str_doc},
    {"getLength",(PyCFunction)oaString_getLength,METH_VARARGS,oaString_getLength_doc},
    {"getSize",(PyCFunction)oaString_getSize,METH_VARARGS,oaString_getSize_doc},
    {"index",(PyCFunction)oaString_index,METH_VARARGS,oaString_index_doc},
    {"isEmpty",(PyCFunction)oaString_isEmpty,METH_VARARGS,oaString_isEmpty_doc},
    {"resize",(PyCFunction)oaString_resize,METH_VARARGS,oaString_resize_doc},
    {"substr",(PyCFunction)oaString_substr,METH_VARARGS,oaString_substr_doc},
    {"toInt",(PyCFunction)oaString_toInt,METH_VARARGS,oaString_toInt_doc},
    {"toLower",(PyCFunction)oaString_toLower,METH_VARARGS,oaString_toLower_doc},
    {"toUpper",(PyCFunction)oaString_toUpper,METH_VARARGS,oaString_toUpper_doc},
   {NULL,NULL,0,NULL}
};
// ------------------------------------------------------------------
//  Type Object:
// ------------------------------------------------------------------

// ------------------------------------------------------------------
static char oaString_doc[] =
"Class: oaString\n"
"  The oaString utility class a single char.\n"
"Constructors:\n"
"  Paramegers: ()\n"
"    Calls: oaString()\n"
"    Signature: oaString||\n"
"    This is the default constructor for the oaString class. This constructor creates an empty oaString.\n"
"  Paramegers: (oaString)\n"
"    Calls: (const oaString&)\n"
"    Signature: oaString||cref-oaString,\n"
;

// ------------------------------------------------------------------
PyTypeObject PyoaString_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,
    "oaString",
    sizeof(PyoaStringObject),
    0,
    oaString_dealloc, /* tp_dealloc */
    0,  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    oaString_compare,    /* tp_compare */
    oaString_repr,      /* tp_repr */
    0,                                  /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_as_hash */
    0,                                  /* tp_as_call */
    oaString_str,               /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE, /* tp_flags */
    oaString_doc, /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompre */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    oaString_methodlist, /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    PyType_GenericAlloc,        /* tp_alloc */
    oaString_new, /* tp_new */
    _PyObject_Del,      /* tp_free */
};


// ------------------------------------------------------------------
//  Type Init:
// ------------------------------------------------------------------

int
PyoaString_TypeInit(PyObject* mod_dict)
{
    if (PyType_Ready(&PyoaString_Type)<0) {
      printf("** PyType_Ready failed for: oaString\n");
      return -1;
    }

    if (PyDict_SetItemString(mod_dict,"oaString",
           (PyObject*)(&PyoaString_Type))<0) {
       printf("** Failed to add type name to module dictionary for: oaString\n");
       return -1;
    }
    return 0;
}

