#
#********************************************************************
#* Copyright (C) 2005 LSI Logic Corporation.                        *
#*         All Rights Reserved.                                     *
#********************************************************************
#
# Sample Test program to try RegionQuery

import openaccess22
from openaccess22 import *

import oaExUtl22
from oaExUtl22 import *

#-----------------------------------------------
class myShapeQuery(oaShapeQuery):
    def queryShape(self,shape):
        print "queryShape:",shape

class myBlockageQuery(oaBlockageQuery):
    def queryBlockage(self,blockage):
        print "queryBlockage:",blockage

#-----------------------------------------------
def TestQuery():
    ns=oaNativeNS()
    print "Open Library"
    OpenLibrary("LIBNAME")
    print "Open Design"
    design=OpenDesign('LIBNAME','CELLNAME','VIEWNAME')
    topblock=design.getTopBlock()
    
    bbox=oaBox()
    topblock.getBBox(bbox)

    tech=design.getTech()
    for layer in tech.getLayersIter():
        lnum=layer.getNumber()
        for purpose in tech.getPurposesIter():
            pnum=purpose.getNumber()

            print "LP: ",lnum," ",pnum
            myinstquery=myShapeQuery()
            myinstquery.query(design,lnum,pnum,bbox)
    
        print "Layer: ",lnum
        myinstblockage=myBlockageQuery()
        myinstblockage.query(design,lnum,bbox)

    design.close()

#-----------------------------------------------
def Init():
    oaWaferInit()
    oaRegionQuery.static_init("oaRQSystem")

#-----------------------------------------------
if (__name__=='__main__'):
    Init()
    TestQuery()
    print "Done"
    
    
