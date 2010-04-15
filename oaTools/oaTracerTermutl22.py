#********************************************************************
#* Copyright (C) 2003 LSI Logic Corporation.                        *
#*         All Rights Reserved.                                     *
#********************************************************************

#-----------------------------------------------
# oaTracerTermutl: Term Picker for oaTracer
#-----------------------------------------------

import openaccess22
import oaTracerUtl22

#---------------------------------------------------------------
# DesignAssistant InstanceUtility Class
#
class cTracerTermUtility(oaTracerUtl22.cTracerUtilityCellview):
  #######################################
  # AllObjects
  #######################################
  def AllObjects(self):
    l=[]
    ns=openaccess22.oaNativeNS()
    s=openaccess22.oaString()
    for obj in self.mDesign.getTermsIter(openaccess22.oacTermIterAll):
      l.append(obj)
    return l

  #######################################
  # FindObject
  #######################################
  def FindObject(self,name):
    ns=openaccess22.oaNativeNS()
    name=openaccess22.oaName(ns,name)
    typname=self.mDesign.getType().oaTypeEnum()
    if (typname==openaccess22.oacBlockType):
      return oaTerm.static_find(self.mDesign,name)
    if (typname==openaccess22.oacModuleType):
      return oaModTerm.static_find(self.mDesign,name)
    if (typname==openaccess22.oacOccurrenceType):
      return oaOccTerm.static_find(self.mDesign,name)
    return None
    
  #######################################
  # ObjectName
  #######################################
  def ObjectName(self,obj):
    ns=openaccess22.oaNativeNS()
    s=openaccess22.oaString()
    obj.getName(ns,s)
    return str(s)

  #######################################
  # Init
  #######################################
  def __init__(self,design,return_action=None):
    self.mDesign=design
    oaTracerUtl22.cTracerUtility.__init__(self,'Term Utility',return_action)
    
#-----------------------------------------------------
