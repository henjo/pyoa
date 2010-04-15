#*******************************************************************
#   Copyright 2002-2008  LSI Corporation
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#
#*******************************************************************
#
#--------------------------------------------------------------------
# Part of DoxData2Desc
# Find all the used template types
#--------------------------------------------------------------------
#

import string
import sys
import copy
import types

# ===============================================================
# Convert a templated class name: const Class<a1,a2>&
# into [Class,a1_a2,(a1,a2)]
def GetTemplateInfo(tname):
  # add spaces around dilimiters
  tname=string.replace(tname,',',' ')
  tname=string.replace(tname,'<',' < ')
  tname=string.replace(tname,'>',' > ')
  # Split by spaces
  tokens=string.split(tname)
  start=tokens.index('<')
  end=tokens.index('>')
  clsname=tokens[start-1]
  args=[]
  argstr=None
  # Iterate on template args
  for i in range(start+1,end):
    args.append(tokens[i])
    if (argstr==None): argstr=tokens[i]
    else: argstr+=("_"+tokens[i])
  return [clsname,args]

# ===============================================================
# Get the TypeName part of a type description
def GetTypeName(tname):
  parts=string.split(tname)
  lp=len(parts)
  if (lp==0):
    return ''
  index=0
  if (index+1<lp and parts[index]=='virtual'): index+=1
  if (index+1<lp and parts[index]=='const'): index+=1
  return parts[index]

# ===============================================================
def ConvertTemplateParam(name,targs,orgclsname,typedefname):
  clsname=GetTypeName(name)
  if (clsname==orgclsname): 
    name=name.replace(clsname,typedefname)
    return name
  fname=string.replace(clsname,'<',' ')
  fname=string.replace(fname,',',' ')
  fname=string.replace(fname,'>','')
  parts=string.split(fname)
  newparts=[]
  index=0
  for part in parts:
    for tpname,arg in targs:
      if (part==tpname):
        part=arg
        if (index>0):
          if (part[-1]=='*'): part=part[:-1]
        break
    newparts.append(part)
    index+=1
  newclsname=string.join(newparts,'_')
  namelen=len(clsname)
  loc=string.find(name,clsname)
  name=name[:loc]+newclsname+name[loc+namelen:]
  return name
    
# ===============================================================
def ConvertTemplateCase(data,name):
  clsname=GetTypeName(name)
  typedefname=data.mTemplateTypedefs.get(clsname,None)
  if (typedefname):
    namelen=len(clsname)
    loc=string.find(name,clsname)
    name=name[:loc]+typedefname+name[loc+namelen:]
    return name
  return name

# ===============================================================
# Find all the class types combinations
def RemoveEmptyData(data):
  #---------------------------------------------
  # Remove Empty Stuff
  sys.stderr.write("Removing Empty Data:\n")
  newdata=[]
  for item in data.mData:
    if (item['category']!='file'): 
      newdata.append(item)
      continue
    if (item['defines'] or item['enums'] or item['functions'] or
        item['typedefs'] or item['vars']):
      newdata.append(item)
  data.mData=newdata

# ===============================================================
# ===============================================================
# Expand template default args
def ExpandTemplateDefaults(data):
  #---------------------------------------------
  # Get List of templates
  templates={}
  for item in data.mData:
    if (item['category']!='class'): continue
    name=item['name']
    if (not item.has_key('template')): continue # skip non-templates
    templates[name]=item

  #---------------------------------------------
  # Find instances of template
  for item in data.mData:
    if (item['category']!='class'): continue
    name=item['name']
    if (item.has_key('template')): continue # skip general templates
    if (string.find(name,'<')>=0): 
      item['name']=_UpdateTemplateName(templates,name)
    for cat in ['functions','sfunctions']:
      for fun in item[cat]:
          rettype=fun['type']
          if (string.find(rettype,'<')>=0):
            fun['type']=_UpdateTemplateName(templates,rettype)
          for param in fun['param']:
            paramtype=param['type']
            if (string.find(paramtype,'<')>=0):
              param['type']=_UpdateTemplateName(templates,paramtype)
    newbase=[]
    for base in item['bases']:
        if (string.find(base,'<')>=0):
            base=_UpdateTemplateName(templates,base)
        newbase.append(base)
    item['bases']=newbase

# ===============================================================
def _UpdateTemplateName(templates,name):
  clsname,args=GetTemplateInfo(name)
  if (not templates.has_key(clsname)): return name
  tdata=templates[clsname]['template']
  if (len(tdata)==len(args)): return name
  sname=''
  for i in range(len(tdata)):
    if (i<len(args)):
      fname=args[i]
    else:
      fname=tdata[i]['defval']
    if (sname==''):
      sname=clsname+'<'+fname
    else:
      sname=sname+','+fname
  sname+='>'
  return sname

# ===============================================================
# ===============================================================
# Find all the class types combinations
def FindTemplateTypes(data):
  #---------------------------------------------
  # Find templated classes
  sys.stderr.write("Finding Template Cases:\n")
  data.mTemplateCases={}
  data.mTemplateSpecializations={}
  for item in data.mData:
    if (item['category']!='class'): continue
    clsname=item['name']
    if (item.has_key('template')): continue # skip general templates
    data.mTemplateSpecializations[clsname]=1
    if (string.find(clsname,'<')>=0): 
      _UpdateSpecialization(data,data.mTemplateCases,clsname)
    for cat in ['functions','sfunctions']:
      for fun in item[cat]:
          rettype=fun['type']
          if (string.find(rettype,'<')>=0):
            _UpdateSpecialization(data,data.mTemplateCases,rettype)
          for param in fun['param']:
            paramtype=param['type']
            if (string.find(paramtype,'<')>=0):
              _UpdateSpecialization(data,data.mTemplateCases,paramtype)
    for base in item['bases']:
        if (string.find(base,'<')>=0):
            _UpdateSpecialization(data,data.mTemplateCases,base)

  #---------------------------------------------
  # Call User code to add more specializations
  data.vAddTemplateSpecializations(data.mTemplateCases)

  #---------------------------------------------
  # Propagate templated specializations
  propagates=data.vGetTemplatePropagations()
  for propagate in propagates:
    for item in data.mData:
      if (item['category']!='class'): continue
      clsname=item['name']
      if (clsname!=propagate): continue
      if (not item.has_key('template')): continue # skip general classes
      if (not data.mTemplateCases.has_key(clsname)): continue # skip if not specilzed
      if (data.vShouldSkipTemplateClass(clsname)): continue
      for base in item['bases']:
        if (string.find(base,'<')<0): continue # skip if base is not template
        print "Propagate: %s -> %s"%(clsname,base)
        basename,args=GetTemplateInfo(base)
        if (data.vShouldSkipTemplateClass(basename)): continue
        orderlist=[]
        for arg in args:
          index=0
          for param in item['template']:
            if (param['name']==arg):
              orderlist.append(index)
            index+=1
        if len(args)==len(orderlist):  # all args used
          for targs in data.mTemplateCases[clsname].values():
            splist=[]
            for index in orderlist:
              splist.append(targs[index])
            _AddTemplateSpecialization(data,data.mTemplateCases,basename,splist)

  #---------------------------------------------
  data.vReportData("TemplateCaseSpecializations",data.mTemplateCases)

  #---------------------------------------------
  # Build output list
  data.mTmpData=[]
  for key,value in data.mTemplateCases.items():
    if (data.vShouldSkipTemplateClass(key)): continue
    if (not data.mTemplateCases.has_key(key)): continue
    cases=[]
    for case in value.values():
      newcase=[]
      for i in range(len(case)):
        name=case[i]
        if (name[-1]=='*'): 
          name=name[:-1]
        newcase.append(name)
      if (len(newcase)==1):
        cases.append(newcase[0])
      else:
        cases.append(tuple(newcase))
    data.mTmpData.append((key,tuple(cases)))
    data.vPathTmpData()
    data.vReportData("TemplateMapData",data.mTmpData)
        
    
# ===============================================================
# Update the list of specializations
def _UpdateSpecialization(data,specialized,name):
  clsname,args=GetTemplateInfo(name)
  #if (data.vShouldSkipTemplateClass(clsname)): return
  _AddTemplateSpecialization(data,specialized,clsname,args)

# ===============================================================
# Update the list of specializations
def _AddTemplateSpecialization(data,specialized,clsname,spllist):
  dct=specialized.get(clsname,{})
  splname=spllist[0]
  for item in spllist[1:]:
    item=item.replace('<','_')
    item=item.replace('>','_')
    item=item.replace(':','_')
    splname+='_'+item
  dct[splname]=spllist
  specialized[clsname]=dct

# ===============================================================
# ===============================================================
# Expand all the class types 
def ExpandTemplateTypes(data):
  #---------------------------------------------
  # Replace sepecialization names with typedef names
  print "Updating Specialized Templates"
  sys.stderr.write("Updating Specialized Templates:\n")
  data.mTemplateTypedefs={}
  fp=data.vGetReportFile("SpecializedTemplates")
  if (fp): fp.write("Specialized Templates\n")
  for item in data.mData:
    if (item['category']!='class'): continue
    splclsname=item['name']
    if (string.find(splclsname,'<')<0): continue # Skip non-specializations
    tmpclsname,args=GetTemplateInfo(splclsname)
    typedefname=tmpclsname
    for arg in args:
      name=arg
      if (name[-1]=='*'): name=name[:-1]
      typedefname+='_'+name
    item['name']=typedefname
    data.mTemplateTypedefs[splclsname]=typedefname
    if (fp): fp.write("  %s %s -> %s\n"%(splclsname,str(args),typedefname))
    # Patch values:
    # build new dct since the function names could change
    for fun in item['functions']:
      funname=fun['name']
      if (funname==tmpclsname): 
        fun['name']=typedefname
      if (funname==('~'+tmpclsname)): 
        fun['name']=('~'+typedefname)
      # Don't need to patch return value/parameters as
      # the general patch below will catch these.
    # Replace the function dct
    item['template_name']=splclsname
    item['template_typedef']=typedefname

  #---------------------------------------------
  # Expand the general templates
  print "Expanding General Templates:"
  sys.stderr.write("Expanding General Templates:\n")
  if (fp): fp.write("General Templates\n")
  newdata=[]
  for item in data.mData:
    if (item['category']!='class'):
      newdata.append(item)
      continue
    tmpclsname=item['name']
    # skip general templates
    if (not item.has_key('template')):
      newdata.append(item)
      continue
    if (data.vShouldSkipTemplateClass(tmpclsname)): continue
    if (not data.mTemplateCases.has_key(tmpclsname)):
      print "** Don't know how to expand template class:",tmpclsname
      # newdata.append(item) # drop the item
      continue
    templatedct=data.mTemplateCases[tmpclsname]
    for tcase,args in templatedct.items():
      splclsname='%s<'%tmpclsname
      typedefname=tmpclsname
      index=0
      targs=[]
      for arg in args:
        name=arg
        if (name[-1]=='*'): name=name[:-1]
        name=name.replace('<','_')
        name=name.replace('>','_')
        name=name.replace(':','_')
        typedefname+='_'+name
        if (index):
          splclsname+=','
        splclsname+='%s'%arg
        if (index>=len(item['template'])):
          print "** Index error:",tmpclsname,index,templatedct
        targs.append([item['template'][index]['name'],arg])
        index+=1
      splclsname+= '>'

      # if specialized case exists, then skip expantion
      if (data.mTemplateSpecializations.has_key(splclsname)): continue      
      
      # expand out the template
      data.mTemplateTypedefs[splclsname]=typedefname
      if (fp): fp.write("  %s %s -> %s\n"%(splclsname,str(args),typedefname))
      newitem=copy.deepcopy(item)
      newitem['name']=typedefname
      newitem['template_name']=splclsname
      newitem['template_typedef']=typedefname
      # Patch return values and parameters:
      for cat in ['functions','sfunctions']:
        for fun in newitem[cat]:
          funname=fun['name']
          # Rename cstr/destr
          if (funname==tmpclsname): 
            fun['name']=typedefname
          if (funname==('~'+tmpclsname)): 
            fun['name']=('~'+typedefname)
          # conver template arg parameters to their specialized name
          rettype=fun['type']
          fun['type']=ConvertTemplateParam(rettype,targs,tmpclsname,typedefname)
          for param in fun['param']:
            paramtype=param['type']
            param['type']=ConvertTemplateParam(paramtype,targs,tmpclsname,typedefname)
      # Patch var types
      for var in newitem['vars'].values():
        rettype=var['type']
        var['type']=ConvertTemplateParam(rettype,targs,tmpclsname,typedefname)
      # Update bases
      if (newitem.has_key('bases')):
        newlist=[]
        for base in newitem['bases']:
          base=ConvertTemplateParam(base,targs,tmpclsname,typedefname)
          newlist.append(base)
        newitem['bases']=newlist
      # Add new item to list
      newdata.append(newitem)
  data.mData=newdata
  if (fp): fp.close()

  #---------------------------------------------
  # Patch all parameters of the specialization types
  print "Updating all Templated Values/Parameters"
  sys.stderr.write("Updating all Templated Values/Parameters:\n")
  for item in data.mData:
    if (item['category']!='class'): continue
    # Patch values:
    for cat in ['functions','sfunctions']:
      for fun in item[cat]:
        rettype=fun['type']
        fun['type']=ConvertTemplateCase(data,rettype)
        for param in fun['param']:
          paramtype=param['type']
          param['type']=ConvertTemplateCase(data,paramtype)

