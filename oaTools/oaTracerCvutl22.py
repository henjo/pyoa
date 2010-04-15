#********************************************************************
#* Copyright (C) 2002 LSI Logic Corporation.                        *
#*         All Rights Reserved.                                     *
#********************************************************************

#-----------------------------------------------
# oaTracerCvUtl: Utility package for the Picking a CellView
#-----------------------------------------------

import openaccess22
import BrowserWx
from BrowserWx import *

import re
import string
import copy
import traceback

#-----------------------------------------------
def OpenAllLibraries():
    openaccess22.oaLibDefList.static_openLibs()
    
#-----------------------------------------------
def OpenLibrary(libname):
    ns=openaccess22.oaNativeNS()
    slibname=openaccess22.oaScalarName(ns,libname)

    # set mode to apped
    oas=openaccess22.oaString("lib.defs")
    liblist=openaccess22.oaLibDefList.static_get(oas,'r')

    found=0
    # We only check top level members for the entry
    for libdefmem in liblist.getMembersIter():
      if (libdefmem.getType().oaTypeEnum()!=openaccess22.oacLibDefType): continue
      sname=openaccess22.oaScalarName()
      libdefmem.getLibName(sname)
      sname.get(ns,oas)
      name=str(oas)
      if (name==libname):
        ostr=openaccess22.oaString()
        libdefmem.getLibPath(ostr)
        libpath=str(ostr)
        found=1
        break
    liblist.destroy()
    if (not found):
      return None
     
    lib=openaccess22.oaLib.static_find(slibname)
    if (not lib):
      lib=openaccess22.oaLib.static_open(slibname,libpath)
    access=openaccess22.oaLibAccessLevelEnum(openaccess22.oacReadLibAccessLevel)
    access=openaccess22.oaLibAccess(access)
    lib.getAccess(access)
    return lib

#-----------------------------------------------
def GetLibraryList():
    ns=openaccess22.oaNativeNS()

    # set mode to apped
    oas=openaccess22.oaString("lib.defs")
    liblist=openaccess22.oaLibDefList.static_get(oas,'r')

    result=[]
    # We only check top level members for the entry
    for libdefmem in liblist.getMembersIter():
      if (libdefmem.getType().oaTypeEnum()!=openaccess22.oacLibDefType): continue
      sname=openaccess22.oaScalarName()
      libdefmem.getLibName(sname)
      sname.get(ns,oas)
      name=str(oas)
      result.append(name)
    return result

#---------------------------------------------------------------
class cTracerDesignUtility:
  #######################################
  # PickLibrary
  #######################################
  def PickLibrary(self,*v):
    ns=openaccess22.oaNativeNS()
    try:
      s=self.mLibrary.get()
    except:
      return
    lib=OpenLibrary(s)
    if (lib==None): return
    self.mInPickLibrary=1
    self.EmptyCell()
    s=openaccess22.oaString()
    for cell in lib.getCellsIter():
      cell.getName(ns,s)
      self.mCellNames.append(str(s))
    self.mCell.setvalues(self.mCellNames)
    self.mInPickLibrary=0

  #######################################
  # PickCell
  #######################################
  def PickCell(self,*v):
    if (self.mInPickLibrary): return
    ns=openaccess22.oaNativeNS()
    try:
      s=self.mLibrary.get()
    except:
      return
    lib=OpenLibrary(s)
    if (lib==None): return
    try:
      s=openaccess22.oaScalarName(ns,self.mCell.get())
    except:
      return
    cell=openaccess22.oaCell.static_find(lib,s)
    if (cell==None): return
    self.mInPickCell=1
    self.EmptyView()
    s=openaccess22.oaString()
    for cv in cell.getCellViewsIter():
      view=cv.getView()
      view.getName(ns,s)
      self.mViewNames.append(str(s))
    self.mView.setvalues(self.mViewNames)
    self.mInPickCell=0

  #######################################
  # PickView
  #######################################
  def PickView(self,*v):
    if (self.mInPickLibrary): return
    if (self.mInPickCell): return
    ns=openaccess22.oaNativeNS()
    libtext=self.mLibrary.get()
    libName=openaccess22.oaScalarName(ns,libtext)
    lib=OpenLibrary(libtext)
    if (lib==None): return
    cellName=openaccess22.oaScalarName(ns,self.mCell.get())
    cell=openaccess22.oaCell.static_find(lib,cellName)
    if (cell==None): return
    viewName=openaccess22.oaScalarName(ns,self.mView.get())
    design=openaccess22.oaDesign.static_open(libName,cellName,viewName,'r')
    if (design==None):
      return
    
    self.mInView=1 
    self.EmptyModule()
    self.mModuleNames.append(' -Design-')
    self.mModuleNames.append(' -TopBlock-')
    self.mModuleNames.append(' -TopModule-')
    self.mModuleNames.append(' -TopOccurrence-')
    s=openaccess22.oaString()
    for mod in design.getModulesIter():
      mod.getName(ns,s)
      self.mModuleNames.append(str(s))
    self.mModule.setvalues(self.mModuleNames)
    design.close()
    self.mInView=0

  #######################################
  # PickModule
  #######################################
  def PickModule(self,*v):
    pass

  #######################################
  # ReturnSelected
  #######################################
  def Ok(self,*v):
    self.mLibraryName=self.mLibrary.get()
    self.mCellName=self.mCell.get()
    self.mViewName=self.mView.get()
    self.mModuleName=self.mModule.get()
    if (self.mLibraryName!="" and
        self.mCellName!="" and
        self.mViewName!="" and
        self.mModuleName!=""):
  
      if (self.mReturnAction):
        apply(self.mReturnAction)
      self.Detach()

  #######################################
  # SelectedValue
  #######################################
  def SelectedValue(self):
    if (self.mTop==None): return None
    self.mReturnValue=[self.mLibraryName,self.mCellName,self.mViewName,self.mModuleName]
    return self.mReturnValue

  #######################################
  # Detach
  #######################################
  def Detach(self,*v):
    if (self.mTop==None): return
    self.mTop.Detach()
    self.mTop=None
   
  #######################################
  # Display
  #######################################
  def Display(self):
    if (self.mTop!=None):
      self.mTop.Raise()
      return
    # -------------------------------------
    # Main Display
    # -------------------------------------
    self.mTop=cWinTop(self.mTitle,self.Detach)
    self.mCol=self.mTop.CreateColumn(1)

    self.mLibrary=cWinRowComboButton(self.mCol,"Library:",self.mLibraryNames,
      command=self.PickLibrary,label_minwidth=60,button_minwidth=200)

    self.mCell=cWinRowComboButton(self.mCol,"Cell:",[],
      command=self.PickCell,label_minwidth=60,button_minwidth=200)
    
    self.mView=cWinRowComboButton(self.mCol,"View:",[],
      command=self.PickView,label_minwidth=60,button_minwidth=200)
    
    self.mModule=cWinRowComboButton(self.mCol,"Module:",[],
      command=self.PickModule,label_minwidth=60,button_minwidth=200)

    row=self.mCol.CreateRow()
    cWinButton(row,text='OK',command=self.Ok)
    cWinButton(row,text='Cancel',command=self.Detach)
    
    self.mTop.End()
    
  #######################################
  # EmptyModule
  #######################################
  def EmptyModule(self):
    self.mCurrentModule=None
    self.mModuleNames=[]
    if (self.mTop):
      self.mModule.clear()

  #######################################
  # EmptyView
  #######################################
  def EmptyView(self):
    self.mCurrentView=None
    self.mViewNames=[]
    self.EmptyModule()
    if (self.mTop):
      self.mView.clear()

  #######################################
  # EmptyCell
  #######################################
  def EmptyCell(self):
    self.mCellNames=[]
    self.EmptyView()
    if (self.mTop):
      self.mCell.clear()

  #######################################
  # EmptyLib
  #######################################
  def EmptyLib(self):
    self.mLibraryNames=[]
    self.EmptyCell()
    if (self.mTop):
      self.mLibrary.clear()

  #######################################
  # Init
  #######################################
  def __init__(self,title,return_action=None):
    self.mReturnAction=return_action
    self.mTitle=title
    self.mTop=None
    self.mReturnValue=[]
    self.EmptyLib()
    self.mLibraryNames=GetLibraryList()
    self.mInPickLibrary=0
    self.mInPickCell=0
    self.mInPickView=0

#-----------------------------------------------
class oaDesignPickApp:
  #-----------------------------------------------
  def __init__(self):
    self.mDesignPicker=None
    self.mDesign=None
    self.mApp=None
    self.mCloseFun=None
    self.mData=None
    self.mPickMode=None

  #-----------------------------------------------
  def Help(self):
    pass

  #-----------------------------------------------
  def ProcessStdArgs(self):
    if (len(self.mArgs)<1): 
       return None

    if (self.mArgs[0]=='-topblock'):
      if (len(self.mArgs)<4):
          print "topblock requires: -topblock libName cellName viewName"
          return (data,commands)
      ns=openaccess22.oaNativeNS()
      try:
        lib=OpenLibrary(self.mArgs[1])
        libName=openaccess22.oaScalarName(ns,self.mArgs[1])
        cellName=openaccess22.oaScalarName(ns,self.mArgs[2])
        viewName=openaccess22.oaScalarName(ns,self.mArgs[3])
        design=openaccess22.oaDesign.static_open(libName,cellName,viewName,'r')
        if (design!=None):
          #self.mCloseFun=design.close
          self.mDesign=design.getTopBlock()
          self.mData=self.mDesign
        return 1
      except:
        traceback.print_exc()

    if (self.mArgs[0]=='-topmodule'):
      if (len(self.mArgs)<4):
          print "topmodule requires: -topmodule libName cellName viewName"
          return (data,commands)
      ns=openaccess22.oaNativeNS()
      try:
        lib=OpenLibrary(self.mArgs[1])
        libName=openaccess22.oaScalarName(ns,self.mArgs[1])
        cellName=openaccess22.oaScalarName(ns,self.mArgs[2])
        viewName=openaccess22.oaScalarName(ns,self.mArgs[3])
        self.mDesign=openaccess22.oaDesign.static_open(libName,cellName,viewName,'r')
        design=openaccess22.oaDesign.static_open(libName,cellName,viewName,'r')
        if (design!=None):
          #self.mCloseFun=design.close
          self.mDesign=self.mDesign.getTopModule()
          self.mData=self.mDesign
        return 1
      except:
        traceback.print_exc()

    if (self.mArgs[0]=='-topocc'):
      if (len(self.mArgs)<4):
          print "topocc requires: -topocc libName cellName viewName"
          return (data,commands)
      ns=openaccess22.oaNativeNS()
      try:
        lib=OpenLibrary(self.mArgs[1])
        libName=openaccess22.oaScalarName(ns,self.mArgs[1])
        cellName=openaccess22.oaScalarName(ns,self.mArgs[2])
        viewName=openaccess22.oaScalarName(ns,self.mArgs[3])
        self.mDesign=openaccess22.oaDesign.static_open(libName,cellName,viewName,'r')
        design=openaccess22.oaDesign.static_open(libName,cellName,viewName,'r')
        if (design!=None):
          #self.mCloseFun=design.close
          self.mDesign=self.mDesign.getTopOccurrence()
          self.mData=self.mDesign
        return 1
      except:
        traceback.print_exc()

    if (self.mArgs[0]=='-module'):
      if (len(self.mArgs)<5):
          print "module requires: -module libName cellName viewName modName"
          return (data,commands)
      ns=openaccess22.oaNativeNS()
      try:
        self.mData=None
        lib=OpenLibrary(self.mArgs[1])
        libName=openaccess22.oaScalarName(ns,self.mArgs[1])
        cellName=openaccess22.oaScalarName(ns,self.mArgs[2])
        viewName=openaccess22.oaScalarName(ns,self.mArgs[3])
        modName=openaccess22.oaScalarName(ns,self.mArgs[4])
        design=openaccess22.oaDesign.static_open(libName,cellName,viewName,'r')
        if (design!=None):
          module=openaccess22.oaModule.static_find(design,modName)
          if (module):
            #self.mCloseFun=design.close
            self.mDesign=module
            self.mData=self.mDesign
        return 1
      except:
        traceback.print_exc()

    elif (self.mArgs[0]=="-pick"):
      self.mPickMode=1
      return 1
      
    return None
    
  #-----------------------------------------------
  def ProcessOtherArgs(self):
    return None
    
  #-----------------------------------------------
  def ProcessArgs(self):
    if (len(self.mArgs)<1):
      print "** No mode given"
      self.Help()
      return None
      
    if (self.ProcessStdArgs()):
      return 1
      
    if (self.ProcessOtherArgs()):
      return 1
    
    return None
      
  #-----------------------------------------------
  def Init(self):
    openaccess22.oaWaferInit()
    OpenAllLibraries()

  #-----------------------------------------------
  def OpenGui(self):
    pass
    
  #-----------------------------------------------
  def ProcessPick(self):
    data=self.mDesignPicker.SelectedValue()
    if (data!=None): 
      self.OpenDesign(data)
      if (self.mDesign!=None):
        self.OpenGui()
        return
    self.mApp.exit()
    return

  #---------------------------------------------------------------
  def OpenDesign(self,data):
    ns=openaccess22.oaNativeNS()
    try:
      self.mData=None
      lib=OpenLibrary(data[0])
      libName=openaccess22.oaScalarName(ns,data[0])
      cellName=openaccess22.oaScalarName(ns,data[1])
      viewName=openaccess22.oaScalarName(ns,data[2])
      design=openaccess22.oaDesign.static_open(libName,cellName,viewName,'r')
      if (design):
        if (data[3]==' -Design-'):  
          self.mDesign=design
        elif (data[3]==' -TopBlock-'):  
          self.mDesign=design.getTopBlock()
        elif (data[3]==' -TopModule-'):  
          self.mDesign=design.getTopModule()
        elif (data[3]==' -TopOccurrence-'):  
          self.mDesign=design.getTopOccurrence()
        else:
          modName=openaccess22.oaScalarName(ns,data[3])
          self.mDesign=openaccess22.oaModule.static_find(design,modName)
        #self.mCloseFun=design.close
      self.mData=self.mDesign
    except:
      traceback.print_exc()

  #---------------------------------------------------------------
  def Run(self,*args):
    print "Args",args
    self.mArgs=copy.copy(args)
    self.mApp=cWinApp()
    self.Init()
    self.ProcessArgs()
    if (self.mPickMode):
      self.mDesignPicker=cTracerDesignUtility('Pick Library Cell View',
                                                  self.ProcessPick)
      self.mDesignPicker.Display()
      self.mApp.main_loop()
    else:
      if (self.mData!=None):
        self.OpenGui()
        self.mApp.main_loop()
    self.mApp=None
    
  
  
    

