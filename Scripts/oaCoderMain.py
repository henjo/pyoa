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
# This file contains classes for genesis class descriptions.
# These descriptions describe how each genesis class is to be
# wrapped in python.
# These description will be used to automatically build the
# C++ wrapper code for these objects as python extensions.
#--------------------------------------------------------------------

import types
import sys
import copy
from pyCoderMain import *
from pyCoderClass import *
from pyCoderFunc import *

# ===================================================================
oaversioncode='226p084'
oaversion='226.20080327'
pyoaversion='226.20080508'

# ===================================================================
# Define Main Code Generation class
# ===================================================================
class oaMain(cMain):
  def __init__(self,data):
    cMain.__init__(self,
      data,    # The data set
      "wrap",  # output directory
      "pyoa",  # file prefix
      "openaccess",   # package name
      "pyoa%s"%oaversioncode  # module name (.so,.dll)
    )

  # -------------------------------------
  # Callback for Personalization Includes
  def vGenIncludes(self,fp):
    fp.write('#include "oa/oaWaferDB.h"\n')
    fp.write('#include "%s_util.h"\n'%self.mFilePrefix)

  # -------------------------------------
  # Callback for Personalization Defines
  def vGenDefs(self,fp):
    fp.write('  // OpenAccess Version Defines\n')
    fp.write('  def=PyString_FromString("%s");\n'%oaversion)
    fp.write("  PyDict_SetItemString(dict,\"oaVersion\",def);\n")
    fp.write("  Py_DECREF(def);\n")
    fp.write('  def=PyString_FromString("%s");\n'%pyoaversion)
    fp.write("  PyDict_SetItemString(dict,\"pyoaVersion\",def);\n")
    fp.write("  Py_DECREF(def);\n")

    # -----------------------
    # Define Exception
    fp.write("""

  // OpenAccess Exception
  PyExec_OpenAccess=PyErr_NewException("%s.error",NULL,NULL);
  if (PyExec_OpenAccess==NULL) return;
  PyDict_SetItemString(dict,"error",PyExec_OpenAccess);
  PyDict_SetItemString(dict,"oaException",PyExec_OpenAccess);
  Py_DECREF(PyExec_OpenAccess);
"""%(self.mPackageName))

  # -------------------------------------
  # Callback to generate the __init__.py file
  def vGenInitFile(self):
    fp=self.OpenWrite('openaccess22/__init__.py')
    fp.write("""\
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
# Init of openaccess22
#
import os
if (os.name=='nt'):
  from %s%s import *
else:
  from lib%s%s import *

"""%(self.mFilePrefix,oaversioncode,self.mFilePrefix,oaversioncode))
    self.CloseWrite(fp)

        
  # -------------------------------------
  # Callback for Getting other source files
  def vGetSourceFiles(self):
    srcfiles=[
      'pyoa_util',
      'pyoa_manual',
      'pyoa_math',
      'pyoa_oaBoolean',
      'pyoa_oaByte','pyoa_oaByte_Array',
      'pyoa_oaChar','pyoa_oaChar_Array',
      'pyoa_oaComplex_oaDouble','pyoa_oaComplex_oaFloat',
      'pyoa_oaDouble','pyoa_oaFloat',
      'pyoa_oaInt1','pyoa_oaInt2','pyoa_oaInt4','pyoa_oaInt8',
      'pyoa_oaUInt2','pyoa_oaUInt4','pyoa_oaUInt8',
      'pyoa_oaCoord','pyoa_oaDist','pyoa_oaOffset',
      'pyoa_oaLayerNum','pyoa_oaPurposeNum',
      'pyoa_oaString','pyoa_oaTime',
    ]
    return ['src',srcfiles]

  # -------------------------------------
  # Callback for Getting other source files
  def vGenCustomOutputs(self):
    #self._GenProjectFile()
    pass

  # -------------------------------------
  # Generate a Project File
  def _GenProjectFile(self):
    name="%s/../NTBuild/oafull.vcproj"%(self.mDirName)
    print "Updating file:",name
    fp=open(name,"r")
    predata=[]
    postdata=[]
    line=fp.readline()
    while (line):
      predata.append(line)
      if (string.find(line,'Name="Source Files"')>0): break
      line=fp.readline()
    line=fp.readline()
    predata.append(line)
    line=fp.readline()
    while (line):
      if (string.find(line,'</Filter>')>0):break
      line=fp.readline()
    postdata.append(line)
    line=fp.readline()
    while (line):
      postdata.append(line)
      line=fp.readline()
    fp.close()

    libfiles=[]
    for name in ['main','array']:
      libfiles.append('%s_%s'%(self.mFilePrefix,name))
    for cls in self.mClsData:
      if (not cls.HasImplementation()): continue
      libfiles.append('%s_%s'%(self.mFilePrefix,cls.mName))
    fp=self.OpenWrite(name)
    for line in predata:
      fp.write(line)
    for name in libfiles:
      fp.write('\t\t\t<File\n\t\t\t\tRelativePath="..\%s\%s.cpp">\n\t\t\t</File>\n'%
        (self.mDirName,name))
    for line in postdata:
      fp.write(line)
    self.CloseWrite(fp)



    name="%s/../NTBuild/%s.vcproj"%(self.mDirName,self.mFilePrefix)
    print "Updating file:",name
    fp=open(name,"r")
    predata=[]
    postdata=[]
    line=fp.readline()
    while (line):
      predata.append(line)
      if (string.find(line,'Name="Source Files"')>0): break
      line=fp.readline()
    line=fp.readline()
    predata.append(line)
    line=fp.readline()
    while (line):
      if (string.find(line,'</Filter>')>0):break
      line=fp.readline()
    postdata.append(line)
    line=fp.readline()
    while (line):
      postdata.append(line)
      line=fp.readline()
    fp.close()

    allfiles=[]
    libfiles=[]
    for name in self.mSourceFiles: allfiles.append(name)
    for name in self.mWrapFiles: allfiles.append(name)
    block=1
    self.mBlockSize=50
    count=0
    for name in allfiles:
      if (count>=self.mBlockSize):
        count=0
      if (count==0):
        libfiles.append('block%d'%block)
        block+=1
      count+=1

    fp=self.OpenWrite(name)
    for line in predata:
      fp.write(line)
    print "LibFiles:",libfiles
    for name in libfiles:
      fp.write('\t\t\t<File\n\t\t\t\tRelativePath="..\%s\%s.cpp">\n\t\t\t</File>\n'%
        (self.mDirName,name))
    for line in postdata:
      fp.write(line)
    self.CloseWrite(fp)

#--------------------------------------------------------------------
if (__name__=='__main__'):
  print "Importing Data"
  sys.path.append('.')
  import OpenAccessDesc
  Data=OpenAccessDesc.Data
  print "Processing Data"
  T=oaMain(Data)
  T.Process()
  print "Done"
