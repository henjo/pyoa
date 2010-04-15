
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *******************************************************************/

#ifndef pyoa_util_h
#define pyoa_util_h

// ------------------------------------------------------------------
// OpenAccess Headers
// ------------------------------------------------------------------
using namespace oa;

// ------------------------------------------------------------------
// Macros for use in REPR routines
// ------------------------------------------------------------------
#if defined(_LP64)
#define POINTER_AS_DISPLAY(x) (long long)(x)
#define DISPLAY_FORMAT "0x%16.16llX"
#else
#define POINTER_AS_DISPLAY(x) (long)(x)
#define DISPLAY_FORMAT "0x%8.8lX"
#endif

// ------------------------------------------------------------------
// Version configuration
// ------------------------------------------------------------------
#if (PY_MAJOR_VERSION>2) || ((PY_MAJOR_VERSION==2) && (PY_MINOR_VERSION>=5))
#define Pyoa_ssize_t Py_ssize_t
#define Pyoa_inquiry lenfunc
#define Pyoa_binaryfunc binaryfunc
#define Pyoa_intargfunc ssizeargfunc
#define Pyoa_intintargfunc ssizessizeargfunc
#define Pyoa_intobjargproc ssizeobjargproc
#else
#define Pyoa_ssize_t int
#define Pyoa_inquiry inquiry
#define Pyoa_binaryfunc binaryfunc
#define Pyoa_intargfunc intargfunc
#define Pyoa_intintargfunc intintargfunc
#define Pyoa_intobjargproc intobjargproc
#endif

// ------------------------------------------------------------------
// Platform configuration
// ------------------------------------------------------------------
#ifdef WIN32
#define strcasecmp stricmp
#endif

// ------------------------------------------------------------------
// DLL Stuff
// ------------------------------------------------------------------
#ifdef WIN32
# ifdef PYTHON_OPENACCESS_BUILD_DLL
#  define PYTHON_OPENACCESS_DLL_EXPORT __declspec(dllexport)
#  define PYTHON_OPENACCESS_DLL_EXPORT_TEMPLATE PYTHON_OPENACCESS_DLL_EXPORT
# else
// Allways Use if not exporting
#   define PYTHON_OPENACCESS_DLL_EXPORT __declspec(dllimport)
#   define PYTHON_OPENACCESS_DLL_EXPORT_TEMPLATE
# endif
#else
# define PYTHON_OPENACCESS_DLL_EXPORT
# define PYTHON_OPENACCESS_DLL_EXPORT_TEMPLATE
#endif

#define PYTHON_OPENACCESS_CLASS class PYTHON_OPENACCESS_DLL_EXPORT
#define PYTHON_OPENACCESS_EXTERN extern PYTHON_OPENACCESS_DLL_EXPORT
#define PYTHON_OPENACCESS_TEMPLATE_CLASS class PYTHON_OPENACCESS_DLL_EXPORT_TEMPLATE

// ------------------------------------------------------------------
// Define PYOA_LONG_LONG for python
// ------------------------------------------------------------------
// Python 2.4 and newer used PY_LONG_LONG now, instead of LONG_LONG
#ifdef PY_LONG_LONG
#define PYOA_LONG_LONG PY_LONG_LONG
#else
#define PYOA_LONG_LONG LONG_LONG
#endif

// ------------------------------------------------------------------
// Parameter Objects
// ------------------------------------------------------------------
// Parameter Object for Utility Objects, and Manual Objects
template <class T>
PYTHON_OPENACCESS_TEMPLATE_CLASS PyParamObject {
  public:
    T* data;
    int owner;
    PyParamObject(): data(NULL), owner(0) {}
    ~PyParamObject() { Clear(); }

    void Clear() { if (owner) delete data; owner=0; data=NULL; }
    //T* PtrData() { return data; }
    T* DataCall() { return data; }
    T& Data()    { return *data; }
    T* DataAof() { return data; }
    //T* TakeData() { T* result=data; Clear(); return result; }
    void SetData(T* v) { Clear(); owner=0; data=v; }
    void GiveData(T* v) { Clear(); owner=1; data=v; }
  private:
    PyParamObject(const PyParamObject& t) {}
    void operator=(const PyParamObject& t) {}
};
// Parameter Object for Utility Objects that are pure virtuals
template <class T>
PYTHON_OPENACCESS_TEMPLATE_CLASS PyParamVirtualObject {
  public:
    T* data;
    PyParamVirtualObject(): data(NULL) {}
    ~PyParamVirtualObject() { Clear(); }

    void Clear() { data=NULL; }
    //T* PtrData() { return data; }
    T* DataCall() { return data; }
    T& Data()    { return *data; }
    T* DataAof() { return data; }
    //T* TakeData() { T* result=data; Clear(); return result; }
    void SetData(T* v) { data=v; }
  private:
    PyParamVirtualObject(const PyParamVirtualObject& t) {}
    void operator=(const PyParamVirtualObject& t) {}
};

// Parameter Object for Db Object
template <class T>
PYTHON_OPENACCESS_TEMPLATE_CLASS PyParamDbObject {
  public:
    T** data;
    PyParamDbObject(): data(NULL) {}
    ~PyParamDbObject() { }

    void Clear() { }
    T* DataCall() { return *(data); }
    T*& Data()    { return *(data); }
    T** DataAof() { return data; }
    //T** PtrData() { return data; }
    void SetData(T** v) { data=v; }
  private:
    PyParamDbObject(const PyParamDbObject& t) {}
    void operator=(const PyParamDbObject& t) {}
};

// Parameter Object for Enum Objects
template <class T>
PYTHON_OPENACCESS_TEMPLATE_CLASS PyParamEnumObject {
  public:
    T data;
    PyParamEnumObject(): data((T)(0)) {}
    ~PyParamEnumObject() { }

    void Clear() { }
    T& Data()    { return data; }
    void SetData(T v) { data=v; }
  private:
    PyParamEnumObject(const PyParamEnumObject& t) {}
    void operator=(const PyParamEnumObject& t) {}
};
// ------------------------------------------------------------------
// Templated Python Object Description for Manual classes
// ------------------------------------------------------------------
template <class T>
struct Pyoa_Object {
  PyObject_VAR_HEAD
  T* value;
  T data;
  int borrow;
  PyObject* locks;
};

// ------------------------------------------------------------------
// Parameter Objects for Arrays
// ------------------------------------------------------------------
template <class T>
PYTHON_OPENACCESS_TEMPLATE_CLASS Pyoa_Array {
public:
  Pyoa_Array(): len(0), data(NULL), owner(0) {}
  Pyoa_Array(int l): len(l) { data=new T[len]; owner=1; }
  ~Pyoa_Array() { Clear(); }
  Pyoa_Array(const Pyoa_Array& v) : len(0), data(NULL), owner(0) { operator=(v); }
  void operator=(const Pyoa_Array& v) { SetLen(v.len); Copy(v.data); }
  void Clear() { if (data && owner) delete [] data; data=NULL; owner=0; }
  void SetLen(Pyoa_ssize_t l) { Clear(); len=l; data=new T[len]; owner=1; }
  void Borrow(T* d,Pyoa_ssize_t l) { Clear(); len=l; data=d; owner=0; }
  void Borrow(Pyoa_Array& v) { Clear(); len=v.len; data=v.data; owner=0; }
  void Copy(const T* d) { for(int i=0;i<len;i++) data[i]=d[i]; }
  void SetItem(Pyoa_ssize_t i,const T& v) { data[i]=v; }
  const T& GetItem(Pyoa_ssize_t i) const { return data[i]; }
  T* GetItemPtr(Pyoa_ssize_t i) const { return &(data[i]); }
  int GetBorrow() const { return owner?0:1; }
  Pyoa_ssize_t Len()const { return len; }
  Pyoa_ssize_t* LenAdr() { return &len; }
  T* Data() const { return data; }
  void GiveAway(Pyoa_Array& v) { v.Clear(); v.data=data; v.len=len; v.owner=owner;
                                 len=0; owner=0; data=NULL; }
  void TakeAway(Pyoa_Array& v) {
    if (!v.owner) { operator=(v); }
    else {
      Clear(); data=v.data; len=v.len; owner=1;
      v.data=NULL; v.len=0; v.owner=0;
    }
  }
protected:
  Pyoa_ssize_t len;
  T* data;
  int owner;
};

// ------------------------------------------------------------------
// Templated Python Object Description for Arrays of Manual classes
// ------------------------------------------------------------------
template <class T>
struct Pyoa_ArrayObject {
  PyObject_VAR_HEAD
  Pyoa_Array<T> data;
  int borrow;
  PyObject* locks;
};

// ------------------------------------------------------------------
// Native Type Converts for Manual classes
// ------------------------------------------------------------------
extern int PyNone_Convert(PyObject* obj,void* result);
#define PyParamint int
extern int Pyint_Convert(PyObject* obj,int* result);
extern PyObject* Pyint_Fromint(int value);

// -----------------------------
PYTHON_OPENACCESS_CLASS char_Array {
public:
  char *data;
  char_Array() { data=NULL; }
  ~char_Array() { delete data; }
  void Init(const char* v,Pyoa_ssize_t len) {
    if (data) delete data;
    data=new char[len+1];
    memcpy(data,v,len);
    data[len]='\0';
  }
  void Copy(const char* v) {
    if (data) delete data;
    Pyoa_ssize_t len=strlen(v);
    data=new char[len+1];
    memcpy(data,v,len);
    data[len]='\0';
  }
  char* Data() { return data; }
private:
  char_Array(const char_Array&);
  void operator=(const char_Array&);
};

#define PyParamchar char
#define PyParamchar_Array char_Array

PYTHON_OPENACCESS_EXTERN int Pychar_Convert(PyObject* obj,char* result);
PYTHON_OPENACCESS_EXTERN PyObject* Pychar_Fromchar(char value);
PYTHON_OPENACCESS_EXTERN int Pychar_Array_Convert(PyObject* obj,PyParamchar_Array* result);
PYTHON_OPENACCESS_EXTERN PyObject* Pychar_Array_Fromchar_Array(const char_Array& value);
PYTHON_OPENACCESS_EXTERN PyObject* Pychar_Array_Fromchar_Array(const char* value,Pyoa_ssize_t len,PyObject* lock);

// -----------------------------
typedef char* charp;
#define PyParamcharp charp
PYTHON_OPENACCESS_EXTERN int Pycharp_Convert(PyObject* obj,PyParamcharp* result);
PYTHON_OPENACCESS_EXTERN PyObject* Pycharp_Fromcharp(charp value);

typedef Pyoa_Array<charp> Pycharp_Array;
typedef Pyoa_Array<charp> PyParamcharp_Array;
PYTHON_OPENACCESS_EXTERN int Pycharp_Array_Convert(PyObject* obj,PyParamcharp_Array* result);
PYTHON_OPENACCESS_EXTERN PyObject* Pycharp_Array_Fromcharp_Array(const Pycharp_Array& value);

// ------------------------------------------------------------------
// Types for Manual Array classes
// ------------------------------------------------------------------

// ------------------------------------------------------------------
// oaChar
// ------------------------------------------------------------------
PYTHON_OPENACCESS_CLASS oaChar_Array {
public:
  oaChar_Array(): len(0), data(NULL), owner(0) {}
  oaChar_Array(int l): len(l), data(NULL), owner(1) { data=new oaChar[len]; }
  ~oaChar_Array() {
     if (owner && data) { delete [] data; }
  }
  void operator=(const oaChar_Array& v) {
    SetLen(v.len);
    Copy(v.data);
  }
  void Copy(const char* v) {
    memcpy(data,v,len);
  }
  void SetLen(Pyoa_ssize_t l) {
    if (data && owner) { delete [] data; }
    len=l;
    owner=1;
    data=new oaChar[len+1];
    memset(data,0,len+1);
  }
  void SetUse(oaChar* v, Pyoa_ssize_t l) {
    if (data && owner) { delete [] data; }
    len=l;
    owner=0;
    data=v;
  }
  void SetUse(const oaChar_Array& v) {
    if (data && owner) { delete [] data; }
    len=v.len;
    owner=0;
    data=v.data;
  }
  oaChar* Data() { return data; }
  Pyoa_ssize_t Len() { return len; }
protected:
  Pyoa_ssize_t len;
  oaChar *data;
  int owner;
private:
  oaChar_Array(const oaChar_Array&);
};

typedef Pyoa_Object<oaChar_Array> PyoaChar_ArrayObject;
typedef oaChar_Array PyParamoaChar_Array;
PYTHON_OPENACCESS_EXTERN PyTypeObject PyoaChar_Array_Type;
PYTHON_OPENACCESS_EXTERN int PyoaChar_Array_TypeInit(PyObject* dict);
PYTHON_OPENACCESS_EXTERN int PyoaChar_Array_Convert(PyObject* obj,PyParamoaChar_Array* result);
PYTHON_OPENACCESS_EXTERN PyObject* PyoaChar_Array_FromoaChar_Array(const oaChar_Array& value);
PYTHON_OPENACCESS_EXTERN PyObject* PyoaChar_Array_FromoaChar_Array(const oaChar* value,Pyoa_ssize_t len,PyObject* lock);
#define PyoaChar_Array_Check(op) PyObject_TypeCheck(op, &PyoaChar_Array_Type)
#define PyoaChar_Array_CheckExact(op) PyObject_TypeCheck((op)->ob_type == &PyoaChar_Array_Type)

// ------------------------------------------------------------------
// oaByte
// ------------------------------------------------------------------
PYTHON_OPENACCESS_CLASS oaByte_Array {
public:
  oaByte_Array(): len(0), data(NULL), owner(0) {}
  oaByte_Array(int l): len(l), data(NULL), owner(1) { data=new oaByte[len]; }
  ~oaByte_Array() {
     if (data && owner) { delete [] data; }
  }
  void operator=(const oaByte_Array& v) {
    SetLen(v.len);
    Copy(v.data);
  }
  void Copy(const oaByte* d) {
    memcpy(data,d,len);
  }
  void SetLen(Pyoa_ssize_t l) {
    if (data && owner) { delete [] data; }
    len=l;
    owner=1;
    data=new oaByte[len];
    memset(data,0,len);
  }
  void SetUse(oaByte* v, Pyoa_ssize_t l) {
    if (data && owner) { delete [] data; }
    len=l;
    owner=0;
    data=v;
  }
  void SetUse(const oaByte_Array& v) {
    if (data && owner) { delete [] data; }
    len=v.len;
    owner=0;
    data=v.data;
  }
  Pyoa_ssize_t Len() { return len; }
  oaByte* Data() { return data; }
protected:
  Pyoa_ssize_t len;
  oaByte* data;
  int owner;
private:
  oaByte_Array(const oaByte_Array&);
};

typedef Pyoa_Object<oaByte_Array> PyoaByte_ArrayObject;
typedef oaByte_Array PyParamoaByte_Array;
PYTHON_OPENACCESS_EXTERN PyTypeObject PyoaByte_Array_Type;
PYTHON_OPENACCESS_EXTERN int PyoaByte_Array_TypeInit(PyObject* dict);
PYTHON_OPENACCESS_EXTERN int PyoaByte_Array_Convert(PyObject* obj,PyParamoaByte_Array* result);
PYTHON_OPENACCESS_EXTERN PyObject* PyoaByte_Array_FromoaByte_Array(const oaByte_Array& value);
PYTHON_OPENACCESS_EXTERN PyObject* PyoaByte_Array_FromoaByte_Array(const oaByte* value,Pyoa_ssize_t len,PyObject* lock);
#define PyoaByte_Array_Check(op) PyObject_TypeCheck(op, &PyoaByte_Array_Type)
#define PyoaByte_Array_CheckExact(op) PyObject_TypeCheck((op)->ob_type == &PyoaByte_Array_Type)

// ------------------------------------------------------------------
// oaObjects - Manually Coded Native Types:
// ------------------------------------------------------------------
typedef oaComplex<oaFloat> oaComplex_oaFloat;
typedef oaComplex<oaDouble> oaComplex_oaDouble;

// ------------------------------------------------------------------
// Exception From Python in Callbacks
// ------------------------------------------------------------------
PYTHON_OPENACCESS_CLASS oaPythonException: public oaException {
 public:
  oaPythonException(const char *_msg);
 protected:
  virtual const oaString& getFormatString() const;
};

// ------------------------------------------------------------------
// External utilites
// ------------------------------------------------------------------

PYTHON_OPENACCESS_EXTERN PyObject* PyExec_OpenAccess;
PYTHON_OPENACCESS_EXTERN void PyErr_OpenAccess(const oaException& exc);
PYTHON_OPENACCESS_EXTERN void PyoaLockObject(PyObject*& list,PyObject* obj);
// One for each Db BaseType
PYTHON_OPENACCESS_EXTERN int PyValidateDbObject(oaObject*,int);
PYTHON_OPENACCESS_EXTERN int PyValidateDbObject(oaVCSystem*,int);
PYTHON_OPENACCESS_EXTERN int PyValidateDbObject(oaEvalTextLink*,int);
PYTHON_OPENACCESS_EXTERN int PyValidateDbObject(oaPcellLink*,int);
PYTHON_OPENACCESS_EXTERN int PyValidateDbObject(oaBuildInfo*,int);

#endif
