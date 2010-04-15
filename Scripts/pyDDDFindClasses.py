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
#   Find Classes, Define class representations, Link BaseClasses
#--------------------------------------------------------------------
#

import string
import copy
import sys
import re

# ===============================================================
# ==========================================
# Find all the class types and add to mClasses dict.
def FindClasses(data):
  print "Finding Classes"
  sys.stderr.write("Finding Classes:\n")
  for item in data.mData:
    if (item['category']!='class'): continue
    name=item['name']
    predefined=0
    orgitem=item
    if (data.mClasses.has_key(name)):
      item=data.mClasses[name]
      predefined=1
    skip=data.vShouldSkipClass(name)
    if (skip): 
     print "  Skipping Class:",name
     continue
    else:
      if (not predefined):
        data.mClasses[name]=item
  names=data.mClasses.keys()
  names.sort()

  data.vReportData("ListOfClasses",names)
    
# ==========================================
# Find the base class and rootbase class for each class
def FindClassBases(data):
  print "Resolving Class Inheritance"
  sys.stderr.write("Resolving Class Inheritance:\n")
  report={}
  for clsname,item in data.mClasses.items():
    item['linked']=1
    item['db']=0
    item['base']=None
    bases=item['bases']
    if (len(bases)==0): continue
    if (len(bases)>1):
      print "** Multiple Inheritance not suported, Skipping class: %s %s"%(item['name'],bases)
      item['linked']=0
      continue

    base=bases[0]
    if (data.mTemplateTypedefs.has_key(base)):
      base=data.mTemplateTypedefs[base]
    if (not data.mClasses.has_key(base)):
      print "** Base class not found: %s, Skipping class: %s"%(base,item['name'])
      item['linked']=0
      continue
    item['base']=data.mClasses[base]

  for clsname,item in data.mClasses.items():
    rep=data.vGetClassRepr(clsname)
    rootbase=item
    base=item
    while (1):
      if (data.vShouldSkipDerivedClass(base['name'])):
        #print "** Base class request skip: %s, Skipping class: %s"%(base['name'],item['name'])
        item['linked']=-1
      if (rep==None):
        rep=data.vGetClassReprByBaseClass(base['name'])
      base=base['base']
      if (base==None): break
      rootbase=base
    item['rootbase']=rootbase
    if (data.vIsDbClass(rootbase['name'])):
      item['db']=1
    if (rep!=None):
      item['repr']=rep

  for name,item in data.mClasses.items():
    if (item['linked']<1):
      if (item['linked']==0):
        print "  Removing Unlinked Class:",name
      else:
        print "  Removing Class By BaseClass:",name
      del data.mClasses[name]

  # Build a class hierarchy report
  for clsname,cls in data.mClasses.items():
    lst=[]
    base=cls['base']
    while (base!=None):
      lst.append(base['name'])
      base=base['base']
    report[clsname]=lst
  data.vReportData("ClassBases",report)
    
  
