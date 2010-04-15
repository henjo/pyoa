#
#********************************************************************
#* Copyright (C) 2002 LSI Logic Corporation.                        *
#*         All Rights Reserved.                                     *
#********************************************************************
#
# Sample Test program to try Extensions

import openaccess22
from openaccess22 import *

import oaExUtl22
from oaExUtl22 import *

import sys

#-----------------------------------------------
# Each extension requires a unique name in the database.
# The standard conventions is generate the name as follows:
#   DUN_number
#   Date the extension is first used by your code
#   SomeDescriptive name
#   Your membername

MyExt_Net_Index="18-277-7680__20020802__SampleNetClassExtension__Index"

#-----------------------------------------------
# This class is a wrapper for nets.
# Your create a myNet for an oaNet as:
#    net=... # an oaNet object
#    mnet=myNet(net)
# Then a myNet acts like a oaNet but with extra members
# that get/set the extension index field
#    mnet.getIndex()
#    mnet.setIndex(value)
#    mnet.destroyIndex()  # sets it to the default value
#
class myNet(oaNet):
    def initialize():
        global myNet_IndexExt
        print "Createing myNet_IndexExt"
        myNet_IndexExt=oaIntAppDef[oaNet].static_get(MyExt_Net_Index,-99)
    initialize=staticmethod(initialize)

    def unUseInDesign(design):
        global myNet_IndexExt
        myNet_IndexExt.remove(design)
    unUseInDesign=staticmethod(unUseInDesign)
        
    #---------------------------------------
    # self is the net in these routines
    def getIndex(self):
        global myNet_IndexExt
        return myNet_IndexExt.get(self)

    def setIndex(self,index):
        global myNet_IndexExt
        return myNet_IndexExt.set(self,index)

    def destroyIndex(self):
        global myNet_IndexExt
        return myNet_IndexExt.destroy(self)

#-----------------------------------------------
def TestBuild():
    ns=oaNativeNS()
    print "Create Design"
    design=CreateDesign('testLib','testCell','extView')
    print "Create Block"
    block=oaBlock.static_create(design,1)

    print "Create Data"
    data=[0,-1,-2,1000]
    for i in range (5):
        name=oaScalarName(ns,"net_%d"%i)
        print "  Create net:",name
        net=myNet(oaScalarNet.static_create(block,name))
        if (i<=3):
            net.setIndex(data[i])

    design.save()
    
    TestRead(design)
    TestModify(design)
    TestRead(design)
    design.close()

#-----------------------------------------------
def TestModify(design):
    print "Modify Data"
    block=design.getTopBlock()
    for net in block.getNetsIter():
        net=myNet(net)
        value=int(net.getIndex())
        if (value>2):
           net.destroyIndex()

#-----------------------------------------------
def TestRead(design):
    print "Walk Data"
    block=design.getTopBlock()
    for net in block.getNetsIter():
        net=myNet(net)
        print "  Net:",net
        print "    Index:",net.getIndex()

#-----------------------------------------------
def TestReRead():
    print "ReRead"
    design=OpenDesign('testLib','testCell','extView','r')
    TestRead(design)
    myNet.unUseInDesign(design)
    TestRead(design)
    design.close()
    
#-----------------------------------------------
def Init():
    oaWaferInit()
    myNet.initialize()

    print "Create Library"
    libpath='testLib'
    libname='testLib'
    lib=CreateLibrary(libname,libpath)

#-----------------------------------------------
if (__name__=='__main__'):
    Init()
    TestBuild()
    TestReRead()
    print "Done"
    
    
