#
#********************************************************************
#* Copyright (C) 2002 LSI Logic Corporation.                        *
#*         All Rights Reserved.                                     *
#********************************************************************
#
# DESC: Hints to customize Browser for OpenAccess
#
# This file provides hints that customize the browser for
# use with OpenAccess.
#

from openaccess22 import *

#--------------------------------------------------------
class cOpenAccessExtraMethod:
    def __init__(self,name,fun):
        self.mName=name
        self.mFun=fun
        
#--------------------------------------------------------
class cOpenAccessBrowserHints:
    def __init__(self):
        self.mSkipMethods={
            'oaLib':{
                'getControlledObjects':1,
            },
       }

        self.mSkipShow={
            }

        self.mExtraMethods={
            'oaCellView':[
                cOpenAccessExtraMethod('Br_open',self.oaView_Open)
                ]
            }

        self.mCallMethods={
        }
    #----------------------------------------------
    # Hint that tells if a given attribute should be skipped
    def ShouldGetMember(self,typ,member):
#        if (member[0:2]=='__' and member[-2:]=='__'):
#            if (member!='__class__'):
#                return 0
        type_name=typ.__name__
        data=self.mSkipMethods.get(type_name,{})
        skip=data.get(member,0)
        if (skip): return 0
        return 1
        
    #----------------------------------------------
    # Hint that tells if a given attribute should be called
    def ShouldCallMember(self,typ,member,fun):
        type_name=typ.__name__
        #data=self.mCallMethods.get(type_name,{})
        #call=data.get(member,0)
        #if (call): return 1
        st=None
        if (member[0:7]=='getNext'): st=None
        elif (member[0:3]=='get'): st=1
        elif (member[0:3]=='has'): st=1
        elif (member[0:2]=='is'): st=1
        elif (member[0:2]=='inGroup'): st==1
        if (st):
            #st=(1,(),"()")
            st=None
            if (hasattr(fun,'__doc__')):
                doc=getattr(fun,'__doc__').split('\n')
                for line in doc:
                   loc=line.find('BrowseData:')
                   if (loc<0): continue
                   data=line[loc+12:]
                   parts=data.split(',')
                   usevalue=int(parts[0])
                   args=[]
                   sargs="("
                   for part in parts[1:]:
                       if (sargs!="("): sargs+=","
                       sargs+=part
                       cmd='%s()'%part
                       #print "Eval:",cmd
                       try:
                           value=eval(cmd)
                       except:
                           return None
                       args.append(value)
                   sargs+=")"
                   return [usevalue,tuple(args),sargs]
        return st
        
    #----------------------------------------------
    # Hint that tells if a given attribute value should be skipped
    def ShouldShowValue(self,typ,member,value):
        return 1
    
    #----------------------------------------------
    # Hint that tells if a given type should be displayed
    def ShouldShowType(self,type):
        return 1
    
    #----------------------------------------------
    # Hint that given extra methods to call
    def ExtraMethods(self,type):
        return self.mExtraMethods.get(type.__name__,[])

    #----------------------------------------------
    # Routine to Open a gnView
    def oaView_Open(self,cellview):
        libName=oaScalarName()
        cellName=oaScalarName()
        viewName=oaScalarName()
        cellview.getLib().getName(libName)
        cellview.getCell().getName(cellName)
        cellview.getView().getName(viewName)
        design=oaDesign.static_open(libName,cellName,viewName,'r')
        return design
    
        
