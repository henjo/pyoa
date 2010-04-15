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

MyExt_Net_Index="18-277-7680__20020802__SampleNetExtension__Index"

#-----------------------------------------------
class cData:
    pass
Data=cData()

def Setup():
    global Data
    Data.mNetIndexExt=oaIntAppDef[oaNet].static_get(MyExt_Net_Index,-99)
    
#-----------------------------------------------
def TestBuild():
    global Data
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
        net=oaScalarNet.static_create(block,name)
        if (i<=3):
            Data.mNetIndexExt.set(net,data[i])
    design.save()
    
    TestRead(design)
    TestModify(design)
    TestRead(design)
    design.close()

#-----------------------------------------------
def TestModify(design):
    global Data
    print "Modify Data"
    block=design.getTopBlock()
    for net in block.getNetsIter():
        value=int(Data.mNetIndexExt.get(net))
        if (value>2):
           Data.mNetIndexExt.destroy(net)

#-----------------------------------------------
def TestRead(design):
    global Data
    print "Walk Data"
    block=design.getTopBlock()
    for net in block.getNetsIter():
        print "  Net:",net
        print "    Index:",Data.mNetIndexExt.get(net)

#-----------------------------------------------
def TestReRead():
    global Data
    print "ReRead"
    design=OpenDesign('testLib','testCell','extView','r')
    TestRead(design)
    Data.mNetIndexExt.remove(design)
    TestRead(design)
    design.close()
    
#-----------------------------------------------
def Init():
    oaWaferInit()
    Setup()

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
    
    
