#
#********************************************************************
#* Copyright (C) 2002-2003 LSI Logic Corporation.                   *
#*         All Rights Reserved.                                     *
#********************************************************************
#
# DESC: Tkinter Utilities for Browser
#
#  This provides the Tkinter based support routines.
#

import Tkinter
from Tkinter import *
import types

TkRoot=None

kDefault_Space=4
kDefault_SliderMinSize=100

wxHORIZONTAL=1
wxVERTICAL=2

# -----------------------------------------------------
# cFrameSlide
#  This was taken from fmgr_wdg.py
#  If you fix bugs in cFrameSlide, please update the original.
# -----------------------------------------------------
class cFrameSlide:
    def __init__(self,root,ud=0,type="button"):
        if (ud!=0): ud=1
        self.mUd=ud
        self.mSlideSize=9
        cursor=("sb_h_double_arrow","sb_v_double_arrow")[self.mUd]
        self.mRoot=root
        self.mRoot.rowconfigure(0,weight=1,minsize=30)
        self.mRoot.columnconfigure(0,weight=1,minsize=30)
        self.mCanvas=Canvas(self.mRoot,borderwidth=0,
                            highlightthickness=0)
        self.mCanvas.grid(row=0,column=0,sticky="nsew")

        # Create the 3 frames
        self.mLeft=Frame(self.mCanvas) #,relief="raised",borderwidth=8)
        self.mRight=Frame(self.mCanvas) #,relief="raised",borderwidth=8)
        self.mCenter=Frame(self.mCanvas,
                          cursor=cursor)
        if (type=="button"):
            self.BuildSlider_Button()
        else:
            self.BuildSlider_Bar()

        self.mCanvas.update()

        # Configure the 3 main windows
        if (self.mUd):
            w=self.mCanvas.winfo_height()
            h=self.mCanvas.winfo_width()
            w2=(w-self.mSlideSize)/2
            self.mLeftSize=w2
            self.mRightSize=w2
            self.mLeftId=self.mCanvas.create_window(
                0,0,anchor="nw",
                height=self.mLeftSize,width=h,
                window=self.mLeft)
            self.mCenterId=self.mCanvas.create_window(
                0,self.mLeftSize,anchor="nw",
                height=self.mSlideSize,width=h,
                window=self.mCenter)
            self.mRightId=self.mCanvas.create_window(
                0,self.mLeftSize+self.mSlideSize,anchor="nw",
                height=self.mRightSize,width=h,
                window=self.mRight)
        else:
            w=self.mCanvas.winfo_width()
            h=self.mCanvas.winfo_height()
            w2=(w-self.mSlideSize)/2
            self.mLeftSize=w2
            self.mRightSize=w2
            self.mLeftId=self.mCanvas.create_window(
                0,0,anchor="nw",
                width=self.mLeftSize,height=h,
                window=self.mLeft)
            self.mCenterId=self.mCanvas.create_window(
                self.mLeftSize,0,anchor="nw",
                width=self.mSlideSize,height=h,
                window=self.mCenter)
            self.mRightId=self.mCanvas.create_window(
                self.mLeftSize+self.mSlideSize,0,anchor="nw",
                width=self.mRightSize,height=h,
                window=self.mRight)

        # Bind events to the Slider
        wins=self.mCenter.winfo_children()
        wins.append(self.mCenter)
        for w in wins:
            w.bind("<ButtonPress-1>",self.Press)
            w.bind("<B1-Motion>",self.Slide)
            w.bind("<ButtonRelease-1>",self.Release)

        # Bind event to changing window size
        self.mCanvas.bind("<Configure>",self.Configure)

    # -------------------------------------------------
    def Window(self):
        return self.mCanvas
    
    #---------------------------------------------
    def BuildSlider_Button(self):
        # Build the Slider
        if (self.mUd):
            self.mCenter.columnconfigure(0,weight=1,minsize=self.mSlideSize/3)
            self.mCenter.columnconfigure(1,weight=0,minsize=self.mSlideSize)
            self.mCenter.columnconfigure(2,weight=10,minsize=self.mSlideSize/3)
            self.mCenter.rowconfigure(0,minsize=4)
            self.mCenter.rowconfigure(1,minsize=self.mSlideSize-6)
            self.mCenter.rowconfigure(2,minsize=2)
            self.mCF1=Frame(self.mCenter,relief="sunken",borderwidth=2)
            self.mCF1.grid(column=0,row=1,columnspan=3,sticky="nesw")
            self.mCF2=Frame(self.mCenter,relief="raised",borderwidth=2)
            self.mCF2.grid(column=1,row=0,rowspan=3,sticky="nesw")
        else:
            self.mCenter.rowconfigure(0,weight=1,minsize=self.mSlideSize/3)
            self.mCenter.rowconfigure(1,weight=0,minsize=self.mSlideSize)
            self.mCenter.rowconfigure(2,weight=10,minsize=self.mSlideSize/3)
            self.mCenter.columnconfigure(0,minsize=4)
            self.mCenter.columnconfigure(1,minsize=self.mSlideSize-6)
            self.mCenter.columnconfigure(2,minsize=2)
            self.mCF1=Frame(self.mCenter,relief="sunken",borderwidth=2)
            self.mCF1.grid(row=0,column=1,rowspan=3,sticky="nesw")
            self.mCF2=Frame(self.mCenter,relief="raised",borderwidth=2)
            self.mCF2.grid(row=1,column=0,columnspan=3,sticky="nesw")

    #---------------------------------------------
    def BuildSlider_Bar(self):
        # Build the Slider
        if (self.mUd):
            self.mCenter.columnconfigure(0,minsize=self.mSlideSize)
            self.mCenter.rowconfigure(0,minsize=self.mSlideSize)
            self.mCenter.configure(height=self.mSlideSize,
                                   relief="raised",
                                   borderwidth=(self.mSlideSize-1)/2-1)
        else:
            self.mCenter.columnconfigure(0,minsize=self.mSlideSize)
            self.mCenter.rowconfigure(0,minsize=self.mSlideSize)
            self.mCenter.configure(width=self.mSlideSize,
                                   relief="raised",
                                   borderwidth=(self.mSlideSize-1)/2-1)


    #---------------------------------------------
    # Window resize
    def Configure(self,v):
        if (self.mUd):
            w=self.mCanvas.winfo_height()
            h=self.mCanvas.winfo_width()
        else:
            w=self.mCanvas.winfo_width()
            h=self.mCanvas.winfo_height()

        # Adjust by current percentage
        self.mLeftSize=((w-self.mSlideSize)*self.mLeftSize)/(self.mLeftSize+self.mRightSize)
        self.mRightSize=w-self.mSlideSize-self.mLeftSize

        # Check Ranges
        if (self.mLeftSize<0):
            self.mRightSize=self.mRightSize+self.mLeftSize-1
            self.mLeftSize=1
        if (self.mRightSize<0):
            self.mLeftSize=self.mLeftSize+self.mRightSize-1
            self.mRightSize=1

        # Update Locations
        if (self.mUd):
            self.mCanvas.itemconfigure(self.mLeftId,height=self.mLeftSize)
            self.mCanvas.itemconfigure(self.mLeftId,width=h)
            self.mCanvas.itemconfigure(self.mRightId,width=h)
            self.mCanvas.itemconfigure(self.mRightId,height=self.mRightSize)
            self.mCanvas.itemconfigure(self.mCenterId,width=h)
            self.mCanvas.coords(self.mCenterId,0,self.mLeftSize)
            self.mCanvas.coords(self.mRightId,0,self.mLeftSize+self.mSlideSize)
        else:
            self.mCanvas.itemconfigure(self.mLeftId,width=self.mLeftSize)
            self.mCanvas.itemconfigure(self.mLeftId,height=h)
            self.mCanvas.itemconfigure(self.mRightId,height=h)
            self.mCanvas.itemconfigure(self.mRightId,width=self.mRightSize)
            self.mCanvas.itemconfigure(self.mCenterId,height=h)
            self.mCanvas.coords(self.mCenterId,self.mLeftSize,0)
            self.mCanvas.coords(self.mRightId,self.mLeftSize+self.mSlideSize,0)
        
    #---------------------------------------------
    # Start Sliding
    def Press(self,v):
        self.mSplit=self.mLeftSize
        if (self.mUd):
            self.mSplitRange=[1,self.mCanvas.winfo_height()-self.mSlideSize-1]
        else:
            self.mSplitRange=[1,self.mCanvas.winfo_width()-self.mSlideSize-1]

    #---------------------------------------------
    # Move the slider
    def Slide(self,v):
        if (self.mUd):
            d=v.y
        else:
            d=v.x

        self.mSplit=self.mSplit+d
        if (self.mSplit<self.mSplitRange[0]): self.mSplit=self.mSplitRange[0]
        if (self.mSplit>self.mSplitRange[1]): self.mSplit=self.mSplitRange[1]
        if (self.mUd):
            self.mCanvas.coords(self.mCenterId,0,self.mSplit)
        else:
            self.mCanvas.coords(self.mCenterId,self.mSplit,0)

    #---------------------------------------------
    # End slide, update all windows
    def Release(self,v):
        if (self.mUd):
            w=self.mCanvas.winfo_height()
            self.mLeftSize=self.mSplit
            self.mRightSize=w-self.mSlideSize-self.mLeftSize
            self.mCanvas.itemconfigure(self.mLeftId,height=self.mLeftSize)
            self.mCanvas.itemconfigure(self.mRightId,height=self.mRightSize)
            self.mCanvas.coords(self.mRightId,0,self.mLeftSize+self.mSlideSize)
        else:
            w=self.mCanvas.winfo_width()
            self.mLeftSize=self.mSplit
            self.mRightSize=w-self.mSlideSize-self.mLeftSize
            self.mCanvas.itemconfigure(self.mLeftId,width=self.mLeftSize)
            self.mCanvas.itemconfigure(self.mRightId,width=self.mRightSize)
            self.mCanvas.coords(self.mRightId,self.mLeftSize+self.mSlideSize,0)

    #---------------------------------------------
    # Interface access to windows
    def Main(self):
        return self.mCanvas

    def Right(self):
        return self.mRight

    def Left(self):
        return self.mLeft

    def Bottom(self):
        return self.mRight

    def Top(self):
        return self.mLeft


#-----------------------------------------------------
#-----------------------------------------------------
# Make a WindowRow
#   Negative space is between items, not first/last
class cWinRow:
    # -----------------------------------------
    # Initialize the Row/Column
    def __init__(self,parent,grow=0,space=kDefault_Space,border=0,dr=wxHORIZONTAL):
        self.mParent=parent
        self.mSpace=space
        self.mDir=dr
        self.mCount=0
        self.mX=0
        self.mY=0
        self.mLastWindow=None
        self.mLastWinWindow=None
        self.mLastAdd=None

        if (parent!=None):
#            print "Border:",border
            if (border==0):
#                print "Plain"
                self.mWindow=Frame(parent.mWindow) 
            else:
#                print "Solid"
                self.mWindow=Frame(parent.mWindow,borderwidth=1,relief='solid')
            self.mParent.WinAdd(self,grow,1)

        if (self.mSpace>0):
            self.AddSpace(self.mSpace)

    # -----------------------------------------
    # Update the X/Y size of a completed thing that was added
    def _UpdateSize(self,x,y):
        if (self.mDir==wxHORIZONTAL): # A Row
            self.mX+=x
            if (y>self.mY): self.mY=y
        else:
            self.mY+=y
            if (x>self.mX): self.mX=x

    # -----------------------------------------
    # The last added thing is complete, so check its size
    def _UpdateLast(self):
        if (self.mLastWinWindow!=None):
            self.mLastWinWindow.End()
            self._UpdateSize(self.mLastWinWindow.mX,self.mLastWinWindow.mY)
            self.mLastWinWindow=None
            self.mLastWindow=None
        elif (self.mLastWindow!=None):
            w=self.mLastWindow.winfo_width()
            h=self.mLastWindow.winfo_height()
            self._UpdateSize(w,h)
            self.mLastWindow=None
        if (self.mLastAdd):
            if (self.mSpace<0 and self.mCount>0): self.AddSpace(-self.mSpace,1)
            win,opt,flag=self.mLastAdd
            if (self.mDir==wxHORIZONTAL): # A Row
                if (opt):
                    if (flag):
                        win.pack(side=LEFT,fill=BOTH,expand=1)
                    else:
                        win.pack(side=LEFT,fill=X,expand=1)
                else:
                    if (flag):
                        win.pack(side=LEFT,fill=Y)
                    else:
                        win.pack(side=LEFT)
            else:
                if (opt):
                    if (flag):
                        win.pack(side=TOP,fill=BOTH,expand=1)
                    else:
                        win.pack(side=TOP,fill=Y,expand=1)
                else:
                    if (flag):
                        win.pack(side=TOP,fill=X)
                    else:
                        win.pack(side=TOP)
                        
            self.mCount+=1
            if (self.mSpace>0): self.AddSpace(self.mSpace,1)
            self.mLastAdd=None
 
    # -----------------------------------------
    # Add Blank Space
    def AddSpace(self,space,nc=0):
        if (not nc):
            self._UpdateLast()
        if (self.mDir==wxHORIZONTAL): # A Row
            frame=Frame(self.mWindow,width=space,height=1)
            frame.pack(side=LEFT)
            self.mX+=space
        else:
            frame=Frame(self.mWindow,width=1,height=space)
            frame.pack(side=TOP)
            self.mY+=space
        
    # -----------------------------------------
    # Add a row/column to us
    def WinAdd(self,win,opt=0,flag=0):
        self._UpdateLast()
        self.Add(win.mWindow,opt,flag)
        self.mLastWinWindow=win

    # -----------------------------------------
    # Add a wxWindow to us
    def Add(self,win,opt=0,flag=0):
        self._UpdateLast()
        self.mLastAdd=[win,opt,flag]
        self.mLastWindow=win

    # -----------------------------------------
    # End this row/column
    def End(self):
        self._UpdateLast()
        self.mX=max(self.mX,1)
        self.mY=max(self.mY,1)
#        print "SetDim:",self.mX,self.mY
#        self.mWindow.SetDimensions(-1,-1,self.mX,self.mY)
#        self.mWindow.SetAutoLayout(1)

    # -----------------------------------------
    # Helpers for making sub-row/cols
    def CreateRow(self,grow=0,space=kDefault_Space):
        return cWinRow(self,grow=grow,space=space)

    def CreateColumn(self,grow=0,space=kDefault_Space):
        return cWinColumn(self,grow=grow,space=space)

#-----------------------------------------------------
# Make a Window Column
class cWinColumn(cWinRow):
    def __init__(self,window,grow=0,space=1,border=0):
        cWinRow.__init__(self,window,grow=grow,space=space,
                         border=border,dr=wxVERTICAL)

#-----------------------------------------------------
# Make a Top Window
class cWinTop(cWinRow):
    def __init__(self,title,clos,dr=wxHORIZONTAL):
        global TkRoot
        if (TkRoot==None):
            TkRoot=Tk()
            self.mWindow=TkRoot
        else:
            self.mWindow=Toplevel(TkRoot)
        self.mWindow.wm_protocol("WM_DELETE_WINDOW",clos)
        self.mWindow.wm_title(title)
        cWinRow.__init__(self,None,space=kDefault_Space,dr=dr)
        cmd="if { [lsearch -exact [font names] lsibrowserfont_bold] == -1 } { font create lsibrowserfont_bold -family courier -size 12 -weight bold -slant roman -underline 0 -overstrike 0 }"
        TkRoot.tk.eval(cmd)

        cmd="if { [lsearch -exact [font names] lsibrowserfont_normal] == -1 } {  font create lsibrowserfont_normal -family courier -size 12 -weight normal -slant roman -underline 0 -overstrike 0 }"
        TkRoot.tk.eval(cmd)

    def End(self):
        cWinRow.End(self)
        self.mWindow.update()
        self.mWindow.wm_geometry("%dx%d"%(500,600))

    def Raise(self):
        self.mWindow.tkraise()

    def Close(self):
        self.mWindow.destroy()

#-----------------------------------------------------
# Make a Scrolling ListBox
class cWinScrollListbox:
    def __init__(self,col):
        self.mFrame=Frame(col.mWindow)
        col.Add(self.mFrame,1,1)
        self.mListbox=Listbox(self.mFrame,selectmode="single",height=5,
                              font='lsibrowserfont_normal')
        self.mFrame.columnconfigure(0,weight=1)
        self.mFrame.rowconfigure(0,weight=1)
        self.mListbox.grid(column=0,row=0,sticky="nesw")
        self.mVs=Scrollbar(self.mFrame,orient="vertical")
        self.mVs.grid(column=1,row=0,sticky="ns")
        self.mHs=Scrollbar(self.mFrame,orient="horizontal")
        self.mHs.grid(column=0,row=1,sticky="ew")
        self.mListbox.configure(yscrollcommand=self.mVs.set,xscrollcommand=self.mHs.set)
        self.mVs.configure(command=self.mListbox.yview)
        self.mHs.configure(command=self.mListbox.xview)

    def curselection(self):
        index=self.mListbox.curselection()
        if (index):
            return int(index[0])
        return -1

    def selection_set(self,index):
        self.mListbox.selection_clear(0,'end')
        self.mListbox.selection_set(index)

    def insert(self,value):
        if (type(value)==types.ListType):
            for val in value:
                self.mListbox.insert('end',val)
        else:
            self.mListbox.insert('end',value)

    def Clear(self):
        self.mListbox.delete(0,'end')

#-----------------------------------------------------
# Make a Scrolling Test area
class cWinScrollText:
    def __init__(self,col):
        self.mFrame=Frame(col.mWindow)
        col.Add(self.mFrame,1,1)
        self.mFrame.columnconfigure(0,weight=1)
        self.mFrame.rowconfigure(0,weight=1)
        self.mText=Text(self.mFrame,wrap="none",state="disabled",
                        font="lsibrowserfont_normal")
        self.mText.grid(column=0,row=0,sticky="nesw")
        self.mVs=Scrollbar(self.mFrame,orient="vertical")
        self.mVs.grid(column=1,row=0,sticky="ns")
        self.mHs=Scrollbar(self.mFrame,orient="horizontal")
        self.mHs.grid(column=0,row=1,sticky="ew")
        self.mText.configure(yscrollcommand=self.mVs.set,xscrollcommand=self.mHs.set)
        self.mVs.configure(command=self.mText.yview)
        self.mHs.configure(command=self.mText.xview)

    def Print(self,text):
        self.mText.configure(state='normal')
        self.mText.insert('end',text+'\n')
        self.mText.configure(state='disabled')

#-----------------------------------------------------
# Make a Button
class cWinButton:
    def __init__(self,row,text,command,width=0):
        if (width):
            self.mButton=Button(row.mWindow,text=text,command=command,width=width,
                                font="lsibrowserfont_normal")
        else:
            self.mButton=Button(row.mWindow,text=text,command=command,
                                font="lsibrowserfont_normal")
        row.Add(self.mButton,0,0)

#-----------------------------------------------------
# Make a CheckBox
class cWinCheckBox:
    def __init__(self,row,text,command=None):
        if (command):
            self.mButton=Checkbutton(row.mWindow,text=text,command=command,
                                     font="lsibrowserfont_normal")
        else:
            self.mButton=Checkbutton(row.mWindow,text=text,
                                     font="lsibrowserfont_normal")
        row.Add(self.mButton,0,0)

    def get(self):
        return self.mButton.get()
    
    def set(self,v):
        if (v):
          self.mButton.select()
        else:
          self.mButton.deselect()
    
#-----------------------------------------------------
# Make a Label
class cWinLabel:
    def __init__(self,col,text,grow=0):
        self.mLabel=Label(col.mWindow,text=text,
                          font="lsibrowserfont_normal")
        col.Add(self.mLabel,grow,0)

#-----------------------------------------------------
# Make a Entry
class cWinEntry:
    def __init__(self,col,grow=1):
        self.mEntry=Entry(col.mWindow,
                          font="lsibrowserfont_normal")
        col.Add(self.mEntry,grow,0)

    def get(self):
        return self.mEntry.get()
    
    def set(self,text):
        self.mEntry.delete(0,'end')
        self.mEntry.insert('end',text)
    
#-----------------------------------------------------
# Make a Entry
class cWinRowEntry(cWinRow):
    def __init__(self,col,text):
        cWinRow.__init__(self,col)
        self.mLabel=cWinLabel(self,text)
        self.mEntry=cWinEntry(self,1)

    def get(self):
        return self.mEntry.get()
    
    def set(self,text):
        return self.mEntry.set(text)
    
#-----------------------------------------------------
# Make a RowEntryButton
class cWinRowEntryButton(cWinRowEntry):
    def __init__(self,col,text,buttext,command):
        cWinRowEntry.__init__(self,col,text)
#        self.mEntry.SetWindowStyleFlag(self.mEntry.GetWindowStyleFlag()|
#                                       wxTE_PROCESS_ENTER)
#        EVT_TEXT_ENTER(self.mWindow,self.mEntry.GetId(),command)
        self.mButton=cWinButton(self,buttext,command)

#-----------------------------------------------------
# Make a Label
class cWinRowLabel(cWinRow):
    def __init__(self,col,text):
        cWinRow.__init__(self,col)
        self.mLabel=cWinLabel(self,text,1)

#-----------------------------------------------------
# Make a Label
class cWinRowLabelButton(cWinRow):
    def __init__(self,col,text,buttext,command):
        cWinRow.__init__(self,col)
        self.mLabel=cWinLabel(self,text,1)
        self.mButton=cWinButton(self,buttext,command)

#-----------------------------------------------------
# Make a Panel for inside a spliter
class c_WinPanel(cWinRow):
    def __init__(self,frame,dr=wxVERTICAL):
        self.mWindow=Frame(frame,borderwidth=1,relief='solid')
        self.mWindow.pack(fill=BOTH,expand=1)
        cWinRow.__init__(self,None,space=kDefault_Space,dr=dr)

#-----------------------------------------------------
# Make a 2-way Splitter
class cWinHorizontalSplitter:
    def __init__(self,col):
        self.mWindow=Frame(col.mWindow)
        col.WinAdd(self,1,1)
        self.mSlide=cFrameSlide(self.mWindow,1)
        self.mTopPanel=c_WinPanel(self.mSlide.Top())
        self.mBottomPanel=c_WinPanel(self.mSlide.Bottom())
        self.mPanels=[self.mTopPanel,self.mBottomPanel]

    def End(self):
        self.mTopPanel.End()
        self.mBottomPanel.End()
#        print "Top:",self.mTopPanel.mY
#        print "Bot:",self.mBottomPanel.mY
        self.mX=max(self.mTopPanel.mX,self.mBottomPanel.mX)
        h=1 #self.mWindow.GetBestSize().GetHeight()
        self.mY=h+self.mTopPanel.mY+self.mBottomPanel.mY
        split=self.mTopPanel.mY+h/2
#        print "Size:",self.mX,self.mY,h,split
#        self.mWindow.SetDimensions(-1,-1,self.mX,self.mY)
#        self.mWindow.SplitHorizontally(self.mTopPanel.mWindow,self.mBottomPanel.mWindow,split)
#        self.mWindow.SetMinimumPaneSize(kDefault_SliderMinSize)

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
        self.mWindow=Frame(col.mWindow)
        col.WinAdd(self,1,1)
        self.mSlide=cFrameSlide(self.mWindow,0)
        self.mLeftPanel=c_WinPanel(self.mSlide.Left())
        self.mRightPanel=c_WinPanel(self.mSlide.Right())
        self.mPanels=[self.mLeftPanel,self.mRightPanel]

    def End(self):
        self.mLeftPanel.End()
        self.mRightPanel.End()
#        print "Left:",self.mLeftPanel.mY
#        print "Bot:",self.mRightPanel.mY
        self.mY=max(self.mLeftPanel.mY,self.mRightPanel.mY)
        w=1 #self.mWindow.GetBestSize().GetWidth()
        self.mX=w+self.mLeftPanel.mX+self.mRightPanel.mX
        split=self.mLeftPanel.mX+w/2
#        print "Size:",self.mX,self.mY,w,split
#        self.mWindow.SetDimensions(-1,-1,self.mX,self.mY)
#        self.mWindow.SplitHorizontally(self.mLeftPanel.mWindow,self.mRightPanel.mWindow,split)
#        self.mWindow.SetMinimumPaneSize(kDefault_SliderMinSize)

#-----------------------------------------------------
# Create App
class cWinApp:
    def __init__(self):
        pass

    def main_loop(self):
        global TkRoot
        TkRoot.mainloop()
        

#-----------------------------------------------------

class cTest:
    def Action(self,*v):
        print "Action:",v

    def Close(self,*v):
        print "Close"
        self.mTop.Close()
        
    def __init__(self):
        self.mApp=cWinApp()
        
        self.mTop=cWinTop("Browser",self.Close)
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
