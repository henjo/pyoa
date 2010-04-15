#
#********************************************************************
#* Copyright (C) 2004 LSI Logic Corporation.                        *
#*         All Rights Reserved.                                     *
#********************************************************************
#
# Sample Test program to try Observers

import openaccess22
from openaccess22 import *

import oaExUtl22
from oaExUtl22 import *

import sys

#-----------------------------------------------
class MyLibDefListObserver(oaObserver[oaLibDefList]):
    def onPreOpenLibs(self,deflist):
        print "        MyLibDefListObserver::onPreOpenLibs DefList:",deflist
        return oaBoolean(1)

    def onPostOpenLibs(self,deflist):
        print  "        MyLibDefListObserver::onPostOpenLibs DefList:",deflist

    def onLoadWarnings(self,deflist,msg,typ):
        print  "        MyLibDefListObserver::onLoadWarnings DefList:",deflist,'=',msg,'@',typ
        return oaBoolean(1)

#-----------------------------------------------
class MyLibObserver(oaObserver[oaLib]):
    def onPostCreate(self,lib):
        print "        MyLibObserver::onPostCreate Lib:",lib

    def onPostOpen(self,lib):
        print "        MyLibObserver::onPostOpen Lib:",lib

    def onPreClose(self,lib):
        print  "        MyLibObserver::onPreClose Lib:",lib

    def onPreModify(self,lib,modType):
        print  "        MyLibObserver::onPreModify Lib:",lib,'@',modType

    def onPostModify(self,lib,modType):
        print  "        MyLibObserver::onPostModify Lib:",lib,'@',modType

#-----------------------------------------------
class MyDesignObserver(oaObserver[oaDesign]):
    def onFirstOpen(self,design):
        print "        MyDesignObserver::onFirstOpen Design:",design

    def onPurge(self,design):
        print "        MyDesignObserver::onPurge Design:",design
        
    def onPreReopen(self,design,mode):
        print "        MyDesignObserver::onPreReopen Design:",design,"Mode:",mode

    def onPostReopen(self,design,mode):
        print "        MyDesignObserver::onPostReopen Design:",design,"Mode:",mode

    def onTruncate(self,design):
        print "        MyDesignObserver::onTruncate Design:",design

    def onPreSave(self,design):
        print "        MyDesignObserver::onPreSave Design:",design

    def onPostSave(self,design,succeeded):
        print "        MyDesignObserver::onPostSave Design:",design,\
              "Succeeded:",succeeded

    def onPreSaveAs(self,design,libname,cellname,viewname):
        print "        MyDesignObserver::onPreSaveAs Design:",design, \
              "Lib:",libname,"Cell:",cellname,"View:",viewname

    def onPostSaveAs(self,design,libname,cellname,viewname,succeeded):
        print "        MyDesignObserver::onPostSaveAs Design:",design, \
              "Lib:",libname,"Cell:",cellname,"View:",viewname, \
              "Succeeded:",succeeded

    def onPreModify(self,design,modType):
        print  "        MyDesignObserver::onPreModify Design:",design,'@',modType

    def onPostModify(self,design,modType):
        print  "        MyDesignObserver::onPostModify Design:",design,'@',modType

#-----------------------------------------------
class MyNetObserver(oaObserver[oaNet]):
    def onPostCreate(self,net):
        print  "        MyNetObserver::onPostCreate Net:",net

    def onPreDestroy(self,net):
        print  "        MyNetObserver::onPreDestroy Net:",net

    def onPreModify(self,net,modType):
        print  "        MyNetObserver::onPreModify Net:",net,'@',modType

    def onPostModify(self,net,modType):
        print  "        MyNetObserver::onPostModify Net:",net,'@',modType

#-----------------------------------------------
class MyTermObserver(oaObserver[oaTerm]):
    def onPostCreate(self,term):
        print  "        MyTermObserver::onPostCreate Term:",term

    def onPreDestroy(self,term):
        print  "        MyTermObserver::onPreDestroy Term:",term

    def onPreModify(self,term,modType):
        print  "        MyTermObserver::onPreModify Term:",term,'@',modType

    def onPostModify(self,term,modType):
        print  "        MyTermObserver::onPostModify Term:",term,'@',modType

#-----------------------------------------------
class MyPinObserver(oaObserver[oaPin]):
    def onPostCreate(self,pin):
        print  "        MyPinObserver::onPostCreate Pin:",pin

    def onPreDestroy(self,pin):
        print  "        MyPinObserver::onPreDestroy Pin:",pin

    def onPreModify(self,pin,modType):
        print  "        MyPinObserver::onPreModify Pin:",pin,'@',modType

    def onPostModify(self,pin,modType):
        print  "        MyPinObserver::onPostModify Pin:",pin,'@',modType

#-----------------------------------------------
class MyShapeObserver(oaObserver[oaShape]):
    def reportBBox(self,shape):
        bbox=oaBox()
        shape.getBBox(bbox)
        return "[[%d,%d],[%d,%d]]"%(bbox.left(),bbox.bottom(),bbox.right(),bbox.top())
        
    def onPostCreate(self,shape):
        print  "        MyShapeObserver::onPostCreate Shape:",shape,"@",self.reportBBox(shape)

    def onPreDestroy(self,shape):
        print  "        MyShapeObserver::onPreDestroy Shape:",shape,"@",self.reportBBox(shape)

    def onPreModify(self,shape,modType):
        print  "        MyShapeObserver::onPreModify Shape:",shape,"@",self.reportBBox(shape),'@',modType

    def onPostModify(self,shape,modType):
        print  "        MyShapeObserver::onPostModify Shape:",shape,"@",self.reportBBox(shape),'@',modType


#-----------------------------------------------
MyObservers=[]
def Setup():
    print "Setup Observers"
    global MyObservers
    print "  Create MyLibDefListObserver"
    MyObservers.append(MyLibDefListObserver(10))
    print "  Create MyLibObserver"
    MyObservers.append(MyLibObserver(10))
    print "  Create MyDesignObserver"
    MyObservers.append(MyDesignObserver(10))
    print "  Create MyNetObserver"
    MyObservers.append(MyNetObserver(10))
    print "  Create MyTermObserver"
    MyObservers.append(MyTermObserver(10))
    print "  Create MyPinObserver"
    MyObservers.append(MyPinObserver(10))
    print "  Create MyShapeObserver"
    MyObservers.append(MyShapeObserver(10))
    
#-----------------------------------------------
def Test():
    print "Open Lib List"
    ns=oaNativeNS()
    print "Create Library"
    libpath='testLib'
    libname='testLib'
    lib=CreateLibrary(libname,libpath)
    
    print "Open Design"
    sys.stdout.flush()
    design=CreateDesign(libname,'testCell','ObserverView')
    print "Create Block"
    block=oaBlock.static_create(design,1)
    
    print "Create Data"
    for i in range (5):
        name=oaScalarName(ns,"net_%d"%i)
        print "  Create net:",name
        net=oaScalarNet.static_create(block,name)
        print "    Create term:",name
        term=oaScalarTerm.static_create(net,name)
        box=oaBox(i*100,i*200,(i+1)*100,(i+1)*200)
        print "    Create shape:",box
        shape=oaRect.static_create(block,i,0,box)
        print "    Create pin:"
        pin=oaPin.static_create(term,"pin_%d"%i)
        print "    Add shape to pin:"
        shape.addToPin(pin)

    print "Modify Data"
    # Change Pin Shapes
    for pin in block.getPinsIter():
      for shape in pin.getFigsIter():
        box=oaBox()
        shape.getBBox(box)
        pinname=oaString()
        pin.getName(pinname)
        term=pin.getTerm()
        termname=oaString()
        term.getName(ns,termname)
        print "  Pin:",pinname,"on Term:",termname,"Shape:",box
        box.transform(oaPoint(50,50))
        print "    Change Shape"
        shape.setBBox(box)
        print "    Change Name"
        pinname=str(pinname)+'a'
        pin.setName(pinname)
        term=pin.getTerm()
        print "    Change TermType"
        term.setTermType(oaTermType(oacInputTermType))
        net=term.getNet()
        print "    Change NetType"
        net.setSigType(oaSigType(oacAnalogSigType))

    print "Save Design"
    design.save()

    if (1):    
      print "Delete Data"
      pin=block.getPinsIter().next()
      term=pin.getTerm()
      net=term.getNet()
      net.destroy()

      print "Revert Design"
      design.revert()
      block=design.getTopBlock()

      print "Delete Data"
      pin=block.getPinsIter().next()
      term=pin.getTerm()
      net=term.getNet()
      net.destroy()

      print "ReOpen Design"
      design.reopen('r')

      print "Delete Data"
      pin=block.getPinsIter().next()
      term=pin.getTerm()
      net=term.getNet()
      net.destroy()

    print "Close Design"
    design.close()
    
    print "Close Lib"
    lib.close()

    print "Done"
    sys.stdout.flush()

    
#-----------------------------------------------
def Init():
    oaWaferInit()

#-----------------------------------------------
if (__name__=='__main__'):
    Init()
    Setup()
    Test()


