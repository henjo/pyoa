#
#********************************************************************
#* Copyright (C) 2002-2003 LSI Logic Corporation.                   *
#*         All Rights Reserved.                                     *
#********************************************************************
#
# DESC: wxWindows Utilities for Browser
#
#  This provides the wxWindows based support routines.
#
#  Bugs:
#    Currently the size feature does not work, only minsize works.
#

import types
import string

import wxPython.wx
from wxPython.wx import *

kDefault_Space=4
kDefault_SliderMinSize=20
kDebug=0

IsNt=0
try:
  import nt
  IsNt=1
except:
  pass

#-----------------------------------------------------
defaultFonts=None
def SetDefaultFont(cls,font):
  global defaultFonts
  if (defaultFonts==None):
      size=12
      if IsNt: size=10
      defaultFonts={
        'cWinScrollListbox':wxFont(size,wxMODERN,wxNORMAL,wxNORMAL),
        'cWinScrollText':wxFont(size,wxMODERN,wxNORMAL,wxNORMAL),
      }
  if (font==None):
      name=cls.__class__.__name__
      font=defaultFonts.get(name,None)
  if (font!=None):
      cls.SetFont(font)
  
#-----------------------------------------------------
# Wrap a command so a busy cursor is displayed
class cWinBusyCommand:
    def __init__(self,command):
        self.mCommand=command
        
    def __call__(self,*args):
        wxBeginBusyCursor()
        try:
          apply(self.mCommand,args)
        except:
          wxEndBusyCursor()
          raise
        wxEndBusyCursor()
        
#-----------------------------------------------------
# Make a WindowRow
#   Negative space is between items, not first/last
class cWinRow:
    # -----------------------------------------
    # Initialize the Row/Column
    def __init__(self,parent,grow=0,space=kDefault_Space,
                 border=0,dr=wxHORIZONTAL,
                 parentwin=None):
        #border=1
        self.mParent=parent
        self.mSpace=space
        self.mDir=dr
        self.mX=0
        self.mY=0
        self.mMinX=0
        self.mMinY=0
        self.mLastWindow=None
        self.mLastWinWindow=None
        self.mLastAdd=None
        self.mBorder=border
        self.mIndent=''
        par=self.mParent
        while (par!=None):
          self.mIndent=self.mIndent+'  '
          par=par.mParent

        if (parentwin==None):
            parentwin=parent.mWindow
        if (border):
            self.mWindow=wxPanel(parentwin,-1,style=wxSIMPLE_BORDER)
            self.mX+=1
            self.mY+=2
            self.mMinX+=1
            self.mMinY+=2
        else:
            self.mWindow=wxPanel(parentwin,-1) #,style=wxSIMPLE_BORDER)
        self.mSizer=wxBoxSizer(dr)
        self.mSizerPos=0
        if (parent!=None):
            self.mParent.WinAdd(self,grow,wxEXPAND)
        if (kDebug):
            print self.mIndent,"Create:",self

        if (self.mSpace>0):
            self.AddSpace(self.mSpace,update=0)

    # -----------------------------------------
    # Update the X/Y size of a completed thing that was added
    def _UpdateSize(self,x,y,minx,miny):
        if (self.mDir==wxHORIZONTAL): # A Row
            self.mX+=x
            self.mMinX+=minx
            if (y>self.mY): self.mY=y
            if (miny>self.mMinY): self.mMinY=miny
        else:
            self.mY+=y
            self.mMinY+=miny
            if (x>self.mX): self.mX=x
            if (minx>self.mMinX): self.mMinX=minx
        if (kDebug):
            print self.mIndent," UpdateSize:",self,self.mMinX,self.mMinY,self.mX,self.mY

    # -----------------------------------------
    # The last added thing is complete, so check its size
    def _UpdateLast(self):
        if (self.mLastWinWindow!=None):  # was a row/column
            self.mLastWinWindow.End()
            sz=wxSize(self.mLastWinWindow.mX,self.mLastWinWindow.mY)
            #print self.mIndent,"  Win:",self.mLastWinWindow,sz,self.mLastWinWindow.mWindow.GetBestSize()
            #self.mLastWinWindow.mWindow.SetSize(sz)
            self._UpdateSize(self.mLastWinWindow.mX,self.mLastWinWindow.mY,
                             self.mLastWinWindow.mMinX,self.mLastWinWindow.mMinY)
            minsz=None
            self.mLastWinWindow=None
            self.mLastWindow=None
        elif (self.mLastWindow!=None):
            sz=self.mLastWindow.GetBestSize()
            minsz=self.mLastWindow.GetSize()
            if (kDebug):
                print self.mIndent," Update:",self.mLastWindow,\
                  self.mLastSize,self.mLastMinSize,minsz,sz
            if (self.mLastSize.GetWidth()>sz.GetWidth()):
              sz.SetWidth(self.mLastSize.GetWidth())
            if (self.mLastSize.GetHeight()>sz.GetHeight()):
              sz.SetHeight(self.mLastSize.GetHeight())
            if (self.mLastMinSize.GetWidth()>minsz.GetWidth()):
              minsz.SetWidth(self.mLastMinSize.GetWidth())
            if (self.mLastMinSize.GetHeight()>minsz.GetHeight()):
              minsz.SetHeight(self.mLastMinSize.GetHeight())
            if (kDebug):
                print self.mIndent," Update2:",self.mLastWindow,minsz,sz
            self.mLastWindow.SetSize(sz)
            self.mLastWindow.SetSizeHints(minsz.GetWidth(),minsz.GetHeight())
            self._UpdateSize(sz.GetWidth(),sz.GetHeight(),
                             minsz.GetWidth(),minsz.GetHeight())
            self.mLastWindow=None

        if (self.mLastAdd):
            if (self.mSpace<0 and self.mSizerPos>0): self.AddSpace(-self.mSpace,update=0)
            win,opt,flag=self.mLastAdd
            if (kDebug):
                print self.mIndent," LastAdd:",win
            self.mSizer.Add(win,opt,flag)
            if (minsz!=None):
                self.mSizer.SetItemMinSize(win,minsz.GetWidth(),minsz.GetHeight())
            self.mSizerPos+=1
            if (self.mSpace>0): self.AddSpace(self.mSpace,update=0)
            self.mLastAdd=None
 
    # -----------------------------------------
    # Add Blank Space
    def AddSpace(self,minspace,space=None,grow=0,update=1):
        if (update):
            self._UpdateLast()
        if (space==None): 
            space=minspace
        pos=self.mSizerPos
        if (self.mDir==wxHORIZONTAL): # A Row
            self.mSizer.Add(space,1,grow)
            self.mSizer.SetItemMinSize(self.mSizerPos,minspace,1)
            self.mX+=space
            self.mMinX+=minspace
        else:
            self.mSizer.Add(1,space,grow)
            self.mSizer.SetItemMinSize(self.mSizerPos,1,minspace)
            self.mY+=space
            self.mMinY+=minspace
        self.mSizerPos+=1
        if (kDebug):
            print self.mIndent," AddSpace:",self,self.mMinX,self.mMinY,self.mX,self.mY
        
    # -----------------------------------------
    # Add a row/column to us
    def WinAdd(self,win,opt=0,flag=0):
        self._UpdateLast()
        self.Add(win.mWindow,opt,flag)
        self.mLastWinWindow=win

    # -----------------------------------------
    # Add a wxWindow to us
    def Add(self,win,opt=0,flag=0,size=wxDefaultSize,minsize=wxDefaultSize):
        self._UpdateLast()
        self.mLastAdd=[win,opt,flag]
        if (kDebug):
            print self.mIndent," Add:",self.mLastAdd
        self.mLastWindow=win
        if (type(minsize)==types.TupleType):
          minsize=wxSize(minsize[0],minsize[1])
        self.mLastMinSize=minsize
        if (type(size)==types.TupleType):
          size=wxSize(size[0],size[1])
        self.mLastSize=size

    # -----------------------------------------
    # End this row/column
    def End(self):
        self._UpdateLast()
        #if (self.mSpace>0):
        #    self.AddSpace(self.mSpace,1)
        if (self.mBorder):
          self.mX+=1
          self.mY+=2
          self.mMinX+=1
          self.mMinY+=2
        self.mX=max(self.mX,1)
        self.mY=max(self.mY,1)
        self.mX=max(self.mX,self.mMinX)
        self.mY=max(self.mY,self.mMinY)
        if (kDebug):
            print self.mIndent,"End:",self,self.mMinX,self.mMinY,self,self.mX,self.mY
        #self.mWindow.SetDimensions(-1,-1,self.mX,self.mY,wxSIZE_AUTO)
        #self.mWindow.SetAutoLayout(1)
        self.mWindow.SetSizer(self.mSizer)
        self.mSizer.Fit(self.mWindow)
        #self.mWindow.SetDimensions(-1,-1,self.mX,self.mY,wxSIZE_AUTO)
        #self.mSizer.SetSizeHints(self.mWindow)
        # This prevents bugs in drawing
        #sz=self.mSizer.CalcMin()
        #self.mSizer.RecalcSizes()
        #print self.mIndent,"EndSize:",sz

    # -----------------------------------------
    # Helpers for making sub-row/cols
    def CreateRow(self,grow=0,space=kDefault_Space,border=0):
        return cWinRow(self,grow=grow,space=space,border=border)

    def CreateColumn(self,grow=0,space=kDefault_Space,border=0):
        return cWinColumn(self,grow=grow,space=space,border=border)

#-----------------------------------------------------
# Make a Window Column
class cWinColumn(cWinRow):
    def __init__(self,window,grow=0,space=1,border=0):
        cWinRow.__init__(self,window,grow=grow,space=space,
                         border=border,dr=wxVERTICAL)

#-----------------------------------------------------
# c_WinFrame
class c_WinFrame(wxFrame):
    def __init__(self,fun,dr,*arg,**kw):
        wxFrame.__init__(self,*arg,**kw)
        EVT_CLOSE(self,self.Detach)
        self.mFun=fun
        self.mDirection=dr
        self.mSizer=wxBoxSizer(self.mDirection)
        #self.SetSizer(self.mSizer)

    def Detach(self,*v):
        self.mFun()

    def End(self,row):
        self.mSizer.Add(row.mWindow,1,wxEXPAND)
        x=row.mX+8 
        y=row.mY+27
        #self.SetDimensions(-1,-1,x,y,wxSIZE_AUTO)
        # This prevents bugs in drawing
        #self.mSizer.RecalcSizes()
        #self.SetAutoLayout(1)
        self.SetSizer(self.mSizer)
        self.mSizer.Fit(self)
        self.mSizer.SetSizeHints(self)
        self.Show(1)
        
#-----------------------------------------------------
# Make a Top Window
class cWinTop(cWinRow):
    def __init__(self,title,clos,dr=wxHORIZONTAL):
        self.mFrame=c_WinFrame(clos,dr,None,-1,title,
                             style=wxDEFAULT_FRAME_STYLE)
        cWinRow.__init__(self,None,space=0,dr=dr,
                         parentwin=self.mFrame)

    def End(self):
        cWinRow.End(self)
        self.mFrame.End(self)
#        print "Top SetDimensions:",self.mX,self.mY
        #if (self.mCount>1):
        #    self.mWindow.SetSizer(self.mSizer)

    def Detach(self):
        self.mFrame.Destroy()

    def Raise(self):
        self.mFrame.Raise()
        
    def Report(self,win=None,indent=0):
        if (win==None): win=self.mFrame
        str=''
        for i in range(indent): str+=' '
        rect=win.GetRect()
        print '%s %s %d %d  %d %d  %d %d'%(str,win,
          rect.GetLeft(),rect.GetTop(),
          rect.GetRight(),rect.GetBottom(),
          rect.width,rect.height)
        children=win.GetChildren()
        for i in children:
          self.Report(i,indent+2)
        

#-----------------------------------------------------
# Make a Scrolling ListBox
class cWinScrollListbox(wxListBox):
    def __init__(self,col,command=None,double_command=None,
                 multiple=0,extended=0,font=None,
                 size=wxDefaultSize,minsize=wxDefaultSize):
        flags=wxLB_SINGLE|wxLB_HSCROLL|wxLB_ALWAYS_SB
        if (multiple):
          flags=flags|wxLB_MULTIPLE
        if (extended):
          flags=flags|wxLB_EXTENDED
        wxListBox.__init__(self,col.mWindow,-1,style=flags)
        col.Add(self,1,wxEXPAND,size=size,minsize=minsize)
        SetDefaultFont(self,font)
        if (command!=None):
            EVT_LISTBOX(col.mWindow,self.GetId(),cWinBusyCommand(command))
        if (double_command!=None):
            EVT_LISTBOX_DCLICK(col.mWindow,self.GetId(),cWinBusyCommand(double_command))

    def curselection(self):
        index=self.GetSelection()
        return index
        
    def curselections(self):
        return self.GetSelections()

    def selection_set(self,index,set=1):
        if (set):
            self.SetSelection(index)
        else:
            self.SetSelection(index,0)

    def clear(self):
        self.Clear()
        
    def insert(self,value):
        loc=self.Number()
        if (type(value)==types.ListType):
            self.InsertItems(value,loc)
        else:
            self.InsertItems([value],loc)

    def value(self,index=None):
        if (index==None):
          return self.GetStringSelection()
        else:
          return self.GetString(index)

    def values(self):
        l=[]
        for i in range(self.Number()):
            if (self.Selected(i)):
                l.append(self.GetString(i))
        return l

    def allvalues(self):
        l=[]
        for i in range(self.Number()):
            l.append(self.GetString(i))
        return l

    def select_all(self,set=1):
        for i in range(self.Number()):
            self.SetSelection(i,set)
            
    def remove_selected(self):
        l=[]
        for i in range(self.Number()):
            if (not self.Selected(i)):
                l.append(self.GetString(i))
        self.Clear()
        self.InsertItems(l,0)
         
    def remove_unselected(self):
        l=[]
        for i in range(self.Number()):
            if (self.Selected(i)):
                l.append(self.GetString(i))
        self.Clear()
        self.InsertItems(l,0)
    
#-----------------------------------------------------
# Make a Scrolling Test area
class cWinScrollText(wxTextCtrl):
    def __init__(self,col,size=wxDefaultSize,minsize=wxDefaultSize,
                 font=None,hscroll=1):
        style=wxTE_MULTILINE|wxTE_READONLY|wxSUNKEN_BORDER
        if (hscroll): style=style|wxHSCROLL
        wxTextCtrl.__init__(self,col.mWindow,-1,style=style)
        for i in range(10):
            for j in range(80):
                self.WriteText(" ")
            self.WriteText("\n")
        col.Add(self,1,wxEXPAND,size=size,minsize=minsize)
        SetDefaultFont(self,font)
        self.mFirst=1

    def Print(self,text):
        if (self.mFirst):
            self.Clear()
            self.mFirst=0
        self.SetInsertionPointEnd()
        self.WriteText(text+'\n')
        
    def Write(self,text):
        if (self.mFirst):
            self.Clear()
            self.mFirst=0
        self.SetInsertionPointEnd()
        self.WriteText(text)
       

#-----------------------------------------------------
# Make a Button
class cWinButton(wxButton):
    def __init__(self,row,text,command,grow=0,width=-1,minwidth=-1,
                 font=None,align=None):
        wxButton.__init__(self,row.mWindow,-1,text,wxDefaultPosition)
        malign=0
        row.Add(self,grow,wxALIGN_BOTTOM,
                size=(width,-1),minsize=(minwidth,-1))
        EVT_BUTTON(row.mWindow,self.GetId(),cWinBusyCommand(command))
        SetDefaultFont(self,font)
        
    def set(self,v):
        self.SetLabel(v)

#-----------------------------------------------------
# Make a CheckBox
class cWinCheckBox(wxCheckBox):
    def __init__(self,row,text,command=None,grow=0,width=-1,minwidth=-1,font=None):
        wxCheckBox.__init__(self,row.mWindow,-1,text)
        row.Add(self,grow,wxALIGN_BOTTOM,
                size=(width,-1),minsize=(minwidth,-1))
        if (command):
            EVT_CHECKBOX(row.mWindow,self.GetId(),cWinBusyCommand(command))
        SetDefaultFont(self,font)

    def get(self):
        return self.GetValue()
    
    def set(self,v):
        self.SetValue(v)
    
#-----------------------------------------------------
# Make a Choice
class cWinChoice(wxChoice):
    def __init__(self,row,values,command=None,grow=0,width=-1,minwidth=-1,value=0,font=None):
        wxChoice.__init__(self,row.mWindow,-1,wxDefaultPosition,wxDefaultSize,values)
        self.SetSelection(value)
        row.Add(self,grow,wxALIGN_BOTTOM,
                size=(width,-1),minsize=(minwidth,-1))
        if (command):
            EVT_CHOICE(row.mWindow,self.GetId(),cWinBusyCommand(command))
        SetDefaultFont(self,font)
            
    def GetBestSize(self):
        return wxSize(wxChoice.GetBestSize(self).GetWidth(),self.GetSize().GetHeight())

    def get(self):
        return self.GetSelection()
    
    def set(self,v):
        self.SetSelection(v)

    def value(self):
        return self.GetStringSelection()
        
    def values(self):
        l=[]
        for i in range(self.GetCount()):
            l.append(self.GetString(i))
        return l
        
    def setvalues(self,values):
        self.Clear()
        for item in value:
          self.Append(item)

#-----------------------------------------------------
# Make a Combo
class cWinCombo(wxComboBox):
    def __init__(self,row,values,command=None,grow=0,width=-1,minwidth=-1,value="",font=None):
        wxComboBox.__init__(self,row.mWindow,-1,"",wxDefaultPosition,wxDefaultSize,values)
        self.SetValue(value)
        row.Add(self,grow,wxALIGN_BOTTOM,
                size=(width,-1),minsize=(minwidth,-1))
        if (command):
            EVT_COMBOBOX(row.mWindow,self.GetId(),cWinBusyCommand(command))
            EVT_TEXT(row.mWindow,self.GetId(),cWinBusyCommand(command))
        SetDefaultFont(self,font)
            
    def GetBestSize(self):
        return wxSize(wxComboBox.GetBestSize(self).GetWidth(),self.GetSize().GetHeight())

    def get(self):
        result=self.GetValue()
        if (result==""): result=self.GetStringSelection()
        return result
    
    def set(self,v):
        self.SetValue(v)

    def value(self):
        return self.get()
        
    def values(self):
        l=[]
        for i in range(self.GetCount()):
            l.append(self.GetString(i))
        return l
        
    def setvalues(self,values):
        self.Clear()
        for item in values:
          self.Append(item)
        self.SetValue("")
        
    def clear(self):
        self.SetValue("")
        self.Clear()

#-----------------------------------------------------
# Make a Label
class cWinLabel(wxStaticText):
    def __init__(self,col,text,grow=0,width=-1,minwidth=-1,font=None):
        wxStaticText.__init__(self,col.mWindow,-1,text,style=wxALIGN_LEFT)
        col.Add(self,grow,wxALIGN_BOTTOM,
                size=(width,-1),minsize=(minwidth,-1))
        SetDefaultFont(self,font)
        
    def set(self,text):
        self.SetLabel(text)

#-----------------------------------------------------
# Make a Entry
class cWinEntry(wxTextCtrl):
    def __init__(self,col,grow=1,width=-1,minwidth=-1,font=None,edit=1,multiline=0):
        style=0
        if (multiline):
            style=style|WxTE_MULTILINE
        wxTextCtrl.__init__(self,col.mWindow,-1,style=style)
        col.Add(self,grow,wxALIGN_BOTTOM,
                size=(width,-1),minsize=(minwidth,-1))
        SetDefaultFont(self,font)
        self.mEdit=edit
        self.SetEditable(edit)

    def get(self):
        return self.GetValue()
    
    def set(self,text):
        return self.SetValue(text)
    
#-----------------------------------------------------
# Make a Entry
class cWinRowEntry(cWinRow):
    def __init__(self,col,text,
                 label_width=-1,label_minwidth=-1,
                 entry_width=-1,entry_minwidth=-1,edit=1):
        cWinRow.__init__(self,col)
        self.mLabel=cWinLabel(self,text,
                              width=label_width,minwidth=label_minwidth)
        self.mEntry=cWinEntry(self,grow=1,edit=edit,
                              width=entry_width,minwidth=label_minwidth)

    def get(self):
        return self.mEntry.get()
    
    def set(self,text):
        return self.mEntry.set(text)
    
#-----------------------------------------------------
# Make a RowEntryButton
class cWinRowEntryButton(cWinRowEntry):
    def __init__(self,col,text,buttext,command,
                 label_width=-1,label_minwidth=-1,
                 entry_width=-1,entry_minwidth=-1,
                 button_width=-1,button_minwidth=-1):
        cWinRowEntry.__init__(self,col,text,
                              label_width=label_width,label_minwidth=label_minwidth,
                              entry_width=entry_width,entry_minwidth=entry_minwidth)
        self.mEntry.SetWindowStyleFlag(self.mEntry.GetWindowStyleFlag()|
                                       wxTE_PROCESS_ENTER)
        EVT_TEXT_ENTER(self.mWindow,self.mEntry.GetId(),cWinBusyCommand(command))
        self.mButton=cWinButton(self,buttext,cWinBusyCommand(command),
                                width=button_width,minwidth=button_minwidth)

#-----------------------------------------------------
# Make a Label
class cWinRowLabel(cWinRow):
    def __init__(self,col,text,width=-1,minwidth=-1):
        cWinRow.__init__(self,col)
        self.mLabel=cWinLabel(self,text,1,
                              width=width,minwidth=minwidth)
        
#-----------------------------------------------------
# Make a Label
class cWinRowLabelButton(cWinRow):
    def __init__(self,col,text,buttext,command,
                 label_width=-1,label_minwidth=-1,
                 button_width=-1,button_minwidth=-1):
        cWinRow.__init__(self,col)
        self.mLabel=cWinLabel(self,text,grow=1,
                              width=label_width,minwidth=label_minwidth)
        self.mButton=cWinButton(self,buttext,command,
                                width=button_width,minwidth=button_minwidth)

    def set(self,v):
        self.mButton.set(v)

#-----------------------------------------------------
# Make a Choice
class cWinRowChoiceButton(cWinRow):
    def __init__(self,col,text,values,command=None,
                 value=0,
                 label_width=-1,label_minwidth=-1,
                 button_width=-1,button_minwidth=-1):
        cWinRow.__init__(self,col)
        self.mLabel=cWinLabel(self,text,
                              width=label_width,minwidth=label_minwidth)
        self.mButton=cWinChoice(self,values,command,value=value,
                                width=button_width,minwidth=button_minwidth)

    def get(self):
        return self.mButton.get()

    def set(self,v):
        self.mButton.set(v)
        
    def value(self):
        return self.mButton.value()

    def values(self):
        return self.mButton.values()

    def setvalues(self,values):
        return self.mButton.setvalues(values)

#-----------------------------------------------------
# Make a Combo
class cWinRowComboButton(cWinRow):
    def __init__(self,col,text,values,command=None,
                 value="",
                 label_width=-1,label_minwidth=-1,
                 button_width=-1,button_minwidth=-1):
        cWinRow.__init__(self,col)
        self.mLabel=cWinLabel(self,text,
                              width=label_width,minwidth=label_minwidth)
        self.mButton=cWinCombo(self,values,command,value=value,
                                width=button_width,minwidth=button_minwidth)

    def get(self):
        return self.mButton.get()

    def set(self,v):
        self.mButton.set(v)
        
    def value(self):
        return self.mButton.value()

    def values(self):
        return self.mButton.values()

    def setvalues(self,values):
        return self.mButton.setvalues(values)

    def clear(self):
        self.mButton.clear()
        
#-----------------------------------------------------
# Make a Panel for inside a spliter
class c_WinPanel(cWinRow):
    def __init__(self,win,dr=wxVERTICAL):
        #self.mWindow=wxPanel(win,-1,style=wxSIMPLE_BORDER)
        #self.mSizer=wxBoxSizer(dr)
        #self.mWindow.SetSizer(self.mSizer)
        cWinRow.__init__(self,None,0,dr=dr,border=1,parentwin=win)

#-----------------------------------------------------
# Make a 2-way Splitter
class cWinHorizontalSplitter:
    def __init__(self,col):
        self.mWindow=wxSplitterWindow(col.mWindow,-1,
                                      style=wxSP_3DSASH)
        col.WinAdd(self,1,wxEXPAND)
        self.mTopPanel=c_WinPanel(self.mWindow)
        self.mBottomPanel=c_WinPanel(self.mWindow)
        self.mPanels=[self.mTopPanel,self.mBottomPanel]

    def End(self):
        self.mTopPanel.End()
        self.mBottomPanel.End()
        if (kDebug):
            print "Top:",self.mTopPanel.mY,self.mTopPanel.mMinY
            print "Bot:",self.mBottomPanel.mY,self.mBottomPanel.mMinY
        self.mX=max(self.mTopPanel.mX,self.mBottomPanel.mX)
        self.mMinX=max(self.mTopPanel.mMinX,self.mBottomPanel.mMinX)
        h=200 #self.mWindow.GetBestSize().GetHeight()
        self.mY=max(h,self.mTopPanel.mY+self.mBottomPanel.mY+15)
        self.mMinY=max(h,self.mTopPanel.mMinY+self.mBottomPanel.mMinY+15)
        #split=self.mTopPanel.mY+25
        split=self.mY/2
        if (kDebug):
            print "Size:",self.mX,self.mY,h,split,kDefault_SliderMinSize
        self.mWindow.SetDimensions(-1,-1,self.mX,self.mY,wxSIZE_AUTO)
        self.mWindow.SplitHorizontally(self.mTopPanel.mWindow,self.mBottomPanel.mWindow,split)
        self.mWindow.SetMinimumPaneSize(kDefault_SliderMinSize)

        #self.mWindow.SetAutoLayout(1)
        #self.mWindow.SetSizer(self.mSizer)
        #self.mSizer.Fit(self.mWindow)
        #self.mSizer.SetSizeHints(self.mWindow)

#-----------------------------------------------------
# Make a 3-way Splitter
class cWinHorizontalSplitter3(cWinHorizontalSplitter):
    def __init__(self,col):
        cWinHorizontalSplitter.__init__(self,col)
        self.mSplitter=cWinHorizontalSplitter(self.mTopPanel)
        self.mPanels=[self.mSplitter.mTopPanel,self.mSplitter.mBottomPanel,self.mBottomPanel]

#-----------------------------------------------------
# Make a 2-way Splitter
class cWinVerticalSplitter:
    def __init__(self,col):
        self.mWindow=wxSplitterWindow(col.mWindow,-1,
                                      style=wxSP_3DSASH)
        col.WinAdd(self,1,wxEXPAND)
        self.mLeftPanel=c_WinPanel(self.mWindow)
        self.mRightPanel=c_WinPanel(self.mWindow)
        self.mPanels=[self.mLeftPanel,self.mRightPanel]

    def End(self):
        self.mLeftPanel.End()
        self.mRightPanel.End()
#        print "Left:",self.mLeftPanel.mY
#        print "Bot:",self.mRightPanel.mY
        self.mY=max(self.mLeftPanel.mY,self.mRightPanel.mY)
        self.mMinY=max(self.mLeftPanel.mMinY,self.mRightPanel.mMinY)
        w=self.mWindow.GetBestSize().GetWidth()
        self.mX=w+self.mLeftPanel.mX+self.mRightPanel.mX
        self.mMinX=w+self.mLeftPanel.mMinX+self.mRightPanel.mMinX
        split=self.mLeftPanel.mX+w/2
#        print "Size:",self.mX,self.mY,w,split
        self.mWindow.SetDimensions(-1,-1,self.mX,self.mY)
        self.mWindow.SplitVertically(self.mLeftPanel.mWindow,self.mRightPanel.mWindow,split)
        self.mWindow.SetMinimumPaneSize(kDefault_SliderMinSize)

#-----------------------------------------------------
# Alert Dialog
class cWinAlert:
    def __init__(self,msg):
        self.mMessage=msg
        self.mTop=None
        
    def Detach(self,*v):
        if (self.mTop==None): return

        self.mTop.Detach()
        self.mTop=None

    def Display(self):
        if (self.mTop!=None):
            self.mTop.Raise()
            return

        self.mTop=cWinTop("Alert",self.Detach)
        self.mCol=self.mTop.CreateColumn(1)

        row=self.mCol.CreateRow()
        self.mLabel=cWinLabel(row,' ')

        row=self.mCol.CreateRow()
        self.mLabel=cWinLabel(row,self.mMessage)
        row=self.mCol.CreateRow()
        cWinButton(row,text="Cancel",command=self.Detach,minwidth=80)

        row=self.mCol.CreateRow()
        self.mLabel=cWinLabel(row,' ')

        self.mTop.End()

def WinAlert(msg):
    t=cWinAlert(msg)
    t.Display()
    
#-----------------------------------------------------
# Create App
class cWinApp(wxPySimpleApp):
    def __init__(self):
        wxPySimpleApp.__init__(self)

    def main_loop(self):
        self.MainLoop()
        
    def exit(self):
        self.ExitMainLoop()
        

class cTest:
    def Action(self,*v):
        print "Action:",v

    def Detach(self,*v):
        print "DetachAction"
        self.mTop.DetachAction()
        
    def __init__(self):
        self.mApp=cWinApp()
        
        self.mTop=cWinTop("Browser",self.DetachAction)
        col=self.mTop.CreateColumn(1)
        cWinLabel(col,"Text:")
        row=col.CreateRow()
        cWinLabel(row,"Row:")
    
        split=cWinVerticalSplitter(col)
        left,right=split.mPanels
        
        splitl=cWinHorizontalSplitter(left)
        tp,bt=splitl.mPanels
    
        cWinLabel(tp,"ScrollText:")
        out=cWinScrollText(tp)
        for i in range(10):
            out.Print("Line: %d"%i)
    
        cWinLabel(bt,"ScrollListBox:")
        lst=cWinScrollListbox(bt)
        for i in range(10):
            lst.insert("Item: %d"%i)
        
        splitr=cWinHorizontalSplitter3(right)
    #    self.mTop,bottom=split.mPanels
    #    out=cWinScrollText(self.mTop)
    #    for i in range(10):
    #        out.Print("Line: %d"%i)
    
    #    lst=cWinScrollListbox(bottom)
    #    for i in range(10):
    #        lst.insert("Item: %d"%i)
        
    
        cWinRowEntry(col,"Entry:")
        cWinRowEntryButton(col,"Entry:","Ex",self.Action)
    
        row=col.CreateRow()
        cWinLabel(row,"Buttons:")
        cWinButton(row,"Button",command=self.Action)
    
        self.mTop.End()

    def Run(self):
        self.mApp.main_loop()
    
#-----------------------------------------------------
if (__name__ == '__main__'):
    t=cTest()
    t.Run()
