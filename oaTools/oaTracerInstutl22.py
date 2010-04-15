#********************************************************************
#* Copyright (C) 2003 LSI Logic Corporation.                        *
#*         All Rights Reserved.                                     *
#********************************************************************

#-----------------------------------------------
# oaTracerInstutl: Instance Picker for oaTracer
#-----------------------------------------------

import openaccess22
import oaTracerUtl22

#---------------------------------------------------------------
# DesignAssistant InstanceUtility Class
#
class cTracerInstUtility(oaTracerUtl22.cTracerUtilityCellview):
  #######################################
  # AllObjects
  #######################################
  def AllObjects(self):
    l=[]
    ns=openaccess22.oaNativeNS()
    s=openaccess22.oaString()
    for obj in self.mDesign.getInstsIter():
      l.append(obj)
    return l

  #######################################
  # FindObject
  #######################################
  def FindObject(self,name):
    ns=openaccess22.oaNativeNS()
    simplename=openaccess22.oaSimpleName(ns,name)
    typname=self.mDesign.getType().oaTypeEnum()
    if (typname==openaccess22.oacBlockType):
      return oaInst.static_find(self.mDesign,name)
    if (typname==openaccess22.oacModuleType):
      return oaModInst.static_find(self.mDesign,name)
    if (typname==openaccess22.oacOccurrenceType):
      return oaOccInst.static_find(self.mDesign.getTopOccurrence(),name)
    return None

  #######################################
  # ObjectName
  #######################################
  def ObjectName(self,obj):
    ns=openaccess22.oaNativeNS()
    s=openaccess22.oaString()
    if (obj.isOccObject()):
      obj.getPathName(ns,s)
    else:
      obj.getName(ns,s)
    return str(s)

  #######################################
  # Init
  #######################################
  def __init__(self,design,return_action=None):
    self.mDesign=design
    oaTracerUtl22.cTracerUtility.__init__(self,'Instance Utility',return_action)
    self.mWithLoadAll=0
    
#-----------------------------------------------------
