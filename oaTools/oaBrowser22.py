#********************************************************************
#* Copyright (C) 2002-2003 LSI Logic Corporation.                   *
#*         All Rights Reserved.                                     *
#********************************************************************

#-----------------------------------------------
# Browse the Lib, Cell, and Views available
#-----------------------------------------------

import BrowserWx
from BrowserWx import *
import Browser
import BrowserOA22

import sys
import copy
import traceback

import openaccess22
from openaccess22 import *

import oaTracerCvutl22

#-----------------------------------------------
class cCloser:
  def __init__(self,things):
    self.mThings=things
    
  def close(self):
    for item in self.mThings:
      apply(item,())
      
#-----------------------------------------------
#-----------------------------------------------
class oaBrowserApp(oaTracerCvutl22.oaDesignPickApp):
  #-----------------------------------------------
  def Help(self):
    print """\
  Usage: python oaBrowser.py -mode
    modes:
      -libs
      -cellview  libName cellName viewName
      -topblock  libName cellName viewName
      -topmodule libName cellName viewName
      -topocc    libName cellName viewName
      -module    libName cellName viewName modName
      -celltech  libName cellName viewName
      -libtech   libName
      -module
      -pick
  """

  #-----------------------------------------------
  def ProcessOtherArgs(self):
    if (self.mArgs[0]=='-libtech'):
      if (len(self.mArgs)<2):
        print "-libtech requires: -libtech libName"
        return None
      ns=oaNativeNS()
      try:
        lib=oaTracerCvutl22.OpenLibrary(self.mArgs[1])
        self.mData=oaTech.static_open(lib,'r')
        #if (self.mData):
        #  self.mCloseFun=cCloser(self.mData.close,lib.close)
        return 1
      except:
        traceback.print_exc()

    elif (self.mArgs[0]=='-cellview'):
      if (len(self.mArgs)<4):
        print "-cellview requires: -cellview libName cellName viewName"
        return None
      ns=oaNativeNS()
      try:
        libName=oaScalarName(ns,self.mArgs[1])
        cellName=oaScalarName(ns,self.mArgs[2])
        viewName=oaScalarName(ns,self.mArgs[3])
        design=oaDesign.statis_open(libName,cellName,viewName,'r')
        self.mData=design
        #if (self.mData):
        #  self.mCloseFun=design.close
        return 1
      except:
        traceback.print_exc()

    elif (self.mArgs[0]=='-celltech'):
      if (len(self.mArgs)<4):
        print "-celltech requires: -celltech libName cellName viewName"
        return None
      ns=oaNativeNS()
      try:
        libName=oaScalarName(ns,self.mArgs[1])
        cellName=oaScalarName(ns,self.mArgs[2])
        viewName=oaScalarName(ns,self.mArgs[3])
        design=oaDesign.statis_open(libName,cellName,viewName,'r')
        self.mData=design.getTech()
        #if (self.mData):
        #  self.mCloseFun=design.close
        return 1
      except:
        traceback.print_exc()

    elif (self.mArgs[0]=="-libs"):
      data=oaTracerCvutl22.GetLibraryList()
      self.mData=[]
      for libname in data:
        self.mData.append(oaTracerCvutl22.OpenLibrary(libname))
      return 1

    elif (self.mArgs[0]=="-module"):
      self.mData=openaccess22
      return 1
      
    return None

  #-----------------------------------------------
  def OpenGui(self):
    self.mGuiBrowser=Browser.cBrowser(self.mData,
                                      BrowserOA22.cOpenAccessBrowserHints(),
                                      0,self.mCloseFun)
    self.mGuiBrowser.Display()

#---------------------------------------------------------------
def Run(*args):
  c=oaBrowserApp()
  apply(c.Run,args)
  
#---------------------------------------------------------------
if (__name__=='__main__'):
  apply(Run,sys.argv[1:])
 
