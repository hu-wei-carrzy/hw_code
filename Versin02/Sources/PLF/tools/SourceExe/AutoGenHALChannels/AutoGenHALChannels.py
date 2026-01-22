# coding=utf-8
import sys
import os
import time
import getpass
import shutil
import re


#if necessary you should change the path according to real path location
gStrLDBPath = r".\..\..\..\XXX\YYY\LDB\\"
gStrHALPath = r".\..\..\..\XXX\YYY\HAL\\"
gStrDATPath = r".\..\..\..\XXX\YYY\DAT\\"
gStrCANMsgCfgJILPath = r".\..\..\..\XXX\YYY\DAT\DAT_CAN\CAN_MSG_CFG.jil"
gStrSubSource = "source"

gStrHAL_INCLUDE_H=r"HAL_CHANNELS.h"
gStrHAL_CHANNEL_H= r"HAL_LDB_INCLUDE.h"
gStrHAL_DATCBK_H = r"HAL_DATCBK_INCLUDE.h"
gStrDATCBKExport_H = "CBKEXPORT.H"

#function dictionary , all the func will be updated
#NOTE:gDictFuncToPar must have the same sequence and same size with gListFunc
gDictFuncToPar = {"LDBInit":"",   "LDBEnterSleepMode":"",   "LDBLeaveSleepMode":"",\
"LDBSendWithAddr":"Addr,pMsg",   "LDBPrepareSendWithAddr":"Addr,pMsg",         "LDBSendWithoutAddr":"pMsg",\
"LDBPrepareSendWithoutAddr":"pMsg",      "LDBReceiveWithAddr":"Addr,pMsg",    "LDBReceiveWithoutAddr":"pMsg",\
"LDBControl":"Ctrl",       "LDBEnableCallBack":"CallBackAuthorize","LDBCallBackControl":"Ctrl,Status",\
"LDBCallBackRxWithAddr":"Addr,Status","LDBCallBackTxWithAddr":"Addr,Status","LDBCallBackEndControl":"Ctrl,Status",\
"LDBCallBackFromIrqWithAddr":"Addr,Status"}


gListFunc = gDictFuncToPar.keys()

gListWithCaseFuncElement =["Addr","Control","CallBack"]


gStrHALCDemo = "HALDemo.c"
gStrHALC = "HAL.c"

gDictDATCBKExportFiles = {}
gListExcludeLDBDir = ["LDB_API","LDB_COMMON","LDB_CAN"]
gStrCfgMacro="#ifdef cHeadIncludeType_Directly\n"
gStrElse="#else\n"
gStrEndIf="#endif\n"
gStrLeadingSpace="    "
gStrStdInclude = '''#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "HAL_CHANNELS.h"
#else
#include "HAL_CHANNELS.h"
#endif\n\n'''


StrHALIncludeHeader = """#ifndef I_HAL_INCLUDE_H
#define I_HAL_INCLUDE_H\n\n\n"""

StrHALIncludeTalier= "#endif\n"

StrHALChannelsHeader = \
"""#ifndef I_HAL_CHANNELS_H
#define I_HAL_CHANNELS_H

"""
StrHALChannelsTailer = \
"""#endif\n"""


StrHALDATCBKHeader = \
"""#ifndef I_HAL_DATCBK_INCLUDE_H
#define I_HAL_DATCBK_INCLUDE_H

"""
StrHALDATCBKTailer = \
"""#endif\n"""



def GenHALIncludeHeader(fHandle):
    fHandle.write(GetGenLog())
    fHandle.write(StrHALIncludeHeader)
    fHandle.write(gStrStdInclude)

def GenHALChannelsHeader(fHandle):
    fHandle.write(GetGenLog())
    fHandle.write(StrHALChannelsHeader)

def GenHALDATCBKHeader(fHandle):
    fHandle.write(GetGenLog())
    fHandle.write(StrHALDATCBKHeader)

def GenHALChannelsTailer(fHandle):
    fHandle.write(StrHALChannelsTailer)

def GenHALIncludeTailer(fHandle):
    fHandle.write(StrHALIncludeTalier)

def GenHALDATCBKTailer(fHandle):
    fHandle.write(StrHALDATCBKTailer)

def GenHALChannelsBody(fHandle,strChannelName,intChannelNum):
    fHandle.write("#define cLDBChannel" + strChannelName+"    ((tChannel)" + "%d"%intChannelNum + "UL)\n")

def GenIncludeDirect(fHandle,strHeaderFileName):
    fHandle.write(gStrLeadingSpace + "#include "+'"'+strHeaderFileName+'.h"\n')

def GenIncludeInDirect(fHandle,strHeaderFileName):
    fHandle.write(gStrLeadingSpace + "#include "+'"'+".\\..\\LDB\\" + strHeaderFileName+"\\"+strHeaderFileName+'.h"\n')


def GenHeaderInclude(fHandle,strHeaderFileName):
    fHandle.write('\n')
    fHandle.write('#ifdef cLDBChannel'+strHeaderFileName+'\n')
    fHandle.write(gStrLeadingSpace+gStrCfgMacro)
    GenIncludeDirect(fHandle,strHeaderFileName)
    fHandle.write(gStrLeadingSpace+gStrElse)
    GenIncludeInDirect(fHandle,strHeaderFileName)
    fHandle.write(gStrLeadingSpace+gStrEndIf)
    fHandle.write("#endif")
    fHandle.write('\n')

def GenSpecialHeaerIncludeForCAN(fHandle,listSpecialCAN):
    strHeaderFileName = ""
    strLDBCAN = "LDB_CAN"
    #now we want to get the follwing string
    # #ifdef cLDBChannelCan0 || cLDBChannelCan1
    for each in listSpecialCAN:
        strHeaderFileName = strHeaderFileName + "defined( cLDBChannel"+each + ") || "

    fHandle.write('\n')
    fHandle.write('#if '+strHeaderFileName[:-4]+'\n')
    fHandle.write(gStrLeadingSpace+gStrCfgMacro)
    GenIncludeDirect(fHandle,strLDBCAN)
    fHandle.write(gStrLeadingSpace+gStrElse)
    GenIncludeInDirect(fHandle,strLDBCAN)
    fHandle.write(gStrLeadingSpace+gStrEndIf)
    fHandle.write("#endif")
    fHandle.write('\n')


def GetLDBPath(strPath):
    listLDBFolder = []
    strAllFiels = ""
    for root, dirs,files in os.walk(strPath):
        for strEachDir in dirs:
            listLDBFolder.append(strEachDir)
        #only analyse LDB directory
        break

    listLDBFolder = list(set(listLDBFolder) - set(gListExcludeLDBDir))
    #analyse the CAN_MSG_CFG.jil file, so first check the file existing.
    #this action is to get the CAN channels name and define the name
    if os.path.exists(gStrCANMsgCfgJILPath):
        fHJIL = open(gStrCANMsgCfgJILPath,"r")
        fStrJIL = fHJIL.read()
        fHJIL.close()
        regComment1 =r"/\*[\s\S]*?\*/"
        regComment2 = r"//.*"
        regCANBus=r"CANBus\s*(?P<ChlName>\w+).*?BaudRate.*?\d+\s*?;.*?\};"
        #must fisrt match /**/ and then match //
        fStrJIL = re.sub(regComment1,"",fStrJIL,flags=re.S)
        fStrJIL = re.sub(regComment2,"",fStrJIL)
        intCANSpeicalNum = 0
        for each in (re.findall(regCANBus,fStrJIL,re.S)):
            #add the CAN channel name into listLDBFolder
            listLDBFolder.append(each)
            intCANSpeicalNum = intCANSpeicalNum+1

        if intCANSpeicalNum>0:
            listLDBFolder.append("LDB_CAN")
            intCANSpeicalNum = intCANSpeicalNum + 1
    return listLDBFolder,intCANSpeicalNum



def GetNormalIncludeFormat(strModelName,strHFileName,strPathName):
    return '''
//#ifdef cSERChannel%(ModelName)s
#ifdef cHeadIncludeType_Directly
#include "%(HFileName)s"
#else
#include "%(PathName)s\%(HFileName)s"
#endif
//#endif\n
'''%{'ModelName':strModelName,'HFileName':strHFileName,'PathName':strPathName}

#if the include path changed ,you should change this function
#retrun vlaue just like this:
#include ".\..\..\..\DAT\DAT_DIO\DAT_DIN\DAT_DIN.h"
#include ".\..\..\..\DAT\DAT_BUZ\DAT_BUZ.h"
def GetHFilePathAndModelName(strPath):
    listPath = strPath.split("\\")
    #use the list compression to remove some unused element
    listPath = [each for each in listPath if each != ""]
    listPath.remove(gStrSubSource)
    listPath.remove("..")
    return ("\\".join(listPath),listPath[-1])


def WriteDictToFile(dictCBK,fHandle):
    for eachKey in dictCBK:
        #writhe file include
        strPath,strModelName = GetHFilePathAndModelName(dictCBK[eachKey])
        fHandle.write(GetNormalIncludeFormat(strModelName,eachKey,strPath))



def ModelNameProcess(strModelName):
    #LDB_ABC=>LDBAbc
    #1:remove "-"
    #2:Uppper the former 4 chars and lower the following chars
    #strNewName =strModelName.replace("_","")
    #return strNewName[:4].upper()+strNewName[4:].lower()
    return strModelName


def GetLDBFuncFormat(strFuncName, strModelName,strPar,strCase,strBreak):
#for example:strFuncName=LDBReceiveWithAddr,strModelName=LDB_DIN,
#now I want to get:mLDBDINReceiveWithAddr, so first I have to get it by
#mLDBDINReceiveWithAddr = m + strFuncName[:3](this is LDB) + strModel[4:](this is DIN)
#+strFuncName[4:](this is ReceiveWithAddr)
    strmLDBFuncFormat = 'm'+strFuncName[:3]+strModelName[4:]+strFuncName[3:]
    return'''
#ifdef %(mMacro)s
    %(strCase)s%(mMacro)s(%(par)s);%(strBreak)s
#endif
'''%{"mMacro":strmLDBFuncFormat,'par':strPar,'strCase':strCase,'strBreak':strBreak}


def UpdateHALCFile(listModel,intCANSpecialNum):
    global gDictFuncToPar
    global gListFunc
    global gStrHALC
    global gStrHALCDemo
    global gStrHALPath
    global gListWithCaseFuncElement

    #get file content
    fHandle = open(gStrHALCDemo,'r')
    strHALDemoContent = fHandle.read()
    fHandle.close()


    fHandle = open(gStrHALC,"w")

    #define a list to store all function content
    listLDBFuncContent = ["" for x in range(len(gDictFuncToPar))]

    intLoop = 0
    strCase = ''
    strBreak = "break;\n"

    for eachFunc in gListFunc:
        #1:get index
        intLoop = gListFunc.index(eachFunc)

        #2:update each function content
        for eachEle in listModel:
            #1:get the new model name
            strModelName = ModelNameProcess(eachEle)
            #special process CAN channel because the channel comes from CAN_MSG_CFG.jil
            if intCANSpecialNum>=2:
                intEachIndex = listModel.index(eachEle)
                if intEachIndex >= (len(listModel)-(intCANSpecialNum-1)):
                    strModelName = "LDB_"+strModelName


            #2:check whether there is case and break
            strCase = ""
            strBreak = ""
            for each in gListWithCaseFuncElement:
                if each in eachFunc:
                    if "CAN" in eachEle.upper():
                        #special process for CAN channle
                        #keep the old can name for in line with CAN_MSG_CFG.jil
                        strCase = "case cLDBChannel"+eachEle+":\n        "
                    else:
                        strCase = "case cLDBChannel"+eachEle.upper()+":\n        "
                    strBreak = "\n    break;"
                    break

            #3:loop each model to finish the function content
            listLDBFuncContent[intLoop] = listLDBFuncContent[intLoop] + GetLDBFuncFormat(eachFunc,strModelName,gDictFuncToPar[eachFunc],strCase,strBreak)
            pass

        pass
        #replace the function content
        strHALDemoContent = strHALDemoContent.replace(eachFunc+"Content",listLDBFuncContent[intLoop])
        #fHandle.write(listLDBFuncContent[intLoop])

    pass
    fHandle.write(GetGenLog())
    fHandle.write(strHALDemoContent)
    fHandle.close()
    #remove file to HAL folder
    shutil.move(gStrHALC, gStrHALPath+gStrHALC)
    pass

def GetExportFile(strPath, dictDATCBK):
    for root, dirs,files in os.walk(strPath):
        for strEachFileName in files:
            #process DAT_XXX_CBKEXPORT.h
            if gStrDATCBKExport_H.upper() in strEachFileName.upper():
                dictDATCBK[strEachFileName]=root


'''
Change:
1:modify HAL.c file format,for example:mLDBDinReveiveWithAddr->mLDBDINReveiveWithAddr
2:get gListFunc from gDictFuncToPar

1.02:
    change the directory loacation and name
1.03:
    redefine LDB_CAN channel generation method.
    because CAN channel is generated from message
    configuration.
1.04
    1:add code for generate the LDBCallBackRxWithAddr and LDBCallBackTxWithAddr
    2:change GetNormalIncludeFormat() function for not use macro control for HAL_DATCBK_INCLUDE.h
1.05
    add "LDBCallBackControl":"Ctrl,Status" function
1.06---2015-15-16-10-37
    add new "LDBCallBackFromIrqWithAddr":"Addr,Status" function both in both script and C file
1.07---2016-01-13-11-09
    bug fix about CAN channel number: the old can channel has the same value with the upper
    adjacent channel.
    bug fix about CAN channel name:the CAN channel name should be the same with CAN_MSG_CFG.jil
2.00---2016-04-16-15
    1:bug fix about removing comment code
    2:remove the generated date and author
'''
def PrintVersion():
    strVersion = "2.00"
    print "%s version is %s"%(os.path.basename(sys.argv[0]),strVersion)

def GetGenLog():
    strTime =  ("//This file is auto generated by %s"%(os.path.basename(sys.argv[0]) ))
    strName = "//This file is generated by %s"%getpass.getuser()
    return strTime + "\n" #+ strName + "\n\n"

#将\XXX\YYY替换为真正的路径
def SubRealSourcePath(strSub):
    global gStrSubSource

    strReg = r".+(\\(\w+)\\(\w+))\\LAP\\LAP_SUP"
    regXY = r"\\XXX\\YYY"
    for root,dirs,files in os.walk(r".\..\..\.."):#搜索当前路径
        for Each in files:
            if Each == "LAP_SUP.c": #找到LAP_SUP.c，将LAP文件夹前面两层路径提取出来
                listRealPath = re.findall(strReg,root)
                gStrSubSource = listRealPath[0][1]
                strRealPath = re.sub(regXY,listRealPath[0][0],strSub)#将\XXX\YYY替换为真正的路径

                return strRealPath

if __name__ == '__main__':

    gStrLDBPath = SubRealSourcePath(gStrLDBPath)
    gStrHALPath = SubRealSourcePath(gStrHALPath)
    gStrDATPath = SubRealSourcePath(gStrDATPath)
    gStrCANMsgCfgJILPath = SubRealSourcePath(gStrCANMsgCfgJILPath)

    PrintVersion()

    GetExportFile(gStrDATPath,gDictDATCBKExportFiles)

    fChannelHandle = open(gStrHAL_INCLUDE_H,"w")
    fLDBIncludeHandle = open(gStrHAL_CHANNEL_H,'w')
    fDATCBKHandle  = open(gStrHAL_DATCBK_H, "w")

    #write file header
    GenHALIncludeHeader(fLDBIncludeHandle)
    GenHALChannelsHeader(fChannelHandle)
    GenHALDATCBKHeader(fDATCBKHandle)

    #get available ldb folder
    listModel,intCANSpecialNum = GetLDBPath(gStrLDBPath)

    intChlNum =0
    #write HAL_LDB_INCLUDE.h and HAL_CHANNELS.h content
    for count, eachItem in enumerate(listModel[0:len(listModel)-intCANSpecialNum]):
            #count+1 is to skip the value 0.
         #define channel macro
         GenHALChannelsBody(fChannelHandle,eachItem,count+1)
         GenHeaderInclude(fLDBIncludeHandle,eachItem)
         intChlNum = count


    #process special CAN channel
    if intCANSpecialNum>=2:
        #add the header include,"LDB_CAN" must be the last one.
        GenSpecialHeaerIncludeForCAN(fLDBIncludeHandle,listModel[(len(listModel)-intCANSpecialNum):-1])
        for count, eachItem in enumerate(listModel[(len(listModel)-intCANSpecialNum):-1]):
             #define channel macro
             GenHALChannelsBody(fChannelHandle,eachItem,count+2+intChlNum)

    #write HAL_DATCBK_INCLUDE.h
    WriteDictToFile(gDictDATCBKExportFiles,fDATCBKHandle)

    #write file tailer
    GenHALChannelsTailer(fChannelHandle)
    GenHALIncludeTailer(fLDBIncludeHandle)
    GenHALDATCBKTailer(fDATCBKHandle)

    #close file
    fLDBIncludeHandle.close()
    fChannelHandle.close()
    fDATCBKHandle.close()

    #copy the generated file HAL_CHANNELS.h and HAL_INCLUDE.h and HAL_DATCBK_INCLUDE.h into HAL
    shutil.move(gStrHAL_INCLUDE_H, gStrHALPath+gStrHAL_INCLUDE_H)
    shutil.move(gStrHAL_CHANNEL_H, gStrHALPath+gStrHAL_CHANNEL_H)
    shutil.move(gStrHAL_DATCBK_H , gStrHALPath+gStrHAL_DATCBK_H)

    #update HAL.c file by dynamically analying the LDB channels
    if intCANSpecialNum>=2:#this is special can channel needs processed
        UpdateHALCFile(listModel[:-1],intCANSpecialNum)
    else:
        UpdateHALCFile(listModel,intCANSpecialNum)



