#
#********************************************************************
#* Copyright (C) 2002-2003 LSI Logic Corporation.                   *
#*         All Rights Reserved.                                     *
#********************************************************************
#
# DESC: The standard Python DataBase Browser.
#
#  This is a generica data browser program.
#  It will let you walk the database and look at objects.
#  Each object is displayed with a form that shows the
#  members and their values, and a list of callable methods.
#
# This browser used the wxPython widgets.
#

import re
import types
import string
import traceback

import BrowserWx
from BrowserWx import *

#import BrowserTk
#from BrowserTk import *

#--------------------------------------------------------
gLastObject=None
gLastCallValue=None

#--------------------------------------------------------
# Make this portable
def TypeName(o):
    n=type(o).__name__
    if (n=='instance'):
        n='Instance of Class %s'%o.__class__.__name__
    return n

#-----------------------------------------------------
# Make a display string for an object
def DisplayStr(obj):
    if (type(obj)==types.ListType):
        s='[ ... ]'
    elif (type(obj)==types.TupleType):
        s='( ... )'
    elif (type(obj)==types.DictType):
        s='{ ... }'
    else:
        s=str(obj)
        s=string.replace(s,'\n','\\n')
        if (len(s)>100):
            s=s[0:99]+' ...'
    return s

#--------------------------------------------------------
class cException:
    def __init__(self,value):
        self.mValue=value

    def __str__(self):
        return "Exception: %s"%self.mValue

#-----------------------------------------------------
#  Class to build a Browser Form for a given object type
#
class cBrowserForm:
    help="""BrowserForm:
  The Browser form is a generic form for inspecting the
values of a given object type. The top pannel lists all
the member attributes and their values. Lists are reported
as [ ... ].  The lower panel reports the names of all the
methods available for the object.

Operations buttons:
  Close - close this form.
  Visit - Visit/Inspect the selected member object.
  Call  - Call a member function.
"""
    # -----------------------------------------
    #  Build the form
    # -----------------------------------------
    def __init__(self,obj,browser):
        self.mBrowser=browser
        self.mObj=obj
        self.mStrObj=DisplayStr(obj)

        #----------------------------------------
        # Fetch Data
        #----------------------------------------
        self.mBrowser.Print("Display: %s"%self.mStrObj)
        self.mMethods=[]
        self.mExtraMethods=[]
        self.mAttrNames=[]
        ##self.mAttrValues=[]
        self.mAttrDisplays=[]
        ##self.mAttrCalled=[]
        dr=dir(obj)
        typ=type(obj)
        #print "Type(obj):",typ.__name__
        #print "Dir(obj):",dr
        for key in dr:
            #print "  Key:",key
            if (self.mBrowser.mHints and
                not self.mBrowser.mHints.ShouldGetMember(typ,key)): continue
            if (not self.mBrowser.mShowHidden and key[0:2]=='__' and key[-2:]=='__'): continue
            ok=0
            try:
                value=getattr(obj,key)
                ok=1
            except:
                value=cException(sys.exc_info()[1])
            called=None
            if (ok and callable(value)):
                #print "    Callable"
                self.mMethods.append(key)
                if (self.mBrowser.mHints):
                    data=self.mBrowser.mHints.ShouldCallMember(typ,key,value)
                    #print "    ShouldCall(%s) %s"%(key,data)
                    if (data!=None):
                        usevalue,args,sargs=data
                        called=key+sargs
                        try:
                            result=apply(value,args)
                            value=list(args)
                            if (usevalue):
                                value.insert(0,result)
                            if (len(value)==1): value=value[0]
                            elif (len(value)==0): value=None
                        except:
                            value=cException(sys.exc_info()[1])
                if (called==None):
                    continue
            else:
                if (self.mBrowser.mHints and
                    not self.mBrowser.mHints.ShouldShowValue(typ,key,value)): continue
            #print "    Value:",value
            self.mAttrNames.append(key)
            ##self.mAttrValues.append(value)
            ##self.mAttrCalled.append(called)
            if (called!=None):
                 self.mAttrDisplays.append("%s: %s"%(called,DisplayStr(value)))
            else:
                 self.mAttrDisplays.append("%s: %s"%(key,DisplayStr(value)))

        if (self.mBrowser.mHints):
            self.mExtraMethods=self.mBrowser.mHints.ExtraMethods(typ)

        #----------------------------------------
        # See if object is iterator
        #----------------------------------------
        try:
            self.mIterValues=[]
            self.mIterDisplays=[]
            for key,value in obj.items():
                self.mIterValues.append(value)
                s=DisplayStr(key)+' -> '+DisplayStr(value)
                self.mIterDisplays.append(s)
            #print "Dict OK"
        except:
            #traceback.print_exc()
            self.mIterValues=[]
            self.mIterDisplays=[]
            try:
                for item in obj:
                    self.mIterValues.append(item)
                    self.mIterDisplays.append(DisplayStr(item))
                #print "Sequence OK"
            except:
                #traceback.print_exc()
                pass
            # Patch List Displays for Gtk issues
            if (IsNt==0):
                if (len(self.mIterValues)>2000):
                    values=self.mIterValues
                    displays=self.mIterDisplays
                    self.mIterValues=[]
                    self.mIterDisplays=[]
                    i=0
                    while (len(values)>0):
                        curset=values[0:1000]
                        self.mIterValues.append(curset)
                        values=values[1000:]
                        self.mIterDisplays.append('[%d ... %d]'%(
                            i,i+len(curset)-1))
                        i=i+1000

        #----------------------------------------
        # Build Form
        #----------------------------------------
        self.mTop=cWinTop("Obj: %s"%self.mStrObj,self.Detach)
        self.mCol=self.mTop.CreateColumn(1)

        #----------------------------------------
        # Heading
        #----------------------------------------
        row=self.mCol.CreateRow()
        cWinLabel(row,"Object: %s"%self.mStrObj)
        row=self.mCol.CreateRow()
        cWinLabel(row,"Type: %s"%TypeName(self.mObj))
        row=self.mCol.CreateRow()
        cWinButton(row,"Doc",self.Doc)
        
        #----------------------------------------
        # Slider Sections
        #----------------------------------------
#        print "Iter:",self.mIterDisplays
#        print "Methods:",self.mMethods
#        print "Attr:",self.mAttrDisplays

        if (self.mIterDisplays):
            if ((self.mMethods  or self.mExtraMethods) and self.mAttrDisplays):
                self.mSplitter=cWinHorizontalSplitter3(self.mCol)
                ad_frame,it_frame,md_frame=self.mSplitter.mPanels
            elif (self.mAttrDisplays):
                self.mSplitter=cWinHorizontalSplitter(self.mCol)
                ad_frame,it_frame=self.mSplitter.mPanels
            elif (self.mMethods or self.mExtraMethods):
                self.mSplitter=cWinHorizontalSplitter(self.mCol)
                it_frame,md_frame=self.mSplitter.mPanels
            else:
                it_frame=cWinColumn(self.mCol,border=1,grow=1)
        else:
            if ((self.mMethods  or self.mExtraMethods) and self.mAttrDisplays):
                self.mSplitter=cWinHorizontalSplitter(self.mCol)
                ad_frame,md_frame=self.mSplitter.mPanels
            elif (self.mAttrDisplays):
                ad_frame=cWinColumn(self.mCol,border=1,grow=1)
            elif (self.mMethods or self.mExtraMethods):
                md_frame=cWinColumn(self.mCol,border=1,grow=1)
                
        #----------------------------------------
        # Attrs Section
        #----------------------------------------
        if (self.mAttrDisplays):
            cWinRowLabelButton(ad_frame,"Attrs: %d"%(len(self.mAttrDisplays)),
                               "Visit",self.VisitAttr)
            row=ad_frame.CreateRow(1)
            self.mOutAttr=cWinScrollListbox(row,double_command=self.VisitAttr,
                                            minsize=(400,150))
            self.mOutAttr.insert(self.mAttrDisplays)

        #----------------------------------------
        # Iter Section
        #----------------------------------------
        if (self.mIterDisplays):
            cWinRowLabelButton(it_frame,"Iter Values: %d"%(len(self.mIterDisplays)),
                               "Visit",self.VisitIter)
            row=it_frame.CreateRow(1)
            self.mOutIter=cWinScrollListbox(row,double_command=self.VisitIter,
                                            minsize=(400,150))
            self.mSearchData=cWinRowEntry(it_frame,text="Search String (RE):")
            row=it_frame.CreateRow(0)
            cWinButton(row,text="Search (Start)",command=self.SearchStart)
            cWinButton(row,text="Search (Next)",command=self.SearchNext)

            self.mOutIter.insert(self.mIterDisplays)
                
        #----------------------------------------
        # Methods Section
        #----------------------------------------
        if (self.mMethods or self.mExtraMethods):
            row=cWinRow(md_frame)
            cWinLabel(row,"Methods: %d"%(len(self.mMethods)+len(self.mExtraMethods)),
                      grow=1)
            cWinButton(row,"Doc",self.DocMethod)
            cWinButton(row,"Visit",self.VisitMethod)
            row=md_frame.CreateRow(1)
            self.mOutMethod=cWinScrollListbox(row,minsize=(400,150))
            self.mExprMethod=cWinRowEntryButton(md_frame,"Parameters:","Call",self.Call)

            self.mOutMethod.insert(self.mMethods)
                
            lst=[]
            for item in self.mExtraMethods:
                lst.append(item.mName)
            self.mOutMethod.insert(lst)
                
        #----------------------------------------
        # Buttons
        #----------------------------------------
        row=self.mCol.CreateRow(0)
        cWinButton(row,text="Close",command=self.Detach)

        self.mTop.End()
         
    # -----------------------------------------
    # Request doc a method
    # -----------------------------------------
    def Doc(self,*v):
        self.mBrowser.DisplayDoc(self.mObj)

    # -----------------------------------------
    #  Search for the match
    # -----------------------------------------
    def Search(self,start):
        pat=re.compile(self.mSearchData.get())
        if (start):
            index=0
        else:
            index=self.mOutIter.curselection()
            if (index<0): index=0
        for item in self.mIterDisplays[index:]:
            if (pat.search(item)>0):
                self.mOutIter.selection_set(index)
                return
            index+=1
        self.mBrowser.Print("** String Search Failed")

    # -----------------------------------------
    # SearchStart
    # -----------------------------------------
    def SearchStart(self,*v):
        self.Search(1)

    # -----------------------------------------
    # SearchNext
    # -----------------------------------------
    def SearchNext(self,*v):
        self.Search(0)

    # -----------------------------------------
    # Clear Data on close
    # -----------------------------------------
    def Detach(self,*v):
        self.mBrowser.Remove(self)
        self.mTop.Detach()

    # -----------------------------------------
    # Request visiting an object
    # -----------------------------------------
    def VisitAttr(self,*v):
        index=self.mOutAttr.curselection()
        if (index<0): 
            self.mBrowser.Print("No Selection")
            return

        # Refetch value, so iterators are fresh
        key=self.mAttrNames[index]
        ok=0
        try:
            value=getattr(self.mObj,key)
            ok=1
        except:
            value=cException(sys.exc_info()[1])
        called=None
        if (ok and callable(value)):
            #print "    Callable"
            if (self.mBrowser.mHints):
                typ=type(self.mObj)
                data=self.mBrowser.mHints.ShouldCallMember(typ,key,value)
                #print "    ShouldCall(%s) %s"%(key,data)
                if (data!=None):
                    usevalue,args,sargs=data
                    called=key+sargs
                    try:
                        result=apply(value,args)
                        value=list(args)
                        if (usevalue):
                            value.insert(0,result)
                        if (len(value)==1): value=value[0]
                        elif (len(value)==0): value=None
                    except:
                        value=cException(sys.exc_info()[1])
            if (called==None):
                return
        else:
            typ=type(value)
            if (self.mBrowser.mHints and
                not self.mBrowser.mHints.ShouldShowValue(typ,key,value)): return

        self.mBrowser.DisplayObj(value)

        #key=self.mAttrNames[index]
        #try:
        #    obj=getattr(self.mObj,key)  # Refetch, to get new iterators.
        #    if (self.mAttrCalled[index]):
        #        try:
        #            obj=obj()
        #        except:
        #            pass
        #except:
        #    obj=cException(sys.exc_info()[1])
        ##obj=self.mAttrValues[index]
#        print "Visit: ",obj
        ##self.mBrowser.DisplayObj(obj)

    # -----------------------------------------
    # Request doc a method
    # -----------------------------------------
    def DocMethod(self,*v):
        index=self.mOutMethod.curselection()
        if (index<0):
            self.mBrowser.Print("No Selection")
            return
        ml=len(self.mMethods)
        if (index<ml):
            name=self.mMethods[index]
            try:
                obj=getattr(self.mObj,name)  # Refetch, to get new iterators.
            except:
                obj=cException(sys.exc_info()[1])
        else:
            data=self.mExtraMethods[index-ml]
            name=data.mName
            obj=data.mFun
#        print "Visit: ",obj
        self.mBrowser.DisplayDoc(obj)

    # -----------------------------------------
    # Request visiting a method
    # -----------------------------------------
    def VisitMethod(self,*v):
        index=self.mOutMethod.curselection()
        if (index<0):
            self.mBrowser.Print("No Selection")
            return
        ml=len(self.mMethods)
        if (index<ml):
            name=self.mMethods[index]
            try:
                obj=getattr(self.mObj,name)  # Refetch, to get new iterators.
            except:
                obj=cException(sys.exc_info()[1])
        else:
            data=self.mExtraMethods[index-ml]
            name=data.mName
            obj=data.mFun
#        print "Visit: ",obj
        self.mBrowser.DisplayObj(obj)

    # -----------------------------------------
    # Request visiting an object
    # -----------------------------------------
    def VisitIter(self,*v):
        index=self.mOutIter.curselection()
        if (index<0): 
            self.mBrowser.Print("No Selection")
            return
        obj=self.mIterValues[index]
#        print "Visit: ",obj
        self.mBrowser.DisplayObj(obj)

    # -----------------------------------------
    # Call a method
    # -----------------------------------------
    def Call(self,*v):
        global gLastCallValue
        index=self.mOutMethod.curselection()
        if (index<0):
            self.mBrowser.Print("No Selection")
            return
        try:
            args=self.mExprMethod.get()
            if (args==""): ex=()
            else:
              ex=eval(args,globals())
              if (type(ex)!=types.TupleType):
                self.mBrowser.Print("** Error: Parameter Expression must be a tuple")
        except:
            self.mBrowser.Print("** Error In Parameter Expression")
            traceback.print_exc()
            return
        ml=len(self.mMethods)
        if (index<ml):
            name=self.mMethods[index]
            m=getattr(self.mObj,name)
        else:
            data=self.mExtraMethods[index-ml]
            name=data.mName
            m=data.mFun
            args=[self.mObj]
            for item in ex:
                args.append(args)
            ex=tuple(args)
        self.mBrowser.Print("Calling: %s %s"%(name,ex))
        try:
            try:
                gLastCallValue=apply(m,ex)
                self.mBrowser.Print("CallValue: %s"%(gLastCallValue))
                if (gLastCallValue!=None):
                    self.mBrowser.DisplayObj(gLastCallValue,
                       'Return Value for Object: '+DisplayStr(self.mObj)+' ::'+DisplayStr(ex))
            except TypeError,value:
                self.mBrowser.Print("** TypeError Calling Method: %s"%DisplayStr(value))
                traceback.print_exc()
        except:
            self.mBrowser.Print("General Error Calling Method")
            traceback.print_exc()

#-----------------------------------------------------
# Object Lister
class cObjLister:
    help="""cObjectLister:
Provides a display for all the currently viewed objects.
"""
    def __init__(self,browser):
        self.mBrowser=browser
        
        # -------------------------------------
        # Main Display
        # -------------------------------------
        self.mTop=cWinTop("Object Lister",self.Detach)
        self.mCol=self.mTop.CreateColumn(1)

        row=self.mCol.CreateRow()
        cWinLabel(row,"List of all Open Objects:")
        self.mOut=cWinScrollListbox(self.mCol)

        row=self.mCol.CreateRow(0)
        cWinLabel(row,"Operations:")
        cWinButton(row,text="Close",command=self.Detach)
        cWinButton(row,text="Close-Obj",command=self.CloseObj)
        cWinButton(row,text="Raise-Obj",command=self.PopObj)

        self.mTop.End()
        self.Update()

    # -----------------------------------------
    def Detach(self,*v):
        self.mTop.Detach()
        self.mBrowser.mListForm=None
        
    # -----------------------------------------
    def CloseObj(self,*v):
        index=self.mOut.curselection()
        if (index<0): return
        key=self.mNames[index]
        form=self.mBrowser.mForms[key]
        form.Detach()

    # -----------------------------------------
    def PopObj(self,*v):
        index=self.mOut.curselection()
        if (index<0): return
        key=self.mNames[index]
        form=self.mBrowser.mForms[key]
        form.mTop.Raise()
        global gLastObject
        gLastObject=form.mObj

    # -----------------------------------------
    def Update(self):
        self.mOut.Clear()
        self.mNames=self.mBrowser.mForms.keys()
        lst=[]
        for item in self.mNames:
            form=self.mBrowser.mForms[item]
            lst.append(form.mStrObj)
        self.mOut.insert(lst)

        
#-----------------------------------------------------
# History Lister
class cHistoryLister:
    help="""cObjectLister:
Provides a display for all object visited.
"""
    def __init__(self,browser):
        self.mBrowser=browser
        
        # -------------------------------------
        # Main Display
        # -------------------------------------
        self.mTop=cWinTop("History Lister",self.Detach)
        self.mCol=self.mTop.CreateColumn(1)

        row=self.mCol.CreateRow()
        cWinLabel(row,"List of all Visited Objects:")
        self.mOut=cWinScrollListbox(self.mCol,double_command=self.DisplayObj,
                                    minsize=(400,200))

        row=self.mCol.CreateRow(0)
        cWinLabel(row,"Operations:")
        cWinButton(row,text="Close",command=self.Detach)
        cWinButton(row,text="Display",command=self.DisplayObj)

        self.mTop.End()
        self.Update()

    # -----------------------------------------
    def Detach(self,*v):
        self.mTop.Detach()
        self.mBrowser.mHistoryForm=None
        
    # -----------------------------------------
    def DisplayObj(self,*v):
        index=self.mOut.curselection()
        if (index<0): return
        item=self.mNames[index]
        self.mBrowser.DisplayObj(item[1])

    # -----------------------------------------
    def Update(self):
        self.mOut.Clear()
        self.mNames=self.mBrowser.mHistory
        lst=[]
        for item in self.mNames:
            lst.append(item[0])
        self.mOut.insert(lst)

#-----------------------------------------------------
# Object Doc
class cObjDoc:
    help="""cObjectDoc:
Provides a display for doc string on an object
"""
    def __init__(self,browser,obj,doc):
        self.mBrowser=browser
        self.mObj=obj
        self.mStrObj=DisplayStr(obj)
        self.mDoc=doc
        
        # -------------------------------------
        # Main Display
        # -------------------------------------
        self.mTop=cWinTop("Object Documentation",self.Detach)
        self.mCol=self.mTop.CreateColumn(1)

        row=self.mCol.CreateRow()
        cWinLabel(row,"Object: %s"%self.mStrObj)
        row=self.mCol.CreateRow()
        cWinLabel(row,"Type: %s"%TypeName(self.mObj))

        self.mOut=cWinScrollText(self.mCol,minsize=(500,200),hscroll=0)
        self.mOut.Print(self.mDoc)

        row=self.mCol.CreateRow(0)
        cWinButton(row,text="Close",command=self.Detach)

        self.mTop.End()

    # -----------------------------------------
    def Detach(self,*v):
        self.mTop.Detach()
        

#-----------------------------------------------------
#  Main Browser class
#
class cBrowser:
    help="""Browser:
  Browser is a simple program for walking/inspecting any
data in the OpenAccess database. For each object
it will list all the member attributes and their values.
If the object is a refernece to another object or list
of objects, you can Vist that object/list.
"""

    # -----------------------------------------
    # Dispaly/browse and object
    # -----------------------------------------
    def DisplayObj(self,obj,title='List:'):
        global gLastObject
        typ=type(obj)
        if (self.mHints and
            not self.mHints.ShouldShowType(typ)): return
        gLastObject=obj
        sobj=str(obj)
        self.mHistory.append([sobj,obj])
        if (self.mHistoryForm):
            self.mHistoryForm.Update()
        if (self.mForms.has_key(sobj)):
            form=self.mForms[sobj]
            form.mTop.Raise()
            self.mAge.remove(form) 
        else:
            form=cBrowserForm(obj,self)
            form.mFormId=sobj
            self.mForms[sobj]=form
            if (self.mListForm):
                self.mListForm.Update()
        self.mAge.append(form)
        self.CheckMaxOpen()

    
    # -----------------------------------------
    # Remove a form
    # -----------------------------------------
    def Remove(self,form):
        del self.mForms[form.mFormId]
        self.mAge.remove(form) 
        if (self.mListForm):
            self.mListForm.Update()

    # -----------------------------------------
    # Re-Diplay First Item
    # -----------------------------------------
    def DisplayDesign(self,*v):
        if (self.mRootObj):
            self.DisplayObj(self.mRootObj)
      
    # -----------------------------------------
    # Display Documentation
    # -----------------------------------------
    def DisplayDoc(self,obj):
        if (hasattr(obj,'__doc__')):
            doc=getattr(obj,'__doc__')
            if (doc!=None):
                form=cObjDoc(self,obj,doc)
        
    # -----------------------------------------
    # close form and all sub-forms
    # -----------------------------------------
    def Detach(self,*v):
#        self.Print("Close")
        while (self.mForms):
            win=self.mForms.values()[0]
            win.Detach()
        if (self.mListForm):
            self.mListForm.Detach()
        if (self.mHistoryForm):
            self.mHistoryForm.Detach()
        if (self.mTop):
            self.mTop.Detach()
        self.mTop=None
        global gLastObject
        gLastObject=None
        if (self.mCloseFun):
          print "Close Root Object"
          apply(self.mCloseFun,())
          self.mCloseFun=None
    
    # -----------------------------------------
    # close all sub-forms
    # -----------------------------------------
    def DetachAll(self,*v):
        while (self.mForms):
            win=self.mForms.values()[0]
            win.Detach()
        if (self.mHistoryForm):
            self.mHistoryForm.Detach()
        if (self.mListForm):
            self.mListForm.Detach()
        global gLastObject
        gLastObject=None
    
    # -----------------------------------------
    # Evaluate an expression
    # -----------------------------------------
    def Eval(self,*v):
        value=self.mExpr.get()
        self.Print("Eval: %s"%value)
        try:
            v=eval(value,globals())
        except:
            self.Print("** Error In Expression")
            traceback.print_exc()
            WinAlert("Error in Expression")
            return
        self.Print("Result: %s"%DisplayStr(v))
        self.DisplayObj(v,'Expression Result')

    # -----------------------------------------
    # Execute a statement
    # -----------------------------------------
    def Exec(self,*v):
        value=self.mStm.get()
        self.Print("Stm: %s"%value)
        try:
            exec value in globals()
        except:
            self.Print("** Error In Statement")
            traceback.print_exc()
            WinAlert("Error in Statement")
            return

    # -----------------------------------------
    # List
    # -----------------------------------------
    def List(self,*v):
        if (self.mListForm):
            self.mListForm.mTop.Raise()
        else:
            self.mListForm=cObjLister(self)

    # -----------------------------------------
    # History
    # -----------------------------------------
    def History(self,*v):
        if (self.mHistoryForm):
            self.mHistoryForm.mTop.Raise()
        else:
            self.mHistoryForm=cHistoryLister(self)

    # -----------------------------------------
    # Print
    # -----------------------------------------
    def Print(self,msg):
        print  msg
        self.mOut.Print(msg)
                       
    # -----------------------------------------
    # SetMo
    # -----------------------------------------
    def SetMo(self,*v):
        v=self.mMaxOpen.get()
        try:
            self.mMaxOpenWin=int(v)
        except:
            pass
        self.mMaxOpen.set(str(self.mMaxOpenWin))
        self.CheckMaxOpen()

    # -----------------------------------------
    # CheckMaxOpen
    # -----------------------------------------
    def CheckMaxOpen(self):
        while (len(self.mAge)>self.mMaxOpenWin):
            form=self.mAge[0]
            form.Detach()
                       
    # -----------------------------------------
    # Hidden
    # -----------------------------------------
    def Hidden(self,*v):
        self.mShowHidden=self.mHidden.get()
                       
    # -----------------------------------------
    # Init
    # -----------------------------------------
    def __init__(self,root=None,hints=None,close=0,closefun=None):
        self.mRootObj=root
        self.mForms = {}
        self.mHistory = []
        self.mListForm=None
        self.mHistoryForm=None
        self.mHints=hints
        self.mMaxOpenWin=6
        self.mAge=[]
        self.mShowHidden=0
        self.mClose=close
        self.mCloseFun=closefun
        self.mTop=None
          
    # -------------------------------------
    # Main Display
    # -------------------------------------
    def Display(self,postroot=0):
        if (self.mTop!=None):
            self.mTop.Raise()
            if (postroot and self.mRootObj):
              self.DisplayObj(self.mRootObj)
            return
            
        self.mTop=cWinTop("Browser",self.Detach)
        self.mCol=self.mTop.CreateColumn(1)

        row=self.mCol.CreateRow()
        cWinLabel(row,"Report Log:")
        self.mOut=cWinScrollText(self.mCol,minsize=(0,100))

        self.mExpr=cWinRowEntryButton(self.mCol,"Expression:","Eval",self.Eval)
        self.mStm=cWinRowEntryButton(self.mCol,"Statement:","Exec",self.Exec)
        self.mMaxOpen=cWinRowEntryButton(self.mCol,"Max Open Wins:","Set",self.SetMo)
        self.mMaxOpen.set(str(self.mMaxOpenWin))

        row=self.mCol.CreateRow()
        cWinLabel(row,"Settings:")
        self.mHidden=cWinCheckBox(row,text="Display Hidden Members",command=self.Hidden)
        self.mHidden.set(self.mShowHidden)

        row=self.mCol.CreateRow(0)
        cWinLabel(row,"Operations:")
        if (self.mClose):
          cWinButton(row,text="Close",command=self.Detach)
        else:
          cWinButton(row,text="Exit",command=self.Detach)
        cWinButton(row,text="Root-Obj",command=self.DisplayDesign)
        cWinButton(row,text="CloseAll",command=self.DetachAll)
        cWinButton(row,text="Lister",command=self.List)
        cWinButton(row,text="History",command=self.History)
        
        self.mTop.End()
        
        if (postroot and self.mRootObj):
            self.DisplayObj(self.mRootObj)

#-----------------------------------------------------
def App(init_fun):
    app=cWinApp()
    data=init_fun()
    app.main_loop()
    
#-----------------------------------------------------
def Test():
    dct={
        'String':'A String',
        'Int':1,
        'Float:':2.0,
        }
    lst=dct.values()
    print lst
    tpl=tuple(lst)
    data={
        'String':'A String',
        'Int':1,
        'Float:':2.0,
        'List':lst,
        'Tuple':tpl,
        'Dict':dct,
        }
    return data

#-----------------------------------------------------
if (__name__ == '__main__'):
    Test()
    app=cWinApp()
    data=Test()
    browser=cBrowser(data,None,0)
    browser.Display()
    app.main_loop()
    
