#!/usr/bin/env python
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

#--------------------------------------------------------------------
# Setup stript to compile Python for OpenAccess
# 
# Edit the top section to include the correct paths to 
# OpenAccess on your system
#--------------------------------------------------------------------
oaversioncode='226p084'
pyoaversion='226.20080508'

import os
import os.path

#--------------------------------------------------------------------
class Builder:
  #--------------------------------------------------------------------
  def __init__(self):
    if (os.name=='nt'):
      self.OpenAcessRoot = '../OpenAccess-2.2.6p084'
    else:
      self.OpenAcessRoot = '../OpenAccess-2.2.6p084'

  #--------------------------------------------------------------------
  def SetupNt(self):
    #--------------------------------------------------------------------
    #  Data for Release Build
    #--------------------------------------------------------------------
    # The Include directories
    self.OpenAccessIncludeDirs = [
        'src',
        'wrap',
        self.OpenAcessRoot + '/include',
        ]

    # The Library directories
    self.OpenAccessLibDirs = [
        self.OpenAcessRoot + '/lib/win32/opt',
      ]

    # The libraries.
    self.OpenAccessLibraries = [
      'oaBase',
      'oaCommon',
      'oaDesign',
      'oaDM',
      #'oaDMFileSys',
      #'oaDMTurbo',
      #'oaDMTurboBase',
      'oaPlugIn',
      'oaTech',
      #'oaUtil',
      'oaWafer',
    ]
    
    # Defines
    self.OpenAccessDefines=[
      ('WIN32',None),
      ('NDEBUG',None),
      ('_WINDOWS',None),
      ('PYTHON_OPENACCESS_BUILD_DLL',None),
    ]
    
    # Compiler Args
    self.OpenAccessCompileArgs=[
      '/YX"pyoa_header.h"',
      '/Fp"pyoa_header_r.pch"',
    ]

  #--------------------------------------------------------------------
  def SetupUnix(self):
    #--------------------------------------------------------------------
    #  Data for Release Build
    #--------------------------------------------------------------------
    # The Include directories
    self.OpenAccessIncludeDirs = [
        'src',
        'wrap',
        self.OpenAcessRoot + '/include',
        ]

    # The Library directories
    if (os.uname()[0]=='SunOS'):
      self.OpenAccessLibDirs = [
          self.OpenAcessRoot + '/lib/sunos_58_32/opt',
        ]
    if (os.uname()[0]=='Linux'):
      if (os.uname()[4]=='x86_64'):
        self.OpenAccessLibDirs = [
          self.OpenAcessRoot + '/lib/linux_rhel30_64/opt',
        ]
      else:
        self.OpenAccessLibDirs = [
          self.OpenAcessRoot + '/lib/linux_rhel21_32/opt',
        ]

    # The libraries.
    self.OpenAccessLibraries = [
      'oaBase',
      'oaCommon',
      'oaDesign',
      'oaDM',
      #'oaDMFileSys',
      #'oaDMTurbo',
      #'oaDMTurboBase',
      'oaPlugIn',
      'oaTech',
      #'oaUtil',
      'oaWafer',
    ]
    
    # Defines
    self.OpenAccessDefines=[]
    
    # compiler options
    self.OpenAccessCompileArgs=[]

  #--------------------------------------------------------------------
  def Setup(self):
    if (os.name=='nt'):
      self.SetupNt()
    else:
      self.SetupUnix()
  
    #--------------------------------------------------------------------
    #  You shouldn't need to edit anything below here!
    #--------------------------------------------------------------------

    #--------------------------------------------------------------------
    # Source files
    #--------------------------------------------------------------------
    self.OpenAccessHeadersWrap=[
      'wrap/pyoa_header.h'
      ]
    self.OpenAccessHeadersSrc=[
      'src/pyoa_util.h',
      ]
    self.PackageSources=[
      'wrap/block1.cpp',
      'wrap/block2.cpp',
      'wrap/block3.cpp',
      'wrap/block4.cpp',
      'wrap/block5.cpp',
      'wrap/block6.cpp',
      'wrap/block7.cpp',
      'wrap/block8.cpp',
      'wrap/block9.cpp',
      'wrap/block10.cpp',
      'wrap/block11.cpp',
      'wrap/block12.cpp',
      'wrap/block13.cpp',
      'wrap/block14.cpp',
      'wrap/block15.cpp',
      'wrap/block16.cpp',
      'wrap/block17.cpp',
      'wrap/block18.cpp',
      'wrap/block19.cpp',
      'wrap/block20.cpp',
      'wrap/block21.cpp',
      'wrap/block22.cpp',
      'wrap/block23.cpp',
      'wrap/block24.cpp',
      'wrap/block25.cpp',
      'wrap/block26.cpp',
      'wrap/block27.cpp',
      'wrap/block28.cpp',
      'wrap/block29.cpp',
      'wrap/block30.cpp',
      'wrap/block31.cpp',
      'wrap/block32.cpp',
      'wrap/block33.cpp',
      'wrap/block34.cpp',
      'wrap/block35.cpp',
      'wrap/block36.cpp',
      'wrap/block37.cpp',
      'wrap/block38.cpp',
      'wrap/block39.cpp',
      'wrap/block40.cpp',
      'wrap/block41.cpp',
      'wrap/block42.cpp',
      'wrap/block43.cpp',
      'wrap/block44.cpp',
      'wrap/block45.cpp',
      'wrap/block46.cpp',
      'wrap/block47.cpp',
      'wrap/block48.cpp',
      'wrap/block49.cpp',
      'wrap/block50.cpp',
      'wrap/block51.cpp',
      'wrap/block52.cpp',
      'wrap/block53.cpp',
      'wrap/block54.cpp',
      'wrap/block55.cpp',
      'wrap/block56.cpp',
      'wrap/block57.cpp',
    ]
  def Build(self):
    #--------------------------------------------------------------------
    # Setup Instructions
    #--------------------------------------------------------------------
    import sys
    from distutils.core import setup,Extension
    from distutils.sysconfig import get_config_vars
    import types
    is64=0
    try:
      if (type(pow(2,40))==types.IntType):
        is64=1
    except:
      pass

    if (os.name!='nt'):
      if (os.uname()[0]=='SunOS'):
        vars=get_config_vars()
        if (is64):
          vars['CC']='CC'
          vars['BLDSHARED']='CC -G -xarch=v9'
          vars['LDSHARED']='CC -G -xarch=v9'
        else:
          vars['CC']='CC'
          vars['BLDSHARED']='CC -G -xarch=v8'
          vars['LDSHARED']='CC -G -xarch=v8'
        self.OpenAccessLibraries.append('Crun')
      if (os.uname()[0]=='Linux'):
        vars=get_config_vars()
        vars['CC']='g++'
        vars['OPT']='-DNDEBUG -O2 -g -D_GNU_SRC -fPIC -fpermissive'
        vars['BLDSHARED']='g++ -shared'
        vars['LDSHARED']='g++ -shared'
        if (os.uname()[4]=='x86_64'):
          vars['OPT']=vars['OPT']+' -m64'

    build_dist = ('bdist_wininst' in sys.argv)
    build = ('build' in sys.argv)

    if (os.name=='nt'):
      Prefix=''
    else:
      Prefix='lib'

    OpenAccessModule=Extension(
        "%spyoa%s"%(Prefix,oaversioncode),  # module names 
        self.PackageSources,                      # sources
        include_dirs=self.OpenAccessIncludeDirs,  # includes
        library_dirs=self.OpenAccessLibDirs,      # library paths
        libraries=self.OpenAccessLibraries,       # libraries
        define_macros=self.OpenAccessDefines,
        extra_compile_args=self.OpenAccessCompileArgs,
      )
    DataFiles=[]
    if (build):
      DataFiles=[('wrap',self.OpenAccessHeadersWrap),
        ('src',self.OpenAccessHeadersSrc)]
    setup(name="pyoa",
      version=pyoaversion,
      description="Python for OpenAccess",
      author="Donald Amundson", 
      author_email="amson@lsil.com", 
      packages=["openaccess22"],
      ext_package="openaccess22",
      ext_modules=[OpenAccessModule],
      data_files=DataFiles 
    )

  def BuildTools(self):
    #-------------------------------------------------------------------- 
    # Setup Instructions
    #--------------------------------------------------------------------
    import sys
    from distutils.core import setup,Extension
    from distutils.sysconfig import get_config_vars 
    setup(name="oaTools",
      version=pyoaversion, 
      description="Python for OpenAccess Tools",
      author="Donald Amundson",
      author_email="amson@lsil.com",
      packages=["oaTools"]
      )
#--------------------------------------------------------------------
# Main Run 
#--------------------------------------------------------------------
if (__name__=='__main__'):
  b=Builder()
  b.Setup()
  b.Build()
  #b.BuildTools()
  
