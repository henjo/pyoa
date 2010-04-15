#********************************************************************
#* Copyright (C) 2002 LSI Logic Corporation.                        *
#*         All Rights Reserved.                                     *
#********************************************************************

#-----------------------------------------------
# oaTracerUtl: Utility package for the Pickers in oaTracer
#-----------------------------------------------

import openaccess22
import BrowserWx
from BrowserWx import *

import re
import string

#---------------------------------------------------------------
def getInstCellviewName(inst):
  s=openaccess22.oaString()
  ns=openaccess22.oaNativeNS()
  inst.getCellName(ns,s)
  return str(s)

#---------------------------------------------------------------
def getInstCellviewNames(inst):
  s=openaccess22.oaString()
  ns=openaccess22.oaNativeNS()
  l=[]
  inst.getLibName(ns,s)
  l.append(str(s))
  inst.getCellName(ns,s)
  l.append(str(s))
  inst.getViewName(ns,s)
  l.append(str(s))
  return l

#---------------------------------------------------------------
def getInstCellviewFullname(inst):
  l=getInstCellviewNames(inst)
  return string.join(l,' ')
  
#---------------------------------------------------------------
def getInstModuleFullname(inst):
  s=openaccess22.oaString()
  ns=openaccess22.oaNativeNS()
  inst.getMaster().getName(ns,s)
  return str(s)
  
#---------------------------------------------------------------
def getOccInstOccFullname(inst):
  s=openaccess22.oaString()
  ns=openaccess22.oaNativeNS()
  inst.getPathName(ns,s)
  return str(s)

#---------------------------------------------------------------
def getCellviewName(design):
  design=design.getDesign()
  s=openaccess22.oaString()
  ns=openaccess22.oaNativeNS()
  design.getCellName(ns,s)
  return str(s)

#---------------------------------------------------------------
def getCellviewNames(design):
  design=design.getDesign()
  s=openaccess22.oaString()
  ns=openaccess22.oaNativeNS()
  l=[]
  design.getLibName(ns,s)
  l.append(str(s))
  design.getCellName(ns,s)
  l.append(str(s))
  design.getViewName(ns,s)
  l.append(str(s))
  return l

#---------------------------------------------------------------
def getCellviewFullname(design):
  l=getCellviewNames(design)
  return string.join(l,' ')
  
#---------------------------------------------------------------
def getModuleNames(module):
  design=module.getDesign()
  s=openaccess22.oaString()
  ns=openaccess22.oaNativeNS()
  l=[]
  design.getLibName(ns,s)
  l.append(str(s))
  design.getCellName(ns,s)
  l.append(str(s))
  design.getViewName(ns,s)
  l.append(str(s))
  module.getName(ns,s)
  l.append(str(s))
  return l

#---------------------------------------------------------------
def getModuleFullname(design):
  l=getModuleNames(design)
  return string.join(l,' ')
  
#---------------------------------------------------------------
def getDesObjectRepr(obj):
  if (obj.isBlockObject()):
    s='oaBlock: %s'%getCellviewFullname(obj)
  elif (obj.isModObject()):
    s='oaModule: %s'%getModuleFullname(obj)
  elif (obj.isOccObject()):
    s='oaOccurrence: %s '%getCellviewFullname(obj)
    oinst=obj.getOccInst()
    if (oinst):
      ss=openaccess22.oaString()
      ns=openaccess22.oaNativeNS()
      oinst.getPathName(ns,ss)
      s+=str(ss)
    else:
      s+='.'
  else:
    s=str(obj)
  return s  
  
#---------------------------------------------------------------
# master members:
#  self.AllObjects() - returns a list of all objects
#  self.FindObject(name) - Fetch an object by name
#  self.ObjectName(obj) - Returns an objects name
#
class cTracerUtility:
  #######################################
  # ObjectList
  #######################################
  def ObjectList(self):
    list=self.mReturnData
    if (len(list)==0):
      return None
    return list

  #######################################
  # FormatList
  #######################################
  def FormatList(self,list):
    if (not list):
      return None
    first=1
    str=""
    for l in list:
      if (first): first=None
      else: str = str + " "
      str = str + l
    return str

  #######################################
  # ObjectNames
  #######################################
  def ObjectNames(self):
    list=self.ObjectList()
    return self.FormatList(list)

  #######################################
  # ObjectName
  #######################################
  def ObjectName(self):
    list=self.ObjectList(self)
    if (list):
      return list[0]
    return list

  #######################################
  # ApplyUpdate
  #######################################
  def ApplyUpdate(self,l):
    v=self.mAction.get()
    values=self.mMenu.allvalues()
    dct={}
    for item in values:
      dct[item]=1
    if (v==0):
      for item in l:
        if (dct.has_key(item)): continue
        values.append(item)
        dct[item]=1
      newvalues=values
    elif (v==1): 
      newvalues=[]
      for item in l:
        if (not dct.has_key(item)): continue
        newvalues.append(item)
    elif (v==2): 
      newvalues=[]
      for item in l:
        if (dct.has_key(item)): continue
        newvalues.append(item)
    self.mMenu.clear()
    self.mMenu.insert(newvalues)
    return len(newvalues)

  #######################################
  # LoadAll
  #######################################
  def LoadAll(self,*v):
    values=[]
    for obj in self.AllObjects():
      values.append(self.ObjectName(obj))
    values.sort()
    return self.ApplyUpdate(values)

  #######################################
  # Read
  #######################################
  def Read(self,*v):
    values=[]
    str = self.mFile.get()
    if (not str):
      return None
    try:
      fp=open(str,'r')
      line=fp.readline()
      while (line):
        if (line[0]!='#'):
          obj=self.FindObject(line)
          if (obj!=None): values.append(self.ObjectName(obj))
        line=fp.readline()
    except:
      pass
    return self.ApplyUpdate(values)

  #######################################
  # Evaluate
  #######################################
  def Evaluate(self,*v):
    values=[]
    str = self.mExpr.get()
    if (not str):
      return None

    prog=re.compile(str)
    for obj in self.AllObjects():
      name=self.ObjectName(obj)
      if (prog.match(name)!=None):
        values.append(name)
    values.sort()
    return self.ApplyUpdate(values)

  #######################################
  # ReturnAll
  #######################################
  def ReturnAll(self,*v):
    self.mReturnData=self.mMenu.allvalues()
    if (self.mReturnAction):
      apply(self.mReturnAction)
    self.Detach()
    self.mReturnData=[]

  #######################################
  # ReturnSelected
  #######################################
  def ReturnSelected(self,*v):
    self.mReturnData=self.mMenu.values()
    if (self.mReturnAction):
      apply(self.mReturnAction)
    self.Detach()
    self.mReturnData=[]

  #######################################
  # DeselectAll
  #######################################
  def DeselectAll(self,*v):
    self.mMenu.select_all(0)

  #######################################
  # SelectAll
  #######################################
  def SelectAll(self,*v):
    self.mMenu.select_all(1)

  #######################################
  # RemoveSelected
  #######################################
  def RemoveSelected(self,*v):
    self.mMenu.remove_selected()

  #######################################
  # RemoveUnselected
  #######################################
  def RemoveUnselected(self,*v):
    self.mMenu.remove_unselected()

  #######################################
  # Empty
  #######################################
  def Empty(self,*v):
    if (self.mTop!=None):
      self.mMenu.clear()
    else:
      self.mDisplayData=[]

  #######################################
  # DetachAction
  #######################################
  def DetachAction(self):
    pass

  #######################################
  # Raise
  #######################################
  def Raise(self):
    self.mTop.Raise()

  #######################################
  # Report
  #######################################
  def Report(self,*v):
    self.mTop.Report()

  #######################################
  # Detach
  #######################################
  def Detach(self,*v):
    if (self.mTop==None): return
    self.mDisplayData=self.mMenu.allvalues()
    self.DetachAction()
    self.mTop.Detach()
    self.mTop=None
   
  #######################################
  # Display
  #######################################
  def Display(self,clear=0):
    if (self.mTop!=None):
      self.mTop.Raise()
      return
    # -------------------------------------
    # Main Display
    # -------------------------------------
    if (clear):
      self.mDisplayData=[]
      
    self.mTop=cWinTop(self.mTitle,self.Detach)
    self.mCol=self.mTop.CreateColumn(1)

    row=self.mCol.CreateRow(1)
    self.mMenu=cWinScrollListbox(row,multiple=1,minsize=(400,200),
                                 double_command=self.ReturnSelected)
    self.mMenu.insert(self.mDisplayData)
    col=row.CreateColumn()
    r1=col.CreateRow()
    cWinButton(r1,'DeselectAll',command=self.DeselectAll,minwidth=120)
    #r1.AddSpace(10)
    r2=col.CreateRow()
    cWinButton(r2,'SelectAll',command=self.SelectAll,minwidth=120)
    r3=col.CreateRow()
    cWinButton(r3,'RemoveSelected',command=self.RemoveSelected,minwidth=120)
    #r3.AddSpace(30)
    r4=col.CreateRow()
    cWinButton(r4,'RemoveUnselected',command=self.RemoveUnselected,minwidth=120)
    r5=col.CreateRow()
    cWinButton(r5,'Empty',command=self.Empty,minwidth=120)
    
    row=self.mCol.CreateRow()
    cWinLabel(row,'Action:')
    self.mAction=cWinChoice(row,['Add','Filter','Remove'])
    
    row=self.mCol.CreateRow()
    cWinLabel(row,'Expression:')
    self.mExpr=cWinEntry(row)
    cWinButton(row,'Eval',self.Evaluate)
    
    row=self.mCol.CreateRow()
    cWinLabel(row,'File:')
    self.mFile=cWinEntry(row)
    cWinButton(row,'Read',self.Read)

    row=self.mCol.CreateRow()
    cWinButton(row,text='ReturnSelected',command=self.ReturnSelected)
    cWinButton(row,text='ReturnAll',command=self.ReturnAll)
    cWinButton(row,text='Cancel',command=self.Detach)
    if (self.mWithLoadAll):
      cWinButton(row,text='LoadAll',command=self.LoadAll)
    #cWinButton(row,text='Report',command=self.Report)
    
    self.mTop.End()
    
  #######################################
  # Init
  #######################################
  def __init__(self,title,return_action=None):
    self.mReturnAction=return_action
    self.mReturnData=[]
    self.mDisplayData=[]
    self.mTop=None
    self.mTitle=title
    self.mWithLoadAll=1
    

#---------------------------------------------------------------
class cTracerUtilityCellview(cTracerUtility):
  #######################################
  # Display
  #######################################
  def Display(self,design=None,clear=0):
    if (design!=None):
      if (self.mDesign!=design): clear=1
      self.mDesign=design
    cTracerUtility.Display(self,clear=clear)
    
  #######################################
  # UpdateCellview
  #######################################
  def UpdateCellview(self,design):
    self.mDesign=design
    self.Empty()
    
  #######################################
  # Init
  #######################################
  def __init__(self,design,title,return_action=None):
    self.mDesign=design
    title=title+': '+oaTracerUtl.getCellviewFullname(self.mDesign)
    cTracerUtility.__init__(self,title,return_action)

