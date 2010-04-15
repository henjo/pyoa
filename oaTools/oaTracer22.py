#********************************************************************
#* Copyright (C) 2003 LSI Logic Corporation.                        *
#*         All Rights Reserved.                                     *
#********************************************************************

#-----------------------------------------------
# oaTracer:
#  Sample demo program of Python for openaccess22
#-----------------------------------------------

import openaccess22
import BrowserWx
from BrowserWx import *

import Browser
import BrowserOA22

import oaTracerNetutl22
import oaTracerTermutl22
import oaTracerInstutl22
import oaTracerUtl22
import oaTracerCvutl22

import string
import re
import sys
import copy
import traceback

#---------------------------------------------------------------------
# This class does single traces of items.
# The Application Iterface to this class consists of 2 routines:
#   ParseCommand(cmd) - Takes a command string and parses/executes it.
#   ParseFile(filename) - Takes a file name of commands
#     Both commands return the report as a list of lines
#     Errors are return by exception: cTraceSingle.CommandError
# The commands are:
#   instance name, .... name   - trace the named instances
#   net name, .... name        - trace the named nets
#   port name, .... name       - trace the named ports
#   depth n                    - set the trace depth
#   directions dir_name        - set the direction: in out inout
#

class cTraceSingle:
  CommandError = "cTraceSingle_CommandError"

  ##############################################################
  #  init : initialize the class, empty log files.
  def __init__(self,design,empty=0):
    self.mDir = 2
    self.mMaxDepth = 0
    self.mReport = []
    self.mDesign = design
    self.mNS = openaccess22.oaNativeNS()
    self.mFirstObj=None

    mode="a"
    if (empty): mode="w"
    self.mFp=None
    filename="oaTracer.log"
    if (filename):
      try:
        self.mFp=open(filename,mode)
        #print "[Open tracer.log]"
      except:
        pass


  def __del__(self):
    if (self.mFp):
      self.mFp.close()
      #print "[Close tracer.log]"

  ##############################################################
  #  trace_instance: This routine walks all the connects on an instance
  #  and reports the connections. If we are tracing deeper, it then
  #  calls trace_nets on the connected nets.
  #    inst - the instance we are tracing
  #    dir - the trace directions 0=input, 1=output
  #    depth - currect tracing depth
  #
  def trace_instance(self,inst,dir,depth):
    rep=''
    for i in range(depth): rep=rep+'  '
    if (inst.isBlockObject()):
      rep=rep+'Cell: '+oaTracerUtl22.getInstCellviewFullname(inst)
    elif (inst.isModObject() and inst.isModDesignInst()):
      rep=rep+'Cell: '+oaTracerUtl22.getInstCellviewFullname(inst)
    elif (inst.isModObject() and inst.isModModuleInst()):
      rep=rep+'Mod: '+oaTracerUtl22.getInstModuleFullname(inst)
    elif (inst.isOccObject() and inst.isOccDesignInst()):
      rep=rep+'Cell: '+oaTracerUtl22.getInstCellviewFullname(inst)
    elif (inst.isOccObject() and inst.isOccModuleInst()):
      rep=rep+'Mod: '+oaTracerUtl22.getInstModuleFullname(inst)
    self.mReport.append(rep)
    if (inst.isOccObject()):
      rep=''
      for i in range(depth): rep=rep+'  '
      rep=rep+'Occ: '+oaTracerUtl22.getOccInstOccFullname(inst)
      self.mReport.append(rep)
    for p in range(3):
      if (p==1 and dir==0): continue
      if (p==0 and dir==1): continue
      for instterm in inst.getInstTermsIter():
        term=instterm.getTerm()
        if (term==None): continue  # Unbound
        termtype=term.getTermType().oaTermTypeEnum()
        if (p==0 and termtype!='oacInputTermType'): continue
        if (p==1 and termtype!='oacOutputTermType'): continue
        if (p==2 and termtype!='oacInputOutputTermType'): continue
        net=instterm.getNet()
        if (net!=None): 
          netname=openaccess22.oaString()
          if (net.isOccObject()):
            net.getPathName(self.mNS,netname)
          else:
            net.getName(self.mNS,netname)
          netname=str(netname)
        else: netname="OPEN"
        fo=-1
        if (depth<self.mMaxDepth and p>=1 and net!=None):
          fo=self.trace_net_fo(net)
        rep=''
        for i in range(depth): rep=rep+"  "
        termname=openaccess22.oaString()
        instterm.getTermName(self.mNS,termname)
        termname=str(termname)
        rep=rep+"Net: "+netname+" ("+termname+":"
        if (termtype=='oacInputTermType'): rep=rep+"I"
        elif (termtype=='oacOutputTermType'): rep=rep+"O"
        elif (termtype=='oacInputOutputTermType'): rep=rep+"B"
        else: rep=rep+"X"
        rep=rep+") "
        if (fo>=0): rep=rep+" { fanout="+str(fo)+" }"
        self.mReport.append(rep)
        if (depth>=self.mMaxDepth): continue
        if (net!=None): self.trace_net(net,p,depth+1)

  #-------------------------------------------------------------------
  #  trace_net: This routine walks all the connects on a net
  #  and reports the connections. If we are tracing deeper, it then
  #  calls trace_instance on the connected nets.
  #    n - the net we are tracing
  #    dir - the trace directions 0=input, 1=output
  #    depth - currect tracing depth
  #
  def trace_net(self,net,dir,depth):
    self.trace_enet(net,dir,depth)
    for enet in net.getEquivalentNetsIter():
      rep=''
      for i in range(depth-1): rep=rep+"  "
      repname=openaccess22.oaString()
      if (enet.isOccObject()):
        enet.getPathName(self.mNS,repname)
      else:
        enet.getName(self.mNS,repname)
      rep=rep+" EqNet: "+str(repname)
      self.mReport.append(rep)
      self.trace_enet(enet,self.mDir,depth)
    for mnet in net.getSingleBitMembersIter():
      if (mnet==net): continue
      rep=''
      for i in range(depth-1): rep=rep+"  "
      repname=openaccess22.oaString()
      if (mnet.isOccObject()):
        mnet.getPathName(self.mNS,repname)
      else:
        mnet.getName(self.mNS,repname)
      rep=rep+" MemNet: "+str(repname)
      self.mReport.append(rep)
      self.trace_net(mnet,self.mDir,depth)
      
    
  def trace_enet(self,net,dir,depth):
    for p in range(3):
      if (p==1 and dir==0): continue
      if (p==0 and dir==1): continue
      for mnet,index in net.getMemberNetsIter():
        for bterm in mnet.getTermsIter():
          term=bterm.getBit(index)
          termtype=term.getTermType().oaTermTypeEnum()
          if (p==0 and termtype!='oacInputTermType'): continue
          if (p==1 and termtype!='oacOutputTermType'): continue
          if (p==2 and termtype!='oacInputOutputTermType'): continue
          rep=''
          for i in range(depth): rep=rep+"  "
          termname=openaccess22.oaString()
          term.getName(self.mNS,termname)
          termname=str(termname)
          rep=rep+"Term: "+termname+" ("
          if (termtype=='oacInputTermType'): rep=rep+"I"
          elif (termtype=='oacOutputTermType'): rep=rep+"O"
          elif (termtype=='oacInputOutputTermType'): rep=rep+"B"
          else: rep=rep+"X"
          rep+=")"
          self.mReport.append(rep)
    for p in range(3):
      for mnet,index in net.getMemberNetsIter():
        for instterm in mnet.getInstTermsIter():
          bterm=instterm.getTerm()
          if (bterm==None): continue  # Unbound
          term=bterm.getBit(index)
          if (term==None): continue  # Unbound
          termtype=term.getTermType().oaTermTypeEnum()
          if (p==0 and termtype!='oacOutputTermType'): continue
          if (p==1 and termtype!='oacInputTermType'): continue
          if (p==2 and termtype!='oacInputOutputTermType'): continue
          rep=''
          for i in range(depth): rep=rep+"  "
          inst=instterm.getInst()
          termname=openaccess22.oaString()
          #instterm.getTermName(self.mNS,termname)
          term.getName(self.mNS,termname)
          termname=str(termname)
          instname=openaccess22.oaString()
          if (inst.isOccObject()):
            inst.getPathName(self.mNS,instname)
          else:
            inst.getName(self.mNS,instname)
          instname=str(instname)
          rep=rep+"Inst: "+instname+" ("+termname+":"
          if (termtype=='oacInputTermType'): rep=rep+"I"
          elif (termtype=='oacOutputTermType'): rep=rep+"O"
          elif (termtype=='oacInputOutputTermType'): rep=rep+"B"
          else: rep=rep+"X"
          rep=rep+")"
          self.mReport.append(rep)
          if (depth>=self.mMaxDepth): continue
          self.trace_instance(inst,p,depth+1)

  #-------------------------------------------------------------------
  #  trace_net_fot: count fanout on a net
  #
  def trace_net_fo(self,net):
    net=net.getPreferredEquivalent()
    enets=[net]
    for enet in net.getEquivalentNetsIter():
      enets.append(enet)
    fo=0
    instterms={}
    for enet in enets:
      for net,index in net.getMemberNetsIter():
        for iti in net.getInstTermsIter():
          s=str(iti)
          if (instterms.has_key(s)): continue
          instterms[s]=1
          bterm=iti.getTerm()
          if (bterm==None): continue
          term=bterm.getBit(index)
          if (term==None): continue
          termtype=term.getTermType().oaTermTypeEnum()
          if (termtype=='oacInputTermType' or termtype=='oacInputOutputTermType'): 
            fo=fo+1
    return fo
    
  #-------------------------------------------------------------------
  #  validate: check for valid design
  #
  def validate(self,cmd,names):
    self.mReport=[]
    list=string.split(names)
    return list

  #-------------------------------------------------------------------
  #  log_cmd:
  #
  def log_cmd(self,cmd,names):
    if (self.mFp):
      try:
        self.mFp.write("Cmd: %s %s\n"%(cmd,names))
      except:
        pass

  #-------------------------------------------------------------------
  #  log_report:
  #
  def log_report(self,cmd,names):
    if (self.mFp):
      self.log_cmd(cmd,names)
      try:
        for item in self.mReport:
          self.mFp.write(item)
          self.mFp.write('\n')
      except:
        pass

  #-------------------------------------------------------------------
  #  trace_instance_list: generate a full trace/report for all the
  #  instances in the input list.
  #
  def trace_instance_list(self,cmd,names):
    list=self.validate(cmd,names)
    for instname in list:
      name=openaccess22.oaSimpleName(self.mNS,instname)
      inst=None
      typname=self.mDesign.getType().oaTypeEnum()
      if (typname==openaccess22.oacBlockType):
        inst=openaccess22.oaInst.static_find(self.mDesign,name)
      if (typname==openaccess22.oacModuleType):
        inst=openaccess22.oaModInst.static_find(self.mDesign,name)
      if (typname==openaccess22.oacOccurrenceType):
        inst=openaccess22.oaOccInst.static_find(self.mDesign.getTopOccurrence(),name)
      if (inst==None):
        print "Can't Find Instance: ",instname
        continue

      instname=openaccess22.oaString()      
      if (inst.isOccObject()):
        inst.getPathName(self.mNS,instname)
      else:
        inst.getName(self.mNS,instname)
      instname=str(instname)
      rep = "Inst: "+instname
      self.mReport.append(rep)
      if (self.mFirstObj==None): self.mFirstObj=inst
      self.trace_instance(inst,self.mDir,1)
    self.log_report(cmd,names)

  #-------------------------------------------------------------------
  #  trace_net_list: generate a full trace/report for all the
  #  nets in the input list.
  #
  def trace_net_list(self,cmd,names):
    list=self.validate(cmd,names)
    for netname in list:
      name=openaccess22.oaName(self.mNS,netname)
      net=None
      typname=self.mDesign.getType().oaTypeEnum()
      if (typname==openaccess22.oacBlockType):
        net=openaccess22.oaNet.static_find(self.mDesign,name)
      if (typname==openaccess22.oacModuleType):
        net=openaccess22.oaModNet.static_find(self.mDesign,name)
      if (typname==openaccess22.oacOccurrenceType):
        net=openaccess22.oaOccNet.static_find(self.mDesign.getTopOccurrence(),name)
      if (net==None):
        if (name.getType().oaNameTypeEnum()==openaccess22.oacVectorBitNameType):
          sname=openaccess22.oaScalarName()
          vname=name.getVectorBit()
          vname.getBaseName(sname)
          if (typname==openaccess22.oacBlockType):
            net=openaccess22.oaBusNetBit.static_find(self.mDesign,sname,vname.getIndex())
          if (typname==openaccess22.oacModuleType):
            net=openaccess22.oaModBusNetBit.static_find(self.mDesign,sname,vname.getIndex())
          if (typname==openaccess22.oacOccurrenceType):
            net=openaccess22.oaOccBusNetBit.static_find(self.mDesign.getTopOccurrence(),sname,vname.getIndex())
        if (net==None):
          print "Can't Find Net: ",netname
          continue 
      for snet in net.getSingleBitMembersIter():
        net=snet.getPreferredEquivalent()
        fo=self.trace_net_fo(net)

        repname=openaccess22.oaString()
        if (net.isOccObject()):
          net.getPathName(self.mNS,repname)
        else:
          net.getName(self.mNS,repname)
        rep = "Net: "+str(repname)+" { fanout="+str(fo)+" }"
        self.mReport.append(rep)
        if (self.mFirstObj==None): self.mFirstObj=net
        self.trace_net(net,self.mDir,1)
      
    self.log_report(cmd,names)

  #-------------------------------------------------------------------
  #  trace_term_list: generate a full trace/report for all the
  #  terms in the input list.
  #
  def trace_term_list(self,cmd,names):
    list=self.validate(cmd,names)
    for termname in list:
      name=openaccess22.oaName(self.mNS,termname)
      term=None
      typname=self.mDesign.getType().oaTypeEnum()
      if (typname==openaccess22.oacBlockType):
        term=openaccess22.oaTerm.static_find(self.mDesign,name)
      if (typname==openaccess22.oacModuleType):
        term=openaccess22.oaModTerm.static_find(self.mDesign,name)
      if (typname==openaccess22.oacOccurrenceType):
        term=openaccess22.oaOccTerm.static_find(self.mDesign,name)
      if (term==None): 
        if (name.getType().oaNameTypeEnum()==openaccess22.oacVectorBitNameType):
          sname=openaccess22.oaScalarName()
          vname=name.getVectorBit()
          vname.getBaseName(sname)
          if (typname==openaccess22.oacBlockType):
            term=openaccess22.oaBusTermBit.static_find(self.mDesign,sname,vname.getIndex())
          if (typname==openaccess22.oacModuleType):
            term=openaccess22.oaModBusTermBit.static_find(self.mDesign,sname,vname.getIndex())
          if (typname==openaccess22.oacOccurrenceType):
            term=openaccess22.oaOccBusTermBit.static_find(self.mDesign,sname,vname.getIndex())
        if (term==None):
          print "Can't Find Term: ",termname
          continue 
      termname=openaccess22.oaString()
      term.getName(self.mNS,termname)
      termname=str(termname)
      rep = "Term: "+termname+" ("
      termtype=term.getTermType().oaTermTypeEnum()
      if (termtype=='oacInputTermType'): rep=rep+"I"
      elif (termtype=='oacOutputTermType'): rep=rep+"O"
      elif (termtype=='oacInputOutputTermType'): rep=rep+"B"
      else: rep=rep+"X"
      rep=rep+")"
      if (self.mFirstObj==None): self.mFirstObj=term
      self.mReport.append(rep)
      net=term.getNet()
      netname=openaccess22.oaString()
      if (net.isOccObject()):
        net.getPathName(self.mNS,netname)
      else:
        net.getName(self.mNS,netname)
      netname=str(netname)
      rep="Net: "+netname
      self.mReport.append(rep)
      #self.trace_net(net,self.mDir,1)
      for snet in net.getSingleBitMembersIter():
        net=snet.getPreferredEquivalent()
        fo=self.trace_net_fo(net)

        repname=openaccess22.oaString()
        if (net.isOccObject()):
          net.getPathName(self.mNS,repname)
        else:
          net.getName(self.mNS,repname)
        rep = "Net: "+str(repname)+" { fanout="+str(fo)+" }"
        self.mReport.append(rep)
        if (self.mFirstObj==None): self.mFirstObj=net
        self.trace_net(net,self.mDir,1)
    self.log_report(cmd,names)

  #-------------------------------------------------------------------
  #  trace_topblock_list: 
  #
  def trace_topblock_list(self,cmd,names):
    data=self.validate(cmd,names)
    if (len(data)==3):
      ns=openaccess22.oaNativeNS()
      libName=openaccess22.oaScalarName(ns,data[0])
      cellName=openaccess22.oaScalarName(ns,data[1])
      viewName=openaccess22.oaScalarName(ns,data[2])
      design=openaccess22.oaDesign.static_open(libName,cellName,viewName,'r')
      if (design):
        self.mDesign=design.getTopBlock()
        if (self.mFirstObj==None): self.mFirstObj=self.mDesign

  #-------------------------------------------------------------------
  #  trace_topmodule_list: 
  #
  def trace_topmodule_list(self,cmd,names):
    data=self.validate(cmd,names)
    if (len(data)==3):
      ns=openaccess22.oaNativeNS()
      libName=openaccess22.oaScalarName(ns,data[0])
      cellName=openaccess22.oaScalarName(ns,data[1])
      viewName=openaccess22.oaScalarName(ns,data[2])
      design=openaccess22.oaDesign.static_open(libName,cellName,viewName,'r')
      if (design):
        self.mDesign=design.getTopModule()
        if (self.mFirstObj==None): self.mFirstObj=self.mDesign

  #-------------------------------------------------------------------
  #  trace_topocc_list: 
  #
  def trace_topocc_list(self,cmd,names):
    data=self.validate(cmd,names)
    if (len(data)==3):
      ns=openaccess22.oaNativeNS()
      libName=openaccess22.oaScalarName(ns,data[0])
      cellName=openaccess22.oaScalarName(ns,data[1])
      viewName=openaccess22.oaScalarName(ns,data[2])
      design=openaccess22.oaDesign.static_open(libName,cellName,viewName,'r')
      if (design):
        self.mDesign=design.getTopOccurrence()
        if (self.mFirstObj==None): self.mFirstObj=self.mDesign

  #-------------------------------------------------------------------
  #  trace_designmodule_list: 
  #
  def trace_designmodule_list(self,cmd,names):
    data=self.validate(cmd,names)
    if (len(data)==4):
      ns=openaccess22.oaNativeNS()
      libName=openaccess22.oaScalarName(ns,data[0])
      cellName=openaccess22.oaScalarName(ns,data[1])
      viewName=openaccess22.oaScalarName(ns,data[2])
      modName=openaccess22.oaScalarName(ns,data[3])
      design=openaccess22.oaDesign.static_open(libName,cellName,viewName,'r')
      if (design):
        module=openaccess22.oaModule.static_find(design,modName)
        if (module):
          self.mDesign=module
          if (self.mFirstObj==None): self.mFirstObj=self.mDesign

  #-------------------------------------------------------------------
  #  trace_module_list: 
  #
  def trace_module_list(self,cmd,names):
    data=self.validate(cmd,names)
    if (len(data)==1):
      ns=openaccess22.oaNativeNS()
      modName=openaccess22.oaScalarName(ns,data[0])
      module=openaccess22.oaModule.static_find(self.mDesign.getDesign(),modName)
      if (module):
        self.mDesign=module
        if (self.mFirstObj==None): self.mFirstObj=self.mDesign

  #-------------------------------------------------------------------
  #  trace_occ_list: 
  #
  def trace_occ_list(self,cmd,names):
    data=self.validate(cmd,names)
    if (len(data)==1):
      ns=openaccess22.oaNativeNS()
      name=openaccess22.oaSimpleName(ns,data[0])
      inst=openaccess22.oaOccInst.static_find(self.mDesign.getTopOccurrence(),name)
      if (inst):
        occ=inst.getMasterOccurrence()
        if (occ):
          self.mDesign=occ
          if (self.mFirstObj==None): self.mFirstObj=self.mDesign

  #-------------------------------------------------------------------
  #  process_cmd: generate a full trace/report for all the
  #  cmds in the input list.
  #
  def process_cmd(self,cmd,names):
    if (cmd=="term"): self.trace_term_list(cmd,names)
    elif (cmd=="net"): self.trace_net_list(cmd,names)
    elif (cmd=="instance"): self.trace_instance_list(cmd,names)
    elif (cmd=="topblock"): self.trace_topblock_list(cmd,names)
    elif (cmd=="topmodule"): self.trace_topmodule_list(cmd,names)
    elif (cmd=="topocc"): self.trace_topocc_list(cmd,names)
    elif (cmd=="designmodule"): self.trace_designmodule_list(cmd,names)
    elif (cmd=="module"): self.trace_module_list(cmd,names)
    elif (cmd=="occ"): self.trace_occ_list(cmd,names)
    elif (cmd=="depth"):
      try: 
        self.mMaxDepth = int(names)
        self.log_cmd(cmd,names)
      except:
        raise self.CommandError,("Bad Value on depth command: %s"%names)
    elif (cmd=="direction"):
      item=string.lower(names)
      if (item=="in"): self.mDir=0
      elif (item=="out"): self.mDir=1
      elif (item=="bi"): self.mDir=2
      else:
        raise self.CommandError,("Bad Value on direction command: %s"%item)
      self.log_cmd(cmd,names)
    elif (cmd=="file"):
      print "File: ",names
      self.log_cmd(cmd,names)
      return self.parse_file(names)
    else:
      raise self.CommandError,("Unknown command: %s"%cmd)

    return self.mReport

  #-------------------------------------------------------------------
  #  parse_line: Parse a single command line
  #
  def parse_line(self,line):
    args = string.split(re.sub("\n"," ",line),None,1)
    if (len(args)==0):
      return None
    cmd=string.lower(args[0])
    if (cmd=="#"): 
      return None

    if (len(args)!=2):
      raise self.CommandError,"Trace commands require 2 arguments"
    names=args[1]

    return self.process_cmd(cmd,names)

  #-------------------------------------------------------------------
  #  parse_file: Parse a command file
  #
  def parse_file(self,filename):
    report=[]
    try:
      fp=open(filename,"r")
      line=fp.readline()
    except:
      raise self.CommandError,("Error Openning file: %s"%filename)

    while (line):
      list=self.parse_line(line)
      if (list):
        for item in list:
          report.append(item)
      line=fp.readline()
    fp.close()

    return report

  #-------------------------------------------------------------------
  #  ParseFile: Parse a command file
  #
  def ParseFile(self,filename):
    return self.parse_file(filename)

  #-------------------------------------------------------------------
  #  ParseCommand: Parse a command 
  #
  def ParseCommand(self,command):
    return self.parse_line(command)

#-----------------------------------------------------
# History Lister
class cHistoryLister:
    help="""cHistoryLister:
Provides a display for all commands executed.
"""
    def __init__(self,tracer):
        self.mTracer=tracer
        self.mTop=None
        
    def Display(self):
        if (self.mTop!=None):
          self.mTop.Raise()
          return
        # -------------------------------------
        # Main Display
        # -------------------------------------
        self.mTop=cWinTop("History Lister",self.Detach)
        self.mCol=self.mTop.CreateColumn(1)

        row=self.mCol.CreateRow()
        cWinLabel(row,"List of all Visited Objects:")
        self.mOut=cWinScrollListbox(self.mCol,double_command=self.DisplayHistory,
                                    minsize=(400,200))

        row=self.mCol.CreateRow(0)
        cWinLabel(row,"Operations:")
        cWinButton(row,text="Close",command=self.Detach)
        cWinButton(row,text="Display",command=self.DisplayHistory)

        self.mTop.End()
        self.Update()

    # -----------------------------------------
    def Detach(self,*v):
        if (self.mTop==None): return
        self.mTop.Detach()
        self.mTop=None
        
    # -----------------------------------------
    def DisplayHistory(self,*v):
        index=self.mOut.curselection()
        if (index<0): return
        item=self.mNames[index]
        self.mTracer.ExecCommand(item,1)

    # -----------------------------------------
    def Update(self):
        if (self.mTop==None): return
        self.mOut.Clear()
        self.mNames=self.mTracer.mHistory
        lst=[]
        for item in self.mNames:
            lst.append(item)
        self.mOut.insert(lst)

#---------------------------------------------------------------
# Main Window of Tracer is written as a class
#  Implements a GUI around the cTraceSingle Class.
#
class cTraceSingleGui:
  #######################################
  # ExecCommand
  #######################################
  def ExecCommand(self,cmd,post):
    filename="oaTracerCmd.log"
    if (filename):
      try:
        fp=open(filename,'a')
        fp.write(cmd)
        fp.write('\n')
        fp.close()
      except:
        pass

    self.mHistory.append(cmd)
    self.mHistoryForm.Update()
    if (post):
      try:
        Tracer=cTraceSingle(self.mDesign,self.first_cmd)
        self.first_cmd=None
        md_cmd = "depth %d"%(self.mDepth.get()*2)
        Tracer.ParseCommand(md_cmd)
        md_cmd = "direction "+self.mDirection.value()
        Tracer.ParseCommand(md_cmd)
        report=Tracer.ParseCommand(cmd)
        design=Tracer.mDesign
        
      except cTraceSingle.CommandError,value:
        print "** Error",value
        #pddesign.Alert(value)
        return

      self.mOut.clear()
      if (report):
        self.mOut.insert(report)
      else:
        self.mOut.insert([])
        
      self.UpdateCellview(design)
      self.mBrowser.mRootObj=Tracer.mFirstObj

  #######################################
  # ExecCommands
  #######################################
  def ExecCommands(self,cmds):
    filename="oaTracerCmd.log"
    if (filename):
      try:
        fp=open(filename,'a')
        for cmd in cmds:
          fp.write(cmd)
        fp.write('\n')
        fp.close()
      except:
        pass

    try:
      Tracer=cTraceSingle(self.mDesign,self.first_cmd)
      self.first_cmd=None
      md_cmd = "depth %d"%(self.mDepth.get()*2)
      Tracer.ParseCommand(md_cmd)
      md_cmd = "direction "+self.mDirection.value()
      Tracer.ParseCommand(md_cmd)
      report=[]
      for cmd in cmds:
        self.mHistory.append(cmd)
        #print cmd
        result=Tracer.ParseCommand(cmd)
        #print result
        for item in result:
          report.append(item)
        design=Tracer.mDesign

    except cTraceSingle.CommandError,value:
      print "** Error",value
      #pddesign.Alert(value)
      return

    self.mHistoryForm.Update()
    self.mOut.clear()
    if (report):
      self.mOut.insert(report)
    else:
      self.mOut.insert([])

    self.UpdateCellview(design)
    self.mBrowser.mRootObj=Tracer.mFirstObj

  #######################################
  # UpdateCellview
  #######################################
  def UpdateCellview(self,design):
    if (design==self.mDesign): return
    if (self.mCloseFun):
      apply(self.mCloseFun,())
      self.mCloseFun=None
    self.mDesign=design
    self.mNetUtil.UpdateCellview(design)
    self.mTermUtil.UpdateCellview(design)
    self.mInstUtil.UpdateCellview(design)
    s=oaTracerUtl22.getDesObjectRepr(self.mDesign)
    self.mLabel.set(s)
    #self.mCloseFun=self.mDesign.getDesign().close

  #######################################
  # DepthButton
  #######################################
  def DepthButton(self,*v):
    cmd = "depth %d"%(self.mDepth.get()*2)
    self.ExecCommand(cmd,None)

  #######################################
  # DirectionButton
  #######################################
  def DirectionButton(self,*v):
    cmd = "direction "+self.mDirection.value()
    self.ExecCommand(cmd,None)

  #######################################
  # InstanceButton
  #######################################
  def InstButton(self,*v):
    self.mInstUtil.Display()
    
  def PickInst(self):
    list=self.mInstUtil.ObjectNames()
    if (list):
      cmd = "instance "+list
      self.ExecCommand(cmd,1)

  #######################################
  # NetButton
  #######################################
  def NetButton(self,*v):
    self.mNetUtil.Display()
    
  def PickNet(self):
    list=self.mNetUtil.ObjectNames()
    if (list):
      cmd = "net "+list
      self.ExecCommand(cmd,1)

  #######################################
  # TermButton
  #######################################
  def TermButton(self,*v):
    self.mTermUtil.Display()
    
  def PickTerm(self):
    list=self.mTermUtil.ObjectNames()
    if (list):
      cmd = "term "+list
      self.ExecCommand(cmd,1)

  #######################################
  # CvButton
  #######################################
  def CvButton(self,*v):
    self.mCvUtil.Display()
    
  def PickCv(self):
    list=self.mCvUtil.SelectedValue()
    if (list):
      if (list[3]==' -Design-'):
        pass
      if (list[3]==' -TopBlock-'):
        cmd = "topblock "+string.join(list[0:3],' ')
        self.ExecCommand(cmd,1)
      elif (list[3]==' -TopModule-'):
        cmd = "topmodule "+string.join(list[0:3],' ')
        self.ExecCommand(cmd,1)
      elif (list[3]==' -TopOccurrence-'):
        cmd = "topocc "+string.join(list[0:3],' ')
        self.ExecCommand(cmd,1)
      else:
        cmd = "designmodule "+string.join(list,' ')
        self.ExecCommand(cmd,1)

  #######################################
  # Fetch Command
  #######################################
  def FetchCommand(self,index=None):
    line=self.mOut.value(index)
    data=re.sub(r"\s(\{.*\})|(\(.*\))","",line)
    data=re.sub(r"^\s*Inst:","instance",data)
    data=re.sub(r"^\s*Net:","net",data)
    data=re.sub(r"^\s*EqNet:","net",data)
    data=re.sub(r"^\s*MemNet:","net",data)
    data=re.sub(r"^\s*Term:","term",data)
    data=re.sub(r"^\s*Cell:","topmodule",data)
    data=re.sub(r"^\s*Mod:","module",data)
    data=re.sub(r"^\s*Occ:","occ",data)
    return data

  #######################################
  # MenuPickButton
  #######################################
  def MenuPickButton(self,*v):
    data=self.FetchCommand()
    self.ExecCommand(data,1)

  #######################################
  # EvaluateButton
  #######################################
  def EvaluateButton(self,*v):
    cmd=self.mCommand.get()
    self.ExecCommand(cmd,1)

  #######################################
  # FileButton
  #######################################
  def FileButton(self,*v):
    cmd="file "+self.mFile.get()
    self.ExecCommand(cmd,1)

  #######################################
  # HistoryButton
  #######################################
  def HistoryButton(self,*v):
      self.mHistoryForm.Display()

  def ReportButton(self,*v):
    self.mTop.Report()

  #######################################
  # Browser
  #######################################
  def Browser(self,*v):
    self.mBrowser.Display(postroot=1)

  #######################################
  # Detach
  #######################################
  def Detach(self,*v):
    if (self.mTop==None): return

    self.mHistoryForm.Detach()    
    self.mNetUtil.Detach()
    self.mTermUtil.Detach()
    self.mInstUtil.Detach()
    self.mBrowser.Detach()
    self.mCvUtil.Detach()
    self.mTop.Detach()
    self.mTop=None
    if (self.mCloseFun):
      print "Close Root Object"
      apply(self.mCloseFun,())
      self.mCloseFun=None

  #######################################
  # Init
  #######################################
  def __init__(self,design,closefun,close=0):
    self.Ok=None
    self.Apply=None
    self.mDesign=design
    self.mHistoryForm=None
    if (self.mDesign.isBlockObject()):
      self.mHistory=['topblock %s'%oaTracerUtl22.getCellviewFullname(self.mDesign)]
    if (self.mDesign.isModObject()):
      if (self.mDesign==self.mDesign.getTopModule()):
        self.mHistory=['topmod %s'%oaTracerUtl22.getCellviewFullname(self.mDesign)]
      else:
        self.mHistory=['designmodule %s %s'%oaTracerUtl22.getModuleFullname(self.mDesign)]
    if (self.mDesign.isOccObject()):
      self.mHistory=['topocc %s'%oaTracerUtl22.getCellviewFullname(self.mDesign)]
    self.mTop=None
    self.mCloseFun=closefun
    self.mClose=close

    self.mNetUtil=oaTracerNetutl22.cTracerNetUtility(self.mDesign,self.PickNet)
    self.mTermUtil=oaTracerTermutl22.cTracerTermUtility(self.mDesign,self.PickTerm)
    self.mInstUtil=oaTracerInstutl22.cTracerInstUtility(self.mDesign,self.PickInst)
    self.mBrowser=Browser.cBrowser(self.mDesign,BrowserOA22.cOpenAccessBrowserHints(),1)
    self.mCvUtil=oaTracerCvutl22.cTracerDesignUtility('Pick Library Cell View',self.PickCv)
    self.mHistoryForm=cHistoryLister(self)

#   Empty cmd.log file
    self.first_cmd=1
    filename="oaTracerCmd.log"
    if (filename):
      try:
        fp=open(filename,"w")
        fp.close()
      except:
        pass

  #######################################
  # CreateOtherButtons
  #######################################
  def CreateOtherButtons(self):
    pass
    
  #######################################
  # Display
  #######################################
  def Display(self):
    if (self.mTop!=None):
      self.mTop.Raise()
      return

    self.mTop=cWinTop("oaTracer",self.Detach)
    self.mCol=self.mTop.CreateColumn(1)

    row=self.mCol.CreateRow()
    s=oaTracerUtl22.getDesObjectRepr(self.mDesign)
    self.mLabel=cWinLabel(row,s)
    row=self.mCol.CreateRow()
    cWinLabel(row,"Report Log:")

    self.mOut=cWinScrollListbox(self.mCol,size=(-1,200),minsize=(-1,200),
                                double_command=self.MenuPickButton)

    row=self.mCol.CreateRow()
    cWinLabel(row,"Pick Object:")
    cWinButton(row,text="Instance",command=self.InstButton)
    cWinButton(row,text="Term",command=self.TermButton)
    cWinButton(row,text="Net",command=self.NetButton)
    cWinButton(row,text="Cell",command=self.CvButton)
    cWinButton(row,text="Browser",command=self.Browser)
    
    self.CreateOtherButtons()
    
    self.mCommand=cWinRowEntryButton(self.mCol,"Command:","Eval",self.EvaluateButton)
    self.mFile=cWinRowEntryButton(self.mCol,"File:","Run",self.FileButton)

    self.mDirection=cWinRowChoiceButton(self.mCol,"Direction:",
                                        ["In","Out","Bi"],value=2,
                                        command=self.DirectionButton)
    self.mDepth=cWinRowChoiceButton(self.mCol,"Depth:",
                                    ["0","1","2","3","4","5","6","7","8","9"],
                                    command=self.DepthButton)

    row=self.mCol.CreateRow()
    if (self.mClose):
      cWinButton(row,text="Close",command=self.Detach)
    else:
      cWinButton(row,text="Exit",command=self.Detach)
    cWinButton(row,text="History",command=self.HistoryButton)
    #cWinButton(row,text="Report",command=self.ReportButton)

    self.mTop.End()

#-----------------------------------------------
class oaTracerApp(oaTracerCvutl22.oaDesignPickApp):
  #-----------------------------------------------
  def Help(self):
    print """\
  Usage: 
    oaTracer -topblock libName cellName viewName
    oaTracer -topmodule libName cellName viewName
    oaTracer -topocc libName cellName viewName
    oaTracer -module libName cellName viewName modName
    oaTracery -pick
  """

  #-----------------------------------------------
  def OpenGui(self):
    self.mGuiTracer=cTraceSingleGui(self.mDesign,self.mCloseFun)
    self.mGuiTracer.Display()

#---------------------------------------------------------------
def Run(*args):
  c=oaTracerApp()
  apply(c.Run,args)
  
#---------------------------------------------------------------
if (__name__=='__main__'):
  apply(Run,sys.argv[1:])
  
