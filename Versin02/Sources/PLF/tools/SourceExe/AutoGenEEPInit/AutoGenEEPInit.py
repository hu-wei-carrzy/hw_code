# coding=utf-8
import sys
import os
import time
import getpass
import shutil
import re


strDBKxFilePath = r".\..\..\..\XXX\YYY\DAT\DAT_EEP\DAT_DBK\DAT_DBKx.h"
strSBKxFilePath = r".\..\..\..\XXX\YYY\DAT\DAT_EEP\DAT_SBK\DAT_SBKx.h"
strDATPEEInitGenFilePath = r".\..\..\..\XXX\YYY\DAT\DAT_EEP\DAT_PEE\DAT_PEE_INIT_GEN.h"
strLAPEEPInitGenFilePath = r".\..\..\..\XXX\YYY\LAP\LAP_EEP\LAP_EEP_INIT_GEN.h"

regSBKGroups = r"typedef\s*struct.*?{(.*?)}\s*tDATSbkMirrors"
regDBKGroups = r"typedef\s*struct.*?{(.*?)}\s*tDATDbkMirrors"
regGroupName = r"\s*U16\s*(\w+)\s*\["

strSBKRebuildTemplate = '''                                                    \\
		case cDATSbkHandleGROUPNAME:                \\
			mSetSbkDefaultValue(GROUPNAME);         \\
			break;                                  \\
                                                    \\
'''

strDBKRebuildTemplate = '''                                                    \\
                                                   \\
    case cDATDbkHandleGROUPNAME:                   \\
		mSetDbkDefaultValue(GROUPNAME);            \\
      break;                                       \\
                                                   \\
'''
strRebuildSBKCmdTemplate = '''    case cU16EEPInitStep_XXXX:                         \\
        DATPeeRebuildSingleBank(cDATSbkHandleGROUPNAME);                         \\
		mSERControl(Eep,UpDateEepGroupGROUPNAME);                                 \\
        break;                                                                    \\
'''

strRebuildDBKCmdTemplate = '''    case cU16EEPInitStep_XXXX:                         \\
        DATPeeRebuildDoubleBank(cDATDbkHandleGROUPNAME);\\
        mSERControl(Eep,UpDateEepGroupGROUPNAME);                                 \\
        break;                                                                   \\
'''
strRebuildSBKUpdate  = "       mSERControl(Eep,UpDateEepGroupGROUPNAME);\\"
strRebuildDBKUpdate  = "       mSERControl(Eep,UpDateEepGroupGROUPNAME);\\"

structContent = ""
#GroupEEPInitFlag 这个组是SBK组
#它不用于自动恢复，只有四个元素，
#用于控制EEP的初始化
listSBKName = []
listDBKName = []

strPEEFileHeader = '''
#ifndef I_DAT_PEE_INIT_GEN_H
#define I_DAT_PEE_INIT_GEN_H

'''
strPEEFileTailer = '''

#endif
'''
strSBKRebuildMacro = "#define mSBKGroupsRebuild()       \
"
strDBKRebuildMacro = "#define mDBKGroupsRebuild()       \
"
strLAPEEPHeader = """#ifndef I_LAP_EEP_INIT_GEN_H
#define I_LAP_EEP_INIT_GEN_H


"""
strLAPEEPTailer = """
#endif"""
strLAPEEInitMacro ='''#define mEEPGroupInit()        \\
'''

strGroupEndSeq =     '''#define cU16EEPInitSetp_SetInitFlag       cU16EEPInitStep_DATA1
#define cU16EEPInitSetp_RebuildErrorGroup cU16EEPInitStep_DATA2
#define cU16EEPInitStep_ECUReset          cU16EEPInitStep_DATA3


    '''

def GetSBKGroupName():
    global structContent
    structContent = ""
    fDATFileHandle = open(strSBKxFilePath,"r")
    strFileContent = fDATFileHandle.read()
    #通过正则表达式查找结构体的内容
    for each in (re.findall(regSBKGroups,strFileContent,re.S)):
        structContent = structContent + each
    fDATFileHandle.close()

    #解析结构体的内容，得到具体的每个组名
    for each in (re.findall(regGroupName,structContent,re.S)):
        listSBKName.append(each)
    pass

def GetDBKGroupName():
    global structContent
    structContent = ""
    fDATFileHandle = open(strDBKxFilePath,"r")
    strFileContent = fDATFileHandle.read()
    #通过正则表达式查找结构体的内容
    for each in (re.findall(regDBKGroups,strFileContent,re.S)):
        structContent = structContent + each
    fDATFileHandle.close()

    #解析结构体的内容，得到具体的每个组名
    for each in (re.findall(regGroupName,structContent,re.S)):
        listDBKName.append(each)
    pass

def GenFile():
    fDATFileHandle = open(strDATPEEInitGenFilePath,"w")
    fLAPFileHandle = open(strLAPEEPInitGenFilePath,"w")
    fDATFileHandle.write(GetGenLog())

    fDATFileHandle.write(strPEEFileHeader)

    #写入SBK恢复宏
    fDATFileHandle.write(strSBKRebuildMacro)
    strGenCode = strSBKRebuildTemplate
    strCmdCode = strRebuildSBKCmdTemplate
    #由于第一个分组cU16EEPInitStep_1留给里程使用，所以这里可用
    #的有效分组的开始是cU16EEPInitStep_2

    strTmp = ""
    intGroupIndex = 2

    fLAPFileHandle.write(strLAPEEPHeader)
    fLAPFileHandle.write(strLAPEEInitMacro)

    for each in listSBKName:
        fDATFileHandle.write(strGenCode.replace("GROUPNAME",each))
        strGenCode = strSBKRebuildTemplate

        #这里要        #有两个单备份组要排除掉：GroupEEPInitCtrl和GroupErrorGroup这个组，不做任何恢复操作
        #对于 GroupEEPInitCtrl，它是通过具体写各个变量实现的。对于GroupErrorGroup
        #这个是在特定时刻初始化的
        if each != "ErrorGroup" and each != "GroupEEPInitCtrl":
            #更新组名
            strTmp =strCmdCode.replace("GROUPNAME",each)
            #更换序号
            strTmp =strTmp.replace("XXXX","%d"%intGroupIndex)
            intGroupIndex = intGroupIndex + 1

            fLAPFileHandle.write(strTmp)
            strCmdCode = strRebuildSBKCmdTemplate

    #写入DBK恢复宏
    fDATFileHandle.write("\n\n\n\n")
    fDATFileHandle.write(strDBKRebuildMacro)
    strGenCode = strDBKRebuildTemplate
    strCmdCode = strRebuildDBKCmdTemplate
    for each in listDBKName:
        fDATFileHandle.write(strGenCode.replace("GROUPNAME",each))
        strGenCode = strDBKRebuildTemplate

        #更新组名
        strTmp =strCmdCode.replace("GROUPNAME",each)
        #更换序号
        strTmp =strTmp.replace("XXXX","%d"%intGroupIndex)
        intGroupIndex = intGroupIndex + 1
        fLAPFileHandle.write(strTmp)
        strCmdCode = strRebuildDBKCmdTemplate
    #写入文件结束
    fDATFileHandle.write(strPEEFileTailer)
    fDATFileHandle.close()

    #添加分界线
    fLAPFileHandle.write("\n\n\n\n")
    #这里生成其它宏，来描述各个初始化组的关系，形式如下：
    #具体的各个组的序号要在生成的组的基础上，再添加，这里
    #为了保险起见，添加3
    intGroupIndex = intGroupIndex + 3
    strTmp = strGroupEndSeq
    strTmp =strTmp.replace("DATA1","%d"%(intGroupIndex + 0))
    strTmp =strTmp.replace("DATA2","%d"%(intGroupIndex + 2))
    strTmp =strTmp.replace("DATA3","%d"%(intGroupIndex + 4))

    fLAPFileHandle.write(strTmp)
    fLAPFileHandle.write(strLAPEEPTailer)
    fLAPFileHandle.close()

'''
1.00:
    2016.07.06 create this file
2.00
    2017.04.08 add code to gen init code.
'''
def PrintVersion():
    strVersion = "1.00"
    print "%s version is %s"%(os.path.basename(sys.argv[0]),strVersion)

def GetGenLog():
    strTime =  ("//This file is auto generated by %s"%(os.path.basename(sys.argv[0]) ))
    strName = "//This file is generated by %s"%getpass.getuser()
    return strTime + "\n" #+ strName + "\n\n"

#将\XXX\YYY替换为真正的路径
def SubRealSourcePath(strSub):
    strReg = r".+(\\\w+\\\w+)\\LAP\\LAP_SUP"
    regXY = r"\\XXX\\YYY"
    for root,dirs,files in os.walk(r".\..\..\.."):#搜索当前路径
        for Each in files:
            if Each == "LAP_SUP.c": #找到LAP_SUP.c，将LAP文件夹前面两层路径提取出来
                listRealPath = re.findall(strReg,root)

                strRealPath = re.sub(regXY,listRealPath[0],strSub)#将\XXX\YYY替换为真正的路径

                return strRealPath

if __name__ == '__main__':

    strDBKxFilePath = SubRealSourcePath(strDBKxFilePath)
    strSBKxFilePath = SubRealSourcePath(strSBKxFilePath)
    strDATPEEInitGenFilePath = SubRealSourcePath(strDATPEEInitGenFilePath)
    strLAPEEPInitGenFilePath = SubRealSourcePath(strLAPEEPInitGenFilePath)

    PrintVersion()
    GetDBKGroupName()
    GetSBKGroupName()
    GenFile()


