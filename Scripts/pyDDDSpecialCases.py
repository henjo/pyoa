#*******************************************************************
#   Copyright 2002-2008  LSI Corporation
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#
#*******************************************************************
#
#--------------------------------------------------------------------
# Part of DoxData2Desc
#   Generates a summary of special cases
#--------------------------------------------------------------------
#

import string
import sys

import pyDDDParameters
import pyDDDFunction
import pyFunc


# -------------------------------------
def ReportRenames(fp):
  fp.write('Summary of Renamed Functions:\n')
  classnames=pyDDDFunction.HintForceRename.keys()
  classnames.sort()
  for classname in classnames:
    fp.write('  Class: %s\n'%classname)
    cls=pyDDDFunction.HintForceRename[classname]
    funnames=cls.keys()
    funnames.sort()
    for funname in funnames:
       value=cls[funname]
       desc=pyFunc.ExpandSig(funname,classname)
       fp.write('    %s -> %s\n'%(desc,value))
       
# -------------------------------------
def ReportDirections(fp):
  dirs=['In','Out','Bi']
  fp.write('Summary of Parameter Direction Exceptions:\n')
  fp.write('  - => parameter direction matches parameter mode\n')
  fp.write('  In, Out, Bit => Exception parameter direction\n')
  classnames=pyDDDParameters.FunctionHints.keys()
  classnames.sort()
  for classname in classnames:
    reportclass=0
    cls=pyDDDParameters.FunctionHints[classname]
    funnames=cls.keys()
    funnames.sort()
    for funname in funnames:
       data=cls[funname]
       desc=pyFunc.ExpandSig(funname,classname)
       report=0
       for item in data[1:]:
         if (item.has_key('dir')): report=1
       if (not report): continue
       if (not reportclass):
         fp.write('  Class: %s\n'%classname)
         reportclass=1
       fp.write('    %s\n'%desc)
       fp.write('      ')
       first=1
       for item in data[1:]:
         if (first): first=0
         else: fp.write(',')
         if (item.has_key('dir')):
           fp.write('%s'%dirs[item['dir']])
         else:
           fp.write('-')
       fp.write('\n')
           
# -------------------------------------
def ReportSpecial(fp):
  fp.write('Summary of Parameter Special Exceptions:\n')
  classnames=pyDDDParameters.FunctionHints.keys()
  classnames.sort()
  for classname in classnames:
    reportclass=0
    cls=pyDDDParameters.FunctionHints[classname]
    funnames=cls.keys()
    funnames.sort()
    for funname in funnames:
       data=cls[funname]
       desc=pyFunc.ExpandSig(funname,classname)
       report=0
       for item in data[1:]:
         for flag in ['aof','copy','check','pre','post','init','set']:
           if (item.has_key(flag)): report=1
       if (not report): continue
       if (not reportclass):
         fp.write('  Class: %s\n'%classname)
         reportclass=1
       fp.write('    %s\n'%desc)
       fp.write('       ')
       first=1
       for item in data[1:]:
         if (first): first=0
         else: fp.write(',')
         flags=0
         for flag in ['aof','copy','check','pre','post','init','set']:
           if (item.has_key(flag)):
             if (flags): fp.write('+')
             fp.write(flag)
             flags+=1
         if (not flags):
           fp.write('-')
       fp.write('\n')
       
# -------------------------------------
def ReportPointerReturn(fp):
  fp.write('Summary of Pointer Return Cases:\n')
  classnames=pyDDDParameters.FunctionHints.keys()
  classnames.sort()
  for classname in classnames:
    reportclass=0
    cls=pyDDDParameters.FunctionHints[classname]
    funnames=cls.keys()
    funnames.sort()
    for funname in funnames:
       data=cls[funname]
       desc=pyFunc.ExpandSig(funname,classname)
       report=0
       item=data[0]
       for flag in ['init','set','dref','alloc','borrow']:
         if (item.has_key(flag)): report=1
       if (not report): continue
       if (not reportclass):
         fp.write('  Class: %s\n'%classname)
         reportclass=1
       fp.write('    %s\n'%desc)
       fp.write('       ')
       item=data[0]
       flags=0
       for flag in ['init','set','dref','alloc','borrow']:
         if (item.has_key(flag)):
           if (flags): fp.write('+')
           fp.write(flag)
           flags+=1
       fp.write('\n')
       
# -------------------------------------
def Test():
  fp=open('Summary/Special','w')
  ReportRenames(fp)
  ReportDirections(fp)
  ReportSpecial(fp)
  ReportPointerReturn(fp)
  fp.close()
  
Test()


    