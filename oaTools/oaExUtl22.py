#
#********************************************************************
#* Copyright (C) 2004 LSI Logic Corporation.                        *
#*         All Rights Reserved.                                     *
#********************************************************************
#
# Sample Test program to try Observers

import openaccess22
from openaccess22 import *

#-----------------------------------------------
def CreateLibrary(libname,libpath):
    ns=oaNativeNS()
    slibname=oaScalarName(ns,libname)

    # set mode to apped
    print "Setup lib.defs"
    oas=oaString("lib.defs")
    liblist=oaLibDefList.static_get(oas,'a')

    print "CreateLibrary: %s"%libname
    found=0
    # We only check top level members for the entry
    for libdefmem in liblist.getMembersIter():
      if (libdefmem.getType().oaTypeEnum()!=oacLibDefType): continue
      sname=oaScalarName()
      libdefmem.getLibName(sname)
      sname.get(ns,oas)
      name=str(oas)
      print "  lib.defs Entry:",name
      if (name==libname):
        print "  Found in lib.defs"
        ostr=oaString()
        libdefmem.getLibPath(ostr)
        libpath=str(ostr)
        found=1
        break
    if (not found):
      print " Adding to lib.defs"
      oaLibDef.static_create(liblist,slibname,libpath)
      print " Save Lib List"
      liblist.save()
    liblist.destroy()
      
    print "  Using LibPath: %s"%libpath
    if (oaLib.static_exists(libpath)):
      print "  Openned Existing Library"
      lib=oaLib.static_open(slibname,libpath)
      return lib
    print "  Creating Library"
    lib=oaLib.static_create(slibname,libpath,
      oaLibMode(oacSharedLibMode), # mode
      "oaDMTurbo"
      # "oaDMFileSys"  # mode
    )

    return lib
    
#-----------------------------------------------
def OpenLibrary(libname):
    ns=oaNativeNS()
    slibname=oaScalarName(ns,libname)

    # set mode to apped
    print "Setup lib.defs"
    oas=oaString("lib.defs")
    liblist=oaLibDefList.static_get(oas,'r')

    print "OpenLibrary: %s"%libname
    found=0
    # We only check top level members for the entry
    for libdefmem in liblist.getMembersIter():
      if (libdefmem.getType().oaTypeEnum()!=oacLibDefType): continue
      sname=oaScalarName()
      libdefmem.getLibName(sname)
      sname.get(ns,oas)
      name=str(oas)
      print "  lib.defs Entry:",name
      if (name==libname):
        print "  Found in lib.defs"
        ostr=oaString()
        libdefmem.getLibPath(ostr)
        libpath=str(ostr)
        found=1
        break
    liblist.destroy()
    if (not found):
      print "Library Not found:",libname
      return None
      
    print "  Using LibPath: %s"%libpath
    print "  Openned Existing Library"
    lib=oaLib.static_open(slibname,libpath)
    return lib
    
#-----------------------------------------------
def CreateDesign(libname,cellname,viewname):
    print "Creating Design: %s/%s/%s"%(libname,cellname,viewname)
    ns=oaNativeNS()
    libName=oaScalarName(ns,libname)
    cellName=oaScalarName(ns,cellname)
    viewName=oaScalarName(ns,viewname)
    vt=oaViewType.static_get(oaReservedViewType(oacMaskLayout))
    design=oaDesign.static_open(libName,cellName,viewName,vt,'w')
    return design

#-----------------------------------------------
def OpenDesign(libname,cellname,viewname,mode='r'):
    print "Creating Design: %s/%s/%s"%(libname,cellname,viewname)
    ns=oaNativeNS()
    libName=oaScalarName(ns,libname)
    cellName=oaScalarName(ns,cellname)
    viewName=oaScalarName(ns,viewname)
    vt=oaViewType.static_get(oaReservedViewType(oacMaskLayout))
    design=oaDesign.static_open(libName,cellName,viewName,vt,mode)
    return design

