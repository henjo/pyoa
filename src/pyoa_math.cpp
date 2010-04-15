
/********************************************************************
 *   Copyright 2002-2008  LSI Corporation
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
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
// pyoaPoint
// -----------------------------------------------------
static PyObject* oaPoint_add(PyObject* ob1,PyObject* ob2)
{
  PyParamoaPoint p1;
  PyParamoaPoint p2;
  int s1=PyoaPoint_Convert(ob1,&p1);
  int s2=PyoaPoint_Convert(ob2,&p2);
  assert(s1!=0);
  assert(s2!=0);
  oaPoint* result=new oaPoint();
  (*result)=(p1.Data())+(p2.Data());
  return PyoaPoint_FromoaPoint(result);
}
// -----------------------------------------------------
static PyObject* oaPoint_sub(PyObject* ob1,PyObject* ob2)
{
  PyParamoaPoint p1;
  PyParamoaPoint p2;
  int s1=PyoaPoint_Convert(ob1,&p1);
  int s2=PyoaPoint_Convert(ob2,&p2);
  assert(s1!=0);
  assert(s2!=0);
  oaPoint* result=new oaPoint();
  (*result)=(p1.Data())-(p2.Data());
  return PyoaPoint_FromoaPoint(result);
}
// -----------------------------------------------------
static PyObject* oaPoint_abs(PyObject* ob)
{
  PyParamoaPoint p;
  int s=PyoaPoint_Convert(ob,&p);
  assert(s!=0);
  oaPoint* result=new oaPoint();
  result->x()=abs(p.Data().x());
  result->y()=abs(p.Data().y());
  return PyoaPoint_FromoaPoint(result);
}
// -----------------------------------------------------
static PyObject* oaPoint_neg(PyObject* ob)
{
  PyParamoaPoint p;
  int s=PyoaPoint_Convert(ob,&p);
  assert(s!=0);
  oaPoint* result=new oaPoint();
  result->x()=-(p.Data().x());
  result->y()=-(p.Data().y());
  return PyoaPoint_FromoaPoint(result);
}
// -----------------------------------------------------
static PyObject* oaPoint_pos(PyObject* ob)
{
  PyParamoaPoint p;
  int s=PyoaPoint_Convert(ob,&p);
  assert(s!=0);
  Py_INCREF(ob);
  return ob;
}
// -----------------------------------------------------
static int oaPoint_nonzero(PyObject* ob)
{
  PyParamoaPoint p;
  int s=PyoaPoint_Convert(ob,&p);
  assert(s!=0);
  return (p.Data().x()!=0 || p.Data().y()!=0)?1:0;
}
// -----------------------------------------------------
static PyObject* oaPoint_iadd(PyObject *ob1,PyObject* ob2)
{
  PyParamoaPoint p1;
  PyParamoaPoint p2;
  int s1=PyoaPoint_Convert(ob1,&p1);
  int s2=PyoaPoint_Convert(ob2,&p2);
  assert(s1!=0);
  assert(s2!=0);
  (p1.Data())+=(p2.Data());
  Py_INCREF(ob1);
  return ob1;
}
// -----------------------------------------------------
static PyObject* oaPoint_isub(PyObject *ob1,PyObject* ob2)
{
  PyParamoaPoint p1;
  PyParamoaPoint p2;
  int s1=PyoaPoint_Convert(ob1,&p1);
  int s2=PyoaPoint_Convert(ob2,&p2);
  assert(s1!=0);
  assert(s2!=0);
  (p1.Data())-=(p2.Data());
  Py_INCREF(ob1);
  return ob1;
}
// -----------------------------------------------------
PyNumberMethods oaPointAsNumber = {
  (binaryfunc)oaPoint_add, /*nb_add*/
  (binaryfunc)oaPoint_sub, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  (unaryfunc)oaPoint_neg, /*nb_negative*/
  (unaryfunc)oaPoint_pos, /*nb_positive*/
  (unaryfunc)oaPoint_abs, /*nb_absolute*/
  (inquiry)oaPoint_nonzero, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/

  (binaryfunc)oaPoint_iadd, /*ng_inplace_add*/
  (binaryfunc)oaPoint_isub, /*ng_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/

  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
};

